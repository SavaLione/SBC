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
 * @brief Реализация вспомогательных функций для table_template
 * @author SavaLione
 * @date 13 Jan 2021
 */
#ifndef DB_TABLE_TEMPLATE_IMPL_H
#define DB_TABLE_TEMPLATE_IMPL_H

#include <regex>

/* Преобразование массива в вектор */
template <typename T>
void extract_integers(std::string const &str, std::vector<T> &result)
{
    result.clear();
    using re_iterator = std::regex_iterator<std::string::const_iterator>;
    using re_iterated = re_iterator::value_type;
    std::regex re("([\\+\\-]?\\d+)");
    re_iterator rit(str.begin(), str.end(), re), rend;
    std::transform(rit, rend, std::back_inserter(result), [](const re_iterated &it) { return std::stoi(it[1]); });
}

/* Преобразование вуктора в массив */
template <typename T>
void split_integers(std::string &str, std::vector<T> const &arr)
{
    str = "{";
    if (arr.size())
    {
        str += std::accumulate(arr.begin() + 1, arr.end(), std::to_string(arr[0]), [](const std::string &a, T b) { return a + ',' + std::to_string(b); });
    }
    str += "}";
}

#endif // DB_TABLE_TEMPLATE_IMPL_H