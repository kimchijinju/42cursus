mariadbd --bootstrap < database_init.sql
mariadbd-safe -u root
rm database_init.sql
