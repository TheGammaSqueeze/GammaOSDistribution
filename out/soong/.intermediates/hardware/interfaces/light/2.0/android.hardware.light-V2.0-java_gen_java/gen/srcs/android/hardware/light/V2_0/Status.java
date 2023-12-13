package android.hardware.light.V2_0;


public final class Status {
    public static final int SUCCESS = 0;
    public static final int LIGHT_NOT_SUPPORTED = 1 /* ::android::hardware::light::V2_0::Status.SUCCESS implicitly + 1 */;
    public static final int BRIGHTNESS_NOT_SUPPORTED = 2 /* ::android::hardware::light::V2_0::Status.LIGHT_NOT_SUPPORTED implicitly + 1 */;
    public static final int UNKNOWN = 3 /* ::android::hardware::light::V2_0::Status.BRIGHTNESS_NOT_SUPPORTED implicitly + 1 */;
    public static final String toString(int o) {
        if (o == SUCCESS) {
            return "SUCCESS";
        }
        if (o == LIGHT_NOT_SUPPORTED) {
            return "LIGHT_NOT_SUPPORTED";
        }
        if (o == BRIGHTNESS_NOT_SUPPORTED) {
            return "BRIGHTNESS_NOT_SUPPORTED";
        }
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("SUCCESS"); // SUCCESS == 0
        if ((o & LIGHT_NOT_SUPPORTED) == LIGHT_NOT_SUPPORTED) {
            list.add("LIGHT_NOT_SUPPORTED");
            flipped |= LIGHT_NOT_SUPPORTED;
        }
        if ((o & BRIGHTNESS_NOT_SUPPORTED) == BRIGHTNESS_NOT_SUPPORTED) {
            list.add("BRIGHTNESS_NOT_SUPPORTED");
            flipped |= BRIGHTNESS_NOT_SUPPORTED;
        }
        if ((o & UNKNOWN) == UNKNOWN) {
            list.add("UNKNOWN");
            flipped |= UNKNOWN;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

