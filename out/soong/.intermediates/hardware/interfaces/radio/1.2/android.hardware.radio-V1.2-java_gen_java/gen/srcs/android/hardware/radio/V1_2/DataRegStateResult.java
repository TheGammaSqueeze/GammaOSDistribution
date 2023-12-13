package android.hardware.radio.V1_2;


public final class DataRegStateResult {
    /**
     * Valid reg states are NOT_REG_MT_NOT_SEARCHING_OP,
     * REG_HOME, NOT_REG_MT_SEARCHING_OP, REG_DENIED,
     * UNKNOWN, REG_ROAMING defined in RegState
     */
    public int regState = 0;
    /**
     * Indicates the available data radio technology,
     * valid values as defined by RadioTechnology.
     */
    public int rat = 0;
    /**
     * If registration state is 3 (Registration
     * denied) this is an enumerated reason why
     * registration was denied. See 3GPP TS 24.008,
     * Annex G.6 "Additional cause codes for GMM".
     * 7 == GPRS services not allowed
     * 8 == GPRS services and non-GPRS services not allowed
     * 9 == MS identity cannot be derived by the network
     * 10 == Implicitly detached
     * 14 == GPRS services not allowed in this PLMN
     * 16 == MSC temporarily not reachable
     * 40 == No PDP context activated
     */
    public int reasonDataDenied = 0;
    /**
     * The maximum number of simultaneous Data Calls must be established using setupDataCall().
     */
    public int maxDataCalls = 0;
    public android.hardware.radio.V1_2.CellIdentity cellIdentity = new android.hardware.radio.V1_2.CellIdentity();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_2.DataRegStateResult.class) {
            return false;
        }
        android.hardware.radio.V1_2.DataRegStateResult other = (android.hardware.radio.V1_2.DataRegStateResult)otherObject;
        if (this.regState != other.regState) {
            return false;
        }
        if (this.rat != other.rat) {
            return false;
        }
        if (this.reasonDataDenied != other.reasonDataDenied) {
            return false;
        }
        if (this.maxDataCalls != other.maxDataCalls) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.cellIdentity, other.cellIdentity)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.regState), 
                android.os.HidlSupport.deepHashCode(this.rat), 
                android.os.HidlSupport.deepHashCode(this.reasonDataDenied), 
                android.os.HidlSupport.deepHashCode(this.maxDataCalls), 
                android.os.HidlSupport.deepHashCode(this.cellIdentity));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".regState = ");
        builder.append(android.hardware.radio.V1_0.RegState.toString(this.regState));
        builder.append(", .rat = ");
        builder.append(this.rat);
        builder.append(", .reasonDataDenied = ");
        builder.append(this.reasonDataDenied);
        builder.append(", .maxDataCalls = ");
        builder.append(this.maxDataCalls);
        builder.append(", .cellIdentity = ");
        builder.append(this.cellIdentity);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(104 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<DataRegStateResult> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<DataRegStateResult> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 104,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_2.DataRegStateResult _hidl_vec_element = new android.hardware.radio.V1_2.DataRegStateResult();
                ((android.hardware.radio.V1_2.DataRegStateResult) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 104);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        regState = _hidl_blob.getInt32(_hidl_offset + 0);
        rat = _hidl_blob.getInt32(_hidl_offset + 4);
        reasonDataDenied = _hidl_blob.getInt32(_hidl_offset + 8);
        maxDataCalls = _hidl_blob.getInt32(_hidl_offset + 12);
        ((android.hardware.radio.V1_2.CellIdentity) cellIdentity).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 16);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(104 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<DataRegStateResult> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, regState);
        _hidl_blob.putInt32(_hidl_offset + 4, rat);
        _hidl_blob.putInt32(_hidl_offset + 8, reasonDataDenied);
        _hidl_blob.putInt32(_hidl_offset + 12, maxDataCalls);
        cellIdentity.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 16);
    }
};

