package android.hardware.wifi.supplicant.V1_4;


public final class SupplicantStatusCode {
    /**
     * No errors.
     */
    public static final int SUCCESS = 0;
    /**
     * Unknown failure occured.
     */
    public static final int FAILURE_UNKNOWN = 1 /* ::android::hardware::wifi::supplicant::V1_0::SupplicantStatusCode.SUCCESS implicitly + 1 */;
    /**
     * One of the incoming args is invalid.
     */
    public static final int FAILURE_ARGS_INVALID = 2 /* ::android::hardware::wifi::supplicant::V1_0::SupplicantStatusCode.FAILURE_UNKNOWN implicitly + 1 */;
    /**
     * |ISupplicantIface| HIDL interface object is no longer valid.
     */
    public static final int FAILURE_IFACE_INVALID = 3 /* ::android::hardware::wifi::supplicant::V1_0::SupplicantStatusCode.FAILURE_ARGS_INVALID implicitly + 1 */;
    /**
     * Iface with the provided name does not exist.
     */
    public static final int FAILURE_IFACE_UNKNOWN = 4 /* ::android::hardware::wifi::supplicant::V1_0::SupplicantStatusCode.FAILURE_IFACE_INVALID implicitly + 1 */;
    /**
     * Iface with the provided name already exists.
     */
    public static final int FAILURE_IFACE_EXISTS = 5 /* ::android::hardware::wifi::supplicant::V1_0::SupplicantStatusCode.FAILURE_IFACE_UNKNOWN implicitly + 1 */;
    /**
     * Iface is disabled and cannot be used.
     */
    public static final int FAILURE_IFACE_DISABLED = 6 /* ::android::hardware::wifi::supplicant::V1_0::SupplicantStatusCode.FAILURE_IFACE_EXISTS implicitly + 1 */;
    /**
     * Iface is not currently disconnected, so cannot reconnect.
     */
    public static final int FAILURE_IFACE_NOT_DISCONNECTED = 7 /* ::android::hardware::wifi::supplicant::V1_0::SupplicantStatusCode.FAILURE_IFACE_DISABLED implicitly + 1 */;
    /**
     * |ISupplicantNetwork| HIDL interface object is no longer valid.
     */
    public static final int FAILURE_NETWORK_INVALID = 8 /* ::android::hardware::wifi::supplicant::V1_0::SupplicantStatusCode.FAILURE_IFACE_NOT_DISCONNECTED implicitly + 1 */;
    /**
     * Network with the provided id does not exist.
     */
    public static final int FAILURE_NETWORK_UNKNOWN = 9 /* ::android::hardware::wifi::supplicant::V1_0::SupplicantStatusCode.FAILURE_NETWORK_INVALID implicitly + 1 */;
    public static final int FAILURE_UNSUPPORTED = 10 /* ::android::hardware::wifi::supplicant::V1_0::SupplicantStatusCode.FAILURE_NETWORK_UNKNOWN implicitly + 1 */;
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
        if (o == FAILURE_IFACE_INVALID) {
            return "FAILURE_IFACE_INVALID";
        }
        if (o == FAILURE_IFACE_UNKNOWN) {
            return "FAILURE_IFACE_UNKNOWN";
        }
        if (o == FAILURE_IFACE_EXISTS) {
            return "FAILURE_IFACE_EXISTS";
        }
        if (o == FAILURE_IFACE_DISABLED) {
            return "FAILURE_IFACE_DISABLED";
        }
        if (o == FAILURE_IFACE_NOT_DISCONNECTED) {
            return "FAILURE_IFACE_NOT_DISCONNECTED";
        }
        if (o == FAILURE_NETWORK_INVALID) {
            return "FAILURE_NETWORK_INVALID";
        }
        if (o == FAILURE_NETWORK_UNKNOWN) {
            return "FAILURE_NETWORK_UNKNOWN";
        }
        if (o == FAILURE_UNSUPPORTED) {
            return "FAILURE_UNSUPPORTED";
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
        if ((o & FAILURE_IFACE_INVALID) == FAILURE_IFACE_INVALID) {
            list.add("FAILURE_IFACE_INVALID");
            flipped |= FAILURE_IFACE_INVALID;
        }
        if ((o & FAILURE_IFACE_UNKNOWN) == FAILURE_IFACE_UNKNOWN) {
            list.add("FAILURE_IFACE_UNKNOWN");
            flipped |= FAILURE_IFACE_UNKNOWN;
        }
        if ((o & FAILURE_IFACE_EXISTS) == FAILURE_IFACE_EXISTS) {
            list.add("FAILURE_IFACE_EXISTS");
            flipped |= FAILURE_IFACE_EXISTS;
        }
        if ((o & FAILURE_IFACE_DISABLED) == FAILURE_IFACE_DISABLED) {
            list.add("FAILURE_IFACE_DISABLED");
            flipped |= FAILURE_IFACE_DISABLED;
        }
        if ((o & FAILURE_IFACE_NOT_DISCONNECTED) == FAILURE_IFACE_NOT_DISCONNECTED) {
            list.add("FAILURE_IFACE_NOT_DISCONNECTED");
            flipped |= FAILURE_IFACE_NOT_DISCONNECTED;
        }
        if ((o & FAILURE_NETWORK_INVALID) == FAILURE_NETWORK_INVALID) {
            list.add("FAILURE_NETWORK_INVALID");
            flipped |= FAILURE_NETWORK_INVALID;
        }
        if ((o & FAILURE_NETWORK_UNKNOWN) == FAILURE_NETWORK_UNKNOWN) {
            list.add("FAILURE_NETWORK_UNKNOWN");
            flipped |= FAILURE_NETWORK_UNKNOWN;
        }
        if ((o & FAILURE_UNSUPPORTED) == FAILURE_UNSUPPORTED) {
            list.add("FAILURE_UNSUPPORTED");
            flipped |= FAILURE_UNSUPPORTED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

