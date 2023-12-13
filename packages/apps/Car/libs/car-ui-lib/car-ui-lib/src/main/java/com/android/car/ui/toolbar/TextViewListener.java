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

package com.android.car.ui.toolbar;

import static com.android.car.ui.core.CarUi.MIN_TARGET_API;

import android.annotation.SuppressLint;
import android.annotation.TargetApi;
import android.content.Context;
import android.widget.TextView;

import java.util.function.Consumer;

/**
 * Listener for setting text on {@link DeprecatedTabWrapper}
 */
@SuppressLint("AppCompatCustomView")
@SuppressWarnings("AndroidJdkLibsChecker")
@TargetApi(MIN_TARGET_API)
public final class TextViewListener extends TextView {
    private Consumer<CharSequence> mTextListener;

    public TextViewListener(Context context) {
        super(context);
    }

    @Override
    public void setText(CharSequence text, BufferType bufferType) {
        super.setText(text, bufferType);

        if (mTextListener != null) {
            mTextListener.accept(text);
        }
    }

    public void setTextListener(Consumer<CharSequence> textListener) {
        mTextListener = textListener;
    }
}
