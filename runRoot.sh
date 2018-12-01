#!/bin/bash
/etc/init.d/postgresql start &&\
  /etc/init.d/nginx start &&\
  /etc/init.d/rabbitmq-server start &&\
  su sio2 -c '/home/sio2/runSio2.sh'

