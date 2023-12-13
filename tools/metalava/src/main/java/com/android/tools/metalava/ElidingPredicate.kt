/*
 * Copyright (C) 2020 The Android Open Source Project
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

package com.android.tools.metalava

import com.android.tools.metalava.model.Item
import com.android.tools.metalava.model.MethodItem

import java.util.function.Predicate

/**
 * Filter that will elide exact duplicate methods that are already included
 * in another superclass/interfaces.
 */
class ElidingPredicate(private val wrapped: Predicate<Item>) : Predicate<Item> {

    override fun test(method: Item): Boolean {
        // This method should be included, but if it's an exact duplicate
        // override then we can elide it.
        return if (method is MethodItem && !method.isConstructor()) {
            val differentSuper = method.findPredicateSuperMethod(Predicate { test ->
                // We're looking for included and perfect signature
                wrapped.test(test) &&
                    test is MethodItem &&
                    MethodItem.sameSignature(method, test, false)
            })
            differentSuper == null
        } else {
            true
        }
    }
}
