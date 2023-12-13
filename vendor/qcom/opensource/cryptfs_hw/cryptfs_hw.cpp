/* Copyright (c) 2014, 2017, 2019 The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of The Linux Foundation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#define LOG_TAG "Cryptfs_hw"

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "cutils/log.h"
#include "cutils/properties.h"
#include "cryptfs_hw.h"
#ifdef LEGACY_HW_DISK_ENCRYPTION
#include <hardware/hardware.h>
#include <hardware/keymaster_common.h>
#endif
#include <vendor/qti/hardware/cryptfshw/1.0/ICryptfsHw.h>

using android::sp;
using vendor::qti::hardware::cryptfshw::V1_0::ICryptfsHw;
using ::android::hardware::Return;
using ::android::hardware::Void;

#define QTI_ICE_STORAGE_UFS				1
#define QTI_ICE_STORAGE_SDCC				2

int set_ice_param(int flag)
{
    int rc = -1;
    sp<ICryptfsHw> cryptfshwService = ICryptfsHw::getService();
    if (cryptfshwService.get() == nullptr) {
        ALOGE("Failed to get Cryptfshw service");
        return rc;
    }
    rc = cryptfshwService->setIceParam(flag);
    return rc;
}

int set_hw_device_encryption_key(const char* passwd, const char* enc_mode)
{
    int rc = -1;
    sp<ICryptfsHw> cryptfshwService = ICryptfsHw::getService();
    if (cryptfshwService.get() == nullptr) {
        ALOGE("Failed to get Cryptfshw service");
        return rc;
    }
    rc = cryptfshwService->setKey(passwd, enc_mode);
    return rc;
}

int update_hw_device_encryption_key(const char* oldpw, const char* newpw, const char* enc_mode)
{
    int rc = -1;
    sp<ICryptfsHw> cryptfshwService = ICryptfsHw::getService();
    if (cryptfshwService.get() == nullptr) {
        ALOGE("Failed to get Cryptfshw service");
        return rc;
    }
    rc = cryptfshwService->updateKey(oldpw, newpw, enc_mode);
    return rc;
}

unsigned int is_hw_disk_encryption(const char* encryption_mode)
{
    int ret = 0;
    if(encryption_mode) {
        if (!strcmp(encryption_mode, "aes-xts")) {
            SLOGD("HW based disk encryption is enabled \n");
            ret = 1;
        }
    }
    return ret;
}

int is_ice_enabled(void)
{
  char prop_storage[PATH_MAX];
  int storage_type = 0;

  if (property_get("ro.boot.bootdevice", prop_storage, "")) {
    if (strstr(prop_storage, "ufs")) {
      /* All UFS based devices has ICE in it. So we dont need
       * to check if corresponding device exists or not
       */
      storage_type = QTI_ICE_STORAGE_UFS;
    } else if (strstr(prop_storage, "sdhc")) {
      if (access("/dev/icesdcc", F_OK) != -1)
        storage_type = QTI_ICE_STORAGE_SDCC;
    }
  }
  return storage_type;
}

int clear_hw_device_encryption_key()
{
    int rc = -1;
    sp<ICryptfsHw> cryptfshwService = ICryptfsHw::getService();
    if (cryptfshwService.get() == nullptr) {
        ALOGE("Failed to get Cryptfshw service");
        return rc;
    }
    rc = cryptfshwService->clearKey();
    return rc;
}

#ifdef LEGACY_HW_DISK_ENCRYPTION
static int get_keymaster_version()
{
    int rc = -1;
    const hw_module_t* mod;
    rc = hw_get_module_by_class(KEYSTORE_HARDWARE_MODULE_ID, NULL, &mod);
    if (rc) {
        ALOGE("could not find any keystore module");
        return rc;
    }
    return mod->module_api_version;
}

int should_use_keymaster()
{
    /*
     * HW FDE key should be tied to keymaster
     * if version is above 0.3. this is to
     * support msm8909 go target.
     */
    int rc = 1;
    if (get_keymaster_version() == KEYMASTER_MODULE_API_VERSION_0_3) {
        ALOGI("Keymaster version is 0.3");
        rc = 0;
    }
    return rc;
}
#endif
