FROM alpine:3.16

WORKDIR /var/www

RUN apk update && apk add php8 php8-common php8-fpm php8-mysqli php8-phar wget && addgroup -S nginx && adduser -S nginx -G nginx

RUN wget http://wordpress.org/latest.tar.gz && tar -xzvf latest.tar.gz && rm latest.tar.gz

COPY conf/www.conf /etc/php8/php-fpm.d/www.conf
RUN chown -R nginx:nginx /var/www/wordpress && chmod -R 755 /var/www/wordpress

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar 
RUN chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp && 
#wp config create --dbname=wordpress --dbuser=wordpress

EXPOSE 9000

CMD ["php-fpm8", "-F"]
