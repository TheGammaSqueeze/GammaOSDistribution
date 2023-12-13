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

#ifndef EXYNOS_DISPLAY_DRM_INTERFACE_MODULE_H
#define EXYNOS_DISPLAY_DRM_INTERFACE_MODULE_H

#include <gs101/displaycolor/displaycolor_gs101.h>

#include "ExynosDisplayDrmInterface.h"

namespace gs101 {

using namespace displaycolor;

class ExynosDisplayDrmInterfaceModule : public ExynosDisplayDrmInterface {
    public:
        ExynosDisplayDrmInterfaceModule(ExynosDisplay *exynosDisplay);
        virtual ~ExynosDisplayDrmInterfaceModule();
        virtual int32_t initDrmDevice(DrmDevice *drmDevice);

        virtual int32_t setDisplayColorSetting(
                ExynosDisplayDrmInterface::DrmModeAtomicReq &drmReq);
        virtual int32_t setPlaneColorSetting(
                ExynosDisplayDrmInterface::DrmModeAtomicReq &drmReq,
                const std::unique_ptr<DrmPlane> &plane,
                const exynos_win_config_data &config);
        void setColorSettingChanged(bool changed, bool forceDisplay = false) {
            mColorSettingChanged = changed;
            mForceDisplayColorSetting = forceDisplay;
        };
        void destroyOldBlobs(std::vector<uint32_t> &oldBlobs);

        int32_t createCgcBlobFromIDqe(const IDisplayColorGS101::IDqe &dqe,
                uint32_t &blobId);
        int32_t createDegammaLutBlobFromIDqe(const IDisplayColorGS101::IDqe &dqe,
                uint32_t &blobId);
        int32_t createRegammaLutBlobFromIDqe(const IDisplayColorGS101::IDqe &dqe,
                uint32_t &blobId);
        int32_t createGammaMatBlobFromIDqe(const IDisplayColorGS101::IDqe &dqe,
                uint32_t &blobId);
        int32_t createLinearMatBlobFromIDqe(const IDisplayColorGS101::IDqe &dqe,
                uint32_t &blobId);
        int32_t createDispDitherBlobFromIDqe(const IDisplayColorGS101::IDqe &dqe,
                uint32_t &blobId);
        int32_t createCgcDitherBlobFromIDqe(const IDisplayColorGS101::IDqe &dqe,
                uint32_t &blobId);

        int32_t createEotfBlobFromIDpp(const IDisplayColorGS101::IDpp &dpp,
                uint32_t &blobId);
        int32_t createGmBlobFromIDpp(const IDisplayColorGS101::IDpp &dpp,
                uint32_t &blobId);
        int32_t createDtmBlobFromIDpp(const IDisplayColorGS101::IDpp &dpp,
                uint32_t &blobId);
        int32_t createOetfBlobFromIDpp(const IDisplayColorGS101::IDpp &dpp,
                uint32_t &blobId);

        void getDisplayInfo(std::vector<displaycolor::DisplayInfo> &display_info);

    protected:
        class SaveBlob {
            public:
                ~SaveBlob();
                void init(DrmDevice *drmDevice, uint32_t size) {
                    mDrmDevice = drmDevice;
                    blobs.resize(size, 0);
                };
                void addBlob(uint32_t type, uint32_t blob);
                uint32_t getBlob(uint32_t type);
            private:
                DrmDevice *mDrmDevice = NULL;
                std::vector<uint32_t> blobs;
        };
        class DqeBlobs:public SaveBlob {
            public:
                enum Dqe_Blob_Type{
                    CGC,
                    DEGAMMA_LUT,
                    REGAMMA_LUT,
                    GAMMA_MAT,
                    LINEAR_MAT,
                    DISP_DITHER,
                    CGC_DITHER,
                    DQE_BLOB_NUM // number of DQE blobs
                };
                void init(DrmDevice *drmDevice) {
                    SaveBlob::init(drmDevice, DQE_BLOB_NUM);
                };
        };
        class DppBlobs:public SaveBlob {
            public:
                enum Dpp_Blob_Type{
                    EOTF,
                    GM,
                    DTM,
                    OETF,
                    DPP_BLOB_NUM // number of DPP blobs
                };
                DppBlobs(DrmDevice *drmDevice, uint32_t pid) : planeId(pid) {
                    SaveBlob::init(drmDevice, DPP_BLOB_NUM);
                };
                uint32_t planeId;
        };
        template<typename StageDataType>
        int32_t setDisplayColorBlob(
                const DrmProperty &prop,
                const uint32_t type,
                const StageDataType &stage,
                const IDisplayColorGS101::IDqe &dqe,
                ExynosDisplayDrmInterface::DrmModeAtomicReq &drmReq);
        template<typename StageDataType>
        int32_t setPlaneColorBlob(
                const std::unique_ptr<DrmPlane> &plane,
                const DrmProperty &prop,
                const uint32_t type,
                const StageDataType &stage,
                const IDisplayColorGS101::IDpp &dpp,
                const uint32_t dppIndex,
                ExynosDisplayDrmInterface::DrmModeAtomicReq &drmReq,
                bool forceUpdate);
        void parseBpcEnums(const DrmProperty& property);
        DqeBlobs mOldDqeBlobs;
        std::vector<DppBlobs> mOldDppBlobs;
        void initOldDppBlobs(DrmDevice *drmDevice) {
            auto const &planes = drmDevice->planes();
            for (uint32_t ix = 0; ix < planes.size(); ++ix)
                mOldDppBlobs.emplace_back(mDrmDevice, planes[ix]->id());
        };
        bool mColorSettingChanged = false;
        bool mForceDisplayColorSetting = false;
        enum Bpc_Type {
            BPC_UNSPECIFIED = 0,
            BPC_8,
            BPC_10,
        };
        DrmPropertyMap mBpcEnums;
};

class ExynosPrimaryDisplayDrmInterfaceModule : public ExynosDisplayDrmInterfaceModule {
    public:
        ExynosPrimaryDisplayDrmInterfaceModule(ExynosDisplay *exynosDisplay);
        virtual ~ExynosPrimaryDisplayDrmInterfaceModule();
};

class ExynosExternalDisplayDrmInterfaceModule : public ExynosDisplayDrmInterfaceModule {
    public:
        ExynosExternalDisplayDrmInterfaceModule(ExynosDisplay *exynosDisplay);
        virtual ~ExynosExternalDisplayDrmInterfaceModule();
};

}  // namespace gs101

#endif
