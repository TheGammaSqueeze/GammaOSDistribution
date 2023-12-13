#pragma once
#include <android/binder_interface_utils.h>
#include <android/binder_parcelable_utils.h>
#include <android/binder_to_string.h>

#include <cassert>
#include <type_traits>
#include <utility>
#include <variant>
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT
#include <aidl/android/hardware/neuralnetworks/SymmPerChannelQuantParams.h>

#ifndef __BIONIC__
#define __assert2(a,b,c,d) ((void)0)
#endif

namespace aidl {
namespace android {
namespace hardware {
namespace neuralnetworks {
class OperandExtraParams {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  enum Tag : int32_t {
    channelQuant = 0,  // android.hardware.neuralnetworks.SymmPerChannelQuantParams channelQuant;
    extension,  // byte[] extension;
  };

  template<typename _Tp>
  static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, OperandExtraParams>;

  OperandExtraParams() : _value(std::in_place_index<channelQuant>, ::aidl::android::hardware::neuralnetworks::SymmPerChannelQuantParams()) { }
  OperandExtraParams(const OperandExtraParams&) = default;
  OperandExtraParams(OperandExtraParams&&) = default;
  OperandExtraParams& operator=(const OperandExtraParams&) = default;
  OperandExtraParams& operator=(OperandExtraParams&&) = default;

  template <typename _Tp, typename = std::enable_if_t<_not_self<_Tp>>>
  // NOLINTNEXTLINE(google-explicit-constructor)
  constexpr OperandExtraParams(_Tp&& _arg)
      : _value(std::forward<_Tp>(_arg)) {}

  template <size_t _Np, typename... _Tp>
  constexpr explicit OperandExtraParams(std::in_place_index_t<_Np>, _Tp&&... _args)
      : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

  template <Tag _tag, typename... _Tp>
  static OperandExtraParams make(_Tp&&... _args) {
    return OperandExtraParams(std::in_place_index<_tag>, std::forward<_Tp>(_args)...);
  }

  template <Tag _tag, typename _Tp, typename... _Up>
  static OperandExtraParams make(std::initializer_list<_Tp> _il, _Up&&... _args) {
    return OperandExtraParams(std::in_place_index<_tag>, std::move(_il), std::forward<_Up>(_args)...);
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

  binder_status_t readFromParcel(const AParcel* _parcel);
  binder_status_t writeToParcel(AParcel* _parcel) const;

  inline bool operator!=(const OperandExtraParams& rhs) const {
    return _value != rhs._value;
  }
  inline bool operator<(const OperandExtraParams& rhs) const {
    return _value < rhs._value;
  }
  inline bool operator<=(const OperandExtraParams& rhs) const {
    return _value <= rhs._value;
  }
  inline bool operator==(const OperandExtraParams& rhs) const {
    return _value == rhs._value;
  }
  inline bool operator>(const OperandExtraParams& rhs) const {
    return _value > rhs._value;
  }
  inline bool operator>=(const OperandExtraParams& rhs) const {
    return _value >= rhs._value;
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream os;
    os << "OperandExtraParams{";
    switch (getTag()) {
    case channelQuant: os << "channelQuant: " << ::android::internal::ToString(get<channelQuant>()); break;
    case extension: os << "extension: " << ::android::internal::ToString(get<extension>()); break;
    }
    os << "}";
    return os.str();
  }
private:
  std::variant<::aidl::android::hardware::neuralnetworks::SymmPerChannelQuantParams, std::vector<uint8_t>> _value;
};
}  // namespace neuralnetworks
}  // namespace hardware
}  // namespace android
}  // namespace aidl
