#include <android/binder_parcel_utils.h>
#include <aidl/android/security/apc/BpConfirmationCallback.h>
#include <aidl/android/security/apc/BnConfirmationCallback.h>
#include <aidl/android/security/apc/IConfirmationCallback.h>

namespace aidl {
namespace android {
namespace security {
namespace apc {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnConfirmationCallback> _aidl_impl = std::static_pointer_cast<BnConfirmationCallback>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*onCompleted*/): {
      ::aidl::android::security::apc::ResponseCode in_result;
      std::optional<std::vector<uint8_t>> in_dataConfirmed;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, reinterpret_cast<int32_t*>(&in_result));
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_dataConfirmed);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onCompleted(in_result, in_dataConfirmed);
      _aidl_ret_status = STATUS_OK;
      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IConfirmationCallback::descriptor, _aidl_onTransact);

BpConfirmationCallback::BpConfirmationCallback(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpConfirmationCallback::~BpConfirmationCallback() {}

::ndk::ScopedAStatus BpConfirmationCallback::onCompleted(::aidl::android::security::apc::ResponseCode in_result, const std::optional<std::vector<uint8_t>>& in_dataConfirmed) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), static_cast<int32_t>(in_result));
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_dataConfirmed);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*onCompleted*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IConfirmationCallback::getDefaultImpl()) {
    _aidl_status = IConfirmationCallback::getDefaultImpl()->onCompleted(in_result, in_dataConfirmed);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
// Source for BnConfirmationCallback
BnConfirmationCallback::BnConfirmationCallback() {}
BnConfirmationCallback::~BnConfirmationCallback() {}
::ndk::SpAIBinder BnConfirmationCallback::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IConfirmationCallback
const char* IConfirmationCallback::descriptor = "android.security.apc.IConfirmationCallback";
IConfirmationCallback::IConfirmationCallback() {}
IConfirmationCallback::~IConfirmationCallback() {}


std::shared_ptr<IConfirmationCallback> IConfirmationCallback::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IConfirmationCallback>(interface);
  }
  return ::ndk::SharedRefBase::make<BpConfirmationCallback>(binder);
}

binder_status_t IConfirmationCallback::writeToParcel(AParcel* parcel, const std::shared_ptr<IConfirmationCallback>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IConfirmationCallback::readFromParcel(const AParcel* parcel, std::shared_ptr<IConfirmationCallback>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IConfirmationCallback::fromBinder(binder);
  return STATUS_OK;
}
bool IConfirmationCallback::setDefaultImpl(const std::shared_ptr<IConfirmationCallback>& impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IConfirmationCallback::default_impl);
  if (impl) {
    IConfirmationCallback::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IConfirmationCallback>& IConfirmationCallback::getDefaultImpl() {
  return IConfirmationCallback::default_impl;
}
std::shared_ptr<IConfirmationCallback> IConfirmationCallback::default_impl = nullptr;
::ndk::ScopedAStatus IConfirmationCallbackDefault::onCompleted(::aidl::android::security::apc::ResponseCode /*in_result*/, const std::optional<std::vector<uint8_t>>& /*in_dataConfirmed*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IConfirmationCallbackDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IConfirmationCallbackDefault::isRemote() {
  return false;
}
}  // namespace apc
}  // namespace security
}  // namespace android
}  // namespace aidl
