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
#ifndef _EXYNOSHWCHELPER_H
#define _EXYNOSHWCHELPER_H

#include <sstream>
#include <string>
#include <vector>

#include <drm/drm_fourcc.h>
#include <hardware/hwcomposer2.h>
#include <utils/String8.h>

#include <optional>

#include "DeconCommonHeader.h"
#include "VendorVideoAPI.h"
#include "exynos_sync.h"

#include "VendorGraphicBuffer.h"
#include "exynos_format.h"
#include "mali_gralloc_formats.h"

#define MAX_FENCE_NAME 64
#define MAX_FENCE_THRESHOLD 500
#define MAX_FD_NUM      1024

#define MAX_USE_FORMAT 27
#ifndef P010M_Y_SIZE
#define P010M_Y_SIZE(w,h) (__ALIGN_UP((w), 16) * 2 * __ALIGN_UP((h), 16) + 256)
#endif
#ifndef P010M_CBCR_SIZE
#define P010M_CBCR_SIZE(w,h) ((__ALIGN_UP((w), 16) * 2 * __ALIGN_UP((h), 16) / 2) + 256)
#endif
#ifndef P010_Y_SIZE
#define P010_Y_SIZE(w, h) ((w) * (h) * 2)
#endif
#ifndef P010_CBCR_SIZE
#define P010_CBCR_SIZE(w, h) ((w) * (h))
#endif
#ifndef DRM_FORMAT_YUV420_8BIT
#define DRM_FORMAT_YUV420_8BIT fourcc_code('Y', 'U', '0', '8')
#endif
#ifndef DRM_FORMAT_YUV420_10BIT
#define DRM_FORMAT_YUV420_10BIT fourcc_code('Y', 'U', '1', '0')
#endif

static constexpr uint32_t DISPLAYID_MASK_LEN = 8;

template<typename T> inline T max(T a, T b) { return (a > b) ? a : b; }
template<typename T> inline T min(T a, T b) { return (a < b) ? a : b; }

class ExynosLayer;
class ExynosDisplay;

using namespace android;

static constexpr uint32_t TRANSFORM_MAT_SIZE = 4*4;

enum {
    EXYNOS_HWC_DIM_LAYER = 1 << 0,
    EXYNOS_HWC_IGNORE_LAYER = 1 << 1,
};

enum {
    INTERFACE_TYPE_NONE = 0,
    INTERFACE_TYPE_FB   = 1,
    INTERFACE_TYPE_DRM  = 2,
};

typedef enum format_type {
    TYPE_UNDEF      = 0,

    /* format */
    FORMAT_SHIFT    = 0,
    FORMAT_MASK     = 0x00000fff,
    RGB             = 0x00000001,
    YUV420          = 0x00000002,
    YUV422          = 0x00000004,
    P010            = 0x00000008,

    /* bit */
    BIT_SHIFT       = 12,
    BIT_MASK        = 0x000ff000,
    BIT8            = 0x00001000,
    BIT10           = 0x00002000,
    BIT8_2          = 0x00004000,

    /* compression */
    /*
     * COMP_ANY: Compression type doesn't affect any other
     * descriptions of format (ex: drmFormat, bufferNum, bpp...)
     * in format_description
     */
    COMP_SHIFT      = 20,
    COMP_MASK       = 0x0ff00000,
    COMP_ANY        = 0x08000000, /* the highest bit */
    AFBC            = 0x00100000,
    SBWC            = 0x00200000,
    SBWC_LOSSY      = 0x00400000,

} format_type_t;

typedef struct format_description {
    inline uint32_t getFormat() const { return type & FORMAT_MASK; }
    inline uint32_t getBit() const { return type & BIT_MASK; }
    inline uint32_t getCompression() const { return type & COMP_MASK; }
    int halFormat;
    decon_pixel_format s3cFormat;
    int drmFormat;
    uint32_t planeNum;
    uint32_t bufferNum;
    uint8_t bpp;
    uint32_t type;
    bool hasAlpha;
    String8 name;
    uint32_t reserved;
} format_description_t;

constexpr int HAL_PIXEL_FORMAT_EXYNOS_UNDEFINED = 0;
constexpr int DRM_FORMAT_UNDEFINED = 0;

const format_description_t exynos_format_desc[] = {
    /* RGB */
    {HAL_PIXEL_FORMAT_RGBA_8888, DECON_PIXEL_FORMAT_RGBA_8888, DRM_FORMAT_RGBA8888,
        1, 1, 32, RGB|BIT8|COMP_ANY, true, String8("RGBA_8888"), 0},
    {HAL_PIXEL_FORMAT_RGBX_8888, DECON_PIXEL_FORMAT_RGBX_8888, DRM_FORMAT_RGBX8888,
        1, 1, 32, RGB|BIT8|COMP_ANY, false, String8("RGBx_8888"), 0},
    {HAL_PIXEL_FORMAT_RGB_888, DECON_PIXEL_FORMAT_MAX, DRM_FORMAT_RGB888,
        1, 1, 24, RGB|BIT8|COMP_ANY, false, String8("RGB_888"), 0},
    {HAL_PIXEL_FORMAT_RGB_565, DECON_PIXEL_FORMAT_RGB_565, DRM_FORMAT_BGR565,
        1, 1, 16, RGB, false, String8("RGB_565"), 0},
    {HAL_PIXEL_FORMAT_RGB_565, DECON_PIXEL_FORMAT_RGB_565, DRM_FORMAT_RGB565,
        1, 1, 16, RGB|AFBC, false, String8("RGB_565_AFBC"), 0},
    {HAL_PIXEL_FORMAT_BGRA_8888, DECON_PIXEL_FORMAT_BGRA_8888, DRM_FORMAT_BGRA8888,
        1, 1, 32, RGB|BIT8|COMP_ANY, true, String8("BGRA_8888"), 0},
    {HAL_PIXEL_FORMAT_RGBA_1010102, DECON_PIXEL_FORMAT_ABGR_2101010, DRM_FORMAT_RGBA1010102,
        1, 1, 32, RGB|BIT10|COMP_ANY, true, String8("RGBA_1010102"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_ARGB_8888, DECON_PIXEL_FORMAT_MAX, DRM_FORMAT_ARGB8888,
        1, 1, 32, RGB|BIT8|COMP_ANY, true, String8("EXYNOS_ARGB_8888"), 0},

    /* YUV 420 */
    {HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_P_M, DECON_PIXEL_FORMAT_YUV420M, DRM_FORMAT_UNDEFINED,
        3, 3, 12, YUV420|BIT8, false, String8("EXYNOS_YCbCr_420_P_M"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SP_M, DECON_PIXEL_FORMAT_NV12M, DRM_FORMAT_NV12,
        2, 2, 12, YUV420|BIT8, false, String8("EXYNOS_YCbCr_420_SP_M"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SP_M_TILED, DECON_PIXEL_FORMAT_MAX, DRM_FORMAT_UNDEFINED,
        2, 2, 12, YUV420|BIT8, false, String8("EXYNOS_YCbCr_420_SP_M_TILED"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_YV12_M, DECON_PIXEL_FORMAT_YVU420M, DRM_FORMAT_UNDEFINED,
        3, 3, 12, YUV420|BIT8, false, String8("EXYNOS_YV12_M"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_YCrCb_420_SP_M, DECON_PIXEL_FORMAT_NV21M, DRM_FORMAT_NV21,
        2, 2, 12, YUV420|BIT8, false, String8("EXYNOS_YCrCb_420_SP_M"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_YCrCb_420_SP_M_FULL, DECON_PIXEL_FORMAT_NV21M, DRM_FORMAT_NV21,
        2, 2, 12, YUV420|BIT8, false, String8("EXYNOS_YCrCb_420_SP_M_FULL"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_P, DECON_PIXEL_FORMAT_MAX, DRM_FORMAT_UNDEFINED,
        3, 1, 0, YUV420|BIT8, false, String8("EXYNOS_YCbCr_420_P"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SP, DECON_PIXEL_FORMAT_MAX, DRM_FORMAT_UNDEFINED,
        2, 1, 0, YUV420|BIT8, false, String8("EXYNOS_YCbCr_420_SP"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SP_M_PRIV, DECON_PIXEL_FORMAT_NV12M, DRM_FORMAT_NV12,
        2, 2, 12, YUV420|BIT8, false, String8("EXYNOS_YCbCr_420_SP_M_PRIV"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_PN, DECON_PIXEL_FORMAT_MAX, DRM_FORMAT_UNDEFINED,
        3, 1, 12, YUV420|BIT8, false, String8("EXYNOS_YCbCr_420_PN"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SPN, DECON_PIXEL_FORMAT_NV12N, DRM_FORMAT_NV12,
        2, 1, 12, YUV420|BIT8, false, String8("EXYNOS_YCbCr_420_SPN"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SPN_TILED, DECON_PIXEL_FORMAT_MAX, DRM_FORMAT_UNDEFINED,
        2, 1, 12, YUV420|BIT8, false, String8("EXYNOS_YCbCr_420_SPN_TILED"), 0},
    {HAL_PIXEL_FORMAT_YCrCb_420_SP, DECON_PIXEL_FORMAT_NV21, DRM_FORMAT_NV21,
        2, 1, 12, YUV420|BIT8, false, String8("YCrCb_420_SP"), 0},
    {HAL_PIXEL_FORMAT_YV12, DECON_PIXEL_FORMAT_MAX, DRM_FORMAT_UNDEFINED,
        3, 1, 12, YUV420|BIT8, false, String8("YV12"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SP_M_S10B, DECON_PIXEL_FORMAT_NV12M_S10B, DRM_FORMAT_UNDEFINED,
        2, 2, 12, YUV420|BIT10|BIT8_2, false, String8("EXYNOS_YCbCr_420_SP_M_S10B"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SPN_S10B, DECON_PIXEL_FORMAT_NV12N_10B, DRM_FORMAT_UNDEFINED,
        2, 1, 12, YUV420|BIT10|BIT8_2, false, String8("EXYNOS_YCbCr_420_SPN_S10B"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_YCbCr_P010_M, DECON_PIXEL_FORMAT_NV12M_P010, DRM_FORMAT_P010,
        2, 2, 24, YUV420|BIT10|P010, false, String8("EXYNOS_YCbCr_P010_M"), 0},
    {HAL_PIXEL_FORMAT_YCBCR_P010, DECON_PIXEL_FORMAT_NV12_P010, DRM_FORMAT_P010,
        2, 1, 24, YUV420|BIT10|P010, false, String8("EXYNOS_YCbCr_P010"), 0},

    {HAL_PIXEL_FORMAT_GOOGLE_NV12_SP, DECON_PIXEL_FORMAT_MAX, DRM_FORMAT_NV12,
        2, 1, 12, YUV420|BIT8, false, String8("GOOGLE_YCbCr_420_SP"), 0},
    {HAL_PIXEL_FORMAT_GOOGLE_NV12_SP_10B, DECON_PIXEL_FORMAT_MAX, DRM_FORMAT_P010,
        2, 1, 24, YUV420|BIT10, false, String8("GOOGLE_YCbCr_P010"), 0},
    {MALI_GRALLOC_FORMAT_INTERNAL_YUV420_8BIT_I, DECON_PIXEL_FORMAT_MAX, DRM_FORMAT_YUV420_8BIT,
        1, 1, 12, YUV420|BIT8|AFBC, false, String8("MALI_GRALLOC_FORMAT_INTERNAL_YUV420_8BIT_I"), 0},
    {MALI_GRALLOC_FORMAT_INTERNAL_YUV420_10BIT_I, DECON_PIXEL_FORMAT_MAX, DRM_FORMAT_YUV420_10BIT,
        1, 1, 15, YUV420|BIT10|AFBC, false, String8("MALI_GRALLOC_FORMAT_INTERNAL_YUV420_10BIT_I"), 0},

    /* YUV 422 */
    {HAL_PIXEL_FORMAT_EXYNOS_CbYCrY_422_I, DECON_PIXEL_FORMAT_MAX, DRM_FORMAT_UNDEFINED,
        0, 0, 0, YUV422|BIT8, false, String8("EXYNOS_CbYCrY_422_I"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_YCrCb_422_SP, DECON_PIXEL_FORMAT_MAX, DRM_FORMAT_UNDEFINED,
        0, 0, 0, YUV422|BIT8, false, String8("EXYNOS_YCrCb_422_SP"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_YCrCb_422_I, DECON_PIXEL_FORMAT_MAX, DRM_FORMAT_UNDEFINED,
        0, 0, 0, YUV422|BIT8, false, String8("EXYNOS_YCrCb_422_I"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_CrYCbY_422_I, DECON_PIXEL_FORMAT_MAX, DRM_FORMAT_UNDEFINED,
        0, 0, 0, YUV422|BIT8, false, String8("EXYNOS_CrYCbY_422_I"), 0},

    /* SBWC formats */
    /* NV12, YCbCr, Multi */
    {HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SP_M_SBWC, DECON_PIXEL_FORMAT_NV12M_SBWC_8B, DRM_FORMAT_NV12,
        2, 2, 12, YUV420|BIT8|SBWC, false, String8("EXYNOS_YCbCr_420_SP_M_SBWC"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SP_M_SBWC_L50, DECON_PIXEL_FORMAT_NV12M_SBWC_8B_L50, DRM_FORMAT_NV12,
        2, 2, 12, YUV420|BIT8|SBWC_LOSSY, false, String8("EXYNOS_YCbCr_420_SP_M_SBWC_L50"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SP_M_SBWC_L75, DECON_PIXEL_FORMAT_NV12M_SBWC_8B_L75, DRM_FORMAT_NV12,
        2, 2, 12, YUV420|BIT8|SBWC_LOSSY, false, String8("EXYNOS_YCbCr_420_SP_M_SBWC_L75"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SP_M_10B_SBWC, DECON_PIXEL_FORMAT_NV12M_SBWC_10B, DRM_FORMAT_UNDEFINED,
        2, 2, 12, YUV420|BIT10|SBWC, false, String8("EXYNOS_YCbCr_420_SP_M_10B_SBWC"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SP_M_10B_SBWC_L40, DECON_PIXEL_FORMAT_NV12M_SBWC_10B_L40, DRM_FORMAT_UNDEFINED,
        2, 2, 12, YUV420|BIT10|SBWC_LOSSY, false, String8("EXYNOS_YCbCr_420_SP_M_10B_SBWC_L40"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SP_M_10B_SBWC_L60, DECON_PIXEL_FORMAT_NV12M_SBWC_10B_L60, DRM_FORMAT_UNDEFINED,
        2, 2, 12, YUV420|BIT10|SBWC_LOSSY, false, String8("EXYNOS_YCbCr_420_SP_M_10B_SBWC_L60"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SP_M_10B_SBWC_L80, DECON_PIXEL_FORMAT_NV12M_SBWC_10B_L80, DRM_FORMAT_UNDEFINED,
        2, 2, 12, YUV420|BIT10|SBWC_LOSSY, false, String8("EXYNOS_YCbCr_420_SP_M_10B_SBWC_L80"), 0},

    /* NV12, YCbCr, Single */
    {HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SPN_SBWC, DECON_PIXEL_FORMAT_NV12N_SBWC_8B, DRM_FORMAT_NV12,
        2, 1, 12, YUV420|BIT8|SBWC, false, String8("EXYNOS_YCbCr_420_SPN_SBWC"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SPN_SBWC_L50, DECON_PIXEL_FORMAT_NV12N_SBWC_8B_L50, DRM_FORMAT_NV12,
        2, 1, 12, YUV420|BIT8|SBWC_LOSSY, false, String8("EXYNOS_YCbCr_420_SPN_SBWC_L50"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SPN_SBWC_L75, DECON_PIXEL_FORMAT_NV12N_SBWC_8B_L75, DRM_FORMAT_NV12,
        2, 1, 12, YUV420|BIT8|SBWC_LOSSY, false, String8("EXYNOS_YCbCr_420_SPN_SBWC_75"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SPN_10B_SBWC, DECON_PIXEL_FORMAT_NV12N_SBWC_10B, DRM_FORMAT_UNDEFINED,
        2, 1, 12, YUV420|BIT10|SBWC, false, String8("EXYNOS_YCbCr_420_SPN_10B_SBWC"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SPN_10B_SBWC_L40, DECON_PIXEL_FORMAT_NV12N_SBWC_10B_L40, DRM_FORMAT_UNDEFINED,
        2, 1, 12, YUV420|BIT10|SBWC_LOSSY, false, String8("EXYNOS_YCbCr_420_SPN_10B_SBWC_L40"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SPN_10B_SBWC_L60, DECON_PIXEL_FORMAT_NV12N_SBWC_10B_L60, DRM_FORMAT_UNDEFINED,
        2, 1, 12, YUV420|BIT10|SBWC_LOSSY, false, String8("EXYNOS_YCbCr_420_SPN_10B_SBWC_L60"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_YCbCr_420_SPN_10B_SBWC_L80, DECON_PIXEL_FORMAT_NV12N_SBWC_10B_L80, DRM_FORMAT_UNDEFINED,
        2, 1, 12, YUV420|BIT10|SBWC_LOSSY, false, String8("EXYNOS_YCbCr_420_SPN_10B_SBWC_L80"), 0},

    /* NV12, YCrCb */
    {HAL_PIXEL_FORMAT_EXYNOS_YCrCb_420_SP_M_SBWC, DECON_PIXEL_FORMAT_NV21M_SBWC_8B, DRM_FORMAT_UNDEFINED,
        2, 2, 12, YUV420|BIT8|SBWC, false, String8("EXYNOS_YCrCb_420_SP_M_SBWC"), 0},
    {HAL_PIXEL_FORMAT_EXYNOS_YCrCb_420_SP_M_10B_SBWC, DECON_PIXEL_FORMAT_NV21M_SBWC_10B, DRM_FORMAT_UNDEFINED,
        2, 2, 12, YUV420|BIT10|SBWC, false, String8("EXYNOS_YCrbCb_420_SP_M_10B_SBWC"), 0},

    {HAL_PIXEL_FORMAT_IMPLEMENTATION_DEFINED, DECON_PIXEL_FORMAT_MAX, DRM_FORMAT_UNDEFINED,
        0, 0, 0, TYPE_UNDEF, false, String8("ImplDef"), 0}
};

constexpr size_t FORMAT_MAX_CNT = sizeof(exynos_format_desc) / sizeof(format_description);

typedef enum hwc_fdebug_fence_type_t {
    FENCE_TYPE_SRC_RELEASE = 1,
    FENCE_TYPE_SRC_ACQUIRE = 2,
    FENCE_TYPE_DST_RELEASE = 3,
    FENCE_TYPE_DST_ACQUIRE = 4,
    FENCE_TYPE_FREE_RELEASE = 5,
    FENCE_TYPE_FREE_ACQUIRE = 6,
    FENCE_TYPE_HW_STATE = 7,
    FENCE_TYPE_RETIRE = 8,
    FENCE_TYPE_READBACK_ACQUIRE = 9,
    FENCE_TYPE_READBACK_RELEASE = 10,
    FENCE_TYPE_ALL = 11,
    FENCE_TYPE_UNDEFINED = 100
} hwc_fdebug_fence_type;

typedef enum hwc_fdebug_ip_type_t {
    FENCE_IP_DPP = 0,
    FENCE_IP_MSC = 1,
    FENCE_IP_G2D = 2,
    FENCE_IP_FB = 3,
    FENCE_IP_LAYER = 4,
    FENCE_IP_ALL = 5,
    FENCE_IP_UNDEFINED = 100
} hwc_fdebug_ip_type;

typedef enum hwc_fence_type_t {
    FENCE_LAYER_RELEASE_DPP     = 0,
    FENCE_LAYER_RELEASE_MPP     = 1,
    FENCE_LAYER_RELEASE_MSC     = 2,
    FENCE_LAYER_RELEASE_G2D     = 3,
    FENCE_DPP_HW_STATE          = 4,
    FENCE_MSC_HW_STATE          = 5,
    FENCE_G2D_HW_STATE          = 6,
    FENCE_MSC_SRC_LAYER         = 7,
    FENCE_G2D_SRC_LAYER         = 8,
    FENCE_MPP_DST_DPP           = 9,
    FENCE_MSC_DST_DPP           = 10,
    FENCE_G2D_DST_DPP           = 11,
    FENCE_DPP_SRC_MPP           = 12,
    FENCE_DPP_SRC_MSC           = 13,
    FENCE_DPP_SRC_G2D           = 14,
    FENCE_DPP_SRC_LAYER         = 15,
    FENCE_MPP_FREE_BUF_ACQUIRE  = 16,
    FENCE_MPP_FREE_BUF_RELEASE  = 17,
    FENCE_RETIRE                = 18,
    FENCE_MAX
} hwc_fence_type;

enum {
    EXYNOS_ERROR_NONE       = 0,
    EXYNOS_ERROR_CHANGED    = 1
};

enum {
    eSkipLayer                    =     0x00000001,
    eInvalidHandle                =     0x00000002,
    eHasFloatSrcCrop              =     0x00000004,
    eUpdateExynosComposition      =     0x00000008,
    eDynamicRecomposition         =     0x00000010,
    eForceFbEnabled               =     0x00000020,
    eSandwitchedBetweenGLES       =     0x00000040,
    eSandwitchedBetweenEXYNOS     =     0x00000080,
    eInsufficientWindow           =     0x00000100,
    eInsufficientMPP              =     0x00000200,
    eSkipStaticLayer              =     0x00000400,
    eUnSupportedUseCase           =     0x00000800,
    eDimLayer                     =     0x00001000,
    eResourcePendingWork          =     0x00002000,
    eSkipRotateAnim               =     0x00004000,
    eUnSupportedColorTransform    =     0x00008000,
    eLowFpsLayer                  =     0x00010000,
    eReallocOnGoingForDDI         =     0x00020000,
    eInvalidDispFrame             =     0x00040000,
    eExceedMaxLayerNum            =     0x00080000,
    eResourceAssignFail           =     0x20000000,
    eMPPUnsupported               =     0x40000000,
    eUnknown                      =     0x80000000,
};

enum regionType {
    eTransparentRegion          =       0,
    eCoveredOpaqueRegion        =       1,
    eDamageRegionByDamage       =       2,
    eDamageRegionByLayer        =       3,
};

enum {
    eDamageRegionFull = 0,
    eDamageRegionPartial,
    eDamageRegionSkip,
    eDamageRegionError,
};

/*
 * bufferHandle can be NULL if it is not allocated yet
 * or size or format information can be different between other field values and
 * member of bufferHandle. This means bufferHandle should be reallocated.
 * */
typedef struct exynos_image {
    uint32_t fullWidth = 0;
    uint32_t fullHeight = 0;
    uint32_t x = 0;
    uint32_t y = 0;
    uint32_t w = 0;
    uint32_t h = 0;
    uint32_t format= 0;
    uint64_t usageFlags = 0;
    uint32_t layerFlags = 0;
    int acquireFenceFd = -1;
    int releaseFenceFd = -1;
    buffer_handle_t bufferHandle = NULL;
    android_dataspace dataSpace = HAL_DATASPACE_UNKNOWN;
    uint32_t blending = 0;
    uint32_t transform = 0;
    uint32_t compressed = 0;
    float planeAlpha = 0;
    uint32_t zOrder = 0;
    /* refer
     * frameworks/native/include/media/hardware/VideoAPI.h
     * frameworks/native/include/media/hardware/HardwareAPI.h */
    bool hasMetaParcel = false;
    ExynosVideoMeta metaParcel;
    ExynosVideoInfoType metaType = VIDEO_INFO_TYPE_INVALID;
    bool needColorTransform = false;

    bool isDimLayer()
    {
        if (layerFlags & EXYNOS_HWC_DIM_LAYER)
            return true;
        return false;
    };
} exynos_image_t;

uint32_t getHWC1CompType(int32_t /*hwc2_composition_t*/ type);

uint32_t getDrmMode(uint64_t flags);
uint32_t getDrmMode(const buffer_handle_t handle);

inline int WIDTH(const hwc_rect &rect) { return rect.right - rect.left; }
inline int HEIGHT(const hwc_rect &rect) { return rect.bottom - rect.top; }
inline int WIDTH(const hwc_frect_t &rect) { return (int)(rect.right - rect.left); }
inline int HEIGHT(const hwc_frect_t &rect) { return (int)(rect.bottom - rect.top); }

const format_description_t *halFormatToExynosFormat(int format, uint32_t compressType);

uint32_t halDataSpaceToV4L2ColorSpace(android_dataspace data_space);
enum decon_pixel_format halFormatToDpuFormat(int format, uint32_t compressType);
uint32_t DpuFormatToHalFormat(int format, uint32_t compressType);
int halFormatToDrmFormat(int format, uint32_t compressType);
int32_t drmFormatToHalFormats(int format, std::vector<uint32_t> *halFormats);
int drmFormatToHalFormat(int format);
uint8_t formatToBpp(int format);
uint8_t DpuFormatToBpp(decon_pixel_format format);
uint64_t halTransformToDrmRot(uint32_t halTransform);
uint32_t getCompressionType(const buffer_handle_t handle);

bool isFormatRgb(int format);
bool isFormatYUV(int format);
bool isFormatYUV420(int format);
bool isFormatYUV422(int format);
bool isFormatYCrCb(int format);
bool isFormatYUV8_2(int format);
bool isFormat10BitYUV420(int format);
bool isFormatLossy(int format);
bool isFormatSBWC(int format);
bool isFormatP010(int format);
bool formatHasAlphaChannel(int format);
unsigned int isNarrowRgb(int format, android_dataspace data_space);
bool isAFBCCompressed(const buffer_handle_t handle);
bool isSrcCropFloat(hwc_frect &frect);
bool isScaled(exynos_image &src, exynos_image &dst);
bool isScaledDown(exynos_image &src, exynos_image &dst);
bool hasHdrInfo(const exynos_image &img);
bool hasHdrInfo(android_dataspace dataSpace);
bool hasHdr10Plus(exynos_image &img);

void dumpExynosImage(uint32_t type, exynos_image &img);
void dumpExynosImage(String8& result, exynos_image &img);
void dumpHandle(uint32_t type, buffer_handle_t h);
void printExynosLayer(const ExynosLayer *layer);
String8 getFormatStr(int format, uint32_t compressType);
String8 getMPPStr(int typeId);
void adjustRect(hwc_rect_t &rect, int32_t width, int32_t height);
uint32_t getBufferNumOfFormat(int format, uint32_t compressType);
uint32_t getPlaneNumOfFormat(int format, uint32_t compressType);
uint32_t getBytePerPixelOfPrimaryPlane(int format);

int fence_close(int fence, ExynosDisplay* display,
        hwc_fdebug_fence_type type, hwc_fdebug_ip_type ip);
bool fence_valid(int fence);

int hwcFdClose(int fd);
int hwc_dup(int fd, ExynosDisplay *display, hwc_fdebug_fence_type type, hwc_fdebug_ip_type ip,
            bool pendingAllowed = false);
int hwc_print_stack();

inline hwc_rect expand(const hwc_rect &r1, const hwc_rect &r2)
{
    hwc_rect i;
    i.top = min(r1.top, r2.top);
    i.bottom = max(r1.bottom, r2.bottom);
    i.left = min(r1.left, r2.left);
    i.right = max(r1.right, r2.right);
    return i;
}

template <typename T>
inline T pixel_align_down(const T x, const uint32_t a) {
    static_assert(std::numeric_limits<T>::is_integer,
                  "Integer type is expected as the alignment input");
    return a ? (x / a) * a : x;
}

template <typename T>
inline T pixel_align(const T x, const uint32_t a) {
    static_assert(std::numeric_limits<T>::is_integer,
                  "Integer type is expected as the alignment input");
    return a ? ((x + a - 1) / a) * a : x;
}

uint32_t getExynosBufferYLength(uint32_t width, uint32_t height, int format);
int getBufLength(buffer_handle_t handle, uint32_t planer_num, size_t *length, int format, uint32_t width, uint32_t height);

//class hwc_fence_info(sync_fence_info_data* data, sync_pt_info* info) {
struct tm* getHwcFenceTime();

enum {
    FENCE_FROM = 0,
    FENCE_TO,
    FENCE_DUP,
    FENCE_CLOSE,
};

typedef struct fenceTrace {
    hwc_fdebug_fence_type type;
    hwc_fdebug_ip_type ip;
    struct timeval time;
    int32_t curFlag;
} fenceTrace_t;

typedef struct hwc_fence_info {
    uint32_t displayId;
    struct sync_fence_info_data* sync_data;
    struct sync_pt_info* pt_info;
    fenceTrace_t from;
    fenceTrace_t to;
    fenceTrace_t dup;
    fenceTrace_t close;
    int32_t usage;
    int32_t curFlag;
    uint32_t last_dir;
    bool pendingAllowed = false;
    bool leaking = false;
} hwc_fence_info_t;

class funcReturnCallback {
    public:
        funcReturnCallback(const std::function<void(void)> cb) : mCb(cb) {}
        ~funcReturnCallback() { mCb(); }
    private:
        const std::function<void(void)> mCb;
};

void setFenceName(int fenceFd, hwc_fence_type fenceType);
void setFenceName(uint32_t fd, ExynosDisplay *display,
        hwc_fdebug_fence_type type, hwc_fdebug_ip_type ip,
        uint32_t direction, bool pendingAllowed = false);
void setFenceInfo(uint32_t fd, ExynosDisplay *display,
        hwc_fdebug_fence_type type, hwc_fdebug_ip_type ip,
        uint32_t direction, bool pendingAllowed = false);
void printFenceInfo(uint32_t fd, hwc_fence_info_t* info);
void dumpFenceInfo(ExynosDisplay *display, int32_t __unused depth);
bool fenceWarn(hwc_fence_info_t **info, uint32_t threshold);
void resetFenceCurFlag(ExynosDisplay *display);
bool fenceWarn(ExynosDisplay *display, uint32_t threshold);
void printLeakFds(ExynosDisplay *display);
bool validateFencePerFrame(ExynosDisplay *display);
android_dataspace colorModeToDataspace(android_color_mode_t mode);
bool hasPPC(uint32_t physicalType, uint32_t formatIndex, uint32_t rotIndex);

class TableBuilder {
public:
    template <typename T>
    TableBuilder& add(const std::string& key, const T& value) {
        std::stringstream v;
        v << value;
        data.emplace_back(std::make_pair(key, v.str()));
        return *this;
    }

    template <typename T>
    TableBuilder& add(const std::string& key, const std::vector<T>& values) {
        std::stringstream value;
        for (int i = 0; i < values.size(); i++) {
            if (i) value << ", ";
            value << values[i];
        }

        data.emplace_back(std::make_pair(key, value.str()));
        return *this;
    }

    // Template overrides for hex integers
    TableBuilder& add(const std::string& key, const uint64_t& value, bool toHex);
    TableBuilder& add(const std::string& key, const std::vector<uint64_t>& values, bool toHex);

    std::string build();

private:
    std::string buildPaddedString(const std::string& str, int size);

    using StringPairVec = std::vector<std::pair<std::string, std::string>>;
    StringPairVec data;
};

void writeFileNode(FILE *fd, int value);
int32_t writeIntToFile(const char *file, uint32_t value);
uint32_t getDisplayId(int32_t displayType, int32_t displayIndex = 0);
int32_t load_png_image(const char *filepath, buffer_handle_t buffer);

template <typename T>
struct CtrlValue {
public:
    void store(T value) {
        if (value == value_) return;
        dirty_ = true;
        value_ = value;
    };
    const T &get() { return value_; };
    bool is_dirty() { return dirty_; };
    void clear_dirty() { dirty_ = false; };
    void set_dirty() { dirty_ = true; };

private:
    T value_;
    bool dirty_;
};

#endif
