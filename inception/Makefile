all : .all_check

.all_check :
	touch $@
	mkdir -p ~/data/mariadb
	mkdir -p ~/data/wordpress
	docker compose -f srcs/docker-compose.yml build --no-cache

clean : 
	rm -f .all_check
	docker compose -f srcs/docker-compose.yml down -v
	docker image rm nginx:v1 wordpress:v1 mariadb:v1

fclean :
	make clean
	sudo rm -rf ~/data

re :
	make clean
	make all

.PHONY : all clean fclean re
