
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

#ifndef SVEP_OSD_H_
#define SVEP_OSD_H_

#include "Buffer.h"
#include "SvepType.h"
// libfreetype2
#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H
#include FT_OUTLINE_H

#include <cwchar>

namespace android {

// 19(capital) and 22(low) english char
// 14 chinese word.
// 29 num word.
#define SVEP_OSD_WIDTH        960
#define SVEP_OSD_HIGHT        300
#define SVEP_OSD_MIN_PEN_SIZE 64
#define SVEP_OSD_TTF  "/vendor/etc/SvepOsd.ttf" //OPPOSans-B.ttf

class SvepOsd {
public:
	static SvepOsd* getInstance(){
		static SvepOsd svepOsd_;
		return &svepOsd_;
	}

  int Init();
  int State();
  void ClearFont();
  int AddDrawFont(const wchar_t* str, int font_size);
  int AddDrawFont(const char* str, int font_size);
  int FinishDraw();
  int GetOsdFd();
  int GetOsdWidth();
  int GetOsdHeight();
  int GetOsdFormat();
  int GetOsdStride();
  int GetOsdSize();

private:
	SvepOsd();
	~SvepOsd();
	SvepOsd(const SvepOsd&);
	SvepOsd& operator=(const SvepOsd&);
  void draw_bitmap(FT_Bitmap* bitmap, FT_Int x, FT_Int y);
  sp<GraphicBuffer> ptrOsdBuffer_;
  int iOsdFd_;
  int iOsdWidth_;
  int iOsdHeight_;
  int iOsdStride_;
  int iOsdSize_;
  int iOsdFormat_;
  int iOsdOffset_;
  // FreeType2
  FT_Library    mLibrary_;
  FT_Face       mFace_;
  FT_GlyphSlot  mSlot_;
  unsigned char mImage_[SVEP_OSD_HIGHT][SVEP_OSD_WIDTH];
  int mState_;
};
};

#endif