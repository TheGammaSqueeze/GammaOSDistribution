/*
 * Copyright (C) 2018 The Android Open Source Project
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

#ifndef ANDROID_SENSOR_PRIVACY_MANAGER_H
#define ANDROID_SENSOR_PRIVACY_MANAGER_H

#include "android/hardware/ISensorPrivacyListener.h"
#include "android/hardware/ISensorPrivacyManager.h"

#include <utils/threads.h>

#include <unordered_map>

// ---------------------------------------------------------------------------
namespace android {

class SensorPrivacyManager
{
public:
    enum {
        INDIVIDUAL_SENSOR_MICROPHONE = 1,
        INDIVIDUAL_SENSOR_CAMERA = 2
    };

    SensorPrivacyManager();

    bool supportsSensorToggle(int sensor);
    void addSensorPrivacyListener(const sp<hardware::ISensorPrivacyListener>& listener);
    status_t addIndividualSensorPrivacyListener(int userId, int sensor,
            const sp<hardware::ISensorPrivacyListener>& listener);
    void removeSensorPrivacyListener(const sp<hardware::ISensorPrivacyListener>& listener);
    void removeIndividualSensorPrivacyListener(int sensor,
            const sp<hardware::ISensorPrivacyListener>& listener);
    bool isSensorPrivacyEnabled();
    bool isIndividualSensorPrivacyEnabled(int userId, int sensor);
    status_t isIndividualSensorPrivacyEnabled(int userId, int sensor, bool &result);

    status_t linkToDeath(const sp<IBinder::DeathRecipient>& recipient);
    status_t unlinkToDeath(const sp<IBinder::DeathRecipient>& recipient);

private:
    Mutex mLock;
    sp<hardware::ISensorPrivacyManager> mService;
    sp<hardware::ISensorPrivacyManager> getService();

    std::unordered_map<int, bool> mSupportedCache;
};


}; // namespace android
// ---------------------------------------------------------------------------

#endif // ANDROID_SENSOR_PRIVACY_MANAGER_H
