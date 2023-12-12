package android.hardware.radio.V1_5;


public final class RadioAccessSpecifier {
    public final static class Bands {
        public Bands() {
            hidl_o = new java.util.ArrayList<Integer>();
        }

        public static final class hidl_discriminator {
            /**
             * Valid only if radioAccessNetwork = GERAN.
             */
            public static final byte geranBands = 0;  // java.util.ArrayList<Integer>
            /**
             * Valid only if radioAccessNetwork = UTRAN.
             */
            public static final byte utranBands = 1;  // java.util.ArrayList<Integer>
            /**
             * Valid only if radioAccessNetwork = EUTRAN.
             */
            public static final byte eutranBands = 2;  // java.util.ArrayList<Integer>
            /**
             * Valid only if radioAccessNetwork = NGRAN.
             */
            public static final byte ngranBands = 3;  // java.util.ArrayList<Integer>

            public static final String getName(byte value) {
                switch (value) {
                    case 0: { return "geranBands"; }
                    case 1: { return "utranBands"; }
                    case 2: { return "eutranBands"; }
                    case 3: { return "ngranBands"; }
                    default: { return "Unknown"; }
                }
            }

            private hidl_discriminator() {}
        }

        private byte hidl_d = 0;
        private Object hidl_o = null;
        public void geranBands(java.util.ArrayList<Integer> geranBands) {
            hidl_d = hidl_discriminator.geranBands;
            hidl_o = geranBands;
        }

        public java.util.ArrayList<Integer> geranBands() {
            if (hidl_d != hidl_discriminator.geranBands) {
                String className = (hidl_o != null) ? hidl_o.getClass().getName() : "null";
                throw new IllegalStateException(
                        "Read access to inactive union components is disallowed. " +
                        "Discriminator value is " + hidl_d + " (corresponding " +
                        "to " + hidl_discriminator.getName(hidl_d) + "), and " +
                        "hidl_o is of type " + className + ".");
            }
            if (hidl_o != null && !java.util.ArrayList.class.isInstance(hidl_o)) {
                throw new Error("Union is in a corrupted state.");
            }
            return ((java.util.ArrayList<Integer>) hidl_o);
        }

        public void utranBands(java.util.ArrayList<Integer> utranBands) {
            hidl_d = hidl_discriminator.utranBands;
            hidl_o = utranBands;
        }

        public java.util.ArrayList<Integer> utranBands() {
            if (hidl_d != hidl_discriminator.utranBands) {
                String className = (hidl_o != null) ? hidl_o.getClass().getName() : "null";
                throw new IllegalStateException(
                        "Read access to inactive union components is disallowed. " +
                        "Discriminator value is " + hidl_d + " (corresponding " +
                        "to " + hidl_discriminator.getName(hidl_d) + "), and " +
                        "hidl_o is of type " + className + ".");
            }
            if (hidl_o != null && !java.util.ArrayList.class.isInstance(hidl_o)) {
                throw new Error("Union is in a corrupted state.");
            }
            return ((java.util.ArrayList<Integer>) hidl_o);
        }

        public void eutranBands(java.util.ArrayList<Integer> eutranBands) {
            hidl_d = hidl_discriminator.eutranBands;
            hidl_o = eutranBands;
        }

        public java.util.ArrayList<Integer> eutranBands() {
            if (hidl_d != hidl_discriminator.eutranBands) {
                String className = (hidl_o != null) ? hidl_o.getClass().getName() : "null";
                throw new IllegalStateException(
                        "Read access to inactive union components is disallowed. " +
                        "Discriminator value is " + hidl_d + " (corresponding " +
                        "to " + hidl_discriminator.getName(hidl_d) + "), and " +
                        "hidl_o is of type " + className + ".");
            }
            if (hidl_o != null && !java.util.ArrayList.class.isInstance(hidl_o)) {
                throw new Error("Union is in a corrupted state.");
            }
            return ((java.util.ArrayList<Integer>) hidl_o);
        }

        public void ngranBands(java.util.ArrayList<Integer> ngranBands) {
            hidl_d = hidl_discriminator.ngranBands;
            hidl_o = ngranBands;
        }

        public java.util.ArrayList<Integer> ngranBands() {
            if (hidl_d != hidl_discriminator.ngranBands) {
                String className = (hidl_o != null) ? hidl_o.getClass().getName() : "null";
                throw new IllegalStateException(
                        "Read access to inactive union components is disallowed. " +
                        "Discriminator value is " + hidl_d + " (corresponding " +
                        "to " + hidl_discriminator.getName(hidl_d) + "), and " +
                        "hidl_o is of type " + className + ".");
            }
            if (hidl_o != null && !java.util.ArrayList.class.isInstance(hidl_o)) {
                throw new Error("Union is in a corrupted state.");
            }
            return ((java.util.ArrayList<Integer>) hidl_o);
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
            if (otherObject.getClass() != android.hardware.radio.V1_5.RadioAccessSpecifier.Bands.class) {
                return false;
            }
            android.hardware.radio.V1_5.RadioAccessSpecifier.Bands other = (android.hardware.radio.V1_5.RadioAccessSpecifier.Bands)otherObject;
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
                case hidl_discriminator.geranBands: {
                    builder.append(".geranBands = ");
                    builder.append(this.geranBands());
                    break;
                }
                case hidl_discriminator.utranBands: {
                    builder.append(".utranBands = ");
                    builder.append(this.utranBands());
                    break;
                }
                case hidl_discriminator.eutranBands: {
                    builder.append(".eutranBands = ");
                    builder.append(this.eutranBands());
                    break;
                }
                case hidl_discriminator.ngranBands: {
                    builder.append(".ngranBands = ");
                    builder.append(this.ngranBands());
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
            android.os.HwBlob blob = parcel.readBuffer(24 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<Bands> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<Bands> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 24,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.radio.V1_5.RadioAccessSpecifier.Bands _hidl_vec_element = new android.hardware.radio.V1_5.RadioAccessSpecifier.Bands();
                    ((android.hardware.radio.V1_5.RadioAccessSpecifier.Bands) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 24);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            hidl_d = _hidl_blob.getInt8(_hidl_offset + 0);
            switch (this.hidl_d) {
                case hidl_discriminator.geranBands: {
                    hidl_o = new java.util.ArrayList<Integer>();
                    {
                        int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                        android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                                _hidl_vec_size * 4,_hidl_blob.handle(),
                                _hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                        ((java.util.ArrayList<Integer>) hidl_o).clear();
                        for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                            int _hidl_vec_element = 0;
                            _hidl_vec_element = childBlob.getInt32(_hidl_index_0 * 4);
                            ((java.util.ArrayList<Integer>) hidl_o).add(_hidl_vec_element);
                        }
                    }
                    break;
                }
                case hidl_discriminator.utranBands: {
                    hidl_o = new java.util.ArrayList<Integer>();
                    {
                        int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                        android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                                _hidl_vec_size * 4,_hidl_blob.handle(),
                                _hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                        ((java.util.ArrayList<Integer>) hidl_o).clear();
                        for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                            int _hidl_vec_element = 0;
                            _hidl_vec_element = childBlob.getInt32(_hidl_index_0 * 4);
                            ((java.util.ArrayList<Integer>) hidl_o).add(_hidl_vec_element);
                        }
                    }
                    break;
                }
                case hidl_discriminator.eutranBands: {
                    hidl_o = new java.util.ArrayList<Integer>();
                    {
                        int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                        android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                                _hidl_vec_size * 4,_hidl_blob.handle(),
                                _hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                        ((java.util.ArrayList<Integer>) hidl_o).clear();
                        for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                            int _hidl_vec_element = 0;
                            _hidl_vec_element = childBlob.getInt32(_hidl_index_0 * 4);
                            ((java.util.ArrayList<Integer>) hidl_o).add(_hidl_vec_element);
                        }
                    }
                    break;
                }
                case hidl_discriminator.ngranBands: {
                    hidl_o = new java.util.ArrayList<Integer>();
                    {
                        int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                        android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                                _hidl_vec_size * 4,_hidl_blob.handle(),
                                _hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                        ((java.util.ArrayList<Integer>) hidl_o).clear();
                        for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                            int _hidl_vec_element = 0;
                            _hidl_vec_element = childBlob.getInt32(_hidl_index_0 * 4);
                            ((java.util.ArrayList<Integer>) hidl_o).add(_hidl_vec_element);
                        }
                    }
                    break;
                }
                default: {
                    throw new IllegalStateException("Unknown union discriminator (value: " + hidl_d + ").");
                }
            }
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(24 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<Bands> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 24));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 24);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            _hidl_blob.putInt8(_hidl_offset + 0, hidl_d);
            switch (this.hidl_d) {
                case hidl_discriminator.geranBands: {
                    {
                        int _hidl_vec_size = geranBands().size();
                        _hidl_blob.putInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                        _hidl_blob.putBool(_hidl_offset + 8 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                        android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 4));
                        for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                            childBlob.putInt32(_hidl_index_0 * 4, geranBands().get(_hidl_index_0));
                        }
                        _hidl_blob.putBlob(_hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
                    }
                    break;
                }
                case hidl_discriminator.utranBands: {
                    {
                        int _hidl_vec_size = utranBands().size();
                        _hidl_blob.putInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                        _hidl_blob.putBool(_hidl_offset + 8 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                        android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 4));
                        for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                            childBlob.putInt32(_hidl_index_0 * 4, utranBands().get(_hidl_index_0));
                        }
                        _hidl_blob.putBlob(_hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
                    }
                    break;
                }
                case hidl_discriminator.eutranBands: {
                    {
                        int _hidl_vec_size = eutranBands().size();
                        _hidl_blob.putInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                        _hidl_blob.putBool(_hidl_offset + 8 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                        android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 4));
                        for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                            childBlob.putInt32(_hidl_index_0 * 4, eutranBands().get(_hidl_index_0));
                        }
                        _hidl_blob.putBlob(_hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
                    }
                    break;
                }
                case hidl_discriminator.ngranBands: {
                    {
                        int _hidl_vec_size = ngranBands().size();
                        _hidl_blob.putInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                        _hidl_blob.putBool(_hidl_offset + 8 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                        android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 4));
                        for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                            childBlob.putInt32(_hidl_index_0 * 4, ngranBands().get(_hidl_index_0));
                        }
                        _hidl_blob.putBlob(_hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
                    }
                    break;
                }
                default: {
                    throw new Error("Unknown union discriminator (value: " + hidl_d + ").");
                }
            }
        }
    };

    /**
     * The type of network to scan.
     */
    public int radioAccessNetwork = 0;
    /**
     * The frequency bands to scan.
     * Maximum length of the vector is 8.
     */
    public android.hardware.radio.V1_5.RadioAccessSpecifier.Bands bands = new android.hardware.radio.V1_5.RadioAccessSpecifier.Bands();
    /**
     * The radio channels to scan as defined in 3GPP TS 25.101 and 36.101.
     * Maximum length of the vector is 32.
     */
    public java.util.ArrayList<Integer> channels = new java.util.ArrayList<Integer>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_5.RadioAccessSpecifier.class) {
            return false;
        }
        android.hardware.radio.V1_5.RadioAccessSpecifier other = (android.hardware.radio.V1_5.RadioAccessSpecifier)otherObject;
        if (this.radioAccessNetwork != other.radioAccessNetwork) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.bands, other.bands)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.channels, other.channels)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.radioAccessNetwork), 
                android.os.HidlSupport.deepHashCode(this.bands), 
                android.os.HidlSupport.deepHashCode(this.channels));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".radioAccessNetwork = ");
        builder.append(android.hardware.radio.V1_5.RadioAccessNetworks.toString(this.radioAccessNetwork));
        builder.append(", .bands = ");
        builder.append(this.bands);
        builder.append(", .channels = ");
        builder.append(this.channels);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(48 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<RadioAccessSpecifier> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<RadioAccessSpecifier> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 48,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_5.RadioAccessSpecifier _hidl_vec_element = new android.hardware.radio.V1_5.RadioAccessSpecifier();
                ((android.hardware.radio.V1_5.RadioAccessSpecifier) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 48);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        radioAccessNetwork = _hidl_blob.getInt32(_hidl_offset + 0);
        ((android.hardware.radio.V1_5.RadioAccessSpecifier.Bands) bands).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 8);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 32 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 4,_hidl_blob.handle(),
                    _hidl_offset + 32 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Integer>) channels).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                int _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt32(_hidl_index_0 * 4);
                ((java.util.ArrayList<Integer>) channels).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(48 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<RadioAccessSpecifier> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, radioAccessNetwork);
        bands.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 8);
        {
            int _hidl_vec_size = channels.size();
            _hidl_blob.putInt32(_hidl_offset + 32 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 32 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 4));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt32(_hidl_index_0 * 4, channels.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 32 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

