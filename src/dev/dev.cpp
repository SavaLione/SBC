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
 * @brief Дополнительные инструменты для разработки проекта sbc
 * @author SavaLione
 * @date 12 Jan 2021
 */
#include "dev/dev.h"

#include <iostream>
#include <vector>
#include <fstream>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: dev index.html" << std::endl;
        exit(1);
    }

    parse(argv[1]);

    return 0;
}

std::string vec_to_string(std::vector<std::string> const &vec)
{
    std::string result = "";

    for (int i = 0; i < vec.size(); i++)
    {
        result += vec[i];
        result += "\n";
    }

    return result;
}

void parse(std::string const &file_name)
{
    std::string result_file_name = file_name;
    result_file_name += ".txt";

    std::vector<std::string> vec_file, vec_new_file;

    /* Получаем файл */
    try
    {
        std::ifstream file(file_name);

        std::string s = "";

        while (getline(file, s))
        {
            vec_file.push_back(s);
        }

        file.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < vec_file.size(); i++)
    {
        std::string s = "";

        bool is_line_empty = true;
        for (int z = 0; z < vec_file[i].size(); z++)
        {
            if (vec_file[i][z] != ' ')
            {
                is_line_empty = false;
            }
        }

        if (!is_line_empty)
        {
            s += "_add_content(\"";
            for (int z = 0; z < vec_file[i].size(); z++)
            {
                if (vec_file[i][z] == '\"')
                {
                    s += "\\\"";
                }
                else if (vec_file[i][z] == '\\')
                {
                    s += "\\\\";
                }
                else
                {
                    s += vec_file[i][z];
                }
            }
            s += "\");";
        }

        vec_new_file.push_back(s);
    }

    /* Создаём новый файл */
    try
    {
        std::ofstream file(result_file_name);

        file << vec_to_string(vec_new_file);

        file.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}