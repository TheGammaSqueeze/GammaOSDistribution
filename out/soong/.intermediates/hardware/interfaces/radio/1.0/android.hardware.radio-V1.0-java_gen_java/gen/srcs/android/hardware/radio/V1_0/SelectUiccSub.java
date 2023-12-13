package android.hardware.radio.V1_0;


public final class SelectUiccSub {
    public int slot = 0;
    public int appIndex = 0;
    public int subType = 0;
    public int actStatus = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_0.SelectUiccSub.class) {
            return false;
        }
        android.hardware.radio.V1_0.SelectUiccSub other = (android.hardware.radio.V1_0.SelectUiccSub)otherObject;
        if (this.slot != other.slot) {
            return false;
        }
        if (this.appIndex != other.appIndex) {
            return false;
        }
        if (this.subType != other.subType) {
            return false;
        }
        if (this.actStatus != other.actStatus) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.slot), 
                android.os.HidlSupport.deepHashCode(this.appIndex), 
                android.os.HidlSupport.deepHashCode(this.subType), 
                android.os.HidlSupport.deepHashCode(this.actStatus));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".slot = ");
        builder.append(this.slot);
        builder.append(", .appIndex = ");
        builder.append(this.appIndex);
        builder.append(", .subType = ");
        builder.append(android.hardware.radio.V1_0.SubscriptionType.toString(this.subType));
        builder.append(", .actStatus = ");
        builder.append(android.hardware.radio.V1_0.UiccSubActStatus.toString(this.actStatus));
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(16 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<SelectUiccSub> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<SelectUiccSub> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 16,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.SelectUiccSub _hidl_vec_element = new android.hardware.radio.V1_0.SelectUiccSub();
                ((android.hardware.radio.V1_0.SelectUiccSub) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 16);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        slot = _hidl_blob.getInt32(_hidl_offset + 0);
        appIndex = _hidl_blob.getInt32(_hidl_offset + 4);
        subType = _hidl_blob.getInt32(_hidl_offset + 8);
        actStatus = _hidl_blob.getInt32(_hidl_offset + 12);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<SelectUiccSub> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, slot);
        _hidl_blob.putInt32(_hidl_offset + 4, appIndex);
        _hidl_blob.putInt32(_hidl_offset + 8, subType);
        _hidl_blob.putInt32(_hidl_offset + 12, actStatus);
    }
};

