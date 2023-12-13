package android.hardware.radio.V1_0;


public final class ClipStatus {
    public static final int CLIP_PROVISIONED = 0;
    public static final int CLIP_UNPROVISIONED = 1 /* ::android::hardware::radio::V1_0::ClipStatus.CLIP_PROVISIONED implicitly + 1 */;
    public static final int UNKNOWN = 2 /* ::android::hardware::radio::V1_0::ClipStatus.CLIP_UNPROVISIONED implicitly + 1 */;
    public static final String toString(int o) {
        if (o == CLIP_PROVISIONED) {
            return "CLIP_PROVISIONED";
        }
        if (o == CLIP_UNPROVISIONED) {
            return "CLIP_UNPROVISIONED";
        }
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("CLIP_PROVISIONED"); // CLIP_PROVISIONED == 0
        if ((o & CLIP_UNPROVISIONED) == CLIP_UNPROVISIONED) {
            list.add("CLIP_UNPROVISIONED");
            flipped |= CLIP_UNPROVISIONED;
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

