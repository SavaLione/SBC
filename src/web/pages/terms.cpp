/*
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
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
 * @brief Страница с пользовательским соглашением
 * @author SavaLione
 * @date 15 Dec 2021
 */
#include "web/pages/terms.h"

terms::~terms()
{
}

void terms::_head()
{
    _add_content("<head>");

    _add_content("  <meta charset=\"utf-8\">");
    _add_content("  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">");
    _add_content("  <meta name=\"description\" content=\"\">");
    _add_content("  <meta name=\"author\" content=\"\">");
    _add_content("  <link rel=\"icon\" href=\"/assets/favicon.ico\">");

    _add_content("  <title>Terms</title>");

    _add_content("  <!-- Bootstrap core CSS -->");
    _add_content("  <link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css\" integrity=\"sha384-JcKb8q3iqJ61gNV9KGb8thSsNjpSL0n8PARn9HuZOnIxN0hoP+VmmDGMN5t9UJ0Z\" crossorigin=\"anonymous\">");

    _add_content("</head>");
}

void terms::_body()
{
    _add_content("<body class=\"text-left\">");
    _add_content("  <div class=\"container\">");
    _add_content("    <h3>Terms</h3>");

    _add_content("    <h3>BSD 3-Clause License</h3>");

    _add_content("    <pre>");
    _add_content("    <span style=\"font-size: 12px;\">Copyright (c) 2020-2021, SBC team</span>");
    _add_content("    <span style=\"font-size: 12px;\">All rights reserved.</span>");

    _add_content("    <span style=\"font-size: 14px;\">Redistribution and use in source and binary forms, with or without</span>");
    _add_content("    <span style=\"font-size: 14px;\">modification, are permitted provided that the following conditions are met:</span>");
    _add_content("    <span style=\"font-size: 14px;\">1. Redistributions of source code must retain the above copyright notice, this</span>");
    _add_content("    <span style=\"font-size: 14px;\">   list of conditions and the following disclaimer.</span>");
    _add_content("    <span style=\"font-size: 14px;\">2. Redistributions in binary form must reproduce the above copyright notice,</span>");
    _add_content("    <span style=\"font-size: 14px;\">   this list of conditions and the following disclaimer in the documentation</span>");
    _add_content("    <span style=\"font-size: 14px;\">   and/or other materials provided with the distribution.</span>");
    _add_content("    <span style=\"font-size: 14px;\">3. Neither the name of the copyright holder nor the names of its</span>");
    _add_content("    <span style=\"font-size: 14px;\">   contributors may be used to endorse or promote products derived from</span>");
    _add_content("    <span style=\"font-size: 14px;\">   this software without specific prior written permission.</span>");
    _add_content("    <span style=\"font-size: 14px;\">THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS &quot;AS IS&quot;</span>");
    _add_content("    <span style=\"font-size: 14px;\">AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE</span>");
    _add_content("    <span style=\"font-size: 14px;\">IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE</span>");
    _add_content("    <span style=\"font-size: 14px;\">DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE</span>");
    _add_content("    <span style=\"font-size: 14px;\">FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL</span>");
    _add_content("    <span style=\"font-size: 14px;\">DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR</span>");
    _add_content("    <span style=\"font-size: 14px;\">SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER</span>");
    _add_content("    <span style=\"font-size: 14px;\">CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,</span>");
    _add_content("    <span style=\"font-size: 14px;\">OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE</span>");
    _add_content("    <span style=\"font-size: 14px;\">OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.</span></pre>");

    _add_content("    <h3>Our cookie policy</h3>");
    _add_content("    <h4>What are cookies and similar technologies and why do we use them?</h4>");
    _add_content("    <p>Cookies and similar technologies allow small pieces of information to be read from and/or placed onto your device when you visit a website or application. Your web browser (such as Google Chrome, Internet Explorer or Mozilla Firefox) then");
    _add_content("      sends this information back to the website on each subsequent visit so that they can remember things like preferences.</p>");
    _add_content("    <p>Cookies and similar technologies are very useful and do lots of different jobs. For example, they enable you to move between our web pages efficiently, they remember your preferences when you visit us again and generally improve your");
    _add_content("      experience when browsing with us. They can also help to ensure that adverts you see online are more relevant to you and your interests.</p>");
    _add_content("    <p>Cookies last for different lengths of time depending on the job they do. There are session cookies and persistent cookies:</p>");
    _add_content("    <ul>");
    _add_content("      <li>Session cookies only last for your online session and disappear from your device when you close your browser</li>");
    _add_content("      <li>Persistent cookies stay on your device after the browser has been closed and last for the period of time specified in the cookie</li>");
    _add_content("    </ul>");
    _add_content("    <h4>Your choices</h4>");
    _add_content("    <p>We will only place cookies for the preference level you set (usually when you first visit our website).</p>");
    _add_content("    <p>Please note that cookies set before you changed your settings will still be on your computer. You can remove them using your browser settings.</p>");
    _add_content("    <p>Our free online tool can help you manage the cookies we use on bt.com. To use it, your web browser needs to support JavaScript &ndash; if it doesn&apos;t you can still find out about the cookies we use here, but you&apos;ll need to manage them");
    _add_content("      through your web browser settings.</p>");
    _add_content("    <p>We also use a cookie to remember your cookie preferences. This means:</p>");
    _add_content("    <ul>");
    _add_content("      <li>If you delete all your cookies you will have to update your preferences with us again &ndash; we&rsquo;ll ask you when you next visit our website</li>");
    _add_content("      <li>If you use a different device, computer profile or browser you will have to tell us your preferences again</li>");
    _add_content("    </ul>");
    _add_content("    <hr>");
    _add_content("    <h4>The cookies we use</h4>");
    _add_content("    <p>The cookies and similar technologies used on our website fall into one of four categories: strictly necessary, performance, functional and targeting.</p>");
    _add_content("    <h4>1. Strictly necessary cookies</h4>");
    _add_content("    <p>Strictly necessary cookies let you move around the website and use essential features like secure areas, shopping baskets and online billing.</p>");
    _add_content("    <p><strong>We use these strictly necessary cookies to:</strong></p>");
    _add_content("    <ul>");
    _add_content("      <li>Remember information you&apos;ve entered on order forms when you visit different pages in a single web browser session</li>");
    _add_content("      <li>Remember what you&rsquo;ve ordered when you get to the checkout page</li>");
    _add_content("      <li>Identify you as being logged in to our website</li>");
    _add_content("      <li>Make sure you connect to the right service on our website when we make any changes to the way the website works</li>");
    _add_content("    </ul>");
    _add_content("    <p><strong>Cookies we have defined as strictly necessary will NOT be used to:</strong></p>");
    _add_content("    <ul>");
    _add_content("      <li>Gather information that could be used to advertise products or services to you</li>");
    _add_content("      <li>Remember your preferences or username beyond your current visit</li>");
    _add_content("    </ul>");
    _add_content("    <hr>");
    _add_content("    <h4>2. Performance cookies</h4>");
    _add_content("    <p>Performance cookies collect information about how you use our website. For example, which pages you visit and if you experience any errors. These cookies are essential to us being able to operate and maintain our website.</p>");
    _add_content("    <p>These cookies don&apos;t collect any information that could identify you &ndash; all the information collected is anonymous.</p>");
    _add_content("    <p>Accepting these cookies is a condition of using the website, so if you prevent them we cannot guarantee how our site will perform for you.</p>");
    _add_content("    <p>In some cases, some performance cookies are managed for us by third parties, but we don&apos;t allow the third party to use the cookies for any purpose other than those listed below.</p>");
    _add_content("    <p><strong>We use performance cookies to:</strong></p>");
    _add_content("    <ul>");
    _add_content("      <li>Provide statistics on how our website is used</li>");
    _add_content("      <li>See how effective our adverts are (we don&apos;t use this information to target adverts to you when you visit other websites)</li>");
    _add_content("      <li>Help us improve the website by measuring any errors that occur</li>");
    _add_content("      <li>Test different designs of our website</li>");
    _add_content("    </ul>");
    _add_content("    <p><strong>Cookies we have defined as performance will NOT be used to:</strong></p>");
    _add_content("    <ul>");
    _add_content("      <li>Gather information that could be used to advertise products or services to you on other websites</li>");
    _add_content("      <li>Remember your preferences or username beyond your current visit</li>");
    _add_content("      <li>Target adverts to you on any other website</li>");
    _add_content("    </ul>");
    _add_content("    <hr>");
    _add_content("    <h4>3. Functional cookies</h4>");
    _add_content("    <p>Functional cookies are used to provide services or to remember settings to improve your visit.</p>");
    _add_content("    <p>You decide whether or not these cookies are used, but preventing them may mean we can&apos;t offer you some services, and will reduce the support we can offer you, such as &lsquo;live chat&rsquo;. We use functional cookies to:</p>");
    _add_content("    <ul>");
    _add_content("      <li>Remember if we&apos;ve already asked you if you want to fill in a survey</li>");
    _add_content("      <li>Provide proactive live chat sessions to offer you support</li>");
    _add_content("      <li>Show you when you&apos;re logged in to the website</li>");
    _add_content("      <li>Share information with partners to provide a service on our website. The information shared is only to be used to provide the service, product or function and not for any other purpose</li>");
    _add_content("      <li>Remember results of tests performed to make the website more relevant to you</li>");
    _add_content("    </ul>");
    _add_content("    <p><strong>Cookies we have defined as functional will not be used to:</strong></p>");
    _add_content("    <ul>");
    _add_content("      <li>Target you with adverts on other websites</li>");
    _add_content("    </ul>");
    _add_content("    <hr>");
    _add_content("    <h4>4. Targeting</h4>");
    _add_content("    <p>Targeting cookies are linked to services provided by our trusted partners. The services are listed below. You decide whether or not these cookies are used.</p>");
    _add_content("    <p><strong>We use targeting cookies to:</strong></p>");
    _add_content("    <ul>");
    _add_content("      <li>link to social networks who may use information about your visit to target advertising to you on other websites</li>");
    _add_content("      <li>provide advertising agencies and our trusted partners with information on your visit so that we can present adverts that you may be interested in, and prevent you receiving duplicate ads &ndash; online behavioural advertising (for more");
    _add_content("        details please see below)</li>");
    _add_content("      <li>deliver content, including video content, tailored to your interests</li>");
    _add_content("      <li>provide personalised communications to you when you&rsquo;re logged in on our website</li>");
    _add_content("      <li>provide personalised communications to you in limited circumstances when you&rsquo;re logged out (this will depend on the preferences you set).</li>");
    _add_content("    </ul>");
    _add_content("    <hr>");
    _add_content("    <h4>Managing cookies</h4>");
    _add_content("    <p>There are ways you can control and manage cookies on your device. Please remember that any settings you change will not just affect the cookies we use. These changes will apply to all websites you visit (unless you choose to block cookies from");
    _add_content("      particular sites).</p>");
    _add_content("    <h4>Managing cookies in your browser</h4>");
    _add_content("    <p>Most browsers will allow you to choose the level of privacy settings you want. You can block all cookies, or accept all cookies or pick a setting somewhere in between. This range lets you control your cookie settings, so you can:</p>");
    _add_content("    <ul>");
    _add_content("      <li>See what cookies you&apos;ve got and delete them on an individual basis</li>");
    _add_content("      <li>Block third party cookies</li>");
    _add_content("      <li>Block cookies from particular sites</li>");
    _add_content("      <li>Block all cookies from being set</li>");
    _add_content("      <li>Delete all cookies when you close your browser</li>");
    _add_content("    </ul>");
    _add_content("    <p>Deleting cookies means that any preference settings you have made on a website will be lost. If you&rsquo;ve set your preferences to opt out of cookies, this setting will be lost too, as that information is stored in a cookie. Blocking all");
    _add_content("      cookies means functionality on our websites will be lost, as described above. We don&rsquo;t recommend turning all cookies off when using our websites.</p>");
    _add_content("    <p>If you want to reduce your cookie settings at any time &ndash; for example, if you accept all cookies, but later decide you don&rsquo;t want a certain type of cookie &ndash; you&rsquo;ll need to use your browser settings to remove any third");
    _add_content("      party cookies dropped on your previous visit.</p>");
    _add_content("    <p>Find out how to manage your cookies using the most popular browsers below.</p>");
    _add_content("    <p><strong>Internet Explorer</strong></p>");
    _add_content("    <p><a href=\"https://support.microsoft.com/en-us/help/17442/windows-internet-explorer-delete-manage-cookies\">https://support.microsoft.com/en-us/help/17442/windows-internet-explorer-delete-manage-cookies</a></p>");
    _add_content("    <p><strong>Firefox</strong></p>");
    _add_content("    <p><a href=\"https://support.mozilla.org/en-US/kb/cookies-information-websites-store-on-your-computer?\">https://support.mozilla.org/en-US/kb/cookies-information-websites-store-on-your-computer?</a></p>");
    _add_content("    <p><strong>Google Chrome</strong></p>");
    _add_content("    <p><a href=\"https://support.google.com/chrome/answer/95647?hl=en\">https://support.google.com/chrome/answer/95647?hl=en</a></p>");
    _add_content("    <p><strong>Safari</strong></p>");
    _add_content("    <p><a href=\"https://support.apple.com/kb/PH21411?locale=en_US\">https://support.apple.com/kb/PH21411?locale=en_US</a></p>");

    _add_content("  </div>");
    _add_content("</body>");
}