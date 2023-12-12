package android.hardware.radio.V1_0;


public final class Call {
    public int state = 0;
    public int index = 0;
    public int toa = 0;
    public boolean isMpty = false;
    public boolean isMT = false;
    public byte als = 0;
    public boolean isVoice = false;
    public boolean isVoicePrivacy = false;
    public String number = new String();
    public int numberPresentation = 0;
    public String name = new String();
    public int namePresentation = 0;
    public java.util.ArrayList<android.hardware.radio.V1_0.UusInfo> uusInfo = new java.util.ArrayList<android.hardware.radio.V1_0.UusInfo>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_0.Call.class) {
            return false;
        }
        android.hardware.radio.V1_0.Call other = (android.hardware.radio.V1_0.Call)otherObject;
        if (this.state != other.state) {
            return false;
        }
        if (this.index != other.index) {
            return false;
        }
        if (this.toa != other.toa) {
            return false;
        }
        if (this.isMpty != other.isMpty) {
            return false;
        }
        if (this.isMT != other.isMT) {
            return false;
        }
        if (this.als != other.als) {
            return false;
        }
        if (this.isVoice != other.isVoice) {
            return false;
        }
        if (this.isVoicePrivacy != other.isVoicePrivacy) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.number, other.number)) {
            return false;
        }
        if (this.numberPresentation != other.numberPresentation) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.name, other.name)) {
            return false;
        }
        if (this.namePresentation != other.namePresentation) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.uusInfo, other.uusInfo)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.state), 
                android.os.HidlSupport.deepHashCode(this.index), 
                android.os.HidlSupport.deepHashCode(this.toa), 
                android.os.HidlSupport.deepHashCode(this.isMpty), 
                android.os.HidlSupport.deepHashCode(this.isMT), 
                android.os.HidlSupport.deepHashCode(this.als), 
                android.os.HidlSupport.deepHashCode(this.isVoice), 
                android.os.HidlSupport.deepHashCode(this.isVoicePrivacy), 
                android.os.HidlSupport.deepHashCode(this.number), 
                android.os.HidlSupport.deepHashCode(this.numberPresentation), 
                android.os.HidlSupport.deepHashCode(this.name), 
                android.os.HidlSupport.deepHashCode(this.namePresentation), 
                android.os.HidlSupport.deepHashCode(this.uusInfo));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".state = ");
        builder.append(android.hardware.radio.V1_0.CallState.toString(this.state));
        builder.append(", .index = ");
        builder.append(this.index);
        builder.append(", .toa = ");
        builder.append(this.toa);
        builder.append(", .isMpty = ");
        builder.append(this.isMpty);
        builder.append(", .isMT = ");
        builder.append(this.isMT);
        builder.append(", .als = ");
        builder.append(this.als);
        builder.append(", .isVoice = ");
        builder.append(this.isVoice);
        builder.append(", .isVoicePrivacy = ");
        builder.append(this.isVoicePrivacy);
        builder.append(", .number = ");
        builder.append(this.number);
        builder.append(", .numberPresentation = ");
        builder.append(android.hardware.radio.V1_0.CallPresentation.toString(this.numberPresentation));
        builder.append(", .name = ");
        builder.append(this.name);
        builder.append(", .namePresentation = ");
        builder.append(android.hardware.radio.V1_0.CallPresentation.toString(this.namePresentation));
        builder.append(", .uusInfo = ");
        builder.append(this.uusInfo);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(88 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<Call> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<Call> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 88,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.Call _hidl_vec_element = new android.hardware.radio.V1_0.Call();
                ((android.hardware.radio.V1_0.Call) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 88);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        state = _hidl_blob.getInt32(_hidl_offset + 0);
        index = _hidl_blob.getInt32(_hidl_offset + 4);
        toa = _hidl_blob.getInt32(_hidl_offset + 8);
        isMpty = _hidl_blob.getBool(_hidl_offset + 12);
        isMT = _hidl_blob.getBool(_hidl_offset + 13);
        als = _hidl_blob.getInt8(_hidl_offset + 14);
        isVoice = _hidl_blob.getBool(_hidl_offset + 15);
        isVoicePrivacy = _hidl_blob.getBool(_hidl_offset + 16);
        number = _hidl_blob.getString(_hidl_offset + 24);

        parcel.readEmbeddedBuffer(
                ((String) number).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 24 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        numberPresentation = _hidl_blob.getInt32(_hidl_offset + 40);
        name = _hidl_blob.getString(_hidl_offset + 48);

        parcel.readEmbeddedBuffer(
                ((String) name).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 48 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        namePresentation = _hidl_blob.getInt32(_hidl_offset + 64);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 72 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 24,_hidl_blob.handle(),
                    _hidl_offset + 72 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.V1_0.UusInfo>) uusInfo).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.UusInfo _hidl_vec_element = new android.hardware.radio.V1_0.UusInfo();
                ((android.hardware.radio.V1_0.UusInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 24);
                ((java.util.ArrayList<android.hardware.radio.V1_0.UusInfo>) uusInfo).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(88 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<Call> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, state);
        _hidl_blob.putInt32(_hidl_offset + 4, index);
        _hidl_blob.putInt32(_hidl_offset + 8, toa);
        _hidl_blob.putBool(_hidl_offset + 12, isMpty);
        _hidl_blob.putBool(_hidl_offset + 13, isMT);
        _hidl_blob.putInt8(_hidl_offset + 14, als);
        _hidl_blob.putBool(_hidl_offset + 15, isVoice);
        _hidl_blob.putBool(_hidl_offset + 16, isVoicePrivacy);
        _hidl_blob.putString(_hidl_offset + 24, number);
        _hidl_blob.putInt32(_hidl_offset + 40, numberPresentation);
        _hidl_blob.putString(_hidl_offset + 48, name);
        _hidl_blob.putInt32(_hidl_offset + 64, namePresentation);
        {
            int _hidl_vec_size = uusInfo.size();
            _hidl_blob.putInt32(_hidl_offset + 72 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 72 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 24));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                uusInfo.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 24);
            }
            _hidl_blob.putBlob(_hidl_offset + 72 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

