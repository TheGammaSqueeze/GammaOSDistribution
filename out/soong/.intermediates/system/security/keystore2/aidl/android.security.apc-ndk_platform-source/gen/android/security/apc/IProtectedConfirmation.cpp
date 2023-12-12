#include <android/binder_parcel_utils.h>
#include <aidl/android/security/apc/BpConfirmationCallback.h>
#include <aidl/android/security/apc/BnConfirmationCallback.h>
#include <aidl/android/security/apc/IConfirmationCallback.h>
#include <aidl/android/security/apc/BpProtectedConfirmation.h>
#include <aidl/android/security/apc/BnProtectedConfirmation.h>
#include <aidl/android/security/apc/IProtectedConfirmation.h>

namespace aidl {
namespace android {
namespace security {
namespace apc {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnProtectedConfirmation> _aidl_impl = std::static_pointer_cast<BnProtectedConfirmation>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*presentPrompt*/): {
      std::shared_ptr<::aidl::android::security::apc::IConfirmationCallback> in_listener;
      std::string in_promptText;
      std::vector<uint8_t> in_extraData;
      std::string in_locale;
      int32_t in_uiOptionFlags;

      _aidl_ret_status = ::aidl::android::security::apc::IConfirmationCallback::readFromParcel(_aidl_in, &in_listener);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readString(_aidl_in, &in_promptText);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_extraData);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readString(_aidl_in, &in_locale);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_uiOptionFlags);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->presentPrompt(in_listener, in_promptText, in_extraData, in_locale, in_uiOptionFlags);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*cancelPrompt*/): {
      std::shared_ptr<::aidl::android::security::apc::IConfirmationCallback> in_listener;

      _aidl_ret_status = ::aidl::android::security::apc::IConfirmationCallback::readFromParcel(_aidl_in, &in_listener);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->cancelPrompt(in_listener);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 2 /*isSupported*/): {
      bool _aidl_return;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->isSupported(&_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = AParcel_writeBool(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IProtectedConfirmation::descriptor, _aidl_onTransact);

BpProtectedConfirmation::BpProtectedConfirmation(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpProtectedConfirmation::~BpProtectedConfirmation() {}

::ndk::ScopedAStatus BpProtectedConfirmation::presentPrompt(const std::shared_ptr<::aidl::android::security::apc::IConfirmationCallback>& in_listener, const std::string& in_promptText, const std::vector<uint8_t>& in_extraData, const std::string& in_locale, int32_t in_uiOptionFlags) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::aidl::android::security::apc::IConfirmationCallback::writeToParcel(_aidl_in.get(), in_listener);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeString(_aidl_in.get(), in_promptText);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_extraData);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeString(_aidl_in.get(), in_locale);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_uiOptionFlags);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*presentPrompt*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IProtectedConfirmation::getDefaultImpl()) {
    _aidl_status = IProtectedConfirmation::getDefaultImpl()->presentPrompt(in_listener, in_promptText, in_extraData, in_locale, in_uiOptionFlags);
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
::ndk::ScopedAStatus BpProtectedConfirmation::cancelPrompt(const std::shared_ptr<::aidl::android::security::apc::IConfirmationCallback>& in_listener) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::aidl::android::security::apc::IConfirmationCallback::writeToParcel(_aidl_in.get(), in_listener);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*cancelPrompt*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IProtectedConfirmation::getDefaultImpl()) {
    _aidl_status = IProtectedConfirmation::getDefaultImpl()->cancelPrompt(in_listener);
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
::ndk::ScopedAStatus BpProtectedConfirmation::isSupported(bool* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 2 /*isSupported*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IProtectedConfirmation::getDefaultImpl()) {
    _aidl_status = IProtectedConfirmation::getDefaultImpl()->isSupported(_aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = AParcel_readBool(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
// Source for BnProtectedConfirmation
BnProtectedConfirmation::BnProtectedConfirmation() {}
BnProtectedConfirmation::~BnProtectedConfirmation() {}
::ndk::SpAIBinder BnProtectedConfirmation::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IProtectedConfirmation
const char* IProtectedConfirmation::descriptor = "android.security.apc.IProtectedConfirmation";
IProtectedConfirmation::IProtectedConfirmation() {}
IProtectedConfirmation::~IProtectedConfirmation() {}


std::shared_ptr<IProtectedConfirmation> IProtectedConfirmation::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IProtectedConfirmation>(interface);
  }
  return ::ndk::SharedRefBase::make<BpProtectedConfirmation>(binder);
}

binder_status_t IProtectedConfirmation::writeToParcel(AParcel* parcel, const std::shared_ptr<IProtectedConfirmation>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IProtectedConfirmation::readFromParcel(const AParcel* parcel, std::shared_ptr<IProtectedConfirmation>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IProtectedConfirmation::fromBinder(binder);
  return STATUS_OK;
}
bool IProtectedConfirmation::setDefaultImpl(const std::shared_ptr<IProtectedConfirmation>& impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IProtectedConfirmation::default_impl);
  if (impl) {
    IProtectedConfirmation::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IProtectedConfirmation>& IProtectedConfirmation::getDefaultImpl() {
  return IProtectedConfirmation::default_impl;
}
std::shared_ptr<IProtectedConfirmation> IProtectedConfirmation::default_impl = nullptr;
::ndk::ScopedAStatus IProtectedConfirmationDefault::presentPrompt(const std::shared_ptr<::aidl::android::security::apc::IConfirmationCallback>& /*in_listener*/, const std::string& /*in_promptText*/, const std::vector<uint8_t>& /*in_extraData*/, const std::string& /*in_locale*/, int32_t /*in_uiOptionFlags*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IProtectedConfirmationDefault::cancelPrompt(const std::shared_ptr<::aidl::android::security::apc::IConfirmationCallback>& /*in_listener*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IProtectedConfirmationDefault::isSupported(bool* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IProtectedConfirmationDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IProtectedConfirmationDefault::isRemote() {
  return false;
}
}  // namespace apc
}  // namespace security
}  // namespace android
}  // namespace aidl
