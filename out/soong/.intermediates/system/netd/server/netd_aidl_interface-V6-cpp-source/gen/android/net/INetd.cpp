#include <android/net/INetd.h>
#include <android/net/BpNetd.h>

namespace android {

namespace net {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(Netd, "android.net.INetd")

const ::android::String16& INetd::IPSEC_INTERFACE_PREFIX() {
  static const ::android::String16 value(::android::String16("ipsec"));
  return value;
}

const ::android::String16& INetd::NEXTHOP_NONE() {
  static const ::android::String16 value(::android::String16(""));
  return value;
}

const ::android::String16& INetd::NEXTHOP_UNREACHABLE() {
  static const ::android::String16 value(::android::String16("unreachable"));
  return value;
}

const ::android::String16& INetd::NEXTHOP_THROW() {
  static const ::android::String16 value(::android::String16("throw"));
  return value;
}

const ::android::String16& INetd::IF_STATE_UP() {
  static const ::android::String16 value(::android::String16("up"));
  return value;
}

const ::android::String16& INetd::IF_STATE_DOWN() {
  static const ::android::String16 value(::android::String16("down"));
  return value;
}

const ::android::String16& INetd::IF_FLAG_BROADCAST() {
  static const ::android::String16 value(::android::String16("broadcast"));
  return value;
}

const ::android::String16& INetd::IF_FLAG_LOOPBACK() {
  static const ::android::String16 value(::android::String16("loopback"));
  return value;
}

const ::android::String16& INetd::IF_FLAG_POINTOPOINT() {
  static const ::android::String16 value(::android::String16("point-to-point"));
  return value;
}

const ::android::String16& INetd::IF_FLAG_RUNNING() {
  static const ::android::String16 value(::android::String16("running"));
  return value;
}

const ::android::String16& INetd::IF_FLAG_MULTICAST() {
  static const ::android::String16 value(::android::String16("multicast"));
  return value;
}

}  // namespace net

}  // namespace android
#include <android/net/BpNetd.h>
#include <android/net/BnNetd.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>
#include <chrono>
#include <functional>

namespace android {

namespace net {

BpNetd::BpNetd(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<INetd>(_aidl_impl){
}

std::function<void(const BpNetd::TransactionLog&)> BpNetd::logFunc;

::android::binder::Status BpNetd::isAlive(bool* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_isAlive, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->isAlive(_aidl_return);
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
  _aidl_ret_status = _aidl_reply.readBool(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "isAlive";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    _transaction_log.result = ::android::internal::ToString(*_aidl_return);
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::firewallReplaceUidChain(const ::std::string& chainName, bool isAllowlist, const ::std::vector<int32_t>& uids, bool* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("chainName", ::android::internal::ToString(chainName));
    _transaction_log.input_args.emplace_back("isAllowlist", ::android::internal::ToString(isAllowlist));
    _transaction_log.input_args.emplace_back("uids", ::android::internal::ToString(uids));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(chainName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(isAllowlist);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32Vector(uids);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_firewallReplaceUidChain, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->firewallReplaceUidChain(chainName, isAllowlist, uids, _aidl_return);
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
  _aidl_ret_status = _aidl_reply.readBool(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "firewallReplaceUidChain";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    _transaction_log.result = ::android::internal::ToString(*_aidl_return);
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::bandwidthEnableDataSaver(bool enable, bool* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("enable", ::android::internal::ToString(enable));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(enable);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_bandwidthEnableDataSaver, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->bandwidthEnableDataSaver(enable, _aidl_return);
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
  _aidl_ret_status = _aidl_reply.readBool(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "bandwidthEnableDataSaver";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    _transaction_log.result = ::android::internal::ToString(*_aidl_return);
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkCreatePhysical(int32_t netId, int32_t permission) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("netId", ::android::internal::ToString(netId));
    _transaction_log.input_args.emplace_back("permission", ::android::internal::ToString(permission));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(permission);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_networkCreatePhysical, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkCreatePhysical(netId, permission);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "networkCreatePhysical";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkCreateVpn(int32_t netId, bool secure) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("netId", ::android::internal::ToString(netId));
    _transaction_log.input_args.emplace_back("secure", ::android::internal::ToString(secure));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(secure);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_networkCreateVpn, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkCreateVpn(netId, secure);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "networkCreateVpn";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkDestroy(int32_t netId) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("netId", ::android::internal::ToString(netId));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_networkDestroy, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkDestroy(netId);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "networkDestroy";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkAddInterface(int32_t netId, const ::std::string& iface) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("netId", ::android::internal::ToString(netId));
    _transaction_log.input_args.emplace_back("iface", ::android::internal::ToString(iface));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(iface);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_networkAddInterface, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkAddInterface(netId, iface);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "networkAddInterface";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkRemoveInterface(int32_t netId, const ::std::string& iface) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("netId", ::android::internal::ToString(netId));
    _transaction_log.input_args.emplace_back("iface", ::android::internal::ToString(iface));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(iface);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_networkRemoveInterface, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkRemoveInterface(netId, iface);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "networkRemoveInterface";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkAddUidRanges(int32_t netId, const ::std::vector<::android::net::UidRangeParcel>& uidRanges) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("netId", ::android::internal::ToString(netId));
    _transaction_log.input_args.emplace_back("uidRanges", ::android::internal::ToString(uidRanges));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelableVector(uidRanges);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_networkAddUidRanges, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkAddUidRanges(netId, uidRanges);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "networkAddUidRanges";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkRemoveUidRanges(int32_t netId, const ::std::vector<::android::net::UidRangeParcel>& uidRanges) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("netId", ::android::internal::ToString(netId));
    _transaction_log.input_args.emplace_back("uidRanges", ::android::internal::ToString(uidRanges));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelableVector(uidRanges);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_networkRemoveUidRanges, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkRemoveUidRanges(netId, uidRanges);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "networkRemoveUidRanges";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkRejectNonSecureVpn(bool add, const ::std::vector<::android::net::UidRangeParcel>& uidRanges) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("add", ::android::internal::ToString(add));
    _transaction_log.input_args.emplace_back("uidRanges", ::android::internal::ToString(uidRanges));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(add);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelableVector(uidRanges);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_networkRejectNonSecureVpn, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkRejectNonSecureVpn(add, uidRanges);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "networkRejectNonSecureVpn";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::socketDestroy(const ::std::vector<::android::net::UidRangeParcel>& uidRanges, const ::std::vector<int32_t>& exemptUids) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("uidRanges", ::android::internal::ToString(uidRanges));
    _transaction_log.input_args.emplace_back("exemptUids", ::android::internal::ToString(exemptUids));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelableVector(uidRanges);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32Vector(exemptUids);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_socketDestroy, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->socketDestroy(uidRanges, exemptUids);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "socketDestroy";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherApplyDnsInterfaces(bool* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_tetherApplyDnsInterfaces, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherApplyDnsInterfaces(_aidl_return);
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
  _aidl_ret_status = _aidl_reply.readBool(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "tetherApplyDnsInterfaces";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    _transaction_log.result = ::android::internal::ToString(*_aidl_return);
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherGetStats(::std::vector<::android::net::TetherStatsParcel>* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_tetherGetStats, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherGetStats(_aidl_return);
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
  _aidl_ret_status = _aidl_reply.readParcelableVector(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "tetherGetStats";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    _transaction_log.result = ::android::internal::ToString(*_aidl_return);
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::interfaceAddAddress(const ::std::string& ifName, const ::std::string& addrString, int32_t prefixLength) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("ifName", ::android::internal::ToString(ifName));
    _transaction_log.input_args.emplace_back("addrString", ::android::internal::ToString(addrString));
    _transaction_log.input_args.emplace_back("prefixLength", ::android::internal::ToString(prefixLength));
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
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(addrString);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(prefixLength);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_interfaceAddAddress, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->interfaceAddAddress(ifName, addrString, prefixLength);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "interfaceAddAddress";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::interfaceDelAddress(const ::std::string& ifName, const ::std::string& addrString, int32_t prefixLength) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("ifName", ::android::internal::ToString(ifName));
    _transaction_log.input_args.emplace_back("addrString", ::android::internal::ToString(addrString));
    _transaction_log.input_args.emplace_back("prefixLength", ::android::internal::ToString(prefixLength));
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
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(addrString);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(prefixLength);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_interfaceDelAddress, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->interfaceDelAddress(ifName, addrString, prefixLength);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "interfaceDelAddress";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::getProcSysNet(int32_t ipversion, int32_t which, const ::std::string& ifname, const ::std::string& parameter, ::std::string* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("ipversion", ::android::internal::ToString(ipversion));
    _transaction_log.input_args.emplace_back("which", ::android::internal::ToString(which));
    _transaction_log.input_args.emplace_back("ifname", ::android::internal::ToString(ifname));
    _transaction_log.input_args.emplace_back("parameter", ::android::internal::ToString(parameter));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(ipversion);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(which);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifname);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(parameter);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_getProcSysNet, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->getProcSysNet(ipversion, which, ifname, parameter, _aidl_return);
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
  _aidl_ret_status = _aidl_reply.readUtf8FromUtf16(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "getProcSysNet";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    _transaction_log.result = ::android::internal::ToString(*_aidl_return);
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::setProcSysNet(int32_t ipversion, int32_t which, const ::std::string& ifname, const ::std::string& parameter, const ::std::string& value) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("ipversion", ::android::internal::ToString(ipversion));
    _transaction_log.input_args.emplace_back("which", ::android::internal::ToString(which));
    _transaction_log.input_args.emplace_back("ifname", ::android::internal::ToString(ifname));
    _transaction_log.input_args.emplace_back("parameter", ::android::internal::ToString(parameter));
    _transaction_log.input_args.emplace_back("value", ::android::internal::ToString(value));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(ipversion);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(which);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifname);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(parameter);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(value);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_setProcSysNet, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->setProcSysNet(ipversion, which, ifname, parameter, value);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "setProcSysNet";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipSecSetEncapSocketOwner(const ::android::os::ParcelFileDescriptor& socket, int32_t newUid) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("socket", ::android::internal::ToString(socket));
    _transaction_log.input_args.emplace_back("newUid", ::android::internal::ToString(newUid));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(socket);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(newUid);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_ipSecSetEncapSocketOwner, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipSecSetEncapSocketOwner(socket, newUid);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "ipSecSetEncapSocketOwner";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipSecAllocateSpi(int32_t transformId, const ::std::string& sourceAddress, const ::std::string& destinationAddress, int32_t spi, int32_t* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("transformId", ::android::internal::ToString(transformId));
    _transaction_log.input_args.emplace_back("sourceAddress", ::android::internal::ToString(sourceAddress));
    _transaction_log.input_args.emplace_back("destinationAddress", ::android::internal::ToString(destinationAddress));
    _transaction_log.input_args.emplace_back("spi", ::android::internal::ToString(spi));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(transformId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(sourceAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(destinationAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(spi);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_ipSecAllocateSpi, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipSecAllocateSpi(transformId, sourceAddress, destinationAddress, spi, _aidl_return);
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
  _aidl_ret_status = _aidl_reply.readInt32(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "ipSecAllocateSpi";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    _transaction_log.result = ::android::internal::ToString(*_aidl_return);
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipSecAddSecurityAssociation(int32_t transformId, int32_t mode, const ::std::string& sourceAddress, const ::std::string& destinationAddress, int32_t underlyingNetId, int32_t spi, int32_t markValue, int32_t markMask, const ::std::string& authAlgo, const ::std::vector<uint8_t>& authKey, int32_t authTruncBits, const ::std::string& cryptAlgo, const ::std::vector<uint8_t>& cryptKey, int32_t cryptTruncBits, const ::std::string& aeadAlgo, const ::std::vector<uint8_t>& aeadKey, int32_t aeadIcvBits, int32_t encapType, int32_t encapLocalPort, int32_t encapRemotePort, int32_t interfaceId) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("transformId", ::android::internal::ToString(transformId));
    _transaction_log.input_args.emplace_back("mode", ::android::internal::ToString(mode));
    _transaction_log.input_args.emplace_back("sourceAddress", ::android::internal::ToString(sourceAddress));
    _transaction_log.input_args.emplace_back("destinationAddress", ::android::internal::ToString(destinationAddress));
    _transaction_log.input_args.emplace_back("underlyingNetId", ::android::internal::ToString(underlyingNetId));
    _transaction_log.input_args.emplace_back("spi", ::android::internal::ToString(spi));
    _transaction_log.input_args.emplace_back("markValue", ::android::internal::ToString(markValue));
    _transaction_log.input_args.emplace_back("markMask", ::android::internal::ToString(markMask));
    _transaction_log.input_args.emplace_back("authAlgo", ::android::internal::ToString(authAlgo));
    _transaction_log.input_args.emplace_back("authKey", ::android::internal::ToString(authKey));
    _transaction_log.input_args.emplace_back("authTruncBits", ::android::internal::ToString(authTruncBits));
    _transaction_log.input_args.emplace_back("cryptAlgo", ::android::internal::ToString(cryptAlgo));
    _transaction_log.input_args.emplace_back("cryptKey", ::android::internal::ToString(cryptKey));
    _transaction_log.input_args.emplace_back("cryptTruncBits", ::android::internal::ToString(cryptTruncBits));
    _transaction_log.input_args.emplace_back("aeadAlgo", ::android::internal::ToString(aeadAlgo));
    _transaction_log.input_args.emplace_back("aeadKey", ::android::internal::ToString(aeadKey));
    _transaction_log.input_args.emplace_back("aeadIcvBits", ::android::internal::ToString(aeadIcvBits));
    _transaction_log.input_args.emplace_back("encapType", ::android::internal::ToString(encapType));
    _transaction_log.input_args.emplace_back("encapLocalPort", ::android::internal::ToString(encapLocalPort));
    _transaction_log.input_args.emplace_back("encapRemotePort", ::android::internal::ToString(encapRemotePort));
    _transaction_log.input_args.emplace_back("interfaceId", ::android::internal::ToString(interfaceId));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(transformId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(mode);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(sourceAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(destinationAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(underlyingNetId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(spi);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(markValue);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(markMask);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(authAlgo);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(authKey);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(authTruncBits);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(cryptAlgo);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(cryptKey);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(cryptTruncBits);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(aeadAlgo);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(aeadKey);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(aeadIcvBits);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(encapType);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(encapLocalPort);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(encapRemotePort);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(interfaceId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_ipSecAddSecurityAssociation, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipSecAddSecurityAssociation(transformId, mode, sourceAddress, destinationAddress, underlyingNetId, spi, markValue, markMask, authAlgo, authKey, authTruncBits, cryptAlgo, cryptKey, cryptTruncBits, aeadAlgo, aeadKey, aeadIcvBits, encapType, encapLocalPort, encapRemotePort, interfaceId);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "ipSecAddSecurityAssociation";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipSecDeleteSecurityAssociation(int32_t transformId, const ::std::string& sourceAddress, const ::std::string& destinationAddress, int32_t spi, int32_t markValue, int32_t markMask, int32_t interfaceId) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("transformId", ::android::internal::ToString(transformId));
    _transaction_log.input_args.emplace_back("sourceAddress", ::android::internal::ToString(sourceAddress));
    _transaction_log.input_args.emplace_back("destinationAddress", ::android::internal::ToString(destinationAddress));
    _transaction_log.input_args.emplace_back("spi", ::android::internal::ToString(spi));
    _transaction_log.input_args.emplace_back("markValue", ::android::internal::ToString(markValue));
    _transaction_log.input_args.emplace_back("markMask", ::android::internal::ToString(markMask));
    _transaction_log.input_args.emplace_back("interfaceId", ::android::internal::ToString(interfaceId));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(transformId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(sourceAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(destinationAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(spi);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(markValue);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(markMask);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(interfaceId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_ipSecDeleteSecurityAssociation, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipSecDeleteSecurityAssociation(transformId, sourceAddress, destinationAddress, spi, markValue, markMask, interfaceId);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "ipSecDeleteSecurityAssociation";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipSecApplyTransportModeTransform(const ::android::os::ParcelFileDescriptor& socket, int32_t transformId, int32_t direction, const ::std::string& sourceAddress, const ::std::string& destinationAddress, int32_t spi) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("socket", ::android::internal::ToString(socket));
    _transaction_log.input_args.emplace_back("transformId", ::android::internal::ToString(transformId));
    _transaction_log.input_args.emplace_back("direction", ::android::internal::ToString(direction));
    _transaction_log.input_args.emplace_back("sourceAddress", ::android::internal::ToString(sourceAddress));
    _transaction_log.input_args.emplace_back("destinationAddress", ::android::internal::ToString(destinationAddress));
    _transaction_log.input_args.emplace_back("spi", ::android::internal::ToString(spi));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(socket);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(transformId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(direction);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(sourceAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(destinationAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(spi);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_ipSecApplyTransportModeTransform, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipSecApplyTransportModeTransform(socket, transformId, direction, sourceAddress, destinationAddress, spi);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "ipSecApplyTransportModeTransform";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipSecRemoveTransportModeTransform(const ::android::os::ParcelFileDescriptor& socket) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("socket", ::android::internal::ToString(socket));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(socket);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_ipSecRemoveTransportModeTransform, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipSecRemoveTransportModeTransform(socket);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "ipSecRemoveTransportModeTransform";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipSecAddSecurityPolicy(int32_t transformId, int32_t selAddrFamily, int32_t direction, const ::std::string& tmplSrcAddress, const ::std::string& tmplDstAddress, int32_t spi, int32_t markValue, int32_t markMask, int32_t interfaceId) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("transformId", ::android::internal::ToString(transformId));
    _transaction_log.input_args.emplace_back("selAddrFamily", ::android::internal::ToString(selAddrFamily));
    _transaction_log.input_args.emplace_back("direction", ::android::internal::ToString(direction));
    _transaction_log.input_args.emplace_back("tmplSrcAddress", ::android::internal::ToString(tmplSrcAddress));
    _transaction_log.input_args.emplace_back("tmplDstAddress", ::android::internal::ToString(tmplDstAddress));
    _transaction_log.input_args.emplace_back("spi", ::android::internal::ToString(spi));
    _transaction_log.input_args.emplace_back("markValue", ::android::internal::ToString(markValue));
    _transaction_log.input_args.emplace_back("markMask", ::android::internal::ToString(markMask));
    _transaction_log.input_args.emplace_back("interfaceId", ::android::internal::ToString(interfaceId));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(transformId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(selAddrFamily);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(direction);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(tmplSrcAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(tmplDstAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(spi);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(markValue);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(markMask);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(interfaceId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_ipSecAddSecurityPolicy, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipSecAddSecurityPolicy(transformId, selAddrFamily, direction, tmplSrcAddress, tmplDstAddress, spi, markValue, markMask, interfaceId);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "ipSecAddSecurityPolicy";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipSecUpdateSecurityPolicy(int32_t transformId, int32_t selAddrFamily, int32_t direction, const ::std::string& tmplSrcAddress, const ::std::string& tmplDstAddress, int32_t spi, int32_t markValue, int32_t markMask, int32_t interfaceId) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("transformId", ::android::internal::ToString(transformId));
    _transaction_log.input_args.emplace_back("selAddrFamily", ::android::internal::ToString(selAddrFamily));
    _transaction_log.input_args.emplace_back("direction", ::android::internal::ToString(direction));
    _transaction_log.input_args.emplace_back("tmplSrcAddress", ::android::internal::ToString(tmplSrcAddress));
    _transaction_log.input_args.emplace_back("tmplDstAddress", ::android::internal::ToString(tmplDstAddress));
    _transaction_log.input_args.emplace_back("spi", ::android::internal::ToString(spi));
    _transaction_log.input_args.emplace_back("markValue", ::android::internal::ToString(markValue));
    _transaction_log.input_args.emplace_back("markMask", ::android::internal::ToString(markMask));
    _transaction_log.input_args.emplace_back("interfaceId", ::android::internal::ToString(interfaceId));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(transformId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(selAddrFamily);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(direction);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(tmplSrcAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(tmplDstAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(spi);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(markValue);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(markMask);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(interfaceId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_ipSecUpdateSecurityPolicy, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipSecUpdateSecurityPolicy(transformId, selAddrFamily, direction, tmplSrcAddress, tmplDstAddress, spi, markValue, markMask, interfaceId);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "ipSecUpdateSecurityPolicy";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipSecDeleteSecurityPolicy(int32_t transformId, int32_t selAddrFamily, int32_t direction, int32_t markValue, int32_t markMask, int32_t interfaceId) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("transformId", ::android::internal::ToString(transformId));
    _transaction_log.input_args.emplace_back("selAddrFamily", ::android::internal::ToString(selAddrFamily));
    _transaction_log.input_args.emplace_back("direction", ::android::internal::ToString(direction));
    _transaction_log.input_args.emplace_back("markValue", ::android::internal::ToString(markValue));
    _transaction_log.input_args.emplace_back("markMask", ::android::internal::ToString(markMask));
    _transaction_log.input_args.emplace_back("interfaceId", ::android::internal::ToString(interfaceId));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(transformId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(selAddrFamily);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(direction);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(markValue);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(markMask);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(interfaceId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_ipSecDeleteSecurityPolicy, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipSecDeleteSecurityPolicy(transformId, selAddrFamily, direction, markValue, markMask, interfaceId);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "ipSecDeleteSecurityPolicy";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipSecAddTunnelInterface(const ::std::string& deviceName, const ::std::string& localAddress, const ::std::string& remoteAddress, int32_t iKey, int32_t oKey, int32_t interfaceId) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("deviceName", ::android::internal::ToString(deviceName));
    _transaction_log.input_args.emplace_back("localAddress", ::android::internal::ToString(localAddress));
    _transaction_log.input_args.emplace_back("remoteAddress", ::android::internal::ToString(remoteAddress));
    _transaction_log.input_args.emplace_back("iKey", ::android::internal::ToString(iKey));
    _transaction_log.input_args.emplace_back("oKey", ::android::internal::ToString(oKey));
    _transaction_log.input_args.emplace_back("interfaceId", ::android::internal::ToString(interfaceId));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(deviceName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(localAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(remoteAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(iKey);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(oKey);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(interfaceId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_ipSecAddTunnelInterface, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipSecAddTunnelInterface(deviceName, localAddress, remoteAddress, iKey, oKey, interfaceId);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "ipSecAddTunnelInterface";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipSecUpdateTunnelInterface(const ::std::string& deviceName, const ::std::string& localAddress, const ::std::string& remoteAddress, int32_t iKey, int32_t oKey, int32_t interfaceId) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("deviceName", ::android::internal::ToString(deviceName));
    _transaction_log.input_args.emplace_back("localAddress", ::android::internal::ToString(localAddress));
    _transaction_log.input_args.emplace_back("remoteAddress", ::android::internal::ToString(remoteAddress));
    _transaction_log.input_args.emplace_back("iKey", ::android::internal::ToString(iKey));
    _transaction_log.input_args.emplace_back("oKey", ::android::internal::ToString(oKey));
    _transaction_log.input_args.emplace_back("interfaceId", ::android::internal::ToString(interfaceId));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(deviceName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(localAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(remoteAddress);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(iKey);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(oKey);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(interfaceId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_ipSecUpdateTunnelInterface, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipSecUpdateTunnelInterface(deviceName, localAddress, remoteAddress, iKey, oKey, interfaceId);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "ipSecUpdateTunnelInterface";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipSecRemoveTunnelInterface(const ::std::string& deviceName) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("deviceName", ::android::internal::ToString(deviceName));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(deviceName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_ipSecRemoveTunnelInterface, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipSecRemoveTunnelInterface(deviceName);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "ipSecRemoveTunnelInterface";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::wakeupAddInterface(const ::std::string& ifName, const ::std::string& prefix, int32_t mark, int32_t mask) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("ifName", ::android::internal::ToString(ifName));
    _transaction_log.input_args.emplace_back("prefix", ::android::internal::ToString(prefix));
    _transaction_log.input_args.emplace_back("mark", ::android::internal::ToString(mark));
    _transaction_log.input_args.emplace_back("mask", ::android::internal::ToString(mask));
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
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(prefix);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(mark);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(mask);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_wakeupAddInterface, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->wakeupAddInterface(ifName, prefix, mark, mask);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "wakeupAddInterface";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::wakeupDelInterface(const ::std::string& ifName, const ::std::string& prefix, int32_t mark, int32_t mask) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("ifName", ::android::internal::ToString(ifName));
    _transaction_log.input_args.emplace_back("prefix", ::android::internal::ToString(prefix));
    _transaction_log.input_args.emplace_back("mark", ::android::internal::ToString(mark));
    _transaction_log.input_args.emplace_back("mask", ::android::internal::ToString(mask));
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
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(prefix);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(mark);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(mask);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_wakeupDelInterface, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->wakeupDelInterface(ifName, prefix, mark, mask);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "wakeupDelInterface";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::setIPv6AddrGenMode(const ::std::string& ifName, int32_t mode) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("ifName", ::android::internal::ToString(ifName));
    _transaction_log.input_args.emplace_back("mode", ::android::internal::ToString(mode));
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
  _aidl_ret_status = _aidl_data.writeInt32(mode);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_setIPv6AddrGenMode, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->setIPv6AddrGenMode(ifName, mode);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "setIPv6AddrGenMode";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::idletimerAddInterface(const ::std::string& ifName, int32_t timeout, const ::std::string& classLabel) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("ifName", ::android::internal::ToString(ifName));
    _transaction_log.input_args.emplace_back("timeout", ::android::internal::ToString(timeout));
    _transaction_log.input_args.emplace_back("classLabel", ::android::internal::ToString(classLabel));
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
  _aidl_ret_status = _aidl_data.writeInt32(timeout);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(classLabel);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_idletimerAddInterface, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->idletimerAddInterface(ifName, timeout, classLabel);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "idletimerAddInterface";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::idletimerRemoveInterface(const ::std::string& ifName, int32_t timeout, const ::std::string& classLabel) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("ifName", ::android::internal::ToString(ifName));
    _transaction_log.input_args.emplace_back("timeout", ::android::internal::ToString(timeout));
    _transaction_log.input_args.emplace_back("classLabel", ::android::internal::ToString(classLabel));
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
  _aidl_ret_status = _aidl_data.writeInt32(timeout);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(classLabel);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_idletimerRemoveInterface, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->idletimerRemoveInterface(ifName, timeout, classLabel);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "idletimerRemoveInterface";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::strictUidCleartextPenalty(int32_t uid, int32_t policyPenalty) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("uid", ::android::internal::ToString(uid));
    _transaction_log.input_args.emplace_back("policyPenalty", ::android::internal::ToString(policyPenalty));
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
  _aidl_ret_status = _aidl_data.writeInt32(policyPenalty);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_strictUidCleartextPenalty, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->strictUidCleartextPenalty(uid, policyPenalty);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "strictUidCleartextPenalty";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::clatdStart(const ::std::string& ifName, const ::std::string& nat64Prefix, ::std::string* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("ifName", ::android::internal::ToString(ifName));
    _transaction_log.input_args.emplace_back("nat64Prefix", ::android::internal::ToString(nat64Prefix));
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
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(nat64Prefix);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_clatdStart, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->clatdStart(ifName, nat64Prefix, _aidl_return);
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
  _aidl_ret_status = _aidl_reply.readUtf8FromUtf16(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "clatdStart";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    _transaction_log.result = ::android::internal::ToString(*_aidl_return);
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::clatdStop(const ::std::string& ifName) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
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
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_clatdStop, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->clatdStop(ifName);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "clatdStop";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipfwdEnabled(bool* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_ipfwdEnabled, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipfwdEnabled(_aidl_return);
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
  _aidl_ret_status = _aidl_reply.readBool(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "ipfwdEnabled";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    _transaction_log.result = ::android::internal::ToString(*_aidl_return);
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipfwdGetRequesterList(::std::vector<::std::string>* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_ipfwdGetRequesterList, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipfwdGetRequesterList(_aidl_return);
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
  _aidl_ret_status = _aidl_reply.readUtf8VectorFromUtf16Vector(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "ipfwdGetRequesterList";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    _transaction_log.result = ::android::internal::ToString(*_aidl_return);
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipfwdEnableForwarding(const ::std::string& requester) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("requester", ::android::internal::ToString(requester));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(requester);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_ipfwdEnableForwarding, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipfwdEnableForwarding(requester);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "ipfwdEnableForwarding";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipfwdDisableForwarding(const ::std::string& requester) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("requester", ::android::internal::ToString(requester));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(requester);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_ipfwdDisableForwarding, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipfwdDisableForwarding(requester);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "ipfwdDisableForwarding";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipfwdAddInterfaceForward(const ::std::string& fromIface, const ::std::string& toIface) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("fromIface", ::android::internal::ToString(fromIface));
    _transaction_log.input_args.emplace_back("toIface", ::android::internal::ToString(toIface));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(fromIface);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(toIface);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_ipfwdAddInterfaceForward, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipfwdAddInterfaceForward(fromIface, toIface);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "ipfwdAddInterfaceForward";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::ipfwdRemoveInterfaceForward(const ::std::string& fromIface, const ::std::string& toIface) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("fromIface", ::android::internal::ToString(fromIface));
    _transaction_log.input_args.emplace_back("toIface", ::android::internal::ToString(toIface));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(fromIface);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(toIface);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_ipfwdRemoveInterfaceForward, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->ipfwdRemoveInterfaceForward(fromIface, toIface);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "ipfwdRemoveInterfaceForward";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::bandwidthSetInterfaceQuota(const ::std::string& ifName, int64_t bytes) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("ifName", ::android::internal::ToString(ifName));
    _transaction_log.input_args.emplace_back("bytes", ::android::internal::ToString(bytes));
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
  _aidl_ret_status = _aidl_data.writeInt64(bytes);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_bandwidthSetInterfaceQuota, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->bandwidthSetInterfaceQuota(ifName, bytes);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "bandwidthSetInterfaceQuota";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::bandwidthRemoveInterfaceQuota(const ::std::string& ifName) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
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
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_bandwidthRemoveInterfaceQuota, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->bandwidthRemoveInterfaceQuota(ifName);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "bandwidthRemoveInterfaceQuota";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::bandwidthSetInterfaceAlert(const ::std::string& ifName, int64_t bytes) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("ifName", ::android::internal::ToString(ifName));
    _transaction_log.input_args.emplace_back("bytes", ::android::internal::ToString(bytes));
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
  _aidl_ret_status = _aidl_data.writeInt64(bytes);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_bandwidthSetInterfaceAlert, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->bandwidthSetInterfaceAlert(ifName, bytes);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "bandwidthSetInterfaceAlert";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::bandwidthRemoveInterfaceAlert(const ::std::string& ifName) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
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
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_bandwidthRemoveInterfaceAlert, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->bandwidthRemoveInterfaceAlert(ifName);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "bandwidthRemoveInterfaceAlert";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::bandwidthSetGlobalAlert(int64_t bytes) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("bytes", ::android::internal::ToString(bytes));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt64(bytes);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_bandwidthSetGlobalAlert, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->bandwidthSetGlobalAlert(bytes);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "bandwidthSetGlobalAlert";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::bandwidthAddNaughtyApp(int32_t uid) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("uid", ::android::internal::ToString(uid));
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
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_bandwidthAddNaughtyApp, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->bandwidthAddNaughtyApp(uid);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "bandwidthAddNaughtyApp";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::bandwidthRemoveNaughtyApp(int32_t uid) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("uid", ::android::internal::ToString(uid));
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
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_bandwidthRemoveNaughtyApp, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->bandwidthRemoveNaughtyApp(uid);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "bandwidthRemoveNaughtyApp";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::bandwidthAddNiceApp(int32_t uid) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("uid", ::android::internal::ToString(uid));
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
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_bandwidthAddNiceApp, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->bandwidthAddNiceApp(uid);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "bandwidthAddNiceApp";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::bandwidthRemoveNiceApp(int32_t uid) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("uid", ::android::internal::ToString(uid));
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
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_bandwidthRemoveNiceApp, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->bandwidthRemoveNiceApp(uid);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "bandwidthRemoveNiceApp";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherStart(const ::std::vector<::std::string>& dhcpRanges) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("dhcpRanges", ::android::internal::ToString(dhcpRanges));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8VectorAsUtf16Vector(dhcpRanges);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_tetherStart, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherStart(dhcpRanges);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "tetherStart";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherStop() {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_tetherStop, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherStop();
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "tetherStop";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherIsEnabled(bool* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_tetherIsEnabled, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherIsEnabled(_aidl_return);
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
  _aidl_ret_status = _aidl_reply.readBool(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "tetherIsEnabled";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    _transaction_log.result = ::android::internal::ToString(*_aidl_return);
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherInterfaceAdd(const ::std::string& ifName) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
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
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_tetherInterfaceAdd, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherInterfaceAdd(ifName);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "tetherInterfaceAdd";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherInterfaceRemove(const ::std::string& ifName) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
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
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_tetherInterfaceRemove, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherInterfaceRemove(ifName);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "tetherInterfaceRemove";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherInterfaceList(::std::vector<::std::string>* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_tetherInterfaceList, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherInterfaceList(_aidl_return);
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
  _aidl_ret_status = _aidl_reply.readUtf8VectorFromUtf16Vector(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "tetherInterfaceList";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    _transaction_log.result = ::android::internal::ToString(*_aidl_return);
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherDnsSet(int32_t netId, const ::std::vector<::std::string>& dnsAddrs) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("netId", ::android::internal::ToString(netId));
    _transaction_log.input_args.emplace_back("dnsAddrs", ::android::internal::ToString(dnsAddrs));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8VectorAsUtf16Vector(dnsAddrs);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_tetherDnsSet, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherDnsSet(netId, dnsAddrs);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "tetherDnsSet";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherDnsList(::std::vector<::std::string>* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_tetherDnsList, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherDnsList(_aidl_return);
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
  _aidl_ret_status = _aidl_reply.readUtf8VectorFromUtf16Vector(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "tetherDnsList";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    _transaction_log.result = ::android::internal::ToString(*_aidl_return);
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkAddRoute(int32_t netId, const ::std::string& ifName, const ::std::string& destination, const ::std::string& nextHop) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("netId", ::android::internal::ToString(netId));
    _transaction_log.input_args.emplace_back("ifName", ::android::internal::ToString(ifName));
    _transaction_log.input_args.emplace_back("destination", ::android::internal::ToString(destination));
    _transaction_log.input_args.emplace_back("nextHop", ::android::internal::ToString(nextHop));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(destination);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(nextHop);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_networkAddRoute, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkAddRoute(netId, ifName, destination, nextHop);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "networkAddRoute";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkRemoveRoute(int32_t netId, const ::std::string& ifName, const ::std::string& destination, const ::std::string& nextHop) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("netId", ::android::internal::ToString(netId));
    _transaction_log.input_args.emplace_back("ifName", ::android::internal::ToString(ifName));
    _transaction_log.input_args.emplace_back("destination", ::android::internal::ToString(destination));
    _transaction_log.input_args.emplace_back("nextHop", ::android::internal::ToString(nextHop));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(destination);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(nextHop);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_networkRemoveRoute, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkRemoveRoute(netId, ifName, destination, nextHop);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "networkRemoveRoute";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkAddLegacyRoute(int32_t netId, const ::std::string& ifName, const ::std::string& destination, const ::std::string& nextHop, int32_t uid) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("netId", ::android::internal::ToString(netId));
    _transaction_log.input_args.emplace_back("ifName", ::android::internal::ToString(ifName));
    _transaction_log.input_args.emplace_back("destination", ::android::internal::ToString(destination));
    _transaction_log.input_args.emplace_back("nextHop", ::android::internal::ToString(nextHop));
    _transaction_log.input_args.emplace_back("uid", ::android::internal::ToString(uid));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(destination);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(nextHop);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(uid);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_networkAddLegacyRoute, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkAddLegacyRoute(netId, ifName, destination, nextHop, uid);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "networkAddLegacyRoute";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkRemoveLegacyRoute(int32_t netId, const ::std::string& ifName, const ::std::string& destination, const ::std::string& nextHop, int32_t uid) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("netId", ::android::internal::ToString(netId));
    _transaction_log.input_args.emplace_back("ifName", ::android::internal::ToString(ifName));
    _transaction_log.input_args.emplace_back("destination", ::android::internal::ToString(destination));
    _transaction_log.input_args.emplace_back("nextHop", ::android::internal::ToString(nextHop));
    _transaction_log.input_args.emplace_back("uid", ::android::internal::ToString(uid));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(ifName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(destination);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(nextHop);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(uid);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_networkRemoveLegacyRoute, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkRemoveLegacyRoute(netId, ifName, destination, nextHop, uid);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "networkRemoveLegacyRoute";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkGetDefault(int32_t* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_networkGetDefault, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkGetDefault(_aidl_return);
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
  _aidl_ret_status = _aidl_reply.readInt32(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "networkGetDefault";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    _transaction_log.result = ::android::internal::ToString(*_aidl_return);
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkSetDefault(int32_t netId) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("netId", ::android::internal::ToString(netId));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_networkSetDefault, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkSetDefault(netId);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "networkSetDefault";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkClearDefault() {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_networkClearDefault, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkClearDefault();
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "networkClearDefault";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkSetPermissionForNetwork(int32_t netId, int32_t permission) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("netId", ::android::internal::ToString(netId));
    _transaction_log.input_args.emplace_back("permission", ::android::internal::ToString(permission));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(permission);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_networkSetPermissionForNetwork, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkSetPermissionForNetwork(netId, permission);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "networkSetPermissionForNetwork";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkSetPermissionForUser(int32_t permission, const ::std::vector<int32_t>& uids) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("permission", ::android::internal::ToString(permission));
    _transaction_log.input_args.emplace_back("uids", ::android::internal::ToString(uids));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(permission);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32Vector(uids);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_networkSetPermissionForUser, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkSetPermissionForUser(permission, uids);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "networkSetPermissionForUser";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkClearPermissionForUser(const ::std::vector<int32_t>& uids) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("uids", ::android::internal::ToString(uids));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32Vector(uids);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_networkClearPermissionForUser, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkClearPermissionForUser(uids);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "networkClearPermissionForUser";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::trafficSetNetPermForUids(int32_t permission, const ::std::vector<int32_t>& uids) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("permission", ::android::internal::ToString(permission));
    _transaction_log.input_args.emplace_back("uids", ::android::internal::ToString(uids));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(permission);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32Vector(uids);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_trafficSetNetPermForUids, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->trafficSetNetPermForUids(permission, uids);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "trafficSetNetPermForUids";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkSetProtectAllow(int32_t uid) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("uid", ::android::internal::ToString(uid));
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
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_networkSetProtectAllow, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkSetProtectAllow(uid);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "networkSetProtectAllow";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkSetProtectDeny(int32_t uid) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("uid", ::android::internal::ToString(uid));
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
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_networkSetProtectDeny, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkSetProtectDeny(uid);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "networkSetProtectDeny";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkCanProtect(int32_t uid, bool* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("uid", ::android::internal::ToString(uid));
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
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_networkCanProtect, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkCanProtect(uid, _aidl_return);
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
  _aidl_ret_status = _aidl_reply.readBool(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "networkCanProtect";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    _transaction_log.result = ::android::internal::ToString(*_aidl_return);
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::firewallSetFirewallType(int32_t firewalltype) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("firewalltype", ::android::internal::ToString(firewalltype));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(firewalltype);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_firewallSetFirewallType, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->firewallSetFirewallType(firewalltype);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "firewallSetFirewallType";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::firewallSetInterfaceRule(const ::std::string& ifName, int32_t firewallRule) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("ifName", ::android::internal::ToString(ifName));
    _transaction_log.input_args.emplace_back("firewallRule", ::android::internal::ToString(firewallRule));
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
  _aidl_ret_status = _aidl_data.writeInt32(firewallRule);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_firewallSetInterfaceRule, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->firewallSetInterfaceRule(ifName, firewallRule);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "firewallSetInterfaceRule";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::firewallSetUidRule(int32_t childChain, int32_t uid, int32_t firewallRule) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("childChain", ::android::internal::ToString(childChain));
    _transaction_log.input_args.emplace_back("uid", ::android::internal::ToString(uid));
    _transaction_log.input_args.emplace_back("firewallRule", ::android::internal::ToString(firewallRule));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(childChain);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(uid);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(firewallRule);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_firewallSetUidRule, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->firewallSetUidRule(childChain, uid, firewallRule);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "firewallSetUidRule";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::firewallEnableChildChain(int32_t childChain, bool enable) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("childChain", ::android::internal::ToString(childChain));
    _transaction_log.input_args.emplace_back("enable", ::android::internal::ToString(enable));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(childChain);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(enable);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_firewallEnableChildChain, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->firewallEnableChildChain(childChain, enable);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "firewallEnableChildChain";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::interfaceGetList(::std::vector<::std::string>* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_interfaceGetList, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->interfaceGetList(_aidl_return);
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
  _aidl_ret_status = _aidl_reply.readUtf8VectorFromUtf16Vector(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "interfaceGetList";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    _transaction_log.result = ::android::internal::ToString(*_aidl_return);
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::interfaceGetCfg(const ::std::string& ifName, ::android::net::InterfaceConfigurationParcel* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
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
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_interfaceGetCfg, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->interfaceGetCfg(ifName, _aidl_return);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "interfaceGetCfg";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    _transaction_log.result = ::android::internal::ToString(*_aidl_return);
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::interfaceSetCfg(const ::android::net::InterfaceConfigurationParcel& cfg) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("cfg", ::android::internal::ToString(cfg));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(cfg);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_interfaceSetCfg, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->interfaceSetCfg(cfg);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "interfaceSetCfg";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::interfaceSetIPv6PrivacyExtensions(const ::std::string& ifName, bool enable) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("ifName", ::android::internal::ToString(ifName));
    _transaction_log.input_args.emplace_back("enable", ::android::internal::ToString(enable));
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
  _aidl_ret_status = _aidl_data.writeBool(enable);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_interfaceSetIPv6PrivacyExtensions, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->interfaceSetIPv6PrivacyExtensions(ifName, enable);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "interfaceSetIPv6PrivacyExtensions";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::interfaceClearAddrs(const ::std::string& ifName) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
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
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_interfaceClearAddrs, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->interfaceClearAddrs(ifName);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "interfaceClearAddrs";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::interfaceSetEnableIPv6(const ::std::string& ifName, bool enable) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("ifName", ::android::internal::ToString(ifName));
    _transaction_log.input_args.emplace_back("enable", ::android::internal::ToString(enable));
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
  _aidl_ret_status = _aidl_data.writeBool(enable);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_interfaceSetEnableIPv6, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->interfaceSetEnableIPv6(ifName, enable);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "interfaceSetEnableIPv6";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::interfaceSetMtu(const ::std::string& ifName, int32_t mtu) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("ifName", ::android::internal::ToString(ifName));
    _transaction_log.input_args.emplace_back("mtu", ::android::internal::ToString(mtu));
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
  _aidl_ret_status = _aidl_data.writeInt32(mtu);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_interfaceSetMtu, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->interfaceSetMtu(ifName, mtu);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "interfaceSetMtu";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherAddForward(const ::std::string& intIface, const ::std::string& extIface) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("intIface", ::android::internal::ToString(intIface));
    _transaction_log.input_args.emplace_back("extIface", ::android::internal::ToString(extIface));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(intIface);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(extIface);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_tetherAddForward, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherAddForward(intIface, extIface);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "tetherAddForward";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherRemoveForward(const ::std::string& intIface, const ::std::string& extIface) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("intIface", ::android::internal::ToString(intIface));
    _transaction_log.input_args.emplace_back("extIface", ::android::internal::ToString(extIface));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(intIface);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(extIface);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_tetherRemoveForward, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherRemoveForward(intIface, extIface);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "tetherRemoveForward";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::setTcpRWmemorySize(const ::std::string& rmemValues, const ::std::string& wmemValues) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("rmemValues", ::android::internal::ToString(rmemValues));
    _transaction_log.input_args.emplace_back("wmemValues", ::android::internal::ToString(wmemValues));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(rmemValues);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(wmemValues);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_setTcpRWmemorySize, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->setTcpRWmemorySize(rmemValues, wmemValues);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "setTcpRWmemorySize";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::registerUnsolicitedEventListener(const ::android::sp<::android::net::INetdUnsolicitedEventListener>& listener) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("listener", ::android::internal::ToString(listener));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeStrongBinder(::android::net::INetdUnsolicitedEventListener::asBinder(listener));
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_registerUnsolicitedEventListener, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->registerUnsolicitedEventListener(listener);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "registerUnsolicitedEventListener";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::firewallAddUidInterfaceRules(const ::std::string& ifName, const ::std::vector<int32_t>& uids) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("ifName", ::android::internal::ToString(ifName));
    _transaction_log.input_args.emplace_back("uids", ::android::internal::ToString(uids));
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
  _aidl_ret_status = _aidl_data.writeInt32Vector(uids);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_firewallAddUidInterfaceRules, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->firewallAddUidInterfaceRules(ifName, uids);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "firewallAddUidInterfaceRules";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::firewallRemoveUidInterfaceRules(const ::std::vector<int32_t>& uids) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("uids", ::android::internal::ToString(uids));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32Vector(uids);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_firewallRemoveUidInterfaceRules, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->firewallRemoveUidInterfaceRules(uids);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "firewallRemoveUidInterfaceRules";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::trafficSwapActiveStatsMap() {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_trafficSwapActiveStatsMap, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->trafficSwapActiveStatsMap();
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "trafficSwapActiveStatsMap";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::getOemNetd(::android::sp<::android::IBinder>* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_getOemNetd, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->getOemNetd(_aidl_return);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "getOemNetd";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    _transaction_log.result = ::android::internal::ToString(*_aidl_return);
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherStartWithConfiguration(const ::android::net::TetherConfigParcel& config) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("config", ::android::internal::ToString(config));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(config);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_tetherStartWithConfiguration, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherStartWithConfiguration(config);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "tetherStartWithConfiguration";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::getFwmarkForNetwork(int32_t netId, ::android::net::MarkMaskParcel* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("netId", ::android::internal::ToString(netId));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_getFwmarkForNetwork, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->getFwmarkForNetwork(netId, _aidl_return);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "getFwmarkForNetwork";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    _transaction_log.result = ::android::internal::ToString(*_aidl_return);
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkAddRouteParcel(int32_t netId, const ::android::net::RouteInfoParcel& routeInfo) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("netId", ::android::internal::ToString(netId));
    _transaction_log.input_args.emplace_back("routeInfo", ::android::internal::ToString(routeInfo));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(routeInfo);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_networkAddRouteParcel, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkAddRouteParcel(netId, routeInfo);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "networkAddRouteParcel";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkUpdateRouteParcel(int32_t netId, const ::android::net::RouteInfoParcel& routeInfo) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("netId", ::android::internal::ToString(netId));
    _transaction_log.input_args.emplace_back("routeInfo", ::android::internal::ToString(routeInfo));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(routeInfo);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_networkUpdateRouteParcel, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkUpdateRouteParcel(netId, routeInfo);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "networkUpdateRouteParcel";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkRemoveRouteParcel(int32_t netId, const ::android::net::RouteInfoParcel& routeInfo) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("netId", ::android::internal::ToString(netId));
    _transaction_log.input_args.emplace_back("routeInfo", ::android::internal::ToString(routeInfo));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(netId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(routeInfo);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_networkRemoveRouteParcel, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkRemoveRouteParcel(netId, routeInfo);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "networkRemoveRouteParcel";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherOffloadRuleAdd(const ::android::net::TetherOffloadRuleParcel& rule) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("rule", ::android::internal::ToString(rule));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(rule);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_tetherOffloadRuleAdd, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherOffloadRuleAdd(rule);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "tetherOffloadRuleAdd";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherOffloadRuleRemove(const ::android::net::TetherOffloadRuleParcel& rule) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("rule", ::android::internal::ToString(rule));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(rule);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_tetherOffloadRuleRemove, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherOffloadRuleRemove(rule);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "tetherOffloadRuleRemove";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherOffloadGetStats(::std::vector<::android::net::TetherStatsParcel>* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_tetherOffloadGetStats, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherOffloadGetStats(_aidl_return);
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
  _aidl_ret_status = _aidl_reply.readParcelableVector(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "tetherOffloadGetStats";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    _transaction_log.result = ::android::internal::ToString(*_aidl_return);
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherOffloadSetInterfaceQuota(int32_t ifIndex, int64_t quotaBytes) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("ifIndex", ::android::internal::ToString(ifIndex));
    _transaction_log.input_args.emplace_back("quotaBytes", ::android::internal::ToString(quotaBytes));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(ifIndex);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt64(quotaBytes);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_tetherOffloadSetInterfaceQuota, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherOffloadSetInterfaceQuota(ifIndex, quotaBytes);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "tetherOffloadSetInterfaceQuota";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::tetherOffloadGetAndClearStats(int32_t ifIndex, ::android::net::TetherStatsParcel* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("ifIndex", ::android::internal::ToString(ifIndex));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(ifIndex);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_tetherOffloadGetAndClearStats, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->tetherOffloadGetAndClearStats(ifIndex, _aidl_return);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "tetherOffloadGetAndClearStats";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    _transaction_log.result = ::android::internal::ToString(*_aidl_return);
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

::android::binder::Status BpNetd::networkCreate(const ::android::net::NativeNetworkConfig& config) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpNetd::TransactionLog _transaction_log;
  if (BpNetd::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("config", ::android::internal::ToString(config));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(config);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnNetd::TRANSACTION_networkCreate, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && INetd::getDefaultImpl())) {
     return INetd::getDefaultImpl()->networkCreate(config);
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
  if (BpNetd::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.INetd";
    _transaction_log.method_name = "networkCreate";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    BpNetd::logFunc(_transaction_log);
  }
  return _aidl_status;
}

int32_t BpNetd::getInterfaceVersion() {
  if (cached_version_ == -1) {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(BnNetd::TRANSACTION_getInterfaceVersion, data, &reply);
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

std::string BpNetd::getInterfaceHash() {
  std::lock_guard<std::mutex> lockGuard(cached_hash_mutex_);
  if (cached_hash_ == "-1") {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(BnNetd::TRANSACTION_getInterfaceHash, data, &reply);
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
#include <android/net/BnNetd.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>
#include <chrono>
#include <functional>

namespace android {

namespace net {

BnNetd::BnNetd()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated"

::android::status_t BnNetd::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnNetd::TRANSACTION_isAlive:
  {
    bool _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(isAlive(&_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "isAlive";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      _transaction_log.result = ::android::internal::ToString(_aidl_return);
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeBool(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_firewallReplaceUidChain:
  {
    ::std::string in_chainName;
    bool in_isAllowlist;
    ::std::vector<int32_t> in_uids;
    bool _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_chainName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_isAllowlist);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32Vector(&in_uids);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_chainName", ::android::internal::ToString(in_chainName));
      _transaction_log.input_args.emplace_back("in_isAllowlist", ::android::internal::ToString(in_isAllowlist));
      _transaction_log.input_args.emplace_back("in_uids", ::android::internal::ToString(in_uids));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(firewallReplaceUidChain(in_chainName, in_isAllowlist, in_uids, &_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "firewallReplaceUidChain";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      _transaction_log.result = ::android::internal::ToString(_aidl_return);
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeBool(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_bandwidthEnableDataSaver:
  {
    bool in_enable;
    bool _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_enable);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_enable", ::android::internal::ToString(in_enable));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(bandwidthEnableDataSaver(in_enable, &_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "bandwidthEnableDataSaver";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      _transaction_log.result = ::android::internal::ToString(_aidl_return);
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeBool(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_networkCreatePhysical:
  {
    int32_t in_netId;
    int32_t in_permission;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_permission);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
      _transaction_log.input_args.emplace_back("in_permission", ::android::internal::ToString(in_permission));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkCreatePhysical(in_netId, in_permission));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "networkCreatePhysical";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_networkCreateVpn:
  {
    int32_t in_netId;
    bool in_secure;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_secure);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
      _transaction_log.input_args.emplace_back("in_secure", ::android::internal::ToString(in_secure));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkCreateVpn(in_netId, in_secure));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "networkCreateVpn";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_networkDestroy:
  {
    int32_t in_netId;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkDestroy(in_netId));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "networkDestroy";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_networkAddInterface:
  {
    int32_t in_netId;
    ::std::string in_iface;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_iface);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
      _transaction_log.input_args.emplace_back("in_iface", ::android::internal::ToString(in_iface));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkAddInterface(in_netId, in_iface));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "networkAddInterface";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_networkRemoveInterface:
  {
    int32_t in_netId;
    ::std::string in_iface;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_iface);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
      _transaction_log.input_args.emplace_back("in_iface", ::android::internal::ToString(in_iface));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkRemoveInterface(in_netId, in_iface));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "networkRemoveInterface";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_networkAddUidRanges:
  {
    int32_t in_netId;
    ::std::vector<::android::net::UidRangeParcel> in_uidRanges;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelableVector(&in_uidRanges);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
      _transaction_log.input_args.emplace_back("in_uidRanges", ::android::internal::ToString(in_uidRanges));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkAddUidRanges(in_netId, in_uidRanges));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "networkAddUidRanges";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_networkRemoveUidRanges:
  {
    int32_t in_netId;
    ::std::vector<::android::net::UidRangeParcel> in_uidRanges;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelableVector(&in_uidRanges);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
      _transaction_log.input_args.emplace_back("in_uidRanges", ::android::internal::ToString(in_uidRanges));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkRemoveUidRanges(in_netId, in_uidRanges));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "networkRemoveUidRanges";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_networkRejectNonSecureVpn:
  {
    bool in_add;
    ::std::vector<::android::net::UidRangeParcel> in_uidRanges;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_add);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelableVector(&in_uidRanges);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_add", ::android::internal::ToString(in_add));
      _transaction_log.input_args.emplace_back("in_uidRanges", ::android::internal::ToString(in_uidRanges));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkRejectNonSecureVpn(in_add, in_uidRanges));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "networkRejectNonSecureVpn";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_socketDestroy:
  {
    ::std::vector<::android::net::UidRangeParcel> in_uidRanges;
    ::std::vector<int32_t> in_exemptUids;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelableVector(&in_uidRanges);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32Vector(&in_exemptUids);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_uidRanges", ::android::internal::ToString(in_uidRanges));
      _transaction_log.input_args.emplace_back("in_exemptUids", ::android::internal::ToString(in_exemptUids));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(socketDestroy(in_uidRanges, in_exemptUids));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "socketDestroy";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_tetherApplyDnsInterfaces:
  {
    bool _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherApplyDnsInterfaces(&_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "tetherApplyDnsInterfaces";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      _transaction_log.result = ::android::internal::ToString(_aidl_return);
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeBool(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_tetherGetStats:
  {
    ::std::vector<::android::net::TetherStatsParcel> _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherGetStats(&_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "tetherGetStats";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      _transaction_log.result = ::android::internal::ToString(_aidl_return);
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeParcelableVector(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_interfaceAddAddress:
  {
    ::std::string in_ifName;
    ::std::string in_addrString;
    int32_t in_prefixLength;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_addrString);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_prefixLength);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
      _transaction_log.input_args.emplace_back("in_addrString", ::android::internal::ToString(in_addrString));
      _transaction_log.input_args.emplace_back("in_prefixLength", ::android::internal::ToString(in_prefixLength));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(interfaceAddAddress(in_ifName, in_addrString, in_prefixLength));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "interfaceAddAddress";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_interfaceDelAddress:
  {
    ::std::string in_ifName;
    ::std::string in_addrString;
    int32_t in_prefixLength;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_addrString);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_prefixLength);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
      _transaction_log.input_args.emplace_back("in_addrString", ::android::internal::ToString(in_addrString));
      _transaction_log.input_args.emplace_back("in_prefixLength", ::android::internal::ToString(in_prefixLength));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(interfaceDelAddress(in_ifName, in_addrString, in_prefixLength));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "interfaceDelAddress";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_getProcSysNet:
  {
    int32_t in_ipversion;
    int32_t in_which;
    ::std::string in_ifname;
    ::std::string in_parameter;
    ::std::string _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_ipversion);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_which);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifname);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_parameter);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ipversion", ::android::internal::ToString(in_ipversion));
      _transaction_log.input_args.emplace_back("in_which", ::android::internal::ToString(in_which));
      _transaction_log.input_args.emplace_back("in_ifname", ::android::internal::ToString(in_ifname));
      _transaction_log.input_args.emplace_back("in_parameter", ::android::internal::ToString(in_parameter));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(getProcSysNet(in_ipversion, in_which, in_ifname, in_parameter, &_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "getProcSysNet";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      _transaction_log.result = ::android::internal::ToString(_aidl_return);
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeUtf8AsUtf16(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_setProcSysNet:
  {
    int32_t in_ipversion;
    int32_t in_which;
    ::std::string in_ifname;
    ::std::string in_parameter;
    ::std::string in_value;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_ipversion);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_which);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifname);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_parameter);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_value);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ipversion", ::android::internal::ToString(in_ipversion));
      _transaction_log.input_args.emplace_back("in_which", ::android::internal::ToString(in_which));
      _transaction_log.input_args.emplace_back("in_ifname", ::android::internal::ToString(in_ifname));
      _transaction_log.input_args.emplace_back("in_parameter", ::android::internal::ToString(in_parameter));
      _transaction_log.input_args.emplace_back("in_value", ::android::internal::ToString(in_value));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(setProcSysNet(in_ipversion, in_which, in_ifname, in_parameter, in_value));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "setProcSysNet";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_ipSecSetEncapSocketOwner:
  {
    ::android::os::ParcelFileDescriptor in_socket;
    int32_t in_newUid;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_socket);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_newUid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_socket", ::android::internal::ToString(in_socket));
      _transaction_log.input_args.emplace_back("in_newUid", ::android::internal::ToString(in_newUid));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipSecSetEncapSocketOwner(in_socket, in_newUid));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "ipSecSetEncapSocketOwner";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_ipSecAllocateSpi:
  {
    int32_t in_transformId;
    ::std::string in_sourceAddress;
    ::std::string in_destinationAddress;
    int32_t in_spi;
    int32_t _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_transformId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_sourceAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_destinationAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_spi);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_transformId", ::android::internal::ToString(in_transformId));
      _transaction_log.input_args.emplace_back("in_sourceAddress", ::android::internal::ToString(in_sourceAddress));
      _transaction_log.input_args.emplace_back("in_destinationAddress", ::android::internal::ToString(in_destinationAddress));
      _transaction_log.input_args.emplace_back("in_spi", ::android::internal::ToString(in_spi));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipSecAllocateSpi(in_transformId, in_sourceAddress, in_destinationAddress, in_spi, &_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "ipSecAllocateSpi";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      _transaction_log.result = ::android::internal::ToString(_aidl_return);
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeInt32(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_ipSecAddSecurityAssociation:
  {
    int32_t in_transformId;
    int32_t in_mode;
    ::std::string in_sourceAddress;
    ::std::string in_destinationAddress;
    int32_t in_underlyingNetId;
    int32_t in_spi;
    int32_t in_markValue;
    int32_t in_markMask;
    ::std::string in_authAlgo;
    ::std::vector<uint8_t> in_authKey;
    int32_t in_authTruncBits;
    ::std::string in_cryptAlgo;
    ::std::vector<uint8_t> in_cryptKey;
    int32_t in_cryptTruncBits;
    ::std::string in_aeadAlgo;
    ::std::vector<uint8_t> in_aeadKey;
    int32_t in_aeadIcvBits;
    int32_t in_encapType;
    int32_t in_encapLocalPort;
    int32_t in_encapRemotePort;
    int32_t in_interfaceId;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_transformId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_mode);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_sourceAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_destinationAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_underlyingNetId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_spi);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_markValue);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_markMask);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_authAlgo);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_authKey);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_authTruncBits);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_cryptAlgo);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_cryptKey);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_cryptTruncBits);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_aeadAlgo);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_aeadKey);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_aeadIcvBits);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_encapType);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_encapLocalPort);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_encapRemotePort);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_interfaceId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_transformId", ::android::internal::ToString(in_transformId));
      _transaction_log.input_args.emplace_back("in_mode", ::android::internal::ToString(in_mode));
      _transaction_log.input_args.emplace_back("in_sourceAddress", ::android::internal::ToString(in_sourceAddress));
      _transaction_log.input_args.emplace_back("in_destinationAddress", ::android::internal::ToString(in_destinationAddress));
      _transaction_log.input_args.emplace_back("in_underlyingNetId", ::android::internal::ToString(in_underlyingNetId));
      _transaction_log.input_args.emplace_back("in_spi", ::android::internal::ToString(in_spi));
      _transaction_log.input_args.emplace_back("in_markValue", ::android::internal::ToString(in_markValue));
      _transaction_log.input_args.emplace_back("in_markMask", ::android::internal::ToString(in_markMask));
      _transaction_log.input_args.emplace_back("in_authAlgo", ::android::internal::ToString(in_authAlgo));
      _transaction_log.input_args.emplace_back("in_authKey", ::android::internal::ToString(in_authKey));
      _transaction_log.input_args.emplace_back("in_authTruncBits", ::android::internal::ToString(in_authTruncBits));
      _transaction_log.input_args.emplace_back("in_cryptAlgo", ::android::internal::ToString(in_cryptAlgo));
      _transaction_log.input_args.emplace_back("in_cryptKey", ::android::internal::ToString(in_cryptKey));
      _transaction_log.input_args.emplace_back("in_cryptTruncBits", ::android::internal::ToString(in_cryptTruncBits));
      _transaction_log.input_args.emplace_back("in_aeadAlgo", ::android::internal::ToString(in_aeadAlgo));
      _transaction_log.input_args.emplace_back("in_aeadKey", ::android::internal::ToString(in_aeadKey));
      _transaction_log.input_args.emplace_back("in_aeadIcvBits", ::android::internal::ToString(in_aeadIcvBits));
      _transaction_log.input_args.emplace_back("in_encapType", ::android::internal::ToString(in_encapType));
      _transaction_log.input_args.emplace_back("in_encapLocalPort", ::android::internal::ToString(in_encapLocalPort));
      _transaction_log.input_args.emplace_back("in_encapRemotePort", ::android::internal::ToString(in_encapRemotePort));
      _transaction_log.input_args.emplace_back("in_interfaceId", ::android::internal::ToString(in_interfaceId));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipSecAddSecurityAssociation(in_transformId, in_mode, in_sourceAddress, in_destinationAddress, in_underlyingNetId, in_spi, in_markValue, in_markMask, in_authAlgo, in_authKey, in_authTruncBits, in_cryptAlgo, in_cryptKey, in_cryptTruncBits, in_aeadAlgo, in_aeadKey, in_aeadIcvBits, in_encapType, in_encapLocalPort, in_encapRemotePort, in_interfaceId));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "ipSecAddSecurityAssociation";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_ipSecDeleteSecurityAssociation:
  {
    int32_t in_transformId;
    ::std::string in_sourceAddress;
    ::std::string in_destinationAddress;
    int32_t in_spi;
    int32_t in_markValue;
    int32_t in_markMask;
    int32_t in_interfaceId;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_transformId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_sourceAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_destinationAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_spi);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_markValue);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_markMask);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_interfaceId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_transformId", ::android::internal::ToString(in_transformId));
      _transaction_log.input_args.emplace_back("in_sourceAddress", ::android::internal::ToString(in_sourceAddress));
      _transaction_log.input_args.emplace_back("in_destinationAddress", ::android::internal::ToString(in_destinationAddress));
      _transaction_log.input_args.emplace_back("in_spi", ::android::internal::ToString(in_spi));
      _transaction_log.input_args.emplace_back("in_markValue", ::android::internal::ToString(in_markValue));
      _transaction_log.input_args.emplace_back("in_markMask", ::android::internal::ToString(in_markMask));
      _transaction_log.input_args.emplace_back("in_interfaceId", ::android::internal::ToString(in_interfaceId));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipSecDeleteSecurityAssociation(in_transformId, in_sourceAddress, in_destinationAddress, in_spi, in_markValue, in_markMask, in_interfaceId));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "ipSecDeleteSecurityAssociation";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_ipSecApplyTransportModeTransform:
  {
    ::android::os::ParcelFileDescriptor in_socket;
    int32_t in_transformId;
    int32_t in_direction;
    ::std::string in_sourceAddress;
    ::std::string in_destinationAddress;
    int32_t in_spi;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_socket);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_transformId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_direction);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_sourceAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_destinationAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_spi);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_socket", ::android::internal::ToString(in_socket));
      _transaction_log.input_args.emplace_back("in_transformId", ::android::internal::ToString(in_transformId));
      _transaction_log.input_args.emplace_back("in_direction", ::android::internal::ToString(in_direction));
      _transaction_log.input_args.emplace_back("in_sourceAddress", ::android::internal::ToString(in_sourceAddress));
      _transaction_log.input_args.emplace_back("in_destinationAddress", ::android::internal::ToString(in_destinationAddress));
      _transaction_log.input_args.emplace_back("in_spi", ::android::internal::ToString(in_spi));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipSecApplyTransportModeTransform(in_socket, in_transformId, in_direction, in_sourceAddress, in_destinationAddress, in_spi));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "ipSecApplyTransportModeTransform";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_ipSecRemoveTransportModeTransform:
  {
    ::android::os::ParcelFileDescriptor in_socket;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_socket);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_socket", ::android::internal::ToString(in_socket));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipSecRemoveTransportModeTransform(in_socket));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "ipSecRemoveTransportModeTransform";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_ipSecAddSecurityPolicy:
  {
    int32_t in_transformId;
    int32_t in_selAddrFamily;
    int32_t in_direction;
    ::std::string in_tmplSrcAddress;
    ::std::string in_tmplDstAddress;
    int32_t in_spi;
    int32_t in_markValue;
    int32_t in_markMask;
    int32_t in_interfaceId;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_transformId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_selAddrFamily);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_direction);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_tmplSrcAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_tmplDstAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_spi);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_markValue);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_markMask);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_interfaceId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_transformId", ::android::internal::ToString(in_transformId));
      _transaction_log.input_args.emplace_back("in_selAddrFamily", ::android::internal::ToString(in_selAddrFamily));
      _transaction_log.input_args.emplace_back("in_direction", ::android::internal::ToString(in_direction));
      _transaction_log.input_args.emplace_back("in_tmplSrcAddress", ::android::internal::ToString(in_tmplSrcAddress));
      _transaction_log.input_args.emplace_back("in_tmplDstAddress", ::android::internal::ToString(in_tmplDstAddress));
      _transaction_log.input_args.emplace_back("in_spi", ::android::internal::ToString(in_spi));
      _transaction_log.input_args.emplace_back("in_markValue", ::android::internal::ToString(in_markValue));
      _transaction_log.input_args.emplace_back("in_markMask", ::android::internal::ToString(in_markMask));
      _transaction_log.input_args.emplace_back("in_interfaceId", ::android::internal::ToString(in_interfaceId));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipSecAddSecurityPolicy(in_transformId, in_selAddrFamily, in_direction, in_tmplSrcAddress, in_tmplDstAddress, in_spi, in_markValue, in_markMask, in_interfaceId));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "ipSecAddSecurityPolicy";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_ipSecUpdateSecurityPolicy:
  {
    int32_t in_transformId;
    int32_t in_selAddrFamily;
    int32_t in_direction;
    ::std::string in_tmplSrcAddress;
    ::std::string in_tmplDstAddress;
    int32_t in_spi;
    int32_t in_markValue;
    int32_t in_markMask;
    int32_t in_interfaceId;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_transformId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_selAddrFamily);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_direction);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_tmplSrcAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_tmplDstAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_spi);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_markValue);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_markMask);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_interfaceId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_transformId", ::android::internal::ToString(in_transformId));
      _transaction_log.input_args.emplace_back("in_selAddrFamily", ::android::internal::ToString(in_selAddrFamily));
      _transaction_log.input_args.emplace_back("in_direction", ::android::internal::ToString(in_direction));
      _transaction_log.input_args.emplace_back("in_tmplSrcAddress", ::android::internal::ToString(in_tmplSrcAddress));
      _transaction_log.input_args.emplace_back("in_tmplDstAddress", ::android::internal::ToString(in_tmplDstAddress));
      _transaction_log.input_args.emplace_back("in_spi", ::android::internal::ToString(in_spi));
      _transaction_log.input_args.emplace_back("in_markValue", ::android::internal::ToString(in_markValue));
      _transaction_log.input_args.emplace_back("in_markMask", ::android::internal::ToString(in_markMask));
      _transaction_log.input_args.emplace_back("in_interfaceId", ::android::internal::ToString(in_interfaceId));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipSecUpdateSecurityPolicy(in_transformId, in_selAddrFamily, in_direction, in_tmplSrcAddress, in_tmplDstAddress, in_spi, in_markValue, in_markMask, in_interfaceId));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "ipSecUpdateSecurityPolicy";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_ipSecDeleteSecurityPolicy:
  {
    int32_t in_transformId;
    int32_t in_selAddrFamily;
    int32_t in_direction;
    int32_t in_markValue;
    int32_t in_markMask;
    int32_t in_interfaceId;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_transformId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_selAddrFamily);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_direction);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_markValue);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_markMask);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_interfaceId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_transformId", ::android::internal::ToString(in_transformId));
      _transaction_log.input_args.emplace_back("in_selAddrFamily", ::android::internal::ToString(in_selAddrFamily));
      _transaction_log.input_args.emplace_back("in_direction", ::android::internal::ToString(in_direction));
      _transaction_log.input_args.emplace_back("in_markValue", ::android::internal::ToString(in_markValue));
      _transaction_log.input_args.emplace_back("in_markMask", ::android::internal::ToString(in_markMask));
      _transaction_log.input_args.emplace_back("in_interfaceId", ::android::internal::ToString(in_interfaceId));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipSecDeleteSecurityPolicy(in_transformId, in_selAddrFamily, in_direction, in_markValue, in_markMask, in_interfaceId));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "ipSecDeleteSecurityPolicy";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_ipSecAddTunnelInterface:
  {
    ::std::string in_deviceName;
    ::std::string in_localAddress;
    ::std::string in_remoteAddress;
    int32_t in_iKey;
    int32_t in_oKey;
    int32_t in_interfaceId;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_deviceName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_localAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_remoteAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_iKey);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_oKey);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_interfaceId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_deviceName", ::android::internal::ToString(in_deviceName));
      _transaction_log.input_args.emplace_back("in_localAddress", ::android::internal::ToString(in_localAddress));
      _transaction_log.input_args.emplace_back("in_remoteAddress", ::android::internal::ToString(in_remoteAddress));
      _transaction_log.input_args.emplace_back("in_iKey", ::android::internal::ToString(in_iKey));
      _transaction_log.input_args.emplace_back("in_oKey", ::android::internal::ToString(in_oKey));
      _transaction_log.input_args.emplace_back("in_interfaceId", ::android::internal::ToString(in_interfaceId));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipSecAddTunnelInterface(in_deviceName, in_localAddress, in_remoteAddress, in_iKey, in_oKey, in_interfaceId));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "ipSecAddTunnelInterface";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_ipSecUpdateTunnelInterface:
  {
    ::std::string in_deviceName;
    ::std::string in_localAddress;
    ::std::string in_remoteAddress;
    int32_t in_iKey;
    int32_t in_oKey;
    int32_t in_interfaceId;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_deviceName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_localAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_remoteAddress);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_iKey);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_oKey);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_interfaceId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_deviceName", ::android::internal::ToString(in_deviceName));
      _transaction_log.input_args.emplace_back("in_localAddress", ::android::internal::ToString(in_localAddress));
      _transaction_log.input_args.emplace_back("in_remoteAddress", ::android::internal::ToString(in_remoteAddress));
      _transaction_log.input_args.emplace_back("in_iKey", ::android::internal::ToString(in_iKey));
      _transaction_log.input_args.emplace_back("in_oKey", ::android::internal::ToString(in_oKey));
      _transaction_log.input_args.emplace_back("in_interfaceId", ::android::internal::ToString(in_interfaceId));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipSecUpdateTunnelInterface(in_deviceName, in_localAddress, in_remoteAddress, in_iKey, in_oKey, in_interfaceId));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "ipSecUpdateTunnelInterface";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_ipSecRemoveTunnelInterface:
  {
    ::std::string in_deviceName;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_deviceName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_deviceName", ::android::internal::ToString(in_deviceName));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipSecRemoveTunnelInterface(in_deviceName));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "ipSecRemoveTunnelInterface";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_wakeupAddInterface:
  {
    ::std::string in_ifName;
    ::std::string in_prefix;
    int32_t in_mark;
    int32_t in_mask;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_prefix);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_mark);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_mask);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
      _transaction_log.input_args.emplace_back("in_prefix", ::android::internal::ToString(in_prefix));
      _transaction_log.input_args.emplace_back("in_mark", ::android::internal::ToString(in_mark));
      _transaction_log.input_args.emplace_back("in_mask", ::android::internal::ToString(in_mask));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(wakeupAddInterface(in_ifName, in_prefix, in_mark, in_mask));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "wakeupAddInterface";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_wakeupDelInterface:
  {
    ::std::string in_ifName;
    ::std::string in_prefix;
    int32_t in_mark;
    int32_t in_mask;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_prefix);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_mark);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_mask);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
      _transaction_log.input_args.emplace_back("in_prefix", ::android::internal::ToString(in_prefix));
      _transaction_log.input_args.emplace_back("in_mark", ::android::internal::ToString(in_mark));
      _transaction_log.input_args.emplace_back("in_mask", ::android::internal::ToString(in_mask));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(wakeupDelInterface(in_ifName, in_prefix, in_mark, in_mask));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "wakeupDelInterface";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_setIPv6AddrGenMode:
  {
    ::std::string in_ifName;
    int32_t in_mode;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_mode);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
      _transaction_log.input_args.emplace_back("in_mode", ::android::internal::ToString(in_mode));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(setIPv6AddrGenMode(in_ifName, in_mode));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "setIPv6AddrGenMode";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_idletimerAddInterface:
  {
    ::std::string in_ifName;
    int32_t in_timeout;
    ::std::string in_classLabel;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_timeout);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_classLabel);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
      _transaction_log.input_args.emplace_back("in_timeout", ::android::internal::ToString(in_timeout));
      _transaction_log.input_args.emplace_back("in_classLabel", ::android::internal::ToString(in_classLabel));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(idletimerAddInterface(in_ifName, in_timeout, in_classLabel));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "idletimerAddInterface";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_idletimerRemoveInterface:
  {
    ::std::string in_ifName;
    int32_t in_timeout;
    ::std::string in_classLabel;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_timeout);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_classLabel);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
      _transaction_log.input_args.emplace_back("in_timeout", ::android::internal::ToString(in_timeout));
      _transaction_log.input_args.emplace_back("in_classLabel", ::android::internal::ToString(in_classLabel));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(idletimerRemoveInterface(in_ifName, in_timeout, in_classLabel));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "idletimerRemoveInterface";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_strictUidCleartextPenalty:
  {
    int32_t in_uid;
    int32_t in_policyPenalty;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_uid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_policyPenalty);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_uid", ::android::internal::ToString(in_uid));
      _transaction_log.input_args.emplace_back("in_policyPenalty", ::android::internal::ToString(in_policyPenalty));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(strictUidCleartextPenalty(in_uid, in_policyPenalty));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "strictUidCleartextPenalty";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_clatdStart:
  {
    ::std::string in_ifName;
    ::std::string in_nat64Prefix;
    ::std::string _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_nat64Prefix);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
      _transaction_log.input_args.emplace_back("in_nat64Prefix", ::android::internal::ToString(in_nat64Prefix));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(clatdStart(in_ifName, in_nat64Prefix, &_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "clatdStart";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      _transaction_log.result = ::android::internal::ToString(_aidl_return);
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeUtf8AsUtf16(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_clatdStop:
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
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(clatdStop(in_ifName));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "clatdStop";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_ipfwdEnabled:
  {
    bool _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipfwdEnabled(&_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "ipfwdEnabled";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      _transaction_log.result = ::android::internal::ToString(_aidl_return);
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeBool(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_ipfwdGetRequesterList:
  {
    ::std::vector<::std::string> _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipfwdGetRequesterList(&_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "ipfwdGetRequesterList";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      _transaction_log.result = ::android::internal::ToString(_aidl_return);
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeUtf8VectorAsUtf16Vector(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_ipfwdEnableForwarding:
  {
    ::std::string in_requester;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_requester);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_requester", ::android::internal::ToString(in_requester));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipfwdEnableForwarding(in_requester));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "ipfwdEnableForwarding";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_ipfwdDisableForwarding:
  {
    ::std::string in_requester;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_requester);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_requester", ::android::internal::ToString(in_requester));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipfwdDisableForwarding(in_requester));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "ipfwdDisableForwarding";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_ipfwdAddInterfaceForward:
  {
    ::std::string in_fromIface;
    ::std::string in_toIface;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_fromIface);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_toIface);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_fromIface", ::android::internal::ToString(in_fromIface));
      _transaction_log.input_args.emplace_back("in_toIface", ::android::internal::ToString(in_toIface));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipfwdAddInterfaceForward(in_fromIface, in_toIface));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "ipfwdAddInterfaceForward";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_ipfwdRemoveInterfaceForward:
  {
    ::std::string in_fromIface;
    ::std::string in_toIface;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_fromIface);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_toIface);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_fromIface", ::android::internal::ToString(in_fromIface));
      _transaction_log.input_args.emplace_back("in_toIface", ::android::internal::ToString(in_toIface));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(ipfwdRemoveInterfaceForward(in_fromIface, in_toIface));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "ipfwdRemoveInterfaceForward";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_bandwidthSetInterfaceQuota:
  {
    ::std::string in_ifName;
    int64_t in_bytes;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt64(&in_bytes);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
      _transaction_log.input_args.emplace_back("in_bytes", ::android::internal::ToString(in_bytes));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(bandwidthSetInterfaceQuota(in_ifName, in_bytes));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "bandwidthSetInterfaceQuota";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_bandwidthRemoveInterfaceQuota:
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
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(bandwidthRemoveInterfaceQuota(in_ifName));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "bandwidthRemoveInterfaceQuota";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_bandwidthSetInterfaceAlert:
  {
    ::std::string in_ifName;
    int64_t in_bytes;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt64(&in_bytes);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
      _transaction_log.input_args.emplace_back("in_bytes", ::android::internal::ToString(in_bytes));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(bandwidthSetInterfaceAlert(in_ifName, in_bytes));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "bandwidthSetInterfaceAlert";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_bandwidthRemoveInterfaceAlert:
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
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(bandwidthRemoveInterfaceAlert(in_ifName));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "bandwidthRemoveInterfaceAlert";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_bandwidthSetGlobalAlert:
  {
    int64_t in_bytes;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt64(&in_bytes);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_bytes", ::android::internal::ToString(in_bytes));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(bandwidthSetGlobalAlert(in_bytes));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "bandwidthSetGlobalAlert";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_bandwidthAddNaughtyApp:
  {
    int32_t in_uid;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_uid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_uid", ::android::internal::ToString(in_uid));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(bandwidthAddNaughtyApp(in_uid));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "bandwidthAddNaughtyApp";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_bandwidthRemoveNaughtyApp:
  {
    int32_t in_uid;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_uid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_uid", ::android::internal::ToString(in_uid));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(bandwidthRemoveNaughtyApp(in_uid));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "bandwidthRemoveNaughtyApp";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_bandwidthAddNiceApp:
  {
    int32_t in_uid;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_uid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_uid", ::android::internal::ToString(in_uid));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(bandwidthAddNiceApp(in_uid));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "bandwidthAddNiceApp";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_bandwidthRemoveNiceApp:
  {
    int32_t in_uid;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_uid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_uid", ::android::internal::ToString(in_uid));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(bandwidthRemoveNiceApp(in_uid));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "bandwidthRemoveNiceApp";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_tetherStart:
  {
    ::std::vector<::std::string> in_dhcpRanges;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8VectorFromUtf16Vector(&in_dhcpRanges);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_dhcpRanges", ::android::internal::ToString(in_dhcpRanges));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherStart(in_dhcpRanges));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "tetherStart";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_tetherStop:
  {
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherStop());
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "tetherStop";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_tetherIsEnabled:
  {
    bool _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherIsEnabled(&_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "tetherIsEnabled";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      _transaction_log.result = ::android::internal::ToString(_aidl_return);
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeBool(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_tetherInterfaceAdd:
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
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherInterfaceAdd(in_ifName));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "tetherInterfaceAdd";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_tetherInterfaceRemove:
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
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherInterfaceRemove(in_ifName));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "tetherInterfaceRemove";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_tetherInterfaceList:
  {
    ::std::vector<::std::string> _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherInterfaceList(&_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "tetherInterfaceList";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      _transaction_log.result = ::android::internal::ToString(_aidl_return);
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeUtf8VectorAsUtf16Vector(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_tetherDnsSet:
  {
    int32_t in_netId;
    ::std::vector<::std::string> in_dnsAddrs;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8VectorFromUtf16Vector(&in_dnsAddrs);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
      _transaction_log.input_args.emplace_back("in_dnsAddrs", ::android::internal::ToString(in_dnsAddrs));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherDnsSet(in_netId, in_dnsAddrs));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "tetherDnsSet";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_tetherDnsList:
  {
    ::std::vector<::std::string> _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherDnsList(&_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "tetherDnsList";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      _transaction_log.result = ::android::internal::ToString(_aidl_return);
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeUtf8VectorAsUtf16Vector(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_networkAddRoute:
  {
    int32_t in_netId;
    ::std::string in_ifName;
    ::std::string in_destination;
    ::std::string in_nextHop;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_destination);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_nextHop);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
      _transaction_log.input_args.emplace_back("in_destination", ::android::internal::ToString(in_destination));
      _transaction_log.input_args.emplace_back("in_nextHop", ::android::internal::ToString(in_nextHop));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkAddRoute(in_netId, in_ifName, in_destination, in_nextHop));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "networkAddRoute";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_networkRemoveRoute:
  {
    int32_t in_netId;
    ::std::string in_ifName;
    ::std::string in_destination;
    ::std::string in_nextHop;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_destination);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_nextHop);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
      _transaction_log.input_args.emplace_back("in_destination", ::android::internal::ToString(in_destination));
      _transaction_log.input_args.emplace_back("in_nextHop", ::android::internal::ToString(in_nextHop));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkRemoveRoute(in_netId, in_ifName, in_destination, in_nextHop));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "networkRemoveRoute";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_networkAddLegacyRoute:
  {
    int32_t in_netId;
    ::std::string in_ifName;
    ::std::string in_destination;
    ::std::string in_nextHop;
    int32_t in_uid;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_destination);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_nextHop);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_uid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
      _transaction_log.input_args.emplace_back("in_destination", ::android::internal::ToString(in_destination));
      _transaction_log.input_args.emplace_back("in_nextHop", ::android::internal::ToString(in_nextHop));
      _transaction_log.input_args.emplace_back("in_uid", ::android::internal::ToString(in_uid));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkAddLegacyRoute(in_netId, in_ifName, in_destination, in_nextHop, in_uid));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "networkAddLegacyRoute";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_networkRemoveLegacyRoute:
  {
    int32_t in_netId;
    ::std::string in_ifName;
    ::std::string in_destination;
    ::std::string in_nextHop;
    int32_t in_uid;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_destination);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_nextHop);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_uid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
      _transaction_log.input_args.emplace_back("in_destination", ::android::internal::ToString(in_destination));
      _transaction_log.input_args.emplace_back("in_nextHop", ::android::internal::ToString(in_nextHop));
      _transaction_log.input_args.emplace_back("in_uid", ::android::internal::ToString(in_uid));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkRemoveLegacyRoute(in_netId, in_ifName, in_destination, in_nextHop, in_uid));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "networkRemoveLegacyRoute";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_networkGetDefault:
  {
    int32_t _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkGetDefault(&_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "networkGetDefault";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      _transaction_log.result = ::android::internal::ToString(_aidl_return);
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeInt32(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_networkSetDefault:
  {
    int32_t in_netId;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkSetDefault(in_netId));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "networkSetDefault";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_networkClearDefault:
  {
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkClearDefault());
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "networkClearDefault";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_networkSetPermissionForNetwork:
  {
    int32_t in_netId;
    int32_t in_permission;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_permission);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
      _transaction_log.input_args.emplace_back("in_permission", ::android::internal::ToString(in_permission));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkSetPermissionForNetwork(in_netId, in_permission));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "networkSetPermissionForNetwork";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_networkSetPermissionForUser:
  {
    int32_t in_permission;
    ::std::vector<int32_t> in_uids;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_permission);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32Vector(&in_uids);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_permission", ::android::internal::ToString(in_permission));
      _transaction_log.input_args.emplace_back("in_uids", ::android::internal::ToString(in_uids));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkSetPermissionForUser(in_permission, in_uids));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "networkSetPermissionForUser";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_networkClearPermissionForUser:
  {
    ::std::vector<int32_t> in_uids;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32Vector(&in_uids);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_uids", ::android::internal::ToString(in_uids));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkClearPermissionForUser(in_uids));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "networkClearPermissionForUser";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_trafficSetNetPermForUids:
  {
    int32_t in_permission;
    ::std::vector<int32_t> in_uids;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_permission);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32Vector(&in_uids);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_permission", ::android::internal::ToString(in_permission));
      _transaction_log.input_args.emplace_back("in_uids", ::android::internal::ToString(in_uids));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(trafficSetNetPermForUids(in_permission, in_uids));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "trafficSetNetPermForUids";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_networkSetProtectAllow:
  {
    int32_t in_uid;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_uid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_uid", ::android::internal::ToString(in_uid));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkSetProtectAllow(in_uid));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "networkSetProtectAllow";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_networkSetProtectDeny:
  {
    int32_t in_uid;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_uid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_uid", ::android::internal::ToString(in_uid));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkSetProtectDeny(in_uid));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "networkSetProtectDeny";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_networkCanProtect:
  {
    int32_t in_uid;
    bool _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_uid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_uid", ::android::internal::ToString(in_uid));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkCanProtect(in_uid, &_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "networkCanProtect";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      _transaction_log.result = ::android::internal::ToString(_aidl_return);
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeBool(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_firewallSetFirewallType:
  {
    int32_t in_firewalltype;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_firewalltype);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_firewalltype", ::android::internal::ToString(in_firewalltype));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(firewallSetFirewallType(in_firewalltype));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "firewallSetFirewallType";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_firewallSetInterfaceRule:
  {
    ::std::string in_ifName;
    int32_t in_firewallRule;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_firewallRule);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
      _transaction_log.input_args.emplace_back("in_firewallRule", ::android::internal::ToString(in_firewallRule));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(firewallSetInterfaceRule(in_ifName, in_firewallRule));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "firewallSetInterfaceRule";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_firewallSetUidRule:
  {
    int32_t in_childChain;
    int32_t in_uid;
    int32_t in_firewallRule;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_childChain);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_uid);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_firewallRule);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_childChain", ::android::internal::ToString(in_childChain));
      _transaction_log.input_args.emplace_back("in_uid", ::android::internal::ToString(in_uid));
      _transaction_log.input_args.emplace_back("in_firewallRule", ::android::internal::ToString(in_firewallRule));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(firewallSetUidRule(in_childChain, in_uid, in_firewallRule));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "firewallSetUidRule";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_firewallEnableChildChain:
  {
    int32_t in_childChain;
    bool in_enable;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_childChain);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_enable);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_childChain", ::android::internal::ToString(in_childChain));
      _transaction_log.input_args.emplace_back("in_enable", ::android::internal::ToString(in_enable));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(firewallEnableChildChain(in_childChain, in_enable));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "firewallEnableChildChain";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_interfaceGetList:
  {
    ::std::vector<::std::string> _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(interfaceGetList(&_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "interfaceGetList";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      _transaction_log.result = ::android::internal::ToString(_aidl_return);
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeUtf8VectorAsUtf16Vector(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_interfaceGetCfg:
  {
    ::std::string in_ifName;
    ::android::net::InterfaceConfigurationParcel _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(interfaceGetCfg(in_ifName, &_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "interfaceGetCfg";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      _transaction_log.result = ::android::internal::ToString(_aidl_return);
      BnNetd::logFunc(_transaction_log);
    }
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
  case BnNetd::TRANSACTION_interfaceSetCfg:
  {
    ::android::net::InterfaceConfigurationParcel in_cfg;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_cfg);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_cfg", ::android::internal::ToString(in_cfg));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(interfaceSetCfg(in_cfg));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "interfaceSetCfg";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_interfaceSetIPv6PrivacyExtensions:
  {
    ::std::string in_ifName;
    bool in_enable;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_enable);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
      _transaction_log.input_args.emplace_back("in_enable", ::android::internal::ToString(in_enable));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(interfaceSetIPv6PrivacyExtensions(in_ifName, in_enable));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "interfaceSetIPv6PrivacyExtensions";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_interfaceClearAddrs:
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
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(interfaceClearAddrs(in_ifName));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "interfaceClearAddrs";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_interfaceSetEnableIPv6:
  {
    ::std::string in_ifName;
    bool in_enable;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_enable);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
      _transaction_log.input_args.emplace_back("in_enable", ::android::internal::ToString(in_enable));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(interfaceSetEnableIPv6(in_ifName, in_enable));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "interfaceSetEnableIPv6";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_interfaceSetMtu:
  {
    ::std::string in_ifName;
    int32_t in_mtu;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_mtu);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
      _transaction_log.input_args.emplace_back("in_mtu", ::android::internal::ToString(in_mtu));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(interfaceSetMtu(in_ifName, in_mtu));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "interfaceSetMtu";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_tetherAddForward:
  {
    ::std::string in_intIface;
    ::std::string in_extIface;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_intIface);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_extIface);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_intIface", ::android::internal::ToString(in_intIface));
      _transaction_log.input_args.emplace_back("in_extIface", ::android::internal::ToString(in_extIface));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherAddForward(in_intIface, in_extIface));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "tetherAddForward";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_tetherRemoveForward:
  {
    ::std::string in_intIface;
    ::std::string in_extIface;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_intIface);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_extIface);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_intIface", ::android::internal::ToString(in_intIface));
      _transaction_log.input_args.emplace_back("in_extIface", ::android::internal::ToString(in_extIface));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherRemoveForward(in_intIface, in_extIface));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "tetherRemoveForward";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_setTcpRWmemorySize:
  {
    ::std::string in_rmemValues;
    ::std::string in_wmemValues;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_rmemValues);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_wmemValues);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_rmemValues", ::android::internal::ToString(in_rmemValues));
      _transaction_log.input_args.emplace_back("in_wmemValues", ::android::internal::ToString(in_wmemValues));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(setTcpRWmemorySize(in_rmemValues, in_wmemValues));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "setTcpRWmemorySize";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_registerUnsolicitedEventListener:
  {
    ::android::sp<::android::net::INetdUnsolicitedEventListener> in_listener;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readStrongBinder(&in_listener);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_listener", ::android::internal::ToString(in_listener));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(registerUnsolicitedEventListener(in_listener));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "registerUnsolicitedEventListener";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_firewallAddUidInterfaceRules:
  {
    ::std::string in_ifName;
    ::std::vector<int32_t> in_uids;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_ifName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32Vector(&in_uids);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ifName", ::android::internal::ToString(in_ifName));
      _transaction_log.input_args.emplace_back("in_uids", ::android::internal::ToString(in_uids));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(firewallAddUidInterfaceRules(in_ifName, in_uids));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "firewallAddUidInterfaceRules";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_firewallRemoveUidInterfaceRules:
  {
    ::std::vector<int32_t> in_uids;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32Vector(&in_uids);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_uids", ::android::internal::ToString(in_uids));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(firewallRemoveUidInterfaceRules(in_uids));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "firewallRemoveUidInterfaceRules";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_trafficSwapActiveStatsMap:
  {
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(trafficSwapActiveStatsMap());
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "trafficSwapActiveStatsMap";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_getOemNetd:
  {
    ::android::sp<::android::IBinder> _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(getOemNetd(&_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "getOemNetd";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      _transaction_log.result = ::android::internal::ToString(_aidl_return);
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeStrongBinder(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_tetherStartWithConfiguration:
  {
    ::android::net::TetherConfigParcel in_config;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_config);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_config", ::android::internal::ToString(in_config));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherStartWithConfiguration(in_config));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "tetherStartWithConfiguration";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_getFwmarkForNetwork:
  {
    int32_t in_netId;
    ::android::net::MarkMaskParcel _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(getFwmarkForNetwork(in_netId, &_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "getFwmarkForNetwork";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      _transaction_log.result = ::android::internal::ToString(_aidl_return);
      BnNetd::logFunc(_transaction_log);
    }
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
  case BnNetd::TRANSACTION_networkAddRouteParcel:
  {
    int32_t in_netId;
    ::android::net::RouteInfoParcel in_routeInfo;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_routeInfo);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
      _transaction_log.input_args.emplace_back("in_routeInfo", ::android::internal::ToString(in_routeInfo));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkAddRouteParcel(in_netId, in_routeInfo));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "networkAddRouteParcel";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_networkUpdateRouteParcel:
  {
    int32_t in_netId;
    ::android::net::RouteInfoParcel in_routeInfo;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_routeInfo);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
      _transaction_log.input_args.emplace_back("in_routeInfo", ::android::internal::ToString(in_routeInfo));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkUpdateRouteParcel(in_netId, in_routeInfo));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "networkUpdateRouteParcel";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_networkRemoveRouteParcel:
  {
    int32_t in_netId;
    ::android::net::RouteInfoParcel in_routeInfo;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_netId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_routeInfo);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
      _transaction_log.input_args.emplace_back("in_routeInfo", ::android::internal::ToString(in_routeInfo));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkRemoveRouteParcel(in_netId, in_routeInfo));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "networkRemoveRouteParcel";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_tetherOffloadRuleAdd:
  {
    ::android::net::TetherOffloadRuleParcel in_rule;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_rule);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_rule", ::android::internal::ToString(in_rule));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherOffloadRuleAdd(in_rule));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "tetherOffloadRuleAdd";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_tetherOffloadRuleRemove:
  {
    ::android::net::TetherOffloadRuleParcel in_rule;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_rule);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_rule", ::android::internal::ToString(in_rule));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherOffloadRuleRemove(in_rule));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "tetherOffloadRuleRemove";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_tetherOffloadGetStats:
  {
    ::std::vector<::android::net::TetherStatsParcel> _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherOffloadGetStats(&_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "tetherOffloadGetStats";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      _transaction_log.result = ::android::internal::ToString(_aidl_return);
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeParcelableVector(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_tetherOffloadSetInterfaceQuota:
  {
    int32_t in_ifIndex;
    int64_t in_quotaBytes;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_ifIndex);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt64(&in_quotaBytes);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ifIndex", ::android::internal::ToString(in_ifIndex));
      _transaction_log.input_args.emplace_back("in_quotaBytes", ::android::internal::ToString(in_quotaBytes));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherOffloadSetInterfaceQuota(in_ifIndex, in_quotaBytes));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "tetherOffloadSetInterfaceQuota";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_tetherOffloadGetAndClearStats:
  {
    int32_t in_ifIndex;
    ::android::net::TetherStatsParcel _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_ifIndex);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_ifIndex", ::android::internal::ToString(in_ifIndex));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(tetherOffloadGetAndClearStats(in_ifIndex, &_aidl_return));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "tetherOffloadGetAndClearStats";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      _transaction_log.result = ::android::internal::ToString(_aidl_return);
      BnNetd::logFunc(_transaction_log);
    }
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
  case BnNetd::TRANSACTION_networkCreate:
  {
    ::android::net::NativeNetworkConfig in_config;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_config);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnNetd::TransactionLog _transaction_log;
    if (BnNetd::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_config", ::android::internal::ToString(in_config));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(networkCreate(in_config));
    if (BnNetd::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.net.INetd";
      _transaction_log.method_name = "networkCreate";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      BnNetd::logFunc(_transaction_log);
    }
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  case BnNetd::TRANSACTION_getInterfaceVersion:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeInt32(INetd::VERSION);
  }
  break;
  case BnNetd::TRANSACTION_getInterfaceHash:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeUtf8AsUtf16(INetd::HASH);
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

#pragma clang diagnostic pop

int32_t BnNetd::getInterfaceVersion() {
  return INetd::VERSION;
}

std::string BnNetd::getInterfaceHash() {
  return INetd::HASH;
}

std::function<void(const BnNetd::TransactionLog&)> BnNetd::logFunc;

}  // namespace net

}  // namespace android
