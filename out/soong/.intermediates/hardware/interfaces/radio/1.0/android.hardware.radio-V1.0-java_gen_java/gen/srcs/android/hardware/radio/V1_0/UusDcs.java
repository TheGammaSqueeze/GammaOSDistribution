package android.hardware.radio.V1_0;


public final class UusDcs {
    public static final int USP = 0;
    public static final int OSIHLP = 1 /* ::android::hardware::radio::V1_0::UusDcs.USP implicitly + 1 */;
    public static final int X244 = 2 /* ::android::hardware::radio::V1_0::UusDcs.OSIHLP implicitly + 1 */;
    public static final int RMCF = 3 /* ::android::hardware::radio::V1_0::UusDcs.X244 implicitly + 1 */;
    public static final int IA5C = 4 /* ::android::hardware::radio::V1_0::UusDcs.RMCF implicitly + 1 */;
    public static final String toString(int o) {
        if (o == USP) {
            return "USP";
        }
        if (o == OSIHLP) {
            return "OSIHLP";
        }
        if (o == X244) {
            return "X244";
        }
        if (o == RMCF) {
            return "RMCF";
        }
        if (o == IA5C) {
            return "IA5C";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("USP"); // USP == 0
        if ((o & OSIHLP) == OSIHLP) {
            list.add("OSIHLP");
            flipped |= OSIHLP;
        }
        if ((o & X244) == X244) {
            list.add("X244");
            flipped |= X244;
        }
        if ((o & RMCF) == RMCF) {
            list.add("RMCF");
            flipped |= RMCF;
        }
        if ((o & IA5C) == IA5C) {
            list.add("IA5C");
            flipped |= IA5C;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

