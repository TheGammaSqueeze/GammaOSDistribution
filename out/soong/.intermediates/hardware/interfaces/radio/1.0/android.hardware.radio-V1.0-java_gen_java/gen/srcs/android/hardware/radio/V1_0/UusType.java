package android.hardware.radio.V1_0;


public final class UusType {
    public static final int TYPE1_IMPLICIT = 0;
    public static final int TYPE1_REQUIRED = 1 /* ::android::hardware::radio::V1_0::UusType.TYPE1_IMPLICIT implicitly + 1 */;
    public static final int TYPE1_NOT_REQUIRED = 2 /* ::android::hardware::radio::V1_0::UusType.TYPE1_REQUIRED implicitly + 1 */;
    public static final int TYPE2_REQUIRED = 3 /* ::android::hardware::radio::V1_0::UusType.TYPE1_NOT_REQUIRED implicitly + 1 */;
    public static final int TYPE2_NOT_REQUIRED = 4 /* ::android::hardware::radio::V1_0::UusType.TYPE2_REQUIRED implicitly + 1 */;
    public static final int TYPE3_REQUIRED = 5 /* ::android::hardware::radio::V1_0::UusType.TYPE2_NOT_REQUIRED implicitly + 1 */;
    public static final int TYPE3_NOT_REQUIRED = 6 /* ::android::hardware::radio::V1_0::UusType.TYPE3_REQUIRED implicitly + 1 */;
    public static final String toString(int o) {
        if (o == TYPE1_IMPLICIT) {
            return "TYPE1_IMPLICIT";
        }
        if (o == TYPE1_REQUIRED) {
            return "TYPE1_REQUIRED";
        }
        if (o == TYPE1_NOT_REQUIRED) {
            return "TYPE1_NOT_REQUIRED";
        }
        if (o == TYPE2_REQUIRED) {
            return "TYPE2_REQUIRED";
        }
        if (o == TYPE2_NOT_REQUIRED) {
            return "TYPE2_NOT_REQUIRED";
        }
        if (o == TYPE3_REQUIRED) {
            return "TYPE3_REQUIRED";
        }
        if (o == TYPE3_NOT_REQUIRED) {
            return "TYPE3_NOT_REQUIRED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("TYPE1_IMPLICIT"); // TYPE1_IMPLICIT == 0
        if ((o & TYPE1_REQUIRED) == TYPE1_REQUIRED) {
            list.add("TYPE1_REQUIRED");
            flipped |= TYPE1_REQUIRED;
        }
        if ((o & TYPE1_NOT_REQUIRED) == TYPE1_NOT_REQUIRED) {
            list.add("TYPE1_NOT_REQUIRED");
            flipped |= TYPE1_NOT_REQUIRED;
        }
        if ((o & TYPE2_REQUIRED) == TYPE2_REQUIRED) {
            list.add("TYPE2_REQUIRED");
            flipped |= TYPE2_REQUIRED;
        }
        if ((o & TYPE2_NOT_REQUIRED) == TYPE2_NOT_REQUIRED) {
            list.add("TYPE2_NOT_REQUIRED");
            flipped |= TYPE2_NOT_REQUIRED;
        }
        if ((o & TYPE3_REQUIRED) == TYPE3_REQUIRED) {
            list.add("TYPE3_REQUIRED");
            flipped |= TYPE3_REQUIRED;
        }
        if ((o & TYPE3_NOT_REQUIRED) == TYPE3_NOT_REQUIRED) {
            list.add("TYPE3_NOT_REQUIRED");
            flipped |= TYPE3_NOT_REQUIRED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

