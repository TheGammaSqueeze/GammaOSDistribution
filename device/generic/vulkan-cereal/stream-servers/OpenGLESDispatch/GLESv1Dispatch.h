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
#pragma once

#include "OpenGLESDispatch/gldefs.h"
#include "OpenGLESDispatch/gles_functions.h"
#include "KHR/khrplatform.h"

#include "GLES12Translator/underlying_apis.h"

#include "OpenGLESDispatch/gles1_only_static_translator_namespaced_header.h"
#include "OpenGLESDispatch/gles1_extensions_static_translator_namespaced_header.h"
#include "OpenGLESDispatch/gles_common_for_gles1_static_translator_namespaced_header.h"
#include "OpenGLESDispatch/gles_extensions_for_gles1_static_translator_namespaced_header.h"

#include <stdint.h>

// Define function pointer types.
#define GLES1_DISPATCH_DEFINE_TYPE(return_type,func_name,signature,callargs) \
    typedef return_type (KHRONOS_APIENTRY * func_name ## _t) signature;

LIST_GLES1_FUNCTIONS(GLES1_DISPATCH_DEFINE_TYPE,GLES1_DISPATCH_DEFINE_TYPE)
    LIST_GLES12_TR_FUNCTIONS(GLES1_DISPATCH_DEFINE_TYPE)

struct GLESv1Dispatch {
#define GLES1_DISPATCH_DECLARE_POINTER(return_type,func_name,signature,callargs) \
        func_name ## _t func_name;
    LIST_GLES1_FUNCTIONS(GLES1_DISPATCH_DECLARE_POINTER,
                         GLES1_DISPATCH_DECLARE_POINTER)

    bool initialized = false;
};

#undef GLES1_DISPATCH_DECLARE_POINTER
#undef GLES1_DISPATCH_DEFINE_TYPE

bool gles1_dispatch_init(GLESv1Dispatch* dispatch_table);

// Used to initialize the decoder.
void* gles1_dispatch_get_proc_func(const char* name, void* userData);

// Used to check for unimplemented.
void gles1_unimplemented();
