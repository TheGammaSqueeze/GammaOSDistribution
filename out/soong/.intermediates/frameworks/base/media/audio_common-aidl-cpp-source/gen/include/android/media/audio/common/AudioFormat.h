#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

namespace audio {

namespace common {

enum class AudioFormat : int32_t {
  INVALID = -1,
  DEFAULT = 0,
  PCM = 0,
  MP3 = 16777216,
  AMR_NB = 33554432,
  AMR_WB = 50331648,
  AAC = 67108864,
  HE_AAC_V1 = 83886080,
  HE_AAC_V2 = 100663296,
  VORBIS = 117440512,
  OPUS = 134217728,
  AC3 = 150994944,
  E_AC3 = 167772160,
  DTS = 184549376,
  DTS_HD = 201326592,
  IEC61937 = 218103808,
  DOLBY_TRUEHD = 234881024,
  EVRC = 268435456,
  EVRCB = 285212672,
  EVRCWB = 301989888,
  EVRCNW = 318767104,
  AAC_ADIF = 335544320,
  WMA = 352321536,
  WMA_PRO = 369098752,
  AMR_WB_PLUS = 385875968,
  MP2 = 402653184,
  QCELP = 419430400,
  DSD = 436207616,
  FLAC = 452984832,
  ALAC = 469762048,
  APE = 486539264,
  AAC_ADTS = 503316480,
  SBC = 520093696,
  APTX = 536870912,
  APTX_HD = 553648128,
  AC4 = 570425344,
  LDAC = 587202560,
  MAT = 603979776,
  AAC_LATM = 620756992,
  CELT = 637534208,
  APTX_ADAPTIVE = 654311424,
  LHDC = 671088640,
  LHDC_LL = 687865856,
  APTX_TWSP = 704643072,
  MAIN_MASK = -16777216,
  SUB_MASK = 16777215,
  PCM_SUB_16_BIT = 1,
  PCM_SUB_8_BIT = 2,
  PCM_SUB_32_BIT = 3,
  PCM_SUB_8_24_BIT = 4,
  PCM_SUB_FLOAT = 5,
  PCM_SUB_24_BIT_PACKED = 6,
  MP3_SUB_NONE = 0,
  AMR_SUB_NONE = 0,
  AAC_SUB_MAIN = 1,
  AAC_SUB_LC = 2,
  AAC_SUB_SSR = 4,
  AAC_SUB_LTP = 8,
  AAC_SUB_HE_V1 = 16,
  AAC_SUB_SCALABLE = 32,
  AAC_SUB_ERLC = 64,
  AAC_SUB_LD = 128,
  AAC_SUB_HE_V2 = 256,
  AAC_SUB_ELD = 512,
  AAC_SUB_XHE = 768,
  VORBIS_SUB_NONE = 0,
  E_AC3_SUB_JOC = 1,
  MAT_SUB_1_0 = 1,
  MAT_SUB_2_0 = 2,
  MAT_SUB_2_1 = 3,
};

[[nodiscard]] static inline std::string toString(AudioFormat val) {
  switch(val) {
  case AudioFormat::INVALID:
    return "INVALID";
  case AudioFormat::DEFAULT:
    return "DEFAULT";
  case AudioFormat::MP3:
    return "MP3";
  case AudioFormat::AMR_NB:
    return "AMR_NB";
  case AudioFormat::AMR_WB:
    return "AMR_WB";
  case AudioFormat::AAC:
    return "AAC";
  case AudioFormat::HE_AAC_V1:
    return "HE_AAC_V1";
  case AudioFormat::HE_AAC_V2:
    return "HE_AAC_V2";
  case AudioFormat::VORBIS:
    return "VORBIS";
  case AudioFormat::OPUS:
    return "OPUS";
  case AudioFormat::AC3:
    return "AC3";
  case AudioFormat::E_AC3:
    return "E_AC3";
  case AudioFormat::DTS:
    return "DTS";
  case AudioFormat::DTS_HD:
    return "DTS_HD";
  case AudioFormat::IEC61937:
    return "IEC61937";
  case AudioFormat::DOLBY_TRUEHD:
    return "DOLBY_TRUEHD";
  case AudioFormat::EVRC:
    return "EVRC";
  case AudioFormat::EVRCB:
    return "EVRCB";
  case AudioFormat::EVRCWB:
    return "EVRCWB";
  case AudioFormat::EVRCNW:
    return "EVRCNW";
  case AudioFormat::AAC_ADIF:
    return "AAC_ADIF";
  case AudioFormat::WMA:
    return "WMA";
  case AudioFormat::WMA_PRO:
    return "WMA_PRO";
  case AudioFormat::AMR_WB_PLUS:
    return "AMR_WB_PLUS";
  case AudioFormat::MP2:
    return "MP2";
  case AudioFormat::QCELP:
    return "QCELP";
  case AudioFormat::DSD:
    return "DSD";
  case AudioFormat::FLAC:
    return "FLAC";
  case AudioFormat::ALAC:
    return "ALAC";
  case AudioFormat::APE:
    return "APE";
  case AudioFormat::AAC_ADTS:
    return "AAC_ADTS";
  case AudioFormat::SBC:
    return "SBC";
  case AudioFormat::APTX:
    return "APTX";
  case AudioFormat::APTX_HD:
    return "APTX_HD";
  case AudioFormat::AC4:
    return "AC4";
  case AudioFormat::LDAC:
    return "LDAC";
  case AudioFormat::MAT:
    return "MAT";
  case AudioFormat::AAC_LATM:
    return "AAC_LATM";
  case AudioFormat::CELT:
    return "CELT";
  case AudioFormat::APTX_ADAPTIVE:
    return "APTX_ADAPTIVE";
  case AudioFormat::LHDC:
    return "LHDC";
  case AudioFormat::LHDC_LL:
    return "LHDC_LL";
  case AudioFormat::APTX_TWSP:
    return "APTX_TWSP";
  case AudioFormat::MAIN_MASK:
    return "MAIN_MASK";
  case AudioFormat::SUB_MASK:
    return "SUB_MASK";
  case AudioFormat::PCM_SUB_16_BIT:
    return "PCM_SUB_16_BIT";
  case AudioFormat::PCM_SUB_8_BIT:
    return "PCM_SUB_8_BIT";
  case AudioFormat::PCM_SUB_32_BIT:
    return "PCM_SUB_32_BIT";
  case AudioFormat::PCM_SUB_8_24_BIT:
    return "PCM_SUB_8_24_BIT";
  case AudioFormat::PCM_SUB_FLOAT:
    return "PCM_SUB_FLOAT";
  case AudioFormat::PCM_SUB_24_BIT_PACKED:
    return "PCM_SUB_24_BIT_PACKED";
  case AudioFormat::AAC_SUB_LTP:
    return "AAC_SUB_LTP";
  case AudioFormat::AAC_SUB_HE_V1:
    return "AAC_SUB_HE_V1";
  case AudioFormat::AAC_SUB_SCALABLE:
    return "AAC_SUB_SCALABLE";
  case AudioFormat::AAC_SUB_ERLC:
    return "AAC_SUB_ERLC";
  case AudioFormat::AAC_SUB_LD:
    return "AAC_SUB_LD";
  case AudioFormat::AAC_SUB_HE_V2:
    return "AAC_SUB_HE_V2";
  case AudioFormat::AAC_SUB_ELD:
    return "AAC_SUB_ELD";
  case AudioFormat::AAC_SUB_XHE:
    return "AAC_SUB_XHE";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}

}  // namespace common

}  // namespace audio

}  // namespace media

}  // namespace android
namespace android {

namespace internal {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::android::media::audio::common::AudioFormat, 70> enum_values<::android::media::audio::common::AudioFormat> = {
  ::android::media::audio::common::AudioFormat::INVALID,
  ::android::media::audio::common::AudioFormat::DEFAULT,
  ::android::media::audio::common::AudioFormat::PCM,
  ::android::media::audio::common::AudioFormat::MP3,
  ::android::media::audio::common::AudioFormat::AMR_NB,
  ::android::media::audio::common::AudioFormat::AMR_WB,
  ::android::media::audio::common::AudioFormat::AAC,
  ::android::media::audio::common::AudioFormat::HE_AAC_V1,
  ::android::media::audio::common::AudioFormat::HE_AAC_V2,
  ::android::media::audio::common::AudioFormat::VORBIS,
  ::android::media::audio::common::AudioFormat::OPUS,
  ::android::media::audio::common::AudioFormat::AC3,
  ::android::media::audio::common::AudioFormat::E_AC3,
  ::android::media::audio::common::AudioFormat::DTS,
  ::android::media::audio::common::AudioFormat::DTS_HD,
  ::android::media::audio::common::AudioFormat::IEC61937,
  ::android::media::audio::common::AudioFormat::DOLBY_TRUEHD,
  ::android::media::audio::common::AudioFormat::EVRC,
  ::android::media::audio::common::AudioFormat::EVRCB,
  ::android::media::audio::common::AudioFormat::EVRCWB,
  ::android::media::audio::common::AudioFormat::EVRCNW,
  ::android::media::audio::common::AudioFormat::AAC_ADIF,
  ::android::media::audio::common::AudioFormat::WMA,
  ::android::media::audio::common::AudioFormat::WMA_PRO,
  ::android::media::audio::common::AudioFormat::AMR_WB_PLUS,
  ::android::media::audio::common::AudioFormat::MP2,
  ::android::media::audio::common::AudioFormat::QCELP,
  ::android::media::audio::common::AudioFormat::DSD,
  ::android::media::audio::common::AudioFormat::FLAC,
  ::android::media::audio::common::AudioFormat::ALAC,
  ::android::media::audio::common::AudioFormat::APE,
  ::android::media::audio::common::AudioFormat::AAC_ADTS,
  ::android::media::audio::common::AudioFormat::SBC,
  ::android::media::audio::common::AudioFormat::APTX,
  ::android::media::audio::common::AudioFormat::APTX_HD,
  ::android::media::audio::common::AudioFormat::AC4,
  ::android::media::audio::common::AudioFormat::LDAC,
  ::android::media::audio::common::AudioFormat::MAT,
  ::android::media::audio::common::AudioFormat::AAC_LATM,
  ::android::media::audio::common::AudioFormat::CELT,
  ::android::media::audio::common::AudioFormat::APTX_ADAPTIVE,
  ::android::media::audio::common::AudioFormat::LHDC,
  ::android::media::audio::common::AudioFormat::LHDC_LL,
  ::android::media::audio::common::AudioFormat::APTX_TWSP,
  ::android::media::audio::common::AudioFormat::MAIN_MASK,
  ::android::media::audio::common::AudioFormat::SUB_MASK,
  ::android::media::audio::common::AudioFormat::PCM_SUB_16_BIT,
  ::android::media::audio::common::AudioFormat::PCM_SUB_8_BIT,
  ::android::media::audio::common::AudioFormat::PCM_SUB_32_BIT,
  ::android::media::audio::common::AudioFormat::PCM_SUB_8_24_BIT,
  ::android::media::audio::common::AudioFormat::PCM_SUB_FLOAT,
  ::android::media::audio::common::AudioFormat::PCM_SUB_24_BIT_PACKED,
  ::android::media::audio::common::AudioFormat::MP3_SUB_NONE,
  ::android::media::audio::common::AudioFormat::AMR_SUB_NONE,
  ::android::media::audio::common::AudioFormat::AAC_SUB_MAIN,
  ::android::media::audio::common::AudioFormat::AAC_SUB_LC,
  ::android::media::audio::common::AudioFormat::AAC_SUB_SSR,
  ::android::media::audio::common::AudioFormat::AAC_SUB_LTP,
  ::android::media::audio::common::AudioFormat::AAC_SUB_HE_V1,
  ::android::media::audio::common::AudioFormat::AAC_SUB_SCALABLE,
  ::android::media::audio::common::AudioFormat::AAC_SUB_ERLC,
  ::android::media::audio::common::AudioFormat::AAC_SUB_LD,
  ::android::media::audio::common::AudioFormat::AAC_SUB_HE_V2,
  ::android::media::audio::common::AudioFormat::AAC_SUB_ELD,
  ::android::media::audio::common::AudioFormat::AAC_SUB_XHE,
  ::android::media::audio::common::AudioFormat::VORBIS_SUB_NONE,
  ::android::media::audio::common::AudioFormat::E_AC3_SUB_JOC,
  ::android::media::audio::common::AudioFormat::MAT_SUB_1_0,
  ::android::media::audio::common::AudioFormat::MAT_SUB_2_0,
  ::android::media::audio::common::AudioFormat::MAT_SUB_2_1,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
