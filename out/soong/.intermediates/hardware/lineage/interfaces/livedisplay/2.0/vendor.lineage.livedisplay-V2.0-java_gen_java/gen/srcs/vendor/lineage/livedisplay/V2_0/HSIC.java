package vendor.lineage.livedisplay.V2_0;


public final class HSIC {
    public float hue = 0.0f;
    public float saturation = 0.0f;
    public float intensity = 0.0f;
    public float contrast = 0.0f;
    public float saturationThreshold = 0.0f;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != vendor.lineage.livedisplay.V2_0.HSIC.class) {
            return false;
        }
        vendor.lineage.livedisplay.V2_0.HSIC other = (vendor.lineage.livedisplay.V2_0.HSIC)otherObject;
        if (this.hue != other.hue) {
            return false;
        }
        if (this.saturation != other.saturation) {
            return false;
        }
        if (this.intensity != other.intensity) {
            return false;
        }
        if (this.contrast != other.contrast) {
            return false;
        }
        if (this.saturationThreshold != other.saturationThreshold) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.hue), 
                android.os.HidlSupport.deepHashCode(this.saturation), 
                android.os.HidlSupport.deepHashCode(this.intensity), 
                android.os.HidlSupport.deepHashCode(this.contrast), 
                android.os.HidlSupport.deepHashCode(this.saturationThreshold));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".hue = ");
        builder.append(this.hue);
        builder.append(", .saturation = ");
        builder.append(this.saturation);
        builder.append(", .intensity = ");
        builder.append(this.intensity);
        builder.append(", .contrast = ");
        builder.append(this.contrast);
        builder.append(", .saturationThreshold = ");
        builder.append(this.saturationThreshold);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(20 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<HSIC> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<HSIC> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 20,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                vendor.lineage.livedisplay.V2_0.HSIC _hidl_vec_element = new vendor.lineage.livedisplay.V2_0.HSIC();
                ((vendor.lineage.livedisplay.V2_0.HSIC) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 20);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        hue = _hidl_blob.getFloat(_hidl_offset + 0);
        saturation = _hidl_blob.getFloat(_hidl_offset + 4);
        intensity = _hidl_blob.getFloat(_hidl_offset + 8);
        contrast = _hidl_blob.getFloat(_hidl_offset + 12);
        saturationThreshold = _hidl_blob.getFloat(_hidl_offset + 16);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(20 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<HSIC> _hidl_vec) {
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
        _hidl_blob.putFloat(_hidl_offset + 0, hue);
        _hidl_blob.putFloat(_hidl_offset + 4, saturation);
        _hidl_blob.putFloat(_hidl_offset + 8, intensity);
        _hidl_blob.putFloat(_hidl_offset + 12, contrast);
        _hidl_blob.putFloat(_hidl_offset + 16, saturationThreshold);
    }
};

