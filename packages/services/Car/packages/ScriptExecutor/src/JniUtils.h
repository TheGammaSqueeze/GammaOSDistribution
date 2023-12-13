/*
 * Copyright (c) 2021, The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef PACKAGES_SCRIPTEXECUTOR_SRC_JNIUTILS_H_
#define PACKAGES_SCRIPTEXECUTOR_SRC_JNIUTILS_H_

#include "jni.h"

extern "C" {
#include "lua.h"
}

#include <android-base/result.h>

namespace com {
namespace android {
namespace car {
namespace scriptexecutor {

// Helper function which takes android.os.Bundle object in "bundle" argument
// and converts it to Lua table on top of Lua stack. All key-value pairs are
// converted to the corresponding key-value pairs of the Lua table as long as
// the Bundle value types are supported. At this point, we support boolean,
// integer, double and String types in Java.
void pushBundleToLuaTable(JNIEnv* env, lua_State* lua, jobject bundle);

}  // namespace scriptexecutor
}  // namespace car
}  // namespace android
}  // namespace com

#endif  // PACKAGES_SCRIPTEXECUTOR_SRC_JNIUTILS_H_
