#include <android/binder_parcel_utils.h>
#include <aidl/android/net/BpDnsResolver.h>
#include <aidl/android/net/BnDnsResolver.h>
#include <aidl/android/net/IDnsResolver.h>
#include <aidl/android/net/metrics/BpNetdEventListener.h>
#include <aidl/android/net/metrics/BnNetdEventListener.h>
#include <aidl/android/net/metrics/INetdEventListener.h>
#include <aidl/android/net/resolv/aidl/BpDnsResolverUnsolicitedEventListener.h>
#include <aidl/android/net/resolv/aidl/BnDnsResolverUnsolicitedEventListener.h>
#include <aidl/android/net/resolv/aidl/IDnsResolverUnsolicitedEventListener.h>
#include <android/binder_to_string.h>

namespace aidl {
namespace android {
namespace net {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnDnsResolver> _aidl_impl = std::static_pointer_cast<BnDnsResolver>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*isAlive*/): {
      bool _aidl_return;

      BnDnsResolver::TransactionLog _transaction_log;
      if (BnDnsResolver::logFunc != nullptr) {
      }
      auto _log_start = std::chrono::steady_clock::now();
      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->isAlive(&_aidl_return);
      if (BnDnsResolver::logFunc != nullptr) {
        auto _log_end = std::chrono::steady_clock::now();
        _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
        _transaction_log.interface_name = "android.net.IDnsResolver";
        _transaction_log.method_name = "isAlive";
        _transaction_log.stub_address = _aidl_impl.get();
        _transaction_log.proxy_address = nullptr;
        _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
        _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
        _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
        _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
        _transaction_log.result = ::android::internal::ToString(_aidl_return);
        BnDnsResolver::logFunc(_transaction_log);
      }
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = AParcel_writeBool(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*registerEventListener*/): {
      std::shared_ptr<::aidl::android::net::metrics::INetdEventListener> in_listener;

      _aidl_ret_status = ::aidl::android::net::metrics::INetdEventListener::readFromParcel(_aidl_in, &in_listener);
      if (_aidl_ret_status != STATUS_OK) break;

      BnDnsResolver::TransactionLog _transaction_log;
      if (BnDnsResolver::logFunc != nullptr) {
        _transaction_log.input_args.emplace_back("in_listener", ::android::internal::ToString(in_listener));
      }
      auto _log_start = std::chrono::steady_clock::now();
      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->registerEventListener(in_listener);
      if (BnDnsResolver::logFunc != nullptr) {
        auto _log_end = std::chrono::steady_clock::now();
        _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
        _transaction_log.interface_name = "android.net.IDnsResolver";
        _transaction_log.method_name = "registerEventListener";
        _transaction_log.stub_address = _aidl_impl.get();
        _transaction_log.proxy_address = nullptr;
        _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
        _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
        _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
        _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
        BnDnsResolver::logFunc(_transaction_log);
      }
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 2 /*setResolverConfiguration*/): {
      ::aidl::android::net::ResolverParamsParcel in_resolverParams;

      _aidl_ret_status = ::ndk::AParcel_readParcelable(_aidl_in, &in_resolverParams);
      if (_aidl_ret_status != STATUS_OK) break;

      BnDnsResolver::TransactionLog _transaction_log;
      if (BnDnsResolver::logFunc != nullptr) {
        _transaction_log.input_args.emplace_back("in_resolverParams", ::android::internal::ToString(in_resolverParams));
      }
      auto _log_start = std::chrono::steady_clock::now();
      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->setResolverConfiguration(in_resolverParams);
      if (BnDnsResolver::logFunc != nullptr) {
        auto _log_end = std::chrono::steady_clock::now();
        _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
        _transaction_log.interface_name = "android.net.IDnsResolver";
        _transaction_log.method_name = "setResolverConfiguration";
        _transaction_log.stub_address = _aidl_impl.get();
        _transaction_log.proxy_address = nullptr;
        _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
        _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
        _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
        _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
        BnDnsResolver::logFunc(_transaction_log);
      }
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 3 /*getResolverInfo*/): {
      int32_t in_netId;
      std::vector<std::string> out_servers;
      std::vector<std::string> out_domains;
      std::vector<std::string> out_tlsServers;
      std::vector<int32_t> out_params;
      std::vector<int32_t> out_stats;
      std::vector<int32_t> out_wait_for_pending_req_timeout_count;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_netId);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_resizeVector(_aidl_in, &out_servers);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_resizeVector(_aidl_in, &out_domains);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_resizeVector(_aidl_in, &out_tlsServers);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_resizeVector(_aidl_in, &out_params);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_resizeVector(_aidl_in, &out_stats);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_resizeVector(_aidl_in, &out_wait_for_pending_req_timeout_count);
      if (_aidl_ret_status != STATUS_OK) break;

      BnDnsResolver::TransactionLog _transaction_log;
      if (BnDnsResolver::logFunc != nullptr) {
        _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
      }
      auto _log_start = std::chrono::steady_clock::now();
      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->getResolverInfo(in_netId, &out_servers, &out_domains, &out_tlsServers, &out_params, &out_stats, &out_wait_for_pending_req_timeout_count);
      if (BnDnsResolver::logFunc != nullptr) {
        auto _log_end = std::chrono::steady_clock::now();
        _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
        _transaction_log.interface_name = "android.net.IDnsResolver";
        _transaction_log.method_name = "getResolverInfo";
        _transaction_log.stub_address = _aidl_impl.get();
        _transaction_log.proxy_address = nullptr;
        _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
        _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
        _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
        _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
        _transaction_log.output_args.emplace_back("out_servers", ::android::internal::ToString(out_servers));
        _transaction_log.output_args.emplace_back("out_domains", ::android::internal::ToString(out_domains));
        _transaction_log.output_args.emplace_back("out_tlsServers", ::android::internal::ToString(out_tlsServers));
        _transaction_log.output_args.emplace_back("out_params", ::android::internal::ToString(out_params));
        _transaction_log.output_args.emplace_back("out_stats", ::android::internal::ToString(out_stats));
        _transaction_log.output_args.emplace_back("out_wait_for_pending_req_timeout_count", ::android::internal::ToString(out_wait_for_pending_req_timeout_count));
        BnDnsResolver::logFunc(_transaction_log);
      }
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_out, out_servers);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_out, out_domains);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_out, out_tlsServers);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_out, out_params);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_out, out_stats);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_out, out_wait_for_pending_req_timeout_count);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 4 /*startPrefix64Discovery*/): {
      int32_t in_netId;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_netId);
      if (_aidl_ret_status != STATUS_OK) break;

      BnDnsResolver::TransactionLog _transaction_log;
      if (BnDnsResolver::logFunc != nullptr) {
        _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
      }
      auto _log_start = std::chrono::steady_clock::now();
      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->startPrefix64Discovery(in_netId);
      if (BnDnsResolver::logFunc != nullptr) {
        auto _log_end = std::chrono::steady_clock::now();
        _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
        _transaction_log.interface_name = "android.net.IDnsResolver";
        _transaction_log.method_name = "startPrefix64Discovery";
        _transaction_log.stub_address = _aidl_impl.get();
        _transaction_log.proxy_address = nullptr;
        _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
        _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
        _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
        _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
        BnDnsResolver::logFunc(_transaction_log);
      }
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 5 /*stopPrefix64Discovery*/): {
      int32_t in_netId;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_netId);
      if (_aidl_ret_status != STATUS_OK) break;

      BnDnsResolver::TransactionLog _transaction_log;
      if (BnDnsResolver::logFunc != nullptr) {
        _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
      }
      auto _log_start = std::chrono::steady_clock::now();
      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->stopPrefix64Discovery(in_netId);
      if (BnDnsResolver::logFunc != nullptr) {
        auto _log_end = std::chrono::steady_clock::now();
        _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
        _transaction_log.interface_name = "android.net.IDnsResolver";
        _transaction_log.method_name = "stopPrefix64Discovery";
        _transaction_log.stub_address = _aidl_impl.get();
        _transaction_log.proxy_address = nullptr;
        _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
        _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
        _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
        _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
        BnDnsResolver::logFunc(_transaction_log);
      }
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 6 /*getPrefix64*/): {
      int32_t in_netId;
      std::string _aidl_return;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_netId);
      if (_aidl_ret_status != STATUS_OK) break;

      BnDnsResolver::TransactionLog _transaction_log;
      if (BnDnsResolver::logFunc != nullptr) {
        _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
      }
      auto _log_start = std::chrono::steady_clock::now();
      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->getPrefix64(in_netId, &_aidl_return);
      if (BnDnsResolver::logFunc != nullptr) {
        auto _log_end = std::chrono::steady_clock::now();
        _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
        _transaction_log.interface_name = "android.net.IDnsResolver";
        _transaction_log.method_name = "getPrefix64";
        _transaction_log.stub_address = _aidl_impl.get();
        _transaction_log.proxy_address = nullptr;
        _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
        _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
        _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
        _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
        _transaction_log.result = ::android::internal::ToString(_aidl_return);
        BnDnsResolver::logFunc(_transaction_log);
      }
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeString(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 7 /*createNetworkCache*/): {
      int32_t in_netId;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_netId);
      if (_aidl_ret_status != STATUS_OK) break;

      BnDnsResolver::TransactionLog _transaction_log;
      if (BnDnsResolver::logFunc != nullptr) {
        _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
      }
      auto _log_start = std::chrono::steady_clock::now();
      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->createNetworkCache(in_netId);
      if (BnDnsResolver::logFunc != nullptr) {
        auto _log_end = std::chrono::steady_clock::now();
        _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
        _transaction_log.interface_name = "android.net.IDnsResolver";
        _transaction_log.method_name = "createNetworkCache";
        _transaction_log.stub_address = _aidl_impl.get();
        _transaction_log.proxy_address = nullptr;
        _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
        _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
        _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
        _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
        BnDnsResolver::logFunc(_transaction_log);
      }
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 8 /*destroyNetworkCache*/): {
      int32_t in_netId;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_netId);
      if (_aidl_ret_status != STATUS_OK) break;

      BnDnsResolver::TransactionLog _transaction_log;
      if (BnDnsResolver::logFunc != nullptr) {
        _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
      }
      auto _log_start = std::chrono::steady_clock::now();
      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->destroyNetworkCache(in_netId);
      if (BnDnsResolver::logFunc != nullptr) {
        auto _log_end = std::chrono::steady_clock::now();
        _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
        _transaction_log.interface_name = "android.net.IDnsResolver";
        _transaction_log.method_name = "destroyNetworkCache";
        _transaction_log.stub_address = _aidl_impl.get();
        _transaction_log.proxy_address = nullptr;
        _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
        _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
        _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
        _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
        BnDnsResolver::logFunc(_transaction_log);
      }
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 9 /*setLogSeverity*/): {
      int32_t in_logSeverity;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_logSeverity);
      if (_aidl_ret_status != STATUS_OK) break;

      BnDnsResolver::TransactionLog _transaction_log;
      if (BnDnsResolver::logFunc != nullptr) {
        _transaction_log.input_args.emplace_back("in_logSeverity", ::android::internal::ToString(in_logSeverity));
      }
      auto _log_start = std::chrono::steady_clock::now();
      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->setLogSeverity(in_logSeverity);
      if (BnDnsResolver::logFunc != nullptr) {
        auto _log_end = std::chrono::steady_clock::now();
        _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
        _transaction_log.interface_name = "android.net.IDnsResolver";
        _transaction_log.method_name = "setLogSeverity";
        _transaction_log.stub_address = _aidl_impl.get();
        _transaction_log.proxy_address = nullptr;
        _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
        _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
        _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
        _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
        BnDnsResolver::logFunc(_transaction_log);
      }
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 10 /*flushNetworkCache*/): {
      int32_t in_netId;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_netId);
      if (_aidl_ret_status != STATUS_OK) break;

      BnDnsResolver::TransactionLog _transaction_log;
      if (BnDnsResolver::logFunc != nullptr) {
        _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
      }
      auto _log_start = std::chrono::steady_clock::now();
      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->flushNetworkCache(in_netId);
      if (BnDnsResolver::logFunc != nullptr) {
        auto _log_end = std::chrono::steady_clock::now();
        _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
        _transaction_log.interface_name = "android.net.IDnsResolver";
        _transaction_log.method_name = "flushNetworkCache";
        _transaction_log.stub_address = _aidl_impl.get();
        _transaction_log.proxy_address = nullptr;
        _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
        _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
        _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
        _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
        BnDnsResolver::logFunc(_transaction_log);
      }
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 11 /*setPrefix64*/): {
      int32_t in_netId;
      std::string in_prefix;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_netId);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readString(_aidl_in, &in_prefix);
      if (_aidl_ret_status != STATUS_OK) break;

      BnDnsResolver::TransactionLog _transaction_log;
      if (BnDnsResolver::logFunc != nullptr) {
        _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
        _transaction_log.input_args.emplace_back("in_prefix", ::android::internal::ToString(in_prefix));
      }
      auto _log_start = std::chrono::steady_clock::now();
      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->setPrefix64(in_netId, in_prefix);
      if (BnDnsResolver::logFunc != nullptr) {
        auto _log_end = std::chrono::steady_clock::now();
        _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
        _transaction_log.interface_name = "android.net.IDnsResolver";
        _transaction_log.method_name = "setPrefix64";
        _transaction_log.stub_address = _aidl_impl.get();
        _transaction_log.proxy_address = nullptr;
        _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
        _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
        _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
        _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
        BnDnsResolver::logFunc(_transaction_log);
      }
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 12 /*registerUnsolicitedEventListener*/): {
      std::shared_ptr<::aidl::android::net::resolv::aidl::IDnsResolverUnsolicitedEventListener> in_listener;

      _aidl_ret_status = ::aidl::android::net::resolv::aidl::IDnsResolverUnsolicitedEventListener::readFromParcel(_aidl_in, &in_listener);
      if (_aidl_ret_status != STATUS_OK) break;

      BnDnsResolver::TransactionLog _transaction_log;
      if (BnDnsResolver::logFunc != nullptr) {
        _transaction_log.input_args.emplace_back("in_listener", ::android::internal::ToString(in_listener));
      }
      auto _log_start = std::chrono::steady_clock::now();
      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->registerUnsolicitedEventListener(in_listener);
      if (BnDnsResolver::logFunc != nullptr) {
        auto _log_end = std::chrono::steady_clock::now();
        _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
        _transaction_log.interface_name = "android.net.IDnsResolver";
        _transaction_log.method_name = "registerUnsolicitedEventListener";
        _transaction_log.stub_address = _aidl_impl.get();
        _transaction_log.proxy_address = nullptr;
        _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
        _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
        _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
        _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
        BnDnsResolver::logFunc(_transaction_log);
      }
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 13 /*setResolverOptions*/): {
      int32_t in_netId;
      ::aidl::android::net::ResolverOptionsParcel in_optionParams;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_netId);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readParcelable(_aidl_in, &in_optionParams);
      if (_aidl_ret_status != STATUS_OK) break;

      BnDnsResolver::TransactionLog _transaction_log;
      if (BnDnsResolver::logFunc != nullptr) {
        _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
        _transaction_log.input_args.emplace_back("in_optionParams", ::android::internal::ToString(in_optionParams));
      }
      auto _log_start = std::chrono::steady_clock::now();
      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->setResolverOptions(in_netId, in_optionParams);
      if (BnDnsResolver::logFunc != nullptr) {
        auto _log_end = std::chrono::steady_clock::now();
        _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
        _transaction_log.interface_name = "android.net.IDnsResolver";
        _transaction_log.method_name = "setResolverOptions";
        _transaction_log.stub_address = _aidl_impl.get();
        _transaction_log.proxy_address = nullptr;
        _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
        _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
        _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
        _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
        BnDnsResolver::logFunc(_transaction_log);
      }
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 16777214 /*getInterfaceVersion*/): {
      int32_t _aidl_return;

      BnDnsResolver::TransactionLog _transaction_log;
      if (BnDnsResolver::logFunc != nullptr) {
      }
      auto _log_start = std::chrono::steady_clock::now();
      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->getInterfaceVersion(&_aidl_return);
      if (BnDnsResolver::logFunc != nullptr) {
        auto _log_end = std::chrono::steady_clock::now();
        _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
        _transaction_log.interface_name = "android.net.IDnsResolver";
        _transaction_log.method_name = "getInterfaceVersion";
        _transaction_log.stub_address = _aidl_impl.get();
        _transaction_log.proxy_address = nullptr;
        _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
        _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
        _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
        _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
        _transaction_log.result = ::android::internal::ToString(_aidl_return);
        BnDnsResolver::logFunc(_transaction_log);
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

      BnDnsResolver::TransactionLog _transaction_log;
      if (BnDnsResolver::logFunc != nullptr) {
      }
      auto _log_start = std::chrono::steady_clock::now();
      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->getInterfaceHash(&_aidl_return);
      if (BnDnsResolver::logFunc != nullptr) {
        auto _log_end = std::chrono::steady_clock::now();
        _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
        _transaction_log.interface_name = "android.net.IDnsResolver";
        _transaction_log.method_name = "getInterfaceHash";
        _transaction_log.stub_address = _aidl_impl.get();
        _transaction_log.proxy_address = nullptr;
        _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
        _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
        _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
        _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
        _transaction_log.result = ::android::internal::ToString(_aidl_return);
        BnDnsResolver::logFunc(_transaction_log);
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

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IDnsResolver::descriptor, _aidl_onTransact);

BpDnsResolver::BpDnsResolver(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpDnsResolver::~BpDnsResolver() {}
std::function<void(const BpDnsResolver::TransactionLog&)> BpDnsResolver::logFunc;

::ndk::ScopedAStatus BpDnsResolver::isAlive(bool* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  BpDnsResolver::TransactionLog _transaction_log;
  if (BpDnsResolver::logFunc != nullptr) {
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*isAlive*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IDnsResolver::getDefaultImpl()) {
    _aidl_status = IDnsResolver::getDefaultImpl()->isAlive(_aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = AParcel_readBool(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  if (BpDnsResolver::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.IDnsResolver";
    _transaction_log.method_name = "isAlive";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
    _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
    _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
    _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
    _transaction_log.result = ::android::internal::ToString(*_aidl_return);
    BpDnsResolver::logFunc(_transaction_log);
  }
  return _aidl_status;
}
::ndk::ScopedAStatus BpDnsResolver::registerEventListener(const std::shared_ptr<::aidl::android::net::metrics::INetdEventListener>& in_listener) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  BpDnsResolver::TransactionLog _transaction_log;
  if (BpDnsResolver::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("in_listener", ::android::internal::ToString(in_listener));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::aidl::android::net::metrics::INetdEventListener::writeToParcel(_aidl_in.get(), in_listener);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*registerEventListener*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IDnsResolver::getDefaultImpl()) {
    _aidl_status = IDnsResolver::getDefaultImpl()->registerEventListener(in_listener);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  if (BpDnsResolver::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.IDnsResolver";
    _transaction_log.method_name = "registerEventListener";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
    _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
    _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
    _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
    BpDnsResolver::logFunc(_transaction_log);
  }
  return _aidl_status;
}
::ndk::ScopedAStatus BpDnsResolver::setResolverConfiguration(const ::aidl::android::net::ResolverParamsParcel& in_resolverParams) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  BpDnsResolver::TransactionLog _transaction_log;
  if (BpDnsResolver::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("in_resolverParams", ::android::internal::ToString(in_resolverParams));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeParcelable(_aidl_in.get(), in_resolverParams);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 2 /*setResolverConfiguration*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IDnsResolver::getDefaultImpl()) {
    _aidl_status = IDnsResolver::getDefaultImpl()->setResolverConfiguration(in_resolverParams);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  if (BpDnsResolver::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.IDnsResolver";
    _transaction_log.method_name = "setResolverConfiguration";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
    _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
    _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
    _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
    BpDnsResolver::logFunc(_transaction_log);
  }
  return _aidl_status;
}
::ndk::ScopedAStatus BpDnsResolver::getResolverInfo(int32_t in_netId, std::vector<std::string>* out_servers, std::vector<std::string>* out_domains, std::vector<std::string>* out_tlsServers, std::vector<int32_t>* out_params, std::vector<int32_t>* out_stats, std::vector<int32_t>* out_wait_for_pending_req_timeout_count) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  BpDnsResolver::TransactionLog _transaction_log;
  if (BpDnsResolver::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_netId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVectorSize(_aidl_in.get(), *out_servers);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVectorSize(_aidl_in.get(), *out_domains);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVectorSize(_aidl_in.get(), *out_tlsServers);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVectorSize(_aidl_in.get(), *out_params);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVectorSize(_aidl_in.get(), *out_stats);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVectorSize(_aidl_in.get(), *out_wait_for_pending_req_timeout_count);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 3 /*getResolverInfo*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IDnsResolver::getDefaultImpl()) {
    _aidl_status = IDnsResolver::getDefaultImpl()->getResolverInfo(in_netId, out_servers, out_domains, out_tlsServers, out_params, out_stats, out_wait_for_pending_req_timeout_count);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_out.get(), out_servers);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_out.get(), out_domains);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_out.get(), out_tlsServers);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_out.get(), out_params);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_out.get(), out_stats);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_out.get(), out_wait_for_pending_req_timeout_count);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  if (BpDnsResolver::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.IDnsResolver";
    _transaction_log.method_name = "getResolverInfo";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
    _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
    _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
    _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
    _transaction_log.output_args.emplace_back("out_servers", ::android::internal::ToString(*out_servers));
    _transaction_log.output_args.emplace_back("out_domains", ::android::internal::ToString(*out_domains));
    _transaction_log.output_args.emplace_back("out_tlsServers", ::android::internal::ToString(*out_tlsServers));
    _transaction_log.output_args.emplace_back("out_params", ::android::internal::ToString(*out_params));
    _transaction_log.output_args.emplace_back("out_stats", ::android::internal::ToString(*out_stats));
    _transaction_log.output_args.emplace_back("out_wait_for_pending_req_timeout_count", ::android::internal::ToString(*out_wait_for_pending_req_timeout_count));
    BpDnsResolver::logFunc(_transaction_log);
  }
  return _aidl_status;
}
::ndk::ScopedAStatus BpDnsResolver::startPrefix64Discovery(int32_t in_netId) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  BpDnsResolver::TransactionLog _transaction_log;
  if (BpDnsResolver::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_netId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 4 /*startPrefix64Discovery*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IDnsResolver::getDefaultImpl()) {
    _aidl_status = IDnsResolver::getDefaultImpl()->startPrefix64Discovery(in_netId);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  if (BpDnsResolver::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.IDnsResolver";
    _transaction_log.method_name = "startPrefix64Discovery";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
    _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
    _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
    _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
    BpDnsResolver::logFunc(_transaction_log);
  }
  return _aidl_status;
}
::ndk::ScopedAStatus BpDnsResolver::stopPrefix64Discovery(int32_t in_netId) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  BpDnsResolver::TransactionLog _transaction_log;
  if (BpDnsResolver::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_netId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 5 /*stopPrefix64Discovery*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IDnsResolver::getDefaultImpl()) {
    _aidl_status = IDnsResolver::getDefaultImpl()->stopPrefix64Discovery(in_netId);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  if (BpDnsResolver::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.IDnsResolver";
    _transaction_log.method_name = "stopPrefix64Discovery";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
    _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
    _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
    _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
    BpDnsResolver::logFunc(_transaction_log);
  }
  return _aidl_status;
}
::ndk::ScopedAStatus BpDnsResolver::getPrefix64(int32_t in_netId, std::string* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  BpDnsResolver::TransactionLog _transaction_log;
  if (BpDnsResolver::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_netId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 6 /*getPrefix64*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IDnsResolver::getDefaultImpl()) {
    _aidl_status = IDnsResolver::getDefaultImpl()->getPrefix64(in_netId, _aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = ::ndk::AParcel_readString(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  if (BpDnsResolver::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.IDnsResolver";
    _transaction_log.method_name = "getPrefix64";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
    _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
    _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
    _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
    _transaction_log.result = ::android::internal::ToString(*_aidl_return);
    BpDnsResolver::logFunc(_transaction_log);
  }
  return _aidl_status;
}
::ndk::ScopedAStatus BpDnsResolver::createNetworkCache(int32_t in_netId) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  BpDnsResolver::TransactionLog _transaction_log;
  if (BpDnsResolver::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_netId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 7 /*createNetworkCache*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IDnsResolver::getDefaultImpl()) {
    _aidl_status = IDnsResolver::getDefaultImpl()->createNetworkCache(in_netId);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  if (BpDnsResolver::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.IDnsResolver";
    _transaction_log.method_name = "createNetworkCache";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
    _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
    _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
    _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
    BpDnsResolver::logFunc(_transaction_log);
  }
  return _aidl_status;
}
::ndk::ScopedAStatus BpDnsResolver::destroyNetworkCache(int32_t in_netId) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  BpDnsResolver::TransactionLog _transaction_log;
  if (BpDnsResolver::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_netId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 8 /*destroyNetworkCache*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IDnsResolver::getDefaultImpl()) {
    _aidl_status = IDnsResolver::getDefaultImpl()->destroyNetworkCache(in_netId);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  if (BpDnsResolver::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.IDnsResolver";
    _transaction_log.method_name = "destroyNetworkCache";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
    _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
    _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
    _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
    BpDnsResolver::logFunc(_transaction_log);
  }
  return _aidl_status;
}
::ndk::ScopedAStatus BpDnsResolver::setLogSeverity(int32_t in_logSeverity) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  BpDnsResolver::TransactionLog _transaction_log;
  if (BpDnsResolver::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("in_logSeverity", ::android::internal::ToString(in_logSeverity));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_logSeverity);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 9 /*setLogSeverity*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IDnsResolver::getDefaultImpl()) {
    _aidl_status = IDnsResolver::getDefaultImpl()->setLogSeverity(in_logSeverity);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  if (BpDnsResolver::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.IDnsResolver";
    _transaction_log.method_name = "setLogSeverity";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
    _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
    _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
    _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
    BpDnsResolver::logFunc(_transaction_log);
  }
  return _aidl_status;
}
::ndk::ScopedAStatus BpDnsResolver::flushNetworkCache(int32_t in_netId) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  BpDnsResolver::TransactionLog _transaction_log;
  if (BpDnsResolver::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_netId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 10 /*flushNetworkCache*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IDnsResolver::getDefaultImpl()) {
    _aidl_status = IDnsResolver::getDefaultImpl()->flushNetworkCache(in_netId);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  if (BpDnsResolver::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.IDnsResolver";
    _transaction_log.method_name = "flushNetworkCache";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
    _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
    _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
    _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
    BpDnsResolver::logFunc(_transaction_log);
  }
  return _aidl_status;
}
::ndk::ScopedAStatus BpDnsResolver::setPrefix64(int32_t in_netId, const std::string& in_prefix) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  BpDnsResolver::TransactionLog _transaction_log;
  if (BpDnsResolver::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
    _transaction_log.input_args.emplace_back("in_prefix", ::android::internal::ToString(in_prefix));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_netId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeString(_aidl_in.get(), in_prefix);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 11 /*setPrefix64*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IDnsResolver::getDefaultImpl()) {
    _aidl_status = IDnsResolver::getDefaultImpl()->setPrefix64(in_netId, in_prefix);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  if (BpDnsResolver::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.IDnsResolver";
    _transaction_log.method_name = "setPrefix64";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
    _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
    _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
    _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
    BpDnsResolver::logFunc(_transaction_log);
  }
  return _aidl_status;
}
::ndk::ScopedAStatus BpDnsResolver::registerUnsolicitedEventListener(const std::shared_ptr<::aidl::android::net::resolv::aidl::IDnsResolverUnsolicitedEventListener>& in_listener) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  BpDnsResolver::TransactionLog _transaction_log;
  if (BpDnsResolver::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("in_listener", ::android::internal::ToString(in_listener));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::aidl::android::net::resolv::aidl::IDnsResolverUnsolicitedEventListener::writeToParcel(_aidl_in.get(), in_listener);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 12 /*registerUnsolicitedEventListener*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IDnsResolver::getDefaultImpl()) {
    _aidl_status = IDnsResolver::getDefaultImpl()->registerUnsolicitedEventListener(in_listener);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  if (BpDnsResolver::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.IDnsResolver";
    _transaction_log.method_name = "registerUnsolicitedEventListener";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
    _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
    _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
    _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
    BpDnsResolver::logFunc(_transaction_log);
  }
  return _aidl_status;
}
::ndk::ScopedAStatus BpDnsResolver::setResolverOptions(int32_t in_netId, const ::aidl::android::net::ResolverOptionsParcel& in_optionParams) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  BpDnsResolver::TransactionLog _transaction_log;
  if (BpDnsResolver::logFunc != nullptr) {
    _transaction_log.input_args.emplace_back("in_netId", ::android::internal::ToString(in_netId));
    _transaction_log.input_args.emplace_back("in_optionParams", ::android::internal::ToString(in_optionParams));
  }
  auto _log_start = std::chrono::steady_clock::now();
  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_netId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeParcelable(_aidl_in.get(), in_optionParams);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 13 /*setResolverOptions*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IDnsResolver::getDefaultImpl()) {
    _aidl_status = IDnsResolver::getDefaultImpl()->setResolverOptions(in_netId, in_optionParams);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  if (BpDnsResolver::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.IDnsResolver";
    _transaction_log.method_name = "setResolverOptions";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
    _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
    _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
    _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
    BpDnsResolver::logFunc(_transaction_log);
  }
  return _aidl_status;
}
::ndk::ScopedAStatus BpDnsResolver::getInterfaceVersion(int32_t* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  if (_aidl_cached_version != -1) {
    *_aidl_return = _aidl_cached_version;
    _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
    return _aidl_status;
  }
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  BpDnsResolver::TransactionLog _transaction_log;
  if (BpDnsResolver::logFunc != nullptr) {
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
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IDnsResolver::getDefaultImpl()) {
    _aidl_status = IDnsResolver::getDefaultImpl()->getInterfaceVersion(_aidl_return);
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
  if (BpDnsResolver::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.IDnsResolver";
    _transaction_log.method_name = "getInterfaceVersion";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
    _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
    _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
    _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
    _transaction_log.result = ::android::internal::ToString(*_aidl_return);
    BpDnsResolver::logFunc(_transaction_log);
  }
  return _aidl_status;
}
::ndk::ScopedAStatus BpDnsResolver::getInterfaceHash(std::string* _aidl_return) {
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

  BpDnsResolver::TransactionLog _transaction_log;
  if (BpDnsResolver::logFunc != nullptr) {
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
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IDnsResolver::getDefaultImpl()) {
    _aidl_status = IDnsResolver::getDefaultImpl()->getInterfaceHash(_aidl_return);
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
  if (BpDnsResolver::logFunc != nullptr) {
    auto _log_end = std::chrono::steady_clock::now();
    _transaction_log.duration_ms = std::chrono::duration<double, std::milli>(_log_end - _log_start).count();
    _transaction_log.interface_name = "android.net.IDnsResolver";
    _transaction_log.method_name = "getInterfaceHash";
    _transaction_log.stub_address = nullptr;
    _transaction_log.proxy_address = static_cast<const void*>(this);
    _transaction_log.exception_code = AStatus_getExceptionCode(_aidl_status.get());
    _transaction_log.exception_message = AStatus_getMessage(_aidl_status.get());
    _transaction_log.transaction_error = AStatus_getStatus(_aidl_status.get());
    _transaction_log.service_specific_error_code = AStatus_getServiceSpecificError(_aidl_status.get());
    _transaction_log.result = ::android::internal::ToString(*_aidl_return);
    BpDnsResolver::logFunc(_transaction_log);
  }
  return _aidl_status;
}
// Source for BnDnsResolver
BnDnsResolver::BnDnsResolver() {}
BnDnsResolver::~BnDnsResolver() {}
std::function<void(const BnDnsResolver::TransactionLog&)> BnDnsResolver::logFunc;
::ndk::SpAIBinder BnDnsResolver::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
::ndk::ScopedAStatus BnDnsResolver::getInterfaceVersion(int32_t* _aidl_return) {
  *_aidl_return = IDnsResolver::version;
  return ::ndk::ScopedAStatus(AStatus_newOk());
}
::ndk::ScopedAStatus BnDnsResolver::getInterfaceHash(std::string* _aidl_return) {
  *_aidl_return = IDnsResolver::hash;
  return ::ndk::ScopedAStatus(AStatus_newOk());
}
// Source for IDnsResolver
const char* IDnsResolver::descriptor = "android.net.IDnsResolver";
IDnsResolver::IDnsResolver() {}
IDnsResolver::~IDnsResolver() {}


std::shared_ptr<IDnsResolver> IDnsResolver::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IDnsResolver>(interface);
  }
  return ::ndk::SharedRefBase::make<BpDnsResolver>(binder);
}

binder_status_t IDnsResolver::writeToParcel(AParcel* parcel, const std::shared_ptr<IDnsResolver>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IDnsResolver::readFromParcel(const AParcel* parcel, std::shared_ptr<IDnsResolver>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IDnsResolver::fromBinder(binder);
  return STATUS_OK;
}
bool IDnsResolver::setDefaultImpl(const std::shared_ptr<IDnsResolver>& impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IDnsResolver::default_impl);
  if (impl) {
    IDnsResolver::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IDnsResolver>& IDnsResolver::getDefaultImpl() {
  return IDnsResolver::default_impl;
}
std::shared_ptr<IDnsResolver> IDnsResolver::default_impl = nullptr;
::ndk::ScopedAStatus IDnsResolverDefault::isAlive(bool* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IDnsResolverDefault::registerEventListener(const std::shared_ptr<::aidl::android::net::metrics::INetdEventListener>& /*in_listener*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IDnsResolverDefault::setResolverConfiguration(const ::aidl::android::net::ResolverParamsParcel& /*in_resolverParams*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IDnsResolverDefault::getResolverInfo(int32_t /*in_netId*/, std::vector<std::string>* /*out_servers*/, std::vector<std::string>* /*out_domains*/, std::vector<std::string>* /*out_tlsServers*/, std::vector<int32_t>* /*out_params*/, std::vector<int32_t>* /*out_stats*/, std::vector<int32_t>* /*out_wait_for_pending_req_timeout_count*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IDnsResolverDefault::startPrefix64Discovery(int32_t /*in_netId*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IDnsResolverDefault::stopPrefix64Discovery(int32_t /*in_netId*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IDnsResolverDefault::getPrefix64(int32_t /*in_netId*/, std::string* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IDnsResolverDefault::createNetworkCache(int32_t /*in_netId*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IDnsResolverDefault::destroyNetworkCache(int32_t /*in_netId*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IDnsResolverDefault::setLogSeverity(int32_t /*in_logSeverity*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IDnsResolverDefault::flushNetworkCache(int32_t /*in_netId*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IDnsResolverDefault::setPrefix64(int32_t /*in_netId*/, const std::string& /*in_prefix*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IDnsResolverDefault::registerUnsolicitedEventListener(const std::shared_ptr<::aidl::android::net::resolv::aidl::IDnsResolverUnsolicitedEventListener>& /*in_listener*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IDnsResolverDefault::setResolverOptions(int32_t /*in_netId*/, const ::aidl::android::net::ResolverOptionsParcel& /*in_optionParams*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IDnsResolverDefault::getInterfaceVersion(int32_t* _aidl_return) {
  *_aidl_return = 0;
  return ::ndk::ScopedAStatus(AStatus_newOk());
}
::ndk::ScopedAStatus IDnsResolverDefault::getInterfaceHash(std::string* _aidl_return) {
  *_aidl_return = "";
  return ::ndk::ScopedAStatus(AStatus_newOk());
}
::ndk::SpAIBinder IDnsResolverDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IDnsResolverDefault::isRemote() {
  return false;
}
}  // namespace net
}  // namespace android
}  // namespace aidl
