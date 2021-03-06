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
 * @brief Тип журнала базы данных SQLite
 * @author SavaLione
 * @date 12 Dec 2020
 */
#ifndef DB_SQLITE_SQLITE_JOURNAL_MODE_H
#define DB_SQLITE_SQLITE_JOURNAL_MODE_H

#include <string>

enum sqlite_journal_mode
{
    SQLITE_JOURNAL_MODE_DELETE,
    SQLITE_JOURNAL_MODE_TRUNCATE,
    SQLITE_JOURNAL_MODE_PERSIST,
    SQLITE_JOURNAL_MODE_MEMORY,
    SQLITE_JOURNAL_MODE_WAL,
    SQLITE_JOURNAL_MODE_OFF
};

/* Получить строковое представление типа журнала sqlite */
const std::string string_sqlite_journal_mode(sqlite_journal_mode const &journal_mode);

/* Получить строку с параметром для sqlite */
const std::string get_sqlite_journal_mode(sqlite_journal_mode const &journal_mode);

#endif // DB_SQLITE_SQLITE_JOURNAL_MODE_H