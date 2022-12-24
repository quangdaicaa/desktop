docker pull php:8.2.1RC1-fpm-alpine3.17
docker pull httpd:2.4.54-alpine3.17
docker pull busybox:stable-glibc
docker pull mcr.microsoft.com/mssql/server:latest
docker pull mysql:8.0.31-debian

docker tag php:8.2.1RC1-fpm-alpine3.17 php-fpm:8.2-alpine3.17
docker tag httpd:2.4.54-alpine3.17 httpd:2.4-alpine3.17
docker tag busybox:stable-glibc busybox:glibc
docker tag mcr.microsoft.com/mssql/server:latest mssql:latest
docker tag mysql:8.0.31-debian mysql:8.0-debian

docker image rm mcr.microsoft.com/mssql/server:latest
docker image rm busybox:stable-glibc
docker image rm httpd:2.4.54-alpine3.17
docker image rm php:8.2.1RC1-fpm-alpine3.17
docker image rm mysql:8.0.31-debian

