all : .all_check

.all_check :
	docker compose -f srcs/docker-compose.yml build --no-cache
	touch $@

clean :
	rm -f .all_check
	sudo rm -rf ~/container_data
	docker compose -f srcs/docker-compose.yml down
	docker image rm nginx:v1 wordpress:v1 mariadb:v1

re :
	make clean
	make all

.PHONY : all clean re
