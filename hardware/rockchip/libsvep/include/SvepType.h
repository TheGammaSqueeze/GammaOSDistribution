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

#include "autofd.h"
#include <stdint.h>
#include <utils/Trace.h>
#include <cutils/properties.h>
#include <time.h>
#include <vector>
#include <utils/String8.h>
#include <cwchar>
namespace android {

// Verison info
#define SVEP_MAGIC        0x83991906
#define SVEP_VERSION      "Svep-1.6.5"
#define SVEP_VERSION_NAME "vendor.svep.version"

// Release property interface.
#define SVEP_MODE_NAME               "persist.sys.svep.mode"
#define SVEP_RUNTIME_DISABLE_NAME    "sys.svep.runtime_disable"
#define SVEP_ENHANCEMENT_RATE_NAME   "persist.sys.svep.enhancement_rate"
#define SVEP_CONTRAST_MODE_NAME      "persist.sys.svep.contrast_mode"
#define SVEP_CONTRAST_MODE_OFFSET    "persist.sys.svep.contrast_offset_ratio"
#define SVEP_OSD_VIDEO_ONELINE_MODE  "persist.sys.svep.enable_oneline_osd"
#define SVEP_AVG_COST_TIME_NAME      "vendor.svep.avg_cost_time"
// OSD string interface.
#define SVEP_OSD_VIDEO_STR  L"RKNPU-AI视频增强"
// One line OSD
#define SVEP_OSD_VIDEO_ONELINE_STR  L"AI"
// 30hz, 360 is 12 second.
#define SVEP_OSD_VIDEO_ONELINE_CNT  360

// Vendor Storage ID.
#define SVEP_VENDOR_AUTHOR_ID "ro.vendor.svep.vsid"

#define SVEP_CONTRAST_MODE_ENABLE     1
#define SVEP_CONTRAST_MODE_LINE_WIDTH 4;

// Debug Property.
#define SVEP_DEBUG_NAME   "vendor.svep.log"

#define SVEP_ALOGE(x, ...)  \
    ALOGE("%s,line=%d " x ,__FUNCTION__,__LINE__, ##__VA_ARGS__)

#define SVEP_ALOGW(x, ...)  \
    ALOGW("%s,line=%d " x ,__FUNCTION__,__LINE__, ##__VA_ARGS__)

#define SVEP_ALOGI(x, ...)  \
    ALOGI("%s,line=%d " x ,__FUNCTION__,__LINE__, ##__VA_ARGS__)

#define SVEP_ALOGD_IF(x, ...)  \
    ALOGD_IF(SvepLogLevel(), "%s,line=%d " x ,__FUNCTION__,__LINE__, ##__VA_ARGS__)

#define YUV_ALIGN 2
#define RGB_ALIGN 1

#define IS_ALIGN(val,align)    (((val)&(align-1))==0)
#ifndef ALIGN
#define ALIGN( value, base ) (((value) + ((base) - 1)) & ~((base) - 1))
#endif
#ifndef ALIGN_DOWN
#define ALIGN_DOWN( value, base)	(value & (~(base-1)))
#endif
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

int UpdateSvepLogLevel();
bool SvepLogLevel();
void EnableTimeStampUs();
long GetCurrentTimeUs();

enum SvepError {
    None = 0,
    BadVersion,
    BadStage,
    BadParameter,
    UnLicence,
    UnSupported,
    UnSucess,
    UnInit,
};

enum SvepStage {
    SVEP_UN_INIT = 0,
    SVEP_INIT_SUCCESS,
    SVEP_VERITY_SRC_SUCCESS,
    SVEP_GET_REQUIRE_SUCCESS,
    SVEP_VERITY_DST_SUCCESS,
};

enum SvepMode {
    UN_SUPPORT = 0,
    SVEP_360p,
    SVEP_540p,
    SVEP_720p,
    SVEP_1080p,
    SVEP_2160p,
    SVEP_4320p,
    SVEP_4320p_v2,
};

enum SvepModeUsage {
    SVEP_MODE_NONE = 0,
    SVEP_OUTPUT_8K_MODE = 1 << 1,
};

enum SvepBufferMask {
    SVEP_BUFFER_NONE = 0,
    SVEP_AFBC_FORMATE = 1 << 1
};

enum SvepOsdMode {
    SVEP_OSD_DISABLE = 0,
    SVEP_OSD_ENABLE_VIDEO,
    SVEP_OSD_ENABLE_VIDEO_ONELINE
};

struct SvepVersion{
  int iMajor_;
  int iMinor_;
  int iPatchLevel_;
};

struct SvepModeRequireInfo{
  SvepMode mode_;
  int iSvepSrcWidth_;
  int iSvepSrcHeight_;
  int iSvepSrcFormat_;
  float iSvepScale_;
  int iSvepDstFormat_;
  char cName[20];
};

class SvepRect{
public:
  int iLeft_;
  int iTop_;
  int iRight_;
  int iBottom_;

  int Width() const {return iRight_ - iLeft_; };
  int Height() const {return iBottom_ - iTop_; };

  SvepRect() = default;
  SvepRect(const SvepRect& rhs){
    iLeft_   = rhs.iLeft_;
    iTop_    = rhs.iTop_;
    iRight_  = rhs.iRight_;
    iBottom_ = rhs.iBottom_;
  };

  SvepRect& operator=(const SvepRect& rhs){
    iLeft_   = rhs.iLeft_;
    iTop_    = rhs.iTop_;
    iRight_  = rhs.iRight_;
    iBottom_ = rhs.iBottom_;
    return *this;
  };

  bool operator!=(const SvepRect& rhs){
    if(iLeft_   != rhs.iLeft_ ||
       iTop_    != rhs.iTop_  ||
       iRight_  != rhs.iRight_||
       iBottom_ != rhs.iBottom_){
      return true;
    }

    return false;
  };

  bool isValid() const {
    return Width() > 0 && Height() > 0;
  };
};

class SvepBufferInfo{
public:
  int iFd_;
  int iWidth_;
  int iHeight_;
  int iFormat_;
  int iStride_;
  int iSize_;
  uint64_t uBufferId_;
  uint64_t uDataSpace_;
  uint64_t uBufferMask_;

  SvepBufferInfo() = default;
  SvepBufferInfo(const SvepBufferInfo& rhs){
    iFd_     = rhs.iFd_;
    iWidth_  = rhs.iWidth_;
    iHeight_ = rhs.iHeight_;
    iFormat_ = rhs.iFormat_;
    iStride_ = rhs.iStride_;
    iSize_   = rhs.iSize_;
    uBufferId_   = rhs.uBufferId_;
    uDataSpace_  = rhs.uDataSpace_;
    uBufferMask_ = rhs.uBufferMask_;

  };

  SvepBufferInfo& operator=(const SvepBufferInfo& rhs){
    iFd_     = rhs.iFd_;
    iWidth_  = rhs.iWidth_;
    iHeight_ = rhs.iHeight_;
    iFormat_ = rhs.iFormat_;
    iStride_ = rhs.iStride_;
    iSize_   = rhs.iSize_;
    uBufferId_   = rhs.uBufferId_;
    uDataSpace_  = rhs.uDataSpace_;
    uBufferMask_ = rhs.uBufferMask_;
    return *this;
  };

  bool isValid() const {
    return iFd_ > 0     &&
           iWidth_ > 0  &&
           iHeight_ > 0 &&
           iStride_ > 0 &&
           iSize_ > 0   &&
           iFormat_ > 0;
  }
};

class SvepParameter{
public:
  // Svep Enhancement 0 - 10
  float mEnhancementRate_;
  // Svep Osd Mode : 0 / 1 / 2
  SvepOsdMode mOsdMode_;
  const wchar_t* mOsdVideo_;

  SvepParameter() = default;
  SvepParameter(const SvepParameter& rhs){
    mEnhancementRate_ = rhs.mEnhancementRate_;
    mOsdMode_ = rhs.mOsdMode_;
    mOsdVideo_ = rhs.mOsdVideo_;
  };

  SvepParameter& operator=(const SvepParameter& rhs){
    mEnhancementRate_ = rhs.mEnhancementRate_;
    mOsdMode_ = rhs.mOsdMode_;
    mOsdVideo_ = rhs.mOsdVideo_;
    return *this;
  };
};

class SvepImageInfo{
public:
  SvepBufferInfo mBufferInfo_;
  SvepRect mCrop_;
  UniqueFd mAcquireFence_;
  bool mValid;
  SvepImageInfo() = default;
  SvepImageInfo(const SvepImageInfo& rhs){
    mBufferInfo_ = rhs.mBufferInfo_;
    mCrop_ = rhs.mCrop_;
    mAcquireFence_ = rhs.mAcquireFence_.Dup();
  };

  SvepImageInfo& operator=(const SvepImageInfo& rhs){
    mBufferInfo_ = rhs.mBufferInfo_;
    mCrop_ = rhs.mCrop_;
    mAcquireFence_ = rhs.mAcquireFence_.Dup();
    return *this;
  };
};

class SvepContext {
public:
  unsigned int mMagic_;
  SvepVersion mVersion_;
  SvepStage mStage_;
  SvepMode mSvepMode_;
  SvepImageInfo mSvepSrc_;
  SvepImageInfo mSvepDst_;
  SvepImageInfo mSrc_;
  SvepImageInfo mDst_;
  SvepParameter mParam_;
};

class TimeStamp{
public:
  TimeStamp(long time, const char* name){
    mTime_ = time;
    mName_ = name;
  };

  ~TimeStamp(){};
  long mTime_;
  String8 mName_;

};

#define RECORD_CURRENT_TIME(stage_name) \
  abCtx->mTimeStampVec_.push_back(TimeStamp(GetCurrentTimeUs(), stage_name))

#define PRINT_TIME_STAMP() \
  if(abCtx->mTimeStampVec_.size() > 0){ \
    long last_time = 0; \
    String8 output; \
    for(auto &time : abCtx->mTimeStampVec_){ \
      output.appendFormat("%s:%ld ", time.mName_.c_str(), time.mTime_ - last_time); \
      last_time = time.mTime_; \
    } \
    SVEP_ALOGD_IF("SvepTimeStamp(us): %s", output.c_str()); \
  }

class SvepBackendContext {
public:
  unsigned int mMagic_;
  SvepVersion mVersion_;
  SvepStage mStage_;
  SvepMode mSvepMode_;
  SvepImageInfo mSvepSrc_;
  SvepImageInfo mSvepDst_;
  SvepImageInfo mSrc_;
  SvepImageInfo mDst_;
  SvepParameter mParam_;
  int iFenceTimeline_;
  UniqueFd ufCurrentFinishFence_;
  struct timeval mStartTime_;
  std::vector<TimeStamp> mTimeStampVec_;

  SvepBackendContext(const SvepContext ac):
    mMagic_(ac.mMagic_),
    mVersion_(ac.mVersion_),
    mStage_(ac.mStage_),
    mSvepMode_(ac.mSvepMode_),
    mSvepSrc_(ac.mSvepSrc_),
    mSvepDst_(ac.mSvepDst_),
    mSrc_(ac.mSrc_),
    mDst_(ac.mDst_),
    mParam_(ac.mParam_),
    iFenceTimeline_(0){};
};

} // namespace android
