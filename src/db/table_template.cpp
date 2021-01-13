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
#include "db/table_template.h"

#include "io/logger.h"

table_template::table_template()
{
}

table_template::~table_template()
{
}

void table_template::clear()
{
    id = 0;
}

void table_template::print()
{
    spdlog::debug("table_template::print()");
    spdlog::debug("id: {}", id);
}

table_template &table_template::operator=(table_template const &rhs)
{
    if (this != &rhs)
    {
        id = rhs.id;
    }
    return *this;
}

template <>
struct soci::type_conversion<table_template>
{
    typedef values base_type;

    static void from_base(values const &v, indicator ind, table_template &p)
    {
        if (ind == i_null)
        {
            return;
        }

        try
        {
            p.id = v.get<int>("id", 0);
        }
        catch (std::exception const &e)
        {
            spdlog::error(e.what());
        }
    }

    static void to_base(table_template const &p, values &v, indicator &ind)
    {
        try
        {
            v.set("id", p.id);

            ind = i_ok;
            return;
        }
        catch (std::exception const &e)
        {
            spdlog::error(e.what());
        }
        ind = i_null;
    }
};