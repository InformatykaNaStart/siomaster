FROM debian:stable

RUN apt update &&\
  DEBIAN_FRONTEND=noninteractive apt install -y git bash supervisor python-virtualenv libpython2.7-dev libdb-dev build-essential rabbitmq-server openssh-server postgresql postgresql-client nginx lighttpd librabbitmq4 librabbitmq-dev wget &&\
  useradd -s /bin/bash -m sio2

USER postgres
RUN /etc/init.d/postgresql start &&\
  createuser sio2 &&\
  createdb -O sio2 sio2

USER sio2
### oioioi
RUN git clone https://github.com/xneby/oioioi.git /home/sio2/oioioi &&\
  cd /home/sio2/oioioi &&\
  git checkout docker &&\
  python -m virtualenv /home/sio2/venv &&\
  . /home/sio2/venv/bin/activate && \
  ln -s /usr/sbin/lighttpd /home/sio2/venv/local/bin/lighttpd &&\
  cd /home/sio2/oioioi  &&\
  pip install -r requirements.txt &&\
  pip install psycopg2 uwsgi beautifulsoup4==4.6.0 flup==1.0.3.dev20110405 requests==2.18.4

### staszicowe dodatki
RUN git clone https://github.com/InformatykaNaStart/staszic-sio2.git /home/sio2/staszic &&\
  echo "/home/sio2" > /home/sio2/venv/lib/python2.7/site-packages/staszic.pth

### folder deployment
ENV IP=127.0.0.1
RUN . /home/sio2/venv/bin/activate &&\
  cd /home/sio2 &&\
  oioioi-create-config deployment &&\
  mv /home/sio2/oioioi/settings.py /home/sio2/deployment/ &&\
  echo yes | /home/sio2/deployment/manage.py collectstatic

### sandboxy
RUN mkdir -p /home/sio2/deployment/media/files &&\
  cd  /home/sio2/deployment/media/files &&\
  wget -q http://hugo.w.staszic.waw.pl/sio2-sandboxes/all.tar.gz &&\
  tar -zxvf all.tar.gz &&\
  mv sio2-sandboxes sandboxes &&\
  rm all.tar.gz

USER root
# migracja bazy wymaga użycia sudo (aby uruchomić postgres-a potrzebujemy być root-em, 
# a żeby powiodło się połączenie django z bazą, potrzebujemy odpalać manage.py jako użytkownik sio2)
# do tego potrzebujemy jeszcze paskudnego sleep-a, bo /etc/init.d/postgresql nie blokuje aż postgres skończy wstawać
RUN /etc/init.d/postgresql start &&\
  sleep 10 &&\
  . /home/sio2/venv/bin/activate &&\
  su sio2 -c 'IP=127.0.0.1 /home/sio2/deployment/manage.py migrate' &&\
  su sio2 -c 'IP=127.0.0.1 /home/sio2/deployment/manage.py createsuperuser' 
### konfiguracja nginxa
RUN ln -s /home/sio2/deployment/nginx-site.conf /etc/nginx/sites-enabled/oioioi &&\
  rm /etc/nginx/sites-enabled/default
COPY --chown=sio2:sio2 root/home/sio2 /home/sio2

EXPOSE 80 5672 7888 7899 7890 9877 9999
ENTRYPOINT ["/home/sio2/runRoot.sh"]

