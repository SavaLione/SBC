/*
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * Copyright (c) 2020, Darlakon
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
 * @brief Тест blowfish
 * @author Darlakon
 * @date 21 Dec 2020
 */
#include "blowfish_test.h"

#include "core/blowfish.h"

blowfish_test::blowfish_test()
{
}

blowfish_test::~blowfish_test()
{
}

TEST_F(blowfish_test, test_1)
{
    BLOWFISH bf("FEDCBA9876543210");

    const std::string message = "Hello";
    std::string message_encrypt = bf.Encrypt_CBC(message);
    std::string message_decrypt = bf.Decrypt_CBC(message_encrypt);

    ASSERT_EQ(message, message_decrypt);
    ASSERT_EQ(1, 0) << "\nkeyIV:\n" << bf.GetIV() << "\nmessage:\n" << message << "\nmessage_encrypt:\n" << message_encrypt << "\nmessage_decrypt:\n" << message_decrypt << "\n";
}

TEST_F(blowfish_test, test_2)
{
    BLOWFISH bf("FEDCBA9876543210");

    const std::string message = "Some";
    std::string message_encrypt = bf.Encrypt_CBC(message);
    std::string message_decrypt = bf.Decrypt_CBC(message_encrypt);

    ASSERT_EQ(message, message_decrypt);
}

TEST_F(blowfish_test, test_3)
{
    BLOWFISH bf("FEDCBA9876543210");

    const std::string message = "Some new";
    std::string message_encrypt = bf.Encrypt_CBC(message);
    std::string message_decrypt = bf.Decrypt_CBC(message_encrypt);

    ASSERT_EQ(message, message_decrypt);
}

TEST_F(blowfish_test, test_4)
{
    BLOWFISH bf("FEDCBA9876543210");

    const std::string message = "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    std::string message_encrypt = bf.Encrypt_CBC(message);
    std::string message_decrypt = bf.Decrypt_CBC(message_encrypt);

    ASSERT_EQ(message, message_decrypt);
}