/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_APEXD_APEXD_H_
#define ANDROID_APEXD_APEXD_H_

#include <ostream>
#include <string>
#include <vector>

#include <android-base/macros.h>
#include <android-base/result.h>

#include "apex_constants.h"
#include "apex_database.h"
#include "apex_file.h"
#include "apex_file_repository.h"
#include "apexd_session.h"

namespace android {
namespace apex {

// A structure containing all the values that might need to be injected for
// testing (e.g. apexd status property, etc.)
//
// Ideally we want to introduce Apexd class and use dependency injection for
// such values, but that will require a sizeable refactoring. For the time being
// this config should do the trick.
struct ApexdConfig {
  const char* apex_status_sysprop;
  std::vector<std::string> apex_built_in_dirs;
  const char* active_apex_data_dir;
  const char* decompression_dir;
  const char* ota_reserved_dir;
  const char* apex_hash_tree_dir;
  const char* staged_session_dir;
};

static const ApexdConfig kDefaultConfig = {
    kApexStatusSysprop,   kApexPackageBuiltinDirs, kActiveApexPackagesDataDir,
    kApexDecompressedDir, kOtaReservedDir,         kApexHashTreeDir,
    kStagedSessionsDir,
};

class CheckpointInterface;

void SetConfig(const ApexdConfig& config);

// Exposed only for testing.
android::base::Result<void> Unmount(
    const MountedApexDatabase::MountedApexData& data, bool deferred);

android::base::Result<void> ResumeRevertIfNeeded();

android::base::Result<void> PreinstallPackages(
    const std::vector<std::string>& paths) WARN_UNUSED;
android::base::Result<void> PostinstallPackages(
    const std::vector<std::string>& paths) WARN_UNUSED;

android::base::Result<void> StagePackages(
    const std::vector<std::string>& tmpPaths) WARN_UNUSED;
android::base::Result<void> UnstagePackages(
    const std::vector<std::string>& paths) WARN_UNUSED;

android::base::Result<std::vector<ApexFile>> SubmitStagedSession(
    const int session_id, const std::vector<int>& child_session_ids,
    const bool has_rollback_enabled, const bool is_rollback,
    const int rollback_id) WARN_UNUSED;
android::base::Result<void> MarkStagedSessionReady(const int session_id)
    WARN_UNUSED;
android::base::Result<void> MarkStagedSessionSuccessful(const int session_id)
    WARN_UNUSED;
// Only only of the parameters should be passed during revert
android::base::Result<void> RevertActiveSessions(
    const std::string& crashing_native_process,
    const std::string& error_message);
// Only only of the parameters should be passed during revert
android::base::Result<void> RevertActiveSessionsAndReboot(
    const std::string& crashing_native_process,
    const std::string& error_message);

android::base::Result<void> ActivatePackage(const std::string& full_path)
    WARN_UNUSED;
android::base::Result<void> DeactivatePackage(const std::string& full_path)
    WARN_UNUSED;

std::vector<ApexFile> GetActivePackages();
android::base::Result<ApexFile> GetActivePackage(
    const std::string& package_name);

std::vector<ApexFile> GetFactoryPackages();

android::base::Result<void> AbortStagedSession(const int session_id);

android::base::Result<void> SnapshotCeData(const int user_id,
                                           const int rollback_id,
                                           const std::string& apex_name);
android::base::Result<void> RestoreCeData(const int user_id,
                                          const int rollback_id,
                                          const std::string& apex_name);

android::base::Result<void> DestroyDeSnapshots(const int rollback_id);
android::base::Result<void> DestroyCeSnapshots(const int user_id,
                                               const int rollback_id);
android::base::Result<void> DestroyCeSnapshotsNotSpecified(
    int user_id, const std::vector<int>& retain_rollback_ids);

int OnBootstrap();
// Sets the values of gVoldService and gInFsCheckpointMode.
void InitializeVold(CheckpointInterface* checkpoint_service);
// Initializes in-memory state (e.g. pre-installed data, activated apexes).
// Must be called first before calling any other boot sequence related function.
void Initialize(CheckpointInterface* checkpoint_service);
// Initializes data apex as in-memory state. Should be called only if we are
// not booting, since initialization timing is different when booting
void InitializeDataApex();
// Migrates sessions from /data/apex/session to /metadata/session.i
// Must only be called during boot (i.e apexd.status is not "ready" or
// "activated").
android::base::Result<void> MigrateSessionsDirIfNeeded();
// Apex activation logic. Scans staged apex sessions and activates apexes.
// Must only be called during boot (i.e apexd.status is not "ready" or
// "activated").
void OnStart();
// For every package X, there can be at most two APEX, pre-installed vs
// installed on data. We decide which ones should be activated and return them
// as a list
std::vector<ApexFileRef> SelectApexForActivation(
    const std::unordered_map<std::string, std::vector<ApexFileRef>>& all_apex,
    const ApexFileRepository& instance);
std::vector<ApexFile> ProcessCompressedApex(
    const std::vector<ApexFileRef>& compressed_apex, bool is_ota_chroot);
// Validate |apex| is same as |capex|
android::base::Result<void> ValidateDecompressedApex(const ApexFile& capex,
                                                     const ApexFile& apex);
// Notifies system that apexes are activated by setting apexd.status property to
// "activated".
// Must only be called during boot (i.e. apexd.status is not "ready" or
// "activated").
void OnAllPackagesActivated(bool is_bootstrap);
// Notifies system that apexes are ready by setting apexd.status property to
// "ready".
// Must only be called during boot (i.e. apexd.status is not "ready" or
// "activated").
void OnAllPackagesReady();
void OnBootCompleted();
// Exposed for testing
void RemoveInactiveDataApex();
void BootCompletedCleanup();
int SnapshotOrRestoreDeUserData();

int UnmountAll();

android::base::Result<MountedApexDatabase::MountedApexData>
GetTempMountedApexData(const std::string& package);

// Optimistically tries to remount as many APEX packages as possible.
// For more documentation see corresponding binder call in IApexService.aidl.
android::base::Result<void> RemountPackages();

// Exposed for unit tests
android::base::Result<bool> ShouldAllocateSpaceForDecompression(
    const std::string& new_apex_name, int64_t new_apex_version,
    const ApexFileRepository& instance);

void CollectApexInfoList(std::ostream& os,
                         const std::vector<ApexFile>& active_apexs,
                         const std::vector<ApexFile>& inactive_apexs);

// Reserve |size| bytes in |dest_dir| by creating a zero-filled file
android::base::Result<void> ReserveSpaceForCompressedApex(
    int64_t size, const std::string& dest_dir);

// Activates apexes in otapreot_chroot environment.
// TODO(b/172911822): support compressed apexes.
int OnOtaChrootBootstrap();

// Activates flattened apexes in otapreopt_chroot environment.
int OnOtaChrootBootstrapFlattenedApex();

android::apex::MountedApexDatabase& GetApexDatabaseForTesting();

// Performs a non-staged install of an APEX specified by |package_path|.
// TODO(ioffe): add more documentation.
android::base::Result<ApexFile> InstallPackage(const std::string& package_path);

}  // namespace apex
}  // namespace android

#endif  // ANDROID_APEXD_APEXD_H_
