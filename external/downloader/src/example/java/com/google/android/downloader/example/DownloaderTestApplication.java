// Copyright 2021 The Android Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

package com.google.android.downloader.example;

import android.app.Application;
import com.google.common.flogger.backend.android.AndroidLoggerConfig;
import com.google.common.flogger.backend.android.AndroidLoggerConfig.CustomConfig;
import com.google.common.flogger.backend.android.SimpleAndroidLoggerBackend;

/** {@link Application} instance for the downloader test app. */
public class DownloaderTestApplication extends Application {
  @Override
  public void onCreate() {
    super.onCreate();
    AndroidLoggerConfig.useCustomConfig(
        CustomConfig.newCustomConfig()
            .withBackendFactory(new SimpleAndroidLoggerBackend.Factory()));
  }
}
