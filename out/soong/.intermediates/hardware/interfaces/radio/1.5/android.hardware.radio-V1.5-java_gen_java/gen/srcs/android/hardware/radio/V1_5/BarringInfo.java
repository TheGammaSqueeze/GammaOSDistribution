package android.hardware.radio.V1_5;


public final class BarringInfo {
    public static final class ServiceType {
        /**
         * Applicable to UTRAN
         *
         *
         * Barring for all CS services, including registration
         */
        public static final int CS_SERVICE = 0;
        /**
         * Barring for all PS services, including registration
         */
        public static final int PS_SERVICE = 1 /* ::android::hardware::radio::V1_5::BarringInfo::ServiceType.CS_SERVICE implicitly + 1 */;
        /**
         * Barring for mobile-originated circuit-switched voice calls
         */
        public static final int CS_VOICE = 2 /* ::android::hardware::radio::V1_5::BarringInfo::ServiceType.PS_SERVICE implicitly + 1 */;
        /**
         * Applicable to EUTRAN, NGRAN
         *
         *
         * Barring for mobile-originated signalling for any purpose
         */
        public static final int MO_SIGNALLING = 3 /* ::android::hardware::radio::V1_5::BarringInfo::ServiceType.CS_VOICE implicitly + 1 */;
        /**
         * Barring for mobile-originated internet or other interactive data
         */
        public static final int MO_DATA = 4 /* ::android::hardware::radio::V1_5::BarringInfo::ServiceType.MO_SIGNALLING implicitly + 1 */;
        /**
         * Barring for circuit-switched fallback calling
         */
        public static final int CS_FALLBACK = 5 /* ::android::hardware::radio::V1_5::BarringInfo::ServiceType.MO_DATA implicitly + 1 */;
        /**
         * Barring for IMS voice calling
         */
        public static final int MMTEL_VOICE = 6 /* ::android::hardware::radio::V1_5::BarringInfo::ServiceType.CS_FALLBACK implicitly + 1 */;
        /**
         * Barring for IMS video calling
         */
        public static final int MMTEL_VIDEO = 7 /* ::android::hardware::radio::V1_5::BarringInfo::ServiceType.MMTEL_VOICE implicitly + 1 */;
        /**
         * Applicable to UTRAN, EUTRAN, NGRAN
         *
         *
         * Barring for emergency services, either CS or emergency MMTEL
         */
        public static final int EMERGENCY = 8 /* ::android::hardware::radio::V1_5::BarringInfo::ServiceType.MMTEL_VIDEO implicitly + 1 */;
        /**
         * Barring for short message services
         */
        public static final int SMS = 9 /* ::android::hardware::radio::V1_5::BarringInfo::ServiceType.EMERGENCY implicitly + 1 */;
        /**
         * Operator-specific barring codes; applicable to NGRAN
         */
        public static final int OPERATOR_1 = 1001;
        public static final int OPERATOR_2 = 1002;
        public static final int OPERATOR_3 = 1003;
        public static final int OPERATOR_4 = 1004;
        public static final int OPERATOR_5 = 1005;
        public static final int OPERATOR_6 = 1006;
        public static final int OPERATOR_7 = 1007;
        public static final int OPERATOR_8 = 1008;
        public static final int OPERATOR_9 = 1009;
        public static final int OPERATOR_10 = 1010;
        public static final int OPERATOR_11 = 1011;
        public static final int OPERATOR_12 = 1012;
        public static final int OPERATOR_13 = 1013;
        public static final int OPERATOR_14 = 1014;
        public static final int OPERATOR_15 = 1015;
        public static final int OPERATOR_16 = 1016;
        public static final int OPERATOR_17 = 1017;
        public static final int OPERATOR_18 = 1018;
        public static final int OPERATOR_19 = 1019;
        public static final int OPERATOR_20 = 1020;
        public static final int OPERATOR_21 = 1021;
        public static final int OPERATOR_22 = 1022;
        public static final int OPERATOR_23 = 1023;
        public static final int OPERATOR_24 = 1024;
        public static final int OPERATOR_25 = 1025;
        public static final int OPERATOR_26 = 1026;
        public static final int OPERATOR_27 = 1027;
        public static final int OPERATOR_28 = 1028;
        public static final int OPERATOR_29 = 1029;
        public static final int OPERATOR_30 = 1030;
        public static final int OPERATOR_31 = 1031;
        public static final int OPERATOR_32 = 1032;
        public static final String toString(int o) {
            if (o == CS_SERVICE) {
                return "CS_SERVICE";
            }
            if (o == PS_SERVICE) {
                return "PS_SERVICE";
            }
            if (o == CS_VOICE) {
                return "CS_VOICE";
            }
            if (o == MO_SIGNALLING) {
                return "MO_SIGNALLING";
            }
            if (o == MO_DATA) {
                return "MO_DATA";
            }
            if (o == CS_FALLBACK) {
                return "CS_FALLBACK";
            }
            if (o == MMTEL_VOICE) {
                return "MMTEL_VOICE";
            }
            if (o == MMTEL_VIDEO) {
                return "MMTEL_VIDEO";
            }
            if (o == EMERGENCY) {
                return "EMERGENCY";
            }
            if (o == SMS) {
                return "SMS";
            }
            if (o == OPERATOR_1) {
                return "OPERATOR_1";
            }
            if (o == OPERATOR_2) {
                return "OPERATOR_2";
            }
            if (o == OPERATOR_3) {
                return "OPERATOR_3";
            }
            if (o == OPERATOR_4) {
                return "OPERATOR_4";
            }
            if (o == OPERATOR_5) {
                return "OPERATOR_5";
            }
            if (o == OPERATOR_6) {
                return "OPERATOR_6";
            }
            if (o == OPERATOR_7) {
                return "OPERATOR_7";
            }
            if (o == OPERATOR_8) {
                return "OPERATOR_8";
            }
            if (o == OPERATOR_9) {
                return "OPERATOR_9";
            }
            if (o == OPERATOR_10) {
                return "OPERATOR_10";
            }
            if (o == OPERATOR_11) {
                return "OPERATOR_11";
            }
            if (o == OPERATOR_12) {
                return "OPERATOR_12";
            }
            if (o == OPERATOR_13) {
                return "OPERATOR_13";
            }
            if (o == OPERATOR_14) {
                return "OPERATOR_14";
            }
            if (o == OPERATOR_15) {
                return "OPERATOR_15";
            }
            if (o == OPERATOR_16) {
                return "OPERATOR_16";
            }
            if (o == OPERATOR_17) {
                return "OPERATOR_17";
            }
            if (o == OPERATOR_18) {
                return "OPERATOR_18";
            }
            if (o == OPERATOR_19) {
                return "OPERATOR_19";
            }
            if (o == OPERATOR_20) {
                return "OPERATOR_20";
            }
            if (o == OPERATOR_21) {
                return "OPERATOR_21";
            }
            if (o == OPERATOR_22) {
                return "OPERATOR_22";
            }
            if (o == OPERATOR_23) {
                return "OPERATOR_23";
            }
            if (o == OPERATOR_24) {
                return "OPERATOR_24";
            }
            if (o == OPERATOR_25) {
                return "OPERATOR_25";
            }
            if (o == OPERATOR_26) {
                return "OPERATOR_26";
            }
            if (o == OPERATOR_27) {
                return "OPERATOR_27";
            }
            if (o == OPERATOR_28) {
                return "OPERATOR_28";
            }
            if (o == OPERATOR_29) {
                return "OPERATOR_29";
            }
            if (o == OPERATOR_30) {
                return "OPERATOR_30";
            }
            if (o == OPERATOR_31) {
                return "OPERATOR_31";
            }
            if (o == OPERATOR_32) {
                return "OPERATOR_32";
            }
            return "0x" + Integer.toHexString(o);
        }

        public static final String dumpBitfield(int o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            int flipped = 0;
            list.add("CS_SERVICE"); // CS_SERVICE == 0
            if ((o & PS_SERVICE) == PS_SERVICE) {
                list.add("PS_SERVICE");
                flipped |= PS_SERVICE;
            }
            if ((o & CS_VOICE) == CS_VOICE) {
                list.add("CS_VOICE");
                flipped |= CS_VOICE;
            }
            if ((o & MO_SIGNALLING) == MO_SIGNALLING) {
                list.add("MO_SIGNALLING");
                flipped |= MO_SIGNALLING;
            }
            if ((o & MO_DATA) == MO_DATA) {
                list.add("MO_DATA");
                flipped |= MO_DATA;
            }
            if ((o & CS_FALLBACK) == CS_FALLBACK) {
                list.add("CS_FALLBACK");
                flipped |= CS_FALLBACK;
            }
            if ((o & MMTEL_VOICE) == MMTEL_VOICE) {
                list.add("MMTEL_VOICE");
                flipped |= MMTEL_VOICE;
            }
            if ((o & MMTEL_VIDEO) == MMTEL_VIDEO) {
                list.add("MMTEL_VIDEO");
                flipped |= MMTEL_VIDEO;
            }
            if ((o & EMERGENCY) == EMERGENCY) {
                list.add("EMERGENCY");
                flipped |= EMERGENCY;
            }
            if ((o & SMS) == SMS) {
                list.add("SMS");
                flipped |= SMS;
            }
            if ((o & OPERATOR_1) == OPERATOR_1) {
                list.add("OPERATOR_1");
                flipped |= OPERATOR_1;
            }
            if ((o & OPERATOR_2) == OPERATOR_2) {
                list.add("OPERATOR_2");
                flipped |= OPERATOR_2;
            }
            if ((o & OPERATOR_3) == OPERATOR_3) {
                list.add("OPERATOR_3");
                flipped |= OPERATOR_3;
            }
            if ((o & OPERATOR_4) == OPERATOR_4) {
                list.add("OPERATOR_4");
                flipped |= OPERATOR_4;
            }
            if ((o & OPERATOR_5) == OPERATOR_5) {
                list.add("OPERATOR_5");
                flipped |= OPERATOR_5;
            }
            if ((o & OPERATOR_6) == OPERATOR_6) {
                list.add("OPERATOR_6");
                flipped |= OPERATOR_6;
            }
            if ((o & OPERATOR_7) == OPERATOR_7) {
                list.add("OPERATOR_7");
                flipped |= OPERATOR_7;
            }
            if ((o & OPERATOR_8) == OPERATOR_8) {
                list.add("OPERATOR_8");
                flipped |= OPERATOR_8;
            }
            if ((o & OPERATOR_9) == OPERATOR_9) {
                list.add("OPERATOR_9");
                flipped |= OPERATOR_9;
            }
            if ((o & OPERATOR_10) == OPERATOR_10) {
                list.add("OPERATOR_10");
                flipped |= OPERATOR_10;
            }
            if ((o & OPERATOR_11) == OPERATOR_11) {
                list.add("OPERATOR_11");
                flipped |= OPERATOR_11;
            }
            if ((o & OPERATOR_12) == OPERATOR_12) {
                list.add("OPERATOR_12");
                flipped |= OPERATOR_12;
            }
            if ((o & OPERATOR_13) == OPERATOR_13) {
                list.add("OPERATOR_13");
                flipped |= OPERATOR_13;
            }
            if ((o & OPERATOR_14) == OPERATOR_14) {
                list.add("OPERATOR_14");
                flipped |= OPERATOR_14;
            }
            if ((o & OPERATOR_15) == OPERATOR_15) {
                list.add("OPERATOR_15");
                flipped |= OPERATOR_15;
            }
            if ((o & OPERATOR_16) == OPERATOR_16) {
                list.add("OPERATOR_16");
                flipped |= OPERATOR_16;
            }
            if ((o & OPERATOR_17) == OPERATOR_17) {
                list.add("OPERATOR_17");
                flipped |= OPERATOR_17;
            }
            if ((o & OPERATOR_18) == OPERATOR_18) {
                list.add("OPERATOR_18");
                flipped |= OPERATOR_18;
            }
            if ((o & OPERATOR_19) == OPERATOR_19) {
                list.add("OPERATOR_19");
                flipped |= OPERATOR_19;
            }
            if ((o & OPERATOR_20) == OPERATOR_20) {
                list.add("OPERATOR_20");
                flipped |= OPERATOR_20;
            }
            if ((o & OPERATOR_21) == OPERATOR_21) {
                list.add("OPERATOR_21");
                flipped |= OPERATOR_21;
            }
            if ((o & OPERATOR_22) == OPERATOR_22) {
                list.add("OPERATOR_22");
                flipped |= OPERATOR_22;
            }
            if ((o & OPERATOR_23) == OPERATOR_23) {
                list.add("OPERATOR_23");
                flipped |= OPERATOR_23;
            }
            if ((o & OPERATOR_24) == OPERATOR_24) {
                list.add("OPERATOR_24");
                flipped |= OPERATOR_24;
            }
            if ((o & OPERATOR_25) == OPERATOR_25) {
                list.add("OPERATOR_25");
                flipped |= OPERATOR_25;
            }
            if ((o & OPERATOR_26) == OPERATOR_26) {
                list.add("OPERATOR_26");
                flipped |= OPERATOR_26;
            }
            if ((o & OPERATOR_27) == OPERATOR_27) {
                list.add("OPERATOR_27");
                flipped |= OPERATOR_27;
            }
            if ((o & OPERATOR_28) == OPERATOR_28) {
                list.add("OPERATOR_28");
                flipped |= OPERATOR_28;
            }
            if ((o & OPERATOR_29) == OPERATOR_29) {
                list.add("OPERATOR_29");
                flipped |= OPERATOR_29;
            }
            if ((o & OPERATOR_30) == OPERATOR_30) {
                list.add("OPERATOR_30");
                flipped |= OPERATOR_30;
            }
            if ((o & OPERATOR_31) == OPERATOR_31) {
                list.add("OPERATOR_31");
                flipped |= OPERATOR_31;
            }
            if ((o & OPERATOR_32) == OPERATOR_32) {
                list.add("OPERATOR_32");
                flipped |= OPERATOR_32;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(o & (~flipped)));
            }
            return String.join(" | ", list);
        }

    };

    public static final class BarringType {
        /**
         * Device is not barred for the given service
         */
        public static final int NONE = 0;
        /**
         * Device may be barred based on time and probability factors
         */
        public static final int CONDITIONAL = 1 /* ::android::hardware::radio::V1_5::BarringInfo::BarringType.NONE implicitly + 1 */;
        /*
         * Device is unconditionally barred
         */
        public static final int UNCONDITIONAL = 2 /* ::android::hardware::radio::V1_5::BarringInfo::BarringType.CONDITIONAL implicitly + 1 */;
        public static final String toString(int o) {
            if (o == NONE) {
                return "NONE";
            }
            if (o == CONDITIONAL) {
                return "CONDITIONAL";
            }
            if (o == UNCONDITIONAL) {
                return "UNCONDITIONAL";
            }
            return "0x" + Integer.toHexString(o);
        }

        public static final String dumpBitfield(int o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            int flipped = 0;
            list.add("NONE"); // NONE == 0
            if ((o & CONDITIONAL) == CONDITIONAL) {
                list.add("CONDITIONAL");
                flipped |= CONDITIONAL;
            }
            if ((o & UNCONDITIONAL) == UNCONDITIONAL) {
                list.add("UNCONDITIONAL");
                flipped |= UNCONDITIONAL;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(o & (~flipped)));
            }
            return String.join(" | ", list);
        }

    };

    public final static class BarringTypeSpecificInfo {
        public final static class Conditional {
            /**
             * The barring factor as a percentage 0-100
             */
            public int factor = 0;
            /**
             * The number of seconds between re-evaluations of barring
             */
            public int timeSeconds = 0;
            /**
             * Indicates whether barring is currently being applied.
             *
             * <p>True if the UE applies barring to a conditionally barred
             * service based on the conditional barring parameters.
             *
             * <p>False if the service is conditionally barred but barring
             * is not currently applied, which could be due to either the
             * barring criteria not having been evaluated (if the UE has not
             * attempted to use the service) or due to the criteria being
             * evaluated and the UE being permitted to use the service
             * despite conditional barring.
             */
            public boolean isBarred = false;

            @Override
            public final boolean equals(Object otherObject) {
                if (this == otherObject) {
                    return true;
                }
                if (otherObject == null) {
                    return false;
                }
                if (otherObject.getClass() != android.hardware.radio.V1_5.BarringInfo.BarringTypeSpecificInfo.Conditional.class) {
                    return false;
                }
                android.hardware.radio.V1_5.BarringInfo.BarringTypeSpecificInfo.Conditional other = (android.hardware.radio.V1_5.BarringInfo.BarringTypeSpecificInfo.Conditional)otherObject;
                if (this.factor != other.factor) {
                    return false;
                }
                if (this.timeSeconds != other.timeSeconds) {
                    return false;
                }
                if (this.isBarred != other.isBarred) {
                    return false;
                }
                return true;
            }

            @Override
            public final int hashCode() {
                return java.util.Objects.hash(
                        android.os.HidlSupport.deepHashCode(this.factor), 
                        android.os.HidlSupport.deepHashCode(this.timeSeconds), 
                        android.os.HidlSupport.deepHashCode(this.isBarred));
            }

            @Override
            public final String toString() {
                java.lang.StringBuilder builder = new java.lang.StringBuilder();
                builder.append("{");
                builder.append(".factor = ");
                builder.append(this.factor);
                builder.append(", .timeSeconds = ");
                builder.append(this.timeSeconds);
                builder.append(", .isBarred = ");
                builder.append(this.isBarred);
                builder.append("}");
                return builder.toString();
            }

            public final void readFromParcel(android.os.HwParcel parcel) {
                android.os.HwBlob blob = parcel.readBuffer(12 /* size */);
                readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
            }

            public static final java.util.ArrayList<Conditional> readVectorFromParcel(android.os.HwParcel parcel) {
                java.util.ArrayList<Conditional> _hidl_vec = new java.util.ArrayList();
                android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

                {
                    int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                    android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                            _hidl_vec_size * 12,_hidl_blob.handle(),
                            0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                    _hidl_vec.clear();
                    for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                        android.hardware.radio.V1_5.BarringInfo.BarringTypeSpecificInfo.Conditional _hidl_vec_element = new android.hardware.radio.V1_5.BarringInfo.BarringTypeSpecificInfo.Conditional();
                        ((android.hardware.radio.V1_5.BarringInfo.BarringTypeSpecificInfo.Conditional) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 12);
                        _hidl_vec.add(_hidl_vec_element);
                    }
                }

                return _hidl_vec;
            }

            public final void readEmbeddedFromParcel(
                    android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
                factor = _hidl_blob.getInt32(_hidl_offset + 0);
                timeSeconds = _hidl_blob.getInt32(_hidl_offset + 4);
                isBarred = _hidl_blob.getBool(_hidl_offset + 8);
            }

            public final void writeToParcel(android.os.HwParcel parcel) {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(12 /* size */);
                writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
                parcel.writeBuffer(_hidl_blob);
            }

            public static final void writeVectorToParcel(
                    android.os.HwParcel parcel, java.util.ArrayList<Conditional> _hidl_vec) {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
                {
                    int _hidl_vec_size = _hidl_vec.size();
                    _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                    _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                    android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 12));
                    for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                        _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 12);
                    }
                    _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
                }

                parcel.writeBuffer(_hidl_blob);
            }

            public final void writeEmbeddedToBlob(
                    android.os.HwBlob _hidl_blob, long _hidl_offset) {
                _hidl_blob.putInt32(_hidl_offset + 0, factor);
                _hidl_blob.putInt32(_hidl_offset + 4, timeSeconds);
                _hidl_blob.putBool(_hidl_offset + 8, isBarred);
            }
        };

        public BarringTypeSpecificInfo() {
            hidl_o = new android.hidl.safe_union.V1_0.Monostate();
        }

        public static final class hidl_discriminator {
            /**
             * Barring type is either none or unconditional
             */
            public static final byte noinit = 0;  // android.hidl.safe_union.V1_0.Monostate
            /**
             * Must be included if barring is conditional
             */
            public static final byte conditional = 1;  // android.hardware.radio.V1_5.BarringInfo.BarringTypeSpecificInfo.Conditional

            public static final String getName(byte value) {
                switch (value) {
                    case 0: { return "noinit"; }
                    case 1: { return "conditional"; }
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

        public void conditional(android.hardware.radio.V1_5.BarringInfo.BarringTypeSpecificInfo.Conditional conditional) {
            hidl_d = hidl_discriminator.conditional;
            hidl_o = conditional;
        }

        public android.hardware.radio.V1_5.BarringInfo.BarringTypeSpecificInfo.Conditional conditional() {
            if (hidl_d != hidl_discriminator.conditional) {
                String className = (hidl_o != null) ? hidl_o.getClass().getName() : "null";
                throw new IllegalStateException(
                        "Read access to inactive union components is disallowed. " +
                        "Discriminator value is " + hidl_d + " (corresponding " +
                        "to " + hidl_discriminator.getName(hidl_d) + "), and " +
                        "hidl_o is of type " + className + ".");
            }
            if (hidl_o != null && !android.hardware.radio.V1_5.BarringInfo.BarringTypeSpecificInfo.Conditional.class.isInstance(hidl_o)) {
                throw new Error("Union is in a corrupted state.");
            }
            return ((android.hardware.radio.V1_5.BarringInfo.BarringTypeSpecificInfo.Conditional) hidl_o);
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
            if (otherObject.getClass() != android.hardware.radio.V1_5.BarringInfo.BarringTypeSpecificInfo.class) {
                return false;
            }
            android.hardware.radio.V1_5.BarringInfo.BarringTypeSpecificInfo other = (android.hardware.radio.V1_5.BarringInfo.BarringTypeSpecificInfo)otherObject;
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
                case hidl_discriminator.conditional: {
                    builder.append(".conditional = ");
                    builder.append(this.conditional());
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
            android.os.HwBlob blob = parcel.readBuffer(16 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<BarringTypeSpecificInfo> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<BarringTypeSpecificInfo> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 16,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.radio.V1_5.BarringInfo.BarringTypeSpecificInfo _hidl_vec_element = new android.hardware.radio.V1_5.BarringInfo.BarringTypeSpecificInfo();
                    ((android.hardware.radio.V1_5.BarringInfo.BarringTypeSpecificInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 16);
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
                case hidl_discriminator.conditional: {
                    hidl_o = new android.hardware.radio.V1_5.BarringInfo.BarringTypeSpecificInfo.Conditional();
                    ((android.hardware.radio.V1_5.BarringInfo.BarringTypeSpecificInfo.Conditional) hidl_o).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 4);
                    break;
                }
                default: {
                    throw new IllegalStateException("Unknown union discriminator (value: " + hidl_d + ").");
                }
            }
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<BarringTypeSpecificInfo> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 16));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 16);
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
                case hidl_discriminator.conditional: {
                    conditional().writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 4);
                    break;
                }
                default: {
                    throw new Error("Unknown union discriminator (value: " + hidl_d + ").");
                }
            }
        }
    };

    /**
     * Combined list of barring services for UTRAN, EUTRAN, and NGRAN.
     *
     * Barring information is defined in:
     * -UTRAN - 3gpp 25.331 Sec 10.2.48.8.6.
     * -EUTRAN - 3gpp 36.331 Sec 6.3.1 SystemInformationBlockType2
     * -NGRAN - 3gpp 38.331 Sec 6.3.2 UAC-BarringInfo and 22.261 Sec 6.22.2.[2-3]
     */
    public int serviceType = 0;
    /**
     * The type of barring applied to the service
     */
    public int barringType = 0;
    /**
     * Type-specific barring info if applicable
     */
    public android.hardware.radio.V1_5.BarringInfo.BarringTypeSpecificInfo barringTypeSpecificInfo = new android.hardware.radio.V1_5.BarringInfo.BarringTypeSpecificInfo();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.V1_5.BarringInfo.class) {
            return false;
        }
        android.hardware.radio.V1_5.BarringInfo other = (android.hardware.radio.V1_5.BarringInfo)otherObject;
        if (this.serviceType != other.serviceType) {
            return false;
        }
        if (this.barringType != other.barringType) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.barringTypeSpecificInfo, other.barringTypeSpecificInfo)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.serviceType), 
                android.os.HidlSupport.deepHashCode(this.barringType), 
                android.os.HidlSupport.deepHashCode(this.barringTypeSpecificInfo));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".serviceType = ");
        builder.append(android.hardware.radio.V1_5.BarringInfo.ServiceType.toString(this.serviceType));
        builder.append(", .barringType = ");
        builder.append(android.hardware.radio.V1_5.BarringInfo.BarringType.toString(this.barringType));
        builder.append(", .barringTypeSpecificInfo = ");
        builder.append(this.barringTypeSpecificInfo);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(24 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<BarringInfo> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<BarringInfo> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 24,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.V1_5.BarringInfo _hidl_vec_element = new android.hardware.radio.V1_5.BarringInfo();
                ((android.hardware.radio.V1_5.BarringInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 24);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        serviceType = _hidl_blob.getInt32(_hidl_offset + 0);
        barringType = _hidl_blob.getInt32(_hidl_offset + 4);
        ((android.hardware.radio.V1_5.BarringInfo.BarringTypeSpecificInfo) barringTypeSpecificInfo).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 8);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(24 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<BarringInfo> _hidl_vec) {
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
        _hidl_blob.putInt32(_hidl_offset + 0, serviceType);
        _hidl_blob.putInt32(_hidl_offset + 4, barringType);
        barringTypeSpecificInfo.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 8);
    }
};

