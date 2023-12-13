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

import android.content.IntentFilter;

import com.android.queryable.Queryable;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

import java.util.Set;

@RunWith(JUnit4.class)
public class IntentFilterQueryHelperTest {

    private final Queryable mQuery = null;

    private static final Set<String> ACTIONS = Set.of("action1", "action2", "action3");
    private static final Set<String> CATEGORIES = Set.of("category1", "category2", "category3");

    private static final IntentFilter ACTIONS_INTENT_FILTER = createIntentFilter(ACTIONS, Set.of());
    private static final IntentFilter CATEGORIES_INTENT_FILTER =
            createIntentFilter(Set.of(), CATEGORIES);

    private static IntentFilter createIntentFilter(Set<String> actions, Set<String> categories) {
        IntentFilter filter = new IntentFilter();

        for (String action : actions) {
            filter.addAction(action);
        }
        for (String category : categories) {
            filter.addCategory(category);
        }

        return filter;
    }

    @Test
    public void matches_noRestrictions_returnsTrue() {
        IntentFilterQueryHelper<Queryable> intentFilterQueryHelper =
                new IntentFilterQueryHelper<>(mQuery);

        assertThat(intentFilterQueryHelper.matches(ACTIONS_INTENT_FILTER)).isTrue();
    }

    @Test
    public void matches_actionsRestriction_meetsRestriction_returnsTrue() {
        IntentFilterQueryHelper<Queryable> intentFilterQueryHelper =
                new IntentFilterQueryHelper<>(mQuery);

        intentFilterQueryHelper.actions().contains("action1");

        assertThat(intentFilterQueryHelper.matches(ACTIONS_INTENT_FILTER)).isTrue();
    }

    @Test
    public void matches_actionsRestriction_doesNotMeetRestriction_returnsFalse() {
        IntentFilterQueryHelper<Queryable> intentFilterQueryHelper =
                new IntentFilterQueryHelper<>(mQuery);

        intentFilterQueryHelper.actions().contains("action4");

        assertThat(intentFilterQueryHelper.matches(ACTIONS_INTENT_FILTER)).isFalse();
    }

    @Test
    public void matches_categoriesRestriction_meetsRestriction_returnsTrue() {
        IntentFilterQueryHelper<Queryable> intentFilterQueryHelper =
                new IntentFilterQueryHelper<>(mQuery);

        intentFilterQueryHelper.categories().contains("category1");

        assertThat(intentFilterQueryHelper.matches(CATEGORIES_INTENT_FILTER)).isTrue();
    }

    @Test
    public void matches_categoriesRestriction_doesNotMeetRestriction_returnsFalse() {
        IntentFilterQueryHelper<Queryable> intentFilterQueryHelper =
                new IntentFilterQueryHelper<>(mQuery);

        intentFilterQueryHelper.actions().contains("category4");

        assertThat(intentFilterQueryHelper.matches(CATEGORIES_INTENT_FILTER)).isFalse();
    }
}
