package android.hardware.wifi.V1_0;


public final class NanSubscribeType {
    public static final int PASSIVE = 0;
    public static final int ACTIVE = 1 /* ::android::hardware::wifi::V1_0::NanSubscribeType.PASSIVE implicitly + 1 */;
    public static final String toString(int o) {
        if (o == PASSIVE) {
            return "PASSIVE";
        }
        if (o == ACTIVE) {
            return "ACTIVE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("PASSIVE"); // PASSIVE == 0
        if ((o & ACTIVE) == ACTIVE) {
            list.add("ACTIVE");
            flipped |= ACTIVE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

