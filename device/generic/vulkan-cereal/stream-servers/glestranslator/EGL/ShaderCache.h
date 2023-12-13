// Copyright (C) 2021 The Android Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef SHADER_CACHE_H
#define SHADER_CACHE_H

#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <map>
#include <vector>

void SetBlob(const void* key, EGLsizeiANDROID keySize, const void* value, EGLsizeiANDROID valueSize);

EGLsizeiANDROID GetBlob(const void* key, EGLsizeiANDROID keySize, void* value, EGLsizeiANDROID valueSize);

#endif