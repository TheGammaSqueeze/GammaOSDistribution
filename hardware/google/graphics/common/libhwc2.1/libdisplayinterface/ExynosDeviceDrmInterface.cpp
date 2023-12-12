/*
 * Copyright (C) 2019 The Android Open Source Project
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

#include <drm/drm_mode.h>
#include "ExynosDeviceDrmInterface.h"
#include "ExynosDisplayDrmInterface.h"
#include "ExynosHWCDebug.h"
#include "ExynosDevice.h"
#include "ExynosDisplay.h"
#include "ExynosExternalDisplayModule.h"
#include <hardware/hwcomposer_defs.h>
#include <drm/samsung_drm.h>

void set_hwc_dpp_size_range(hwc_dpp_size_range &hwc_dpp_range, dpp_size_range &dpp_range)
{
    hwc_dpp_range.min = dpp_range.min;
    hwc_dpp_range.max = dpp_range.max;
    hwc_dpp_range.align = dpp_range.align;
}

static void set_dpp_ch_restriction(struct hwc_dpp_ch_restriction &hwc_dpp_restriction,
        struct dpp_ch_restriction &drm_restriction)
{
    hwc_dpp_restriction.id = drm_restriction.id;
    hwc_dpp_restriction.attr = drm_restriction.attr;
    set_hwc_dpp_size_range(hwc_dpp_restriction.restriction.src_f_w, drm_restriction.restriction.src_f_w);
    set_hwc_dpp_size_range(hwc_dpp_restriction.restriction.src_f_h, drm_restriction.restriction.src_f_h);
    set_hwc_dpp_size_range(hwc_dpp_restriction.restriction.src_w, drm_restriction.restriction.src_w);
    set_hwc_dpp_size_range(hwc_dpp_restriction.restriction.src_h, drm_restriction.restriction.src_h);
    hwc_dpp_restriction.restriction.src_x_align = drm_restriction.restriction.src_x_align;
    hwc_dpp_restriction.restriction.src_y_align = drm_restriction.restriction.src_y_align;
    set_hwc_dpp_size_range(hwc_dpp_restriction.restriction.dst_f_w, drm_restriction.restriction.dst_f_w);
    set_hwc_dpp_size_range(hwc_dpp_restriction.restriction.dst_f_h, drm_restriction.restriction.dst_f_h);
    set_hwc_dpp_size_range(hwc_dpp_restriction.restriction.dst_w, drm_restriction.restriction.dst_w);
    set_hwc_dpp_size_range(hwc_dpp_restriction.restriction.dst_h, drm_restriction.restriction.dst_h);
    hwc_dpp_restriction.restriction.dst_x_align = drm_restriction.restriction.dst_x_align;
    hwc_dpp_restriction.restriction.dst_y_align = drm_restriction.restriction.dst_y_align;
    set_hwc_dpp_size_range(hwc_dpp_restriction.restriction.blk_w, drm_restriction.restriction.blk_w);
    set_hwc_dpp_size_range(hwc_dpp_restriction.restriction.blk_h, drm_restriction.restriction.blk_h);
    hwc_dpp_restriction.restriction.blk_x_align = drm_restriction.restriction.blk_x_align;
    hwc_dpp_restriction.restriction.blk_y_align = drm_restriction.restriction.blk_y_align;
    hwc_dpp_restriction.restriction.src_h_rot_max = drm_restriction.restriction.src_h_rot_max;
    hwc_dpp_restriction.restriction.scale_down = drm_restriction.restriction.scale_down;
    hwc_dpp_restriction.restriction.scale_up = drm_restriction.restriction.scale_up;

    /* scale ratio can't be 0 */
    if (hwc_dpp_restriction.restriction.scale_down == 0)
        hwc_dpp_restriction.restriction.scale_down = 1;
    if (hwc_dpp_restriction.restriction.scale_up == 0)
        hwc_dpp_restriction.restriction.scale_up = 1;
}

using namespace SOC_VERSION;

ExynosDeviceDrmInterface::ExynosDeviceDrmInterface(ExynosDevice *exynosDevice)
{
    mType = INTERFACE_TYPE_DRM;
}

ExynosDeviceDrmInterface::~ExynosDeviceDrmInterface()
{
    mDrmDevice->event_listener()->UnRegisterHotplugHandler(static_cast<DrmEventHandler *>(&mExynosDrmEventHandler));
    mDrmDevice->event_listener()->UnRegisterTUIHandler(static_cast<DrmTUIEventHandler *>(&mExynosDrmEventHandler));
}

void ExynosDeviceDrmInterface::init(ExynosDevice *exynosDevice)
{
    mUseQuery = false;
    mExynosDevice = exynosDevice;
    mDrmResourceManager.Init();
    mDrmDevice = mDrmResourceManager.GetDrmDevice(HWC_DISPLAY_PRIMARY);
    assert(mDrmDevice != NULL);

    updateRestrictions();

    mExynosDrmEventHandler.init(mExynosDevice, mDrmDevice);
    mDrmDevice->event_listener()->RegisterHotplugHandler(static_cast<DrmEventHandler *>(&mExynosDrmEventHandler));
    mDrmDevice->event_listener()->RegisterTUIHandler(static_cast<DrmTUIEventHandler *>(&mExynosDrmEventHandler));

    if (mDrmDevice->event_listener()->IsDrmInTUI()) {
        mExynosDevice->enterToTUI();
        ALOGD("%s:: device is already in TUI", __func__);
    }
}

int32_t ExynosDeviceDrmInterface::initDisplayInterface(
         std::unique_ptr<ExynosDisplayInterface> &dispInterface)
{
    ExynosDisplayDrmInterface *displayInterface =
        static_cast<ExynosDisplayDrmInterface*>(dispInterface.get());
    return displayInterface->initDrmDevice(mDrmDevice);
}

void ExynosDeviceDrmInterface::updateRestrictions()
{
    int32_t ret = 0;

    mDPUInfo.dpuInfo.dpp_chs.resize(mDrmDevice->planes().size());
    uint32_t channelId = 0;

    for (auto &plane : mDrmDevice->planes()) {
        /* Set size restriction information */
        if (plane->hw_restrictions_property().id()) {
            uint64_t blobId;
            std::tie(ret, blobId) = plane->hw_restrictions_property().value();
            if (ret)
                break;
            struct dpp_ch_restriction *res;
            drmModePropertyBlobPtr blob = drmModeGetPropertyBlob(mDrmDevice->fd(), blobId);
            if (!blob) {
                ALOGE("Fail to get blob for hw_restrictions(%" PRId64 ")", blobId);
                ret = HWC2_ERROR_UNSUPPORTED;
                break;
            }
            res = (struct dpp_ch_restriction *)blob->data;
            set_dpp_ch_restriction(mDPUInfo.dpuInfo.dpp_chs[channelId], *res);
            drmModeFreePropertyBlob(blob);
        } else {
            ALOGI("plane[%d] There is no hw restriction information", channelId);
            ret = HWC2_ERROR_UNSUPPORTED;
            break;
        }
        /* Set supported format information */
        for (auto format : plane->formats()) {
            std::vector<uint32_t> halFormats;
            if (drmFormatToHalFormats(format, &halFormats) != NO_ERROR) {
                ALOGE("Fail to convert drm format(%d)", format);
                continue;
            }
            for (auto halFormat : halFormats) {
                mDPUInfo.dpuInfo.dpp_chs[channelId].restriction.formats.push_back(halFormat);
            }
        }
        if (hwcCheckDebugMessages(eDebugAttrSetting))
            printDppRestriction(mDPUInfo.dpuInfo.dpp_chs[channelId]);

        channelId++;
    }

    DrmCrtc *drmCrtc = mDrmDevice->GetCrtcForDisplay(0);
    if (drmCrtc != nullptr) {
        /*
         * Run makeDPURestrictions() even if there is error
         * in getting the value
         */
        if (drmCrtc->ppc_property().id()) {
            auto [ret_ppc, value] = drmCrtc->ppc_property().value();
            if (ret_ppc < 0) {
                ALOGE("Failed to get ppc property");
            } else {
                mDPUInfo.dpuInfo.ppc = static_cast<uint32_t>(value);
            }
        }
        if (drmCrtc->max_disp_freq_property().id()) {
            auto [ret_max_freq, value] = drmCrtc->max_disp_freq_property().value();
            if (ret_max_freq < 0) {
                ALOGE("Failed to get max_disp_freq property");
            } else {
                mDPUInfo.dpuInfo.max_disp_freq = static_cast<uint32_t>(value);
            }
        }
    } else {
        ALOGE("%s:: Fail to get DrmCrtc", __func__);
    }

    if (ret != NO_ERROR) {
        ALOGI("Fail to get restriction (ret: %d)", ret);
        mUseQuery = false;
        return;
    }

    if ((ret = makeDPURestrictions()) != NO_ERROR) {
        ALOGE("makeDPURestrictions fail");
    } else if ((ret = updateFeatureTable()) != NO_ERROR) {
        ALOGE("updateFeatureTable fail");
    }

    if (ret == NO_ERROR)
        mUseQuery = true;
    else {
        ALOGI("There is no hw restriction information, use default values");
        mUseQuery = false;
    }
}

void ExynosDeviceDrmInterface::ExynosDrmEventHandler::init(ExynosDevice *exynosDevice, DrmDevice *drmDevice)
{
    mExynosDevice = exynosDevice;
    mDrmDevice = drmDevice;
}

void ExynosDeviceDrmInterface::ExynosDrmEventHandler::HandleEvent(uint64_t timestamp_us)
{
    hwc2_callback_data_t callbackData =
        mExynosDevice->mCallbackInfos[HWC2_CALLBACK_HOTPLUG].callbackData;
    HWC2_PFN_HOTPLUG callbackFunc =
        (HWC2_PFN_HOTPLUG)mExynosDevice->mCallbackInfos[HWC2_CALLBACK_HOTPLUG].funcPointer;

    if (callbackData == NULL || callbackFunc == NULL)
    {
        ALOGE("%s:: callback info is NULL", __func__);
        return;
    }

    for (auto it : mExynosDevice->mDisplays) {
        /* Call UpdateModes to get plug status */
        uint32_t numConfigs;
        it->getDisplayConfigs(&numConfigs, NULL);

        callbackFunc(callbackData, getDisplayId(it->mType, it->mIndex),
                it->mPlugState ? HWC2_CONNECTION_CONNECTED : HWC2_CONNECTION_DISCONNECTED);
    }

    /* TODO: Check plug status hear or ExynosExternalDisplay::handleHotplugEvent() */
    ExynosExternalDisplayModule *display =
        static_cast<ExynosExternalDisplayModule*>(mExynosDevice->getDisplay(getDisplayId(HWC_DISPLAY_EXTERNAL, 0)));
    if (display != NULL)
        display->handleHotplugEvent();
}

void ExynosDeviceDrmInterface::ExynosDrmEventHandler::HandleTUIEvent()
{
    if (mDrmDevice->event_listener()->IsDrmInTUI()) {
        /* Received TUI Enter event */
        if (!mExynosDevice->isInTUI()) {
            mExynosDevice->enterToTUI();
            ALOGV("%s:: DRM device in TUI", __func__);
        }
    } else {
        /* Received TUI Exit event */
        if (mExynosDevice->isInTUI()) {
            mExynosDevice->invalidate();
            mExynosDevice->exitFromTUI();
            ALOGV("%s:: DRM device out TUI", __func__);
        }
    }
}
