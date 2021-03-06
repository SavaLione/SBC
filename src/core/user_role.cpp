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
#include "core/user_role.h"

const std::string string_user_role(user_role const &role)
{
    switch (role)
    {
    case USER_ROLE_NOT_SET:
        return "USER_ROLE_NOT_SET";
        break;
    case USER_ROLE_DEFAULT:
        return "USER_ROLE_DEFAULT";
        break;
    case USER_ROLE_GUEST:
        return "USER_ROLE_GUEST";
        break;
    case USER_ROLE_MANAGER:
        return "USER_ROLE_MANAGER";
        break;
    case USER_ROLE_ADMINISTRATOR:
        return "USER_ROLE_ADMINISTRATOR";
        break;
    case USER_ROLE_BANNED:
        return "USER_ROLE_BANNED";
        break;
    default:
        return "USER_ROLE_NOT_SET";
        break;
    }
    return "USER_ROLE_NOT_SET";
}