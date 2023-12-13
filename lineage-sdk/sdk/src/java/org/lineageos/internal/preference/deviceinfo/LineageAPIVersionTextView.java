/*
 * Copyright (C) 2018 The LineageOS Project
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

package org.lineageos.internal.preference.deviceinfo;

import android.content.Context;
import android.util.AttributeSet;
import android.widget.TextView;

public class LineageAPIVersionTextView extends TextView {
    private static final String TAG = "LineageAPIVersionTextView";

    public LineageAPIVersionTextView(Context context, AttributeSet attrs) {
        super(context, attrs);

        final int sdk = lineageos.os.Build.LINEAGE_VERSION.SDK_INT;
        StringBuilder builder = new StringBuilder();
        builder.append(lineageos.os.Build.getNameForSDKInt(sdk))
                .append(" (" + sdk + ")");
        setText(builder.toString());
    }

}
