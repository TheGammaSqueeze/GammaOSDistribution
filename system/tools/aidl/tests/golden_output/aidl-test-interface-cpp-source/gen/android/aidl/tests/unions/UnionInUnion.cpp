#include <android/aidl/tests/unions/UnionInUnion.h>

namespace android {

namespace aidl {

namespace tests {

namespace unions {

::android::status_t UnionInUnion::readFromParcel(const ::android::Parcel* _aidl_parcel) {
  ::android::status_t _aidl_ret_status;
  int32_t _aidl_tag;
  if ((_aidl_ret_status = _aidl_parcel->readInt32(&_aidl_tag)) != ::android::OK) return _aidl_ret_status;
  switch (_aidl_tag) {
  case first: {
    ::android::aidl::tests::unions::EnumUnion _aidl_value;
    if ((_aidl_ret_status = _aidl_parcel->readParcelable(&_aidl_value)) != ::android::OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<::android::aidl::tests::unions::EnumUnion>) {
      set<first>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<first>(std::move(_aidl_value));
    }
    return ::android::OK; }
  case second: {
    int32_t _aidl_value;
    if ((_aidl_ret_status = _aidl_parcel->readInt32(&_aidl_value)) != ::android::OK) return _aidl_ret_status;
    if constexpr (std::is_trivially_copyable_v<int32_t>) {
      set<second>(_aidl_value);
    } else {
      // NOLINTNEXTLINE(performance-move-const-arg)
      set<second>(std::move(_aidl_value));
    }
    return ::android::OK; }
  }
  return ::android::BAD_VALUE;
}

::android::status_t UnionInUnion::writeToParcel(::android::Parcel* _aidl_parcel) const {
  ::android::status_t _aidl_ret_status = _aidl_parcel->writeInt32(getTag());
  if (_aidl_ret_status != ::android::OK) return _aidl_ret_status;
  switch (getTag()) {
  case first: return _aidl_parcel->writeParcelable(get<first>());
  case second: return _aidl_parcel->writeInt32(get<second>());
  }
  __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "can't reach here");
}

}  // namespace unions

}  // namespace tests

}  // namespace aidl

}  // namespace android
