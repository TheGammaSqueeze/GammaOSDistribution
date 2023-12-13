/*
 * Copyright (C) 2019 The Android Open Source Project
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
 * limitations under the License
 */

package com.android.class2nonsdklist;

import com.google.common.base.Joiner;

import java.util.List;

public class MultipleAlternativesFoundWarning extends Exception {
    public final ApiComponents alternative;
    public final List<ApiComponents> almostMatches;

    public MultipleAlternativesFoundWarning(ApiComponents alternative,
            List<ApiComponents> almostMatches) {
        this.alternative = alternative;
        this.almostMatches = almostMatches;
    }

    @Override
    public String toString() {
        return "Alternative " + alternative + " returned multiple matches. Consider adding method" +
                " parameters to make the match unique. Matches: "
                + Joiner.on(", ").join(almostMatches);
    }
}
