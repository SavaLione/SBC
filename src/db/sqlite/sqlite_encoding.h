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
 * @brief Кодировка базы данных SQLite
 * @author SavaLione
 * @date 12 Dec 2020
 */
#ifndef DB_SQLITE_SQLITE_ENCODING_H
#define DB_SQLITE_SQLITE_ENCODING_H

#include <string>

/*
    In first form, if the main database has already been created, then this pragma
    returns the text encoding used by the main database, one of 'UTF-8',
    'UTF-16le' (little-endian UTF-16 encoding) or
    'UTF-16be' (big-endian UTF-16 encoding).
    If the main database has not already been created, then the value returned is the
    text encoding that will be used to create the main database, if it is created by this session.

    The second through fifth forms of this pragma set the encoding that the main database will
    be created with if it is created by this session. The string 'UTF-16' is interpreted as
    "UTF-16 encoding using native machine byte-ordering". It is not possible to change the text
    encoding of a database after it has been created and any attempt to do so will be silently ignored.

    Once an encoding has been set for a database, it cannot be changed.

    Databases created by the ATTACH command always use the same encoding as the main database.
    An attempt to ATTACH a database with a different text encoding from the "main" database will fail.
*/
enum sqlite_encoding
{
    SQLITE_ENCODING_UTF_8,
    SQLITE_ENCODING_UTF_16,
    SQLITE_ENCODING_UTF_16_LE,
    SQLITE_ENCODING_UTF_16_BE
};

/* Получить строковое представление кодировки sqlite */
const std::string string_sqlite_encoding(sqlite_encoding const &encoding);

/* Получить строку с параметром для sqlite */
const std::string get_sqlite_encoding(sqlite_encoding const &encoding);

#endif // DB_SQLITE_SQLITE_ENCODING_H