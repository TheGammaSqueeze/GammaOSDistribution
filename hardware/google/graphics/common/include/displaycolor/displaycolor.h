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

#ifndef DISPLAYCOLOR_H_
#define DISPLAYCOLOR_H_

#include <android/hardware/graphics/common/1.1/types.h>
#include <android/hardware/graphics/common/1.2/types.h>

#include <string>

namespace displaycolor {

namespace hwc {
using android::hardware::graphics::common::V1_1::RenderIntent;
using android::hardware::graphics::common::V1_2::ColorMode;
using android::hardware::graphics::common::V1_2::Dataspace;
}  // namespace hwc

/**
 * hwc/displaycolor interface history
 *
 * 3.0.0.2021-11-18 calibration info intf
 * 2.0.0.2021-08-27 pass brightness table for hdr10+
 * 1.0.0.2021-08-25 Initial release
 */

constexpr struct DisplayColorIntfVer {
    uint16_t major; // increase it for new functionalities
    uint16_t minor; // for bug fix and cause binary incompatible
    uint16_t patch; // for bug fix and binary compatible

    bool operator==(const DisplayColorIntfVer &rhs) const {
        return major == rhs.major &&
            minor == rhs.minor &&
            patch == rhs.patch;
    }

    bool Compatible(const DisplayColorIntfVer &rhs) const {
        return major == rhs.major &&
            minor == rhs.minor;
    }

} kInterfaceVersion {
    3,
    0,
    0,
};

/// A map associating supported RenderIntents for each supported ColorMode
using ColorModesMap = std::map<hwc::ColorMode, std::vector<hwc::RenderIntent>>;

/// Image data bit depths.
enum class BitDepth { kEight, kTen };

/// Display type used to get pipeline or update display scene.
enum DisplayType {
    /// builtin primary display
    DISPLAY_PRIMARY = 0,
    /// builtin secondary display
    DISPLAY_SECONDARY = 1,
    /// number of display
    DISPLAY_MAX = 2,
};

enum BrightnessMode {
    BM_NOMINAL = 0,
    BM_HBM = 1,
    BM_MAX = 2,
};

struct DisplayBrightnessTable {
    float nbm_nits_min;
    float nbm_nits_max;
    float hbm_nits_min;
    float hbm_nits_max;

    uint32_t nbm_dbv_min;
    uint32_t nbm_dbv_max;
    uint32_t hbm_dbv_min;
    uint32_t hbm_dbv_max;
};

struct DisplayInfo {
    std::string panel_name;
    std::string panel_serial;

    DisplayBrightnessTable brightness_table;
};

struct LayerColorData {
    bool operator==(const LayerColorData &rhs) const {
        return dataspace == rhs.dataspace && matrix == rhs.matrix &&
               static_metadata == rhs.static_metadata &&
               dynamic_metadata == rhs.dynamic_metadata;
    }

    /**
     * @brief HDR static metadata.
     *
     * See HWC v2.2 (IComposerClient::PerFrameMetadataKey)
     * for more information.
     */
    struct HdrStaticMetadata {
       private:
        std::array<int32_t, 13> data;

       public:
        HdrStaticMetadata() = default;
        HdrStaticMetadata(const HdrStaticMetadata &other)
            : data(other.data), is_valid(other.is_valid) {}
        HdrStaticMetadata(const HdrStaticMetadata &&other) = delete;
        HdrStaticMetadata &operator=(const HdrStaticMetadata &other) {
            data = other.data;
            is_valid = other.is_valid;
            return *this;
        }
        HdrStaticMetadata &operator=(HdrStaticMetadata &&other) = delete;
        ~HdrStaticMetadata() = default;

        bool operator==(const HdrStaticMetadata &rhs) const {
            return data == rhs.data && is_valid == rhs.is_valid;
        }

        /// Indicator for whether the data in this struct should be used.
        bool is_valid = false;
        /// This device's display's peak luminance, in nits.
        int32_t &device_max_luminance = data[0];

        // Mastering display properties
        int32_t &display_red_primary_x = data[1];
        int32_t &display_red_primary_y = data[2];
        int32_t &display_green_primary_x = data[3];
        int32_t &display_green_primary_y = data[4];
        int32_t &display_blue_primary_x = data[5];
        int32_t &display_blue_primary_y = data[6];
        int32_t &white_point_x = data[7];
        int32_t &white_point_y = data[8];
        int32_t &max_luminance = data[9];
        int32_t &min_luminance = data[10];

        // Content properties
        int32_t &max_content_light_level = data[11];
        int32_t &max_frame_average_light_level = data[12];
    };

    /**
     * @brief HDR dynamic metadata.
     *
     * The members defined here are a subset of metadata define in
     * SMPTE ST 2094-40:2016.
     * Also see module videoapi information.
     */
    struct HdrDynamicMetadata {
        bool operator==(const HdrDynamicMetadata &rhs) const {
            return is_valid == rhs.is_valid &&
                   display_maximum_luminance == rhs.display_maximum_luminance &&
                   maxscl == rhs.maxscl &&
                   maxrgb_percentages == rhs.maxrgb_percentages &&
                   maxrgb_percentiles == rhs.maxrgb_percentiles &&
                   tm_flag == rhs.tm_flag && tm_knee_x == rhs.tm_knee_x &&
                   tm_knee_y == rhs.tm_knee_y &&
                   bezier_curve_anchors == rhs.bezier_curve_anchors;
        }

        /// Indicator for whether the data in this struct should be used.
        bool is_valid = false;

        uint32_t display_maximum_luminance;
        std::array<uint32_t, 3> maxscl;
        std::vector<uint8_t> maxrgb_percentages;
        std::vector<uint32_t> maxrgb_percentiles;
        uint16_t tm_flag;
        uint16_t tm_knee_x;
        uint16_t tm_knee_y;
        std::vector<uint16_t> bezier_curve_anchors;
    };

    /// This layer's dataspace (color gamut, transfer function, and range).
    hwc::Dataspace dataspace = hwc::Dataspace::UNKNOWN;
    /// Color transform for this layer. See SET_LAYER_COLOR_TRANSFORM HWC v2.3.
    // clang-format off
    std::array<float, 16> matrix {
        1.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0
    };
    // clang-format on
    /**
     * @brief This layer's HDR static metadata. Only applicable when dataspace
     * indicates this is an HDR layer.
     */
    HdrStaticMetadata static_metadata;
    /**
     * @brief This layer's HDR dynamic metadata. Only applicable when dataspace
     * indicates this is an HDR layer.
     */
    HdrDynamicMetadata dynamic_metadata;
};

/**
 * @brief DisplayScene holds all the information required for libdisplaycolor to
 * return correct data.
 */
struct DisplayScene {
    bool operator==(const DisplayScene &rhs) const {
        return layer_data == rhs.layer_data &&
               dpu_bit_depth == rhs.dpu_bit_depth &&
               color_mode == rhs.color_mode &&
               render_intent == rhs.render_intent &&
               matrix == rhs.matrix &&
               force_hdr == rhs.force_hdr &&
               bm == rhs.bm &&
               lhbm_on == rhs.lhbm_on &&
               (lhbm_on && dbv == rhs.dbv) &&
               refresh_rate == rhs.refresh_rate &&
               hdr_full_screen == rhs.hdr_full_screen;
    }

    /// A vector of layer color data.
    std::vector<LayerColorData> layer_data;
    /// The bit depth the DPU is currently outputting
    BitDepth dpu_bit_depth = BitDepth::kTen;
    /// The current ColorMode (typically set by SurfaceFlinger)
    hwc::ColorMode color_mode = hwc::ColorMode::NATIVE;
    /// The current RenderIntent (typically set by SurfaceFlinger)
    hwc::RenderIntent render_intent = hwc::RenderIntent::COLORIMETRIC;
    /// Color transform for this layer. See SET_COLOR_TRANSFORM HWC v2.1.
    // clang-format off
    std::array<float, 16> matrix {
        1.0, 0.0, 0.0, 0.0,
        0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0
    };
    // clang-format on
    /// When this bit is set, process hdr layers and the layer matrix even if
    //it's in native color mode.
    bool force_hdr;

    /// display brightness mode
    BrightnessMode bm;

    /// dbv level
    uint32_t dbv;

    /// lhbm status
    bool lhbm_on;

    /// refresh rate
    float refresh_rate;

    /// hdr full screen mode
    bool hdr_full_screen;
};

struct CalibrationInfo {
    bool factory_cal_loaded;
    bool golden_cal_loaded;
    bool common_cal_loaded;
    bool dev_cal_loaded;
};

/// An interface specifying functions that are HW-agnostic.
class IDisplayColorGeneric {
   public:
    /// A generic stage in the display pipeline.
    template <typename T>
    struct DisplayStage {
        using ConfigType = T;

        std::function<void(void)> data_applied_notifier = nullptr;
        void NotifyDataApplied() const {
            if (data_applied_notifier) {
                data_applied_notifier();
            }
        }

        bool enable = false;
        /// A flag indicating if the data has been changed in last Update call.
        // It should be set when enable is changed from false to true.
        bool dirty = false;

        const ConfigType *config = nullptr;
    };

    /// Interface for accessing data for panel
    class IPanel {
      public:
        /// Get the adjusted dbv for panel.
        virtual uint32_t GetAdjustedBrightnessLevel() const = 0;

        virtual ~IPanel() {}
    };

    virtual ~IDisplayColorGeneric() {}

    /**
     * @brief Update display color data. This function is expected to be called
     * in the context of HWC::validateDisplay, if the display scene has changed.
     *
     * @param display The display relating to the scene.
     * @param scene Display scene data to use during the update.
     * @return OK if successful, error otherwise.
     */
    virtual int Update(DisplayType display, const DisplayScene &scene) = 0;

    /**
     * @brief Update display color data. This function is expected to be called
     * in the context of HWC::presentDisplay, if the display scene has changed
     * since the Update call for HWC::validateDisplay.
     *
     * @param display The display relating to the scene.
     * @param scene Display scene data to use during the update.
     * @return OK if successful, error otherwise.
     */
    virtual int UpdatePresent(DisplayType display, const DisplayScene &scene) = 0;

    /**
     * @brief Check if refresh rate regamma compensation is enabled.
     *
     * @return true for yes.
     */
    virtual bool IsRrCompensationEnabled(DisplayType display) = 0;

    /**
     * @brief Get calibration information for each profiles.
     * @param display The display to get the calibration information.
     */
    virtual const CalibrationInfo &GetCalibrationInfo(
        DisplayType display) const = 0;

    /**
     * @brief Get a map of supported ColorModes, and supported RenderIntents for
     * each ColorMode.
     * @param display The display to get the color modes and render intents.
     */
    virtual const ColorModesMap &ColorModesAndRenderIntents(
        DisplayType display) const = 0;
};

extern "C" {
    const DisplayColorIntfVer *GetInterfaceVersion();
}

}  // namespace displaycolor

#endif  // DISPLAYCOLOR_H_
