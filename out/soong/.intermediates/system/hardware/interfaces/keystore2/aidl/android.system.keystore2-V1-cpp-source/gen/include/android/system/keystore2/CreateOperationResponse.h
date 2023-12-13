#pragma once

#include <android/binder_to_string.h>
#include <android/system/keystore2/IKeystoreOperation.h>
#include <android/system/keystore2/KeyParameters.h>
#include <android/system/keystore2/OperationChallenge.h>
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

class CreateOperationResponse : public ::android::Parcelable {
public:
  inline bool operator!=(const CreateOperationResponse& rhs) const {
    return std::tie(iOperation, operationChallenge, parameters, upgradedBlob) != std::tie(rhs.iOperation, rhs.operationChallenge, rhs.parameters, rhs.upgradedBlob);
  }
  inline bool operator<(const CreateOperationResponse& rhs) const {
    return std::tie(iOperation, operationChallenge, parameters, upgradedBlob) < std::tie(rhs.iOperation, rhs.operationChallenge, rhs.parameters, rhs.upgradedBlob);
  }
  inline bool operator<=(const CreateOperationResponse& rhs) const {
    return std::tie(iOperation, operationChallenge, parameters, upgradedBlob) <= std::tie(rhs.iOperation, rhs.operationChallenge, rhs.parameters, rhs.upgradedBlob);
  }
  inline bool operator==(const CreateOperationResponse& rhs) const {
    return std::tie(iOperation, operationChallenge, parameters, upgradedBlob) == std::tie(rhs.iOperation, rhs.operationChallenge, rhs.parameters, rhs.upgradedBlob);
  }
  inline bool operator>(const CreateOperationResponse& rhs) const {
    return std::tie(iOperation, operationChallenge, parameters, upgradedBlob) > std::tie(rhs.iOperation, rhs.operationChallenge, rhs.parameters, rhs.upgradedBlob);
  }
  inline bool operator>=(const CreateOperationResponse& rhs) const {
    return std::tie(iOperation, operationChallenge, parameters, upgradedBlob) >= std::tie(rhs.iOperation, rhs.operationChallenge, rhs.parameters, rhs.upgradedBlob);
  }

  ::android::sp<::android::system::keystore2::IKeystoreOperation> iOperation;
  ::std::optional<::android::system::keystore2::OperationChallenge> operationChallenge;
  ::std::optional<::android::system::keystore2::KeyParameters> parameters;
  ::std::optional<::std::vector<uint8_t>> upgradedBlob;
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.system.keystore2.CreateOperationResponse");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "CreateOperationResponse{";
    os << "iOperation: " << ::android::internal::ToString(iOperation);
    os << ", operationChallenge: " << ::android::internal::ToString(operationChallenge);
    os << ", parameters: " << ::android::internal::ToString(parameters);
    os << ", upgradedBlob: " << ::android::internal::ToString(upgradedBlob);
    os << "}";
    return os.str();
  }
};  // class CreateOperationResponse

}  // namespace keystore2

}  // namespace system

}  // namespace android
