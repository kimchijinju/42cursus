FROM alpine:3.17

RUN apk update && apk add php81 php81-common php81-fpm php81-mysqli php81-phar php81-mbstring wget mariadb-client

RUN addgroup -S nginx && adduser -S nginx -G nginx
RUN mkdir -p /var/www/ && chown -R nginx:nginx /var/www
WORKDIR /var/www/

COPY conf/www.conf /etc/php81/php-fpm.d/www.conf

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp 

COPY tools/wordpress_init.sh /usr/local/bin/

EXPOSE 9000

ENTRYPOINT ["sh", "/usr/local/bin/wordpress_init.sh"]
