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
/*
 * Copyright (c) 2020, Savely Pototsky (SavaLione)
 * Copyright (c) 2008, Taylor Hornby
*/

/* Use
#include <iostream>
#include <string.h>
#include "blowfish.h"

using namespace std;

typedef unsigned char byte;

int main()
{
    BLOWFISH bf("FEDCBA9876543210");
    string asdf = "BlowwFIshhhhhhhhhhh!";
    asdf = bf.Encrypt_CBC(asdf);
    cout << "Encrypted: " << asdf << endl;
    asdf = bf.Decrypt_CBC(asdf);
    cout << "Decrypted: " << asdf;
    return 0;
}

*/
/**
 * @file
 * @brief Blowfish
 * @author Taylor Hornby, SavaLione
 * @date 15 Nov 2020
 */
#ifndef BLOWFISH_INCLUDED
#define BLOWFISH_INCLUDED

#include <string>

//headers needed for the CSPRNG
#ifdef _WIN32
    #include <Windows.h>
    #include <Wincrypt.h>
#else
    #include <fstream> //for reading from /dev/urandom on *nix systems
#endif

typedef unsigned char byte;

class BLOWFISH{

    //Although there is no successful cryptanalysis of the 16 round version, a higher number of rounds generally means more security.
    //STANDARD: 16
    //MAXIMUM: 256
    //**MUST be an EVEN number**
    #define ROUNDS 16
    public:
        BLOWFISH(std::string hexKey);
        BLOWFISH(byte* cipherKey, int keylength);

        //TODO: string encryption functions -> base64
        std::string Encrypt_CBC(std::string data);
        byte* Encrypt_CBC(byte* data, int length, int* newlength);
        byte* Encrypt_ECB(byte* data, int length, int* newlength);
        void Encrypt_Block(byte* block, int offset = 0);

        std::string Decrypt_CBC(std::string data);
        byte* Decrypt_CBC(byte* data, int length, int* newlength);
        byte* Decrypt_ECB(byte* data, int length, int* newlength);
        void Decrypt_Block(byte* block, int offset = 0);

        void SetRandomIV();
        void SetIV(byte* newIV);
        byte* GetIV();
        bool IvSet;

    protected:
        void SetupKey(byte* cipherKey, int length);
        void encipher();
        void decipher();
        unsigned int round(unsigned int a, unsigned int b, unsigned int n);
        void setblock(byte* block, int offset);
        void getblock(byte* block, int offset);
        static unsigned int p[];
        static unsigned int s0[];
        static unsigned int s1[];
        static unsigned int s2[];
        static unsigned int s3[];

        unsigned int xl_par;
        unsigned int xr_par;

        byte IV[8];

        byte* Crypt_ECB(byte* data, int length, int* newlength, void (BLOWFISH::*CryptBlock)(byte*, int offset), bool decrypt);
        byte* Crypt_CBC(byte* data, int length, int* newlength, void (BLOWFISH::*CryptBlock)(byte*, int offset), bool decrypt);
        byte* padData(byte* data, int length, int* paddedLength, bool decrypt, bool IvSpace);
        int findPaddingEnd(byte* data, int length);
        int hex2dec(char hex);
        std::string byteToHex(unsigned char x);
};

#endif // BLOWFISH_INCLUDED
