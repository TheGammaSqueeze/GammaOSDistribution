package android.hardware.radio.V1_0;


public final class AppStatus {
    public int appType = 0;
    public int appState = 0;
    public int persoSubstate = 0;
    public String aidPtr = new String();
    public String appLabelPtr = new String();
    public int pin1Replaced = 0;
    public int pin1 = 0;
    public int pin2 = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_0.AppStatus.class) {
            return false;
        }
        android.hardware.radio.V1_0.AppStatus other = (android.hardware.radio.V1_0.AppStatus)otherObject;
        if (this.appType != other.appType) {
            return false;
        }
        if (this.appState != other.appState) {
            return false;
        }
        if (this.persoSubstate != other.persoSubstate) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.aidPtr, other.aidPtr)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.appLabelPtr, other.appLabelPtr)) {
            return false;
        }
        if (this.pin1Replaced != other.pin1Replaced) {
            return false;
        }
        if (this.pin1 != other.pin1) {
            return false;
        }
        if (this.pin2 != other.pin2) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.appType), 
                android.os.HidlSupport.deepHashCode(this.appState), 
                android.os.HidlSupport.deepHashCode(this.persoSubstate), 
                android.os.HidlSupport.deepHashCode(this.aidPtr), 
                android.os.HidlSupport.deepHashCode(this.appLabelPtr), 
                android.os.HidlSupport.deepHashCode(this.pin1Replaced), 
                android.os.HidlSupport.deepHashCode(this.pin1), 
                android.os.HidlSupport.deepHashCode(this.pin2));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".appType = ");
        builder.append(android.hardware.radio.V1_0.AppType.toString(this.appType));
        builder.append(", .appState = ");
        builder.append(android.hardware.radio.V1_0.AppState.toString(this.appState));
        builder.append(", .persoSubstate = ");
        builder.append(android.hardware.radio.V1_0.PersoSubstate.toString(this.persoSubstate));
        builder.append(", .aidPtr = ");
        builder.append(this.aidPtr);
        builder.append(", .appLabelPtr = ");
        builder.append(this.appLabelPtr);
        builder.append(", .pin1Replaced = ");
        builder.append(this.pin1Replaced);
        builder.append(", .pin1 = ");
        builder.append(android.hardware.radio.V1_0.PinState.toString(this.pin1));
        builder.append(", .pin2 = ");
        builder.append(android.hardware.radio.V1_0.PinState.toString(this.pin2));
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(64 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<AppStatus> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<AppStatus> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 64,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.AppStatus _hidl_vec_element = new android.hardware.radio.V1_0.AppStatus();
                ((android.hardware.radio.V1_0.AppStatus) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 64);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        appType = _hidl_blob.getInt32(_hidl_offset + 0);
        appState = _hidl_blob.getInt32(_hidl_offset + 4);
        persoSubstate = _hidl_blob.getInt32(_hidl_offset + 8);
        aidPtr = _hidl_blob.getString(_hidl_offset + 16);

        parcel.readEmbeddedBuffer(
                ((String) aidPtr).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 16 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        appLabelPtr = _hidl_blob.getString(_hidl_offset + 32);

        parcel.readEmbeddedBuffer(
                ((String) appLabelPtr).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 32 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        pin1Replaced = _hidl_blob.getInt32(_hidl_offset + 48);
        pin1 = _hidl_blob.getInt32(_hidl_offset + 52);
        pin2 = _hidl_blob.getInt32(_hidl_offset + 56);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(64 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<AppStatus> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 64));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 64);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, appType);
        _hidl_blob.putInt32(_hidl_offset + 4, appState);
        _hidl_blob.putInt32(_hidl_offset + 8, persoSubstate);
        _hidl_blob.putString(_hidl_offset + 16, aidPtr);
        _hidl_blob.putString(_hidl_offset + 32, appLabelPtr);
        _hidl_blob.putInt32(_hidl_offset + 48, pin1Replaced);
        _hidl_blob.putInt32(_hidl_offset + 52, pin1);
        _hidl_blob.putInt32(_hidl_offset + 56, pin2);
    }
};

