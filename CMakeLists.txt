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

set(SBC_CORE_SRC
    src/core/sbc_server.cpp
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
    src/db/db_sqlite.h
    src/db/db_sqlite.cpp
    src/db/db_mysql.h
    src/db/db_mysql.cpp
    src/db/db_mariadb.h
    src/db/db_mariadb.cpp
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
add_executable(${SBC_PROJECT} ${SBC_SRC} ${PROTO_SRCS} ${PROTO_HDRS})
target_include_directories(${SBC_PROJECT} PUBLIC ${PROJECT_SOURCE_DIR}/src)

if(Threads_FOUND)
    # Threads
    target_link_libraries(${SBC_PROJECT} Threads::Threads)
endif()

if(Boost_FOUND)
    target_include_directories(${SBC_PROJECT} PUBLIC ${Boost_INCLUDE_DIRS})
    target_link_libraries(${SBC_PROJECT} ${Boost_LIBRARIES})
endif()

if(UNIX)
    target_include_directories(${SBC_PROJECT} PUBLIC /usr/include)
    target_link_libraries(${SBC_PROJECT} mysqlcppconn)
endif()

if(Protobuf_FOUND)
    target_include_directories(${SBC_PROJECT} PUBLIC ${PROTOBUF_INCLUDE_DIRS})
    target_include_directories(${SBC_PROJECT} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
    target_link_libraries(${SBC_PROJECT} ${Protobuf_LIBRARY})
endif()

if(SQLite3_FOUND)
    target_include_directories(${SBC_PROJECT} PUBLIC ${SQLite3_INCLUDE_DIRS})
    target_link_libraries (${SBC_PROJECT} ${SQLite3_LIBRARIES})
endif()

# fcgi
target_link_libraries(${SBC_PROJECT} fcgi)

# spdlog
target_link_libraries(${SBC_PROJECT} spdlog::spdlog)

# Soci
if(SOCI_FOUND)
    target_include_directories(${SBC_PROJECT} PUBLIC ${SOCI_INCLUDE_DIRS})
    target_link_libraries (${SBC_PROJECT} ${SOCI_LIBRARY})
endif()

#################################################################################
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