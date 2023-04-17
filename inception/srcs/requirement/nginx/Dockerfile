FROM alpine:3.16

WORKDIR /app

RUN apk update && apk add nginx openssl

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt -subj "/C=KO/ST=State/L=City/O=Organization/OU=Department/CN=localhost"

COPY ./conf/nginx.conf /etc/nginx/http.d
COPY ./conf/index.html /app

EXPOSE 443

#CMD ["nginx", "-g", "daemon off;"]
CMD ["sh"]
