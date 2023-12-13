/*
 * Copyright (C) 2021 The Android Open Source Project
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

#include "palette/palette.h"

#include <android-base/macros.h>
#include <stdbool.h>

palette_status_t PaletteShouldReportDex2oatCompilation(bool* value) {
  *value = 0;
  return PALETTE_STATUS_OK;
}

palette_status_t PaletteNotifyStartDex2oatCompilation(int source_fd ATTRIBUTE_UNUSED,
                                                      int art_fd ATTRIBUTE_UNUSED,
                                                      int oat_fd ATTRIBUTE_UNUSED,
                                                      int vdex_fd ATTRIBUTE_UNUSED) {
  return PALETTE_STATUS_OK;
}

palette_status_t PaletteNotifyEndDex2oatCompilation(int source_fd ATTRIBUTE_UNUSED,
                                                    int art_fd ATTRIBUTE_UNUSED,
                                                    int oat_fd ATTRIBUTE_UNUSED,
                                                    int vdex_fd ATTRIBUTE_UNUSED) {
  return PALETTE_STATUS_OK;
}

palette_status_t PaletteNotifyDexFileLoaded(const char* path ATTRIBUTE_UNUSED) {
  return PALETTE_STATUS_OK;
}

palette_status_t PaletteNotifyOatFileLoaded(const char* path ATTRIBUTE_UNUSED) {
  return PALETTE_STATUS_OK;
}

palette_status_t PaletteShouldReportJniInvocations(bool* value) {
  *value = 0;
  return PALETTE_STATUS_OK;
}

palette_status_t PaletteNotifyBeginJniInvocation(JNIEnv* env ATTRIBUTE_UNUSED) {
  return PALETTE_STATUS_OK;
}

palette_status_t PaletteNotifyEndJniInvocation(JNIEnv* env ATTRIBUTE_UNUSED) {
  return PALETTE_STATUS_OK;
}
