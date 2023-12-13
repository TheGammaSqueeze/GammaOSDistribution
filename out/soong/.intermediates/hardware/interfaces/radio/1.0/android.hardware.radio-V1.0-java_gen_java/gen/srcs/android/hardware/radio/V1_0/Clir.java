package android.hardware.radio.V1_0;


public final class Clir {
    public static final int DEFAULT = 0;
    public static final int INVOCATION = 1 /* ::android::hardware::radio::V1_0::Clir.DEFAULT implicitly + 1 */;
    public static final int SUPPRESSION = 2 /* ::android::hardware::radio::V1_0::Clir.INVOCATION implicitly + 1 */;
    public static final String toString(int o) {
        if (o == DEFAULT) {
            return "DEFAULT";
        }
        if (o == INVOCATION) {
            return "INVOCATION";
        }
        if (o == SUPPRESSION) {
            return "SUPPRESSION";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("DEFAULT"); // DEFAULT == 0
        if ((o & INVOCATION) == INVOCATION) {
            list.add("INVOCATION");
            flipped |= INVOCATION;
        }
        if ((o & SUPPRESSION) == SUPPRESSION) {
            list.add("SUPPRESSION");
            flipped |= SUPPRESSION;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

