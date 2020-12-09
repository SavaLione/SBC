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
 * @brief Обработка url
 * @author SavaLione
 * @date 09 Dec 2020
 */
#include "web/url.h"

const std::string url_decode(std::string const &str)
{
    std::string result;
    char decode_buf[3];
    result.reserve(str.size());
    for (size_t pos = 0; pos < str.size(); ++pos)
    {
        switch (str[pos])
        {
        case '+':
            /* convert to space character */
            result += ' ';
            break;
        case '%':
            /* decode hexidecimal value */
            if (pos + 2 < str.size())
            {
                decode_buf[0] = s[++pos];
                decode_buf[1] = s[++pos];
                decode_buf[2] = '\0';
                result += static_cast<char>(strtol(decode_buf, nullptr, 16));
            }
            else
            {
                /* recover from error by not decoding character */
                result += '%';
            }
            break;
        default:
            /* character does not need to be escaped */
            result += str[pos];
        }
    }
    return result;
}

const std::string url_encode(std::string const &str)
{
    std::string result;
    char encode_buf[4];
    encode_buf[0] = '%';
    result.reserve(str.size());
    for (size_t pos = 0; pos < str.size(); ++pos)
    {
        switch (str[pos])
        {
        default:
            if (str[pos] >= 32 && str[pos] < 127)
            {
                /* character does not need to be escaped */
                result += str[pos];
                break;
            }
        /* else pass through to next case */
        case '$':
        case '&':
        case '+':
        case ',':
        case '/':
        case ':':
        case ';':
        case '=':
        case '?':
        case '@':
        case '"':
        case '<':
        case '>':
        case '#':
        case '%':
        case '{':
        case '}':
        case '|':
        case '\\':
        case '^':
        case '~':
        case '[':
        case ']':
        case '`':
            /* the character needs to be encoded */
            sprintf(encode_buf + 1, "%02X", str[pos]);
            result += encode_buf;
            break;
        }
    }
    return result;
}