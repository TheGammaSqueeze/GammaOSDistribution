package android.hardware.radio.V1_6;


public final class PhysicalChannelConfig {
    public final static class Band {
        public Band() {
            hidl_o = 0;
        }

        public static final class hidl_discriminator {
            /**
             * Valid only if radioAccessNetwork = GERAN.
             */
            public static final byte geranBand = 0;  // int
            /**
             * Valid only if radioAccessNetwork = UTRAN.
             */
            public static final byte utranBand = 1;  // int
            /**
             * Valid only if radioAccessNetwork = EUTRAN.
             */
            public static final byte eutranBand = 2;  // int
            /**
             * Valid only if radioAccessNetwork = NGRAN.
             */
            public static final byte ngranBand = 3;  // int

            public static final String getName(byte value) {
                switch (value) {
                    case 0: { return "geranBand"; }
                    case 1: { return "utranBand"; }
                    case 2: { return "eutranBand"; }
                    case 3: { return "ngranBand"; }
                    default: { return "Unknown"; }
                }
            }

            private hidl_discriminator() {}
        }

        private byte hidl_d = 0;
        private Object hidl_o = null;
        public void geranBand(int geranBand) {
            hidl_d = hidl_discriminator.geranBand;
            hidl_o = geranBand;
        }

        public int geranBand() {
            if (hidl_d != hidl_discriminator.geranBand) {
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

        public void utranBand(int utranBand) {
            hidl_d = hidl_discriminator.utranBand;
            hidl_o = utranBand;
        }

        public int utranBand() {
            if (hidl_d != hidl_discriminator.utranBand) {
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

        public void eutranBand(int eutranBand) {
            hidl_d = hidl_discriminator.eutranBand;
            hidl_o = eutranBand;
        }

        public int eutranBand() {
            if (hidl_d != hidl_discriminator.eutranBand) {
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

        public void ngranBand(int ngranBand) {
            hidl_d = hidl_discriminator.ngranBand;
            hidl_o = ngranBand;
        }

        public int ngranBand() {
            if (hidl_d != hidl_discriminator.ngranBand) {
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
            if (otherObject.getClass() != android.hardware.radio.V1_6.PhysicalChannelConfig.Band.class) {
                return false;
            }
            android.hardware.radio.V1_6.PhysicalChannelConfig.Band other = (android.hardware.radio.V1_6.PhysicalChannelConfig.Band)otherObject;
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
                case hidl_discriminator.geranBand: {
                    builder.append(".geranBand = ");
                    builder.append(android.hardware.radio.V1_1.GeranBands.toString(this.geranBand()));
                    break;
                }
                case hidl_discriminator.utranBand: {
                    builder.append(".utranBand = ");
                    builder.append(android.hardware.radio.V1_1.UtranBands.toString(this.utranBand()));
                    break;
                }
                case hidl_discriminator.eutranBand: {
                    builder.append(".eutranBand = ");
                    builder.append(android.hardware.radio.V1_1.EutranBands.toString(this.eutranBand()));
                    break;
                }
                case hidl_discriminator.ngranBand: {
                    builder.append(".ngranBand = ");
                    builder.append(android.hardware.radio.V1_6.NgranBands.toString(this.ngranBand()));
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

        public static final java.util.ArrayList<Band> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<Band> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 8,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.radio.V1_6.PhysicalChannelConfig.Band _hidl_vec_element = new android.hardware.radio.V1_6.PhysicalChannelConfig.Band();
                    ((android.hardware.radio.V1_6.PhysicalChannelConfig.Band) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 8);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            hidl_d = _hidl_blob.getInt8(_hidl_offset + 0);
            switch (this.hidl_d) {
                case hidl_discriminator.geranBand: {
                    hidl_o = 0;
                    hidl_o = _hidl_blob.getInt32(_hidl_offset + 4);
                    break;
                }
                case hidl_discriminator.utranBand: {
                    hidl_o = 0;
                    hidl_o = _hidl_blob.getInt32(_hidl_offset + 4);
                    break;
                }
                case hidl_discriminator.eutranBand: {
                    hidl_o = 0;
                    hidl_o = _hidl_blob.getInt32(_hidl_offset + 4);
                    break;
                }
                case hidl_discriminator.ngranBand: {
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
                android.os.HwParcel parcel, java.util.ArrayList<Band> _hidl_vec) {
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
                case hidl_discriminator.geranBand: {
                    _hidl_blob.putInt32(_hidl_offset + 4, geranBand());
                    break;
                }
                case hidl_discriminator.utranBand: {
                    _hidl_blob.putInt32(_hidl_offset + 4, utranBand());
                    break;
                }
                case hidl_discriminator.eutranBand: {
                    _hidl_blob.putInt32(_hidl_offset + 4, eutranBand());
                    break;
                }
                case hidl_discriminator.ngranBand: {
                    _hidl_blob.putInt32(_hidl_offset + 4, ngranBand());
                    break;
                }
                default: {
                    throw new Error("Unknown union discriminator (value: " + hidl_d + ").");
                }
            }
        }
    };

    /**
     * Connection status for cell. Valid values are PRIMARY_SERVING and SECONDARY_SERVING
     */
    public int status = 0;
    /**
     * The radio technology for this physical channel
     */
    public int rat = 0;
    /**
     * Downlink Absolute Radio Frequency Channel Number
     */
    public int downlinkChannelNumber = 0;
    /**
     * Uplink Absolute Radio Frequency Channel Number
     */
    public int uplinkChannelNumber = 0;
    /**
     * Downlink cell bandwidth, in kHz
     */
    public int cellBandwidthDownlinkKhz = 0;
    /**
     * Uplink cell bandwidth, in kHz
     */
    public int cellBandwidthUplinkKhz = 0;
    /**
     * A list of data calls mapped to this physical channel. The context id must match the cid of
     * @1.5::SetupDataCallResult. An empty list means the physical channel has no data call mapped
     * to it.
     */
    public java.util.ArrayList<Integer> contextIds = new java.util.ArrayList<Integer>();
    /**
     * The physical cell identifier for this cell.
     *
     * In UTRAN, this value is primary scrambling code. The range is [0, 511].
     * Reference: 3GPP TS 25.213 section 5.2.2.
     *
     * In EUTRAN, this value is physical layer cell identity. The range is [0, 503].
     * Reference: 3GPP TS 36.211 section 6.11.
     *
     * In 5G RAN, this value is physical layer cell identity. The range is [0, 1007].
     * Reference: 3GPP TS 38.211 section 7.4.2.1.
     */
    public int physicalCellId = 0;
    /**
     * The frequency band to scan.
     */
    public android.hardware.radio.V1_6.PhysicalChannelConfig.Band band = new android.hardware.radio.V1_6.PhysicalChannelConfig.Band();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_6.PhysicalChannelConfig.class) {
            return false;
        }
        android.hardware.radio.V1_6.PhysicalChannelConfig other = (android.hardware.radio.V1_6.PhysicalChannelConfig)otherObject;
        if (this.status != other.status) {
            return false;
        }
        if (this.rat != other.rat) {
            return false;
        }
        if (this.downlinkChannelNumber != other.downlinkChannelNumber) {
            return false;
        }
        if (this.uplinkChannelNumber != other.uplinkChannelNumber) {
            return false;
        }
        if (this.cellBandwidthDownlinkKhz != other.cellBandwidthDownlinkKhz) {
            return false;
        }
        if (this.cellBandwidthUplinkKhz != other.cellBandwidthUplinkKhz) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.contextIds, other.contextIds)) {
            return false;
        }
        if (this.physicalCellId != other.physicalCellId) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.band, other.band)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.status), 
                android.os.HidlSupport.deepHashCode(this.rat), 
                android.os.HidlSupport.deepHashCode(this.downlinkChannelNumber), 
                android.os.HidlSupport.deepHashCode(this.uplinkChannelNumber), 
                android.os.HidlSupport.deepHashCode(this.cellBandwidthDownlinkKhz), 
                android.os.HidlSupport.deepHashCode(this.cellBandwidthUplinkKhz), 
                android.os.HidlSupport.deepHashCode(this.contextIds), 
                android.os.HidlSupport.deepHashCode(this.physicalCellId), 
                android.os.HidlSupport.deepHashCode(this.band));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".status = ");
        builder.append(android.hardware.radio.V1_2.CellConnectionStatus.toString(this.status));
        builder.append(", .rat = ");
        builder.append(android.hardware.radio.V1_4.RadioTechnology.toString(this.rat));
        builder.append(", .downlinkChannelNumber = ");
        builder.append(this.downlinkChannelNumber);
        builder.append(", .uplinkChannelNumber = ");
        builder.append(this.uplinkChannelNumber);
        builder.append(", .cellBandwidthDownlinkKhz = ");
        builder.append(this.cellBandwidthDownlinkKhz);
        builder.append(", .cellBandwidthUplinkKhz = ");
        builder.append(this.cellBandwidthUplinkKhz);
        builder.append(", .contextIds = ");
        builder.append(this.contextIds);
        builder.append(", .physicalCellId = ");
        builder.append(this.physicalCellId);
        builder.append(", .band = ");
        builder.append(this.band);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(56 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<PhysicalChannelConfig> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<PhysicalChannelConfig> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 56,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_6.PhysicalChannelConfig _hidl_vec_element = new android.hardware.radio.V1_6.PhysicalChannelConfig();
                ((android.hardware.radio.V1_6.PhysicalChannelConfig) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 56);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        status = _hidl_blob.getInt32(_hidl_offset + 0);
        rat = _hidl_blob.getInt32(_hidl_offset + 4);
        downlinkChannelNumber = _hidl_blob.getInt32(_hidl_offset + 8);
        uplinkChannelNumber = _hidl_blob.getInt32(_hidl_offset + 12);
        cellBandwidthDownlinkKhz = _hidl_blob.getInt32(_hidl_offset + 16);
        cellBandwidthUplinkKhz = _hidl_blob.getInt32(_hidl_offset + 20);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 24 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 4,_hidl_blob.handle(),
                    _hidl_offset + 24 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<Integer>) contextIds).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                int _hidl_vec_element = 0;
                _hidl_vec_element = childBlob.getInt32(_hidl_index_0 * 4);
                ((java.util.ArrayList<Integer>) contextIds).add(_hidl_vec_element);
            }
        }
        physicalCellId = _hidl_blob.getInt32(_hidl_offset + 40);
        ((android.hardware.radio.V1_6.PhysicalChannelConfig.Band) band).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 44);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(56 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<PhysicalChannelConfig> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 56));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 56);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, status);
        _hidl_blob.putInt32(_hidl_offset + 4, rat);
        _hidl_blob.putInt32(_hidl_offset + 8, downlinkChannelNumber);
        _hidl_blob.putInt32(_hidl_offset + 12, uplinkChannelNumber);
        _hidl_blob.putInt32(_hidl_offset + 16, cellBandwidthDownlinkKhz);
        _hidl_blob.putInt32(_hidl_offset + 20, cellBandwidthUplinkKhz);
        {
            int _hidl_vec_size = contextIds.size();
            _hidl_blob.putInt32(_hidl_offset + 24 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 24 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 4));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putInt32(_hidl_index_0 * 4, contextIds.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 24 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        _hidl_blob.putInt32(_hidl_offset + 40, physicalCellId);
        band.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 44);
    }
};

