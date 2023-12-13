#pragma once

#include <android/apex/ApexInfo.h>
#include <android/apex/ApexInfoList.h>
#include <android/apex/ApexSessionInfo.h>
#include <android/apex/ApexSessionParams.h>
#include <android/apex/CompressedApexInfoList.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace apex {

class IApexService : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(ApexService)
  virtual ::android::binder::Status submitStagedSession(const ::android::apex::ApexSessionParams& params, ::android::apex::ApexInfoList* packages) = 0;
  virtual ::android::binder::Status markStagedSessionReady(int32_t session_id) = 0;
  virtual ::android::binder::Status markStagedSessionSuccessful(int32_t session_id) = 0;
  virtual ::android::binder::Status getSessions(::std::vector<::android::apex::ApexSessionInfo>* _aidl_return) = 0;
  virtual ::android::binder::Status getStagedSessionInfo(int32_t session_id, ::android::apex::ApexSessionInfo* _aidl_return) = 0;
  virtual ::android::binder::Status getActivePackages(::std::vector<::android::apex::ApexInfo>* _aidl_return) = 0;
  virtual ::android::binder::Status getAllPackages(::std::vector<::android::apex::ApexInfo>* _aidl_return) = 0;
  virtual ::android::binder::Status abortStagedSession(int32_t session_id) = 0;
  virtual ::android::binder::Status revertActiveSessions() = 0;
  virtual ::android::binder::Status snapshotCeData(int32_t user_id, int32_t rollback_id, const ::std::string& apex_name) = 0;
  virtual ::android::binder::Status restoreCeData(int32_t user_id, int32_t rollback_id, const ::std::string& apex_name) = 0;
  virtual ::android::binder::Status destroyDeSnapshots(int32_t rollback_id) = 0;
  virtual ::android::binder::Status destroyCeSnapshots(int32_t user_id, int32_t rollback_id) = 0;
  virtual ::android::binder::Status destroyCeSnapshotsNotSpecified(int32_t user_id, const ::std::vector<int32_t>& retain_rollback_ids) = 0;
  virtual ::android::binder::Status unstagePackages(const ::std::vector<::std::string>& active_package_paths) = 0;
  virtual ::android::binder::Status getActivePackage(const ::std::string& package_name, ::android::apex::ApexInfo* _aidl_return) = 0;
  virtual ::android::binder::Status activatePackage(const ::std::string& package_path) = 0;
  virtual ::android::binder::Status deactivatePackage(const ::std::string& package_path) = 0;
  virtual ::android::binder::Status preinstallPackages(const ::std::vector<::std::string>& package_tmp_paths) = 0;
  virtual ::android::binder::Status postinstallPackages(const ::std::vector<::std::string>& package_tmp_paths) = 0;
  virtual ::android::binder::Status stagePackages(const ::std::vector<::std::string>& package_tmp_paths) = 0;
  virtual ::android::binder::Status resumeRevertIfNeeded() = 0;
  virtual ::android::binder::Status remountPackages() = 0;
  virtual ::android::binder::Status recollectPreinstalledData(const ::std::vector<::std::string>& paths) = 0;
  virtual ::android::binder::Status recollectDataApex(const ::std::string& path, const ::std::string& decompression_dir) = 0;
  virtual ::android::binder::Status markBootCompleted() = 0;
  virtual ::android::binder::Status calculateSizeForCompressedApex(const ::android::apex::CompressedApexInfoList& compressed_apex_info_list, int64_t* _aidl_return) = 0;
  virtual ::android::binder::Status reserveSpaceForCompressedApex(const ::android::apex::CompressedApexInfoList& compressed_apex_info_list) = 0;
  virtual ::android::binder::Status installAndActivatePackage(const ::std::string& packagePath, ::android::apex::ApexInfo* _aidl_return) = 0;
};  // class IApexService

class IApexServiceDefault : public IApexService {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status submitStagedSession(const ::android::apex::ApexSessionParams&, ::android::apex::ApexInfoList*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status markStagedSessionReady(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status markStagedSessionSuccessful(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getSessions(::std::vector<::android::apex::ApexSessionInfo>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getStagedSessionInfo(int32_t, ::android::apex::ApexSessionInfo*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getActivePackages(::std::vector<::android::apex::ApexInfo>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getAllPackages(::std::vector<::android::apex::ApexInfo>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status abortStagedSession(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status revertActiveSessions() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status snapshotCeData(int32_t, int32_t, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status restoreCeData(int32_t, int32_t, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status destroyDeSnapshots(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status destroyCeSnapshots(int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status destroyCeSnapshotsNotSpecified(int32_t, const ::std::vector<int32_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status unstagePackages(const ::std::vector<::std::string>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getActivePackage(const ::std::string&, ::android::apex::ApexInfo*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status activatePackage(const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status deactivatePackage(const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status preinstallPackages(const ::std::vector<::std::string>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status postinstallPackages(const ::std::vector<::std::string>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status stagePackages(const ::std::vector<::std::string>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status resumeRevertIfNeeded() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status remountPackages() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status recollectPreinstalledData(const ::std::vector<::std::string>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status recollectDataApex(const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status markBootCompleted() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status calculateSizeForCompressedApex(const ::android::apex::CompressedApexInfoList&, int64_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status reserveSpaceForCompressedApex(const ::android::apex::CompressedApexInfoList&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status installAndActivatePackage(const ::std::string&, ::android::apex::ApexInfo*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IApexServiceDefault

}  // namespace apex

}  // namespace android
