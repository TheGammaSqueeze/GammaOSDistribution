package android.hardware.wifi.V1_0;


public final class WifiDebugRxPacketFate {
    /**
     * Valid and delivered to network stack (e.g., netif_rx()).
     */
    public static final int SUCCESS = 0;
    /**
     * Queued within firmware, but not yet sent to driver.
     */
    public static final int FW_QUEUED = 1 /* ::android::hardware::wifi::V1_0::WifiDebugRxPacketFate.SUCCESS implicitly + 1 */;
    /**
     * Dropped by firmware due to host-programmable filters.
     */
    public static final int FW_DROP_FILTER = 2 /* ::android::hardware::wifi::V1_0::WifiDebugRxPacketFate.FW_QUEUED implicitly + 1 */;
    /**
     * Dropped by firmware as invalid. E.g. bad checksum, decrypt failed,
     * or invalid for current state.
     */
    public static final int FW_DROP_INVALID = 3 /* ::android::hardware::wifi::V1_0::WifiDebugRxPacketFate.FW_DROP_FILTER implicitly + 1 */;
    /**
     * Dropped by firmware due to lack of buffer space.
     */
    public static final int FW_DROP_NOBUFS = 4 /* ::android::hardware::wifi::V1_0::WifiDebugRxPacketFate.FW_DROP_INVALID implicitly + 1 */;
    /**
     * Dropped by firmware for any other reason.
     */
    public static final int FW_DROP_OTHER = 5 /* ::android::hardware::wifi::V1_0::WifiDebugRxPacketFate.FW_DROP_NOBUFS implicitly + 1 */;
    /**
     * Queued within driver, not yet delivered to network stack.
     */
    public static final int DRV_QUEUED = 6 /* ::android::hardware::wifi::V1_0::WifiDebugRxPacketFate.FW_DROP_OTHER implicitly + 1 */;
    /**
     * Dropped by driver due to filter rules.
     */
    public static final int DRV_DROP_FILTER = 7 /* ::android::hardware::wifi::V1_0::WifiDebugRxPacketFate.DRV_QUEUED implicitly + 1 */;
    /**
     * Dropped by driver as invalid. E.g. not permitted in current state.
     */
    public static final int DRV_DROP_INVALID = 8 /* ::android::hardware::wifi::V1_0::WifiDebugRxPacketFate.DRV_DROP_FILTER implicitly + 1 */;
    /**
     * Dropped by driver due to lack of buffer space.
     */
    public static final int DRV_DROP_NOBUFS = 9 /* ::android::hardware::wifi::V1_0::WifiDebugRxPacketFate.DRV_DROP_INVALID implicitly + 1 */;
    /**
     * Dropped by driver for any other reason.
     */
    public static final int DRV_DROP_OTHER = 10 /* ::android::hardware::wifi::V1_0::WifiDebugRxPacketFate.DRV_DROP_NOBUFS implicitly + 1 */;
    public static final String toString(int o) {
        if (o == SUCCESS) {
            return "SUCCESS";
        }
        if (o == FW_QUEUED) {
            return "FW_QUEUED";
        }
        if (o == FW_DROP_FILTER) {
            return "FW_DROP_FILTER";
        }
        if (o == FW_DROP_INVALID) {
            return "FW_DROP_INVALID";
        }
        if (o == FW_DROP_NOBUFS) {
            return "FW_DROP_NOBUFS";
        }
        if (o == FW_DROP_OTHER) {
            return "FW_DROP_OTHER";
        }
        if (o == DRV_QUEUED) {
            return "DRV_QUEUED";
        }
        if (o == DRV_DROP_FILTER) {
            return "DRV_DROP_FILTER";
        }
        if (o == DRV_DROP_INVALID) {
            return "DRV_DROP_INVALID";
        }
        if (o == DRV_DROP_NOBUFS) {
            return "DRV_DROP_NOBUFS";
        }
        if (o == DRV_DROP_OTHER) {
            return "DRV_DROP_OTHER";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("SUCCESS"); // SUCCESS == 0
        if ((o & FW_QUEUED) == FW_QUEUED) {
            list.add("FW_QUEUED");
            flipped |= FW_QUEUED;
        }
        if ((o & FW_DROP_FILTER) == FW_DROP_FILTER) {
            list.add("FW_DROP_FILTER");
            flipped |= FW_DROP_FILTER;
        }
        if ((o & FW_DROP_INVALID) == FW_DROP_INVALID) {
            list.add("FW_DROP_INVALID");
            flipped |= FW_DROP_INVALID;
        }
        if ((o & FW_DROP_NOBUFS) == FW_DROP_NOBUFS) {
            list.add("FW_DROP_NOBUFS");
            flipped |= FW_DROP_NOBUFS;
        }
        if ((o & FW_DROP_OTHER) == FW_DROP_OTHER) {
            list.add("FW_DROP_OTHER");
            flipped |= FW_DROP_OTHER;
        }
        if ((o & DRV_QUEUED) == DRV_QUEUED) {
            list.add("DRV_QUEUED");
            flipped |= DRV_QUEUED;
        }
        if ((o & DRV_DROP_FILTER) == DRV_DROP_FILTER) {
            list.add("DRV_DROP_FILTER");
            flipped |= DRV_DROP_FILTER;
        }
        if ((o & DRV_DROP_INVALID) == DRV_DROP_INVALID) {
            list.add("DRV_DROP_INVALID");
            flipped |= DRV_DROP_INVALID;
        }
        if ((o & DRV_DROP_NOBUFS) == DRV_DROP_NOBUFS) {
            list.add("DRV_DROP_NOBUFS");
            flipped |= DRV_DROP_NOBUFS;
        }
        if ((o & DRV_DROP_OTHER) == DRV_DROP_OTHER) {
            list.add("DRV_DROP_OTHER");
            flipped |= DRV_DROP_OTHER;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

