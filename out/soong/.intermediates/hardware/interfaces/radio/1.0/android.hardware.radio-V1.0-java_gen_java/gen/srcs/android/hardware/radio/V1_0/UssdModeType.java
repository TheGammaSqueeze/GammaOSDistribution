package android.hardware.radio.V1_0;


public final class UssdModeType {
    public static final int NOTIFY = 0;
    public static final int REQUEST = 1 /* ::android::hardware::radio::V1_0::UssdModeType.NOTIFY implicitly + 1 */;
    public static final int NW_RELEASE = 2 /* ::android::hardware::radio::V1_0::UssdModeType.REQUEST implicitly + 1 */;
    public static final int LOCAL_CLIENT = 3 /* ::android::hardware::radio::V1_0::UssdModeType.NW_RELEASE implicitly + 1 */;
    public static final int NOT_SUPPORTED = 4 /* ::android::hardware::radio::V1_0::UssdModeType.LOCAL_CLIENT implicitly + 1 */;
    public static final int NW_TIMEOUT = 5 /* ::android::hardware::radio::V1_0::UssdModeType.NOT_SUPPORTED implicitly + 1 */;
    public static final String toString(int o) {
        if (o == NOTIFY) {
            return "NOTIFY";
        }
        if (o == REQUEST) {
            return "REQUEST";
        }
        if (o == NW_RELEASE) {
            return "NW_RELEASE";
        }
        if (o == LOCAL_CLIENT) {
            return "LOCAL_CLIENT";
        }
        if (o == NOT_SUPPORTED) {
            return "NOT_SUPPORTED";
        }
        if (o == NW_TIMEOUT) {
            return "NW_TIMEOUT";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NOTIFY"); // NOTIFY == 0
        if ((o & REQUEST) == REQUEST) {
            list.add("REQUEST");
            flipped |= REQUEST;
        }
        if ((o & NW_RELEASE) == NW_RELEASE) {
            list.add("NW_RELEASE");
            flipped |= NW_RELEASE;
        }
        if ((o & LOCAL_CLIENT) == LOCAL_CLIENT) {
            list.add("LOCAL_CLIENT");
            flipped |= LOCAL_CLIENT;
        }
        if ((o & NOT_SUPPORTED) == NOT_SUPPORTED) {
            list.add("NOT_SUPPORTED");
            flipped |= NOT_SUPPORTED;
        }
        if ((o & NW_TIMEOUT) == NW_TIMEOUT) {
            list.add("NW_TIMEOUT");
            flipped |= NW_TIMEOUT;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

