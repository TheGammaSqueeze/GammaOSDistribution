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

#include <android-base/result.h>

#include "SigningKey.h"

android::base::Result<void> addCertToFsVerityKeyring(const std::string& path);
android::base::Result<std::vector<uint8_t>> createDigest(const std::string& path);
android::base::Result<std::map<std::string, std::string>>
verifyAllFilesInVerity(const std::string& path);

// Note that this function will skip files that are already in fs-verity, and
// for those files it will return the existing digest.
android::base::Result<std::map<std::string, std::string>>
addFilesToVerityRecursive(const std::string& path, const SigningKey& key);
