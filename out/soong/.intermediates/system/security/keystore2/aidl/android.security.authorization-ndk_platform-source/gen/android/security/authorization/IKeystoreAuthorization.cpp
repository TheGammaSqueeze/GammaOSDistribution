#include <android/binder_parcel_utils.h>
#include <aidl/android/security/authorization/BpKeystoreAuthorization.h>
#include <aidl/android/security/authorization/BnKeystoreAuthorization.h>
#include <aidl/android/security/authorization/IKeystoreAuthorization.h>

namespace aidl {
namespace android {
namespace security {
namespace authorization {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnKeystoreAuthorization> _aidl_impl = std::static_pointer_cast<BnKeystoreAuthorization>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*addAuthToken*/): {
      ::aidl::android::hardware::security::keymint::HardwareAuthToken in_authToken;

      _aidl_ret_status = ::ndk::AParcel_readParcelable(_aidl_in, &in_authToken);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->addAuthToken(in_authToken);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*onLockScreenEvent*/): {
      ::aidl::android::security::authorization::LockScreenEvent in_lockScreenEvent;
      int32_t in_userId;
      std::optional<std::vector<uint8_t>> in_password;
      std::optional<std::vector<int64_t>> in_unlockingSids;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, reinterpret_cast<int32_t*>(&in_lockScreenEvent));
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_userId);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_password);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_unlockingSids);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onLockScreenEvent(in_lockScreenEvent, in_userId, in_password, in_unlockingSids);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 2 /*getAuthTokensForCredStore*/): {
      int64_t in_challenge;
      int64_t in_secureUserId;
      int64_t in_authTokenMaxAgeMillis;
      ::aidl::android::security::authorization::AuthorizationTokens _aidl_return;

      _aidl_ret_status = AParcel_readInt64(_aidl_in, &in_challenge);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt64(_aidl_in, &in_secureUserId);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt64(_aidl_in, &in_authTokenMaxAgeMillis);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->getAuthTokensForCredStore(in_challenge, in_secureUserId, in_authTokenMaxAgeMillis, &_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeParcelable(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IKeystoreAuthorization::descriptor, _aidl_onTransact);

BpKeystoreAuthorization::BpKeystoreAuthorization(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpKeystoreAuthorization::~BpKeystoreAuthorization() {}

::ndk::ScopedAStatus BpKeystoreAuthorization::addAuthToken(const ::aidl::android::hardware::security::keymint::HardwareAuthToken& in_authToken) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  AParcel_markSensitive(_aidl_in.get());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeParcelable(_aidl_in.get(), in_authToken);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*addAuthToken*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_CLEAR_BUF
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IKeystoreAuthorization::getDefaultImpl()) {
    _aidl_status = IKeystoreAuthorization::getDefaultImpl()->addAuthToken(in_authToken);
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
::ndk::ScopedAStatus BpKeystoreAuthorization::onLockScreenEvent(::aidl::android::security::authorization::LockScreenEvent in_lockScreenEvent, int32_t in_userId, const std::optional<std::vector<uint8_t>>& in_password, const std::optional<std::vector<int64_t>>& in_unlockingSids) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  AParcel_markSensitive(_aidl_in.get());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), static_cast<int32_t>(in_lockScreenEvent));
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_userId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_password);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_unlockingSids);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*onLockScreenEvent*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_CLEAR_BUF
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IKeystoreAuthorization::getDefaultImpl()) {
    _aidl_status = IKeystoreAuthorization::getDefaultImpl()->onLockScreenEvent(in_lockScreenEvent, in_userId, in_password, in_unlockingSids);
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
::ndk::ScopedAStatus BpKeystoreAuthorization::getAuthTokensForCredStore(int64_t in_challenge, int64_t in_secureUserId, int64_t in_authTokenMaxAgeMillis, ::aidl::android::security::authorization::AuthorizationTokens* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  AParcel_markSensitive(_aidl_in.get());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt64(_aidl_in.get(), in_challenge);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt64(_aidl_in.get(), in_secureUserId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt64(_aidl_in.get(), in_authTokenMaxAgeMillis);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 2 /*getAuthTokensForCredStore*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_CLEAR_BUF
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IKeystoreAuthorization::getDefaultImpl()) {
    _aidl_status = IKeystoreAuthorization::getDefaultImpl()->getAuthTokensForCredStore(in_challenge, in_secureUserId, in_authTokenMaxAgeMillis, _aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = ::ndk::AParcel_readParcelable(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
// Source for BnKeystoreAuthorization
BnKeystoreAuthorization::BnKeystoreAuthorization() {}
BnKeystoreAuthorization::~BnKeystoreAuthorization() {}
::ndk::SpAIBinder BnKeystoreAuthorization::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IKeystoreAuthorization
const char* IKeystoreAuthorization::descriptor = "android.security.authorization.IKeystoreAuthorization";
IKeystoreAuthorization::IKeystoreAuthorization() {}
IKeystoreAuthorization::~IKeystoreAuthorization() {}


std::shared_ptr<IKeystoreAuthorization> IKeystoreAuthorization::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IKeystoreAuthorization>(interface);
  }
  return ::ndk::SharedRefBase::make<BpKeystoreAuthorization>(binder);
}

binder_status_t IKeystoreAuthorization::writeToParcel(AParcel* parcel, const std::shared_ptr<IKeystoreAuthorization>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IKeystoreAuthorization::readFromParcel(const AParcel* parcel, std::shared_ptr<IKeystoreAuthorization>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IKeystoreAuthorization::fromBinder(binder);
  return STATUS_OK;
}
bool IKeystoreAuthorization::setDefaultImpl(const std::shared_ptr<IKeystoreAuthorization>& impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IKeystoreAuthorization::default_impl);
  if (impl) {
    IKeystoreAuthorization::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IKeystoreAuthorization>& IKeystoreAuthorization::getDefaultImpl() {
  return IKeystoreAuthorization::default_impl;
}
std::shared_ptr<IKeystoreAuthorization> IKeystoreAuthorization::default_impl = nullptr;
::ndk::ScopedAStatus IKeystoreAuthorizationDefault::addAuthToken(const ::aidl::android::hardware::security::keymint::HardwareAuthToken& /*in_authToken*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IKeystoreAuthorizationDefault::onLockScreenEvent(::aidl::android::security::authorization::LockScreenEvent /*in_lockScreenEvent*/, int32_t /*in_userId*/, const std::optional<std::vector<uint8_t>>& /*in_password*/, const std::optional<std::vector<int64_t>>& /*in_unlockingSids*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IKeystoreAuthorizationDefault::getAuthTokensForCredStore(int64_t /*in_challenge*/, int64_t /*in_secureUserId*/, int64_t /*in_authTokenMaxAgeMillis*/, ::aidl::android::security::authorization::AuthorizationTokens* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IKeystoreAuthorizationDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IKeystoreAuthorizationDefault::isRemote() {
  return false;
}
}  // namespace authorization
}  // namespace security
}  // namespace android
}  // namespace aidl
