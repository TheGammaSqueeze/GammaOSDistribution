/*
 * Copyright (c) 2019, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *        * Redistributions of source code must retain the above copyright
 *            notice, this list of conditions and the following disclaimer.
 *        * Redistributions in binary form must reproduce the above
 *            copyright notice, this list of conditions and the following
 *            disclaimer in the documentation and/or other materials provided
 *            with the distribution.
 *        * Neither the name of The Linux Foundation nor the names of its
 *            contributors may be used to endorse or promote products derived
 *            from this software without specific prior written permission.
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

/*****************************************************************************
 *
 *  This file contains main functions to support BT Config Store interface to send
 *  commands and  received events.
 *
 *****************************************************************************/

#define LOG_TAG "bt_config_store"

#include <vector>

#include "bt_configstore.h"
#include <cutils/properties.h>

#include "osi/include/log.h"
#include "osi/include/osi.h"
#include "osi/include/config.h"
#include <vendor/qti/hardware/btconfigstore/1.0/IBTConfigStore.h>
#include <vendor/qti/hardware/btconfigstore/1.0/types.h>
#include <vendor/qti/hardware/btconfigstore/2.0/IBTConfigStore.h>
#include <vendor/qti/hardware/btconfigstore/2.0/types.h>


#include <hwbinder/ProcessState.h>
#include <fcntl.h>
#include <string.h>
#include <hwbinder/IPCThreadState.h>
#include <cutils/properties.h>

/* max platform record must be equal to the predefined max num
   of platform in bt_configstore.conf */
#define MAX_PLATFORM_PROP_RECORD 12
#define BT_CONFIG_STORE_PATH "/system_ext/etc/bluetooth/bt_configstore.conf"

using android::hardware::IPCThreadState;

using ::vendor::qti::hardware::btconfigstore::V1_0::AddOnFeaturesList;
using ::vendor::qti::hardware::btconfigstore::V2_0::HostAddOnFeatures;
using ::vendor::qti::hardware::btconfigstore::V2_0::ControllerAddOnFeatures;

using Result_V1_0 = ::vendor::qti::hardware::btconfigstore::V1_0::Result;
using Result_V2_0 = ::vendor::qti::hardware::btconfigstore::V2_0::Result;
using VendorProperty_V1_0 = ::vendor::qti::hardware::btconfigstore::V1_0::VendorProperty;
using VendorProperty_V2_0 = ::vendor::qti::hardware::btconfigstore::V2_0::VendorProperty;
using IBTConfigStore_V1_0 = ::vendor::qti::hardware::btconfigstore::V1_0::IBTConfigStore;
using IBTConfigStore_V2_0 = ::vendor::qti::hardware::btconfigstore::V2_0::IBTConfigStore;


using ::android::hardware::ProcessState;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::hardware::hidl_vec;
using std::vector;

android::sp<IBTConfigStore_V1_0> btConfigStoreHal_1_0 = nullptr;
android::sp<IBTConfigStore_V2_0> btConfigStoreHal_2_0 = nullptr;

char gPlatformName[16] = {'\0'};
int gPlatformNameSize = 0;

static bool getControllerAddOnFeatures(controller_add_on_features_list_t *features_list);
static bool getHostAddOnFeatures(host_add_on_features_list_t *features_list);

static bool getVendorProperties(uint32_t type,
                                   std::vector<vendor_property_t> &vPropList);
static bool setVendorProperty(uint32_t type, const char * value);
static bool btConfigStoreLoadProperties(uint32_t vPropType,
                                                   std::vector<vendor_property_t> &vPropList);
static bt_soc_type_t convertSocNameToBTSocType(const char * name);
static const char * convertPropTypeToStringFormat(uint32_t propType);

const bool IsLazyHalSupported(property_get_bool("ro.vendor.bt.enablelazyhal", false));

EXPORT_SYMBOL bt_configstore_interface_t btConfigStoreInterface = {
    sizeof(btConfigStoreInterface),
    getVendorProperties,
    getControllerAddOnFeatures,
    getHostAddOnFeatures,
    setVendorProperty,
    convertSocNameToBTSocType,
    convertPropTypeToStringFormat,
};


/*******************************************************************************
**
** Function         getVendorProperties
**
** Description      This function is used to read predefined vendor properties from vendor module
**                  to system module It makes a binder call to hal daemon for reading properties.
**
** Parameters:      vPropType - is a vendor property type
**                  vPropList - is a referance vector of vendor property list
**
** Returns          bool
**
*******************************************************************************/
static bool getVendorProperties(uint32_t vPropType, std::vector<vendor_property_t> &vPropList)
{
  bool status = false;

  LOG_INFO(LOG_TAG, "%s ", __func__);
  btConfigStoreHal_2_0 = IBTConfigStore_V2_0::getService();


  if (btConfigStoreHal_2_0 != nullptr) {
    hidl_vec<VendorProperty_V2_0> vendorPropList;
    auto halResult = Result_V2_0::UNKNOWN_ERROR;
    auto cb = [&](Result_V2_0 result, hidl_vec<VendorProperty_V2_0> vendorPropListCb) {
      halResult = result;
      vendorPropList = vendorPropListCb;
    };

    btConfigStoreHal_2_0->getVendorProperties(vPropType, cb);
    if (halResult == Result_V2_0::SUCCESS) {
      for (auto&& vendorProp : vendorPropList) {
        vendor_property_t vProp;

        vProp.type = vendorProp.type;
        strlcpy(vProp.value, vendorProp.value.c_str(), sizeof(vProp.value));
        vPropList.push_back(vProp);
        LOG_INFO(LOG_TAG, "prop type: %s, prop_value: %s",
            convertPropTypeToStringFormat(vProp.type), vProp.value);
      }
      status = true;
    }

  } else {
    btConfigStoreHal_1_0 = IBTConfigStore_V1_0::getService();
    if (btConfigStoreHal_1_0 != nullptr) {
      hidl_vec<VendorProperty_V1_0> vendorPropList;
      auto halResult = Result_V1_0::UNKNOWN_ERROR;
      auto cb = [&](Result_V1_0 result, hidl_vec<VendorProperty_V1_0> vendorPropListCb) {
        halResult = result;
        vendorPropList = vendorPropListCb;
      };

      btConfigStoreHal_1_0->getVendorProperties(vPropType, cb);
      if (halResult == Result_V1_0::SUCCESS){
        for (auto&& vendorProp : vendorPropList) {
          vendor_property_t vProp;

          vProp.type = vendorProp.type;
          strlcpy(vProp.value, vendorProp.value.c_str(), sizeof(vProp.value));
          vPropList.push_back(vProp);
          LOG_INFO(LOG_TAG, "prop type: %s, prop_value: %s",
              convertPropTypeToStringFormat(vProp.type), vProp.value);
        }
        status = true;
      }
    } else {
        LOG_WARN(LOG_TAG,"%s btConfigStore hal interface is null", __func__);
        if (btConfigStoreLoadProperties(vPropType, vPropList)){
          LOG_INFO(LOG_TAG, "Properties are successfully read from %s",
              BT_CONFIG_STORE_PATH);

          status = true;
        }
    }
  }

  if (IsLazyHalSupported && (btConfigStoreHal_2_0 != nullptr
      || btConfigStoreHal_1_0 != nullptr))
    IPCThreadState::self()->flushCommands();

  btConfigStoreHal_2_0 = nullptr;
  btConfigStoreHal_1_0 = nullptr;

  return status;
}

/*******************************************************************************
**
** Function         setVendorProperty
**
** Description      This function is used to set predefined vendor properties from system module
**                  to vendor module It makes a binder call to hal daemon for setting properties.
**
** Parameters:      type - is a vendor property type.
**                  value - is a pointer to vendor property value.
**
** Returns          bool
**
*******************************************************************************/
static bool setVendorProperty(uint32_t type, const char * value)
{
  bool status = false;
  std::string vPropValue(value);

  LOG_INFO(LOG_TAG, "%s ", __func__);

  btConfigStoreHal_2_0 = IBTConfigStore_V2_0::getService();

  if (btConfigStoreHal_2_0 != nullptr) {
    VendorProperty_V2_0 vProp = {type, vPropValue};
    Result_V2_0 halResult = Result_V2_0::UNKNOWN_ERROR;

    halResult = btConfigStoreHal_2_0->setVendorProperty(vProp);

    LOG_INFO(LOG_TAG, "%s:: halResult = %d", __func__, halResult);

    if (halResult == Result_V2_0::SUCCESS){
      status = true;
    }
  } else {
    btConfigStoreHal_1_0 = IBTConfigStore_V1_0::getService();
    if (btConfigStoreHal_1_0 != nullptr) {
      VendorProperty_V1_0 vProp = {type, vPropValue};
      Result_V1_0 halResult = Result_V1_0::UNKNOWN_ERROR;

      halResult = btConfigStoreHal_1_0->setVendorProperty(vProp);

      LOG_INFO(LOG_TAG, "%s:: halResult = %d", __func__, halResult);

      if (halResult == Result_V1_0::SUCCESS) {
        status = true;
      }
    } else {
      LOG_WARN(LOG_TAG, "%s btConfigStore is null", __func__);
    }
  }

  if (IsLazyHalSupported && (btConfigStoreHal_2_0 != nullptr
      || btConfigStoreHal_1_0 != nullptr))
    IPCThreadState::self()->flushCommands();

  btConfigStoreHal_2_0 = nullptr;
  btConfigStoreHal_1_0 = nullptr;
  return status;
}

/*******************************************************************************
**
** Function         getControllerAddOnFeatures
**
** Description      This function is used to read BT controller add on features from bt config store
**                  hidl transport. It makes a binder call to hal daemon
**
** Parameters:      pointer to controller_add_on_features_list_t
**
**
** Returns          bool
**
*******************************************************************************/
static bool getControllerAddOnFeatures(controller_add_on_features_list_t *features_list)
{

  bool status = false;
  LOG_INFO(LOG_TAG, "%s ", __func__);

  btConfigStoreHal_2_0 = IBTConfigStore_V2_0::getService();

  if (btConfigStoreHal_2_0 != nullptr) {
    ControllerAddOnFeatures featureList;
    auto halResult = Result_V2_0::UNKNOWN_ERROR;
    auto cb = [&](Result_V2_0 result, ControllerAddOnFeatures featureListCb) {
      halResult = result;
      featureList = featureListCb;
    };

    auto hidlResult = btConfigStoreHal_2_0->getControllerAddOnFeatures(cb);

    LOG_INFO(LOG_TAG, "%s:: halResult = %d", __func__, halResult);

    if (hidlResult.isOk() && halResult == Result_V2_0::SUCCESS) {
      std::stringstream features;

      features_list->product_id = featureList.product_id;
      features_list->rsp_version = featureList.rsp_version;
      features_list->feat_mask_len = featureList.feat_mask_len;
      memcpy(features_list->features, featureList.features.data(),
          featureList.features.size());

      std::copy(features_list->features, features_list->features + features_list->feat_mask_len,
          std::ostream_iterator<int>(features << std::showbase <<std:: hex, " "));


      LOG_INFO(LOG_TAG,
          "%s:: product_id = %d, version = %d, feat_mask_len = %d features data: %s",
          __func__, features_list->product_id, features_list->rsp_version,
          features_list->feat_mask_len, features.str().c_str());
      status = true;
    }

  } else {
    btConfigStoreHal_1_0 = IBTConfigStore_V1_0::getService();
    if (btConfigStoreHal_1_0 != nullptr) {
      AddOnFeaturesList featureList;
      auto halResult = Result_V1_0::UNKNOWN_ERROR;
      auto cb = [&](Result_V1_0 result, AddOnFeaturesList featureListCb) {
        halResult = result;
        featureList = featureListCb;
      };

      auto hidlResult = btConfigStoreHal_1_0->getAddOnFeatures(cb);

      LOG_INFO(LOG_TAG, "%s:: halResult = %d", __func__, halResult);

      if (hidlResult.isOk() && halResult == Result_V1_0::SUCCESS) {
        std::stringstream features;

        features_list->product_id = featureList.product_id;
        features_list->rsp_version = featureList.rsp_version;
        features_list->feat_mask_len = featureList.feat_mask_len;
        memcpy(features_list->features, &featureList.features,
            features_list->feat_mask_len);

        std::copy(features_list->features, features_list->features + features_list->feat_mask_len,
            std::ostream_iterator<int>(features << std::showbase <<std:: hex, " "));

        LOG_INFO(LOG_TAG,
            "%s:: product_id = %d, version = %d, feat_mask_len = %d features data: %s",
            __func__, features_list->product_id, features_list->rsp_version,
            features_list->feat_mask_len, features.str().c_str());

        status = true;
      }
    }
  }

  if (IsLazyHalSupported && (btConfigStoreHal_2_0 != nullptr
      || btConfigStoreHal_1_0 != nullptr))
    IPCThreadState::self()->flushCommands();

  btConfigStoreHal_2_0 = nullptr;
  btConfigStoreHal_1_0 = nullptr;

  return status;
}

/*******************************************************************************
**
** Function         getHostAddOnFeatures
**
** Description      This function is used to read BT host add on features from bt config store
**                  hidl transport. It makes a binder call to hal daemon
**
** Parameters:      pointer to add_on_features_list_t
**
**
** Returns          bool
**
*******************************************************************************/
static bool getHostAddOnFeatures(host_add_on_features_list_t *features_list)
{
  bool status = false;

  LOG_INFO(LOG_TAG, "%s ", __func__);

  btConfigStoreHal_2_0 = IBTConfigStore_V2_0::getService();

  if (btConfigStoreHal_2_0 != nullptr) {
    HostAddOnFeatures featureList;
    auto halResult = Result_V2_0::UNKNOWN_ERROR;
    auto cb = [&](Result_V2_0 result, HostAddOnFeatures featureListCb) {
      halResult = result;
      featureList = featureListCb;
    };

    auto hidlResult = btConfigStoreHal_2_0->getHostAddOnFeatures(cb);

    LOG_INFO(LOG_TAG, "%s:: halResult = %d", __func__, halResult);

    if (hidlResult.isOk() && halResult == Result_V2_0::SUCCESS) {
      std::stringstream features;

      features_list->feat_mask_len = featureList.feat_mask_len;
      memcpy(features_list->features, featureList.features.data(),
          featureList.features.size());

      std::copy(features_list->features, features_list->features + features_list->feat_mask_len,
          std::ostream_iterator<int>(features << std::showbase <<std:: hex, " "));


      LOG_INFO(LOG_TAG, "%s:: feat_mask_len = %d features data: %s",
          __func__, features_list->feat_mask_len, features.str().c_str());
      status = true;
    }
  } else {
    LOG_WARN(LOG_TAG, "%s add on features is not avaliable", __func__);
  }

  if (IsLazyHalSupported && (btConfigStoreHal_2_0 != nullptr))
    IPCThreadState::self()->flushCommands();

  btConfigStoreHal_2_0 = nullptr;

  return status;
}

/*******************************************************************************
**
** Function         btConfigStoreLoadProperties
**
** Description      This function is used to read vendor properties from bt_configstore.conf
**
** Parameters:      vPropType - is a vendor property type
**                  vPropList - is a referance vector of vendor property list
**
** Returns          bool
**
*******************************************************************************/
static bool btConfigStoreLoadProperties(uint32_t vPropType,
        std::vector<vendor_property_t> &vPropList) {
  char tempPlatformName[16] = {'\0'};
  int fd;
  int status = false;

  if (gPlatformNameSize == 0) {
    fd = open("/sys/devices/soc0/chip_name", O_RDONLY);
    if (fd >= 0) {
      int ret = 0;

      if ((ret = read(fd, gPlatformName, sizeof(gPlatformName) - 1)) == -1) {
        LOG_ERROR(LOG_TAG, "Unable to read chip name");
        close(fd);
        return status;
      }

      if (ret > 0) {
        gPlatformNameSize = ret;
        LOG_INFO(LOG_TAG, "%s gPlatformNameSize: %d", __func__, gPlatformNameSize);
      }
    }
    close(fd);
  }

  config_t* config = config_new(BT_CONFIG_STORE_PATH);
  if (!config) {
    LOG_ERROR(LOG_TAG, "%s unable to load bt configstore '%s'.", __func__, BT_CONFIG_STORE_PATH);
    return status;
  }

  for (int i = 1; i <= MAX_PLATFORM_PROP_RECORD; ++i) {
    char section_name[16] = {0};
    snprintf(section_name, sizeof(section_name), "platform%d", i);

    if (!config_has_section(config, section_name)) {
      LOG_INFO(LOG_TAG, "%s no section named %s.", __func__, section_name);
      break;
    }

    strlcpy(tempPlatformName,
            config_get_string(config, section_name, "platformName", ""),
            sizeof(tempPlatformName));

    //platform name includes null terminted string,only compare till gPlatformNameSize-1
    if (strncmp(tempPlatformName, gPlatformName, gPlatformNameSize-1) != 0) {
      LOG_ERROR(LOG_TAG,
                "%s  platform name %s is not matched %s, ignoring platform record %d.",
                __func__, gPlatformName, tempPlatformName, i);
      continue;
    }

    vendor_property_t vProp;

    switch(vPropType) {
      case BT_PROP_ALL:
        vProp.type = BT_PROP_SOC_TYPE;
        strlcpy(vProp.value,
                config_get_string(config, section_name, "socName", "null"),
                sizeof(vProp.value));
        LOG_INFO(LOG_TAG, "%s:: prop type: %s, prop value: %s", __func__,
                convertPropTypeToStringFormat(vProp.type), vProp.value);
        vPropList.push_back(vProp);

        vProp.type = BT_PROP_A2DP_OFFLOAD_CAP;
        strlcpy(vProp.value,
                config_get_string(config, section_name, "a2dpOffloadCapability", "null"),
                sizeof(vProp.value));
        LOG_INFO(LOG_TAG, "%s:: prop type: %s, prop value: %s", __func__,
                convertPropTypeToStringFormat(vProp.type), vProp.value);
        vPropList.push_back(vProp);

        vProp.type = BT_PROP_SPILT_A2DP;
        strlcpy(vProp.value,
                config_get_string(config, section_name, "spiltA2dpSupported", "null"),
                sizeof(vProp.value));
        LOG_INFO(LOG_TAG, "%s:: prop type: %s, prop value: %s", __func__,
                convertPropTypeToStringFormat(vProp.type), vProp.value);
        vPropList.push_back(vProp);

        vProp.type = BT_PROP_AAC_FRAME_CTL;
        strlcpy(vProp.value,
                config_get_string(config, section_name, "aacFrameCtlEnabled", "null"),
                sizeof(vProp.value));
        LOG_INFO(LOG_TAG, "%s:: prop type: %s, prop value: %s", __func__,
                  convertPropTypeToStringFormat(vProp.type), vProp.value);
        vPropList.push_back(vProp);

        vProp.type = BT_PROP_WIPOWER;
        strlcpy(vProp.value,
                config_get_string(config, section_name, "wiPowerSupported", "null"),
                sizeof(vProp.value));
        LOG_INFO(LOG_TAG, "%s:: prop type: %s, prop value: %s", __func__,
                convertPropTypeToStringFormat(vProp.type), vProp.value);
        vPropList.push_back(vProp);

        vProp.type = BT_PROP_A2DP_MCAST_TEST;
        strlcpy(vProp.value,
                config_get_string(config, section_name, "a2dpMcastSupported", "null"),
                sizeof(vProp.value));
        LOG_INFO(LOG_TAG, "%s:: prop type: %s, prop value: %s", __func__,
                convertPropTypeToStringFormat(vProp.type), vProp.value);
        vPropList.push_back(vProp);

        vProp.type = BT_PROP_TWSP_STATE;
        strlcpy(vProp.value,
                config_get_string(config, section_name, "twspStateSupported", "null"),
                sizeof(vProp.value));
        LOG_INFO(LOG_TAG, "%s:: prop type: %s, prop value: %s", __func__,
                convertPropTypeToStringFormat(vProp.type), vProp.value);
        vPropList.push_back(vProp);
        break;

      case BT_PROP_SOC_TYPE:
        vProp.type = BT_PROP_SOC_TYPE;
        strlcpy(vProp.value,
                config_get_string(config, section_name, "socName", "null"),
                sizeof(vProp.value));
        LOG_INFO(LOG_TAG, "%s:: prop type: %s, prop value: %s", __func__,
                convertPropTypeToStringFormat(vProp.type), vProp.value);
        vPropList.push_back(vProp);
        break;

      case BT_PROP_A2DP_OFFLOAD_CAP:
        vProp.type = BT_PROP_A2DP_OFFLOAD_CAP;
        strlcpy(vProp.value,
                config_get_string(config, section_name, "a2dpOffloadCapability", "null"),
                sizeof(vProp.value));
        LOG_INFO(LOG_TAG, "%s:: prop type: %s, prop value: %s", __func__,
                convertPropTypeToStringFormat(vProp.type), vProp.value);
        vPropList.push_back(vProp);
        break;

      case BT_PROP_SPILT_A2DP:
        vProp.type = BT_PROP_SPILT_A2DP;
        strlcpy(vProp.value,
                config_get_string(config, section_name, "spiltA2dpSupported", "null"),
                sizeof(vProp.value));
        LOG_INFO(LOG_TAG, "%s:: prop type: %s, prop value: %s", __func__,
                convertPropTypeToStringFormat(vProp.type), vProp.value);
        vPropList.push_back(vProp);
        break;

      case BT_PROP_AAC_FRAME_CTL:
        vProp.type = BT_PROP_AAC_FRAME_CTL;
        strlcpy(vProp.value,
                config_get_string(config, section_name, "aacFrameCtlEnabled", "null"),
                sizeof(vProp.value));
        LOG_INFO(LOG_TAG, "%s:: prop type: %s, prop value: %s", __func__,
                  convertPropTypeToStringFormat(vProp.type), vProp.value);
        vPropList.push_back(vProp);
        break;

      case BT_PROP_WIPOWER:
        vProp.type = BT_PROP_WIPOWER;
        strlcpy(vProp.value,
                config_get_string(config, section_name, "wiPowerSupported", "null"),
                sizeof(vProp.value));
        LOG_INFO(LOG_TAG, "%s:: prop type: %s, prop value: %s", __func__,
                convertPropTypeToStringFormat(vProp.type), vProp.value);
        vPropList.push_back(vProp);
        break;
      case BT_PROP_A2DP_MCAST_TEST:
        vProp.type = BT_PROP_A2DP_MCAST_TEST;
        strlcpy(vProp.value,
                config_get_string(config, section_name, "a2dpMcastSupported", "null"),
                sizeof(vProp.value));
        LOG_INFO(LOG_TAG, "%s:: prop type: %s, prop value: %s", __func__,
                convertPropTypeToStringFormat(vProp.type), vProp.value);
        vPropList.push_back(vProp);
        break;

      case BT_PROP_TWSP_STATE:
        vProp.type = BT_PROP_TWSP_STATE;
        strlcpy(vProp.value,
                config_get_string(config, section_name, "twspStateSupported", "null"),
                sizeof(vProp.value));
        LOG_INFO(LOG_TAG, "%s:: prop type: %s, prop value: %s", __func__,
                convertPropTypeToStringFormat(vProp.type), vProp.value);
        vPropList.push_back(vProp);
        break;

      default:
        LOG_INFO(LOG_TAG, "%s:: prop type not handled %d", __func__, vPropType);
        config_free(config);
        return status;
    }

    status = true;
    break;
  }

  config_free(config);
  return status;
}

/*******************************************************************************
**
** Function         convertSocNameToBTSocType
**
** Description      This function is used to convert bt soc name to soc type
**
** Parameters:      soc_name - is a pointer to char
**
** Returns          bt_soc_type_t - soc type
**
*******************************************************************************/
static bt_soc_type_t convertSocNameToBTSocType(const char * soc_name)
{
  bt_soc_type_t soc_type;
  if (!strncasecmp(soc_name, "rome", sizeof("rome"))) {
    soc_type = BT_SOC_TYPE_ROME;
  } else if (!strncasecmp(soc_name, "cherokee", sizeof("cherokee"))) {
    soc_type = BT_SOC_TYPE_CHEROKEE;
  } else if (!strncasecmp(soc_name, "ath3k", sizeof("ath3k"))) {
    soc_type = BT_SOC_TYPE_AR3K;
  } else if (!strncasecmp(soc_name, "hastings", sizeof("hastings"))) {
    soc_type = BT_SOC_TYPE_HASTINGS;
  } else if (!strncasecmp(soc_name, "moselle", sizeof("moselle"))) {
    soc_type = BT_SOC_TYPE_MOSELLE;
  } else if (!strncasecmp(soc_name, "hamilton", sizeof("hamilton"))) {
    soc_type = BT_SOC_TYPE_HAMILTON;
  } else if (!strncasecmp(soc_name, "pronto", sizeof("pronto"))) {
    soc_type = BT_SOC_TYPE_DEFAULT;
  } else {
    LOG_INFO(LOG_TAG, "not set, so using pronto");
    soc_type = BT_SOC_TYPE_DEFAULT;
  }

  LOG_INFO(LOG_TAG, "soc_name: %s, soc_type = %04x", soc_name, soc_type);
  return soc_type;
}

/*******************************************************************************
**
** Function         convertPropTypeToStringFormat
**
** Description      This function is used to convert property type to string format
**
** Parameters:      propType - is a vendor property type
**
** Returns          const char * - pointer to const char
**
*******************************************************************************/
static const char * convertPropTypeToStringFormat(uint32_t propType){

  switch (propType){
    case BT_PROP_ALL:
      return "BT_PROP_ALL";

    case BT_PROP_SOC_TYPE:
      return "BT_PROP_SOC_TYPE";

    case BT_PROP_A2DP_OFFLOAD_CAP:
      return "BT_PROP_A2DP_OFFLOAD_CAP";

    case BT_PROP_SPILT_A2DP:
      return "BT_PROP_SPILT_A2DP";

    case BT_PROP_AAC_FRAME_CTL:
      return "BT_PROP_AAC_FRAME_CTL";

    case BT_PROP_WIPOWER:
      return "BT_PROP_WIPOWER";

    case FM_PROP_NOTCH_VALUE:
      return "FM_PROP_NOTCH_VALUE";

    case FM_PROP_HW_INIT:
      return "FM_PROP_HW_INIT";

    case FM_PROP_HW_MODE:
      return "FM_PROP_HW_MODE";

    case FM_PROP_CTL_START:
      return "FM_PROP_CTL_START";

    case FM_PROP_CTL_STOP:
      return "FM_PROP_CTL_STOP";

    default:
      LOG_INFO(LOG_TAG, " not handled propType = %d", propType);
      return "not handled";
  }
}

