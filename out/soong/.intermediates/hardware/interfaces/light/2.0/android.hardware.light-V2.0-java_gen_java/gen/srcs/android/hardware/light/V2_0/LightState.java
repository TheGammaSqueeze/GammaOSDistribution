package android.hardware.light.V2_0;


public final class LightState {
    /**
     * The color of the LED in ARGB.
     *
     * Do your best here.
     *   - If your light can only do red or green, if they ask for blue,
     *     you should do green.
     *   - If you can only do a brightness ramp, then use this formula:
     *      unsigned char brightness = ((77*((color>>16)&0x00ff))
     *              + (150*((color>>8)&0x00ff)) + (29*(color&0x00ff))) >> 8;
     *   - If you can only do on or off, 0 is off, anything else is on.
     *
     * The high byte should be ignored. Callers will set it to 0xff (which
     * would correspond to 255 alpha).
     */
    public int color = 0;
    /**
     * To flash the light at a given rate, set flashMode to LIGHT_FLASH_TIMED,
     * and then flashOnMS should be set to the number of milliseconds to turn
     * the light on, followed by the number of milliseconds to turn the light
     * off.
     */
    public int flashMode = 0;
    public int flashOnMs = 0;
    public int flashOffMs = 0;
    public int brightnessMode = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.light.V2_0.LightState.class) {
            return false;
        }
        android.hardware.light.V2_0.LightState other = (android.hardware.light.V2_0.LightState)otherObject;
        if (this.color != other.color) {
            return false;
        }
        if (this.flashMode != other.flashMode) {
            return false;
        }
        if (this.flashOnMs != other.flashOnMs) {
            return false;
        }
        if (this.flashOffMs != other.flashOffMs) {
            return false;
        }
        if (this.brightnessMode != other.brightnessMode) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.color), 
                android.os.HidlSupport.deepHashCode(this.flashMode), 
                android.os.HidlSupport.deepHashCode(this.flashOnMs), 
                android.os.HidlSupport.deepHashCode(this.flashOffMs), 
                android.os.HidlSupport.deepHashCode(this.brightnessMode));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".color = ");
        builder.append(this.color);
        builder.append(", .flashMode = ");
        builder.append(android.hardware.light.V2_0.Flash.toString(this.flashMode));
        builder.append(", .flashOnMs = ");
        builder.append(this.flashOnMs);
        builder.append(", .flashOffMs = ");
        builder.append(this.flashOffMs);
        builder.append(", .brightnessMode = ");
        builder.append(android.hardware.light.V2_0.Brightness.toString(this.brightnessMode));
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(20 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<LightState> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<LightState> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 20,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.light.V2_0.LightState _hidl_vec_element = new android.hardware.light.V2_0.LightState();
                ((android.hardware.light.V2_0.LightState) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 20);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        color = _hidl_blob.getInt32(_hidl_offset + 0);
        flashMode = _hidl_blob.getInt32(_hidl_offset + 4);
        flashOnMs = _hidl_blob.getInt32(_hidl_offset + 8);
        flashOffMs = _hidl_blob.getInt32(_hidl_offset + 12);
        brightnessMode = _hidl_blob.getInt32(_hidl_offset + 16);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(20 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<LightState> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, color);
        _hidl_blob.putInt32(_hidl_offset + 4, flashMode);
        _hidl_blob.putInt32(_hidl_offset + 8, flashOnMs);
        _hidl_blob.putInt32(_hidl_offset + 12, flashOffMs);
        _hidl_blob.putInt32(_hidl_offset + 16, brightnessMode);
    }
};

