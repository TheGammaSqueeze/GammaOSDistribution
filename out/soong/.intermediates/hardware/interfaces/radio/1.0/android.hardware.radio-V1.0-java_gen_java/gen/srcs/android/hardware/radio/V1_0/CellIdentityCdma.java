package android.hardware.radio.V1_0;


public final class CellIdentityCdma {
    public int networkId = 0;
    public int systemId = 0;
    public int baseStationId = 0;
    public int longitude = 0;
    public int latitude = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_0.CellIdentityCdma.class) {
            return false;
        }
        android.hardware.radio.V1_0.CellIdentityCdma other = (android.hardware.radio.V1_0.CellIdentityCdma)otherObject;
        if (this.networkId != other.networkId) {
            return false;
        }
        if (this.systemId != other.systemId) {
            return false;
        }
        if (this.baseStationId != other.baseStationId) {
            return false;
        }
        if (this.longitude != other.longitude) {
            return false;
        }
        if (this.latitude != other.latitude) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.networkId), 
                android.os.HidlSupport.deepHashCode(this.systemId), 
                android.os.HidlSupport.deepHashCode(this.baseStationId), 
                android.os.HidlSupport.deepHashCode(this.longitude), 
                android.os.HidlSupport.deepHashCode(this.latitude));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".networkId = ");
        builder.append(this.networkId);
        builder.append(", .systemId = ");
        builder.append(this.systemId);
        builder.append(", .baseStationId = ");
        builder.append(this.baseStationId);
        builder.append(", .longitude = ");
        builder.append(this.longitude);
        builder.append(", .latitude = ");
        builder.append(this.latitude);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(20 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<CellIdentityCdma> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<CellIdentityCdma> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 20,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.CellIdentityCdma _hidl_vec_element = new android.hardware.radio.V1_0.CellIdentityCdma();
                ((android.hardware.radio.V1_0.CellIdentityCdma) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 20);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        networkId = _hidl_blob.getInt32(_hidl_offset + 0);
        systemId = _hidl_blob.getInt32(_hidl_offset + 4);
        baseStationId = _hidl_blob.getInt32(_hidl_offset + 8);
        longitude = _hidl_blob.getInt32(_hidl_offset + 12);
        latitude = _hidl_blob.getInt32(_hidl_offset + 16);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(20 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<CellIdentityCdma> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, networkId);
        _hidl_blob.putInt32(_hidl_offset + 4, systemId);
        _hidl_blob.putInt32(_hidl_offset + 8, baseStationId);
        _hidl_blob.putInt32(_hidl_offset + 12, longitude);
        _hidl_blob.putInt32(_hidl_offset + 16, latitude);
    }
};

