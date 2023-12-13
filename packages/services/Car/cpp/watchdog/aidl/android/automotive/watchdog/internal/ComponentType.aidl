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

package android.automotive.watchdog.internal;

/**
 * Describes the component for which the I/O overuse configuration update was received by
 * ICarWatchdog or the component a package belongs to.
 */
@Backing(type="int")
enum ComponentType {
  /**
   * Unknown component type when the package was recently removed and the internal structures are
   * partially updated.
   */
  UNKNOWN,

  /**
   * System component.
   */
  SYSTEM,

  /**
   * Vendor component.
   */
  VENDOR,

  /**
   * Third-party component.
   */
  THIRD_PARTY,
}
