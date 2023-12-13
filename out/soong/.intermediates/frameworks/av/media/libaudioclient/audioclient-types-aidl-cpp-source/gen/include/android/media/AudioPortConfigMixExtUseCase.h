#pragma once

#include <android/binder_to_string.h>
#include <android/media/AudioSourceType.h>
#include <android/media/AudioStreamType.h>
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

class AudioPortConfigMixExtUseCase : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioPortConfigMixExtUseCase& rhs) const {
    return _value != rhs._value;
  }
  inline bool operator<(const AudioPortConfigMixExtUseCase& rhs) const {
    return _value < rhs._value;
  }
  inline bool operator<=(const AudioPortConfigMixExtUseCase& rhs) const {
    return _value <= rhs._value;
  }
  inline bool operator==(const AudioPortConfigMixExtUseCase& rhs) const {
    return _value == rhs._value;
  }
  inline bool operator>(const AudioPortConfigMixExtUseCase& rhs) const {
    return _value > rhs._value;
  }
  inline bool operator>=(const AudioPortConfigMixExtUseCase& rhs) const {
    return _value >= rhs._value;
  }

  enum Tag : int32_t {
    unspecified = 0,  // boolean unspecified;
    stream,  // android.media.AudioStreamType stream;
    source,  // android.media.AudioSourceType source;
  };

  template<typename _Tp>
  static constexpr bool _not_self = !std::is_same_v<std::remove_cv_t<std::remove_reference_t<_Tp>>, AudioPortConfigMixExtUseCase>;

  AudioPortConfigMixExtUseCase() : _value(std::in_place_index<unspecified>, bool(false)) { }
  AudioPortConfigMixExtUseCase(const AudioPortConfigMixExtUseCase&) = default;
  AudioPortConfigMixExtUseCase(AudioPortConfigMixExtUseCase&&) = default;
  AudioPortConfigMixExtUseCase& operator=(const AudioPortConfigMixExtUseCase&) = default;
  AudioPortConfigMixExtUseCase& operator=(AudioPortConfigMixExtUseCase&&) = default;

  template <typename _Tp, typename = std::enable_if_t<_not_self<_Tp>>>
  // NOLINTNEXTLINE(google-explicit-constructor)
  constexpr AudioPortConfigMixExtUseCase(_Tp&& _arg)
      : _value(std::forward<_Tp>(_arg)) {}

  template <size_t _Np, typename... _Tp>
  constexpr explicit AudioPortConfigMixExtUseCase(std::in_place_index_t<_Np>, _Tp&&... _args)
      : _value(std::in_place_index<_Np>, std::forward<_Tp>(_args)...) {}

  template <Tag _tag, typename... _Tp>
  static AudioPortConfigMixExtUseCase make(_Tp&&... _args) {
    return AudioPortConfigMixExtUseCase(std::in_place_index<_tag>, std::forward<_Tp>(_args)...);
  }

  template <Tag _tag, typename _Tp, typename... _Up>
  static AudioPortConfigMixExtUseCase make(std::initializer_list<_Tp> _il, _Up&&... _args) {
    return AudioPortConfigMixExtUseCase(std::in_place_index<_tag>, std::move(_il), std::forward<_Up>(_args)...);
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
    static const ::android::StaticString16 DESCIPTOR (u"android.media.AudioPortConfigMixExtUseCase");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioPortConfigMixExtUseCase{";
    switch (getTag()) {
    case unspecified: os << "unspecified: " << ::android::internal::ToString(get<unspecified>()); break;
    case stream: os << "stream: " << ::android::internal::ToString(get<stream>()); break;
    case source: os << "source: " << ::android::internal::ToString(get<source>()); break;
    }
    os << "}";
    return os.str();
  }
private:
  std::variant<bool, ::android::media::AudioStreamType, ::android::media::AudioSourceType> _value;
};  // class AudioPortConfigMixExtUseCase

}  // namespace media

}  // namespace android
