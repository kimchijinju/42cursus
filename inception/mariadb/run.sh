docker build . -t hanbin:mariadb
docker rm abc
docker run -it --name abc hanbin:mariadb
