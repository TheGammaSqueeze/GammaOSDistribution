package android.hardware.radio.V1_1;


public final class KeepaliveStatusCode {
    public static final int ACTIVE = 0;
    public static final int INACTIVE = 1 /* ::android::hardware::radio::V1_1::KeepaliveStatusCode.ACTIVE implicitly + 1 */;
    public static final int PENDING = 2 /* ::android::hardware::radio::V1_1::KeepaliveStatusCode.INACTIVE implicitly + 1 */;
    public static final String toString(int o) {
        if (o == ACTIVE) {
            return "ACTIVE";
        }
        if (o == INACTIVE) {
            return "INACTIVE";
        }
        if (o == PENDING) {
            return "PENDING";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("ACTIVE"); // ACTIVE == 0
        if ((o & INACTIVE) == INACTIVE) {
            list.add("INACTIVE");
            flipped |= INACTIVE;
        }
        if ((o & PENDING) == PENDING) {
            list.add("PENDING");
            flipped |= PENDING;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

