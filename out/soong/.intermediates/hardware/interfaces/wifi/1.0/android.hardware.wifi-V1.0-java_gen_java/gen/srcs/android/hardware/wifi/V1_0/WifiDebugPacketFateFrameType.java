package android.hardware.wifi.V1_0;


public final class WifiDebugPacketFateFrameType {
    public static final int UNKNOWN = 0;
    public static final int ETHERNET_II = 1 /* ::android::hardware::wifi::V1_0::WifiDebugPacketFateFrameType.UNKNOWN implicitly + 1 */;
    public static final int MGMT_80211 = 2 /* ::android::hardware::wifi::V1_0::WifiDebugPacketFateFrameType.ETHERNET_II implicitly + 1 */;
    public static final String toString(int o) {
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        if (o == ETHERNET_II) {
            return "ETHERNET_II";
        }
        if (o == MGMT_80211) {
            return "MGMT_80211";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("UNKNOWN"); // UNKNOWN == 0
        if ((o & ETHERNET_II) == ETHERNET_II) {
            list.add("ETHERNET_II");
            flipped |= ETHERNET_II;
        }
        if ((o & MGMT_80211) == MGMT_80211) {
            list.add("MGMT_80211");
            flipped |= MGMT_80211;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

