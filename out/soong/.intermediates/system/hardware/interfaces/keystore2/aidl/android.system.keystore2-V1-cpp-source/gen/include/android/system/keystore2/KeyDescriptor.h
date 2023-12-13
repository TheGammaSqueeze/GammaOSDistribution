#pragma once

#include <android/binder_to_string.h>
#include <android/system/keystore2/Domain.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <optional>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace system {

namespace keystore2 {

class KeyDescriptor : public ::android::Parcelable {
public:
  inline bool operator!=(const KeyDescriptor& rhs) const {
    return std::tie(domain, nspace, alias, blob) != std::tie(rhs.domain, rhs.nspace, rhs.alias, rhs.blob);
  }
  inline bool operator<(const KeyDescriptor& rhs) const {
    return std::tie(domain, nspace, alias, blob) < std::tie(rhs.domain, rhs.nspace, rhs.alias, rhs.blob);
  }
  inline bool operator<=(const KeyDescriptor& rhs) const {
    return std::tie(domain, nspace, alias, blob) <= std::tie(rhs.domain, rhs.nspace, rhs.alias, rhs.blob);
  }
  inline bool operator==(const KeyDescriptor& rhs) const {
    return std::tie(domain, nspace, alias, blob) == std::tie(rhs.domain, rhs.nspace, rhs.alias, rhs.blob);
  }
  inline bool operator>(const KeyDescriptor& rhs) const {
    return std::tie(domain, nspace, alias, blob) > std::tie(rhs.domain, rhs.nspace, rhs.alias, rhs.blob);
  }
  inline bool operator>=(const KeyDescriptor& rhs) const {
    return std::tie(domain, nspace, alias, blob) >= std::tie(rhs.domain, rhs.nspace, rhs.alias, rhs.blob);
  }

  ::android::system::keystore2::Domain domain = ::android::system::keystore2::Domain(0);
  int64_t nspace = int64_t(0L);
  ::std::optional<::android::String16> alias;
  ::std::optional<::std::vector<uint8_t>> blob;
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.system.keystore2.KeyDescriptor");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "KeyDescriptor{";
    os << "domain: " << ::android::internal::ToString(domain);
    os << ", nspace: " << ::android::internal::ToString(nspace);
    os << ", alias: " << ::android::internal::ToString(alias);
    os << ", blob: " << ::android::internal::ToString(blob);
    os << "}";
    return os.str();
  }
};  // class KeyDescriptor

}  // namespace keystore2

}  // namespace system

}  // namespace android
