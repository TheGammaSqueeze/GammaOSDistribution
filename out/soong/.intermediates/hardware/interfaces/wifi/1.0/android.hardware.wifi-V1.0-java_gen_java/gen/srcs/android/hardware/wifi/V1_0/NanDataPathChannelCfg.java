package android.hardware.wifi.V1_0;


public final class NanDataPathChannelCfg {
    public static final int CHANNEL_NOT_REQUESTED = 0;
    public static final int REQUEST_CHANNEL_SETUP = 1 /* ::android::hardware::wifi::V1_0::NanDataPathChannelCfg.CHANNEL_NOT_REQUESTED implicitly + 1 */;
    public static final int FORCE_CHANNEL_SETUP = 2 /* ::android::hardware::wifi::V1_0::NanDataPathChannelCfg.REQUEST_CHANNEL_SETUP implicitly + 1 */;
    public static final String toString(int o) {
        if (o == CHANNEL_NOT_REQUESTED) {
            return "CHANNEL_NOT_REQUESTED";
        }
        if (o == REQUEST_CHANNEL_SETUP) {
            return "REQUEST_CHANNEL_SETUP";
        }
        if (o == FORCE_CHANNEL_SETUP) {
            return "FORCE_CHANNEL_SETUP";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("CHANNEL_NOT_REQUESTED"); // CHANNEL_NOT_REQUESTED == 0
        if ((o & REQUEST_CHANNEL_SETUP) == REQUEST_CHANNEL_SETUP) {
            list.add("REQUEST_CHANNEL_SETUP");
            flipped |= REQUEST_CHANNEL_SETUP;
        }
        if ((o & FORCE_CHANNEL_SETUP) == FORCE_CHANNEL_SETUP) {
            list.add("FORCE_CHANNEL_SETUP");
            flipped |= FORCE_CHANNEL_SETUP;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

