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

package android.autofillservice.cts.inline;

import static android.autofillservice.cts.testcore.Helper.getContext;
import static android.autofillservice.cts.testcore.InstrumentedAutoFillServiceInlineEnabled.SERVICE_NAME;

import android.autofillservice.cts.commontests.DatasetFilteringTest;
import android.autofillservice.cts.testcore.Helper;
import android.autofillservice.cts.testcore.InlineUiBot;

import org.junit.rules.TestRule;

public class DatasetFilteringInlineTest extends DatasetFilteringTest {
    public DatasetFilteringInlineTest() {
        super(getInlineUiBot());
    }


    @Override
    public TestRule getMainTestRule() {
        return InlineUiBot.annotateRule(super.getMainTestRule());
    }

    @Override
    protected boolean isInlineMode() {
        return true;
    }

    @Override
    protected void enableService() {
        Helper.enableAutofillService(getContext(), SERVICE_NAME);
    }
}
