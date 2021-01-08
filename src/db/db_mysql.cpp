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
 * @brief Working with MySQL(MariaDB) database
 * @author SavaLione
 * @date 17 Nov 2020
 */
// #include "db/db_mysql.h"

// #include "core/settings.h"

// db_mysql::db_mysql()
// {
//     settings &settings_instance = settings::Instance();

//     _host = settings_instance.db_host();
//     _username = settings_instance.db_username();
//     _password = settings_instance.db_password();
//     _name = settings_instance.db_name();

//     // cout << "Connect to db" << endl;
//     try
//     {
//         sql::Driver *driver;
//         driver = get_driver_instance();
//         con = driver->connect(_host, _username, _password);
//         con->setSchema(_name);
//         stmt = con->createStatement();
//         _open = true;
//     }
//     catch (sql::SQLException &e)
//     {
//         // cout << "# ERR: SQLException in " << __FILE__;
//         // cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
//         // cout << "# ERR: " << e.what();
//         // cout << " (MySQL error code: " << e.getErrorCode();
//         // cout << ", SQLState: " << e.getSQLState() << " )" << endl;
//         _open = false;
//     }
// }

// db_mysql::~db_mysql()
// {
//     delete stmt;
//     delete con;
//     _open = false;
// }

// bool db_mysql::answer(std::string const &request, std::vector<std::string> &return_data)
// {
//     std::vector<std::string> ret;

    
// }