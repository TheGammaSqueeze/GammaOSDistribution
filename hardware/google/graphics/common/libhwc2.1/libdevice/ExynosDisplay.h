/*
 * Copyright (C) 2012 The Android Open Source Project
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

#ifndef _EXYNOSDISPLAY_H
#define _EXYNOSDISPLAY_H

#include <android/hardware/graphics/composer/2.4/types.h>
#include <hardware/hwcomposer2.h>
#include <system/graphics.h>
#include <utils/KeyedVector.h>
#include <utils/Vector.h>

#include "ExynosDisplayInterface.h"
#include "ExynosHWC.h"
#include "ExynosHWCDebug.h"
#include "ExynosHWCHelper.h"
#include "ExynosMPP.h"
#include "ExynosResourceManager.h"
#include "worker.h"

#define HWC_CLEARDISPLAY_WITH_COLORMAP
#define HWC_PRINT_FRAME_NUM     10

#define LOW_FPS_THRESHOLD     5
#define MAX_BRIGHTNESS_LEN 5

using ::android::hardware::graphics::composer::V2_4::VsyncPeriodNanos;

#ifndef SECOND_DISPLAY_START_BIT
#define SECOND_DISPLAY_START_BIT   4
#endif

typedef hwc2_composition_t exynos_composition;

class ExynosLayer;
class ExynosDevice;
class ExynosMPP;
class ExynosMPPSource;

namespace aidl {
namespace google {
namespace hardware {
namespace power {
namespace extension {
namespace pixel {

class IPowerExt;

} // namespace pixel
} // namespace extension
} // namespace power
} // namespace hardware
} // namespace google
} // namespace aidl

enum dynamic_recomp_mode {
    NO_MODE_SWITCH,
    DEVICE_2_CLIENT,
    CLIENT_2_DEVICE
};

enum rendering_state {
    RENDERING_STATE_NONE = 0,
    RENDERING_STATE_VALIDATED,
    RENDERING_STATE_ACCEPTED_CHANGE,
    RENDERING_STATE_PRESENTED,
    RENDERING_STATE_MAX
};

enum composition_type {
    COMPOSITION_NONE = 0,
    COMPOSITION_CLIENT,
    COMPOSITION_EXYNOS,
    COMPOSITION_MAX
};

enum {
    PSR_NONE = 0,
    PSR_DP,
    PSR_MIPI,
    PSR_MAX,
};

enum {
    PANEL_LEGACY = 0,
    PANEL_DSC,
    PANEL_MIC,
};

enum {
    eDisplayNone     = 0x0,
    ePrimaryDisplay  = 0x00000001,
    eExternalDisplay = 0x00000002,
    eVirtualDisplay  = 0x00000004,
};

// served as extension of hwc2_power_mode_t for use with setPowerMode
enum class ext_hwc2_power_mode_t{
    PAUSE = 10,
    RESUME,
};

enum class PanelGammaSource {
    GAMMA_DEFAULT,     // Resotre gamma table to default
    GAMMA_CALIBRATION, // Update gamma table from calibration file
    GAMMA_TYPES,
};

enum class hwc_request_state_t {
    SET_CONFIG_STATE_NONE = 0,
    SET_CONFIG_STATE_PENDING,
    SET_CONFIG_STATE_REQUESTED,
};

#define NUM_SKIP_STATIC_LAYER  5
struct ExynosFrameInfo
{
    uint32_t srcNum;
    exynos_image srcInfo[NUM_SKIP_STATIC_LAYER];
    exynos_image dstInfo[NUM_SKIP_STATIC_LAYER];
};

struct exynos_readback_info
{
    buffer_handle_t handle = NULL;
    /* release sync fence file descriptor,
     * which will be signaled when it is safe to write to the output buffer.
     */
    int rel_fence = -1;
    /* acquire sync fence file descriptor which will signal when the
     * buffer provided to setReadbackBuffer has been filled by the device and is
     * safe for the client to read.
     */
    int acq_fence = -1;
    /* Requested from HWCService */
    bool requested_from_service = false;
};

struct exynos_win_config_data
{
    enum {
        WIN_STATE_DISABLED = 0,
        WIN_STATE_COLOR,
        WIN_STATE_BUFFER,
        WIN_STATE_UPDATE,
        WIN_STATE_CURSOR,
    } state = WIN_STATE_DISABLED;

    uint32_t color = 0;
    const ExynosLayer* layer = nullptr;
    uint64_t buffer_id = 0;
    int fd_idma[3] = {-1, -1, -1};
    int acq_fence = -1;
    int rel_fence = -1;
    float plane_alpha = 1;
    int32_t blending = HWC2_BLEND_MODE_NONE;
    ExynosMPP* assignedMPP = NULL;
    int format = 0;
    uint32_t transform = 0;
    android_dataspace dataspace = HAL_DATASPACE_UNKNOWN;
    bool hdr_enable = false;
    enum dpp_comp_src comp_src = DPP_COMP_SRC_NONE;
    uint32_t min_luminance = 0;
    uint32_t max_luminance = 0;
    struct decon_win_rect block_area = { 0, 0, 0, 0};
    struct decon_win_rect transparent_area = {0, 0, 0, 0};
    struct decon_win_rect opaque_area = {0, 0, 0, 0};
    struct decon_frame src = {0, 0, 0, 0, 0, 0};
    struct decon_frame dst = {0, 0, 0, 0, 0, 0};
    bool protection = false;
    bool compression = false;
    bool needColorTransform = false;

    void reset(){
        *this = {};
    };
};
struct exynos_dpu_data
{
    int retire_fence = -1;
    std::vector<exynos_win_config_data> configs;
    bool enable_win_update = false;
    std::atomic<bool> enable_readback = false;
    struct decon_frame win_update_region = {0, 0, 0, 0, 0, 0};
    struct exynos_readback_info readback_info;

    void init(uint32_t configNum) {
        for(uint32_t i = 0; i < configNum; i++)
        {
            exynos_win_config_data config_data;
            configs.push_back(config_data);
        }
    };

    void reset() {
        retire_fence = -1;
        for (uint32_t i = 0; i < configs.size(); i++)
            configs[i].reset();

        /*
         * Should not initialize readback_info
         * readback_info should be initialized after present
         */
    };
    exynos_dpu_data& operator =(const exynos_dpu_data &configs_data){
        retire_fence = configs_data.retire_fence;
        if (configs.size() != configs_data.configs.size()) {
            HWC_LOGE(NULL, "invalid config, it has different configs size");
            return *this;
        }
        configs = configs_data.configs;
        return *this;
    };
};

class ExynosLowFpsLayerInfo
{
    public:
        ExynosLowFpsLayerInfo();
        bool mHasLowFpsLayer;
        int32_t mFirstIndex;
        int32_t mLastIndex;

        void initializeInfos();
        int32_t addLowFpsLayer(uint32_t layerIndex);
};

class ExynosSortedLayer : public Vector <ExynosLayer*>
{
    public:
        ssize_t remove(const ExynosLayer *item);
        status_t vector_sort();
        static int compare(ExynosLayer * const *lhs, ExynosLayer *const *rhs);
};

class ExynosCompositionInfo : public ExynosMPPSource {
    public:
        ExynosCompositionInfo():ExynosCompositionInfo(COMPOSITION_NONE){};
        ExynosCompositionInfo(uint32_t type);
        uint32_t mType;
        bool mHasCompositionLayer;
        int32_t mFirstIndex;
        int32_t mLastIndex;
        buffer_handle_t mTargetBuffer;
        android_dataspace mDataSpace;
        int32_t mAcquireFence;
        int32_t mReleaseFence;
        bool mEnableSkipStatic;
        bool mSkipStaticInitFlag;
        bool mSkipFlag;
        ExynosFrameInfo mSkipSrcInfo;
        exynos_win_config_data mLastWinConfigData;

        int32_t mWindowIndex;
        bool mCompressed;

        void initializeInfos(ExynosDisplay *display);
        void setTargetBuffer(ExynosDisplay *display, buffer_handle_t handle,
                int32_t acquireFence, android_dataspace dataspace);
        void setCompressed(bool compressed);
        bool getCompressed();
        void dump(String8& result);
        String8 getTypeStr();
};

// Prepare multi-resolution
struct ResolutionSize {
    uint32_t w;
    uint32_t h;
};

struct ResolutionInfo {
    uint32_t nNum;
    ResolutionSize nResolution[3];
    uint32_t nDSCYSliceSize[3];
    uint32_t nDSCXSliceSize[3];
    int      nPanelType[3];
};

typedef struct displayConfigs {
    // HWC2_ATTRIBUTE_VSYNC_PERIOD
    VsyncPeriodNanos vsyncPeriod;
    // HWC2_ATTRIBUTE_WIDTH
    uint32_t width;
    // case HWC2_ATTRIBUTE_HEIGHT
    uint32_t height;
    // HWC2_ATTRIBUTE_DPI_X
    uint32_t Xdpi;
    // HWC2_ATTRIBUTE_DPI_Y
    uint32_t Ydpi;
    // HWC2_ATTRIBUTE_CONFIG_GROUP
    uint32_t groupId;
} displayConfigs_t;

struct DisplayControl {
    /** Composition crop en/disable **/
    bool enableCompositionCrop;
    /** Resource assignment optimization for exynos composition **/
    bool enableExynosCompositionOptimization;
    /** Resource assignment optimization for client composition **/
    bool enableClientCompositionOptimization;
    /** Use G2D as much as possible **/
    bool useMaxG2DSrc;
    /** Low fps layer optimization **/
    bool handleLowFpsLayers;
    /** start m2mMPP before persentDisplay **/
    bool earlyStartMPP;
    /** Adjust display size of the layer having high priority */
    bool adjustDisplayFrame;
    /** setCursorPosition support **/
    bool cursorSupport;
    /** readback support **/
    bool readbackSupport = false;
    /** Reserve MPP regardless of plug state **/
    bool forceReserveMPP = false;
    /** Skip M2MMPP processing **/
    bool skipM2mProcessing = true;
};

typedef struct brightnessState {
    enum MipiSyncType {
        MIPI_SYNC_NONE,
        MIPI_SYNC_GHBM_ON,
        MIPI_SYNC_GHBM_OFF,
        MIPI_SYNC_LHBM_ON,
        MIPI_SYNC_LHBM_OFF,
    };
    static constexpr size_t kNumofBrightnessState = 3;
    static constexpr float kSdrDimRatioNone = 1.0;
    union {
        std::array<bool, kNumofBrightnessState> mData;
        struct {
            bool instant_hbm;
            bool peak_hbm;
            bool local_hbm;
        };
    };
    /** dim ratio calculated from current layer stack but will be delayed to apply **/
    float dim_sdr_target_ratio = kSdrDimRatioNone;
    /** dim ratio to apply to current frame and is 'dim_delay' frames behind
     * dim_sdr_target_ratio **/
    float dim_sdr_ratio = kSdrDimRatioNone;

    // current Brightness value
    float brightness_value;

    // HDR layer is covering most of the screen
    bool hdr_full_screen;

    bool enhanced_hbm;

    void reset() {
        mData = {false, false, false};
        dim_sdr_target_ratio = kSdrDimRatioNone;
        hdr_full_screen = false;
    }
    bool dimSdrTransition() {
        return dim_sdr_target_ratio != dim_sdr_ratio &&
            (dim_sdr_target_ratio == kSdrDimRatioNone || dim_sdr_ratio == kSdrDimRatioNone);
    }
    brightnessState& operator=(const brightnessState& a) {
        mData = a.mData;
        dim_sdr_target_ratio = a.dim_sdr_target_ratio;
        dim_sdr_ratio = a.dim_sdr_ratio;
        brightness_value = a.brightness_value;
        enhanced_hbm = a.enhanced_hbm;
        return *this;
    }
    // TODO: add hdr_full_screen comparison
    bool operator==(const brightnessState& a) const {
        return a.mData == mData && a.dim_sdr_ratio == dim_sdr_ratio &&
                a.dim_sdr_target_ratio == dim_sdr_target_ratio &&
                a.brightness_value == brightness_value && a.enhanced_hbm == enhanced_hbm;
    }
} brightnessState_t;

class ExynosDisplay {
    public:
        uint32_t mDisplayId;
        uint32_t mType;
        uint32_t mIndex;
        String8 mDeconNodeName;
        uint32_t mXres;
        uint32_t mYres;
        uint32_t mXdpi;
        uint32_t mYdpi;
        uint32_t mVsyncPeriod;
        uint32_t mBtsVsyncPeriod;

        int                     mPanelType;
        int                     mPsrMode;

        /* Constructor */
        ExynosDisplay(uint32_t index, ExynosDevice *device);
        /* Destructor */
        virtual ~ExynosDisplay();

        ExynosDevice *mDevice;

        String8 mDisplayName;

        Mutex mDisplayMutex;

        /** State variables */
        bool mPlugState;
        hwc2_power_mode_t mPowerModeState;
        hwc2_vsync_t mVsyncState;
        bool mHasSingleBuffer;
        bool mPauseDisplay = false;

        DisplayControl mDisplayControl;

        /**
         * TODO : Should be defined as ExynosLayer type
         * Layer list those sorted by z-order
         */
        ExynosSortedLayer mLayers;
        std::vector<ExynosLayer*> mIgnoreLayers;

        ExynosResourceManager *mResourceManager;

        /**
         * Layer index, target buffer information for GLES.
         */
        ExynosCompositionInfo mClientCompositionInfo;

        /**
         * Layer index, target buffer information for G2D.
         */
        ExynosCompositionInfo mExynosCompositionInfo;

        /**
         * Geometry change info is described by bit map.
         * This flag is cleared when resource assignment for all displays
         * is done.
         */
        uint64_t  mGeometryChanged;

        /**
         * Rendering step information that is seperated by
         * VALIDATED, ACCEPTED_CHANGE, PRESENTED.
         */
        rendering_state  mRenderingState;

        /**
         * Rendering step information that is called by client
         */
        rendering_state  mHWCRenderingState;

        /**
         * Window total bandwidth by enabled window, It's used as dynamic re-composition enable/disable.
         */
        uint32_t  mDisplayBW;

        /**
         * Mode information Dynamic re-composition feature.
         * DEVICE_2_CLIENT: All layers are composited by GLES composition.
         * CLIENT_2_DEVICE: Device composition.
         */
        dynamic_recomp_mode mDynamicReCompMode;
        bool mDREnable;
        bool mDRDefault;
        Mutex mDRMutex;

        nsecs_t  mLastFpsTime;
        uint64_t mFrameCount;
        uint64_t mLastFrameCount;
        uint64_t mErrorFrameCount;
        uint64_t mLastModeSwitchTimeStamp;
        uint64_t mLastUpdateTimeStamp;
        uint64_t mUpdateEventCnt;
        uint64_t mUpdateCallCnt;

        /* default DMA for the display */
        decon_idma_type mDefaultDMA;

        /**
         * DECON WIN_CONFIG information.
         */
        exynos_dpu_data mDpuData;

        /**
         * Last win_config data is used as WIN_CONFIG skip decision or debugging.
         */
        exynos_dpu_data mLastDpuData;

        /**
         * Restore release fenc from DECON.
         */
        int mLastRetireFence;

        bool mUseDpu;

        /**
         * Max Window number, It should be set by display module(chip)
         */
        uint32_t mMaxWindowNum;
        uint32_t mWindowNumUsed;
        uint32_t mBaseWindowIndex;

        // Priority
        uint32_t mNumMaxPriorityAllowed;
        int32_t mCursorIndex;

        int32_t mColorTransformHint;

        ExynosLowFpsLayerInfo mLowFpsLayerInfo;

        // HDR capabilities
        std::vector<int32_t> mHdrTypes;
        float mMaxLuminance;
        float mMaxAverageLuminance;
        float mMinLuminance;

        /* For debugging */
        hwc_display_contents_1_t *mHWC1LayerList;

        /* Support Multi-resolution scheme */
        int mOldScalerMode;
        int mNewScaledWidth;
        int mNewScaledHeight;
        int32_t mDeviceXres;
        int32_t mDeviceYres;
        ResolutionInfo mResolutionInfo;
        std::map<uint32_t, displayConfigs_t> mDisplayConfigs;

        // WCG
        android_color_mode_t mColorMode;

        // Skip present frame if there was no validate after power on
        bool mSkipFrame;

        FILE *mBrightnessFd;
        FILE *mEarlyWakeupFd;
        uint32_t mMaxBrightness;

        hwc_vsync_period_change_constraints_t mVsyncPeriodChangeConstraints;
        hwc_vsync_period_change_timeline_t mVsyncAppliedTimeLine;
        hwc_request_state_t mConfigRequestState;
        hwc2_config_t mDesiredConfig;

        hwc2_config_t mActiveConfig = UINT_MAX;

        void initDisplay();

        int getId();
        Mutex& getDisplayMutex() {return mDisplayMutex; };

        int32_t setCompositionTargetExynosImage(uint32_t targetType, exynos_image *src_img, exynos_image *dst_img);
        int32_t initializeValidateInfos();
        int32_t addClientCompositionLayer(uint32_t layerIndex);
        int32_t removeClientCompositionLayer(uint32_t layerIndex);
        int32_t addExynosCompositionLayer(uint32_t layerIndex);

        /**
         * Dynamic AFBC Control solution : To get the prepared information is applied to current or not.
         */
        bool comparePreferedLayers();

        /**
         * @param *outLayer
         */
        int32_t destroyLayer(hwc2_layer_t outLayer);

        void destroyLayers();

        ExynosLayer *checkLayer(hwc2_layer_t addr);

        void checkIgnoreLayers();
        virtual void doPreProcessing();

        int checkLayerFps();

        int checkDynamicReCompMode();

        int handleDynamicReCompMode();

        void updateBrightnessState();

        /**
         * @param compositionType
         */
        int skipStaticLayers(ExynosCompositionInfo& compositionInfo);
        int handleStaticLayers(ExynosCompositionInfo& compositionInfo);

        int doPostProcessing();

        int doExynosComposition();

        int32_t configureOverlay(ExynosLayer *layer, exynos_win_config_data &cfg);
        int32_t configureOverlay(ExynosCompositionInfo &compositionInfo);

        int32_t configureHandle(ExynosLayer &layer,  int fence_fd, exynos_win_config_data &cfg);

        virtual int setWinConfigData();

        virtual int setDisplayWinConfigData();

        virtual int32_t validateWinConfigData();

        virtual int deliverWinConfigData();

        virtual int setReleaseFences();

        virtual bool checkFrameValidation();

        /**
         * Display Functions for HWC 2.0
         */

        /**
         * Descriptor: HWC2_FUNCTION_ACCEPT_DISPLAY_CHANGES
         * HWC2_PFN_ACCEPT_DISPLAY_CHANGES
         **/
        virtual int32_t acceptDisplayChanges();

        /**
         * Descriptor: HWC2_FUNCTION_CREATE_LAYER
         * HWC2_PFN_CREATE_LAYER
         */
        virtual int32_t createLayer(hwc2_layer_t* outLayer);

        /**
         * Descriptor: HWC2_FUNCTION_GET_ACTIVE_CONFIG
         * HWC2_PFN_GET_ACTIVE_CONFIG
         */
        virtual int32_t getActiveConfig(hwc2_config_t* outConfig);

        /**
         * Descriptor: HWC2_FUNCTION_GET_CHANGED_COMPOSITION_TYPES
         * HWC2_PFN_GET_CHANGED_COMPOSITION_TYPES
         */
        virtual int32_t getChangedCompositionTypes(
                uint32_t* outNumElements, hwc2_layer_t* outLayers,
                int32_t* /*hwc2_composition_t*/ outTypes);

        /**
         * Descriptor: HWC2_FUNCTION_GET_CLIENT_TARGET_SUPPORT
         * HWC2_PFN_GET_CLIENT_TARGET_SUPPORT
         */
        virtual int32_t getClientTargetSupport(
                uint32_t width, uint32_t height,
                int32_t /*android_pixel_format_t*/ format,
                int32_t /*android_dataspace_t*/ dataspace);

        /**
         * Descriptor: HWC2_FUNCTION_GET_COLOR_MODES
         * HWC2_PFN_GET_COLOR_MODES
         */
        virtual int32_t getColorModes(
                uint32_t* outNumModes,
                int32_t* /*android_color_mode_t*/ outModes);

        /* getDisplayAttribute(..., config, attribute, outValue)
         * Descriptor: HWC2_FUNCTION_GET_DISPLAY_ATTRIBUTE
         * HWC2_PFN_GET_DISPLAY_ATTRIBUTE
         */
        virtual int32_t getDisplayAttribute(
                hwc2_config_t config,
                int32_t /*hwc2_attribute_t*/ attribute, int32_t* outValue);

        /* getDisplayConfigs(..., outNumConfigs, outConfigs)
         * Descriptor: HWC2_FUNCTION_GET_DISPLAY_CONFIGS
         * HWC2_PFN_GET_DISPLAY_CONFIGS
         */
        virtual int32_t getDisplayConfigs(
                uint32_t* outNumConfigs,
                hwc2_config_t* outConfigs);

        /* getDisplayName(..., outSize, outName)
         * Descriptor: HWC2_FUNCTION_GET_DISPLAY_NAME
         * HWC2_PFN_GET_DISPLAY_NAME
         */
        virtual int32_t getDisplayName(uint32_t* outSize, char* outName);

        /* getDisplayRequests(..., outDisplayRequests, outNumElements, outLayers,
         *     outLayerRequests)
         * Descriptor: HWC2_FUNCTION_GET_DISPLAY_REQUESTS
         * HWC2_PFN_GET_DISPLAY_REQUESTS
         */
        virtual int32_t getDisplayRequests(
                int32_t* /*hwc2_display_request_t*/ outDisplayRequests,
                uint32_t* outNumElements, hwc2_layer_t* outLayers,
                int32_t* /*hwc2_layer_request_t*/ outLayerRequests);

        /* getDisplayType(..., outType)
         * Descriptor: HWC2_FUNCTION_GET_DISPLAY_TYPE
         * HWC2_PFN_GET_DISPLAY_TYPE
         */
        virtual int32_t getDisplayType(
                int32_t* /*hwc2_display_type_t*/ outType);
        /* getDozeSupport(..., outSupport)
         * Descriptor: HWC2_FUNCTION_GET_DOZE_SUPPORT
         * HWC2_PFN_GET_DOZE_SUPPORT
         */
        virtual int32_t getDozeSupport(int32_t* outSupport);

        /* getReleaseFences(..., outNumElements, outLayers, outFences)
         * Descriptor: HWC2_FUNCTION_GET_RELEASE_FENCES
         * HWC2_PFN_GET_RELEASE_FENCES
         */
        virtual int32_t getReleaseFences(
                uint32_t* outNumElements,
                hwc2_layer_t* outLayers, int32_t* outFences);

        enum {
            SKIP_ERR_NONE = 0,
            SKIP_ERR_CONFIG_DISABLED,
            SKIP_ERR_FIRST_FRAME,
            SKIP_ERR_GEOMETRY_CHAGNED,
            SKIP_ERR_HAS_CLIENT_COMP,
            SKIP_ERR_SKIP_STATIC_CHANGED,
            SKIP_ERR_HAS_REQUEST,
            SKIP_ERR_DISP_NOT_CONNECTED,
            SKIP_ERR_DISP_NOT_POWER_ON,
            SKIP_ERR_FORCE_VALIDATE,
            SKIP_ERR_INVALID_CLIENT_TARGET_BUFFER
        };
        virtual int32_t canSkipValidate();

        /* presentDisplay(..., outRetireFence)
         * Descriptor: HWC2_FUNCTION_PRESENT_DISPLAY
         * HWC2_PFN_PRESENT_DISPLAY
         */
        virtual int32_t presentDisplay(int32_t* outRetireFence);
        virtual int32_t presentPostProcessing();

        /* setActiveConfig(..., config)
         * Descriptor: HWC2_FUNCTION_SET_ACTIVE_CONFIG
         * HWC2_PFN_SET_ACTIVE_CONFIG
         */
        virtual int32_t setActiveConfig(hwc2_config_t config);

        /* setClientTarget(..., target, acquireFence, dataspace)
         * Descriptor: HWC2_FUNCTION_SET_CLIENT_TARGET
         * HWC2_PFN_SET_CLIENT_TARGET
         */
        virtual int32_t setClientTarget(
                buffer_handle_t target,
                int32_t acquireFence, int32_t /*android_dataspace_t*/ dataspace);

        /* setColorTransform(..., matrix, hint)
         * Descriptor: HWC2_FUNCTION_SET_COLOR_TRANSFORM
         * HWC2_PFN_SET_COLOR_TRANSFORM
         */
        virtual int32_t setColorTransform(
                const float* matrix,
                int32_t /*android_color_transform_t*/ hint);

        /* setColorMode(..., mode)
         * Descriptor: HWC2_FUNCTION_SET_COLOR_MODE
         * HWC2_PFN_SET_COLOR_MODE
         */
        virtual int32_t setColorMode(
                int32_t /*android_color_mode_t*/ mode);

        /* setOutputBuffer(..., buffer, releaseFence)
         * Descriptor: HWC2_FUNCTION_SET_OUTPUT_BUFFER
         * HWC2_PFN_SET_OUTPUT_BUFFER
         */
        virtual int32_t setOutputBuffer(
                buffer_handle_t buffer,
                int32_t releaseFence);

        virtual int clearDisplay(bool needModeClear = false);

        /* setPowerMode(..., mode)
         * Descriptor: HWC2_FUNCTION_SET_POWER_MODE
         * HWC2_PFN_SET_POWER_MODE
         */
        virtual int32_t setPowerMode(
                int32_t /*hwc2_power_mode_t*/ mode);

        /* setVsyncEnabled(..., enabled)
         * Descriptor: HWC2_FUNCTION_SET_VSYNC_ENABLED
         * HWC2_PFN_SET_VSYNC_ENABLED
         */
        virtual int32_t setVsyncEnabled(
                int32_t /*hwc2_vsync_t*/ enabled);
        int32_t setVsyncEnabledInternal(
                int32_t /*hwc2_vsync_t*/ enabled);

        /* validateDisplay(..., outNumTypes, outNumRequests)
         * Descriptor: HWC2_FUNCTION_VALIDATE_DISPLAY
         * HWC2_PFN_VALIDATE_DISPLAY
         */
        virtual int32_t validateDisplay(
                uint32_t* outNumTypes, uint32_t* outNumRequests);

        /* getHdrCapabilities(..., outNumTypes, outTypes, outMaxLuminance,
         *     outMaxAverageLuminance, outMinLuminance)
         * Descriptor: HWC2_FUNCTION_GET_HDR_CAPABILITIES
         */
        virtual int32_t getHdrCapabilities(uint32_t* outNumTypes, int32_t* /*android_hdr_t*/ outTypes, float* outMaxLuminance,
                float* outMaxAverageLuminance, float* outMinLuminance);

        virtual int32_t getRenderIntents(int32_t mode, uint32_t* outNumIntents,
                int32_t* /*android_render_intent_v1_1_t*/ outIntents);
        virtual int32_t setColorModeWithRenderIntent(int32_t /*android_color_mode_t*/ mode,
                int32_t /*android_render_intent_v1_1_t */ intent);

        /* HWC 2.3 APIs */

        /* getDisplayIdentificationData(..., outPort, outDataSize, outData)
         * Descriptor: HWC2_FUNCTION_GET_DISPLAY_IDENTIFICATION_DATA
         * Parameters:
         *   outPort - the connector to which the display is connected;
         *             pointer will be non-NULL
         *   outDataSize - if outData is NULL, the size in bytes of the data which would
         *       have been returned; if outData is not NULL, the size of outData, which
         *       must not exceed the value stored in outDataSize prior to the call;
         *       pointer will be non-NULL
         *   outData - the EDID 1.3 blob identifying the display
         *
         * Returns HWC2_ERROR_NONE or one of the following errors:
         *   HWC2_ERROR_BAD_DISPLAY - an invalid display handle was passed in
         */
        int32_t getDisplayIdentificationData(uint8_t* outPort,
                uint32_t* outDataSize, uint8_t* outData);

        /* getDisplayCapabilities(..., outCapabilities)
         * Descriptor: HWC2_FUNCTION_GET_DISPLAY_CAPABILITIES
         * Parameters:
         *   outNumCapabilities - if outCapabilities was nullptr, returns the number of capabilities
         *       if outCapabilities was not nullptr, returns the number of capabilities stored in
         *       outCapabilities, which must not exceed the value stored in outNumCapabilities prior
         *       to the call; pointer will be non-NULL
         *   outCapabilities - a list of supported capabilities.
         *
         * Returns HWC2_ERROR_NONE or one of the following errors:
         *   HWC2_ERROR_BAD_DISPLAY - an invalid display handle was passed in
         */
        /* Capabilities
           Invalid = HWC2_CAPABILITY_INVALID,
           SidebandStream = HWC2_CAPABILITY_SIDEBAND_STREAM,
           SkipClientColorTransform = HWC2_CAPABILITY_SKIP_CLIENT_COLOR_TRANSFORM,
           PresentFenceIsNotReliable = HWC2_CAPABILITY_PRESENT_FENCE_IS_NOT_RELIABLE,
           SkipValidate = HWC2_CAPABILITY_SKIP_VALIDATE,
        */
        int32_t getDisplayCapabilities(uint32_t* outNumCapabilities,
                uint32_t* outCapabilities);

        /* getDisplayBrightnessSupport(displayToken)
         * Descriptor: HWC2_FUNCTION_GET_DISPLAY_BRIGHTNESS_SUPPORT
         * Parameters:
         *   outSupport - whether the display supports operations.
         *
         * Returns HWC2_ERROR_NONE or one of the following errors:
         *   HWC2_ERROR_BAD_DISPLAY when the display is invalid.
         */
        int32_t getDisplayBrightnessSupport(bool* outSupport);

        /* setDisplayBrightness(displayToken, brightnesss)
         * Descriptor: HWC2_FUNCTION_SET_DISPLAY_BRIGHTNESS
         * Parameters:
         *   brightness - a number between 0.0f (minimum brightness) and 1.0f (maximum brightness), or
         *          -1.0f to turn the backlight off.
         *
         * Returns HWC2_ERROR_NONE or one of the following errors:
         *   HWC2_ERROR_BAD_DISPLAY   when the display is invalid, or
         *   HWC2_ERROR_UNSUPPORTED   when brightness operations are not supported, or
         *   HWC2_ERROR_BAD_PARAMETER when the brightness is invalid, or
         *   HWC2_ERROR_NO_RESOURCES  when the brightness cannot be applied.
         */
        virtual int32_t setDisplayBrightness(float brightness);

        /* getDisplayConnectionType(..., outType)
         * Descriptor: HWC2_FUNCTION_GET_DISPLAY_CONNECTION_TYPE
         * Optional for all HWC2 devices
         *
         * Returns whether the given physical display is internal or external.
         *
         * Parameters:
         * outType - the connection type of the display; pointer will be non-NULL
         *
         * Returns HWC2_ERROR_NONE or one of the following errors:
         * HWC2_ERROR_BAD_DISPLAY when the display is invalid or virtual.
         */
        int32_t getDisplayConnectionType(uint32_t* outType);

        /* getDisplayVsyncPeriod(..., outVsyncPeriods)
         * Descriptor: HWC2_FUNCTION_GET_DISPLAY_VSYNC_PERIOD
         * Required for HWC2 devices for composer 2.4
         *
         * Retrieves which vsync period the display is currently using.
         *
         * If no display configuration is currently active, this function must
         * return BAD_CONFIG. If a vsync period is about to change due to a
         * setActiveConfigWithConstraints call, this function must return the current vsync period
         * until the change has taken place.
         *
         * Parameters:
         *     outVsyncPeriod - the current vsync period of the display.
         *
         * Returns HWC2_ERROR_NONE or one of the following errors:
         *   HWC2_ERROR_BAD_DISPLAY - an invalid display handle was passed in
         *   HWC2_ERROR_BAD_CONFIG - no configuration is currently active
         */
        int32_t getDisplayVsyncPeriod(hwc2_vsync_period_t* __unused outVsyncPeriod);

        /* setActiveConfigWithConstraints(...,
         *                                config,
         *                                vsyncPeriodChangeConstraints,
         *                                outTimeline)
         * Descriptor: HWC2_FUNCTION_SET_ACTIVE_CONFIG_WITH_CONSTRAINTS
         * Required for HWC2 devices for composer 2.4
         *
         * Sets the active configuration and the refresh rate for this display.
         * If the new config shares the same config group as the current config,
         * only the vsync period shall change.
         * Upon returning, the given display configuration, except vsync period, must be active and
         * remain so until either this function is called again or the display is disconnected.
         * When the display starts to refresh at the new vsync period, onVsync_2_4 callback must be
         * called with the new vsync period.
         *
         * Parameters:
         *     config - the new display configuration.
         *     vsyncPeriodChangeConstraints - constraints required for changing vsync period:
         *                                    desiredTimeNanos - the time in CLOCK_MONOTONIC after
         *                                                       which the vsync period may change
         *                                                       (i.e., the vsync period must not change
         *                                                       before this time).
         *                                    seamlessRequired - if true, requires that the vsync period
         *                                                       change must happen seamlessly without
         *                                                       a noticeable visual artifact.
         *                                                       When the conditions change and it may be
         *                                                       possible to change the vsync period
         *                                                       seamlessly, HWC2_CALLBACK_SEAMLESS_POSSIBLE
         *                                                       callback must be called to indicate that
         *                                                       caller should retry.
         *     outTimeline - the timeline for the vsync period change.
         *
         * Returns HWC2_ERROR_NONE or one of the following errors:
         *   HWC2_ERROR_BAD_DISPLAY - an invalid display handle was passed in.
         *   HWC2_ERROR_BAD_CONFIG - an invalid configuration handle passed in.
         *   HWC2_ERROR_SEAMLESS_NOT_ALLOWED - when seamlessRequired was true but config provided doesn't
         *                                 share the same config group as the current config.
         *   HWC2_ERROR_SEAMLESS_NOT_POSSIBLE - when seamlessRequired was true but the display cannot
         *                                      achieve the vsync period change without a noticeable
         *                                      visual artifact.
         */
        int32_t setActiveConfigWithConstraints(hwc2_config_t __unused config,
                hwc_vsync_period_change_constraints_t* __unused vsyncPeriodChangeConstraints,
                hwc_vsync_period_change_timeline_t* __unused outTimeline);

        /* setAutoLowLatencyMode(displayToken, on)
         * Descriptor: HWC2_FUNCTION_SET_AUTO_LOW_LATENCY_MODE
         * Optional for HWC2 devices
         *
         * setAutoLowLatencyMode requests that the display goes into low latency mode. If the display
         * is connected via HDMI 2.1, then Auto Low Latency Mode should be triggered. If the display is
         * internally connected, then a custom low latency mode should be triggered (if available).
         *
         * Parameters:
         *   on - indicates whether to turn low latency mode on (=true) or off (=false)
         *
         * Returns HWC2_ERROR_NONE or one of the following errors:
         *   HWC2_ERROR_BAD_DISPLAY - when the display is invalid, or
         *   HWC2_ERROR_UNSUPPORTED - when the display does not support any low latency mode
         */
        int32_t setAutoLowLatencyMode(bool __unused on);

        /* getSupportedContentTypes(..., outSupportedContentTypes)
         * Descriptor: HWC2_FUNCTION_GET_SUPPORTED_CONTENT_TYPES
         * Optional for HWC2 devices
         *
         * getSupportedContentTypes returns a list of supported content types
         * (as described in the definition of ContentType above).
         * This list must not change after initialization.
         *
         * Parameters:
         *   outNumSupportedContentTypes - if outSupportedContentTypes was nullptr, returns the number
         *       of supported content types; if outSupportedContentTypes was not nullptr, returns the
         *       number of capabilities stored in outSupportedContentTypes, which must not exceed the
         *       value stored in outNumSupportedContentTypes prior to the call; pointer will be non-NULL
         *   outSupportedContentTypes - a list of supported content types.
         *
         * Returns HWC2_ERROR_NONE or one of the following errors:
         *   HWC2_ERROR_BAD_DISPLAY - an invalid display handle was passed in
         */
        int32_t getSupportedContentTypes(uint32_t* __unused outNumSupportedContentTypes,
                uint32_t* __unused outSupportedContentTypes);

        /* setContentType(displayToken, contentType)
         * Descriptor: HWC2_FUNCTION_SET_CONTENT_TYPE
         * Optional for HWC2 devices
         *
         * setContentType instructs the display that the content being shown is of the given contentType
         * (one of GRAPHICS, PHOTO, CINEMA, GAME).
         *
         * According to the HDMI 1.4 specification, supporting all content types is optional. Whether
         * the display supports a given content type is reported by getSupportedContentTypes.
         *
         * Parameters:
         *   contentType - the type of content that is currently being shown on the display
         *
         * Returns HWC2_ERROR_NONE or one of the following errors:
         *   HWC2_ERROR_BAD_DISPLAY - when the display is invalid, or
         *   HWC2_ERROR_UNSUPPORTED - when the given content type is a valid content type, but is not
         *                            supported on this display, or
         *   HWC2_ERROR_BAD_PARAMETER - when the given content type is invalid
         */
        int32_t setContentType(int32_t /* hwc2_content_type_t */ __unused contentType);

        /* getClientTargetProperty(..., outClientTargetProperty)
         * Descriptor: HWC2_FUNCTION_GET_CLIENT_TARGET_PROPERTY
         * Optional for HWC2 devices
         *
         * Retrieves the client target properties for which the hardware composer
         * requests after the last call to validateDisplay. The client must set the
         * properties of the client target to match the returned values.
         * When this API is implemented, if client composition is needed, the hardware
         * composer must return meaningful client target property with dataspace not
         * setting to UNKNOWN.
         * When the returned dataspace is set to UNKNOWN, it means hardware composer
         * requests nothing, the client must ignore the returned client target property
         * structrue.
         *
         * Parameters:
         *   outClientTargetProperty - the client target properties that hardware
         *       composer requests. If dataspace field is set to UNKNOWN, it means
         *       the hardware composer requests nothing, the client must ignore the
         *       returned client target property structure.
         *
         * Returns HWC2_ERROR_NONE or one of the following errors:
         *   HWC2_ERROR_BAD_DISPLAY - an invalid display handle was passed in
         *   HWC2_ERROR_NOT_VALIDATED - validateDisplay has not been called for this
         *       display
         */
        int32_t getClientTargetProperty(hwc_client_target_property_t* outClientTargetProperty);

        /* setActiveConfig MISCs */
        bool isBadConfig(hwc2_config_t config);
        bool needNotChangeConfig(hwc2_config_t config);
        int32_t updateInternalDisplayConfigVariables(
                hwc2_config_t config, bool updateVsync = true);
        int32_t resetConfigRequestStateLocked();
        int32_t updateConfigRequestAppliedTime();
        int32_t updateVsyncAppliedTimeLine(int64_t actualChangeTime);
        int32_t getDisplayVsyncPeriodInternal(
                hwc2_vsync_period_t* outVsyncPeriod);
        virtual int32_t doDisplayConfigInternal(hwc2_config_t config);
        int32_t doDisplayConfigPostProcess(ExynosDevice *dev);
        int32_t getConfigAppliedTime(const uint64_t desiredTime,
                const uint64_t actualChangeTime,
                int64_t &appliedTime, int64_t &refreshTime);
        void updateBtsVsyncPeriod(uint32_t vsyncPeriod, bool forceUpdate = false);
        uint32_t getBtsRefreshRate() const;

        /* TODO : TBD */
        int32_t setCursorPositionAsync(uint32_t x_pos, uint32_t y_pos);

        int32_t getReadbackBufferAttributes(int32_t* /*android_pixel_format_t*/ outFormat,
                int32_t* /*android_dataspace_t*/ outDataspace);
        int32_t setReadbackBuffer(buffer_handle_t buffer, int32_t releaseFence, bool requestedService = false);
        void setReadbackBufferInternal(buffer_handle_t buffer, int32_t releaseFence, bool requestedService = false);
        int32_t getReadbackBufferFence(int32_t* outFence);
        /* This function is called by ExynosDisplayInterface class to set acquire fence*/
        int32_t setReadbackBufferAcqFence(int32_t acqFence);

        virtual void dump(String8& result);

        virtual int32_t startPostProcessing();

        void dumpConfig(const exynos_win_config_data &c);
        void dumpConfig(String8 &result, const exynos_win_config_data &c);
        void printConfig(exynos_win_config_data &c);

        unsigned int getLayerRegion(ExynosLayer *layer,
                hwc_rect *rect_area, uint32_t regionType);

        int handleWindowUpdate();
        bool windowUpdateExceptions();

        /* For debugging */
        void setHWC1LayerList(hwc_display_contents_1_t *contents) {mHWC1LayerList = contents;};
        void traceLayerTypes();

        bool validateExynosCompositionLayer();
        void printDebugInfos(String8 &reason);

        bool checkConfigChanged(const exynos_dpu_data &lastConfigsData,
                const exynos_dpu_data &newConfigsData);
        int checkConfigDstChanged(const exynos_dpu_data &lastConfigData,
                const exynos_dpu_data &newConfigData, uint32_t index);

        uint32_t getRestrictionIndex(int halFormat);
        void closeFences();
        void closeFencesForSkipFrame(rendering_state renderingState);

        int32_t getLayerCompositionTypeForValidationType(uint32_t layerIndex);
        void setHWCControl(uint32_t ctrl, int32_t val);
        void setGeometryChanged(uint64_t changedBit);
        void clearGeometryChanged();

        virtual void setDDIScalerEnable(int width, int height);
        virtual int getDDIScalerMode(int width, int height);
        void increaseMPPDstBufIndex();
        virtual void initDisplayInterface(uint32_t interfaceType);
        virtual int32_t updateColorConversionInfo() { return NO_ERROR; };
        virtual int32_t updatePresentColorConversionInfo() { return NO_ERROR; };
        virtual bool checkRrCompensationEnabled() { return false; };
        virtual bool isColorCalibratedByDevice() { return false; };
        virtual int32_t getColorAdjustedDbv(uint32_t &) { return NO_ERROR; }
        virtual int32_t SetCurrentPanelGammaSource(const displaycolor::DisplayType /* type */,
                                                   const PanelGammaSource& /* source */) {
            return HWC2_ERROR_UNSUPPORTED;
        }
        virtual PanelGammaSource GetCurrentPanelGammaSource() const {
            return PanelGammaSource::GAMMA_DEFAULT;
        }
        virtual void initLbe(){};
        virtual void setLbeState(LbeState __unused state) {}
        virtual void setLbeAmbientLight(int __unused value) {}
        virtual LbeState getLbeState() { return LbeState::OFF; }

        int32_t checkPowerHalExtHintSupport(const std::string& mode);

        virtual bool isLhbmSupported() { return false; }
        virtual int32_t setLhbmState(bool __unused enabled) { return NO_ERROR; }
        virtual bool getLhbmState() { return false; };
        virtual void notifyLhbmState(bool __unused enabled) {}
        virtual void setWakeupDisplay() {}

        /* getDisplayPreAssignBit support mIndex up to 1.
           It supports only dual LCD and 2 external displays */
        inline uint32_t getDisplayPreAssignBit() {
            uint32_t type = SECOND_DISPLAY_START_BIT * mIndex + mType;
            return 1 << type;
        }
        void requestEnhancedHbm(bool on) { mBrightnessState.enhanced_hbm = on; };

        void cleanupAfterClientDeath();

    protected:
        virtual bool getHDRException(ExynosLayer *layer);
        virtual int32_t getActiveConfigInternal(hwc2_config_t* outConfig);
        virtual int32_t setActiveConfigInternal(hwc2_config_t config, bool force);

        void updateRefreshRateHint();

    public:
        /**
         * This will be initialized with differnt class
         * that inherits ExynosDisplayInterface according to
         * interface type.
         */
        std::unique_ptr<ExynosDisplayInterface> mDisplayInterface;

        const brightnessState_t& getBrightnessState() const { return mBrightnessState; }
        void updateForMipiSync(brightnessState_t::MipiSyncType type) {
            if (type == brightnessState_t::MIPI_SYNC_GHBM_ON ||
                type == brightnessState_t::MIPI_SYNC_GHBM_OFF) {
                mBrightnessState.dim_sdr_ratio = mBrightnessState.dim_sdr_target_ratio;
            }
        }
        float getBrightnessValue() const { return mBrightnessState.brightness_value; }
        void requestLhbm(bool on) {
            mReqLhbm = on;
            mDevice->invalidate();
        }

        virtual int setMinIdleRefreshRate(const int __unused fps) { return NO_ERROR; }
        virtual int setRefreshRateThrottleNanos(const int64_t __unused delayNanos) {
            return NO_ERROR;
        }

        virtual void updateAppliedActiveConfig(const hwc2_config_t /*newConfig*/,
                                               const int64_t /*ts*/) {}

    private:
        bool skipStaticLayerChanged(ExynosCompositionInfo& compositionInfo);

        bool skipSignalIdleForVideoLayer();

        /// minimum possible dim rate in the case hbm peak is 1000 nits and norml
        // display brightness is 2 nits
        static constexpr float kGhbmMinDimRatio = 0.002;

        /// consider HDR as full screen playback when its frame coverage
        //exceeds this threshold.
        static constexpr float kHdrFullScreen = 0.5;
        uint32_t mHdrFullScrenAreaThreshold;

       // Brightness state
        brightnessState_t mBrightnessState;

        // request lhbm state
        bool mReqLhbm = false;

        /* Display hint to notify power hal */
        class PowerHalHintWorker : public Worker {
        public:
            PowerHalHintWorker();
            virtual ~PowerHalHintWorker();
            int Init();

            void signalRefreshRate(hwc2_power_mode_t powerMode, uint32_t vsyncPeriod);
            void signalIdle();

        protected:
            void Routine() override;

        private:
            static void BinderDiedCallback(void*);
            int32_t connectPowerHalExt();
            int32_t checkPowerHalExtHintSupport(const std::string& mode);
            int32_t sendPowerHalExtHint(const std::string& mode, bool enabled);

            int32_t checkRefreshRateHintSupport(int refreshRate);
            int32_t updateRefreshRateHintInternal(hwc2_power_mode_t powerMode,
                                                  uint32_t vsyncPeriod);
            int32_t sendRefreshRateHint(int refreshRate, bool enabled);
            void forceUpdateHints();

            int32_t checkIdleHintSupport();
            int32_t updateIdleHint(int64_t deadlineTime, bool forceUpdate);
            bool needUpdateIdleHintLocked(int64_t& timeout) REQUIRES(mutex_);

            bool mNeedUpdateRefreshRateHint;

            // previous refresh rate
            int mPrevRefreshRate;

            // the refresh rate whose hint failed to be disabled
            int mPendingPrevRefreshRate;

            // support list of refresh rate hints
            std::map<int, bool> mRefreshRateHintSupportMap;

            bool mIdleHintIsEnabled;
            bool mForceUpdateIdleHint;
            int64_t mIdleHintDeadlineTime;

            // whether idle hint support is checked
            bool mIdleHintSupportIsChecked;

            // whether idle hint is supported
            bool mIdleHintIsSupported;

            hwc2_power_mode_t mPowerModeState;
            uint32_t mVsyncPeriod;

            // for power HAL extension hints
            std::shared_ptr<aidl::google::hardware::power::extension::pixel::IPowerExt>
                    mPowerHalExtAidl;
            ndk::ScopedAIBinder_DeathRecipient mDeathRecipient;
        };

        PowerHalHintWorker mPowerHalHint;

    protected:
        inline uint32_t getDisplayVsyncPeriodFromConfig(hwc2_config_t config) {
            int32_t vsync_period;
            getDisplayAttribute(config, HWC2_ATTRIBUTE_VSYNC_PERIOD, &vsync_period);
            assert(vsync_period > 0);
            return static_cast<uint32_t>(vsync_period);
        }

        virtual void calculateTimeline(
                hwc2_config_t config,
                hwc_vsync_period_change_constraints_t* vsyncPeriodChangeConstraints,
                hwc_vsync_period_change_timeline_t* outTimeline);
};

#endif //_EXYNOSDISPLAY_H
