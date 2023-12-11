package android.hardware.gnss.V1_0;

/**
 * The callback interface to report measurements from the HAL.
 */
public interface IGnssMeasurementCallback extends android.hidl.base.V1_0.IBase {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.gnss@1.0::IGnssMeasurementCallback";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static IGnssMeasurementCallback asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof IGnssMeasurementCallback)) {
            return (IGnssMeasurementCallback)iface;
        }

        IGnssMeasurementCallback proxy = new IGnssMeasurementCallback.Proxy(binder);

        try {
            for (String descriptor : proxy.interfaceChain()) {
                if (descriptor.equals(kInterfaceName)) {
                    return proxy;
                }
            }
        } catch (android.os.RemoteException e) {
        }

        return null;
    }

    /**
     * Does a checked conversion from any interface to this class.
     */
    public static IGnssMeasurementCallback castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : IGnssMeasurementCallback.asInterface(iface.asBinder());
    }

    @Override
    public android.os.IHwBinder asBinder();

    /**
     * This will invoke the equivalent of the C++ getService(std::string) if retry is
     * true or tryGetService(std::string) if retry is false. If the service is
     * available on the device and retry is true, this will wait for the service to
     * start.
     *
     * @throws NoSuchElementException if this service is not available
     */
    public static IGnssMeasurementCallback getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return IGnssMeasurementCallback.asInterface(android.os.HwBinder.getService("android.hardware.gnss@1.0::IGnssMeasurementCallback", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static IGnssMeasurementCallback getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static IGnssMeasurementCallback getService(String serviceName) throws android.os.RemoteException {
        return IGnssMeasurementCallback.asInterface(android.os.HwBinder.getService("android.hardware.gnss@1.0::IGnssMeasurementCallback", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static IGnssMeasurementCallback getService() throws android.os.RemoteException {
        return getService("default");
    }

    /**
     * Flags to indicate what fields in GnssClock are valid.
     */
    public static final class GnssClockFlags {
        /**
         * A valid 'leap second' is stored in the data structure.
         */
        public static final short HAS_LEAP_SECOND = 1 /* 1 << 0 */;
        /**
         * A valid 'time uncertainty' is stored in the data structure.
         */
        public static final short HAS_TIME_UNCERTAINTY = 2 /* 1 << 1 */;
        /**
         * A valid 'full bias' is stored in the data structure.
         */
        public static final short HAS_FULL_BIAS = 4 /* 1 << 2 */;
        /**
         * A valid 'bias' is stored in the data structure.
         */
        public static final short HAS_BIAS = 8 /* 1 << 3 */;
        /**
         * A valid 'bias uncertainty' is stored in the data structure.
         */
        public static final short HAS_BIAS_UNCERTAINTY = 16 /* 1 << 4 */;
        /**
         * A valid 'drift' is stored in the data structure.
         */
        public static final short HAS_DRIFT = 32 /* 1 << 5 */;
        /**
         * A valid 'drift uncertainty' is stored in the data structure.
         */
        public static final short HAS_DRIFT_UNCERTAINTY = 64 /* 1 << 6 */;
        public static final String toString(short o) {
            if (o == HAS_LEAP_SECOND) {
                return "HAS_LEAP_SECOND";
            }
            if (o == HAS_TIME_UNCERTAINTY) {
                return "HAS_TIME_UNCERTAINTY";
            }
            if (o == HAS_FULL_BIAS) {
                return "HAS_FULL_BIAS";
            }
            if (o == HAS_BIAS) {
                return "HAS_BIAS";
            }
            if (o == HAS_BIAS_UNCERTAINTY) {
                return "HAS_BIAS_UNCERTAINTY";
            }
            if (o == HAS_DRIFT) {
                return "HAS_DRIFT";
            }
            if (o == HAS_DRIFT_UNCERTAINTY) {
                return "HAS_DRIFT_UNCERTAINTY";
            }
            return "0x" + Integer.toHexString(Short.toUnsignedInt((short)(o)));
        }

        public static final String dumpBitfield(short o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            short flipped = 0;
            if ((o & HAS_LEAP_SECOND) == HAS_LEAP_SECOND) {
                list.add("HAS_LEAP_SECOND");
                flipped |= HAS_LEAP_SECOND;
            }
            if ((o & HAS_TIME_UNCERTAINTY) == HAS_TIME_UNCERTAINTY) {
                list.add("HAS_TIME_UNCERTAINTY");
                flipped |= HAS_TIME_UNCERTAINTY;
            }
            if ((o & HAS_FULL_BIAS) == HAS_FULL_BIAS) {
                list.add("HAS_FULL_BIAS");
                flipped |= HAS_FULL_BIAS;
            }
            if ((o & HAS_BIAS) == HAS_BIAS) {
                list.add("HAS_BIAS");
                flipped |= HAS_BIAS;
            }
            if ((o & HAS_BIAS_UNCERTAINTY) == HAS_BIAS_UNCERTAINTY) {
                list.add("HAS_BIAS_UNCERTAINTY");
                flipped |= HAS_BIAS_UNCERTAINTY;
            }
            if ((o & HAS_DRIFT) == HAS_DRIFT) {
                list.add("HAS_DRIFT");
                flipped |= HAS_DRIFT;
            }
            if ((o & HAS_DRIFT_UNCERTAINTY) == HAS_DRIFT_UNCERTAINTY) {
                list.add("HAS_DRIFT_UNCERTAINTY");
                flipped |= HAS_DRIFT_UNCERTAINTY;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(Short.toUnsignedInt((short)(o & (~flipped)))));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Flags to indicate what fields in GnssMeasurement are valid.
     */
    public static final class GnssMeasurementFlags {
        /**
         * A valid 'snr' is stored in the data structure.
         */
        public static final int HAS_SNR = 1 /* 1 << 0 */;
        /**
         * A valid 'carrier frequency' is stored in the data structure.
         */
        public static final int HAS_CARRIER_FREQUENCY = 512 /* 1 << 9 */;
        /**
         * A valid 'carrier cycles' is stored in the data structure.
         */
        public static final int HAS_CARRIER_CYCLES = 1024 /* 1 << 10 */;
        /**
         * A valid 'carrier phase' is stored in the data structure.
         */
        public static final int HAS_CARRIER_PHASE = 2048 /* 1 << 11 */;
        /**
         * A valid 'carrier phase uncertainty' is stored in the data structure.
         */
        public static final int HAS_CARRIER_PHASE_UNCERTAINTY = 4096 /* 1 << 12 */;
        /**
         * A valid automatic gain control is stored in the data structure.
         */
        public static final int HAS_AUTOMATIC_GAIN_CONTROL = 8192 /* 1 << 13 */;
        public static final String toString(int o) {
            if (o == HAS_SNR) {
                return "HAS_SNR";
            }
            if (o == HAS_CARRIER_FREQUENCY) {
                return "HAS_CARRIER_FREQUENCY";
            }
            if (o == HAS_CARRIER_CYCLES) {
                return "HAS_CARRIER_CYCLES";
            }
            if (o == HAS_CARRIER_PHASE) {
                return "HAS_CARRIER_PHASE";
            }
            if (o == HAS_CARRIER_PHASE_UNCERTAINTY) {
                return "HAS_CARRIER_PHASE_UNCERTAINTY";
            }
            if (o == HAS_AUTOMATIC_GAIN_CONTROL) {
                return "HAS_AUTOMATIC_GAIN_CONTROL";
            }
            return "0x" + Integer.toHexString(o);
        }

        public static final String dumpBitfield(int o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            int flipped = 0;
            if ((o & HAS_SNR) == HAS_SNR) {
                list.add("HAS_SNR");
                flipped |= HAS_SNR;
            }
            if ((o & HAS_CARRIER_FREQUENCY) == HAS_CARRIER_FREQUENCY) {
                list.add("HAS_CARRIER_FREQUENCY");
                flipped |= HAS_CARRIER_FREQUENCY;
            }
            if ((o & HAS_CARRIER_CYCLES) == HAS_CARRIER_CYCLES) {
                list.add("HAS_CARRIER_CYCLES");
                flipped |= HAS_CARRIER_CYCLES;
            }
            if ((o & HAS_CARRIER_PHASE) == HAS_CARRIER_PHASE) {
                list.add("HAS_CARRIER_PHASE");
                flipped |= HAS_CARRIER_PHASE;
            }
            if ((o & HAS_CARRIER_PHASE_UNCERTAINTY) == HAS_CARRIER_PHASE_UNCERTAINTY) {
                list.add("HAS_CARRIER_PHASE_UNCERTAINTY");
                flipped |= HAS_CARRIER_PHASE_UNCERTAINTY;
            }
            if ((o & HAS_AUTOMATIC_GAIN_CONTROL) == HAS_AUTOMATIC_GAIN_CONTROL) {
                list.add("HAS_AUTOMATIC_GAIN_CONTROL");
                flipped |= HAS_AUTOMATIC_GAIN_CONTROL;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(o & (~flipped)));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Enumeration of available values for the GNSS Measurement's multipath
     * indicator.
     */
    public static final class GnssMultipathIndicator {
        /**
         * The indicator is not available or unknown.
         */
        public static final byte INDICATOR_UNKNOWN = 0;
        /**
         * The measurement is indicated to be affected by multipath.
         */
        public static final byte INDICATOR_PRESENT = 1;
        /**
         * The measurement is indicated to be not affected by multipath.
         */
        public static final byte INDICATIOR_NOT_PRESENT = 2;
        public static final String toString(byte o) {
            if (o == INDICATOR_UNKNOWN) {
                return "INDICATOR_UNKNOWN";
            }
            if (o == INDICATOR_PRESENT) {
                return "INDICATOR_PRESENT";
            }
            if (o == INDICATIOR_NOT_PRESENT) {
                return "INDICATIOR_NOT_PRESENT";
            }
            return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
        }

        public static final String dumpBitfield(byte o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            byte flipped = 0;
            list.add("INDICATOR_UNKNOWN"); // INDICATOR_UNKNOWN == 0
            if ((o & INDICATOR_PRESENT) == INDICATOR_PRESENT) {
                list.add("INDICATOR_PRESENT");
                flipped |= INDICATOR_PRESENT;
            }
            if ((o & INDICATIOR_NOT_PRESENT) == INDICATIOR_NOT_PRESENT) {
                list.add("INDICATIOR_NOT_PRESENT");
                flipped |= INDICATIOR_NOT_PRESENT;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Flags indicating the GNSS measurement state.
     *
     * The expected behavior here is for GNSS HAL to set all the flags that applies.
     * For example, if the state for a satellite is only C/A code locked and bit
     * synchronized, and there is still millisecond ambiguity, the state must be
     * set as:
     *
     * STATE_CODE_LOCK | STATE_BIT_SYNC |  STATE_MSEC_AMBIGUOUS
     *
     * If GNSS is still searching for a satellite, the corresponding state must be
     * set to STATE_UNKNOWN(0).
     */
    public static final class GnssMeasurementState {
        public static final int STATE_UNKNOWN = 0;
        public static final int STATE_CODE_LOCK = 1 /* 1 << 0 */;
        public static final int STATE_BIT_SYNC = 2 /* 1 << 1 */;
        public static final int STATE_SUBFRAME_SYNC = 4 /* 1 << 2 */;
        public static final int STATE_TOW_DECODED = 8 /* 1 << 3 */;
        public static final int STATE_MSEC_AMBIGUOUS = 16 /* 1 << 4 */;
        public static final int STATE_SYMBOL_SYNC = 32 /* 1 << 5 */;
        public static final int STATE_GLO_STRING_SYNC = 64 /* 1 << 6 */;
        public static final int STATE_GLO_TOD_DECODED = 128 /* 1 << 7 */;
        public static final int STATE_BDS_D2_BIT_SYNC = 256 /* 1 << 8 */;
        public static final int STATE_BDS_D2_SUBFRAME_SYNC = 512 /* 1 << 9 */;
        public static final int STATE_GAL_E1BC_CODE_LOCK = 1024 /* 1 << 10 */;
        public static final int STATE_GAL_E1C_2ND_CODE_LOCK = 2048 /* 1 << 11 */;
        public static final int STATE_GAL_E1B_PAGE_SYNC = 4096 /* 1 << 12 */;
        public static final int STATE_SBAS_SYNC = 8192 /* 1 << 13 */;
        public static final int STATE_TOW_KNOWN = 16384 /* 1 << 14 */;
        public static final int STATE_GLO_TOD_KNOWN = 32768 /* 1 << 15 */;
        public static final String toString(int o) {
            if (o == STATE_UNKNOWN) {
                return "STATE_UNKNOWN";
            }
            if (o == STATE_CODE_LOCK) {
                return "STATE_CODE_LOCK";
            }
            if (o == STATE_BIT_SYNC) {
                return "STATE_BIT_SYNC";
            }
            if (o == STATE_SUBFRAME_SYNC) {
                return "STATE_SUBFRAME_SYNC";
            }
            if (o == STATE_TOW_DECODED) {
                return "STATE_TOW_DECODED";
            }
            if (o == STATE_MSEC_AMBIGUOUS) {
                return "STATE_MSEC_AMBIGUOUS";
            }
            if (o == STATE_SYMBOL_SYNC) {
                return "STATE_SYMBOL_SYNC";
            }
            if (o == STATE_GLO_STRING_SYNC) {
                return "STATE_GLO_STRING_SYNC";
            }
            if (o == STATE_GLO_TOD_DECODED) {
                return "STATE_GLO_TOD_DECODED";
            }
            if (o == STATE_BDS_D2_BIT_SYNC) {
                return "STATE_BDS_D2_BIT_SYNC";
            }
            if (o == STATE_BDS_D2_SUBFRAME_SYNC) {
                return "STATE_BDS_D2_SUBFRAME_SYNC";
            }
            if (o == STATE_GAL_E1BC_CODE_LOCK) {
                return "STATE_GAL_E1BC_CODE_LOCK";
            }
            if (o == STATE_GAL_E1C_2ND_CODE_LOCK) {
                return "STATE_GAL_E1C_2ND_CODE_LOCK";
            }
            if (o == STATE_GAL_E1B_PAGE_SYNC) {
                return "STATE_GAL_E1B_PAGE_SYNC";
            }
            if (o == STATE_SBAS_SYNC) {
                return "STATE_SBAS_SYNC";
            }
            if (o == STATE_TOW_KNOWN) {
                return "STATE_TOW_KNOWN";
            }
            if (o == STATE_GLO_TOD_KNOWN) {
                return "STATE_GLO_TOD_KNOWN";
            }
            return "0x" + Integer.toHexString(o);
        }

        public static final String dumpBitfield(int o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            int flipped = 0;
            list.add("STATE_UNKNOWN"); // STATE_UNKNOWN == 0
            if ((o & STATE_CODE_LOCK) == STATE_CODE_LOCK) {
                list.add("STATE_CODE_LOCK");
                flipped |= STATE_CODE_LOCK;
            }
            if ((o & STATE_BIT_SYNC) == STATE_BIT_SYNC) {
                list.add("STATE_BIT_SYNC");
                flipped |= STATE_BIT_SYNC;
            }
            if ((o & STATE_SUBFRAME_SYNC) == STATE_SUBFRAME_SYNC) {
                list.add("STATE_SUBFRAME_SYNC");
                flipped |= STATE_SUBFRAME_SYNC;
            }
            if ((o & STATE_TOW_DECODED) == STATE_TOW_DECODED) {
                list.add("STATE_TOW_DECODED");
                flipped |= STATE_TOW_DECODED;
            }
            if ((o & STATE_MSEC_AMBIGUOUS) == STATE_MSEC_AMBIGUOUS) {
                list.add("STATE_MSEC_AMBIGUOUS");
                flipped |= STATE_MSEC_AMBIGUOUS;
            }
            if ((o & STATE_SYMBOL_SYNC) == STATE_SYMBOL_SYNC) {
                list.add("STATE_SYMBOL_SYNC");
                flipped |= STATE_SYMBOL_SYNC;
            }
            if ((o & STATE_GLO_STRING_SYNC) == STATE_GLO_STRING_SYNC) {
                list.add("STATE_GLO_STRING_SYNC");
                flipped |= STATE_GLO_STRING_SYNC;
            }
            if ((o & STATE_GLO_TOD_DECODED) == STATE_GLO_TOD_DECODED) {
                list.add("STATE_GLO_TOD_DECODED");
                flipped |= STATE_GLO_TOD_DECODED;
            }
            if ((o & STATE_BDS_D2_BIT_SYNC) == STATE_BDS_D2_BIT_SYNC) {
                list.add("STATE_BDS_D2_BIT_SYNC");
                flipped |= STATE_BDS_D2_BIT_SYNC;
            }
            if ((o & STATE_BDS_D2_SUBFRAME_SYNC) == STATE_BDS_D2_SUBFRAME_SYNC) {
                list.add("STATE_BDS_D2_SUBFRAME_SYNC");
                flipped |= STATE_BDS_D2_SUBFRAME_SYNC;
            }
            if ((o & STATE_GAL_E1BC_CODE_LOCK) == STATE_GAL_E1BC_CODE_LOCK) {
                list.add("STATE_GAL_E1BC_CODE_LOCK");
                flipped |= STATE_GAL_E1BC_CODE_LOCK;
            }
            if ((o & STATE_GAL_E1C_2ND_CODE_LOCK) == STATE_GAL_E1C_2ND_CODE_LOCK) {
                list.add("STATE_GAL_E1C_2ND_CODE_LOCK");
                flipped |= STATE_GAL_E1C_2ND_CODE_LOCK;
            }
            if ((o & STATE_GAL_E1B_PAGE_SYNC) == STATE_GAL_E1B_PAGE_SYNC) {
                list.add("STATE_GAL_E1B_PAGE_SYNC");
                flipped |= STATE_GAL_E1B_PAGE_SYNC;
            }
            if ((o & STATE_SBAS_SYNC) == STATE_SBAS_SYNC) {
                list.add("STATE_SBAS_SYNC");
                flipped |= STATE_SBAS_SYNC;
            }
            if ((o & STATE_TOW_KNOWN) == STATE_TOW_KNOWN) {
                list.add("STATE_TOW_KNOWN");
                flipped |= STATE_TOW_KNOWN;
            }
            if ((o & STATE_GLO_TOD_KNOWN) == STATE_GLO_TOD_KNOWN) {
                list.add("STATE_GLO_TOD_KNOWN");
                flipped |= STATE_GLO_TOD_KNOWN;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(o & (~flipped)));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Flags indicating the Accumulated Delta Range's states.
     *
     * See the table below for a detailed interpretation of each state.
     *
     * +---------------------+-------------------+-----------------------------+
     * | ADR_STATE           | Time of relevance | Interpretation              |
     * +---------------------+-------------------+-----------------------------+
     * | UNKNOWN             | ADR(t)            | No valid carrier phase      |
     * |                     |                   | information is available    |
     * |                     |                   | at time t.                  |
     * +---------------------+-------------------+-----------------------------+
     * | VALID               | ADR(t)            | Valid carrier phase         |
     * |                     |                   | information is available    |
     * |                     |                   | at time t. This indicates   |
     * |                     |                   | that this measurement can   |
     * |                     |                   | be used as a reference for  |
     * |                     |                   | future measurements.        |
     * |                     |                   | However, to compare it to   |
     * |                     |                   | previous measurements to    |
     * |                     |                   | compute delta range,        |
     * |                     |                   | other bits should be        |
     * |                     |                   | checked. Specifically, it   |
     * |                     |                   | can be used for delta range |
     * |                     |                   | computation if it is valid  |
     * |                     |                   | and has no reset or cycle   |
     * |                     |                   | slip at this epoch i.e.     |
     * |                     |                   | if VALID_BIT == 1 &&        |
     * |                     |                   | CYCLE_SLIP_BIT == 0 &&      |
     * |                     |                   | RESET_BIT == 0.             |
     * +---------------------+-------------------+-----------------------------+
     * | RESET               | ADR(t) - ADR(t-1) | Carrier phase accumulation  |
     * |                     |                   | has been restarted between  |
     * |                     |                   | current time t and previous |
     * |                     |                   | time t-1. This indicates    |
     * |                     |                   | that this measurement can   |
     * |                     |                   | be used as a reference for  |
     * |                     |                   | future measurements, but it |
     * |                     |                   | should not be compared to   |
     * |                     |                   | previous measurements to    |
     * |                     |                   | compute delta range.        |
     * +---------------------+-------------------+-----------------------------+
     * | CYCLE_SLIP          | ADR(t) - ADR(t-1) | Cycle slip(s) have been     |
     * |                     |                   | detected between the        |
     * |                     |                   | current time t and previous |
     * |                     |                   | time t-1. This indicates    |
     * |                     |                   | that this measurement can   |
     * |                     |                   | be used as a reference for  |
     * |                     |                   | future measurements.        |
     * |                     |                   | Clients can use a           |
     * |                     |                   | measurement with a cycle    |
     * |                     |                   | slip to compute delta range |
     * |                     |                   | against previous            |
     * |                     |                   | measurements at their own   |
     * |                     |                   | risk.                       |
     * +---------------------+-------------------+-----------------------------+
     *
     */
    public static final class GnssAccumulatedDeltaRangeState {
        public static final short ADR_STATE_UNKNOWN = 0;
        public static final short ADR_STATE_VALID = 1 /* 1 << 0 */;
        public static final short ADR_STATE_RESET = 2 /* 1 << 1 */;
        public static final short ADR_STATE_CYCLE_SLIP = 4 /* 1 << 2 */;
        public static final String toString(short o) {
            if (o == ADR_STATE_UNKNOWN) {
                return "ADR_STATE_UNKNOWN";
            }
            if (o == ADR_STATE_VALID) {
                return "ADR_STATE_VALID";
            }
            if (o == ADR_STATE_RESET) {
                return "ADR_STATE_RESET";
            }
            if (o == ADR_STATE_CYCLE_SLIP) {
                return "ADR_STATE_CYCLE_SLIP";
            }
            return "0x" + Integer.toHexString(Short.toUnsignedInt((short)(o)));
        }

        public static final String dumpBitfield(short o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            short flipped = 0;
            list.add("ADR_STATE_UNKNOWN"); // ADR_STATE_UNKNOWN == 0
            if ((o & ADR_STATE_VALID) == ADR_STATE_VALID) {
                list.add("ADR_STATE_VALID");
                flipped |= ADR_STATE_VALID;
            }
            if ((o & ADR_STATE_RESET) == ADR_STATE_RESET) {
                list.add("ADR_STATE_RESET");
                flipped |= ADR_STATE_RESET;
            }
            if ((o & ADR_STATE_CYCLE_SLIP) == ADR_STATE_CYCLE_SLIP) {
                list.add("ADR_STATE_CYCLE_SLIP");
                flipped |= ADR_STATE_CYCLE_SLIP;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(Short.toUnsignedInt((short)(o & (~flipped)))));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Represents an estimate of the GNSS clock time.
     */
    public final static class GnssClock {
        /**
         * A set of flags indicating the validity of the fields in this data
         * structure.
         *
         * Fields for which there is no corresponding flag must be filled in
         * with a valid value.  For convenience, these are marked as mandatory.
         *
         * Others fields may have invalid information in them, if not marked as
         * valid by the corresponding bit in gnssClockFlags.
         */
        public short gnssClockFlags;
        /**
         * Leap second data.
         * The sign of the value is defined by the following equation:
         *      utcTimeNs = timeNs - (fullBiasNs + biasNs) - leapSecond *
         *      1,000,000,000
         *
         * If this data is available, gnssClockFlags must contain
         * HAS_LEAP_SECOND.
         */
        public short leapSecond = 0;
        /**
         * The GNSS receiver internal clock value. This is the local hardware clock
         * value.
         *
         * For local hardware clock, this value is expected to be monotonically
         * increasing while the hardware clock remains powered on. (For the case of a
         * HW clock that is not continuously on, see the
         * hwClockDiscontinuityCount field). The receiver's estimate of GNSS time
         * can be derived by subtracting the sum of fullBiasNs and biasNs (when
         * available) from this value.
         *
         * This GNSS time must be the best estimate of current GNSS time
         * that GNSS receiver can achieve.
         *
         * Sub-nanosecond accuracy can be provided by means of the 'biasNs' field.
         * The value contains the timeUncertaintyNs in it.
         *
         * This value is mandatory.
         */
        public long timeNs = 0L;
        /**
         * 1-Sigma uncertainty associated with the clock's time in nanoseconds.
         * The uncertainty is represented as an absolute (single sided) value.
         *
         * If the data is available, gnssClockFlags must contain
         * HAS_TIME_UNCERTAINTY. Ths value is ideally zero, as the time
         * 'latched' by timeNs is defined as the reference clock vs. which all
         * other times (and corresponding uncertainties) are measured.
         */
        public double timeUncertaintyNs = 0.0d;
        /**
         * The difference between hardware clock ('time' field) inside GNSS receiver
         * and the true GPS time since 0000Z, January 6, 1980, in nanoseconds.
         *
         * The sign of the value is defined by the following equation:
         *      local estimate of GPS time = timeNs - (fullBiasNs + biasNs)
         *
         * If receiver has computed time for a non-GPS constellation, the time offset of
         * that constellation versus GPS time must be applied to fill this value.
         *
         * The error estimate for the sum of this and the biasNs is the biasUncertaintyNs.
         *
         * If the data is available gnssClockFlags must contain HAS_FULL_BIAS.
         *
         * This value is mandatory if the receiver has estimated GPS time.
         */
        public long fullBiasNs = 0L;
        /**
         * Sub-nanosecond bias - used with fullBiasNS, see fullBiasNs for details.
         *
         * The error estimate for the sum of this and the fullBiasNs is the
         * biasUncertaintyNs.
         *
         * If the data is available gnssClockFlags must contain HAS_BIAS.
         *
         * This value is mandatory if the receiver has estimated GPS time.
         */
        public double biasNs = 0.0d;
        /**
         * 1-Sigma uncertainty associated with the local estimate of GNSS time (clock
         * bias) in nanoseconds. The uncertainty is represented as an absolute
         * (single sided) value.
         *
         * The caller is responsible for using this uncertainty (it can be very
         * large before the GPS time has been fully resolved.)
         *
         * If the data is available gnssClockFlags must contain HAS_BIAS_UNCERTAINTY.
         *
         * This value is mandatory if the receiver has estimated GPS time.
         */
        public double biasUncertaintyNs = 0.0d;
        /**
         * The clock's drift in nanoseconds (per second).
         *
         * A positive value means that the frequency is higher than the nominal
         * frequency, and that the (fullBiasNs + biasNs) is growing more positive
         * over time.
         *
         * If the data is available gnssClockFlags must contain HAS_DRIFT.
         *
         * This value is mandatory if the receiver has estimated GPS time.
         */
        public double driftNsps = 0.0d;
        /**
         * 1-Sigma uncertainty associated with the clock's drift in nanoseconds (per
         * second).
         * The uncertainty is represented as an absolute (single sided) value.
         *
         * If the data is available gnssClockFlags must contain HAS_DRIFT_UNCERTAINTY.
         *
         * This value is mandatory if the receiver has estimated GPS time.
         */
        public double driftUncertaintyNsps = 0.0d;
        /**
         * This field must be incremented, when there are discontinuities in the
         * hardware clock.
         *
         * A "discontinuity" is meant to cover the case of a switch from one source
         * of clock to another.  A single free-running crystal oscillator (XO)
         * will generally not have any discontinuities, and this can be set and
         * left at 0.
         *
         * If, however, the timeNs value (HW clock) is derived from a composite of
         * sources, that is not as smooth as a typical XO, or is otherwise stopped &
         * restarted, then this value shall be incremented each time a discontinuity
         * occurs.  (E.g. this value can start at zero at device boot-up and
         * increment each time there is a change in clock continuity. In the
         * unlikely event that this value reaches full scale, rollover (not
         * clamping) is required, such that this value continues to change, during
         * subsequent discontinuity events.)
         *
         * While this number stays the same, between GnssClock reports, it can be
         * safely assumed that the timeNs value has been running continuously, e.g.
         * derived from a single, high quality clock (XO like, or better, that is
         * typically used during continuous GNSS signal sampling.)
         *
         * It is expected, esp. during periods where there are few GNSS signals
         * available, that the HW clock be discontinuity-free as long as possible,
         * as this avoids the need to use (waste) a GNSS measurement to fully
         * re-solve for the GNSS clock bias and drift, when using the accompanying
         * measurements, from consecutive GnssData reports.
         *
         * This value is mandatory.
         */
        public int hwClockDiscontinuityCount = 0;

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssClock.class) {
                return false;
            }
            android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssClock other = (android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssClock)otherObject;
            if (!android.os.HidlSupport.deepEquals(this.gnssClockFlags, other.gnssClockFlags)) {
                return false;
            }
            if (this.leapSecond != other.leapSecond) {
                return false;
            }
            if (this.timeNs != other.timeNs) {
                return false;
            }
            if (this.timeUncertaintyNs != other.timeUncertaintyNs) {
                return false;
            }
            if (this.fullBiasNs != other.fullBiasNs) {
                return false;
            }
            if (this.biasNs != other.biasNs) {
                return false;
            }
            if (this.biasUncertaintyNs != other.biasUncertaintyNs) {
                return false;
            }
            if (this.driftNsps != other.driftNsps) {
                return false;
            }
            if (this.driftUncertaintyNsps != other.driftUncertaintyNsps) {
                return false;
            }
            if (this.hwClockDiscontinuityCount != other.hwClockDiscontinuityCount) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.gnssClockFlags), 
                    android.os.HidlSupport.deepHashCode(this.leapSecond), 
                    android.os.HidlSupport.deepHashCode(this.timeNs), 
                    android.os.HidlSupport.deepHashCode(this.timeUncertaintyNs), 
                    android.os.HidlSupport.deepHashCode(this.fullBiasNs), 
                    android.os.HidlSupport.deepHashCode(this.biasNs), 
                    android.os.HidlSupport.deepHashCode(this.biasUncertaintyNs), 
                    android.os.HidlSupport.deepHashCode(this.driftNsps), 
                    android.os.HidlSupport.deepHashCode(this.driftUncertaintyNsps), 
                    android.os.HidlSupport.deepHashCode(this.hwClockDiscontinuityCount));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".gnssClockFlags = ");
            builder.append(android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssClockFlags.dumpBitfield(this.gnssClockFlags));
            builder.append(", .leapSecond = ");
            builder.append(this.leapSecond);
            builder.append(", .timeNs = ");
            builder.append(this.timeNs);
            builder.append(", .timeUncertaintyNs = ");
            builder.append(this.timeUncertaintyNs);
            builder.append(", .fullBiasNs = ");
            builder.append(this.fullBiasNs);
            builder.append(", .biasNs = ");
            builder.append(this.biasNs);
            builder.append(", .biasUncertaintyNs = ");
            builder.append(this.biasUncertaintyNs);
            builder.append(", .driftNsps = ");
            builder.append(this.driftNsps);
            builder.append(", .driftUncertaintyNsps = ");
            builder.append(this.driftUncertaintyNsps);
            builder.append(", .hwClockDiscontinuityCount = ");
            builder.append(this.hwClockDiscontinuityCount);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(72 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<GnssClock> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<GnssClock> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 72,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssClock _hidl_vec_element = new android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssClock();
                    ((android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssClock) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 72);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            gnssClockFlags = _hidl_blob.getInt16(_hidl_offset + 0);
            leapSecond = _hidl_blob.getInt16(_hidl_offset + 2);
            timeNs = _hidl_blob.getInt64(_hidl_offset + 8);
            timeUncertaintyNs = _hidl_blob.getDouble(_hidl_offset + 16);
            fullBiasNs = _hidl_blob.getInt64(_hidl_offset + 24);
            biasNs = _hidl_blob.getDouble(_hidl_offset + 32);
            biasUncertaintyNs = _hidl_blob.getDouble(_hidl_offset + 40);
            driftNsps = _hidl_blob.getDouble(_hidl_offset + 48);
            driftUncertaintyNsps = _hidl_blob.getDouble(_hidl_offset + 56);
            hwClockDiscontinuityCount = _hidl_blob.getInt32(_hidl_offset + 64);
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(72 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<GnssClock> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 72));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 72);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            _hidl_blob.putInt16(_hidl_offset + 0, gnssClockFlags);
            _hidl_blob.putInt16(_hidl_offset + 2, leapSecond);
            _hidl_blob.putInt64(_hidl_offset + 8, timeNs);
            _hidl_blob.putDouble(_hidl_offset + 16, timeUncertaintyNs);
            _hidl_blob.putInt64(_hidl_offset + 24, fullBiasNs);
            _hidl_blob.putDouble(_hidl_offset + 32, biasNs);
            _hidl_blob.putDouble(_hidl_offset + 40, biasUncertaintyNs);
            _hidl_blob.putDouble(_hidl_offset + 48, driftNsps);
            _hidl_blob.putDouble(_hidl_offset + 56, driftUncertaintyNsps);
            _hidl_blob.putInt32(_hidl_offset + 64, hwClockDiscontinuityCount);
        }
    };

    /**
     * Represents a GNSS Measurement, it contains raw and computed information.
     *
     * All signal measurement information (e.g. svTime,
     * pseudorangeRate, multipathIndicator) reported in this struct must be
     * based on GNSS signal measurements only. You must not synthesize measurements
     * by calculating or reporting expected measurements based on known or estimated
     * position, velocity, or time.
     */
    public final static class GnssMeasurement {
        /**
         * A set of flags indicating the validity of the fields in this data
         * structure.
         *
         * Fields for which there is no corresponding flag must be filled in
         * with a valid value.  For convenience, these are marked as mandatory.
         *
         * Others fields may have invalid information in them, if not marked as
         * valid by the corresponding bit in flags.
         */
        public int flags;
        /**
         * Satellite vehicle ID number, as defined in GnssSvInfo::svid
         *
         * This value is mandatory.
         */
        public short svid = 0;
        /**
         * Defines the constellation of the given SV.
         *
         * This value is mandatory.
         */
        public byte constellation = 0;
        /**
         * Time offset at which the measurement was taken in nanoseconds.
         * The reference receiver's time is specified by GnssData::clock::timeNs.
         *
         * The sign of timeOffsetNs is given by the following equation:
         *      measurement time = GnssClock::timeNs + timeOffsetNs
         *
         * It provides an individual time-stamp for the measurement, and allows
         * sub-nanosecond accuracy. It may be zero if all measurements are
         * aligned to a common time.
         *
         * This value is mandatory.
         */
        public double timeOffsetNs = 0.0d;
        /**
         * Per satellite sync state. It represents the current sync state for the
         * associated satellite.
         * Based on the sync state, the 'received GNSS tow' field must be interpreted
         * accordingly.
         *
         * This value is mandatory.
         */
        public int state;
        /**
         * The received GNSS Time-of-Week at the measurement time, in nanoseconds.
         * For GNSS & QZSS, this is the received GNSS Time-of-Week at the
         * measurement time, in nanoseconds. The value is relative to the
         * beginning of the current GNSS week.
         *
         * Given the highest sync state that can be achieved, per each satellite,
         * valid range for this field can be:
         * Searching       : [ 0       ] : STATE_UNKNOWN
         * C/A code lock   : [ 0 1ms   ] : STATE_CODE_LOCK set
         * Bit sync        : [ 0 20ms  ] : STATE_BIT_SYNC set
         * Subframe sync   : [ 0  6s   ] : STATE_SUBFRAME_SYNC set
         * TOW decoded     : [ 0 1week ] : STATE_TOW_DECODED set
         * TOW Known       : [ 0 1week ] : STATE_TOW_KNOWN set
         *
         * Note: TOW Known refers to the case where TOW is possibly not decoded
         * over the air but has been determined from other sources. If TOW
         * decoded is set then TOW Known must also be set.
         *
         * Note: If there is any ambiguity in integer millisecond,
         * GNSS_MEASUREMENT_STATE_MSEC_AMBIGUOUS must be set accordingly, in the
         * 'state' field.
         *
         * This value must be populated if 'state' != STATE_UNKNOWN.
         *
         * For Glonass, this is the received Glonass time of day, at the
         * measurement time in nanoseconds.
         *
         * Given the highest sync state that can be achieved, per each satellite,
         * valid range for this field can be:
         * Searching           : [ 0       ] : STATE_UNKNOWN set
         * C/A code lock       : [ 0   1ms ] : STATE_CODE_LOCK set
         * Symbol sync         : [ 0  10ms ] : STATE_SYMBOL_SYNC set
         * Bit sync            : [ 0  20ms ] : STATE_BIT_SYNC set
         * String sync         : [ 0    2s ] : STATE_GLO_STRING_SYNC set
         * Time of day decoded : [ 0  1day ] : STATE_GLO_TOD_DECODED set
         * Time of day known   : [ 0  1day ] : STATE_GLO_TOD_KNOWN set
         *
         * Note: Time of day known refers to the case where it is possibly not
         * decoded over the air but has been determined from other sources. If
         * Time of day decoded is set then Time of day known must also be set.
         *
         * For Beidou, this is the received Beidou time of week,
         * at the measurement time in nanoseconds.
         *
         * Given the highest sync state that can be achieved, per each satellite,
         * valid range for this field can be:
         * Searching            : [ 0       ] : STATE_UNKNOWN set.
         * C/A code lock        : [ 0   1ms ] : STATE_CODE_LOCK set.
         * Bit sync (D2)        : [ 0   2ms ] : STATE_BDS_D2_BIT_SYNC set.
         * Bit sync (D1)        : [ 0  20ms ] : STATE_BIT_SYNC set.
         * Subframe (D2)        : [ 0  0.6s ] : STATE_BDS_D2_SUBFRAME_SYNC set.
         * Subframe (D1)        : [ 0    6s ] : STATE_SUBFRAME_SYNC set.
         * Time of week decoded : [ 0 1week ] : STATE_TOW_DECODED set.
         * Time of week known   : [ 0 1week ] : STATE_TOW_KNOWN set
         *
         * Note: TOW Known refers to the case where TOW is possibly not decoded
         * over the air but has been determined from other sources. If TOW
         * decoded is set then TOW Known must also be set.
         *
         * For Galileo, this is the received Galileo time of week,
         * at the measurement time in nanoseconds.
         *
         * E1BC code lock       : [ 0  4ms ] : STATE_GAL_E1BC_CODE_LOCK set.
         * E1C 2nd code lock    : [ 0 100ms] : STATE_GAL_E1C_2ND_CODE_LOCK set.
         * E1B page             : [ 0   2s ] : STATE_GAL_E1B_PAGE_SYNC set.
         * Time of week decoded : [ 0 1week] : STATE_TOW_DECODED is set.
         * Time of week known   : [ 0 1week] : STATE_TOW_KNOWN set
         *
         * Note: TOW Known refers to the case where TOW is possibly not decoded
         * over the air but has been determined from other sources. If TOW
         * decoded is set then TOW Known must also be set.
         *
         * For SBAS, this is received SBAS time, at the measurement time in
         * nanoseconds.
         *
         * Given the highest sync state that can be achieved, per each satellite,
         * valid range for this field can be:
         * Searching    : [ 0     ] : STATE_UNKNOWN
         * C/A code lock: [ 0 1ms ] : STATE_CODE_LOCK is set
         * Symbol sync  : [ 0 2ms ] : STATE_SYMBOL_SYNC is set
         * Message      : [ 0  1s ] : STATE_SBAS_SYNC is set
         */
        public long receivedSvTimeInNs = 0L;
        /**
         * 1-Sigma uncertainty of the Received GNSS Time-of-Week in nanoseconds.
         *
         * This value must be populated if 'state' != STATE_UNKNOWN.
         */
        public long receivedSvTimeUncertaintyInNs = 0L;
        /**
         * Carrier-to-noise density in dB-Hz, typically in the range [0, 63].
         * It contains the measured C/N0 value for the signal at the antenna port.
         *
         * If a signal has separate components (e.g. Pilot and Data channels) and
         * the receiver only processes one of the components, then the reported
         * cN0DbHz reflects only the component that is processed.
         *
         * This value is mandatory.
         */
        public double cN0DbHz = 0.0d;
        /**
         * Pseudorange rate at the timestamp in m/s. The correction of a given
         * Pseudorange Rate value includes corrections for receiver and satellite
         * clock frequency errors. Ensure that this field is independent (see
         * comment at top of GnssMeasurement struct.)
         *
         * It is mandatory to provide the 'uncorrected' 'pseudorange rate', and
         * provide GnssClock's 'drift' field as well. When providing the
         * uncorrected pseudorange rate, do not apply the corrections described above.)
         *
         * The value includes the 'pseudorange rate uncertainty' in it.
         * A positive 'uncorrected' value indicates that the SV is moving away from
         * the receiver.
         *
         * The sign of the 'uncorrected' 'pseudorange rate' and its relation to the
         * sign of 'doppler shift' is given by the equation:
         *      pseudorange rate = -k * doppler shift   (where k is a constant)
         *
         * This must be the most accurate pseudorange rate available, based on
         * fresh signal measurements from this channel.
         *
         * It is mandatory that this value be provided at typical carrier phase PRR
         * quality (few cm/sec per second of uncertainty, or better) - when signals
         * are sufficiently strong & stable, e.g. signals from a GNSS simulator at >=
         * 35 dB-Hz.
         */
        public double pseudorangeRateMps = 0.0d;
        /**
         * 1-Sigma uncertainty of the pseudorangeRateMps.
         * The uncertainty is represented as an absolute (single sided) value.
         *
         * This value is mandatory.
         */
        public double pseudorangeRateUncertaintyMps = 0.0d;
        /**
         * Accumulated delta range's state. It indicates whether ADR is reset or
         * there is a cycle slip(indicating loss of lock).
         *
         * This value is mandatory.
         */
        public short accumulatedDeltaRangeState;
        /**
         * Accumulated delta range since the last channel reset in meters.
         * A positive value indicates that the SV is moving away from the receiver.
         *
         * The sign of the 'accumulated delta range' and its relation to the sign of
         * 'carrier phase' is given by the equation:
         * accumulated delta range = -k * carrier phase (where k is a constant)
         *
         * This value must be populated if 'accumulated delta range state' !=
         * ADR_STATE_UNKNOWN.
         * However, it is expected that the data is only accurate when:
         *      'accumulated delta range state' == ADR_STATE_VALID.
         */
        public double accumulatedDeltaRangeM = 0.0d;
        /**
         * 1-Sigma uncertainty of the accumulated delta range in meters.
         * This value must be populated if 'accumulated delta range state' !=
         * ADR_STATE_UNKNOWN.
         */
        public double accumulatedDeltaRangeUncertaintyM = 0.0d;
        /**
         * Carrier frequency of the signal tracked, for example it can be the
         * GPS central frequency for L1 = 1575.45 MHz, or L2 = 1227.60 MHz, L5 =
         * 1176.45 MHz, varying GLO channels, etc. If the field is not set, it
         * is the primary common use central frequency, e.g. L1 = 1575.45 MHz
         * for GPS.
         *
         * For an L1, L5 receiver tracking a satellite on L1 and L5 at the same
         * time, two raw measurement structs must be reported for this same
         * satellite, in one of the measurement structs, all the values related
         * to L1 must be filled, and in the other all of the values related to
         * L5 must be filled.
         *
         * If the data is available, gnssMeasurementFlags must contain
         * HAS_CARRIER_FREQUENCY.
         */
        public float carrierFrequencyHz = 0.0f;
        /**
         * The number of full carrier cycles between the satellite and the
         * receiver. The reference frequency is given by the field
         * 'carrierFrequencyHz'. Indications of possible cycle slips and
         * resets in the accumulation of this value can be inferred from the
         * accumulatedDeltaRangeState flags.
         *
         * If the data is available, gnssMeasurementFlags must contain
         * HAS_CARRIER_CYCLES.
         */
        public long carrierCycles = 0L;
        /**
         * The RF phase detected by the receiver, in the range [0.0, 1.0].
         * This is usually the fractional part of the complete carrier phase
         * measurement.
         *
         * The reference frequency is given by the field 'carrierFrequencyHz'.
         * The value contains the 'carrier-phase uncertainty' in it.
         *
         * If the data is available, gnssMeasurementFlags must contain
         * HAS_CARRIER_PHASE.
         */
        public double carrierPhase = 0.0d;
        /**
         * 1-Sigma uncertainty of the carrier-phase.
         * If the data is available, gnssMeasurementFlags must contain
         * HAS_CARRIER_PHASE_UNCERTAINTY.
         */
        public double carrierPhaseUncertainty = 0.0d;
        /**
         * An enumeration that indicates the 'multipath' state of the event.
         *
         * The multipath Indicator is intended to report the presence of overlapping
         * signals that manifest as distorted correlation peaks.
         *
         * - if there is a distorted correlation peak shape, report that multipath
         *   is MULTIPATH_INDICATOR_PRESENT.
         * - if there is no distorted correlation peak shape, report
         *   MULTIPATH_INDICATOR_NOT_PRESENT
         * - if signals are too weak to discern this information, report
         *   MULTIPATH_INDICATOR_UNKNOWN
         *
         * Example: when doing the standardized overlapping Multipath Performance
         * test (3GPP TS 34.171) the Multipath indicator must report
         * MULTIPATH_INDICATOR_PRESENT for those signals that are tracked, and
         * contain multipath, and MULTIPATH_INDICATOR_NOT_PRESENT for those
         * signals that are tracked and do not contain multipath.
         */
        public byte multipathIndicator = 0;
        /**
         * Signal-to-noise ratio at correlator output in dB.
         * If the data is available, GnssMeasurementFlags must contain HAS_SNR.
         * This is the power ratio of the "correlation peak height above the
         * observed noise floor" to "the noise RMS".
         */
        public double snrDb = 0.0d;
        /**
         * Automatic gain control (AGC) level. AGC acts as a variable gain amplifier adjusting the power
         * of the incoming signal. The AGC level may be used to indicate potential interference. Higher
         * gain (and/or lower input power) must be output as a positive number. Hence in cases of strong
         * jamming, in the band of this signal, this value must go more negative. This value must be
         * consistent given the same level of the incoming signal power.
         *
         * Note: Different hardware designs (e.g. antenna, pre-amplification, or other RF HW components)
         * may also affect the typical output of this value on any given hardware design in an open sky
         * test - the important aspect of this output is that changes in this value are indicative of
         * changes on input signal power in the frequency band for this measurement.
         */
        public double agcLevelDb = 0.0d;

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssMeasurement.class) {
                return false;
            }
            android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssMeasurement other = (android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssMeasurement)otherObject;
            if (!android.os.HidlSupport.deepEquals(this.flags, other.flags)) {
                return false;
            }
            if (this.svid != other.svid) {
                return false;
            }
            if (this.constellation != other.constellation) {
                return false;
            }
            if (this.timeOffsetNs != other.timeOffsetNs) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.state, other.state)) {
                return false;
            }
            if (this.receivedSvTimeInNs != other.receivedSvTimeInNs) {
                return false;
            }
            if (this.receivedSvTimeUncertaintyInNs != other.receivedSvTimeUncertaintyInNs) {
                return false;
            }
            if (this.cN0DbHz != other.cN0DbHz) {
                return false;
            }
            if (this.pseudorangeRateMps != other.pseudorangeRateMps) {
                return false;
            }
            if (this.pseudorangeRateUncertaintyMps != other.pseudorangeRateUncertaintyMps) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.accumulatedDeltaRangeState, other.accumulatedDeltaRangeState)) {
                return false;
            }
            if (this.accumulatedDeltaRangeM != other.accumulatedDeltaRangeM) {
                return false;
            }
            if (this.accumulatedDeltaRangeUncertaintyM != other.accumulatedDeltaRangeUncertaintyM) {
                return false;
            }
            if (this.carrierFrequencyHz != other.carrierFrequencyHz) {
                return false;
            }
            if (this.carrierCycles != other.carrierCycles) {
                return false;
            }
            if (this.carrierPhase != other.carrierPhase) {
                return false;
            }
            if (this.carrierPhaseUncertainty != other.carrierPhaseUncertainty) {
                return false;
            }
            if (this.multipathIndicator != other.multipathIndicator) {
                return false;
            }
            if (this.snrDb != other.snrDb) {
                return false;
            }
            if (this.agcLevelDb != other.agcLevelDb) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.flags), 
                    android.os.HidlSupport.deepHashCode(this.svid), 
                    android.os.HidlSupport.deepHashCode(this.constellation), 
                    android.os.HidlSupport.deepHashCode(this.timeOffsetNs), 
                    android.os.HidlSupport.deepHashCode(this.state), 
                    android.os.HidlSupport.deepHashCode(this.receivedSvTimeInNs), 
                    android.os.HidlSupport.deepHashCode(this.receivedSvTimeUncertaintyInNs), 
                    android.os.HidlSupport.deepHashCode(this.cN0DbHz), 
                    android.os.HidlSupport.deepHashCode(this.pseudorangeRateMps), 
                    android.os.HidlSupport.deepHashCode(this.pseudorangeRateUncertaintyMps), 
                    android.os.HidlSupport.deepHashCode(this.accumulatedDeltaRangeState), 
                    android.os.HidlSupport.deepHashCode(this.accumulatedDeltaRangeM), 
                    android.os.HidlSupport.deepHashCode(this.accumulatedDeltaRangeUncertaintyM), 
                    android.os.HidlSupport.deepHashCode(this.carrierFrequencyHz), 
                    android.os.HidlSupport.deepHashCode(this.carrierCycles), 
                    android.os.HidlSupport.deepHashCode(this.carrierPhase), 
                    android.os.HidlSupport.deepHashCode(this.carrierPhaseUncertainty), 
                    android.os.HidlSupport.deepHashCode(this.multipathIndicator), 
                    android.os.HidlSupport.deepHashCode(this.snrDb), 
                    android.os.HidlSupport.deepHashCode(this.agcLevelDb));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".flags = ");
            builder.append(android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssMeasurementFlags.dumpBitfield(this.flags));
            builder.append(", .svid = ");
            builder.append(this.svid);
            builder.append(", .constellation = ");
            builder.append(android.hardware.gnss.V1_0.GnssConstellationType.toString(this.constellation));
            builder.append(", .timeOffsetNs = ");
            builder.append(this.timeOffsetNs);
            builder.append(", .state = ");
            builder.append(android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssMeasurementState.dumpBitfield(this.state));
            builder.append(", .receivedSvTimeInNs = ");
            builder.append(this.receivedSvTimeInNs);
            builder.append(", .receivedSvTimeUncertaintyInNs = ");
            builder.append(this.receivedSvTimeUncertaintyInNs);
            builder.append(", .cN0DbHz = ");
            builder.append(this.cN0DbHz);
            builder.append(", .pseudorangeRateMps = ");
            builder.append(this.pseudorangeRateMps);
            builder.append(", .pseudorangeRateUncertaintyMps = ");
            builder.append(this.pseudorangeRateUncertaintyMps);
            builder.append(", .accumulatedDeltaRangeState = ");
            builder.append(android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssAccumulatedDeltaRangeState.dumpBitfield(this.accumulatedDeltaRangeState));
            builder.append(", .accumulatedDeltaRangeM = ");
            builder.append(this.accumulatedDeltaRangeM);
            builder.append(", .accumulatedDeltaRangeUncertaintyM = ");
            builder.append(this.accumulatedDeltaRangeUncertaintyM);
            builder.append(", .carrierFrequencyHz = ");
            builder.append(this.carrierFrequencyHz);
            builder.append(", .carrierCycles = ");
            builder.append(this.carrierCycles);
            builder.append(", .carrierPhase = ");
            builder.append(this.carrierPhase);
            builder.append(", .carrierPhaseUncertainty = ");
            builder.append(this.carrierPhaseUncertainty);
            builder.append(", .multipathIndicator = ");
            builder.append(android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssMultipathIndicator.toString(this.multipathIndicator));
            builder.append(", .snrDb = ");
            builder.append(this.snrDb);
            builder.append(", .agcLevelDb = ");
            builder.append(this.agcLevelDb);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(144 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<GnssMeasurement> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<GnssMeasurement> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 144,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssMeasurement _hidl_vec_element = new android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssMeasurement();
                    ((android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssMeasurement) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 144);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            flags = _hidl_blob.getInt32(_hidl_offset + 0);
            svid = _hidl_blob.getInt16(_hidl_offset + 4);
            constellation = _hidl_blob.getInt8(_hidl_offset + 6);
            timeOffsetNs = _hidl_blob.getDouble(_hidl_offset + 8);
            state = _hidl_blob.getInt32(_hidl_offset + 16);
            receivedSvTimeInNs = _hidl_blob.getInt64(_hidl_offset + 24);
            receivedSvTimeUncertaintyInNs = _hidl_blob.getInt64(_hidl_offset + 32);
            cN0DbHz = _hidl_blob.getDouble(_hidl_offset + 40);
            pseudorangeRateMps = _hidl_blob.getDouble(_hidl_offset + 48);
            pseudorangeRateUncertaintyMps = _hidl_blob.getDouble(_hidl_offset + 56);
            accumulatedDeltaRangeState = _hidl_blob.getInt16(_hidl_offset + 64);
            accumulatedDeltaRangeM = _hidl_blob.getDouble(_hidl_offset + 72);
            accumulatedDeltaRangeUncertaintyM = _hidl_blob.getDouble(_hidl_offset + 80);
            carrierFrequencyHz = _hidl_blob.getFloat(_hidl_offset + 88);
            carrierCycles = _hidl_blob.getInt64(_hidl_offset + 96);
            carrierPhase = _hidl_blob.getDouble(_hidl_offset + 104);
            carrierPhaseUncertainty = _hidl_blob.getDouble(_hidl_offset + 112);
            multipathIndicator = _hidl_blob.getInt8(_hidl_offset + 120);
            snrDb = _hidl_blob.getDouble(_hidl_offset + 128);
            agcLevelDb = _hidl_blob.getDouble(_hidl_offset + 136);
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(144 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<GnssMeasurement> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 144));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 144);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            _hidl_blob.putInt32(_hidl_offset + 0, flags);
            _hidl_blob.putInt16(_hidl_offset + 4, svid);
            _hidl_blob.putInt8(_hidl_offset + 6, constellation);
            _hidl_blob.putDouble(_hidl_offset + 8, timeOffsetNs);
            _hidl_blob.putInt32(_hidl_offset + 16, state);
            _hidl_blob.putInt64(_hidl_offset + 24, receivedSvTimeInNs);
            _hidl_blob.putInt64(_hidl_offset + 32, receivedSvTimeUncertaintyInNs);
            _hidl_blob.putDouble(_hidl_offset + 40, cN0DbHz);
            _hidl_blob.putDouble(_hidl_offset + 48, pseudorangeRateMps);
            _hidl_blob.putDouble(_hidl_offset + 56, pseudorangeRateUncertaintyMps);
            _hidl_blob.putInt16(_hidl_offset + 64, accumulatedDeltaRangeState);
            _hidl_blob.putDouble(_hidl_offset + 72, accumulatedDeltaRangeM);
            _hidl_blob.putDouble(_hidl_offset + 80, accumulatedDeltaRangeUncertaintyM);
            _hidl_blob.putFloat(_hidl_offset + 88, carrierFrequencyHz);
            _hidl_blob.putInt64(_hidl_offset + 96, carrierCycles);
            _hidl_blob.putDouble(_hidl_offset + 104, carrierPhase);
            _hidl_blob.putDouble(_hidl_offset + 112, carrierPhaseUncertainty);
            _hidl_blob.putInt8(_hidl_offset + 120, multipathIndicator);
            _hidl_blob.putDouble(_hidl_offset + 128, snrDb);
            _hidl_blob.putDouble(_hidl_offset + 136, agcLevelDb);
        }
    };

    /**
     * Represents a reading of GNSS measurements. For devices where GnssSystemInfo's
     * yearOfHw is set to 2016+, it is mandatory that these be provided, on
     * request, when the GNSS receiver is searching/tracking signals.
     *
     * - Reporting of GNSS constellation measurements is mandatory.
     * - Reporting of all tracked constellations are encouraged.
     */
    public final static class GnssData {
        /**
         * Number of GnssMeasurement elements.
         */
        public int measurementCount = 0;
        /**
         * The array of measurements.
         */
        public android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssMeasurement[/* GnssMax:SVS_COUNT */] measurements = new android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssMeasurement[64 /* GnssMax:SVS_COUNT */];
        /**
         * The GNSS clock time reading.
         */
        public android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssClock clock = new android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssClock();

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssData.class) {
                return false;
            }
            android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssData other = (android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssData)otherObject;
            if (this.measurementCount != other.measurementCount) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.measurements, other.measurements)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.clock, other.clock)) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.measurementCount), 
                    android.os.HidlSupport.deepHashCode(this.measurements), 
                    android.os.HidlSupport.deepHashCode(this.clock));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".measurementCount = ");
            builder.append(this.measurementCount);
            builder.append(", .measurements = ");
            builder.append(java.util.Arrays.toString(this.measurements));
            builder.append(", .clock = ");
            builder.append(this.clock);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(9296 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<GnssData> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<GnssData> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 9296,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssData _hidl_vec_element = new android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssData();
                    ((android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssData) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 9296);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            measurementCount = _hidl_blob.getInt32(_hidl_offset + 0);
            {
                long _hidl_array_offset_0 = _hidl_offset + 8;
                for (int _hidl_index_0_0 = 0; _hidl_index_0_0 < 64 /* GnssMax:SVS_COUNT */; ++_hidl_index_0_0) {
                    ((android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssMeasurement[/* GnssMax:SVS_COUNT */]) measurements)[_hidl_index_0_0] = new android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssMeasurement();
                    ((android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssMeasurement) ((android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssMeasurement[/* GnssMax:SVS_COUNT */]) measurements)[_hidl_index_0_0]).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_array_offset_0);
                    _hidl_array_offset_0 += 144;
                }
            }
            ((android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssClock) clock).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 9224);
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(9296 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<GnssData> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 9296));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 9296);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            _hidl_blob.putInt32(_hidl_offset + 0, measurementCount);
            {
                long _hidl_array_offset_0 = _hidl_offset + 8;
                for (int _hidl_index_0_0 = 0; _hidl_index_0_0 < 64 /* GnssMax:SVS_COUNT */; ++_hidl_index_0_0) {
                    ((android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssMeasurement[/* GnssMax:SVS_COUNT */]) measurements)[_hidl_index_0_0].writeEmbeddedToBlob(_hidl_blob, _hidl_array_offset_0);
                    _hidl_array_offset_0 += 144;
                }
            }
            clock.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 9224);
        }
    };

    /**
     * Callback for the hal to pass a GnssData structure back to the client.
     *
     * @param data Contains a reading of GNSS measurements.
     */
    void GnssMeasurementCb(android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssData data)
        throws android.os.RemoteException;
    /*
     * Provides run-time type information for this object.
     * For example, for the following interface definition:
     *     package android.hardware.foo@1.0;
     *     interface IParent {};
     *     interface IChild extends IParent {};
     * Calling interfaceChain on an IChild object must yield the following:
     *     ["android.hardware.foo@1.0::IChild",
     *      "android.hardware.foo@1.0::IParent"
     *      "android.hidl.base@1.0::IBase"]
     *
     * @return descriptors a vector of descriptors of the run-time type of the
     *         object.
     */
    java.util.ArrayList<String> interfaceChain()
        throws android.os.RemoteException;
    /*
     * Emit diagnostic information to the given file.
     *
     * Optionally overriden.
     *
     * @param fd      File descriptor to dump data to.
     *                Must only be used for the duration of this call.
     * @param options Arguments for debugging.
     *                Must support empty for default debug information.
     */
    void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options)
        throws android.os.RemoteException;
    /*
     * Provides run-time type information for this object.
     * For example, for the following interface definition:
     *     package android.hardware.foo@1.0;
     *     interface IParent {};
     *     interface IChild extends IParent {};
     * Calling interfaceDescriptor on an IChild object must yield
     *     "android.hardware.foo@1.0::IChild"
     *
     * @return descriptor a descriptor of the run-time type of the
     *         object (the first element of the vector returned by
     *         interfaceChain())
     */
    String interfaceDescriptor()
        throws android.os.RemoteException;
    /*
     * Returns hashes of the source HAL files that define the interfaces of the
     * runtime type information on the object.
     * For example, for the following interface definition:
     *     package android.hardware.foo@1.0;
     *     interface IParent {};
     *     interface IChild extends IParent {};
     * Calling interfaceChain on an IChild object must yield the following:
     *     [(hash of IChild.hal),
     *      (hash of IParent.hal)
     *      (hash of IBase.hal)].
     *
     * SHA-256 is used as the hashing algorithm. Each hash has 32 bytes
     * according to SHA-256 standard.
     *
     * @return hashchain a vector of SHA-1 digests
     */
    java.util.ArrayList<byte[/* 32 */]> getHashChain()
        throws android.os.RemoteException;
    /*
     * This method trigger the interface to enable/disable instrumentation based
     * on system property hal.instrumentation.enable.
     */
    void setHALInstrumentation()
        throws android.os.RemoteException;
    /*
     * Registers a death recipient, to be called when the process hosting this
     * interface dies.
     *
     * @param recipient a hidl_death_recipient callback object
     * @param cookie a cookie that must be returned with the callback
     * @return success whether the death recipient was registered successfully.
     */
    boolean linkToDeath(android.os.IHwBinder.DeathRecipient recipient, long cookie)
        throws android.os.RemoteException;
    /*
     * Provides way to determine if interface is running without requesting
     * any functionality.
     */
    void ping()
        throws android.os.RemoteException;
    /*
     * Get debug information on references on this interface.
     * @return info debugging information. See comments of DebugInfo.
     */
    android.hidl.base.V1_0.DebugInfo getDebugInfo()
        throws android.os.RemoteException;
    /*
     * This method notifies the interface that one or more system properties
     * have changed. The default implementation calls
     * (C++)  report_sysprop_change() in libcutils or
     * (Java) android.os.SystemProperties.reportSyspropChanged,
     * which in turn calls a set of registered callbacks (eg to update trace
     * tags).
     */
    void notifySyspropsChanged()
        throws android.os.RemoteException;
    /*
     * Unregisters the registered death recipient. If this service was registered
     * multiple times with the same exact death recipient, this unlinks the most
     * recently registered one.
     *
     * @param recipient a previously registered hidl_death_recipient callback
     * @return success whether the death recipient was unregistered successfully.
     */
    boolean unlinkToDeath(android.os.IHwBinder.DeathRecipient recipient)
        throws android.os.RemoteException;

    public static final class Proxy implements IGnssMeasurementCallback {
        private android.os.IHwBinder mRemote;

        public Proxy(android.os.IHwBinder remote) {
            mRemote = java.util.Objects.requireNonNull(remote);
        }

        @Override
        public android.os.IHwBinder asBinder() {
            return mRemote;
        }

        @Override
        public String toString() {
            try {
                return this.interfaceDescriptor() + "@Proxy";
            } catch (android.os.RemoteException ex) {
                /* ignored; handled below. */
            }
            return "[class or subclass of " + IGnssMeasurementCallback.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::gnss::V1_0::IGnssMeasurementCallback follow.
        @Override
        public void GnssMeasurementCb(android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssData data)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnssMeasurementCallback.kInterfaceName);
            ((android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssData) data).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* GnssMeasurementCb */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hidl::base::V1_0::IBase follow.
        @Override
        public java.util.ArrayList<String> interfaceChain()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(256067662 /* interfaceChain */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                java.util.ArrayList<String> _hidl_out_descriptors = _hidl_reply.readStringVector();
                return _hidl_out_descriptors;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);
            _hidl_request.writeNativeHandle(fd);
            _hidl_request.writeStringVector(options);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(256131655 /* debug */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public String interfaceDescriptor()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(256136003 /* interfaceDescriptor */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                String _hidl_out_descriptor = _hidl_reply.readString();
                return _hidl_out_descriptor;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public java.util.ArrayList<byte[/* 32 */]> getHashChain()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(256398152 /* getHashChain */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                java.util.ArrayList<byte[/* 32 */]> _hidl_out_hashchain =  new java.util.ArrayList<byte[/* 32 */]>();
                {
                    android.os.HwBlob _hidl_blob = _hidl_reply.readBuffer(16 /* size */);
                    {
                        int _hidl_vec_size = _hidl_blob.getInt32(0 /* offset */ + 8 /* offsetof(hidl_vec<T>, mSize) */);
                        android.os.HwBlob childBlob = _hidl_reply.readEmbeddedBuffer(
                                _hidl_vec_size * 32,_hidl_blob.handle(),
                                0 /* offset */ + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                        ((java.util.ArrayList<byte[/* 32 */]>) _hidl_out_hashchain).clear();
                        for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                            byte[/* 32 */] _hidl_vec_element = new byte[32];
                            {
                                long _hidl_array_offset_1 = _hidl_index_0 * 32;
                                childBlob.copyToInt8Array(_hidl_array_offset_1, (byte[/* 32 */]) _hidl_vec_element, 32 /* size */);
                                _hidl_array_offset_1 += 32 * 1;
                            }
                            ((java.util.ArrayList<byte[/* 32 */]>) _hidl_out_hashchain).add(_hidl_vec_element);
                        }
                    }
                }
                return _hidl_out_hashchain;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setHALInstrumentation()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(256462420 /* setHALInstrumentation */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean linkToDeath(android.os.IHwBinder.DeathRecipient recipient, long cookie)
                throws android.os.RemoteException {
            return mRemote.linkToDeath(recipient, cookie);
        }
        @Override
        public void ping()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(256921159 /* ping */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hidl.base.V1_0.DebugInfo getDebugInfo()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(257049926 /* getDebugInfo */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hidl.base.V1_0.DebugInfo _hidl_out_info = new android.hidl.base.V1_0.DebugInfo();
                ((android.hidl.base.V1_0.DebugInfo) _hidl_out_info).readFromParcel(_hidl_reply);
                return _hidl_out_info;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void notifySyspropsChanged()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(257120595 /* notifySyspropsChanged */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean unlinkToDeath(android.os.IHwBinder.DeathRecipient recipient)
                throws android.os.RemoteException {
            return mRemote.unlinkToDeath(recipient);
        }
    }

    public static abstract class Stub extends android.os.HwBinder implements IGnssMeasurementCallback {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.gnss.V1_0.IGnssMeasurementCallback.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.gnss.V1_0.IGnssMeasurementCallback.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{-67,-92,-110,-20,64,33,-47,56,105,-34,114,-67,111,-116,21,-59,-125,123,120,-42,19,107,-115,83,-114,-2,-59,50,5,115,-91,-20} /* bda492ec4021d13869de72bd6f8c15c5837b78d6136b8d538efec5320573a5ec */,
                    new byte[/* 32 */]{-20,127,-41,-98,-48,45,-6,-123,-68,73,-108,38,-83,-82,62,-66,35,-17,5,36,-13,-51,105,87,19,-109,36,-72,59,24,-54,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */));

        }

        @Override
        public final void setHALInstrumentation() {

        }

        @Override
        public final boolean linkToDeath(android.os.IHwBinder.DeathRecipient recipient, long cookie) {
            return true;

        }

        @Override
        public final void ping() {
            return;

        }

        @Override
        public final android.hidl.base.V1_0.DebugInfo getDebugInfo() {
            android.hidl.base.V1_0.DebugInfo info = new android.hidl.base.V1_0.DebugInfo();
            info.pid = android.os.HidlSupport.getPidIfSharable();
            info.ptr = 0;
            info.arch = android.hidl.base.V1_0.DebugInfo.Architecture.UNKNOWN;
            return info;

        }

        @Override
        public final void notifySyspropsChanged() {
            android.os.HwBinder.enableInstrumentation();

        }

        @Override
        public final boolean unlinkToDeath(android.os.IHwBinder.DeathRecipient recipient) {
            return true;

        }

        @Override
        public android.os.IHwInterface queryLocalInterface(String descriptor) {
            if (kInterfaceName.equals(descriptor)) {
                return this;
            }
            return null;
        }

        public void registerAsService(String serviceName) throws android.os.RemoteException {
            registerService(serviceName);
        }

        @Override
        public String toString() {
            return this.interfaceDescriptor() + "@Stub";
        }

        @Override
        public void onTransact(int _hidl_code, android.os.HwParcel _hidl_request, final android.os.HwParcel _hidl_reply, int _hidl_flags)
                throws android.os.RemoteException {
            switch (_hidl_code) {
                case 1 /* GnssMeasurementCb */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnssMeasurementCallback.kInterfaceName);

                    android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssData data = new android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssData();
                    ((android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssData) data).readFromParcel(_hidl_request);
                    GnssMeasurementCb(data);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 256067662 /* interfaceChain */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    java.util.ArrayList<String> _hidl_out_descriptors = interfaceChain();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStringVector(_hidl_out_descriptors);
                    _hidl_reply.send();
                    break;
                }

                case 256131655 /* debug */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    android.os.NativeHandle fd = _hidl_request.readNativeHandle();
                    java.util.ArrayList<String> options = _hidl_request.readStringVector();
                    debug(fd, options);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 256136003 /* interfaceDescriptor */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    String _hidl_out_descriptor = interfaceDescriptor();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeString(_hidl_out_descriptor);
                    _hidl_reply.send();
                    break;
                }

                case 256398152 /* getHashChain */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    java.util.ArrayList<byte[/* 32 */]> _hidl_out_hashchain = getHashChain();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    {
                        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* size */);
                        {
                            int _hidl_vec_size = _hidl_out_hashchain.size();
                            _hidl_blob.putInt32(0 /* offset */ + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                            _hidl_blob.putBool(0 /* offset */ + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 32));
                            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                                {
                                    long _hidl_array_offset_1 = _hidl_index_0 * 32;
                                    byte[] _hidl_array_item_1 = (byte[/* 32 */]) _hidl_out_hashchain.get(_hidl_index_0);

                                    if (_hidl_array_item_1 == null || _hidl_array_item_1.length != 32) {
                                        throw new IllegalArgumentException("Array element is not of the expected length");
                                    }

                                    childBlob.putInt8Array(_hidl_array_offset_1, _hidl_array_item_1);
                                    _hidl_array_offset_1 += 32 * 1;
                                }
                            }
                            _hidl_blob.putBlob(0 /* offset */ + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
                        }
                        _hidl_reply.writeBuffer(_hidl_blob);
                    }
                    _hidl_reply.send();
                    break;
                }

                case 256462420 /* setHALInstrumentation */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    setHALInstrumentation();
                    break;
                }

                case 256660548 /* linkToDeath */:
                {
                break;
                }

                case 256921159 /* ping */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    ping();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 257049926 /* getDebugInfo */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    android.hidl.base.V1_0.DebugInfo _hidl_out_info = getDebugInfo();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hidl.base.V1_0.DebugInfo) _hidl_out_info).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 257120595 /* notifySyspropsChanged */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    notifySyspropsChanged();
                    break;
                }

                case 257250372 /* unlinkToDeath */:
                {
                break;
                }

            }
        }
    }
}
