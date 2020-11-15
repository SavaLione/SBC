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
 * @brief Settings
 * @author SavaLione
 * @date 04 Sep 2020
 */
#ifndef CORE_SETTINGS_H
#define CORE_SETTINGS_H

/*
    Usage:
    settings &instance = settings::Instance();
    instance.get();
*/

#include <string>

class settings
{
public:
    static settings &Instance()
    {
        static settings s;
        return s;
    }
    ~settings();

    int get_port();

    std::string get_db_host();
    std::string get_db_name();
    std::string get_db_username();
    std::string get_db_password();

private:
    settings();
    settings(settings const &) = delete;
    settings &operator=(settings const &) = delete;

    int _port = 1234;
    int _get_port();

    std::string _db_host = "tcp://192.168.1.70:3306";
    std::string _db_username = "test_mysql_user";
    std::string _db_password = "Ba6ctHKSPPmvDtYXNg1EddBGiJ1uF8qp";
    std::string _db_name = "test_mysql_db";

    std::string _get_db_host();
    std::string _get_db_name();
    std::string _get_db_username();
    std::string _get_db_password();
};

#endif // CORE_SETTINGS_H