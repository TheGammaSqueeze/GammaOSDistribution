/*
 * Copyright (C) 2020 The Dagger Authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package dagger.hilt.android.testing;

import android.content.Context;
import androidx.multidex.MultiDexApplication;
import dagger.hilt.android.internal.testing.TestApplicationComponentManager;
import dagger.hilt.android.internal.testing.TestApplicationComponentManagerHolder;
import dagger.hilt.internal.GeneratedComponentManager;

/**
 * An application that can be used for Android instrumentation or Robolectric tests using Hilt.
 */
public final class HiltTestApplication extends MultiDexApplication
    implements GeneratedComponentManager<Object>, TestApplicationComponentManagerHolder {

  // This field is initialized in attachBaseContext to avoid pulling the generated component into
  // the main dex. We could possibly avoid this by class loading TestComponentDataSupplier lazily
  // rather than in the TestApplicationComponentManager constructor.
  private TestApplicationComponentManager componentManager;

  @Override
  protected final void attachBaseContext(Context base) {
    super.attachBaseContext(base);
    componentManager = new TestApplicationComponentManager(this);
  }

  @Override
  public final Object componentManager() {
    return componentManager;
  }

  @Override
  public final Object generatedComponent() {
    return componentManager.generatedComponent();
  }
}
