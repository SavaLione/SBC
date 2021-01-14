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
 * @brief Cookie
 * @author SavaLione
 * @date 24 Nov 2020
 */
#ifndef WEB_COOKIE_H
#define WEB_COOKIE_H

#include <string>

/*
    Пара cookie
    key - ключ
    value - значение
    set - установлена ли пара?
*/
struct cookie_pair
{
    const std::string key;
    std::string value;
    bool set = false;
};

class cookie
{
public:
    cookie(){};
    cookie(std::string const &unprocessed_cookies) : _unprocessed_cookies(unprocessed_cookies) { _init(); };
    ~cookie();

    /* Получаем пару cookie uuid */
    cookie_pair get_uuid();

    /* Устанавливаем uuid */
    void set_uuid(cookie_pair const &uuid);

    /*
        Возвращаем строку вида:
        Set-Cookie: uuid=aa-bb-cc-dd; 
    */
    operator std::string();

private:
    /* 
        Необработанные cookie
        Строка вида:
        Cookie: username=SavaLione; uuid=aa-bb-cc-dd; some=Soome; 
    */
    std::string const _unprocessed_cookies;

    /* Разделитель cookie данных */
    char _separator = ';';

    /* Инициализация объекта. Получение cookie из строки. */
    void _init();

    /* Уникальный идентификатор пользователя */
    cookie_pair _uuid = {"uuid", "", false};

    cookie_pair _author = {"author", "SBC team", true};

    /* 
        Получение значения по ключу
        true - значение найдено и присвоено паре
        false - значение не найдено и не присвоено паре
    */
    void _get(cookie_pair &c);
};

#endif // WEB_COOKIE_H