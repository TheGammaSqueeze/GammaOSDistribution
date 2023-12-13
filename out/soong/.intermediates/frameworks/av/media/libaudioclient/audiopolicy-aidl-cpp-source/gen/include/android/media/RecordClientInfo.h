#pragma once

#include <android/binder_to_string.h>
#include <android/media/AudioSourceType.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class RecordClientInfo : public ::android::Parcelable {
public:
  inline bool operator!=(const RecordClientInfo& rhs) const {
    return std::tie(riid, uid, session, source, portId, silenced) != std::tie(rhs.riid, rhs.uid, rhs.session, rhs.source, rhs.portId, rhs.silenced);
  }
  inline bool operator<(const RecordClientInfo& rhs) const {
    return std::tie(riid, uid, session, source, portId, silenced) < std::tie(rhs.riid, rhs.uid, rhs.session, rhs.source, rhs.portId, rhs.silenced);
  }
  inline bool operator<=(const RecordClientInfo& rhs) const {
    return std::tie(riid, uid, session, source, portId, silenced) <= std::tie(rhs.riid, rhs.uid, rhs.session, rhs.source, rhs.portId, rhs.silenced);
  }
  inline bool operator==(const RecordClientInfo& rhs) const {
    return std::tie(riid, uid, session, source, portId, silenced) == std::tie(rhs.riid, rhs.uid, rhs.session, rhs.source, rhs.portId, rhs.silenced);
  }
  inline bool operator>(const RecordClientInfo& rhs) const {
    return std::tie(riid, uid, session, source, portId, silenced) > std::tie(rhs.riid, rhs.uid, rhs.session, rhs.source, rhs.portId, rhs.silenced);
  }
  inline bool operator>=(const RecordClientInfo& rhs) const {
    return std::tie(riid, uid, session, source, portId, silenced) >= std::tie(rhs.riid, rhs.uid, rhs.session, rhs.source, rhs.portId, rhs.silenced);
  }

  int32_t riid = int32_t(0);
  int32_t uid = int32_t(0);
  int32_t session = int32_t(0);
  ::android::media::AudioSourceType source = ::android::media::AudioSourceType(0);
  int32_t portId = int32_t(0);
  bool silenced = bool(false);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.RecordClientInfo");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "RecordClientInfo{";
    os << "riid: " << ::android::internal::ToString(riid);
    os << ", uid: " << ::android::internal::ToString(uid);
    os << ", session: " << ::android::internal::ToString(session);
    os << ", source: " << ::android::internal::ToString(source);
    os << ", portId: " << ::android::internal::ToString(portId);
    os << ", silenced: " << ::android::internal::ToString(silenced);
    os << "}";
    return os.str();
  }
};  // class RecordClientInfo

}  // namespace media

}  // namespace android
