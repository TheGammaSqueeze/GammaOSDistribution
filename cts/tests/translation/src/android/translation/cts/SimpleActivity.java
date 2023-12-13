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

package android.translation.cts;

import android.app.Activity;
import android.os.Bundle;
import android.view.autofill.AutofillId;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.List;

/**
 * A simple activity that contains a TextView used for translation testing.
 */
public class SimpleActivity extends Activity {

    public static final String HELLO_TEXT_ID = "hello";

    private static final String TAG = "SimpleActivity";

    private TextView mHelloText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.simple_activity);

        mHelloText = findViewById(R.id.hello);
    }

    List<AutofillId> getViewsForTranslation() {
        final List<AutofillId> views = new ArrayList<>();
        views.add(mHelloText.getAutofillId());
        return views;
    }

    TextView getHelloText() {
        return mHelloText;
    }
}
