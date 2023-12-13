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

import android.content.IntentFilter;

import com.android.queryable.Queryable;
import com.android.queryable.info.ActivityInfo;

/** Implementation of {@link ActivityQuery}. */
public final class ActivityQueryHelper<E extends Queryable> implements ActivityQuery<E> {

    private final E mQuery;
    private final ClassQueryHelper<E> mActivityClassQueryHelper;
    private final BooleanQueryHelper<E> mExportedQueryHelper;
    private final SetQueryHelper<E, IntentFilter, IntentFilterQuery<?>>
            mIntentFiltersQueryHelper;

    ActivityQueryHelper() {
        mQuery = (E) this;
        mActivityClassQueryHelper = new ClassQueryHelper<>(mQuery);
        mExportedQueryHelper = new BooleanQueryHelper<>(mQuery);
        mIntentFiltersQueryHelper = new SetQueryHelper<>(mQuery);
    }

    public ActivityQueryHelper(E query) {
        mQuery = query;
        mActivityClassQueryHelper = new ClassQueryHelper<>(query);
        mExportedQueryHelper = new BooleanQueryHelper<>(query);
        mIntentFiltersQueryHelper = new SetQueryHelper<>(query);
    }

    @Override
    public ClassQuery<E> activityClass() {
        return mActivityClassQueryHelper;
    }

    @Override
    public BooleanQuery<E> exported() {
        return mExportedQueryHelper;
    }

    @Override
    public SetQuery<E, IntentFilter, IntentFilterQuery<?>> intentFilters() {
        return mIntentFiltersQueryHelper;
    }

    @Override
    public boolean matches(ActivityInfo value) {
        return mActivityClassQueryHelper.matches(value)
                && mExportedQueryHelper.matches(value.exported())
                && mIntentFiltersQueryHelper.matches(value.intentFilters());
    }

    @Override
    public String describeQuery(String fieldName) {
        return Queryable.joinQueryStrings(
          mActivityClassQueryHelper.describeQuery(fieldName + ".activity"),
          mExportedQueryHelper.describeQuery(fieldName + ".exported"),
          mIntentFiltersQueryHelper.describeQuery(fieldName + ".intentFilters")
        );
    }

    public static boolean matches(ActivityQueryHelper<?> activityQueryHelper, ActivityInfo value) {
        return activityQueryHelper.matches(value);
    }
}
