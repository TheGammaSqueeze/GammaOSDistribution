#include <android/binder_parcel_utils.h>
#include <aidl/android/os/BpPendingIntentRef.h>
#include <aidl/android/os/BnPendingIntentRef.h>
#include <aidl/android/os/IPendingIntentRef.h>
#include <aidl/android/os/BpPullAtomCallback.h>
#include <aidl/android/os/BnPullAtomCallback.h>
#include <aidl/android/os/IPullAtomCallback.h>
#include <aidl/android/os/BpStatsd.h>
#include <aidl/android/os/BnStatsd.h>
#include <aidl/android/os/IStatsd.h>

namespace aidl {
namespace android {
namespace os {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnStatsd> _aidl_impl = std::static_pointer_cast<BnStatsd>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*systemRunning*/): {

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->systemRunning();
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*bootCompleted*/): {

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->bootCompleted();
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 2 /*statsCompanionReady*/): {

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->statsCompanionReady();
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 3 /*informAnomalyAlarmFired*/): {

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->informAnomalyAlarmFired();
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 4 /*informPollAlarmFired*/): {

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->informPollAlarmFired();
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 5 /*informAlarmForSubscriberTriggeringFired*/): {

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->informAlarmForSubscriberTriggeringFired();
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 6 /*informDeviceShutdown*/): {

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->informDeviceShutdown();
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 7 /*informAllUidData*/): {
      ::ndk::ScopedFileDescriptor in_fd;

      _aidl_ret_status = ::ndk::AParcel_readRequiredParcelFileDescriptor(_aidl_in, &in_fd);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->informAllUidData(in_fd);
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 8 /*informOnePackage*/): {
      std::string in_app;
      int32_t in_uid;
      int64_t in_version;
      std::string in_version_string;
      std::string in_installer;

      _aidl_ret_status = ::ndk::AParcel_readString(_aidl_in, &in_app);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_uid);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt64(_aidl_in, &in_version);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readString(_aidl_in, &in_version_string);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readString(_aidl_in, &in_installer);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->informOnePackage(in_app, in_uid, in_version, in_version_string, in_installer);
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 9 /*informOnePackageRemoved*/): {
      std::string in_app;
      int32_t in_uid;

      _aidl_ret_status = ::ndk::AParcel_readString(_aidl_in, &in_app);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_uid);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->informOnePackageRemoved(in_app, in_uid);
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 10 /*getData*/): {
      int64_t in_key;
      int32_t in_callingUid;
      std::vector<uint8_t> _aidl_return;

      _aidl_ret_status = AParcel_readInt64(_aidl_in, &in_key);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_callingUid);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->getData(in_key, in_callingUid, &_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 11 /*getMetadata*/): {
      std::vector<uint8_t> _aidl_return;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->getMetadata(&_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 12 /*addConfiguration*/): {
      int64_t in_configId;
      std::vector<uint8_t> in_config;
      int32_t in_callingUid;

      _aidl_ret_status = AParcel_readInt64(_aidl_in, &in_configId);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_config);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_callingUid);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->addConfiguration(in_configId, in_config, in_callingUid);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 13 /*setDataFetchOperation*/): {
      int64_t in_configId;
      std::shared_ptr<::aidl::android::os::IPendingIntentRef> in_pendingIntentRef;
      int32_t in_callingUid;

      _aidl_ret_status = AParcel_readInt64(_aidl_in, &in_configId);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::aidl::android::os::IPendingIntentRef::readFromParcel(_aidl_in, &in_pendingIntentRef);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_callingUid);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->setDataFetchOperation(in_configId, in_pendingIntentRef, in_callingUid);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 14 /*removeDataFetchOperation*/): {
      int64_t in_configId;
      int32_t in_callingUid;

      _aidl_ret_status = AParcel_readInt64(_aidl_in, &in_configId);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_callingUid);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->removeDataFetchOperation(in_configId, in_callingUid);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 15 /*setActiveConfigsChangedOperation*/): {
      std::shared_ptr<::aidl::android::os::IPendingIntentRef> in_pendingIntentRef;
      int32_t in_callingUid;
      std::vector<int64_t> _aidl_return;

      _aidl_ret_status = ::aidl::android::os::IPendingIntentRef::readFromParcel(_aidl_in, &in_pendingIntentRef);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_callingUid);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->setActiveConfigsChangedOperation(in_pendingIntentRef, in_callingUid, &_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 16 /*removeActiveConfigsChangedOperation*/): {
      int32_t in_callingUid;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_callingUid);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->removeActiveConfigsChangedOperation(in_callingUid);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 17 /*removeConfiguration*/): {
      int64_t in_configId;
      int32_t in_callingUid;

      _aidl_ret_status = AParcel_readInt64(_aidl_in, &in_configId);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_callingUid);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->removeConfiguration(in_configId, in_callingUid);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 18 /*setBroadcastSubscriber*/): {
      int64_t in_configId;
      int64_t in_subscriberId;
      std::shared_ptr<::aidl::android::os::IPendingIntentRef> in_pir;
      int32_t in_callingUid;

      _aidl_ret_status = AParcel_readInt64(_aidl_in, &in_configId);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt64(_aidl_in, &in_subscriberId);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::aidl::android::os::IPendingIntentRef::readFromParcel(_aidl_in, &in_pir);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_callingUid);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->setBroadcastSubscriber(in_configId, in_subscriberId, in_pir, in_callingUid);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 19 /*unsetBroadcastSubscriber*/): {
      int64_t in_configId;
      int64_t in_subscriberId;
      int32_t in_callingUid;

      _aidl_ret_status = AParcel_readInt64(_aidl_in, &in_configId);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt64(_aidl_in, &in_subscriberId);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_callingUid);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->unsetBroadcastSubscriber(in_configId, in_subscriberId, in_callingUid);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 20 /*allPullersFromBootRegistered*/): {

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->allPullersFromBootRegistered();
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 21 /*registerPullAtomCallback*/): {
      int32_t in_uid;
      int32_t in_atomTag;
      int64_t in_coolDownMillis;
      int64_t in_timeoutMillis;
      std::vector<int32_t> in_additiveFields;
      std::shared_ptr<::aidl::android::os::IPullAtomCallback> in_pullerCallback;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_uid);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_atomTag);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt64(_aidl_in, &in_coolDownMillis);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt64(_aidl_in, &in_timeoutMillis);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_additiveFields);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::aidl::android::os::IPullAtomCallback::readFromParcel(_aidl_in, &in_pullerCallback);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->registerPullAtomCallback(in_uid, in_atomTag, in_coolDownMillis, in_timeoutMillis, in_additiveFields, in_pullerCallback);
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 22 /*registerNativePullAtomCallback*/): {
      int32_t in_atomTag;
      int64_t in_coolDownMillis;
      int64_t in_timeoutMillis;
      std::vector<int32_t> in_additiveFields;
      std::shared_ptr<::aidl::android::os::IPullAtomCallback> in_pullerCallback;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_atomTag);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt64(_aidl_in, &in_coolDownMillis);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt64(_aidl_in, &in_timeoutMillis);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_additiveFields);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::aidl::android::os::IPullAtomCallback::readFromParcel(_aidl_in, &in_pullerCallback);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->registerNativePullAtomCallback(in_atomTag, in_coolDownMillis, in_timeoutMillis, in_additiveFields, in_pullerCallback);
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 23 /*unregisterPullAtomCallback*/): {
      int32_t in_uid;
      int32_t in_atomTag;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_uid);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_atomTag);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->unregisterPullAtomCallback(in_uid, in_atomTag);
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 24 /*unregisterNativePullAtomCallback*/): {
      int32_t in_atomTag;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_atomTag);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->unregisterNativePullAtomCallback(in_atomTag);
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 25 /*getRegisteredExperimentIds*/): {
      std::vector<int64_t> _aidl_return;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->getRegisteredExperimentIds(&_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IStatsd::descriptor, _aidl_onTransact);

BpStatsd::BpStatsd(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpStatsd::~BpStatsd() {}

::ndk::ScopedAStatus BpStatsd::systemRunning() {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*systemRunning*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IStatsd::getDefaultImpl()) {
    _aidl_status = IStatsd::getDefaultImpl()->systemRunning();
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpStatsd::bootCompleted() {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*bootCompleted*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IStatsd::getDefaultImpl()) {
    _aidl_status = IStatsd::getDefaultImpl()->bootCompleted();
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpStatsd::statsCompanionReady() {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 2 /*statsCompanionReady*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IStatsd::getDefaultImpl()) {
    _aidl_status = IStatsd::getDefaultImpl()->statsCompanionReady();
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpStatsd::informAnomalyAlarmFired() {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 3 /*informAnomalyAlarmFired*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IStatsd::getDefaultImpl()) {
    _aidl_status = IStatsd::getDefaultImpl()->informAnomalyAlarmFired();
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpStatsd::informPollAlarmFired() {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 4 /*informPollAlarmFired*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IStatsd::getDefaultImpl()) {
    _aidl_status = IStatsd::getDefaultImpl()->informPollAlarmFired();
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpStatsd::informAlarmForSubscriberTriggeringFired() {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 5 /*informAlarmForSubscriberTriggeringFired*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IStatsd::getDefaultImpl()) {
    _aidl_status = IStatsd::getDefaultImpl()->informAlarmForSubscriberTriggeringFired();
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpStatsd::informDeviceShutdown() {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 6 /*informDeviceShutdown*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IStatsd::getDefaultImpl()) {
    _aidl_status = IStatsd::getDefaultImpl()->informDeviceShutdown();
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpStatsd::informAllUidData(const ::ndk::ScopedFileDescriptor& in_fd) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeRequiredParcelFileDescriptor(_aidl_in.get(), in_fd);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 7 /*informAllUidData*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IStatsd::getDefaultImpl()) {
    _aidl_status = IStatsd::getDefaultImpl()->informAllUidData(in_fd);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpStatsd::informOnePackage(const std::string& in_app, int32_t in_uid, int64_t in_version, const std::string& in_version_string, const std::string& in_installer) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeString(_aidl_in.get(), in_app);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_uid);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt64(_aidl_in.get(), in_version);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeString(_aidl_in.get(), in_version_string);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeString(_aidl_in.get(), in_installer);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 8 /*informOnePackage*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IStatsd::getDefaultImpl()) {
    _aidl_status = IStatsd::getDefaultImpl()->informOnePackage(in_app, in_uid, in_version, in_version_string, in_installer);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpStatsd::informOnePackageRemoved(const std::string& in_app, int32_t in_uid) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeString(_aidl_in.get(), in_app);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_uid);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 9 /*informOnePackageRemoved*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IStatsd::getDefaultImpl()) {
    _aidl_status = IStatsd::getDefaultImpl()->informOnePackageRemoved(in_app, in_uid);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpStatsd::getData(int64_t in_key, int32_t in_callingUid, std::vector<uint8_t>* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt64(_aidl_in.get(), in_key);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_callingUid);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 10 /*getData*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IStatsd::getDefaultImpl()) {
    _aidl_status = IStatsd::getDefaultImpl()->getData(in_key, in_callingUid, _aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpStatsd::getMetadata(std::vector<uint8_t>* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 11 /*getMetadata*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IStatsd::getDefaultImpl()) {
    _aidl_status = IStatsd::getDefaultImpl()->getMetadata(_aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpStatsd::addConfiguration(int64_t in_configId, const std::vector<uint8_t>& in_config, int32_t in_callingUid) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt64(_aidl_in.get(), in_configId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_config);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_callingUid);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 12 /*addConfiguration*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IStatsd::getDefaultImpl()) {
    _aidl_status = IStatsd::getDefaultImpl()->addConfiguration(in_configId, in_config, in_callingUid);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpStatsd::setDataFetchOperation(int64_t in_configId, const std::shared_ptr<::aidl::android::os::IPendingIntentRef>& in_pendingIntentRef, int32_t in_callingUid) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt64(_aidl_in.get(), in_configId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::aidl::android::os::IPendingIntentRef::writeToParcel(_aidl_in.get(), in_pendingIntentRef);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_callingUid);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 13 /*setDataFetchOperation*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IStatsd::getDefaultImpl()) {
    _aidl_status = IStatsd::getDefaultImpl()->setDataFetchOperation(in_configId, in_pendingIntentRef, in_callingUid);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpStatsd::removeDataFetchOperation(int64_t in_configId, int32_t in_callingUid) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt64(_aidl_in.get(), in_configId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_callingUid);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 14 /*removeDataFetchOperation*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IStatsd::getDefaultImpl()) {
    _aidl_status = IStatsd::getDefaultImpl()->removeDataFetchOperation(in_configId, in_callingUid);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpStatsd::setActiveConfigsChangedOperation(const std::shared_ptr<::aidl::android::os::IPendingIntentRef>& in_pendingIntentRef, int32_t in_callingUid, std::vector<int64_t>* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::aidl::android::os::IPendingIntentRef::writeToParcel(_aidl_in.get(), in_pendingIntentRef);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_callingUid);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 15 /*setActiveConfigsChangedOperation*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IStatsd::getDefaultImpl()) {
    _aidl_status = IStatsd::getDefaultImpl()->setActiveConfigsChangedOperation(in_pendingIntentRef, in_callingUid, _aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpStatsd::removeActiveConfigsChangedOperation(int32_t in_callingUid) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_callingUid);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 16 /*removeActiveConfigsChangedOperation*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IStatsd::getDefaultImpl()) {
    _aidl_status = IStatsd::getDefaultImpl()->removeActiveConfigsChangedOperation(in_callingUid);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpStatsd::removeConfiguration(int64_t in_configId, int32_t in_callingUid) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt64(_aidl_in.get(), in_configId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_callingUid);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 17 /*removeConfiguration*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IStatsd::getDefaultImpl()) {
    _aidl_status = IStatsd::getDefaultImpl()->removeConfiguration(in_configId, in_callingUid);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpStatsd::setBroadcastSubscriber(int64_t in_configId, int64_t in_subscriberId, const std::shared_ptr<::aidl::android::os::IPendingIntentRef>& in_pir, int32_t in_callingUid) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt64(_aidl_in.get(), in_configId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt64(_aidl_in.get(), in_subscriberId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::aidl::android::os::IPendingIntentRef::writeToParcel(_aidl_in.get(), in_pir);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_callingUid);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 18 /*setBroadcastSubscriber*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IStatsd::getDefaultImpl()) {
    _aidl_status = IStatsd::getDefaultImpl()->setBroadcastSubscriber(in_configId, in_subscriberId, in_pir, in_callingUid);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpStatsd::unsetBroadcastSubscriber(int64_t in_configId, int64_t in_subscriberId, int32_t in_callingUid) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt64(_aidl_in.get(), in_configId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt64(_aidl_in.get(), in_subscriberId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_callingUid);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 19 /*unsetBroadcastSubscriber*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IStatsd::getDefaultImpl()) {
    _aidl_status = IStatsd::getDefaultImpl()->unsetBroadcastSubscriber(in_configId, in_subscriberId, in_callingUid);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpStatsd::allPullersFromBootRegistered() {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 20 /*allPullersFromBootRegistered*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IStatsd::getDefaultImpl()) {
    _aidl_status = IStatsd::getDefaultImpl()->allPullersFromBootRegistered();
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpStatsd::registerPullAtomCallback(int32_t in_uid, int32_t in_atomTag, int64_t in_coolDownMillis, int64_t in_timeoutMillis, const std::vector<int32_t>& in_additiveFields, const std::shared_ptr<::aidl::android::os::IPullAtomCallback>& in_pullerCallback) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_uid);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_atomTag);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt64(_aidl_in.get(), in_coolDownMillis);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt64(_aidl_in.get(), in_timeoutMillis);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_additiveFields);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::aidl::android::os::IPullAtomCallback::writeToParcel(_aidl_in.get(), in_pullerCallback);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 21 /*registerPullAtomCallback*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IStatsd::getDefaultImpl()) {
    _aidl_status = IStatsd::getDefaultImpl()->registerPullAtomCallback(in_uid, in_atomTag, in_coolDownMillis, in_timeoutMillis, in_additiveFields, in_pullerCallback);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpStatsd::registerNativePullAtomCallback(int32_t in_atomTag, int64_t in_coolDownMillis, int64_t in_timeoutMillis, const std::vector<int32_t>& in_additiveFields, const std::shared_ptr<::aidl::android::os::IPullAtomCallback>& in_pullerCallback) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_atomTag);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt64(_aidl_in.get(), in_coolDownMillis);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt64(_aidl_in.get(), in_timeoutMillis);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_additiveFields);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::aidl::android::os::IPullAtomCallback::writeToParcel(_aidl_in.get(), in_pullerCallback);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 22 /*registerNativePullAtomCallback*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IStatsd::getDefaultImpl()) {
    _aidl_status = IStatsd::getDefaultImpl()->registerNativePullAtomCallback(in_atomTag, in_coolDownMillis, in_timeoutMillis, in_additiveFields, in_pullerCallback);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpStatsd::unregisterPullAtomCallback(int32_t in_uid, int32_t in_atomTag) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_uid);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_atomTag);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 23 /*unregisterPullAtomCallback*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IStatsd::getDefaultImpl()) {
    _aidl_status = IStatsd::getDefaultImpl()->unregisterPullAtomCallback(in_uid, in_atomTag);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpStatsd::unregisterNativePullAtomCallback(int32_t in_atomTag) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_atomTag);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 24 /*unregisterNativePullAtomCallback*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IStatsd::getDefaultImpl()) {
    _aidl_status = IStatsd::getDefaultImpl()->unregisterNativePullAtomCallback(in_atomTag);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpStatsd::getRegisteredExperimentIds(std::vector<int64_t>* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 25 /*getRegisteredExperimentIds*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IStatsd::getDefaultImpl()) {
    _aidl_status = IStatsd::getDefaultImpl()->getRegisteredExperimentIds(_aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
// Source for BnStatsd
BnStatsd::BnStatsd() {}
BnStatsd::~BnStatsd() {}
::ndk::SpAIBinder BnStatsd::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IStatsd
const char* IStatsd::descriptor = "android.os.IStatsd";
IStatsd::IStatsd() {}
IStatsd::~IStatsd() {}


std::shared_ptr<IStatsd> IStatsd::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IStatsd>(interface);
  }
  return ::ndk::SharedRefBase::make<BpStatsd>(binder);
}

binder_status_t IStatsd::writeToParcel(AParcel* parcel, const std::shared_ptr<IStatsd>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IStatsd::readFromParcel(const AParcel* parcel, std::shared_ptr<IStatsd>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IStatsd::fromBinder(binder);
  return STATUS_OK;
}
bool IStatsd::setDefaultImpl(const std::shared_ptr<IStatsd>& impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IStatsd::default_impl);
  if (impl) {
    IStatsd::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IStatsd>& IStatsd::getDefaultImpl() {
  return IStatsd::default_impl;
}
std::shared_ptr<IStatsd> IStatsd::default_impl = nullptr;
::ndk::ScopedAStatus IStatsdDefault::systemRunning() {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IStatsdDefault::bootCompleted() {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IStatsdDefault::statsCompanionReady() {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IStatsdDefault::informAnomalyAlarmFired() {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IStatsdDefault::informPollAlarmFired() {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IStatsdDefault::informAlarmForSubscriberTriggeringFired() {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IStatsdDefault::informDeviceShutdown() {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IStatsdDefault::informAllUidData(const ::ndk::ScopedFileDescriptor& /*in_fd*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IStatsdDefault::informOnePackage(const std::string& /*in_app*/, int32_t /*in_uid*/, int64_t /*in_version*/, const std::string& /*in_version_string*/, const std::string& /*in_installer*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IStatsdDefault::informOnePackageRemoved(const std::string& /*in_app*/, int32_t /*in_uid*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IStatsdDefault::getData(int64_t /*in_key*/, int32_t /*in_callingUid*/, std::vector<uint8_t>* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IStatsdDefault::getMetadata(std::vector<uint8_t>* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IStatsdDefault::addConfiguration(int64_t /*in_configId*/, const std::vector<uint8_t>& /*in_config*/, int32_t /*in_callingUid*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IStatsdDefault::setDataFetchOperation(int64_t /*in_configId*/, const std::shared_ptr<::aidl::android::os::IPendingIntentRef>& /*in_pendingIntentRef*/, int32_t /*in_callingUid*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IStatsdDefault::removeDataFetchOperation(int64_t /*in_configId*/, int32_t /*in_callingUid*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IStatsdDefault::setActiveConfigsChangedOperation(const std::shared_ptr<::aidl::android::os::IPendingIntentRef>& /*in_pendingIntentRef*/, int32_t /*in_callingUid*/, std::vector<int64_t>* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IStatsdDefault::removeActiveConfigsChangedOperation(int32_t /*in_callingUid*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IStatsdDefault::removeConfiguration(int64_t /*in_configId*/, int32_t /*in_callingUid*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IStatsdDefault::setBroadcastSubscriber(int64_t /*in_configId*/, int64_t /*in_subscriberId*/, const std::shared_ptr<::aidl::android::os::IPendingIntentRef>& /*in_pir*/, int32_t /*in_callingUid*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IStatsdDefault::unsetBroadcastSubscriber(int64_t /*in_configId*/, int64_t /*in_subscriberId*/, int32_t /*in_callingUid*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IStatsdDefault::allPullersFromBootRegistered() {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IStatsdDefault::registerPullAtomCallback(int32_t /*in_uid*/, int32_t /*in_atomTag*/, int64_t /*in_coolDownMillis*/, int64_t /*in_timeoutMillis*/, const std::vector<int32_t>& /*in_additiveFields*/, const std::shared_ptr<::aidl::android::os::IPullAtomCallback>& /*in_pullerCallback*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IStatsdDefault::registerNativePullAtomCallback(int32_t /*in_atomTag*/, int64_t /*in_coolDownMillis*/, int64_t /*in_timeoutMillis*/, const std::vector<int32_t>& /*in_additiveFields*/, const std::shared_ptr<::aidl::android::os::IPullAtomCallback>& /*in_pullerCallback*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IStatsdDefault::unregisterPullAtomCallback(int32_t /*in_uid*/, int32_t /*in_atomTag*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IStatsdDefault::unregisterNativePullAtomCallback(int32_t /*in_atomTag*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IStatsdDefault::getRegisteredExperimentIds(std::vector<int64_t>* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IStatsdDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IStatsdDefault::isRemote() {
  return false;
}
}  // namespace os
}  // namespace android
}  // namespace aidl
