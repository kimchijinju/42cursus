#!bin/sh

wp core download
wp config create --dbhost=$WORDPRESS_DATABASE_HOST --dbname=$WORDPRESS_DATABASE_NAME --dbuser=$WORDPRESS_DATABASE_USER --dbpass=$WORDPRESS_DATABASE_PASS
wp core install --url=$WORDPRESS_URL --title=$WORDPRESS_TITLE --admin_user=$WORDPRESS_ADMIN_USER --admin_password=$WORDPRESS_ADMIN_PASSWORD --admin_email=$WORDPRESS_ADMIN_EMAIL
exec php-fpm8 -F