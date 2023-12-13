package android.hardware.tv.cec.V1_0;


public final class HdmiPortInfo {
    public int type = 0;
    public int portId = 0;
    public boolean cecSupported = false;
    public boolean arcSupported = false;
    public short physicalAddress = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.tv.cec.V1_0.HdmiPortInfo.class) {
            return false;
        }
        android.hardware.tv.cec.V1_0.HdmiPortInfo other = (android.hardware.tv.cec.V1_0.HdmiPortInfo)otherObject;
        if (this.type != other.type) {
            return false;
        }
        if (this.portId != other.portId) {
            return false;
        }
        if (this.cecSupported != other.cecSupported) {
            return false;
        }
        if (this.arcSupported != other.arcSupported) {
            return false;
        }
        if (this.physicalAddress != other.physicalAddress) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.type), 
                android.os.HidlSupport.deepHashCode(this.portId), 
                android.os.HidlSupport.deepHashCode(this.cecSupported), 
                android.os.HidlSupport.deepHashCode(this.arcSupported), 
                android.os.HidlSupport.deepHashCode(this.physicalAddress));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".type = ");
        builder.append(android.hardware.tv.cec.V1_0.HdmiPortType.toString(this.type));
        builder.append(", .portId = ");
        builder.append(this.portId);
        builder.append(", .cecSupported = ");
        builder.append(this.cecSupported);
        builder.append(", .arcSupported = ");
        builder.append(this.arcSupported);
        builder.append(", .physicalAddress = ");
        builder.append(this.physicalAddress);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(12 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<HdmiPortInfo> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<HdmiPortInfo> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 12,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.tv.cec.V1_0.HdmiPortInfo _hidl_vec_element = new android.hardware.tv.cec.V1_0.HdmiPortInfo();
                ((android.hardware.tv.cec.V1_0.HdmiPortInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 12);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        type = _hidl_blob.getInt32(_hidl_offset + 0);
        portId = _hidl_blob.getInt32(_hidl_offset + 4);
        cecSupported = _hidl_blob.getBool(_hidl_offset + 8);
        arcSupported = _hidl_blob.getBool(_hidl_offset + 9);
        physicalAddress = _hidl_blob.getInt16(_hidl_offset + 10);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(12 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<HdmiPortInfo> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 12));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 12);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, type);
        _hidl_blob.putInt32(_hidl_offset + 4, portId);
        _hidl_blob.putBool(_hidl_offset + 8, cecSupported);
        _hidl_blob.putBool(_hidl_offset + 9, arcSupported);
        _hidl_blob.putInt16(_hidl_offset + 10, physicalAddress);
    }
};

