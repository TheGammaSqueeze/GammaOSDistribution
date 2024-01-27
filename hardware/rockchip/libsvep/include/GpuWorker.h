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

#include "RKSVEP.h"
#include "worker.h"
#include "Buffer.h"
#include "BufferQueue.h"
#include "SvepType.h"
#include "Osd.h"

#include <map>
#include <queue>
#include <memory>

namespace android {

class GpuWorker : public Worker {
  public:
  GpuWorker();
  ~GpuWorker() override;

  int Init(RKSVEP *pVDlss360,
           RKSVEP *pVDlss540,
           RKSVEP *pVDlss720,
           RKSVEP *pVDlss1080,
           RKSVEP *pVDlss2160,
           int timeline_fd);
  void Queue(std::shared_ptr<SvepBackendContext> abCtx);

  protected:
  void Routine() override;
  // int WaitAllFence(std::shared_ptr<SvepBackendContext> abCtx);
  int SignalFinishFence(std::shared_ptr<SvepBackendContext> abCtx);
  int GpuRun(std::shared_ptr<SvepBackendContext> abCtx);
  RKSVEPBUFFERHANDLE SvepImportBuffer(std::shared_ptr<SvepBackendContext> abCtx);
  int SvepReleaseBuffer(std::shared_ptr<SvepBackendContext> abCtx);
  // SvepOsd
  int SvepUpdateOsd(std::shared_ptr<SvepBackendContext> abCtx);
  int Run(std::shared_ptr<SvepBackendContext> abCtx, RKSVEPBUFFERHANDLE bufferHandle);
  int ScaleTo8k(std::shared_ptr<SvepBackendContext> abCtx);
  // Osd "RKNPU AI Video Enhancement" Subtitle
  int OsdSubtitle(std::shared_ptr<SvepBackendContext> abCtx);
  int ContrastMode(std::shared_ptr<SvepBackendContext> abCtx);
  int CalculateCostTime(std::shared_ptr<SvepBackendContext> abCtx);
  private:
  std::queue<std::shared_ptr<SvepBackendContext>> abCtxQueue_;
  char cFenceName_[50];
  int iTimelineFd_;
  int iTimeline_;
  int iCurrentTimeline_;
  RKSVEP *pVDlss360_;
  RKSVEP *pVDlss540_;
  RKSVEP *pVDlss720_;
  RKSVEP *pVDlss1080_;
  RKSVEP *pVDlss2160_;
  std::map<uint64_t, RKSVEPBUFFERHANDLE> mapGpuHandle;


  SvepOsd *svepOsd_;

  long totalTime_;
  long lastAvgCostTime_;
  long avgCnt_;

  SvepMode mLastMode_ = UN_SUPPORT;
};
} //namespace android