package android.hardware.radio.V1_0;


public final class VoiceRegStateResult {
    public int regState = 0;
    public int rat = 0;
    public boolean cssSupported = false;
    public int roamingIndicator = 0;
    public int systemIsInPrl = 0;
    public int defaultRoamingIndicator = 0;
    public int reasonForDenial = 0;
    public android.hardware.radio.V1_0.CellIdentity cellIdentity = new android.hardware.radio.V1_0.CellIdentity();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_0.VoiceRegStateResult.class) {
            return false;
        }
        android.hardware.radio.V1_0.VoiceRegStateResult other = (android.hardware.radio.V1_0.VoiceRegStateResult)otherObject;
        if (this.regState != other.regState) {
            return false;
        }
        if (this.rat != other.rat) {
            return false;
        }
        if (this.cssSupported != other.cssSupported) {
            return false;
        }
        if (this.roamingIndicator != other.roamingIndicator) {
            return false;
        }
        if (this.systemIsInPrl != other.systemIsInPrl) {
            return false;
        }
        if (this.defaultRoamingIndicator != other.defaultRoamingIndicator) {
            return false;
        }
        if (this.reasonForDenial != other.reasonForDenial) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.cellIdentity, other.cellIdentity)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.regState), 
                android.os.HidlSupport.deepHashCode(this.rat), 
                android.os.HidlSupport.deepHashCode(this.cssSupported), 
                android.os.HidlSupport.deepHashCode(this.roamingIndicator), 
                android.os.HidlSupport.deepHashCode(this.systemIsInPrl), 
                android.os.HidlSupport.deepHashCode(this.defaultRoamingIndicator), 
                android.os.HidlSupport.deepHashCode(this.reasonForDenial), 
                android.os.HidlSupport.deepHashCode(this.cellIdentity));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".regState = ");
        builder.append(android.hardware.radio.V1_0.RegState.toString(this.regState));
        builder.append(", .rat = ");
        builder.append(this.rat);
        builder.append(", .cssSupported = ");
        builder.append(this.cssSupported);
        builder.append(", .roamingIndicator = ");
        builder.append(this.roamingIndicator);
        builder.append(", .systemIsInPrl = ");
        builder.append(this.systemIsInPrl);
        builder.append(", .defaultRoamingIndicator = ");
        builder.append(this.defaultRoamingIndicator);
        builder.append(", .reasonForDenial = ");
        builder.append(this.reasonForDenial);
        builder.append(", .cellIdentity = ");
        builder.append(this.cellIdentity);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(120 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<VoiceRegStateResult> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<VoiceRegStateResult> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 120,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.VoiceRegStateResult _hidl_vec_element = new android.hardware.radio.V1_0.VoiceRegStateResult();
                ((android.hardware.radio.V1_0.VoiceRegStateResult) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 120);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        regState = _hidl_blob.getInt32(_hidl_offset + 0);
        rat = _hidl_blob.getInt32(_hidl_offset + 4);
        cssSupported = _hidl_blob.getBool(_hidl_offset + 8);
        roamingIndicator = _hidl_blob.getInt32(_hidl_offset + 12);
        systemIsInPrl = _hidl_blob.getInt32(_hidl_offset + 16);
        defaultRoamingIndicator = _hidl_blob.getInt32(_hidl_offset + 20);
        reasonForDenial = _hidl_blob.getInt32(_hidl_offset + 24);
        ((android.hardware.radio.V1_0.CellIdentity) cellIdentity).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 32);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(120 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<VoiceRegStateResult> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 120));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 120);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, regState);
        _hidl_blob.putInt32(_hidl_offset + 4, rat);
        _hidl_blob.putBool(_hidl_offset + 8, cssSupported);
        _hidl_blob.putInt32(_hidl_offset + 12, roamingIndicator);
        _hidl_blob.putInt32(_hidl_offset + 16, systemIsInPrl);
        _hidl_blob.putInt32(_hidl_offset + 20, defaultRoamingIndicator);
        _hidl_blob.putInt32(_hidl_offset + 24, reasonForDenial);
        cellIdentity.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 32);
    }
};

