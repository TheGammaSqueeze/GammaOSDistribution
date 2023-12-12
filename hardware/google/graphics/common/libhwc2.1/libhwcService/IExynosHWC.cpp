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

#include <stdint.h>
#include <sys/types.h>

#include <utils/Errors.h>
#include <utils/RefBase.h>
#include <utils/Timers.h>

#include <binder/Parcel.h>
#include <binder/IInterface.h>

#include "IExynosHWC.h"

namespace android {

enum {
    ADD_VIRTUAL_DISPLAY_DEVICE = 0,
    DESTROY_VIRTUAL_DISPLAY_DEVICE,
    SET_WFD_MODE,
    GET_WFD_MODE,
    SEND_WFD_COMMAND,
    SET_SECURE_VDS_MODE,
    SET_WFD_OUTPUT_RESOLUTION,
    GET_WFD_OUTPUT_RESOLUTION,
    SET_PRESENTATION_MODE,
    GET_PRESENTATION_MODE,
    SET_VDS_GLES_FORMAT,
    HWC_CONTROL,
    SET_BOOT_FINISHED,
    SET_VIRTUAL_HPD,
    GET_EXTERNAL_DISPLAY_CONFIG,
    SET_EXTERNAL_DISPLAY_CONFIG,
    ENABLE_MPP,
    SET_EXTERNAL_VSYNC,
    SET_DDISCALER,
    GET_EXTERNAL_HDR_CAPA,
    SET_SCALE_DOWN_RATIO,
#if 0
    NOTIFY_PSR_EXIT,
#endif
    SET_HWC_DEBUG = 105,
    GET_HWC_DEBUG = 106,
    SET_HWC_FENCE_DEBUG = 107,
    GET_HWC_FENCE_DEBUG = 108,
    SET_DISPLAY_DEVICE_MODE = 1000,
    SET_PANEL_GAMMA_TABLE_SOURCE = 1001,
    SET_DISPLAY_BRIGHTNESS = 1002,
    SET_DISPLAY_LHBM = 1003,
    SET_LBE_CTRL = 1004,
    SET_MIN_IDLE_REFRESH_RATE = 1005,
    SET_REFRESH_RATE_THROTTLE = 1006,
};

class BpExynosHWCService : public BpInterface<IExynosHWCService> {
public:
    BpExynosHWCService(const sp<IBinder>& impl)
        : BpInterface<IExynosHWCService>(impl)
    {
    }

    virtual int addVirtualDisplayDevice()
    {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        int result = remote()->transact(ADD_VIRTUAL_DISPLAY_DEVICE, data, &reply);
        if (result == NO_ERROR)
            result = reply.readInt32();
        else
            ALOGE("ADD_VIRTUAL_DISPLAY_DEVICE transact error(%d)", result);
        return result;
    }

    virtual int destroyVirtualDisplayDevice()
    {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        int result = remote()->transact(DESTROY_VIRTUAL_DISPLAY_DEVICE, data, &reply);
        if (result == NO_ERROR)
            result = reply.readInt32();
        else
            ALOGE("DESTROY_VIRTUAL_DISPLAY_DEVICE transact error(%d)", result);
        return result;
    }

    virtual int setWFDMode(unsigned int mode)
    {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        data.writeInt32(mode);
        int result = remote()->transact(SET_WFD_MODE, data, &reply);
        if (result == NO_ERROR)
            result = reply.readInt32();
        else
            ALOGE("SET_WFD_MODE transact error(%d)", result);
        return result;
    }

    virtual int getWFDMode()
    {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        int result = remote()->transact(GET_WFD_MODE, data, &reply);
        if (result == NO_ERROR)
            result = reply.readInt32();
        else
            ALOGE("GET_WFD_MODE transact error(%d)", result);
        return result;
    }

    virtual int sendWFDCommand(int32_t cmd, int32_t ext1, int32_t ext2)
    {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        data.writeInt32(cmd);
        data.writeInt32(ext1);
        data.writeInt32(ext2);
        int result = remote()->transact(SEND_WFD_COMMAND, data, &reply);
        if (result == NO_ERROR)
            result = reply.readInt32();
        else
            ALOGE("SEND_WFD_COMMAND transact error(%d)", result);
        return result;
    }

    virtual int setSecureVDSMode(unsigned int mode)
    {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        data.writeInt32(mode);
        int result = remote()->transact(SET_SECURE_VDS_MODE, data, &reply);
        if (result == NO_ERROR)
            result = reply.readInt32();
        else
            ALOGE("SET_SECURE_VDS_MODE transact error(%d)", result);
        return result;
    }

    virtual int setWFDOutputResolution(unsigned int width, unsigned int height)
    {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        data.writeInt32(width);
        data.writeInt32(height);
        int result = remote()->transact(SET_WFD_OUTPUT_RESOLUTION, data, &reply);
        if (result == NO_ERROR)
            result = reply.readInt32();
        else
            ALOGE("SET_WFD_OUTPUT_RESOLUTION transact error(%d)", result);
        return result;
    }

    virtual void getWFDOutputResolution(unsigned int *width, unsigned int *height)
    {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        int result = remote()->transact(GET_WFD_OUTPUT_RESOLUTION, data, &reply);
        if (result == NO_ERROR) {
            *width  = reply.readInt32();
            *height = reply.readInt32();
        } else
            ALOGE("GET_WFD_OUTPUT_RESOLUTION transact error(%d)", result);
    }

    virtual void setPresentationMode(bool use)
    {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        data.writeInt32(use);
        int result = remote()->transact(SET_PRESENTATION_MODE, data, &reply);
        if (result != NO_ERROR)
            ALOGE("SET_PRESENTATION_MODE transact error(%d)", result);
    }

    virtual int getPresentationMode(void)
    {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        int result = remote()->transact(GET_PRESENTATION_MODE, data, &reply);
        if (result == NO_ERROR)
            result = reply.readInt32();
        else
            ALOGE("GET_PRESENTATION_MODE transact error(%d)", result);
        return result;
    }

    virtual int setVDSGlesFormat(int format)
    {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        data.writeInt32(format);
        int result = remote()->transact(SET_VDS_GLES_FORMAT, data, &reply);
        if (result == NO_ERROR)
            result = reply.readInt32();
        else
            ALOGE("SET_VDS_GLES_FORMAT transact error(%d)", result);
        return result;
    }

    virtual int getExternalDisplayConfigs()
    {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        int result = remote()->transact(GET_EXTERNAL_DISPLAY_CONFIG, data, &reply);
        if (result == NO_ERROR)
            result = reply.readInt32();
        else
            ALOGE("GET_EXTERNAL_DISPLAY_CONFIG transact error(%d)", result);
        return result;
    }

    virtual int setExternalDisplayConfig(unsigned int index)
    {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        data.writeInt32(index);
        int result = remote()->transact(SET_EXTERNAL_DISPLAY_CONFIG, data, &reply);
        if (result == NO_ERROR)
            result = reply.readInt32();
        else
            ALOGE("SET_EXTERNAL_DISPLAY_CONFIG transact error(%d)", result);
        return result;
    }

    virtual int setExternalVsyncEnabled(unsigned int index)
    {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        data.writeInt32(index);
        int result = remote()->transact(SET_EXTERNAL_VSYNC, data, &reply);
        if (result == NO_ERROR)
            result = reply.readInt32();
        else
            ALOGE("SET_EXTERNAL_VSYNC transact error(%d)", result);
        return result;
    }

    virtual int getExternalHdrCapabilities()
    {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        int result = remote()->transact(GET_EXTERNAL_HDR_CAPA, data, &reply);
        if (result == NO_ERROR)
            result = reply.readInt32();
        else
            ALOGE("GET_EXTERNAL_HDR_CAPA transact error(%d)", result);

        return result;
    }

    virtual void setBootFinished()
    {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        int result = remote()->transact(SET_BOOT_FINISHED, data, &reply);
        if (result != NO_ERROR)
            ALOGE("SET_BOOT_FINISHED transact error(%d)", result);
    }

    virtual void enableMPP(uint32_t physicalType, uint32_t physicalIndex, uint32_t logicalIndex, uint32_t enable)
    {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        data.writeInt32(physicalType);
        data.writeInt32(physicalIndex);
        data.writeInt32(logicalIndex);
        data.writeInt32(enable);
        int result = remote()->transact(ENABLE_MPP, data, &reply);
        if (result != NO_ERROR)
            ALOGE("ENABLE_MPP transact error(%d)", result);
    }

    virtual void setScaleDownRatio(uint32_t physicalType, uint32_t physicalIndex,
            uint32_t logicalIndex, uint32_t scaleDownRatio)
    {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        data.writeInt32(physicalType);
        data.writeInt32(physicalIndex);
        data.writeInt32(logicalIndex);
        data.writeInt32(scaleDownRatio);
        int result = remote()->transact(SET_SCALE_DOWN_RATIO, data, &reply);
        if (result != NO_ERROR)
            ALOGE("SET_SCALE_DOWN_RATIO transact error(%d)", result);
    }

    virtual void setLbeCtrl(uint32_t display_id, uint32_t state, uint32_t lux) {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        data.writeInt32(display_id);
        data.writeInt32(state);
        data.writeInt32(lux);
        int result = remote()->transact(SET_LBE_CTRL, data, &reply);
        if (result != NO_ERROR) ALOGE("SET_LBE_CTRL transact error(%d)", result);
    }

    virtual void setHWCDebug(int debug)
    {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        data.writeInt32(debug);
        int result = remote()->transact(SET_HWC_DEBUG, data, &reply);
        if (result != NO_ERROR)
            ALOGE("SET_HWC_DEBUG transact error(%d)", result);
    }

    virtual uint32_t getHWCDebug()
    {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        int result = remote()->transact(GET_HWC_DEBUG, data, &reply);
        if (result == NO_ERROR)
            result = reply.readInt32();
        else {
            ALOGE("GET_HWC_DEBUG transact error(%d)", result);
        }
        return result;
    }

    virtual void setHWCFenceDebug(uint32_t fenceNum, uint32_t ipNum, uint32_t mode)
    {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        data.writeInt32(fenceNum);
        data.writeInt32(ipNum);
        data.writeInt32(mode);
        remote()->transact(SET_HWC_FENCE_DEBUG, data, &reply);
    }

    virtual void getHWCFenceDebug()
    {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        remote()->transact(GET_HWC_FENCE_DEBUG, data, &reply);
    }

    virtual int setHWCCtl(uint32_t display, uint32_t ctrl, int32_t val) {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        data.writeInt32(display);
        data.writeInt32(ctrl);
        data.writeInt32(val);
        int result = remote()->transact(HWC_CONTROL, data, &reply);
        if (result == NO_ERROR)
            result = reply.readInt32();
        else
            ALOGE("HWC_CONTROL transact error(%d)", result);
        return result;
    };

    virtual int setDDIScaler(uint32_t width, uint32_t height) {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        data.writeInt32(width);
        data.writeInt32(height);
        int result = remote()->transact(SET_DDISCALER, data, &reply);
        if (result == NO_ERROR)
            result = reply.readInt32();
        else
            ALOGE("SET_DDISCALER transact error(%d)", result);
        return result;
    }

    /*
    virtual void notifyPSRExit()
    {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        remote()->transact(NOTIFY_PSR_EXIT, data, &reply);
    }
    */

    int32_t setDisplayDeviceMode(int32_t display_id, int32_t mode)
    {
        ALOGD("null func: %s(%d %d)", __func__, display_id, mode);
        return NO_ERROR;
    }

    virtual int32_t setPanelGammaTableSource(int32_t display_id, int32_t type, int32_t source) {
        ALOGD("null func: %s(%d %d %d)", __func__, display_id, type, source);
        return NO_ERROR;
    }

    virtual int32_t setDisplayBrightness(int32_t display_id, float brightness) {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        data.writeInt32(display_id);
        data.writeFloat(brightness);
        int result = remote()->transact(SET_DISPLAY_BRIGHTNESS, data, &reply);
        if (result)
            ALOGE("SET_DISPLAY_BRIGHTNESS transact error(%d)", result);
        return result;
    }

    virtual int32_t setDisplayLhbm(int32_t display_id, uint32_t on) {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        data.writeInt32(display_id);
        data.writeInt32(on);
        int result = remote()->transact(SET_DISPLAY_LHBM, data, &reply);
        if (result) ALOGE("SET_DISPLAY_LHBM transact error(%d)", result);
        return result;
    }

    virtual int32_t setMinIdleRefreshRate(uint32_t display_id, int32_t fps) {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        data.writeUint32(display_id);
        data.writeInt32(fps);
        int result = remote()->transact(SET_MIN_IDLE_REFRESH_RATE, data, &reply);
        if (result) ALOGE("SET_MIN_IDLE_REFRESH_RATE transact error(%d)", result);
        return result;
    }

    virtual int32_t setRefreshRateThrottle(uint32_t display_id, int32_t delay_ms) {
        Parcel data, reply;
        data.writeInterfaceToken(IExynosHWCService::getInterfaceDescriptor());
        data.writeUint32(display_id);
        data.writeInt32(delay_ms);
        int result = remote()->transact(SET_REFRESH_RATE_THROTTLE, data, &reply);
        if (result) ALOGE("SET_REFRESH_RATE_THROTTLE transact error(%d)", result);
        return result;
    }
};

IMPLEMENT_META_INTERFACE(ExynosHWCService, "android.hal.ExynosHWCService");

status_t BnExynosHWCService::onTransact(
    uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
    switch(code) {
        case ADD_VIRTUAL_DISPLAY_DEVICE: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            int res = addVirtualDisplayDevice();
            reply->writeInt32(res);
            return NO_ERROR;
        } break;
        case DESTROY_VIRTUAL_DISPLAY_DEVICE: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            int res = destroyVirtualDisplayDevice();
            reply->writeInt32(res);
            return NO_ERROR;
        } break;
        case SET_WFD_MODE: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            int mode = data.readInt32();
            int res = setWFDMode(mode);
            reply->writeInt32(res);
            return NO_ERROR;
        } break;
        case GET_WFD_MODE: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            int res = getWFDMode();
            reply->writeInt32(res);
            return NO_ERROR;
        } break;
        case SEND_WFD_COMMAND: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            int cmd = data.readInt32();
            int ext1 = data.readInt32();
            int ext2 = data.readInt32();
            int res = sendWFDCommand(cmd, ext1, ext2);
            reply->writeInt32(res);
            return NO_ERROR;
        } break;
        case SET_SECURE_VDS_MODE: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            int mode = data.readInt32();
            int res = setSecureVDSMode(mode);
            reply->writeInt32(res);
            return NO_ERROR;
        } break;
        case SET_WFD_OUTPUT_RESOLUTION: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            int width  = data.readInt32();
            int height = data.readInt32();
            int res = setWFDOutputResolution(width, height);
            reply->writeInt32(res);
            return NO_ERROR;
        } break;
        case GET_WFD_OUTPUT_RESOLUTION: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            uint32_t width, height;
            getWFDOutputResolution(&width, &height);
            reply->writeInt32(width);
            reply->writeInt32(height);
            return NO_ERROR;
        } break;
        case SET_PRESENTATION_MODE: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            int use = data.readInt32();
            setPresentationMode(use);
            return NO_ERROR;
        } break;
        case GET_PRESENTATION_MODE: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            int res = getPresentationMode();
            reply->writeInt32(res);
            return NO_ERROR;
        } break;
        case SET_VDS_GLES_FORMAT: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            int format  = data.readInt32();
            int res = setVDSGlesFormat(format);
            reply->writeInt32(res);
            return NO_ERROR;
        } break;
       case HWC_CONTROL: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            int display = data.readInt32();
            int ctrl = data.readInt32();
            int value = data.readInt32();
            int res = setHWCCtl(display, ctrl, value);
            reply->writeInt32(res);
            return NO_ERROR;
        } break;
        case GET_EXTERNAL_DISPLAY_CONFIG: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            int res = getExternalDisplayConfigs();
            reply->writeInt32(res);
            return NO_ERROR;
        } break;
        case SET_EXTERNAL_DISPLAY_CONFIG: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            int index = data.readInt32();
            int res = setExternalDisplayConfig(index);
            reply->writeInt32(res);
            return NO_ERROR;
        } break;
        case SET_EXTERNAL_VSYNC: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            int index = data.readInt32();
            int res = setExternalVsyncEnabled(index);
            reply->writeInt32(res);
            return NO_ERROR;
        } break;
        case GET_EXTERNAL_HDR_CAPA: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            int res = getExternalHdrCapabilities();
            reply->writeInt32(res);
            return NO_ERROR;
        } break;
        case SET_BOOT_FINISHED: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            setBootFinished();
            return NO_ERROR;
        } break;
        case ENABLE_MPP: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            uint32_t type = data.readInt32();
            uint32_t physicalIdx = data.readInt32();
            uint32_t logicalIdx = data.readInt32();
            uint32_t enable = data.readInt32();
            enableMPP(type, physicalIdx, logicalIdx, enable);
            return NO_ERROR;
        } break;
        case SET_SCALE_DOWN_RATIO: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            uint32_t type = data.readInt32();
            uint32_t physicalIdx = data.readInt32();
            uint32_t logicalIdx = data.readInt32();
            uint32_t scaleDownRatio = data.readInt32();
            setScaleDownRatio(type, physicalIdx, logicalIdx, scaleDownRatio);
            return NO_ERROR;
        } break;
        case SET_HWC_DEBUG: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            int debug = data.readInt32();
            setHWCDebug(debug);
            reply->writeInt32(debug);
            return NO_ERROR;
        } break;
        case GET_HWC_DEBUG: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            int debugFlag = getHWCDebug();
            reply->writeInt32(debugFlag);
            return NO_ERROR;
        } break;
        case SET_HWC_FENCE_DEBUG: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            uint32_t fenceNum = data.readInt32();
            uint32_t ipNum = data.readInt32();
            uint32_t mode = data.readInt32();
            setHWCFenceDebug(fenceNum, ipNum, mode);
            return NO_ERROR;
        } break;
        case SET_DDISCALER: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            uint32_t width = data.readInt32();
            uint32_t height = data.readInt32();
            int error = setDDIScaler(width, height);
            reply->writeInt32(error);
            return NO_ERROR;
        } break;

#if 0
        case SET_HWC_CTL_MAX_OVLY_CNT: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            int val = data.readInt32();
            setHWCCtl(SET_HWC_CTL_MAX_OVLY_CNT, val);
            return NO_ERROR;
        } break;
        case SET_HWC_CTL_VIDEO_OVLY_CNT: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            int val = data.readInt32();
            setHWCCtl(SET_HWC_CTL_VIDEO_OVLY_CNT, val);
            return NO_ERROR;
        } break;
         case SET_HWC_CTL_DYNAMIC_RECOMP: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            int val = data.readInt32();
            setHWCCtl(SET_HWC_CTL_DYNAMIC_RECOMP, val);
            return NO_ERROR;
        } break;
        case SET_HWC_CTL_SKIP_STATIC: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            int val = data.readInt32();
            setHWCCtl(SET_HWC_CTL_SKIP_STATIC, val);
            return NO_ERROR;
        } break;
        case SET_HWC_CTL_SECURE_DMA: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            int val = data.readInt32();
            setHWCCtl(SET_HWC_CTL_SECURE_DMA, val);
            return NO_ERROR;
        } break;
        case NOTIFY_PSR_EXIT: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            notifyPSRExit();
            return NO_ERROR;
        }
#endif
        case SET_DISPLAY_DEVICE_MODE: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            int32_t display_id = data.readInt32();
            int32_t mode = data.readInt32();
            int32_t error = setDisplayDeviceMode(display_id, mode);
            reply->writeInt32(error);
            return NO_ERROR;
        } break;
        case SET_PANEL_GAMMA_TABLE_SOURCE: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            int32_t display_id = data.readInt32();
            int32_t type = data.readInt32();
            int32_t source = data.readInt32();
            int32_t error = setPanelGammaTableSource(display_id, type, source);
            reply->writeInt32(error);
            return NO_ERROR;
        } break;

        case SET_DISPLAY_BRIGHTNESS: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            int32_t display_id = data.readInt32();
            float brightness = data.readFloat();
            int32_t error = setDisplayBrightness(display_id, brightness);
            reply->writeInt32(error);
            return NO_ERROR;
        } break;

        case SET_DISPLAY_LHBM: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            int32_t display_id = data.readInt32();
            uint32_t on = data.readInt32();
            int32_t error = setDisplayLhbm(display_id, on);
            reply->writeInt32(error);
            return NO_ERROR;
        } break;

        case SET_LBE_CTRL: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            uint32_t display_id = data.readInt32();
            uint32_t state = data.readInt32();
            uint32_t lux = data.readInt32();
            setLbeCtrl(display_id, state, lux);
            return NO_ERROR;
        } break;

        case SET_MIN_IDLE_REFRESH_RATE: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            uint32_t display_id = data.readUint32();
            int32_t fps = data.readInt32();
            return setMinIdleRefreshRate(display_id, fps);
        } break;

        case SET_REFRESH_RATE_THROTTLE: {
            CHECK_INTERFACE(IExynosHWCService, data, reply);
            uint32_t display_id = data.readUint32();
            int32_t delay_ms = data.readInt32();
            return setRefreshRateThrottle(display_id, delay_ms);
        } break;

        default:
            return BBinder::onTransact(code, data, reply, flags);
    }
}
}
