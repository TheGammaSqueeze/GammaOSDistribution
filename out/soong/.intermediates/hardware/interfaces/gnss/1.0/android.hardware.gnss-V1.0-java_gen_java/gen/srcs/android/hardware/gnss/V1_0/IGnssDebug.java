package android.hardware.gnss.V1_0;

/**
 * Extended interface for DEBUG support.
 */
public interface IGnssDebug extends android.hidl.base.V1_0.IBase {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.gnss@1.0::IGnssDebug";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static IGnssDebug asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof IGnssDebug)) {
            return (IGnssDebug)iface;
        }

        IGnssDebug proxy = new IGnssDebug.Proxy(binder);

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
    public static IGnssDebug castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : IGnssDebug.asInterface(iface.asBinder());
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
    public static IGnssDebug getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return IGnssDebug.asInterface(android.os.HwBinder.getService("android.hardware.gnss@1.0::IGnssDebug", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static IGnssDebug getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static IGnssDebug getService(String serviceName) throws android.os.RemoteException {
        return IGnssDebug.asInterface(android.os.HwBinder.getService("android.hardware.gnss@1.0::IGnssDebug", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static IGnssDebug getService() throws android.os.RemoteException {
        return getService("default");
    }

    public static final class SatelliteEphemerisType {
        /**
         * Ephemeris is known for this satellite.
         */
        public static final byte EPHEMERIS = 0;
        /**
         * Ephemeris is not known, but Almanac (approximate location) is known.
         */
        public static final byte ALMANAC_ONLY = 1 /* ::android::hardware::gnss::V1_0::IGnssDebug::SatelliteEphemerisType.EPHEMERIS implicitly + 1 */;
        /**
         * Both ephemeris & almanac are not known (e.g. during a cold start
         * blind search.)
         */
        public static final byte NOT_AVAILABLE = 2 /* ::android::hardware::gnss::V1_0::IGnssDebug::SatelliteEphemerisType.ALMANAC_ONLY implicitly + 1 */;
        public static final String toString(byte o) {
            if (o == EPHEMERIS) {
                return "EPHEMERIS";
            }
            if (o == ALMANAC_ONLY) {
                return "ALMANAC_ONLY";
            }
            if (o == NOT_AVAILABLE) {
                return "NOT_AVAILABLE";
            }
            return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
        }

        public static final String dumpBitfield(byte o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            byte flipped = 0;
            list.add("EPHEMERIS"); // EPHEMERIS == 0
            if ((o & ALMANAC_ONLY) == ALMANAC_ONLY) {
                list.add("ALMANAC_ONLY");
                flipped |= ALMANAC_ONLY;
            }
            if ((o & NOT_AVAILABLE) == NOT_AVAILABLE) {
                list.add("NOT_AVAILABLE");
                flipped |= NOT_AVAILABLE;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
            }
            return String.join(" | ", list);
        }

    };

    public static final class SatelliteEphemerisSource {
        /**
         * The ephemeris (or almanac only) information was demodulated from the
         * signal received on the device
         */
        public static final byte DEMODULATED = 0;
        /**
         * The ephemeris (or almanac only) information was received from a SUPL
         * server.
         */
        public static final byte SUPL_PROVIDED = 1 /* ::android::hardware::gnss::V1_0::IGnssDebug::SatelliteEphemerisSource.DEMODULATED implicitly + 1 */;
        /**
         * The ephemeris (or almanac only) information was provided by another
         * server.
         */
        public static final byte OTHER_SERVER_PROVIDED = 2 /* ::android::hardware::gnss::V1_0::IGnssDebug::SatelliteEphemerisSource.SUPL_PROVIDED implicitly + 1 */;
        /**
         * The ephemeris (or almanac only) information was provided by another
         * method, e.g. injected via a local debug tool, from build defaults
         * (e.g. almanac), or is from a satellite
         * with SatelliteEphemerisType::NOT_AVAILABLE.
         */
        public static final byte OTHER = 3 /* ::android::hardware::gnss::V1_0::IGnssDebug::SatelliteEphemerisSource.OTHER_SERVER_PROVIDED implicitly + 1 */;
        public static final String toString(byte o) {
            if (o == DEMODULATED) {
                return "DEMODULATED";
            }
            if (o == SUPL_PROVIDED) {
                return "SUPL_PROVIDED";
            }
            if (o == OTHER_SERVER_PROVIDED) {
                return "OTHER_SERVER_PROVIDED";
            }
            if (o == OTHER) {
                return "OTHER";
            }
            return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
        }

        public static final String dumpBitfield(byte o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            byte flipped = 0;
            list.add("DEMODULATED"); // DEMODULATED == 0
            if ((o & SUPL_PROVIDED) == SUPL_PROVIDED) {
                list.add("SUPL_PROVIDED");
                flipped |= SUPL_PROVIDED;
            }
            if ((o & OTHER_SERVER_PROVIDED) == OTHER_SERVER_PROVIDED) {
                list.add("OTHER_SERVER_PROVIDED");
                flipped |= OTHER_SERVER_PROVIDED;
            }
            if ((o & OTHER) == OTHER) {
                list.add("OTHER");
                flipped |= OTHER;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
            }
            return String.join(" | ", list);
        }

    };

    public static final class SatelliteEphemerisHealth {
        /**
         * The ephemeris is known good.
         */
        public static final byte GOOD = 0;
        /**
         * The ephemeris is known bad.
         */
        public static final byte BAD = 1 /* ::android::hardware::gnss::V1_0::IGnssDebug::SatelliteEphemerisHealth.GOOD implicitly + 1 */;
        /**
         * The ephemeris is unknown to be good or bad.
         */
        public static final byte UNKNOWN = 2 /* ::android::hardware::gnss::V1_0::IGnssDebug::SatelliteEphemerisHealth.BAD implicitly + 1 */;
        public static final String toString(byte o) {
            if (o == GOOD) {
                return "GOOD";
            }
            if (o == BAD) {
                return "BAD";
            }
            if (o == UNKNOWN) {
                return "UNKNOWN";
            }
            return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
        }

        public static final String dumpBitfield(byte o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            byte flipped = 0;
            list.add("GOOD"); // GOOD == 0
            if ((o & BAD) == BAD) {
                list.add("BAD");
                flipped |= BAD;
            }
            if ((o & UNKNOWN) == UNKNOWN) {
                list.add("UNKNOWN");
                flipped |= UNKNOWN;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Provides the current best known position from any
     * source (GNSS or injected assistance).
     */
    public final static class PositionDebug {
        /**
         * Validity of the data in this struct. False only if no
         * latitude/longitude information is known.
         */
        public boolean valid = false;
        /**
         * Latitude expressed in degrees
         */
        public double latitudeDegrees = 0.0d;
        /**
         * Longitude expressed in degrees
         */
        public double longitudeDegrees = 0.0d;
        /**
         * Altitude above ellipsoid expressed in meters
         */
        public float altitudeMeters = 0.0f;
        /**
         * Represents horizontal speed in meters per second.
         */
        public float speedMetersPerSec = 0.0f;
        /**
         * Represents heading in degrees.
         */
        public float bearingDegrees = 0.0f;
        /**
         * Estimated horizontal accuracy of position expressed in meters,
         * radial, 68% confidence.
         */
        public double horizontalAccuracyMeters = 0.0d;
        /**
         * Estimated vertical accuracy of position expressed in meters, with
         * 68% confidence.
         */
        public double verticalAccuracyMeters = 0.0d;
        /**
         * Estimated speed accuracy in meters per second with 68% confidence.
         */
        public double speedAccuracyMetersPerSecond = 0.0d;
        /**
         * estimated bearing accuracy degrees with 68% confidence.
         */
        public double bearingAccuracyDegrees = 0.0d;
        /**
         * Time duration before this report that this position information was
         * valid.  This can, for example, be a previous injected location with
         * an age potentially thousands of seconds old, or
         * extrapolated to the current time (with appropriately increased
         * accuracy estimates), with a (near) zero age.
         */
        public float ageSeconds = 0.0f;

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.gnss.V1_0.IGnssDebug.PositionDebug.class) {
                return false;
            }
            android.hardware.gnss.V1_0.IGnssDebug.PositionDebug other = (android.hardware.gnss.V1_0.IGnssDebug.PositionDebug)otherObject;
            if (this.valid != other.valid) {
                return false;
            }
            if (this.latitudeDegrees != other.latitudeDegrees) {
                return false;
            }
            if (this.longitudeDegrees != other.longitudeDegrees) {
                return false;
            }
            if (this.altitudeMeters != other.altitudeMeters) {
                return false;
            }
            if (this.speedMetersPerSec != other.speedMetersPerSec) {
                return false;
            }
            if (this.bearingDegrees != other.bearingDegrees) {
                return false;
            }
            if (this.horizontalAccuracyMeters != other.horizontalAccuracyMeters) {
                return false;
            }
            if (this.verticalAccuracyMeters != other.verticalAccuracyMeters) {
                return false;
            }
            if (this.speedAccuracyMetersPerSecond != other.speedAccuracyMetersPerSecond) {
                return false;
            }
            if (this.bearingAccuracyDegrees != other.bearingAccuracyDegrees) {
                return false;
            }
            if (this.ageSeconds != other.ageSeconds) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.valid), 
                    android.os.HidlSupport.deepHashCode(this.latitudeDegrees), 
                    android.os.HidlSupport.deepHashCode(this.longitudeDegrees), 
                    android.os.HidlSupport.deepHashCode(this.altitudeMeters), 
                    android.os.HidlSupport.deepHashCode(this.speedMetersPerSec), 
                    android.os.HidlSupport.deepHashCode(this.bearingDegrees), 
                    android.os.HidlSupport.deepHashCode(this.horizontalAccuracyMeters), 
                    android.os.HidlSupport.deepHashCode(this.verticalAccuracyMeters), 
                    android.os.HidlSupport.deepHashCode(this.speedAccuracyMetersPerSecond), 
                    android.os.HidlSupport.deepHashCode(this.bearingAccuracyDegrees), 
                    android.os.HidlSupport.deepHashCode(this.ageSeconds));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".valid = ");
            builder.append(this.valid);
            builder.append(", .latitudeDegrees = ");
            builder.append(this.latitudeDegrees);
            builder.append(", .longitudeDegrees = ");
            builder.append(this.longitudeDegrees);
            builder.append(", .altitudeMeters = ");
            builder.append(this.altitudeMeters);
            builder.append(", .speedMetersPerSec = ");
            builder.append(this.speedMetersPerSec);
            builder.append(", .bearingDegrees = ");
            builder.append(this.bearingDegrees);
            builder.append(", .horizontalAccuracyMeters = ");
            builder.append(this.horizontalAccuracyMeters);
            builder.append(", .verticalAccuracyMeters = ");
            builder.append(this.verticalAccuracyMeters);
            builder.append(", .speedAccuracyMetersPerSecond = ");
            builder.append(this.speedAccuracyMetersPerSecond);
            builder.append(", .bearingAccuracyDegrees = ");
            builder.append(this.bearingAccuracyDegrees);
            builder.append(", .ageSeconds = ");
            builder.append(this.ageSeconds);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(80 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<PositionDebug> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<PositionDebug> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 80,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.gnss.V1_0.IGnssDebug.PositionDebug _hidl_vec_element = new android.hardware.gnss.V1_0.IGnssDebug.PositionDebug();
                    ((android.hardware.gnss.V1_0.IGnssDebug.PositionDebug) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 80);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            valid = _hidl_blob.getBool(_hidl_offset + 0);
            latitudeDegrees = _hidl_blob.getDouble(_hidl_offset + 8);
            longitudeDegrees = _hidl_blob.getDouble(_hidl_offset + 16);
            altitudeMeters = _hidl_blob.getFloat(_hidl_offset + 24);
            speedMetersPerSec = _hidl_blob.getFloat(_hidl_offset + 28);
            bearingDegrees = _hidl_blob.getFloat(_hidl_offset + 32);
            horizontalAccuracyMeters = _hidl_blob.getDouble(_hidl_offset + 40);
            verticalAccuracyMeters = _hidl_blob.getDouble(_hidl_offset + 48);
            speedAccuracyMetersPerSecond = _hidl_blob.getDouble(_hidl_offset + 56);
            bearingAccuracyDegrees = _hidl_blob.getDouble(_hidl_offset + 64);
            ageSeconds = _hidl_blob.getFloat(_hidl_offset + 72);
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(80 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<PositionDebug> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 80));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 80);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            _hidl_blob.putBool(_hidl_offset + 0, valid);
            _hidl_blob.putDouble(_hidl_offset + 8, latitudeDegrees);
            _hidl_blob.putDouble(_hidl_offset + 16, longitudeDegrees);
            _hidl_blob.putFloat(_hidl_offset + 24, altitudeMeters);
            _hidl_blob.putFloat(_hidl_offset + 28, speedMetersPerSec);
            _hidl_blob.putFloat(_hidl_offset + 32, bearingDegrees);
            _hidl_blob.putDouble(_hidl_offset + 40, horizontalAccuracyMeters);
            _hidl_blob.putDouble(_hidl_offset + 48, verticalAccuracyMeters);
            _hidl_blob.putDouble(_hidl_offset + 56, speedAccuracyMetersPerSecond);
            _hidl_blob.putDouble(_hidl_offset + 64, bearingAccuracyDegrees);
            _hidl_blob.putFloat(_hidl_offset + 72, ageSeconds);
        }
    };

    /**
     * Provides the current best known UTC time estimate.
     * If no fresh information is available, e.g. after a delete all,
     * then whatever the effective defaults are on the device must be
     * provided (e.g. Jan. 1, 2017, with an uncertainty of 5 years) expressed
     * in the specified units.
     */
    public final static class TimeDebug {
        /**
         * UTC time estimate.
         */
        public long timeEstimate = 0L;
        /**
         * 68% error estimate in time.
         */
        public float timeUncertaintyNs = 0.0f;
        /**
         * 68% error estimate in local clock drift,
         * in nanoseconds per second (also known as parts per billion - ppb.)
         */
        public float frequencyUncertaintyNsPerSec = 0.0f;

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.gnss.V1_0.IGnssDebug.TimeDebug.class) {
                return false;
            }
            android.hardware.gnss.V1_0.IGnssDebug.TimeDebug other = (android.hardware.gnss.V1_0.IGnssDebug.TimeDebug)otherObject;
            if (this.timeEstimate != other.timeEstimate) {
                return false;
            }
            if (this.timeUncertaintyNs != other.timeUncertaintyNs) {
                return false;
            }
            if (this.frequencyUncertaintyNsPerSec != other.frequencyUncertaintyNsPerSec) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.timeEstimate), 
                    android.os.HidlSupport.deepHashCode(this.timeUncertaintyNs), 
                    android.os.HidlSupport.deepHashCode(this.frequencyUncertaintyNsPerSec));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".timeEstimate = ");
            builder.append(this.timeEstimate);
            builder.append(", .timeUncertaintyNs = ");
            builder.append(this.timeUncertaintyNs);
            builder.append(", .frequencyUncertaintyNsPerSec = ");
            builder.append(this.frequencyUncertaintyNsPerSec);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(16 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<TimeDebug> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<TimeDebug> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 16,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.gnss.V1_0.IGnssDebug.TimeDebug _hidl_vec_element = new android.hardware.gnss.V1_0.IGnssDebug.TimeDebug();
                    ((android.hardware.gnss.V1_0.IGnssDebug.TimeDebug) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 16);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            timeEstimate = _hidl_blob.getInt64(_hidl_offset + 0);
            timeUncertaintyNs = _hidl_blob.getFloat(_hidl_offset + 8);
            frequencyUncertaintyNsPerSec = _hidl_blob.getFloat(_hidl_offset + 12);
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<TimeDebug> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 16));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 16);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            _hidl_blob.putInt64(_hidl_offset + 0, timeEstimate);
            _hidl_blob.putFloat(_hidl_offset + 8, timeUncertaintyNs);
            _hidl_blob.putFloat(_hidl_offset + 12, frequencyUncertaintyNsPerSec);
        }
    };

    /**
     * Provides a single satellite info that has decoded navigation data.
     */
    public final static class SatelliteData {
        /**
         * Satellite vehicle ID number
         */
        public short svid = 0;
        /**
         * Defines the constellation type of the given SV.
         */
        public byte constellation = 0;
        /**
         * Defines the standard broadcast ephemeris or almanac availability for
         * the satellite.  To report status of predicted orbit and clock
         * information, see the serverPrediction fields below.
         */
        public byte ephemerisType = 0;
        /**
         * Defines the ephemeris source of the satellite.
         */
        public byte ephemerisSource = 0;
        /**
         * Defines whether the satellite is known healthy
         * (safe for use in location calculation.)
         */
        public byte ephemerisHealth = 0;
        /**
         * Time duration from this report (current time), minus the
         * effective time of the ephemeris source (e.g. TOE, TOA.)
         * Set to 0 when ephemerisType is NOT_AVAILABLE.
         */
        public float ephemerisAgeSeconds = 0.0f;
        /**
         * True if a server has provided a predicted orbit and clock model for
         * this satellite.
         */
        public boolean serverPredictionIsAvailable = false;
        /**
         * Time duration from this report (current time) minus the time of the
         * start of the server predicted information.  For example, a 1 day
         * old prediction would be reported as 86400 seconds here.
         */
        public float serverPredictionAgeSeconds = 0.0f;

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.gnss.V1_0.IGnssDebug.SatelliteData.class) {
                return false;
            }
            android.hardware.gnss.V1_0.IGnssDebug.SatelliteData other = (android.hardware.gnss.V1_0.IGnssDebug.SatelliteData)otherObject;
            if (this.svid != other.svid) {
                return false;
            }
            if (this.constellation != other.constellation) {
                return false;
            }
            if (this.ephemerisType != other.ephemerisType) {
                return false;
            }
            if (this.ephemerisSource != other.ephemerisSource) {
                return false;
            }
            if (this.ephemerisHealth != other.ephemerisHealth) {
                return false;
            }
            if (this.ephemerisAgeSeconds != other.ephemerisAgeSeconds) {
                return false;
            }
            if (this.serverPredictionIsAvailable != other.serverPredictionIsAvailable) {
                return false;
            }
            if (this.serverPredictionAgeSeconds != other.serverPredictionAgeSeconds) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.svid), 
                    android.os.HidlSupport.deepHashCode(this.constellation), 
                    android.os.HidlSupport.deepHashCode(this.ephemerisType), 
                    android.os.HidlSupport.deepHashCode(this.ephemerisSource), 
                    android.os.HidlSupport.deepHashCode(this.ephemerisHealth), 
                    android.os.HidlSupport.deepHashCode(this.ephemerisAgeSeconds), 
                    android.os.HidlSupport.deepHashCode(this.serverPredictionIsAvailable), 
                    android.os.HidlSupport.deepHashCode(this.serverPredictionAgeSeconds));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".svid = ");
            builder.append(this.svid);
            builder.append(", .constellation = ");
            builder.append(android.hardware.gnss.V1_0.GnssConstellationType.toString(this.constellation));
            builder.append(", .ephemerisType = ");
            builder.append(android.hardware.gnss.V1_0.IGnssDebug.SatelliteEphemerisType.toString(this.ephemerisType));
            builder.append(", .ephemerisSource = ");
            builder.append(android.hardware.gnss.V1_0.IGnssDebug.SatelliteEphemerisSource.toString(this.ephemerisSource));
            builder.append(", .ephemerisHealth = ");
            builder.append(android.hardware.gnss.V1_0.IGnssDebug.SatelliteEphemerisHealth.toString(this.ephemerisHealth));
            builder.append(", .ephemerisAgeSeconds = ");
            builder.append(this.ephemerisAgeSeconds);
            builder.append(", .serverPredictionIsAvailable = ");
            builder.append(this.serverPredictionIsAvailable);
            builder.append(", .serverPredictionAgeSeconds = ");
            builder.append(this.serverPredictionAgeSeconds);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(20 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<SatelliteData> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<SatelliteData> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 20,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.gnss.V1_0.IGnssDebug.SatelliteData _hidl_vec_element = new android.hardware.gnss.V1_0.IGnssDebug.SatelliteData();
                    ((android.hardware.gnss.V1_0.IGnssDebug.SatelliteData) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 20);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            svid = _hidl_blob.getInt16(_hidl_offset + 0);
            constellation = _hidl_blob.getInt8(_hidl_offset + 2);
            ephemerisType = _hidl_blob.getInt8(_hidl_offset + 3);
            ephemerisSource = _hidl_blob.getInt8(_hidl_offset + 4);
            ephemerisHealth = _hidl_blob.getInt8(_hidl_offset + 5);
            ephemerisAgeSeconds = _hidl_blob.getFloat(_hidl_offset + 8);
            serverPredictionIsAvailable = _hidl_blob.getBool(_hidl_offset + 12);
            serverPredictionAgeSeconds = _hidl_blob.getFloat(_hidl_offset + 16);
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(20 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<SatelliteData> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 20));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 20);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            _hidl_blob.putInt16(_hidl_offset + 0, svid);
            _hidl_blob.putInt8(_hidl_offset + 2, constellation);
            _hidl_blob.putInt8(_hidl_offset + 3, ephemerisType);
            _hidl_blob.putInt8(_hidl_offset + 4, ephemerisSource);
            _hidl_blob.putInt8(_hidl_offset + 5, ephemerisHealth);
            _hidl_blob.putFloat(_hidl_offset + 8, ephemerisAgeSeconds);
            _hidl_blob.putBool(_hidl_offset + 12, serverPredictionIsAvailable);
            _hidl_blob.putFloat(_hidl_offset + 16, serverPredictionAgeSeconds);
        }
    };

    /**
     * Provides a set of debug information that is filled by the GNSS chipset
     * when the method getDebugData() is invoked.
     */
    public final static class DebugData {
        /**
         * Current best known position.
         */
        public android.hardware.gnss.V1_0.IGnssDebug.PositionDebug position = new android.hardware.gnss.V1_0.IGnssDebug.PositionDebug();
        /**
         * Current best know time estimate
         */
        public android.hardware.gnss.V1_0.IGnssDebug.TimeDebug time = new android.hardware.gnss.V1_0.IGnssDebug.TimeDebug();
        /**
         * Provides a list of the available satellite data, for all
         * satellites and constellations the device can track,
         * including GnssConstellationType UNKNOWN.
         */
        public java.util.ArrayList<android.hardware.gnss.V1_0.IGnssDebug.SatelliteData> satelliteDataArray = new java.util.ArrayList<android.hardware.gnss.V1_0.IGnssDebug.SatelliteData>();

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.gnss.V1_0.IGnssDebug.DebugData.class) {
                return false;
            }
            android.hardware.gnss.V1_0.IGnssDebug.DebugData other = (android.hardware.gnss.V1_0.IGnssDebug.DebugData)otherObject;
            if (!android.os.HidlSupport.deepEquals(this.position, other.position)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.time, other.time)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.satelliteDataArray, other.satelliteDataArray)) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.position), 
                    android.os.HidlSupport.deepHashCode(this.time), 
                    android.os.HidlSupport.deepHashCode(this.satelliteDataArray));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".position = ");
            builder.append(this.position);
            builder.append(", .time = ");
            builder.append(this.time);
            builder.append(", .satelliteDataArray = ");
            builder.append(this.satelliteDataArray);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(112 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<DebugData> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<DebugData> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 112,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.gnss.V1_0.IGnssDebug.DebugData _hidl_vec_element = new android.hardware.gnss.V1_0.IGnssDebug.DebugData();
                    ((android.hardware.gnss.V1_0.IGnssDebug.DebugData) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 112);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            ((android.hardware.gnss.V1_0.IGnssDebug.PositionDebug) position).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
            ((android.hardware.gnss.V1_0.IGnssDebug.TimeDebug) time).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 80);
            {
                int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 96 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 20,_hidl_blob.handle(),
                        _hidl_offset + 96 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                ((java.util.ArrayList<android.hardware.gnss.V1_0.IGnssDebug.SatelliteData>) satelliteDataArray).clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.gnss.V1_0.IGnssDebug.SatelliteData _hidl_vec_element = new android.hardware.gnss.V1_0.IGnssDebug.SatelliteData();
                    ((android.hardware.gnss.V1_0.IGnssDebug.SatelliteData) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 20);
                    ((java.util.ArrayList<android.hardware.gnss.V1_0.IGnssDebug.SatelliteData>) satelliteDataArray).add(_hidl_vec_element);
                }
            }
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(112 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<DebugData> _hidl_vec) {
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
            position.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
            time.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 80);
            {
                int _hidl_vec_size = satelliteDataArray.size();
                _hidl_blob.putInt32(_hidl_offset + 96 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(_hidl_offset + 96 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 20));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    satelliteDataArray.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 20);
                }
                _hidl_blob.putBlob(_hidl_offset + 96 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }
        }
    };

    /**
     * This methods requests position, time and satellite ephemeris debug information
     * from the HAL.
     *
     * @return ret debugData information from GNSS Hal that contains the current best
     * known position, best known time estimate and a complete list of
     * constellations that the device can track.
     */
    android.hardware.gnss.V1_0.IGnssDebug.DebugData getDebugData()
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

    public static final class Proxy implements IGnssDebug {
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
            return "[class or subclass of " + IGnssDebug.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::gnss::V1_0::IGnssDebug follow.
        @Override
        public android.hardware.gnss.V1_0.IGnssDebug.DebugData getDebugData()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnssDebug.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* getDebugData */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.gnss.V1_0.IGnssDebug.DebugData _hidl_out_debugData = new android.hardware.gnss.V1_0.IGnssDebug.DebugData();
                ((android.hardware.gnss.V1_0.IGnssDebug.DebugData) _hidl_out_debugData).readFromParcel(_hidl_reply);
                return _hidl_out_debugData;
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

    public static abstract class Stub extends android.os.HwBinder implements IGnssDebug {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.gnss.V1_0.IGnssDebug.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.gnss.V1_0.IGnssDebug.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{69,66,18,43,-106,-5,-14,113,1,-53,-126,34,-70,-5,118,-25,-56,-48,50,-39,119,-35,16,88,-19,-40,-27,-120,28,-91,117,47} /* 4542122b96fbf27101cb8222bafb76e7c8d032d977dd1058edd8e5881ca5752f */,
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
                case 1 /* getDebugData */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnssDebug.kInterfaceName);

                    android.hardware.gnss.V1_0.IGnssDebug.DebugData _hidl_out_debugData = getDebugData();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.gnss.V1_0.IGnssDebug.DebugData) _hidl_out_debugData).writeToParcel(_hidl_reply);
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
