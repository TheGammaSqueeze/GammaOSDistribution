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
#ifndef GL_DISPATCHH
#define GL_DISPATCHH

#include <GLES/gl.h>
#include <GLES2/gl2.h>
#include <GLES3/gl3.h>

#include "base/Lock.h"

#include "OpenGLESDispatch/gldefs.h"
#include "OpenGLESDispatch/gles_functions.h"
#include "GLutils.h"

#include <functional>

#define GLAPIENTRY GL_APIENTRY
typedef void (*FUNCPTR_NO_ARGS_RET_VOID)();
typedef int (*FUNCPTR_NO_ARGS_RET_INT)();
typedef GLsync (*FUNCPTR_FENCE_SYNC)(GLenum, GLbitfield);
typedef GLenum (*FUNCPTR_CLIENT_WAIT_SYNC)(GLsync, GLbitfield, GLuint64);
typedef void (*FUNCPTR_DELETE_SYNC)(GLsync);
typedef void (*FUNCPTR_WAIT_SYNC)(GLsync, GLbitfield, GLuint64);
typedef void (*FUNCPTR_GET_SYNC_IV)(GLsync, GLenum pname, GLsizei bufsize, GLsizei *length, GLint *values);

class GlLibrary;

#define GLES_DECLARE_METHOD(return_type, function_name, signature, args) \
    static return_type (*function_name) signature;

using EGLGetProcAddressFunc = std::function<void*(const char* name)>;

class GLDispatch {
public:
    // Constructor.
    GLDispatch();

    bool isInitialized() const;
    void dispatchFuncs(GLESVersion version, GlLibrary* glLib, EGLGetProcAddressFunc eglGPA);
    GLESVersion getGLESVersion() const;

    LIST_GLES_FUNCTIONS(GLES_DECLARE_METHOD, GLES_DECLARE_METHOD)

private:
    bool                  m_isLoaded;
    GLESVersion           m_version;
    static android::base::Lock   s_lock;
};

#endif  // GL_DISPATCH_H
