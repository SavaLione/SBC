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
 * @brief Роль пользователя в системе
 * @author SavaLione
 * @date 12 Dec 2020
 */
#ifndef CORE_USER_ROLE_H
#define CORE_USER_ROLE_H

#include <string>

/*
    Роль пользователя в системе 
    USER_ROLE_NOT_SET - Роль не установлена
    USER_ROLE_DEFAULT - Стандартная роль
    USER_ROLE_GUEST - Роль гостя
    USER_ROLE_MANAGER - Роль менеджера
    USER_ROLE_ADMINISTRATOR - Роль администратора
    USER_ROLE_BANNED - Пользователь забанен. Нет доступа к системе
*/
enum user_role
{
    USER_ROLE_NOT_SET = -1,
    USER_ROLE_DEFAULT = 0,
    USER_ROLE_GUEST = 1,
    USER_ROLE_MANAGER = 2,
    USER_ROLE_ADMINISTRATOR = 3,
    USER_ROLE_BANNED = 100
};

/* Получить строковое представление статуса пользователя */
const std::string string_user_role(user_role const &role);

#endif // CORE_USER_ROLE_H