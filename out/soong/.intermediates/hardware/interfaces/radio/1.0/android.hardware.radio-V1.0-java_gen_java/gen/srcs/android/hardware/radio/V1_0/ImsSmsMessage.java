package android.hardware.radio.V1_0;


public final class ImsSmsMessage {
    public int tech = 0;
    public boolean retry = false;
    public int messageRef = 0;
    public java.util.ArrayList<android.hardware.radio.V1_0.CdmaSmsMessage> cdmaMessage = new java.util.ArrayList<android.hardware.radio.V1_0.CdmaSmsMessage>();
    public java.util.ArrayList<android.hardware.radio.V1_0.GsmSmsMessage> gsmMessage = new java.util.ArrayList<android.hardware.radio.V1_0.GsmSmsMessage>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_0.ImsSmsMessage.class) {
            return false;
        }
        android.hardware.radio.V1_0.ImsSmsMessage other = (android.hardware.radio.V1_0.ImsSmsMessage)otherObject;
        if (this.tech != other.tech) {
            return false;
        }
        if (this.retry != other.retry) {
            return false;
        }
        if (this.messageRef != other.messageRef) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.cdmaMessage, other.cdmaMessage)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.gsmMessage, other.gsmMessage)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.tech), 
                android.os.HidlSupport.deepHashCode(this.retry), 
                android.os.HidlSupport.deepHashCode(this.messageRef), 
                android.os.HidlSupport.deepHashCode(this.cdmaMessage), 
                android.os.HidlSupport.deepHashCode(this.gsmMessage));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".tech = ");
        builder.append(android.hardware.radio.V1_0.RadioTechnologyFamily.toString(this.tech));
        builder.append(", .retry = ");
        builder.append(this.retry);
        builder.append(", .messageRef = ");
        builder.append(this.messageRef);
        builder.append(", .cdmaMessage = ");
        builder.append(this.cdmaMessage);
        builder.append(", .gsmMessage = ");
        builder.append(this.gsmMessage);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(48 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<ImsSmsMessage> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<ImsSmsMessage> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 48,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.ImsSmsMessage _hidl_vec_element = new android.hardware.radio.V1_0.ImsSmsMessage();
                ((android.hardware.radio.V1_0.ImsSmsMessage) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 48);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        tech = _hidl_blob.getInt32(_hidl_offset + 0);
        retry = _hidl_blob.getBool(_hidl_offset + 4);
        messageRef = _hidl_blob.getInt32(_hidl_offset + 8);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 88,_hidl_blob.handle(),
                    _hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.V1_0.CdmaSmsMessage>) cdmaMessage).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.CdmaSmsMessage _hidl_vec_element = new android.hardware.radio.V1_0.CdmaSmsMessage();
                ((android.hardware.radio.V1_0.CdmaSmsMessage) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 88);
                ((java.util.ArrayList<android.hardware.radio.V1_0.CdmaSmsMessage>) cdmaMessage).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 32 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 32,_hidl_blob.handle(),
                    _hidl_offset + 32 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.V1_0.GsmSmsMessage>) gsmMessage).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.GsmSmsMessage _hidl_vec_element = new android.hardware.radio.V1_0.GsmSmsMessage();
                ((android.hardware.radio.V1_0.GsmSmsMessage) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 32);
                ((java.util.ArrayList<android.hardware.radio.V1_0.GsmSmsMessage>) gsmMessage).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(48 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<ImsSmsMessage> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, tech);
        _hidl_blob.putBool(_hidl_offset + 4, retry);
        _hidl_blob.putInt32(_hidl_offset + 8, messageRef);
        {
            int _hidl_vec_size = cdmaMessage.size();
            _hidl_blob.putInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 16 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 88));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                cdmaMessage.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 88);
            }
            _hidl_blob.putBlob(_hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = gsmMessage.size();
            _hidl_blob.putInt32(_hidl_offset + 32 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 32 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 32));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                gsmMessage.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 32);
            }
            _hidl_blob.putBlob(_hidl_offset + 32 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

