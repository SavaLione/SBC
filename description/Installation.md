# Установка проекта SBC (Scanning bar codes)
Проект разделён на несколько частей:
* sbc - Сервер
* sbc-client - Консольный клиент
* sbc-tests - Автоматические тесты
* sbc-dev - Дополнительные инструменты для разработки проекта sbc

Стандартные порты:
* 9000  - FastCGI (web интерфейс)
* 12340 - Порт sbc сервера

## Зависимости
### sbc
* C++ (c++11 и выше)
* gcc (тестировалось на версии 9.3.0)
* CMake 3.13.1+ (только на время сборки проекта)
* Boost 1.71.0+
* Threads (поставляется с gcc)
* Protocol Buffers (тестировалось на версии 3.14.0)
* SQLite3 (для поддержки sqlite)
* spdlog (тестировалось на версии 1:1.5.0-1)
* SOCI 4.0+
* OpenSSL (тестировалось на версии 1.1.1f)
* FastCGI (libfcgi) (тестировалось на версии 2.4.0-10build1)

### sbc-client
* C++ (c++11 и выше)
* gcc (тестировалось на версии 9.3.0)
* CMake 3.13.1+ (только на время сборки проекта)
* Boost 1.71.0+

### sbc-tests
* C++ (c++11 и выше)
* gcc (тестировалось на версии 9.3.0)
* CMake 3.13.1+ (только на время сборки проекта)
* Boost 1.71.0+
* Threads (поставляется с gcc)
* Protocol Buffers (тестировалось на версии 3.14.0)
* SQLite3 (для поддержки sqlite)
* spdlog (тестировалось на версии 1:1.5.0-1)
* SOCI 4.0+
* OpenSSL (тестировалось на версии 1.1.1f)
* FastCGI (libfcgi) (тестировалось на версии 2.4.0-10build1)
* Google C++ Testing Framework (gtest) (тестировалось на версии 1.10.0-2)

### dev
* C++ (c++11 и выше)
* gcc (тестировалось на версии 9.3.0)
* CMake 3.13.1+ (только на время сборки проекта)

## Установка зависимостей (ubuntu)
Перед установкой пакетов желательно обновить список пакетов:
```sh
sudo apt update
```

```
-j4 после команды make означает, что компилируем проект 4 процессорными ядрами
4 можно заменить на любое число. Также можно вовсе убрать -j4
```

### gcc
```sh
sudo apt install build-essential
```

### CMake
```sh
sudo apt install cmake
```

### Boost
```sh
sudo apt install libboost-all-dev
```

### Protocol Buffers
```sh
sudo apt install autoconf automake libtool curl make g++ unzip
git clone https://github.com/protocolbuffers/protobuf.git
cd protobuf
git submodule update --init --recursive
./autogen.sh
./configure
make -j4
make check
sudo make install
sudo ldconfig
```

### SQLite3 (для поддержки sqlite)
```sh
sudo apt install sqlite3 libsqlite3-dev
```

### spdlog
```sh
sudo apt install libspdlog-dev
```

### SOCI
```sh
git clone https://github.com/SOCI/soci.git
cd soci && mkdir build
cd build
cmake .. -DSOCI_CXX11=ON -DWITH_BOOST=ON
make -j4
sudo make install

sudo cp /usr/local/lib64/libsoci_core.a /usr/local/lib/libsoci_core.a
sudo cp /usr/local/lib64/libsoci_empty.a /usr/local/lib/libsoci_empty.a
sudo cp /usr/local/lib64/libsoci_sqlite3.a /usr/local/lib/libsoci_sqlite3.a
sudo ln -s /usr/local/lib64/libsoci_core.so  /usr/local/lib/libsoci_core.so
sudo ln -s /usr/local/lib64/libsoci_empty.so /usr/local/lib/libsoci_empty.so
sudo ln -s /usr/local/lib64/libsoci_sqlite3.so /usr/local/lib/libsoci_sqlite3.so

sudo ln -s /usr/local/lib64/libsoci_core.so.4.0 /usr/local/lib/libsoci_core.so.4.0
sudo ln -s /usr/local/lib64/libsoci_empty.so.4.0 /usr/local/lib/libsoci_empty.so.4.0
sudo ln -s /usr/local/lib64/libsoci_sqlite3.so.4.0 /usr/local/lib/libsoci_sqlite3.so.4.0

sudo ldconfig
```

### OpenSSL
```sh
sudo apt install libssl-dev
```

### Google C++ Testing Framework (gtest)
```sh
sudo apt install libgtest-dev
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make -j4

sudo cp *.a /usr/lib
sudo ln -s /usr/lib/libgtest.a /usr/local/lib/gtest/libgtest.a
sudo ln -s /usr/lib/libgtest_main.a /usr/local/lib/gtest/libgtest_main.a
```

### FastCGI (libfcgi)
```sh
sudo pat install libfcgi-dev
```

## Установка проекта sbc (*nix)
```sh
git clone https://github.com/SavaLione/SBC.git
cd SBC
mkdir build
cd build
cmake ..
make -j4
```

Для сборки автоматических тестов ```sbc``` нужно указать дополнительный флаг ```-DSBC_PROJECT_TESTS=on```

Для сборки автоматических тестов ```sbc-client``` нужно указать дополнительный флаг ```-DSBC_CLIENT_TESTS=on```

Для сборки автоматических тестов ```dev``` нужно указать дополнительный флаг ```-DSBC_DEV_TESTS=on```

Для сборки ```dev``` нужно указать дополнительный флаг ```-DSBC_PROJECT_DEV=on```

Пример:
```sh
cmake .. -DSBC_PROJECT_TESTS=on -DSBC_CLIENT_TESTS=on
```

## Установка проекта sbc (windows)
Установка проекта под Windows возможна, но необходимо собрать все библиотеки с использованием MinGW64

# Установка web интерфейса
## Зависимости
* nginx или apache
* FastCGI (libfcgi)

## Установка зависимостей (ubuntu)
### nginx (если предполагается использование nginx web сервера)
```sh
sudo apt install nginx
```

### apache (если предполагается использование apache web сервера)
```sh
sudo apt install apache2
```

### FastCGI (libfcgi)
```sh
sudo pat install libfcgi-dev
```

## Установка web интерфейса проекта sbc
Необходимо разместить дополнительные материалы (assets) по пути ```/assets``` (путь от домена)

Веб серверу нужно указать путь к FastCGI порту

### Пример конфигурации nginx
```
server {
        listen 80 default_server;
        listen [::]:80 default_server;

        root /home/savalione/www/assets;

        index index.html index.htm index.nginx-debian.html;

        server_name _;

        location /assets {
                try_files $uri $uri/ =404;
        }

        location / {
                fastcgi_pass 127.0.0.1:9000;

                include fastcgi_params;
        }
}
```

# Сборка документации к проекту (не обязательно)
## Зависимости
* Doxygen
* Graphviz (не обязательно)

## Установка зависимостей
### Doxygen
```sh
sudo apt install doxygen
```

### Graphviz (не обязательно)
```sh
sudo apt install graphviz
```

## Сборка документации
```sh
doxygen
```