package android.hardware.radio.V1_0;


public final class AppState {
    public static final int UNKNOWN = 0;
    public static final int DETECTED = 1 /* ::android::hardware::radio::V1_0::AppState.UNKNOWN implicitly + 1 */;
    public static final int PIN = 2 /* ::android::hardware::radio::V1_0::AppState.DETECTED implicitly + 1 */;
    public static final int PUK = 3 /* ::android::hardware::radio::V1_0::AppState.PIN implicitly + 1 */;
    public static final int SUBSCRIPTION_PERSO = 4 /* ::android::hardware::radio::V1_0::AppState.PUK implicitly + 1 */;
    public static final int READY = 5 /* ::android::hardware::radio::V1_0::AppState.SUBSCRIPTION_PERSO implicitly + 1 */;
    public static final String toString(int o) {
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        if (o == DETECTED) {
            return "DETECTED";
        }
        if (o == PIN) {
            return "PIN";
        }
        if (o == PUK) {
            return "PUK";
        }
        if (o == SUBSCRIPTION_PERSO) {
            return "SUBSCRIPTION_PERSO";
        }
        if (o == READY) {
            return "READY";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("UNKNOWN"); // UNKNOWN == 0
        if ((o & DETECTED) == DETECTED) {
            list.add("DETECTED");
            flipped |= DETECTED;
        }
        if ((o & PIN) == PIN) {
            list.add("PIN");
            flipped |= PIN;
        }
        if ((o & PUK) == PUK) {
            list.add("PUK");
            flipped |= PUK;
        }
        if ((o & SUBSCRIPTION_PERSO) == SUBSCRIPTION_PERSO) {
            list.add("SUBSCRIPTION_PERSO");
            flipped |= SUBSCRIPTION_PERSO;
        }
        if ((o & READY) == READY) {
            list.add("READY");
            flipped |= READY;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

