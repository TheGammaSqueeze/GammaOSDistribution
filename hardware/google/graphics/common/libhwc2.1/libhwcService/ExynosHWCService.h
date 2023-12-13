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

#ifndef ANDROID_EXYNOS_HWC_SERVICE_H_
#define ANDROID_EXYNOS_HWC_SERVICE_H_

#include <utils/Errors.h>
#include <sys/types.h>
#include <log/log.h>
#include <binder/IServiceManager.h>
#include <utils/Singleton.h>
#include <utils/StrongPointer.h>
#include "IExynosHWC.h"
#include "ExynosHWC.h"

typedef struct exynos_hwc2_device_t ExynosHWCCtx;

namespace android {

class ExynosHWCService
    : public BnExynosHWCService,  Singleton<ExynosHWCService> {

public:
    static ExynosHWCService* getExynosHWCService();
    ~ExynosHWCService();
    virtual void setExynosHWCCtx(ExynosHWCCtx *);

    virtual int addVirtualDisplayDevice();
    virtual int destroyVirtualDisplayDevice();
    virtual int setWFDMode(unsigned int mode);
    virtual int getWFDMode();
    virtual int sendWFDCommand(int32_t cmd, int32_t ext1, int32_t ext2);
    virtual int setSecureVDSMode(unsigned int mode);
    virtual int setWFDOutputResolution(unsigned int width, unsigned int height);
    virtual void getWFDOutputResolution(unsigned int *width, unsigned int *height);
    virtual void setPresentationMode(bool use);
    virtual int getPresentationMode(void);
    virtual int setVDSGlesFormat(int format);

    virtual int getExternalDisplayConfigs();
    virtual int setExternalDisplayConfig(unsigned int index);
    virtual int setExternalVsyncEnabled(unsigned int index);
    virtual int getExternalHdrCapabilities();
    void setBootFinishedCallback(void (*callback)(ExynosHWCCtx *));
    virtual void setBootFinished(void);
    virtual void enableMPP(uint32_t physicalType, uint32_t physicalIndex, uint32_t logicalIndex, uint32_t enable);
    virtual void setScaleDownRatio(uint32_t physicalType, uint32_t physicalIndex,
            uint32_t logicalIndex, uint32_t scaleDownRatio);
    virtual void setHWCDebug(int debug);
    virtual uint32_t getHWCDebug();
    virtual void setHWCFenceDebug(uint32_t ipNum, uint32_t fenceNum, uint32_t mode);
    virtual void getHWCFenceDebug();
    virtual int  setHWCCtl(uint32_t display, uint32_t ctrl, int32_t val);

    virtual int setDDIScaler(uint32_t width, uint32_t height);
    virtual void setLbeCtrl(uint32_t display_id, uint32_t state, uint32_t lux) override;
#if 0
    void setPSRExitCallback(void (*callback)(exynos_hwc_composer_device_1_t *));
    virtual void notifyPSRExit();
#endif
    virtual int32_t setDisplayDeviceMode(int32_t display_id, int32_t mode);
    virtual int32_t setPanelGammaTableSource(int32_t display_id, int32_t type, int32_t source);
    virtual int32_t setDisplayBrightness(int32_t display_id, float brightness);
    virtual int32_t setDisplayLhbm(int32_t display_id, uint32_t on);

    virtual int32_t setMinIdleRefreshRate(uint32_t display_id, int32_t fps);
    virtual int32_t setRefreshRateThrottle(uint32_t display_id, int32_t delayMs);

private:
    friend class Singleton<ExynosHWCService>;
    ExynosHWCService();
    int createServiceLocked();
    ExynosHWCService *mHWCService;
    Mutex mLock;
    ExynosHWCCtx *mHWCCtx;
    void (*bootFinishedCallback)(ExynosHWCCtx *);
    void (*doPSRExit)(ExynosHWCCtx *ctx);
};

}
#endif
