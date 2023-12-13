/*
 * Copyright 2021 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package com.google.android.enterprise.connectedapps.testing;

import com.google.android.enterprise.connectedapps.Permissions;

class FakePermissions implements Permissions {

  private final AbstractFakeProfileConnector fakeProfileConnector;

  FakePermissions(AbstractFakeProfileConnector fakeProfileConnector) {
    this.fakeProfileConnector = fakeProfileConnector;
  }

  @Override
  public boolean canMakeCrossProfileCalls() {
    return fakeProfileConnector.hasPermissionToMakeCrossProfileCalls();
  }
}
