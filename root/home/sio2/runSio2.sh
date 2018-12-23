if [ "$INIT_DB" == "on" ]; then
    echo "Filling in the sio2 database with a sample data"
    cp -R /home/sio2/sample_files /home/sio2/deployment/media/files
    sleep 5 # give postgresql time to start
    psql -f /home/sio2/sio2.sql sio2
fi
source /home/sio2/venv/bin/activate &&\
  /home/sio2/deployment/manage.py supervisor

