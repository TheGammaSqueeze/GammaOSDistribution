#include <android/binder_parcel_utils.h>
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
  std::shared_ptr<BnTranscodingClientCallback> _aidl_impl = std::static_pointer_cast<BnTranscodingClientCallback>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*openFileDescriptor*/): {
      std::string in_fileUri;
      std::string in_mode;
      ::ndk::ScopedFileDescriptor _aidl_return;

      _aidl_ret_status = ::ndk::AParcel_readString(_aidl_in, &in_fileUri);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readString(_aidl_in, &in_mode);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->openFileDescriptor(in_fileUri, in_mode, &_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeRequiredParcelFileDescriptor(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*onTranscodingStarted*/): {
      int32_t in_sessionId;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_sessionId);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onTranscodingStarted(in_sessionId);
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 2 /*onTranscodingPaused*/): {
      int32_t in_sessionId;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_sessionId);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onTranscodingPaused(in_sessionId);
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 3 /*onTranscodingResumed*/): {
      int32_t in_sessionId;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_sessionId);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onTranscodingResumed(in_sessionId);
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 4 /*onTranscodingFinished*/): {
      int32_t in_sessionId;
      ::aidl::android::media::TranscodingResultParcel in_result;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_sessionId);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readParcelable(_aidl_in, &in_result);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onTranscodingFinished(in_sessionId, in_result);
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 5 /*onTranscodingFailed*/): {
      int32_t in_sessionId;
      ::aidl::android::media::TranscodingErrorCode in_errorCode;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_sessionId);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, reinterpret_cast<int32_t*>(&in_errorCode));
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onTranscodingFailed(in_sessionId, in_errorCode);
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 6 /*onAwaitNumberOfSessionsChanged*/): {
      int32_t in_sessionId;
      int32_t in_oldAwaitNumber;
      int32_t in_newAwaitNumber;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_sessionId);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_oldAwaitNumber);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_newAwaitNumber);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onAwaitNumberOfSessionsChanged(in_sessionId, in_oldAwaitNumber, in_newAwaitNumber);
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 7 /*onProgressUpdate*/): {
      int32_t in_sessionId;
      int32_t in_progress;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_sessionId);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_progress);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onProgressUpdate(in_sessionId, in_progress);
      _aidl_ret_status = STATUS_OK;
      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(ITranscodingClientCallback::descriptor, _aidl_onTransact);

BpTranscodingClientCallback::BpTranscodingClientCallback(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpTranscodingClientCallback::~BpTranscodingClientCallback() {}

::ndk::ScopedAStatus BpTranscodingClientCallback::openFileDescriptor(const std::string& in_fileUri, const std::string& in_mode, ::ndk::ScopedFileDescriptor* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeString(_aidl_in.get(), in_fileUri);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeString(_aidl_in.get(), in_mode);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*openFileDescriptor*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ITranscodingClientCallback::getDefaultImpl()) {
    _aidl_status = ITranscodingClientCallback::getDefaultImpl()->openFileDescriptor(in_fileUri, in_mode, _aidl_return);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) goto _aidl_status_return;
  _aidl_ret_status = ::ndk::AParcel_readRequiredParcelFileDescriptor(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpTranscodingClientCallback::onTranscodingStarted(int32_t in_sessionId) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_sessionId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*onTranscodingStarted*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ITranscodingClientCallback::getDefaultImpl()) {
    _aidl_status = ITranscodingClientCallback::getDefaultImpl()->onTranscodingStarted(in_sessionId);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpTranscodingClientCallback::onTranscodingPaused(int32_t in_sessionId) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_sessionId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 2 /*onTranscodingPaused*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ITranscodingClientCallback::getDefaultImpl()) {
    _aidl_status = ITranscodingClientCallback::getDefaultImpl()->onTranscodingPaused(in_sessionId);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpTranscodingClientCallback::onTranscodingResumed(int32_t in_sessionId) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_sessionId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 3 /*onTranscodingResumed*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ITranscodingClientCallback::getDefaultImpl()) {
    _aidl_status = ITranscodingClientCallback::getDefaultImpl()->onTranscodingResumed(in_sessionId);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpTranscodingClientCallback::onTranscodingFinished(int32_t in_sessionId, const ::aidl::android::media::TranscodingResultParcel& in_result) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_sessionId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeParcelable(_aidl_in.get(), in_result);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 4 /*onTranscodingFinished*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ITranscodingClientCallback::getDefaultImpl()) {
    _aidl_status = ITranscodingClientCallback::getDefaultImpl()->onTranscodingFinished(in_sessionId, in_result);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpTranscodingClientCallback::onTranscodingFailed(int32_t in_sessionId, ::aidl::android::media::TranscodingErrorCode in_errorCode) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_sessionId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), static_cast<int32_t>(in_errorCode));
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 5 /*onTranscodingFailed*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ITranscodingClientCallback::getDefaultImpl()) {
    _aidl_status = ITranscodingClientCallback::getDefaultImpl()->onTranscodingFailed(in_sessionId, in_errorCode);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpTranscodingClientCallback::onAwaitNumberOfSessionsChanged(int32_t in_sessionId, int32_t in_oldAwaitNumber, int32_t in_newAwaitNumber) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_sessionId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_oldAwaitNumber);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_newAwaitNumber);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 6 /*onAwaitNumberOfSessionsChanged*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ITranscodingClientCallback::getDefaultImpl()) {
    _aidl_status = ITranscodingClientCallback::getDefaultImpl()->onAwaitNumberOfSessionsChanged(in_sessionId, in_oldAwaitNumber, in_newAwaitNumber);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
::ndk::ScopedAStatus BpTranscodingClientCallback::onProgressUpdate(int32_t in_sessionId, int32_t in_progress) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_sessionId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_progress);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 7 /*onProgressUpdate*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ITranscodingClientCallback::getDefaultImpl()) {
    _aidl_status = ITranscodingClientCallback::getDefaultImpl()->onProgressUpdate(in_sessionId, in_progress);
    goto _aidl_status_return;
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  _aidl_status_return:
  return _aidl_status;
}
// Source for BnTranscodingClientCallback
BnTranscodingClientCallback::BnTranscodingClientCallback() {}
BnTranscodingClientCallback::~BnTranscodingClientCallback() {}
::ndk::SpAIBinder BnTranscodingClientCallback::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for ITranscodingClientCallback
const char* ITranscodingClientCallback::descriptor = "android.media.ITranscodingClientCallback";
ITranscodingClientCallback::ITranscodingClientCallback() {}
ITranscodingClientCallback::~ITranscodingClientCallback() {}


std::shared_ptr<ITranscodingClientCallback> ITranscodingClientCallback::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<ITranscodingClientCallback>(interface);
  }
  return ::ndk::SharedRefBase::make<BpTranscodingClientCallback>(binder);
}

binder_status_t ITranscodingClientCallback::writeToParcel(AParcel* parcel, const std::shared_ptr<ITranscodingClientCallback>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t ITranscodingClientCallback::readFromParcel(const AParcel* parcel, std::shared_ptr<ITranscodingClientCallback>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = ITranscodingClientCallback::fromBinder(binder);
  return STATUS_OK;
}
bool ITranscodingClientCallback::setDefaultImpl(const std::shared_ptr<ITranscodingClientCallback>& impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!ITranscodingClientCallback::default_impl);
  if (impl) {
    ITranscodingClientCallback::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<ITranscodingClientCallback>& ITranscodingClientCallback::getDefaultImpl() {
  return ITranscodingClientCallback::default_impl;
}
std::shared_ptr<ITranscodingClientCallback> ITranscodingClientCallback::default_impl = nullptr;
::ndk::ScopedAStatus ITranscodingClientCallbackDefault::openFileDescriptor(const std::string& /*in_fileUri*/, const std::string& /*in_mode*/, ::ndk::ScopedFileDescriptor* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus ITranscodingClientCallbackDefault::onTranscodingStarted(int32_t /*in_sessionId*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus ITranscodingClientCallbackDefault::onTranscodingPaused(int32_t /*in_sessionId*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus ITranscodingClientCallbackDefault::onTranscodingResumed(int32_t /*in_sessionId*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus ITranscodingClientCallbackDefault::onTranscodingFinished(int32_t /*in_sessionId*/, const ::aidl::android::media::TranscodingResultParcel& /*in_result*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus ITranscodingClientCallbackDefault::onTranscodingFailed(int32_t /*in_sessionId*/, ::aidl::android::media::TranscodingErrorCode /*in_errorCode*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus ITranscodingClientCallbackDefault::onAwaitNumberOfSessionsChanged(int32_t /*in_sessionId*/, int32_t /*in_oldAwaitNumber*/, int32_t /*in_newAwaitNumber*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus ITranscodingClientCallbackDefault::onProgressUpdate(int32_t /*in_sessionId*/, int32_t /*in_progress*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder ITranscodingClientCallbackDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool ITranscodingClientCallbackDefault::isRemote() {
  return false;
}
}  // namespace media
}  // namespace android
}  // namespace aidl
