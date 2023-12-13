#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/apex/IApexService.h>

namespace android {

namespace apex {

class BpApexService : public ::android::BpInterface<IApexService> {
public:
  explicit BpApexService(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpApexService() = default;
  ::android::binder::Status submitStagedSession(const ::android::apex::ApexSessionParams& params, ::android::apex::ApexInfoList* packages) override;
  ::android::binder::Status markStagedSessionReady(int32_t session_id) override;
  ::android::binder::Status markStagedSessionSuccessful(int32_t session_id) override;
  ::android::binder::Status getSessions(::std::vector<::android::apex::ApexSessionInfo>* _aidl_return) override;
  ::android::binder::Status getStagedSessionInfo(int32_t session_id, ::android::apex::ApexSessionInfo* _aidl_return) override;
  ::android::binder::Status getActivePackages(::std::vector<::android::apex::ApexInfo>* _aidl_return) override;
  ::android::binder::Status getAllPackages(::std::vector<::android::apex::ApexInfo>* _aidl_return) override;
  ::android::binder::Status abortStagedSession(int32_t session_id) override;
  ::android::binder::Status revertActiveSessions() override;
  ::android::binder::Status snapshotCeData(int32_t user_id, int32_t rollback_id, const ::std::string& apex_name) override;
  ::android::binder::Status restoreCeData(int32_t user_id, int32_t rollback_id, const ::std::string& apex_name) override;
  ::android::binder::Status destroyDeSnapshots(int32_t rollback_id) override;
  ::android::binder::Status destroyCeSnapshots(int32_t user_id, int32_t rollback_id) override;
  ::android::binder::Status destroyCeSnapshotsNotSpecified(int32_t user_id, const ::std::vector<int32_t>& retain_rollback_ids) override;
  ::android::binder::Status unstagePackages(const ::std::vector<::std::string>& active_package_paths) override;
  ::android::binder::Status getActivePackage(const ::std::string& package_name, ::android::apex::ApexInfo* _aidl_return) override;
  ::android::binder::Status activatePackage(const ::std::string& package_path) override;
  ::android::binder::Status deactivatePackage(const ::std::string& package_path) override;
  ::android::binder::Status preinstallPackages(const ::std::vector<::std::string>& package_tmp_paths) override;
  ::android::binder::Status postinstallPackages(const ::std::vector<::std::string>& package_tmp_paths) override;
  ::android::binder::Status stagePackages(const ::std::vector<::std::string>& package_tmp_paths) override;
  ::android::binder::Status resumeRevertIfNeeded() override;
  ::android::binder::Status remountPackages() override;
  ::android::binder::Status recollectPreinstalledData(const ::std::vector<::std::string>& paths) override;
  ::android::binder::Status recollectDataApex(const ::std::string& path, const ::std::string& decompression_dir) override;
  ::android::binder::Status markBootCompleted() override;
  ::android::binder::Status calculateSizeForCompressedApex(const ::android::apex::CompressedApexInfoList& compressed_apex_info_list, int64_t* _aidl_return) override;
  ::android::binder::Status reserveSpaceForCompressedApex(const ::android::apex::CompressedApexInfoList& compressed_apex_info_list) override;
  ::android::binder::Status installAndActivatePackage(const ::std::string& packagePath, ::android::apex::ApexInfo* _aidl_return) override;
};  // class BpApexService

}  // namespace apex

}  // namespace android
