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
 * @brief Обработка структуры пользователя. Получение данных и прочее
 * @author SavaLione
 * @date 12 Dec 2020
 */
#include "core/user_handler.h"

#include "io/logger.h"

#include "web/cookie_repository.h"

user_handler::~user_handler()
{
}

void user_handler::_init()
{
    _show_debug();
}

void user_handler::_show_debug()
{
    spdlog::debug("user_handler::_show()");
    spdlog::debug("_id: {}", _user._id);
    spdlog::debug("_username: {}", _user._username);
    spdlog::debug("_password: {}", _user._password);
    spdlog::debug("_name: {}", _user._name);
    spdlog::debug("_email: {}", _user._email);
    spdlog::debug("_phone:", _user._phone);
    spdlog::debug("_user_role: {}", string_user_role(_user._user_role));
    spdlog::debug("_registration_date: {}", _user._registration_date);
    spdlog::debug("_last_time_online: {}", _user._last_time_online);
    spdlog::debug("_description: {}", _user._description);
    spdlog::debug("_department: {}", _user._department);
    spdlog::debug("_branch: {}", _user._branch);
    spdlog::debug("_is_user_active: {}", _user._is_user_active);
    spdlog::debug("_registration_confirmation_code: {}", _user._registration_confirmation_code);
    spdlog::debug("_city: {}", _user._city);
    spdlog::debug("_uuid: {}", _user._uuid);
    spdlog::debug("_user_status: {}", string_user_status(_user._user_status));
}