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

package com.android.bedstead.harrier.annotations.meta;

import static com.android.bedstead.harrier.OptionalBoolean.TRUE;

import com.android.bedstead.harrier.OptionalBoolean;

import java.lang.annotation.Target;

/**
 * This annotation should not be used directly. It exists as a template for annotations which
 * ensure that a test runs on a given user type.
 */
@Target({})
public @interface RequireRunOnUser {
    /**
     * Should we ensure that we are switched to the given user
     */
    OptionalBoolean switchedToUser() default TRUE;
}
