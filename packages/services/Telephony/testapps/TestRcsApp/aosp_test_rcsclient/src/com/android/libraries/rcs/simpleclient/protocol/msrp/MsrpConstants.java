/*
 * Copyright (C) 2020 The Android Open Source Project
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

package com.android.libraries.rcs.simpleclient.protocol.msrp;

import static java.nio.charset.StandardCharsets.UTF_8;

/**
 * Several constants used for MSRP parsing and serializing.
 */
public class MsrpConstants {
    public static final byte[] HEADER_DELIMITER_BYTES = ": ".getBytes();
    public static final String MSRP_PROTOCOL = "MSRP";
    public static final byte[] MSRP_PROTOCOL_BYTES = MSRP_PROTOCOL.getBytes(UTF_8);
    public static final String NEW_LINE = "\r\n";
    public static final byte[] NEW_LINE_BYTES = NEW_LINE.getBytes(UTF_8);
    public static final String END_MSRP_MSG = "-------";
    public static final byte[] END_MSRP_MSG_BYTES = END_MSRP_MSG.getBytes(UTF_8);
    public static final String NEW_LINE_END_MSRP_MSG = NEW_LINE + END_MSRP_MSG;
    public static final int END_MSRP_MSG_LENGTH = END_MSRP_MSG.length();
    public static final int FLAG_LAST_CHUNK = '$';
    public static final int FLAG_MORE_CHUNK = '+';
    public static final int FLAG_ABORT_CHUNK = '#';
    public static final byte CHAR_SP = ' ';
    public static final byte CHAR_LF = '\r';
    public static final byte CHAR_MIN = '-';
    public static final byte CHAR_DOUBLE_POINT = ':';
    public static final String HEADER_BYTE_RANGE = "Byte-Range";
    public static final String HEADER_CONTENT_TYPE = "Content-Type";
    public static final String HEADER_MESSAGE_ID = "Message-ID";
    public static final String HEADER_TO_PATH = "To-Path";
    public static final String HEADER_FROM_PATH = "From-Path";
    public static final String HEADER_FAILURE_REPORT = "Failure-Report";
    public static final String HEADER_SUCCESS_REPORT = "Success-Report";
    public static final String REPORT_VALUE_YES = "yes";
    public static final String REPORT_VALUE_NO = "no";

    public static final int RESPONSE_CODE_OK = 200;

    private MsrpConstants() {
    }
}
