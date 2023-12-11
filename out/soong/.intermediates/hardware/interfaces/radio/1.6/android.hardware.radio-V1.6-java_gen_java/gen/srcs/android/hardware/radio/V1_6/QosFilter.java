package android.hardware.radio.V1_6;


public final class QosFilter {
    public final static class TypeOfService {
        public TypeOfService() {
            hidl_o = new android.hidl.safe_union.V1_0.Monostate();
        }

        public static final class hidl_discriminator {
            public static final byte noinit = 0;  // android.hidl.safe_union.V1_0.Monostate
            public static final byte value = 1;  // byte

            public static final String getName(byte value) {
                switch (value) {
                    case 0: { return "noinit"; }
                    case 1: { return "value"; }
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

        public void value(byte value) {
            hidl_d = hidl_discriminator.value;
            hidl_o = value;
        }

        public byte value() {
            if (hidl_d != hidl_discriminator.value) {
                String className = (hidl_o != null) ? hidl_o.getClass().getName() : "null";
                throw new IllegalStateException(
                        "Read access to inactive union components is disallowed. " +
                        "Discriminator value is " + hidl_d + " (corresponding " +
                        "to " + hidl_discriminator.getName(hidl_d) + "), and " +
                        "hidl_o is of type " + className + ".");
            }
            if (hidl_o != null && !Byte.class.isInstance(hidl_o)) {
                throw new Error("Union is in a corrupted state.");
            }
            return ((byte) hidl_o);
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
            if (otherObject.getClass() != android.hardware.radio.V1_6.QosFilter.TypeOfService.class) {
                return false;
            }
            android.hardware.radio.V1_6.QosFilter.TypeOfService other = (android.hardware.radio.V1_6.QosFilter.TypeOfService)otherObject;
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
                case hidl_discriminator.value: {
                    builder.append(".value = ");
                    builder.append(this.value());
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
            android.os.HwBlob blob = parcel.readBuffer(2 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<TypeOfService> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<TypeOfService> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 2,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.radio.V1_6.QosFilter.TypeOfService _hidl_vec_element = new android.hardware.radio.V1_6.QosFilter.TypeOfService();
                    ((android.hardware.radio.V1_6.QosFilter.TypeOfService) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 2);
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
                    ((android.hidl.safe_union.V1_0.Monostate) hidl_o).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 1);
                    break;
                }
                case hidl_discriminator.value: {
                    hidl_o = 0;
                    hidl_o = _hidl_blob.getInt8(_hidl_offset + 1);
                    break;
                }
                default: {
                    throw new IllegalStateException("Unknown union discriminator (value: " + hidl_d + ").");
                }
            }
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(2 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<TypeOfService> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 2));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 2);
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
                    noinit().writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 1);
                    break;
                }
                case hidl_discriminator.value: {
                    _hidl_blob.putInt8(_hidl_offset + 1, value());
                    break;
                }
                default: {
                    throw new Error("Unknown union discriminator (value: " + hidl_d + ").");
                }
            }
        }
    };

    public final static class Ipv6FlowLabel {
        public Ipv6FlowLabel() {
            hidl_o = new android.hidl.safe_union.V1_0.Monostate();
        }

        public static final class hidl_discriminator {
            public static final byte noinit = 0;  // android.hidl.safe_union.V1_0.Monostate
            public static final byte value = 1;  // int

            public static final String getName(byte value) {
                switch (value) {
                    case 0: { return "noinit"; }
                    case 1: { return "value"; }
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

        public void value(int value) {
            hidl_d = hidl_discriminator.value;
            hidl_o = value;
        }

        public int value() {
            if (hidl_d != hidl_discriminator.value) {
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
            if (otherObject.getClass() != android.hardware.radio.V1_6.QosFilter.Ipv6FlowLabel.class) {
                return false;
            }
            android.hardware.radio.V1_6.QosFilter.Ipv6FlowLabel other = (android.hardware.radio.V1_6.QosFilter.Ipv6FlowLabel)otherObject;
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
                case hidl_discriminator.value: {
                    builder.append(".value = ");
                    builder.append(this.value());
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

        public static final java.util.ArrayList<Ipv6FlowLabel> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<Ipv6FlowLabel> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 8,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.radio.V1_6.QosFilter.Ipv6FlowLabel _hidl_vec_element = new android.hardware.radio.V1_6.QosFilter.Ipv6FlowLabel();
                    ((android.hardware.radio.V1_6.QosFilter.Ipv6FlowLabel) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 8);
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
                case hidl_discriminator.value: {
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
                android.os.HwParcel parcel, java.util.ArrayList<Ipv6FlowLabel> _hidl_vec) {
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
                case hidl_discriminator.noinit: {
                    noinit().writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 4);
                    break;
                }
                case hidl_discriminator.value: {
                    _hidl_blob.putInt32(_hidl_offset + 4, value());
                    break;
                }
                default: {
                    throw new Error("Unknown union discriminator (value: " + hidl_d + ").");
                }
            }
        }
    };

    public final static class IpsecSpi {
        public IpsecSpi() {
            hidl_o = new android.hidl.safe_union.V1_0.Monostate();
        }

        public static final class hidl_discriminator {
            public static final byte noinit = 0;  // android.hidl.safe_union.V1_0.Monostate
            public static final byte value = 1;  // int

            public static final String getName(byte value) {
                switch (value) {
                    case 0: { return "noinit"; }
                    case 1: { return "value"; }
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

        public void value(int value) {
            hidl_d = hidl_discriminator.value;
            hidl_o = value;
        }

        public int value() {
            if (hidl_d != hidl_discriminator.value) {
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
            if (otherObject.getClass() != android.hardware.radio.V1_6.QosFilter.IpsecSpi.class) {
                return false;
            }
            android.hardware.radio.V1_6.QosFilter.IpsecSpi other = (android.hardware.radio.V1_6.QosFilter.IpsecSpi)otherObject;
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
                case hidl_discriminator.value: {
                    builder.append(".value = ");
                    builder.append(this.value());
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

        public static final java.util.ArrayList<IpsecSpi> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<IpsecSpi> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 8,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.radio.V1_6.QosFilter.IpsecSpi _hidl_vec_element = new android.hardware.radio.V1_6.QosFilter.IpsecSpi();
                    ((android.hardware.radio.V1_6.QosFilter.IpsecSpi) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 8);
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
                case hidl_discriminator.value: {
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
                android.os.HwParcel parcel, java.util.ArrayList<IpsecSpi> _hidl_vec) {
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
                case hidl_discriminator.noinit: {
                    noinit().writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 4);
                    break;
                }
                case hidl_discriminator.value: {
                    _hidl_blob.putInt32(_hidl_offset + 4, value());
                    break;
                }
                default: {
                    throw new Error("Unknown union discriminator (value: " + hidl_d + ").");
                }
            }
        }
    };

    /**
     * Local and remote IP addresses, typically one IPv4 or one IPv6
     * or one of each. Addresses could be with optional "/" prefix
     * length, e.g.,"192.0.1.3" or "192.0.1.11/16 2001:db8::1/64".
     * If the prefix length is absent the addresses are assumed to be
     * point to point with IPv4 having a prefix length of 32 and
     * IPv6 128.
     */
    public java.util.ArrayList<String> localAddresses = new java.util.ArrayList<String>();
    public java.util.ArrayList<String> remoteAddresses = new java.util.ArrayList<String>();
    /**
     * Local and remote port/ranges
     */
    public android.hardware.radio.V1_6.MaybePort localPort = new android.hardware.radio.V1_6.MaybePort();
    public android.hardware.radio.V1_6.MaybePort remotePort = new android.hardware.radio.V1_6.MaybePort();
    /**
     * QoS protocol
     */
    public byte protocol = 0;
    /**
     * Type of service value or mask as defined in RFC 1349
     */
    public android.hardware.radio.V1_6.QosFilter.TypeOfService tos = new android.hardware.radio.V1_6.QosFilter.TypeOfService();
    /**
     * IPv6 flow label as defined in RFC 6437
     */
    public android.hardware.radio.V1_6.QosFilter.Ipv6FlowLabel flowLabel = new android.hardware.radio.V1_6.QosFilter.Ipv6FlowLabel();
    /**
     * IPSec security parameter index
     */
    public android.hardware.radio.V1_6.QosFilter.IpsecSpi spi = new android.hardware.radio.V1_6.QosFilter.IpsecSpi();
    /**
     * Filter direction
     */
    public byte direction = 0;
    /**
     * Specifies the order in which the filter needs to be matched.
     * A lower numerical(positive) value has a higher precedence.
     * Set -1 when unspecified.
     */
    public int precedence = 0;

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_6.QosFilter.class) {
            return false;
        }
        android.hardware.radio.V1_6.QosFilter other = (android.hardware.radio.V1_6.QosFilter)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.localAddresses, other.localAddresses)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.remoteAddresses, other.remoteAddresses)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.localPort, other.localPort)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.remotePort, other.remotePort)) {
            return false;
        }
        if (this.protocol != other.protocol) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.tos, other.tos)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.flowLabel, other.flowLabel)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.spi, other.spi)) {
            return false;
        }
        if (this.direction != other.direction) {
            return false;
        }
        if (this.precedence != other.precedence) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.localAddresses), 
                android.os.HidlSupport.deepHashCode(this.remoteAddresses), 
                android.os.HidlSupport.deepHashCode(this.localPort), 
                android.os.HidlSupport.deepHashCode(this.remotePort), 
                android.os.HidlSupport.deepHashCode(this.protocol), 
                android.os.HidlSupport.deepHashCode(this.tos), 
                android.os.HidlSupport.deepHashCode(this.flowLabel), 
                android.os.HidlSupport.deepHashCode(this.spi), 
                android.os.HidlSupport.deepHashCode(this.direction), 
                android.os.HidlSupport.deepHashCode(this.precedence));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".localAddresses = ");
        builder.append(this.localAddresses);
        builder.append(", .remoteAddresses = ");
        builder.append(this.remoteAddresses);
        builder.append(", .localPort = ");
        builder.append(this.localPort);
        builder.append(", .remotePort = ");
        builder.append(this.remotePort);
        builder.append(", .protocol = ");
        builder.append(android.hardware.radio.V1_6.QosProtocol.toString(this.protocol));
        builder.append(", .tos = ");
        builder.append(this.tos);
        builder.append(", .flowLabel = ");
        builder.append(this.flowLabel);
        builder.append(", .spi = ");
        builder.append(this.spi);
        builder.append(", .direction = ");
        builder.append(android.hardware.radio.V1_6.QosFilterDirection.toString(this.direction));
        builder.append(", .precedence = ");
        builder.append(this.precedence);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(88 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<QosFilter> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<QosFilter> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 88,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_6.QosFilter _hidl_vec_element = new android.hardware.radio.V1_6.QosFilter();
                ((android.hardware.radio.V1_6.QosFilter) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 88);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 16,_hidl_blob.handle(),
                    _hidl_offset + 0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<String>) localAddresses).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                String _hidl_vec_element = new String();
                _hidl_vec_element = childBlob.getString(_hidl_index_0 * 16);

                parcel.readEmbeddedBuffer(
                        ((String) _hidl_vec_element).getBytes().length + 1,
                        childBlob.handle(),
                        _hidl_index_0 * 16 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

                ((java.util.ArrayList<String>) localAddresses).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 16,_hidl_blob.handle(),
                    _hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<String>) remoteAddresses).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                String _hidl_vec_element = new String();
                _hidl_vec_element = childBlob.getString(_hidl_index_0 * 16);

                parcel.readEmbeddedBuffer(
                        ((String) _hidl_vec_element).getBytes().length + 1,
                        childBlob.handle(),
                        _hidl_index_0 * 16 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

                ((java.util.ArrayList<String>) remoteAddresses).add(_hidl_vec_element);
            }
        }
        ((android.hardware.radio.V1_6.MaybePort) localPort).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 32);
        ((android.hardware.radio.V1_6.MaybePort) remotePort).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 44);
        protocol = _hidl_blob.getInt8(_hidl_offset + 56);
        ((android.hardware.radio.V1_6.QosFilter.TypeOfService) tos).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 57);
        ((android.hardware.radio.V1_6.QosFilter.Ipv6FlowLabel) flowLabel).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 60);
        ((android.hardware.radio.V1_6.QosFilter.IpsecSpi) spi).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 68);
        direction = _hidl_blob.getInt8(_hidl_offset + 76);
        precedence = _hidl_blob.getInt32(_hidl_offset + 80);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(88 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<QosFilter> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 88));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 88);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        {
            int _hidl_vec_size = localAddresses.size();
            _hidl_blob.putInt32(_hidl_offset + 0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 16));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putString(_hidl_index_0 * 16, localAddresses.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = remoteAddresses.size();
            _hidl_blob.putInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 16 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 16));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                childBlob.putString(_hidl_index_0 * 16, remoteAddresses.get(_hidl_index_0));
            }
            _hidl_blob.putBlob(_hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        localPort.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 32);
        remotePort.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 44);
        _hidl_blob.putInt8(_hidl_offset + 56, protocol);
        tos.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 57);
        flowLabel.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 60);
        spi.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 68);
        _hidl_blob.putInt8(_hidl_offset + 76, direction);
        _hidl_blob.putInt32(_hidl_offset + 80, precedence);
    }
};

