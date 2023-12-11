package android.hardware.gnss.V2_0;

/**
 * The callback interface to report measurements from the HAL.
 */
public interface IGnssMeasurementCallback extends android.hardware.gnss.V1_1.IGnssMeasurementCallback {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.gnss@2.0::IGnssMeasurementCallback";

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
        return IGnssMeasurementCallback.asInterface(android.os.HwBinder.getService("android.hardware.gnss@2.0::IGnssMeasurementCallback", serviceName, retry));
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
        return IGnssMeasurementCallback.asInterface(android.os.HwBinder.getService("android.hardware.gnss@2.0::IGnssMeasurementCallback", serviceName));
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
     * Flags indicating the GNSS measurement state.
     *
     * <p>The expected behavior here is for GNSS HAL to set all the flags that apply. For example,
     * if the state for a satellite is only C/A code locked and bit synchronized, and there is still
     * millisecond ambiguity, the state must be set as:
     *
     * STATE_CODE_LOCK | STATE_BIT_SYNC |  STATE_MSEC_AMBIGUOUS
     *
     * <p>If GNSS is still searching for a satellite, the corresponding state must be set to
     * STATE_UNKNOWN(0).
     *
     * <p>In @2.0::IGnssMeasurementCallback.GnssMeasurement, v1_1.v1_0.receivedSvTimeInNs, the
     * received satellite time, is relative to the beginning of the system week for all
     * constellations except for Glonass where it is relative to the beginning of the Glonass system
     * day.
     *
     * <p>The table below indicates the valid range of the received GNSS satellite time.  These
     * ranges depend on the constellation and code being tracked and the state of the tracking
     * algorithms given by the getState method. If the state flag is set, then the valid measurement
     * range is zero to the value in the table. The state flag with the widest range indicates the
     * range of the received GNSS satellite time value.
     *
     * <table>
     *   <thead>
     *     <tr>
     *       <td />
     *       <td colspan="3"><strong>GPS/QZSS</strong></td>
     *       <td><strong>GLNS</strong></td>
     *       <td colspan="2"><strong>BDS</strong></td>
     *       <td colspan="3"><strong>GAL</strong></td>
     *       <td><strong>SBAS</strong></td>
     *     </tr>
     *     <tr>
     *       <td><strong>State Flag</strong></td>
     *       <td><strong>L1 C/A</strong></td>
     *       <td><strong>L5I</strong></td>
     *       <td><strong>L5Q</strong></td>
     *       <td><strong>L1OF</strong></td>
     *       <td><strong>B1I (D1)</strong></td>
     *       <td><strong>B1I &nbsp;(D2)</strong></td>
     *       <td><strong>E1B</strong></td>
     *       <td><strong>E1C</strong></td>
     *       <td><strong>E5AQ</strong></td>
     *       <td><strong>L1 C/A</strong></td>
     *     </tr>
     *   </thead>
     *   <tbody>
     *     <tr>
     *       <td>
     *         <strong>STATE_UNKNOWN</strong>
     *       </td>
     *       <td>0</td>
     *       <td>0</td>
     *       <td>0</td>
     *       <td>0</td>
     *       <td>0</td>
     *       <td>0</td>
     *       <td>0</td>
     *       <td>0</td>
     *       <td>0</td>
     *       <td>0</td>
     *     </tr>
     *     <tr>
     *       <td>
     *         <strong>STATE_CODE_LOCK</strong>
     *       </td>
     *       <td>1 ms</td>
     *       <td>1 ms</td>
     *       <td>1 ms</td>
     *       <td>1 ms</td>
     *       <td>1 ms</td>
     *       <td>1 ms</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>1 ms</td>
     *       <td>1 ms</td>
     *     </tr>
     *     <tr>
     *       <td>
     *         <strong>STATE_SYMBOL_SYNC</strong>
     *       </td>
     *       <td>20 ms (optional)</td>
     *       <td>10 ms</td>
     *       <td>1 ms (optional)</td>
     *       <td>10 ms</td>
     *       <td>20 ms (optional)</td>
     *       <td>2 ms</td>
     *       <td>4 ms (optional)</td>
     *       <td>4 ms (optional)</td>
     *       <td>1 ms (optional)</td>
     *       <td>2 ms</td>
     *     </tr>
     *     <tr>
     *       <td>
     *         <strong>STATE_BIT_SYNC</strong>
     *       </td>
     *       <td>20 ms</td>
     *       <td>20 ms</td>
     *       <td>1 ms (optional)</td>
     *       <td>20 ms</td>
     *       <td>20 ms</td>
     *       <td>-</td>
     *       <td>8 ms</td>
     *       <td>-</td>
     *       <td>1 ms (optional)</td>
     *       <td>4 ms</td>
     *     </tr>
     *     <tr>
     *       <td>
     *         <strong>STATE_SUBFRAME_SYNC</strong>
     *       </td>
     *       <td>6s</td>
     *       <td>6s</td>
     *       <td>-</td>
     *       <td>2 s</td>
     *       <td>6 s</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>100 ms</td>
     *       <td>-</td>
     *     </tr>
     *     <tr>
     *       <td>
     *         <strong>STATE_TOW_DECODED</strong>
     *       </td>
     *       <td colspan="2">1 week</td>
     *       <td>-</td>
     *       <td>1 day</td>
     *       <td colspan="2">1 week</td>
     *       <td colspan="2">1 week</td>
     *       <td>-</td>
     *       <td>1 week</td>
     *     </tr>
     *     <tr>
     *       <td>
     *         <strong>STATE_TOW_KNOWN</strong>
     *       </td>
     *       <td colspan="3">1 week</td>
     *       <td>1 day</td>
     *       <td colspan="2">1 week</td>
     *       <td colspan="3">1 week</td>
     *       <td>1 week</td>
     *     </tr>
     *     <tr>
     *       <td>
     *         <strong>STATE_GLO_STRING_SYNC</strong>
     *       </td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>2 s</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *     </tr>
     *     <tr>
     *       <td>
     *         <strong>STATE_GLO_TOD_DECODED</strong>
     *       </td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>1 day</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *     </tr>
     *     <tr>
     *       <td>
     *         <strong>STATE_GLO_TOD_KNOWN</strong>
     *       </td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>1 day</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *     </tr>
     *     <tr>
     *       <td>
     *         <strong>STATE_BDS_D2_BIT_SYNC</strong>
     *       </td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>2 ms</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *     </tr>
     *     <tr>
     *       <td>
     *         <strong>STATE_BDS_D2_SUBFRAME_SYNC</strong>
     *       </td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>600 ms</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *     </tr>
     *     <tr>
     *       <td>
     *         <strong>STATE_GAL_E1BC_CODE_LOCK</strong>
     *       </td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>4 ms</td>
     *       <td>4 ms</td>
     *       <td>-</td>
     *       <td>-</td>
     *     </tr>
     *     <tr>
     *       <td>
     *         <strong>STATE_GAL_E1C_2ND_CODE_LOCK</strong>
     *       </td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>100 ms</td>
     *       <td>-</td>
     *       <td>-</td>
     *     </tr>
     *     <tr>
     *       <td>
     *         <strong>STATE_2ND_CODE_LOCK</strong>
     *       </td>
     *       <td>-</td>
     *       <td>10 ms (optional)</td>
     *       <td>20 ms</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>100 ms (optional)</td>
     *       <td>100 ms</td>
     *       <td>-</td>
     *     </tr>
     *     <tr>
     *       <td>
     *         <strong>STATE_GAL_E1B_PAGE_SYNC</strong>
     *       </td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>2 s</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *     </tr>
     *     <tr>
     *       <td>
     *         <strong>STATE_SBAS_SYNC</strong>
     *       </td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>-</td>
     *       <td>1 s</td>
     *     </tr>
     *   </tbody>
     * </table>
     *
     * <p>Note: TOW Known refers to the case where TOW is possibly not decoded over the air but has
     * been determined from other sources. If TOW decoded is set then TOW Known must also be set.
     *
     * <p>Note well: if there is any ambiguity in integer millisecond, STATE_MSEC_AMBIGUOUS must be
     * set accordingly, in the 'state' field.  This value must be populated if 'state' !=
     * STATE_UNKNOWN.
     *
     * <p>Note on optional flags:
     * <ul>
     *     <li> For L1 C/A and B1I, STATE_SYMBOL_SYNC is optional since the symbol length is the
     *     same as the bit length.
     *     <li> For L5Q and E5aQ, STATE_BIT_SYNC and STATE_SYMBOL_SYNC are optional since they are
     *     implied by STATE_CODE_LOCK.
     *     <li> STATE_2ND_CODE_LOCK for L5I is optional since it is implied by STATE_SYMBOL_SYNC.
     *     <li> STATE_2ND_CODE_LOCK for E1C is optional since it is implied by
     *     STATE_GAL_E1C_2ND_CODE_LOCK.
     *     <li> For E1B and E1C, STATE_SYMBOL_SYNC is optional, because it is implied by
     *     STATE_GAL_E1BC_CODE_LOCK.
     * </ul>
     *
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
        public static final int STATE_2ND_CODE_LOCK = 65536 /* 1 << 16 */;
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
            if (o == STATE_2ND_CODE_LOCK) {
                return "STATE_2ND_CODE_LOCK";
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
            if ((o & STATE_2ND_CODE_LOCK) == STATE_2ND_CODE_LOCK) {
                list.add("STATE_2ND_CODE_LOCK");
                flipped |= STATE_2ND_CODE_LOCK;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(o & (~flipped)));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Extends a GNSS Measurement, adding a GnssMeasurementCodeType, a GnssMeasurementState, and
     * replacing the GnssConstellationType.
     */
    public final static class GnssMeasurement {
        /**
         * GNSS measurement information for a single satellite and frequency, as in the 1.1
         * version of the HAL with further clarification of the value reported in the
         * accumulatedDeltaRangeM field, i.e., the alignment of the phase measurement will not be
         * adjusted by the receiver so the in-phase and quadrature phase components will have a
         * quarter cycle offset as they do when transmitted from the satellites. If the measurement
         * is from a combination of the in-phase and quadrature phase components, then the alignment
         * of the phase measurement will be aligned to the in-phase component.
         *
         * In this version of the HAL, the field 'state' in the v1_1.v1_0 struct is deprecated, and
         * is no longer used by the framework. The satellite sync state is instead reported in
         * @2.0::IGnssMeasurementCallback.GnssMeasurement.state.
         *
         * In this version of the HAL, the field 'constellation' in the v1_1.v1_0 struct is
         * deprecated, and is no longer used by the framework. The constellation type is instead
         * reported in @2.0::IGnssMeasurementCallback.GnssMeasurement.constellation.
         */
        public android.hardware.gnss.V1_1.IGnssMeasurementCallback.GnssMeasurement v1_1 = new android.hardware.gnss.V1_1.IGnssMeasurementCallback.GnssMeasurement();
        /**
         * The type of code that is currently being tracked in the GNSS measurement.
         *
         * For high precision applications the type of code being tracked needs to be considered
         * in-order to properly apply code specific corrections to the pseudorange measurements.
         *
         * Value "A" represents GALILEO E1A, GALILEO E6A, IRNSS L5A, IRNSS SA.
         *
         * Value "B" represents GALILEO E1B, GALILEO E6B, IRNSS L5B, IRNSS SB.
         *
         * Value "C" represents GPS L1 C/A,  GPS L2 C/A, GLONASS G1 C/A, GLONASS G2 C/A, GALILEO E1C,
         * GALILEO E6C, SBAS L1 C/A, QZSS L1 C/A, IRNSS L5C.
         *
         * value "D" represents BDS B1C D.
         *
         * Value "I" represents GPS L5 I, GLONASS G3 I, GALILEO E5a I, GALILEO E5b I, GALILEO E5a+b I,
         * SBAS L5 I, QZSS L5 I, BDS B1 I, BDS B2 I, BDS B3 I.
         *
         * Value "L" represents GPS L1C (P), GPS L2C (L), QZSS L1C (P), QZSS L2C (L), LEX(6) L.
         *
         * Value "M" represents GPS L1M, GPS L2M.
         *
         * Value "N" represents GPS L1 codeless, GPS L2 codeless.
         *
         * Value "P" represents GPS L1P, GPS L2P, GLONASS G1P, GLONASS G2P, BDS B1C P.
         *
         * Value "Q" represents GPS L5 Q, GLONASS G3 Q, GALILEO E5a Q, GALILEO E5b Q, GALILEO E5a+b Q,
         * SBAS L5 Q, QZSS L5 Q, BDS B1 Q, BDS B2 Q, BDS B3 Q.
         *
         * Value "S" represents GPS L1C (D), GPS L2C (M), QZSS L1C (D), QZSS L2C (M), LEX(6) S.
         *
         * Value "W" represents GPS L1 Z-tracking, GPS L2 Z-tracking.
         *
         * Value "X" represents GPS L1C (D+P), GPS L2C (M+L), GPS L5 (I+Q), GLONASS G3 (I+Q),
         * GALILEO E1 (B+C), GALILEO E5a (I+Q), GALILEO E5b (I+Q), GALILEO E5a+b(I+Q),
         * GALILEO E6 (B+C), SBAS L5 (I+Q), QZSS L1C (D+P), QZSS L2C (M+L), QZSS L5 (I+Q),
         * LEX(6) (S+L), BDS B1 (I+Q), BDS B1C (D+P), BDS B2 (I+Q), BDS B3 (I+Q), IRNSS L5 (B+C).
         *
         * Value "Y" represents GPS L1Y, GPS L2Y.
         *
         * Value "Z" represents GALILEO E1 (A+B+C), GALILEO E6 (A+B+C), QZSS L1-SAIF.
         *
         * Value "UNKNOWN" represents the GNSS Measurement's code type is unknown.
         *
         * This is used to specify the observation descriptor defined in GNSS Observation Data File
         * Header Section Description in the RINEX standard (Version 3.XX). In RINEX Version 3.03,
         * in Appendix Table A2 Attributes are listed as uppercase letters (for instance, "A" for
         * "A channel"). In the future, if for instance a code "G" was added in the official RINEX
         * standard, "G" could be specified here.
         */
        public String codeType = new String();
        /**
         * Per satellite sync state. It represents the current sync state for the associated
         * satellite.
         *
         * Based on the sync state, the receivedSvTimeInNs field must be interpreted accordingly.
         *
         * This value is mandatory.
         */
        public int state;
        /**
         * The constellation type of the GNSS measurement.
         */
        public byte constellation = 0;

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.gnss.V2_0.IGnssMeasurementCallback.GnssMeasurement.class) {
                return false;
            }
            android.hardware.gnss.V2_0.IGnssMeasurementCallback.GnssMeasurement other = (android.hardware.gnss.V2_0.IGnssMeasurementCallback.GnssMeasurement)otherObject;
            if (!android.os.HidlSupport.deepEquals(this.v1_1, other.v1_1)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.codeType, other.codeType)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.state, other.state)) {
                return false;
            }
            if (this.constellation != other.constellation) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.v1_1), 
                    android.os.HidlSupport.deepHashCode(this.codeType), 
                    android.os.HidlSupport.deepHashCode(this.state), 
                    android.os.HidlSupport.deepHashCode(this.constellation));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".v1_1 = ");
            builder.append(this.v1_1);
            builder.append(", .codeType = ");
            builder.append(this.codeType);
            builder.append(", .state = ");
            builder.append(android.hardware.gnss.V2_0.IGnssMeasurementCallback.GnssMeasurementState.dumpBitfield(this.state));
            builder.append(", .constellation = ");
            builder.append(android.hardware.gnss.V2_0.GnssConstellationType.toString(this.constellation));
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(176 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<GnssMeasurement> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<GnssMeasurement> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 176,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.gnss.V2_0.IGnssMeasurementCallback.GnssMeasurement _hidl_vec_element = new android.hardware.gnss.V2_0.IGnssMeasurementCallback.GnssMeasurement();
                    ((android.hardware.gnss.V2_0.IGnssMeasurementCallback.GnssMeasurement) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 176);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            ((android.hardware.gnss.V1_1.IGnssMeasurementCallback.GnssMeasurement) v1_1).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
            codeType = _hidl_blob.getString(_hidl_offset + 152);

            parcel.readEmbeddedBuffer(
                    ((String) codeType).getBytes().length + 1,
                    _hidl_blob.handle(),
                    _hidl_offset + 152 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

            state = _hidl_blob.getInt32(_hidl_offset + 168);
            constellation = _hidl_blob.getInt8(_hidl_offset + 172);
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(176 /* size */);
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
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 176));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 176);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            v1_1.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
            _hidl_blob.putString(_hidl_offset + 152, codeType);
            _hidl_blob.putInt32(_hidl_offset + 168, state);
            _hidl_blob.putInt8(_hidl_offset + 172, constellation);
        }
    };

    /**
     * Complete set of GNSS Measurement data, same as 1.1 with additional enum in measurements.
     */
    public final static class GnssData {
        /**
         * The full set of satellite measurement observations.
         */
        public java.util.ArrayList<android.hardware.gnss.V2_0.IGnssMeasurementCallback.GnssMeasurement> measurements = new java.util.ArrayList<android.hardware.gnss.V2_0.IGnssMeasurementCallback.GnssMeasurement>();
        /**
         * The GNSS clock time reading.
         */
        public android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssClock clock = new android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssClock();
        /**
         * Timing information of the GNSS data synchronized with SystemClock.elapsedRealtimeNanos()
         * clock.
         */
        public android.hardware.gnss.V2_0.ElapsedRealtime elapsedRealtime = new android.hardware.gnss.V2_0.ElapsedRealtime();

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.gnss.V2_0.IGnssMeasurementCallback.GnssData.class) {
                return false;
            }
            android.hardware.gnss.V2_0.IGnssMeasurementCallback.GnssData other = (android.hardware.gnss.V2_0.IGnssMeasurementCallback.GnssData)otherObject;
            if (!android.os.HidlSupport.deepEquals(this.measurements, other.measurements)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.clock, other.clock)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.elapsedRealtime, other.elapsedRealtime)) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.measurements), 
                    android.os.HidlSupport.deepHashCode(this.clock), 
                    android.os.HidlSupport.deepHashCode(this.elapsedRealtime));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".measurements = ");
            builder.append(this.measurements);
            builder.append(", .clock = ");
            builder.append(this.clock);
            builder.append(", .elapsedRealtime = ");
            builder.append(this.elapsedRealtime);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(112 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<GnssData> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<GnssData> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 112,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.gnss.V2_0.IGnssMeasurementCallback.GnssData _hidl_vec_element = new android.hardware.gnss.V2_0.IGnssMeasurementCallback.GnssData();
                    ((android.hardware.gnss.V2_0.IGnssMeasurementCallback.GnssData) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 112);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            {
                int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 176,_hidl_blob.handle(),
                        _hidl_offset + 0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                ((java.util.ArrayList<android.hardware.gnss.V2_0.IGnssMeasurementCallback.GnssMeasurement>) measurements).clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.gnss.V2_0.IGnssMeasurementCallback.GnssMeasurement _hidl_vec_element = new android.hardware.gnss.V2_0.IGnssMeasurementCallback.GnssMeasurement();
                    ((android.hardware.gnss.V2_0.IGnssMeasurementCallback.GnssMeasurement) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 176);
                    ((java.util.ArrayList<android.hardware.gnss.V2_0.IGnssMeasurementCallback.GnssMeasurement>) measurements).add(_hidl_vec_element);
                }
            }
            ((android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssClock) clock).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 16);
            ((android.hardware.gnss.V2_0.ElapsedRealtime) elapsedRealtime).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 88);
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(112 /* size */);
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
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 112));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 112);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            {
                int _hidl_vec_size = measurements.size();
                _hidl_blob.putInt32(_hidl_offset + 0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(_hidl_offset + 0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 176));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    measurements.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 176);
                }
                _hidl_blob.putBlob(_hidl_offset + 0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }
            clock.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 16);
            elapsedRealtime.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 88);
        }
    };

    /**
     * Callback for the hal to pass a GnssData structure back to the client.
     *
     * @param data Contains a reading of GNSS measurements.
     */
    void gnssMeasurementCb_2_0(android.hardware.gnss.V2_0.IGnssMeasurementCallback.GnssData data)
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

        // Methods from ::android::hardware::gnss::V1_1::IGnssMeasurementCallback follow.
        @Override
        public void gnssMeasurementCb(android.hardware.gnss.V1_1.IGnssMeasurementCallback.GnssData data)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_1.IGnssMeasurementCallback.kInterfaceName);
            ((android.hardware.gnss.V1_1.IGnssMeasurementCallback.GnssData) data).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* gnssMeasurementCb */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::gnss::V2_0::IGnssMeasurementCallback follow.
        @Override
        public void gnssMeasurementCb_2_0(android.hardware.gnss.V2_0.IGnssMeasurementCallback.GnssData data)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V2_0.IGnssMeasurementCallback.kInterfaceName);
            ((android.hardware.gnss.V2_0.IGnssMeasurementCallback.GnssData) data).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(3 /* gnssMeasurementCb_2_0 */, _hidl_request, _hidl_reply, 0 /* flags */);
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
                    android.hardware.gnss.V2_0.IGnssMeasurementCallback.kInterfaceName,
                    android.hardware.gnss.V1_1.IGnssMeasurementCallback.kInterfaceName,
                    android.hardware.gnss.V1_0.IGnssMeasurementCallback.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.gnss.V2_0.IGnssMeasurementCallback.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{-35,108,-39,-37,-92,-3,-23,-102,27,-61,-53,23,40,-40,35,9,-11,9,-90,-26,-31,-103,62,80,66,-33,-91,-1,-28,-81,84,66} /* dd6cd9dba4fde99a1bc3cb1728d82309f509a6e6e1993e5042dfa5ffe4af5442 */,
                    new byte[/* 32 */]{122,-30,2,86,98,-29,14,105,10,63,-6,28,101,-52,-105,44,98,-105,-90,-122,56,23,64,85,-61,60,-65,61,46,75,-67,-36} /* 7ae2025662e30e690a3ffa1c65cc972c6297a68638174055c33cbf3d2e4bbddc */,
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

                case 2 /* gnssMeasurementCb */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_1.IGnssMeasurementCallback.kInterfaceName);

                    android.hardware.gnss.V1_1.IGnssMeasurementCallback.GnssData data = new android.hardware.gnss.V1_1.IGnssMeasurementCallback.GnssData();
                    ((android.hardware.gnss.V1_1.IGnssMeasurementCallback.GnssData) data).readFromParcel(_hidl_request);
                    gnssMeasurementCb(data);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 3 /* gnssMeasurementCb_2_0 */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V2_0.IGnssMeasurementCallback.kInterfaceName);

                    android.hardware.gnss.V2_0.IGnssMeasurementCallback.GnssData data = new android.hardware.gnss.V2_0.IGnssMeasurementCallback.GnssData();
                    ((android.hardware.gnss.V2_0.IGnssMeasurementCallback.GnssData) data).readFromParcel(_hidl_request);
                    gnssMeasurementCb_2_0(data);
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
