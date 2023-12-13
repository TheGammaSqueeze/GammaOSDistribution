/*
 * Copyright 2020 The Android Open Source Project
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

#pragma once

#include <apex/choreographer.h>
#include <inttypes.h>
#include <jni.h>

namespace android {

// Registers the global JVM for AChoreographer
void AChoreographer_initJVM(JNIEnv* env);

// Signals all AChoregorapher* instances that a new vsync period is available
// for consumption by callbacks.
void AChoreographer_signalRefreshRateCallbacks(int64_t vsyncPeriod);

// Returns the vsync id of the last frame callback. Client are expected to call
// this function from their frame callback function to get the vsyncId and pass
// it together with a buffer or transaction to the Surface Composer. Calling
// this function from anywhere else will return an undefined value.
int64_t AChoreographer_getVsyncId(const AChoreographer* choreographer);

// Returns the deadline timestamp (in CLOCK_MONOTONIC) of the last frame callback.
// Client are expected to call this function from their frame callback function
// to get the deadline and use it to know whether a frame is likely to miss
// presentation. Calling this function from anywhere else will return an undefined
// value.
int64_t AChoreographer_getFrameDeadline(const AChoreographer* choreographer);

// Returns the current interval in ns between frames.
// Client are expected to call this function from their frame callback function.
// Calling this function from anywhere else will return an undefined value.
int64_t AChoreographer_getFrameInterval(const AChoreographer* choreographer);

// Trampoline functions allowing libandroid.so to define the NDK symbols without including
// the entirety of libnativedisplay as a whole static lib. As libnativedisplay
// maintains global state, libnativedisplay can never be directly statically
// linked so that global state won't be duplicated. This way libandroid.so can
// reroute the NDK methods into the implementations defined by libnativedisplay
AChoreographer* AChoreographer_routeGetInstance();
void AChoreographer_routePostFrameCallback(AChoreographer* choreographer,
                                           AChoreographer_frameCallback callback, void* data);
void AChoreographer_routePostFrameCallbackDelayed(AChoreographer* choreographer,
                                                  AChoreographer_frameCallback callback, void* data,
                                                  long delayMillis);
void AChoreographer_routePostFrameCallback64(AChoreographer* choreographer,
                                             AChoreographer_frameCallback64 callback, void* data);
void AChoreographer_routePostFrameCallbackDelayed64(AChoreographer* choreographer,
                                                    AChoreographer_frameCallback64 callback,
                                                    void* data, uint32_t delayMillis);
void AChoreographer_routeRegisterRefreshRateCallback(AChoreographer* choreographer,
                                                     AChoreographer_refreshRateCallback callback,
                                                     void* data);
void AChoreographer_routeUnregisterRefreshRateCallback(AChoreographer* choreographer,
                                                       AChoreographer_refreshRateCallback callback,
                                                       void* data);

} // namespace android
