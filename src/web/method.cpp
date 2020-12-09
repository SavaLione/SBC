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
 * @brief Web methods
 * @author SavaLione
 * @date 07 Dec 2020
 */
#include "web/method.h"

method recognize_method(std::string const &unprocessed_method)
{
    if (unprocessed_method == "OPTIONS")
    {
        return _OPTIONS;
    }

    if (unprocessed_method == "GET")
    {
        return _GET;
    }

    if (unprocessed_method == "HEAD")
    {
        return _HEAD;
    }

    if (unprocessed_method == "POST")
    {
        return _POST;
    }

    if (unprocessed_method == "PUT")
    {
        return _PUT;
    }

    if (unprocessed_method == "DELETE")
    {
        return _DELETE;
    }

    if (unprocessed_method == "TRACE")
    {
        return _TRACE;
    }

    if (unprocessed_method == "CONNECT")
    {
        return _CONNECT;
    }
}

const std::string string_method(method const &m)
{
    switch (m)
    {
    case _OPTIONS:
        return "OPTIONS";
        break;
    case _GET:
        return "GET";
        break;
    case _HEAD:
        return "HEAD";
        break;
    case _POST:
        return "POST";
        break;
    case _PUT:
        return "PUT";
        break;
    case _DELETE:
        return "DELETE";
        break;
    case _TRACE:
        return "TRACE";
        break;
    case _CONNECT:
        return "CONNECT";
        break;
    default:
        break;
    }
    return "UNKNOWN";
}