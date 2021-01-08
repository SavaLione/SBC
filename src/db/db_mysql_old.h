/*
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * Copyright (c) 2020, Savely Pototsky (SavaLione)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/**
 * @file
 * @brief Working with mysql database
 * @author SavaLione
 * @date 16 Nov 2020
 */
#ifndef DB_DB_MYSQL_H
#define DB_DB_MYSQL_H

// #include <string>
// #include <vector>

// /* Standard C++ includes */
// #include <stdlib.h>
// #include <iostream>

// /*
//     Include directly the different
//     headers from cppconn/ and mysql_driver.h + mysql_util.h
//     (and mysql_connection.h)
// */
// #include <mysql_connection.h>

// #include <cppconn/driver.h>
// #include <cppconn/exception.h>
// #include <cppconn/resultset.h>
// #include <cppconn/statement.h>

// class db_mysql
// {
// public:
//     db_mysql();
//     ~db_mysql();
//     // void run();
//     void runc();
//     const bool has(std::string const &table_name, std::string const &column_name, std::string const &data);
//     const bool add(std::string const &table_name, std::vector<std::string> const &column_names, std::vector<std::string> const &data);
//     const std::string get_string(std::string const &table_name, std::string const &column_name, std::string const &where);

//     std::vector<std::string> vec_answer(std::string const &table_name, std::vector<std::string> const &column_names,  std::string const &where); /* TODO */

// private:
//     sql::Connection *con;
//     sql::Statement *stmt;
// };

#endif // DB_DB_MYSQL_H