package android.hardware.radio.V1_0;


public final class CdmaSmsMessage {
    public int teleserviceId = 0;
    public boolean isServicePresent = false;
    public int serviceCategory = 0;
    public android.hardware.radio.V1_0.CdmaSmsAddress address = new android.hardware.radio.V1_0.CdmaSmsAddress();
    public android.hardware.radio.V1_0.CdmaSmsSubaddress subAddress = new android.hardware.radio.V1_0.CdmaSmsSubaddress();
    public java.util.ArrayList<Byte> bearerData = new java.util.ArrayList<Byte>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_0.CdmaSmsMessage.class) {
            return false;
        }
        android.hardware.radio.V1_0.CdmaSmsMessage other = (android.hardware.radio.V1_0.CdmaSmsMessage)otherObject;
        if (this.teleserviceId != other.teleserviceId) {
            return false;
        }
        if (this.isServicePresent != other.isServicePresent) {
            return false;
        }
        if (this.serviceCategory != other.serviceCategory) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.address, other.address)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.subAddress, other.subAddress)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.bearerData, other.bearerData)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.teleserviceId), 
                android.os.HidlSupport.deepHashCode(this.isServicePresent), 
                android.os.HidlSupport.deepHashCode(this.serviceCategory), 
                android.os.HidlSupport.deepHashCode(this.address), 
                android.os.HidlSupport.deepHashCode(this.subAddress), 
                android.os.HidlSupport.deepHashCode(this.bearerData));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".teleserviceId = ");
        builder.append(this.teleserviceId);
        builder.append(", .isServicePresent = ");
        builder.append(this.isServicePresent);
        builder.append(", .serviceCategory = ");
        builder.append(this.serviceCategory);
        builder.append(", .address = ");
        builder.append(this.address);
        builder.append(", .subAddress = ");
        builder.append(this.subAddress);
        builder.append(", .bearerData = ");
        builder.append(this.bearerData);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(88 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<CdmaSmsMessage> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<CdmaSmsMessage> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 88,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.CdmaSmsMessage _hidl_vec_element = new android.hardware.radio.V1_0.CdmaSmsMessage();
                ((android.hardware.radio.V1_0.CdmaSmsMessage) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 88);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        teleserviceId = _hidl_blob.getInt32(_hidl_offset + 0);
        isServicePresent = _hidl_blob.getBool(_hidl_offset + 4);
        serviceCategory = _hidl_blob.getInt32(_hidl_offset + 8);
        ((android.hardware.radio.V1_0.CdmaSmsAddress) address).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 16);
        ((android.hardware.radio.V1_0.CdmaSmsSubaddress) subAddress).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 48);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 72 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 1,_hidl_blob.handle(),
                    _hidl_offset + 72 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Byte>) bearerData).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                byte _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                ((java.util.ArrayList<Byte>) bearerData).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(88 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<CdmaSmsMessage> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 88));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 88);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, teleserviceId);
        _hidl_blob.putBool(_hidl_offset + 4, isServicePresent);
        _hidl_blob.putInt32(_hidl_offset + 8, serviceCategory);
        address.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 16);
        subAddress.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 48);
        {
            int _hidl_vec_size = bearerData.size();
            _hidl_blob.putInt32(_hidl_offset + 72 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 72 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt8(_hidl_index_0 * 1, bearerData.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 72 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

