/*
 * Copyright (c) 2014-2018, The Linux Foundation. All rights reserved.
 * Not a Contribution.
 *
 * Copyright 2015 The Android Open Source Project
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

#include <cutils/properties.h>
#include <errno.h>
#include <math.h>
#include <sync/sync.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <utils/constants.h>
#include <utils/debug.h>
#include <utils/formats.h>
#include <utils/rect.h>
#include <qd_utils.h>

#include <algorithm>
#include <iomanip>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "hwc_display.h"
#include "hwc_debugger.h"
#include "hwc_tonemapper.h"
#include "hwc_session.h"

#ifdef QTI_BSP
#include <hardware/display_defs.h>
#endif

#define __CLASS__ "HWCDisplay"

namespace sdm {

HWCColorMode::HWCColorMode(DisplayInterface *display_intf) : display_intf_(display_intf) {}

HWC2::Error HWCColorMode::Init() {
  PopulateColorModes();
  InitColorCompensation();
  return ApplyDefaultColorMode();
}

HWC2::Error HWCColorMode::DeInit() {
  color_mode_map_.clear();
  return HWC2::Error::None;
}

uint32_t HWCColorMode::GetColorModeCount() {
  uint32_t count = UINT32(color_mode_map_.size());
  DLOGI("Supported color mode count = %d", count);
  return std::max(1U, count);
}

uint32_t HWCColorMode::GetRenderIntentCount(ColorMode mode) {
  uint32_t count = UINT32(color_mode_map_[mode].size());
  DLOGI("mode: %d supported rendering intent count = %d", mode, count);
  return std::max(1U, count);
}

HWC2::Error HWCColorMode::GetColorModes(uint32_t *out_num_modes, ColorMode *out_modes) {
  auto it = color_mode_map_.begin();
  *out_num_modes = std::min(*out_num_modes, UINT32(color_mode_map_.size()));
  for (uint32_t i = 0; i < *out_num_modes; it++, i++) {
    out_modes[i] = it->first;
  }
  return HWC2::Error::None;
}

HWC2::Error HWCColorMode::GetRenderIntents(ColorMode mode, uint32_t *out_num_intents,
                                           RenderIntent *out_intents) {
  if (color_mode_map_.find(mode) == color_mode_map_.end()) {
    return HWC2::Error::BadParameter;
  }
  auto it = color_mode_map_[mode].begin();
  *out_num_intents = std::min(*out_num_intents, UINT32(color_mode_map_[mode].size()));
  for (uint32_t i = 0; i < *out_num_intents; it++, i++) {
    out_intents[i] = it->first;
  }
  return HWC2::Error::None;
}

HWC2::Error HWCColorMode::SetColorModeWithRenderIntent(ColorMode mode, RenderIntent intent) {
  DTRACE_SCOPED();
  if (mode < ColorMode::NATIVE || mode > ColorMode::BT2100_HLG) {
    DLOGE("Could not find mode: %d", mode);
    return HWC2::Error::BadParameter;
  }
  if (color_mode_map_.find(mode) == color_mode_map_.end()) {
    return HWC2::Error::Unsupported;
  }
  if (color_mode_map_[mode].find(intent) == color_mode_map_[mode].end()) {
    return HWC2::Error::Unsupported;
  }

  if (current_color_mode_ == mode && current_render_intent_ == intent) {
    return HWC2::Error::None;
  }

  auto mode_string = color_mode_map_[mode][intent];
  DisplayError error = display_intf_->SetColorMode(mode_string);
  if (error != kErrorNone) {
    DLOGE("failed for mode = %d intent = %d name = %s", mode, intent, mode_string.c_str());
    return HWC2::Error::Unsupported;
  }

  current_color_mode_ = mode;
  current_render_intent_ = intent;

  // The mode does not have the PCC configured, restore the transform
  RestoreColorTransform();

  DLOGV_IF(kTagClient, "Successfully applied mode = %d intent = %d name = %s", mode, intent,
           mode_string.c_str());
  return HWC2::Error::None;
}

HWC2::Error HWCColorMode::SetColorModeById(int32_t color_mode_id) {
  DLOGI("Applying mode: %d", color_mode_id);
  DisplayError error = display_intf_->SetColorModeById(color_mode_id);
  if (error != kErrorNone) {
    DLOGI_IF(kTagClient, "Failed to apply mode: %d", color_mode_id);
    return HWC2::Error::BadParameter;
  }
  return HWC2::Error::None;
}

HWC2::Error HWCColorMode::RestoreColorTransform() {
  DisplayError error =
      display_intf_->SetColorTransform(kColorTransformMatrixCount, PickTransferMatrix());
  if (error != kErrorNone) {
    DLOGE("Failed to set Color Transform");
    return HWC2::Error::BadParameter;
  }

  return HWC2::Error::None;
}

void HWCColorMode::InitColorCompensation() {
  char value[kPropertyMax] = {0};
  if (Debug::Get()->GetProperty(ADAPTIVE_WHITE_COEFFICIENT_PROP, value) == kErrorNone) {
    adaptive_white_ = std::make_unique<WhiteCompensation>(string(value));
    adaptive_white_->SetEnabled(true);
  }
  std::memset(value, 0, sizeof(value));
  if (Debug::Get()->GetProperty(ADAPTIVE_SATURATION_PARAMETER_PROP, value) == kErrorNone) {
    adaptive_saturation_ = std::make_unique<SaturationCompensation>(string(value));
    adaptive_saturation_->SetEnabled(true);
  }
}

const double *HWCColorMode::PickTransferMatrix() {
  double matrix[kColorTransformMatrixCount] = {0};
  if (current_render_intent_ == RenderIntent::ENHANCE) {
    CopyColorTransformMatrix(color_matrix_, matrix);
    if (HasSaturationCompensation())
      adaptive_saturation_->ApplyToMatrix(matrix);

    if (HasWhiteCompensation())
      adaptive_white_->ApplyToMatrix(matrix);

    CopyColorTransformMatrix(matrix, compensated_color_matrix_);
    return compensated_color_matrix_;
  } else {
    return color_matrix_;
  }
}

HWC2::Error HWCColorMode::SetWhiteCompensation(bool enabled) {
  if (adaptive_white_ == NULL)
    return HWC2::Error::Unsupported;

  if (adaptive_white_->SetEnabled(enabled) != HWC2::Error::None) {
    return HWC2::Error::NotValidated;
  }

  RestoreColorTransform();

  DLOGI("Set White Compensation: %d", enabled);
  return HWC2::Error::None;
}

HWC2::Error HWCColorMatrix::SetEnabled(bool enabled) {
  enabled_ = enabled;
  return HWC2::Error::None;
}

bool HWCColorMatrix::ParseFloatValueByCommas(const string &values, uint32_t length,
                                             std::vector<float> &elements) const {
  std::istringstream data_stream(values);
  string data;
  uint32_t index = 0;
  std::vector<float> temp_elements;
  while (std::getline(data_stream, data, ',')) {
    temp_elements.push_back(std::move(std::stof(data.c_str())));
    index++;
  }

  if (index != length) {
    DLOGW("Insufficient elements defined");
    return false;
  }
  std::move(temp_elements.begin(), temp_elements.end(), elements.begin());
  return true;
}

HWC2::Error WhiteCompensation::SetEnabled(bool enabled) {
  // re-parse data when set enabled for retry calibration
  if (enabled) {
    if (!ConfigCoefficients() || !ParseWhitePointCalibrationData()) {
      enabled_ = false;
      DLOGE("Failed to WhiteCompensation Set");
      return HWC2::Error::NotValidated;
    }
    CalculateRGBRatio();
  }
  enabled_ = enabled;
  return HWC2::Error::None;
}

bool WhiteCompensation::ParseWhitePointCalibrationData() {
  static constexpr char kWhitePointCalibrationDataPath[] = "/persist/display/calibrated_rgb";
  FILE *fp = fopen(kWhitePointCalibrationDataPath, "r");
  int ret;

  if (!fp) {
    DLOGW("Failed to open white point calibration data file");
    return false;
  }

  ret = fscanf(fp, "%d %d %d", &compensated_red_, &compensated_green_, &compensated_blue_);
  fclose(fp);

  if ((ret == kNumOfCompensationData) && CheckCompensatedRGB(compensated_red_) &&
      CheckCompensatedRGB(compensated_green_) && CheckCompensatedRGB(compensated_blue_)) {
    DLOGD("Compensated RGB: %d %d %d", compensated_red_, compensated_green_, compensated_blue_);
    return true;
  } else {
    compensated_red_ = kCompensatedMaxRGB;
    compensated_green_ = kCompensatedMaxRGB;
    compensated_blue_ = kCompensatedMaxRGB;
    DLOGE("Wrong white compensated value");
    return false;
  }
}

bool WhiteCompensation::ConfigCoefficients() {
  std::vector<float> CompensatedCoefficients(kCoefficientElements);
  if (!ParseFloatValueByCommas(key_values_, kCoefficientElements, CompensatedCoefficients))
    return false;
  std::move(CompensatedCoefficients.begin(), CompensatedCoefficients.end(),
            white_compensated_Coefficients_);
  for (const auto &c : white_compensated_Coefficients_) {
    DLOGD("white_compensated_Coefficients_=%f", c);
  }
  return true;
}

void WhiteCompensation::CalculateRGBRatio() {
  // r = r_coeffient2 * R^2 + r_coeffient1 * R + r_coeffient0
  // g = g_coeffient2 * G^2 + g_coeffient1 * G + g_coeffient0
  // b = b_coeffient2 * B^2 + b_coeffient1 * B + b_coeffient0
  // r_ratio = r/kCompensatedMaxRGB
  // g_ratio = g/kCompensatedMaxRGB
  // b_ratio = b/kCompensatedMaxRGB
  auto rgb_ratio = [=](int rgb, float c2, float c1, float c0) {
    float frgb = FLOAT(rgb);
    return ((c2 * frgb * frgb + c1 * frgb + c0) / kCompensatedMaxRGB);
  };

  compensated_red_ratio_ =
      rgb_ratio(compensated_red_, white_compensated_Coefficients_[0],
                white_compensated_Coefficients_[1], white_compensated_Coefficients_[2]);
  compensated_green_ratio_ =
      rgb_ratio(compensated_green_, white_compensated_Coefficients_[3],
                white_compensated_Coefficients_[4], white_compensated_Coefficients_[5]);
  compensated_blue_ratio_ =
      rgb_ratio(compensated_blue_, white_compensated_Coefficients_[6],
                white_compensated_Coefficients_[7], white_compensated_Coefficients_[8]);
  DLOGI("Compensated ratio %f %f %f", compensated_red_ratio_, compensated_green_ratio_,
        compensated_blue_ratio_);
}

void WhiteCompensation::ApplyToMatrix(double *in) {
  double matrix[kColorTransformMatrixCount] = {0};
  for (uint32_t i = 0; i < kColorTransformMatrixCount; i++) {
    if ((i % 4) == 0)
      matrix[i] = compensated_red_ratio_ * in[i];
    else if ((i % 4) == 1)
      matrix[i] = compensated_green_ratio_ * in[i];
    else if ((i % 4) == 2)
      matrix[i] = compensated_blue_ratio_ * in[i];
    else if ((i % 4) == 3)
      matrix[i] = in[i];
  }
  std::move(&matrix[0], &matrix[kColorTransformMatrixCount - 1], in);
}

HWC2::Error SaturationCompensation::SetEnabled(bool enabled) {
  if (enabled == enabled_)
    return HWC2::Error::None;

  if (enabled) {
    if (!ConfigSaturationParameter()) {
      enabled_ = false;
      return HWC2::Error::NotValidated;
    }
  }
  enabled_ = enabled;
  return HWC2::Error::None;
}

bool SaturationCompensation::ConfigSaturationParameter() {
  std::vector<float> SaturationParameter(kSaturationParameters);
  if (!ParseFloatValueByCommas(key_values_, kSaturationParameters, SaturationParameter))
    return false;

  int32_t matrix_index = 0;
  for (uint32_t i = 0; i < SaturationParameter.size(); i++) {
    saturated_matrix_[matrix_index] = SaturationParameter.at(i);
    // Put parameters to matrix and keep the last row/column identity
    if ((i + 1) % 3 == 0) {
      matrix_index += 2;
    } else {
      matrix_index++;
    }
    DLOGD("SaturationParameter[%d]=%f", i, SaturationParameter.at(i));
  }
  return true;
}

void SaturationCompensation::ApplyToMatrix(double *in) {
  double matrix[kColorTransformMatrixCount] = {0};
  // 4 x 4 matrix multiplication
  for (uint32_t i = 0; i < kNumOfRows; i++) {
    for (uint32_t j = 0; j < kColumnsPerRow; j++) {
      for (uint32_t k = 0; k < kColumnsPerRow; k++) {
        matrix[j + (i * kColumnsPerRow)] +=
            saturated_matrix_[k + (i * kColumnsPerRow)] * in[j + (k * kColumnsPerRow)];
      }
    }
  }
  std::move(&matrix[0], &matrix[kColorTransformMatrixCount - 1], in);
}

HWC2::Error HWCColorMode::SetColorTransform(const float *matrix,
                                            android_color_transform_t /*hint*/) {
  DTRACE_SCOPED();
  auto status = HWC2::Error::None;
  double color_matrix_restore[kColorTransformMatrixCount] = {0};
  CopyColorTransformMatrix(color_matrix_, color_matrix_restore);
  CopyColorTransformMatrix(matrix, color_matrix_);
  DisplayError error =
      display_intf_->SetColorTransform(kColorTransformMatrixCount, PickTransferMatrix());
  if (error != kErrorNone) {
    CopyColorTransformMatrix(color_matrix_restore, color_matrix_);
    DLOGE("Failed to set Color Transform Matrix");
    status = HWC2::Error::Unsupported;
  }

  return status;
}

void HWCColorMode::FindRenderIntent(const ColorMode &mode, const std::string &mode_string) {
  auto intent = RenderIntent::COLORIMETRIC;
  if (mode_string.find("enhanced") != std::string::npos) {
    intent = RenderIntent::ENHANCE;
  }
  color_mode_map_[mode][intent] = mode_string;
}

void HWCColorMode::PopulateColorModes() {
  uint32_t color_mode_count = 0;
  // SDM returns modes which have attributes defining mode and rendering intent
  DisplayError error = display_intf_->GetColorModeCount(&color_mode_count);
  if (error != kErrorNone || (color_mode_count == 0)) {
    DLOGW("GetColorModeCount failed, use native color mode");
    color_mode_map_[ColorMode::NATIVE][RenderIntent::COLORIMETRIC] = "hal_native_identity";
    return;
  }

  DLOGV_IF(kTagClient, "Color Modes supported count = %d", color_mode_count);

  std::vector<std::string> color_modes(color_mode_count);
  error = display_intf_->GetColorModes(&color_mode_count, &color_modes);
  for (uint32_t i = 0; i < color_mode_count; i++) {
    std::string &mode_string = color_modes.at(i);
    DLOGV_IF(kTagClient, "Color Mode[%d] = %s", i, mode_string.c_str());
    AttrVal attr;
    error = display_intf_->GetColorModeAttr(mode_string, &attr);
    std::string color_gamut = kNative, dynamic_range = kSdr, pic_quality = kStandard;
    if (!attr.empty()) {
      for (auto &it : attr) {
        if (it.first.find(kColorGamutAttribute) != std::string::npos) {
          color_gamut = it.second;
        } else if (it.first.find(kDynamicRangeAttribute) != std::string::npos) {
          dynamic_range = it.second;
        } else if (it.first.find(kPictureQualityAttribute) != std::string::npos) {
          pic_quality = it.second;
        }
      }

      DLOGV_IF(kTagClient, "color_gamut : %s, dynamic_range : %s, pic_quality : %s",
               color_gamut.c_str(), dynamic_range.c_str(), pic_quality.c_str());
      if (color_gamut == kNative) {
        color_mode_map_[ColorMode::NATIVE][RenderIntent::COLORIMETRIC] = mode_string;
      }

      if (color_gamut == kSrgb && dynamic_range == kSdr) {
        if (pic_quality == kStandard) {
          color_mode_map_[ColorMode::SRGB][RenderIntent::COLORIMETRIC] = mode_string;
        }
        if (pic_quality == kEnhanced) {
          color_mode_map_[ColorMode::SRGB][RenderIntent::ENHANCE] = mode_string;
        }
      }

      if (color_gamut == kDcip3 && dynamic_range == kSdr) {
        if (pic_quality == kStandard) {
          color_mode_map_[ColorMode::DISPLAY_P3][RenderIntent::COLORIMETRIC] = mode_string;
        }
        if (pic_quality == kEnhanced) {
          color_mode_map_[ColorMode::DISPLAY_P3][RenderIntent::ENHANCE] = mode_string;
        }
      }

      if (pic_quality == kStandard && dynamic_range == kHdr) {
        color_mode_map_[ColorMode::BT2100_PQ][RenderIntent::TONE_MAP_COLORIMETRIC] = mode_string;
        color_mode_map_[ColorMode::BT2100_HLG][RenderIntent::TONE_MAP_COLORIMETRIC] = mode_string;
      }
    } else {
      // Look at the mode names, if no attributes are found
      if (mode_string.find("hal_native") != std::string::npos) {
        color_mode_map_[ColorMode::NATIVE][RenderIntent::COLORIMETRIC] = mode_string;
      }
    }
  }
}

HWC2::Error HWCColorMode::ApplyDefaultColorMode() {
  auto color_mode = ColorMode::NATIVE;
  if (color_mode_map_.size() == 1U) {
    color_mode = color_mode_map_.begin()->first;
  } else if (color_mode_map_.size() > 1U) {
    std::string default_color_mode;
    bool found = false;
    DisplayError error = display_intf_->GetDefaultColorMode(&default_color_mode);
    if (error == kErrorNone) {
      // get the default mode corresponding android_color_mode_t
      for (auto &it_mode : color_mode_map_) {
        for (auto &it : it_mode.second) {
          if (it.second == default_color_mode) {
            found = true;
            break;
          }
        }
        if (found) {
          color_mode = it_mode.first;
          break;
        }
      }
    }

    // return the first color mode we encounter if not found
    if (!found) {
      color_mode = color_mode_map_.begin()->first;
    }
  }
  return SetColorModeWithRenderIntent(color_mode, RenderIntent::COLORIMETRIC);
}

PrimariesTransfer HWCColorMode::GetWorkingColorSpace() {
  ColorPrimaries primaries = ColorPrimaries_BT709_5;
  GammaTransfer transfer = Transfer_sRGB;
  switch (current_color_mode_) {
    case ColorMode::BT2100_PQ:
      primaries = ColorPrimaries_BT2020;
      transfer = Transfer_SMPTE_ST2084;
      break;
    case ColorMode::BT2100_HLG:
      primaries = ColorPrimaries_BT2020;
      transfer = Transfer_HLG;
      break;
    case ColorMode::DISPLAY_P3:
      primaries = ColorPrimaries_DCIP3;
      transfer = Transfer_sRGB;
      break;
    case ColorMode::NATIVE:
    case ColorMode::SRGB:
      break;
    default:
      DLOGW("Invalid color mode: %d", current_color_mode_);
      break;
  }
  return std::make_pair(primaries, transfer);
}

void HWCColorMode::Dump(std::ostringstream* os) {
  *os << "color modes supported: \n";
  for (auto it : color_mode_map_) {
    *os << "mode: " << static_cast<int32_t>(it.first) << " RIs { ";
    for (auto rit : color_mode_map_[it.first]) {
      *os << static_cast<int32_t>(rit.first) << " ";
    }
    *os << "} \n";
  }
  *os << "current mode: " << static_cast<uint32_t>(current_color_mode_) << std::endl;
  *os << "current render_intent: " << static_cast<uint32_t>(current_render_intent_) << std::endl;
  *os << "Need WhiteCompensation: "
      << (current_render_intent_ == RenderIntent::ENHANCE && HasWhiteCompensation()) << std::endl;
  *os << "Need SaturationCompensation: "
      << (current_render_intent_ == RenderIntent::ENHANCE && HasSaturationCompensation())
      << std::endl;

  *os << "current transform: ";
  double color_matrix[kColorTransformMatrixCount] = {0};

  CopyColorTransformMatrix(PickTransferMatrix(), color_matrix);

  for (uint32_t i = 0; i < kColorTransformMatrixCount; i++) {
    if (i % 4 == 0) {
     *os << std::endl;
    }
    *os << std::fixed << std::setprecision(4) << std::setw(8) << std::setfill(' ')
        << color_matrix[i] << " ";
  }
  *os << std::endl;
}

HWCDisplay::HWCDisplay(CoreInterface *core_intf, HWCCallbacks *callbacks, DisplayType type,
                       hwc2_display_t id, bool needs_blit, qService::QService *qservice,
                       DisplayClass display_class, BufferAllocator *buffer_allocator)
    : core_intf_(core_intf),
      callbacks_(callbacks),
      type_(type),
      id_(id),
      needs_blit_(needs_blit),
      qservice_(qservice),
      display_class_(display_class) {
  buffer_allocator_ = static_cast<HWCBufferAllocator *>(buffer_allocator);
}

int HWCDisplay::Init() {
  DisplayError error = core_intf_->CreateDisplay(type_, this, &display_intf_);
  if (error != kErrorNone) {
    DLOGE("Display create failed. Error = %d display_type %d event_handler %p disp_intf %p", error,
          type_, this, &display_intf_);
    return -EINVAL;
  }

  validated_ = false;
  HWCDebugHandler::Get()->GetProperty(DISABLE_HDR, &disable_hdr_handling_);
  if (disable_hdr_handling_) {
    DLOGI("HDR Handling disabled");
  }

  int property_swap_interval = 1;
  HWCDebugHandler::Get()->GetProperty("debug.egl.swapinterval", &property_swap_interval);
  if (property_swap_interval == 0) {
    swap_interval_zero_ = true;
  }

  client_target_ = new HWCLayer(id_, buffer_allocator_);

  int blit_enabled = 0;
  HWCDebugHandler::Get()->GetProperty(DISABLE_BLIT_COMPOSITION_PROP, &blit_enabled);
  if (needs_blit_ && blit_enabled) {
    // TODO(user): Add blit engine when needed
  }

  error = display_intf_->GetNumVariableInfoConfigs(&num_configs_);
  if (error != kErrorNone) {
    DLOGE("Getting config count failed. Error = %d", error);
    return -EINVAL;
  }

  display_intf_->GetRefreshRateRange(&min_refresh_rate_, &max_refresh_rate_);
  current_refresh_rate_ = max_refresh_rate_;

  GetUnderScanConfig();

  DisplayConfigFixedInfo fixed_info = {};
  display_intf_->GetConfig(&fixed_info);
  partial_update_enabled_ = fixed_info.partial_update || (!fixed_info.is_cmdmode);
  client_target_->SetPartialUpdate(partial_update_enabled_);

  DLOGI("Display created with id: %d", id_);

  return 0;
}

int HWCDisplay::Deinit() {
  DisplayError error = core_intf_->DestroyDisplay(display_intf_);
  if (error != kErrorNone) {
    DLOGE("Display destroy failed. Error = %d", error);
    return -EINVAL;
  }

  delete client_target_;
  for (auto hwc_layer : layer_set_) {
    delete hwc_layer;
  }

  if (color_mode_) {
    color_mode_->DeInit();
    delete color_mode_;
  }

  return 0;
}

// LayerStack operations
HWC2::Error HWCDisplay::CreateLayer(hwc2_layer_t *out_layer_id) {
  HWCLayer *layer = *layer_set_.emplace(new HWCLayer(id_, buffer_allocator_));
  layer_map_.emplace(std::make_pair(layer->GetId(), layer));
  *out_layer_id = layer->GetId();
  geometry_changes_ |= GeometryChanges::kAdded;
  validated_ = false;
  layer_stack_invalid_ = true;
  layer->SetPartialUpdate(partial_update_enabled_);

  return HWC2::Error::None;
}

HWCLayer *HWCDisplay::GetHWCLayer(hwc2_layer_t layer_id) {
  const auto map_layer = layer_map_.find(layer_id);
  if (map_layer == layer_map_.end()) {
    DLOGE("[%" PRIu64 "] GetLayer(%" PRIu64 ") failed: no such layer", id_, layer_id);
    return nullptr;
  } else {
    return map_layer->second;
  }
}

HWC2::Error HWCDisplay::DestroyLayer(hwc2_layer_t layer_id) {
  const auto map_layer = layer_map_.find(layer_id);
  if (map_layer == layer_map_.end()) {
    DLOGE("[%" PRIu64 "] destroyLayer(%" PRIu64 ") failed: no such layer", id_, layer_id);
    return HWC2::Error::BadLayer;
  }
  const auto layer = map_layer->second;
  layer_map_.erase(map_layer);
  const auto z_range = layer_set_.equal_range(layer);
  for (auto current = z_range.first; current != z_range.second; ++current) {
    if (*current == layer) {
      current = layer_set_.erase(current);
      delete layer;
      break;
    }
  }

  geometry_changes_ |= GeometryChanges::kRemoved;
  validated_ = false;
  layer_stack_invalid_ = true;

  return HWC2::Error::None;
}


void HWCDisplay::BuildLayerStack() {
  layer_stack_ = LayerStack();
  display_rect_ = LayerRect();
  metadata_refresh_rate_ = 0;
  bool secure_display_active = false;
  layer_stack_.flags.animating = animating_;

  uint32_t color_mode_count = 0;
  display_intf_->GetColorModeCount(&color_mode_count);
  hdr_largest_layer_px_ = 0.0f;

  // Add one layer for fb target
  // TODO(user): Add blit target layers
  for (auto hwc_layer : layer_set_) {
    // Reset layer data which SDM may change
    hwc_layer->ResetPerFrameData();

    Layer *layer = hwc_layer->GetSDMLayer();
    layer->flags = {};   // Reset earlier flags
    if (hwc_layer->GetClientRequestedCompositionType() == HWC2::Composition::Client) {
      layer->flags.skip = true;
    } else if (hwc_layer->GetClientRequestedCompositionType() == HWC2::Composition::SolidColor) {
      layer->flags.solid_fill = true;
    }

    if (!hwc_layer->ValidateAndSetCSC()) {
      layer->flags.skip = true;
    }

    auto range = hwc_layer->GetLayerDataspace() & HAL_DATASPACE_RANGE_MASK;
    if (range == HAL_DATASPACE_RANGE_EXTENDED) {
      layer->flags.skip = true;
    }

    if (hwc_layer->IsColorTransformSet()) {
      layer->flags.skip = true;
    }

    // set default composition as GPU for SDM
    layer->composition = kCompositionGPU;

    if (swap_interval_zero_) {
      if (layer->input_buffer.acquire_fence_fd >= 0) {
        close(layer->input_buffer.acquire_fence_fd);
        layer->input_buffer.acquire_fence_fd = -1;
      }
    }

    bool is_secure = false;
    bool is_video = false;
    const private_handle_t *handle =
        reinterpret_cast<const private_handle_t *>(layer->input_buffer.buffer_id);
    if (handle) {
      if (handle->buffer_type == BUFFER_TYPE_VIDEO) {
        layer_stack_.flags.video_present = true;
        is_video = true;
      } else if (layer->transform.rotation != 0.0f) {
        layer->flags.skip = true;
      }
      // TZ Protected Buffer - L1
      // Gralloc Usage Protected Buffer - L3 - which needs to be treated as Secure & avoid fallback
      if (handle->flags & private_handle_t::PRIV_FLAGS_PROTECTED_BUFFER ||
          handle->flags & private_handle_t::PRIV_FLAGS_SECURE_BUFFER) {
        layer_stack_.flags.secure_present = true;
        is_secure = true;
      }
    }

    if (layer->input_buffer.flags.secure_display) {
      secure_display_active = true;
      is_secure = true;
    }

    if (hwc_layer->IsSingleBuffered() &&
       !(hwc_layer->IsRotationPresent() || hwc_layer->IsScalingPresent())) {
      layer->flags.single_buffer = true;
      layer_stack_.flags.single_buffered_layer_present = true;
    }

    if (hwc_layer->GetClientRequestedCompositionType() == HWC2::Composition::Cursor) {
      // Currently we support only one HWCursor & only at top most z-order
      if ((*layer_set_.rbegin())->GetId() == hwc_layer->GetId()) {
        layer->flags.cursor = true;
        layer_stack_.flags.cursor_present = true;
      }
    }

    bool hdr_layer = layer->input_buffer.color_metadata.colorPrimaries == ColorPrimaries_BT2020 &&
                     (layer->input_buffer.color_metadata.transfer == Transfer_SMPTE_ST2084 ||
                     layer->input_buffer.color_metadata.transfer == Transfer_HLG);
    if (hdr_layer && !disable_hdr_handling_  &&
        current_color_mode_ != ColorMode::NATIVE) {
      // Dont honor HDR when its handling is disabled
      // Also, when the color mode is native, it implies that
      // SF has not correctly set the mode to BT2100_PQ in the presence of an HDR layer
      // In such cases, we should not handle HDR as the HDR mode isn't applied
      layer->input_buffer.flags.hdr = true;
      layer_stack_.flags.hdr_present = true;

      // HDR area
      auto hdr_layer_area = (layer->dst_rect.right - layer->dst_rect.left) *
                            (layer->dst_rect.bottom - layer->dst_rect.top);
      hdr_largest_layer_px_ = std::max(hdr_largest_layer_px_, hdr_layer_area);
    }

    if (hwc_layer->IsNonIntegralSourceCrop() && !is_secure && !layer->flags.solid_fill &&
        !is_video) {
      layer->flags.skip = true;
    }

    if (layer->flags.skip) {
      layer_stack_.flags.skip_present = true;
    }

    // TODO(user): Move to a getter if this is needed at other places
    hwc_rect_t scaled_display_frame = {INT(layer->dst_rect.left), INT(layer->dst_rect.top),
                                       INT(layer->dst_rect.right), INT(layer->dst_rect.bottom)};
    if (hwc_layer->GetGeometryChanges() & kDisplayFrame) {
      ApplyScanAdjustment(&scaled_display_frame);
    }
    hwc_layer->SetLayerDisplayFrame(scaled_display_frame);
    hwc_layer->ResetPerFrameData();
    // SDM requires these details even for solid fill
    if (layer->flags.solid_fill) {
      LayerBuffer *layer_buffer = &layer->input_buffer;
      layer_buffer->width = UINT32(layer->dst_rect.right - layer->dst_rect.left);
      layer_buffer->height = UINT32(layer->dst_rect.bottom - layer->dst_rect.top);
      layer_buffer->unaligned_width = layer_buffer->width;
      layer_buffer->unaligned_height = layer_buffer->height;
      layer_buffer->acquire_fence_fd = -1;
      layer_buffer->release_fence_fd = -1;
      layer->src_rect.left = 0;
      layer->src_rect.top = 0;
      layer->src_rect.right = FLOAT(layer_buffer->width);
      layer->src_rect.bottom = FLOAT(layer_buffer->height);
    }

    if (hwc_layer->HasMetaDataRefreshRate() && layer->frame_rate > metadata_refresh_rate_) {
      metadata_refresh_rate_ = SanitizeRefreshRate(layer->frame_rate);
    }

    display_rect_ = Union(display_rect_, layer->dst_rect);
    geometry_changes_ |= hwc_layer->GetGeometryChanges();

    layer->flags.updating = true;
    if (layer_set_.size() <= kMaxLayerCount) {
      layer->flags.updating = IsLayerUpdating(hwc_layer);
    }

    layer_stack_.layers.push_back(layer);
  }

  for (auto hwc_layer : layer_set_) {
    auto layer = hwc_layer->GetSDMLayer();
    if (layer->input_buffer.color_metadata.colorPrimaries != working_primaries_ &&
        !hwc_layer->SupportLocalConversion(working_primaries_)) {
      layer->flags.skip = true;
    }
    if (layer->flags.skip) {
      layer_stack_.flags.skip_present = true;
    }
  }

  // TODO(user): Set correctly when SDM supports geometry_changes as bitmask
  layer_stack_.flags.geometry_changed = UINT32(geometry_changes_ > 0);
  // Append client target to the layer stack
  Layer *sdm_client_target = client_target_->GetSDMLayer();
  sdm_client_target->flags.updating = IsLayerUpdating(client_target_);
  layer_stack_.layers.push_back(sdm_client_target);
  // fall back frame composition to GPU when client target is 10bit
  // TODO(user): clarify the behaviour from Client(SF) and SDM Extn -
  // when handling 10bit FBT, as it would affect blending
  if (Is10BitFormat(sdm_client_target->input_buffer.format)) {
    // Must fall back to client composition
    MarkLayersForClientComposition();
  }
  // set secure display
  SetSecureDisplay(secure_display_active);
}

void HWCDisplay::BuildSolidFillStack() {
  layer_stack_ = LayerStack();
  display_rect_ = LayerRect();

  layer_stack_.layers.push_back(solid_fill_layer_);
  layer_stack_.flags.geometry_changed = 1U;
  // Append client target to the layer stack
  layer_stack_.layers.push_back(client_target_->GetSDMLayer());
}

HWC2::Error HWCDisplay::SetLayerZOrder(hwc2_layer_t layer_id, uint32_t z) {
  const auto map_layer = layer_map_.find(layer_id);
  if (map_layer == layer_map_.end()) {
    DLOGE("[%" PRIu64 "] updateLayerZ failed to find layer", id_);
    return HWC2::Error::BadLayer;
  }

  const auto layer = map_layer->second;
  const auto z_range = layer_set_.equal_range(layer);
  bool layer_on_display = false;
  for (auto current = z_range.first; current != z_range.second; ++current) {
    if (*current == layer) {
      if ((*current)->GetZ() == z) {
        // Don't change anything if the Z hasn't changed
        return HWC2::Error::None;
      }
      current = layer_set_.erase(current);
      layer_on_display = true;
      break;
    }
  }

  if (!layer_on_display) {
    DLOGE("[%" PRIu64 "] updateLayerZ failed to find layer on display", id_);
    return HWC2::Error::BadLayer;
  }

  layer->SetLayerZOrder(z);
  layer_set_.emplace(layer);
  return HWC2::Error::None;
}

HWC2::Error HWCDisplay::SetVsyncEnabled(HWC2::Vsync enabled) {
  DLOGV("Display ID: %d enabled: %s", id_, to_string(enabled).c_str());
  ATRACE_INT("SetVsyncState ", enabled == HWC2::Vsync::Enable ? 1 : 0);
  DisplayError error = kErrorNone;

  if (shutdown_pending_ || !callbacks_->VsyncCallbackRegistered()) {
    return HWC2::Error::None;
  }

  bool state;
  if (enabled == HWC2::Vsync::Enable)
    state = true;
  else if (enabled == HWC2::Vsync::Disable)
    state = false;
  else
    return HWC2::Error::BadParameter;

  error = display_intf_->SetVSyncState(state);

  if (error != kErrorNone) {
    if (error == kErrorShutDown) {
      shutdown_pending_ = true;
      return HWC2::Error::None;
    }
    DLOGE("Failed. enabled = %s, error = %d", to_string(enabled).c_str(), error);
    return HWC2::Error::BadDisplay;
  }

  return HWC2::Error::None;
}

HWC2::Error HWCDisplay::SetPowerMode(HWC2::PowerMode mode) {
  DLOGV("display = %d, mode = %s", id_, to_string(mode).c_str());
  DisplayState state = kStateOff;
  bool flush_on_error = flush_on_error_;

  if (shutdown_pending_) {
    return HWC2::Error::None;
  }

  switch (mode) {
    case HWC2::PowerMode::Off:
      // During power off, all of the buffers are released.
      // Do not flush until a buffer is successfully submitted again.
      flush_on_error = false;
      state = kStateOff;
      if (tone_mapper_) {
        tone_mapper_->Terminate();
      }
      break;
    case HWC2::PowerMode::On:
      state = kStateOn;
      last_power_mode_ = HWC2::PowerMode::On;
      break;
    case HWC2::PowerMode::Doze:
      state = kStateDoze;
      last_power_mode_ = HWC2::PowerMode::Doze;
      break;
    case HWC2::PowerMode::DozeSuspend:
      state = kStateDozeSuspend;
      last_power_mode_ = HWC2::PowerMode::DozeSuspend;
      break;
    default:
      return HWC2::Error::BadParameter;
  }
  int release_fence = -1;

  ATRACE_INT("SetPowerMode ", state);
  DisplayError error = display_intf_->SetDisplayState(state, &release_fence);
  validated_ = false;

  if (error == kErrorNone) {
    flush_on_error_ = flush_on_error;
  } else {
    if (error == kErrorShutDown) {
      shutdown_pending_ = true;
      return HWC2::Error::None;
    }
    DLOGE("Set state failed. Error = %d", error);
    return HWC2::Error::BadParameter;
  }

  if (release_fence >= 0) {
    for (auto hwc_layer : layer_set_) {
      auto fence = hwc_layer->PopBackReleaseFence();
      auto merged_fence = -1;
      if (fence >= 0) {
        merged_fence = sync_merge("sync_merge", release_fence, fence);
        ::close(fence);
      } else {
        merged_fence = ::dup(release_fence);
      }
      hwc_layer->PushBackReleaseFence(merged_fence);
    }
    ::close(release_fence);
  }
  return HWC2::Error::None;
}

HWC2::Error HWCDisplay::GetClientTargetSupport(uint32_t width, uint32_t height, int32_t format,
                                               int32_t dataspace) {
  ColorMetaData color_metadata = {};
  if (dataspace != HAL_DATASPACE_UNKNOWN) {
    GetColorPrimary(dataspace, &(color_metadata.colorPrimaries));
    GetTransfer(dataspace, &(color_metadata.transfer));
    GetRange(dataspace, &(color_metadata.range));
  }

  LayerBufferFormat sdm_format = GetSDMFormat(format, 0);
  if (display_intf_->GetClientTargetSupport(width, height, sdm_format,
                                            color_metadata) != kErrorNone) {
    return HWC2::Error::Unsupported;
  }

  return HWC2::Error::None;
}

HWC2::Error HWCDisplay::GetColorModes(uint32_t *out_num_modes, ColorMode *out_modes) {
  if (out_modes == nullptr) {
    *out_num_modes = 1;
  } else if (out_modes && *out_num_modes > 0) {
    *out_num_modes = 1;
    out_modes[0] = ColorMode::NATIVE;
  }
  return HWC2::Error::None;
}

HWC2::Error HWCDisplay::GetRenderIntents(ColorMode mode, uint32_t *out_num_intents,
                                         RenderIntent *out_intents) {
  if (mode != ColorMode::NATIVE) {
    return HWC2::Error::Unsupported;
  }
  if (out_intents == nullptr) {
    *out_num_intents = 1;
  } else if (out_intents && *out_num_intents > 0) {
    *out_num_intents = 1;
    out_intents[0] = RenderIntent::COLORIMETRIC;
  }
  return HWC2::Error::None;
}

HWC2::Error HWCDisplay::GetDisplayConfigs(uint32_t *out_num_configs, hwc2_config_t *out_configs) {
  if (out_num_configs == nullptr) {
    return HWC2::Error::BadParameter;
  }

  if (out_configs == nullptr) {
    *out_num_configs = num_configs_;
    return HWC2::Error::None;
  }

  *out_num_configs = std::min(*out_num_configs, num_configs_);
  for (uint32_t i = 0; i < *out_num_configs; i++) {
    out_configs[i] = i;
  }

  return HWC2::Error::None;
}

HWC2::Error HWCDisplay::GetDisplayAttribute(hwc2_config_t config, HWC2::Attribute attribute,
                                            int32_t *out_value) {
  DisplayConfigVariableInfo variable_config;
  // Get display attributes from config index only if resolution switch is supported.
  // Otherwise always send mixer attributes. This is to support destination scaler.
  if (num_configs_ > 1) {
    if (GetDisplayAttributesForConfig(INT(config), &variable_config) != kErrorNone) {
      DLOGE("Get variable config failed");
      return HWC2::Error::BadDisplay;
    }
  } else {
    if (display_intf_->GetFrameBufferConfig(&variable_config) != kErrorNone) {
      DLOGV("Get variable config failed");
      return HWC2::Error::BadDisplay;
    }
  }

  switch (attribute) {
    case HWC2::Attribute::VsyncPeriod:
      *out_value = INT32(variable_config.vsync_period_ns);
      break;
    case HWC2::Attribute::Width:
      *out_value = INT32(variable_config.x_pixels);
      break;
    case HWC2::Attribute::Height:
      *out_value = INT32(variable_config.y_pixels);
      break;
    case HWC2::Attribute::DpiX:
      *out_value = INT32(variable_config.x_dpi * 1000.0f);
      break;
    case HWC2::Attribute::DpiY:
      *out_value = INT32(variable_config.y_dpi * 1000.0f);
      break;
    default:
      DLOGW("Spurious attribute type = %s", to_string(attribute).c_str());
      *out_value = -1;
      return HWC2::Error::BadConfig;
  }

  return HWC2::Error::None;
}

HWC2::Error HWCDisplay::GetDisplayName(uint32_t *out_size, char *out_name) {
  // TODO(user): Get panel name and EDID name and populate it here
  if (out_size == nullptr) {
    return HWC2::Error::BadParameter;
  }

  std::string name;
  switch (id_) {
    case HWC_DISPLAY_PRIMARY:
      name = "Primary Display";
      break;
    case HWC_DISPLAY_EXTERNAL:
      name = "External Display";
      break;
    case HWC_DISPLAY_VIRTUAL:
      name = "Virtual Display";
      break;
    default:
      name = "Unknown";
      break;
  }

  if (out_name == nullptr) {
    *out_size = UINT32(name.size()) + 1;
  } else {
    *out_size = std::min((UINT32(name.size()) + 1), *out_size);
    if (*out_size > 0) {
      std::strncpy(out_name, name.c_str(), *out_size);
      out_name[*out_size - 1] = '\0';
    } else {
      DLOGW("Invalid size requested");
    }
  }

  return HWC2::Error::None;
}

HWC2::Error HWCDisplay::GetDisplayType(int32_t *out_type) {
  if (out_type != nullptr) {
    if (id_ == HWC_DISPLAY_VIRTUAL) {
      *out_type = HWC2_DISPLAY_TYPE_VIRTUAL;
    } else {
      *out_type = HWC2_DISPLAY_TYPE_PHYSICAL;
    }
    return HWC2::Error::None;
  } else {
    return HWC2::Error::BadParameter;
  }
}

HWC2::Error HWCDisplay::GetPerFrameMetadataKeys(uint32_t *out_num_keys,
                                                PerFrameMetadataKey *out_keys) {
  if (out_num_keys == nullptr) {
    return HWC2::Error::BadParameter;
  }
  *out_num_keys = UINT32(PerFrameMetadataKey::MAX_FRAME_AVERAGE_LIGHT_LEVEL) + 1;
  if (out_keys != nullptr) {
    out_keys[0] = PerFrameMetadataKey::DISPLAY_RED_PRIMARY_X;
    out_keys[1] = PerFrameMetadataKey::DISPLAY_RED_PRIMARY_Y;
    out_keys[2] = PerFrameMetadataKey::DISPLAY_GREEN_PRIMARY_X;
    out_keys[3] = PerFrameMetadataKey::DISPLAY_GREEN_PRIMARY_Y;
    out_keys[4] = PerFrameMetadataKey::DISPLAY_BLUE_PRIMARY_X;
    out_keys[5] = PerFrameMetadataKey::DISPLAY_BLUE_PRIMARY_Y;
    out_keys[6] = PerFrameMetadataKey::WHITE_POINT_X;
    out_keys[7] = PerFrameMetadataKey::WHITE_POINT_Y;
    out_keys[8] = PerFrameMetadataKey::MAX_LUMINANCE;
    out_keys[9] = PerFrameMetadataKey::MIN_LUMINANCE;
    out_keys[10] = PerFrameMetadataKey::MAX_CONTENT_LIGHT_LEVEL;
    out_keys[11] = PerFrameMetadataKey::MAX_FRAME_AVERAGE_LIGHT_LEVEL;
  }
  return HWC2::Error::None;
}

HWC2::Error HWCDisplay::GetActiveConfig(hwc2_config_t *out_config) {
  if (out_config == nullptr) {
    return HWC2::Error::BadDisplay;
  }

  uint32_t active_index = 0;
  if (GetActiveDisplayConfig(&active_index) != kErrorNone) {
    return HWC2::Error::BadConfig;
  }

  *out_config = active_index;

  return HWC2::Error::None;
}

HWC2::Error HWCDisplay::SetClientTarget(buffer_handle_t target, int32_t acquire_fence,
                                        int32_t dataspace, hwc_region_t damage) {
  // TODO(user): SurfaceFlinger gives us a null pointer here when doing full SDE composition
  // The error is problematic for layer caching as it would overwrite our cached client target.
  // Reported bug 28569722 to resolve this.
  // For now, continue to use the last valid buffer reported to us for layer caching.
  if (target == nullptr) {
    return HWC2::Error::None;
  }

  if (acquire_fence == 0) {
    DLOGE("acquire_fence is zero");
    return HWC2::Error::BadParameter;
  }

  Layer *sdm_layer = client_target_->GetSDMLayer();
  sdm_layer->frame_rate = current_refresh_rate_;
  client_target_->SetLayerBuffer(target, acquire_fence);
  client_target_->SetLayerSurfaceDamage(damage);
  if (client_target_->GetLayerDataspace() != dataspace) {
    client_target_->SetLayerDataspace(dataspace);
    Layer *sdm_layer = client_target_->GetSDMLayer();
    // Data space would be validated at GetClientTargetSupport, so just use here.
    sdm::GetSDMColorSpace(dataspace, &sdm_layer->input_buffer.color_metadata);
  }

  return HWC2::Error::None;
}

HWC2::Error HWCDisplay::SetActiveConfig(hwc2_config_t config) {
  if (SetActiveDisplayConfig(config) != kErrorNone) {
    return HWC2::Error::BadConfig;
  }

  validated_ = false;
  return HWC2::Error::None;
}

DisplayError HWCDisplay::SetMixerResolution(uint32_t width, uint32_t height) {
  return kErrorNotSupported;
}

HWC2::Error HWCDisplay::SetFrameDumpConfig(uint32_t count, uint32_t bit_mask_layer_type,
                                           int32_t format, bool post_processed) {
  dump_frame_count_ = count;
  dump_frame_index_ = 0;
  dump_input_layers_ = ((bit_mask_layer_type & (1 << INPUT_LAYER_DUMP)) != 0);

  if (tone_mapper_) {
    tone_mapper_->SetFrameDumpConfig(count);
  }

  DLOGI("num_frame_dump %d, input_layer_dump_enable %d", dump_frame_count_, dump_input_layers_);
  validated_ = false;
  return HWC2::Error::None;
}

HWC2::PowerMode HWCDisplay::GetLastPowerMode() {
  return last_power_mode_;
}

DisplayError HWCDisplay::VSync(const DisplayEventVSync &vsync) {
  callbacks_->Vsync(id_, vsync.timestamp);
  return kErrorNone;
}

DisplayError HWCDisplay::Refresh() {
  return kErrorNotSupported;
}

DisplayError HWCDisplay::CECMessage(char *message) {
  if (qservice_) {
    qservice_->onCECMessageReceived(message, 0);
  } else {
    DLOGW("Qservice instance not available.");
  }

  return kErrorNone;
}

DisplayError HWCDisplay::HandleEvent(DisplayEvent event) {
  switch (event) {
    case kIdleTimeout: {
      SCOPE_LOCK(HWCSession::locker_[type_]);
      if (pending_commit_) {
        // If idle timeout event comes in between prepare
        // and commit, drop it since device is not really
        // idle.
        return kErrorNotSupported;
      }
      validated_ = false;
      break;
    }
    case kThermalEvent:
    case kPanelDeadEvent: {
      SEQUENCE_WAIT_SCOPE_LOCK(HWCSession::locker_[type_]);
      validated_ = false;
    } break;
    case kIdlePowerCollapse:
      break;
    default:
      DLOGW("Unknown event: %d", event);
      break;
  }

  return kErrorNone;
}

HWC2::Error HWCDisplay::PrepareLayerStack(uint32_t *out_num_types, uint32_t *out_num_requests) {
  layer_changes_.clear();
  layer_requests_.clear();
  has_client_composition_ = false;

  if (shutdown_pending_) {
    validated_ = false;
    return HWC2::Error::BadDisplay;
  }

  UpdateRefreshRate();

  if (CanSkipSdmPrepare(out_num_types, out_num_requests)) {
    return ((*out_num_types > 0) ? HWC2::Error::HasChanges : HWC2::Error::None);
  }

  if (!skip_prepare_) {
    DisplayError error = display_intf_->Prepare(&layer_stack_);
    if (error != kErrorNone) {
      if (error == kErrorShutDown) {
        shutdown_pending_ = true;
      } else if (error != kErrorPermission) {
        DLOGE("Prepare failed. Error = %d", error);
        // To prevent surfaceflinger infinite wait, flush the previous frame during Commit()
        // so that previous buffer and fences are released, and override the error.
        flush_ = true;
      }
      validated_ = false;
      return HWC2::Error::BadDisplay;
    }
  } else {
    // Skip is not set
    MarkLayersForGPUBypass();
    skip_prepare_ = false;
    DLOGI("SecureDisplay %s, Skip Prepare/Commit and Flush",
          secure_display_active_ ? "Starting" : "Stopping");
    flush_ = true;
  }

  for (auto hwc_layer : layer_set_) {
    Layer *layer = hwc_layer->GetSDMLayer();
    LayerComposition &composition = layer->composition;

    if ((composition == kCompositionSDE) || (composition == kCompositionHybrid) ||
        (composition == kCompositionBlit)) {
      layer_requests_[hwc_layer->GetId()] = HWC2::LayerRequest::ClearClientTarget;
    }

    HWC2::Composition requested_composition = hwc_layer->GetClientRequestedCompositionType();
    // Set SDM composition to HWC2 type in HWCLayer
    hwc_layer->SetComposition(composition);
    HWC2::Composition device_composition  = hwc_layer->GetDeviceSelectedCompositionType();
    if (device_composition == HWC2::Composition::Client) {
      has_client_composition_ = true;
    }
    // Update the changes list only if the requested composition is different from SDM comp type
    // TODO(user): Take Care of other comptypes(BLIT)
    if (requested_composition != device_composition) {
      layer_changes_[hwc_layer->GetId()] = device_composition;
    }
    hwc_layer->ResetValidation();
  }

  client_target_->ResetValidation();
  *out_num_types = UINT32(layer_changes_.size());
  *out_num_requests = UINT32(layer_requests_.size());
  validate_state_ = kNormalValidate;
  validated_ = true;
  layer_stack_invalid_ = false;
  return ((*out_num_types > 0) ? HWC2::Error::HasChanges : HWC2::Error::None);
}

HWC2::Error HWCDisplay::AcceptDisplayChanges() {
  if (layer_set_.empty()) {
    return HWC2::Error::None;
  }

  if (!validated_) {
    return HWC2::Error::NotValidated;
  }

  for (const auto& change : layer_changes_) {
    auto hwc_layer = layer_map_[change.first];
    auto composition = change.second;
    if (hwc_layer != nullptr) {
      hwc_layer->UpdateClientCompositionType(composition);
    } else {
      DLOGW("Invalid layer: %" PRIu64, change.first);
    }
  }
  return HWC2::Error::None;
}

HWC2::Error HWCDisplay::GetChangedCompositionTypes(uint32_t *out_num_elements,
                                                   hwc2_layer_t *out_layers, int32_t *out_types) {
  if (layer_set_.empty()) {
    return HWC2::Error::None;
  }

  if (!validated_) {
    DLOGW("Display is not validated");
    return HWC2::Error::NotValidated;
  }

  *out_num_elements = UINT32(layer_changes_.size());
  if (out_layers != nullptr && out_types != nullptr) {
    int i = 0;
    for (auto change : layer_changes_) {
      out_layers[i] = change.first;
      out_types[i] = INT32(change.second);
      i++;
    }
  }
  return HWC2::Error::None;
}

HWC2::Error HWCDisplay::GetReleaseFences(uint32_t *out_num_elements, hwc2_layer_t *out_layers,
                                         int32_t *out_fences) {
  if (out_num_elements == nullptr) {
    return HWC2::Error::BadParameter;
  }

  if (out_layers != nullptr && out_fences != nullptr) {
    *out_num_elements = std::min(*out_num_elements, UINT32(layer_set_.size()));
    auto it = layer_set_.begin();
    for (uint32_t i = 0; i < *out_num_elements; i++, it++) {
      auto hwc_layer = *it;
      out_layers[i] = hwc_layer->GetId();
      out_fences[i] = hwc_layer->PopFrontReleaseFence();
    }
  } else {
    *out_num_elements = UINT32(layer_set_.size());
  }

  return HWC2::Error::None;
}

HWC2::Error HWCDisplay::GetDisplayRequests(int32_t *out_display_requests,
                                           uint32_t *out_num_elements, hwc2_layer_t *out_layers,
                                           int32_t *out_layer_requests) {
  if (layer_set_.empty()) {
    return HWC2::Error::None;
  }

  if (out_display_requests == nullptr || out_num_elements == nullptr) {
    return HWC2::Error::BadParameter;
  }

  // No display requests for now
  // Use for sharing blit buffers and
  // writing wfd buffer directly to output if there is full GPU composition
  // and no color conversion needed
  if (!validated_) {
    DLOGW("Display is not validated");
    return HWC2::Error::NotValidated;
  }

  *out_display_requests = 0;
  if (out_layers != nullptr && out_layer_requests != nullptr) {
    *out_num_elements = std::min(*out_num_elements, UINT32(layer_requests_.size()));
    auto it = layer_requests_.begin();
    for (uint32_t i = 0; i < *out_num_elements; i++, it++) {
      out_layers[i] = it->first;
      out_layer_requests[i] = INT32(it->second);
    }
  } else {
    *out_num_elements = UINT32(layer_requests_.size());
  }

  auto client_target_layer = client_target_->GetSDMLayer();
  if (client_target_layer->request.flags.flip_buffer) {
    *out_display_requests = INT32(HWC2::DisplayRequest::FlipClientTarget);
  }

  return HWC2::Error::None;
}

HWC2::Error HWCDisplay::GetHdrCapabilities(uint32_t *out_num_types, int32_t *out_types,
                                           float *out_max_luminance,
                                           float *out_max_average_luminance,
                                           float *out_min_luminance) {
  if (out_num_types == nullptr || out_max_luminance == nullptr ||
      out_max_average_luminance == nullptr || out_min_luminance == nullptr) {
    return HWC2::Error::BadParameter;
  }

  DisplayConfigFixedInfo fixed_info = {};
  display_intf_->GetConfig(&fixed_info);

  if (!fixed_info.hdr_supported) {
    *out_num_types = 0;
    DLOGI("HDR is not supported");
    return HWC2::Error::None;
  }

  if (out_types == nullptr) {
    // We support HDR10 and HLG
    *out_num_types = 2;
  } else {
    // HDR10 and HLG are supported
    out_types[0] = HAL_HDR_HDR10;
    out_types[1] = HAL_HDR_HLG;
    static const float kLuminanceFactor = 10000.0;
    // luminance is expressed in the unit of 0.0001 cd/m2, convert it to 1cd/m2.
    *out_max_luminance = FLOAT(fixed_info.max_luminance)/kLuminanceFactor;
    *out_max_average_luminance = FLOAT(fixed_info.average_luminance)/kLuminanceFactor;
    *out_min_luminance = FLOAT(fixed_info.min_luminance)/kLuminanceFactor;
  }

  return HWC2::Error::None;
}


HWC2::Error HWCDisplay::CommitLayerStack(void) {
  if (!validated_) {
    DLOGV_IF(kTagClient, "Display %d is not validated", id_);
    return HWC2::Error::NotValidated;
  }

  if (shutdown_pending_ || layer_set_.empty()) {
    return HWC2::Error::None;
  }

  DumpInputBuffers();

  if (!flush_) {
    DisplayError error = kErrorUndefined;
    int status = 0;
    if (tone_mapper_) {
      if (layer_stack_.flags.hdr_present) {
        status = tone_mapper_->HandleToneMap(&layer_stack_);
        if (status != 0) {
          DLOGE("Error handling HDR in ToneMapper");
        }
      } else {
        tone_mapper_->Terminate();
      }
    }
    error = display_intf_->Commit(&layer_stack_);

    if (error == kErrorNone) {
      // A commit is successfully submitted, start flushing on failure now onwards.
      flush_on_error_ = true;
    } else {
      if (error == kErrorShutDown) {
        shutdown_pending_ = true;
        return HWC2::Error::Unsupported;
      } else if (error == kErrorNotValidated) {
        validated_ = false;
        return HWC2::Error::NotValidated;
      } else if (error != kErrorPermission) {
        DLOGE("Commit failed. Error = %d", error);
        // To prevent surfaceflinger infinite wait, flush the previous frame during Commit()
        // so that previous buffer and fences are released, and override the error.
        flush_ = true;
      }
    }
  }

  validate_state_ = kSkipValidate;
  return HWC2::Error::None;
}

HWC2::Error HWCDisplay::PostCommitLayerStack(int32_t *out_retire_fence) {
  auto status = HWC2::Error::None;

  // Do no call flush on errors, if a successful buffer is never submitted.
  if (flush_ && flush_on_error_) {
    display_intf_->Flush();
    validated_ = false;
  }

  if (tone_mapper_ && tone_mapper_->IsActive()) {
     tone_mapper_->PostCommit(&layer_stack_);
  }

  // TODO(user): No way to set the client target release fence on SF
  int32_t &client_target_release_fence =
      client_target_->GetSDMLayer()->input_buffer.release_fence_fd;
  if (client_target_release_fence >= 0) {
    close(client_target_release_fence);
    client_target_release_fence = -1;
  }
  client_target_->ResetGeometryChanges();

  for (auto hwc_layer : layer_set_) {
    hwc_layer->ResetGeometryChanges();
    Layer *layer = hwc_layer->GetSDMLayer();
    LayerBuffer *layer_buffer = &layer->input_buffer;

    if (!flush_) {
      // If swapinterval property is set to 0 or for single buffer layers, do not update f/w
      // release fences and discard fences from driver
      if (swap_interval_zero_ || layer->flags.single_buffer) {
        close(layer_buffer->release_fence_fd);
      } else if (layer->composition != kCompositionGPU) {
        hwc_layer->PushBackReleaseFence(layer_buffer->release_fence_fd);
      } else {
        hwc_layer->PushBackReleaseFence(-1);
      }
    } else {
      // In case of flush, we don't return an error to f/w, so it will get a release fence out of
      // the hwc_layer's release fence queue. We should push a -1 to preserve release fence
      // circulation semantics.
      hwc_layer->PushBackReleaseFence(-1);
    }

    layer_buffer->release_fence_fd = -1;
    if (layer_buffer->acquire_fence_fd >= 0) {
      close(layer_buffer->acquire_fence_fd);
      layer_buffer->acquire_fence_fd = -1;
    }

    layer->request.flags = {};
  }

  client_target_->GetSDMLayer()->request.flags = {};
  *out_retire_fence = -1;
  if (!flush_) {
    // if swapinterval property is set to 0 then close and reset the list retire fence
    if (swap_interval_zero_) {
      close(layer_stack_.retire_fence_fd);
      layer_stack_.retire_fence_fd = -1;
    }
    *out_retire_fence = layer_stack_.retire_fence_fd;
    layer_stack_.retire_fence_fd = -1;

    if (dump_frame_count_) {
      dump_frame_count_--;
      dump_frame_index_++;
    }
  }
  config_pending_ = false;

  geometry_changes_ = GeometryChanges::kNone;
  flush_ = false;

  return status;
}

void HWCDisplay::SetIdleTimeoutMs(uint32_t timeout_ms) {
  return;
}

DisplayError HWCDisplay::SetMaxMixerStages(uint32_t max_mixer_stages) {
  DisplayError error = kErrorNone;

  if (display_intf_) {
    error = display_intf_->SetMaxMixerStages(max_mixer_stages);
    validated_ = false;
  }

  return error;
}

LayerBufferFormat HWCDisplay::GetSDMFormat(const int32_t &source, const int flags) {
  LayerBufferFormat format = kFormatInvalid;
  if (flags & private_handle_t::PRIV_FLAGS_UBWC_ALIGNED) {
    switch (source) {
      case HAL_PIXEL_FORMAT_RGBA_8888:
        format = kFormatRGBA8888Ubwc;
        break;
      case HAL_PIXEL_FORMAT_RGBX_8888:
        format = kFormatRGBX8888Ubwc;
        break;
      case HAL_PIXEL_FORMAT_BGR_565:
        format = kFormatBGR565Ubwc;
        break;
      case HAL_PIXEL_FORMAT_YCbCr_420_SP_VENUS:
      case HAL_PIXEL_FORMAT_YCbCr_420_SP_VENUS_UBWC:
      case HAL_PIXEL_FORMAT_NV12_ENCODEABLE:
        format = kFormatYCbCr420SPVenusUbwc;
        break;
      case HAL_PIXEL_FORMAT_RGBA_1010102:
        format = kFormatRGBA1010102Ubwc;
        break;
      case HAL_PIXEL_FORMAT_RGBX_1010102:
        format = kFormatRGBX1010102Ubwc;
        break;
      case HAL_PIXEL_FORMAT_YCbCr_420_TP10_UBWC:
        format = kFormatYCbCr420TP10Ubwc;
        break;
      case HAL_PIXEL_FORMAT_YCbCr_420_P010_UBWC:
        format = kFormatYCbCr420P010Ubwc;
        break;
      default:
        DLOGE("Unsupported format type for UBWC %d", source);
        return kFormatInvalid;
    }
    return format;
  }

  switch (source) {
    case HAL_PIXEL_FORMAT_RGBA_8888:
      format = kFormatRGBA8888;
      break;
    case HAL_PIXEL_FORMAT_RGBA_5551:
      format = kFormatRGBA5551;
      break;
    case HAL_PIXEL_FORMAT_RGBA_4444:
      format = kFormatRGBA4444;
      break;
    case HAL_PIXEL_FORMAT_BGRA_8888:
      format = kFormatBGRA8888;
      break;
    case HAL_PIXEL_FORMAT_RGBX_8888:
      format = kFormatRGBX8888;
      break;
    case HAL_PIXEL_FORMAT_BGRX_8888:
      format = kFormatBGRX8888;
      break;
    case HAL_PIXEL_FORMAT_RGB_888:
      format = kFormatRGB888;
      break;
    case HAL_PIXEL_FORMAT_RGB_565:
      format = kFormatRGB565;
      break;
    case HAL_PIXEL_FORMAT_BGR_565:
      format = kFormatBGR565;
      break;
    case HAL_PIXEL_FORMAT_BGR_888:
      format = kFormatBGR888;
      break;
    case HAL_PIXEL_FORMAT_NV12_ENCODEABLE:
    case HAL_PIXEL_FORMAT_YCbCr_420_SP_VENUS:
      format = kFormatYCbCr420SemiPlanarVenus;
      break;
    case HAL_PIXEL_FORMAT_YCrCb_420_SP_VENUS:
      format = kFormatYCrCb420SemiPlanarVenus;
      break;
    case HAL_PIXEL_FORMAT_YCbCr_420_SP_VENUS_UBWC:
      format = kFormatYCbCr420SPVenusUbwc;
      break;
    case HAL_PIXEL_FORMAT_YV12:
      format = kFormatYCrCb420PlanarStride16;
      break;
    case HAL_PIXEL_FORMAT_YCrCb_420_SP:
      format = kFormatYCrCb420SemiPlanar;
      break;
    case HAL_PIXEL_FORMAT_YCbCr_420_SP:
      format = kFormatYCbCr420SemiPlanar;
      break;
    case HAL_PIXEL_FORMAT_YCbCr_422_SP:
      format = kFormatYCbCr422H2V1SemiPlanar;
      break;
    case HAL_PIXEL_FORMAT_YCbCr_422_I:
      format = kFormatYCbCr422H2V1Packed;
      break;
    case HAL_PIXEL_FORMAT_CbYCrY_422_I:
      format = kFormatCbYCrY422H2V1Packed;
      break;
    case HAL_PIXEL_FORMAT_RGBA_1010102:
      format = kFormatRGBA1010102;
      break;
    case HAL_PIXEL_FORMAT_ARGB_2101010:
      format = kFormatARGB2101010;
      break;
    case HAL_PIXEL_FORMAT_RGBX_1010102:
      format = kFormatRGBX1010102;
      break;
    case HAL_PIXEL_FORMAT_XRGB_2101010:
      format = kFormatXRGB2101010;
      break;
    case HAL_PIXEL_FORMAT_BGRA_1010102:
      format = kFormatBGRA1010102;
      break;
    case HAL_PIXEL_FORMAT_ABGR_2101010:
      format = kFormatABGR2101010;
      break;
    case HAL_PIXEL_FORMAT_BGRX_1010102:
      format = kFormatBGRX1010102;
      break;
    case HAL_PIXEL_FORMAT_XBGR_2101010:
      format = kFormatXBGR2101010;
      break;
    case HAL_PIXEL_FORMAT_YCbCr_420_P010:
      format = kFormatYCbCr420P010;
      break;
    case HAL_PIXEL_FORMAT_YCbCr_420_TP10_UBWC:
      format = kFormatYCbCr420TP10Ubwc;
      break;
    case HAL_PIXEL_FORMAT_YCbCr_420_P010_UBWC:
      format = kFormatYCbCr420P010Ubwc;
      break;
    case HAL_PIXEL_FORMAT_YCbCr_420_P010_VENUS:
      format = kFormatYCbCr420P010Venus;
      break;
    default:
      DLOGW("Unsupported format type = %d", source);
      return kFormatInvalid;
  }

  return format;
}

void HWCDisplay::DumpInputBuffers() {
  char dir_path[PATH_MAX];
  int  status;

  if (!dump_frame_count_ || flush_ || !dump_input_layers_) {
    return;
  }

  DLOGI("dump_frame_count %d dump_input_layers %d", dump_frame_count_, dump_input_layers_);
  snprintf(dir_path, sizeof(dir_path), "%s/frame_dump_%s", HWCDebugHandler::DumpDir(),
           GetDisplayString());

  status = mkdir(dir_path, 777);
  if ((status != 0) && errno != EEXIST) {
    DLOGW("Failed to create %s directory errno = %d, desc = %s", dir_path, errno, strerror(errno));
    return;
  }

  // Even if directory exists already, need to explicitly change the permission.
  if (chmod(dir_path, 0777) != 0) {
    DLOGW("Failed to change permissions on %s directory", dir_path);
    return;
  }

  for (uint32_t i = 0; i < layer_stack_.layers.size(); i++) {
    auto layer = layer_stack_.layers.at(i);
    const private_handle_t *pvt_handle =
        reinterpret_cast<const private_handle_t *>(layer->input_buffer.buffer_id);
    auto acquire_fence_fd = layer->input_buffer.acquire_fence_fd;

    if (acquire_fence_fd >= 0) {
      int error = sync_wait(acquire_fence_fd, 1000);
      if (error < 0) {
        DLOGW("sync_wait error errno = %d, desc = %s", errno, strerror(errno));
        return;
      }
    }

    DLOGI("Dump layer[%d] of %d pvt_handle %x pvt_handle->base %x", i, layer_stack_.layers.size(),
          pvt_handle, pvt_handle? pvt_handle->base : 0);

    if (!pvt_handle) {
      DLOGE("Buffer handle is null");
      return;
    }

    if (!pvt_handle->base) {
      DisplayError error = buffer_allocator_->MapBuffer(pvt_handle, -1);
      if (error != kErrorNone) {
        DLOGE("Failed to map buffer, error = %d", error);
        return;
      }
    }

    char dump_file_name[PATH_MAX];
    size_t result = 0;

    snprintf(dump_file_name, sizeof(dump_file_name), "%s/input_layer%d_%dx%d_%s_frame%d.raw",
             dir_path, i, pvt_handle->width, pvt_handle->height,
             qdutils::GetHALPixelFormatString(pvt_handle->format), dump_frame_index_);

    FILE *fp = fopen(dump_file_name, "w+");
    if (fp) {
      result = fwrite(reinterpret_cast<void *>(pvt_handle->base), pvt_handle->size, 1, fp);
      fclose(fp);
    }

    int release_fence = -1;
    DisplayError error = buffer_allocator_->UnmapBuffer(pvt_handle, &release_fence);
    if (error != kErrorNone) {
      DLOGE("Failed to unmap buffer, error = %d", error);
      return;
    }

    DLOGI("Frame Dump %s: is %s", dump_file_name, result ? "Successful" : "Failed");
  }
}

void HWCDisplay::DumpOutputBuffer(const BufferInfo &buffer_info, void *base, int fence) {
  char dir_path[PATH_MAX];
  int  status;

  snprintf(dir_path, sizeof(dir_path), "%s/frame_dump_%s", HWCDebugHandler::DumpDir(),
           GetDisplayString());

  status = mkdir(dir_path, 777);
  if ((status != 0) && errno != EEXIST) {
    DLOGW("Failed to create %s directory errno = %d, desc = %s", dir_path, errno, strerror(errno));
    return;
  }

  // Even if directory exists already, need to explicitly change the permission.
  if (chmod(dir_path, 0777) != 0) {
    DLOGW("Failed to change permissions on %s directory", dir_path);
    return;
  }

  if (base) {
    char dump_file_name[PATH_MAX];
    size_t result = 0;

    if (fence >= 0) {
      int error = sync_wait(fence, 1000);
      if (error < 0) {
        DLOGW("sync_wait error errno = %d, desc = %s", errno, strerror(errno));
        return;
      }
    }

    snprintf(dump_file_name, sizeof(dump_file_name), "%s/output_layer_%dx%d_%s_frame%d.raw",
             dir_path, buffer_info.alloc_buffer_info.aligned_width,
             buffer_info.alloc_buffer_info.aligned_height,
             GetFormatString(buffer_info.buffer_config.format), dump_frame_index_);

    FILE *fp = fopen(dump_file_name, "w+");
    if (fp) {
      result = fwrite(base, buffer_info.alloc_buffer_info.size, 1, fp);
      fclose(fp);
    }

    DLOGI("Frame Dump of %s is %s", dump_file_name, result ? "Successful" : "Failed");
  }
}

const char *HWCDisplay::GetDisplayString() {
  switch (type_) {
    case kPrimary:
      return "primary";
    case kHDMI:
      return "hdmi";
    case kVirtual:
      return "virtual";
    default:
      return "invalid";
  }
}

int HWCDisplay::SetFrameBufferResolution(uint32_t x_pixels, uint32_t y_pixels) {
  if (x_pixels <= 0 || y_pixels <= 0) {
    DLOGW("Unsupported config: x_pixels=%d, y_pixels=%d", x_pixels, y_pixels);
    return -EINVAL;
  }

  DisplayConfigVariableInfo fb_config;
  DisplayError error = display_intf_->GetFrameBufferConfig(&fb_config);
  if (error != kErrorNone) {
    DLOGV("Get frame buffer config failed. Error = %d", error);
    return -EINVAL;
  }

  fb_config.x_pixels = x_pixels;
  fb_config.y_pixels = y_pixels;

  error = display_intf_->SetFrameBufferConfig(fb_config);
  if (error != kErrorNone) {
    DLOGV("Set frame buffer config failed. Error = %d", error);
    return -EINVAL;
  }

  // Create rects to represent the new source and destination crops
  LayerRect crop = LayerRect(0, 0, FLOAT(x_pixels), FLOAT(y_pixels));
  hwc_rect_t scaled_display_frame = {0, 0, INT(x_pixels), INT(y_pixels)};
  ApplyScanAdjustment(&scaled_display_frame);
  client_target_->SetLayerDisplayFrame(scaled_display_frame);
  client_target_->ResetPerFrameData();

  auto client_target_layer = client_target_->GetSDMLayer();
  client_target_layer->src_rect = crop;

  int aligned_width;
  int aligned_height;
  uint32_t usage = GRALLOC_USAGE_HW_FB;
  int format = HAL_PIXEL_FORMAT_RGBA_8888;
  int ubwc_disabled = 0;
  int flags = 0;

  // By default UBWC is enabled and below property is global enable/disable for all
  // buffers allocated through gralloc , including framebuffer targets.
  HWCDebugHandler::Get()->GetProperty(DISABLE_UBWC_PROP, &ubwc_disabled);
  if (!ubwc_disabled) {
    usage |= GRALLOC_USAGE_PRIVATE_ALLOC_UBWC;
    flags |= private_handle_t::PRIV_FLAGS_UBWC_ALIGNED;
  }

  buffer_allocator_->GetAlignedWidthAndHeight(INT(x_pixels), INT(y_pixels), format, usage,
                                              &aligned_width, &aligned_height);

  // TODO(user): How does the dirty region get set on the client target? File bug on Google
  client_target_layer->composition = kCompositionGPUTarget;
  client_target_layer->input_buffer.format = GetSDMFormat(format, flags);
  client_target_layer->input_buffer.width = UINT32(aligned_width);
  client_target_layer->input_buffer.height = UINT32(aligned_height);
  client_target_layer->input_buffer.unaligned_width = x_pixels;
  client_target_layer->input_buffer.unaligned_height = y_pixels;
  client_target_layer->plane_alpha = 255;

  DLOGI("New framebuffer resolution (%dx%d)", fb_config.x_pixels, fb_config.y_pixels);

  return 0;
}

void HWCDisplay::GetFrameBufferResolution(uint32_t *x_pixels, uint32_t *y_pixels) {
  DisplayConfigVariableInfo fb_config;
  display_intf_->GetFrameBufferConfig(&fb_config);

  *x_pixels = fb_config.x_pixels;
  *y_pixels = fb_config.y_pixels;
}

DisplayError HWCDisplay::GetMixerResolution(uint32_t *x_pixels, uint32_t *y_pixels) {
  return display_intf_->GetMixerResolution(x_pixels, y_pixels);
}

void HWCDisplay::GetPanelResolution(uint32_t *x_pixels, uint32_t *y_pixels) {
  DisplayConfigVariableInfo display_config;
  uint32_t active_index = 0;

  display_intf_->GetActiveConfig(&active_index);
  display_intf_->GetConfig(active_index, &display_config);

  *x_pixels = display_config.x_pixels;
  *y_pixels = display_config.y_pixels;
}

int HWCDisplay::SetDisplayStatus(DisplayStatus display_status) {
  int status = 0;

  switch (display_status) {
    case kDisplayStatusResume:
      display_paused_ = false;
      status = INT32(SetPowerMode(HWC2::PowerMode::On));
      break;
    case kDisplayStatusOnline:
      status = INT32(SetPowerMode(HWC2::PowerMode::On));
      break;
    case kDisplayStatusPause:
      display_paused_ = true;
      status = INT32(SetPowerMode(HWC2::PowerMode::Off));
      break;
    case kDisplayStatusOffline:
      status = INT32(SetPowerMode(HWC2::PowerMode::Off));
      break;
    default:
      DLOGW("Invalid display status %d", display_status);
      return -EINVAL;
  }

  if (display_status == kDisplayStatusResume || display_status == kDisplayStatusPause) {
    callbacks_->Refresh(HWC_DISPLAY_PRIMARY);
    validated_ = false;
  }

  return status;
}

HWC2::Error HWCDisplay::SetCursorPosition(hwc2_layer_t layer, int x, int y) {
  if (shutdown_pending_) {
    return HWC2::Error::None;
  }

  HWCLayer *hwc_layer = GetHWCLayer(layer);
  if (hwc_layer == nullptr) {
    return HWC2::Error::BadLayer;
  }
  if (hwc_layer->GetDeviceSelectedCompositionType() != HWC2::Composition::Cursor) {
    return HWC2::Error::None;
  }
  if ((validate_state_ != kSkipValidate) && validated_) {
    // the device is currently in the middle of the validate/present sequence,
    // cannot set the Position(as per HWC2 spec)
    return HWC2::Error::NotValidated;
  }

  DisplayState state;
  if (display_intf_->GetDisplayState(&state) == kErrorNone) {
    if (state != kStateOn) {
      return HWC2::Error::None;
    }
  }

  // TODO(user): HWC1.5 was not letting SetCursorPosition before validateDisplay,
  // but HWC2.0 doesn't let setting cursor position after validate before present.
  // Need to revisit.

  auto error = display_intf_->SetCursorPosition(x, y);
  if (error != kErrorNone) {
    if (error == kErrorShutDown) {
      shutdown_pending_ = true;
      return HWC2::Error::None;
    }

    DLOGE("Failed for x = %d y = %d, Error = %d", x, y, error);
    return HWC2::Error::BadDisplay;
  }

  return HWC2::Error::None;
}

int HWCDisplay::OnMinHdcpEncryptionLevelChange(uint32_t min_enc_level) {
  DisplayError error = display_intf_->OnMinHdcpEncryptionLevelChange(min_enc_level);
  if (error != kErrorNone) {
    DLOGE("Failed. Error = %d", error);
    return -1;
  }

  validated_ = false;
  return 0;
}

void HWCDisplay::MarkLayersForGPUBypass() {
  for (auto hwc_layer : layer_set_) {
    auto layer = hwc_layer->GetSDMLayer();
    layer->composition = kCompositionSDE;
  }
  validated_ = true;
}

void HWCDisplay::MarkLayersForClientComposition() {
  // ClientComposition - GPU comp, to acheive this, set skip flag so that
  // SDM does not handle this layer and hwc_layer composition will be
  // set correctly at the end of Prepare.
  DLOGV_IF(kTagClient, "HWC Layers marked for GPU comp");
  for (auto hwc_layer : layer_set_) {
    Layer *layer = hwc_layer->GetSDMLayer();
    layer->flags.skip = true;
  }
  layer_stack_.flags.skip_present = true;
}

void HWCDisplay::ApplyScanAdjustment(hwc_rect_t *display_frame) {
}

int HWCDisplay::SetPanelBrightness(int level) {
  int ret = 0;
  if (display_intf_) {
    ret = display_intf_->SetPanelBrightness(level);
    validated_ = false;
  } else {
    ret = -EINVAL;
  }

  return ret;
}

int HWCDisplay::GetPanelBrightness(int *level) {
  return display_intf_->GetPanelBrightness(level);
}

int HWCDisplay::ToggleScreenUpdates(bool enable) {
  display_paused_ = enable ? false : true;
  callbacks_->Refresh(HWC_DISPLAY_PRIMARY);
  validated_ = false;
  return 0;
}

int HWCDisplay::ColorSVCRequestRoute(const PPDisplayAPIPayload &in_payload,
                                     PPDisplayAPIPayload *out_payload,
                                     PPPendingParams *pending_action) {
  int ret = 0;

  if (display_intf_)
    ret = display_intf_->ColorSVCRequestRoute(in_payload, out_payload, pending_action);
  else
    ret = -EINVAL;

  return ret;
}

void HWCDisplay::SolidFillPrepare() {
  if (solid_fill_enable_) {
    if (solid_fill_layer_ == NULL) {
      // Create a dummy layer here
      solid_fill_layer_ = new Layer();
    }
    uint32_t primary_width = 0, primary_height = 0;
    GetMixerResolution(&primary_width, &primary_height);

    LayerBuffer *layer_buffer = &solid_fill_layer_->input_buffer;
    layer_buffer->width = primary_width;
    layer_buffer->height = primary_height;
    layer_buffer->unaligned_width = primary_width;
    layer_buffer->unaligned_height = primary_height;
    layer_buffer->acquire_fence_fd = -1;
    layer_buffer->release_fence_fd = -1;

    solid_fill_layer_->composition = kCompositionGPU;
    solid_fill_layer_->src_rect = solid_fill_rect_;
    solid_fill_layer_->dst_rect = solid_fill_rect_;

    solid_fill_layer_->blending = kBlendingPremultiplied;
    solid_fill_layer_->solid_fill_color = 0;
    solid_fill_layer_->solid_fill_info.bit_depth = solid_fill_color_.bit_depth;
    solid_fill_layer_->solid_fill_info.red = solid_fill_color_.red;
    solid_fill_layer_->solid_fill_info.blue = solid_fill_color_.blue;
    solid_fill_layer_->solid_fill_info.green = solid_fill_color_.green;
    solid_fill_layer_->solid_fill_info.alpha = solid_fill_color_.alpha;
    solid_fill_layer_->frame_rate = 60;
    solid_fill_layer_->visible_regions.push_back(solid_fill_layer_->dst_rect);
    solid_fill_layer_->flags.updating = 1;
    solid_fill_layer_->flags.solid_fill = true;
  } else {
    // delete the dummy layer
    delete solid_fill_layer_;
    solid_fill_layer_ = NULL;
  }

  if (solid_fill_enable_ && solid_fill_layer_) {
    BuildSolidFillStack();
    MarkLayersForGPUBypass();
  }

  return;
}

void HWCDisplay::SolidFillCommit() {
  if (solid_fill_enable_ && solid_fill_layer_) {
    LayerBuffer *layer_buffer = &solid_fill_layer_->input_buffer;
    if (layer_buffer->release_fence_fd > 0) {
      close(layer_buffer->release_fence_fd);
      layer_buffer->release_fence_fd = -1;
    }
    if (layer_stack_.retire_fence_fd > 0) {
      close(layer_stack_.retire_fence_fd);
      layer_stack_.retire_fence_fd = -1;
    }
  }
}

int HWCDisplay::GetVisibleDisplayRect(hwc_rect_t *visible_rect) {
  if (!IsValid(display_rect_)) {
    return -EINVAL;
  }

  visible_rect->left = INT(display_rect_.left);
  visible_rect->top = INT(display_rect_.top);
  visible_rect->right = INT(display_rect_.right);
  visible_rect->bottom = INT(display_rect_.bottom);
  DLOGI("Dpy = %d Visible Display Rect(%d %d %d %d)", visible_rect->left, visible_rect->top,
        visible_rect->right, visible_rect->bottom);

  return 0;
}

void HWCDisplay::SetSecureDisplay(bool secure_display_active) {
  if (secure_display_active_ != secure_display_active) {
    DLOGI("SecureDisplay state changed from %d to %d Needs Flush!!", secure_display_active_,
          secure_display_active);
    secure_display_active_ = secure_display_active;
    skip_prepare_ = true;
  }
  return;
}

int HWCDisplay::SetActiveDisplayConfig(uint32_t config) {
  if (display_config_ == config) {
    return 0;
  }
  display_config_ = config;
  config_pending_ = true;
  validated_ = false;

  callbacks_->Refresh(id_);

  return 0;
}

int HWCDisplay::GetActiveDisplayConfig(uint32_t *config) {
  if (config_pending_) {
    *config = display_config_;
    return 0;
  }
  return display_intf_->GetActiveConfig(config) == kErrorNone ? 0 : -1;
}

int HWCDisplay::GetDisplayConfigCount(uint32_t *count) {
  return display_intf_->GetNumVariableInfoConfigs(count) == kErrorNone ? 0 : -1;
}

int HWCDisplay::GetDisplayAttributesForConfig(int config,
                                            DisplayConfigVariableInfo *display_attributes) {
  return display_intf_->GetConfig(UINT32(config), display_attributes) == kErrorNone ? 0 : -1;
}

uint32_t HWCDisplay::GetUpdatingLayersCount(void) {
  uint32_t updating_count = 0;

  for (uint i = 0; i < layer_stack_.layers.size(); i++) {
    auto layer = layer_stack_.layers.at(i);
    if (layer->flags.updating) {
      updating_count++;
    }
  }

  return updating_count;
}

bool HWCDisplay::IsLayerUpdating(HWCLayer *hwc_layer) {
  auto layer = hwc_layer->GetSDMLayer();
  // Layer should be considered updating if
  //   a) layer is in single buffer mode, or
  //   b) valid dirty_regions(android specific hint for updating status), or
  //   c) layer stack geometry has changed (TODO(user): Remove when SDM accepts
  //      geometry_changed as bit fields).
  return (layer->flags.single_buffer || hwc_layer->IsSurfaceUpdated() ||
          geometry_changes_);
}

uint32_t HWCDisplay::SanitizeRefreshRate(uint32_t req_refresh_rate) {
  uint32_t refresh_rate = req_refresh_rate;

  if (refresh_rate < min_refresh_rate_) {
    // Pick the next multiple of request which is within the range
    refresh_rate =
        (((min_refresh_rate_ / refresh_rate) + ((min_refresh_rate_ % refresh_rate) ? 1 : 0)) *
         refresh_rate);
  }

  if (refresh_rate > max_refresh_rate_) {
    refresh_rate = max_refresh_rate_;
  }

  return refresh_rate;
}

DisplayClass HWCDisplay::GetDisplayClass() {
  return display_class_;
}

std::string HWCDisplay::Dump() {
  std::ostringstream os;
  os << "\n------------HWC----------------\n";
  os << "HWC2 display_id: " << id_ << std::endl;
  for (auto layer : layer_set_) {
    auto sdm_layer = layer->GetSDMLayer();
    auto transform = sdm_layer->transform;
    os << "layer: " << std::setw(4) << layer->GetId();
    os << " z: " << layer->GetZ();
    os << " composition: " <<
          to_string(layer->GetClientRequestedCompositionType()).c_str();
    os << "/" <<
          to_string(layer->GetDeviceSelectedCompositionType()).c_str();
    os << " alpha: " << std::to_string(sdm_layer->plane_alpha).c_str();
    os << " format: " << std::setw(22) << GetFormatString(sdm_layer->input_buffer.format);
    os << " dataspace:" << std::hex << "0x" << std::setw(8) << std::setfill('0')
       << layer->GetLayerDataspace() << std::dec << std::setfill(' ');
    os << " transform: " << transform.rotation << "/" << transform.flip_horizontal <<
          "/"<< transform.flip_vertical;
    os << " buffer_id: " << std::hex << "0x" << sdm_layer->input_buffer.buffer_id << std::dec
       << std::endl;
  }

  if (layer_stack_invalid_) {
    os << "\n Layers added or removed but not reflected to SDM's layer stack yet\n";
    return os.str();
  }

  if (color_mode_) {
    os << "\n----------Color Modes---------\n";
    color_mode_->Dump(&os);
  }

  if (display_intf_) {
    os << "\n------------SDM----------------\n";
    os << display_intf_->Dump();
  }

  os << "\n";

  return os.str();
}

bool HWCDisplay::CanSkipValidate() {
  if (!validated_ || solid_fill_enable_) {
    return false;
  }

  // Layer Stack checks
  if ((layer_stack_.flags.hdr_present && (tone_mapper_ && tone_mapper_->IsActive())) ||
     layer_stack_.flags.single_buffered_layer_present) {
    DLOGV_IF(kTagClient, "HDR content present with tone mapping enabled. Returning false.");
    return false;
  }

  if (client_target_->NeedsValidation()) {
    DLOGV_IF(kTagClient, "Framebuffer target needs validation. Returning false.");
    return false;
  }

  for (auto hwc_layer : layer_set_) {
    if (hwc_layer->NeedsValidation()) {
      DLOGV_IF(kTagClient, "hwc_layer[%d] needs validation. Returning false.",
               hwc_layer->GetId());
      return false;
    }

    // Do not allow Skip Validate, if any layer needs GPU Composition.
    if (hwc_layer->GetDeviceSelectedCompositionType() == HWC2::Composition::Client) {
      DLOGV_IF(kTagClient, "hwc_layer[%d] is GPU composed. Returning false.",
               hwc_layer->GetId());
      return false;
    }
  }

  return true;
}

HWC2::Error HWCDisplay::GetValidateDisplayOutput(uint32_t *out_num_types,
                                                 uint32_t *out_num_requests) {
  *out_num_types = UINT32(layer_changes_.size());
  *out_num_requests = UINT32(layer_requests_.size());

  return ((*out_num_types > 0) ? HWC2::Error::HasChanges : HWC2::Error::None);
}

HWC2::Error HWCDisplay::SetDisplayedContentSamplingEnabledVndService(bool enabled) {
  return HWC2::Error::Unsupported;
}

HWC2::Error HWCDisplay::SetDisplayedContentSamplingEnabled(int32_t enabled,
    uint8_t component_mask, uint64_t max_frames) {

  DLOGV("Request to start/stop histogram thread not supported on this display");
  return HWC2::Error::Unsupported;
}

HWC2::Error HWCDisplay::GetDisplayedContentSamplingAttributes(int32_t* format,
                                                              int32_t* dataspace,
                                                              uint8_t* supported_components) {
  return HWC2::Error::Unsupported;
}

HWC2::Error HWCDisplay::GetDisplayedContentSample(uint64_t max_frames,
                                                  uint64_t timestamp,
                                                  uint64_t* numFrames,
                                                  int32_t samples_size[NUM_HISTOGRAM_COLOR_COMPONENTS],
                                                  uint64_t* samples[NUM_HISTOGRAM_COLOR_COMPONENTS]) {
  return HWC2::Error::Unsupported;
}

void HWCDisplay::UpdateRefreshRate() {
  for (auto hwc_layer : layer_set_) {
    if (hwc_layer->HasMetaDataRefreshRate()) {
      continue;
    }
    auto layer = hwc_layer->GetSDMLayer();
    layer->frame_rate = current_refresh_rate_;
  }

  Layer *sdm_client_target = client_target_->GetSDMLayer();
  sdm_client_target->frame_rate = current_refresh_rate_;
}

// Skip SDM prepare if all the layers in the current draw cycle are marked as Skip and
// previous draw cycle had GPU Composition, as the resources for GPU Target layer have
// already been validated and configured to the driver.
bool HWCDisplay::CanSkipSdmPrepare(uint32_t *num_types, uint32_t *num_requests) {
  if (!validated_ || layer_set_.empty()) {
    return false;
  }

  bool skip_prepare = true;
  for (auto hwc_layer : layer_set_) {
    if (!hwc_layer->GetSDMLayer()->flags.skip ||
        (hwc_layer->GetDeviceSelectedCompositionType() != HWC2::Composition::Client)) {
      skip_prepare = false;
      layer_changes_.clear();
      break;
    }
    if (hwc_layer->GetClientRequestedCompositionType() != HWC2::Composition::Client) {
      layer_changes_[hwc_layer->GetId()] = HWC2::Composition::Client;
    }
  }

  if (skip_prepare) {
    *num_types = UINT32(layer_changes_.size());
    *num_requests = 0;
    layer_stack_invalid_ = false;
    has_client_composition_ = true;
    client_target_->ResetValidation();
    validate_state_ = kNormalValidate;
  }

  return skip_prepare;
}

}  // namespace sdm
