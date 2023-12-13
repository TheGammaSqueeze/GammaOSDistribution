package android.hardware.contexthub.V1_1;


public final class SettingValue {
    public static final byte DISABLED = 0;
    public static final byte ENABLED = 1 /* ::android::hardware::contexthub::V1_1::SettingValue.DISABLED implicitly + 1 */;
    public static final String toString(byte o) {
        if (o == DISABLED) {
            return "DISABLED";
        }
        if (o == ENABLED) {
            return "ENABLED";
        }
        return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
    }

    public static final String dumpBitfield(byte o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        byte flipped = 0;
        list.add("DISABLED"); // DISABLED == 0
        if ((o & ENABLED) == ENABLED) {
            list.add("ENABLED");
            flipped |= ENABLED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

