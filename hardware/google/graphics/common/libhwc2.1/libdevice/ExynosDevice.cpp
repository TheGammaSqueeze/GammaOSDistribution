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

#include "ExynosDevice.h"
#include "ExynosDisplay.h"
#include "ExynosLayer.h"
#include "ExynosPrimaryDisplayModule.h"
#include "ExynosResourceManagerModule.h"
#include "ExynosExternalDisplayModule.h"
#include "ExynosVirtualDisplayModule.h"
#include "ExynosHWCDebug.h"
#include "ExynosHWCHelper.h"
#include "ExynosDeviceDrmInterface.h"
#include <unistd.h>
#include <sync/sync.h>
#include <sys/mman.h>
#include "VendorGraphicBuffer.h"

using namespace vendor::graphics;
using namespace SOC_VERSION;

/**
 * ExynosDevice implementation
 */

class ExynosDevice;

extern void vsync_callback(hwc2_callback_data_t callbackData,
        hwc2_display_t displayId, int64_t timestamp);
extern uint32_t mFenceLogSize;
extern void PixelDisplayInit(ExynosDevice *device);

int hwcDebug;
int hwcFenceDebug[FENCE_IP_ALL];
struct exynos_hwc_control exynosHWCControl;
struct update_time_info updateTimeInfo;
char fence_names[FENCE_MAX][32];

uint32_t getDeviceInterfaceType()
{
    if (access(DRM_DEVICE_PATH, F_OK) == NO_ERROR)
        return INTERFACE_TYPE_DRM;
    else
        return INTERFACE_TYPE_FB;
}

ExynosDevice::ExynosDevice()
    : mGeometryChanged(0),
    mVsyncFd(-1),
    mExtVsyncFd(-1),
    mVsyncDisplayId(getDisplayId(HWC_DISPLAY_PRIMARY, 0)),
    mTimestamp(0),
    mDisplayMode(0),
    mInterfaceType(INTERFACE_TYPE_FB),
    mIsInTUI(false)
{
    exynosHWCControl.forceGpu = false;
    exynosHWCControl.windowUpdate = true;
    exynosHWCControl.forcePanic = false;
    exynosHWCControl.skipStaticLayers = true;
    exynosHWCControl.skipM2mProcessing = true;
    exynosHWCControl.skipResourceAssign = true;
    exynosHWCControl.multiResolution = true;
    exynosHWCControl.dumpMidBuf = false;
    exynosHWCControl.displayMode = DISPLAY_MODE_NUM;
    exynosHWCControl.setDDIScaler = false;
    exynosHWCControl.skipWinConfig = false;
    exynosHWCControl.skipValidate = true;
    exynosHWCControl.doFenceFileDump = false;
    exynosHWCControl.fenceTracer = 0;
    exynosHWCControl.sysFenceLogging = false;
    exynosHWCControl.useDynamicRecomp = false;

    mInterfaceType = getDeviceInterfaceType();

    ALOGD("HWC2 : %s : interface type(%d)", __func__, mInterfaceType);
    mResourceManager = new ExynosResourceManagerModule(this);

    for (size_t i = 0; i < AVAILABLE_DISPLAY_UNITS.size(); i++) {
        exynos_display_t display_t = AVAILABLE_DISPLAY_UNITS[i];
        ExynosDisplay *exynos_display = NULL;
        ALOGD("Create display[%zu] type: %d, index: %d", i, display_t.type, display_t.index);
        switch(display_t.type) {
            case HWC_DISPLAY_PRIMARY:
                exynos_display = (ExynosDisplay *)(new ExynosPrimaryDisplayModule(display_t.index, this));
                if(display_t.index == 0) {
                    exynos_display->mPlugState = true;
                    ExynosMPP::mainDisplayWidth = exynos_display->mXres;
                    if (ExynosMPP::mainDisplayWidth <= 0) {
                        ExynosMPP::mainDisplayWidth = 1440;
                    }
                    ExynosMPP::mainDisplayHeight = exynos_display->mYres;
                    if (ExynosMPP::mainDisplayHeight <= 0) {
                        ExynosMPP::mainDisplayHeight = 2560;
                    }
                }
                break;
            case HWC_DISPLAY_EXTERNAL:
                exynos_display = (ExynosDisplay *)(new ExynosExternalDisplayModule(display_t.index, this));
                break;
            case HWC_DISPLAY_VIRTUAL:
                exynos_display = (ExynosDisplay *)(new ExynosVirtualDisplayModule(display_t.index, this));
                mNumVirtualDisplay = 0;
                break;
            default:
                ALOGE("Unsupported display type(%d)", display_t.type);
                break;
        }
        exynos_display->mDeconNodeName.appendFormat("%s", display_t.decon_node_name.c_str());
        exynos_display->mDisplayName.appendFormat("%s", display_t.display_name.c_str());
        mDisplays.add(exynos_display);

#ifndef FORCE_DISABLE_DR
        if (exynos_display->mDREnable)
            exynosHWCControl.useDynamicRecomp = true;
#endif
    }

    memset(mCallbackInfos, 0, sizeof(mCallbackInfos));

    dynamicRecompositionThreadCreate();

    hwcDebug = 0;
    for (uint32_t i = 0; i < FENCE_IP_ALL; i++)
        hwcFenceDebug[i] = 0;

    for (uint32_t i = 0; i < FENCE_MAX; i++) {
        memset(fence_names[i], 0, sizeof(fence_names[0]));
        sprintf(fence_names[i], "_%2dh", i);
    }

    String8 saveString;
    saveString.appendFormat("ExynosDevice is initialized");
    uint32_t errFileSize = saveErrorLog(saveString);
    ALOGI("Initial errlog size: %d bytes\n", errFileSize);

    /*
     * This order should not be changed
     * new ExynosResourceManager ->
     * create displays and add them to the list ->
     * initDeviceInterface() ->
     * ExynosResourceManager::updateRestrictions()
     */
    initDeviceInterface(mInterfaceType);
    mResourceManager->updateRestrictions();

    if (mInterfaceType == INTERFACE_TYPE_DRM) {
        /* disable vblank immediately after updates */
        setVBlankOffDelay(-1);
    }

    PixelDisplayInit(this);

    ExynosDisplay *primary_display = getDisplay(getDisplayId(HWC_DISPLAY_PRIMARY, 0));
    char value[PROPERTY_VALUE_MAX];
    property_get("vendor.display.lbe.supported", value, "0");
    mLbeSupported = atoi(value) ? true : false;
    if (mLbeSupported) {
        primary_display->initLbe();
    }
}

void ExynosDevice::initDeviceInterface(uint32_t interfaceType)
{
    if (interfaceType == INTERFACE_TYPE_DRM) {
        mDeviceInterface = std::make_unique<ExynosDeviceDrmInterface>(this);
    } else {
        LOG_ALWAYS_FATAL("%s::Unknown interface type(%d)",
                __func__, interfaceType);
    }

    mDeviceInterface->init(this);

    /* Remove display when display interface is not valid */
    for (uint32_t i = 0; i < mDisplays.size();) {
        ExynosDisplay* display = mDisplays[i];
        display->initDisplayInterface(interfaceType);
        if (mDeviceInterface->initDisplayInterface(
                    display->mDisplayInterface) != NO_ERROR) {
            ALOGD("Remove display[%d], Failed to initialize display interface", i);
            mDisplays.removeAt(i);
            delete display;
        } else {
            i++;
        }
    }
}

ExynosDevice::~ExynosDevice() {

    ExynosDisplay *primary_display = getDisplay(getDisplayId(HWC_DISPLAY_PRIMARY,0));

    mDRLoopStatus = false;
    mDRThread.join();

    delete primary_display;
}

bool ExynosDevice::isFirstValidate()
{
    for (uint32_t i = 0; i < mDisplays.size(); i++) {
        if ((mDisplays[i]->mType != HWC_DISPLAY_VIRTUAL) &&
            (mDisplays[i]->mPowerModeState == (hwc2_power_mode_t)HWC_POWER_MODE_OFF))
            continue;
        if ((mDisplays[i]->mPlugState == true) &&
            ((mDisplays[i]->mRenderingState != RENDERING_STATE_NONE) &&
             (mDisplays[i]->mRenderingState != RENDERING_STATE_PRESENTED)))
            return false;
    }

    return true;
}

bool ExynosDevice::isLastValidate(ExynosDisplay *display)
{
    for (uint32_t i = 0; i < mDisplays.size(); i++) {
        if (mDisplays[i] == display)
            continue;
        if ((mDisplays[i]->mType != HWC_DISPLAY_VIRTUAL) &&
            (mDisplays[i]->mPowerModeState == (hwc2_power_mode_t)HWC_POWER_MODE_OFF))
            continue;
        if ((mDisplays[i]->mPlugState == true) &&
            (mDisplays[i]->mRenderingState != RENDERING_STATE_VALIDATED) &&
            (mDisplays[i]->mRenderingState != RENDERING_STATE_ACCEPTED_CHANGE))
            return false;
    }
    return true;
}

bool ExynosDevice::isDynamicRecompositionThreadAlive()
{
    android_atomic_acquire_load(&mDRThreadStatus);
    return (mDRThreadStatus > 0);
}

void ExynosDevice::checkDynamicRecompositionThread()
{
    // If thread was destroyed, create thread and run. (resume status)
    if (isDynamicRecompositionThreadAlive() == false) {
        for (uint32_t i = 0; i < mDisplays.size(); i++) {
            if (mDisplays[i]->mDREnable) {
                dynamicRecompositionThreadCreate();
                return;
            }
        }
    } else {
    // If thread is running and all displays turnned off DR, destroy the thread.
        for (uint32_t i = 0; i < mDisplays.size(); i++) {
            if (mDisplays[i]->mDREnable)
                return;
        }
        mDRLoopStatus = false;
        mDRThread.join();
    }
}

void ExynosDevice::dynamicRecompositionThreadCreate()
{
    if (exynosHWCControl.useDynamicRecomp == true) {
        mDRLoopStatus = true;
        mDRThread = std::thread(&dynamicRecompositionThreadLoop, this);
    }
}

void *ExynosDevice::dynamicRecompositionThreadLoop(void *data)
{
    ExynosDevice *dev = (ExynosDevice *)data;
    ExynosDisplay *display[dev->mDisplays.size()];
    uint64_t event_cnt[dev->mDisplays.size()];

    for (uint32_t i = 0; i < dev->mDisplays.size(); i++) {
        display[i] = dev->mDisplays[i];
        event_cnt[i] = 0;
    }
    android_atomic_inc(&(dev->mDRThreadStatus));

    while (dev->mDRLoopStatus) {
        uint32_t result = 0;
        for (uint32_t i = 0; i < dev->mDisplays.size(); i++)
            event_cnt[i] = display[i]->mUpdateEventCnt;

        /*
         * If there is no update for more than 100ms, favor the 3D composition mode.
         * If all other conditions are met, mode will be switched to 3D composition.
         */
        usleep(100000);
        for (uint32_t i = 0; i < dev->mDisplays.size(); i++) {
            if (display[i]->mDREnable &&
                display[i]->mPlugState == true &&
                event_cnt[i] == display[i]->mUpdateEventCnt) {
                if (display[i]->checkDynamicReCompMode() == DEVICE_2_CLIENT) {
                    display[i]->mUpdateEventCnt = 0;
                    display[i]->setGeometryChanged(GEOMETRY_DISPLAY_DYNAMIC_RECOMPOSITION);
                    result = 1;
                }
            }
        }
        if (result)
            dev->invalidate();
    }

    android_atomic_dec(&(dev->mDRThreadStatus));

    return NULL;
}
/**
 * @param display
 * @return ExynosDisplay
 */
ExynosDisplay* ExynosDevice::getDisplay(uint32_t display) {
    if (mDisplays.isEmpty()) {
        ALOGE("mDisplays.size(%zu), requested display(%d)",
                mDisplays.size(), display);
        return NULL;
    }

    for (size_t i = 0;i < mDisplays.size(); i++) {
        if (mDisplays[i]->mDisplayId == display)
            return (ExynosDisplay*)mDisplays[i];
    }

    return NULL;
}

/**
 * Device Functions for HWC 2.0
 */

int32_t ExynosDevice::createVirtualDisplay(
        uint32_t width, uint32_t height, int32_t* /*android_pixel_format_t*/ format, ExynosDisplay* display) {
    ((ExynosVirtualDisplay*)display)->createVirtualDisplay(width, height, format);
    return 0;
}

/**
 * @param *display
 * @return int32_t
 */
int32_t ExynosDevice::destroyVirtualDisplay(ExynosDisplay* display) {
    ((ExynosVirtualDisplay *)display)->destroyVirtualDisplay();
    return 0;
}

void ExynosDevice::dump(uint32_t *outSize, char *outBuffer) {
    if (outSize == NULL) {
        ALOGE("%s:: outSize is null", __func__);
        return;
    }

    android::String8 result;
    result.append("\n\n");

    struct tm* localTime = (struct tm*)localtime((time_t*)&updateTimeInfo.lastUeventTime.tv_sec);
    result.appendFormat("lastUeventTime(%02d:%02d:%02d.%03lu) lastTimestamp(%" PRIu64 ")\n",
            localTime->tm_hour, localTime->tm_min,
            localTime->tm_sec, updateTimeInfo.lastUeventTime.tv_usec/1000, mTimestamp);

    localTime = (struct tm*)localtime((time_t*)&updateTimeInfo.lastEnableVsyncTime.tv_sec);
    result.appendFormat("lastEnableVsyncTime(%02d:%02d:%02d.%03lu)\n",
            localTime->tm_hour, localTime->tm_min,
            localTime->tm_sec, updateTimeInfo.lastEnableVsyncTime.tv_usec/1000);

    localTime = (struct tm*)localtime((time_t*)&updateTimeInfo.lastDisableVsyncTime.tv_sec);
    result.appendFormat("lastDisableVsyncTime(%02d:%02d:%02d.%03lu)\n",
            localTime->tm_hour, localTime->tm_min,
            localTime->tm_sec, updateTimeInfo.lastDisableVsyncTime.tv_usec/1000);

    localTime = (struct tm*)localtime((time_t*)&updateTimeInfo.lastValidateTime.tv_sec);
    result.appendFormat("lastValidateTime(%02d:%02d:%02d.%03lu)\n",
            localTime->tm_hour, localTime->tm_min,
            localTime->tm_sec, updateTimeInfo.lastValidateTime.tv_usec/1000);

    localTime = (struct tm*)localtime((time_t*)&updateTimeInfo.lastPresentTime.tv_sec);
    result.appendFormat("lastPresentTime(%02d:%02d:%02d.%03lu)\n",
            localTime->tm_hour, localTime->tm_min,
            localTime->tm_sec, updateTimeInfo.lastPresentTime.tv_usec/1000);

    result.appendFormat("\n");
    mResourceManager->dump(result);

    for (size_t i = 0;i < mDisplays.size(); i++) {
        ExynosDisplay *display = mDisplays[i];
        if (display->mPlugState == true)
            display->dump(result);
    }

    if (outBuffer == NULL) {
        *outSize = (uint32_t)result.length();
    } else {
        if (*outSize == 0) {
            ALOGE("%s:: outSize is 0", __func__);
            return;
        }
        uint32_t copySize = *outSize;
        if (*outSize > result.size())
            copySize = (uint32_t)result.size();
        ALOGI("HWC dump:: resultSize(%zu), outSize(%d), copySize(%d)", result.size(), *outSize, copySize);
        strlcpy(outBuffer, result.string(), copySize);
    }

    return;
}

uint32_t ExynosDevice::getMaxVirtualDisplayCount() {
#ifdef USES_VIRTUAL_DISPLAY
    return 1;
#else
    return 0;
#endif
}

int32_t ExynosDevice::registerCallback (
        int32_t descriptor, hwc2_callback_data_t callbackData,
        hwc2_function_pointer_t point) {
    if (descriptor < 0 || descriptor > HWC2_CALLBACK_SEAMLESS_POSSIBLE)
        return HWC2_ERROR_BAD_PARAMETER;

    mCallbackInfos[descriptor].callbackData = callbackData;
    mCallbackInfos[descriptor].funcPointer = point;

    /* Call hotplug callback for primary display*/
    if (descriptor == HWC2_CALLBACK_HOTPLUG) {
        HWC2_PFN_HOTPLUG callbackFunc =
            (HWC2_PFN_HOTPLUG)mCallbackInfos[descriptor].funcPointer;
        if (callbackFunc != NULL) {
            for (auto it : mDisplays) {
                if (it->mPlugState)
                    callbackFunc(callbackData, getDisplayId(it->mType, it->mIndex),
                            HWC2_CONNECTION_CONNECTED);
            }
        } else {
            // unregistering callback can be used as a sign of ComposerClient's death
            for (auto it : mDisplays) {
                it->cleanupAfterClientDeath();
            }
        }
    }

    if (descriptor == HWC2_CALLBACK_VSYNC)
        mResourceManager->doPreProcessing();

    return HWC2_ERROR_NONE;
}

void ExynosDevice::invalidate()
{
    HWC2_PFN_REFRESH callbackFunc =
        (HWC2_PFN_REFRESH)mCallbackInfos[HWC2_CALLBACK_REFRESH].funcPointer;
    if (callbackFunc != NULL)
        callbackFunc(mCallbackInfos[HWC2_CALLBACK_REFRESH].callbackData,
                getDisplayId(HWC_DISPLAY_PRIMARY, 0));
    else
        ALOGE("%s:: refresh callback is not registered", __func__);

}

void ExynosDevice::setHWCDebug(unsigned int debug)
{
    hwcDebug = debug;
}

uint32_t ExynosDevice::getHWCDebug()
{
    return hwcDebug;
}

void ExynosDevice::setHWCFenceDebug(uint32_t typeNum, uint32_t ipNum, uint32_t mode)
{
    if (typeNum > FENCE_TYPE_ALL || typeNum < 0 || ipNum > FENCE_IP_ALL || ipNum < 0
            || mode > 1 || mode < 0) {
        ALOGE("%s:: input is not valid type(%u), IP(%u), mode(%d)", __func__, typeNum, ipNum, mode);
        return;
    }

    uint32_t value = 0;

    if (typeNum == FENCE_TYPE_ALL)
        value = (1 << FENCE_TYPE_ALL) - 1;
    else
        value = 1 << typeNum;

    if (ipNum == FENCE_IP_ALL) {
        for (uint32_t i = 0; i < FENCE_IP_ALL; i++) {
            if (mode)
                hwcFenceDebug[i] |= value;
            else
                hwcFenceDebug[i] &= (~value);
        }
    } else {
        if (mode)
            hwcFenceDebug[ipNum] |= value;
        else
            hwcFenceDebug[ipNum] &= (~value);
    }

}

void ExynosDevice::getHWCFenceDebug()
{
    for (uint32_t i = 0; i < FENCE_IP_ALL; i++)
        ALOGE("[HWCFenceDebug] IP_Number(%d) : Debug(%x)", i, hwcFenceDebug[i]);
}

void ExynosDevice::setHWCControl(uint32_t display, uint32_t ctrl, int32_t val)
{
    ExynosDisplay *exynosDisplay = NULL;
    switch (ctrl) {
        case HWC_CTL_FORCE_GPU:
            ALOGI("%s::HWC_CTL_FORCE_GPU on/off=%d", __func__, val);
            exynosHWCControl.forceGpu = (unsigned int)val;
            setGeometryChanged(GEOMETRY_DEVICE_CONFIG_CHANGED);
            invalidate();
            break;
        case HWC_CTL_WINDOW_UPDATE:
            ALOGI("%s::HWC_CTL_WINDOW_UPDATE on/off=%d", __func__, val);
            exynosHWCControl.windowUpdate = (unsigned int)val;
            setGeometryChanged(GEOMETRY_DEVICE_CONFIG_CHANGED);
            invalidate();
            break;
        case HWC_CTL_FORCE_PANIC:
            ALOGI("%s::HWC_CTL_FORCE_PANIC on/off=%d", __func__, val);
            exynosHWCControl.forcePanic = (unsigned int)val;
            setGeometryChanged(GEOMETRY_DEVICE_CONFIG_CHANGED);
            break;
        case HWC_CTL_SKIP_STATIC:
            ALOGI("%s::HWC_CTL_SKIP_STATIC on/off=%d", __func__, val);
            exynosHWCControl.skipStaticLayers = (unsigned int)val;
            setGeometryChanged(GEOMETRY_DEVICE_CONFIG_CHANGED);
            break;
        case HWC_CTL_SKIP_M2M_PROCESSING:
            ALOGI("%s::HWC_CTL_SKIP_M2M_PROCESSING on/off=%d", __func__, val);
            exynosHWCControl.skipM2mProcessing = (unsigned int)val;
            setGeometryChanged(GEOMETRY_DEVICE_CONFIG_CHANGED);
            break;
        case HWC_CTL_SKIP_RESOURCE_ASSIGN:
            ALOGI("%s::HWC_CTL_SKIP_RESOURCE_ASSIGN on/off=%d", __func__, val);
            exynosHWCControl.skipResourceAssign = (unsigned int)val;
            setGeometryChanged(GEOMETRY_DEVICE_CONFIG_CHANGED);
            invalidate();
            break;
        case HWC_CTL_SKIP_VALIDATE:
            ALOGI("%s::HWC_CTL_SKIP_VALIDATE on/off=%d", __func__, val);
            exynosHWCControl.skipValidate = (unsigned int)val;
            setGeometryChanged(GEOMETRY_DEVICE_CONFIG_CHANGED);
            invalidate();
            break;
        case HWC_CTL_DUMP_MID_BUF:
            ALOGI("%s::HWC_CTL_DUMP_MID_BUF on/off=%d", __func__, val);
            exynosHWCControl.dumpMidBuf = (unsigned int)val;
            setGeometryChanged(GEOMETRY_DEVICE_CONFIG_CHANGED);
            invalidate();
            break;
        case HWC_CTL_CAPTURE_READBACK:
            captureScreenWithReadback(HWC_DISPLAY_PRIMARY);
            break;
        case HWC_CTL_DISPLAY_MODE:
            ALOGI("%s::HWC_CTL_DISPLAY_MODE mode=%d", __func__, val);
            setDisplayMode((uint32_t)val);
            setGeometryChanged(GEOMETRY_DEVICE_CONFIG_CHANGED);
            invalidate();
            break;
        // Support DDI scalser {
        case HWC_CTL_DDI_RESOLUTION_CHANGE:
            ALOGI("%s::HWC_CTL_DDI_RESOLUTION_CHANGE mode=%d", __func__, val);
            exynosDisplay = (ExynosDisplay*)getDisplay(display);
            uint32_t width, height;

            /* TODO: Add branch here for each resolution/index */
            switch(val) {
            case 1:
            case 2:
            case 3:
            default:
                width = 1440; height = 2960;
                break;
            }

            if (exynosDisplay == NULL) {
                for (uint32_t i = 0; i < mDisplays.size(); i++) {
                    mDisplays[i]->setDDIScalerEnable(width, height);
                }
            } else {
                exynosDisplay->setDDIScalerEnable(width, height);
            }
            setGeometryChanged(GEOMETRY_DISPLAY_RESOLUTION_CHANGED);
            invalidate();
            break;
        // } Support DDI scaler
        case HWC_CTL_ENABLE_COMPOSITION_CROP:
        case HWC_CTL_ENABLE_EXYNOSCOMPOSITION_OPT:
        case HWC_CTL_ENABLE_CLIENTCOMPOSITION_OPT:
        case HWC_CTL_USE_MAX_G2D_SRC:
        case HWC_CTL_ENABLE_HANDLE_LOW_FPS:
        case HWC_CTL_ENABLE_EARLY_START_MPP:
            exynosDisplay = (ExynosDisplay*)getDisplay(display);
            if (exynosDisplay == NULL) {
                for (uint32_t i = 0; i < mDisplays.size(); i++) {
                    mDisplays[i]->setHWCControl(ctrl, val);
                }
            } else {
                exynosDisplay->setHWCControl(ctrl, val);
            }
            setGeometryChanged(GEOMETRY_DEVICE_CONFIG_CHANGED);
            invalidate();
            break;
        case HWC_CTL_DYNAMIC_RECOMP:
            ALOGI("%s::HWC_CTL_DYNAMIC_RECOMP on/off = %d", __func__, val);
            setDynamicRecomposition((unsigned int)val);
            break;
        case HWC_CTL_ENABLE_FENCE_TRACER:
            ALOGI("%s::HWC_CTL_ENABLE_FENCE_TRACER on/off=%d", __func__, val);
            exynosHWCControl.fenceTracer = (unsigned int)val;
            break;
        case HWC_CTL_SYS_FENCE_LOGGING:
            ALOGI("%s::HWC_CTL_SYS_FENCE_LOGGING on/off=%d", __func__, val);
            exynosHWCControl.sysFenceLogging = (unsigned int)val;
            break;
        case HWC_CTL_DO_FENCE_FILE_DUMP:
            ALOGI("%s::HWC_CTL_DO_FENCE_FILE_DUMP on/off=%d", __func__, val);
            exynosHWCControl.doFenceFileDump = (unsigned int)val;
            break;
        default:
            ALOGE("%s: unsupported HWC_CTL (%d)", __func__, ctrl);
            break;
    }
}

void ExynosDevice::setDisplayMode(uint32_t displayMode)
{
    exynosHWCControl.displayMode = displayMode;
}

void ExynosDevice::setDynamicRecomposition(unsigned int on)
{
    exynosHWCControl.useDynamicRecomp = on;
}

bool ExynosDevice::checkDisplayConnection(uint32_t displayId)
{
	ExynosDisplay *display = getDisplay(displayId);

    if (!display)
        return false;
    else
        return display->mPlugState;
}

bool ExynosDevice::checkNonInternalConnection()
{
    for (uint32_t i = 0; i < mDisplays.size(); i++) {
        switch(mDisplays[i]->mType) {
            case HWC_DISPLAY_PRIMARY:
                break;
            case HWC_DISPLAY_EXTERNAL:
            case HWC_DISPLAY_VIRTUAL:
                if (mDisplays[i]->mPlugState)
                    return true;
                break;
            default:
                break;
        }
    }
    return false;
}

void ExynosDevice::getCapabilities(uint32_t *outCount, int32_t* outCapabilities)
{
    uint32_t capabilityNum = 0;
#ifdef HWC_SUPPORT_COLOR_TRANSFORM
    capabilityNum++;
#endif
#ifdef HWC_SKIP_VALIDATE
    capabilityNum++;
#endif
    if (outCapabilities == NULL) {
        *outCount = capabilityNum;
        return;
    }
    if (capabilityNum != *outCount) {
        ALOGE("%s:: invalid outCount(%d), should be(%d)", __func__, *outCount, capabilityNum);
        return;
    }
#if defined(HWC_SUPPORT_COLOR_TRANSFORM) || defined(HWC_SKIP_VALIDATE)
    uint32_t index = 0;
#endif
#ifdef HWC_SUPPORT_COLOR_TRANSFORM
    outCapabilities[index++] = HWC2_CAPABILITY_SKIP_CLIENT_COLOR_TRANSFORM;
#endif
#ifdef HWC_SKIP_VALIDATE
    outCapabilities[index++] = HWC2_CAPABILITY_SKIP_VALIDATE;
#endif
    return;
}

void ExynosDevice::clearGeometryChanged()
{
    mGeometryChanged = 0;
}

bool ExynosDevice::canSkipValidate()
{
    /*
     * This should be called by presentDisplay()
     * when presentDisplay() is called without validateDisplay() call
     */

    int ret = 0;
    if (exynosHWCControl.skipValidate == false)
        return false;

    for (uint32_t i = 0; i < mDisplays.size(); i++) {
        /*
         * Check all displays.
         * Resource assignment can have problem if validateDisplay is skipped
         * on only some displays.
         * All display's validateDisplay should be skipped or all display's validateDisplay
         * should not be skipped.
         */
        if (mDisplays[i]->mPlugState) {
            /*
             * presentDisplay is called without validateDisplay.
             * Call functions that should be called in validateDiplay
             */
            mDisplays[i]->doPreProcessing();
            mDisplays[i]->checkLayerFps();

            if ((ret = mDisplays[i]->canSkipValidate()) != NO_ERROR) {
                HDEBUGLOGD(eDebugSkipValidate, "Display[%d] can't skip validate (%d), renderingState(%d), geometryChanged(0x%" PRIx64 ")",
                        mDisplays[i]->mDisplayId, ret,
                        mDisplays[i]->mRenderingState, mGeometryChanged);
                return false;
            } else {
                HDEBUGLOGD(eDebugSkipValidate, "Display[%d] can skip validate (%d), renderingState(%d), geometryChanged(0x%" PRIx64 ")",
                        mDisplays[i]->mDisplayId, ret,
                        mDisplays[i]->mRenderingState, mGeometryChanged);
            }
        }
    }
    return true;
}

bool ExynosDevice::validateFences(ExynosDisplay *display) {

    if (!validateFencePerFrame(display)) {
        String8 errString;
        errString.appendFormat("You should doubt fence leak!\n");
        ALOGE("%s", errString.string());
        saveFenceTrace(display);
        return false;
    }

    if (fenceWarn(display, MAX_FENCE_THRESHOLD)) {
        String8 errString;
        errString.appendFormat("Fence leak!\n");
        printLeakFds(display);
        ALOGE("Fence leak! --");
        saveFenceTrace(display);
        return false;
    }

    if (exynosHWCControl.doFenceFileDump) {
        ALOGE("Fence file dump !");
        if (mFenceLogSize != 0)
            ALOGE("Fence file not empty!");
        saveFenceTrace(display);
        exynosHWCControl.doFenceFileDump = false;
    }

    return true;
}

void ExynosDevice::compareVsyncPeriod() {
    ExynosDisplay *primary_display = getDisplay(getDisplayId(HWC_DISPLAY_PRIMARY, 0));
    ExynosDisplay *external_display = getDisplay(getDisplayId(HWC_DISPLAY_EXTERNAL, 0));

    mVsyncDisplayId = getDisplayId(HWC_DISPLAY_PRIMARY, 0);

    if ((external_display == nullptr) ||
        (external_display->mPowerModeState == HWC2_POWER_MODE_OFF)) {
        return;
    } else if (primary_display->mPowerModeState == HWC2_POWER_MODE_OFF) {
        mVsyncDisplayId = getDisplayId(HWC_DISPLAY_EXTERNAL, 0);
        return;
    } else if (((primary_display->mPowerModeState == HWC2_POWER_MODE_DOZE) ||
            (primary_display->mPowerModeState == HWC2_POWER_MODE_DOZE_SUSPEND)) &&
            (external_display->mVsyncPeriod >= DOZE_VSYNC_PERIOD)) { /*30fps*/
        mVsyncDisplayId = getDisplayId(HWC_DISPLAY_EXTERNAL, 0);
        return;
    } else if (primary_display->mVsyncPeriod <= external_display->mVsyncPeriod) {
        mVsyncDisplayId = getDisplayId(HWC_DISPLAY_EXTERNAL, 0);
        return;
    }

    return;
}

ExynosDevice::captureReadbackClass::captureReadbackClass(
        ExynosDevice *device) :
    mDevice(device)
{
    if (device == nullptr)
        return;
}

ExynosDevice::captureReadbackClass::~captureReadbackClass()
{
    VendorGraphicBufferMapper& gMapper(VendorGraphicBufferMapper::get());
    if (mBuffer != nullptr)
        gMapper.freeBuffer(mBuffer);

    if (mDevice != nullptr)
        mDevice->clearWaitingReadbackReqDone();
}


int32_t ExynosDevice::captureReadbackClass::allocBuffer(
        uint32_t format, uint32_t w, uint32_t h)
{
    VendorGraphicBufferAllocator& gAllocator(VendorGraphicBufferAllocator::get());

    uint32_t dstStride = 0;
    uint64_t usage = static_cast<uint64_t>(GRALLOC1_CONSUMER_USAGE_HWCOMPOSER |
            GRALLOC1_CONSUMER_USAGE_CPU_READ_OFTEN);

    status_t error = NO_ERROR;
    error = gAllocator.allocate(w, h, format, 1, usage, &mBuffer, &dstStride, "HWC");
    if ((error != NO_ERROR) || (mBuffer == nullptr)) {
        ALOGE("failed to allocate destination buffer(%dx%d): %d",
                w, h, error);
        return static_cast<int32_t>(error);
    }
    return NO_ERROR;
}

void  ExynosDevice::captureReadbackClass::saveToFile(const String8 &fileName)
{
    if (mBuffer == nullptr) {
        ALOGE("%s:: buffer is null", __func__);
        return;
    }

    char filePath[MAX_DEV_NAME] = {0};
    VendorGraphicBufferMeta gmeta(mBuffer);

    snprintf(filePath, MAX_DEV_NAME,
            "%s/%s", WRITEBACK_CAPTURE_PATH, fileName.string());
    FILE *fp = fopen(filePath, "w");
    if (fp) {
        uint32_t writeSize =
            gmeta.stride * gmeta.vstride * formatToBpp(gmeta.format)/8;
        void *writebackData = mmap(0, writeSize,
                PROT_READ|PROT_WRITE, MAP_SHARED, gmeta.fd, 0);
        if (writebackData != MAP_FAILED && writebackData != NULL) {
            size_t result = fwrite(writebackData, writeSize, 1, fp);
            munmap(writebackData, writeSize);
            ALOGD("Success to write %zu data, size(%d)", result, writeSize);
        } else {
            ALOGE("Fail to mmap");
        }
    } else {
        ALOGE("Fail to open %s", filePath);
    }
}

void ExynosDevice::signalReadbackDone()
{
    if (mIsWaitingReadbackReqDone) {
        Mutex::Autolock lock(mCaptureMutex);
        mCaptureCondition.signal();
    }
}

void ExynosDevice::captureScreenWithReadback(uint32_t displayType)
{
    ExynosDisplay *display = getDisplay(displayType);
    if (display == nullptr) {
        ALOGE("There is no display(%d)", displayType);
        return;
    }

    int32_t outFormat;
    int32_t outDataspace;
    int32_t ret = 0;
    if ((ret = display->getReadbackBufferAttributes(
                &outFormat, &outDataspace)) != HWC2_ERROR_NONE) {
        ALOGE("getReadbackBufferAttributes fail, ret(%d)", ret);
        return;
    }

    captureReadbackClass captureClass(this);
    if ((ret = captureClass.allocBuffer(outFormat, display->mXres, display->mYres))
            != NO_ERROR) {
        return;
    }

    mIsWaitingReadbackReqDone = true;

    if (display->setReadbackBuffer(captureClass.getBuffer(), -1, true) != HWC2_ERROR_NONE) {
        ALOGE("setReadbackBuffer fail");
        return;
    }

    /* Update screen */
    invalidate();

    /* Wait for handling readback */
    uint32_t waitPeriod = display->mVsyncPeriod * 3;
    {
        Mutex::Autolock lock(mCaptureMutex);
        status_t err = mCaptureCondition.waitRelative(
                mCaptureMutex, us2ns(waitPeriod));
        if (err == TIMED_OUT) {
            ALOGE("timeout, readback is not requested");
            return;
        } else if (err != NO_ERROR) {
            ALOGE("error waiting for readback request: %s (%d)", strerror(-err), err);
            return;
        } else {
            ALOGD("readback request is done");
        }
    }

    int32_t fence = -1;
    if (display->getReadbackBufferFence(&fence) != HWC2_ERROR_NONE) {
        ALOGE("getReadbackBufferFence fail");
        return;
    }
    if (sync_wait(fence, 1000) < 0) {
        ALOGE("sync wait error, fence(%d)", fence);
    }
    hwcFdClose(fence);

    String8 fileName;
    time_t curTime = time(NULL);
    struct tm *tm = localtime(&curTime);
    fileName.appendFormat("capture_format%d_%dx%d_%04d-%02d-%02d_%02d_%02d_%02d.raw",
            outFormat, display->mXres, display->mYres,
            tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
            tm->tm_hour, tm->tm_min, tm->tm_sec);
    captureClass.saveToFile(fileName);
}

int32_t ExynosDevice::setDisplayDeviceMode(int32_t display_id, int32_t mode)
{
    int32_t ret = HWC2_ERROR_NONE;

    if (display_id == HWC_DISPLAY_PRIMARY) {
        if (mode == static_cast<int32_t>(ext_hwc2_power_mode_t::PAUSE) ||
            mode == static_cast<int32_t>(ext_hwc2_power_mode_t::RESUME)) {
            ret = mDisplays[display_id]->setPowerMode(mode);
            if (mode == static_cast<int32_t>(ext_hwc2_power_mode_t::RESUME) && ret == HWC2_ERROR_NONE) {
                invalidate();
            }
            return ret;
        } else {
            return HWC2_ERROR_UNSUPPORTED;
        }
    } else {
        return HWC2_ERROR_UNSUPPORTED;
    }
}

int32_t ExynosDevice::setPanelGammaTableSource(int32_t display_id, int32_t type, int32_t source) {
    if (display_id < HWC_DISPLAY_PRIMARY || display_id >= HWC_NUM_DISPLAY_TYPES) {
        ALOGE("invalid display %d", display_id);
        return HWC2_ERROR_BAD_DISPLAY;
    }

    if (type < static_cast<int32_t>(DisplayType::DISPLAY_PRIMARY) ||
        type >= static_cast<int32_t>(DisplayType::DISPLAY_MAX)) {
        ALOGE("invalid display type %d", type);
        return HWC2_ERROR_BAD_PARAMETER;
    }

    if (source < static_cast<int32_t>(PanelGammaSource::GAMMA_DEFAULT) ||
        source >= static_cast<int32_t>(PanelGammaSource::GAMMA_TYPES)) {
        ALOGE("invalid gamma source %d", source);
        return HWC2_ERROR_BAD_PARAMETER;
    }

    return mDisplays[display_id]->SetCurrentPanelGammaSource(static_cast<DisplayType>(type),
                                                             static_cast<PanelGammaSource>(source));
}

void ExynosDevice::getLayerGenericMetadataKey(uint32_t __unused keyIndex,
        uint32_t* outKeyLength, char* __unused outKey, bool* __unused outMandatory)
{
    *outKeyLength = 0;
    return;
}

void ExynosDevice::setVBlankOffDelay(int vblankOffDelay) {
    static constexpr const char *kVblankOffDelayPath = "/sys/module/drm/parameters/vblankoffdelay";

    writeIntToFile(kVblankOffDelayPath, vblankOffDelay);
}

bool ExynosDevice::isLbeSupported() {
    return mLbeSupported;
}

bool ExynosDevice::isColorCalibratedByDevice() {
    ExynosDisplay *display = getDisplay(getDisplayId(HWC_DISPLAY_PRIMARY, 0));
    return display->isColorCalibratedByDevice();
}

void ExynosDevice::setLbeState(LbeState state) {
    if (mLbeSupported) {
        ExynosDisplay *primary_display = getDisplay(getDisplayId(HWC_DISPLAY_PRIMARY, 0));
        primary_display->setLbeState(state);
    }
}

void ExynosDevice::setLbeAmbientLight(int value) {
    if (mLbeSupported) {
        ExynosDisplay *primary_display = getDisplay(getDisplayId(HWC_DISPLAY_PRIMARY, 0));
        primary_display->setLbeAmbientLight(value);
    }
}

LbeState ExynosDevice::getLbeState() {
    if (mLbeSupported) {
        ExynosDisplay *primary_display = getDisplay(getDisplayId(HWC_DISPLAY_PRIMARY, 0));
        return primary_display->getLbeState();
    }
    return LbeState::OFF;
}

bool ExynosDevice::isLhbmSupported() {
    ExynosDisplay *display = getDisplay(getDisplayId(HWC_DISPLAY_PRIMARY, 0));
    return display->isLhbmSupported();
}

int32_t ExynosDevice::setLhbmState(bool enabled) {
    if (isLhbmSupported()) {
        ExynosDisplay *display = getDisplay(getDisplayId(HWC_DISPLAY_PRIMARY, 0));
        return display->setLhbmState(enabled);
    }
    return -1;
}

bool ExynosDevice::getLhbmState() {
    if (isLhbmSupported()) {
        ExynosDisplay *display = getDisplay(getDisplayId(HWC_DISPLAY_PRIMARY, 0));
        return display->getLhbmState();
    }
    return false;
}

int ExynosDevice::setMinIdleRefreshRate(const int fps) {
    ExynosDisplay *display = getDisplay(getDisplayId(HWC_DISPLAY_PRIMARY, 0));
    if (display) {
        return display->setMinIdleRefreshRate(fps);
    }
    return BAD_VALUE;
}

int ExynosDevice::setRefreshRateThrottle(const int delayMs) {
    if (delayMs < 0) {
        ALOGE("%s fail: delayMs(%d) is less than 0", __func__, delayMs);
        return BAD_VALUE;
    }

    ExynosDisplay *display = getDisplay(getDisplayId(HWC_DISPLAY_PRIMARY, 0));
    if (display) {
        return display->setRefreshRateThrottleNanos(
                std::chrono::duration_cast<std::chrono::nanoseconds>(
                        std::chrono::milliseconds(delayMs))
                        .count());
    }
    return BAD_VALUE;
}
