#!/bin/sh

mariadb-install-db --datadir=/var/lib/mysql;

chown -R mysql:mysql /var/lib/mysql;
chown mysql:mysql /etc/my.cnf
chmod 777 /etc/my.cnf


mariadbd --user=root --bootstrap << eof
USE mysql;
FLUSH PRIVILEGES;
GRANT ALL ON *.* TO 'root'@'%' identified by '$MYSQL_ROOT_PASSWORD' WITH GRANT OPTION;
GRANT ALL ON *.* TO 'root'@'localhost' identified by '$MYSQL_ROOT_PASSWORD' WITH GRANT OPTION;
SET PASSWORD FOR 'root'@'localhost'=PASSWORD('${MYSQL_ROOT_PASSWORD}');
DROP DATABASE IF EXISTS test;
FLUSH PRIVILEGES;

CREATE DATABASE IF NOT EXISTS $MARIADB_DATABASE;
CREATE USER IF NOT EXISTS '$MARIADB_USER'@'%' IDENTIFIED BY '$MARIADB_PASSWORD';
GRANT ALL PRIVILEGES ON $MARIADB_DATABASE.* TO '$MARIADB_USER'@'%' IDENTIFIED BY '$MARIADB_PASSWORD';
FLUSH PRIVILEGES;
eof

exec mariadbd-safe -u root
