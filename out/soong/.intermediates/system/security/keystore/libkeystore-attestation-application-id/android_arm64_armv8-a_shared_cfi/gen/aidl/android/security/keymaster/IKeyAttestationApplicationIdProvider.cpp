#include <android/security/keymaster/IKeyAttestationApplicationIdProvider.h>
#include <android/security/keymaster/BpKeyAttestationApplicationIdProvider.h>

namespace android {

namespace security {

namespace keymaster {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(KeyAttestationApplicationIdProvider, "android.security.keymaster.IKeyAttestationApplicationIdProvider")

}  // namespace keymaster

}  // namespace security

}  // namespace android
#include <android/security/keymaster/BpKeyAttestationApplicationIdProvider.h>
#include <android/security/keymaster/BnKeyAttestationApplicationIdProvider.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace security {

namespace keymaster {

BpKeyAttestationApplicationIdProvider::BpKeyAttestationApplicationIdProvider(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IKeyAttestationApplicationIdProvider>(_aidl_impl){
}

::android::binder::Status BpKeyAttestationApplicationIdProvider::getKeyAttestationApplicationId(int32_t uid, ::android::security::keymaster::KeyAttestationApplicationId* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(uid);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnKeyAttestationApplicationIdProvider::TRANSACTION_getKeyAttestationApplicationId, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IKeyAttestationApplicationIdProvider::getDefaultImpl())) {
     return IKeyAttestationApplicationIdProvider::getDefaultImpl()->getKeyAttestationApplicationId(uid, _aidl_return);
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
  _aidl_ret_status = _aidl_reply.readParcelable(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

}  // namespace keymaster

}  // namespace security

}  // namespace android
#include <android/security/keymaster/BnKeyAttestationApplicationIdProvider.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace security {

namespace keymaster {

BnKeyAttestationApplicationIdProvider::BnKeyAttestationApplicationIdProvider()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnKeyAttestationApplicationIdProvider::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnKeyAttestationApplicationIdProvider::TRANSACTION_getKeyAttestationApplicationId:
  {
    int32_t in_uid;
    ::android::security::keymaster::KeyAttestationApplicationId _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_uid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(getKeyAttestationApplicationId(in_uid, &_aidl_return));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeParcelable(_aidl_return);
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

}  // namespace keymaster

}  // namespace security

}  // namespace android
