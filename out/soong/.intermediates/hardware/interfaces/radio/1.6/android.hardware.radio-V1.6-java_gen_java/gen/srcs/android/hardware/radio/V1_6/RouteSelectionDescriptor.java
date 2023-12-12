package android.hardware.radio.V1_6;


public final class RouteSelectionDescriptor {
    /**
     * Precedence value in the range of 0 to 255. Higher value has lower
     * precedence.
     */
    public byte precedence = 0;
    /**
     * Valid values are IP, IPV6 and IPV4V6.
     */
    public android.hardware.radio.V1_6.OptionalPdpProtocolType sessionType = new android.hardware.radio.V1_6.OptionalPdpProtocolType();
    public android.hardware.radio.V1_6.OptionalSscMode sscMode = new android.hardware.radio.V1_6.OptionalSscMode();
    /**
     * There can be 0 or more SliceInfo specified in a route descriptor.
     */
    public java.util.ArrayList<android.hardware.radio.V1_6.SliceInfo> sliceInfo = new java.util.ArrayList<android.hardware.radio.V1_6.SliceInfo>();
    /**
     * DNN stands for Data Network Name and represents an APN as defined in
     * 3GPP TS 23.003. There can be 0 or more DNNs specified in a route
     * descriptor.
     */
    public java.util.ArrayList<String> dnn = new java.util.ArrayList<String>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_6.RouteSelectionDescriptor.class) {
            return false;
        }
        android.hardware.radio.V1_6.RouteSelectionDescriptor other = (android.hardware.radio.V1_6.RouteSelectionDescriptor)otherObject;
        if (this.precedence != other.precedence) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.sessionType, other.sessionType)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.sscMode, other.sscMode)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.sliceInfo, other.sliceInfo)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.dnn, other.dnn)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.precedence), 
                android.os.HidlSupport.deepHashCode(this.sessionType), 
                android.os.HidlSupport.deepHashCode(this.sscMode), 
                android.os.HidlSupport.deepHashCode(this.sliceInfo), 
                android.os.HidlSupport.deepHashCode(this.dnn));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".precedence = ");
        builder.append(this.precedence);
        builder.append(", .sessionType = ");
        builder.append(this.sessionType);
        builder.append(", .sscMode = ");
        builder.append(this.sscMode);
        builder.append(", .sliceInfo = ");
        builder.append(this.sliceInfo);
        builder.append(", .dnn = ");
        builder.append(this.dnn);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(48 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<RouteSelectionDescriptor> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<RouteSelectionDescriptor> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 48,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_6.RouteSelectionDescriptor _hidl_vec_element = new android.hardware.radio.V1_6.RouteSelectionDescriptor();
                ((android.hardware.radio.V1_6.RouteSelectionDescriptor) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 48);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        precedence = _hidl_blob.getInt8(_hidl_offset + 0);
        ((android.hardware.radio.V1_6.OptionalPdpProtocolType) sessionType).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 4);
        ((android.hardware.radio.V1_6.OptionalSscMode) sscMode).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 12);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 20,_hidl_blob.handle(),
                    _hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.V1_6.SliceInfo>) sliceInfo).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_6.SliceInfo _hidl_vec_element = new android.hardware.radio.V1_6.SliceInfo();
                ((android.hardware.radio.V1_6.SliceInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 20);
                ((java.util.ArrayList<android.hardware.radio.V1_6.SliceInfo>) sliceInfo).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 32 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 16,_hidl_blob.handle(),
                    _hidl_offset + 32 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<String>) dnn).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                String _hidl_vec_element = new String();
                _hidl_vec_element = childBlob.getString(_hidl_index_0 * 16);

                parcel.readEmbeddedBuffer(
                        ((String) _hidl_vec_element).getBytes().length + 1,
                        childBlob.handle(),
                        _hidl_index_0 * 16 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

                ((java.util.ArrayList<String>) dnn).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(48 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<RouteSelectionDescriptor> _hidl_vec) {
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
        _hidl_blob.putInt8(_hidl_offset + 0, precedence);
        sessionType.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 4);
        sscMode.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 12);
        {
            int _hidl_vec_size = sliceInfo.size();
            _hidl_blob.putInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 16 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 20));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                sliceInfo.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 20);
            }
            _hidl_blob.putBlob(_hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = dnn.size();
            _hidl_blob.putInt32(_hidl_offset + 32 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 32 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 16));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putString(_hidl_index_0 * 16, dnn.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 32 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

