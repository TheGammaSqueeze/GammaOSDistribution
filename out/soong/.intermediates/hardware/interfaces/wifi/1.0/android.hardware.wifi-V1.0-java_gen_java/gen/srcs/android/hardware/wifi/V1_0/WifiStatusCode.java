package android.hardware.wifi.V1_0;


public final class WifiStatusCode {
    /**
     * No errors.
     */
    public static final int SUCCESS = 0;
    /**
     * Method invoked on an invalid |IWifiChip| object.
     */
    public static final int ERROR_WIFI_CHIP_INVALID = 1 /* ::android::hardware::wifi::V1_0::WifiStatusCode.SUCCESS implicitly + 1 */;
    /**
     * Method invoked on an invalid |IWifiIface| object.
     */
    public static final int ERROR_WIFI_IFACE_INVALID = 2 /* ::android::hardware::wifi::V1_0::WifiStatusCode.ERROR_WIFI_CHIP_INVALID implicitly + 1 */;
    /**
     * Method invoked on an invalid |IWifiRttController| object.
     */
    public static final int ERROR_WIFI_RTT_CONTROLLER_INVALID = 3 /* ::android::hardware::wifi::V1_0::WifiStatusCode.ERROR_WIFI_IFACE_INVALID implicitly + 1 */;
    public static final int ERROR_NOT_SUPPORTED = 4 /* ::android::hardware::wifi::V1_0::WifiStatusCode.ERROR_WIFI_RTT_CONTROLLER_INVALID implicitly + 1 */;
    public static final int ERROR_NOT_AVAILABLE = 5 /* ::android::hardware::wifi::V1_0::WifiStatusCode.ERROR_NOT_SUPPORTED implicitly + 1 */;
    public static final int ERROR_NOT_STARTED = 6 /* ::android::hardware::wifi::V1_0::WifiStatusCode.ERROR_NOT_AVAILABLE implicitly + 1 */;
    public static final int ERROR_INVALID_ARGS = 7 /* ::android::hardware::wifi::V1_0::WifiStatusCode.ERROR_NOT_STARTED implicitly + 1 */;
    public static final int ERROR_BUSY = 8 /* ::android::hardware::wifi::V1_0::WifiStatusCode.ERROR_INVALID_ARGS implicitly + 1 */;
    public static final int ERROR_UNKNOWN = 9 /* ::android::hardware::wifi::V1_0::WifiStatusCode.ERROR_BUSY implicitly + 1 */;
    public static final String toString(int o) {
        if (o == SUCCESS) {
            return "SUCCESS";
        }
        if (o == ERROR_WIFI_CHIP_INVALID) {
            return "ERROR_WIFI_CHIP_INVALID";
        }
        if (o == ERROR_WIFI_IFACE_INVALID) {
            return "ERROR_WIFI_IFACE_INVALID";
        }
        if (o == ERROR_WIFI_RTT_CONTROLLER_INVALID) {
            return "ERROR_WIFI_RTT_CONTROLLER_INVALID";
        }
        if (o == ERROR_NOT_SUPPORTED) {
            return "ERROR_NOT_SUPPORTED";
        }
        if (o == ERROR_NOT_AVAILABLE) {
            return "ERROR_NOT_AVAILABLE";
        }
        if (o == ERROR_NOT_STARTED) {
            return "ERROR_NOT_STARTED";
        }
        if (o == ERROR_INVALID_ARGS) {
            return "ERROR_INVALID_ARGS";
        }
        if (o == ERROR_BUSY) {
            return "ERROR_BUSY";
        }
        if (o == ERROR_UNKNOWN) {
            return "ERROR_UNKNOWN";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("SUCCESS"); // SUCCESS == 0
        if ((o & ERROR_WIFI_CHIP_INVALID) == ERROR_WIFI_CHIP_INVALID) {
            list.add("ERROR_WIFI_CHIP_INVALID");
            flipped |= ERROR_WIFI_CHIP_INVALID;
        }
        if ((o & ERROR_WIFI_IFACE_INVALID) == ERROR_WIFI_IFACE_INVALID) {
            list.add("ERROR_WIFI_IFACE_INVALID");
            flipped |= ERROR_WIFI_IFACE_INVALID;
        }
        if ((o & ERROR_WIFI_RTT_CONTROLLER_INVALID) == ERROR_WIFI_RTT_CONTROLLER_INVALID) {
            list.add("ERROR_WIFI_RTT_CONTROLLER_INVALID");
            flipped |= ERROR_WIFI_RTT_CONTROLLER_INVALID;
        }
        if ((o & ERROR_NOT_SUPPORTED) == ERROR_NOT_SUPPORTED) {
            list.add("ERROR_NOT_SUPPORTED");
            flipped |= ERROR_NOT_SUPPORTED;
        }
        if ((o & ERROR_NOT_AVAILABLE) == ERROR_NOT_AVAILABLE) {
            list.add("ERROR_NOT_AVAILABLE");
            flipped |= ERROR_NOT_AVAILABLE;
        }
        if ((o & ERROR_NOT_STARTED) == ERROR_NOT_STARTED) {
            list.add("ERROR_NOT_STARTED");
            flipped |= ERROR_NOT_STARTED;
        }
        if ((o & ERROR_INVALID_ARGS) == ERROR_INVALID_ARGS) {
            list.add("ERROR_INVALID_ARGS");
            flipped |= ERROR_INVALID_ARGS;
        }
        if ((o & ERROR_BUSY) == ERROR_BUSY) {
            list.add("ERROR_BUSY");
            flipped |= ERROR_BUSY;
        }
        if ((o & ERROR_UNKNOWN) == ERROR_UNKNOWN) {
            list.add("ERROR_UNKNOWN");
            flipped |= ERROR_UNKNOWN;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

