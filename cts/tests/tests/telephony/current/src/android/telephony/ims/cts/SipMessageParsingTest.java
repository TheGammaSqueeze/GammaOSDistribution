/*
 * Copyright (C) 2021 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package android.telephony.ims.cts;

import static junit.framework.Assert.fail;

import static org.junit.Assert.assertEquals;

import android.telephony.ims.SipMessage;

import androidx.test.runner.AndroidJUnit4;

import org.junit.Test;
import org.junit.runner.RunWith;

@RunWith(AndroidJUnit4.class)
public class SipMessageParsingTest {

    // Sample messages from RFC 3261 modified for parsing use cases.
    public static final SipMessage SIP_MESSAGE_1 = new SipMessage(
            "INVITE sip:bob@biloxi.com SIP/2.0",
            // Typical Via
            "Via: SIP/2.0/UDP pc33.atlanta.com;branch=z9hG4bK776asdhds\n"
                    + "Max-Forwards: 70\n"
                    + "To: Bob <sip:bob@biloxi.com>\n"
                    + "From: Alice <sip:alice@atlanta.com>;tag=1928301774\n"
                    + "Call-ID: a84b4c76e66710@pc33.atlanta.com\n"
                    + "CSeq: 314159 INVITE\n"
                    + "Contact: <sip:alice@pc33.atlanta.com>\n"
                    + "Content-Type: application/sdp\n"
                    + "Content-Length: 142",
            new byte[0]);
    public static final String SIP_MESSAGE_1_TRANSACTION_ID = "z9hG4bK776asdhds";
    public static final String SIP_MESSAGE_1_CALL_ID = "a84b4c76e66710@pc33.atlanta.com";
    public static final SipMessage SIP_MESSAGE_2 = new SipMessage(
            "INVITE sip:bob@biloxi.com SIP/2.0",
            // include leading whitespace.
            " Max-Forwards: 70\n"
                    + "To: Bob <sip:bob@biloxi.com>\n"
                    + "From: Alice <sip:alice@atlanta.com>;tag=1928301774\n"
                    + "Call-ID: a84b4c76e66710@pc33.atlanta.com\n"
                    + "CSeq: 314159 INVITE\n"
                    + "Contact: <sip:alice@pc33.atlanta.com>\n"
                    + "Content-Type: application/sdp\n"
                    + "Content-Length: 142\n"
                    // transaction ID should be returned for the first "Via"
                    + "Via: SIP/2.0/UDP pc33.atlanta.com;branch=z9hG4bKabcdefghi\n"
                    + "Via: SIP/2.0/UDP pc33.atlanta.com;branch=z9hG4bK776asdhds\n",

            new byte[0]);
    public static final String SIP_MESSAGE_2_TRANSACTION_ID = "z9hG4bKabcdefghi";
    public static final String SIP_MESSAGE_2_CALL_ID = "a84b4c76e66710@pc33.atlanta.com";
    public static final SipMessage SIP_MESSAGE_3 = new SipMessage(
            "INVITE sip:bob@biloxi.com SIP/2.0",
            "Max-Forwards: 70\n"
                    + "To: Bob <sip:bob@biloxi.com>\n"
                    + "From: Alice <sip:alice@atlanta.com>;tag=1928301774\n"
                    // Subject line is split into multiple lines via space and tab.
                    + "Subject: I know you're there,\n"
                    + " pick up the phone\n"
                    + "\tand talk to me!\n"
                    // non-standard key with the same starting chars as via
                    + "Viaabc: SIP/2.0/UDP pc33.atlanta.com;branch=z9hG4bKzynope\n"
                    // transaction ID should be returned for the first "Via"
                    + "Via: SIP/2.0/UDP pc33.atlanta.com;branch=z9hG4bKzyxwvutsr\n"
                    // non-standard key with the same starting chars as call-id
                    + "call-idabc: nottheone@pc33.atlanta.com\n"
                    + "Call-ID: a84b4c76e66710@pc33.atlanta.com\n"
                    + "CSeq: 314159 INVITE\n"
                    + "Contact: <sip:alice@pc33.atlanta.com>\n"
                    + "Content-Type: application/sdp\n"
                    + "Content-Length: 142\n"
                    + "Via: SIP/2.0/UDP pc33.atlanta.com;branch=z9hG4bKabcdefghi\n",
            new byte[0]);
    public static final String SIP_MESSAGE_3_TRANSACTION_ID = "z9hG4bKzyxwvutsr";
    public static final String SIP_MESSAGE_3_CALL_ID = "a84b4c76e66710@pc33.atlanta.com";
    // compact form
    public static final SipMessage SIP_MESSAGE_4 = new SipMessage(
            "INVITE sip:bob@biloxi.com SIP/2.0",
            "Max-Forwards: 70\n"
                    + "t: Bob <sip:bob@biloxi.com>\n"
                    + "f: Alice <sip:alice@atlanta.com>;tag=1928301774\n"
                    // compat form of via
                    + "v: SIP/2.0/UDP pc33.atlanta.com;branch=z9hG4bKAbCdEfGiJ\n"
                    + "v: SIP/2.0/UDP pc33.atlanta.com;branch=z9hG4bKabcdefghi\n"
                    + "i: a84b4c76e66710@pc33.atlanta.com\n"
                    + "CSeq: 314159 INVITE\n"
                    + "m: <sip:alice@pc33.atlanta.com>\n"
                    + "c: application/sdp\n"
                    + "l: 142\n",
            new byte[0]);
    public static final String SIP_MESSAGE_4_TRANSACTION_ID = "z9hG4bKAbCdEfGiJ";
    public static final String SIP_MESSAGE_4_CALL_ID = "a84b4c76e66710@pc33.atlanta.com";
    public static final SipMessage SIP_MESSAGE_5 = new SipMessage(
            "INVITE sip:bob@biloxi.com SIP/2.0",
            "Max-Forwards: 70\n"
                    + "To: Bob <sip:bob@biloxi.com>\n"
                    + "From: Alice <sip:alice@atlanta.com>;tag=1928301774\n"
                    // Malformed lines
                    + "Subject: I know you're there,\n"
                    + "pick up the phone\n"
                    + "and talk to me!\n"
                    // non-standard key with the same starting chars
                    + "Viaabc: SIP/2.0/UDP pc33.atlanta.com;branch=z9hG4bKzyxnope\n"
                    // transaction ID should be returned for the first "Via"
                    + "Via: SIP/2.0/UDP pc33.atlanta.com;branch=z9hG4bKzyxwvutsr\n"
                    // non-standard key with the same starting chars
                    + "iabc: nottheone@pc33.atlanta.com\n"
                    + "i: a84b4c76e66710@pc33.atlanta.com\n"
                    + "CSeq: 314159 INVITE\n"
                    + "Contact: <sip:alice@pc33.atlanta.com>\n"
                    + "Content-Type: application/sdp\n"
                    + "Content-Length: 142\n"
                    + "Via: SIP/2.0/UDP pc33.atlanta.com;branch=z9hG4bKabcdefghi\n",
            new byte[0]);
    public static final String SIP_MESSAGE_5_TRANSACTION_ID = "z9hG4bKzyxwvutsr";
    public static final String SIP_MESSAGE_5_CALL_ID = "a84b4c76e66710@pc33.atlanta.com";
    // Not practical, but ensure that parsing works, even in special cases like one line.
    public static final SipMessage SIP_MESSAGE_6 = new SipMessage(
            "INVITE sip:bob@biloxi.com SIP/2.0",
            "Via: SIP/2.0/UDP pc33.atlanta.com;branch=z9hG4bKabcdefghi\n",
            new byte[0]);
    public static final String SIP_MESSAGE_6_TRANSACTION_ID = "z9hG4bKabcdefghi";
    public static final String SIP_MESSAGE_6_CALL_ID = null;
    public static final SipMessage SIP_MESSAGE_7 = new SipMessage(
            "INVITE sip:bob@biloxi.com SIP/2.0",
            "Max-Forwards: 70\n"
                    + "To: Bob <sip:bob@biloxi.com>\n"
                    + "From: Alice <sip:alice@atlanta.com>;tag=1928301774\n"
                    + "Call-ID: a84b4c76e66710@pc33.atlanta.com\n"
                    + "CSeq: 314159 INVITE\n"
                    + "Contact: <sip:alice@pc33.atlanta.com>\n"
                    + "Content-Type: application/sdp\n"
                    + "Content-Length: 142\n"
                    // Typical Via, but on last line to test edge conditions
                    + "Via: SIP/2.0/UDP pc33.atlanta.com;branch=z9hG4bK776asdhds",
            new byte[0]);
    public static final String SIP_MESSAGE_7_TRANSACTION_ID = "z9hG4bK776asdhds";
    public static final String SIP_MESSAGE_7_CALL_ID = "a84b4c76e66710@pc33.atlanta.com";
    // SIP Message from RFC 4475 "A Short Tortuous INVITE"
    public static final SipMessage SIP_MESSAGE_8 = new SipMessage(
            "INVITE sip:vivekg@chair-dnrc.example.com;unknownparam SIP/2.0",
            "TO :\n"
                    + " sip:vivekg@chair-dnrc.example.com ;   tag    = 1918181833n\n"
                    + "from   : \"J Rosenberg \\\\\\\"\"       <sip:jdrosen@example.com>\n"
                    + "  ;\n"
                    + "  tag = 98asjd8\n"
                    + "MaX-fOrWaRdS: 0068\n"
                    + "Call-ID: wsinv.ndaksdj@192.0.2.1\n"
                    + "Content-Length   : 150\n"
                    + "cseq: 0009\n"
                    + "  INVITE\n"
                    + "s :\n"
                    + "NewFangledHeader:   newfangled value\n"
                    + " continued newfangled value\n"
                    + "UnknownHeaderWithUnusualValue: ;;,,;;,;\n"
                    + "Content-Type: application/sdp\n"
                    + "Route:\n"
                    + " <sip:services.example.com;lr;unknownwith=value;unknown-no-value>\n"
                    // Note, this has multiple Via headers concatenated with one header key, we
                    // should return the first in the list.
                    + "v:  SIP  / 2.0  / TCP     spindle.example.com   ;\n"
                    + "  branch  =   z9hG4bK9ikj8  ,\n"
                    + " SIP  /    2.0   / UDP  192.168.255.111   ; branch=\n"
                    + " z9hG4bK30239\n"
                    + "Via  : SIP  /   2.0\n"
                    + " /UDP\n"
                    + "    192.0.2.2;branch=z9hG4bK390skdjuw\n"
                    + "m:\"Quoted string \\\"\\\"\" <sip:jdrosen@example.com> ; newparam =\n"
                    + "      newvalue ;\n"
                    + "   secondparam ; q = 0.33",
            new byte[0]);
    public static final String SIP_MESSAGE_8_TRANSACTION_ID = "z9hG4bK9ikj8";
    public static final String SIP_MESSAGE_8_CALL_ID = "wsinv.ndaksdj@192.0.2.1";

    @Test
    public void testGetViaBranch() {
        assertEquals(SIP_MESSAGE_1_TRANSACTION_ID, SIP_MESSAGE_1.getViaBranchParameter());
        assertEquals(SIP_MESSAGE_2_TRANSACTION_ID, SIP_MESSAGE_2.getViaBranchParameter());
        assertEquals(SIP_MESSAGE_3_TRANSACTION_ID, SIP_MESSAGE_3.getViaBranchParameter());
        assertEquals(SIP_MESSAGE_4_TRANSACTION_ID, SIP_MESSAGE_4.getViaBranchParameter());
        assertEquals(SIP_MESSAGE_5_TRANSACTION_ID, SIP_MESSAGE_5.getViaBranchParameter());
        assertEquals(SIP_MESSAGE_6_TRANSACTION_ID, SIP_MESSAGE_6.getViaBranchParameter());
        assertEquals(SIP_MESSAGE_7_TRANSACTION_ID, SIP_MESSAGE_7.getViaBranchParameter());
        assertEquals(SIP_MESSAGE_8_TRANSACTION_ID, SIP_MESSAGE_8.getViaBranchParameter());

        try {
            new SipMessage(
                    "INVITE sip:bob@biloxi.com SIP/2.0",
                    "Max-Forwards: 70\n"
                            + "To: Bob <sip:bob@biloxi.com>\n"
                            + "From: Alice <sip:alice@atlanta.com>;tag=1928301774\n"
                            + "Call-ID: a84b4c76e66710@pc33.atlanta.com\n"
                            + "CSeq: 314159 INVITE\n"
                            + "Contact: <sip:alice@pc33.atlanta.com>\n"
                            + "Content-Type: application/sdp\n"
                            + "Content-Length: 142\n",
                    new byte[0]);
            fail("A SipMessage must throw an IllegalArgumentException if no Via branch parameter "
                    + "is present in the headers");
        } catch (IllegalArgumentException e) {
            // expected
        }
    }

    @Test
    public void testGetCallId() {
        assertEquals(SIP_MESSAGE_1_CALL_ID, SIP_MESSAGE_1.getCallIdParameter());
        assertEquals(SIP_MESSAGE_2_CALL_ID, SIP_MESSAGE_2.getCallIdParameter());
        assertEquals(SIP_MESSAGE_3_CALL_ID, SIP_MESSAGE_3.getCallIdParameter());
        assertEquals(SIP_MESSAGE_4_CALL_ID, SIP_MESSAGE_4.getCallIdParameter());
        assertEquals(SIP_MESSAGE_5_CALL_ID, SIP_MESSAGE_5.getCallIdParameter());
        assertEquals(SIP_MESSAGE_6_CALL_ID, SIP_MESSAGE_6.getCallIdParameter());
        assertEquals(SIP_MESSAGE_7_CALL_ID, SIP_MESSAGE_7.getCallIdParameter());
        assertEquals(SIP_MESSAGE_8_CALL_ID, SIP_MESSAGE_8.getCallIdParameter());
    }
}
