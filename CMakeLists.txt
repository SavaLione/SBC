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

# flags
if(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++ -static -lpthread -O3 -fopenmp")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++ -lpthread -O3 -lncurses -fopenmp")
endif()

#configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/core/config.h.cmake ${CMAKE_CURRENT_SOURCE_DIR}/src/core/config.h)
#configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/resources/sql_console.rc.cmake ${CMAKE_CURRENT_SOURCE_DIR}/src/resources/sql_console.rc)
#configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/resources/sql_cli.rc.cmake ${CMAKE_CURRENT_SOURCE_DIR}/src/resources/sql_cli.rc)

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
#SET(Boost_COMPILER ${Boost_COMPILER} "-mgw8")
#SET(Boost_ARCHITECTURE "-x64")
find_package(Boost COMPONENTS system thread regex REQUIRED)
#find_package(Threads)

# protocol buffer
find_package(Protobuf REQUIRED)

set(SBC_CORE_SRC
    src/core/sbc.cpp
    src/core/settings.h
    src/core/settings.cpp
    src/core/blowfish.h
    src/core/user.h
    src/core/user.cpp
    src/core/digits.h
    src/core/digits.cpp
)

set(SBC_DB_SRC
    src/db/db_mysql.h
    src/db/db_mysql.cpp
    src/db/db_wrapper.h
    src/db/db_wrapper.cpp
)

set(SBC_NET_SRC
    src/net/server.h
    src/net/server.cpp
    src/net/session.h
    src/net/session.cpp
)

set(SBC_SRC
    ${SBC_CORE_SRC}
    ${SBC_DB_SRC}
    ${SBC_TUI_SRC}
    ${SBC_NET_SRC}
)

# protocol buffer src
set(SBC_PROTOBUFF_SRC
    src/proto/user_message.proto
)

PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS ${SBC_PROTOBUFF_SRC})

# executable
add_executable(${SBC_PROJECT} ${SBC_SRC} ${PROTO_SRCS} ${PROTO_HDRS})
target_include_directories(${SBC_PROJECT} PUBLIC ${PROJECT_SOURCE_DIR}/src)

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

# sqlite3
#add_subdirectory(${PROJECT_SOURCE_DIR}/lib/sqlite3)
#target_link_libraries(${SBC_PROJECT} SQLite3)
#target_include_directories(${SBC_PROJECT} PUBLIC ${PROJECT_SOURCE_DIR}/lib/sqlite3)

# sl-time
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/sl-time)
target_link_libraries(${SBC_PROJECT} sl-time)
target_include_directories(${SBC_PROJECT} PUBLIC ${PROJECT_SOURCE_DIR}/lib/sl-time/src)

#################################################################################
project(${SBC_CLIENT_PROJECT} VERSION ${SBC_CLIENT_PROJECT_VERSION})

set(SBC_CLIENT_CORE_SRC
    src/core/sbc_client.cpp
)

set(SBC_CLIENT_NET_SRC
    src/net/client.h
    src/net/client.cpp
)

set(SBC_CLIENT_SRC
    ${SBC_CLIENT_CORE_SRC}
    ${SBC_CLIENT_NET_SRC}
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