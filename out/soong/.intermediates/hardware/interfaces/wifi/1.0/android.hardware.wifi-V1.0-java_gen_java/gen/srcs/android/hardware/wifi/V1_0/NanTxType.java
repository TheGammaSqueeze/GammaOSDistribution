package android.hardware.wifi.V1_0;


public final class NanTxType {
    public static final int BROADCAST = 0;
    public static final int UNICAST = 1 /* ::android::hardware::wifi::V1_0::NanTxType.BROADCAST implicitly + 1 */;
    public static final String toString(int o) {
        if (o == BROADCAST) {
            return "BROADCAST";
        }
        if (o == UNICAST) {
            return "UNICAST";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("BROADCAST"); // BROADCAST == 0
        if ((o & UNICAST) == UNICAST) {
            list.add("UNICAST");
            flipped |= UNICAST;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

