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
 * @brief sbc-client
 * @author SavaLione
 * @date 15 Nov 2020
 */

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <boost/asio.hpp>

#include <string>

using boost::asio::ip::tcp;

void get_line(std::string const &name, std::string &result);
std::string hide_password(std::string const &password);

enum
{
    max_length = 16 * 1024
};

int main(int argc, char *argv[])
{
    std::string username = "";
    std::string password = "";
    std::string str_request = "";

    try
    {
        if (argc != 3)
        {
            std::cerr << "Usage: sbc-client <host> <port>\n";
            return 1;
        }

        std::cout << "Enter your username and password" << std::endl;

        get_line("username: ", username);
        get_line("password: ", password);

        std::cout << std::endl << "username: [" << username << "] password: [" << hide_password(password) << "]" << std::endl << std::endl;

        get_line("request: ", str_request);

        std::cout << std::endl << "request: [" << str_request << "]" << std::endl << std::endl;

        boost::asio::io_service io_service;

        tcp::resolver resolver(io_service);
        tcp::resolver::query query(tcp::v4(), argv[1], argv[2]);
        tcp::resolver::iterator iterator = resolver.resolve(query);

        tcp::socket s(io_service);
        boost::asio::connect(s, iterator);

        // std::cout << "Enter message: ";
        // char request[max_length];
        // std::cin.getline(request, max_length);
        // size_t request_length = std::strlen(request);
        // boost::asio::write(s, boost::asio::buffer(request, request_length));

        char request[max_length];
        for (int i = 0; i < str_request.size && i < max_length; i++)
        {
            request[i] = str_request[i];
        }
        size_t request_length = std::strlen(request);
        boost::asio::write(s, boost::asio::buffer(request, request_length));

        char reply[max_length];
        size_t reply_length = boost::asio::read(s, boost::asio::buffer(reply, request_length));
        std::cout << "Reply is: ";
        std::cout.write(reply, reply_length);
        std::cout << "\n";
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}

/* Получаем строку от пользователя */
void get_line(std::string const &name, std::string &result)
{
    for (std::string line; std::cout << name && std::getline(std::cin, line);)
    {
        if (!line.empty())
        {
            result = line;
            break;
        }
    }
}

/* Скрываем пароль при выводе */
std::string hide_password(std::string const &password)
{
    std::string result = "";
    for (int i = 0; i < password.size(); i++)
    {
        result += "*";
    }
    return result;
}