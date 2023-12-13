#include <android/security/identity/ICredentialStoreFactory.h>
#include <android/security/identity/BpCredentialStoreFactory.h>

namespace android {

namespace security {

namespace identity {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(CredentialStoreFactory, "android.security.identity.ICredentialStoreFactory")

}  // namespace identity

}  // namespace security

}  // namespace android
#include <android/security/identity/BpCredentialStoreFactory.h>
#include <android/security/identity/BnCredentialStoreFactory.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace security {

namespace identity {

BpCredentialStoreFactory::BpCredentialStoreFactory(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<ICredentialStoreFactory>(_aidl_impl){
}

::android::binder::Status BpCredentialStoreFactory::getCredentialStore(int32_t credentialStoreType, ::android::sp<::android::security::identity::ICredentialStore>* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(credentialStoreType);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnCredentialStoreFactory::TRANSACTION_getCredentialStore, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && ICredentialStoreFactory::getDefaultImpl())) {
     return ICredentialStoreFactory::getDefaultImpl()->getCredentialStore(credentialStoreType, _aidl_return);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_ret_status = _aidl_reply.readStrongBinder(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

}  // namespace identity

}  // namespace security

}  // namespace android
#include <android/security/identity/BnCredentialStoreFactory.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace security {

namespace identity {

BnCredentialStoreFactory::BnCredentialStoreFactory()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnCredentialStoreFactory::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnCredentialStoreFactory::TRANSACTION_getCredentialStore:
  {
    int32_t in_credentialStoreType;
    ::android::sp<::android::security::identity::ICredentialStore> _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_credentialStoreType);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(getCredentialStore(in_credentialStoreType, &_aidl_return));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeStrongBinder(::android::security::identity::ICredentialStore::asBinder(_aidl_return));
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  default:
  {
    _aidl_ret_status = ::android::BBinder::onTransact(_aidl_code, _aidl_data, _aidl_reply, _aidl_flags);
  }
  break;
  }
  if (_aidl_ret_status == ::android::UNEXPECTED_NULL) {
    _aidl_ret_status = ::android::binder::Status::fromExceptionCode(::android::binder::Status::EX_NULL_POINTER).writeToParcel(_aidl_reply);
  }
  return _aidl_ret_status;
}

}  // namespace identity

}  // namespace security

}  // namespace android
