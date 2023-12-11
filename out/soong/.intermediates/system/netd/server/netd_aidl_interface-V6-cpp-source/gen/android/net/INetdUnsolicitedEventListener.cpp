#include <android/net/INetdUnsolicitedEventListener.h>
#include <android/net/BpNetdUnsolicitedEventListener.h>

namespace android {

namespace net {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(NetdUnsolicitedEventListener, "android.net.INetdUnsolicitedEventListener")

}  // namespace net

}  // namespace android
#include <android/net/BpNetdUnsolicitedEventListener.h>
#include <android/net/BnNetdUnsolicitedEventListener.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>
#include <chrono>
#include <functional>

namespace android {

namespace net {

BpNetdUnsolicitedEventListener::BpNetdUnsolicitedEventListener(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<INetdUnsolicitedEventListener>(_aidl_impl){
}

std::function<void(const BpNetdUnsolicitedEventListener::TransactionLog&)> BpNetdUnsolicitedEventListener::logFunc;

::android::binder::Status BpNetdUnsolicitedEventListener::onInterfaceClassActivityChanged(bool isActive, int32_t timerLabel, int64_t timestampNs, int32_t uid) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetdUnsolicitedEventListener::TransactionLog _transaction_log;
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("isActive", ::android::internal::ToString(isActive));
    _transaction_log.input_args.emplace_back("timerLabel", ::android::internal::ToString(timerLabel));
    _transaction_log.input_args.emplace_back("timestampNs", ::android::internal::ToString(timestampNs));
    _transaction_log.input_args.emplace_back("uid", ::android::internal::ToString(uid));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(isActive);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(timerLabel);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt64(timestampNs);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(uid);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetdUnsolicitedEventListener::TRANSACTION_onInterfaceClassActivityChanged, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetdUnsolicitedEventListener::getDefaultImpl())) {
     return INetdUnsolicitedEventListener::getDefaultImpl()->onInterfaceClassActivityChanged(isActive, timerLabel, timestampNs, uid);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetdUnsolicitedEventListener";
    _transaction_log.method_name = "onInterfaceClassActivityChanged";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetdUnsolicitedEventListener::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetdUnsolicitedEventListener::onQuotaLimitReached(const ::std::string& alertName, const ::std::string& ifName) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetdUnsolicitedEventListener::TransactionLog _transaction_log;
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("alertName", ::android::internal::ToString(alertName));
    _transaction_log.input_args.emplace_back("ifName", ::android::internal::ToString(ifName));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(alertName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetdUnsolicitedEventListener::TRANSACTION_onQuotaLimitReached, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetdUnsolicitedEventListener::getDefaultImpl())) {
     return INetdUnsolicitedEventListener::getDefaultImpl()->onQuotaLimitReached(alertName, ifName);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetdUnsolicitedEventListener";
    _transaction_log.method_name = "onQuotaLimitReached";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetdUnsolicitedEventListener::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetdUnsolicitedEventListener::onInterfaceDnsServerInfo(const ::std::string& ifName, int64_t lifetimeS, const ::std::vector<::std::string>& servers) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetdUnsolicitedEventListener::TransactionLog _transaction_log;
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("ifName", ::android::internal::ToString(ifName));
    _transaction_log.input_args.emplace_back("lifetimeS", ::android::internal::ToString(lifetimeS));
    _transaction_log.input_args.emplace_back("servers", ::android::internal::ToString(servers));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt64(lifetimeS);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8VectorAsUtf16Vector(servers);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetdUnsolicitedEventListener::TRANSACTION_onInterfaceDnsServerInfo, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetdUnsolicitedEventListener::getDefaultImpl())) {
     return INetdUnsolicitedEventListener::getDefaultImpl()->onInterfaceDnsServerInfo(ifName, lifetimeS, servers);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetdUnsolicitedEventListener";
    _transaction_log.method_name = "onInterfaceDnsServerInfo";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetdUnsolicitedEventListener::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetdUnsolicitedEventListener::onInterfaceAddressUpdated(const ::std::string& addr, const ::std::string& ifName, int32_t flags, int32_t scope) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetdUnsolicitedEventListener::TransactionLog _transaction_log;
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("addr", ::android::internal::ToString(addr));
    _transaction_log.input_args.emplace_back("ifName", ::android::internal::ToString(ifName));
    _transaction_log.input_args.emplace_back("flags", ::android::internal::ToString(flags));
    _transaction_log.input_args.emplace_back("scope", ::android::internal::ToString(scope));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(addr);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(flags);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(scope);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetdUnsolicitedEventListener::TRANSACTION_onInterfaceAddressUpdated, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetdUnsolicitedEventListener::getDefaultImpl())) {
     return INetdUnsolicitedEventListener::getDefaultImpl()->onInterfaceAddressUpdated(addr, ifName, flags, scope);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetdUnsolicitedEventListener";
    _transaction_log.method_name = "onInterfaceAddressUpdated";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetdUnsolicitedEventListener::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetdUnsolicitedEventListener::onInterfaceAddressRemoved(const ::std::string& addr, const ::std::string& ifName, int32_t flags, int32_t scope) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetdUnsolicitedEventListener::TransactionLog _transaction_log;
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("addr", ::android::internal::ToString(addr));
    _transaction_log.input_args.emplace_back("ifName", ::android::internal::ToString(ifName));
    _transaction_log.input_args.emplace_back("flags", ::android::internal::ToString(flags));
    _transaction_log.input_args.emplace_back("scope", ::android::internal::ToString(scope));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(addr);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(flags);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(scope);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetdUnsolicitedEventListener::TRANSACTION_onInterfaceAddressRemoved, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetdUnsolicitedEventListener::getDefaultImpl())) {
     return INetdUnsolicitedEventListener::getDefaultImpl()->onInterfaceAddressRemoved(addr, ifName, flags, scope);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetdUnsolicitedEventListener";
    _transaction_log.method_name = "onInterfaceAddressRemoved";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetdUnsolicitedEventListener::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetdUnsolicitedEventListener::onInterfaceAdded(const ::std::string& ifName) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetdUnsolicitedEventListener::TransactionLog _transaction_log;
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("ifName", ::android::internal::ToString(ifName));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetdUnsolicitedEventListener::TRANSACTION_onInterfaceAdded, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetdUnsolicitedEventListener::getDefaultImpl())) {
     return INetdUnsolicitedEventListener::getDefaultImpl()->onInterfaceAdded(ifName);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetdUnsolicitedEventListener";
    _transaction_log.method_name = "onInterfaceAdded";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetdUnsolicitedEventListener::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetdUnsolicitedEventListener::onInterfaceRemoved(const ::std::string& ifName) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetdUnsolicitedEventListener::TransactionLog _transaction_log;
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("ifName", ::android::internal::ToString(ifName));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetdUnsolicitedEventListener::TRANSACTION_onInterfaceRemoved, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetdUnsolicitedEventListener::getDefaultImpl())) {
     return INetdUnsolicitedEventListener::getDefaultImpl()->onInterfaceRemoved(ifName);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetdUnsolicitedEventListener";
    _transaction_log.method_name = "onInterfaceRemoved";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetdUnsolicitedEventListener::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetdUnsolicitedEventListener::onInterfaceChanged(const ::std::string& ifName, bool up) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetdUnsolicitedEventListener::TransactionLog _transaction_log;
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("ifName", ::android::internal::ToString(ifName));
    _transaction_log.input_args.emplace_back("up", ::android::internal::ToString(up));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(up);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetdUnsolicitedEventListener::TRANSACTION_onInterfaceChanged, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetdUnsolicitedEventListener::getDefaultImpl())) {
     return INetdUnsolicitedEventListener::getDefaultImpl()->onInterfaceChanged(ifName, up);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetdUnsolicitedEventListener";
    _transaction_log.method_name = "onInterfaceChanged";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetdUnsolicitedEventListener::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetdUnsolicitedEventListener::onInterfaceLinkStateChanged(const ::std::string& ifName, bool up) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetdUnsolicitedEventListener::TransactionLog _transaction_log;
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("ifName", ::android::internal::ToString(ifName));
    _transaction_log.input_args.emplace_back("up", ::android::internal::ToString(up));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(up);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetdUnsolicitedEventListener::TRANSACTION_onInterfaceLinkStateChanged, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetdUnsolicitedEventListener::getDefaultImpl())) {
     return INetdUnsolicitedEventListener::getDefaultImpl()->onInterfaceLinkStateChanged(ifName, up);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetdUnsolicitedEventListener";
    _transaction_log.method_name = "onInterfaceLinkStateChanged";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetdUnsolicitedEventListener::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetdUnsolicitedEventListener::onRouteChanged(bool updated, const ::std::string& route, const ::std::string& gateway, const ::std::string& ifName) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetdUnsolicitedEventListener::TransactionLog _transaction_log;
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("updated", ::android::internal::ToString(updated));
    _transaction_log.input_args.emplace_back("route", ::android::internal::ToString(route));
    _transaction_log.input_args.emplace_back("gateway", ::android::internal::ToString(gateway));
    _transaction_log.input_args.emplace_back("ifName", ::android::internal::ToString(ifName));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(updated);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(route);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(gateway);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetdUnsolicitedEventListener::TRANSACTION_onRouteChanged, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetdUnsolicitedEventListener::getDefaultImpl())) {
     return INetdUnsolicitedEventListener::getDefaultImpl()->onRouteChanged(updated, route, gateway, ifName);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetdUnsolicitedEventListener";
    _transaction_log.method_name = "onRouteChanged";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetdUnsolicitedEventListener::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetdUnsolicitedEventListener::onStrictCleartextDetected(int32_t uid, const ::std::string& hex) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetdUnsolicitedEventListener::TransactionLog _transaction_log;
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("uid", ::android::internal::ToString(uid));
    _transaction_log.input_args.emplace_back("hex", ::android::internal::ToString(hex));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(uid);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(hex);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetdUnsolicitedEventListener::TRANSACTION_onStrictCleartextDetected, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetdUnsolicitedEventListener::getDefaultImpl())) {
     return INetdUnsolicitedEventListener::getDefaultImpl()->onStrictCleartextDetected(uid, hex);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetdUnsolicitedEventListener::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetdUnsolicitedEventListener";
    _transaction_log.method_name = "onStrictCleartextDetected";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetdUnsolicitedEventListener::logFunc(_transaction_log);
  }
  return _aidl_status;
}

int32_t BpNetdUnsolicitedEventListener::getInterfaceVersion() {
  if (cached_version_ == -1) {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(BnNetdUnsolicitedEventListener::TRANSACTION_getInterfaceVersion, data, &reply);
    if (err == ::android::OK) {
      ::android::binder::Status _aidl_status;
      err = _aidl_status.readFromParcel(reply);
      if (err == ::android::OK && _aidl_status.isOk()) {
        cached_version_ = reply.readInt32();
      }
    }
  }
  return cached_version_;
}

std::string BpNetdUnsolicitedEventListener::getInterfaceHash() {
  std::lock_guard<std::mutex> lockGuard(cached_hash_mutex_);
  if (cached_hash_ == "-1") {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(BnNetdUnsolicitedEventListener::TRANSACTION_getInterfaceHash, data, &reply);
    if (err == ::android::OK) {
      ::android::binder::Status _aidl_status;
      err = _aidl_status.readFromParcel(reply);
      if (err == ::android::OK && _aidl_status.isOk()) {
        reply.readUtf8FromUtf16(&cached_hash_);
      }
    }
  }
  return cached_hash_;
}

}  // namespace net

}  // namespace android
#include <android/net/BnNetdUnsolicitedEventListener.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>
#include <chrono>
#include <functional>

namespace android {

namespace net {

BnNetdUnsolicitedEventListener::BnNetdUnsolicitedEventListener()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnNetdUnsolicitedEventListener::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnNetdUnsolicitedEventListener::TRANSACTION_onInterfaceClassActivityChanged:
  {
    bool in_isActive;
    int32_t in_timerLabel;
    int64_t in_timestampNs;
    int32_t in_uid;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_isActive);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_timerLabel);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt64(&in_timestampNs);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_uid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetdUnsolicitedEventListener::TransactionLog _transaction_log;
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_isActive", ::android::internal::ToString(in_isActive));
      _transaction_log.input_args.emplace_back("in_timerLabel", ::android::internal::ToString(in_timerLabel));
      _transaction_log.input_args.emplace_back("in_timestampNs", ::android::internal::ToString(in_timestampNs));
      _transaction_log.input_args.emplace_back("in_uid", ::android::internal::ToString(in_uid));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(onInterfaceClassActivityChanged(in_isActive, in_timerLabel, in_timestampNs, in_uid));
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetdUnsolicitedEventListener";
      _transaction_log.method_name = "onInterfaceClassActivityChanged";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetdUnsolicitedEventListener::logFunc(_transaction_log);
    }
  }
  break;
  case BnNetdUnsolicitedEventListener::TRANSACTION_onQuotaLimitReached:
  {
    ::std::string in_alertName;
    ::std::string in_ifName;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_alertName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetdUnsolicitedEventListener::TransactionLog _transaction_log;
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_alertName", ::android::internal::ToString(in_alertName));
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(onQuotaLimitReached(in_alertName, in_ifName));
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetdUnsolicitedEventListener";
      _transaction_log.method_name = "onQuotaLimitReached";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetdUnsolicitedEventListener::logFunc(_transaction_log);
    }
  }
  break;
  case BnNetdUnsolicitedEventListener::TRANSACTION_onInterfaceDnsServerInfo:
  {
    ::std::string in_ifName;
    int64_t in_lifetimeS;
    ::std::vector<::std::string> in_servers;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt64(&in_lifetimeS);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8VectorFromUtf16Vector(&in_servers);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetdUnsolicitedEventListener::TransactionLog _transaction_log;
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
      _transaction_log.input_args.emplace_back("in_lifetimeS", ::android::internal::ToString(in_lifetimeS));
      _transaction_log.input_args.emplace_back("in_servers", ::android::internal::ToString(in_servers));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(onInterfaceDnsServerInfo(in_ifName, in_lifetimeS, in_servers));
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetdUnsolicitedEventListener";
      _transaction_log.method_name = "onInterfaceDnsServerInfo";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetdUnsolicitedEventListener::logFunc(_transaction_log);
    }
  }
  break;
  case BnNetdUnsolicitedEventListener::TRANSACTION_onInterfaceAddressUpdated:
  {
    ::std::string in_addr;
    ::std::string in_ifName;
    int32_t in_flags;
    int32_t in_scope;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_addr);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_flags);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_scope);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetdUnsolicitedEventListener::TransactionLog _transaction_log;
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_addr", ::android::internal::ToString(in_addr));
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
      _transaction_log.input_args.emplace_back("in_flags", ::android::internal::ToString(in_flags));
      _transaction_log.input_args.emplace_back("in_scope", ::android::internal::ToString(in_scope));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(onInterfaceAddressUpdated(in_addr, in_ifName, in_flags, in_scope));
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetdUnsolicitedEventListener";
      _transaction_log.method_name = "onInterfaceAddressUpdated";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetdUnsolicitedEventListener::logFunc(_transaction_log);
    }
  }
  break;
  case BnNetdUnsolicitedEventListener::TRANSACTION_onInterfaceAddressRemoved:
  {
    ::std::string in_addr;
    ::std::string in_ifName;
    int32_t in_flags;
    int32_t in_scope;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_addr);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_flags);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_scope);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetdUnsolicitedEventListener::TransactionLog _transaction_log;
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_addr", ::android::internal::ToString(in_addr));
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
      _transaction_log.input_args.emplace_back("in_flags", ::android::internal::ToString(in_flags));
      _transaction_log.input_args.emplace_back("in_scope", ::android::internal::ToString(in_scope));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(onInterfaceAddressRemoved(in_addr, in_ifName, in_flags, in_scope));
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetdUnsolicitedEventListener";
      _transaction_log.method_name = "onInterfaceAddressRemoved";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetdUnsolicitedEventListener::logFunc(_transaction_log);
    }
  }
  break;
  case BnNetdUnsolicitedEventListener::TRANSACTION_onInterfaceAdded:
  {
    ::std::string in_ifName;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetdUnsolicitedEventListener::TransactionLog _transaction_log;
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(onInterfaceAdded(in_ifName));
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetdUnsolicitedEventListener";
      _transaction_log.method_name = "onInterfaceAdded";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetdUnsolicitedEventListener::logFunc(_transaction_log);
    }
  }
  break;
  case BnNetdUnsolicitedEventListener::TRANSACTION_onInterfaceRemoved:
  {
    ::std::string in_ifName;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetdUnsolicitedEventListener::TransactionLog _transaction_log;
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(onInterfaceRemoved(in_ifName));
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetdUnsolicitedEventListener";
      _transaction_log.method_name = "onInterfaceRemoved";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetdUnsolicitedEventListener::logFunc(_transaction_log);
    }
  }
  break;
  case BnNetdUnsolicitedEventListener::TRANSACTION_onInterfaceChanged:
  {
    ::std::string in_ifName;
    bool in_up;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_up);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetdUnsolicitedEventListener::TransactionLog _transaction_log;
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
      _transaction_log.input_args.emplace_back("in_up", ::android::internal::ToString(in_up));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(onInterfaceChanged(in_ifName, in_up));
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetdUnsolicitedEventListener";
      _transaction_log.method_name = "onInterfaceChanged";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetdUnsolicitedEventListener::logFunc(_transaction_log);
    }
  }
  break;
  case BnNetdUnsolicitedEventListener::TRANSACTION_onInterfaceLinkStateChanged:
  {
    ::std::string in_ifName;
    bool in_up;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_up);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetdUnsolicitedEventListener::TransactionLog _transaction_log;
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
      _transaction_log.input_args.emplace_back("in_up", ::android::internal::ToString(in_up));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(onInterfaceLinkStateChanged(in_ifName, in_up));
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetdUnsolicitedEventListener";
      _transaction_log.method_name = "onInterfaceLinkStateChanged";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetdUnsolicitedEventListener::logFunc(_transaction_log);
    }
  }
  break;
  case BnNetdUnsolicitedEventListener::TRANSACTION_onRouteChanged:
  {
    bool in_updated;
    ::std::string in_route;
    ::std::string in_gateway;
    ::std::string in_ifName;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_updated);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_route);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_gateway);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetdUnsolicitedEventListener::TransactionLog _transaction_log;
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_updated", ::android::internal::ToString(in_updated));
      _transaction_log.input_args.emplace_back("in_route", ::android::internal::ToString(in_route));
      _transaction_log.input_args.emplace_back("in_gateway", ::android::internal::ToString(in_gateway));
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(onRouteChanged(in_updated, in_route, in_gateway, in_ifName));
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetdUnsolicitedEventListener";
      _transaction_log.method_name = "onRouteChanged";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetdUnsolicitedEventListener::logFunc(_transaction_log);
    }
  }
  break;
  case BnNetdUnsolicitedEventListener::TRANSACTION_onStrictCleartextDetected:
  {
    int32_t in_uid;
    ::std::string in_hex;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_uid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_hex);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetdUnsolicitedEventListener::TransactionLog _transaction_log;
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_uid", ::android::internal::ToString(in_uid));
      _transaction_log.input_args.emplace_back("in_hex", ::android::internal::ToString(in_hex));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(onStrictCleartextDetected(in_uid, in_hex));
    if (BnNetdUnsolicitedEventListener::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetdUnsolicitedEventListener";
      _transaction_log.method_name = "onStrictCleartextDetected";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetdUnsolicitedEventListener::logFunc(_transaction_log);
    }
  }
  break;
  case BnNetdUnsolicitedEventListener::TRANSACTION_getInterfaceVersion:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeInt32(INetdUnsolicitedEventListener::VERSION);
  }
  break;
  case BnNetdUnsolicitedEventListener::TRANSACTION_getInterfaceHash:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeUtf8AsUtf16(INetdUnsolicitedEventListener::HASH);
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

int32_t BnNetdUnsolicitedEventListener::getInterfaceVersion() {
  return INetdUnsolicitedEventListener::VERSION;
}

std::string BnNetdUnsolicitedEventListener::getInterfaceHash() {
  return INetdUnsolicitedEventListener::HASH;
}

std::function<void(const BnNetdUnsolicitedEventListener::TransactionLog&)> BnNetdUnsolicitedEventListener::logFunc;

}  // namespace net

}  // namespace android
