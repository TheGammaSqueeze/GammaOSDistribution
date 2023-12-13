package android.hardware.radio.V1_4;


public final class RadioFrequencyInfo {
    public RadioFrequencyInfo() {
        hidl_o = 0;
    }

    public static final class hidl_discriminator {
        /**
         * A rough frequency range.
         */
        public static final byte range = 0;  // int
        /**
         * The Absolute Radio Frequency Channel Number.
         */
        public static final byte channelNumber = 1;  // int

        public static final String getName(byte value) {
            switch (value) {
                case 0: { return "range"; }
                case 1: { return "channelNumber"; }
                default: { return "Unknown"; }
            }
        }

        private hidl_discriminator() {}
    }

    private byte hidl_d = 0;
    private Object hidl_o = null;
    public void range(int range) {
        hidl_d = hidl_discriminator.range;
        hidl_o = range;
    }

    public int range() {
        if (hidl_d != hidl_discriminator.range) {
            String className = (hidl_o != null) ? hidl_o.getClass().getName() : "null";
            throw new IllegalStateException(
                    "Read access to inactive union components is disallowed. " +
                    "Discriminator value is " + hidl_d + " (corresponding " +
                    "to " + hidl_discriminator.getName(hidl_d) + "), and " +
                    "hidl_o is of type " + className + ".");
        }
        if (hidl_o != null && !Integer.class.isInstance(hidl_o)) {
            throw new Error("Union is in a corrupted state.");
        }
        return ((int) hidl_o);
    }

    public void channelNumber(int channelNumber) {
        hidl_d = hidl_discriminator.channelNumber;
        hidl_o = channelNumber;
    }

    public int channelNumber() {
        if (hidl_d != hidl_discriminator.channelNumber) {
            String className = (hidl_o != null) ? hidl_o.getClass().getName() : "null";
            throw new IllegalStateException(
                    "Read access to inactive union components is disallowed. " +
                    "Discriminator value is " + hidl_d + " (corresponding " +
                    "to " + hidl_discriminator.getName(hidl_d) + "), and " +
                    "hidl_o is of type " + className + ".");
        }
        if (hidl_o != null && !Integer.class.isInstance(hidl_o)) {
            throw new Error("Union is in a corrupted state.");
        }
        return ((int) hidl_o);
    }

    // Utility method
    public byte getDiscriminator() { return hidl_d; }

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_4.RadioFrequencyInfo.class) {
            return false;
        }
        android.hardware.radio.V1_4.RadioFrequencyInfo other = (android.hardware.radio.V1_4.RadioFrequencyInfo)otherObject;
        if (this.hidl_d != other.hidl_d) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.hidl_o, other.hidl_o)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.hidl_o),
                java.util.Objects.hashCode(this.hidl_d));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        switch (this.hidl_d) {
            case hidl_discriminator.range: {
                builder.append(".range = ");
                builder.append(android.hardware.radio.V1_4.FrequencyRange.toString(this.range()));
                break;
            }
            case hidl_discriminator.channelNumber: {
                builder.append(".channelNumber = ");
                builder.append(this.channelNumber());
                break;
            }
            default: {
                throw new Error("Unknown union discriminator (value: " + hidl_d + ").");
            }
        }
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(8 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<RadioFrequencyInfo> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<RadioFrequencyInfo> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 8,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_4.RadioFrequencyInfo _hidl_vec_element = new android.hardware.radio.V1_4.RadioFrequencyInfo();
                ((android.hardware.radio.V1_4.RadioFrequencyInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 8);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        hidl_d = _hidl_blob.getInt8(_hidl_offset + 0);
        switch (this.hidl_d) {
            case hidl_discriminator.range: {
                hidl_o = 0;
                hidl_o = _hidl_blob.getInt32(_hidl_offset + 4);
                break;
            }
            case hidl_discriminator.channelNumber: {
                hidl_o = 0;
                hidl_o = _hidl_blob.getInt32(_hidl_offset + 4);
                break;
            }
            default: {
                throw new IllegalStateException("Unknown union discriminator (value: " + hidl_d + ").");
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(8 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<RadioFrequencyInfo> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 8));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 8);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt8(_hidl_offset + 0, hidl_d);
        switch (this.hidl_d) {
            case hidl_discriminator.range: {
                _hidl_blob.putInt32(_hidl_offset + 4, range());
                break;
            }
            case hidl_discriminator.channelNumber: {
                _hidl_blob.putInt32(_hidl_offset + 4, channelNumber());
                break;
            }
            default: {
                throw new Error("Unknown union discriminator (value: " + hidl_d + ").");
            }
        }
    }
};

