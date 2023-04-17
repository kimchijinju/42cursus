FROM alpine:3.16

RUN apk update && apk add mariadb mariadb-client

RUN mariadb-install-db --datadir=/var/lib/mysql && chown -R mysql:mysql /var/lib/mysql

WORKDIR /workspace

COPY tools/init.sh /workspace
COPY conf/my.cnf /etc/my.cnf 

EXPOSE 3306

ENTRYPOINT ["sh", "init.sh"]
