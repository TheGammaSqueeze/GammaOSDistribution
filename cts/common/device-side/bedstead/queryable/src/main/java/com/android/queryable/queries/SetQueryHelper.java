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

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

public final class SetQueryHelper<E extends Queryable, F, G extends Query<F>> implements SetQuery<E, F, G>, Serializable {

    private static final long serialVersionUID = 1;

    private E mQuery;
    private final IntegerQueryHelper<E> mSizeQuery;
    private final Set<G> mContainsByQuery = new HashSet<>();
    private final Set<F> mContainsByType = new HashSet<>();
    private final Set<G> mDoesNotContainByQuery = new HashSet<>();
    private final Set<F> mDoesNotContainByType = new HashSet<>();

    SetQueryHelper() {
        mQuery = (E) this;
        mSizeQuery = new IntegerQueryHelper<>(mQuery);
    }

    public SetQueryHelper(E query) {
        mQuery = query;
        mSizeQuery = new IntegerQueryHelper<>(mQuery);
    }

    @Override
    public IntegerQuery<E> size() {
        return mSizeQuery;
    }

    @Override
    public E isEmpty() {
        return size().isEqualTo(0);
    }

    @Override
    public E isNotEmpty() {
        return size().isGreaterThanOrEqualTo(1);
    }


    @Override
    public E contains(G... objects) {
        mContainsByQuery.addAll(Arrays.asList(objects));
        return mQuery;
    }

    @Override
    public E contains(F... objects) {
        mContainsByType.addAll(Arrays.asList(objects));
        return mQuery;
    }

    @Override
    public E doesNotContain(G... objects) {
        mDoesNotContainByQuery.addAll(Arrays.asList(objects));
        return mQuery;
    }

    @Override
    public E doesNotContain(F... objects) {
        mDoesNotContainByType.addAll(Arrays.asList(objects));
        return mQuery;
    }

    @Override
    public <H extends Collection<F>> E containsAll(H... collections) {
        for (H collection : collections) {
            Iterator<F> iterator = collection.iterator();
            while (iterator.hasNext()) {
                contains(iterator.next());
            }
        }
        return  mQuery;
    }

    @Override
    public <H extends Collection<F>> E doesNotContainAny(H... collections) {
        for (H collection : collections) {
            Iterator<F> iterator = collection.iterator();
            while (iterator.hasNext()) {
                doesNotContain(iterator.next());
            }
        }
        return  mQuery;
    }

    @Override
    public boolean matches(Set<F> value) {
        if (!mSizeQuery.matches(value.size())) {
            return false;
        }

        if (!checkContainsAtLeast(value)) {
            return false;
        }

        if (!checkDoesNotContain(value)) {
            return false;
        }

        return true;
    }

    public static <F> boolean matches(SetQuery<?, F, ?> query, Set<F> value) {
        return query.matches(value);
    }

    private boolean checkContainsAtLeast(Set<F> value) {
        Set<F> v = new HashSet<>(value);

        for (F containsAtLeast : mContainsByType) {
            F match = findMatch(containsAtLeast, v);

            if (match == null) {
                return false;
            }
            v.remove(match);
        }

        for (G containsAtLeast : mContainsByQuery) {
            F match = findMatch(containsAtLeast, v);

            if (match == null) {
                return false;
            }
            v.remove(match);
        }

        return true;
    }

    private boolean checkDoesNotContain(Set<F> value) {
        for (F doesNotContain : mDoesNotContainByType) {
            if (findMatch(doesNotContain, value) != null) {
                return false;
            }
        }

        for (G doesNotContain : mDoesNotContainByQuery) {
            if (findMatch(doesNotContain, value) != null) {
                return false;
            }
        }

        return true;
    }

    private F findMatch(G query, Set<F> values) {
        for (F value : values) {
            if (query.matches(value)) {
                return value;
            }
        }

        return null;
    }

    private F findMatch(F object, Set<F> values) {
        return values.contains(object) ? object : null;
    }

    @Override
    public String describeQuery(String fieldName) {
        List<String> queryStrings = new ArrayList<>();
        queryStrings.add(mSizeQuery.describeQuery(fieldName + ".size"));
        if (!mContainsByQuery.isEmpty()) {
            queryStrings.add(fieldName + " contains matches of ["
                    + mContainsByQuery.stream().map(t -> "{" + t.describeQuery("")
                    + "}").collect(Collectors.joining(", ")) + "]");
        }
        if (!mContainsByType.isEmpty()) {
            queryStrings.add(fieldName + " contains ["
                    + mContainsByType.stream().map(Object::toString)
                    .collect(Collectors.joining(", ")) + "]");
        }

        if (!mDoesNotContainByQuery.isEmpty()) {
            queryStrings.add(fieldName + " does not contain anything matching any of ["
                    + mDoesNotContainByQuery.stream().map(t -> "{" + t.describeQuery("")
                    + "}").collect(Collectors.joining(", ")) + "]");
        }
        if (!mDoesNotContainByType.isEmpty()) {
            queryStrings.add(fieldName + " does not contain ["
                    + mDoesNotContainByType.stream().map(Object::toString)
                    .collect(Collectors.joining(", ")) + "]");
        }
        return Queryable.joinQueryStrings(queryStrings);
    }
}
