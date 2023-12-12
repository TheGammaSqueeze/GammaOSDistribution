#include <android/service/gatekeeper/IGateKeeperService.h>
#include <android/service/gatekeeper/BpGateKeeperService.h>

namespace android {

namespace service {

namespace gatekeeper {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(GateKeeperService, "android.service.gatekeeper.IGateKeeperService")

}  // namespace gatekeeper

}  // namespace service

}  // namespace android
#include <android/service/gatekeeper/BpGateKeeperService.h>
#include <android/service/gatekeeper/BnGateKeeperService.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace service {

namespace gatekeeper {

BpGateKeeperService::BpGateKeeperService(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IGateKeeperService>(_aidl_impl){
}

::android::binder::Status BpGateKeeperService::enroll(int32_t userId, const ::std::optional<::std::vector<uint8_t>>& currentPasswordHandle, const ::std::optional<::std::vector<uint8_t>>& currentPassword, const ::std::vector<uint8_t>& desiredPassword, ::android::service::gatekeeper::GateKeeperResponse* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markSensitive();
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(userId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(currentPasswordHandle);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(currentPassword);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(desiredPassword);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnGateKeeperService::TRANSACTION_enroll, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IGateKeeperService::getDefaultImpl())) {
     return IGateKeeperService::getDefaultImpl()->enroll(userId, currentPasswordHandle, currentPassword, desiredPassword, _aidl_return);
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

::android::binder::Status BpGateKeeperService::verify(int32_t userId, const ::std::vector<uint8_t>& enrolledPasswordHandle, const ::std::vector<uint8_t>& providedPassword, ::android::service::gatekeeper::GateKeeperResponse* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markSensitive();
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(userId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(enrolledPasswordHandle);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(providedPassword);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnGateKeeperService::TRANSACTION_verify, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IGateKeeperService::getDefaultImpl())) {
     return IGateKeeperService::getDefaultImpl()->verify(userId, enrolledPasswordHandle, providedPassword, _aidl_return);
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

::android::binder::Status BpGateKeeperService::verifyChallenge(int32_t userId, int64_t challenge, const ::std::vector<uint8_t>& enrolledPasswordHandle, const ::std::vector<uint8_t>& providedPassword, ::android::service::gatekeeper::GateKeeperResponse* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markSensitive();
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(userId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt64(challenge);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(enrolledPasswordHandle);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(providedPassword);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnGateKeeperService::TRANSACTION_verifyChallenge, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IGateKeeperService::getDefaultImpl())) {
     return IGateKeeperService::getDefaultImpl()->verifyChallenge(userId, challenge, enrolledPasswordHandle, providedPassword, _aidl_return);
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

::android::binder::Status BpGateKeeperService::getSecureUserId(int32_t userId, int64_t* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markSensitive();
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(userId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnGateKeeperService::TRANSACTION_getSecureUserId, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IGateKeeperService::getDefaultImpl())) {
     return IGateKeeperService::getDefaultImpl()->getSecureUserId(userId, _aidl_return);
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
  _aidl_ret_status = _aidl_reply.readInt64(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpGateKeeperService::clearSecureUserId(int32_t userId) {
  ::android::Parcel _aidl_data;
  _aidl_data.markSensitive();
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(userId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnGateKeeperService::TRANSACTION_clearSecureUserId, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IGateKeeperService::getDefaultImpl())) {
     return IGateKeeperService::getDefaultImpl()->clearSecureUserId(userId);
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
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpGateKeeperService::reportDeviceSetupComplete() {
  ::android::Parcel _aidl_data;
  _aidl_data.markSensitive();
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnGateKeeperService::TRANSACTION_reportDeviceSetupComplete, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_CLEAR_BUF);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IGateKeeperService::getDefaultImpl())) {
     return IGateKeeperService::getDefaultImpl()->reportDeviceSetupComplete();
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
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

}  // namespace gatekeeper

}  // namespace service

}  // namespace android
#include <android/service/gatekeeper/BnGateKeeperService.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace service {

namespace gatekeeper {

BnGateKeeperService::BnGateKeeperService()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnGateKeeperService::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnGateKeeperService::TRANSACTION_enroll:
  {
    int32_t in_userId;
    ::std::optional<::std::vector<uint8_t>> in_currentPasswordHandle;
    ::std::optional<::std::vector<uint8_t>> in_currentPassword;
    ::std::vector<uint8_t> in_desiredPassword;
    ::android::service::gatekeeper::GateKeeperResponse _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_userId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_currentPasswordHandle);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_currentPassword);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_desiredPassword);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(enroll(in_userId, in_currentPasswordHandle, in_currentPassword, in_desiredPassword, &_aidl_return));
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
  case BnGateKeeperService::TRANSACTION_verify:
  {
    int32_t in_userId;
    ::std::vector<uint8_t> in_enrolledPasswordHandle;
    ::std::vector<uint8_t> in_providedPassword;
    ::android::service::gatekeeper::GateKeeperResponse _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_userId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_enrolledPasswordHandle);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_providedPassword);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(verify(in_userId, in_enrolledPasswordHandle, in_providedPassword, &_aidl_return));
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
  case BnGateKeeperService::TRANSACTION_verifyChallenge:
  {
    int32_t in_userId;
    int64_t in_challenge;
    ::std::vector<uint8_t> in_enrolledPasswordHandle;
    ::std::vector<uint8_t> in_providedPassword;
    ::android::service::gatekeeper::GateKeeperResponse _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_userId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt64(&in_challenge);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_enrolledPasswordHandle);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_providedPassword);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(verifyChallenge(in_userId, in_challenge, in_enrolledPasswordHandle, in_providedPassword, &_aidl_return));
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
  case BnGateKeeperService::TRANSACTION_getSecureUserId:
  {
    int32_t in_userId;
    int64_t _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_userId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(getSecureUserId(in_userId, &_aidl_return));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeInt64(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnGateKeeperService::TRANSACTION_clearSecureUserId:
  {
    int32_t in_userId;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_userId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(clearSecureUserId(in_userId));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnGateKeeperService::TRANSACTION_reportDeviceSetupComplete:
  {
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    ::android::binder::Status _aidl_status(reportDeviceSetupComplete());
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
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

}  // namespace gatekeeper

}  // namespace service

}  // namespace android
