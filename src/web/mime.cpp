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
#include "web/mime.h"

const char *mime_type(mime m)
{
    switch (m)
    {
    /* Application */
    case application_edi_x12:
        return "Content-type: application/EDI-X12";
        break;
    case application_edifact:
        return "Content-type: application/EDIFACT";
        break;
    case application_javascript:
        return "Content-type: application/javascript";
        break;
    case application_octet_stream:
        return "Content-type: application/octet-stream";
        break;
    case application_ogg:
        return "Content-type: application/ogg";
        break;
    case application_pdf:
        return "Content-type: application/pdf";
        break;
    case application_xhtml_xml:
        return "Content-type: application/xhtml+xml";
        break;
    case application_x_shockwave_flash:
        return "Content-type: application/x-shockwave-flash";
        break;
    case application_json:
        return "Content-type: application/json";
        break;
    case application_ld_json:
        return "Content-type: application/ld+json";
        break;
    case application_xml:
        return "Content-type: application/xml";
        break;
    case application_zip:
        return "Content-type: application/zip";
        break;
    case application_x_www_form_urlencoded:
        return "Content-type: application/x-www-form-urlencoded";
        break;

    /* Audio */
    case audio_mpeg:
        return "Content-type: audio/mpeg";
        break;
    case audio_x_ms_wma:
        return "Content-type: audio/x-ms-wma";
        break;
    case audio_vnd_rn_realaudio:
        return "Content-type: audio/vnd.rn-realaudio";
        break;
    case audio_x_wav:
        return "Content-type: audio/x-wav";
        break;
    /* Image */
    case image_gif:
        return "Content-type: image/gif";
        break;
    case image_jpeg:
        return "Content-type: image/jpeg";
        break;
    case image_png:
        return "Content-type: image/png";
        break;
    case image_tiff:
        return "Content-type: image/tiff";
        break;
    case image_vnd_microsoft_icon:
        return "Content-type: image/vnd.microsoft.icon";
        break;
    case image_x_icon:
        return "Content-type: image/x-icon";
        break;
    case image_vnd_djvu:
        return "Content-type: image/vnd.djvu";
        break;
    case image_svg_xml:
        return "Content-type: image/svg+xml";
        break;

    /* Multipart */
    case multipart_mixed:
        return "Content-type: multipart/mixed";
        break;
    case multipart_alternative:
        return "Content-type: multipart/alternative";
        break;
    case multipart_related:
        return "Content-type: multipart/related";
        break;
    case multipart_form_data:
        return "Content-type: multipart/form-data";
        break;

    /* Text */
    case text_css:
        return "Content-type: text/css";
        break;
    case text_csv:
        return "Content-type: text/csv";
        break;
    case text_html:
        return "Content-type: text/html";
        break;
    case text_javascript:
        return "Content-type: text/javascript";
        break;
    case text_plain:
        return "Content-type: text/plain";
        break;
    case text_xml:
        return "Content-type: text/xml";
        break;

    /* Video */
    case video_mpeg:
        return "Content-type: video/mpeg";
        break;
    case video_mp4:
        return "Content-type: video/mp4";
        break;
    case video_quicktime:
        return "Content-type: video/quicktime";
        break;
    case video_x_ms_wmv:
        return "Content-type: video/x-ms-wmv";
        break;
    case video_x_msvideo:
        return "Content-type: video/x-msvideo";
        break;
    case video_x_flv:
        return "Content-type: video/x-flv";
        break;
    case video_webm:
        return "Content-type: video/webm";
        break;

    /* VND */
    case application_vnd_oasis_opendocument_text:
        return "Content-type: application/vnd.oasis.opendocument.text";
        break;
    case application_vnd_oasis_opendocument_spreadsheet:
        return "Content-type: application/vnd.oasis.opendocument.spreadsheet";
        break;
    case application_vnd_oasis_opendocument_presentation:
        return "Content-type: application/vnd.oasis.opendocument.presentation";
        break;
    case application_vnd_oasis_opendocument_graphics:
        return "Content-type: application/vnd.oasis.opendocument.graphics";
        break;
    case application_vnd_ms_excel:
        return "Content-type: application/vnd.ms-excel";
        break;
    case application_vnd_openxmlformats_officedocument_spreadsheetml_sheet:
        return "Content-type: application/vnd.openxmlformats-officedocument.spreadsheetml.sheet";
        break;
    case application_vnd_ms_powerpoint:
        return "Content-type: application/vnd.ms-powerpoint";
        break;
    case application_vnd_openxmlformats_officedocument_presentationml_presentation:
        return "Content-type: application/vnd.openxmlformats-officedocument.presentationml.presentation";
        break;
    case application_msword:
        return "Content-type: application/msword";
        break;
    case application_vnd_openxmlformats_officedocument_wordprocessingml_document:
        return "Content-type: application/vnd.openxmlformats-officedocument.wordprocessingml.document";
        break;
    case application_vnd_mozilla_xul_xml:
        return "Content-type: application/vnd.mozilla.xul+xml";
        break;
    default:
        return "Content-type: text/html";
        break;
    }
    return "Content-type: text/html";
}

// return "Content-type: ";