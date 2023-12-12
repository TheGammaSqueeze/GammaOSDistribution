package android.hardware.radio.V1_5;


public final class CellIdentity {
    public CellIdentity() {
        hidl_o = new android.hidl.safe_union.V1_0.Monostate();
    }

    public static final class hidl_discriminator {
        public static final byte noinit = 0;  // android.hidl.safe_union.V1_0.Monostate
        public static final byte gsm = 1;  // android.hardware.radio.V1_5.CellIdentityGsm
        public static final byte wcdma = 2;  // android.hardware.radio.V1_5.CellIdentityWcdma
        public static final byte tdscdma = 3;  // android.hardware.radio.V1_5.CellIdentityTdscdma
        public static final byte cdma = 4;  // android.hardware.radio.V1_2.CellIdentityCdma
        public static final byte lte = 5;  // android.hardware.radio.V1_5.CellIdentityLte
        public static final byte nr = 6;  // android.hardware.radio.V1_5.CellIdentityNr

        public static final String getName(byte value) {
            switch (value) {
                case 0: { return "noinit"; }
                case 1: { return "gsm"; }
                case 2: { return "wcdma"; }
                case 3: { return "tdscdma"; }
                case 4: { return "cdma"; }
                case 5: { return "lte"; }
                case 6: { return "nr"; }
                default: { return "Unknown"; }
            }
        }

        private hidl_discriminator() {}
    }

    private byte hidl_d = 0;
    private Object hidl_o = null;
    public void noinit(android.hidl.safe_union.V1_0.Monostate noinit) {
        hidl_d = hidl_discriminator.noinit;
        hidl_o = noinit;
    }

    public android.hidl.safe_union.V1_0.Monostate noinit() {
        if (hidl_d != hidl_discriminator.noinit) {
            String className = (hidl_o != null) ? hidl_o.getClass().getName() : "null";
            throw new IllegalStateException(
                    "Read access to inactive union components is disallowed. " +
                    "Discriminator value is " + hidl_d + " (corresponding " +
                    "to " + hidl_discriminator.getName(hidl_d) + "), and " +
                    "hidl_o is of type " + className + ".");
        }
        if (hidl_o != null && !android.hidl.safe_union.V1_0.Monostate.class.isInstance(hidl_o)) {
            throw new Error("Union is in a corrupted state.");
        }
        return ((android.hidl.safe_union.V1_0.Monostate) hidl_o);
    }

    public void gsm(android.hardware.radio.V1_5.CellIdentityGsm gsm) {
        hidl_d = hidl_discriminator.gsm;
        hidl_o = gsm;
    }

    public android.hardware.radio.V1_5.CellIdentityGsm gsm() {
        if (hidl_d != hidl_discriminator.gsm) {
            String className = (hidl_o != null) ? hidl_o.getClass().getName() : "null";
            throw new IllegalStateException(
                    "Read access to inactive union components is disallowed. " +
                    "Discriminator value is " + hidl_d + " (corresponding " +
                    "to " + hidl_discriminator.getName(hidl_d) + "), and " +
                    "hidl_o is of type " + className + ".");
        }
        if (hidl_o != null && !android.hardware.radio.V1_5.CellIdentityGsm.class.isInstance(hidl_o)) {
            throw new Error("Union is in a corrupted state.");
        }
        return ((android.hardware.radio.V1_5.CellIdentityGsm) hidl_o);
    }

    public void wcdma(android.hardware.radio.V1_5.CellIdentityWcdma wcdma) {
        hidl_d = hidl_discriminator.wcdma;
        hidl_o = wcdma;
    }

    public android.hardware.radio.V1_5.CellIdentityWcdma wcdma() {
        if (hidl_d != hidl_discriminator.wcdma) {
            String className = (hidl_o != null) ? hidl_o.getClass().getName() : "null";
            throw new IllegalStateException(
                    "Read access to inactive union components is disallowed. " +
                    "Discriminator value is " + hidl_d + " (corresponding " +
                    "to " + hidl_discriminator.getName(hidl_d) + "), and " +
                    "hidl_o is of type " + className + ".");
        }
        if (hidl_o != null && !android.hardware.radio.V1_5.CellIdentityWcdma.class.isInstance(hidl_o)) {
            throw new Error("Union is in a corrupted state.");
        }
        return ((android.hardware.radio.V1_5.CellIdentityWcdma) hidl_o);
    }

    public void tdscdma(android.hardware.radio.V1_5.CellIdentityTdscdma tdscdma) {
        hidl_d = hidl_discriminator.tdscdma;
        hidl_o = tdscdma;
    }

    public android.hardware.radio.V1_5.CellIdentityTdscdma tdscdma() {
        if (hidl_d != hidl_discriminator.tdscdma) {
            String className = (hidl_o != null) ? hidl_o.getClass().getName() : "null";
            throw new IllegalStateException(
                    "Read access to inactive union components is disallowed. " +
                    "Discriminator value is " + hidl_d + " (corresponding " +
                    "to " + hidl_discriminator.getName(hidl_d) + "), and " +
                    "hidl_o is of type " + className + ".");
        }
        if (hidl_o != null && !android.hardware.radio.V1_5.CellIdentityTdscdma.class.isInstance(hidl_o)) {
            throw new Error("Union is in a corrupted state.");
        }
        return ((android.hardware.radio.V1_5.CellIdentityTdscdma) hidl_o);
    }

    public void cdma(android.hardware.radio.V1_2.CellIdentityCdma cdma) {
        hidl_d = hidl_discriminator.cdma;
        hidl_o = cdma;
    }

    public android.hardware.radio.V1_2.CellIdentityCdma cdma() {
        if (hidl_d != hidl_discriminator.cdma) {
            String className = (hidl_o != null) ? hidl_o.getClass().getName() : "null";
            throw new IllegalStateException(
                    "Read access to inactive union components is disallowed. " +
                    "Discriminator value is " + hidl_d + " (corresponding " +
                    "to " + hidl_discriminator.getName(hidl_d) + "), and " +
                    "hidl_o is of type " + className + ".");
        }
        if (hidl_o != null && !android.hardware.radio.V1_2.CellIdentityCdma.class.isInstance(hidl_o)) {
            throw new Error("Union is in a corrupted state.");
        }
        return ((android.hardware.radio.V1_2.CellIdentityCdma) hidl_o);
    }

    public void lte(android.hardware.radio.V1_5.CellIdentityLte lte) {
        hidl_d = hidl_discriminator.lte;
        hidl_o = lte;
    }

    public android.hardware.radio.V1_5.CellIdentityLte lte() {
        if (hidl_d != hidl_discriminator.lte) {
            String className = (hidl_o != null) ? hidl_o.getClass().getName() : "null";
            throw new IllegalStateException(
                    "Read access to inactive union components is disallowed. " +
                    "Discriminator value is " + hidl_d + " (corresponding " +
                    "to " + hidl_discriminator.getName(hidl_d) + "), and " +
                    "hidl_o is of type " + className + ".");
        }
        if (hidl_o != null && !android.hardware.radio.V1_5.CellIdentityLte.class.isInstance(hidl_o)) {
            throw new Error("Union is in a corrupted state.");
        }
        return ((android.hardware.radio.V1_5.CellIdentityLte) hidl_o);
    }

    public void nr(android.hardware.radio.V1_5.CellIdentityNr nr) {
        hidl_d = hidl_discriminator.nr;
        hidl_o = nr;
    }

    public android.hardware.radio.V1_5.CellIdentityNr nr() {
        if (hidl_d != hidl_discriminator.nr) {
            String className = (hidl_o != null) ? hidl_o.getClass().getName() : "null";
            throw new IllegalStateException(
                    "Read access to inactive union components is disallowed. " +
                    "Discriminator value is " + hidl_d + " (corresponding " +
                    "to " + hidl_discriminator.getName(hidl_d) + "), and " +
                    "hidl_o is of type " + className + ".");
        }
        if (hidl_o != null && !android.hardware.radio.V1_5.CellIdentityNr.class.isInstance(hidl_o)) {
            throw new Error("Union is in a corrupted state.");
        }
        return ((android.hardware.radio.V1_5.CellIdentityNr) hidl_o);
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
        if (otherObject.getClass() != android.hardware.radio.V1_5.CellIdentity.class) {
            return false;
        }
        android.hardware.radio.V1_5.CellIdentity other = (android.hardware.radio.V1_5.CellIdentity)otherObject;
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
            case hidl_discriminator.noinit: {
                builder.append(".noinit = ");
                builder.append(this.noinit());
                break;
            }
            case hidl_discriminator.gsm: {
                builder.append(".gsm = ");
                builder.append(this.gsm());
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
            case hidl_discriminator.cdma: {
                builder.append(".cdma = ");
                builder.append(this.cdma());
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
        android.os.HwBlob blob = parcel.readBuffer(168 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<CellIdentity> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<CellIdentity> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 168,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_5.CellIdentity _hidl_vec_element = new android.hardware.radio.V1_5.CellIdentity();
                ((android.hardware.radio.V1_5.CellIdentity) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 168);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        hidl_d = _hidl_blob.getInt8(_hidl_offset + 0);
        switch (this.hidl_d) {
            case hidl_discriminator.noinit: {
                hidl_o = new android.hidl.safe_union.V1_0.Monostate();
                ((android.hidl.safe_union.V1_0.Monostate) hidl_o).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 8);
                break;
            }
            case hidl_discriminator.gsm: {
                hidl_o = new android.hardware.radio.V1_5.CellIdentityGsm();
                ((android.hardware.radio.V1_5.CellIdentityGsm) hidl_o).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 8);
                break;
            }
            case hidl_discriminator.wcdma: {
                hidl_o = new android.hardware.radio.V1_5.CellIdentityWcdma();
                ((android.hardware.radio.V1_5.CellIdentityWcdma) hidl_o).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 8);
                break;
            }
            case hidl_discriminator.tdscdma: {
                hidl_o = new android.hardware.radio.V1_5.CellIdentityTdscdma();
                ((android.hardware.radio.V1_5.CellIdentityTdscdma) hidl_o).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 8);
                break;
            }
            case hidl_discriminator.cdma: {
                hidl_o = new android.hardware.radio.V1_2.CellIdentityCdma();
                ((android.hardware.radio.V1_2.CellIdentityCdma) hidl_o).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 8);
                break;
            }
            case hidl_discriminator.lte: {
                hidl_o = new android.hardware.radio.V1_5.CellIdentityLte();
                ((android.hardware.radio.V1_5.CellIdentityLte) hidl_o).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 8);
                break;
            }
            case hidl_discriminator.nr: {
                hidl_o = new android.hardware.radio.V1_5.CellIdentityNr();
                ((android.hardware.radio.V1_5.CellIdentityNr) hidl_o).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 8);
                break;
            }
            default: {
                throw new IllegalStateException("Unknown union discriminator (value: " + hidl_d + ").");
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(168 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<CellIdentity> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 168));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 168);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt8(_hidl_offset + 0, hidl_d);
        switch (this.hidl_d) {
            case hidl_discriminator.noinit: {
                noinit().writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 8);
                break;
            }
            case hidl_discriminator.gsm: {
                gsm().writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 8);
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
            case hidl_discriminator.cdma: {
                cdma().writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 8);
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

