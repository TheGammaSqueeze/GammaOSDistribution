#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/vibrator/ActivePwle.h>
#include <android/hardware/vibrator/BrakingPwle.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cassert>
#include <type_traits>
#include <utility>
#include <utils/String16.h>
#include <variant>

#ifndef __BIONIC__
#define __assert2(a,b,c,d) ((void)0)
#endif

namespace android {

namespace hardware {

namespace vibrator {

class PrimitivePwle : public ::android::Parcelable {
public:
  inline bool operator!=(const PrimitivePwle& rhs) const {
    return _value != rhs._value;
  }
  inline bool operator<(const PrimitivePwle& rhs) const {
    return _value < rhs._value;
  }
  inline bool operator<=(const PrimitivePwle& rhs) const {
    return _value <= rhs._value;
  }
  inline bool operator==(const PrimitivePwle& rhs) const {
    return _value == rhs._value;
  }
  inline bool operator>(const PrimitivePwle& rhs) const {
    return _value > rhs._value;
  }
  inline bool operator>=(const PrimitivePwle& rhs) const {
    return _value >= rhs._value;
  }

  enum Tag : int32_t {
    active = 0,  // android.hardware.vibrator.ActivePwle active;
    braking,  // android.hardware.vibrator.BrakingPwle braking;
  };

  template<typename _Tp>
  static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, PrimitivePwle>;

  PrimitivePwle() : _value(std::in_place_index<active>, ::android::hardware::vibrator::ActivePwle()) { }
  PrimitivePwle(const PrimitivePwle&) = default;
  PrimitivePwle(PrimitivePwle&&) = default;
  PrimitivePwle& operator=(const PrimitivePwle&) = default;
  PrimitivePwle& operator=(PrimitivePwle&&) = default;

  template <typename _Tp, typename = std::enable_if_t<_not_self<_Tp>>>
  // NOLINTNEXTLINE(google-explicit-constructor)
  constexpr PrimitivePwle(_Tp&& _arg)
      : _value(std::forward<_Tp>(_arg)) {}

  template <size_t _Np, typename... _Tp>
  constexpr explicit PrimitivePwle(std::in_place_index_t<_Np>, _Tp&&... _args)
      : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

  template <Tag _tag, typename... _Tp>
  static PrimitivePwle make(_Tp&&... _args) {
    return PrimitivePwle(std::in_place_index<_tag>, std::forward<_Tp>(_args)...);
  }

  template <Tag _tag, typename _Tp, typename... _Up>
  static PrimitivePwle make(std::initializer_list<_Tp> _il, _Up&&... _args) {
    return PrimitivePwle(std::in_place_index<_tag>, std::move(_il), std::forward<_Up>(_args)...);
  }

  Tag getTag() const {
    return static_cast<Tag>(_value.index());
  }

  template <Tag _tag>
  const auto& get() const {
    if (getTag() != _tag) { __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "bad access: a wrong tag"); }
    return std::get<_tag>(_value);
  }

  template <Tag _tag>
  auto& get() {
    if (getTag() != _tag) { __assert2(__FILE__, __LINE__, __PRETTY_FUNCTION__, "bad access: a wrong tag"); }
    return std::get<_tag>(_value);
  }

  template <Tag _tag, typename... _Tp>
  void set(_Tp&&... _args) {
    _value.emplace<_tag>(std::forward<_Tp>(_args)...);
  }

  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.vibrator.PrimitivePwle");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "PrimitivePwle{";
    switch (getTag()) {
    case active: os << "active: " << ::android::internal::ToString(get<active>()); break;
    case braking: os << "braking: " << ::android::internal::ToString(get<braking>()); break;
    }
    os << "}";
    return os.str();
  }
private:
  std::variant<::android::hardware::vibrator::ActivePwle, ::android::hardware::vibrator::BrakingPwle> _value;
};  // class PrimitivePwle

}  // namespace vibrator

}  // namespace hardware

}  // namespace android
