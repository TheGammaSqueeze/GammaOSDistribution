package android.hardware.gnss.V2_1;

/**
 * The callback interface to report measurements from the HAL.
 */
public interface IGnssMeasurementCallback extends android.hardware.gnss.V2_0.IGnssMeasurementCallback {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.gnss@2.1::IGnssMeasurementCallback";

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
        return IGnssMeasurementCallback.asInterface(android.os.HwBinder.getService("android.hardware.gnss@2.1::IGnssMeasurementCallback", serviceName, retry));
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
        return IGnssMeasurementCallback.asInterface(android.os.HwBinder.getService("android.hardware.gnss@2.1::IGnssMeasurementCallback", serviceName));
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
        /**
         * A valid full inter-signal bias is stored in the data structure.
         */
        public static final int HAS_FULL_ISB = 65536 /* 1 << 16 */;
        /**
         * A valid full inter-signal bias uncertainty is stored in the data structure.
         */
        public static final int HAS_FULL_ISB_UNCERTAINTY = 131072 /* 1 << 17 */;
        /**
         * A valid satellite inter-signal bias is stored in the data structure.
         */
        public static final int HAS_SATELLITE_ISB = 262144 /* 1 << 18 */;
        /**
         * A valid satellite inter-signal bias uncertainty is stored in the data structure.
         */
        public static final int HAS_SATELLITE_ISB_UNCERTAINTY = 524288 /* 1 << 19 */;
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
            if (o == HAS_FULL_ISB) {
                return "HAS_FULL_ISB";
            }
            if (o == HAS_FULL_ISB_UNCERTAINTY) {
                return "HAS_FULL_ISB_UNCERTAINTY";
            }
            if (o == HAS_SATELLITE_ISB) {
                return "HAS_SATELLITE_ISB";
            }
            if (o == HAS_SATELLITE_ISB_UNCERTAINTY) {
                return "HAS_SATELLITE_ISB_UNCERTAINTY";
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
            if ((o & HAS_FULL_ISB) == HAS_FULL_ISB) {
                list.add("HAS_FULL_ISB");
                flipped |= HAS_FULL_ISB;
            }
            if ((o & HAS_FULL_ISB_UNCERTAINTY) == HAS_FULL_ISB_UNCERTAINTY) {
                list.add("HAS_FULL_ISB_UNCERTAINTY");
                flipped |= HAS_FULL_ISB_UNCERTAINTY;
            }
            if ((o & HAS_SATELLITE_ISB) == HAS_SATELLITE_ISB) {
                list.add("HAS_SATELLITE_ISB");
                flipped |= HAS_SATELLITE_ISB;
            }
            if ((o & HAS_SATELLITE_ISB_UNCERTAINTY) == HAS_SATELLITE_ISB_UNCERTAINTY) {
                list.add("HAS_SATELLITE_ISB_UNCERTAINTY");
                flipped |= HAS_SATELLITE_ISB_UNCERTAINTY;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(o & (~flipped)));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Extends a GNSS Measurement, adding basebandCN0DbHz, GnssMeasurementFlags,
     * receiverInterSignalBiasNs, receiverInterSignalBiasUncertaintyNs, satelliteInterSignalBiasNs
     * and satelliteInterSignalBiasUncertaintyNs.
     */
    public final static class GnssMeasurement {
        /**
         * GNSS measurement information for a single satellite and frequency, as in the 2.0 version
         * of the HAL.
         *
         * In this version of the HAL, the field 'flags' in the v2_0.v1_1.v1_0 struct is deprecated,
         * and is no longer used by the framework. The GNSS measurement flags are instead reported
         * in @2.1::IGnssMeasurementCallback.GnssMeasurement.flags.
         *
         */
        public android.hardware.gnss.V2_0.IGnssMeasurementCallback.GnssMeasurement v2_0 = new android.hardware.gnss.V2_0.IGnssMeasurementCallback.GnssMeasurement();
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
         * The full inter-signal bias (ISB) in nanoseconds.
         *
         * This value is the sum of the estimated receiver-side and the space-segment-side
         * inter-system bias, inter-frequency bias and inter-code bias, including
         *
         * - Receiver inter-constellation bias (with respect to the constellation in
         *   GnssClock.referenceSignalTypeForIsb)
         * - Receiver inter-frequency bias (with respect to the carrier frequency in
         *   GnssClock.referenceSignalTypeForIsb)
         * - Receiver inter-code bias (with respect to the code type in
         *   GnssClock.referenceSignalTypeForIsb)
         * - Master clock bias (e.g., GPS-GAL Time Offset (GGTO), GPS-UTC Time Offset
         *   (TauGps), BDS-GLO Time Offset (BGTO)) (with respect to the constellation in
         *   GnssClock.referenceSignalTypeForIsb)
         * - Group delay (e.g., Total Group Delay (TGD))
         * - Satellite inter-frequency bias (GLO only) (with respect to the carrier frequency in
         *   GnssClock.referenceSignalTypeForIsb)
         * - Satellite inter-code bias (e.g., Differential Code Bias (DCB)) (with respect to the
         *   code type in GnssClock.referenceSignalTypeForIsb)
         *
         * If a component of the above is already compensated in the provided
         * GnssMeasurement.receivedSvTimeInNs, then it must not be included in the reported full
         * ISB.
         *
         * The value does not include the inter-frequency Ionospheric bias.
         *
         * The sign of the value is defined by the following equation:
         *      corrected pseudorange = raw pseudorange - fullInterSignalBias
         *
         * The full ISB of GnssClock.referenceSignalTypeForIsb is defined to be 0.0 nanoseconds.
         */
        public double fullInterSignalBiasNs = 0.0d;
        /**
         * 1-sigma uncertainty associated with the full inter-signal bias in nanoseconds.
         */
        public double fullInterSignalBiasUncertaintyNs = 0.0d;
        /**
         * The satellite inter-signal bias in nanoseconds.
         *
         * This value is the sum of the space-segment-side inter-system bias, inter-frequency bias
         * and inter-code bias, including
         *
         * - Master clock bias (e.g., GPS-GAL Time Offset (GGTO), GPS-UTC Time Offset
         *   (TauGps), BDS-GLO Time Offset (BGTO)) (with respect to the constellation in
         *   GnssClock.referenceSignalTypeForIsb)
         * - Group delay (e.g., Total Group Delay (TGD))
         * - Satellite inter-frequency bias (GLO only) (with respect to the carrier frequency in
         *   GnssClock.referenceSignalTypeForIsb)
         * - Satellite inter-code bias (e.g., Differential Code Bias (DCB)) (with respect to the
         *   code type in GnssClock.referenceSignalTypeForIsb)
         *
         * The sign of the value is defined by the following equation:
         *      corrected pseudorange = raw pseudorange - satelliteInterSignalBias
         *
         * The satellite ISB of GnssClock.referenceSignalTypeForIsb is defined to be 0.0
         * nanoseconds.
         */
        public double satelliteInterSignalBiasNs = 0.0d;
        /**
         * 1-sigma uncertainty associated with the satellite inter-signal bias in nanoseconds.
         */
        public double satelliteInterSignalBiasUncertaintyNs = 0.0d;
        /**
         * Baseband Carrier-to-noise density in dB-Hz, typically in the range [0, 63]. It contains
         * the measured C/N0 value for the signal measured at the baseband.
         *
         * This is typically a few dB weaker than the value estimated for C/N0 at the antenna port,
         * which is reported in cN0DbHz.
         *
         * If a signal has separate components (e.g. Pilot and Data channels) and the receiver only
         * processes one of the components, then the reported basebandCN0DbHz reflects only the
         * component that is processed.
         *
         * This value is mandatory.
         */
        public double basebandCN0DbHz = 0.0d;

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssMeasurement.class) {
                return false;
            }
            android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssMeasurement other = (android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssMeasurement)otherObject;
            if (!android.os.HidlSupport.deepEquals(this.v2_0, other.v2_0)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.flags, other.flags)) {
                return false;
            }
            if (this.fullInterSignalBiasNs != other.fullInterSignalBiasNs) {
                return false;
            }
            if (this.fullInterSignalBiasUncertaintyNs != other.fullInterSignalBiasUncertaintyNs) {
                return false;
            }
            if (this.satelliteInterSignalBiasNs != other.satelliteInterSignalBiasNs) {
                return false;
            }
            if (this.satelliteInterSignalBiasUncertaintyNs != other.satelliteInterSignalBiasUncertaintyNs) {
                return false;
            }
            if (this.basebandCN0DbHz != other.basebandCN0DbHz) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.v2_0), 
                    android.os.HidlSupport.deepHashCode(this.flags), 
                    android.os.HidlSupport.deepHashCode(this.fullInterSignalBiasNs), 
                    android.os.HidlSupport.deepHashCode(this.fullInterSignalBiasUncertaintyNs), 
                    android.os.HidlSupport.deepHashCode(this.satelliteInterSignalBiasNs), 
                    android.os.HidlSupport.deepHashCode(this.satelliteInterSignalBiasUncertaintyNs), 
                    android.os.HidlSupport.deepHashCode(this.basebandCN0DbHz));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".v2_0 = ");
            builder.append(this.v2_0);
            builder.append(", .flags = ");
            builder.append(android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssMeasurementFlags.dumpBitfield(this.flags));
            builder.append(", .fullInterSignalBiasNs = ");
            builder.append(this.fullInterSignalBiasNs);
            builder.append(", .fullInterSignalBiasUncertaintyNs = ");
            builder.append(this.fullInterSignalBiasUncertaintyNs);
            builder.append(", .satelliteInterSignalBiasNs = ");
            builder.append(this.satelliteInterSignalBiasNs);
            builder.append(", .satelliteInterSignalBiasUncertaintyNs = ");
            builder.append(this.satelliteInterSignalBiasUncertaintyNs);
            builder.append(", .basebandCN0DbHz = ");
            builder.append(this.basebandCN0DbHz);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(224 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<GnssMeasurement> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<GnssMeasurement> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 224,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssMeasurement _hidl_vec_element = new android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssMeasurement();
                    ((android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssMeasurement) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 224);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            ((android.hardware.gnss.V2_0.IGnssMeasurementCallback.GnssMeasurement) v2_0).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
            flags = _hidl_blob.getInt32(_hidl_offset + 176);
            fullInterSignalBiasNs = _hidl_blob.getDouble(_hidl_offset + 184);
            fullInterSignalBiasUncertaintyNs = _hidl_blob.getDouble(_hidl_offset + 192);
            satelliteInterSignalBiasNs = _hidl_blob.getDouble(_hidl_offset + 200);
            satelliteInterSignalBiasUncertaintyNs = _hidl_blob.getDouble(_hidl_offset + 208);
            basebandCN0DbHz = _hidl_blob.getDouble(_hidl_offset + 216);
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(224 /* size */);
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
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 224));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 224);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            v2_0.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
            _hidl_blob.putInt32(_hidl_offset + 176, flags);
            _hidl_blob.putDouble(_hidl_offset + 184, fullInterSignalBiasNs);
            _hidl_blob.putDouble(_hidl_offset + 192, fullInterSignalBiasUncertaintyNs);
            _hidl_blob.putDouble(_hidl_offset + 200, satelliteInterSignalBiasNs);
            _hidl_blob.putDouble(_hidl_offset + 208, satelliteInterSignalBiasUncertaintyNs);
            _hidl_blob.putDouble(_hidl_offset + 216, basebandCN0DbHz);
        }
    };

    /**
     * Extends a GNSS clock time, adding a referenceSignalTypeForIsb.
     */
    public final static class GnssClock {
        /**
         * GNSS clock time information, as in the 1.0 version of the HAL.
         */
        public android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssClock v1_0 = new android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssClock();
        /**
         * Reference GNSS signal type for inter-signal bias.
         */
        public android.hardware.gnss.V2_1.GnssSignalType referenceSignalTypeForIsb = new android.hardware.gnss.V2_1.GnssSignalType();

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssClock.class) {
                return false;
            }
            android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssClock other = (android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssClock)otherObject;
            if (!android.os.HidlSupport.deepEquals(this.v1_0, other.v1_0)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.referenceSignalTypeForIsb, other.referenceSignalTypeForIsb)) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.v1_0), 
                    android.os.HidlSupport.deepHashCode(this.referenceSignalTypeForIsb));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".v1_0 = ");
            builder.append(this.v1_0);
            builder.append(", .referenceSignalTypeForIsb = ");
            builder.append(this.referenceSignalTypeForIsb);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(104 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<GnssClock> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<GnssClock> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 104,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssClock _hidl_vec_element = new android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssClock();
                    ((android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssClock) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 104);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            ((android.hardware.gnss.V1_0.IGnssMeasurementCallback.GnssClock) v1_0).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
            ((android.hardware.gnss.V2_1.GnssSignalType) referenceSignalTypeForIsb).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 72);
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(104 /* size */);
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
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 104));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 104);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            v1_0.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
            referenceSignalTypeForIsb.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 72);
        }
    };

    /**
     * Complete set of GNSS Measurement data, same as 2.0 with additional fields in measurements.
     */
    public final static class GnssData {
        /**
         * The full set of satellite measurement observations.
         */
        public java.util.ArrayList<android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssMeasurement> measurements = new java.util.ArrayList<android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssMeasurement>();
        /**
         * The GNSS clock time reading.
         */
        public android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssClock clock = new android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssClock();
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
            if (otherObject.getClass() != android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssData.class) {
                return false;
            }
            android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssData other = (android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssData)otherObject;
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
            android.os.HwBlob blob = parcel.readBuffer(144 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<GnssData> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<GnssData> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 144,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssData _hidl_vec_element = new android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssData();
                    ((android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssData) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 144);
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
                        _hidl_vec_size * 224,_hidl_blob.handle(),
                        _hidl_offset + 0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                ((java.util.ArrayList<android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssMeasurement>) measurements).clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssMeasurement _hidl_vec_element = new android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssMeasurement();
                    ((android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssMeasurement) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 224);
                    ((java.util.ArrayList<android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssMeasurement>) measurements).add(_hidl_vec_element);
                }
            }
            ((android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssClock) clock).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 16);
            ((android.hardware.gnss.V2_0.ElapsedRealtime) elapsedRealtime).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 120);
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(144 /* size */);
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
            {
                int _hidl_vec_size = measurements.size();
                _hidl_blob.putInt32(_hidl_offset + 0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(_hidl_offset + 0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 224));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    measurements.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 224);
                }
                _hidl_blob.putBlob(_hidl_offset + 0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }
            clock.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 16);
            elapsedRealtime.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 120);
        }
    };

    /**
     * Callback for the hal to pass a GnssData structure back to the client.
     *
     * @param data Contains a reading of GNSS measurements.
     */
    void gnssMeasurementCb_2_1(android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssData data)
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

        // Methods from ::android::hardware::gnss::V2_1::IGnssMeasurementCallback follow.
        @Override
        public void gnssMeasurementCb_2_1(android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssData data)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V2_1.IGnssMeasurementCallback.kInterfaceName);
            ((android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssData) data).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(4 /* gnssMeasurementCb_2_1 */, _hidl_request, _hidl_reply, 0 /* flags */);
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
                    android.hardware.gnss.V2_1.IGnssMeasurementCallback.kInterfaceName,
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
            return android.hardware.gnss.V2_1.IGnssMeasurementCallback.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{17,-23,-31,-95,-3,12,-101,61,-106,72,117,13,75,16,-36,42,-125,-99,58,102,-120,-112,76,63,-60,-107,0,-92,-25,-54,117,-80} /* 11e9e1a1fd0c9b3d9648750d4b10dc2a839d3a6688904c3fc49500a4e7ca75b0 */,
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

                case 4 /* gnssMeasurementCb_2_1 */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V2_1.IGnssMeasurementCallback.kInterfaceName);

                    android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssData data = new android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssData();
                    ((android.hardware.gnss.V2_1.IGnssMeasurementCallback.GnssData) data).readFromParcel(_hidl_request);
                    gnssMeasurementCb_2_1(data);
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
