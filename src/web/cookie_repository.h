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
 * @brief Cookie repository
 * @author SavaLione
 * @date 08 Dec 2020
 */
#ifndef WEB_COOKIE_REPOSITORY_H
#define WEB_COOKIE_REPOSITORY_H

#include <vector>

#include "core/user.h"

#include "web/cookie.h"

class cookie_repository
{
public:
    /* constructor */
    static cookie_repository &Instance()
    {
        static cookie_repository cookie_rep;
        return cookie_rep;
    }

    ~cookie_repository();

    /* functions */
    const void add_user(user &u);

    /* Данный uuid есть в базе? */
    bool have_user(std::string uuid);

    /* Получаем пользователя по uuid */
    user get_user(std::string uuid);



    const void remove_user(std::string uuid);

    void debug();

private:
    /* constructor */
    cookie_repository();
    cookie_repository(cookie_repository const &) = delete;
    cookie_repository &operator=(cookie_repository const &) = delete;

    /* variables */
    std::vector<user> _users;
};

#endif // WEB_COOKIE_REPOSITORY_H