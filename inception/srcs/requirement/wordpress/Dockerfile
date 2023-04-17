FROM alpine:3.16

WORKDIR /var/www

RUN apk update && apk add php8-common php8-fpm wget openrc
RUN rc-status && touch /run/openrc/softlevel
#RUN rc-update add php-fpm8 

RUN wget http://wordpress.org/latest.tar.gz && tar -xzvf latest.tar.gz && rm latest.tar.gz

copy conf/wp-config.php /var/www/wordpress/

EXPOSE 9000

CMD ["php-fpm8", "-F"]
