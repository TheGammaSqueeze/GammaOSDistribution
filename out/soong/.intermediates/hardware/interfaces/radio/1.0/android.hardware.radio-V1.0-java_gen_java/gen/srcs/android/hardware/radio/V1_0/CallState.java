package android.hardware.radio.V1_0;


public final class CallState {
    public static final int ACTIVE = 0;
    public static final int HOLDING = 1 /* ::android::hardware::radio::V1_0::CallState.ACTIVE implicitly + 1 */;
    public static final int DIALING = 2 /* ::android::hardware::radio::V1_0::CallState.HOLDING implicitly + 1 */;
    public static final int ALERTING = 3 /* ::android::hardware::radio::V1_0::CallState.DIALING implicitly + 1 */;
    public static final int INCOMING = 4 /* ::android::hardware::radio::V1_0::CallState.ALERTING implicitly + 1 */;
    public static final int WAITING = 5 /* ::android::hardware::radio::V1_0::CallState.INCOMING implicitly + 1 */;
    public static final String toString(int o) {
        if (o == ACTIVE) {
            return "ACTIVE";
        }
        if (o == HOLDING) {
            return "HOLDING";
        }
        if (o == DIALING) {
            return "DIALING";
        }
        if (o == ALERTING) {
            return "ALERTING";
        }
        if (o == INCOMING) {
            return "INCOMING";
        }
        if (o == WAITING) {
            return "WAITING";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("ACTIVE"); // ACTIVE == 0
        if ((o & HOLDING) == HOLDING) {
            list.add("HOLDING");
            flipped |= HOLDING;
        }
        if ((o & DIALING) == DIALING) {
            list.add("DIALING");
            flipped |= DIALING;
        }
        if ((o & ALERTING) == ALERTING) {
            list.add("ALERTING");
            flipped |= ALERTING;
        }
        if ((o & INCOMING) == INCOMING) {
            list.add("INCOMING");
            flipped |= INCOMING;
        }
        if ((o & WAITING) == WAITING) {
            list.add("WAITING");
            flipped |= WAITING;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

