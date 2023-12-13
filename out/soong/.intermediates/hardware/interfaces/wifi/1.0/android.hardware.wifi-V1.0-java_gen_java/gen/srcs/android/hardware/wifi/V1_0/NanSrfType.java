package android.hardware.wifi.V1_0;


public final class NanSrfType {
    public static final int BLOOM_FILTER = 0;
    public static final int PARTIAL_MAC_ADDR = 1 /* ::android::hardware::wifi::V1_0::NanSrfType.BLOOM_FILTER implicitly + 1 */;
    public static final String toString(int o) {
        if (o == BLOOM_FILTER) {
            return "BLOOM_FILTER";
        }
        if (o == PARTIAL_MAC_ADDR) {
            return "PARTIAL_MAC_ADDR";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("BLOOM_FILTER"); // BLOOM_FILTER == 0
        if ((o & PARTIAL_MAC_ADDR) == PARTIAL_MAC_ADDR) {
            list.add("PARTIAL_MAC_ADDR");
            flipped |= PARTIAL_MAC_ADDR;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

