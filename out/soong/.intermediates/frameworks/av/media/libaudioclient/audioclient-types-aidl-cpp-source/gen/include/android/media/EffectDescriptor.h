#pragma once

#include <android/binder_to_string.h>
#include <android/media/AudioUuid.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class EffectDescriptor : public ::android::Parcelable {
public:
  inline bool operator!=(const EffectDescriptor& rhs) const {
    return std::tie(type, uuid, apiVersion, flags, cpuLoad, memoryUsage, name, implementor) != std::tie(rhs.type, rhs.uuid, rhs.apiVersion, rhs.flags, rhs.cpuLoad, rhs.memoryUsage, rhs.name, rhs.implementor);
  }
  inline bool operator<(const EffectDescriptor& rhs) const {
    return std::tie(type, uuid, apiVersion, flags, cpuLoad, memoryUsage, name, implementor) < std::tie(rhs.type, rhs.uuid, rhs.apiVersion, rhs.flags, rhs.cpuLoad, rhs.memoryUsage, rhs.name, rhs.implementor);
  }
  inline bool operator<=(const EffectDescriptor& rhs) const {
    return std::tie(type, uuid, apiVersion, flags, cpuLoad, memoryUsage, name, implementor) <= std::tie(rhs.type, rhs.uuid, rhs.apiVersion, rhs.flags, rhs.cpuLoad, rhs.memoryUsage, rhs.name, rhs.implementor);
  }
  inline bool operator==(const EffectDescriptor& rhs) const {
    return std::tie(type, uuid, apiVersion, flags, cpuLoad, memoryUsage, name, implementor) == std::tie(rhs.type, rhs.uuid, rhs.apiVersion, rhs.flags, rhs.cpuLoad, rhs.memoryUsage, rhs.name, rhs.implementor);
  }
  inline bool operator>(const EffectDescriptor& rhs) const {
    return std::tie(type, uuid, apiVersion, flags, cpuLoad, memoryUsage, name, implementor) > std::tie(rhs.type, rhs.uuid, rhs.apiVersion, rhs.flags, rhs.cpuLoad, rhs.memoryUsage, rhs.name, rhs.implementor);
  }
  inline bool operator>=(const EffectDescriptor& rhs) const {
    return std::tie(type, uuid, apiVersion, flags, cpuLoad, memoryUsage, name, implementor) >= std::tie(rhs.type, rhs.uuid, rhs.apiVersion, rhs.flags, rhs.cpuLoad, rhs.memoryUsage, rhs.name, rhs.implementor);
  }

  ::android::media::AudioUuid type;
  ::android::media::AudioUuid uuid;
  int32_t apiVersion = int32_t(0);
  int32_t flags = int32_t(0);
  int32_t cpuLoad = int32_t(0);
  int32_t memoryUsage = int32_t(0);
  ::std::string name;
  ::std::string implementor;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.EffectDescriptor");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "EffectDescriptor{";
    os << "type: " << ::android::internal::ToString(type);
    os << ", uuid: " << ::android::internal::ToString(uuid);
    os << ", apiVersion: " << ::android::internal::ToString(apiVersion);
    os << ", flags: " << ::android::internal::ToString(flags);
    os << ", cpuLoad: " << ::android::internal::ToString(cpuLoad);
    os << ", memoryUsage: " << ::android::internal::ToString(memoryUsage);
    os << ", name: " << ::android::internal::ToString(name);
    os << ", implementor: " << ::android::internal::ToString(implementor);
    os << "}";
    return os.str();
  }
};  // class EffectDescriptor

}  // namespace media

}  // namespace android
