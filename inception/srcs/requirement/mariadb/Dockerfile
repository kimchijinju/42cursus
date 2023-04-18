FROM alpine:3.16

RUN apk update && apk add mariadb mariadb-client

WORKDIR /workspace

COPY tools/init.sh /workspace
COPY conf/my.cnf /etc/my.cnf 

EXPOSE 3306

ENTRYPOINT ["sh", "init.sh"]
