package android.hardware.radio.V1_0;


public final class CdmaRoamingType {
    public static final int HOME_NETWORK = 0;
    public static final int AFFILIATED_ROAM = 1 /* ::android::hardware::radio::V1_0::CdmaRoamingType.HOME_NETWORK implicitly + 1 */;
    public static final int ANY_ROAM = 2 /* ::android::hardware::radio::V1_0::CdmaRoamingType.AFFILIATED_ROAM implicitly + 1 */;
    public static final String toString(int o) {
        if (o == HOME_NETWORK) {
            return "HOME_NETWORK";
        }
        if (o == AFFILIATED_ROAM) {
            return "AFFILIATED_ROAM";
        }
        if (o == ANY_ROAM) {
            return "ANY_ROAM";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("HOME_NETWORK"); // HOME_NETWORK == 0
        if ((o & AFFILIATED_ROAM) == AFFILIATED_ROAM) {
            list.add("AFFILIATED_ROAM");
            flipped |= AFFILIATED_ROAM;
        }
        if ((o & ANY_ROAM) == ANY_ROAM) {
            list.add("ANY_ROAM");
            flipped |= ANY_ROAM;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

