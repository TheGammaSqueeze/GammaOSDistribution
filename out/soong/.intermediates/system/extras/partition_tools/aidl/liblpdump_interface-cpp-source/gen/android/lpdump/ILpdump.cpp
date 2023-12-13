#include <android/lpdump/ILpdump.h>
#include <android/lpdump/BpLpdump.h>

namespace android {

namespace lpdump {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(Lpdump, "android.lpdump.ILpdump")

}  // namespace lpdump

}  // namespace android
#include <android/lpdump/BpLpdump.h>
#include <android/lpdump/BnLpdump.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>
#include <chrono>
#include <functional>

namespace android {

namespace lpdump {

BpLpdump::BpLpdump(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<ILpdump>(_aidl_impl){
}

std::function<void(const BpLpdump::TransactionLog&)> BpLpdump::logFunc;

::android::binder::Status BpLpdump::run(const ::std::vector<::std::string>& args, ::std::string* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  BpLpdump::TransactionLog _transaction_log;
  if (BpLpdump::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("args", ::android::internal::ToString(args));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8VectorAsUtf16Vector(args);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnLpdump::TRANSACTION_run, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && ILpdump::getDefaultImpl())) {
     return ILpdump::getDefaultImpl()->run(args, _aidl_return);
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
  if (BpLpdump::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.lpdump.ILpdump";
    _transaction_log.method_name = "run";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = _aidl_status.exceptionCode();
    _transaction_log.exception_message = _aidl_status.exceptionMessage();
    _transaction_log.transaction_error = _aidl_status.transactionError();
    _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
    _transaction_log.result = ::android::internal::ToString(*_aidl_return);
    BpLpdump::logFunc(_transaction_log);
  }
  return _aidl_status;
}

}  // namespace lpdump

}  // namespace android
#include <android/lpdump/BnLpdump.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>
#include <chrono>
#include <functional>

namespace android {

namespace lpdump {

BnLpdump::BnLpdump()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnLpdump::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnLpdump::TRANSACTION_run:
  {
    ::std::vector<::std::string> in_args;
    ::std::string _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8VectorFromUtf16Vector(&in_args);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    BnLpdump::TransactionLog _transaction_log;
    if (BnLpdump::logFunc != nullptr) {
      _transaction_log.input_args.emplace_back("in_args", ::android::internal::ToString(in_args));
    }
    auto _log_start = std::chrono::steady_clock::now();
    ::android::binder::Status _aidl_status(run(in_args, &_aidl_return));
    if (BnLpdump::logFunc != nullptr) {
      auto _log_end = std::chrono::steady_clock::now();
      _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
      _transaction_log.interface_name = "android.lpdump.ILpdump";
      _transaction_log.method_name = "run";
      _transaction_log.stub_address = static_cast<const void*>(this);
      _transaction_log.proxy_address = nullptr;
      _transaction_log.exception_code = _aidl_status.exceptionCode();
      _transaction_log.exception_message = _aidl_status.exceptionMessage();
      _transaction_log.transaction_error = _aidl_status.transactionError();
      _transaction_log.service_specific_error_code = _aidl_status.serviceSpecificErrorCode();
      _transaction_log.result = ::android::internal::ToString(_aidl_return);
      BnLpdump::logFunc(_transaction_log);
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

std::function<void(const BnLpdump::TransactionLog&)> BnLpdump::logFunc;

}  // namespace lpdump

}  // namespace android
