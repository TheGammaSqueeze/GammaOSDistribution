/*
 * Copyright 2013 The Android Open Source Project
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

#include <renderengine/RenderEngine.h>

#include <cutils/properties.h>
#include <log/log.h>
#include "gl/GLESRenderEngine.h"
#include "threaded/RenderEngineThreaded.h"

namespace android {
namespace renderengine {

std::unique_ptr<RenderEngine> RenderEngine::create(const RenderEngineCreationArgs& args) {
    RenderEngineType renderEngineType = args.renderEngineType;

    // Keep the ability to override by PROPERTIES:
    char prop[PROPERTY_VALUE_MAX];
    property_get(PROPERTY_DEBUG_RENDERENGINE_BACKEND, prop, "");
    if (strcmp(prop, "gles") == 0) {
        renderEngineType = RenderEngineType::GLES;
    }
    if (strcmp(prop, "threaded") == 0) {
        renderEngineType = RenderEngineType::THREADED;
    }

    switch (renderEngineType) {
        case RenderEngineType::THREADED:
            ALOGD("Threaded RenderEngine with GLES Backend");
            return renderengine::threaded::RenderEngineThreaded::create(
                    [args]() { return android::renderengine::gl::GLESRenderEngine::create(args); });
        case RenderEngineType::GLES:
        default:
            ALOGD("RenderEngine with GLES Backend");
            return renderengine::gl::GLESRenderEngine::create(args);
    }
}

RenderEngine::~RenderEngine() = default;

// static
SyncFeatures &SyncFeatures::GetInstance() {
    static SyncFeatures syncFeatures;
    return syncFeatures;
}

bool SyncFeatures::useNativeFenceSync() const { return mHasNativeFenceSync; }
bool SyncFeatures::useFenceSync() const { return mHasFenceSync; }
bool SyncFeatures::useWaitSync() const { return mHasWaitSync; }

SyncFeatures::SyncFeatures()
    : mHasNativeFenceSync(false),
      mHasFenceSync(false),
      mHasWaitSync(false) {
    EGLDisplay dpy = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    // This can only be called after EGL has been initialized; otherwise the
    // check below will abort.
    const char* exts = eglQueryString(dpy, EGL_EXTENSIONS);
    LOG_ALWAYS_FATAL_IF(exts == nullptr, "eglQueryString failed");
    if (strstr(exts, "EGL_ANDROID_native_fence_sync")) {
        // This makes GLConsumer use the EGL_ANDROID_native_fence_sync
        // extension to create Android native fences to signal when all
        // GLES reads for a given buffer have completed.
        mHasNativeFenceSync = true;
    }
    if (strstr(exts, "EGL_KHR_fence_sync")) {
        mHasFenceSync = true;
    }
    if (strstr(exts, "EGL_KHR_wait_sync")) {
        mHasWaitSync = true;
    }
}

namespace impl {

RenderEngine::RenderEngine(const RenderEngineCreationArgs& args) : mArgs(args) {}

RenderEngine::~RenderEngine() = default;

bool RenderEngine::useNativeFenceSync() const {
    return SyncFeatures::GetInstance().useNativeFenceSync();
}

bool RenderEngine::useWaitSync() const {
    return SyncFeatures::GetInstance().useWaitSync();
}

} // namespace impl
} // namespace renderengine
} // namespace android
