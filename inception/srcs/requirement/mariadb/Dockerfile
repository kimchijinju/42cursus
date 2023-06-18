FROM alpine:3.17

RUN apk update && apk add mariadb mariadb-client

WORKDIR /workspace

COPY tools/init.sh /workspace

EXPOSE 3306

ENTRYPOINT ["sh", "init.sh"]
