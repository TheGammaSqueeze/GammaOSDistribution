#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/gnss/CorrelationVector.h>
#include <android/hardware/gnss/GnssMultipathIndicator.h>
#include <android/hardware/gnss/GnssSignalType.h>
#include <android/hardware/gnss/SatellitePvt.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace hardware {

namespace gnss {

class GnssMeasurement : public ::android::Parcelable {
public:
  inline bool operator!=(const GnssMeasurement& rhs) const {
    return std::tie(flags, svid, signalType, timeOffsetNs, state, receivedSvTimeInNs, receivedSvTimeUncertaintyInNs, antennaCN0DbHz, basebandCN0DbHz, pseudorangeRateMps, pseudorangeRateUncertaintyMps, accumulatedDeltaRangeState, accumulatedDeltaRangeM, accumulatedDeltaRangeUncertaintyM, carrierCycles, carrierPhase, carrierPhaseUncertainty, multipathIndicator, snrDb, agcLevelDb, fullInterSignalBiasNs, fullInterSignalBiasUncertaintyNs, satelliteInterSignalBiasNs, satelliteInterSignalBiasUncertaintyNs, satellitePvt, correlationVectors) != std::tie(rhs.flags, rhs.svid, rhs.signalType, rhs.timeOffsetNs, rhs.state, rhs.receivedSvTimeInNs, rhs.receivedSvTimeUncertaintyInNs, rhs.antennaCN0DbHz, rhs.basebandCN0DbHz, rhs.pseudorangeRateMps, rhs.pseudorangeRateUncertaintyMps, rhs.accumulatedDeltaRangeState, rhs.accumulatedDeltaRangeM, rhs.accumulatedDeltaRangeUncertaintyM, rhs.carrierCycles, rhs.carrierPhase, rhs.carrierPhaseUncertainty, rhs.multipathIndicator, rhs.snrDb, rhs.agcLevelDb, rhs.fullInterSignalBiasNs, rhs.fullInterSignalBiasUncertaintyNs, rhs.satelliteInterSignalBiasNs, rhs.satelliteInterSignalBiasUncertaintyNs, rhs.satellitePvt, rhs.correlationVectors);
  }
  inline bool operator<(const GnssMeasurement& rhs) const {
    return std::tie(flags, svid, signalType, timeOffsetNs, state, receivedSvTimeInNs, receivedSvTimeUncertaintyInNs, antennaCN0DbHz, basebandCN0DbHz, pseudorangeRateMps, pseudorangeRateUncertaintyMps, accumulatedDeltaRangeState, accumulatedDeltaRangeM, accumulatedDeltaRangeUncertaintyM, carrierCycles, carrierPhase, carrierPhaseUncertainty, multipathIndicator, snrDb, agcLevelDb, fullInterSignalBiasNs, fullInterSignalBiasUncertaintyNs, satelliteInterSignalBiasNs, satelliteInterSignalBiasUncertaintyNs, satellitePvt, correlationVectors) < std::tie(rhs.flags, rhs.svid, rhs.signalType, rhs.timeOffsetNs, rhs.state, rhs.receivedSvTimeInNs, rhs.receivedSvTimeUncertaintyInNs, rhs.antennaCN0DbHz, rhs.basebandCN0DbHz, rhs.pseudorangeRateMps, rhs.pseudorangeRateUncertaintyMps, rhs.accumulatedDeltaRangeState, rhs.accumulatedDeltaRangeM, rhs.accumulatedDeltaRangeUncertaintyM, rhs.carrierCycles, rhs.carrierPhase, rhs.carrierPhaseUncertainty, rhs.multipathIndicator, rhs.snrDb, rhs.agcLevelDb, rhs.fullInterSignalBiasNs, rhs.fullInterSignalBiasUncertaintyNs, rhs.satelliteInterSignalBiasNs, rhs.satelliteInterSignalBiasUncertaintyNs, rhs.satellitePvt, rhs.correlationVectors);
  }
  inline bool operator<=(const GnssMeasurement& rhs) const {
    return std::tie(flags, svid, signalType, timeOffsetNs, state, receivedSvTimeInNs, receivedSvTimeUncertaintyInNs, antennaCN0DbHz, basebandCN0DbHz, pseudorangeRateMps, pseudorangeRateUncertaintyMps, accumulatedDeltaRangeState, accumulatedDeltaRangeM, accumulatedDeltaRangeUncertaintyM, carrierCycles, carrierPhase, carrierPhaseUncertainty, multipathIndicator, snrDb, agcLevelDb, fullInterSignalBiasNs, fullInterSignalBiasUncertaintyNs, satelliteInterSignalBiasNs, satelliteInterSignalBiasUncertaintyNs, satellitePvt, correlationVectors) <= std::tie(rhs.flags, rhs.svid, rhs.signalType, rhs.timeOffsetNs, rhs.state, rhs.receivedSvTimeInNs, rhs.receivedSvTimeUncertaintyInNs, rhs.antennaCN0DbHz, rhs.basebandCN0DbHz, rhs.pseudorangeRateMps, rhs.pseudorangeRateUncertaintyMps, rhs.accumulatedDeltaRangeState, rhs.accumulatedDeltaRangeM, rhs.accumulatedDeltaRangeUncertaintyM, rhs.carrierCycles, rhs.carrierPhase, rhs.carrierPhaseUncertainty, rhs.multipathIndicator, rhs.snrDb, rhs.agcLevelDb, rhs.fullInterSignalBiasNs, rhs.fullInterSignalBiasUncertaintyNs, rhs.satelliteInterSignalBiasNs, rhs.satelliteInterSignalBiasUncertaintyNs, rhs.satellitePvt, rhs.correlationVectors);
  }
  inline bool operator==(const GnssMeasurement& rhs) const {
    return std::tie(flags, svid, signalType, timeOffsetNs, state, receivedSvTimeInNs, receivedSvTimeUncertaintyInNs, antennaCN0DbHz, basebandCN0DbHz, pseudorangeRateMps, pseudorangeRateUncertaintyMps, accumulatedDeltaRangeState, accumulatedDeltaRangeM, accumulatedDeltaRangeUncertaintyM, carrierCycles, carrierPhase, carrierPhaseUncertainty, multipathIndicator, snrDb, agcLevelDb, fullInterSignalBiasNs, fullInterSignalBiasUncertaintyNs, satelliteInterSignalBiasNs, satelliteInterSignalBiasUncertaintyNs, satellitePvt, correlationVectors) == std::tie(rhs.flags, rhs.svid, rhs.signalType, rhs.timeOffsetNs, rhs.state, rhs.receivedSvTimeInNs, rhs.receivedSvTimeUncertaintyInNs, rhs.antennaCN0DbHz, rhs.basebandCN0DbHz, rhs.pseudorangeRateMps, rhs.pseudorangeRateUncertaintyMps, rhs.accumulatedDeltaRangeState, rhs.accumulatedDeltaRangeM, rhs.accumulatedDeltaRangeUncertaintyM, rhs.carrierCycles, rhs.carrierPhase, rhs.carrierPhaseUncertainty, rhs.multipathIndicator, rhs.snrDb, rhs.agcLevelDb, rhs.fullInterSignalBiasNs, rhs.fullInterSignalBiasUncertaintyNs, rhs.satelliteInterSignalBiasNs, rhs.satelliteInterSignalBiasUncertaintyNs, rhs.satellitePvt, rhs.correlationVectors);
  }
  inline bool operator>(const GnssMeasurement& rhs) const {
    return std::tie(flags, svid, signalType, timeOffsetNs, state, receivedSvTimeInNs, receivedSvTimeUncertaintyInNs, antennaCN0DbHz, basebandCN0DbHz, pseudorangeRateMps, pseudorangeRateUncertaintyMps, accumulatedDeltaRangeState, accumulatedDeltaRangeM, accumulatedDeltaRangeUncertaintyM, carrierCycles, carrierPhase, carrierPhaseUncertainty, multipathIndicator, snrDb, agcLevelDb, fullInterSignalBiasNs, fullInterSignalBiasUncertaintyNs, satelliteInterSignalBiasNs, satelliteInterSignalBiasUncertaintyNs, satellitePvt, correlationVectors) > std::tie(rhs.flags, rhs.svid, rhs.signalType, rhs.timeOffsetNs, rhs.state, rhs.receivedSvTimeInNs, rhs.receivedSvTimeUncertaintyInNs, rhs.antennaCN0DbHz, rhs.basebandCN0DbHz, rhs.pseudorangeRateMps, rhs.pseudorangeRateUncertaintyMps, rhs.accumulatedDeltaRangeState, rhs.accumulatedDeltaRangeM, rhs.accumulatedDeltaRangeUncertaintyM, rhs.carrierCycles, rhs.carrierPhase, rhs.carrierPhaseUncertainty, rhs.multipathIndicator, rhs.snrDb, rhs.agcLevelDb, rhs.fullInterSignalBiasNs, rhs.fullInterSignalBiasUncertaintyNs, rhs.satelliteInterSignalBiasNs, rhs.satelliteInterSignalBiasUncertaintyNs, rhs.satellitePvt, rhs.correlationVectors);
  }
  inline bool operator>=(const GnssMeasurement& rhs) const {
    return std::tie(flags, svid, signalType, timeOffsetNs, state, receivedSvTimeInNs, receivedSvTimeUncertaintyInNs, antennaCN0DbHz, basebandCN0DbHz, pseudorangeRateMps, pseudorangeRateUncertaintyMps, accumulatedDeltaRangeState, accumulatedDeltaRangeM, accumulatedDeltaRangeUncertaintyM, carrierCycles, carrierPhase, carrierPhaseUncertainty, multipathIndicator, snrDb, agcLevelDb, fullInterSignalBiasNs, fullInterSignalBiasUncertaintyNs, satelliteInterSignalBiasNs, satelliteInterSignalBiasUncertaintyNs, satellitePvt, correlationVectors) >= std::tie(rhs.flags, rhs.svid, rhs.signalType, rhs.timeOffsetNs, rhs.state, rhs.receivedSvTimeInNs, rhs.receivedSvTimeUncertaintyInNs, rhs.antennaCN0DbHz, rhs.basebandCN0DbHz, rhs.pseudorangeRateMps, rhs.pseudorangeRateUncertaintyMps, rhs.accumulatedDeltaRangeState, rhs.accumulatedDeltaRangeM, rhs.accumulatedDeltaRangeUncertaintyM, rhs.carrierCycles, rhs.carrierPhase, rhs.carrierPhaseUncertainty, rhs.multipathIndicator, rhs.snrDb, rhs.agcLevelDb, rhs.fullInterSignalBiasNs, rhs.fullInterSignalBiasUncertaintyNs, rhs.satelliteInterSignalBiasNs, rhs.satelliteInterSignalBiasUncertaintyNs, rhs.satellitePvt, rhs.correlationVectors);
  }

  int32_t flags = int32_t(0);
  int32_t svid = int32_t(0);
  ::android::hardware::gnss::GnssSignalType signalType;
  double timeOffsetNs = double(0.000000);
  int32_t state = int32_t(0);
  int64_t receivedSvTimeInNs = int64_t(0L);
  int64_t receivedSvTimeUncertaintyInNs = int64_t(0L);
  double antennaCN0DbHz = double(0.000000);
  double basebandCN0DbHz = double(0.000000);
  double pseudorangeRateMps = double(0.000000);
  double pseudorangeRateUncertaintyMps = double(0.000000);
  int32_t accumulatedDeltaRangeState = int32_t(0);
  double accumulatedDeltaRangeM = double(0.000000);
  double accumulatedDeltaRangeUncertaintyM = double(0.000000);
  int64_t carrierCycles = int64_t(0L);
  double carrierPhase = double(0.000000);
  double carrierPhaseUncertainty = double(0.000000);
  ::android::hardware::gnss::GnssMultipathIndicator multipathIndicator = ::android::hardware::gnss::GnssMultipathIndicator(::android::hardware::gnss::GnssMultipathIndicator::UNKNOWN);
  double snrDb = double(0.000000);
  double agcLevelDb = double(0.000000);
  double fullInterSignalBiasNs = double(0.000000);
  double fullInterSignalBiasUncertaintyNs = double(0.000000);
  double satelliteInterSignalBiasNs = double(0.000000);
  double satelliteInterSignalBiasUncertaintyNs = double(0.000000);
  ::android::hardware::gnss::SatellitePvt satellitePvt;
  ::std::vector<::android::hardware::gnss::CorrelationVector> correlationVectors;
  enum  : int32_t {
    HAS_SNR = 1,
    HAS_CARRIER_FREQUENCY = 512,
    HAS_CARRIER_CYCLES = 1024,
    HAS_CARRIER_PHASE = 2048,
    HAS_CARRIER_PHASE_UNCERTAINTY = 4096,
    HAS_AUTOMATIC_GAIN_CONTROL = 8192,
    HAS_FULL_ISB = 65536,
    HAS_FULL_ISB_UNCERTAINTY = 131072,
    HAS_SATELLITE_ISB = 262144,
    HAS_SATELLITE_ISB_UNCERTAINTY = 524288,
    HAS_SATELLITE_PVT = 1048576,
    HAS_CORRELATION_VECTOR = 2097152,
    STATE_UNKNOWN = 0,
    STATE_CODE_LOCK = 1,
    STATE_BIT_SYNC = 2,
    STATE_SUBFRAME_SYNC = 4,
    STATE_TOW_DECODED = 8,
    STATE_MSEC_AMBIGUOUS = 16,
    STATE_SYMBOL_SYNC = 32,
    STATE_GLO_STRING_SYNC = 64,
    STATE_GLO_TOD_DECODED = 128,
    STATE_BDS_D2_BIT_SYNC = 256,
    STATE_BDS_D2_SUBFRAME_SYNC = 512,
    STATE_GAL_E1BC_CODE_LOCK = 1024,
    STATE_GAL_E1C_2ND_CODE_LOCK = 2048,
    STATE_GAL_E1B_PAGE_SYNC = 4096,
    STATE_SBAS_SYNC = 8192,
    STATE_TOW_KNOWN = 16384,
    STATE_GLO_TOD_KNOWN = 32768,
    STATE_2ND_CODE_LOCK = 65536,
    ADR_STATE_UNKNOWN = 0,
    ADR_STATE_VALID = 1,
    ADR_STATE_RESET = 2,
    ADR_STATE_CYCLE_SLIP = 4,
    ADR_STATE_HALF_CYCLE_RESOLVED = 8,
  };
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.gnss.GnssMeasurement");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "GnssMeasurement{";
    os << "flags: " << ::android::internal::ToString(flags);
    os << ", svid: " << ::android::internal::ToString(svid);
    os << ", signalType: " << ::android::internal::ToString(signalType);
    os << ", timeOffsetNs: " << ::android::internal::ToString(timeOffsetNs);
    os << ", state: " << ::android::internal::ToString(state);
    os << ", receivedSvTimeInNs: " << ::android::internal::ToString(receivedSvTimeInNs);
    os << ", receivedSvTimeUncertaintyInNs: " << ::android::internal::ToString(receivedSvTimeUncertaintyInNs);
    os << ", antennaCN0DbHz: " << ::android::internal::ToString(antennaCN0DbHz);
    os << ", basebandCN0DbHz: " << ::android::internal::ToString(basebandCN0DbHz);
    os << ", pseudorangeRateMps: " << ::android::internal::ToString(pseudorangeRateMps);
    os << ", pseudorangeRateUncertaintyMps: " << ::android::internal::ToString(pseudorangeRateUncertaintyMps);
    os << ", accumulatedDeltaRangeState: " << ::android::internal::ToString(accumulatedDeltaRangeState);
    os << ", accumulatedDeltaRangeM: " << ::android::internal::ToString(accumulatedDeltaRangeM);
    os << ", accumulatedDeltaRangeUncertaintyM: " << ::android::internal::ToString(accumulatedDeltaRangeUncertaintyM);
    os << ", carrierCycles: " << ::android::internal::ToString(carrierCycles);
    os << ", carrierPhase: " << ::android::internal::ToString(carrierPhase);
    os << ", carrierPhaseUncertainty: " << ::android::internal::ToString(carrierPhaseUncertainty);
    os << ", multipathIndicator: " << ::android::internal::ToString(multipathIndicator);
    os << ", snrDb: " << ::android::internal::ToString(snrDb);
    os << ", agcLevelDb: " << ::android::internal::ToString(agcLevelDb);
    os << ", fullInterSignalBiasNs: " << ::android::internal::ToString(fullInterSignalBiasNs);
    os << ", fullInterSignalBiasUncertaintyNs: " << ::android::internal::ToString(fullInterSignalBiasUncertaintyNs);
    os << ", satelliteInterSignalBiasNs: " << ::android::internal::ToString(satelliteInterSignalBiasNs);
    os << ", satelliteInterSignalBiasUncertaintyNs: " << ::android::internal::ToString(satelliteInterSignalBiasUncertaintyNs);
    os << ", satellitePvt: " << ::android::internal::ToString(satellitePvt);
    os << ", correlationVectors: " << ::android::internal::ToString(correlationVectors);
    os << "}";
    return os.str();
  }
};  // class GnssMeasurement

}  // namespace gnss

}  // namespace hardware

}  // namespace android
