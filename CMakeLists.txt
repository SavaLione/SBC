#################################################################################
# Copyright (c) 2020, Savely Pototsky (SavaLione)
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. Neither the name of the copyright holder nor the names of its contributors
#    may be used to endorse or promote products derived from this software
#    without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS "AS IS" AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.
#################################################################################
# Checking the minimum version
cmake_minimum_required (VERSION 3.13.1)

set(SBC_PROJECT "sbc")
set(SBC_PROJECT_VERSION "0.0.1")

set(SBC_CLIENT_PROJECT "sbc-client")
set(SBC_CLIENT_PROJECT_VERSION "0.0.1")

# examples
option(SBC_PROJECT_EXAMPLES "${SBC_PROJECT}. Build examples" OFF)
option(SBC_CLIENT_EXAMPLES  "${SBC_CLIENT}. Build examples" OFF)

# tests
option(SBC_PROJECT_TESTS "${SBC_PROJECT}. Build tests" OFF)
option(SBC_CLIENT_TESTS  "${SBC_CLIENT}. Build tests" OFF)

set(SBC_TESTS_ENABLED 0)

if(SBC_PROJECT_TESTS OR SBC_CLIENT_TESTS)
    set(SBC_TESTS_ENABLED 1)
else()
    set(SBC_TESTS_ENABLED 0)
endif()

# custom modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

project(${SBC_PROJECT}
    VERSION ${SBC_PROJECT_VERSION}
    LANGUAGES C CXX
)

# boost c++
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREAD ON)
set(Boost_USE_DEBUG_LIBS OFF)
set(Boost_USE_RELEASE_LIBS ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost COMPONENTS system thread regex REQUIRED)

# Threads
find_package(Threads REQUIRED)

# Protocol Buffer
find_package(Protobuf REQUIRED)

# SQLite3
find_package(SQLite3 REQUIRED)

# spdlog
find_package(spdlog REQUIRED)

# Soci
find_package(Soci REQUIRED)

# OpenSSL
find_package(OpenSSL REQUIRED)

# gtest
if(SBC_TESTS_ENABLED)
    find_package(GTest REQUIRED)
endif()

################################################################################# sbc

set(SBC_CORE_MAIN_SRC
    src/core/sbc_server.cpp
)

set(SBC_CORE_SRC
    src/core/blowfish.h
    src/core/blowfish.cpp
    src/core/settings.h
    src/core/settings.cpp
    src/core/uuid.h
    src/core/uuid.cpp
    src/core/user.h
    src/core/user.cpp
    src/core/user_handler.h
    src/core/user_handler.cpp
    src/core/user_role.h
    src/core/user_role.cpp
    src/core/user_status.h
    src/core/user_status.cpp
    src/core/sha.h
    src/core/sha.cpp
)

set(SBC_IO_SRC
    src/io/logger.h
    src/io/logger.cpp
)

set(SBC_NET_SRC
    src/net/server.h
    src/net/server.cpp
    src/net/session.h
    src/net/session.cpp
)

set(SBC_PLATFORM_SRC
    src/platform/platform.h
    src/platform/platform.cpp
)

set(SBC_DB_SQLITE_SRC
    src/db/sqlite/sqlite_encoding.cpp
    src/db/sqlite/sqlite_encoding.h
    src/db/sqlite/sqlite_journal_mode.cpp
    src/db/sqlite/sqlite_journal_mode.h
    src/db/sqlite/sqlite_synchronous.cpp
    src/db/sqlite/sqlite_synchronous.h
)

set(SBC_DB_SRC
    src/db/db.h
    src/db/db.cpp
    src/db/db_pool.h
    src/db/db_pool.cpp
    ${SBC_DB_SQLITE_SRC}
)

set(SBC_TIME_SRC
    src/time/current_time.h
    src/time/current_time.cpp
    src/time/execution_time.h
    src/time/execution_time.cpp
    src/time/wait_time.h
    src/time/wait_time.cpp
)

set(SBC_WEB_PAGES_SRC
	src/web/pages/about.cpp
	src/web/pages/about.h
	src/web/pages/index.cpp
	src/web/pages/index.h
	src/web/pages/login.cpp
	src/web/pages/login.h
	src/web/pages/nologin.cpp
	src/web/pages/nologin.h
	src/web/pages/page_template.cpp
	src/web/pages/page_template.h
	src/web/pages/registration.cpp
    src/web/pages/registration.h
    src/web/pages/not_found.h
    src/web/pages/not_found.cpp
    src/web/pages/test_page.h
    src/web/pages/test_page.cpp
)

set(SBC_WEB_SRC
    src/web/web.h
    src/web/web.cpp
    src/web/page.h
    src/web/page.cpp
    src/web/mime.h
    src/web/mime.cpp
    src/web/cookie.h
    src/web/cookie.cpp
    src/web/method.h
    src/web/method.cpp
    src/web/request_handler.h
    src/web/request_handler.cpp
    src/web/cookie_repository.h
    src/web/cookie_repository.cpp
    src/web/post.h
    src/web/post.cpp
    src/web/url.h
    src/web/url.cpp
    ${SBC_WEB_PAGES_SRC}
)

set(SBC_SRC
    ${SBC_CORE_SRC}
    ${SBC_IO_SRC}
    ${SBC_NET_SRC}
    ${SBC_PLATFORM_SRC}
    ${SBC_DB_SRC}
    ${SBC_TIME_SRC}
    ${SBC_WEB_SRC}
)

# protocol buffer src
set(SBC_PROTOBUFF_SRC
    src/proto/data.proto
)

PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS ${SBC_PROTOBUFF_SRC})

# executable
add_executable(${SBC_PROJECT} ${SBC_SRC} ${SBC_CORE_MAIN_SRC} ${PROTO_SRCS} ${PROTO_HDRS})
target_include_directories(${SBC_PROJECT} PUBLIC ${PROJECT_SOURCE_DIR}/src)

# Threads
if(Threads_FOUND)
    target_link_libraries(${SBC_PROJECT} Threads::Threads)
endif()

# Boost
if(Boost_FOUND)
    target_include_directories(${SBC_PROJECT} PUBLIC ${Boost_INCLUDE_DIRS})
    target_link_libraries(${SBC_PROJECT} ${Boost_LIBRARIES})
endif()

# UNIX
if(UNIX)
    target_include_directories(${SBC_PROJECT} PUBLIC /usr/include)
#    target_link_libraries(${SBC_PROJECT} mysqlcppconn)
endif()

# Protocol buffer
if(Protobuf_FOUND)
    target_include_directories(${SBC_PROJECT} PUBLIC ${PROTOBUF_INCLUDE_DIRS})
    target_include_directories(${SBC_PROJECT} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
    target_link_libraries(${SBC_PROJECT} ${Protobuf_LIBRARY})
endif()

# SQLite
if(SQLite3_FOUND)
    target_include_directories(${SBC_PROJECT} PUBLIC ${SQLite3_INCLUDE_DIRS})
    target_link_libraries(${SBC_PROJECT} ${SQLite3_LIBRARIES})
endif()

# fcgi
target_link_libraries(${SBC_PROJECT} fcgi)

# spdlog
target_link_libraries(${SBC_PROJECT} spdlog::spdlog)

# OpenSSL
if(OPENSSL_FOUND)
    target_include_directories(${SBC_PROJECT} PUBLIC ${OPENSSL_INCLUDE_DIR})
    target_link_libraries(${SBC_PROJECT} ${OPENSSL_LIBRARIES})
endif()

# Soci
if(SOCI_FOUND)
    target_include_directories(${SBC_PROJECT} PUBLIC ${SOCI_INCLUDE_DIRS})
    target_link_libraries(${SBC_PROJECT} ${SOCI_LIBRARY} ${SOCI_sqlite3_PLUGIN})
endif()

################################################################################# sbc-client
project(${SBC_CLIENT_PROJECT} VERSION ${SBC_CLIENT_PROJECT_VERSION})

set(SBC_CLIENT_CORE_SRC
    src/core/sbc_client.cpp
)

set(SBC_CLIENT_SRC
    ${SBC_CLIENT_CORE_SRC}
)

# executable
add_executable(${SBC_CLIENT_PROJECT} ${SBC_CLIENT_SRC} ${PROTO_SRCS} ${PROTO_HDRS})
target_include_directories(${SBC_CLIENT_PROJECT} PUBLIC ${PROJECT_SOURCE_DIR}/src)

if(Boost_FOUND)
    target_include_directories(${SBC_CLIENT_PROJECT} PUBLIC ${Boost_INCLUDE_DIRS})
    target_link_libraries(${SBC_CLIENT_PROJECT} ${Boost_LIBRARIES})
endif()

if(Protobuf_FOUND)
    target_include_directories(${SBC_CLIENT_PROJECT} PUBLIC ${PROTOBUF_INCLUDE_DIRS})
    target_include_directories(${SBC_CLIENT_PROJECT} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
    target_link_libraries(${SBC_CLIENT_PROJECT} ${Protobuf_LIBRARY})
endif()

# OpenSSL
if(OPENSSL_FOUND)
    target_include_directories(${SBC_PROJECT} PUBLIC ${OPENSSL_INCLUDE_DIR})
    target_link_libraries(${SBC_PROJECT} ${OPENSSL_LIBRARIES})
endif()

################################################################################# sbc-db-test
project(sbc-db-test)

set(SBC_DB_TEST_SRC
    src/test/sbc_db_test.h
    src/test/sbc_db_test.cpp
    src/time/current_time.h
    src/time/current_time.cpp
    src/time/execution_time.h
    src/time/execution_time.cpp
    src/time/wait_time.h
    src/time/wait_time.cpp
)

# executable
add_executable(sbc-db-test ${SBC_DB_TEST_SRC})
target_include_directories(sbc-db-test PUBLIC ${PROJECT_SOURCE_DIR}/src)

if(Threads_FOUND)
    # Threads
    target_link_libraries(sbc-db-test Threads::Threads)
endif()

if(Boost_FOUND)
    target_include_directories(sbc-db-test PUBLIC ${Boost_INCLUDE_DIRS})
    target_link_libraries(sbc-db-test ${Boost_LIBRARIES})
endif()

if(UNIX)
    target_include_directories(sbc-db-test PUBLIC /usr/include)
    target_link_libraries(sbc-db-test mysqlcppconn)
endif()

# spdlog
target_link_libraries(sbc-db-test spdlog::spdlog)

# Soci
if(SOCI_FOUND)
    target_include_directories(sbc-db-test PUBLIC ${SOCI_INCLUDE_DIRS})
    target_link_libraries (sbc-db-test ${SOCI_LIBRARY} ${SOCI_sqlite3_PLUGIN})
endif()

if(SQLite3_FOUND)
    target_include_directories(sbc-db-test PUBLIC ${SQLite3_INCLUDE_DIRS})
    target_link_libraries (sbc-db-test ${SQLite3_LIBRARIES})
endif()

################################################################################# sbc - tests
if(SBC_PROJECT_TESTS)
    set(SBC_PROJECT_TESTS_NAME "${SBC_PROJECT}-tests")
    project(${SBC_PROJECT_TESTS_NAME})

    set(SBC_PROJECT_TESTS_MAIN_SRC
        tests/sbc_tests.h
        tests/sbc_tests.cpp
        tests/blowfish_test.h
        tests/blowfish_test.cpp
        tests/settings_test.h
        tests/settings_test.cpp
        tests/uuid_test.h
        tests/uuid_test.cpp
        tests/sha_test.h
        tests/sha_test.cpp
    )

    # executable
    add_executable(${SBC_PROJECT_TESTS_NAME} ${SBC_SRC} ${SBC_PROJECT_TESTS_MAIN_SRC} ${PROTO_SRCS} ${PROTO_HDRS})
    target_include_directories(${SBC_PROJECT_TESTS_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src)
    target_include_directories(${SBC_PROJECT_TESTS_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/tests)
    target_include_directories(${SBC_PROJECT_TESTS_NAME} PUBLIC ${GTEST_INCLUDE_DIRS})

    # Threads
    if(Threads_FOUND)
        target_link_libraries(${SBC_PROJECT_TESTS_NAME} Threads::Threads)
    endif()

    # Boost
    if(Boost_FOUND)
        target_include_directories(${SBC_PROJECT_TESTS_NAME} PUBLIC ${Boost_INCLUDE_DIRS})
        target_link_libraries(${SBC_PROJECT} ${Boost_LIBRARIES})
    endif()

    # UNIX
    if(UNIX)
        target_include_directories(${SBC_PROJECT_TESTS_NAME} PUBLIC /usr/include)
#       target_link_libraries(${SBC_PROJECT_TESTS_NAME} mysqlcppconn)
    endif()

    # Protocol buffer
    if(Protobuf_FOUND)
        target_include_directories(${SBC_PROJECT_TESTS_NAME} PUBLIC ${PROTOBUF_INCLUDE_DIRS})
        target_include_directories(${SBC_PROJECT_TESTS_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
        target_link_libraries(${SBC_PROJECT_TESTS_NAME} ${Protobuf_LIBRARY})
    endif()

    # SQLite
    if(SQLite3_FOUND)
        target_include_directories(${SBC_PROJECT_TESTS_NAME} PUBLIC ${SQLite3_INCLUDE_DIRS})
        target_link_libraries (${SBC_PROJECT_TESTS_NAME} ${SQLite3_LIBRARIES})
    endif()

    # fcgi
    target_link_libraries(${SBC_PROJECT_TESTS_NAME} fcgi)

    # spdlog
    target_link_libraries(${SBC_PROJECT_TESTS_NAME} spdlog::spdlog)

    # Soci
    if(SOCI_FOUND)
        target_include_directories(${SBC_PROJECT_TESTS_NAME} PUBLIC ${SOCI_INCLUDE_DIRS})
        target_link_libraries (${SBC_PROJECT_TESTS_NAME} ${SOCI_LIBRARY} ${SOCI_sqlite3_PLUGIN})
    endif()

    # OpenSSL
    if(OPENSSL_FOUND)
        target_include_directories(${SBC_PROJECT_TESTS_NAME} PUBLIC ${OPENSSL_INCLUDE_DIR})
        target_link_libraries(${SBC_PROJECT_TESTS_NAME} ${OPENSSL_LIBRARIES})
    endif()

    # gtest
    target_link_libraries(${SBC_PROJECT_TESTS_NAME} ${GTEST_LIBRARIES})

endif()