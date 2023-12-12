#include <android/binder_parcel_utils.h>
#include <aidl/android/media/BpMediaTranscodingService.h>
#include <aidl/android/media/BnMediaTranscodingService.h>
#include <aidl/android/media/IMediaTranscodingService.h>
#include <aidl/android/media/BpTranscodingClient.h>
#include <aidl/android/media/BnTranscodingClient.h>
#include <aidl/android/media/ITranscodingClient.h>
#include <aidl/android/media/BpTranscodingClientCallback.h>
#include <aidl/android/media/BnTranscodingClientCallback.h>
#include <aidl/android/media/ITranscodingClientCallback.h>

namespace aidl {
namespace android {
namespace media {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnMediaTranscodingService> _aidl_impl = std::static_pointer_cast<BnMediaTranscodingService>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*registerClient*/): {
      std::shared_ptr<::aidl::android::media::ITranscodingClientCallback> in_callback;
      std::string in_clientName;
      std::string in_opPackageName;
      std::shared_ptr<::aidl::android::media::ITranscodingClient> _aidl_return;

      _aidl_ret_status = ::aidl::android::media::ITranscodingClientCallback::readFromParcel(_aidl_in, &in_callback);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readString(_aidl_in, &in_clientName);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readString(_aidl_in, &in_opPackageName);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->registerClient(in_callback, in_clientName, in_opPackageName, &_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::aidl::android::media::ITranscodingClient::writeToParcel(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*getNumOfClients*/): {
      int32_t _aidl_return;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->getNumOfClients(&_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = AParcel_writeInt32(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IMediaTranscodingService::descriptor, _aidl_onTransact);

BpMediaTranscodingService::BpMediaTranscodingService(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpMediaTranscodingService::~BpMediaTranscodingService() {}

::ndk::ScopedAStatus BpMediaTranscodingService::registerClient(const std::shared_ptr<::aidl::android::media::ITranscodingClientCallback>& in_callback, const std::string& in_clientName, const std::string& in_opPackageName, std::shared_ptr<::aidl::android::media::ITranscodingClient>* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::aidl::android::media::ITranscodingClientCallback::writeToParcel(_aidl_in.get(), in_callback);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeString(_aidl_in.get(), in_clientName);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeString(_aidl_in.get(), in_opPackageName);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*registerClient*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IMediaTranscodingService::getDefaultImpl()) {
    _aidl_status = IMediaTranscodingService::getDefaultImpl()->registerClient(in_callback, in_clientName, in_opPackageName, _aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = ::aidl::android::media::ITranscodingClient::readFromParcel(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpMediaTranscodingService::getNumOfClients(int32_t* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*getNumOfClients*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IMediaTranscodingService::getDefaultImpl()) {
    _aidl_status = IMediaTranscodingService::getDefaultImpl()->getNumOfClients(_aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = AParcel_readInt32(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
// Source for BnMediaTranscodingService
BnMediaTranscodingService::BnMediaTranscodingService() {}
BnMediaTranscodingService::~BnMediaTranscodingService() {}
::ndk::SpAIBinder BnMediaTranscodingService::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IMediaTranscodingService
const char* IMediaTranscodingService::descriptor = "android.media.IMediaTranscodingService";
IMediaTranscodingService::IMediaTranscodingService() {}
IMediaTranscodingService::~IMediaTranscodingService() {}


std::shared_ptr<IMediaTranscodingService> IMediaTranscodingService::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IMediaTranscodingService>(interface);
  }
  return ::ndk::SharedRefBase::make<BpMediaTranscodingService>(binder);
}

binder_status_t IMediaTranscodingService::writeToParcel(AParcel* parcel, const std::shared_ptr<IMediaTranscodingService>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IMediaTranscodingService::readFromParcel(const AParcel* parcel, std::shared_ptr<IMediaTranscodingService>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IMediaTranscodingService::fromBinder(binder);
  return STATUS_OK;
}
bool IMediaTranscodingService::setDefaultImpl(const std::shared_ptr<IMediaTranscodingService>& impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IMediaTranscodingService::default_impl);
  if (impl) {
    IMediaTranscodingService::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IMediaTranscodingService>& IMediaTranscodingService::getDefaultImpl() {
  return IMediaTranscodingService::default_impl;
}
std::shared_ptr<IMediaTranscodingService> IMediaTranscodingService::default_impl = nullptr;
::ndk::ScopedAStatus IMediaTranscodingServiceDefault::registerClient(const std::shared_ptr<::aidl::android::media::ITranscodingClientCallback>& /*in_callback*/, const std::string& /*in_clientName*/, const std::string& /*in_opPackageName*/, std::shared_ptr<::aidl::android::media::ITranscodingClient>* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IMediaTranscodingServiceDefault::getNumOfClients(int32_t* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IMediaTranscodingServiceDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IMediaTranscodingServiceDefault::isRemote() {
  return false;
}
}  // namespace media
}  // namespace android
}  // namespace aidl
