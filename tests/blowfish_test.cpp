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

TEST_F(blowfish_test, string_test_encrypt_1)
{
    BLOWFISH bf("FEDCBA9876543210");

    std::string to_blowfish = "Hello";
    std::string blowfish_result = "o2vdeN2ilTE=";

    std::string result = bf.Encrypt_CBC(to_blowfish);

    ASSERT_EQ(blowfish_result, result);
}

TEST_F(blowfish_test, string_test_encrypt_2)
{
    BLOWFISH bf("FEDCBA9876543210");

    std::string to_blowfish = "Some";
    std::string blowfish_result = "33MYdOooWZk=";

    std::string result = bf.Encrypt_CBC(to_blowfish);

    ASSERT_EQ(blowfish_result, result);
}

TEST_F(blowfish_test, string_test_encrypt_3)
{
    BLOWFISH bf("FEDCBA9876543210");

    std::string to_blowfish = "Some new";
    std::string blowfish_result = "qHxbEcwcAKablzGwBFug5Q==";

    std::string result = bf.Encrypt_CBC(to_blowfish);

    ASSERT_EQ(blowfish_result, result);
}

TEST_F(blowfish_test, string_test_encrypt_4)
{
    BLOWFISH bf("FEDCBA9876543210");

    std::string to_blowfish = "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    std::string blowfish_result = "ezGSp0ueMekaBfTktDUMlx4hINjW0WE5ZdFW+NiZ/rHPAF00GZusSwLEJM2ACSuN3ygRQNdg0I3Uf2mm7hvwZa7blOwNzZ7F4W49LQ3Yr0pu4xQOJp15yirkdrHuei5uO5/IeyEtzS0YrojdpPqgvEQ1mnhT81ceQQs12mexb1PdMW6CkZ2wceAfnToNGIJaaybrNxBycFbblz09zMhiyvZ6amcoPVUGalhMP9FsBgQ45z+FoXEXETqK7s63Vf3P/AHZOLWmRN5TrzZ1Q3sOfyF5c8z49hMN8FzaMLL4Cpi60vQU0Zvuqg4i3wvkZ/XCR2AK+4VNq/ARoq5yMeYO2X+NFFZcXL8O3CP1dh5BrGbO9swE20c2gb04RyC9MP/YYhh2VZVTCHYITngPZcE9lFRaNnrnMzn0UaJux6omLH7Kpgpz+Fub1sAuDmE2rw/wKtahEkwHKM/812uDiXOY4iJFMc+0sUkXJMHuH+XUc5IOINqz8SNUlaEJDaaNjWWtBJg8+N+ge6r3olZBLHhSzJeq/DzEBroQY/qi++RnValhedmWMm8IrIlVAhtCqmGVrogroCizBuf9GkSb8n/vkw==";

    std::string result = bf.Encrypt_CBC(to_blowfish);

    ASSERT_EQ(blowfish_result, result);
}

TEST_F(blowfish_test, string_test_decrypt_1)
{
    BLOWFISH bf("FEDCBA9876543210");

    std::string from_blowfish = "o2vdeN2ilTE=";
    std::string original = "Hello";

    std::string result = bf.Decrypt_CBC(from_blowfish);

    ASSERT_EQ(result, original);
}

TEST_F(blowfish_test, string_test_decrypt_2)
{
    BLOWFISH bf("FEDCBA9876543210");

    std::string from_blowfish = "33MYdOooWZk=";
    std::string original = "Some";

    std::string result = bf.Decrypt_CBC(from_blowfish);

    ASSERT_EQ(result, original);
}

TEST_F(blowfish_test, string_test_decrypt_3)
{
    BLOWFISH bf("FEDCBA9876543210");

    std::string from_blowfish = "qHxbEcwcAKablzGwBFug5Q==";
    std::string original = "Some new";

    std::string result = bf.Decrypt_CBC(from_blowfish);

    ASSERT_EQ(result, original);
}

TEST_F(blowfish_test, string_test_decrypt_4)
{
    BLOWFISH bf("FEDCBA9876543210");

    std::string from_blowfish = "ezGSp0ueMekaBfTktDUMlx4hINjW0WE5ZdFW+NiZ/rHPAF00GZusSwLEJM2ACSuN3ygRQNdg0I3Uf2mm7hvwZa7blOwNzZ7F4W49LQ3Yr0pu4xQOJp15yirkdrHuei5uO5/IeyEtzS0YrojdpPqgvEQ1mnhT81ceQQs12mexb1PdMW6CkZ2wceAfnToNGIJaaybrNxBycFbblz09zMhiyvZ6amcoPVUGalhMP9FsBgQ45z+FoXEXETqK7s63Vf3P/AHZOLWmRN5TrzZ1Q3sOfyF5c8z49hMN8FzaMLL4Cpi60vQU0Zvuqg4i3wvkZ/XCR2AK+4VNq/ARoq5yMeYO2X+NFFZcXL8O3CP1dh5BrGbO9swE20c2gb04RyC9MP/YYhh2VZVTCHYITngPZcE9lFRaNnrnMzn0UaJux6omLH7Kpgpz+Fub1sAuDmE2rw/wKtahEkwHKM/812uDiXOY4iJFMc+0sUkXJMHuH+XUc5IOINqz8SNUlaEJDaaNjWWtBJg8+N+ge6r3olZBLHhSzJeq/DzEBroQY/qi++RnValhedmWMm8IrIlVAhtCqmGVrogroCizBuf9GkSb8n/vkw==";
    std::string original = "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";

    std::string result = bf.Decrypt_CBC(from_blowfish);

    ASSERT_EQ(result, original);
}