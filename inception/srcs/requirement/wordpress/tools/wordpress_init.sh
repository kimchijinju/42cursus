#!bin/sh

while ! mariadb -h mariadb -u $WORDPRESS_DATABASE_USER -p$WORDPRESS_DATABASE_PASS -e "SELECT VERSION();" > /dev/null
do
    echo "MariaDB server is not running on $REMOTE_HOST, waiting 5 seconds..."
    sleep 5
done

if ! wp core is-installed; then
	wp core download
	wp config create --dbhost=$WORDPRESS_DATABASE_HOST --dbname=$WORDPRESS_DATABASE_NAME --dbuser=$WORDPRESS_DATABASE_USER --dbpass=$WORDPRESS_DATABASE_PASS
	wp core install --url=$WORDPRESS_URL --title=$WORDPRESS_TITLE --admin_user=$WORDPRESS_ADMIN_USER --admin_password=$WORDPRESS_ADMIN_PASSWORD --admin_email=$WORDPRESS_ADMIN_EMAIL
	wp user create $WORDPRESS_USER_LOGIN $WORDPRESS_USER_EMAIL --user_pass=$WORDPRESS_USER_PASSWORD
fi

echo "Fast-cgi now running."
exec php-fpm8 -F

