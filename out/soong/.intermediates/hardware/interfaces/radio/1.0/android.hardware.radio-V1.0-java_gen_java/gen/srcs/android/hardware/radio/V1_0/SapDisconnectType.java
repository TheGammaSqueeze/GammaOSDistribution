package android.hardware.radio.V1_0;


public final class SapDisconnectType {
    public static final int GRACEFUL = 0;
    public static final int IMMEDIATE = 1 /* ::android::hardware::radio::V1_0::SapDisconnectType.GRACEFUL implicitly + 1 */;
    public static final String toString(int o) {
        if (o == GRACEFUL) {
            return "GRACEFUL";
        }
        if (o == IMMEDIATE) {
            return "IMMEDIATE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("GRACEFUL"); // GRACEFUL == 0
        if ((o & IMMEDIATE) == IMMEDIATE) {
            list.add("IMMEDIATE");
            flipped |= IMMEDIATE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

