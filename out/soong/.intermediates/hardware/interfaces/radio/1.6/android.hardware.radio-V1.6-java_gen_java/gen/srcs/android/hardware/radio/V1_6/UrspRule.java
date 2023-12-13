package android.hardware.radio.V1_6;


public final class UrspRule {
    /**
     * Precedence value in the range of 0 to 255. Higher value has lower
     * precedence.
     */
    public byte precedence = 0;
    /**
     * Used as a matcher for network requests.
     */
    public java.util.ArrayList<android.hardware.radio.V1_6.TrafficDescriptor> trafficDescriptors = new java.util.ArrayList<android.hardware.radio.V1_6.TrafficDescriptor>();
    /**
     * List of routes (connection parameters) that must be used for requests
     * matching a trafficDescriptor.
     */
    public java.util.ArrayList<android.hardware.radio.V1_6.RouteSelectionDescriptor> routeSelectionDescriptor = new java.util.ArrayList<android.hardware.radio.V1_6.RouteSelectionDescriptor>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_6.UrspRule.class) {
            return false;
        }
        android.hardware.radio.V1_6.UrspRule other = (android.hardware.radio.V1_6.UrspRule)otherObject;
        if (this.precedence != other.precedence) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.trafficDescriptors, other.trafficDescriptors)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.routeSelectionDescriptor, other.routeSelectionDescriptor)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.precedence), 
                android.os.HidlSupport.deepHashCode(this.trafficDescriptors), 
                android.os.HidlSupport.deepHashCode(this.routeSelectionDescriptor));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".precedence = ");
        builder.append(this.precedence);
        builder.append(", .trafficDescriptors = ");
        builder.append(this.trafficDescriptors);
        builder.append(", .routeSelectionDescriptor = ");
        builder.append(this.routeSelectionDescriptor);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(40 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<UrspRule> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<UrspRule> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 40,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_6.UrspRule _hidl_vec_element = new android.hardware.radio.V1_6.UrspRule();
                ((android.hardware.radio.V1_6.UrspRule) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 40);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        precedence = _hidl_blob.getInt8(_hidl_offset + 0);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 48,_hidl_blob.handle(),
                    _hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.V1_6.TrafficDescriptor>) trafficDescriptors).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_6.TrafficDescriptor _hidl_vec_element = new android.hardware.radio.V1_6.TrafficDescriptor();
                ((android.hardware.radio.V1_6.TrafficDescriptor) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 48);
                ((java.util.ArrayList<android.hardware.radio.V1_6.TrafficDescriptor>) trafficDescriptors).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 24 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 48,_hidl_blob.handle(),
                    _hidl_offset + 24 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.V1_6.RouteSelectionDescriptor>) routeSelectionDescriptor).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_6.RouteSelectionDescriptor _hidl_vec_element = new android.hardware.radio.V1_6.RouteSelectionDescriptor();
                ((android.hardware.radio.V1_6.RouteSelectionDescriptor) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 48);
                ((java.util.ArrayList<android.hardware.radio.V1_6.RouteSelectionDescriptor>) routeSelectionDescriptor).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(40 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<UrspRule> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 40));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 40);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt8(_hidl_offset + 0, precedence);
        {
            int _hidl_vec_size = trafficDescriptors.size();
            _hidl_blob.putInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 8 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 48));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                trafficDescriptors.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 48);
            }
            _hidl_blob.putBlob(_hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = routeSelectionDescriptor.size();
            _hidl_blob.putInt32(_hidl_offset + 24 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 24 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 48));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                routeSelectionDescriptor.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 48);
            }
            _hidl_blob.putBlob(_hidl_offset + 24 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

