/*
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
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
 * @brief Шаблон структуры для работы с базой данных
 * @author SavaLione
 * @date 13 Jan 2021
 */
#ifndef DB_TABLE_TEMPLATE_H
#define DB_TABLE_TEMPLATE_H

#include <string>
#include <vector>

#include "db/table_template_impl.h"

#include "db/db_pool.h"

/* Преобразование массива в вектор */
template <typename T>
void extract_integers(std::string const &str, std::vector<T> &result);

/* Преобразование вуктора в массив */
template <typename T>
void split_integers(std::string &str, std::vector<T> const &arr);

class table_template
{
public:
    /* id. Есть в каждой таблице */
    int id = 0;

    table_template();
    ~table_template();

    virtual void clear();
    virtual void print();

    virtual table_template &operator=(table_template const &rhs);
};

namespace soci
{
    template <>
    struct type_conversion<table_template>;

} // namespace soci

#endif // DB_TABLE_TEMPLATE_H