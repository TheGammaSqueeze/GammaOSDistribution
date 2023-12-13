package android.hardware.radio.V1_4;


public final class CarrierRestrictionsWithPriority {
    /**
     * List of allowed carriers.
     * The character '?' is used as wildcard character to match any value.
     */
    public java.util.ArrayList<android.hardware.radio.V1_0.Carrier> allowedCarriers = new java.util.ArrayList<android.hardware.radio.V1_0.Carrier>();
    /**
     * List of excluded carriers.
     * The character '?' is used as wildcard character to match any value.
     */
    public java.util.ArrayList<android.hardware.radio.V1_0.Carrier> excludedCarriers = new java.util.ArrayList<android.hardware.radio.V1_0.Carrier>();
    /**
     * True means that only carriers included in the allowed list and not in the excluded list
     * are permitted. Eg. allowedCarriers match mcc/mnc, excludedCarriers has same mcc/mnc and
     * gid1 is ABCD. It means except the carrier whose gid1 is ABCD, all carriers with the
     * same mcc/mnc are allowed.
     * False means that all carriers are allowed except those included in the excluded list
     * and not in the allowed list.
     */
    public boolean allowedCarriersPrioritized = false;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_4.CarrierRestrictionsWithPriority.class) {
            return false;
        }
        android.hardware.radio.V1_4.CarrierRestrictionsWithPriority other = (android.hardware.radio.V1_4.CarrierRestrictionsWithPriority)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.allowedCarriers, other.allowedCarriers)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.excludedCarriers, other.excludedCarriers)) {
            return false;
        }
        if (this.allowedCarriersPrioritized != other.allowedCarriersPrioritized) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.allowedCarriers), 
                android.os.HidlSupport.deepHashCode(this.excludedCarriers), 
                android.os.HidlSupport.deepHashCode(this.allowedCarriersPrioritized));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".allowedCarriers = ");
        builder.append(this.allowedCarriers);
        builder.append(", .excludedCarriers = ");
        builder.append(this.excludedCarriers);
        builder.append(", .allowedCarriersPrioritized = ");
        builder.append(this.allowedCarriersPrioritized);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(40 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<CarrierRestrictionsWithPriority> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<CarrierRestrictionsWithPriority> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 40,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_4.CarrierRestrictionsWithPriority _hidl_vec_element = new android.hardware.radio.V1_4.CarrierRestrictionsWithPriority();
                ((android.hardware.radio.V1_4.CarrierRestrictionsWithPriority) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 40);
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
                    _hidl_vec_size * 56,_hidl_blob.handle(),
                    _hidl_offset + 0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.V1_0.Carrier>) allowedCarriers).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.Carrier _hidl_vec_element = new android.hardware.radio.V1_0.Carrier();
                ((android.hardware.radio.V1_0.Carrier) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 56);
                ((java.util.ArrayList<android.hardware.radio.V1_0.Carrier>) allowedCarriers).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 56,_hidl_blob.handle(),
                    _hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.V1_0.Carrier>) excludedCarriers).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.Carrier _hidl_vec_element = new android.hardware.radio.V1_0.Carrier();
                ((android.hardware.radio.V1_0.Carrier) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 56);
                ((java.util.ArrayList<android.hardware.radio.V1_0.Carrier>) excludedCarriers).add(_hidl_vec_element);
            }
        }
        allowedCarriersPrioritized = _hidl_blob.getBool(_hidl_offset + 32);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(40 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<CarrierRestrictionsWithPriority> _hidl_vec) {
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
        {
            int _hidl_vec_size = allowedCarriers.size();
            _hidl_blob.putInt32(_hidl_offset + 0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 56));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                allowedCarriers.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 56);
            }
            _hidl_blob.putBlob(_hidl_offset + 0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = excludedCarriers.size();
            _hidl_blob.putInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 16 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 56));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                excludedCarriers.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 56);
            }
            _hidl_blob.putBlob(_hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        _hidl_blob.putBool(_hidl_offset + 32, allowedCarriersPrioritized);
    }
};

