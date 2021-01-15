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
 * @date 15 Nov 2020
 */
#include "net/session.h"

#include "io/logger.h"

#include "db/db.h"

#include "time/current_time.h"

#include <data.pb.h>

#include <iostream>

void session::start()
{
    do_read();
}

void session::do_read()
{
    auto self(shared_from_this());
    socket_.async_read_some(boost::asio::buffer(data_, max_length),
                            [this, self](boost::system::error_code ec, std::size_t length) {
                                if (!ec)
                                {
                                    //spdlog::debug("TCP: {}", data_);
                                    spdlog::info("New connection");

                                    sbc::data::ServerRequest sr;
                                    sbc::data::ServerRequest result;
                                    std::string _str = data_;
                                    if (sr.ParseFromString(_str.c_str()))
                                    {
                                        /* Успешно спарсили */
                                        spdlog::info("Data received and processed successfully");
                                        spdlog::info("Login: [{}]", sr.login());
                                        spdlog::info("Password: [{}]", sr.password());
                                        spdlog::info("Barcode: [{}]", sr.barcode());
                                        spdlog::info("Description: [{}]", sr.description());
                                        switch (sr.newstatus())
                                        {
                                        case sbc::data::Status::PROCESSING:
                                            spdlog::info("status: [PROCESSING]");
                                            break;
                                        case sbc::data::Status::SEND:
                                            spdlog::info("status: [SEND]");
                                            break;
                                        case sbc::data::Status::TRAVEL:
                                            spdlog::info("status: [TRAVEL]");
                                            break;
                                        case sbc::data::Status::RECEIVE:
                                            spdlog::info("status: [RECEIVE]");
                                            break;
                                        case sbc::data::Status::LOST:
                                            spdlog::info("status: [LOST]");
                                            break;
                                        case sbc::data::Status::OTHER:
                                            spdlog::info("status: [OTHER]");
                                            break;
                                        case sbc::data::Status::UNKNOWN:
                                            spdlog::info("status: [UNKNOWN]");
                                            break;
                                        default:
                                            spdlog::info("status: [UNKNOWN]");
                                            break;
                                        }

                                        /* Подключаемся к бд, вносим данные */
                                        try
                                        {
                                            db &_db_instance = db::instance();
                                            db_pool *db_p = &_db_instance.get();

                                            soci::session sql(*db_p->get_pool());

                                            int username_password_correct = 0;

                                            sql << "select count(*) from users where username='" << sr.login() << "' and password='" << sr.password() << "'", soci::into(username_password_correct);

                                            if (username_password_correct)
                                            {
                                                /* Данные корректны */
                                                result.set_returncode(sbc::data::RetCode::SUCCESS);

                                                /* Вносим данные в базу данных */
                                                {
                                                    current_time ct;
                                                    std::string s_status = "";

                                                    switch (sr.newstatus())
                                                    {
                                                    case sbc::data::Status::PROCESSING:
                                                        s_status = "PROCESSING";
                                                        break;
                                                    case sbc::data::Status::SEND:
                                                        s_status = "SEND";
                                                        break;
                                                    case sbc::data::Status::TRAVEL:
                                                        s_status = "TRAVEL";
                                                        break;
                                                    case sbc::data::Status::RECEIVE:
                                                        s_status = "RECEIVE";
                                                        break;
                                                    case sbc::data::Status::LOST:
                                                        s_status = "LOST";
                                                        break;
                                                    case sbc::data::Status::OTHER:
                                                        s_status = "OTHER";
                                                        break;
                                                    case sbc::data::Status::UNKNOWN:
                                                        s_status = "UNKNOWN";
                                                        break;
                                                    default:
                                                        s_status = "UNKNOWN";
                                                        break;
                                                    }

                                                    sql << "insert into codes(code, time, user, status) values('" << sr.barcode() << "', '" << ct.s_date() << "', '" << sr.login() << "', '" << s_status << "')";
                                                }
                                            }
                                            else
                                            {
                                                result.set_returncode(sbc::data::RetCode::SIGN_IN_ERROR);
                                                result.set_callbackmessage("Login or password is incorrect.");
                                            }
                                        }
                                        catch (const std::exception &e)
                                        {
                                            spdlog::error(e.what());
                                            result.set_returncode(sbc::data::RetCode::ERROR);
                                            result.set_callbackmessage("Error in the sent data.");
                                        }
                                    }
                                    else
                                    {
                                        /* Не успешно спарсили */
                                        spdlog::warn("Data was not successfully received and processed");
                                        result.set_returncode(sbc::data::RetCode::ERROR);
                                        result.set_callbackmessage("Data was not successfully received and processed.");
                                    }

                                    std::string s_result_return = "";
                                    if (result.SerializeToString(*s_result_return))
                                    {
                                        /* Данные успешно сериализованы */
                                        for (int i = 0; i < s_result_return.size() && i < max_length; i++)
                                        {
                                            data_[i] = s_result_return[i];
                                        }
                                    }
                                    else
                                    {
                                        /* Данные не успешно сериализованы */
                                        spdlog::warn("Data not serialized successfully.");
                                    }

                                    // do_write(length);
                                    do_write(s_result_return.size());
                                }
                            });
}

void session::do_write(std::size_t length)
{
    auto self(shared_from_this());
    boost::asio::async_write(socket_, boost::asio::buffer(data_, length),
                             [this, self](boost::system::error_code ec, std::size_t /*length*/) {
                                 if (!ec)
                                 {
                                     do_read();
                                 }
                             });
}