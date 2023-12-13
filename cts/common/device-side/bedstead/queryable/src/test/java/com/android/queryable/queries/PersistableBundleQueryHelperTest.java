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

package com.android.queryable.queries;

import static com.google.common.truth.Truth.assertThat;

import android.os.PersistableBundle;

import com.android.queryable.Queryable;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

@RunWith(JUnit4.class)
public class PersistableBundleQueryHelperTest {
    private static final String KEY = "Key";
    private static final String KEY2 = "Key2";
    private static final String STRING_VALUE = "value";

    private final Queryable mQuery = null;
    private final PersistableBundle mPersistableBundle = new PersistableBundle();

    @Test
    public void matches_noRestrictions_returnsTrue() {
        PersistableBundleQueryHelper<Queryable> persistableBundleQueryHelper =
                new PersistableBundleQueryHelper<>(mQuery);

        assertThat(persistableBundleQueryHelper.matches(mPersistableBundle)).isTrue();
    }

    @Test
    public void matches_restrictionOnOneKey_restrictionIsMet_returnsTrue() {
        mPersistableBundle.putString(KEY, STRING_VALUE);
        PersistableBundleQueryHelper<Queryable> persistableBundleQueryHelper =
                new PersistableBundleQueryHelper<>(mQuery);

        persistableBundleQueryHelper.key(KEY).exists();

        assertThat(persistableBundleQueryHelper.matches(mPersistableBundle)).isTrue();
    }

    @Test
    public void matches_restrictionOnOneKey_restrictionIsNotMet_returnsFalse() {
        mPersistableBundle.putString(KEY, STRING_VALUE);
        PersistableBundleQueryHelper<Queryable> persistableBundleQueryHelper =
                new PersistableBundleQueryHelper<>(mQuery);

        persistableBundleQueryHelper.key(KEY).doesNotExist();

        assertThat(persistableBundleQueryHelper.matches(mPersistableBundle)).isFalse();
    }

    @Test
    public void matches_restrictionOnMultipleKeys_oneRestrictionIsNotMet_returnsFalse() {
        mPersistableBundle.putString(KEY, STRING_VALUE);
        mPersistableBundle.remove(KEY2);
        PersistableBundleQueryHelper<Queryable> persistableBundleQueryHelper =
                new PersistableBundleQueryHelper<>(mQuery);

        persistableBundleQueryHelper.key(KEY).exists();
        persistableBundleQueryHelper.key(KEY2).exists();

        assertThat(persistableBundleQueryHelper.matches(mPersistableBundle)).isFalse();
    }

    @Test
    public void matches_restrictionOnNonExistingKey_returnsFalse() {
        mPersistableBundle.remove(KEY);
        PersistableBundleQueryHelper<Queryable> persistableBundleQueryHelper =
                new PersistableBundleQueryHelper<>(mQuery);

        persistableBundleQueryHelper.key(KEY).stringValue().isEqualTo(STRING_VALUE);

        assertThat(persistableBundleQueryHelper.matches(mPersistableBundle)).isFalse();
    }
}
