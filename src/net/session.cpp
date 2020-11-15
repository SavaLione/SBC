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
 * @brief Session
 * @author SavaLione
 * @date 08 Sep 2020
 */
#include "net/session.h"

#include "db/db_wrapper.h"

#include <user_message.pb.h>

#include <iostream>

void session::start()
{
    std::cout << "start()" << std::endl;
    do_read();
}

void session::do_read()
{
    std::cout << "do_read()" << std::endl;
    auto self(shared_from_this());
    socket_.async_read_some(boost::asio::buffer(data_, max_length),
                            [this, self](boost::system::error_code ec, std::size_t length) {
                                if (!ec)
                                {
                                    // db_wrapper &instance = db_wrapper::Instance();
                                    sl::sbc::message::Message msg;
                                    if (msg.ParseFromArray(data_, length))
                                    {
                                        std::cout << "username: [" << msg.username() << "]" << std::endl;
                                        std::cout << "password: [" << msg.password() << "]" << std::endl;
                                        std::cout << "data: [" << msg.data() << "]" << std::endl;
                                        std::cout << "com: [" << msg.com() << "]" << std::endl;

                                        if (msg.username().size() > 0 && msg.password().size() > 0)
                                        {
                                            db_wrapper &instance = db_wrapper::Instance();
                                            if (instance.check_password(msg.username(), msg.password()))
                                            {
                                                if (msg.com() == sl::sbc::message::Command::INSERT_DATA)
                                                {
                                                    instance.add_data(msg.username(), msg.data());

                                                    sl::sbc::message::Message msg_ret;
                                                    msg_ret.set_ret_c(sl::sbc::message::Return_code::SUCCESS);

                                                    data_[0] = 'O';
                                                    data_[1] = 'K';
                                                    data_[2] = ' ';
                                                    data_[3] = ' ';
                                                    data_[4] = ' ';
                                                    do_write(5);
                                                    return;
                                                }
                                            }
                                            else
                                            {
                                                //password incorrect
                                                data_[0] = 'P';
                                                data_[1] = 'A';
                                                data_[2] = 'S';
                                                data_[3] = ' ';
                                                data_[4] = ' ';
                                                do_write(5);
                                                return;
                                            }
                                        }
                                        else
                                        {
                                            sl::sbc::message::Message msg_ret;
                                            msg_ret.set_ret_c(sl::sbc::message::Return_code::PASSWORD_INCORRECT);

                                            data_[0] = 'P';
                                            data_[1] = 'A';
                                            data_[2] = 'S';
                                            data_[3] = ' ';
                                            data_[4] = ' ';
                                            do_write(5);
                                            return;
                                        }
                                    }
                                    else
                                    {
                                        // error parse
                                        std::cout << "Error parse" << std::endl;
                                        data_[0] = 'P';
                                        data_[1] = 'A';
                                        data_[2] = 'R';
                                        data_[3] = 'S';
                                        data_[4] = ' ';
                                        do_write(5);
                                        return;
                                    }
                                }
                            });
}

void session::do_write(std::size_t length)
{
    std::cout << "do_write()" << std::endl;
    std::cout << "data:" << std::endl;
    std::cout.write(data_, length);
    std::cout << std::endl;

    auto self(shared_from_this());
    boost::asio::async_write(socket_, boost::asio::buffer(data_, length),
                             [this, self](boost::system::error_code ec, std::size_t /*length*/) {
                                 if (!ec)
                                 {
                                     do_read();
                                 }
                             });
}