#include <android/net/resolv/aidl/IDnsResolverUnsolicitedEventListener.h>
#include <android/net/resolv/aidl/BpDnsResolverUnsolicitedEventListener.h>

namespace android {

namespace net {

namespace resolv {

namespace aidl {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(DnsResolverUnsolicitedEventListener, "android.net.resolv.aidl.IDnsResolverUnsolicitedEventListener")

}  // namespace aidl

}  // namespace resolv

}  // namespace net

}  // namespace android
#include <android/net/resolv/aidl/BpDnsResolverUnsolicitedEventListener.h>
#include <android/net/resolv/aidl/BnDnsResolverUnsolicitedEventListener.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace net {

namespace resolv {

namespace aidl {

BpDnsResolverUnsolicitedEventListener::BpDnsResolverUnsolicitedEventListener(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IDnsResolverUnsolicitedEventListener>(_aidl_impl){
}

::android::binder::Status BpDnsResolverUnsolicitedEventListener::onDnsHealthEvent(const ::android::net::resolv::aidl::DnsHealthEventParcel& dnsHealthEvent) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(dnsHealthEvent);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnDnsResolverUnsolicitedEventListener::TRANSACTION_onDnsHealthEvent, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IDnsResolverUnsolicitedEventListener::getDefaultImpl())) {
     return IDnsResolverUnsolicitedEventListener::getDefaultImpl()->onDnsHealthEvent(dnsHealthEvent);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpDnsResolverUnsolicitedEventListener::onNat64PrefixEvent(const ::android::net::resolv::aidl::Nat64PrefixEventParcel& nat64PrefixEvent) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(nat64PrefixEvent);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnDnsResolverUnsolicitedEventListener::TRANSACTION_onNat64PrefixEvent, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IDnsResolverUnsolicitedEventListener::getDefaultImpl())) {
     return IDnsResolverUnsolicitedEventListener::getDefaultImpl()->onNat64PrefixEvent(nat64PrefixEvent);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpDnsResolverUnsolicitedEventListener::onPrivateDnsValidationEvent(const ::android::net::resolv::aidl::PrivateDnsValidationEventParcel& privateDnsValidationEvent) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(privateDnsValidationEvent);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnDnsResolverUnsolicitedEventListener::TRANSACTION_onPrivateDnsValidationEvent, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IDnsResolverUnsolicitedEventListener::getDefaultImpl())) {
     return IDnsResolverUnsolicitedEventListener::getDefaultImpl()->onPrivateDnsValidationEvent(privateDnsValidationEvent);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

int32_t BpDnsResolverUnsolicitedEventListener::getInterfaceVersion() {
  if (cached_version_ == -1) {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(BnDnsResolverUnsolicitedEventListener::TRANSACTION_getInterfaceVersion, data, &reply);
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

std::string BpDnsResolverUnsolicitedEventListener::getInterfaceHash() {
  std::lock_guard<std::mutex> lockGuard(cached_hash_mutex_);
  if (cached_hash_ == "-1") {
    ::android::Parcel data;
    ::android::Parcel reply;
    data.writeInterfaceToken(getInterfaceDescriptor());
    ::android::status_t err = remote()->transact(BnDnsResolverUnsolicitedEventListener::TRANSACTION_getInterfaceHash, data, &reply);
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

}  // namespace aidl

}  // namespace resolv

}  // namespace net

}  // namespace android
#include <android/net/resolv/aidl/BnDnsResolverUnsolicitedEventListener.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace net {

namespace resolv {

namespace aidl {

BnDnsResolverUnsolicitedEventListener::BnDnsResolverUnsolicitedEventListener()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnDnsResolverUnsolicitedEventListener::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnDnsResolverUnsolicitedEventListener::TRANSACTION_onDnsHealthEvent:
  {
    ::android::net::resolv::aidl::DnsHealthEventParcel in_dnsHealthEvent;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_dnsHealthEvent);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onDnsHealthEvent(in_dnsHealthEvent));
  }
  break;
  case BnDnsResolverUnsolicitedEventListener::TRANSACTION_onNat64PrefixEvent:
  {
    ::android::net::resolv::aidl::Nat64PrefixEventParcel in_nat64PrefixEvent;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_nat64PrefixEvent);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onNat64PrefixEvent(in_nat64PrefixEvent));
  }
  break;
  case BnDnsResolverUnsolicitedEventListener::TRANSACTION_onPrivateDnsValidationEvent:
  {
    ::android::net::resolv::aidl::PrivateDnsValidationEventParcel in_privateDnsValidationEvent;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_privateDnsValidationEvent);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onPrivateDnsValidationEvent(in_privateDnsValidationEvent));
  }
  break;
  case BnDnsResolverUnsolicitedEventListener::TRANSACTION_getInterfaceVersion:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeInt32(IDnsResolverUnsolicitedEventListener::VERSION);
  }
  break;
  case BnDnsResolverUnsolicitedEventListener::TRANSACTION_getInterfaceHash:
  {
    _aidl_data.checkInterface(this);
    _aidl_reply->writeNoException();
    _aidl_reply->writeUtf8AsUtf16(IDnsResolverUnsolicitedEventListener::HASH);
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

int32_t BnDnsResolverUnsolicitedEventListener::getInterfaceVersion() {
  return IDnsResolverUnsolicitedEventListener::VERSION;
}

std::string BnDnsResolverUnsolicitedEventListener::getInterfaceHash() {
  return IDnsResolverUnsolicitedEventListener::HASH;
}

}  // namespace aidl

}  // namespace resolv

}  // namespace net

}  // namespace android
