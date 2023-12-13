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

package com.google.android.setupcompat.portal;

import com.google.android.setupcompat.portal.IPortalProgressCallback;
import com.google.android.setupcompat.portal.TaskComponent;

/**
 * Declares the interface for portal used by GmsCore.
 */
interface ISetupNotificationServicePortalExtension {
  IPortalProgressCallback registerTask(in TaskComponent component) = 1;

  boolean removeTask(String packageName, String taskName) = 2;
}