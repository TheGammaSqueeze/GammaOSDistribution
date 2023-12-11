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

#include <QService.h>
#include <binder/Parcel.h>
#include <core/buffer_allocator.h>
#include <cutils/properties.h>
#include <display_config.h>
#include <hardware_legacy/uevent.h>
#include <private/color_params.h>
#include <qd_utils.h>
#include <sync/sync.h>
#include <sys/prctl.h>
#include <sys/resource.h>
#include <utils/String16.h>
#include <utils/constants.h>
#include <utils/debug.h>
#include <utils/utils.h>
#include <algorithm>
#include <bitset>
#include <memory>
#include <string>
#include <thread>
#include <vector>

#include "hwc_buffer_allocator.h"
#include "hwc_buffer_sync_handler.h"
#include "hwc_session.h"
#include "hwc_debugger.h"
#include "hwc_display_primary.h"
#include "hwc_display_virtual.h"
#include "hwc_display_external_test.h"

#define __CLASS__ "HWCSession"

#define HWC_UEVENT_SWITCH_HDMI "change@/devices/virtual/switch/hdmi"
#define HWC_UEVENT_GRAPHICS_FB0 "change@/devices/virtual/graphics/fb0"
#define HWC_UEVENT_DRM_EXT_HOTPLUG "mdss_mdp/drm/card"

#define MAX_BRIGHTNESS 255
#define BRIGHTNESS_FILE1 "/sys/class/leds/lcd-backlight/brightness"
#define BRIGHTNESS_FILE2 "/sys/class/backlight/panel0-backlight/brightness"

static sdm::HWCSession::HWCModuleMethods g_hwc_module_methods;

hwc_module_t HAL_MODULE_INFO_SYM = {
  .common = {
    .tag = HARDWARE_MODULE_TAG,
    .version_major = 3,
    .version_minor = 0,
    .id = HWC_HARDWARE_MODULE_ID,
    .name = "QTI Hardware Composer Module",
    .author = "CodeAurora Forum",
    .methods = &g_hwc_module_methods,
    .dso = 0,
    .reserved = {0},
  }
};

namespace sdm {

static HWCUEvent g_hwc_uevent_;
Locker HWCSession::locker_[HWC_NUM_DISPLAY_TYPES];
static const int kSolidFillDelay = 100 * 1000;

void HWCUEvent::UEventThread(HWCUEvent *hwc_uevent) {
  const char *uevent_thread_name = "HWC_UeventThread";

  prctl(PR_SET_NAME, uevent_thread_name, 0, 0, 0);
  setpriority(PRIO_PROCESS, 0, HAL_PRIORITY_URGENT_DISPLAY);

  int status = uevent_init();
  if (!status) {
    std::unique_lock<std::mutex> caller_lock(hwc_uevent->mutex_);
    hwc_uevent->caller_cv_.notify_one();
    DLOGE("Failed to init uevent with err %d", status);
    return;
  }

  {
    // Signal caller thread that worker thread is ready to listen to events.
    std::unique_lock<std::mutex> caller_lock(hwc_uevent->mutex_);
    hwc_uevent->init_done_ = true;
    hwc_uevent->caller_cv_.notify_one();
  }

  while (1) {
    char uevent_data[PAGE_SIZE] = {};

    // keep last 2 zeroes to ensure double 0 termination
    int length = uevent_next_event(uevent_data, INT32(sizeof(uevent_data)) - 2);

    // scope of lock to this block only, so that caller is free to set event handler to nullptr;
    {
      std::lock_guard<std::mutex> guard(hwc_uevent->mutex_);
      if (hwc_uevent->uevent_listener_) {
        hwc_uevent->uevent_listener_->UEventHandler(uevent_data, length);
      } else {
        DLOGW("UEvent dropped. No uevent listener.");
      }
    }
  }
}

HWCUEvent::HWCUEvent() {
  std::unique_lock<std::mutex> caller_lock(mutex_);
  std::thread thread(HWCUEvent::UEventThread, this);
  thread.detach();
  caller_cv_.wait(caller_lock);
}

void HWCUEvent::Register(HWCUEventListener *uevent_listener) {
  DLOGI("Set uevent listener = %p", uevent_listener);

  std::lock_guard<std::mutex> obj(mutex_);
  uevent_listener_ = uevent_listener;
}

HWCSession::HWCSession(const hw_module_t *module) {
  hwc2_device_t::common.tag = HARDWARE_DEVICE_TAG;
  hwc2_device_t::common.version = HWC_DEVICE_API_VERSION_2_0;
  hwc2_device_t::common.module = const_cast<hw_module_t *>(module);
  hwc2_device_t::common.close = Close;
  hwc2_device_t::getCapabilities = GetCapabilities;
  hwc2_device_t::getFunction = GetFunction;
}

int HWCSession::Init() {
  SCOPE_LOCK(locker_[HWC_DISPLAY_PRIMARY]);

  int status = -EINVAL;
  const char *qservice_name = "display.qservice";

  if (!g_hwc_uevent_.InitDone()) {
    return status;
  }

  // Start QService and connect to it.
  qService::QService::init();
  android::sp<qService::IQService> iqservice = android::interface_cast<qService::IQService>(
      android::defaultServiceManager()->getService(android::String16(qservice_name)));

  if (iqservice.get()) {
    iqservice->connect(android::sp<qClient::IQClient>(this));
    qservice_ = reinterpret_cast<qService::QService *>(iqservice.get());
  } else {
    DLOGE("Failed to acquire %s", qservice_name);
    return -EINVAL;
  }

  StartServices();

  g_hwc_uevent_.Register(this);

  auto error = CoreInterface::CreateCore(&buffer_allocator_, &buffer_sync_handler_,
                                    &socket_handler_, &core_intf_);

  // If HDMI display is primary display, defer display creation until hotplug event is received.
  HWDisplayInterfaceInfo hw_disp_info = {};
  error = core_intf_->GetFirstDisplayInterfaceType(&hw_disp_info);
  if (error != kErrorNone) {
    g_hwc_uevent_.Register(nullptr);
    CoreInterface::DestroyCore();
    DLOGE("Primary display type not recognized. Error = %d", error);
    return -EINVAL;
  }

  if (hw_disp_info.type == kHDMI) {
    status = 0;
    hdmi_is_primary_ = true;
    // Create display if it is connected, else wait for hotplug connect event.
    if (hw_disp_info.is_connected) {
      status = CreateExternalDisplay(HWC_DISPLAY_PRIMARY, 0, 0, false);
    }
  } else {
    // Create and power on primary display
    status = HWCDisplayPrimary::Create(core_intf_, &buffer_allocator_, &callbacks_, qservice_,
                                       &hwc_display_[HWC_DISPLAY_PRIMARY]);
    color_mgr_ = HWCColorManager::CreateColorManager(&buffer_allocator_);
    if (!color_mgr_) {
      DLOGW("Failed to load HWCColorManager.");
    }
  }

  if (status) {
    g_hwc_uevent_.Register(nullptr);
    CoreInterface::DestroyCore();
    return status;
  }

  is_composer_up_ = true;
  struct rlimit fd_limit = {};
  getrlimit(RLIMIT_NOFILE, &fd_limit);
  fd_limit.rlim_cur = fd_limit.rlim_cur * 2;
  if (fd_limit.rlim_cur < fd_limit.rlim_max) {
    auto err = setrlimit(RLIMIT_NOFILE, &fd_limit);
    if (err) {
      DLOGW("Unable to increase fd limit -  err:%d, %s", errno, strerror(errno));
    }
  }

  char const *brightness_file;
  if (access(BRIGHTNESS_FILE1, F_OK) == 0) {
    brightness_file = BRIGHTNESS_FILE1;
  } else {
    brightness_file = BRIGHTNESS_FILE2;
  }
  brightness_fd_ = open(brightness_file, O_WRONLY);
  if (brightness_fd_ == -1) {
    DLOGW("Unable to open brightness file: [%d] %s", errno, strerror(errno));
  }

  return 0;
}

int HWCSession::Deinit() {
  Locker::SequenceCancelScopeLock lock_v(locker_[HWC_DISPLAY_VIRTUAL]);
  Locker::SequenceCancelScopeLock lock_e(locker_[HWC_DISPLAY_EXTERNAL]);
  Locker::SequenceCancelScopeLock lock_p(locker_[HWC_DISPLAY_PRIMARY]);

  HWCDisplay *primary_display = hwc_display_[HWC_DISPLAY_PRIMARY];
  if (primary_display) {
    if (hdmi_is_primary_) {
      HWCDisplayExternal::Destroy(primary_display);
    } else {
      HWCDisplayPrimary::Destroy(primary_display);
    }
  }
  hwc_display_[HWC_DISPLAY_PRIMARY] = nullptr;

  if (color_mgr_) {
    color_mgr_->DestroyColorManager();
  }

  g_hwc_uevent_.Register(nullptr);

  DisplayError error = CoreInterface::DestroyCore();
  if (error != kErrorNone) {
    DLOGE("Display core de-initialization failed. Error = %d", error);
  }

  close(brightness_fd_);

  return 0;
}

int HWCSession::Open(const hw_module_t *module, const char *name, hw_device_t **device) {
  if (!module || !name || !device) {
    DLOGE("Invalid parameters.");
    return -EINVAL;
  }

  if (!strcmp(name, HWC_HARDWARE_COMPOSER)) {
    HWCSession *hwc_session = new HWCSession(module);
    if (!hwc_session) {
      return -ENOMEM;
    }

    int status = hwc_session->Init();
    if (status != 0) {
      delete hwc_session;
      hwc_session = NULL;
      return status;
    }

    hwc2_device_t *composer_device = hwc_session;
    *device = reinterpret_cast<hw_device_t *>(composer_device);
  }

  return 0;
}

int HWCSession::Close(hw_device_t *device) {
  if (!device) {
    return -EINVAL;
  }

  hwc2_device_t *composer_device = reinterpret_cast<hwc2_device_t *>(device);
  HWCSession *hwc_session = static_cast<HWCSession *>(composer_device);

  hwc_session->Deinit();

  return 0;
}

void HWCSession::GetCapabilities(struct hwc2_device *device, uint32_t *outCount,
                                 int32_t *outCapabilities) {
  if (!outCount) {
    return;
  }

  int value = 0;
  bool disable_skip_validate = false;
  if (Debug::Get()->GetProperty(DISABLE_SKIP_VALIDATE_PROP, &value) == kErrorNone) {
    disable_skip_validate = (value == 1);
  }
  uint32_t count = 1 + (disable_skip_validate ? 0 : 1);

  if (outCapabilities != nullptr && (*outCount >= count)) {
    outCapabilities[0] = HWC2_CAPABILITY_SKIP_CLIENT_COLOR_TRANSFORM;
    if (!disable_skip_validate) {
      outCapabilities[1] = HWC2_CAPABILITY_SKIP_VALIDATE;
    }
  }
  *outCount = count;
}

int32_t HWCSession::GetDisplayBrightnessSupport(hwc2_device_t *device, hwc2_display_t display,
                                                bool *out_support) {
  HWCSession *hwc_session = static_cast<HWCSession *>(device);
  *out_support = display == HWC_DISPLAY_PRIMARY && hwc_session->brightness_fd_ != -1;
  return INT32(HWC2::Error::None);
}

template <typename PFN, typename T>
static hwc2_function_pointer_t AsFP(T function) {
  static_assert(std::is_same<PFN, T>::value, "Incompatible function pointer");
  return reinterpret_cast<hwc2_function_pointer_t>(function);
}

// HWC2 functions returned in GetFunction
// Defined in the same order as in the HWC2 header

int32_t HWCSession::AcceptDisplayChanges(hwc2_device_t *device, hwc2_display_t display) {
  return HWCSession::CallDisplayFunction(device, display, &HWCDisplay::AcceptDisplayChanges);
}

int32_t HWCSession::CreateLayer(hwc2_device_t *device, hwc2_display_t display,
                                hwc2_layer_t *out_layer_id) {
  if (!out_layer_id) {
    return  HWC2_ERROR_BAD_PARAMETER;
  }

  return CallDisplayFunction(device, display, &HWCDisplay::CreateLayer, out_layer_id);
}

int32_t HWCSession::CreateVirtualDisplay(hwc2_device_t *device, uint32_t width, uint32_t height,
                                         int32_t *format, hwc2_display_t *out_display_id) {
  // TODO(user): Handle concurrency with HDMI
  if (!device) {
    return HWC2_ERROR_BAD_DISPLAY;
  }

  if (!out_display_id || !width || !height || !format) {
    return  HWC2_ERROR_BAD_PARAMETER;
  }

  HWCSession *hwc_session = static_cast<HWCSession *>(device);
  auto status = hwc_session->CreateVirtualDisplayObject(width, height, format);

  if (status == HWC2::Error::None) {
    *out_display_id = HWC_DISPLAY_VIRTUAL;
    DLOGI("Created virtual display id:% " PRIu64 " with res: %dx%d",
          *out_display_id, width, height);
  } else {
    DLOGE("Failed to create virtual display: %s", to_string(status).c_str());
  }
  return INT32(status);
}

int32_t HWCSession::DestroyLayer(hwc2_device_t *device, hwc2_display_t display,
                                 hwc2_layer_t layer) {
  return CallDisplayFunction(device, display, &HWCDisplay::DestroyLayer, layer);
}

int32_t HWCSession::DestroyVirtualDisplay(hwc2_device_t *device, hwc2_display_t display) {
  if (!device || display != HWC_DISPLAY_VIRTUAL) {
    return HWC2_ERROR_BAD_DISPLAY;
  }

  SCOPE_LOCK(locker_[display]);
  DLOGI("Destroying virtual display id:%" PRIu64, display);
  auto *hwc_session = static_cast<HWCSession *>(device);

  if (hwc_session->hwc_display_[display]) {
    HWCDisplayVirtual::Destroy(hwc_session->hwc_display_[display]);
    hwc_session->hwc_display_[display] = nullptr;
    return HWC2_ERROR_NONE;
  } else {
    return HWC2_ERROR_BAD_DISPLAY;
  }
}

void HWCSession::Dump(hwc2_device_t *device, uint32_t *out_size, char *out_buffer) {
  if (!device || !out_size) {
    return;
  }

  auto *hwc_session = static_cast<HWCSession *>(device);
  const size_t max_dump_size = 8192;

  if (out_buffer == nullptr) {
    *out_size = max_dump_size;
  } else {
    std::string s {};
    for (int id = HWC_DISPLAY_PRIMARY; id <= HWC_DISPLAY_VIRTUAL; id++) {
      SCOPE_LOCK(locker_[id]);
      if (hwc_session->hwc_display_[id]) {
        s += hwc_session->hwc_display_[id]->Dump();
      }
    }
    auto copied = s.copy(out_buffer, std::min(s.size(), max_dump_size), 0);
    *out_size = UINT32(copied);
  }
}

static int32_t GetActiveConfig(hwc2_device_t *device, hwc2_display_t display,
                               hwc2_config_t *out_config) {
  return HWCSession::CallDisplayFunction(device, display, &HWCDisplay::GetActiveConfig, out_config);
}

static int32_t GetChangedCompositionTypes(hwc2_device_t *device, hwc2_display_t display,
                                          uint32_t *out_num_elements, hwc2_layer_t *out_layers,
                                          int32_t *out_types) {
  // null_ptr check only for out_num_elements, as out_layers and out_types can be null.
  if (!out_num_elements) {
    return  HWC2_ERROR_BAD_PARAMETER;
  }
  return HWCSession::CallDisplayFunction(device, display, &HWCDisplay::GetChangedCompositionTypes,
                                         out_num_elements, out_layers, out_types);
}

static int32_t GetClientTargetSupport(hwc2_device_t *device, hwc2_display_t display, uint32_t width,
                                      uint32_t height, int32_t format, int32_t dataspace) {
  return HWCSession::CallDisplayFunction(device, display, &HWCDisplay::GetClientTargetSupport,
                                         width, height, format, dataspace);
}

static int32_t GetColorModes(hwc2_device_t *device, hwc2_display_t display, uint32_t *out_num_modes,
                             int32_t /*ColorMode*/ *int_out_modes) {
  auto out_modes = reinterpret_cast<ColorMode *>(int_out_modes);
  if (out_num_modes == nullptr) {
    return HWC2_ERROR_BAD_PARAMETER;
  }
  return HWCSession::CallDisplayFunction(device, display, &HWCDisplay::GetColorModes, out_num_modes,
                                         out_modes);
}

static int32_t GetRenderIntents(hwc2_device_t *device, hwc2_display_t display,
                                int32_t /*ColorMode*/ int_mode, uint32_t *out_num_intents,
                                int32_t /*RenderIntent*/ *int_out_intents) {
  auto mode = static_cast<ColorMode>(int_mode);
  auto out_intents = reinterpret_cast<RenderIntent *>(int_out_intents);
  if (out_num_intents == nullptr) {
    return HWC2_ERROR_BAD_PARAMETER;
  }

  if (mode < ColorMode::NATIVE || mode > ColorMode::BT2100_HLG) {
    DLOGE("Invalid ColorMode: %d", mode);
    return HWC2_ERROR_BAD_PARAMETER;
  }
  return HWCSession::CallDisplayFunction(device, display, &HWCDisplay::GetRenderIntents, mode,
                                         out_num_intents, out_intents);
}

static int32_t GetDataspaceSaturationMatrix(hwc2_device_t *device,
                                            int32_t /*Dataspace*/ int_dataspace,
                                            float *out_matrix) {
  auto dataspace = static_cast<Dataspace>(int_dataspace);
  if (device == nullptr || out_matrix == nullptr || dataspace != Dataspace::SRGB_LINEAR) {
    return HWC2_ERROR_BAD_PARAMETER;
  }
  // We only have the matrix for sRGB
  float saturation_matrix[kDataspaceSaturationMatrixCount] = { 1.0, 0.0, 0.0, 0.0, \
                                                               0.0, 1.0, 0.0, 0.0, \
                                                               0.0, 0.0, 1.0, 0.0, \
                                                               0.0, 0.0, 0.0, 1.0 };

  // TODO(user): This value should ideally be retrieved from a QDCM configuration file
  char value[kPropertyMax] = {};
  if (Debug::Get()->GetProperty(DATASPACE_SATURATION_MATRIX_PROP, value) != kErrorNone) {
    DLOGW("Undefined saturation matrix");
    return HWC2_ERROR_BAD_CONFIG;
  }
  std::string value_string(value);
  std::size_t start = 0, end = 0;
  int index = 0;
  while ((end = value_string.find(",", start)) != std::string::npos) {
    saturation_matrix[index] = std::stof(value_string.substr(start, end - start));
    start = end + 1;
    index++;
    // We expect a 3x3, SF needs 4x4, keep the last row/column identity
    if ((index + 1) % 4 == 0) {
      index++;
    }
  }
  saturation_matrix[index] = std::stof(value_string.substr(start, end - start));
  if (index < kDataspaceSaturationPropertyElements - 1) {
    // The property must have kDataspaceSaturationPropertyElements delimited by commas
    DLOGW("Invalid saturation matrix defined");
    return HWC2_ERROR_BAD_CONFIG;
  }
  for (int32_t i = 0; i < kDataspaceSaturationMatrixCount; i += 4) {
    DLOGD("%f %f %f %f", saturation_matrix[i], saturation_matrix[i + 1], saturation_matrix[i + 2],
          saturation_matrix[i + 3]);
  }
  for (uint32_t i = 0; i < kDataspaceSaturationMatrixCount; i++) {
    out_matrix[i] = saturation_matrix[i];
  }
  return HWC2_ERROR_NONE;
}

static int32_t GetPerFrameMetadataKeys(hwc2_device_t *device, hwc2_display_t display,
                                       uint32_t *out_num_keys, int32_t *int_out_keys) {
  auto out_keys = reinterpret_cast<PerFrameMetadataKey *>(int_out_keys);
  return HWCSession::CallDisplayFunction(device, display, &HWCDisplay::GetPerFrameMetadataKeys,
                                         out_num_keys, out_keys);
}

static int32_t SetLayerPerFrameMetadata(hwc2_device_t *device, hwc2_display_t display,
                                        hwc2_layer_t layer, uint32_t num_elements,
                                        const int32_t *int_keys, const float *metadata) {
  auto keys = reinterpret_cast<const PerFrameMetadataKey *>(int_keys);
  return HWCSession::CallLayerFunction(device, display, layer, &HWCLayer::SetLayerPerFrameMetadata,
                                       num_elements, keys, metadata);
}

static int32_t SetDisplayedContentSamplingEnabled(hwc2_device_t* device,
                                                  hwc2_display_t display,
                                                  int32_t enabled, uint8_t component_mask,
                                                  uint64_t max_frames) {
    static constexpr int32_t validComponentMask =
        HWC2_FORMAT_COMPONENT_0 | HWC2_FORMAT_COMPONENT_1 |
        HWC2_FORMAT_COMPONENT_2 | HWC2_FORMAT_COMPONENT_3;
    if (component_mask & ~validComponentMask) return HWC2_ERROR_BAD_PARAMETER;
    return HWCSession::CallDisplayFunction(device, display,
                                           &HWCDisplay::SetDisplayedContentSamplingEnabled,
                                           enabled, component_mask, max_frames);
}

static int32_t GetDisplayedContentSamplingAttributes(hwc2_device_t* device,
                                                     hwc2_display_t display,
                                                     int32_t* format,
                                                     int32_t* dataspace,
                                                     uint8_t* supported_components) {
    return HWCSession::CallDisplayFunction(device, display,
                                           &HWCDisplay::GetDisplayedContentSamplingAttributes,
                                           format, dataspace, supported_components);
}

static int32_t GetDisplayedContentSample(
    hwc2_device_t* device, hwc2_display_t display, uint64_t max_frames, uint64_t timestamp,
    uint64_t* numFrames,
    int32_t samples_size[NUM_HISTOGRAM_COLOR_COMPONENTS],
    uint64_t* samples[NUM_HISTOGRAM_COLOR_COMPONENTS]) {

    return HWCSession::CallDisplayFunction(device, display, &HWCDisplay::GetDisplayedContentSample,
                                    max_frames, timestamp, numFrames, samples_size, samples);
}

static int32_t GetDisplayAttribute(hwc2_device_t *device, hwc2_display_t display,
                                   hwc2_config_t config, int32_t int_attribute,
                                   int32_t *out_value) {
  if (out_value == nullptr || int_attribute < HWC2_ATTRIBUTE_INVALID ||
      int_attribute > HWC2_ATTRIBUTE_DPI_Y) {
    return HWC2_ERROR_BAD_PARAMETER;
  }
  auto attribute = static_cast<HWC2::Attribute>(int_attribute);
  return HWCSession::CallDisplayFunction(device, display, &HWCDisplay::GetDisplayAttribute, config,
                                         attribute, out_value);
}

static int32_t GetDisplayConfigs(hwc2_device_t *device, hwc2_display_t display,
                                 uint32_t *out_num_configs, hwc2_config_t *out_configs) {
  return HWCSession::CallDisplayFunction(device, display, &HWCDisplay::GetDisplayConfigs,
                                         out_num_configs, out_configs);
}

static int32_t GetDisplayName(hwc2_device_t *device, hwc2_display_t display, uint32_t *out_size,
                              char *out_name) {
  return HWCSession::CallDisplayFunction(device, display, &HWCDisplay::GetDisplayName, out_size,
                                         out_name);
}

static int32_t GetDisplayRequests(hwc2_device_t *device, hwc2_display_t display,
                                  int32_t *out_display_requests, uint32_t *out_num_elements,
                                  hwc2_layer_t *out_layers, int32_t *out_layer_requests) {
  return HWCSession::CallDisplayFunction(device, display, &HWCDisplay::GetDisplayRequests,
                                         out_display_requests, out_num_elements, out_layers,
                                         out_layer_requests);
}

static int32_t GetDisplayType(hwc2_device_t *device, hwc2_display_t display, int32_t *out_type) {
  return HWCSession::CallDisplayFunction(device, display, &HWCDisplay::GetDisplayType, out_type);
}

int32_t HWCSession::GetDozeSupport(hwc2_device_t *device, hwc2_display_t display,
                                  int32_t *out_support) {
  if (!device || !out_support) {
    return HWC2_ERROR_BAD_PARAMETER;
  }

  HWCSession *hwc_session = static_cast<HWCSession *>(device);
  if (display >= HWC_NUM_DISPLAY_TYPES || (hwc_session->hwc_display_[display] == nullptr) ) {
    return HWC2_ERROR_BAD_DISPLAY;
  }

  if (display == HWC_DISPLAY_PRIMARY) {
    *out_support = 1;
  } else {
    *out_support = 0;
  }

  return HWC2_ERROR_NONE;
}

static int32_t GetHdrCapabilities(hwc2_device_t* device, hwc2_display_t display,
                                  uint32_t* out_num_types, int32_t* out_types,
                                  float* out_max_luminance, float* out_max_average_luminance,
                                  float* out_min_luminance) {
  return HWCSession::CallDisplayFunction(device, display, &HWCDisplay::GetHdrCapabilities,
                                         out_num_types, out_types, out_max_luminance,
                                         out_max_average_luminance, out_min_luminance);
}

static uint32_t GetMaxVirtualDisplayCount(hwc2_device_t *device) {
  if (device == nullptr) {
    return HWC2_ERROR_BAD_PARAMETER;
  }

  return 1;
}

static int32_t GetReleaseFences(hwc2_device_t *device, hwc2_display_t display,
                                uint32_t *out_num_elements, hwc2_layer_t *out_layers,
                                int32_t *out_fences) {
  return HWCSession::CallDisplayFunction(device, display, &HWCDisplay::GetReleaseFences,
                                         out_num_elements, out_layers, out_fences);
}

int32_t HWCSession::PresentDisplay(hwc2_device_t *device, hwc2_display_t display,
                                   int32_t *out_retire_fence) {
  HWCSession *hwc_session = static_cast<HWCSession *>(device);
  bool notify_hotplug = false;
  auto status = HWC2::Error::BadDisplay;
  DTRACE_SCOPED();

  if (display >= HWC_NUM_DISPLAY_TYPES || (hwc_session->hwc_display_[display] == nullptr)) {
    return HWC2_ERROR_BAD_DISPLAY;
  }

  {
    SEQUENCE_EXIT_SCOPE_LOCK(locker_[display]);
    if (!device) {
      return HWC2_ERROR_BAD_DISPLAY;
    }

    if (out_retire_fence == nullptr) {
      return HWC2_ERROR_BAD_PARAMETER;
    }

    // TODO(user): Handle virtual display/HDMI concurrency
    status = hwc_session->PresentDisplayInternal(display, out_retire_fence);
  }

  if (status != HWC2::Error::None && status != HWC2::Error::NotValidated) {
    SEQUENCE_CANCEL_SCOPE_LOCK(locker_[display]);
  }

  // Handle Pending external display connection
  if (hwc_session->external_pending_connect_ && (display == HWC_DISPLAY_PRIMARY)) {
    Locker::ScopeLock lock_e(locker_[HWC_DISPLAY_EXTERNAL]);
    Locker::ScopeLock lock_v(locker_[HWC_DISPLAY_VIRTUAL]);

    if (!hwc_session->hwc_display_[HWC_DISPLAY_VIRTUAL]) {
      DLOGD("Process pending external display connection");
      hwc_session->ConnectDisplay(HWC_DISPLAY_EXTERNAL);
      hwc_session->external_pending_connect_ = false;
      notify_hotplug = true;
    }
  }

  if (notify_hotplug) {
    hwc_session->HotPlug(HWC_DISPLAY_EXTERNAL, HWC2::Connection::Connected);
  }

  return INT32(status);
}

int32_t HWCSession::RegisterCallback(hwc2_device_t *device, int32_t descriptor,
                                     hwc2_callback_data_t callback_data,
                                     hwc2_function_pointer_t pointer) {
  if (!device) {
    return HWC2_ERROR_BAD_PARAMETER;
  }
  HWCSession *hwc_session = static_cast<HWCSession *>(device);
  SCOPE_LOCK(hwc_session->callbacks_lock_);
  auto desc = static_cast<HWC2::Callback>(descriptor);
  auto error = hwc_session->callbacks_.Register(desc, callback_data, pointer);
  DLOGD("%s callback: %s", pointer ? "Registering" : "Deregistering", to_string(desc).c_str());
  if (descriptor == HWC2_CALLBACK_HOTPLUG) {
    if (hwc_session->hwc_display_[HWC_DISPLAY_PRIMARY]) {
      hwc_session->callbacks_.Hotplug(HWC_DISPLAY_PRIMARY, HWC2::Connection::Connected);
    }
  }
  hwc_session->need_invalidate_ = false;
  hwc_session->callbacks_lock_.Broadcast();
  return INT32(error);
}

static int32_t SetActiveConfig(hwc2_device_t *device, hwc2_display_t display,
                               hwc2_config_t config) {
  return HWCSession::CallDisplayFunction(device, display, &HWCDisplay::SetActiveConfig, config);
}

static int32_t SetClientTarget(hwc2_device_t *device, hwc2_display_t display,
                               buffer_handle_t target, int32_t acquire_fence,
                               int32_t dataspace, hwc_region_t damage) {
  return HWCSession::CallDisplayFunction(device, display, &HWCDisplay::SetClientTarget, target,
                                         acquire_fence, dataspace, damage);
}

int32_t HWCSession::SetColorMode(hwc2_device_t *device, hwc2_display_t display,
                                 int32_t /*ColorMode*/ int_mode) {
  auto mode = static_cast<ColorMode>(int_mode);
  if (mode < ColorMode::NATIVE || mode > ColorMode::BT2100_HLG) {
    return HWC2_ERROR_BAD_PARAMETER;
  }
  return HWCSession::CallDisplayFunction(device, display, &HWCDisplay::SetColorMode, mode);
}

int32_t HWCSession::SetColorModeWithRenderIntent(hwc2_device_t *device, hwc2_display_t display,
                                                 int32_t /*ColorMode*/ int_mode,
                                                 int32_t /*RenderIntent*/ int_render_intent) {
  auto mode = static_cast<ColorMode>(int_mode);
  if (mode < ColorMode::NATIVE || mode > ColorMode::BT2100_HLG) {
    return HWC2_ERROR_BAD_PARAMETER;
  }
  auto render_intent = static_cast<RenderIntent>(int_render_intent);
  if ((render_intent < RenderIntent::COLORIMETRIC) ||
      (render_intent > RenderIntent::TONE_MAP_ENHANCE)) {
    DLOGE("Invalid RenderIntent: %d", render_intent);
    return HWC2_ERROR_BAD_PARAMETER;
  }
  return HWCSession::CallDisplayFunction(device, display, &HWCDisplay::SetColorModeWithRenderIntent,
                                         mode, render_intent);
}

int32_t HWCSession::SetColorTransform(hwc2_device_t *device, hwc2_display_t display,
                                      const float *matrix,
                                      int32_t /*android_color_transform_t*/ hint) {
  if (!matrix || hint < HAL_COLOR_TRANSFORM_IDENTITY ||
       hint > HAL_COLOR_TRANSFORM_CORRECT_TRITANOPIA) {
    return HWC2_ERROR_BAD_PARAMETER;
  }
  android_color_transform_t transform_hint = static_cast<android_color_transform_t>(hint);
  return HWCSession::CallDisplayFunction(device, display, &HWCDisplay::SetColorTransform, matrix,
                                         transform_hint);
}

static int32_t SetCursorPosition(hwc2_device_t *device, hwc2_display_t display, hwc2_layer_t layer,
                                 int32_t x, int32_t y) {
  auto status = INT32(HWC2::Error::None);
  status = HWCSession::CallDisplayFunction(device, display, &HWCDisplay::SetCursorPosition,
                                           layer, x, y);
  if (status == INT32(HWC2::Error::None)) {
    // Update cursor position
    HWCSession::CallLayerFunction(device, display, layer, &HWCLayer::SetCursorPosition, x, y);
  }
  return status;
}

static int32_t SetLayerBlendMode(hwc2_device_t *device, hwc2_display_t display, hwc2_layer_t layer,
                                 int32_t int_mode) {
  if (int_mode < HWC2_BLEND_MODE_INVALID || int_mode > HWC2_BLEND_MODE_COVERAGE) {
    return HWC2_ERROR_BAD_PARAMETER;
  }
  auto mode = static_cast<HWC2::BlendMode>(int_mode);
  return HWCSession::CallLayerFunction(device, display, layer, &HWCLayer::SetLayerBlendMode, mode);
}

static int32_t SetLayerBuffer(hwc2_device_t *device, hwc2_display_t display, hwc2_layer_t layer,
                              buffer_handle_t buffer, int32_t acquire_fence) {
  return HWCSession::CallLayerFunction(device, display, layer, &HWCLayer::SetLayerBuffer, buffer,
                                       acquire_fence);
}

static int32_t SetLayerColor(hwc2_device_t *device, hwc2_display_t display, hwc2_layer_t layer,
                             hwc_color_t color) {
  return HWCSession::CallLayerFunction(device, display, layer, &HWCLayer::SetLayerColor, color);
}

static int32_t SetLayerCompositionType(hwc2_device_t *device, hwc2_display_t display,
                                       hwc2_layer_t layer, int32_t int_type) {
  auto type = static_cast<HWC2::Composition>(int_type);
  return HWCSession::CallLayerFunction(device, display, layer, &HWCLayer::SetLayerCompositionType,
                                       type);
}

static int32_t SetLayerDataspace(hwc2_device_t *device, hwc2_display_t display, hwc2_layer_t layer,
                                 int32_t dataspace) {
  return HWCSession::CallLayerFunction(device, display, layer, &HWCLayer::SetLayerDataspace,
                                       dataspace);
}

static int32_t SetLayerDisplayFrame(hwc2_device_t *device, hwc2_display_t display,
                                    hwc2_layer_t layer, hwc_rect_t frame) {
  return HWCSession::CallLayerFunction(device, display, layer, &HWCLayer::SetLayerDisplayFrame,
                                       frame);
}

static int32_t SetLayerPlaneAlpha(hwc2_device_t *device, hwc2_display_t display, hwc2_layer_t layer,
                                  float alpha) {
  return HWCSession::CallLayerFunction(device, display, layer, &HWCLayer::SetLayerPlaneAlpha,
                                       alpha);
}

static int32_t SetLayerSourceCrop(hwc2_device_t *device, hwc2_display_t display, hwc2_layer_t layer,
                                  hwc_frect_t crop) {
  return HWCSession::CallLayerFunction(device, display, layer, &HWCLayer::SetLayerSourceCrop, crop);
}

static int32_t SetLayerSurfaceDamage(hwc2_device_t *device, hwc2_display_t display,
                                     hwc2_layer_t layer, hwc_region_t damage) {
  return HWCSession::CallLayerFunction(device, display, layer, &HWCLayer::SetLayerSurfaceDamage,
                                       damage);
}

static int32_t SetLayerTransform(hwc2_device_t *device, hwc2_display_t display, hwc2_layer_t layer,
                                 int32_t int_transform) {
  auto transform = static_cast<HWC2::Transform>(int_transform);
  return HWCSession::CallLayerFunction(device, display, layer, &HWCLayer::SetLayerTransform,
                                       transform);
}

static int32_t SetLayerVisibleRegion(hwc2_device_t *device, hwc2_display_t display,
                                     hwc2_layer_t layer, hwc_region_t visible) {
  return HWCSession::CallLayerFunction(device, display, layer, &HWCLayer::SetLayerVisibleRegion,
                                       visible);
}

static int32_t SetLayerZOrder(hwc2_device_t *device, hwc2_display_t display, hwc2_layer_t layer,
                              uint32_t z) {
  return HWCSession::CallDisplayFunction(device, display, &HWCDisplay::SetLayerZOrder, layer, z);
}

static int32_t SetLayerColorTransform(hwc2_device_t *device, hwc2_display_t display,
                                      hwc2_layer_t layer, const float *matrix) {
  return HWCSession::CallLayerFunction(device, display, layer, &HWCLayer::SetLayerColorTransform,
                                       matrix);
}

int32_t HWCSession::SetOutputBuffer(hwc2_device_t *device, hwc2_display_t display,
                                    buffer_handle_t buffer, int32_t releaseFence) {
  if (!device) {
    return HWC2_ERROR_BAD_PARAMETER;
  }

  if (display != HWC_DISPLAY_VIRTUAL) {
    return HWC2_ERROR_UNSUPPORTED;
  }

  SCOPE_LOCK(locker_[display]);
  auto *hwc_session = static_cast<HWCSession *>(device);
  if (hwc_session->hwc_display_[display]) {
    auto vds = reinterpret_cast<HWCDisplayVirtual *>(hwc_session->hwc_display_[display]);
    auto status = vds->SetOutputBuffer(buffer, releaseFence);
    return INT32(status);
  } else {
    return HWC2_ERROR_BAD_DISPLAY;
  }
}

int32_t HWCSession::SetPowerMode(hwc2_device_t *device, hwc2_display_t display, int32_t int_mode) {
  if (display >= HWC_NUM_DISPLAY_TYPES) {
    return HWC2_ERROR_BAD_DISPLAY;
  }

  //  validate device and also avoid undefined behavior in cast to HWC2::PowerMode
  if (!device || int_mode < HWC2_POWER_MODE_OFF || int_mode > HWC2_POWER_MODE_DOZE_SUSPEND) {
    return HWC2_ERROR_BAD_PARAMETER;
  }

  auto mode = static_cast<HWC2::PowerMode>(int_mode);

  //  all displays support on/off. Check for doze modes
  int support = 0;

  auto status = GetDozeSupport(device, display, &support);
  if (status != HWC2_ERROR_NONE) {
    return INT32(status);
  }

  if (!support && (mode == HWC2::PowerMode::Doze || mode == HWC2::PowerMode::DozeSuspend)) {
    return HWC2_ERROR_UNSUPPORTED;
  }

  auto error = CallDisplayFunction(device, display, &HWCDisplay::SetPowerMode, mode);
  if (error != HWC2_ERROR_NONE) {
    return error;
  }
  // Reset idle pc ref count on suspend, as we enable idle pc during suspend.
  if (mode == HWC2::PowerMode::Off) {
    HWCSession *hwc_session = static_cast<HWCSession *>(device);
    hwc_session->idle_pc_ref_cnt_ = 0;
  }

  return HWC2_ERROR_NONE;
}

static int32_t SetVsyncEnabled(hwc2_device_t *device, hwc2_display_t display, int32_t int_enabled) {
  //  avoid undefined behavior in cast to HWC2::Vsync
  if (int_enabled < HWC2_VSYNC_INVALID || int_enabled > HWC2_VSYNC_DISABLE) {
    return HWC2_ERROR_BAD_PARAMETER;
  }

  auto enabled = static_cast<HWC2::Vsync>(int_enabled);
  return HWCSession::CallDisplayFunction(device, display, &HWCDisplay::SetVsyncEnabled, enabled);
}

int32_t HWCSession::ValidateDisplay(hwc2_device_t *device, hwc2_display_t display,
                                    uint32_t *out_num_types, uint32_t *out_num_requests) {
  //  out_num_types and out_num_requests will be non-NULL
  if (!device) {
    return HWC2_ERROR_BAD_PARAMETER;
  }

  if (display >= HWC_NUM_DISPLAY_TYPES) {
    return HWC2_ERROR_BAD_DISPLAY;
  }

  DTRACE_SCOPED();
  HWCSession *hwc_session = static_cast<HWCSession *>(device);
  // TODO(user): Handle secure session, handle QDCM solid fill
  // Handle external_pending_connect_ in CreateVirtualDisplay
  auto status = HWC2::Error::BadDisplay;
  {
    SEQUENCE_ENTRY_SCOPE_LOCK(locker_[display]);
    if (hwc_session->hwc_display_[display]) {
      status = hwc_session->ValidateDisplayInternal(display, out_num_types, out_num_requests);
    }
  }

  // Sequence locking currently begins on Validate, so cancel the sequence lock on failures
  if (status != HWC2::Error::None && status != HWC2::Error::HasChanges) {
    SEQUENCE_CANCEL_SCOPE_LOCK(locker_[display]);
  }

  return INT32(status);
}

int32_t HWCSession::GetDisplayCapabilities(hwc2_device_t* device, hwc2_display_t display,
        uint32_t* outNumCapabilities, uint32_t* outCapabilities) {
  if (outNumCapabilities == nullptr) {
    return INT32(HWC2::Error::None);
  }

  bool brightness_support = false;
  auto status = GetDisplayBrightnessSupport(device, display, &brightness_support);
  if (status != HWC2_ERROR_NONE) {
    DLOGE("Failed to get display brightness support Error = %d", status);
    return INT32(status);
  }
  int doze_support = 0;
  status = GetDozeSupport(device, display, &doze_support);
  if (status != HWC2_ERROR_NONE) {
    DLOGE("Failed to get doze support Error = %d", status);
    return INT32(status);
  }

  uint32_t count = 1  + static_cast<uint32_t>(doze_support) + (brightness_support ? 1 : 0);
  int index = 0;
  if (outCapabilities != nullptr && (*outNumCapabilities >= count)) {
    outCapabilities[index++] = HWC2_DISPLAY_CAPABILITY_SKIP_CLIENT_COLOR_TRANSFORM;
    if (doze_support == 1) {
      outCapabilities[index++] = HWC2_DISPLAY_CAPABILITY_DOZE;
    }
    if (brightness_support) {
      outCapabilities[index++] = HWC2_DISPLAY_CAPABILITY_BRIGHTNESS;
    }
  }

  *outNumCapabilities = count;
  return INT32(HWC2::Error::None);
}

int32_t HWCSession::SetDisplayBrightness(hwc2_device_t *device, hwc2_display_t display,
                                         float brightness) {
  bool brightness_support = false;
  auto status = GetDisplayBrightnessSupport(device, display, &brightness_support);
  if (status != HWC2_ERROR_NONE) {
    return INT32(status);
  }
  if (!brightness_support) {
    return HWC2_ERROR_UNSUPPORTED;
  }
  int backlight = -1;
  if (brightness == -1.0f) {
    backlight = 0;
  } else if (brightness < 0.0f || brightness > 1.0f) {
    return INT32(HWC2::Error::BadParameter);
  } else {
    // 0 is reserved for "backlight off", so we scale the brightness from 1 to MAX_BRIGHTNESS.
    backlight = (int) ((MAX_BRIGHTNESS - 1.0f) * brightness + 1.0f);
  }
  char buff[20];
  int n = snprintf(buff, sizeof(buff), "%d\n", backlight);
  if (n < 0 || n >= sizeof(buff)) {
    return INT32(HWC2::Error::BadParameter);
  }

  HWCSession *hwc_session = static_cast<HWCSession *>(device);
  long error = lseek(hwc_session->brightness_fd_, 0, SEEK_SET);
  if (error == -1) {
    DLOGW("Failed to rewind brightness file: [%d] %s", errno, strerror(errno));
    return INT32(HWC2::Error::NoResources);
  }
  error = write(hwc_session->brightness_fd_, buff, (size_t) n);
  if (error == -1) {
    DLOGW("Failed to write to brightness file: [%d] %s", errno, strerror(errno));
    return INT32(HWC2::Error::NoResources);
  }
  error = fsync(hwc_session->brightness_fd_);
  if (error == -1) {
    DLOGW("Failed to flush brightness file: [%d] %s", errno, strerror(errno));
    return INT32(HWC2::Error::NoResources);
  }

  return INT32(HWC2::Error::None);
}

hwc2_function_pointer_t HWCSession::GetFunction(struct hwc2_device *device,
                                                int32_t int_descriptor) {
  auto descriptor = static_cast<HWC2::FunctionDescriptor>(int_descriptor);

  switch (descriptor) {
    case HWC2::FunctionDescriptor::AcceptDisplayChanges:
      return AsFP<HWC2_PFN_ACCEPT_DISPLAY_CHANGES>(HWCSession::AcceptDisplayChanges);
    case HWC2::FunctionDescriptor::CreateLayer:
      return AsFP<HWC2_PFN_CREATE_LAYER>(CreateLayer);
    case HWC2::FunctionDescriptor::CreateVirtualDisplay:
      return AsFP<HWC2_PFN_CREATE_VIRTUAL_DISPLAY>(HWCSession::CreateVirtualDisplay);
    case HWC2::FunctionDescriptor::DestroyLayer:
      return AsFP<HWC2_PFN_DESTROY_LAYER>(DestroyLayer);
    case HWC2::FunctionDescriptor::DestroyVirtualDisplay:
      return AsFP<HWC2_PFN_DESTROY_VIRTUAL_DISPLAY>(HWCSession::DestroyVirtualDisplay);
    case HWC2::FunctionDescriptor::Dump:
      return AsFP<HWC2_PFN_DUMP>(HWCSession::Dump);
    case HWC2::FunctionDescriptor::GetActiveConfig:
      return AsFP<HWC2_PFN_GET_ACTIVE_CONFIG>(GetActiveConfig);
    case HWC2::FunctionDescriptor::GetChangedCompositionTypes:
      return AsFP<HWC2_PFN_GET_CHANGED_COMPOSITION_TYPES>(GetChangedCompositionTypes);
    case HWC2::FunctionDescriptor::GetClientTargetSupport:
      return AsFP<HWC2_PFN_GET_CLIENT_TARGET_SUPPORT>(GetClientTargetSupport);
    case HWC2::FunctionDescriptor::GetColorModes:
      return AsFP<HWC2_PFN_GET_COLOR_MODES>(GetColorModes);
    case HWC2::FunctionDescriptor::GetDisplayAttribute:
      return AsFP<HWC2_PFN_GET_DISPLAY_ATTRIBUTE>(GetDisplayAttribute);
    case HWC2::FunctionDescriptor::GetDisplayConfigs:
      return AsFP<HWC2_PFN_GET_DISPLAY_CONFIGS>(GetDisplayConfigs);
    case HWC2::FunctionDescriptor::GetDisplayName:
      return AsFP<HWC2_PFN_GET_DISPLAY_NAME>(GetDisplayName);
    case HWC2::FunctionDescriptor::GetDisplayRequests:
      return AsFP<HWC2_PFN_GET_DISPLAY_REQUESTS>(GetDisplayRequests);
    case HWC2::FunctionDescriptor::GetDisplayType:
      return AsFP<HWC2_PFN_GET_DISPLAY_TYPE>(GetDisplayType);
    case HWC2::FunctionDescriptor::GetHdrCapabilities:
      return AsFP<HWC2_PFN_GET_HDR_CAPABILITIES>(GetHdrCapabilities);
    case HWC2::FunctionDescriptor::GetDozeSupport:
      return AsFP<HWC2_PFN_GET_DOZE_SUPPORT>(GetDozeSupport);
    case HWC2::FunctionDescriptor::GetMaxVirtualDisplayCount:
      return AsFP<HWC2_PFN_GET_MAX_VIRTUAL_DISPLAY_COUNT>(GetMaxVirtualDisplayCount);
    case HWC2::FunctionDescriptor::GetReleaseFences:
      return AsFP<HWC2_PFN_GET_RELEASE_FENCES>(GetReleaseFences);
    case HWC2::FunctionDescriptor::PresentDisplay:
      return AsFP<HWC2_PFN_PRESENT_DISPLAY>(PresentDisplay);
    case HWC2::FunctionDescriptor::RegisterCallback:
      return AsFP<HWC2_PFN_REGISTER_CALLBACK>(RegisterCallback);
    case HWC2::FunctionDescriptor::SetActiveConfig:
      return AsFP<HWC2_PFN_SET_ACTIVE_CONFIG>(SetActiveConfig);
    case HWC2::FunctionDescriptor::SetClientTarget:
      return AsFP<HWC2_PFN_SET_CLIENT_TARGET>(SetClientTarget);
    case HWC2::FunctionDescriptor::SetColorMode:
      return AsFP<HWC2_PFN_SET_COLOR_MODE>(SetColorMode);
    case HWC2::FunctionDescriptor::SetColorTransform:
      return AsFP<HWC2_PFN_SET_COLOR_TRANSFORM>(SetColorTransform);
    case HWC2::FunctionDescriptor::SetCursorPosition:
      return AsFP<HWC2_PFN_SET_CURSOR_POSITION>(SetCursorPosition);
    case HWC2::FunctionDescriptor::SetLayerBlendMode:
      return AsFP<HWC2_PFN_SET_LAYER_BLEND_MODE>(SetLayerBlendMode);
    case HWC2::FunctionDescriptor::SetLayerBuffer:
      return AsFP<HWC2_PFN_SET_LAYER_BUFFER>(SetLayerBuffer);
    case HWC2::FunctionDescriptor::SetLayerColor:
      return AsFP<HWC2_PFN_SET_LAYER_COLOR>(SetLayerColor);
    case HWC2::FunctionDescriptor::SetLayerCompositionType:
      return AsFP<HWC2_PFN_SET_LAYER_COMPOSITION_TYPE>(SetLayerCompositionType);
    case HWC2::FunctionDescriptor::SetLayerDataspace:
      return AsFP<HWC2_PFN_SET_LAYER_DATASPACE>(SetLayerDataspace);
    case HWC2::FunctionDescriptor::SetLayerDisplayFrame:
      return AsFP<HWC2_PFN_SET_LAYER_DISPLAY_FRAME>(SetLayerDisplayFrame);
    case HWC2::FunctionDescriptor::SetLayerPlaneAlpha:
      return AsFP<HWC2_PFN_SET_LAYER_PLANE_ALPHA>(SetLayerPlaneAlpha);
    // Sideband stream is not supported
    // case HWC2::FunctionDescriptor::SetLayerSidebandStream:
    case HWC2::FunctionDescriptor::SetLayerSourceCrop:
      return AsFP<HWC2_PFN_SET_LAYER_SOURCE_CROP>(SetLayerSourceCrop);
    case HWC2::FunctionDescriptor::SetLayerSurfaceDamage:
      return AsFP<HWC2_PFN_SET_LAYER_SURFACE_DAMAGE>(SetLayerSurfaceDamage);
    case HWC2::FunctionDescriptor::SetLayerTransform:
      return AsFP<HWC2_PFN_SET_LAYER_TRANSFORM>(SetLayerTransform);
    case HWC2::FunctionDescriptor::SetLayerVisibleRegion:
      return AsFP<HWC2_PFN_SET_LAYER_VISIBLE_REGION>(SetLayerVisibleRegion);
    case HWC2::FunctionDescriptor::SetLayerZOrder:
      return AsFP<HWC2_PFN_SET_LAYER_Z_ORDER>(SetLayerZOrder);
    case HWC2::FunctionDescriptor::SetLayerColorTransform:
      return AsFP<HWC2_PFN_SET_LAYER_COLOR_TRANSFORM>(SetLayerColorTransform);
    case HWC2::FunctionDescriptor::SetOutputBuffer:
      return AsFP<HWC2_PFN_SET_OUTPUT_BUFFER>(SetOutputBuffer);
    case HWC2::FunctionDescriptor::SetPowerMode:
      return AsFP<HWC2_PFN_SET_POWER_MODE>(SetPowerMode);
    case HWC2::FunctionDescriptor::SetVsyncEnabled:
      return AsFP<HWC2_PFN_SET_VSYNC_ENABLED>(SetVsyncEnabled);
    case HWC2::FunctionDescriptor::ValidateDisplay:
      return AsFP<HWC2_PFN_VALIDATE_DISPLAY>(HWCSession::ValidateDisplay);
    case HWC2::FunctionDescriptor::SetReadbackBuffer:
      return AsFP<HWC2_PFN_SET_READBACK_BUFFER>(HWCSession::SetReadbackBuffer);
    case HWC2::FunctionDescriptor::GetReadbackBufferAttributes:
      return AsFP<HWC2_PFN_GET_READBACK_BUFFER_ATTRIBUTES>(HWCSession::GetReadbackBufferAttributes);
    case HWC2::FunctionDescriptor::GetReadbackBufferFence:
      return AsFP<HWC2_PFN_GET_READBACK_BUFFER_FENCE>(HWCSession::GetReadbackBufferFence);
    case HWC2::FunctionDescriptor::GetRenderIntents:
      return AsFP<HWC2_PFN_GET_RENDER_INTENTS>(GetRenderIntents);
    case HWC2::FunctionDescriptor::SetColorModeWithRenderIntent:
      return AsFP<HWC2_PFN_SET_COLOR_MODE_WITH_RENDER_INTENT>(
          HWCSession::SetColorModeWithRenderIntent);
    case HWC2::FunctionDescriptor::GetDataspaceSaturationMatrix:
      return AsFP<HWC2_PFN_GET_DATASPACE_SATURATION_MATRIX>(GetDataspaceSaturationMatrix);
    case HWC2::FunctionDescriptor::GetPerFrameMetadataKeys:
      return AsFP<HWC2_PFN_GET_PER_FRAME_METADATA_KEYS>(GetPerFrameMetadataKeys);
    case HWC2::FunctionDescriptor::SetLayerPerFrameMetadata:
      return AsFP<HWC2_PFN_SET_LAYER_PER_FRAME_METADATA>(SetLayerPerFrameMetadata);
    case HWC2::FunctionDescriptor::SetDisplayedContentSamplingEnabled:
      return AsFP<HWC2_PFN_SET_DISPLAYED_CONTENT_SAMPLING_ENABLED>(SetDisplayedContentSamplingEnabled);
    case HWC2::FunctionDescriptor::GetDisplayedContentSamplingAttributes:
      return AsFP<HWC2_PFN_GET_DISPLAYED_CONTENT_SAMPLING_ATTRIBUTES>(GetDisplayedContentSamplingAttributes);
    case HWC2::FunctionDescriptor::GetDisplayedContentSample:
      return AsFP<HWC2_PFN_GET_DISPLAYED_CONTENT_SAMPLE>(GetDisplayedContentSample);
    case HWC2::FunctionDescriptor::GetDisplayCapabilities:
      return AsFP<HWC2_PFN_GET_DISPLAY_CAPABILITIES>(GetDisplayCapabilities);
    case HWC2::FunctionDescriptor::SetDisplayBrightness:
      return AsFP<HWC2_PFN_SET_DISPLAY_BRIGHTNESS>(SetDisplayBrightness);
    default:
      DLOGD("Unknown/Unimplemented function descriptor: %d (%s)", int_descriptor,
            to_string(descriptor).c_str());
      return nullptr;
  }
  return nullptr;
}

HWC2::Error HWCSession::CreateVirtualDisplayObject(uint32_t width, uint32_t height,
                                                   int32_t *format) {
  {
    SCOPE_LOCK(locker_[HWC_DISPLAY_VIRTUAL]);
    if (hwc_display_[HWC_DISPLAY_VIRTUAL]) {
      return HWC2::Error::NoResources;
    }

    if (hwc_display_[HWC_DISPLAY_PRIMARY]) {
      auto error = hwc_display_[HWC_DISPLAY_PRIMARY]->TeardownConcurrentWriteback();
      if (error) {
        return HWC2::Error::NoResources;
      }
    }

    auto status = HWCDisplayVirtual::Create(core_intf_, &buffer_allocator_, &callbacks_, width,
                                            height, format, &hwc_display_[HWC_DISPLAY_VIRTUAL]);
    // TODO(user): validate width and height support
    if (status) {
      return HWC2::Error::NoResources;
    }
  }

  SEQUENCE_WAIT_SCOPE_LOCK(locker_[HWC_DISPLAY_PRIMARY]);
  hwc_display_[HWC_DISPLAY_PRIMARY]->ResetValidation();

  return HWC2::Error::None;
}

int32_t HWCSession::ConnectDisplay(int disp) {
  DLOGI("Display = %d", disp);

  int status = 0;
  uint32_t primary_width = 0;
  uint32_t primary_height = 0;

  hwc_display_[HWC_DISPLAY_PRIMARY]->GetFrameBufferResolution(&primary_width, &primary_height);

  if (disp == HWC_DISPLAY_EXTERNAL) {
    status = CreateExternalDisplay(disp, primary_width, primary_height, false);
  } else {
    DLOGE("Invalid display type");
    return -1;
  }

  if (!status) {
    hwc_display_[disp]->SetSecureDisplay(secure_display_active_);
  }

  return status;
}

int HWCSession::DisconnectDisplay(int disp) {
  DLOGI("Display = %d", disp);

  if (disp == HWC_DISPLAY_EXTERNAL) {
    DisplayError error = hwc_display_[disp]->Flush();
    if (error != kErrorNone) {
        DLOGW("Flush failed. Error = %d", error);
    }
    HWCDisplayExternal::Destroy(hwc_display_[disp]);
  } else if (disp == HWC_DISPLAY_VIRTUAL) {
    HWCDisplayVirtual::Destroy(hwc_display_[disp]);
  } else {
    DLOGE("Invalid display type");
    return -1;
  }

  hwc_display_[disp] = NULL;

  return 0;
}

// Qclient methods
android::status_t HWCSession::notifyCallback(uint32_t command, const android::Parcel *input_parcel,
                                             android::Parcel *output_parcel) {
  android::status_t status = -EINVAL;

  switch (command) {
    case qService::IQService::DYNAMIC_DEBUG:
      if (!input_parcel) {
        DLOGE("QService command = %d: input_parcel needed.", command);
        break;
      }
      status = 0;
      DynamicDebug(input_parcel);
      break;

    case qService::IQService::SCREEN_REFRESH:
      status = refreshScreen();
      break;

    case qService::IQService::SET_IDLE_TIMEOUT:
      if (!input_parcel) {
        DLOGE("QService command = %d: input_parcel needed.", command);
        break;
      }
      status = setIdleTimeout(UINT32(input_parcel->readInt32()));
      break;

    case qService::IQService::SET_FRAME_DUMP_CONFIG:
      if (!input_parcel) {
        DLOGE("QService command = %d: input_parcel needed.", command);
        break;
      }
      status = SetFrameDumpConfig(input_parcel);
      break;

    case qService::IQService::SET_MAX_PIPES_PER_MIXER:
      if (!input_parcel) {
        DLOGE("QService command = %d: input_parcel needed.", command);
        break;
      }
      status = SetMaxMixerStages(input_parcel);
      break;

    case qService::IQService::SET_DISPLAY_MODE:
      if (!input_parcel) {
        DLOGE("QService command = %d: input_parcel needed.", command);
        break;
      }
      status = SetDisplayMode(input_parcel);
      break;

    case qService::IQService::SET_SECONDARY_DISPLAY_STATUS: {
        if (!input_parcel || !output_parcel) {
          DLOGE("QService command = %d: input_parcel and output_parcel needed.", command);
          break;
        }
        int disp_id = INT(input_parcel->readInt32());
        HWCDisplay::DisplayStatus disp_status =
              static_cast<HWCDisplay::DisplayStatus>(input_parcel->readInt32());
        status = SetSecondaryDisplayStatus(disp_id, disp_status);
        output_parcel->writeInt32(status);
      }
      break;

    case qService::IQService::CONFIGURE_DYN_REFRESH_RATE:
      if (!input_parcel) {
        DLOGE("QService command = %d: input_parcel needed.", command);
        break;
      }
      status = ConfigureRefreshRate(input_parcel);
      break;

    case qService::IQService::SET_VIEW_FRAME:
      status = 0;
      break;

    case qService::IQService::TOGGLE_SCREEN_UPDATES: {
        if (!input_parcel || !output_parcel) {
          DLOGE("QService command = %d: input_parcel and output_parcel needed.", command);
          break;
        }
        int32_t input = input_parcel->readInt32();
        status = toggleScreenUpdate(input == 1);
        output_parcel->writeInt32(status);
      }
      break;

    case qService::IQService::QDCM_SVC_CMDS:
      if (!input_parcel || !output_parcel) {
        DLOGE("QService command = %d: input_parcel and output_parcel needed.", command);
        break;
      }
      status = QdcmCMDHandler(input_parcel, output_parcel);
      break;

    case qService::IQService::MIN_HDCP_ENCRYPTION_LEVEL_CHANGED: {
        if (!input_parcel || !output_parcel) {
          DLOGE("QService command = %d: input_parcel and output_parcel needed.", command);
          break;
        }
        int disp_id = input_parcel->readInt32();
        uint32_t min_enc_level = UINT32(input_parcel->readInt32());
        status = MinHdcpEncryptionLevelChanged(disp_id, min_enc_level);
        output_parcel->writeInt32(status);
      }
      break;

    case qService::IQService::CONTROL_PARTIAL_UPDATE: {
        if (!input_parcel || !output_parcel) {
          DLOGE("QService command = %d: input_parcel and output_parcel needed.", command);
          break;
        }
        int disp_id = input_parcel->readInt32();
        uint32_t enable = UINT32(input_parcel->readInt32());
        status = ControlPartialUpdate(disp_id, enable == 1);
        output_parcel->writeInt32(status);
      }
      break;

    case qService::IQService::SET_ACTIVE_CONFIG: {
        if (!input_parcel) {
          DLOGE("QService command = %d: input_parcel needed.", command);
          break;
        }
        uint32_t config = UINT32(input_parcel->readInt32());
        int disp_id = input_parcel->readInt32();
        status = SetActiveConfigIndex(disp_id, config);
      }
      break;

    case qService::IQService::GET_ACTIVE_CONFIG: {
        if (!input_parcel || !output_parcel) {
          DLOGE("QService command = %d: input_parcel and output_parcel needed.", command);
          break;
        }
        int disp_id = input_parcel->readInt32();
        uint32_t config = 0;
        status = GetActiveConfigIndex(disp_id, &config);
        output_parcel->writeInt32(INT(config));
      }
      break;

    case qService::IQService::GET_CONFIG_COUNT: {
        if (!input_parcel || !output_parcel) {
          DLOGE("QService command = %d: input_parcel and output_parcel needed.", command);
          break;
        }
        int disp_id = input_parcel->readInt32();
        uint32_t count = 0;
        status = GetConfigCount(disp_id, &count);
        output_parcel->writeInt32(INT(count));
      }
      break;

    case qService::IQService::GET_DISPLAY_ATTRIBUTES_FOR_CONFIG:
      if (!input_parcel || !output_parcel) {
        DLOGE("QService command = %d: input_parcel and output_parcel needed.", command);
        break;
      }
      status = HandleGetDisplayAttributesForConfig(input_parcel, output_parcel);
      break;

    case qService::IQService::GET_PANEL_BRIGHTNESS: {
        if (!output_parcel) {
          DLOGE("QService command = %d: output_parcel needed.", command);
          break;
        }
        int level = 0;
        status = GetPanelBrightness(&level);
        output_parcel->writeInt32(level);
      }
      break;

    case qService::IQService::SET_PANEL_BRIGHTNESS: {
        if (!input_parcel || !output_parcel) {
          DLOGE("QService command = %d: input_parcel and output_parcel needed.", command);
          break;
        }
        uint32_t level = UINT32(input_parcel->readInt32());
        status = setPanelBrightness(level);
        output_parcel->writeInt32(status);
      }
      break;

    case qService::IQService::GET_DISPLAY_VISIBLE_REGION:
      if (!input_parcel || !output_parcel) {
        DLOGE("QService command = %d: input_parcel and output_parcel needed.", command);
        break;
      }
      status = GetVisibleDisplayRect(input_parcel, output_parcel);
      break;

    case qService::IQService::SET_CAMERA_STATUS: {
        if (!input_parcel) {
          DLOGE("QService command = %d: input_parcel needed.", command);
          break;
        }
        uint32_t camera_status = UINT32(input_parcel->readInt32());
        status = setCameraLaunchStatus(camera_status);
      }
      break;

    case qService::IQService::GET_BW_TRANSACTION_STATUS: {
        if (!output_parcel) {
          DLOGE("QService command = %d: output_parcel needed.", command);
          break;
        }
        bool state = true;
        status = DisplayBWTransactionPending(&state);
        output_parcel->writeInt32(state);
      }
      break;

    case qService::IQService::SET_LAYER_MIXER_RESOLUTION:
      if (!input_parcel) {
        DLOGE("QService command = %d: input_parcel needed.", command);
        break;
      }
      status = SetMixerResolution(input_parcel);
      break;

    case qService::IQService::SET_COLOR_MODE:
      if (!input_parcel) {
        DLOGE("QService command = %d: input_parcel needed.", command);
        break;
      }
      status = SetColorModeOverride(input_parcel);
      break;

    case qService::IQService::SET_COLOR_MODE_WITH_RENDER_INTENT:
      if (!input_parcel) {
        DLOGE("QService command = %d: input_parcel needed.", command);
        break;
      }
      status = SetColorModeWithRenderIntentOverride(input_parcel);
      break;

    case qService::IQService::SET_COLOR_MODE_BY_ID:
      if (!input_parcel) {
        DLOGE("QService command = %d: input_parcel needed.", command);
        break;
      }
      status = SetColorModeById(input_parcel);
      break;

    case qService::IQService::GET_COMPOSER_STATUS:
      if (!output_parcel) {
        DLOGE("QService command = %d: output_parcel needed.", command);
        break;
      }
      status = 0;
      output_parcel->writeInt32(getComposerStatus());
      break;

    case qService::IQService::SET_IDLE_PC:
      if (!input_parcel) {
        DLOGE("QService command = %d: input_parcel needed.", command);
        break;
      }
      status = SetIdlePC(input_parcel);
      break;

    case qService::IQService::SET_COLOR_SAMPLING_ENABLED:
      if (!input_parcel) {
        DLOGE("QService command = %d: input_parcel needed.", command);
        break;
      }
      status = setColorSamplingEnabled(input_parcel);
      break;

    case qService::IQService::SET_WHITE_COMPENSATION:
      if (!input_parcel) {
        DLOGE("QService command = %d: input_parcel needed.", command);
        break;
      }
      status = SetWhiteCompensation(input_parcel);
      break;
    default:
      DLOGW("QService command = %d is not supported.", command);
      break;
  }

  return status;
}

android::status_t HWCSession::getComposerStatus() {
  return is_composer_up_;
}

android::status_t HWCSession::setColorSamplingEnabled(const android::Parcel* input_parcel)
{
    int dpy = input_parcel->readInt32();
    int enabled_cmd = input_parcel->readInt32();
    if (dpy < HWC_DISPLAY_PRIMARY || dpy >= HWC_NUM_DISPLAY_TYPES ||
        enabled_cmd < 0 || enabled_cmd > 1) {
        return android::BAD_VALUE;
    }

    SEQUENCE_WAIT_SCOPE_LOCK(locker_[dpy]);
    if (!hwc_display_[dpy]) {
        DLOGW("No display id %i active to enable histogram event", dpy);
        return android::BAD_VALUE;
    }

    auto error = hwc_display_[dpy]->SetDisplayedContentSamplingEnabledVndService(enabled_cmd);
    return (error == HWC2::Error::None) ? android::OK : android::BAD_VALUE;
}

android::status_t HWCSession::HandleGetDisplayAttributesForConfig(const android::Parcel
                                                                  *input_parcel,
                                                                  android::Parcel *output_parcel) {
  int config = input_parcel->readInt32();
  int dpy = input_parcel->readInt32();
  int error = android::BAD_VALUE;
  DisplayConfigVariableInfo display_attributes;

  if (dpy < HWC_DISPLAY_PRIMARY || dpy >= HWC_NUM_DISPLAY_TYPES || config < 0) {
    return android::BAD_VALUE;
  }

  SEQUENCE_WAIT_SCOPE_LOCK(locker_[dpy]);
  if (hwc_display_[dpy]) {
    error = hwc_display_[dpy]->GetDisplayAttributesForConfig(config, &display_attributes);
    if (error == 0) {
      output_parcel->writeInt32(INT(display_attributes.vsync_period_ns));
      output_parcel->writeInt32(INT(display_attributes.x_pixels));
      output_parcel->writeInt32(INT(display_attributes.y_pixels));
      output_parcel->writeFloat(display_attributes.x_dpi);
      output_parcel->writeFloat(display_attributes.y_dpi);
      output_parcel->writeInt32(0);  // Panel type, unsupported.
    }
  }

  return error;
}

android::status_t HWCSession::ConfigureRefreshRate(const android::Parcel *input_parcel) {
  SEQUENCE_WAIT_SCOPE_LOCK(locker_[HWC_DISPLAY_PRIMARY]);

  uint32_t operation = UINT32(input_parcel->readInt32());
  HWCDisplay *hwc_display = hwc_display_[HWC_DISPLAY_PRIMARY];

  if (!hwc_display) {
    DLOGW("Display = %d is not connected.", HWC_DISPLAY_PRIMARY);
    return -ENODEV;
  }

  switch (operation) {
    case qdutils::DISABLE_METADATA_DYN_REFRESH_RATE:
      return hwc_display->Perform(HWCDisplayPrimary::SET_METADATA_DYN_REFRESH_RATE, false);

    case qdutils::ENABLE_METADATA_DYN_REFRESH_RATE:
      return hwc_display->Perform(HWCDisplayPrimary::SET_METADATA_DYN_REFRESH_RATE, true);

    case qdutils::SET_BINDER_DYN_REFRESH_RATE: {
      uint32_t refresh_rate = UINT32(input_parcel->readInt32());
      return hwc_display->Perform(HWCDisplayPrimary::SET_BINDER_DYN_REFRESH_RATE, refresh_rate);
    }

    default:
      DLOGW("Invalid operation %d", operation);
      return -EINVAL;
  }

  return 0;
}

android::status_t HWCSession::SetDisplayMode(const android::Parcel *input_parcel) {
  SEQUENCE_WAIT_SCOPE_LOCK(locker_[HWC_DISPLAY_PRIMARY]);

  if (!hwc_display_[HWC_DISPLAY_PRIMARY]) {
    DLOGW("Display = %d is not connected.", HWC_DISPLAY_PRIMARY);
    return -ENODEV;
  }

  uint32_t mode = UINT32(input_parcel->readInt32());
  return hwc_display_[HWC_DISPLAY_PRIMARY]->Perform(HWCDisplayPrimary::SET_DISPLAY_MODE, mode);
}

android::status_t HWCSession::SetMaxMixerStages(const android::Parcel *input_parcel) {
  DisplayError error = kErrorNone;
  std::bitset<32> bit_mask_display_type = UINT32(input_parcel->readInt32());
  uint32_t max_mixer_stages = UINT32(input_parcel->readInt32());
  android::status_t status = 0;

  for (uint32_t disp_id = HWC_DISPLAY_PRIMARY; disp_id < HWC_NUM_DISPLAY_TYPES; disp_id++) {
    if (bit_mask_display_type[disp_id]) {
      SEQUENCE_WAIT_SCOPE_LOCK(locker_[disp_id]);
      if (hwc_display_[disp_id]) {
        error = hwc_display_[disp_id]->SetMaxMixerStages(max_mixer_stages);
        if (error != kErrorNone) {
          status = -EINVAL;
          continue;
        }
      } else {
        DLOGW("Display = %d is not connected.", disp_id);
        status = (status)? status : -ENODEV;  // Return higher priority error.
        continue;
      }
    }
  }

  return status;
}

android::status_t HWCSession::SetFrameDumpConfig(const android::Parcel *input_parcel) {
  uint32_t frame_dump_count = UINT32(input_parcel->readInt32());
  std::bitset<32> bit_mask_display_type = UINT32(input_parcel->readInt32());
  uint32_t bit_mask_layer_type = UINT32(input_parcel->readInt32());
  int32_t output_format = HAL_PIXEL_FORMAT_RGB_888;
  bool post_processed = true;

  // Read optional user preferences: output_format and post_processed.
  if (input_parcel->dataPosition() != input_parcel->dataSize()) {
    // HAL Pixel Format for output buffer
    output_format = input_parcel->readInt32();
  }
  if (input_parcel->dataPosition() != input_parcel->dataSize()) {
    // Option to dump Layer Mixer output (0) or DSPP output (1)
    post_processed = (input_parcel->readInt32() != 0);
  }

  android::status_t status = 0;

  for (uint32_t disp_id = HWC_DISPLAY_PRIMARY; disp_id < HWC_NUM_DISPLAY_TYPES; disp_id++) {
    if (bit_mask_display_type[disp_id]) {
      SEQUENCE_WAIT_SCOPE_LOCK(locker_[disp_id]);
      if (hwc_display_[disp_id]) {
        HWC2::Error error;
        error = hwc_display_[disp_id]->SetFrameDumpConfig(frame_dump_count, bit_mask_layer_type,
                                                          output_format, post_processed);
        if (HWC2::Error::None != error) {
          if (HWC2::Error::NoResources == error)
            status = -ENOMEM;
          else
            status = -EINVAL;
          continue;
        }
      } else {
        DLOGW("Display = %d is not connected.", disp_id);
        status = (status)? status : -ENODEV;  // Return higher priority error.
        continue;
      }
    }
  }

  return status;
}

android::status_t HWCSession::SetMixerResolution(const android::Parcel *input_parcel) {
  DisplayError error = kErrorNone;
  uint32_t dpy = UINT32(input_parcel->readInt32());

  if (dpy != HWC_DISPLAY_PRIMARY) {
    DLOGW("Resolution change not supported for this display = %d", dpy);
    return -EINVAL;
  }

  SEQUENCE_WAIT_SCOPE_LOCK(locker_[HWC_DISPLAY_PRIMARY]);
  if (!hwc_display_[HWC_DISPLAY_PRIMARY]) {
    DLOGW("Primary display is not initialized");
    return -ENODEV;
  }

  uint32_t width = UINT32(input_parcel->readInt32());
  uint32_t height = UINT32(input_parcel->readInt32());

  error = hwc_display_[HWC_DISPLAY_PRIMARY]->SetMixerResolution(width, height);
  if (error != kErrorNone) {
    return -EINVAL;
  }

  return 0;
}

android::status_t HWCSession::SetColorModeOverride(const android::Parcel *input_parcel) {
  auto display = static_cast<hwc2_display_t >(input_parcel->readInt32());
  auto mode = static_cast<ColorMode>(input_parcel->readInt32());
  auto device = static_cast<hwc2_device_t *>(this);

  if (mode < ColorMode::NATIVE || mode > ColorMode::BT2100_HLG) {
    DLOGE("Invalid ColorMode: %d", mode);
    return HWC2_ERROR_BAD_PARAMETER;
  }

  auto err = CallDisplayFunction(device, display, &HWCDisplay::SetColorMode, mode);
  if (err != HWC2_ERROR_NONE)
    return -EINVAL;

  return 0;
}

android::status_t HWCSession::SetWhiteCompensation(const android::Parcel *input_parcel) {
  auto display = static_cast<hwc2_display_t>(input_parcel->readInt32());
  auto enabled = static_cast<bool>(input_parcel->readInt32());
  auto device = static_cast<hwc2_device_t *>(this);

  auto err = CallDisplayFunction(device, display, &HWCDisplay::SetWhiteCompensation, enabled);
  if (err != HWC2_ERROR_NONE)
    return -EINVAL;

  return 0;
}

android::status_t HWCSession::SetColorModeWithRenderIntentOverride(
    const android::Parcel *input_parcel) {
  auto display = static_cast<hwc2_display_t>(input_parcel->readInt32());
  auto mode = static_cast<ColorMode>(input_parcel->readInt32());
  auto intent = static_cast<RenderIntent>(input_parcel->readInt32());
  auto device = static_cast<hwc2_device_t *>(this);

  if (mode < ColorMode::NATIVE || mode > ColorMode::BT2100_HLG) {
    DLOGE("Invalid ColorMode: %d", mode);
    return HWC2_ERROR_BAD_PARAMETER;
  }

  if (intent < RenderIntent::COLORIMETRIC || intent > RenderIntent::TONE_MAP_ENHANCE) {
    DLOGE("Invalid RenderIntent: %d", intent);
    return HWC2_ERROR_BAD_PARAMETER;
  }

  auto err =
      CallDisplayFunction(device, display, &HWCDisplay::SetColorModeWithRenderIntent, mode, intent);
  if (err != HWC2_ERROR_NONE)
    return -EINVAL;

  return 0;
}
android::status_t HWCSession::SetColorModeById(const android::Parcel *input_parcel) {
  auto display = static_cast<hwc2_display_t >(input_parcel->readInt32());
  auto mode = input_parcel->readInt32();
  auto device = static_cast<hwc2_device_t *>(this);

  auto err = CallDisplayFunction(device, display, &HWCDisplay::SetColorModeById, mode);
  if (err != HWC2_ERROR_NONE)
    return -EINVAL;

  return 0;
}

void HWCSession::DynamicDebug(const android::Parcel *input_parcel) {
  int type = input_parcel->readInt32();
  bool enable = (input_parcel->readInt32() > 0);
  DLOGI("type = %d enable = %d", type, enable);
  int verbose_level = input_parcel->readInt32();

  switch (type) {
    case qService::IQService::DEBUG_ALL:
      HWCDebugHandler::DebugAll(enable, verbose_level);
      break;

    case qService::IQService::DEBUG_MDPCOMP:
      HWCDebugHandler::DebugStrategy(enable, verbose_level);
      HWCDebugHandler::DebugCompManager(enable, verbose_level);
      break;

    case qService::IQService::DEBUG_PIPE_LIFECYCLE:
      HWCDebugHandler::DebugResources(enable, verbose_level);
      break;

    case qService::IQService::DEBUG_DRIVER_CONFIG:
      HWCDebugHandler::DebugDriverConfig(enable, verbose_level);
      break;

    case qService::IQService::DEBUG_ROTATOR:
      HWCDebugHandler::DebugResources(enable, verbose_level);
      HWCDebugHandler::DebugDriverConfig(enable, verbose_level);
      HWCDebugHandler::DebugRotator(enable, verbose_level);
      break;

    case qService::IQService::DEBUG_QDCM:
      HWCDebugHandler::DebugQdcm(enable, verbose_level);
      break;

    case qService::IQService::DEBUG_SCALAR:
      HWCDebugHandler::DebugScalar(enable, verbose_level);
      break;

    case qService::IQService::DEBUG_CLIENT:
      HWCDebugHandler::DebugClient(enable, verbose_level);
      break;

    case qService::IQService::DEBUG_DISPLAY:
      HWCDebugHandler::DebugDisplay(enable, verbose_level);
      break;

    default:
      DLOGW("type = %d is not supported", type);
  }
}

android::status_t HWCSession::QdcmCMDHandler(const android::Parcel *input_parcel,
                                             android::Parcel *output_parcel) {
  int ret = 0;
  int32_t *brightness_value = NULL;
  uint32_t display_id(0);
  PPPendingParams pending_action;
  PPDisplayAPIPayload resp_payload, req_payload;

  if (!color_mgr_) {
    DLOGW("color_mgr_ not initialized.");
    return -ENOENT;
  }

  pending_action.action = kNoAction;
  pending_action.params = NULL;

  // Read display_id, payload_size and payload from in_parcel.
  ret = HWCColorManager::CreatePayloadFromParcel(*input_parcel, &display_id, &req_payload);
  if (!ret) {
    if ((display_id >= HWC_NUM_DISPLAY_TYPES) || !hwc_display_[display_id]) {
      DLOGW("Invalid display id or display = %d is not connected.", display_id);
      ret = -ENODEV;
    }
  }

  if (!ret) {
    if ((HWC_DISPLAY_PRIMARY == display_id) || (HWC_DISPLAY_EXTERNAL == display_id)) {
      ret = hwc_display_[display_id]->ColorSVCRequestRoute(req_payload, &resp_payload,
                                                           &pending_action);
    } else {
      // Virtual, Tertiary etc. not supported.
      DLOGW("Operation not supported on display = %d.", display_id);
      ret = -EINVAL;
    }
  }

  if (ret) {
    output_parcel->writeInt32(ret);  // first field in out parcel indicates return code.
    req_payload.DestroyPayload();
    resp_payload.DestroyPayload();
    return ret;
  }

  if (kNoAction != pending_action.action) {
    // Restrict pending actions to primary display.
    if (HWC_DISPLAY_PRIMARY != display_id) {
      DLOGW("Skipping pending action %d on display = %d.", pending_action.action, display_id);
      pending_action.action = kNoAction;
    }

    int32_t action = pending_action.action;
    int count = -1;
    while (action > 0) {
      count++;
      int32_t bit = (action & 1);
      action = action >> 1;

      if (!bit)
        continue;

      DLOGV_IF(kTagQDCM, "pending action = %d", BITMAP(count));
      switch (BITMAP(count)) {
        case kInvalidating:
          Refresh(HWC_DISPLAY_PRIMARY);
          break;
        case kEnterQDCMMode:
          ret = color_mgr_->EnableQDCMMode(true, hwc_display_[HWC_DISPLAY_PRIMARY]);
          break;
        case kExitQDCMMode:
          ret = color_mgr_->EnableQDCMMode(false, hwc_display_[HWC_DISPLAY_PRIMARY]);
          break;
        case kApplySolidFill:
          {
            SCOPE_LOCK(locker_[HWC_DISPLAY_PRIMARY]);
            ret = color_mgr_->SetSolidFill(pending_action.params,
                                            true, hwc_display_[HWC_DISPLAY_PRIMARY]);
          }
          Refresh(HWC_DISPLAY_PRIMARY);
          usleep(kSolidFillDelay);
          break;
        case kDisableSolidFill:
          {
            SCOPE_LOCK(locker_[HWC_DISPLAY_PRIMARY]);
            ret = color_mgr_->SetSolidFill(pending_action.params,
                                            false, hwc_display_[HWC_DISPLAY_PRIMARY]);
          }
          Refresh(HWC_DISPLAY_PRIMARY);
          usleep(kSolidFillDelay);
          break;
        case kSetPanelBrightness:
          brightness_value = reinterpret_cast<int32_t *>(resp_payload.payload);
          if (brightness_value == NULL) {
            DLOGE("Brightness value is Null");
            ret = -EINVAL;
          } else {
            ret = hwc_display_[HWC_DISPLAY_PRIMARY]->SetPanelBrightness(*brightness_value);
          }
          break;
        case kEnableFrameCapture:
          ret = color_mgr_->SetFrameCapture(pending_action.params, true,
                                        hwc_display_[HWC_DISPLAY_PRIMARY]);
          Refresh(HWC_DISPLAY_PRIMARY);
          break;
        case kDisableFrameCapture:
          ret = color_mgr_->SetFrameCapture(pending_action.params, false,
                                        hwc_display_[HWC_DISPLAY_PRIMARY]);
          break;
        case kConfigureDetailedEnhancer:
          ret = color_mgr_->SetDetailedEnhancer(pending_action.params,
                                            hwc_display_[HWC_DISPLAY_PRIMARY]);
          Refresh(HWC_DISPLAY_PRIMARY);
          break;
        case kModeSet:
          ret = static_cast<int>
                 (hwc_display_[HWC_DISPLAY_PRIMARY]->RestoreColorTransform());
          Refresh(HWC_DISPLAY_PRIMARY);
          break;
        case kNoAction:
          break;
        default:
          DLOGW("Invalid pending action = %d!", pending_action.action);
          break;
      }
    }
  }
  // for display API getter case, marshall returned params into out_parcel.
  output_parcel->writeInt32(ret);
  HWCColorManager::MarshallStructIntoParcel(resp_payload, output_parcel);
  req_payload.DestroyPayload();
  resp_payload.DestroyPayload();
  hwc_display_[display_id]->ResetValidation();

  return ret;
}

void HWCSession::UEventHandler(const char *uevent_data, int length) {
  if (strcasestr(uevent_data, HWC_UEVENT_SWITCH_HDMI)) {
    DLOGI("Uevent HDMI = %s", uevent_data);
    int connected = GetEventValue(uevent_data, length, "SWITCH_STATE=");
    if (connected >= 0) {
      DLOGI("HDMI = %s", connected ? "connected" : "disconnected");
      if (HotPlugHandler(connected) == -1) {
        DLOGE("Failed handling Hotplug = %s", connected ? "connected" : "disconnected");
      }
    }
  } else if (strcasestr(uevent_data, HWC_UEVENT_GRAPHICS_FB0)) {
    DLOGI("Uevent FB0 = %s", uevent_data);
    int panel_reset = GetEventValue(uevent_data, length, "PANEL_ALIVE=");
    if (panel_reset == 0) {
      Refresh(0);
      reset_panel_ = true;
    }
  } else if (strcasestr(uevent_data, HWC_UEVENT_DRM_EXT_HOTPLUG)) {
    HandleExtHPD(uevent_data, length);
  }
}

const char *GetTokenValue(const char *uevent_data, int length, const char *token) {
  const char *iterator_str = uevent_data;
  const char *pstr = NULL;
  while (((iterator_str - uevent_data) <= length) && (*iterator_str)) {
    pstr = strstr(iterator_str, token);
    if (pstr) {
      break;
    }
    iterator_str += strlen(iterator_str) + 1;
  }

  if (pstr)
    pstr = pstr+strlen(token);

  return pstr;
}

void HWCSession::HandleExtHPD(const char *uevent_data, int length) {
  const char *pstr = GetTokenValue(uevent_data, length, "name=");
  if (!pstr || (strncmp(pstr, "DP-1", strlen("DP-1")) != 0)) {
    return;
  }

  pstr = GetTokenValue(uevent_data, length, "status=");
  if (pstr) {
    bool connected = false;
    hpd_bpp_ = 0;
    hpd_pattern_ = 0;
    if (strncmp(pstr, "connected", strlen("connected")) == 0) {
      connected = true;
    }
    int bpp = GetEventValue(uevent_data, length, "bpp=");
    int pattern = GetEventValue(uevent_data, length, "pattern=");
    if (bpp >=0 && pattern >= 0) {
      hpd_bpp_ = bpp;
      hpd_pattern_ = pattern;
    }

    DLOGI("Recived Ext HPD, connected:%d  status=%s  bpp = %d pattern =%d ",
          connected, pstr, hpd_bpp_, hpd_pattern_);
    HotPlugHandler(connected);
  }
}

int HWCSession::GetEventValue(const char *uevent_data, int length, const char *event_info) {
  const char *iterator_str = uevent_data;
  while (((iterator_str - uevent_data) <= length) && (*iterator_str)) {
    const char *pstr = strstr(iterator_str, event_info);
    if (pstr != NULL) {
      return (atoi(iterator_str + strlen(event_info)));
    }
    iterator_str += strlen(iterator_str) + 1;
  }

  return -1;
}

void HWCSession::ResetPanel() {
  HWC2::Error status;

  DLOGI("Powering off primary");
  status = hwc_display_[HWC_DISPLAY_PRIMARY]->SetPowerMode(HWC2::PowerMode::Off);
  if (status != HWC2::Error::None) {
    DLOGE("power-off on primary failed with error = %d", status);
  }

  DLOGI("Restoring power mode on primary");
  HWC2::PowerMode mode = hwc_display_[HWC_DISPLAY_PRIMARY]->GetLastPowerMode();
  status = hwc_display_[HWC_DISPLAY_PRIMARY]->SetPowerMode(mode);
  if (status != HWC2::Error::None) {
    DLOGE("Setting power mode = %d on primary failed with error = %d", mode, status);
  }

  status = hwc_display_[HWC_DISPLAY_PRIMARY]->SetVsyncEnabled(HWC2::Vsync::Enable);
  if (status != HWC2::Error::None) {
    DLOGE("enabling vsync failed for primary with error = %d", status);
  }

  reset_panel_ = false;
}

int HWCSession::HotPlugHandler(bool connected) {
  int status = 0;
  bool notify_hotplug = false;

  // To prevent sending events to client while a lock is held, acquire scope locks only within
  // below scope so that those get automatically unlocked after the scope ends.
  do {
    // If HDMI is primary but not created yet (first time), create it and notify surfaceflinger.
    //    if it is already created, but got disconnected/connected again,
    //    just toggle display status and do not notify surfaceflinger.
    // If HDMI is not primary, create/destroy external display normally.
    if (hdmi_is_primary_) {
      SCOPE_LOCK(locker_[HWC_DISPLAY_PRIMARY]);
      if (hwc_display_[HWC_DISPLAY_PRIMARY]) {
        status = hwc_display_[HWC_DISPLAY_PRIMARY]->SetState(connected);
      } else {
        status = CreateExternalDisplay(HWC_DISPLAY_PRIMARY, 0, 0, false);
        notify_hotplug = true;
      }

      break;
    }

    {
      SCOPE_LOCK(locker_[HWC_DISPLAY_PRIMARY]);
      // Primary display must be connected for HDMI as secondary cases.
      if (!hwc_display_[HWC_DISPLAY_PRIMARY]) {
        DLOGE("Primary display is not connected.");
        return -1;
      }

      hwc_display_[HWC_DISPLAY_PRIMARY]->ResetValidation();
    }

    if (connected) {
      SCOPE_LOCK(locker_[HWC_DISPLAY_EXTERNAL]);
      Locker::ScopeLock lock_v(locker_[HWC_DISPLAY_VIRTUAL]);
      // Connect external display if virtual display is not connected.
      // Else, defer external display connection and process it when virtual display
      // tears down; Do not notify SurfaceFlinger since connection is deferred now.
      if (!hwc_display_[HWC_DISPLAY_VIRTUAL]) {
        status = ConnectDisplay(HWC_DISPLAY_EXTERNAL);
        if (status) {
          return status;
        }
        notify_hotplug = true;
      } else {
        DLOGI("Virtual display is connected, pending connection");
        external_pending_connect_ = true;
      }
    } else {
      SEQUENCE_WAIT_SCOPE_LOCK(locker_[HWC_DISPLAY_EXTERNAL]);
      if (hwc_display_[HWC_DISPLAY_EXTERNAL]) {
        notify_hotplug = true;
      }
      external_pending_connect_ = false;
    }
  } while (0);

  if (connected) {
    // In connect case, we send hotplug after we create display
    Refresh(0);

    if (!hdmi_is_primary_) {
      // wait for sufficient time to ensure sufficient resources are available to process new
      // new display connection.
      uint32_t vsync_period = UINT32(GetVsyncPeriod(HWC_DISPLAY_PRIMARY));
      usleep(vsync_period * 2 / 1000);
    }
    if (notify_hotplug) {
      HotPlug(hdmi_is_primary_ ? HWC_DISPLAY_PRIMARY : HWC_DISPLAY_EXTERNAL,
              HWC2::Connection::Connected);
    }
  } else {
    // In disconnect case, we notify hotplug first to let the listener state update happen first
    // Then we can destroy the underlying display object
    if (notify_hotplug) {
      HotPlug(hdmi_is_primary_ ? HWC_DISPLAY_PRIMARY : HWC_DISPLAY_EXTERNAL,
              HWC2::Connection::Disconnected);
    }
    Refresh(0);
    if (!hdmi_is_primary_) {
      uint32_t vsync_period = UINT32(GetVsyncPeriod(HWC_DISPLAY_PRIMARY));
      usleep(vsync_period * 2 / 1000);
    }
    // Now disconnect the display
    {
      SEQUENCE_WAIT_SCOPE_LOCK(locker_[HWC_DISPLAY_EXTERNAL]);
      // Do not return error if external display is not in connected status.
      // Due to virtual display concurrency, external display connection might be still pending
      // but hdmi got disconnected before pending connection could be processed.
      if (hwc_display_[HWC_DISPLAY_EXTERNAL]) {
        status = DisconnectDisplay(HWC_DISPLAY_EXTERNAL);
      }
    }
  }

  // notify client

  qservice_->onHdmiHotplug(INT(connected));

  return 0;
}

int HWCSession::GetVsyncPeriod(int disp) {
  SCOPE_LOCK(locker_[disp]);
  // default value
  int32_t vsync_period = 1000000000l / 60;
  auto attribute = HWC2::Attribute::VsyncPeriod;

  if (hwc_display_[disp]) {
    hwc_display_[disp]->GetDisplayAttribute(0, attribute, &vsync_period);
  }

  return vsync_period;
}

android::status_t HWCSession::GetVisibleDisplayRect(const android::Parcel *input_parcel,
                                                    android::Parcel *output_parcel) {
  int dpy = input_parcel->readInt32();
  if (dpy < HWC_DISPLAY_PRIMARY || dpy >= HWC_NUM_DISPLAY_TYPES) {
    return android::BAD_VALUE;
  }

  SEQUENCE_WAIT_SCOPE_LOCK(locker_[dpy]);
  if (!hwc_display_[dpy]) {
    return android::NO_INIT;
  }

  hwc_rect_t visible_rect = {0, 0, 0, 0};
  int error = hwc_display_[dpy]->GetVisibleDisplayRect(&visible_rect);
  if (error < 0) {
    return error;
  }

  output_parcel->writeInt32(visible_rect.left);
  output_parcel->writeInt32(visible_rect.top);
  output_parcel->writeInt32(visible_rect.right);
  output_parcel->writeInt32(visible_rect.bottom);

  return android::NO_ERROR;
}

void HWCSession::Refresh(hwc2_display_t display) {
  SCOPE_LOCK(callbacks_lock_);
  HWC2::Error err = callbacks_.Refresh(display);
  while (err != HWC2::Error::None) {
    callbacks_lock_.Wait();
    err = callbacks_.Refresh(display);
  }
}

void HWCSession::HotPlug(hwc2_display_t display, HWC2::Connection state) {
  SCOPE_LOCK(callbacks_lock_);
  HWC2::Error err = callbacks_.Hotplug(display, state);
  while (err != HWC2::Error::None) {
    callbacks_lock_.Wait();
    err = callbacks_.Hotplug(display, state);
  }
}

int HWCSession::CreateExternalDisplay(int disp_id, uint32_t primary_width,
                                      uint32_t primary_height, bool use_primary_res) {
  uint32_t panel_bpp = 0;
  uint32_t pattern_type = 0;

  if (GetDriverType() == DriverType::FB) {
    qdutils::getDPTestConfig(&panel_bpp, &pattern_type);
  } else {
    panel_bpp = static_cast<uint32_t>(hpd_bpp_);
    pattern_type = static_cast<uint32_t>(hpd_pattern_);
  }

  if (panel_bpp && pattern_type) {
    return HWCDisplayExternalTest::Create(core_intf_, &buffer_allocator_, &callbacks_,
                                          qservice_, panel_bpp, pattern_type,
                                          &hwc_display_[disp_id]);
  }

  return  HWCDisplayExternal::Create(core_intf_, &buffer_allocator_, &callbacks_,
                                     primary_width, primary_height, qservice_,
                                     use_primary_res, &hwc_display_[disp_id]);
}

HWC2::Error HWCSession::ValidateDisplayInternal(hwc2_display_t display, uint32_t *out_num_types,
                                                uint32_t *out_num_requests) {
  HWCDisplay *hwc_display = hwc_display_[display];
  if (hwc_display->IsInternalValidateState()) {
    // Internal Validation has already been done on display, get the Output params.
    return hwc_display->GetValidateDisplayOutput(out_num_types, out_num_requests);
  }

  if (display == HWC_DISPLAY_PRIMARY) {
    // TODO(user): This can be moved to HWCDisplayPrimary
    if (reset_panel_) {
      DLOGW("panel is in bad state, resetting the panel");
      ResetPanel();
    }

    if (need_invalidate_) {
      Refresh(display);
      need_invalidate_ = false;
    }

    if (color_mgr_) {
      color_mgr_->SetColorModeDetailEnhancer(hwc_display_[display]);
    }
  }

  return hwc_display->Validate(out_num_types, out_num_requests);
}

HWC2::Error HWCSession::PresentDisplayInternal(hwc2_display_t display, int32_t *out_retire_fence) {
  HWCDisplay *hwc_display = hwc_display_[display];
  // If display is in Skip-Validate state and Validate cannot be skipped, do Internal
  // Validation to optimize for the frames which don't require the Client composition.
  if (hwc_display->IsSkipValidateState() && !hwc_display->CanSkipValidate()) {
    uint32_t out_num_types = 0, out_num_requests = 0;
    HWC2::Error error = ValidateDisplayInternal(display, &out_num_types, &out_num_requests);
    if ((error != HWC2::Error::None) || hwc_display->HasClientComposition()) {
      hwc_display->SetValidationState(HWCDisplay::kInternalValidate);
      return HWC2::Error::NotValidated;
    }
  }

  return hwc_display->Present(out_retire_fence);
}

int32_t HWCSession::GetReadbackBufferAttributes(hwc2_device_t *device, hwc2_display_t display,
                                                int32_t *format, int32_t *dataspace) {
  if (!device || !format || !dataspace) {
    return HWC2_ERROR_BAD_PARAMETER;
  }

  if (display != HWC_DISPLAY_PRIMARY) {
    return HWC2_ERROR_BAD_DISPLAY;
  }

  HWCSession *hwc_session = static_cast<HWCSession *>(device);
  HWCDisplay *hwc_display = hwc_session->hwc_display_[display];

  if (hwc_display) {
    *format = HAL_PIXEL_FORMAT_RGB_888;
    *dataspace = GetDataspace(hwc_display->GetCurrentColorMode());
    return HWC2_ERROR_NONE;
  }

  return HWC2_ERROR_BAD_DISPLAY;
}

int32_t HWCSession::SetReadbackBuffer(hwc2_device_t *device, hwc2_display_t display,
                                      const native_handle_t *buffer, int32_t acquire_fence) {
  if (!buffer) {
    return HWC2_ERROR_BAD_PARAMETER;
  }

  if (display != HWC_DISPLAY_PRIMARY) {
    return HWC2_ERROR_BAD_DISPLAY;
  }

  HWCSession *hwc_session = static_cast<HWCSession *>(device);
  if (hwc_session->hwc_display_[HWC_DISPLAY_EXTERNAL] ||
      hwc_session->hwc_display_[HWC_DISPLAY_VIRTUAL]) {
    return HWC2_ERROR_UNSUPPORTED;
  }

  return CallDisplayFunction(device, display, &HWCDisplay::SetReadbackBuffer,
                             buffer, acquire_fence, false);
}

int32_t HWCSession::GetReadbackBufferFence(hwc2_device_t *device, hwc2_display_t display,
                                           int32_t *release_fence) {
  if (!release_fence) {
    return HWC2_ERROR_BAD_PARAMETER;
  }

  if (display != HWC_DISPLAY_PRIMARY) {
    return HWC2_ERROR_BAD_DISPLAY;
  }

  return CallDisplayFunction(device, display, &HWCDisplay::GetReadbackBufferFence, release_fence);
}

android::status_t HWCSession::SetIdlePC(const android::Parcel *input_parcel) {
  auto enable = input_parcel->readInt32();
  auto synchronous = input_parcel->readInt32();

#ifdef DISPLAY_CONFIG_1_3
  return static_cast<android::status_t>(controlIdlePowerCollapse(enable, synchronous));
#else
  {
    SEQUENCE_WAIT_SCOPE_LOCK(locker_[HWC_DISPLAY_PRIMARY]);
    if (hwc_display_[HWC_DISPLAY_PRIMARY]) {
      DLOGE("Primary display is not ready");
      return -EINVAL;
    }
    auto error = hwc_display_[HWC_DISPLAY_PRIMARY]->ControlIdlePowerCollapse(enable, synchronous);
    if (error != HWC2::Error::None) {
      return -EINVAL;
    }
    if (!enable) {
      Refresh(HWC_DISPLAY_PRIMARY);
      int32_t error = locker_[HWC_DISPLAY_PRIMARY].WaitFinite(kCommitDoneTimeoutMs);
      if (error == ETIMEDOUT) {
        DLOGE("Timed out!! Next frame commit done event not received!!");
        return error;
      }
    }
    DLOGI("Idle PC %s!!", enable ? "enabled" : "disabled");
  }
  return 0;
#endif
}

}  // namespace sdm
