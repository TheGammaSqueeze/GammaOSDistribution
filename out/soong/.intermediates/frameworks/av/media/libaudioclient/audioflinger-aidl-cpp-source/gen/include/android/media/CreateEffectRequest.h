#pragma once

#include <android/binder_to_string.h>
#include <android/content/AttributionSourceState.h>
#include <android/media/AudioDevice.h>
#include <android/media/EffectDescriptor.h>
#include <android/media/IEffectClient.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <optional>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class CreateEffectRequest : public ::android::Parcelable {
public:
  inline bool operator!=(const CreateEffectRequest& rhs) const {
    return std::tie(desc, client, priority, output, sessionId, device, attributionSource, probe, notifyFramesProcessed) != std::tie(rhs.desc, rhs.client, rhs.priority, rhs.output, rhs.sessionId, rhs.device, rhs.attributionSource, rhs.probe, rhs.notifyFramesProcessed);
  }
  inline bool operator<(const CreateEffectRequest& rhs) const {
    return std::tie(desc, client, priority, output, sessionId, device, attributionSource, probe, notifyFramesProcessed) < std::tie(rhs.desc, rhs.client, rhs.priority, rhs.output, rhs.sessionId, rhs.device, rhs.attributionSource, rhs.probe, rhs.notifyFramesProcessed);
  }
  inline bool operator<=(const CreateEffectRequest& rhs) const {
    return std::tie(desc, client, priority, output, sessionId, device, attributionSource, probe, notifyFramesProcessed) <= std::tie(rhs.desc, rhs.client, rhs.priority, rhs.output, rhs.sessionId, rhs.device, rhs.attributionSource, rhs.probe, rhs.notifyFramesProcessed);
  }
  inline bool operator==(const CreateEffectRequest& rhs) const {
    return std::tie(desc, client, priority, output, sessionId, device, attributionSource, probe, notifyFramesProcessed) == std::tie(rhs.desc, rhs.client, rhs.priority, rhs.output, rhs.sessionId, rhs.device, rhs.attributionSource, rhs.probe, rhs.notifyFramesProcessed);
  }
  inline bool operator>(const CreateEffectRequest& rhs) const {
    return std::tie(desc, client, priority, output, sessionId, device, attributionSource, probe, notifyFramesProcessed) > std::tie(rhs.desc, rhs.client, rhs.priority, rhs.output, rhs.sessionId, rhs.device, rhs.attributionSource, rhs.probe, rhs.notifyFramesProcessed);
  }
  inline bool operator>=(const CreateEffectRequest& rhs) const {
    return std::tie(desc, client, priority, output, sessionId, device, attributionSource, probe, notifyFramesProcessed) >= std::tie(rhs.desc, rhs.client, rhs.priority, rhs.output, rhs.sessionId, rhs.device, rhs.attributionSource, rhs.probe, rhs.notifyFramesProcessed);
  }

  ::android::media::EffectDescriptor desc;
  ::android::sp<::android::media::IEffectClient> client;
  int32_t priority = int32_t(0);
  int32_t output = int32_t(0);
  int32_t sessionId = int32_t(0);
  ::android::media::AudioDevice device;
  ::android::content::AttributionSourceState attributionSource;
  bool probe = bool(false);
  bool notifyFramesProcessed = bool(false);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.CreateEffectRequest");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "CreateEffectRequest{";
    os << "desc: " << ::android::internal::ToString(desc);
    os << ", client: " << ::android::internal::ToString(client);
    os << ", priority: " << ::android::internal::ToString(priority);
    os << ", output: " << ::android::internal::ToString(output);
    os << ", sessionId: " << ::android::internal::ToString(sessionId);
    os << ", device: " << ::android::internal::ToString(device);
    os << ", attributionSource: " << ::android::internal::ToString(attributionSource);
    os << ", probe: " << ::android::internal::ToString(probe);
    os << ", notifyFramesProcessed: " << ::android::internal::ToString(notifyFramesProcessed);
    os << "}";
    return os.str();
  }
};  // class CreateEffectRequest

}  // namespace media

}  // namespace android
