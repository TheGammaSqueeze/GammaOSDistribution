#include <android/binder_parcel_utils.h>
#include <aidl/android/net/resolv/aidl/BpDnsResolverUnsolicitedEventListener.h>
#include <aidl/android/net/resolv/aidl/BnDnsResolverUnsolicitedEventListener.h>
#include <aidl/android/net/resolv/aidl/IDnsResolverUnsolicitedEventListener.h>
#include <android/binder_to_string.h>

namespace aidl {
namespace android {
namespace net {
namespace resolv {
namespace aidl {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnDnsResolverUnsolicitedEventListener> _aidl_impl = std::static_pointer_cast<BnDnsResolverUnsolicitedEventListener>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*onDnsHealthEvent*/): {
      ::aidl::android::net::resolv::aidl::DnsHealthEventParcel in_dnsHealthEvent;

      _aidl_ret_status = ::ndk::AParcel_readParcelable(_aidl_in, &in_dnsHealthEvent);
      if (_aidl_ret_status != STATUS_OK) break;

      BnDnsResolverUnsolicitedEventListener::TransactionLog _transaction_log;
      if (BnDnsResolverUnsolicitedEventListener::logFunc != nullptr) {
        _transaction_log.input_args.emplace_back("in_dnsHealthEvent", ::android::internal::ToString(in_dnsHealthEvent));
      }
      auto _log_start = std::chrono::steady_clock::now();
      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onDnsHealthEvent(in_dnsHealthEvent);
      if (BnDnsResolverUnsolicitedEventListener::logFunc != nullptr) {
        auto _log_end = std::chrono::steady_clock::now();
        _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
        _transaction_log.interface_name = "android.net.resolv.aidl.IDnsResolverUnsolicitedEventListener";
        _transaction_log.method_name = "onDnsHealthEvent";
        _transaction_log.stub_address = _aidl_impl.get();
        _transaction_log.proxy_address = nullptr;
        _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
        _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
        _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
        _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
        BnDnsResolverUnsolicitedEventListener::logFunc(_transaction_log);
      }
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*onNat64PrefixEvent*/): {
      ::aidl::android::net::resolv::aidl::Nat64PrefixEventParcel in_nat64PrefixEvent;

      _aidl_ret_status = ::ndk::AParcel_readParcelable(_aidl_in, &in_nat64PrefixEvent);
      if (_aidl_ret_status != STATUS_OK) break;

      BnDnsResolverUnsolicitedEventListener::TransactionLog _transaction_log;
      if (BnDnsResolverUnsolicitedEventListener::logFunc != nullptr) {
        _transaction_log.input_args.emplace_back("in_nat64PrefixEvent", ::android::internal::ToString(in_nat64PrefixEvent));
      }
      auto _log_start = std::chrono::steady_clock::now();
      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onNat64PrefixEvent(in_nat64PrefixEvent);
      if (BnDnsResolverUnsolicitedEventListener::logFunc != nullptr) {
        auto _log_end = std::chrono::steady_clock::now();
        _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
        _transaction_log.interface_name = "android.net.resolv.aidl.IDnsResolverUnsolicitedEventListener";
        _transaction_log.method_name = "onNat64PrefixEvent";
        _transaction_log.stub_address = _aidl_impl.get();
        _transaction_log.proxy_address = nullptr;
        _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
        _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
        _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
        _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
        BnDnsResolverUnsolicitedEventListener::logFunc(_transaction_log);
      }
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 2 /*onPrivateDnsValidationEvent*/): {
      ::aidl::android::net::resolv::aidl::PrivateDnsValidationEventParcel in_privateDnsValidationEvent;

      _aidl_ret_status = ::ndk::AParcel_readParcelable(_aidl_in, &in_privateDnsValidationEvent);
      if (_aidl_ret_status != STATUS_OK) break;

      BnDnsResolverUnsolicitedEventListener::TransactionLog _transaction_log;
      if (BnDnsResolverUnsolicitedEventListener::logFunc != nullptr) {
        _transaction_log.input_args.emplace_back("in_privateDnsValidationEvent", ::android::internal::ToString(in_privateDnsValidationEvent));
      }
      auto _log_start = std::chrono::steady_clock::now();
      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onPrivateDnsValidationEvent(in_privateDnsValidationEvent);
      if (BnDnsResolverUnsolicitedEventListener::logFunc != nullptr) {
        auto _log_end = std::chrono::steady_clock::now();
        _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
        _transaction_log.interface_name = "android.net.resolv.aidl.IDnsResolverUnsolicitedEventListener";
        _transaction_log.method_name = "onPrivateDnsValidationEvent";
        _transaction_log.stub_address = _aidl_impl.get();
        _transaction_log.proxy_address = nullptr;
        _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
        _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
        _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
        _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
        BnDnsResolverUnsolicitedEventListener::logFunc(_transaction_log);
      }
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 16777214 /*getInterfaceVersion*/): {
      int32_t _aidl_return;

      BnDnsResolverUnsolicitedEventListener::TransactionLog _transaction_log;
      if (BnDnsResolverUnsolicitedEventListener::logFunc != nullptr) {
      }
      auto _log_start = std::chrono::steady_clock::now();
      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->getInterfaceVersion(&_aidl_return);
      if (BnDnsResolverUnsolicitedEventListener::logFunc != nullptr) {
        auto _log_end = std::chrono::steady_clock::now();
        _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
        _transaction_log.interface_name = "android.net.resolv.aidl.IDnsResolverUnsolicitedEventListener";
        _transaction_log.method_name = "getInterfaceVersion";
        _transaction_log.stub_address = _aidl_impl.get();
        _transaction_log.proxy_address = nullptr;
        _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
        _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
        _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
        _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
        _transaction_log.result = ::android::internal::ToString(_aidl_return);
        BnDnsResolverUnsolicitedEventListener::logFunc(_transaction_log);
      }
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = AParcel_writeInt32(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 16777213 /*getInterfaceHash*/): {
      std::string _aidl_return;

      BnDnsResolverUnsolicitedEventListener::TransactionLog _transaction_log;
      if (BnDnsResolverUnsolicitedEventListener::logFunc != nullptr) {
      }
      auto _log_start = std::chrono::steady_clock::now();
      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->getInterfaceHash(&_aidl_return);
      if (BnDnsResolverUnsolicitedEventListener::logFunc != nullptr) {
        auto _log_end = std::chrono::steady_clock::now();
        _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
        _transaction_log.interface_name = "android.net.resolv.aidl.IDnsResolverUnsolicitedEventListener";
        _transaction_log.method_name = "getInterfaceHash";
        _transaction_log.stub_address = _aidl_impl.get();
        _transaction_log.proxy_address = nullptr;
        _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
        _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
        _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
        _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
        _transaction_log.result = ::android::internal::ToString(_aidl_return);
        BnDnsResolverUnsolicitedEventListener::logFunc(_transaction_log);
      }
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeString(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IDnsResolverUnsolicitedEventListener::descriptor, _aidl_onTransact);

BpDnsResolverUnsolicitedEventListener::BpDnsResolverUnsolicitedEventListener(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpDnsResolverUnsolicitedEventListener::~BpDnsResolverUnsolicitedEventListener() {}
std::function<void(const BpDnsResolverUnsolicitedEventListener::TransactionLog&)> BpDnsResolverUnsolicitedEventListener::logFunc;

::ndk::ScopedAStatus BpDnsResolverUnsolicitedEventListener::onDnsHealthEvent(const ::aidl::android::net::resolv::aidl::DnsHealthEventParcel& in_dnsHealthEvent) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  BpDnsResolverUnsolicitedEventListener::TransactionLog _transaction_log;
  if (BpDnsResolverUnsolicitedEventListener::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("in_dnsHealthEvent", ::android::internal::ToString(in_dnsHealthEvent));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeParcelable(_aidl_in.get(), in_dnsHealthEvent);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*onDnsHealthEvent*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IDnsResolverUnsolicitedEventListener::getDefaultImpl()) {
    _aidl_status = IDnsResolverUnsolicitedEventListener::getDefaultImpl()->onDnsHealthEvent(in_dnsHealthEvent);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  if (BpDnsResolverUnsolicitedEventListener::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.resolv.aidl.IDnsResolverUnsolicitedEventListener";
    _transaction_log.method_name = "onDnsHealthEvent";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
    _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
    _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
    _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
    BpDnsResolverUnsolicitedEventListener::logFunc(_transaction_log);
  }
  return _aidl_status;
}
::ndk::ScopedAStatus BpDnsResolverUnsolicitedEventListener::onNat64PrefixEvent(const ::aidl::android::net::resolv::aidl::Nat64PrefixEventParcel& in_nat64PrefixEvent) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  BpDnsResolverUnsolicitedEventListener::TransactionLog _transaction_log;
  if (BpDnsResolverUnsolicitedEventListener::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("in_nat64PrefixEvent", ::android::internal::ToString(in_nat64PrefixEvent));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeParcelable(_aidl_in.get(), in_nat64PrefixEvent);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*onNat64PrefixEvent*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IDnsResolverUnsolicitedEventListener::getDefaultImpl()) {
    _aidl_status = IDnsResolverUnsolicitedEventListener::getDefaultImpl()->onNat64PrefixEvent(in_nat64PrefixEvent);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  if (BpDnsResolverUnsolicitedEventListener::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.resolv.aidl.IDnsResolverUnsolicitedEventListener";
    _transaction_log.method_name = "onNat64PrefixEvent";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
    _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
    _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
    _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
    BpDnsResolverUnsolicitedEventListener::logFunc(_transaction_log);
  }
  return _aidl_status;
}
::ndk::ScopedAStatus BpDnsResolverUnsolicitedEventListener::onPrivateDnsValidationEvent(const ::aidl::android::net::resolv::aidl::PrivateDnsValidationEventParcel& in_privateDnsValidationEvent) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  BpDnsResolverUnsolicitedEventListener::TransactionLog _transaction_log;
  if (BpDnsResolverUnsolicitedEventListener::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("in_privateDnsValidationEvent", ::android::internal::ToString(in_privateDnsValidationEvent));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeParcelable(_aidl_in.get(), in_privateDnsValidationEvent);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 2 /*onPrivateDnsValidationEvent*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IDnsResolverUnsolicitedEventListener::getDefaultImpl()) {
    _aidl_status = IDnsResolverUnsolicitedEventListener::getDefaultImpl()->onPrivateDnsValidationEvent(in_privateDnsValidationEvent);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  if (BpDnsResolverUnsolicitedEventListener::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.resolv.aidl.IDnsResolverUnsolicitedEventListener";
    _transaction_log.method_name = "onPrivateDnsValidationEvent";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
    _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
    _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
    _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
    BpDnsResolverUnsolicitedEventListener::logFunc(_transaction_log);
  }
  return _aidl_status;
}
::ndk::ScopedAStatus BpDnsResolverUnsolicitedEventListener::getInterfaceVersion(int32_t* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  if (_aidl_cached_version != -1) {
    *_aidl_return = _aidl_cached_version;
    _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
    return _aidl_status;
  }
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  BpDnsResolverUnsolicitedEventListener::TransactionLog _transaction_log;
  if (BpDnsResolverUnsolicitedEventListener::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 16777214 /*getInterfaceVersion*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IDnsResolverUnsolicitedEventListener::getDefaultImpl()) {
    _aidl_status = IDnsResolverUnsolicitedEventListener::getDefaultImpl()->getInterfaceVersion(_aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = AParcel_readInt32(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_cached_version = *_aidl_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  if (BpDnsResolverUnsolicitedEventListener::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.resolv.aidl.IDnsResolverUnsolicitedEventListener";
    _transaction_log.method_name = "getInterfaceVersion";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
    _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
    _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
    _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
    _transaction_log.result = ::android::internal::ToString(*_aidl_return);
    BpDnsResolverUnsolicitedEventListener::logFunc(_transaction_log);
  }
  return _aidl_status;
}
::ndk::ScopedAStatus BpDnsResolverUnsolicitedEventListener::getInterfaceHash(std::string* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  const std::lock_guard<std::mutex> lock(_aidl_cached_hash_mutex);
  if (_aidl_cached_hash != "-1") {
    *_aidl_return = _aidl_cached_hash;
    _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
    return _aidl_status;
  }
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  BpDnsResolverUnsolicitedEventListener::TransactionLog _transaction_log;
  if (BpDnsResolverUnsolicitedEventListener::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 16777213 /*getInterfaceHash*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IDnsResolverUnsolicitedEventListener::getDefaultImpl()) {
    _aidl_status = IDnsResolverUnsolicitedEventListener::getDefaultImpl()->getInterfaceHash(_aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = ::ndk::AParcel_readString(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_cached_hash = *_aidl_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  if (BpDnsResolverUnsolicitedEventListener::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.resolv.aidl.IDnsResolverUnsolicitedEventListener";
    _transaction_log.method_name = "getInterfaceHash";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
    _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
    _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
    _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
    _transaction_log.result = ::android::internal::ToString(*_aidl_return);
    BpDnsResolverUnsolicitedEventListener::logFunc(_transaction_log);
  }
  return _aidl_status;
}
// Source for BnDnsResolverUnsolicitedEventListener
BnDnsResolverUnsolicitedEventListener::BnDnsResolverUnsolicitedEventListener() {}
BnDnsResolverUnsolicitedEventListener::~BnDnsResolverUnsolicitedEventListener() {}
std::function<void(const BnDnsResolverUnsolicitedEventListener::TransactionLog&)> BnDnsResolverUnsolicitedEventListener::logFunc;
::ndk::SpAIBinder BnDnsResolverUnsolicitedEventListener::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
::ndk::ScopedAStatus BnDnsResolverUnsolicitedEventListener::getInterfaceVersion(int32_t* _aidl_return) {
  *_aidl_return = IDnsResolverUnsolicitedEventListener::version;
  return ::ndk::ScopedAStatus(AStatus_newOk());
}
::ndk::ScopedAStatus BnDnsResolverUnsolicitedEventListener::getInterfaceHash(std::string* _aidl_return) {
  *_aidl_return = IDnsResolverUnsolicitedEventListener::hash;
  return ::ndk::ScopedAStatus(AStatus_newOk());
}
// Source for IDnsResolverUnsolicitedEventListener
const char* IDnsResolverUnsolicitedEventListener::descriptor = "android.net.resolv.aidl.IDnsResolverUnsolicitedEventListener";
IDnsResolverUnsolicitedEventListener::IDnsResolverUnsolicitedEventListener() {}
IDnsResolverUnsolicitedEventListener::~IDnsResolverUnsolicitedEventListener() {}


std::shared_ptr<IDnsResolverUnsolicitedEventListener> IDnsResolverUnsolicitedEventListener::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IDnsResolverUnsolicitedEventListener>(interface);
  }
  return ::ndk::SharedRefBase::make<BpDnsResolverUnsolicitedEventListener>(binder);
}

binder_status_t IDnsResolverUnsolicitedEventListener::writeToParcel(AParcel* parcel, const std::shared_ptr<IDnsResolverUnsolicitedEventListener>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IDnsResolverUnsolicitedEventListener::readFromParcel(const AParcel* parcel, std::shared_ptr<IDnsResolverUnsolicitedEventListener>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IDnsResolverUnsolicitedEventListener::fromBinder(binder);
  return STATUS_OK;
}
bool IDnsResolverUnsolicitedEventListener::setDefaultImpl(const std::shared_ptr<IDnsResolverUnsolicitedEventListener>& impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IDnsResolverUnsolicitedEventListener::default_impl);
  if (impl) {
    IDnsResolverUnsolicitedEventListener::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IDnsResolverUnsolicitedEventListener>& IDnsResolverUnsolicitedEventListener::getDefaultImpl() {
  return IDnsResolverUnsolicitedEventListener::default_impl;
}
std::shared_ptr<IDnsResolverUnsolicitedEventListener> IDnsResolverUnsolicitedEventListener::default_impl = nullptr;
::ndk::ScopedAStatus IDnsResolverUnsolicitedEventListenerDefault::onDnsHealthEvent(const ::aidl::android::net::resolv::aidl::DnsHealthEventParcel& /*in_dnsHealthEvent*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IDnsResolverUnsolicitedEventListenerDefault::onNat64PrefixEvent(const ::aidl::android::net::resolv::aidl::Nat64PrefixEventParcel& /*in_nat64PrefixEvent*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IDnsResolverUnsolicitedEventListenerDefault::onPrivateDnsValidationEvent(const ::aidl::android::net::resolv::aidl::PrivateDnsValidationEventParcel& /*in_privateDnsValidationEvent*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IDnsResolverUnsolicitedEventListenerDefault::getInterfaceVersion(int32_t* _aidl_return) {
  *_aidl_return = 0;
  return ::ndk::ScopedAStatus(AStatus_newOk());
}
::ndk::ScopedAStatus IDnsResolverUnsolicitedEventListenerDefault::getInterfaceHash(std::string* _aidl_return) {
  *_aidl_return = "";
  return ::ndk::ScopedAStatus(AStatus_newOk());
}
::ndk::SpAIBinder IDnsResolverUnsolicitedEventListenerDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IDnsResolverUnsolicitedEventListenerDefault::isRemote() {
  return false;
}
}  // namespace aidl
}  // namespace resolv
}  // namespace net
}  // namespace android
}  // namespace aidl
