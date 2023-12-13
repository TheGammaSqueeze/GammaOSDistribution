#pragma once
#include <android/binder_interface_utils.h>
#include <android/binder_parcelable_utils.h>
#include <android/binder_to_string.h>
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT
#include <aidl/android/media/TranscodingSessionPriority.h>
#include <aidl/android/media/TranscodingTestConfig.h>
#include <aidl/android/media/TranscodingType.h>
#include <aidl/android/media/TranscodingVideoTrackFormat.h>
namespace aidl {
namespace android {
namespace media {
class TranscodingRequestParcel {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  std::string sourceFilePath;
  ::ndk::ScopedFileDescriptor sourceFd;
  std::string destinationFilePath;
  ::ndk::ScopedFileDescriptor destinationFd;
  int32_t clientUid = -1;
  int32_t clientPid = -1;
  std::string clientPackageName;
  ::aidl::android::media::TranscodingType transcodingType = ::aidl::android::media::TranscodingType(0);
  std::optional<::aidl::android::media::TranscodingVideoTrackFormat> requestedVideoTrackFormat;
  ::aidl::android::media::TranscodingSessionPriority priority = ::aidl::android::media::TranscodingSessionPriority(0);
  bool requestProgressUpdate = false;
  bool requestSessionEventUpdate = false;
  bool isForTesting = false;
  std::optional<::aidl::android::media::TranscodingTestConfig> testConfig;
  bool enableStats = false;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator!=(const TranscodingRequestParcel& rhs) const {
    return std::tie(sourceFilePath, sourceFd, destinationFilePath, destinationFd, clientUid, clientPid, clientPackageName, transcodingType, requestedVideoTrackFormat, priority, requestProgressUpdate, requestSessionEventUpdate, isForTesting, testConfig, enableStats) != std::tie(rhs.sourceFilePath, rhs.sourceFd, rhs.destinationFilePath, rhs.destinationFd, rhs.clientUid, rhs.clientPid, rhs.clientPackageName, rhs.transcodingType, rhs.requestedVideoTrackFormat, rhs.priority, rhs.requestProgressUpdate, rhs.requestSessionEventUpdate, rhs.isForTesting, rhs.testConfig, rhs.enableStats);
  }
  inline bool operator<(const TranscodingRequestParcel& rhs) const {
    return std::tie(sourceFilePath, sourceFd, destinationFilePath, destinationFd, clientUid, clientPid, clientPackageName, transcodingType, requestedVideoTrackFormat, priority, requestProgressUpdate, requestSessionEventUpdate, isForTesting, testConfig, enableStats) < std::tie(rhs.sourceFilePath, rhs.sourceFd, rhs.destinationFilePath, rhs.destinationFd, rhs.clientUid, rhs.clientPid, rhs.clientPackageName, rhs.transcodingType, rhs.requestedVideoTrackFormat, rhs.priority, rhs.requestProgressUpdate, rhs.requestSessionEventUpdate, rhs.isForTesting, rhs.testConfig, rhs.enableStats);
  }
  inline bool operator<=(const TranscodingRequestParcel& rhs) const {
    return std::tie(sourceFilePath, sourceFd, destinationFilePath, destinationFd, clientUid, clientPid, clientPackageName, transcodingType, requestedVideoTrackFormat, priority, requestProgressUpdate, requestSessionEventUpdate, isForTesting, testConfig, enableStats) <= std::tie(rhs.sourceFilePath, rhs.sourceFd, rhs.destinationFilePath, rhs.destinationFd, rhs.clientUid, rhs.clientPid, rhs.clientPackageName, rhs.transcodingType, rhs.requestedVideoTrackFormat, rhs.priority, rhs.requestProgressUpdate, rhs.requestSessionEventUpdate, rhs.isForTesting, rhs.testConfig, rhs.enableStats);
  }
  inline bool operator==(const TranscodingRequestParcel& rhs) const {
    return std::tie(sourceFilePath, sourceFd, destinationFilePath, destinationFd, clientUid, clientPid, clientPackageName, transcodingType, requestedVideoTrackFormat, priority, requestProgressUpdate, requestSessionEventUpdate, isForTesting, testConfig, enableStats) == std::tie(rhs.sourceFilePath, rhs.sourceFd, rhs.destinationFilePath, rhs.destinationFd, rhs.clientUid, rhs.clientPid, rhs.clientPackageName, rhs.transcodingType, rhs.requestedVideoTrackFormat, rhs.priority, rhs.requestProgressUpdate, rhs.requestSessionEventUpdate, rhs.isForTesting, rhs.testConfig, rhs.enableStats);
  }
  inline bool operator>(const TranscodingRequestParcel& rhs) const {
    return std::tie(sourceFilePath, sourceFd, destinationFilePath, destinationFd, clientUid, clientPid, clientPackageName, transcodingType, requestedVideoTrackFormat, priority, requestProgressUpdate, requestSessionEventUpdate, isForTesting, testConfig, enableStats) > std::tie(rhs.sourceFilePath, rhs.sourceFd, rhs.destinationFilePath, rhs.destinationFd, rhs.clientUid, rhs.clientPid, rhs.clientPackageName, rhs.transcodingType, rhs.requestedVideoTrackFormat, rhs.priority, rhs.requestProgressUpdate, rhs.requestSessionEventUpdate, rhs.isForTesting, rhs.testConfig, rhs.enableStats);
  }
  inline bool operator>=(const TranscodingRequestParcel& rhs) const {
    return std::tie(sourceFilePath, sourceFd, destinationFilePath, destinationFd, clientUid, clientPid, clientPackageName, transcodingType, requestedVideoTrackFormat, priority, requestProgressUpdate, requestSessionEventUpdate, isForTesting, testConfig, enableStats) >= std::tie(rhs.sourceFilePath, rhs.sourceFd, rhs.destinationFilePath, rhs.destinationFd, rhs.clientUid, rhs.clientPid, rhs.clientPackageName, rhs.transcodingType, rhs.requestedVideoTrackFormat, rhs.priority, rhs.requestProgressUpdate, rhs.requestSessionEventUpdate, rhs.isForTesting, rhs.testConfig, rhs.enableStats);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_LOCAL;
  inline std::string toString() const {
    std::ostringstream os;
    os << "TranscodingRequestParcel{";
    os << "sourceFilePath: " << ::android::internal::ToString(sourceFilePath);
    os << ", sourceFd: " << ::android::internal::ToString(sourceFd);
    os << ", destinationFilePath: " << ::android::internal::ToString(destinationFilePath);
    os << ", destinationFd: " << ::android::internal::ToString(destinationFd);
    os << ", clientUid: " << ::android::internal::ToString(clientUid);
    os << ", clientPid: " << ::android::internal::ToString(clientPid);
    os << ", clientPackageName: " << ::android::internal::ToString(clientPackageName);
    os << ", transcodingType: " << ::android::internal::ToString(transcodingType);
    os << ", requestedVideoTrackFormat: " << ::android::internal::ToString(requestedVideoTrackFormat);
    os << ", priority: " << ::android::internal::ToString(priority);
    os << ", requestProgressUpdate: " << ::android::internal::ToString(requestProgressUpdate);
    os << ", requestSessionEventUpdate: " << ::android::internal::ToString(requestSessionEventUpdate);
    os << ", isForTesting: " << ::android::internal::ToString(isForTesting);
    os << ", testConfig: " << ::android::internal::ToString(testConfig);
    os << ", enableStats: " << ::android::internal::ToString(enableStats);
    os << "}";
    return os.str();
  }
};
}  // namespace media
}  // namespace android
}  // namespace aidl
