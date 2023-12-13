#include <android/binder_parcel_utils.h>
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
  std::shared_ptr<BnPullAtomResultReceiver> _aidl_impl = std::static_pointer_cast<BnPullAtomResultReceiver>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*pullFinished*/): {
      int32_t in_atomTag;
      bool in_success;
      std::vector<::aidl::android::util::StatsEventParcel> in_output;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_atomTag);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readBool(_aidl_in, &in_success);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_output);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->pullFinished(in_atomTag, in_success, in_output);
      _aidl_ret_status = STATUS_OK;
      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IPullAtomResultReceiver::descriptor, _aidl_onTransact);

BpPullAtomResultReceiver::BpPullAtomResultReceiver(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpPullAtomResultReceiver::~BpPullAtomResultReceiver() {}

::ndk::ScopedAStatus BpPullAtomResultReceiver::pullFinished(int32_t in_atomTag, bool in_success, const std::vector<::aidl::android::util::StatsEventParcel>& in_output) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_atomTag);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeBool(_aidl_in.get(), in_success);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_output);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*pullFinished*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IPullAtomResultReceiver::getDefaultImpl()) {
    _aidl_status = IPullAtomResultReceiver::getDefaultImpl()->pullFinished(in_atomTag, in_success, in_output);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
// Source for BnPullAtomResultReceiver
BnPullAtomResultReceiver::BnPullAtomResultReceiver() {}
BnPullAtomResultReceiver::~BnPullAtomResultReceiver() {}
::ndk::SpAIBinder BnPullAtomResultReceiver::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IPullAtomResultReceiver
const char* IPullAtomResultReceiver::descriptor = "android.os.IPullAtomResultReceiver";
IPullAtomResultReceiver::IPullAtomResultReceiver() {}
IPullAtomResultReceiver::~IPullAtomResultReceiver() {}


std::shared_ptr<IPullAtomResultReceiver> IPullAtomResultReceiver::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IPullAtomResultReceiver>(interface);
  }
  return ::ndk::SharedRefBase::make<BpPullAtomResultReceiver>(binder);
}

binder_status_t IPullAtomResultReceiver::writeToParcel(AParcel* parcel, const std::shared_ptr<IPullAtomResultReceiver>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IPullAtomResultReceiver::readFromParcel(const AParcel* parcel, std::shared_ptr<IPullAtomResultReceiver>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IPullAtomResultReceiver::fromBinder(binder);
  return STATUS_OK;
}
bool IPullAtomResultReceiver::setDefaultImpl(const std::shared_ptr<IPullAtomResultReceiver>& impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IPullAtomResultReceiver::default_impl);
  if (impl) {
    IPullAtomResultReceiver::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IPullAtomResultReceiver>& IPullAtomResultReceiver::getDefaultImpl() {
  return IPullAtomResultReceiver::default_impl;
}
std::shared_ptr<IPullAtomResultReceiver> IPullAtomResultReceiver::default_impl = nullptr;
::ndk::ScopedAStatus IPullAtomResultReceiverDefault::pullFinished(int32_t /*in_atomTag*/, bool /*in_success*/, const std::vector<::aidl::android::util::StatsEventParcel>& /*in_output*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IPullAtomResultReceiverDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IPullAtomResultReceiverDefault::isRemote() {
  return false;
}
}  // namespace os
}  // namespace android
}  // namespace aidl
