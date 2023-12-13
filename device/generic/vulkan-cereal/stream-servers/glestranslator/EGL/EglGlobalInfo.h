/*
* Copyright (C) 2011 The Android Open Source Project
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
#ifndef EGL_GLOBAL_INFO
#define EGL_GLOBAL_INFO

#include "EglDisplay.h"
#include "EglConfig.h"
#include "EglContext.h"
#include "EglOsApi.h"

#include "base/Lock.h"

#include <GLcommon/TranslatorIfaces.h>

#include <EGL/egl.h>

#include <vector>

class EglDisplay;

// Holds all global information shared by the EGL implementation in a given
// process. This really amounts to:
//
//   - A list of EglDisplay instances, each identified by an
//     EGLNativeDisplayType and EglOS::Display*.
//
//   - GLES interface function pointers for all supported GLES versions.

class EglGlobalInfo {

public:
    // Returns a pointer to the process' single instance, which will be
    // created on demand. This can be called multiple times, each call will
    // increment an internal reference-count.
    static EglGlobalInfo* getInstance();

    // Create a new EglDisplay instance from an existing native |dpy| value.
    // |idpy| is the corresponding native internal display type. See
    // generateInternalDisplay() below to understand how they differ.
    EglDisplay* addDisplay(EGLNativeDisplayType dpy,
                           EglOS::Display* idpy);

    // Return the EglDisplay instance corresponding to a given native |dpy|
    // value.
    EglDisplay* getDisplay(EGLNativeDisplayType dpy) const;

#ifndef ANDROID
    // Return the EglDisplay instance corresponding to a given EGLDisplay |dpy|
    // value. NULL if none matches.
    EglDisplay* getDisplay(EGLDisplay dpy) const;
#endif

    // Remove a given EGLDisplay identified by |dpy|.
    bool removeDisplay(EGLDisplay dpy);

    // Return the default native internal display handle.
    EglOS::Display* getDefaultNativeDisplay() const {
        return m_display;
    };

    // Return the default engine handle.
    EglOS::Engine* getOsEngine() const {
        return m_engine;
    }

    // Set the GLES interface pointer corresponding to a given GLES version.
    // |iface| is a pointer to a structure containing function pointers
    // related to a specific GLES version.
    // |ver| is a version identifier, e.g. GLES_1_1 or GLES_2_0.
    void setIface(const GLESiface* iface, GLESVersion ver) {
        m_gles_ifaces[ver] = iface;
    };

    void setEglIface(const EGLiface* iface) {
        m_eglIface = iface;
    }

    const EGLiface* getEglIface() {
        return m_eglIface;
    }

    // Return the current GLES interface pointer for a given GLES version.
    // |ver| is a version identifier, e.g. GLES_1_1 or GLES_2_0.
    const GLESiface* getIface(GLESVersion ver) const {
        return m_gles_ifaces[ver];
    }

    // Initialize the table of extension functions for a given GLES version
    // |ver|. This must be called after setIface() for the corresponding
    // version.
    void initClientExtFuncTable(GLESVersion ver);

    void markSurfaceForDestroy(EglDisplay* display,
                               EGLSurface toDestroy);

    // Only call this if there is a suitable context bound, or no
    // actual deleting will happen at the host driver level.
    void sweepDestroySurfaces();

    // setEgl2Egl(true) to enable egl on top of another egl.
    // Must be called before instantiation.
    static void setEgl2Egl(EGLBoolean enable);
    static bool isEgl2Egl();

    // isEgl2EglSyncSafeToUse
    static void setEgl2EglSyncSafeToUse(EGLBoolean enable);
    static bool isEgl2EglSyncSafeToUse();

    EglGlobalInfo();
    ~EglGlobalInfo();

private:

    std::vector<EglDisplay*>       m_displays;

    std::vector<std::pair<EglDisplay*, EGLSurface> >
                                   m_surfaceDestroyList;

    EglOS::Engine*                 m_engine = nullptr;
    EglOS::Display*                m_display = nullptr;
    const GLESiface*               m_gles_ifaces[MAX_GLES_VERSION] = {};
    const EGLiface*                m_eglIface = nullptr;
    bool                           m_gles_extFuncs_inited[MAX_GLES_VERSION] = {};
    mutable android::base::Lock           m_lock;
};

#endif
