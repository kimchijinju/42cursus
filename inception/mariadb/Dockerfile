FROM alpine:3.16

RUN apk update && apk add mariadb mariadb-client openrc

RUN mariadb-install-db --datadir=/var/lib/mysql && chown -R mysql:mysql /var/lib/mysql

RUN rc-status && touch /run/openrc/softlevel && rc-service mariadb start

COPY database_init.sql /docker-entrypoint-initdb.d/
RUN chmod -R 777 /docker-entrypoint-initdb.d

EXPOSE 3306

CMD ["mariadbd", "--user=root"]
