#include <android/binder_parcel_utils.h>
#include <aidl/android/media/BpResourceObserver.h>
#include <aidl/android/media/BnResourceObserver.h>
#include <aidl/android/media/IResourceObserver.h>

namespace aidl {
namespace android {
namespace media {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnResourceObserver> _aidl_impl = std::static_pointer_cast<BnResourceObserver>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*onStatusChanged*/): {
      ::aidl::android::media::MediaObservableEvent in_event;
      int32_t in_uid;
      int32_t in_pid;
      std::vector<::aidl::android::media::MediaObservableParcel> in_observables;

      _aidl_ret_status = AParcel_readInt64(_aidl_in, reinterpret_cast<int64_t*>(&in_event));
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_uid);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_pid);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_observables);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onStatusChanged(in_event, in_uid, in_pid, in_observables);
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 16777214 /*getInterfaceVersion*/): {
      int32_t _aidl_return;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->getInterfaceVersion(&_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = AParcel_writeInt32(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 16777213 /*getInterfaceHash*/): {
      std::string _aidl_return;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->getInterfaceHash(&_aidl_return);
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

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IResourceObserver::descriptor, _aidl_onTransact);

BpResourceObserver::BpResourceObserver(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpResourceObserver::~BpResourceObserver() {}

::ndk::ScopedAStatus BpResourceObserver::onStatusChanged(::aidl::android::media::MediaObservableEvent in_event, int32_t in_uid, int32_t in_pid, const std::vector<::aidl::android::media::MediaObservableParcel>& in_observables) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt64(_aidl_in.get(), static_cast<int64_t>(in_event));
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_uid);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_pid);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_observables);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*onStatusChanged*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IResourceObserver::getDefaultImpl()) {
    _aidl_status = IResourceObserver::getDefaultImpl()->onStatusChanged(in_event, in_uid, in_pid, in_observables);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpResourceObserver::getInterfaceVersion(int32_t* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  if (_aidl_cached_version != -1) {
    *_aidl_return = _aidl_cached_version;
    _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
    return _aidl_status;
  }
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

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
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IResourceObserver::getDefaultImpl()) {
    _aidl_status = IResourceObserver::getDefaultImpl()->getInterfaceVersion(_aidl_return);
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
  return _aidl_status;
}
::ndk::ScopedAStatus BpResourceObserver::getInterfaceHash(std::string* _aidl_return) {
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
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IResourceObserver::getDefaultImpl()) {
    _aidl_status = IResourceObserver::getDefaultImpl()->getInterfaceHash(_aidl_return);
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
  return _aidl_status;
}
// Source for BnResourceObserver
BnResourceObserver::BnResourceObserver() {}
BnResourceObserver::~BnResourceObserver() {}
::ndk::SpAIBinder BnResourceObserver::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
::ndk::ScopedAStatus BnResourceObserver::getInterfaceVersion(int32_t* _aidl_return) {
  *_aidl_return = IResourceObserver::version;
  return ::ndk::ScopedAStatus(AStatus_newOk());
}
::ndk::ScopedAStatus BnResourceObserver::getInterfaceHash(std::string* _aidl_return) {
  *_aidl_return = IResourceObserver::hash;
  return ::ndk::ScopedAStatus(AStatus_newOk());
}
// Source for IResourceObserver
const char* IResourceObserver::descriptor = "android.media.IResourceObserver";
IResourceObserver::IResourceObserver() {}
IResourceObserver::~IResourceObserver() {}


std::shared_ptr<IResourceObserver> IResourceObserver::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IResourceObserver>(interface);
  }
  return ::ndk::SharedRefBase::make<BpResourceObserver>(binder);
}

binder_status_t IResourceObserver::writeToParcel(AParcel* parcel, const std::shared_ptr<IResourceObserver>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IResourceObserver::readFromParcel(const AParcel* parcel, std::shared_ptr<IResourceObserver>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IResourceObserver::fromBinder(binder);
  return STATUS_OK;
}
bool IResourceObserver::setDefaultImpl(const std::shared_ptr<IResourceObserver>& impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IResourceObserver::default_impl);
  if (impl) {
    IResourceObserver::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IResourceObserver>& IResourceObserver::getDefaultImpl() {
  return IResourceObserver::default_impl;
}
std::shared_ptr<IResourceObserver> IResourceObserver::default_impl = nullptr;
::ndk::ScopedAStatus IResourceObserverDefault::onStatusChanged(::aidl::android::media::MediaObservableEvent /*in_event*/, int32_t /*in_uid*/, int32_t /*in_pid*/, const std::vector<::aidl::android::media::MediaObservableParcel>& /*in_observables*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IResourceObserverDefault::getInterfaceVersion(int32_t* _aidl_return) {
  *_aidl_return = 0;
  return ::ndk::ScopedAStatus(AStatus_newOk());
}
::ndk::ScopedAStatus IResourceObserverDefault::getInterfaceHash(std::string* _aidl_return) {
  *_aidl_return = "";
  return ::ndk::ScopedAStatus(AStatus_newOk());
}
::ndk::SpAIBinder IResourceObserverDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IResourceObserverDefault::isRemote() {
  return false;
}
}  // namespace media
}  // namespace android
}  // namespace aidl
