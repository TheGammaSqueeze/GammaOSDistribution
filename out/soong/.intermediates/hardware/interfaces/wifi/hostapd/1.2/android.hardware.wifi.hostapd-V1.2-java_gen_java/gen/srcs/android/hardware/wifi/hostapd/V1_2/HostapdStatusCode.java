package android.hardware.wifi.hostapd.V1_2;


public final class HostapdStatusCode {
    /**
     * No errors.
     */
    public static final int SUCCESS = 0;
    /**
     * Unknown failure occured.
     */
    public static final int FAILURE_UNKNOWN = 1 /* ::android::hardware::wifi::hostapd::V1_0::HostapdStatusCode.SUCCESS implicitly + 1 */;
    /**
     * One or more of the incoming args is invalid.
     */
    public static final int FAILURE_ARGS_INVALID = 2 /* ::android::hardware::wifi::hostapd::V1_0::HostapdStatusCode.FAILURE_UNKNOWN implicitly + 1 */;
    /**
     * Iface with the provided name does not exist.
     */
    public static final int FAILURE_IFACE_UNKNOWN = 3 /* ::android::hardware::wifi::hostapd::V1_0::HostapdStatusCode.FAILURE_ARGS_INVALID implicitly + 1 */;
    /**
     * Iface with the provided name already exists.
     */
    public static final int FAILURE_IFACE_EXISTS = 4 /* ::android::hardware::wifi::hostapd::V1_0::HostapdStatusCode.FAILURE_IFACE_UNKNOWN implicitly + 1 */;
    /**
     * Failure because unknown the client.
     */
    public static final int FAILURE_CLIENT_UNKNOWN = 5 /* ::android::hardware::wifi::hostapd::V1_0::HostapdStatusCode.FAILURE_IFACE_EXISTS implicitly + 1 */;
    public static final String toString(int o) {
        if (o == SUCCESS) {
            return "SUCCESS";
        }
        if (o == FAILURE_UNKNOWN) {
            return "FAILURE_UNKNOWN";
        }
        if (o == FAILURE_ARGS_INVALID) {
            return "FAILURE_ARGS_INVALID";
        }
        if (o == FAILURE_IFACE_UNKNOWN) {
            return "FAILURE_IFACE_UNKNOWN";
        }
        if (o == FAILURE_IFACE_EXISTS) {
            return "FAILURE_IFACE_EXISTS";
        }
        if (o == FAILURE_CLIENT_UNKNOWN) {
            return "FAILURE_CLIENT_UNKNOWN";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("SUCCESS"); // SUCCESS == 0
        if ((o & FAILURE_UNKNOWN) == FAILURE_UNKNOWN) {
            list.add("FAILURE_UNKNOWN");
            flipped |= FAILURE_UNKNOWN;
        }
        if ((o & FAILURE_ARGS_INVALID) == FAILURE_ARGS_INVALID) {
            list.add("FAILURE_ARGS_INVALID");
            flipped |= FAILURE_ARGS_INVALID;
        }
        if ((o & FAILURE_IFACE_UNKNOWN) == FAILURE_IFACE_UNKNOWN) {
            list.add("FAILURE_IFACE_UNKNOWN");
            flipped |= FAILURE_IFACE_UNKNOWN;
        }
        if ((o & FAILURE_IFACE_EXISTS) == FAILURE_IFACE_EXISTS) {
            list.add("FAILURE_IFACE_EXISTS");
            flipped |= FAILURE_IFACE_EXISTS;
        }
        if ((o & FAILURE_CLIENT_UNKNOWN) == FAILURE_CLIENT_UNKNOWN) {
            list.add("FAILURE_CLIENT_UNKNOWN");
            flipped |= FAILURE_CLIENT_UNKNOWN;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

