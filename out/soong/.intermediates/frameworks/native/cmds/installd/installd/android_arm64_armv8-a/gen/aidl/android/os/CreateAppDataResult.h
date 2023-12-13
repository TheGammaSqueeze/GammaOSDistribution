#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace os {

class CreateAppDataResult : public ::android::Parcelable {
public:
  inline bool operator!=(const CreateAppDataResult& rhs) const {
    return std::tie(ceDataInode, exceptionCode, exceptionMessage) != std::tie(rhs.ceDataInode, rhs.exceptionCode, rhs.exceptionMessage);
  }
  inline bool operator<(const CreateAppDataResult& rhs) const {
    return std::tie(ceDataInode, exceptionCode, exceptionMessage) < std::tie(rhs.ceDataInode, rhs.exceptionCode, rhs.exceptionMessage);
  }
  inline bool operator<=(const CreateAppDataResult& rhs) const {
    return std::tie(ceDataInode, exceptionCode, exceptionMessage) <= std::tie(rhs.ceDataInode, rhs.exceptionCode, rhs.exceptionMessage);
  }
  inline bool operator==(const CreateAppDataResult& rhs) const {
    return std::tie(ceDataInode, exceptionCode, exceptionMessage) == std::tie(rhs.ceDataInode, rhs.exceptionCode, rhs.exceptionMessage);
  }
  inline bool operator>(const CreateAppDataResult& rhs) const {
    return std::tie(ceDataInode, exceptionCode, exceptionMessage) > std::tie(rhs.ceDataInode, rhs.exceptionCode, rhs.exceptionMessage);
  }
  inline bool operator>=(const CreateAppDataResult& rhs) const {
    return std::tie(ceDataInode, exceptionCode, exceptionMessage) >= std::tie(rhs.ceDataInode, rhs.exceptionCode, rhs.exceptionMessage);
  }

  int64_t ceDataInode = int64_t(0L);
  int32_t exceptionCode = int32_t(0);
  ::std::string exceptionMessage;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.os.CreateAppDataResult");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "CreateAppDataResult{";
    os << "ceDataInode: " << ::android::internal::ToString(ceDataInode);
    os << ", exceptionCode: " << ::android::internal::ToString(exceptionCode);
    os << ", exceptionMessage: " << ::android::internal::ToString(exceptionMessage);
    os << "}";
    return os.str();
  }
};  // class CreateAppDataResult

}  // namespace os

}  // namespace android
