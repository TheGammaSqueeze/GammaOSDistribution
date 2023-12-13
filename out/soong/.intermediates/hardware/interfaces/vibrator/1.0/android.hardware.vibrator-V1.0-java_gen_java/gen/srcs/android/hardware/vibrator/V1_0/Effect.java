package android.hardware.vibrator.V1_0;


public final class Effect {
    /**
     * A single click effect.
     *
     * This effect should produce a sharp, crisp click sensation.
     */
    public static final int CLICK = 0;
    /**
     * A double click effect.
     *
     * This effect should produce two sequential sharp, crisp click sensations with a minimal
     * amount of time between them.
     */
    public static final int DOUBLE_CLICK = 1 /* ::android::hardware::vibrator::V1_0::Effect.CLICK implicitly + 1 */;
    public static final String toString(int o) {
        if (o == CLICK) {
            return "CLICK";
        }
        if (o == DOUBLE_CLICK) {
            return "DOUBLE_CLICK";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("CLICK"); // CLICK == 0
        if ((o & DOUBLE_CLICK) == DOUBLE_CLICK) {
            list.add("DOUBLE_CLICK");
            flipped |= DOUBLE_CLICK;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

