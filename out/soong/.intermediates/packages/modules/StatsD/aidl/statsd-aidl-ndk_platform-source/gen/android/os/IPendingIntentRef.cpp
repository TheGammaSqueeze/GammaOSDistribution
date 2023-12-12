#include <android/binder_parcel_utils.h>
#include <aidl/android/os/BpPendingIntentRef.h>
#include <aidl/android/os/BnPendingIntentRef.h>
#include <aidl/android/os/IPendingIntentRef.h>

namespace aidl {
namespace android {
namespace os {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnPendingIntentRef> _aidl_impl = std::static_pointer_cast<BnPendingIntentRef>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*sendDataBroadcast*/): {
      int64_t in_lastReportTimeNs;

      _aidl_ret_status = AParcel_readInt64(_aidl_in, &in_lastReportTimeNs);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->sendDataBroadcast(in_lastReportTimeNs);
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*sendActiveConfigsChangedBroadcast*/): {
      std::vector<int64_t> in_configIds;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_configIds);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->sendActiveConfigsChangedBroadcast(in_configIds);
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 2 /*sendSubscriberBroadcast*/): {
      int64_t in_configUid;
      int64_t in_configId;
      int64_t in_subscriptionId;
      int64_t in_subscriptionRuleId;
      std::vector<std::string> in_cookies;
      ::aidl::android::os::StatsDimensionsValueParcel in_dimensionsValueParcel;

      _aidl_ret_status = AParcel_readInt64(_aidl_in, &in_configUid);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt64(_aidl_in, &in_configId);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt64(_aidl_in, &in_subscriptionId);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt64(_aidl_in, &in_subscriptionRuleId);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_cookies);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readParcelable(_aidl_in, &in_dimensionsValueParcel);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->sendSubscriberBroadcast(in_configUid, in_configId, in_subscriptionId, in_subscriptionRuleId, in_cookies, in_dimensionsValueParcel);
      _aidl_ret_status = STATUS_OK;
      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IPendingIntentRef::descriptor, _aidl_onTransact);

BpPendingIntentRef::BpPendingIntentRef(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpPendingIntentRef::~BpPendingIntentRef() {}

::ndk::ScopedAStatus BpPendingIntentRef::sendDataBroadcast(int64_t in_lastReportTimeNs) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt64(_aidl_in.get(), in_lastReportTimeNs);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*sendDataBroadcast*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IPendingIntentRef::getDefaultImpl()) {
    _aidl_status = IPendingIntentRef::getDefaultImpl()->sendDataBroadcast(in_lastReportTimeNs);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpPendingIntentRef::sendActiveConfigsChangedBroadcast(const std::vector<int64_t>& in_configIds) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_configIds);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*sendActiveConfigsChangedBroadcast*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IPendingIntentRef::getDefaultImpl()) {
    _aidl_status = IPendingIntentRef::getDefaultImpl()->sendActiveConfigsChangedBroadcast(in_configIds);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpPendingIntentRef::sendSubscriberBroadcast(int64_t in_configUid, int64_t in_configId, int64_t in_subscriptionId, int64_t in_subscriptionRuleId, const std::vector<std::string>& in_cookies, const ::aidl::android::os::StatsDimensionsValueParcel& in_dimensionsValueParcel) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt64(_aidl_in.get(), in_configUid);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt64(_aidl_in.get(), in_configId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt64(_aidl_in.get(), in_subscriptionId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt64(_aidl_in.get(), in_subscriptionRuleId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_cookies);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeParcelable(_aidl_in.get(), in_dimensionsValueParcel);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 2 /*sendSubscriberBroadcast*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IPendingIntentRef::getDefaultImpl()) {
    _aidl_status = IPendingIntentRef::getDefaultImpl()->sendSubscriberBroadcast(in_configUid, in_configId, in_subscriptionId, in_subscriptionRuleId, in_cookies, in_dimensionsValueParcel);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
// Source for BnPendingIntentRef
BnPendingIntentRef::BnPendingIntentRef() {}
BnPendingIntentRef::~BnPendingIntentRef() {}
::ndk::SpAIBinder BnPendingIntentRef::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IPendingIntentRef
const char* IPendingIntentRef::descriptor = "android.os.IPendingIntentRef";
IPendingIntentRef::IPendingIntentRef() {}
IPendingIntentRef::~IPendingIntentRef() {}


std::shared_ptr<IPendingIntentRef> IPendingIntentRef::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IPendingIntentRef>(interface);
  }
  return ::ndk::SharedRefBase::make<BpPendingIntentRef>(binder);
}

binder_status_t IPendingIntentRef::writeToParcel(AParcel* parcel, const std::shared_ptr<IPendingIntentRef>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IPendingIntentRef::readFromParcel(const AParcel* parcel, std::shared_ptr<IPendingIntentRef>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IPendingIntentRef::fromBinder(binder);
  return STATUS_OK;
}
bool IPendingIntentRef::setDefaultImpl(const std::shared_ptr<IPendingIntentRef>& impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IPendingIntentRef::default_impl);
  if (impl) {
    IPendingIntentRef::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IPendingIntentRef>& IPendingIntentRef::getDefaultImpl() {
  return IPendingIntentRef::default_impl;
}
std::shared_ptr<IPendingIntentRef> IPendingIntentRef::default_impl = nullptr;
::ndk::ScopedAStatus IPendingIntentRefDefault::sendDataBroadcast(int64_t /*in_lastReportTimeNs*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IPendingIntentRefDefault::sendActiveConfigsChangedBroadcast(const std::vector<int64_t>& /*in_configIds*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IPendingIntentRefDefault::sendSubscriberBroadcast(int64_t /*in_configUid*/, int64_t /*in_configId*/, int64_t /*in_subscriptionId*/, int64_t /*in_subscriptionRuleId*/, const std::vector<std::string>& /*in_cookies*/, const ::aidl::android::os::StatsDimensionsValueParcel& /*in_dimensionsValueParcel*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IPendingIntentRefDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IPendingIntentRefDefault::isRemote() {
  return false;
}
}  // namespace os
}  // namespace android
}  // namespace aidl
