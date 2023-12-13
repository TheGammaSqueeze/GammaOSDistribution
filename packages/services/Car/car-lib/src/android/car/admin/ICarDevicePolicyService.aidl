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

package android.car.admin;

import android.car.user.UserCreationResult;
import android.car.user.UserRemovalResult;
import android.car.user.UserStartResult;
import android.car.user.UserStopResult;
import com.android.internal.infra.AndroidFuture;

/** @hide */
interface ICarDevicePolicyService {
    void removeUser(int userId, in AndroidFuture<UserRemovalResult> receiver);
    void createUser(String name, int flags, in AndroidFuture<UserCreationResult> receiver);
    void startUserInBackground(int userId, in AndroidFuture<UserStartResult> receiver);
    void stopUser(int userId, in AndroidFuture<UserStopResult> receiver);
}
