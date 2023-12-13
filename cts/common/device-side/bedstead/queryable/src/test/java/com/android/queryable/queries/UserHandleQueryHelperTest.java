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

import android.os.UserHandle;

import com.android.queryable.Queryable;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

@RunWith(JUnit4.class)
public class UserHandleQueryHelperTest {

    private final Queryable mQuery = null;
    private static final int USER_HANDLE_ID = 1;
    private static final UserHandle USER_HANDLE = UserHandle.of(USER_HANDLE_ID);
    private static final UserHandle DIFFERENT_USER_HANDLE = UserHandle.of(2);

    @Test
    public void matches_noRestrictions_returnsTrue() {
        UserHandleQueryHelper<Queryable> userHandleQueryHelper =
                new UserHandleQueryHelper<>(mQuery);

        assertThat(userHandleQueryHelper.matches(USER_HANDLE)).isTrue();
    }

    @Test
    public void matches_isEqualTo_meetsRestriction_returnsTrue() {
        UserHandleQueryHelper<Queryable> userHandleQueryHelper =
                new UserHandleQueryHelper<>(mQuery);

        userHandleQueryHelper.isEqualTo(USER_HANDLE);

        assertThat(userHandleQueryHelper.matches(USER_HANDLE)).isTrue();
    }

    @Test
    public void matches_isEqualTo_doesNotMeetRestriction_returnsFalse() {
        UserHandleQueryHelper<Queryable> userHandleQueryHelper =
                new UserHandleQueryHelper<>(mQuery);

        userHandleQueryHelper.isEqualTo(USER_HANDLE);

        assertThat(userHandleQueryHelper.matches(DIFFERENT_USER_HANDLE)).isFalse();
    }

    @Test
    public void matches_id_meetsRestriction_returnsTrue() {
        UserHandleQueryHelper<Queryable> userHandleQueryHelper =
                new UserHandleQueryHelper<>(mQuery);

        userHandleQueryHelper.id().isEqualTo(USER_HANDLE_ID);

        assertThat(userHandleQueryHelper.matches(USER_HANDLE)).isTrue();
    }

    @Test
    public void matches_id_doesNotMeetRestriction_returnsFalse() {
        UserHandleQueryHelper<Queryable> userHandleQueryHelper =
                new UserHandleQueryHelper<>(mQuery);

        userHandleQueryHelper.id().isEqualTo(USER_HANDLE_ID);

        assertThat(userHandleQueryHelper.matches(DIFFERENT_USER_HANDLE)).isFalse();
    }
}
