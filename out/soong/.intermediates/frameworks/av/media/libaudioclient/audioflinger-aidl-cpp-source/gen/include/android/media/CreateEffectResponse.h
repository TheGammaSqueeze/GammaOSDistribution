#pragma once

#include <android/binder_to_string.h>
#include <android/media/EffectDescriptor.h>
#include <android/media/IEffect.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <optional>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class CreateEffectResponse : public ::android::Parcelable {
public:
  inline bool operator!=(const CreateEffectResponse& rhs) const {
    return std::tie(id, enabled, effect, desc) != std::tie(rhs.id, rhs.enabled, rhs.effect, rhs.desc);
  }
  inline bool operator<(const CreateEffectResponse& rhs) const {
    return std::tie(id, enabled, effect, desc) < std::tie(rhs.id, rhs.enabled, rhs.effect, rhs.desc);
  }
  inline bool operator<=(const CreateEffectResponse& rhs) const {
    return std::tie(id, enabled, effect, desc) <= std::tie(rhs.id, rhs.enabled, rhs.effect, rhs.desc);
  }
  inline bool operator==(const CreateEffectResponse& rhs) const {
    return std::tie(id, enabled, effect, desc) == std::tie(rhs.id, rhs.enabled, rhs.effect, rhs.desc);
  }
  inline bool operator>(const CreateEffectResponse& rhs) const {
    return std::tie(id, enabled, effect, desc) > std::tie(rhs.id, rhs.enabled, rhs.effect, rhs.desc);
  }
  inline bool operator>=(const CreateEffectResponse& rhs) const {
    return std::tie(id, enabled, effect, desc) >= std::tie(rhs.id, rhs.enabled, rhs.effect, rhs.desc);
  }

  int32_t id = int32_t(0);
  bool enabled = bool(false);
  ::android::sp<::android::media::IEffect> effect;
  ::android::media::EffectDescriptor desc;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.CreateEffectResponse");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "CreateEffectResponse{";
    os << "id: " << ::android::internal::ToString(id);
    os << ", enabled: " << ::android::internal::ToString(enabled);
    os << ", effect: " << ::android::internal::ToString(effect);
    os << ", desc: " << ::android::internal::ToString(desc);
    os << "}";
    return os.str();
  }
};  // class CreateEffectResponse

}  // namespace media

}  // namespace android
