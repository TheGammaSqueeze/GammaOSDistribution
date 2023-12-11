/*
 * Copyright (C) 2013,2016-2017 The Linux Foundation. All rights reserved
 * Not a Contribution.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted (subject to the limitations in the
 * disclaimer below) provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *
 * * Neither the name of The Linux Foundation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE
 * GRANTED BY THIS LICENSE. THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT
 * HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

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

#define LOG_TAG "BluetoothVendorJni"

#include "com_android_bluetooth.h"
#include <hardware/vendor.h>
#include "utils/Log.h"
#include "android_runtime/AndroidRuntime.h"
#include <cutils/properties.h>
#include "bt_configstore.h"
#include <vector>
#include <dlfcn.h>
#include <shared_mutex>

namespace android {
int load_bt_configstore_lib();

static jmethodID method_onBredrCleanup;
static jmethodID method_iotDeviceBroadcast;
static jmethodID method_bqrDeliver;
static jmethodID method_devicePropertyChangedCallback;
static jmethodID method_adapterPropertyChangedCallback;
static jmethodID method_ssrCleanupCallback;
static jmethodID method_whitelistedPlayersChangedCallback;


static btvendor_interface_t *sBluetoothVendorInterface = NULL;
static jobject mCallbacksObj = NULL;

static std::shared_timed_mutex interface_mutex;

static char soc_name[16];
static char a2dp_offload_Cap[PROPERTY_VALUE_MAX] = {'\0'};
static bt_configstore_interface_t* bt_configstore_intf = NULL;
static void *bt_configstore_lib_handle = NULL;
static jboolean spilt_a2dp_supported;
static jboolean swb_supported;
static jboolean swb_pm_supported;

static int get_properties(int num_properties, bt_vendor_property_t* properties,
                          jintArray* types, jobjectArray* props) {
  CallbackEnv sCallbackEnv(__func__);
  if (!sCallbackEnv.valid()) return -1;
    for (int i = 0; i < num_properties; i++) {
    ScopedLocalRef<jbyteArray> propVal(
        sCallbackEnv.get(), sCallbackEnv->NewByteArray(properties[i].len));
    if (!propVal.get()) {
      ALOGE("Error while allocation of array in %s", __func__);
      return -1;
    }


    sCallbackEnv->SetByteArrayRegion(propVal.get(), 0, properties[i].len,
                                    (jbyte*)properties[i].val);
    sCallbackEnv->SetObjectArrayElement(*props, i, propVal.get());
    sCallbackEnv->SetIntArrayRegion(*types, i, 1, (jint*)&properties[i].type);
  }
  return 0;
}

static int property_set_callout(const char* key, const char* value) {
    return property_set(key, value);
}

static int property_get_callout(const char* key, char* value, const char* default_value) {
    return property_get(key, value, default_value);
}

static int32_t property_get_int32_callout(const char* key, int32_t default_value) {
    return property_get_int32(key, default_value);
}

static bt_property_callout_t sBluetoothPropertyCallout = {
    sizeof(sBluetoothPropertyCallout), property_set_callout,
    property_get_callout, property_get_int32_callout,
};

static void bredr_cleanup_callback(bool status){

    ALOGI("%s", __FUNCTION__);
    CallbackEnv sCallbackEnv(__func__);

    if (!sCallbackEnv.valid()) return;

    sCallbackEnv->CallVoidMethod(mCallbacksObj, method_onBredrCleanup, (jboolean)status);
}

static void ssr_cleanup_callback(void){

    ALOGI("%s", __FUNCTION__);
    CallbackEnv sCallbackEnv(__func__);

    if (!sCallbackEnv.valid()) return;

    sCallbackEnv->CallVoidMethod(mCallbacksObj, method_ssrCleanupCallback);
}

static void iot_device_broadcast_callback(RawAddress* bd_addr, uint16_t error,
        uint16_t error_info, uint32_t event_mask, uint8_t lmp_ver, uint16_t lmp_subver,
        uint16_t manufacturer_id, uint8_t power_level, int8_t rssi, uint8_t link_quality,
        uint16_t glitch_count){
    ALOGI("%s", __FUNCTION__);
    CallbackEnv sCallbackEnv(__func__);
    if (!sCallbackEnv.valid()) return;
    ScopedLocalRef<jbyteArray> addr(
    sCallbackEnv.get(), sCallbackEnv->NewByteArray(sizeof(RawAddress)));
    if (!addr.get()) {
        ALOGE("Error while allocation byte array in %s", __func__);
        return;
    }
    sCallbackEnv->SetByteArrayRegion(addr.get(), 0, sizeof(RawAddress),
                               (jbyte*)bd_addr);
    sCallbackEnv->CallVoidMethod(mCallbacksObj, method_iotDeviceBroadcast, addr.get(), (jint)error,
                    (jint)error_info, (jint)event_mask, (jint)lmp_ver, (jint)lmp_subver,
                    (jint)manufacturer_id, (jint)power_level, (jint)rssi, (jint)link_quality,
                    (jint)glitch_count);
}

static void bqr_delivery_callback(RawAddress* bd_addr, uint8_t lmp_ver, uint16_t lmp_subver,
        uint16_t manufacturer_id, std::vector<uint8_t> bqr_raw_data) {
  ALOGI("%s", __func__);
  CallbackEnv sCallbackEnv(__func__);
  if (!sCallbackEnv.valid()) return;

  ScopedLocalRef<jbyteArray> addr(
      sCallbackEnv.get(), sCallbackEnv->NewByteArray(sizeof(RawAddress)));
  if (!addr.get()) {
    ALOGE("Error while allocation byte array for addr in %s", __func__);
    return;
  }
  sCallbackEnv->SetByteArrayRegion(addr.get(), 0, sizeof(RawAddress),
      (jbyte*)bd_addr->address);

  ScopedLocalRef<jbyteArray> raw_data(
      sCallbackEnv.get(), sCallbackEnv->NewByteArray(bqr_raw_data.size()));
  if (!raw_data.get()) {
    ALOGE("Error while allocation byte array for bqr raw data in %s", __func__);
    return;
  }
  sCallbackEnv->SetByteArrayRegion(raw_data.get(), 0, bqr_raw_data.size(),
      (jbyte*)bqr_raw_data.data());

  sCallbackEnv->CallVoidMethod(mCallbacksObj, method_bqrDeliver, addr.get(),
      (jint)lmp_ver, (jint)lmp_subver, (jint)manufacturer_id, raw_data.get());
}

static void adapter_vendor_properties_callback(bt_status_t status,
                          int num_properties,
                          bt_vendor_property_t *properties) {
  CallbackEnv sCallbackEnv(__func__);
  if (!sCallbackEnv.valid()) return;
  ALOGE("%s: Status is: %d, Properties: %d", __func__, status, num_properties);
  if (status != BT_STATUS_SUCCESS) {
    ALOGE("%s: Status %d is incorrect", __func__, status);
    return;
  }
  ScopedLocalRef<jbyteArray> val(
      sCallbackEnv.get(),
      (jbyteArray)sCallbackEnv->NewByteArray(num_properties));
  if (!val.get()) {
    ALOGE("%s: Error allocating byteArray", __func__);
    return;
  }
  ScopedLocalRef<jclass> mclass(sCallbackEnv.get(),
                                sCallbackEnv->GetObjectClass(val.get()));
  ScopedLocalRef<jobjectArray> props(
      sCallbackEnv.get(),
      sCallbackEnv->NewObjectArray(num_properties, mclass.get(), NULL));
  if (!props.get()) {
    ALOGE("%s: Error allocating object Array for properties", __func__);
    return;
  }
  ScopedLocalRef<jintArray> types(
      sCallbackEnv.get(), (jintArray)sCallbackEnv->NewIntArray(num_properties));
  if (!types.get()) {
    ALOGE("%s: Error allocating int Array for values", __func__);
    return;
  }
  jintArray typesPtr = types.get();
  jobjectArray propsPtr = props.get();
  if (get_properties(num_properties, properties, &typesPtr, &propsPtr) < 0) {
    return;
  }
  sCallbackEnv->CallVoidMethod(mCallbacksObj,
                               method_adapterPropertyChangedCallback,
                               types.get(), props.get());
}

static void whitelisted_players_properties_callback(bt_status_t status,
                          int num_properties,
                          bt_vendor_property_t *properties) {
  CallbackEnv sCallbackEnv(__func__);
  if (!sCallbackEnv.valid()) return;
  ALOGE("%s: Status is: %d, Properties: %d", __func__, status, num_properties);
  if (status != BT_STATUS_SUCCESS) {
    ALOGE("%s: Status %d is incorrect", __func__, status);
    return;
  }
  ScopedLocalRef<jbyteArray> val(
      sCallbackEnv.get(),
      (jbyteArray)sCallbackEnv->NewByteArray(num_properties));
  if (!val.get()) {
    ALOGE("%s: Error allocating byteArray", __func__);
    return;
  }
  ScopedLocalRef<jclass> mclass(sCallbackEnv.get(),
                                sCallbackEnv->GetObjectClass(val.get()));
  ScopedLocalRef<jobjectArray> props(
      sCallbackEnv.get(),
      sCallbackEnv->NewObjectArray(num_properties, mclass.get(), NULL));
  if (!props.get()) {
    ALOGE("%s: Error allocating object Array for properties", __func__);
    return;
  }
  ScopedLocalRef<jintArray> types(
      sCallbackEnv.get(), (jintArray)sCallbackEnv->NewIntArray(num_properties));
  if (!types.get()) {
    ALOGE("%s: Error allocating int Array for values", __func__);
    return;
  }
  jintArray typesPtr = types.get();
  jobjectArray propsPtr = props.get();
  if (get_properties(num_properties, properties, &typesPtr, &propsPtr) < 0) {
    return;
  }
  sCallbackEnv->CallVoidMethod(mCallbacksObj,
                               method_whitelistedPlayersChangedCallback,
                               types.get(), props.get());
}

static void remote_device_properties_callback(bt_status_t status,
                          RawAddress *bd_addr, int num_properties,
                          bt_vendor_property_t *properties) {
  CallbackEnv sCallbackEnv(__func__);
  if (!sCallbackEnv.valid()) return;
  ALOGE("%s: Status is: %d, Properties: %d", __func__, status, num_properties);
  if (status != BT_STATUS_SUCCESS) {
    ALOGE("%s: Status %d is incorrect", __func__, status);
    return;
  }
  ScopedLocalRef<jbyteArray> val(
      sCallbackEnv.get(),
      (jbyteArray)sCallbackEnv->NewByteArray(num_properties));
  if (!val.get()) {
    ALOGE("%s: Error allocating byteArray", __func__);
    return;
  }
  ScopedLocalRef<jclass> mclass(sCallbackEnv.get(),
                                sCallbackEnv->GetObjectClass(val.get()));
  ScopedLocalRef<jobjectArray> props(
      sCallbackEnv.get(),
      sCallbackEnv->NewObjectArray(num_properties, mclass.get(), NULL));
  if (!props.get()) {
    ALOGE("%s: Error allocating object Array for properties", __func__);
    return;
  }
  ScopedLocalRef<jintArray> types(
      sCallbackEnv.get(), (jintArray)sCallbackEnv->NewIntArray(num_properties));
  if (!types.get()) {
    ALOGE("%s: Error allocating int Array for values", __func__);
    return;
  }
  ScopedLocalRef<jbyteArray> addr(
      sCallbackEnv.get(), sCallbackEnv->NewByteArray(sizeof(RawAddress)));
  if (!addr.get()) {
    ALOGE("Error while allocation byte array in %s", __func__);
    return;
  }
  sCallbackEnv->SetByteArrayRegion(addr.get(), 0, sizeof(RawAddress),
                                   (jbyte*)bd_addr);
  jintArray typesPtr = types.get();
  jobjectArray propsPtr = props.get();
  if (get_properties(num_properties, properties, &typesPtr, &propsPtr) < 0) {
    return;
  }
  sCallbackEnv->CallVoidMethod(mCallbacksObj,
                               method_devicePropertyChangedCallback, addr.get(),
                               types.get(), props.get());
}

static btvendor_callbacks_t sBluetoothVendorCallbacks = {
    sizeof(sBluetoothVendorCallbacks),
    bredr_cleanup_callback,
    iot_device_broadcast_callback,
    bqr_delivery_callback,
    remote_device_properties_callback,
    NULL,
    adapter_vendor_properties_callback,
    ssr_cleanup_callback,
    whitelisted_players_properties_callback,
};

static void classInitNative(JNIEnv* env, jclass clazz) {

    method_onBredrCleanup = env->GetMethodID(clazz, "onBredrCleanup", "(Z)V");
    method_iotDeviceBroadcast = env->GetMethodID(clazz, "iotDeviceBroadcast", "([BIIIIIIIIII)V");
    method_bqrDeliver = env->GetMethodID(clazz, "bqrDeliver", "([BIII[B)V");
    method_devicePropertyChangedCallback = env->GetMethodID(
      clazz, "devicePropertyChangedCallback", "([B[I[[B)V");
    method_adapterPropertyChangedCallback = env->GetMethodID(
      clazz, "adapterPropertyChangedCallback", "([I[[B)V");
    method_ssrCleanupCallback = env->GetMethodID(
      clazz, "ssr_cleanup_callback", "()V");
    method_whitelistedPlayersChangedCallback = env->GetMethodID(
      clazz, "whitelistedPlayersChangedCallback", "([I[[B)V");
    ALOGI("%s: succeeds", __FUNCTION__);
}

static void initNative(JNIEnv *env, jobject object) {
    const bt_interface_t* btInf;
    bt_status_t status;

    std::unique_lock<std::shared_timed_mutex> interface_lock(interface_mutex);

    load_bt_configstore_lib();

    if (bt_configstore_intf != NULL) {
       std::vector<vendor_property_t> vPropList;

       bt_configstore_intf->get_vendor_properties(BT_PROP_ALL, vPropList);
       for (auto&& vendorProp : vPropList) {
          if (vendorProp.type == BT_PROP_SOC_TYPE) {
            strlcpy(soc_name, vendorProp.value, sizeof(soc_name));
            ALOGI("%s:: soc_name = %s",__func__, soc_name);
          } else if(vendorProp.type == BT_PROP_SPILT_A2DP) {
            if (!strncasecmp(vendorProp.value, "true", sizeof("true"))) {
              spilt_a2dp_supported = true;
            } else {
              spilt_a2dp_supported = false;
            }
          } else if(vendorProp.type == BT_PROP_SWB_ENABLE) {
            if (!strncasecmp(vendorProp.value, "true", sizeof("true"))) {
              swb_supported = true;
            } else {
              swb_supported = false;
            }
          } else if(vendorProp.type == BT_PROP_SWBPM_ENABLE) {
            if (!strncasecmp(vendorProp.value, "true", sizeof("true"))) {
              swb_pm_supported = true;
            } else {
              swb_pm_supported = false;
            }
          } else if(vendorProp.type == BT_PROP_A2DP_OFFLOAD_CAP) {
            strlcpy(a2dp_offload_Cap, vendorProp.value, sizeof(a2dp_offload_Cap));
            ALOGI("%s:: a2dp_offload_Cap = %s", __func__, a2dp_offload_Cap);
          }
       }
    }

    if ( (btInf = getBluetoothInterface()) == NULL) {
        ALOGE("Bluetooth module is not loaded");
        return;
    }

    if (mCallbacksObj != NULL) {
        ALOGW("Cleaning up Bluetooth Vendor callback object");
        env->DeleteGlobalRef(mCallbacksObj);
        mCallbacksObj = NULL;
    }

    if ( (sBluetoothVendorInterface = (btvendor_interface_t *)
          btInf->get_profile_interface(BT_PROFILE_VENDOR_ID)) == NULL) {
        ALOGE("Failed to get Bluetooth Vendor Interface");
        return;
    }

    if ( (status = sBluetoothVendorInterface->init(&sBluetoothVendorCallbacks))
                 != BT_STATUS_SUCCESS) {
        ALOGE("Failed to initialize Bluetooth Vendor, status: %d", status);
        sBluetoothVendorInterface = NULL;
        return;
    }
    mCallbacksObj = env->NewGlobalRef(object);
    sBluetoothVendorInterface->set_property_callouts(&sBluetoothPropertyCallout);
}

static void cleanupNative(JNIEnv *env, jobject object) {
    const bt_interface_t* btInf;

    std::unique_lock<std::shared_timed_mutex> interface_lock(interface_mutex);

    if (bt_configstore_lib_handle) {
      dlclose(bt_configstore_lib_handle);
      bt_configstore_lib_handle = NULL;
      bt_configstore_intf = NULL;
    }

    if ( (btInf = getBluetoothInterface()) == NULL) {
        ALOGE("Bluetooth module is not loaded");
        return;
    }

    if (sBluetoothVendorInterface !=NULL) {
        ALOGW("Cleaning up Bluetooth Vendor Interface...");
        sBluetoothVendorInterface->cleanup();
        sBluetoothVendorInterface = NULL;
    }

    if (mCallbacksObj != NULL) {
        ALOGW("Cleaning up Bluetooth Vendor callback object");
        env->DeleteGlobalRef(mCallbacksObj);
        mCallbacksObj = NULL;
    }

}

static bool informTimeoutToHidlNative(JNIEnv *env, jobject obj) {

    ALOGI("%s", __FUNCTION__);

    if ((bt_configstore_lib_handle && bt_configstore_intf) ||
        !load_bt_configstore_lib()) {
      bt_configstore_intf->set_vendor_property(BT_PROP_STACK_TIMEOUT, "true");
      dlclose(bt_configstore_lib_handle);
      bt_configstore_lib_handle = NULL;
      bt_configstore_intf = NULL;
    } else {
      ALOGE("%s: Failed to inform to HIDL about timeout", __FUNCTION__);
    }

    return JNI_TRUE;
}

static bool bredrcleanupNative(JNIEnv *env, jobject obj) {

    ALOGI("%s", __FUNCTION__);

    jboolean result = JNI_FALSE;

    if (bt_configstore_lib_handle) {
      dlclose(bt_configstore_lib_handle);
      bt_configstore_lib_handle = NULL;
      bt_configstore_intf = NULL;
    }

    if (!sBluetoothVendorInterface) return result;

    sBluetoothVendorInterface->bredrcleanup();
    return JNI_TRUE;
}

static bool bredrstartupNative(JNIEnv *env, jobject obj) {

    ALOGI("%s", __FUNCTION__);

    jboolean result = JNI_FALSE;
    if (!sBluetoothVendorInterface) return result;

    sBluetoothVendorInterface->bredrstartup();
    return JNI_TRUE;
}

static bool hcicloseNative(JNIEnv *env, jobject obj) {

    ALOGI("%s", __FUNCTION__);

    jboolean result = JNI_FALSE;
    if (!sBluetoothVendorInterface) return result;

    sBluetoothVendorInterface->hciclose();
    return JNI_TRUE;
}

static bool setWifiStateNative(JNIEnv *env, jobject obj, jboolean status) {

    ALOGI("%s", __FUNCTION__);

    jboolean result = JNI_FALSE;
    if (!sBluetoothVendorInterface) return result;

    sBluetoothVendorInterface->set_wifi_state(status);
    return JNI_TRUE;
}

static bool setPowerBackoffNative(JNIEnv *env, jobject obj, jboolean status) {

    ALOGI("%s", __FUNCTION__);

    jboolean result = JNI_FALSE;
    if (!sBluetoothVendorInterface) return result;

    sBluetoothVendorInterface->set_Power_back_off_state(status);
    return JNI_TRUE;
}

static bool getProfileInfoNative(JNIEnv *env, jobject obj, jint profile_id , jint profile_info) {

    ALOGI("%s", __FUNCTION__);

    jboolean result = JNI_FALSE;

    if (!sBluetoothVendorInterface) return result;

    result = sBluetoothVendorInterface->get_profile_info((profile_t)profile_id, (profile_info_t)profile_info);

    return result;
}

static bool getQtiStackStatusNative() {
    return (sBluetoothVendorInterface != NULL);
}

static jboolean voipNetworkWifiInfoNative(JNIEnv *env, jobject object,
                                           jboolean isVoipStarted, jboolean isNetworkWifi) {
    bt_status_t status;
    if (!sBluetoothVendorInterface) return JNI_FALSE;

    ALOGE("In voipNetworkWifiInfoNative");
    if ( (status = sBluetoothVendorInterface->voip_network_type_wifi(isVoipStarted ?
            BTHF_VOIP_STATE_STARTED : BTHF_VOIP_STATE_STOPPED, isNetworkWifi ?
            BTHF_VOIP_CALL_NETWORK_TYPE_WIFI : BTHF_VOIP_CALL_NETWORK_TYPE_MOBILE))
            != BT_STATUS_SUCCESS) {
        ALOGE("Failed sending VOIP network type, status: %d", status);
    }
    return (status == BT_STATUS_SUCCESS) ? JNI_TRUE : JNI_FALSE;
}

static jstring getSocNameNative(JNIEnv* env) {

    ALOGI("%s", __FUNCTION__);

    return env->NewStringUTF(soc_name);
}

static jstring getA2apOffloadCapabilityNative(JNIEnv* env) {

    ALOGI("%s", __FUNCTION__);

    return env->NewStringUTF(a2dp_offload_Cap);
}

static jboolean isSplitA2dpEnabledNative(JNIEnv* env) {

    ALOGI("%s", __FUNCTION__);
    return spilt_a2dp_supported;
}

static jboolean isSwbEnabledNative(JNIEnv* env) {

    ALOGI("%s", __FUNCTION__);
    return swb_supported;
}

static jboolean isSwbPmEnabledNative(JNIEnv* env) {

    ALOGI("%s", __FUNCTION__);
    return swb_pm_supported;
}

static jboolean setClockSyncConfigNative(JNIEnv* env, jobject object, jboolean enable, jint mode,
    jint adv_interval, jint channel, jint jitter, jint offset)
{
    if (!sBluetoothVendorInterface) return false;
    return (jboolean)sBluetoothVendorInterface->set_clock_sync_config(enable, mode, adv_interval,
        channel, jitter, offset);
}

static jboolean startClockSyncNative(JNIEnv* env)
{
    if (!sBluetoothVendorInterface) return false;
    sBluetoothVendorInterface->start_clock_sync();
    return true;
}

static bluetooth::Uuid from_java_uuid(jlong uuid_msb, jlong uuid_lsb) {
  std::array<uint8_t, bluetooth::Uuid::kNumBytes128> uu{};
  for (int i = 0; i < 8; i++) {
    uu[7 - i] = (uuid_msb >> (8 * i)) & 0xFF;
    uu[15 - i] = (uuid_lsb >> (8 * i)) & 0xFF;
  }
  return bluetooth::Uuid::From128BitBE(uu);
}

static void registerUuidSrvcDiscNative(JNIEnv* env, jobject obj,
                                        jlong uuid_lsb,
                                        jlong uuid_msb) {
  ALOGV("%s", __func__);

  bluetooth::Uuid uuid = from_java_uuid(uuid_msb, uuid_lsb);

  sBluetoothVendorInterface->register_uuid_srvc_disc(uuid);
}

static jboolean interopMatchAddrNative(JNIEnv* env, jclass clazz,
      jstring feature_name, jstring address) {
  ALOGV("%s", __func__);

  std::shared_lock<std::shared_timed_mutex> lock(interface_mutex);

  if (!sBluetoothVendorInterface) {
    ALOGW("%s: sBluetoothVendorInterface is null.", __func__);
    return JNI_FALSE;
  }

  const char* tmp_addr = env->GetStringUTFChars(address, NULL);
  if (!tmp_addr) {
    ALOGW("%s: address is null.", __func__);
    return JNI_FALSE;
  }
  RawAddress bdaddr;
  bool success = RawAddress::FromString(tmp_addr, bdaddr);

  env->ReleaseStringUTFChars(address, tmp_addr);

  if (!success) {
    ALOGW("%s: address is invalid.", __func__);
    return JNI_FALSE;
  }

  const char* feature_name_str = env->GetStringUTFChars(feature_name, NULL);
  if (!feature_name_str) {
    ALOGW("%s: feature name is null.", __func__);
    return JNI_FALSE;
  }

  bool matched = sBluetoothVendorInterface->interop_match_addr(feature_name_str, &bdaddr);
  env->ReleaseStringUTFChars(feature_name, feature_name_str);

  return matched ? JNI_TRUE : JNI_FALSE;
}

static jboolean interopMatchNameNative(JNIEnv* env, jclass clazz,
      jstring feature_name, jstring name) {
  ALOGV("%s", __func__);

  std::shared_lock<std::shared_timed_mutex> lock(interface_mutex);

  if (!sBluetoothVendorInterface) {
    ALOGW("%s: sBluetoothVendorInterface is null.", __func__);
    return JNI_FALSE;
  }

  const char* feature_name_str = env->GetStringUTFChars(feature_name, NULL);
  if (!feature_name_str) {
    ALOGW("%s: feature name is null.", __func__);
    return JNI_FALSE;
  }

  const char* name_str = env->GetStringUTFChars(name, NULL);
  if (!name_str) {
    ALOGW("%s: name is null.", __func__);
    env->ReleaseStringUTFChars(feature_name, feature_name_str);
    return JNI_FALSE;
  }

  bool matched = sBluetoothVendorInterface->interop_match_name(feature_name_str, name_str);
  env->ReleaseStringUTFChars(feature_name, feature_name_str);
  env->ReleaseStringUTFChars(name, name_str);

  return matched ? JNI_TRUE : JNI_FALSE;
}

static jboolean interopMatchAddrOrNameNative(JNIEnv* env, jclass clazz,
      jstring feature_name, jstring address) {
  ALOGV("%s", __func__);

  std::shared_lock<std::shared_timed_mutex> lock(interface_mutex);

  if (!sBluetoothVendorInterface) {
    ALOGW("%s: sBluetoothVendorInterface is null.", __func__);
    return JNI_FALSE;
  }

  const char* tmp_addr = env->GetStringUTFChars(address, NULL);
  if (!tmp_addr) {
    ALOGW("%s: address is null.", __func__);
    return JNI_FALSE;
  }
  RawAddress bdaddr;
  bool success = RawAddress::FromString(tmp_addr, bdaddr);

  env->ReleaseStringUTFChars(address, tmp_addr);

  if (!success) {
    ALOGW("%s: address is invalid.", __func__);
    return JNI_FALSE;
  }

  const char* feature_name_str = env->GetStringUTFChars(feature_name, NULL);
  if (!feature_name_str) {
    ALOGW("%s: feature name is null.", __func__);
    return JNI_FALSE;
  }

  bool matched = sBluetoothVendorInterface->interop_match_addr_or_name(feature_name_str, &bdaddr);
  env->ReleaseStringUTFChars(feature_name, feature_name_str);

  return matched ? JNI_TRUE : JNI_FALSE;
}

static void interopDatabaseAddRemoveAddrNative(JNIEnv* env, jclass clazz,
      jboolean do_add, jstring feature_name, jstring address, jint length) {
  ALOGV("%s", __func__);

  std::shared_lock<std::shared_timed_mutex> lock(interface_mutex);

  if (!sBluetoothVendorInterface) {
    ALOGW("%s: sBluetoothVendorInterface is null.", __func__);
    return;
  }

  if ((do_add == JNI_TRUE) && (length <= 0 || length > 6)) {
    ALOGE("%s: address length %d is invalid, valid length is [1,6]", __func__, length);
    return;
  }

  const char* tmp_addr = env->GetStringUTFChars(address, NULL);
  if (!tmp_addr) {
    ALOGW("%s: address is null.", __func__);
    return;
  }
  RawAddress bdaddr;
  bool success = RawAddress::FromString(tmp_addr, bdaddr);

  env->ReleaseStringUTFChars(address, tmp_addr);

  if (!success) {
    ALOGW("%s: address is invalid.", __func__);
    return;
  }

  const char* feature_name_str = env->GetStringUTFChars(feature_name, NULL);
  if (!feature_name_str) {
    ALOGW("%s: feature name is null.", __func__);
    return;
  }

  sBluetoothVendorInterface->interop_database_add_remove_addr(
      (do_add == JNI_TRUE), feature_name_str, &bdaddr, (int)length);

  env->ReleaseStringUTFChars(feature_name, feature_name_str);
}

static void interopDatabaseAddRemoveNameNative(JNIEnv* env, jclass clazz,
      jboolean do_add, jstring feature_name, jstring name) {
  ALOGV("%s", __func__);

  std::shared_lock<std::shared_timed_mutex> lock(interface_mutex);

  if (!sBluetoothVendorInterface) {
    ALOGW("%s: sBluetoothVendorInterface is null.", __func__);
    return;
  }

  const char* feature_name_str = env->GetStringUTFChars(feature_name, NULL);
  if (!feature_name_str) {
    ALOGW("%s: feature name is null.", __func__);
    return;
  }

  const char* name_str = env->GetStringUTFChars(name, NULL);
  if (!name_str) {
    ALOGW("%s: name is null.", __func__);
    env->ReleaseStringUTFChars(feature_name, feature_name_str);
    return;
  }

  sBluetoothVendorInterface->interop_database_add_remove_name(
      (do_add == JNI_TRUE), feature_name_str, name_str);

  env->ReleaseStringUTFChars(feature_name, feature_name_str);
  env->ReleaseStringUTFChars(name, name_str);
}

static JNINativeMethod sMethods[] = {
    {"classInitNative", "()V", (void *) classInitNative},
    {"initNative", "()V", (void *) initNative},
    {"cleanupNative", "()V", (void *) cleanupNative},
    {"bredrcleanupNative", "()V", (void*) bredrcleanupNative},
    {"bredrstartupNative", "()V", (void*) bredrstartupNative},
    {"setWifiStateNative", "(Z)V", (void*) setWifiStateNative},
    {"setPowerBackoffNative", "(Z)V", (void*) setPowerBackoffNative},
    {"getProfileInfoNative", "(II)Z", (void*) getProfileInfoNative},
    {"getQtiStackStatusNative", "()Z", (void*) getQtiStackStatusNative},
    {"voipNetworkWifiInfoNative", "(ZZ)Z", (void *)voipNetworkWifiInfoNative},
    {"hcicloseNative", "()V", (void*) hcicloseNative},
    {"getSocNameNative", "()Ljava/lang/String;", (void*) getSocNameNative},
    {"getA2apOffloadCapabilityNative", "()Ljava/lang/String;",
            (void*) getA2apOffloadCapabilityNative},
    {"isSplitA2dpEnabledNative", "()Z", (void*) isSplitA2dpEnabledNative},
    {"isSwbEnabledNative", "()Z", (void*) isSwbEnabledNative},
    {"isSwbPmEnabledNative", "()Z", (void*) isSwbPmEnabledNative},
    {"setClockSyncConfigNative", "(ZIIIII)Z", (void*) setClockSyncConfigNative},
    {"startClockSyncNative", "()Z", (void*) startClockSyncNative},
    {"informTimeoutToHidlNative", "()V", (void*) informTimeoutToHidlNative},
    {"registerUuidSrvcDiscNative", "(JJ)V", (void*)registerUuidSrvcDiscNative},
    {"interopMatchAddrNative", "(Ljava/lang/String;Ljava/lang/String;)Z",
        (void*)interopMatchAddrNative},
    {"interopMatchNameNative", "(Ljava/lang/String;Ljava/lang/String;)Z",
        (void*)interopMatchNameNative},
    {"interopMatchAddrOrNameNative", "(Ljava/lang/String;Ljava/lang/String;)Z",
        (void*)interopMatchAddrOrNameNative},
    {"interopDatabaseAddRemoveAddrNative", "(ZLjava/lang/String;Ljava/lang/String;I)V",
        (void*)interopDatabaseAddRemoveAddrNative},
    {"interopDatabaseAddRemoveNameNative", "(ZLjava/lang/String;Ljava/lang/String;)V",
        (void*)interopDatabaseAddRemoveNameNative},
};

int load_bt_configstore_lib() {
    const char* sym = BT_CONFIG_STORE_INTERFACE_STRING;
    const char* err = "error unknown";

    bt_configstore_lib_handle = dlopen("libbtconfigstore.so", RTLD_NOW);
    if (!bt_configstore_lib_handle) {
        const char* err_str = dlerror();
        LOG(ERROR) << __func__ << ": failed to load Bt Config store library, error="
                   << (err_str ? err_str : err);
        goto error;
    }

    // Get the address of the bt_configstore_interface_t.
    bt_configstore_intf = (bt_configstore_interface_t*)dlsym(bt_configstore_lib_handle, sym);
    if (!bt_configstore_intf) {
        LOG(ERROR) << __func__ << ": failed to load symbol from bt config store library"
                   << sym;
        goto error;
    }

    // Success.
    LOG(INFO) << __func__ << " loaded HAL: bt_configstore_interface_t=" << bt_configstore_intf
              << ", bt_configstore_lib_handle=" << bt_configstore_lib_handle;

    return 0;

  error:
    if (bt_configstore_lib_handle) {
      dlclose(bt_configstore_lib_handle);
      bt_configstore_lib_handle = NULL;
      bt_configstore_intf = NULL;
    }

    return -EINVAL;
}

int register_com_android_bluetooth_btservice_vendor(JNIEnv* env)
{
    ALOGE("%s:",__FUNCTION__);
    return jniRegisterNativeMethods(env, "com/android/bluetooth/btservice/Vendor",
                                    sMethods, NELEM(sMethods));
}

} /* namespace android */
