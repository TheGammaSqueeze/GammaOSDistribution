//
// Copyright (C) 2013 The Android Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef UPDATE_ENGINE_COMMON_CONSTANTS_H_
#define UPDATE_ENGINE_COMMON_CONSTANTS_H_

#include <cstdint>

namespace chromeos_update_engine {

// The root path of all exclusion prefs.
extern const char kExclusionPrefsSubDir[];

// The root path of all DLC metadata.
extern const char kDlcPrefsSubDir[];

// Directory for AU prefs that are preserved across powerwash.
extern const char kPowerwashSafePrefsSubDirectory[];

// The location where we store the AU preferences (state etc).
extern const char kPrefsSubDirectory[];

// Path to the post install command, relative to the partition.
extern const char kPostinstallDefaultScript[];

// Path to the stateful partition on the root filesystem.
extern const char kStatefulPartition[];

// Constants related to preferences.
extern const char kPrefsAttemptInProgress[];
extern const char kPrefsBackoffExpiryTime[];
extern const char kPrefsBootId[];
extern const char kPrefsCurrentBytesDownloaded[];
extern const char kPrefsCurrentResponseSignature[];
extern const char kPrefsCurrentUrlFailureCount[];
extern const char kPrefsCurrentUrlIndex[];
extern const char kPrefsDailyMetricsLastReportedAt[];
extern const char kPrefsDeltaUpdateFailures[];
extern const char kPrefsDynamicPartitionMetadataUpdated[];
extern const char kPrefsFullPayloadAttemptNumber[];
extern const char kPrefsInstallDateDays[];
extern const char kPrefsLastActivePingDay[];
extern const char kPrefsLastRollCallPingDay[];
extern const char kPrefsManifestMetadataSize[];
extern const char kPrefsManifestSignatureSize[];
extern const char kPrefsMetricsAttemptLastReportingTime[];
extern const char kPrefsMetricsCheckLastReportingTime[];
extern const char kPrefsNoIgnoreBackoff[];
extern const char kPrefsNumReboots[];
extern const char kPrefsNumResponsesSeen[];
extern const char kPrefsOmahaCohort[];
extern const char kPrefsOmahaCohortHint[];
extern const char kPrefsOmahaCohortName[];
extern const char kPrefsOmahaEolDate[];
extern const char kPrefsP2PEnabled[];
extern const char kPrefsP2PFirstAttemptTimestamp[];
extern const char kPrefsP2PNumAttempts[];
extern const char kPrefsPayloadAttemptNumber[];
extern const char kPrefsTestUpdateCheckIntervalTimeout[];
extern const char kPrefsPingActive[];
extern const char kPrefsPingLastActive[];
extern const char kPrefsPingLastRollcall[];
extern const char kPrefsLastFp[];
extern const char kPrefsPostInstallSucceeded[];
extern const char kPrefsPreviousVersion[];
extern const char kPrefsPreviousSlot[];
extern const char kPrefsResumedUpdateFailures[];
extern const char kPrefsRollbackHappened[];
extern const char kPrefsRollbackVersion[];
extern const char kPrefsChannelOnSlotPrefix[];
extern const char kPrefsSystemUpdatedMarker[];
extern const char kPrefsTargetVersionAttempt[];
extern const char kPrefsTargetVersionInstalledFrom[];
extern const char kPrefsTargetVersionUniqueId[];
extern const char kPrefsTotalBytesDownloaded[];
extern const char kPrefsUpdateCheckCount[];
extern const char kPrefsUpdateCheckResponseHash[];
extern const char kPrefsUpdateCompletedBootTime[];
extern const char kPrefsUpdateCompletedOnBootId[];
extern const char kPrefsUpdateDurationUptime[];
extern const char kPrefsUpdateFirstSeenAt[];
extern const char kPrefsUpdateOverCellularPermission[];
extern const char kPrefsUpdateOverCellularTargetVersion[];
extern const char kPrefsUpdateOverCellularTargetSize[];
extern const char kPrefsUpdateServerCertificate[];
extern const char kPrefsUpdateStateNextDataLength[];
extern const char kPrefsUpdateStateNextDataOffset[];
extern const char kPrefsUpdateStateNextOperation[];
extern const char kPrefsUpdateStatePayloadIndex[];
extern const char kPrefsUpdateStateSHA256Context[];
extern const char kPrefsUpdateStateSignatureBlob[];
extern const char kPrefsUpdateStateSignedSHA256Context[];
extern const char kPrefsUpdateBootTimestampStart[];
extern const char kPrefsUpdateTimestampStart[];
extern const char kPrefsUrlSwitchCount[];
extern const char kPrefsVerityWritten[];
extern const char kPrefsWallClockScatteringWaitPeriod[];
extern const char kPrefsWallClockStagingWaitPeriod[];
extern const char kPrefsManifestBytes[];

// Keys used when storing and loading payload properties.
extern const char kPayloadPropertyFileSize[];
extern const char kPayloadPropertyFileHash[];
extern const char kPayloadPropertyMetadataSize[];
extern const char kPayloadPropertyMetadataHash[];
extern const char kPayloadPropertyAuthorization[];
extern const char kPayloadPropertyUserAgent[];
extern const char kPayloadPropertyPowerwash[];
extern const char kPayloadPropertyNetworkId[];
extern const char kPayloadPropertySwitchSlotOnReboot[];
extern const char kPayloadPropertyRunPostInstall[];

extern const char kOmahaUpdaterVersion[];

// X-Goog-Update headers.
extern const char kXGoogleUpdateInteractivity[];
extern const char kXGoogleUpdateAppId[];
extern const char kXGoogleUpdateUpdater[];
extern const char kXGoogleUpdateSessionId[];

// A download source is any combination of protocol and server (that's of
// interest to us when looking at UMA metrics) using which we may download
// the payload.
typedef enum {
  kDownloadSourceHttpsServer,  // UMA Binary representation: 0001
  kDownloadSourceHttpServer,   // UMA Binary representation: 0010
  kDownloadSourceHttpPeer,     // UMA Binary representation: 0100

  // Note: Add new sources only above this line.
  kNumDownloadSources
} DownloadSource;

// A payload can be a Full or Delta payload. In some cases, a Full payload is
// used even when a Delta payload was available for the update, called here
// ForcedFull. The PayloadType enum is only used to send UMA metrics about the
// successfully applied payload.
typedef enum {
  kPayloadTypeFull,
  kPayloadTypeDelta,
  kPayloadTypeForcedFull,

  // Note: Add new payload types only above this line.
  kNumPayloadTypes
} PayloadType;

// Maximum number of times we'll allow using p2p for the same update payload.
constexpr int kMaxP2PAttempts = 10;

// Maximum wallclock time we allow attempting to update using p2p for
// the same update payload - five days.
constexpr int kMaxP2PAttemptTimeSeconds = 5 * 24 * 60 * 60;

// The maximum amount of time to spend waiting for p2p-client(1) to
// return while waiting in line to use the LAN - six hours.
constexpr int kMaxP2PNetworkWaitTimeSeconds = 6 * 60 * 60;

// The maximum number of payload files to keep in /var/cache/p2p.
constexpr int kMaxP2PFilesToKeep = 3;

// The maximum number of days to keep a p2p file;
constexpr int kMaxP2PFileAgeDays = 5;

// The default number of UMA buckets for metrics.
constexpr int kNumDefaultUmaBuckets = 50;

// General constexprants
constexpr int kNumBytesInOneMiB = 1024 * 1024;

// Number of redirects allowed when downloading.
constexpr int kDownloadMaxRedirects = 10;

// The minimum average speed that downloads must sustain...
//
// This is set low because some devices may have very poor
// connectivity and we want to make as much forward progress as
// possible. For p2p this is high (25 kB/second) since we can assume
// high bandwidth (same LAN) and we want to fail fast.
constexpr int kDownloadLowSpeedLimitBps = 1;
constexpr int kDownloadP2PLowSpeedLimitBps = 25 * 1000;

// ... measured over this period.
//
// For non-official builds (e.g. typically built on a developer's
// workstation and served via devserver) bump this since it takes time
// for the workstation to generate the payload. For normal operation
// and p2p, make this relatively low since we want to fail fast in
// those cases.
constexpr int kDownloadLowSpeedTimeSeconds = 30;
constexpr int kDownloadDevModeLowSpeedTimeSeconds = 180;
constexpr int kDownloadP2PLowSpeedTimeSeconds = 60;

// The maximum amount of HTTP server reconnect attempts.
//
// This is set high in order to maximize the attempt's chance of
// succeeding. When using p2p, this is low in order to fail fast.
constexpr int kDownloadMaxRetryCount = 20;
constexpr int kDownloadMaxRetryCountOobeNotComplete = 3;
constexpr int kDownloadMaxRetryCountInteractive = 3;
constexpr int kDownloadP2PMaxRetryCount = 5;

// The connect timeout, in seconds.
//
// This is set high because some devices may have very poor
// connectivity and we may be using HTTPS which involves complicated
// multi-roundtrip setup. For p2p, this is set low because we can
// the server is on the same LAN and we want to fail fast.
constexpr int kDownloadConnectTimeoutSeconds = 30;
constexpr int kDownloadP2PConnectTimeoutSeconds = 5;

// Size in bytes of SHA256 hash.
constexpr int kSHA256Size = 32;

// A hardcoded label to mark end of all InstallOps
// This number must be greater than number of install ops.
// Number of install ops is bounded by number of blocks on any partition.
// Currently, the block size is 4096. Using |kEndOfInstallLabel| of 2^48 will
// allow partitions with 2^48 * 4096 = 2^60 bytes. That's 1024PB? Partitions on
// android aren't getting that big any time soon.
constexpr uint64_t kEndOfInstallLabel = (1ULL << 48);

}  // namespace chromeos_update_engine

#endif  // UPDATE_ENGINE_COMMON_CONSTANTS_H_
