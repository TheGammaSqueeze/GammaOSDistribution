package android.hardware.radio.V1_0;


public final class CardStatus {
    public int cardState = 0;
    public int universalPinState = 0;
    public int gsmUmtsSubscriptionAppIndex = 0;
    public int cdmaSubscriptionAppIndex = 0;
    public int imsSubscriptionAppIndex = 0;
    public java.util.ArrayList<android.hardware.radio.V1_0.AppStatus> applications = new java.util.ArrayList<android.hardware.radio.V1_0.AppStatus>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_0.CardStatus.class) {
            return false;
        }
        android.hardware.radio.V1_0.CardStatus other = (android.hardware.radio.V1_0.CardStatus)otherObject;
        if (this.cardState != other.cardState) {
            return false;
        }
        if (this.universalPinState != other.universalPinState) {
            return false;
        }
        if (this.gsmUmtsSubscriptionAppIndex != other.gsmUmtsSubscriptionAppIndex) {
            return false;
        }
        if (this.cdmaSubscriptionAppIndex != other.cdmaSubscriptionAppIndex) {
            return false;
        }
        if (this.imsSubscriptionAppIndex != other.imsSubscriptionAppIndex) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.applications, other.applications)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.cardState), 
                android.os.HidlSupport.deepHashCode(this.universalPinState), 
                android.os.HidlSupport.deepHashCode(this.gsmUmtsSubscriptionAppIndex), 
                android.os.HidlSupport.deepHashCode(this.cdmaSubscriptionAppIndex), 
                android.os.HidlSupport.deepHashCode(this.imsSubscriptionAppIndex), 
                android.os.HidlSupport.deepHashCode(this.applications));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".cardState = ");
        builder.append(android.hardware.radio.V1_0.CardState.toString(this.cardState));
        builder.append(", .universalPinState = ");
        builder.append(android.hardware.radio.V1_0.PinState.toString(this.universalPinState));
        builder.append(", .gsmUmtsSubscriptionAppIndex = ");
        builder.append(this.gsmUmtsSubscriptionAppIndex);
        builder.append(", .cdmaSubscriptionAppIndex = ");
        builder.append(this.cdmaSubscriptionAppIndex);
        builder.append(", .imsSubscriptionAppIndex = ");
        builder.append(this.imsSubscriptionAppIndex);
        builder.append(", .applications = ");
        builder.append(this.applications);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(40 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<CardStatus> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<CardStatus> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 40,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.CardStatus _hidl_vec_element = new android.hardware.radio.V1_0.CardStatus();
                ((android.hardware.radio.V1_0.CardStatus) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 40);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        cardState = _hidl_blob.getInt32(_hidl_offset + 0);
        universalPinState = _hidl_blob.getInt32(_hidl_offset + 4);
        gsmUmtsSubscriptionAppIndex = _hidl_blob.getInt32(_hidl_offset + 8);
        cdmaSubscriptionAppIndex = _hidl_blob.getInt32(_hidl_offset + 12);
        imsSubscriptionAppIndex = _hidl_blob.getInt32(_hidl_offset + 16);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 24 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 64,_hidl_blob.handle(),
                    _hidl_offset + 24 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.radio.V1_0.AppStatus>) applications).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_0.AppStatus _hidl_vec_element = new android.hardware.radio.V1_0.AppStatus();
                ((android.hardware.radio.V1_0.AppStatus) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 64);
                ((java.util.ArrayList<android.hardware.radio.V1_0.AppStatus>) applications).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(40 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<CardStatus> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, cardState);
        _hidl_blob.putInt32(_hidl_offset + 4, universalPinState);
        _hidl_blob.putInt32(_hidl_offset + 8, gsmUmtsSubscriptionAppIndex);
        _hidl_blob.putInt32(_hidl_offset + 12, cdmaSubscriptionAppIndex);
        _hidl_blob.putInt32(_hidl_offset + 16, imsSubscriptionAppIndex);
        {
            int _hidl_vec_size = applications.size();
            _hidl_blob.putInt32(_hidl_offset + 24 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 24 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 64));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                applications.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 64);
            }
            _hidl_blob.putBlob(_hidl_offset + 24 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

