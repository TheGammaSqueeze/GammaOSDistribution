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

import android.os.PersistableBundle;

import com.android.queryable.Queryable;
import com.android.queryable.util.SerializableParcelWrapper;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/** Implementation of {@link PersistableBundleQuery}. */
public final class PersistableBundleQueryHelper<E extends Queryable>
        implements PersistableBundleQuery<E>, Serializable {

    private static final long serialVersionUID = 1;

    private final E mQuery;
    private final Map<String, PersistableBundleKeyQueryHelper<E>> mKeyQueryHelpers =
            new HashMap<>();

    PersistableBundleQueryHelper() {
        mQuery = (E) this;
    }

    public PersistableBundleQueryHelper(E query) {
        mQuery = query;
    }

    @Override
    public PersistableBundleKeyQuery<E> key(String key) {
        if (!mKeyQueryHelpers.containsKey(key)) {
            mKeyQueryHelpers.put(key, new PersistableBundleKeyQueryHelper<>(mQuery));
        }
        return mKeyQueryHelpers.get(key);
    }

    @Override
    public boolean matches(PersistableBundle value) {
        for (Map.Entry<String, PersistableBundleKeyQueryHelper<E>> keyQueries :
                mKeyQueryHelpers.entrySet()) {
            if (!keyQueries.getValue().matches(value, keyQueries.getKey())) {
                return false;
            }
        }

        return true;
    }

    public boolean matches(SerializableParcelWrapper<PersistableBundle> serializableBundle) {
        if ((serializableBundle == null || serializableBundle.get() == null)) {
            if (mKeyQueryHelpers.isEmpty()) {
                return true;
            }
            return false;
        }

        return matches(serializableBundle.get());
    }

    @Override
    public String describeQuery(String fieldName) {
        List<String> queryStrings = new ArrayList<>();
        for (Map.Entry<String, PersistableBundleKeyQueryHelper<E>> query :
                mKeyQueryHelpers.entrySet()) {
            queryStrings.add(query.getValue().describeQuery(fieldName + "." + query.getKey()));
        }

        return Queryable.joinQueryStrings(queryStrings);
    }
}
