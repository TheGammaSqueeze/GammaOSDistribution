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

package com.android.bedstead.harrier.annotations.enterprise;

import static com.android.bedstead.harrier.annotations.AnnotationRunPrecedence.PRECEDENCE_NOT_IMPORTANT;

import com.android.bedstead.harrier.annotations.AnnotationRunPrecedence;
import com.android.bedstead.harrier.annotations.meta.RequiresBedsteadJUnit4;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

/**
 * Mark a test as testing the states where a policy is not allowed to be applied.
 *
 * <p>An example is running with a device owner for a policy only applicable to profile owners.
 *
 * <p>This will generate parameterized runs for all matching states.
 */
@Target(ElementType.METHOD)
@Retention(RetentionPolicy.RUNTIME)
@RequiresBedsteadJUnit4
public @interface CannotSetPolicyTest {
    /**
     * The policy being tested.
     *
     * <p>This is used to calculate which states are required to be tested.
     */
    Class<?> policy();

    /**
     * If true, then this will run in states where the app is a device admin but is not one which is
     * allowed to make the call.
     */
    boolean includeDeviceAdminStates() default true;

    /**
     * If true, then this will run in states where the app is not a device admin.
     */
    boolean includeNonDeviceAdminStates() default true;

    /**
     * Weight sets the order that annotations will be resolved.
     *
     * <p>Annotations with a lower weight will be resolved before annotations with a higher weight.
     *
     * <p>If there is an order requirement between annotations, ensure that the weight of the
     * annotation which must be resolved first is lower than the one which must be resolved later.
     *
     * <p>Weight can be set to a {@link AnnotationRunPrecedence} constant, or to any {@link int}.
     */
    int weight() default PRECEDENCE_NOT_IMPORTANT;
}
