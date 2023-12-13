#include <android/gui/IWindowInfosListener.h>
#include <android/gui/BpWindowInfosListener.h>

namespace android {

namespace gui {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(WindowInfosListener, "android.gui.IWindowInfosListener")

}  // namespace gui

}  // namespace android
#include <android/gui/BpWindowInfosListener.h>
#include <android/gui/BnWindowInfosListener.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace gui {

BpWindowInfosListener::BpWindowInfosListener(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IWindowInfosListener>(_aidl_impl){
}

::android::binder::Status BpWindowInfosListener::onWindowInfosChanged(const ::std::vector<::android::gui::WindowInfo>& windowInfos, const ::android::sp<::android::gui::IWindowInfosReportedListener>& windowInfosReportedListener) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelableVector(windowInfos);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeStrongBinder(::android::gui::IWindowInfosReportedListener::asBinder(windowInfosReportedListener));
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnWindowInfosListener::TRANSACTION_onWindowInfosChanged, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IWindowInfosListener::getDefaultImpl())) {
     return IWindowInfosListener::getDefaultImpl()->onWindowInfosChanged(windowInfos, windowInfosReportedListener);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

}  // namespace gui

}  // namespace android
#include <android/gui/BnWindowInfosListener.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace gui {

BnWindowInfosListener::BnWindowInfosListener()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnWindowInfosListener::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnWindowInfosListener::TRANSACTION_onWindowInfosChanged:
  {
    ::std::vector<::android::gui::WindowInfo> in_windowInfos;
    ::android::sp<::android::gui::IWindowInfosReportedListener> in_windowInfosReportedListener;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelableVector(&in_windowInfos);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readNullableStrongBinder(&in_windowInfosReportedListener);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onWindowInfosChanged(in_windowInfos, in_windowInfosReportedListener));
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

}  // namespace gui

}  // namespace android
