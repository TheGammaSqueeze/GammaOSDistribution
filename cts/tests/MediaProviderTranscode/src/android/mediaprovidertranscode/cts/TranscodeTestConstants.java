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

package android.mediaprovidertranscode.cts;

public final class TranscodeTestConstants {
    private TranscodeTestConstants() {
    }

    public static final String INTENT_QUERY_TYPE =
            "android.mediaprovidertranscode.cts.query_type";
    public static final String INTENT_EXTRA_CALLING_PKG =
            "android.mediaprovidertranscode.cts.calling_pkg";
    public static final String INTENT_EXTRA_PATH = "android.mediaprovidertranscode.cts.path";
    public static final String OPEN_FILE_QUERY = "android.mediaprovidertranscode.cts.open_file";
}
