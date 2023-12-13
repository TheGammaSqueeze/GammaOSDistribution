#pragma once

#include <android/binder_to_string.h>
#include <android/media/AudioAttributesInternal.h>
#include <android/media/AudioClient.h>
#include <android/media/AudioConfigBase.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class CreateRecordRequest : public ::android::Parcelable {
public:
  inline bool operator!=(const CreateRecordRequest& rhs) const {
    return std::tie(attr, config, clientInfo, riid, maxSharedAudioHistoryMs, flags, frameCount, notificationFrameCount, selectedDeviceId, sessionId) != std::tie(rhs.attr, rhs.config, rhs.clientInfo, rhs.riid, rhs.maxSharedAudioHistoryMs, rhs.flags, rhs.frameCount, rhs.notificationFrameCount, rhs.selectedDeviceId, rhs.sessionId);
  }
  inline bool operator<(const CreateRecordRequest& rhs) const {
    return std::tie(attr, config, clientInfo, riid, maxSharedAudioHistoryMs, flags, frameCount, notificationFrameCount, selectedDeviceId, sessionId) < std::tie(rhs.attr, rhs.config, rhs.clientInfo, rhs.riid, rhs.maxSharedAudioHistoryMs, rhs.flags, rhs.frameCount, rhs.notificationFrameCount, rhs.selectedDeviceId, rhs.sessionId);
  }
  inline bool operator<=(const CreateRecordRequest& rhs) const {
    return std::tie(attr, config, clientInfo, riid, maxSharedAudioHistoryMs, flags, frameCount, notificationFrameCount, selectedDeviceId, sessionId) <= std::tie(rhs.attr, rhs.config, rhs.clientInfo, rhs.riid, rhs.maxSharedAudioHistoryMs, rhs.flags, rhs.frameCount, rhs.notificationFrameCount, rhs.selectedDeviceId, rhs.sessionId);
  }
  inline bool operator==(const CreateRecordRequest& rhs) const {
    return std::tie(attr, config, clientInfo, riid, maxSharedAudioHistoryMs, flags, frameCount, notificationFrameCount, selectedDeviceId, sessionId) == std::tie(rhs.attr, rhs.config, rhs.clientInfo, rhs.riid, rhs.maxSharedAudioHistoryMs, rhs.flags, rhs.frameCount, rhs.notificationFrameCount, rhs.selectedDeviceId, rhs.sessionId);
  }
  inline bool operator>(const CreateRecordRequest& rhs) const {
    return std::tie(attr, config, clientInfo, riid, maxSharedAudioHistoryMs, flags, frameCount, notificationFrameCount, selectedDeviceId, sessionId) > std::tie(rhs.attr, rhs.config, rhs.clientInfo, rhs.riid, rhs.maxSharedAudioHistoryMs, rhs.flags, rhs.frameCount, rhs.notificationFrameCount, rhs.selectedDeviceId, rhs.sessionId);
  }
  inline bool operator>=(const CreateRecordRequest& rhs) const {
    return std::tie(attr, config, clientInfo, riid, maxSharedAudioHistoryMs, flags, frameCount, notificationFrameCount, selectedDeviceId, sessionId) >= std::tie(rhs.attr, rhs.config, rhs.clientInfo, rhs.riid, rhs.maxSharedAudioHistoryMs, rhs.flags, rhs.frameCount, rhs.notificationFrameCount, rhs.selectedDeviceId, rhs.sessionId);
  }

  ::android::media::AudioAttributesInternal attr;
  ::android::media::AudioConfigBase config;
  ::android::media::AudioClient clientInfo;
  int32_t riid = int32_t(0);
  int32_t maxSharedAudioHistoryMs = int32_t(0);
  int32_t flags = int32_t(0);
  int64_t frameCount = int64_t(0L);
  int64_t notificationFrameCount = int64_t(0L);
  int32_t selectedDeviceId = int32_t(0);
  int32_t sessionId = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.CreateRecordRequest");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "CreateRecordRequest{";
    os << "attr: " << ::android::internal::ToString(attr);
    os << ", config: " << ::android::internal::ToString(config);
    os << ", clientInfo: " << ::android::internal::ToString(clientInfo);
    os << ", riid: " << ::android::internal::ToString(riid);
    os << ", maxSharedAudioHistoryMs: " << ::android::internal::ToString(maxSharedAudioHistoryMs);
    os << ", flags: " << ::android::internal::ToString(flags);
    os << ", frameCount: " << ::android::internal::ToString(frameCount);
    os << ", notificationFrameCount: " << ::android::internal::ToString(notificationFrameCount);
    os << ", selectedDeviceId: " << ::android::internal::ToString(selectedDeviceId);
    os << ", sessionId: " << ::android::internal::ToString(sessionId);
    os << "}";
    return os.str();
  }
};  // class CreateRecordRequest

}  // namespace media

}  // namespace android
