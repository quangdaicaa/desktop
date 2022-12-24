docker network create \
  --driver bridge \
  www-net

docker run -d \
  --name php -h php \
  --network www-net \
  -v /home/quang/Desktop/doc/docker/vol_b1:/home/volume \
  php-fpm:8.2-alpine3.17

docker exec -it php sh
docker-php-ext-install mysqli
docker-php-ext-install pdo_mysql
exit
docker restart php

docker run -d \
  --name httpd -h httpd \
  -p 9999:80 -p 443:443 \
  --network www-net \
  -v /home/quang/Desktop/doc/docker/vol_b1:/home/volume \
  -v /home/quang/Desktop/doc/docker/vol_b1/wordpress_httpd.conf:/usr/local/apache2/conf/httpd.conf \
  httpd:2.4-alpine3.17

docker run \
  --name mysql -h mysql \
  -e MYSQL_ROOT_PASSWORD=abcd1234 \
  --network www-net \
  -v /home/quang/Desktop/doc/docker/vol_b1/wordpress_my.cnf:/etc/mysql/my.conf \
  -v /home/quang/Desktop/doc/docker/vol_b1/db:/var/lib/mysql \
  mysql:8.0-debian

docker exec -it mysql bash
mysql -uroot -pabcd1234
USE mysql;
CREATE USER 'testuser'@'%' IDENTIFIED BY 'testpass';
CREATE DATABASE wp_wordpress;
GRANT ALL PRIVILEGES ON wp_wordpress.* TO 'testuser'@'%';
SELECT User from user;
FLUSH PRIVILEGES;
exit
exit


Database Name: wp_wordpress
Username: testuser
Password: testpass
Database Host: mysql
Table Prefix: wp_

