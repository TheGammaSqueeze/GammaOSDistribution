package android.hardware.soundtrigger.V2_3;


public final class Properties {
    public android.hardware.soundtrigger.V2_0.ISoundTriggerHw.Properties base = new android.hardware.soundtrigger.V2_0.ISoundTriggerHw.Properties();
    /**
     * String naming the architecture used for running the supported models.
     * (eg. DSP architecture)
     */
    public String supportedModelArch = new String();
    /**
     * Bit field encoding of the AudioCapabilities
     * supported by the firmware.
     */
    public int audioCapabilities;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.soundtrigger.V2_3.Properties.class) {
            return false;
        }
        android.hardware.soundtrigger.V2_3.Properties other = (android.hardware.soundtrigger.V2_3.Properties)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.base, other.base)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.supportedModelArch, other.supportedModelArch)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.audioCapabilities, other.audioCapabilities)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.base), 
                android.os.HidlSupport.deepHashCode(this.supportedModelArch), 
                android.os.HidlSupport.deepHashCode(this.audioCapabilities));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".base = ");
        builder.append(this.base);
        builder.append(", .supportedModelArch = ");
        builder.append(this.supportedModelArch);
        builder.append(", .audioCapabilities = ");
        builder.append(android.hardware.soundtrigger.V2_3.AudioCapabilities.dumpBitfield(this.audioCapabilities));
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(112 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<Properties> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<Properties> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 112,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.soundtrigger.V2_3.Properties _hidl_vec_element = new android.hardware.soundtrigger.V2_3.Properties();
                ((android.hardware.soundtrigger.V2_3.Properties) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 112);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ((android.hardware.soundtrigger.V2_0.ISoundTriggerHw.Properties) base).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
        supportedModelArch = _hidl_blob.getString(_hidl_offset + 88);

        parcel.readEmbeddedBuffer(
                ((String) supportedModelArch).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 88 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        audioCapabilities = _hidl_blob.getInt32(_hidl_offset + 104);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(112 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<Properties> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 112));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 112);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        base.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
        _hidl_blob.putString(_hidl_offset + 88, supportedModelArch);
        _hidl_blob.putInt32(_hidl_offset + 104, audioCapabilities);
    }
};

