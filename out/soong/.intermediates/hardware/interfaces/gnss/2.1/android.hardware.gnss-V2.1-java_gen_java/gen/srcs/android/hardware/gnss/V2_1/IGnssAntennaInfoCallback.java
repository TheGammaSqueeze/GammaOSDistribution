package android.hardware.gnss.V2_1;

/**
 * The callback interface to report GNSS antenna information from the HAL.
 */
public interface IGnssAntennaInfoCallback extends android.hidl.base.V1_0.IBase {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.gnss@2.1::IGnssAntennaInfoCallback";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static IGnssAntennaInfoCallback asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof IGnssAntennaInfoCallback)) {
            return (IGnssAntennaInfoCallback)iface;
        }

        IGnssAntennaInfoCallback proxy = new IGnssAntennaInfoCallback.Proxy(binder);

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
    public static IGnssAntennaInfoCallback castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : IGnssAntennaInfoCallback.asInterface(iface.asBinder());
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
    public static IGnssAntennaInfoCallback getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return IGnssAntennaInfoCallback.asInterface(android.os.HwBinder.getService("android.hardware.gnss@2.1::IGnssAntennaInfoCallback", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static IGnssAntennaInfoCallback getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static IGnssAntennaInfoCallback getService(String serviceName) throws android.os.RemoteException {
        return IGnssAntennaInfoCallback.asInterface(android.os.HwBinder.getService("android.hardware.gnss@2.1::IGnssAntennaInfoCallback", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static IGnssAntennaInfoCallback getService() throws android.os.RemoteException {
        return getService("default");
    }

    /**
     * A row of doubles. This is used to represent a row in a 2D array, which are used to
     * characterize the phase center variation corrections and signal gain corrections.
     */
    public final static class Row {
        public java.util.ArrayList<Double> row = new java.util.ArrayList<Double>();

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row.class) {
                return false;
            }
            android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row other = (android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row)otherObject;
            if (!android.os.HidlSupport.deepEquals(this.row, other.row)) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.row));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".row = ");
            builder.append(this.row);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(16 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<Row> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<Row> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 16,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row _hidl_vec_element = new android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row();
                    ((android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 16);
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
                        _hidl_vec_size * 8,_hidl_blob.handle(),
                        _hidl_offset + 0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                ((java.util.ArrayList<Double>) row).clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    double _hidl_vec_element = 0.0d;
                    _hidl_vec_element = childBlob.getDouble(_hidl_index_0 * 8);
                    ((java.util.ArrayList<Double>) row).add(_hidl_vec_element);
                }
            }
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<Row> _hidl_vec) {
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
            {
                int _hidl_vec_size = row.size();
                _hidl_blob.putInt32(_hidl_offset + 0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(_hidl_offset + 0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 8));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    childBlob.putDouble(_hidl_index_0 * 8, row.get(_hidl_index_0));
                }
                _hidl_blob.putBlob(_hidl_offset + 0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }
        }
    };

    /**
     * A point in 3D space, with associated uncertainty.
     */
    public final static class Coord {
        public double x = 0.0d;
        public double xUncertainty = 0.0d;
        public double y = 0.0d;
        public double yUncertainty = 0.0d;
        public double z = 0.0d;
        public double zUncertainty = 0.0d;

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Coord.class) {
                return false;
            }
            android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Coord other = (android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Coord)otherObject;
            if (this.x != other.x) {
                return false;
            }
            if (this.xUncertainty != other.xUncertainty) {
                return false;
            }
            if (this.y != other.y) {
                return false;
            }
            if (this.yUncertainty != other.yUncertainty) {
                return false;
            }
            if (this.z != other.z) {
                return false;
            }
            if (this.zUncertainty != other.zUncertainty) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.x), 
                    android.os.HidlSupport.deepHashCode(this.xUncertainty), 
                    android.os.HidlSupport.deepHashCode(this.y), 
                    android.os.HidlSupport.deepHashCode(this.yUncertainty), 
                    android.os.HidlSupport.deepHashCode(this.z), 
                    android.os.HidlSupport.deepHashCode(this.zUncertainty));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".x = ");
            builder.append(this.x);
            builder.append(", .xUncertainty = ");
            builder.append(this.xUncertainty);
            builder.append(", .y = ");
            builder.append(this.y);
            builder.append(", .yUncertainty = ");
            builder.append(this.yUncertainty);
            builder.append(", .z = ");
            builder.append(this.z);
            builder.append(", .zUncertainty = ");
            builder.append(this.zUncertainty);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(48 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<Coord> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<Coord> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 48,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Coord _hidl_vec_element = new android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Coord();
                    ((android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Coord) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 48);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            x = _hidl_blob.getDouble(_hidl_offset + 0);
            xUncertainty = _hidl_blob.getDouble(_hidl_offset + 8);
            y = _hidl_blob.getDouble(_hidl_offset + 16);
            yUncertainty = _hidl_blob.getDouble(_hidl_offset + 24);
            z = _hidl_blob.getDouble(_hidl_offset + 32);
            zUncertainty = _hidl_blob.getDouble(_hidl_offset + 40);
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(48 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<Coord> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 48));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 48);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            _hidl_blob.putDouble(_hidl_offset + 0, x);
            _hidl_blob.putDouble(_hidl_offset + 8, xUncertainty);
            _hidl_blob.putDouble(_hidl_offset + 16, y);
            _hidl_blob.putDouble(_hidl_offset + 24, yUncertainty);
            _hidl_blob.putDouble(_hidl_offset + 32, z);
            _hidl_blob.putDouble(_hidl_offset + 40, zUncertainty);
        }
    };

    public final static class GnssAntennaInfo {
        /**
         * The carrier frequency in MHz.
         */
        public double carrierFrequencyMHz = 0.0d;
        /**
         * Phase center offset (PCO) with associated 1-sigma uncertainty. PCO is defined with
         * respect to the origin of the Android sensor coordinate system, e.g., center of primary
         * screen for mobiles - see sensor or form factor documents for details.
         */
        public android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Coord phaseCenterOffsetCoordinateMillimeters = new android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Coord();
        /**
         * 2D vectors representing the phase center variation (PCV) corrections, in
         * millimeters, at regularly spaced azimuthal angle (theta) and zenith angle
         * (phi). The PCV correction is added to the phase measurement to obtain the
         * corrected value.
         *
         * The azimuthal angle, theta, is defined with respect to the X axis of the
         * Android sensor coordinate system, increasing toward the Y axis. The zenith
         * angle, phi, is defined with respect to the Z axis of the Android Sensor
         * coordinate system, increasing toward the X-Y plane.
         *
         * Each row vector (outer vectors) represents a fixed theta. The first row
         * corresponds to a theta angle of 0 degrees. The last row corresponds to a
         * theta angle of (360 - deltaTheta) degrees, where deltaTheta is the regular
         * spacing between azimuthal angles, i.e., deltaTheta = 360 / (number of rows).
         *
         * The columns (inner vectors) represent fixed zenith angles, beginning at 0
         * degrees and ending at 180 degrees. They are separated by deltaPhi, the regular
         * spacing between zenith angles, i.e., deltaPhi = 180 / (number of columns - 1).
         *
         * This field is optional, i.e., an empty vector.
         */
        public java.util.ArrayList<android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row> phaseCenterVariationCorrectionMillimeters = new java.util.ArrayList<android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row>();
        /**
         * 2D vectors of 1-sigma uncertainty in millimeters associated with the PCV
         * correction values.
         *
         * This field is optional, i.e., an empty vector.
         */
        public java.util.ArrayList<android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row> phaseCenterVariationCorrectionUncertaintyMillimeters = new java.util.ArrayList<android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row>();
        /**
         * 2D vectors representing the signal gain corrections at regularly spaced
         * azimuthal angle (theta) and zenith angle (phi). The values are calculated or
         * measured at the antenna feed point without considering the radio and receiver
         * noise figure and path loss contribution, in dBi, i.e., decibel over isotropic
         * antenna with the same total power. The signal gain correction is added the
         * signal gain measurement to obtain the corrected value.
         *
         * The azimuthal angle, theta, is defined with respect to the X axis of the
         * Android sensor coordinate system, increasing toward the Y axis. The zenith
         * angle, phi, is defined with respect to the Z axis of the Android Sensor
         * coordinate system, increasing toward the X-Y plane.
         *
         * Each row vector (outer vectors) represents a fixed theta. The first row
         * corresponds to a theta angle of 0 degrees. The last row corresponds to a
         * theta angle of (360 - deltaTheta) degrees, where deltaTheta is the regular
         * spacing between azimuthal angles, i.e., deltaTheta = 360 / (number of rows).
         *
         * The columns (inner vectors) represent fixed zenith angles, beginning at 0
         * degrees and ending at 180 degrees. They are separated by deltaPhi, the regular
         * spacing between zenith angles, i.e., deltaPhi = 180 / (number of columns - 1).
         *
         * This field is optional, i.e., an empty vector.
         */
        public java.util.ArrayList<android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row> signalGainCorrectionDbi = new java.util.ArrayList<android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row>();
        /**
         * 2D vectors of 1-sigma uncertainty in dBi associated with the signal
         * gain correction values.
         *
         * This field is optional, i.e., an empty vector.
         */
        public java.util.ArrayList<android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row> signalGainCorrectionUncertaintyDbi = new java.util.ArrayList<android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row>();

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.GnssAntennaInfo.class) {
                return false;
            }
            android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.GnssAntennaInfo other = (android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.GnssAntennaInfo)otherObject;
            if (this.carrierFrequencyMHz != other.carrierFrequencyMHz) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.phaseCenterOffsetCoordinateMillimeters, other.phaseCenterOffsetCoordinateMillimeters)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.phaseCenterVariationCorrectionMillimeters, other.phaseCenterVariationCorrectionMillimeters)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.phaseCenterVariationCorrectionUncertaintyMillimeters, other.phaseCenterVariationCorrectionUncertaintyMillimeters)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.signalGainCorrectionDbi, other.signalGainCorrectionDbi)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.signalGainCorrectionUncertaintyDbi, other.signalGainCorrectionUncertaintyDbi)) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.carrierFrequencyMHz), 
                    android.os.HidlSupport.deepHashCode(this.phaseCenterOffsetCoordinateMillimeters), 
                    android.os.HidlSupport.deepHashCode(this.phaseCenterVariationCorrectionMillimeters), 
                    android.os.HidlSupport.deepHashCode(this.phaseCenterVariationCorrectionUncertaintyMillimeters), 
                    android.os.HidlSupport.deepHashCode(this.signalGainCorrectionDbi), 
                    android.os.HidlSupport.deepHashCode(this.signalGainCorrectionUncertaintyDbi));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".carrierFrequencyMHz = ");
            builder.append(this.carrierFrequencyMHz);
            builder.append(", .phaseCenterOffsetCoordinateMillimeters = ");
            builder.append(this.phaseCenterOffsetCoordinateMillimeters);
            builder.append(", .phaseCenterVariationCorrectionMillimeters = ");
            builder.append(this.phaseCenterVariationCorrectionMillimeters);
            builder.append(", .phaseCenterVariationCorrectionUncertaintyMillimeters = ");
            builder.append(this.phaseCenterVariationCorrectionUncertaintyMillimeters);
            builder.append(", .signalGainCorrectionDbi = ");
            builder.append(this.signalGainCorrectionDbi);
            builder.append(", .signalGainCorrectionUncertaintyDbi = ");
            builder.append(this.signalGainCorrectionUncertaintyDbi);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(120 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<GnssAntennaInfo> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<GnssAntennaInfo> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 120,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.GnssAntennaInfo _hidl_vec_element = new android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.GnssAntennaInfo();
                    ((android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.GnssAntennaInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 120);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            carrierFrequencyMHz = _hidl_blob.getDouble(_hidl_offset + 0);
            ((android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Coord) phaseCenterOffsetCoordinateMillimeters).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 8);
            {
                int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 56 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 16,_hidl_blob.handle(),
                        _hidl_offset + 56 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                ((java.util.ArrayList<android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row>) phaseCenterVariationCorrectionMillimeters).clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row _hidl_vec_element = new android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row();
                    ((android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 16);
                    ((java.util.ArrayList<android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row>) phaseCenterVariationCorrectionMillimeters).add(_hidl_vec_element);
                }
            }
            {
                int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 72 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 16,_hidl_blob.handle(),
                        _hidl_offset + 72 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                ((java.util.ArrayList<android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row>) phaseCenterVariationCorrectionUncertaintyMillimeters).clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row _hidl_vec_element = new android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row();
                    ((android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 16);
                    ((java.util.ArrayList<android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row>) phaseCenterVariationCorrectionUncertaintyMillimeters).add(_hidl_vec_element);
                }
            }
            {
                int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 88 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 16,_hidl_blob.handle(),
                        _hidl_offset + 88 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                ((java.util.ArrayList<android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row>) signalGainCorrectionDbi).clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row _hidl_vec_element = new android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row();
                    ((android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 16);
                    ((java.util.ArrayList<android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row>) signalGainCorrectionDbi).add(_hidl_vec_element);
                }
            }
            {
                int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 104 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 16,_hidl_blob.handle(),
                        _hidl_offset + 104 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                ((java.util.ArrayList<android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row>) signalGainCorrectionUncertaintyDbi).clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row _hidl_vec_element = new android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row();
                    ((android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 16);
                    ((java.util.ArrayList<android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.Row>) signalGainCorrectionUncertaintyDbi).add(_hidl_vec_element);
                }
            }
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(120 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<GnssAntennaInfo> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 120));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 120);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            _hidl_blob.putDouble(_hidl_offset + 0, carrierFrequencyMHz);
            phaseCenterOffsetCoordinateMillimeters.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 8);
            {
                int _hidl_vec_size = phaseCenterVariationCorrectionMillimeters.size();
                _hidl_blob.putInt32(_hidl_offset + 56 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(_hidl_offset + 56 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 16));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    phaseCenterVariationCorrectionMillimeters.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 16);
                }
                _hidl_blob.putBlob(_hidl_offset + 56 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }
            {
                int _hidl_vec_size = phaseCenterVariationCorrectionUncertaintyMillimeters.size();
                _hidl_blob.putInt32(_hidl_offset + 72 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(_hidl_offset + 72 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 16));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    phaseCenterVariationCorrectionUncertaintyMillimeters.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 16);
                }
                _hidl_blob.putBlob(_hidl_offset + 72 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }
            {
                int _hidl_vec_size = signalGainCorrectionDbi.size();
                _hidl_blob.putInt32(_hidl_offset + 88 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(_hidl_offset + 88 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 16));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    signalGainCorrectionDbi.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 16);
                }
                _hidl_blob.putBlob(_hidl_offset + 88 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }
            {
                int _hidl_vec_size = signalGainCorrectionUncertaintyDbi.size();
                _hidl_blob.putInt32(_hidl_offset + 104 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(_hidl_offset + 104 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 16));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    signalGainCorrectionUncertaintyDbi.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 16);
                }
                _hidl_blob.putBlob(_hidl_offset + 104 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }
        }
    };

    /**
     * Called when on connection, and on known-change to these values, such as upon a known
     * GNSS RF antenna tuning change, or a foldable device state change.
     *
     * This is optional. It can never be called if the GNSS antenna information is not
     * available.
     */
    void gnssAntennaInfoCb(java.util.ArrayList<android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.GnssAntennaInfo> gnssAntennaInfos)
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

    public static final class Proxy implements IGnssAntennaInfoCallback {
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
            return "[class or subclass of " + IGnssAntennaInfoCallback.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::gnss::V2_1::IGnssAntennaInfoCallback follow.
        @Override
        public void gnssAntennaInfoCb(java.util.ArrayList<android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.GnssAntennaInfo> gnssAntennaInfos)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.kInterfaceName);
            android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.GnssAntennaInfo.writeVectorToParcel(_hidl_request, gnssAntennaInfos);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* gnssAntennaInfoCb */, _hidl_request, _hidl_reply, 0 /* flags */);
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

    public static abstract class Stub extends android.os.HwBinder implements IGnssAntennaInfoCallback {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{11,-61,-19,-105,-53,-61,-10,-85,-56,-100,104,-12,-23,-12,-47,36,-7,-9,35,67,25,-105,-36,-120,-62,24,108,-12,-46,-83,71,-18} /* 0bc3ed97cbc3f6abc89c68f4e9f4d124f9f723431997dc88c2186cf4d2ad47ee */,
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
                case 1 /* gnssAntennaInfoCb */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.kInterfaceName);

                    java.util.ArrayList<android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.GnssAntennaInfo> gnssAntennaInfos = android.hardware.gnss.V2_1.IGnssAntennaInfoCallback.GnssAntennaInfo.readVectorFromParcel(_hidl_request);
                    gnssAntennaInfoCb(gnssAntennaInfos);
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
