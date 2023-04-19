#!/bin/sh

mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld

mariadb-install-db --user=mysql --datadir=/var/lib/mysql
chown -R mysql:mysql /var/lib/mysql
chown -R mysql:mysql /etc/my.cnf.d 
chown mysql:mysql /etc/my.cnf 

mariadbd --user=mysql --bootstrap --skip-networking=0 << eof
USE mysql;
FLUSH PRIVILEGES;
GRANT ALL ON *.* TO 'root'@'%' identified by '$MARIADB_ROOT_PASSWORD' WITH GRANT OPTION;
GRANT ALL ON *.* TO 'root'@'localhost' identified by '$MARIADB_ROOT_PASSWORD' WITH GRANT OPTION;
SET PASSWORD FOR 'root'@'localhost'=PASSWORD('${MARIADB_ROOT_PASSWORD}');
DROP DATABASE IF EXISTS test;
FLUSH PRIVILEGES;
CREATE DATABASE IF NOT EXISTS $MARIADB_DATABASE;
GRANT ALL PRIVILEGES ON $MARIADB_DATABASE.* TO '$MARIADB_USER'@'%' IDENTIFIED BY '$MARIADB_PASSWORD';
GRANT ALL PRIVILEGES ON $MARIADB_DATABASE.* TO '$MARIADB_USER'@'localhost' IDENTIFIED BY '$MARIADB_PASSWORD';
FLUSH PRIVILEGES;
eof

exec mariadbd --user=mysql --console --skip-name-resolve --skip-networking=0
