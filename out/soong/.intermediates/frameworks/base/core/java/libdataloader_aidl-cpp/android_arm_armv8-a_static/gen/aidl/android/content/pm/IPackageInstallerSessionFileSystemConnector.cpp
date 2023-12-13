#include <android/content/pm/IPackageInstallerSessionFileSystemConnector.h>
#include <android/content/pm/BpPackageInstallerSessionFileSystemConnector.h>

namespace android {

namespace content {

namespace pm {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(PackageInstallerSessionFileSystemConnector, "android.content.pm.IPackageInstallerSessionFileSystemConnector")

}  // namespace pm

}  // namespace content

}  // namespace android
#include <android/content/pm/BpPackageInstallerSessionFileSystemConnector.h>
#include <android/content/pm/BnPackageInstallerSessionFileSystemConnector.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace content {

namespace pm {

BpPackageInstallerSessionFileSystemConnector::BpPackageInstallerSessionFileSystemConnector(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IPackageInstallerSessionFileSystemConnector>(_aidl_impl){
}

::android::binder::Status BpPackageInstallerSessionFileSystemConnector::writeData(const ::android::String16& name, int64_t offsetBytes, int64_t lengthBytes, const ::android::os::ParcelFileDescriptor& fd) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeString16(name);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt64(offsetBytes);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt64(lengthBytes);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(fd);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnPackageInstallerSessionFileSystemConnector::TRANSACTION_writeData, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IPackageInstallerSessionFileSystemConnector::getDefaultImpl())) {
     return IPackageInstallerSessionFileSystemConnector::getDefaultImpl()->writeData(name, offsetBytes, lengthBytes, fd);
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

}  // namespace pm

}  // namespace content

}  // namespace android
#include <android/content/pm/BnPackageInstallerSessionFileSystemConnector.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace content {

namespace pm {

BnPackageInstallerSessionFileSystemConnector::BnPackageInstallerSessionFileSystemConnector()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnPackageInstallerSessionFileSystemConnector::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnPackageInstallerSessionFileSystemConnector::TRANSACTION_writeData:
  {
    ::android::String16 in_name;
    int64_t in_offsetBytes;
    int64_t in_lengthBytes;
    ::android::os::ParcelFileDescriptor in_fd;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readString16(&in_name);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt64(&in_offsetBytes);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt64(&in_lengthBytes);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_fd);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(writeData(in_name, in_offsetBytes, in_lengthBytes, in_fd));
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

}  // namespace pm

}  // namespace content

}  // namespace android
