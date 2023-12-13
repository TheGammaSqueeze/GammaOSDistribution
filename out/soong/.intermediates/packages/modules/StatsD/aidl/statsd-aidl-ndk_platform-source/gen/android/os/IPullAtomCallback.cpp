#include <android/binder_parcel_utils.h>
#include <aidl/android/os/BpPullAtomCallback.h>
#include <aidl/android/os/BnPullAtomCallback.h>
#include <aidl/android/os/IPullAtomCallback.h>
#include <aidl/android/os/BpPullAtomResultReceiver.h>
#include <aidl/android/os/BnPullAtomResultReceiver.h>
#include <aidl/android/os/IPullAtomResultReceiver.h>

namespace aidl {
namespace android {
namespace os {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnPullAtomCallback> _aidl_impl = std::static_pointer_cast<BnPullAtomCallback>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*onPullAtom*/): {
      int32_t in_atomTag;
      std::shared_ptr<::aidl::android::os::IPullAtomResultReceiver> in_resultReceiver;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_atomTag);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::aidl::android::os::IPullAtomResultReceiver::readFromParcel(_aidl_in, &in_resultReceiver);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onPullAtom(in_atomTag, in_resultReceiver);
      _aidl_ret_status = STATUS_OK;
      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IPullAtomCallback::descriptor, _aidl_onTransact);

BpPullAtomCallback::BpPullAtomCallback(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpPullAtomCallback::~BpPullAtomCallback() {}

::ndk::ScopedAStatus BpPullAtomCallback::onPullAtom(int32_t in_atomTag, const std::shared_ptr<::aidl::android::os::IPullAtomResultReceiver>& in_resultReceiver) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_atomTag);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::aidl::android::os::IPullAtomResultReceiver::writeToParcel(_aidl_in.get(), in_resultReceiver);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*onPullAtom*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IPullAtomCallback::getDefaultImpl()) {
    _aidl_status = IPullAtomCallback::getDefaultImpl()->onPullAtom(in_atomTag, in_resultReceiver);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
// Source for BnPullAtomCallback
BnPullAtomCallback::BnPullAtomCallback() {}
BnPullAtomCallback::~BnPullAtomCallback() {}
::ndk::SpAIBinder BnPullAtomCallback::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IPullAtomCallback
const char* IPullAtomCallback::descriptor = "android.os.IPullAtomCallback";
IPullAtomCallback::IPullAtomCallback() {}
IPullAtomCallback::~IPullAtomCallback() {}


std::shared_ptr<IPullAtomCallback> IPullAtomCallback::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IPullAtomCallback>(interface);
  }
  return ::ndk::SharedRefBase::make<BpPullAtomCallback>(binder);
}

binder_status_t IPullAtomCallback::writeToParcel(AParcel* parcel, const std::shared_ptr<IPullAtomCallback>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IPullAtomCallback::readFromParcel(const AParcel* parcel, std::shared_ptr<IPullAtomCallback>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IPullAtomCallback::fromBinder(binder);
  return STATUS_OK;
}
bool IPullAtomCallback::setDefaultImpl(const std::shared_ptr<IPullAtomCallback>& impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IPullAtomCallback::default_impl);
  if (impl) {
    IPullAtomCallback::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IPullAtomCallback>& IPullAtomCallback::getDefaultImpl() {
  return IPullAtomCallback::default_impl;
}
std::shared_ptr<IPullAtomCallback> IPullAtomCallback::default_impl = nullptr;
::ndk::ScopedAStatus IPullAtomCallbackDefault::onPullAtom(int32_t /*in_atomTag*/, const std::shared_ptr<::aidl::android::os::IPullAtomResultReceiver>& /*in_resultReceiver*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IPullAtomCallbackDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IPullAtomCallbackDefault::isRemote() {
  return false;
}
}  // namespace os
}  // namespace android
}  // namespace aidl
