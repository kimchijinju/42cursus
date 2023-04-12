CREATE DATABASE wordpress;
CREATE USER 'wp'@'%' IDENTIFIED BY 'hanbin0127';
GRANT ALL PRIVILEGES ON wordpress.* TO 'wp'@'localhost' IDENTIFIED BY 'hanbin0127';
FLUSH PRIVILEGES;

# 이름 비밀번호 환경변수로 처리해야 함
