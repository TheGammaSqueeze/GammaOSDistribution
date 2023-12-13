/*
 * Copyright (C) 2017 The Android Open Source Project
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
package com.android.cts.delegate;

import android.app.admin.DevicePolicyManager;
import android.os.Bundle;
import android.test.MoreAsserts;
import android.util.Log;

import androidx.test.InstrumentationRegistry;

import java.util.Arrays;
import java.util.List;

/**
 * Test general properties of delegate applications that should apply to any delegation scope
 * granted by a device or profile owner via {@link DevicePolicyManager#setDelegatedScopes}.
 */
public class GeneralDelegateTest extends BaseJUnit3TestCase {

    private static final String TAG = GeneralDelegateTest.class.getSimpleName();
    private static final String PARAM_SCOPES = "scopes";

    public void testGetsExpectedDelegationScopes() {
        Bundle arguments = InstrumentationRegistry.getArguments();
        String[] expectedScopes = arguments.getString(PARAM_SCOPES).split(",");
        List<String> delegatedScopes = mDpm.getDelegatedScopes(/* admin= */ null,
                mContext.getPackageName());
        Log.v(TAG, "delegatedScopes: " + delegatedScopes
                + " expected: " + Arrays.toString(expectedScopes));

        assertNotNull("Received null scopes", delegatedScopes);
        MoreAsserts.assertContentsInAnyOrder("Delegated scopes do not match expected scopes",
                delegatedScopes, expectedScopes);
    }

    public void testDifferentPackageNameThrowsException() {
        final String otherPackage = "com.android.cts.launcherapps.simpleapp";
        try {
            List<String> delegatedScopes = mDpm.getDelegatedScopes(null, otherPackage);
            fail("Expected SecurityException not thrown");
        } catch (SecurityException expected) {
            MoreAsserts.assertContainsRegex("Caller with uid \\d+ is not " + otherPackage,
                    expected.getMessage());
        }
    }
}
