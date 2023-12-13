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

import com.android.queryable.Queryable;

public final class BooleanQueryHelper<E extends Queryable> implements BooleanQuery<E> {

    private final E mQuery;
    private Boolean mTargetValue = null;

    BooleanQueryHelper() {
        mQuery = (E) this;
    }

    public BooleanQueryHelper(E query) {
        mQuery = query;
    }

    @Override
    public E isTrue() {
        if (mTargetValue != null) {
            throw new IllegalStateException("Cannot set multiple boolean filters");
        }

        mTargetValue = true;

        return mQuery;
    }

    @Override
    public E isFalse() {
        if (mTargetValue != null) {
            throw new IllegalStateException("Cannot set multiple boolean filters");
        }

        mTargetValue = false;

        return mQuery;
    }

    @Override
    public E isEqualTo(boolean value) {
        if (mTargetValue != null) {
            throw new IllegalStateException("Cannot set multiple boolean filters");
        }

        mTargetValue = value;

        return mQuery;
    }

    @Override
    public boolean matches(Boolean value) {
        return (mTargetValue == null) || mTargetValue.equals(value);
    }

    @Override
    public String describeQuery(String fieldName) {
        if (mTargetValue == null) {
            return null;
        }

        return fieldName + "=" + mTargetValue;
    }

    public static boolean matches(BooleanQuery<?> query, Boolean value) {
        return query.matches(value);
    }
}
