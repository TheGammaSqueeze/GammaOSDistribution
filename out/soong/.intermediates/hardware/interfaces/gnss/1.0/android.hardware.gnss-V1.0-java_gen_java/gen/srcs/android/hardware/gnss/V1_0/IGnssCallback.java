package android.hardware.gnss.V1_0;

/**
 * The interface is required for the HAL to communicate certain information
 * like status and location info back to the platform, the platform implements
 * the interfaces and passes a handle to the HAL.
 */
public interface IGnssCallback extends android.hidl.base.V1_0.IBase {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.gnss@1.0::IGnssCallback";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static IGnssCallback asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof IGnssCallback)) {
            return (IGnssCallback)iface;
        }

        IGnssCallback proxy = new IGnssCallback.Proxy(binder);

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
    public static IGnssCallback castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : IGnssCallback.asInterface(iface.asBinder());
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
    public static IGnssCallback getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return IGnssCallback.asInterface(android.os.HwBinder.getService("android.hardware.gnss@1.0::IGnssCallback", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static IGnssCallback getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static IGnssCallback getService(String serviceName) throws android.os.RemoteException {
        return IGnssCallback.asInterface(android.os.HwBinder.getService("android.hardware.gnss@1.0::IGnssCallback", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static IGnssCallback getService() throws android.os.RemoteException {
        return getService("default");
    }

    /**
     * Flags for the gnssSetCapabilities callback.
     */
    public static final class Capabilities {
        /**
         * GNSS HAL schedules fixes for RECURRENCE_PERIODIC mode.
         * If this is not set, then the framework will use 1000ms for
         * minInterval and will call start() and stop() to schedule the GNSS.
         */
        public static final int SCHEDULING = 1 /* 1 << 0 */;
        /**
         * GNSS supports MS-Based AGNSS mode
         */
        public static final int MSB = 2 /* 1 << 1 */;
        /**
         * GNSS supports MS-Assisted AGNSS mode
         */
        public static final int MSA = 4 /* 1 << 2 */;
        /**
         * GNSS supports single-shot fixes
         */
        public static final int SINGLE_SHOT = 8 /* 1 << 3 */;
        /**
         * GNSS supports on demand time injection
         */
        public static final int ON_DEMAND_TIME = 16 /* 1 << 4 */;
        /**
         * GNSS supports Geofencing
         */
        public static final int GEOFENCING = 32 /* 1 << 5 */;
        /**
         * GNSS supports Measurements for at least GPS.
         */
        public static final int MEASUREMENTS = 64 /* 1 << 6 */;
        /**
         * GNSS supports Navigation Messages
         */
        public static final int NAV_MESSAGES = 128 /* 1 << 7 */;
        public static final String toString(int o) {
            if (o == SCHEDULING) {
                return "SCHEDULING";
            }
            if (o == MSB) {
                return "MSB";
            }
            if (o == MSA) {
                return "MSA";
            }
            if (o == SINGLE_SHOT) {
                return "SINGLE_SHOT";
            }
            if (o == ON_DEMAND_TIME) {
                return "ON_DEMAND_TIME";
            }
            if (o == GEOFENCING) {
                return "GEOFENCING";
            }
            if (o == MEASUREMENTS) {
                return "MEASUREMENTS";
            }
            if (o == NAV_MESSAGES) {
                return "NAV_MESSAGES";
            }
            return "0x" + Integer.toHexString(o);
        }

        public static final String dumpBitfield(int o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            int flipped = 0;
            if ((o & SCHEDULING) == SCHEDULING) {
                list.add("SCHEDULING");
                flipped |= SCHEDULING;
            }
            if ((o & MSB) == MSB) {
                list.add("MSB");
                flipped |= MSB;
            }
            if ((o & MSA) == MSA) {
                list.add("MSA");
                flipped |= MSA;
            }
            if ((o & SINGLE_SHOT) == SINGLE_SHOT) {
                list.add("SINGLE_SHOT");
                flipped |= SINGLE_SHOT;
            }
            if ((o & ON_DEMAND_TIME) == ON_DEMAND_TIME) {
                list.add("ON_DEMAND_TIME");
                flipped |= ON_DEMAND_TIME;
            }
            if ((o & GEOFENCING) == GEOFENCING) {
                list.add("GEOFENCING");
                flipped |= GEOFENCING;
            }
            if ((o & MEASUREMENTS) == MEASUREMENTS) {
                list.add("MEASUREMENTS");
                flipped |= MEASUREMENTS;
            }
            if ((o & NAV_MESSAGES) == NAV_MESSAGES) {
                list.add("NAV_MESSAGES");
                flipped |= NAV_MESSAGES;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(o & (~flipped)));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * GNSS status event values.
     */
    public static final class GnssStatusValue {
        /**
         * GNSS status unknown.
         */
        public static final byte NONE = 0;
        /**
         * GNSS has begun navigating.
         */
        public static final byte SESSION_BEGIN = 1;
        /**
         * GNSS has stopped navigating.
         */
        public static final byte SESSION_END = 2;
        /**
         * GNSS has powered on but is not navigating.
         */
        public static final byte ENGINE_ON = 3;
        /**
         * GNSS is powered off.
         */
        public static final byte ENGINE_OFF = 4;
        public static final String toString(byte o) {
            if (o == NONE) {
                return "NONE";
            }
            if (o == SESSION_BEGIN) {
                return "SESSION_BEGIN";
            }
            if (o == SESSION_END) {
                return "SESSION_END";
            }
            if (o == ENGINE_ON) {
                return "ENGINE_ON";
            }
            if (o == ENGINE_OFF) {
                return "ENGINE_OFF";
            }
            return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
        }

        public static final String dumpBitfield(byte o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            byte flipped = 0;
            list.add("NONE"); // NONE == 0
            if ((o & SESSION_BEGIN) == SESSION_BEGIN) {
                list.add("SESSION_BEGIN");
                flipped |= SESSION_BEGIN;
            }
            if ((o & SESSION_END) == SESSION_END) {
                list.add("SESSION_END");
                flipped |= SESSION_END;
            }
            if ((o & ENGINE_ON) == ENGINE_ON) {
                list.add("ENGINE_ON");
                flipped |= ENGINE_ON;
            }
            if ((o & ENGINE_OFF) == ENGINE_OFF) {
                list.add("ENGINE_OFF");
                flipped |= ENGINE_OFF;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Flags that indicate information about the satellite
     */
    public static final class GnssSvFlags {
        public static final byte NONE = 0;
        public static final byte HAS_EPHEMERIS_DATA = 1 /* 1 << 0 */;
        public static final byte HAS_ALMANAC_DATA = 2 /* 1 << 1 */;
        public static final byte USED_IN_FIX = 4 /* 1 << 2 */;
        public static final byte HAS_CARRIER_FREQUENCY = 8 /* 1 << 3 */;
        public static final String toString(byte o) {
            if (o == NONE) {
                return "NONE";
            }
            if (o == HAS_EPHEMERIS_DATA) {
                return "HAS_EPHEMERIS_DATA";
            }
            if (o == HAS_ALMANAC_DATA) {
                return "HAS_ALMANAC_DATA";
            }
            if (o == USED_IN_FIX) {
                return "USED_IN_FIX";
            }
            if (o == HAS_CARRIER_FREQUENCY) {
                return "HAS_CARRIER_FREQUENCY";
            }
            return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
        }

        public static final String dumpBitfield(byte o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            byte flipped = 0;
            list.add("NONE"); // NONE == 0
            if ((o & HAS_EPHEMERIS_DATA) == HAS_EPHEMERIS_DATA) {
                list.add("HAS_EPHEMERIS_DATA");
                flipped |= HAS_EPHEMERIS_DATA;
            }
            if ((o & HAS_ALMANAC_DATA) == HAS_ALMANAC_DATA) {
                list.add("HAS_ALMANAC_DATA");
                flipped |= HAS_ALMANAC_DATA;
            }
            if ((o & USED_IN_FIX) == USED_IN_FIX) {
                list.add("USED_IN_FIX");
                flipped |= USED_IN_FIX;
            }
            if ((o & HAS_CARRIER_FREQUENCY) == HAS_CARRIER_FREQUENCY) {
                list.add("HAS_CARRIER_FREQUENCY");
                flipped |= HAS_CARRIER_FREQUENCY;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
            }
            return String.join(" | ", list);
        }

    };

    public final static class GnssSvInfo {
        /**
         * Pseudo-random or satellite ID number for the satellite, a.k.a. Space Vehicle (SV), or
         * FCN/OSN number for Glonass. The distinction is made by looking at constellation field.
         * Values must be in the range of:
         *
         * - GNSS:    1-32
         * - SBAS:    120-151, 183-192
         * - GLONASS: 1-24, the orbital slot number (OSN), if known.  Or, if not:
         *            93-106, the frequency channel number (FCN) (-7 to +6) offset by
         *            + 100
         *            i.e. report an FCN of -7 as 93, FCN of 0 as 100, and FCN of +6
         *            as 106.
         * - QZSS:    193-200
         * - Galileo: 1-36
         * - Beidou:  1-37
         * - IRNSS:   1-14
         */
        public short svid = 0;
        /**
         * Defines the constellation of the given SV.
         */
        public byte constellation = 0;
        /**
         * Carrier-to-noise density in dB-Hz, typically in the range [0, 63].
         * It contains the measured C/N0 value for the signal at the antenna port.
         *
         * This is a mandatory value.
         */
        public float cN0Dbhz = 0.0f;
        /**
         * Elevation of SV in degrees.
         */
        public float elevationDegrees = 0.0f;
        /**
         * Azimuth of SV in degrees.
         */
        public float azimuthDegrees = 0.0f;
        /**
         * Carrier frequency of the signal tracked, for example it can be the
         * GPS central frequency for L1 = 1575.45 MHz, or L2 = 1227.60 MHz, L5 =
         * 1176.45 MHz, varying GLO channels, etc. If the field is zero, it is
         * the primary common use central frequency, e.g. L1 = 1575.45 MHz for
         * GPS.
         *
         * For an L1, L5 receiver tracking a satellite on L1 and L5 at the same
         * time, two GnssSvInfo structs must be reported for this same
         * satellite, in one of the structs, all the values related
         * to L1 must be filled, and in the other all of the values related to
         * L5 must be filled.
         *
         * If the data is available, svFlag must contain HAS_CARRIER_FREQUENCY.
         */
        public float carrierFrequencyHz = 0.0f;
        /**
         * Contains additional data about the given SV.
         */
        public byte svFlag;

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.gnss.V1_0.IGnssCallback.GnssSvInfo.class) {
                return false;
            }
            android.hardware.gnss.V1_0.IGnssCallback.GnssSvInfo other = (android.hardware.gnss.V1_0.IGnssCallback.GnssSvInfo)otherObject;
            if (this.svid != other.svid) {
                return false;
            }
            if (this.constellation != other.constellation) {
                return false;
            }
            if (this.cN0Dbhz != other.cN0Dbhz) {
                return false;
            }
            if (this.elevationDegrees != other.elevationDegrees) {
                return false;
            }
            if (this.azimuthDegrees != other.azimuthDegrees) {
                return false;
            }
            if (this.carrierFrequencyHz != other.carrierFrequencyHz) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.svFlag, other.svFlag)) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.svid), 
                    android.os.HidlSupport.deepHashCode(this.constellation), 
                    android.os.HidlSupport.deepHashCode(this.cN0Dbhz), 
                    android.os.HidlSupport.deepHashCode(this.elevationDegrees), 
                    android.os.HidlSupport.deepHashCode(this.azimuthDegrees), 
                    android.os.HidlSupport.deepHashCode(this.carrierFrequencyHz), 
                    android.os.HidlSupport.deepHashCode(this.svFlag));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".svid = ");
            builder.append(this.svid);
            builder.append(", .constellation = ");
            builder.append(android.hardware.gnss.V1_0.GnssConstellationType.toString(this.constellation));
            builder.append(", .cN0Dbhz = ");
            builder.append(this.cN0Dbhz);
            builder.append(", .elevationDegrees = ");
            builder.append(this.elevationDegrees);
            builder.append(", .azimuthDegrees = ");
            builder.append(this.azimuthDegrees);
            builder.append(", .carrierFrequencyHz = ");
            builder.append(this.carrierFrequencyHz);
            builder.append(", .svFlag = ");
            builder.append(android.hardware.gnss.V1_0.IGnssCallback.GnssSvFlags.dumpBitfield(this.svFlag));
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(24 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<GnssSvInfo> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<GnssSvInfo> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 24,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.gnss.V1_0.IGnssCallback.GnssSvInfo _hidl_vec_element = new android.hardware.gnss.V1_0.IGnssCallback.GnssSvInfo();
                    ((android.hardware.gnss.V1_0.IGnssCallback.GnssSvInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 24);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            svid = _hidl_blob.getInt16(_hidl_offset + 0);
            constellation = _hidl_blob.getInt8(_hidl_offset + 2);
            cN0Dbhz = _hidl_blob.getFloat(_hidl_offset + 4);
            elevationDegrees = _hidl_blob.getFloat(_hidl_offset + 8);
            azimuthDegrees = _hidl_blob.getFloat(_hidl_offset + 12);
            carrierFrequencyHz = _hidl_blob.getFloat(_hidl_offset + 16);
            svFlag = _hidl_blob.getInt8(_hidl_offset + 20);
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(24 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<GnssSvInfo> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 24));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 24);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            _hidl_blob.putInt16(_hidl_offset + 0, svid);
            _hidl_blob.putInt8(_hidl_offset + 2, constellation);
            _hidl_blob.putFloat(_hidl_offset + 4, cN0Dbhz);
            _hidl_blob.putFloat(_hidl_offset + 8, elevationDegrees);
            _hidl_blob.putFloat(_hidl_offset + 12, azimuthDegrees);
            _hidl_blob.putFloat(_hidl_offset + 16, carrierFrequencyHz);
            _hidl_blob.putInt8(_hidl_offset + 20, svFlag);
        }
    };

    /**
     * Represents SV status.
     */
    public final static class GnssSvStatus {
        /**
         * Number of GNSS SVs currently visible, refers to the SVs stored in sv_list
         */
        public int numSvs = 0;
        /**
         * Pointer to an array of SVs information for all GNSS constellations,
         * except GNSS, which is reported using svList
         */
        public android.hardware.gnss.V1_0.IGnssCallback.GnssSvInfo[/* GnssMax:SVS_COUNT */] gnssSvList = new android.hardware.gnss.V1_0.IGnssCallback.GnssSvInfo[64 /* GnssMax:SVS_COUNT */];

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.gnss.V1_0.IGnssCallback.GnssSvStatus.class) {
                return false;
            }
            android.hardware.gnss.V1_0.IGnssCallback.GnssSvStatus other = (android.hardware.gnss.V1_0.IGnssCallback.GnssSvStatus)otherObject;
            if (this.numSvs != other.numSvs) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.gnssSvList, other.gnssSvList)) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.numSvs), 
                    android.os.HidlSupport.deepHashCode(this.gnssSvList));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".numSvs = ");
            builder.append(this.numSvs);
            builder.append(", .gnssSvList = ");
            builder.append(java.util.Arrays.toString(this.gnssSvList));
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(1540 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<GnssSvStatus> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<GnssSvStatus> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 1540,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.gnss.V1_0.IGnssCallback.GnssSvStatus _hidl_vec_element = new android.hardware.gnss.V1_0.IGnssCallback.GnssSvStatus();
                    ((android.hardware.gnss.V1_0.IGnssCallback.GnssSvStatus) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 1540);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            numSvs = _hidl_blob.getInt32(_hidl_offset + 0);
            {
                long _hidl_array_offset_0 = _hidl_offset + 4;
                for (int _hidl_index_0_0 = 0; _hidl_index_0_0 < 64 /* GnssMax:SVS_COUNT */; ++_hidl_index_0_0) {
                    ((android.hardware.gnss.V1_0.IGnssCallback.GnssSvInfo[/* GnssMax:SVS_COUNT */]) gnssSvList)[_hidl_index_0_0] = new android.hardware.gnss.V1_0.IGnssCallback.GnssSvInfo();
                    ((android.hardware.gnss.V1_0.IGnssCallback.GnssSvInfo) ((android.hardware.gnss.V1_0.IGnssCallback.GnssSvInfo[/* GnssMax:SVS_COUNT */]) gnssSvList)[_hidl_index_0_0]).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_array_offset_0);
                    _hidl_array_offset_0 += 24;
                }
            }
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(1540 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<GnssSvStatus> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1540));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 1540);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            _hidl_blob.putInt32(_hidl_offset + 0, numSvs);
            {
                long _hidl_array_offset_0 = _hidl_offset + 4;
                for (int _hidl_index_0_0 = 0; _hidl_index_0_0 < 64 /* GnssMax:SVS_COUNT */; ++_hidl_index_0_0) {
                    ((android.hardware.gnss.V1_0.IGnssCallback.GnssSvInfo[/* GnssMax:SVS_COUNT */]) gnssSvList)[_hidl_index_0_0].writeEmbeddedToBlob(_hidl_blob, _hidl_array_offset_0);
                    _hidl_array_offset_0 += 24;
                }
            }
        }
    };

    /**
     * Provides information about how new the underlying GPS/GNSS hardware and
     * software is.
     *
     * This information will be available for Android Test Applications. If a GNSS
     * HAL does not provide this information, it will be considered "2015 or
     * earlier".
     *
     * If a GNSS HAL does provide this information, then newer years will need to
     * meet newer CTS standards. E.g. if the date are 2016 or above, then N+ level
     * GnssMeasurement support will be verified.
     */
    public final static class GnssSystemInfo {
        /**
         * year in which the last update was made to the underlying hardware/firmware
         * used to capture GNSS signals, e.g. 2016
         */
        public short yearOfHw = 0;

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.gnss.V1_0.IGnssCallback.GnssSystemInfo.class) {
                return false;
            }
            android.hardware.gnss.V1_0.IGnssCallback.GnssSystemInfo other = (android.hardware.gnss.V1_0.IGnssCallback.GnssSystemInfo)otherObject;
            if (this.yearOfHw != other.yearOfHw) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.yearOfHw));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".yearOfHw = ");
            builder.append(this.yearOfHw);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(2 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<GnssSystemInfo> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<GnssSystemInfo> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 2,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.gnss.V1_0.IGnssCallback.GnssSystemInfo _hidl_vec_element = new android.hardware.gnss.V1_0.IGnssCallback.GnssSystemInfo();
                    ((android.hardware.gnss.V1_0.IGnssCallback.GnssSystemInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 2);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            yearOfHw = _hidl_blob.getInt16(_hidl_offset + 0);
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(2 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<GnssSystemInfo> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 2));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 2);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            _hidl_blob.putInt16(_hidl_offset + 0, yearOfHw);
        }
    };

    /**
     * Called when a GNSS location is available.
     *
     * @param location Location information from HAL.
     */
    void gnssLocationCb(android.hardware.gnss.V1_0.GnssLocation location)
        throws android.os.RemoteException;
    /**
     * Called to communicate the status of the GNSS engine.
     *
     * @param status Status information from HAL.
     */
    void gnssStatusCb(byte status)
        throws android.os.RemoteException;
    /**
     * @param svInfo SV status information from HAL.
     */
    void gnssSvStatusCb(android.hardware.gnss.V1_0.IGnssCallback.GnssSvStatus svInfo)
        throws android.os.RemoteException;
    /**
     * Called when NMEA data is available.
     * Callback for reporting NMEA sentences.
     *
     * @param timestamp Marks the instance of reporting.
     * @param nmea Follows standard NMEA 0183. Each sentence begins with a '$'
     * and ends with a carriage return/line feed sequence and can be no longer
     * than 80 characters of visible text (plus the line terminators). The data
     * is contained within this single line with data items separated by commas.
     * The data itself is just ascii text and may extend over multiple sentences
     * in certain specialized instances but is normally fully contained in one
     * variable length sentence. The data may vary in the amount of precision
     * contained in the message. For example time might be indicated to decimal
     * parts of a second or location may be shown with 3 or even 4 digits after
     * the decimal point. Programs that read the data must only use the commas
     * to determine the field boundaries and not depend on column positions.
     * There is a provision for a checksum at the end of each sentence which may
     * or may not be checked by the unit that reads the data. The checksum field
     * consists of a '*' and two hex digits representing an 8 bit exclusive OR
     * of all characters between, but not including, the '$' and '*'.
     */
    void gnssNmeaCb(long timestamp, String nmea)
        throws android.os.RemoteException;
    /**
     * Callback to inform framework of the GNSS engine's capabilities.
     *
     * @param capabilities Capability parameter is a bit field of
     * the Capabilities enum.
     */
    void gnssSetCapabilitesCb(int capabilities)
        throws android.os.RemoteException;
    /**
     * Callback utility for acquiring the GNSS wakelock. This can be used to prevent
     * the CPU from suspending while handling GNSS events.
     */
    void gnssAcquireWakelockCb()
        throws android.os.RemoteException;
    /**
     * Callback utility for releasing the GNSS wakelock.
     */
    void gnssReleaseWakelockCb()
        throws android.os.RemoteException;
    /**
     * Callback for requesting NTP time
     */
    void gnssRequestTimeCb()
        throws android.os.RemoteException;
    /**
     * Callback to inform framework of the engine's hardware version information.
     *
     * @param info GnssSystemInfo about the GPS/GNSS hardware.
     */
    void gnssSetSystemInfoCb(android.hardware.gnss.V1_0.IGnssCallback.GnssSystemInfo info)
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

    public static final class Proxy implements IGnssCallback {
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
            return "[class or subclass of " + IGnssCallback.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::gnss::V1_0::IGnssCallback follow.
        @Override
        public void gnssLocationCb(android.hardware.gnss.V1_0.GnssLocation location)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);
            ((android.hardware.gnss.V1_0.GnssLocation) location).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* gnssLocationCb */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void gnssStatusCb(byte status)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);
            _hidl_request.writeInt8(status);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* gnssStatusCb */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void gnssSvStatusCb(android.hardware.gnss.V1_0.IGnssCallback.GnssSvStatus svInfo)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);
            ((android.hardware.gnss.V1_0.IGnssCallback.GnssSvStatus) svInfo).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(3 /* gnssSvStatusCb */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void gnssNmeaCb(long timestamp, String nmea)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);
            _hidl_request.writeInt64(timestamp);
            _hidl_request.writeString(nmea);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(4 /* gnssNmeaCb */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void gnssSetCapabilitesCb(int capabilities)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);
            _hidl_request.writeInt32(capabilities);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(5 /* gnssSetCapabilitesCb */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void gnssAcquireWakelockCb()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(6 /* gnssAcquireWakelockCb */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void gnssReleaseWakelockCb()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(7 /* gnssReleaseWakelockCb */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void gnssRequestTimeCb()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(8 /* gnssRequestTimeCb */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void gnssSetSystemInfoCb(android.hardware.gnss.V1_0.IGnssCallback.GnssSystemInfo info)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);
            ((android.hardware.gnss.V1_0.IGnssCallback.GnssSystemInfo) info).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(9 /* gnssSetSystemInfoCb */, _hidl_request, _hidl_reply, 0 /* flags */);
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

    public static abstract class Stub extends android.os.HwBinder implements IGnssCallback {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{-100,-77,-33,43,-34,44,108,-43,-3,-106,-73,-60,21,85,66,12,-84,-41,-30,118,-91,86,-58,-124,-81,-111,-73,70,28,-122,70,15} /* 9cb3df2bde2c6cd5fd96b7c41555420cacd7e276a556c684af91b7461c86460f */,
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
                case 1 /* gnssLocationCb */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);

                    android.hardware.gnss.V1_0.GnssLocation location = new android.hardware.gnss.V1_0.GnssLocation();
                    ((android.hardware.gnss.V1_0.GnssLocation) location).readFromParcel(_hidl_request);
                    gnssLocationCb(location);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 2 /* gnssStatusCb */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);

                    byte status = _hidl_request.readInt8();
                    gnssStatusCb(status);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 3 /* gnssSvStatusCb */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);

                    android.hardware.gnss.V1_0.IGnssCallback.GnssSvStatus svInfo = new android.hardware.gnss.V1_0.IGnssCallback.GnssSvStatus();
                    ((android.hardware.gnss.V1_0.IGnssCallback.GnssSvStatus) svInfo).readFromParcel(_hidl_request);
                    gnssSvStatusCb(svInfo);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 4 /* gnssNmeaCb */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);

                    long timestamp = _hidl_request.readInt64();
                    String nmea = _hidl_request.readString();
                    gnssNmeaCb(timestamp, nmea);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 5 /* gnssSetCapabilitesCb */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);

                    int capabilities = _hidl_request.readInt32();
                    gnssSetCapabilitesCb(capabilities);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 6 /* gnssAcquireWakelockCb */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);

                    gnssAcquireWakelockCb();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 7 /* gnssReleaseWakelockCb */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);

                    gnssReleaseWakelockCb();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 8 /* gnssRequestTimeCb */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);

                    gnssRequestTimeCb();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 9 /* gnssSetSystemInfoCb */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnssCallback.kInterfaceName);

                    android.hardware.gnss.V1_0.IGnssCallback.GnssSystemInfo info = new android.hardware.gnss.V1_0.IGnssCallback.GnssSystemInfo();
                    ((android.hardware.gnss.V1_0.IGnssCallback.GnssSystemInfo) info).readFromParcel(_hidl_request);
                    gnssSetSystemInfoCb(info);
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
