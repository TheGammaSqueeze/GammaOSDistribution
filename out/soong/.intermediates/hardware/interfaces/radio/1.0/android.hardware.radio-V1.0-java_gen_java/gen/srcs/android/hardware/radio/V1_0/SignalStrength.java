package android.hardware.radio.V1_0;


public final class SignalStrength {
    /**
     * If GSM measurements are provided, this structure must contain valid measurements; otherwise
     * all fields should be set to INT_MAX to mark them as invalid.
     */
    public android.hardware.radio.V1_0.GsmSignalStrength gw = new android.hardware.radio.V1_0.GsmSignalStrength();
    /**
     * If CDMA measurements are provided, this structure must contain valid measurements; otherwise
     * all fields should be set to INT_MAX to mark them as invalid.
     */
    public android.hardware.radio.V1_0.CdmaSignalStrength cdma = new android.hardware.radio.V1_0.CdmaSignalStrength();
    /**
     * If EvDO measurements are provided, this structure must contain valid measurements; otherwise
     * all fields should be set to INT_MAX to mark them as invalid.
     */
    public android.hardware.radio.V1_0.EvdoSignalStrength evdo = new android.hardware.radio.V1_0.EvdoSignalStrength();
    /**
     * If LTE measurements are provided, this structure must contain valid measurements; otherwise
     * all fields should be set to INT_MAX to mark them as invalid.
     */
    public android.hardware.radio.V1_0.LteSignalStrength lte = new android.hardware.radio.V1_0.LteSignalStrength();
    /**
     * If TD-SCDMA measurements are provided, this structure must contain valid measurements;
     * otherwise all fields should be set to INT_MAX to mark them as invalid.
     */
    public android.hardware.radio.V1_0.TdScdmaSignalStrength tdScdma = new android.hardware.radio.V1_0.TdScdmaSignalStrength();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_0.SignalStrength.class) {
            return false;
        }
        android.hardware.radio.V1_0.SignalStrength other = (android.hardware.radio.V1_0.SignalStrength)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.gw, other.gw)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.cdma, other.cdma)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.evdo, other.evdo)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.lte, other.lte)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.tdScdma, other.tdScdma)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.gw), 
                android.os.HidlSupport.deepHashCode(this.cdma), 
                android.os.HidlSupport.deepHashCode(this.evdo), 
                android.os.HidlSupport.deepHashCode(this.lte), 
                android.os.HidlSupport.deepHashCode(this.tdScdma));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".gw = ");
        builder.append(this.gw);
        builder.append(", .cdma = ");
        builder.append(this.cdma);
        builder.append(", .evdo = ");
        builder.append(this.evdo);
        builder.append(", .lte = ");
        builder.append(this.lte);
        builder.append(", .tdScdma = ");
        builder.append(this.tdScdma);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(60 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<SignalStrength> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<SignalStrength> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 60,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.SignalStrength _hidl_vec_element = new android.hardware.radio.V1_0.SignalStrength();
                ((android.hardware.radio.V1_0.SignalStrength) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 60);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ((android.hardware.radio.V1_0.GsmSignalStrength) gw).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
        ((android.hardware.radio.V1_0.CdmaSignalStrength) cdma).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 12);
        ((android.hardware.radio.V1_0.EvdoSignalStrength) evdo).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 20);
        ((android.hardware.radio.V1_0.LteSignalStrength) lte).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 32);
        ((android.hardware.radio.V1_0.TdScdmaSignalStrength) tdScdma).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 56);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(60 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<SignalStrength> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 60));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 60);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        gw.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
        cdma.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 12);
        evdo.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 20);
        lte.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 32);
        tdScdma.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 56);
    }
};

