package android.hardware.vibrator.V1_0;


public final class EffectStrength {
    public static final byte LIGHT = 0;
    public static final byte MEDIUM = 1 /* ::android::hardware::vibrator::V1_0::EffectStrength.LIGHT implicitly + 1 */;
    public static final byte STRONG = 2 /* ::android::hardware::vibrator::V1_0::EffectStrength.MEDIUM implicitly + 1 */;
    public static final String toString(byte o) {
        if (o == LIGHT) {
            return "LIGHT";
        }
        if (o == MEDIUM) {
            return "MEDIUM";
        }
        if (o == STRONG) {
            return "STRONG";
        }
        return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
    }

    public static final String dumpBitfield(byte o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        byte flipped = 0;
        list.add("LIGHT"); // LIGHT == 0
        if ((o & MEDIUM) == MEDIUM) {
            list.add("MEDIUM");
            flipped |= MEDIUM;
        }
        if ((o & STRONG) == STRONG) {
            list.add("STRONG");
            flipped |= STRONG;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

