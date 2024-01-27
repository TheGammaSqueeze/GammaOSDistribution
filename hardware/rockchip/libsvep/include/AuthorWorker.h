/*
 * Copyright (C) 2016 The Android Open Source Project
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

#include "worker.h"
#include "rkauth.h"

namespace android {

enum AuthorState {
  SVEP_AUTHOR_SUCCESS           =  0,
  SVEP_AUTHOR_FAIL              = -1,
  SVEP_AUTHOR_PERMISSION_DENIED = -2,
  SVEP_AUTHOR_CODE_ERROR        = -3,
  SVEP_AUTHOR_LICENSE_ERROR     = -4,
  SVEP_AUTHOR_LICENSE_RESET     = -5,
};

class AuthorWorker : public Worker {
public:
  AuthorWorker();
  ~AuthorWorker() override;
  AuthorState GetState();
  int StarAuthorize(bool async);
  int ReadAuthorCode();

protected:
  void Routine() override;
private:
  AuthorState mState_;
  bool mCodeReady_;
  char mAuthorizationCode_[50];
};
} //namespace android