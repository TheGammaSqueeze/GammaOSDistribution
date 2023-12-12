package android.hardware.radio.V1_4;


public final class CellInfo {
    public final static class Info {
        public Info() {
            hidl_o = new android.hardware.radio.V1_2.CellInfoGsm();
        }

        public static final class hidl_discriminator {
            public static final byte gsm = 0;  // android.hardware.radio.V1_2.CellInfoGsm
            public static final byte cdma = 1;  // android.hardware.radio.V1_2.CellInfoCdma
            public static final byte wcdma = 2;  // android.hardware.radio.V1_2.CellInfoWcdma
            public static final byte tdscdma = 3;  // android.hardware.radio.V1_2.CellInfoTdscdma
            public static final byte lte = 4;  // android.hardware.radio.V1_4.CellInfoLte
            public static final byte nr = 5;  // android.hardware.radio.V1_4.CellInfoNr

            public static final String getName(byte value) {
                switch (value) {
                    case 0: { return "gsm"; }
                    case 1: { return "cdma"; }
                    case 2: { return "wcdma"; }
                    case 3: { return "tdscdma"; }
                    case 4: { return "lte"; }
                    case 5: { return "nr"; }
                    default: { return "Unknown"; }
                }
            }

            private hidl_discriminator() {}
        }

        private byte hidl_d = 0;
        private Object hidl_o = null;
        public void gsm(android.hardware.radio.V1_2.CellInfoGsm gsm) {
            hidl_d = hidl_discriminator.gsm;
            hidl_o = gsm;
        }

        public android.hardware.radio.V1_2.CellInfoGsm gsm() {
            if (hidl_d != hidl_discriminator.gsm) {
                String className = (hidl_o != null) ? hidl_o.getClass().getName() : "null";
                throw new IllegalStateException(
                        "Read access to inactive union components is disallowed. " +
                        "Discriminator value is " + hidl_d + " (corresponding " +
                        "to " + hidl_discriminator.getName(hidl_d) + "), and " +
                        "hidl_o is of type " + className + ".");
            }
            if (hidl_o != null && !android.hardware.radio.V1_2.CellInfoGsm.class.isInstance(hidl_o)) {
                throw new Error("Union is in a corrupted state.");
            }
            return ((android.hardware.radio.V1_2.CellInfoGsm) hidl_o);
        }

        public void cdma(android.hardware.radio.V1_2.CellInfoCdma cdma) {
            hidl_d = hidl_discriminator.cdma;
            hidl_o = cdma;
        }

        public android.hardware.radio.V1_2.CellInfoCdma cdma() {
            if (hidl_d != hidl_discriminator.cdma) {
                String className = (hidl_o != null) ? hidl_o.getClass().getName() : "null";
                throw new IllegalStateException(
                        "Read access to inactive union components is disallowed. " +
                        "Discriminator value is " + hidl_d + " (corresponding " +
                        "to " + hidl_discriminator.getName(hidl_d) + "), and " +
                        "hidl_o is of type " + className + ".");
            }
            if (hidl_o != null && !android.hardware.radio.V1_2.CellInfoCdma.class.isInstance(hidl_o)) {
                throw new Error("Union is in a corrupted state.");
            }
            return ((android.hardware.radio.V1_2.CellInfoCdma) hidl_o);
        }

        public void wcdma(android.hardware.radio.V1_2.CellInfoWcdma wcdma) {
            hidl_d = hidl_discriminator.wcdma;
            hidl_o = wcdma;
        }

        public android.hardware.radio.V1_2.CellInfoWcdma wcdma() {
            if (hidl_d != hidl_discriminator.wcdma) {
                String className = (hidl_o != null) ? hidl_o.getClass().getName() : "null";
                throw new IllegalStateException(
                        "Read access to inactive union components is disallowed. " +
                        "Discriminator value is " + hidl_d + " (corresponding " +
                        "to " + hidl_discriminator.getName(hidl_d) + "), and " +
                        "hidl_o is of type " + className + ".");
            }
            if (hidl_o != null && !android.hardware.radio.V1_2.CellInfoWcdma.class.isInstance(hidl_o)) {
                throw new Error("Union is in a corrupted state.");
            }
            return ((android.hardware.radio.V1_2.CellInfoWcdma) hidl_o);
        }

        public void tdscdma(android.hardware.radio.V1_2.CellInfoTdscdma tdscdma) {
            hidl_d = hidl_discriminator.tdscdma;
            hidl_o = tdscdma;
        }

        public android.hardware.radio.V1_2.CellInfoTdscdma tdscdma() {
            if (hidl_d != hidl_discriminator.tdscdma) {
                String className = (hidl_o != null) ? hidl_o.getClass().getName() : "null";
                throw new IllegalStateException(
                        "Read access to inactive union components is disallowed. " +
                        "Discriminator value is " + hidl_d + " (corresponding " +
                        "to " + hidl_discriminator.getName(hidl_d) + "), and " +
                        "hidl_o is of type " + className + ".");
            }
            if (hidl_o != null && !android.hardware.radio.V1_2.CellInfoTdscdma.class.isInstance(hidl_o)) {
                throw new Error("Union is in a corrupted state.");
            }
            return ((android.hardware.radio.V1_2.CellInfoTdscdma) hidl_o);
        }

        public void lte(android.hardware.radio.V1_4.CellInfoLte lte) {
            hidl_d = hidl_discriminator.lte;
            hidl_o = lte;
        }

        public android.hardware.radio.V1_4.CellInfoLte lte() {
            if (hidl_d != hidl_discriminator.lte) {
                String className = (hidl_o != null) ? hidl_o.getClass().getName() : "null";
                throw new IllegalStateException(
                        "Read access to inactive union components is disallowed. " +
                        "Discriminator value is " + hidl_d + " (corresponding " +
                        "to " + hidl_discriminator.getName(hidl_d) + "), and " +
                        "hidl_o is of type " + className + ".");
            }
            if (hidl_o != null && !android.hardware.radio.V1_4.CellInfoLte.class.isInstance(hidl_o)) {
                throw new Error("Union is in a corrupted state.");
            }
            return ((android.hardware.radio.V1_4.CellInfoLte) hidl_o);
        }

        public void nr(android.hardware.radio.V1_4.CellInfoNr nr) {
            hidl_d = hidl_discriminator.nr;
            hidl_o = nr;
        }

        public android.hardware.radio.V1_4.CellInfoNr nr() {
            if (hidl_d != hidl_discriminator.nr) {
                String className = (hidl_o != null) ? hidl_o.getClass().getName() : "null";
                throw new IllegalStateException(
                        "Read access to inactive union components is disallowed. " +
                        "Discriminator value is " + hidl_d + " (corresponding " +
                        "to " + hidl_discriminator.getName(hidl_d) + "), and " +
                        "hidl_o is of type " + className + ".");
            }
            if (hidl_o != null && !android.hardware.radio.V1_4.CellInfoNr.class.isInstance(hidl_o)) {
                throw new Error("Union is in a corrupted state.");
            }
            return ((android.hardware.radio.V1_4.CellInfoNr) hidl_o);
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
            if (otherObject.getClass() != android.hardware.radio.V1_4.CellInfo.Info.class) {
                return false;
            }
            android.hardware.radio.V1_4.CellInfo.Info other = (android.hardware.radio.V1_4.CellInfo.Info)otherObject;
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
                case hidl_discriminator.gsm: {
                    builder.append(".gsm = ");
                    builder.append(this.gsm());
                    break;
                }
                case hidl_discriminator.cdma: {
                    builder.append(".cdma = ");
                    builder.append(this.cdma());
                    break;
                }
                case hidl_discriminator.wcdma: {
                    builder.append(".wcdma = ");
                    builder.append(this.wcdma());
                    break;
                }
                case hidl_discriminator.tdscdma: {
                    builder.append(".tdscdma = ");
                    builder.append(this.tdscdma());
                    break;
                }
                case hidl_discriminator.lte: {
                    builder.append(".lte = ");
                    builder.append(this.lte());
                    break;
                }
                case hidl_discriminator.nr: {
                    builder.append(".nr = ");
                    builder.append(this.nr());
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
            android.os.HwBlob blob = parcel.readBuffer(128 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<Info> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<Info> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 128,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.radio.V1_4.CellInfo.Info _hidl_vec_element = new android.hardware.radio.V1_4.CellInfo.Info();
                    ((android.hardware.radio.V1_4.CellInfo.Info) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 128);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            hidl_d = _hidl_blob.getInt8(_hidl_offset + 0);
            switch (this.hidl_d) {
                case hidl_discriminator.gsm: {
                    hidl_o = new android.hardware.radio.V1_2.CellInfoGsm();
                    ((android.hardware.radio.V1_2.CellInfoGsm) hidl_o).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 8);
                    break;
                }
                case hidl_discriminator.cdma: {
                    hidl_o = new android.hardware.radio.V1_2.CellInfoCdma();
                    ((android.hardware.radio.V1_2.CellInfoCdma) hidl_o).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 8);
                    break;
                }
                case hidl_discriminator.wcdma: {
                    hidl_o = new android.hardware.radio.V1_2.CellInfoWcdma();
                    ((android.hardware.radio.V1_2.CellInfoWcdma) hidl_o).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 8);
                    break;
                }
                case hidl_discriminator.tdscdma: {
                    hidl_o = new android.hardware.radio.V1_2.CellInfoTdscdma();
                    ((android.hardware.radio.V1_2.CellInfoTdscdma) hidl_o).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 8);
                    break;
                }
                case hidl_discriminator.lte: {
                    hidl_o = new android.hardware.radio.V1_4.CellInfoLte();
                    ((android.hardware.radio.V1_4.CellInfoLte) hidl_o).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 8);
                    break;
                }
                case hidl_discriminator.nr: {
                    hidl_o = new android.hardware.radio.V1_4.CellInfoNr();
                    ((android.hardware.radio.V1_4.CellInfoNr) hidl_o).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 8);
                    break;
                }
                default: {
                    throw new IllegalStateException("Unknown union discriminator (value: " + hidl_d + ").");
                }
            }
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(128 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<Info> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 128));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 128);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            _hidl_blob.putInt8(_hidl_offset + 0, hidl_d);
            switch (this.hidl_d) {
                case hidl_discriminator.gsm: {
                    gsm().writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 8);
                    break;
                }
                case hidl_discriminator.cdma: {
                    cdma().writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 8);
                    break;
                }
                case hidl_discriminator.wcdma: {
                    wcdma().writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 8);
                    break;
                }
                case hidl_discriminator.tdscdma: {
                    tdscdma().writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 8);
                    break;
                }
                case hidl_discriminator.lte: {
                    lte().writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 8);
                    break;
                }
                case hidl_discriminator.nr: {
                    nr().writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 8);
                    break;
                }
                default: {
                    throw new Error("Unknown union discriminator (value: " + hidl_d + ").");
                }
            }
        }
    };

    /**
     * True if the phone is registered to a mobile network that provides service on this cell and
     * this cell is being used or would be used for network signaling.
     */
    public boolean isRegistered = false;
    /**
     * Connection status for the cell.
     */
    public int connectionStatus = 0;
    /**
     * CellInfo details, cellInfoType can tell which cell info should be used.
     */
    public android.hardware.radio.V1_4.CellInfo.Info info = new android.hardware.radio.V1_4.CellInfo.Info();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_4.CellInfo.class) {
            return false;
        }
        android.hardware.radio.V1_4.CellInfo other = (android.hardware.radio.V1_4.CellInfo)otherObject;
        if (this.isRegistered != other.isRegistered) {
            return false;
        }
        if (this.connectionStatus != other.connectionStatus) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.info, other.info)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.isRegistered), 
                android.os.HidlSupport.deepHashCode(this.connectionStatus), 
                android.os.HidlSupport.deepHashCode(this.info));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".isRegistered = ");
        builder.append(this.isRegistered);
        builder.append(", .connectionStatus = ");
        builder.append(android.hardware.radio.V1_2.CellConnectionStatus.toString(this.connectionStatus));
        builder.append(", .info = ");
        builder.append(this.info);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(136 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<CellInfo> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<CellInfo> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 136,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_4.CellInfo _hidl_vec_element = new android.hardware.radio.V1_4.CellInfo();
                ((android.hardware.radio.V1_4.CellInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 136);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        isRegistered = _hidl_blob.getBool(_hidl_offset + 0);
        connectionStatus = _hidl_blob.getInt32(_hidl_offset + 4);
        ((android.hardware.radio.V1_4.CellInfo.Info) info).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 8);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(136 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<CellInfo> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 136));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 136);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putBool(_hidl_offset + 0, isRegistered);
        _hidl_blob.putInt32(_hidl_offset + 4, connectionStatus);
        info.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 8);
    }
};

