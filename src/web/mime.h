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
 * @brief Multipurpose Internet Mail Extensions (mime)
 * @author SavaLione
 * @date 23 Nov 2020
 */
#ifndef WEB_MIME_H
#define WEB_MIME_H

enum mime
{
    /* Application */
    application_edi_x12 = 1,
    application_edifact = 2,
    application_javascript = 3,
    application_octet_stream = 4,
    application_ogg = 5,
    application_pdf = 6,
    application_xhtml_xml = 7,
    application_x_shockwave_flash = 8,
    application_json = 9,
    application_ld_json = 10,
    application_xml = 11,
    application_zip = 12,
    application_x_www_form_urlencoded = 13,

    /* Audio */
    audio_mpeg = 14,
    audio_x_ms_wma = 15,
    audio_vnd_rn_realaudio = 16,
    audio_x_wav = 17,

    /* Image */
    image_gif = 18,
    image_jpeg = 19,
    image_png = 20,
    image_tiff = 21,
    image_vnd_microsoft_icon = 22,
    image_x_icon = 23,
    image_vnd_djvu = 24,
    image_svg_xml = 25,

    /* Multipart */
    multipart_mixed = 26,
    multipart_alternative = 27,
    multipart_related = 28,
    multipart_form_data = 29,

    /* Text */
    text_css = 30,
    text_csv = 31,
    text_html = 32,
    text_javascript = 33,
    text_plain = 34,
    text_xml = 35,

    /* Video */
    video_mpeg = 36,
    video_mp4 = 37,
    video_quicktime = 38,
    video_x_ms_wmv = 39,
    video_x_msvideo = 40,
    video_x_flv = 41,
    video_webm = 42,

    /* VND */
    application_vnd_oasis_opendocument_text = 43,
    application_vnd_oasis_opendocument_spreadsheet = 44,
    application_vnd_oasis_opendocument_presentation = 45,
    application_vnd_oasis_opendocument_graphics = 46,
    application_vnd_ms_excel = 47,
    application_vnd_openxmlformats_officedocument_spreadsheetml_sheet = 48,
    application_vnd_ms_powerpoint = 49,
    application_vnd_openxmlformats_officedocument_presentationml_presentation = 50,
    application_msword = 51,
    application_vnd_openxmlformats_officedocument_wordprocessingml_document = 52,
    application_vnd_mozilla_xul_xml = 53
};

const char *mime_type(mime m);

#endif // WEB_MIME_H