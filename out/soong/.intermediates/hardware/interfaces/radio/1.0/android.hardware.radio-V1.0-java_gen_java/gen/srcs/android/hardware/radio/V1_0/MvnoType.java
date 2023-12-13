package android.hardware.radio.V1_0;


public final class MvnoType {
    public static final int NONE = 0;
    public static final int IMSI = 1 /* ::android::hardware::radio::V1_0::MvnoType.NONE implicitly + 1 */;
    public static final int GID = 2 /* ::android::hardware::radio::V1_0::MvnoType.IMSI implicitly + 1 */;
    public static final int SPN = 3 /* ::android::hardware::radio::V1_0::MvnoType.GID implicitly + 1 */;
    public static final String toString(int o) {
        if (o == NONE) {
            return "NONE";
        }
        if (o == IMSI) {
            return "IMSI";
        }
        if (o == GID) {
            return "GID";
        }
        if (o == SPN) {
            return "SPN";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NONE"); // NONE == 0
        if ((o & IMSI) == IMSI) {
            list.add("IMSI");
            flipped |= IMSI;
        }
        if ((o & GID) == GID) {
            list.add("GID");
            flipped |= GID;
        }
        if ((o & SPN) == SPN) {
            list.add("SPN");
            flipped |= SPN;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

