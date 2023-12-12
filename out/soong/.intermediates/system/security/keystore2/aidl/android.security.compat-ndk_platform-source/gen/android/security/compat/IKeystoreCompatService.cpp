#include <android/binder_parcel_utils.h>
#include <aidl/android/hardware/security/keymint/BpKeyMintDevice.h>
#include <aidl/android/hardware/security/keymint/BnKeyMintDevice.h>
#include <aidl/android/hardware/security/keymint/IKeyMintDevice.h>
#include <aidl/android/hardware/security/secureclock/BpSecureClock.h>
#include <aidl/android/hardware/security/secureclock/BnSecureClock.h>
#include <aidl/android/hardware/security/secureclock/ISecureClock.h>
#include <aidl/android/hardware/security/sharedsecret/BpSharedSecret.h>
#include <aidl/android/hardware/security/sharedsecret/BnSharedSecret.h>
#include <aidl/android/hardware/security/sharedsecret/ISharedSecret.h>
#include <aidl/android/security/compat/BpKeystoreCompatService.h>
#include <aidl/android/security/compat/BnKeystoreCompatService.h>
#include <aidl/android/security/compat/IKeystoreCompatService.h>

namespace aidl {
namespace android {
namespace security {
namespace compat {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnKeystoreCompatService> _aidl_impl = std::static_pointer_cast<BnKeystoreCompatService>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*getKeyMintDevice*/): {
      ::aidl::android::hardware::security::keymint::SecurityLevel in_securityLevel;
      std::shared_ptr<::aidl::android::hardware::security::keymint::IKeyMintDevice> _aidl_return;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, reinterpret_cast<int32_t*>(&in_securityLevel));
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->getKeyMintDevice(in_securityLevel, &_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::aidl::android::hardware::security::keymint::IKeyMintDevice::writeToParcel(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*getSecureClock*/): {
      std::shared_ptr<::aidl::android::hardware::security::secureclock::ISecureClock> _aidl_return;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->getSecureClock(&_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::aidl::android::hardware::security::secureclock::ISecureClock::writeToParcel(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 2 /*getSharedSecret*/): {
      ::aidl::android::hardware::security::keymint::SecurityLevel in_securityLevel;
      std::shared_ptr<::aidl::android::hardware::security::sharedsecret::ISharedSecret> _aidl_return;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, reinterpret_cast<int32_t*>(&in_securityLevel));
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->getSharedSecret(in_securityLevel, &_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::aidl::android::hardware::security::sharedsecret::ISharedSecret::writeToParcel(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IKeystoreCompatService::descriptor, _aidl_onTransact);

BpKeystoreCompatService::BpKeystoreCompatService(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpKeystoreCompatService::~BpKeystoreCompatService() {}

::ndk::ScopedAStatus BpKeystoreCompatService::getKeyMintDevice(::aidl::android::hardware::security::keymint::SecurityLevel in_securityLevel, std::shared_ptr<::aidl::android::hardware::security::keymint::IKeyMintDevice>* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), static_cast<int32_t>(in_securityLevel));
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*getKeyMintDevice*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IKeystoreCompatService::getDefaultImpl()) {
    _aidl_status = IKeystoreCompatService::getDefaultImpl()->getKeyMintDevice(in_securityLevel, _aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = ::aidl::android::hardware::security::keymint::IKeyMintDevice::readFromParcel(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpKeystoreCompatService::getSecureClock(std::shared_ptr<::aidl::android::hardware::security::secureclock::ISecureClock>* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*getSecureClock*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IKeystoreCompatService::getDefaultImpl()) {
    _aidl_status = IKeystoreCompatService::getDefaultImpl()->getSecureClock(_aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = ::aidl::android::hardware::security::secureclock::ISecureClock::readFromParcel(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpKeystoreCompatService::getSharedSecret(::aidl::android::hardware::security::keymint::SecurityLevel in_securityLevel, std::shared_ptr<::aidl::android::hardware::security::sharedsecret::ISharedSecret>* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), static_cast<int32_t>(in_securityLevel));
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 2 /*getSharedSecret*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IKeystoreCompatService::getDefaultImpl()) {
    _aidl_status = IKeystoreCompatService::getDefaultImpl()->getSharedSecret(in_securityLevel, _aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = ::aidl::android::hardware::security::sharedsecret::ISharedSecret::readFromParcel(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
// Source for BnKeystoreCompatService
BnKeystoreCompatService::BnKeystoreCompatService() {}
BnKeystoreCompatService::~BnKeystoreCompatService() {}
::ndk::SpAIBinder BnKeystoreCompatService::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IKeystoreCompatService
const char* IKeystoreCompatService::descriptor = "android.security.compat.IKeystoreCompatService";
IKeystoreCompatService::IKeystoreCompatService() {}
IKeystoreCompatService::~IKeystoreCompatService() {}


std::shared_ptr<IKeystoreCompatService> IKeystoreCompatService::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IKeystoreCompatService>(interface);
  }
  return ::ndk::SharedRefBase::make<BpKeystoreCompatService>(binder);
}

binder_status_t IKeystoreCompatService::writeToParcel(AParcel* parcel, const std::shared_ptr<IKeystoreCompatService>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IKeystoreCompatService::readFromParcel(const AParcel* parcel, std::shared_ptr<IKeystoreCompatService>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IKeystoreCompatService::fromBinder(binder);
  return STATUS_OK;
}
bool IKeystoreCompatService::setDefaultImpl(const std::shared_ptr<IKeystoreCompatService>& impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IKeystoreCompatService::default_impl);
  if (impl) {
    IKeystoreCompatService::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IKeystoreCompatService>& IKeystoreCompatService::getDefaultImpl() {
  return IKeystoreCompatService::default_impl;
}
std::shared_ptr<IKeystoreCompatService> IKeystoreCompatService::default_impl = nullptr;
::ndk::ScopedAStatus IKeystoreCompatServiceDefault::getKeyMintDevice(::aidl::android::hardware::security::keymint::SecurityLevel /*in_securityLevel*/, std::shared_ptr<::aidl::android::hardware::security::keymint::IKeyMintDevice>* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IKeystoreCompatServiceDefault::getSecureClock(std::shared_ptr<::aidl::android::hardware::security::secureclock::ISecureClock>* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IKeystoreCompatServiceDefault::getSharedSecret(::aidl::android::hardware::security::keymint::SecurityLevel /*in_securityLevel*/, std::shared_ptr<::aidl::android::hardware::security::sharedsecret::ISharedSecret>* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IKeystoreCompatServiceDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IKeystoreCompatServiceDefault::isRemote() {
  return false;
}
}  // namespace compat
}  // namespace security
}  // namespace android
}  // namespace aidl
