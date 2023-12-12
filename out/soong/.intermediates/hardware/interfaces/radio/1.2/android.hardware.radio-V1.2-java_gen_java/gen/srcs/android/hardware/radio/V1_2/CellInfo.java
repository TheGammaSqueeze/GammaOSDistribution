package android.hardware.radio.V1_2;


public final class CellInfo {
    /**
     * Cell type for selecting from union CellInfo.
     */
    public int cellInfoType = 0;
    /**
     * True if this cell is registered false if not registered.
     */
    public boolean registered = false;
    /**
     * Type of time stamp represented by timeStamp.
     */
    public int timeStampType = 0;
    /**
     * Time in nanos as returned by ril_nano_time.
     */
    public long timeStamp = 0L;
    /**
     * Only one of the below vectors must be of size 1 based on the CellInfoType and others must be
     * of size 0.
     */
    public java.util.ArrayList<android.hardware.radio.V1_2.CellInfoGsm> gsm = new java.util.ArrayList<android.hardware.radio.V1_2.CellInfoGsm>();
    /**
     * Valid only if type = cdma and size = 1 else must be empty.
     */
    public java.util.ArrayList<android.hardware.radio.V1_2.CellInfoCdma> cdma = new java.util.ArrayList<android.hardware.radio.V1_2.CellInfoCdma>();
    /**
     * Valid only if type = lte and size = 1 else must be empty.
     */
    public java.util.ArrayList<android.hardware.radio.V1_2.CellInfoLte> lte = new java.util.ArrayList<android.hardware.radio.V1_2.CellInfoLte>();
    /**
     * Valid only if type = wcdma and size = 1 else must be empty.
     */
    public java.util.ArrayList<android.hardware.radio.V1_2.CellInfoWcdma> wcdma = new java.util.ArrayList<android.hardware.radio.V1_2.CellInfoWcdma>();
    /**
     * Valid only if type = tdscdma and size = 1 else must be empty.
     */
    public java.util.ArrayList<android.hardware.radio.V1_2.CellInfoTdscdma> tdscdma = new java.util.ArrayList<android.hardware.radio.V1_2.CellInfoTdscdma>();
    /**
     * Connection status for the cell.
     */
    public int connectionStatus = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_2.CellInfo.class) {
            return false;
        }
        android.hardware.radio.V1_2.CellInfo other = (android.hardware.radio.V1_2.CellInfo)otherObject;
        if (this.cellInfoType != other.cellInfoType) {
            return false;
        }
        if (this.registered != other.registered) {
            return false;
        }
        if (this.timeStampType != other.timeStampType) {
            return false;
        }
        if (this.timeStamp != other.timeStamp) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.gsm, other.gsm)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.cdma, other.cdma)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.lte, other.lte)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.wcdma, other.wcdma)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.tdscdma, other.tdscdma)) {
            return false;
        }
        if (this.connectionStatus != other.connectionStatus) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.cellInfoType), 
                android.os.HidlSupport.deepHashCode(this.registered), 
                android.os.HidlSupport.deepHashCode(this.timeStampType), 
                android.os.HidlSupport.deepHashCode(this.timeStamp), 
                android.os.HidlSupport.deepHashCode(this.gsm), 
                android.os.HidlSupport.deepHashCode(this.cdma), 
                android.os.HidlSupport.deepHashCode(this.lte), 
                android.os.HidlSupport.deepHashCode(this.wcdma), 
                android.os.HidlSupport.deepHashCode(this.tdscdma), 
                android.os.HidlSupport.deepHashCode(this.connectionStatus));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".cellInfoType = ");
        builder.append(android.hardware.radio.V1_0.CellInfoType.toString(this.cellInfoType));
        builder.append(", .registered = ");
        builder.append(this.registered);
        builder.append(", .timeStampType = ");
        builder.append(android.hardware.radio.V1_0.TimeStampType.toString(this.timeStampType));
        builder.append(", .timeStamp = ");
        builder.append(this.timeStamp);
        builder.append(", .gsm = ");
        builder.append(this.gsm);
        builder.append(", .cdma = ");
        builder.append(this.cdma);
        builder.append(", .lte = ");
        builder.append(this.lte);
        builder.append(", .wcdma = ");
        builder.append(this.wcdma);
        builder.append(", .tdscdma = ");
        builder.append(this.tdscdma);
        builder.append(", .connectionStatus = ");
        builder.append(android.hardware.radio.V1_2.CellConnectionStatus.toString(this.connectionStatus));
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(112 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<CellInfo> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<CellInfo> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 112,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_2.CellInfo _hidl_vec_element = new android.hardware.radio.V1_2.CellInfo();
                ((android.hardware.radio.V1_2.CellInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 112);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        cellInfoType = _hidl_blob.getInt32(_hidl_offset + 0);
        registered = _hidl_blob.getBool(_hidl_offset + 4);
        timeStampType = _hidl_blob.getInt32(_hidl_offset + 8);
        timeStamp = _hidl_blob.getInt64(_hidl_offset + 16);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 24 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 96,_hidl_blob.handle(),
                    _hidl_offset + 24 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.V1_2.CellInfoGsm>) gsm).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_2.CellInfoGsm _hidl_vec_element = new android.hardware.radio.V1_2.CellInfoGsm();
                ((android.hardware.radio.V1_2.CellInfoGsm) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 96);
                ((java.util.ArrayList<android.hardware.radio.V1_2.CellInfoGsm>) gsm).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 40 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 80,_hidl_blob.handle(),
                    _hidl_offset + 40 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.V1_2.CellInfoCdma>) cdma).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_2.CellInfoCdma _hidl_vec_element = new android.hardware.radio.V1_2.CellInfoCdma();
                ((android.hardware.radio.V1_2.CellInfoCdma) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 80);
                ((java.util.ArrayList<android.hardware.radio.V1_2.CellInfoCdma>) cdma).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 56 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 112,_hidl_blob.handle(),
                    _hidl_offset + 56 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.V1_2.CellInfoLte>) lte).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_2.CellInfoLte _hidl_vec_element = new android.hardware.radio.V1_2.CellInfoLte();
                ((android.hardware.radio.V1_2.CellInfoLte) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 112);
                ((java.util.ArrayList<android.hardware.radio.V1_2.CellInfoLte>) lte).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 72 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 96,_hidl_blob.handle(),
                    _hidl_offset + 72 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.V1_2.CellInfoWcdma>) wcdma).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_2.CellInfoWcdma _hidl_vec_element = new android.hardware.radio.V1_2.CellInfoWcdma();
                ((android.hardware.radio.V1_2.CellInfoWcdma) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 96);
                ((java.util.ArrayList<android.hardware.radio.V1_2.CellInfoWcdma>) wcdma).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 88 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 104,_hidl_blob.handle(),
                    _hidl_offset + 88 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.V1_2.CellInfoTdscdma>) tdscdma).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_2.CellInfoTdscdma _hidl_vec_element = new android.hardware.radio.V1_2.CellInfoTdscdma();
                ((android.hardware.radio.V1_2.CellInfoTdscdma) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 104);
                ((java.util.ArrayList<android.hardware.radio.V1_2.CellInfoTdscdma>) tdscdma).add(_hidl_vec_element);
            }
        }
        connectionStatus = _hidl_blob.getInt32(_hidl_offset + 104);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(112 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<CellInfo> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, cellInfoType);
        _hidl_blob.putBool(_hidl_offset + 4, registered);
        _hidl_blob.putInt32(_hidl_offset + 8, timeStampType);
        _hidl_blob.putInt64(_hidl_offset + 16, timeStamp);
        {
            int _hidl_vec_size = gsm.size();
            _hidl_blob.putInt32(_hidl_offset + 24 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 24 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 96));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                gsm.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 96);
            }
            _hidl_blob.putBlob(_hidl_offset + 24 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = cdma.size();
            _hidl_blob.putInt32(_hidl_offset + 40 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 40 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 80));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                cdma.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 80);
            }
            _hidl_blob.putBlob(_hidl_offset + 40 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = lte.size();
            _hidl_blob.putInt32(_hidl_offset + 56 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 56 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 112));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                lte.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 112);
            }
            _hidl_blob.putBlob(_hidl_offset + 56 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = wcdma.size();
            _hidl_blob.putInt32(_hidl_offset + 72 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 72 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 96));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                wcdma.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 96);
            }
            _hidl_blob.putBlob(_hidl_offset + 72 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = tdscdma.size();
            _hidl_blob.putInt32(_hidl_offset + 88 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 88 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 104));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                tdscdma.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 104);
            }
            _hidl_blob.putBlob(_hidl_offset + 88 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        _hidl_blob.putInt32(_hidl_offset + 104, connectionStatus);
    }
};

