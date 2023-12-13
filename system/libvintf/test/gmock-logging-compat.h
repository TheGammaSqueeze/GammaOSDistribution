/*
 * Copyright (C) 2020 The Android Open Source Project
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

// Include this on top of a source file to work.

// gmock generates operator<< for each argument, including std::string*,
// which libbase logging.h doesn't like.
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wuser-defined-warnings"
#include <gmock/gmock.h>
#pragma clang diagnostic pop
