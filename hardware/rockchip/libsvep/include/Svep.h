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

#include "autolock.h"
#include "SvepType.h"
#include "SvepBackend.h"

namespace android {
class Svep {
public:
  static Svep* Get(bool async = false) { return GetInstance(async); }
  ~Svep();
  Svep(const Svep&)=delete;
  Svep& operator=(const Svep&)=delete;

  // Init Context info
  int InitCtx(SvepContext &ctx);
  // Set src-image info
  int SetSrcImage(SvepContext &ctx,
                  const SvepImageInfo &src,
                  SvepModeUsage usage = SVEP_MODE_NONE);
  // Get dst-image require info
  int GetDstRequireInfo(SvepContext &ctx, SvepImageInfo &require);
  // Set dst-image info
  int SetDstImage(SvepContext &ctx, const SvepImageInfo &dst);
  // Set Enhancement rate
  int SetEnhancementRate(SvepContext &ctx, int rate);
  // Set OsdMode enbale/disable
  int SetOsdMode(SvepContext &ctx, SvepOsdMode mode, const wchar_t* osdStr);
  // Run and get FinishFence
  int Run(const SvepContext &ctx);
  // Run and get FinishFence
  int RunAsync(const SvepContext &ctx, int *outFence);

private:
  Svep();
  int Init(bool async);
  static Svep* GetInstance(bool async){
    static Svep svep;
    if(svep.Init(async))
      return NULL;
    else
      return &svep;
  }

  // Verify dlss context
  int VerifyCtx(const SvepContext &ctx, const SvepStage stage);
  // Verify src info and get suitable svep mode.
  SvepMode VerifyMode(SvepContext &ctx,
                      const SvepImageInfo &src,
                      SvepModeUsage usage);
  // Verify src info
  int VerifySrcInfo(SvepContext &ctx, const SvepImageInfo &src);
  // Verity src info and svep mode whether the RGA requirements are met
  int VerifyRgaTransform(SvepContext &ctx, const SvepImageInfo &src, const SvepMode mode);
  // Verify dst info
  int VerifyDstInfo(SvepContext &ctx, const SvepImageInfo &dst);
  // Dump Ctx info
  int DumpCtx(const SvepContext &ctx);
  SvepError bInitState_ = SvepError::UnInit;
  SvepVersion mVersion_;
  SvepBackend mSvepBackend_;
  mutable pthread_mutex_t mLock_;
};
} //namespace android