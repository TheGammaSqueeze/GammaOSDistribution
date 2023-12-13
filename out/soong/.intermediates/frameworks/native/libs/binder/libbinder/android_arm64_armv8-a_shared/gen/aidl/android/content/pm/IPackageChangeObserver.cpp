#include <android/content/pm/IPackageChangeObserver.h>
#include <android/content/pm/BpPackageChangeObserver.h>

namespace android {

namespace content {

namespace pm {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(PackageChangeObserver, "android.content.pm.IPackageChangeObserver")

}  // namespace pm

}  // namespace content

}  // namespace android
#include <android/content/pm/BpPackageChangeObserver.h>
#include <android/content/pm/BnPackageChangeObserver.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace content {

namespace pm {

BpPackageChangeObserver::BpPackageChangeObserver(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IPackageChangeObserver>(_aidl_impl){
}

::android::binder::Status BpPackageChangeObserver::onPackageChanged(const ::android::content::pm::PackageChangeEvent& event) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(event);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnPackageChangeObserver::TRANSACTION_onPackageChanged, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IPackageChangeObserver::getDefaultImpl())) {
     return IPackageChangeObserver::getDefaultImpl()->onPackageChanged(event);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

}  // namespace pm

}  // namespace content

}  // namespace android
#include <android/content/pm/BnPackageChangeObserver.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace content {

namespace pm {

BnPackageChangeObserver::BnPackageChangeObserver()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnPackageChangeObserver::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnPackageChangeObserver::TRANSACTION_onPackageChanged:
  {
    ::android::content::pm::PackageChangeEvent in_event;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_event);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onPackageChanged(in_event));
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
