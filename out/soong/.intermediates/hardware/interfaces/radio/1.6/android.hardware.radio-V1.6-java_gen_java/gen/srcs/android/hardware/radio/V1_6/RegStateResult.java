package android.hardware.radio.V1_6;


public final class RegStateResult {
    public final static class AccessTechnologySpecificInfo {
        public AccessTechnologySpecificInfo() {
            hidl_o = new android.hidl.safe_union.V1_0.Monostate();
        }

        public static final class hidl_discriminator {
            public static final byte noinit = 0;  // android.hidl.safe_union.V1_0.Monostate
            public static final byte cdmaInfo = 1;  // android.hardware.radio.V1_5.RegStateResult.AccessTechnologySpecificInfo.Cdma2000RegistrationInfo
            public static final byte eutranInfo = 2;  // android.hardware.radio.V1_5.RegStateResult.AccessTechnologySpecificInfo.EutranRegistrationInfo
            /**
             * Network capabilities for voice over PS services. This info is valid only on NR
             * network and must be present when the device is camped on NR. VopsInfo must be
             * empty when the device is not camped on NR.
             */
            public static final byte ngranNrVopsInfo = 3;  // android.hardware.radio.V1_6.NrVopsInfo
            /**
             * True if the dual transfer mode is supported.
             * Refer to 3GPP TS 44.108 section 3.4.25.3
             */
            public static final byte geranDtmSupported = 4;  // boolean

            public static final String getName(byte value) {
                switch (value) {
                    case 0: { return "noinit"; }
                    case 1: { return "cdmaInfo"; }
                    case 2: { return "eutranInfo"; }
                    case 3: { return "ngranNrVopsInfo"; }
                    case 4: { return "geranDtmSupported"; }
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

        public void cdmaInfo(android.hardware.radio.V1_5.RegStateResult.AccessTechnologySpecificInfo.Cdma2000RegistrationInfo cdmaInfo) {
            hidl_d = hidl_discriminator.cdmaInfo;
            hidl_o = cdmaInfo;
        }

        public android.hardware.radio.V1_5.RegStateResult.AccessTechnologySpecificInfo.Cdma2000RegistrationInfo cdmaInfo() {
            if (hidl_d != hidl_discriminator.cdmaInfo) {
                String className = (hidl_o != null) ? hidl_o.getClass().getName() : "null";
                throw new IllegalStateException(
                        "Read access to inactive union components is disallowed. " +
                        "Discriminator value is " + hidl_d + " (corresponding " +
                        "to " + hidl_discriminator.getName(hidl_d) + "), and " +
                        "hidl_o is of type " + className + ".");
            }
            if (hidl_o != null && !android.hardware.radio.V1_5.RegStateResult.AccessTechnologySpecificInfo.Cdma2000RegistrationInfo.class.isInstance(hidl_o)) {
                throw new Error("Union is in a corrupted state.");
            }
            return ((android.hardware.radio.V1_5.RegStateResult.AccessTechnologySpecificInfo.Cdma2000RegistrationInfo) hidl_o);
        }

        public void eutranInfo(android.hardware.radio.V1_5.RegStateResult.AccessTechnologySpecificInfo.EutranRegistrationInfo eutranInfo) {
            hidl_d = hidl_discriminator.eutranInfo;
            hidl_o = eutranInfo;
        }

        public android.hardware.radio.V1_5.RegStateResult.AccessTechnologySpecificInfo.EutranRegistrationInfo eutranInfo() {
            if (hidl_d != hidl_discriminator.eutranInfo) {
                String className = (hidl_o != null) ? hidl_o.getClass().getName() : "null";
                throw new IllegalStateException(
                        "Read access to inactive union components is disallowed. " +
                        "Discriminator value is " + hidl_d + " (corresponding " +
                        "to " + hidl_discriminator.getName(hidl_d) + "), and " +
                        "hidl_o is of type " + className + ".");
            }
            if (hidl_o != null && !android.hardware.radio.V1_5.RegStateResult.AccessTechnologySpecificInfo.EutranRegistrationInfo.class.isInstance(hidl_o)) {
                throw new Error("Union is in a corrupted state.");
            }
            return ((android.hardware.radio.V1_5.RegStateResult.AccessTechnologySpecificInfo.EutranRegistrationInfo) hidl_o);
        }

        public void ngranNrVopsInfo(android.hardware.radio.V1_6.NrVopsInfo ngranNrVopsInfo) {
            hidl_d = hidl_discriminator.ngranNrVopsInfo;
            hidl_o = ngranNrVopsInfo;
        }

        public android.hardware.radio.V1_6.NrVopsInfo ngranNrVopsInfo() {
            if (hidl_d != hidl_discriminator.ngranNrVopsInfo) {
                String className = (hidl_o != null) ? hidl_o.getClass().getName() : "null";
                throw new IllegalStateException(
                        "Read access to inactive union components is disallowed. " +
                        "Discriminator value is " + hidl_d + " (corresponding " +
                        "to " + hidl_discriminator.getName(hidl_d) + "), and " +
                        "hidl_o is of type " + className + ".");
            }
            if (hidl_o != null && !android.hardware.radio.V1_6.NrVopsInfo.class.isInstance(hidl_o)) {
                throw new Error("Union is in a corrupted state.");
            }
            return ((android.hardware.radio.V1_6.NrVopsInfo) hidl_o);
        }

        public void geranDtmSupported(boolean geranDtmSupported) {
            hidl_d = hidl_discriminator.geranDtmSupported;
            hidl_o = geranDtmSupported;
        }

        public boolean geranDtmSupported() {
            if (hidl_d != hidl_discriminator.geranDtmSupported) {
                String className = (hidl_o != null) ? hidl_o.getClass().getName() : "null";
                throw new IllegalStateException(
                        "Read access to inactive union components is disallowed. " +
                        "Discriminator value is " + hidl_d + " (corresponding " +
                        "to " + hidl_discriminator.getName(hidl_d) + "), and " +
                        "hidl_o is of type " + className + ".");
            }
            if (hidl_o != null && !Boolean.class.isInstance(hidl_o)) {
                throw new Error("Union is in a corrupted state.");
            }
            return ((boolean) hidl_o);
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
            if (otherObject.getClass() != android.hardware.radio.V1_6.RegStateResult.AccessTechnologySpecificInfo.class) {
                return false;
            }
            android.hardware.radio.V1_6.RegStateResult.AccessTechnologySpecificInfo other = (android.hardware.radio.V1_6.RegStateResult.AccessTechnologySpecificInfo)otherObject;
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
                case hidl_discriminator.cdmaInfo: {
                    builder.append(".cdmaInfo = ");
                    builder.append(this.cdmaInfo());
                    break;
                }
                case hidl_discriminator.eutranInfo: {
                    builder.append(".eutranInfo = ");
                    builder.append(this.eutranInfo());
                    break;
                }
                case hidl_discriminator.ngranNrVopsInfo: {
                    builder.append(".ngranNrVopsInfo = ");
                    builder.append(this.ngranNrVopsInfo());
                    break;
                }
                case hidl_discriminator.geranDtmSupported: {
                    builder.append(".geranDtmSupported = ");
                    builder.append(this.geranDtmSupported());
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
            android.os.HwBlob blob = parcel.readBuffer(20 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<AccessTechnologySpecificInfo> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<AccessTechnologySpecificInfo> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 20,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.radio.V1_6.RegStateResult.AccessTechnologySpecificInfo _hidl_vec_element = new android.hardware.radio.V1_6.RegStateResult.AccessTechnologySpecificInfo();
                    ((android.hardware.radio.V1_6.RegStateResult.AccessTechnologySpecificInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 20);
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
                    ((android.hidl.safe_union.V1_0.Monostate) hidl_o).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 4);
                    break;
                }
                case hidl_discriminator.cdmaInfo: {
                    hidl_o = new android.hardware.radio.V1_5.RegStateResult.AccessTechnologySpecificInfo.Cdma2000RegistrationInfo();
                    ((android.hardware.radio.V1_5.RegStateResult.AccessTechnologySpecificInfo.Cdma2000RegistrationInfo) hidl_o).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 4);
                    break;
                }
                case hidl_discriminator.eutranInfo: {
                    hidl_o = new android.hardware.radio.V1_5.RegStateResult.AccessTechnologySpecificInfo.EutranRegistrationInfo();
                    ((android.hardware.radio.V1_5.RegStateResult.AccessTechnologySpecificInfo.EutranRegistrationInfo) hidl_o).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 4);
                    break;
                }
                case hidl_discriminator.ngranNrVopsInfo: {
                    hidl_o = new android.hardware.radio.V1_6.NrVopsInfo();
                    ((android.hardware.radio.V1_6.NrVopsInfo) hidl_o).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 4);
                    break;
                }
                case hidl_discriminator.geranDtmSupported: {
                    hidl_o = false;
                    hidl_o = _hidl_blob.getBool(_hidl_offset + 4);
                    break;
                }
                default: {
                    throw new IllegalStateException("Unknown union discriminator (value: " + hidl_d + ").");
                }
            }
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(20 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<AccessTechnologySpecificInfo> _hidl_vec) {
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
            _hidl_blob.putInt8(_hidl_offset + 0, hidl_d);
            switch (this.hidl_d) {
                case hidl_discriminator.noinit: {
                    noinit().writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 4);
                    break;
                }
                case hidl_discriminator.cdmaInfo: {
                    cdmaInfo().writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 4);
                    break;
                }
                case hidl_discriminator.eutranInfo: {
                    eutranInfo().writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 4);
                    break;
                }
                case hidl_discriminator.ngranNrVopsInfo: {
                    ngranNrVopsInfo().writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 4);
                    break;
                }
                case hidl_discriminator.geranDtmSupported: {
                    _hidl_blob.putBool(_hidl_offset + 4, geranDtmSupported());
                    break;
                }
                default: {
                    throw new Error("Unknown union discriminator (value: " + hidl_d + ").");
                }
            }
        }
    };

    /**
     * Registration state
     *
     * If the RAT is indicated as a GERAN, UTRAN, or CDMA2000 technology, this value reports
     * registration in the Circuit-switched domain.
     * If the RAT is indicated as an EUTRAN, NGRAN, or another technology that does not support
     * circuit-switched services, this value reports registration in the Packet-switched domain.
     */
    public int regState = 0;
    /**
     * Indicates the available voice radio technology, valid values as defined by RadioTechnology,
     * except LTE_CA, which is no longer a valid value on 1.5 or above. When the device is on
     * carrier aggregation, vendor RIL service should properly report multiple PhysicalChannelConfig
     * elements through IRadio::currentPhysicalChannelConfigs_1_6.
     */
    public int rat = 0;
    /**
     * Cause code reported by the network in case registration fails. This will be a mobility
     * management cause code defined for MM, GMM, MME or equivalent as appropriate for the RAT.
     */
    public int reasonForDenial = 0;
    /**
     * CellIdentity
     */
    public android.hardware.radio.V1_5.CellIdentity cellIdentity = new android.hardware.radio.V1_5.CellIdentity();
    /**
     * The most-recent PLMN-ID upon which the UE registered (or attempted to register if a failure
     * is reported in the reasonForDenial field). This PLMN shall be in standard format consisting
     * of a 3 digit MCC concatenated with a 2 or 3 digit MNC.
     */
    public String registeredPlmn = new String();
    /**
     * Access-technology-specific registration information, such as for CDMA2000.
     */
    public android.hardware.radio.V1_6.RegStateResult.AccessTechnologySpecificInfo accessTechnologySpecificInfo = new android.hardware.radio.V1_6.RegStateResult.AccessTechnologySpecificInfo();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_6.RegStateResult.class) {
            return false;
        }
        android.hardware.radio.V1_6.RegStateResult other = (android.hardware.radio.V1_6.RegStateResult)otherObject;
        if (this.regState != other.regState) {
            return false;
        }
        if (this.rat != other.rat) {
            return false;
        }
        if (this.reasonForDenial != other.reasonForDenial) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.cellIdentity, other.cellIdentity)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.registeredPlmn, other.registeredPlmn)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.accessTechnologySpecificInfo, other.accessTechnologySpecificInfo)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.regState), 
                android.os.HidlSupport.deepHashCode(this.rat), 
                android.os.HidlSupport.deepHashCode(this.reasonForDenial), 
                android.os.HidlSupport.deepHashCode(this.cellIdentity), 
                android.os.HidlSupport.deepHashCode(this.registeredPlmn), 
                android.os.HidlSupport.deepHashCode(this.accessTechnologySpecificInfo));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".regState = ");
        builder.append(android.hardware.radio.V1_0.RegState.toString(this.regState));
        builder.append(", .rat = ");
        builder.append(android.hardware.radio.V1_4.RadioTechnology.toString(this.rat));
        builder.append(", .reasonForDenial = ");
        builder.append(android.hardware.radio.V1_5.RegistrationFailCause.toString(this.reasonForDenial));
        builder.append(", .cellIdentity = ");
        builder.append(this.cellIdentity);
        builder.append(", .registeredPlmn = ");
        builder.append(this.registeredPlmn);
        builder.append(", .accessTechnologySpecificInfo = ");
        builder.append(this.accessTechnologySpecificInfo);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(224 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<RegStateResult> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<RegStateResult> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 224,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_6.RegStateResult _hidl_vec_element = new android.hardware.radio.V1_6.RegStateResult();
                ((android.hardware.radio.V1_6.RegStateResult) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 224);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        regState = _hidl_blob.getInt32(_hidl_offset + 0);
        rat = _hidl_blob.getInt32(_hidl_offset + 4);
        reasonForDenial = _hidl_blob.getInt32(_hidl_offset + 8);
        ((android.hardware.radio.V1_5.CellIdentity) cellIdentity).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 16);
        registeredPlmn = _hidl_blob.getString(_hidl_offset + 184);

        parcel.readEmbeddedBuffer(
                ((String) registeredPlmn).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 184 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        ((android.hardware.radio.V1_6.RegStateResult.AccessTechnologySpecificInfo) accessTechnologySpecificInfo).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 200);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(224 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<RegStateResult> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 224));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 224);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, regState);
        _hidl_blob.putInt32(_hidl_offset + 4, rat);
        _hidl_blob.putInt32(_hidl_offset + 8, reasonForDenial);
        cellIdentity.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 16);
        _hidl_blob.putString(_hidl_offset + 184, registeredPlmn);
        accessTechnologySpecificInfo.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 200);
    }
};

