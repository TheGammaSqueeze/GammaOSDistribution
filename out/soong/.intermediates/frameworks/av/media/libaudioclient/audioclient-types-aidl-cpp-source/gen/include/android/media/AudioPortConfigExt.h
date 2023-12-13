#pragma once

#include <android/binder_to_string.h>
#include <android/media/AudioPortConfigDeviceExt.h>
#include <android/media/AudioPortConfigMixExt.h>
#include <android/media/AudioPortConfigSessionExt.h>
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

namespace media {

class AudioPortConfigExt : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioPortConfigExt& rhs) const {
    return _value != rhs._value;
  }
  inline bool operator<(const AudioPortConfigExt& rhs) const {
    return _value < rhs._value;
  }
  inline bool operator<=(const AudioPortConfigExt& rhs) const {
    return _value <= rhs._value;
  }
  inline bool operator==(const AudioPortConfigExt& rhs) const {
    return _value == rhs._value;
  }
  inline bool operator>(const AudioPortConfigExt& rhs) const {
    return _value > rhs._value;
  }
  inline bool operator>=(const AudioPortConfigExt& rhs) const {
    return _value >= rhs._value;
  }

  enum Tag : int32_t {
    unspecified = 0,  // boolean unspecified;
    device,  // android.media.AudioPortConfigDeviceExt device;
    mix,  // android.media.AudioPortConfigMixExt mix;
    session,  // android.media.AudioPortConfigSessionExt session;
  };

  template<typename _Tp>
  static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, AudioPortConfigExt>;

  AudioPortConfigExt() : _value(std::in_place_index<unspecified>, bool(false)) { }
  AudioPortConfigExt(const AudioPortConfigExt&) = default;
  AudioPortConfigExt(AudioPortConfigExt&&) = default;
  AudioPortConfigExt& operator=(const AudioPortConfigExt&) = default;
  AudioPortConfigExt& operator=(AudioPortConfigExt&&) = default;

  template <typename _Tp, typename = std::enable_if_t<_not_self<_Tp>>>
  // NOLINTNEXTLINE(google-explicit-constructor)
  constexpr AudioPortConfigExt(_Tp&& _arg)
      : _value(std::forward<_Tp>(_arg)) {}

  template <size_t _Np, typename... _Tp>
  constexpr explicit AudioPortConfigExt(std::in_place_index_t<_Np>, _Tp&&... _args)
      : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

  template <Tag _tag, typename... _Tp>
  static AudioPortConfigExt make(_Tp&&... _args) {
    return AudioPortConfigExt(std::in_place_index<_tag>, std::forward<_Tp>(_args)...);
  }

  template <Tag _tag, typename _Tp, typename... _Up>
  static AudioPortConfigExt make(std::initializer_list<_Tp> _il, _Up&&... _args) {
    return AudioPortConfigExt(std::in_place_index<_tag>, std::move(_il), std::forward<_Up>(_args)...);
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

  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.AudioPortConfigExt");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioPortConfigExt{";
    switch (getTag()) {
    case unspecified: os << "unspecified: " << ::android::internal::ToString(get<unspecified>()); break;
    case device: os << "device: " << ::android::internal::ToString(get<device>()); break;
    case mix: os << "mix: " << ::android::internal::ToString(get<mix>()); break;
    case session: os << "session: " << ::android::internal::ToString(get<session>()); break;
    }
    os << "}";
    return os.str();
  }
private:
  std::variant<bool, ::android::media::AudioPortConfigDeviceExt, ::android::media::AudioPortConfigMixExt, ::android::media::AudioPortConfigSessionExt> _value;
};  // class AudioPortConfigExt

}  // namespace media

}  // namespace android
