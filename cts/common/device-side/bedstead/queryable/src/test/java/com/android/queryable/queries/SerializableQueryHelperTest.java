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

import com.android.queryable.Queryable;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

import java.io.Serializable;

@RunWith(JUnit4.class)
public class SerializableQueryHelperTest {

    private final Queryable mQuery = null;
    private final Serializable mSerializable = "SerializableString";
    private final Serializable mDifferentSerializable = "SerializableString2";

    @Test
    public void matches_noRestrictions_returnsTrue() {
        SerializableQueryHelper<Queryable> serializableQueryHelper =
                new SerializableQueryHelper<>(mQuery);

        assertThat(serializableQueryHelper.matches(mSerializable)).isTrue();
    }

    @Test
    public void matches_isEqualTo_meetsRestriction_returnsTrue() {
        SerializableQueryHelper<Queryable> serializableQueryHelper =
                new SerializableQueryHelper<>(mQuery);

        serializableQueryHelper.isEqualTo(mSerializable);

        assertThat(serializableQueryHelper.matches(mSerializable)).isTrue();
    }

    @Test
    public void matches_isEqualTo_doesNotMeetRestriction_returnsFalse() {
        SerializableQueryHelper<Queryable> serializableQueryHelper =
                new SerializableQueryHelper<>(mQuery);

        serializableQueryHelper.isEqualTo(mDifferentSerializable);

        assertThat(serializableQueryHelper.matches(mSerializable)).isFalse();
    }
}
