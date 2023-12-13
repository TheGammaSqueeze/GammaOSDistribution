package android.hardware.wifi.V1_0;


public final class NanClusterEventType {
    /**
     * Management/discovery interface MAC address has changed (e.g. due to randomization or at
     * startup).
     */
    public static final int DISCOVERY_MAC_ADDRESS_CHANGED = 0;
    /**
     * A new cluster has been formed by this device.
     */
    public static final int STARTED_CLUSTER = 1 /* ::android::hardware::wifi::V1_0::NanClusterEventType.DISCOVERY_MAC_ADDRESS_CHANGED implicitly + 1 */;
    /**
     * This device has joined an existing cluster.
     */
    public static final int JOINED_CLUSTER = 2 /* ::android::hardware::wifi::V1_0::NanClusterEventType.STARTED_CLUSTER implicitly + 1 */;
    public static final String toString(int o) {
        if (o == DISCOVERY_MAC_ADDRESS_CHANGED) {
            return "DISCOVERY_MAC_ADDRESS_CHANGED";
        }
        if (o == STARTED_CLUSTER) {
            return "STARTED_CLUSTER";
        }
        if (o == JOINED_CLUSTER) {
            return "JOINED_CLUSTER";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("DISCOVERY_MAC_ADDRESS_CHANGED"); // DISCOVERY_MAC_ADDRESS_CHANGED == 0
        if ((o & STARTED_CLUSTER) == STARTED_CLUSTER) {
            list.add("STARTED_CLUSTER");
            flipped |= STARTED_CLUSTER;
        }
        if ((o & JOINED_CLUSTER) == JOINED_CLUSTER) {
            list.add("JOINED_CLUSTER");
            flipped |= JOINED_CLUSTER;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

