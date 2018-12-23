# siomaster

A docker image of the SIO2 master node.

Run with `docker run -e IP={IpUsedByWorkersToContactMaster} -p 80:80 -p 7888:7888 -p 9999:9999 -p 9877:9877 -p 7890:7890 -p 5672:5672 -p 7899:7899 informatykanastart/siomaster`.

Startup options:
* Set the `INIT_DB` environment variable (with Docker's run `-e INIT_DB=on` switch) to fill in the database with a sample content - an admin account (login `sio2`, password `qwer1234`) and a few sample tasts assigned to a test contest. It goes withouh saying that it's not secure to make such instance publicly available on the internet. Either run it in an isolated network or change the password quickly.

