package android.hardware.configstore.V1_1;


public final class DisplayOrientation {
    public static final byte ORIENTATION_0 = 0;
    public static final byte ORIENTATION_90 = 1 /* ::android::hardware::configstore::V1_1::DisplayOrientation.ORIENTATION_0 implicitly + 1 */;
    public static final byte ORIENTATION_180 = 2 /* ::android::hardware::configstore::V1_1::DisplayOrientation.ORIENTATION_90 implicitly + 1 */;
    public static final byte ORIENTATION_270 = 3 /* ::android::hardware::configstore::V1_1::DisplayOrientation.ORIENTATION_180 implicitly + 1 */;
    public static final String toString(byte o) {
        if (o == ORIENTATION_0) {
            return "ORIENTATION_0";
        }
        if (o == ORIENTATION_90) {
            return "ORIENTATION_90";
        }
        if (o == ORIENTATION_180) {
            return "ORIENTATION_180";
        }
        if (o == ORIENTATION_270) {
            return "ORIENTATION_270";
        }
        return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
    }

    public static final String dumpBitfield(byte o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        byte flipped = 0;
        list.add("ORIENTATION_0"); // ORIENTATION_0 == 0
        if ((o & ORIENTATION_90) == ORIENTATION_90) {
            list.add("ORIENTATION_90");
            flipped |= ORIENTATION_90;
        }
        if ((o & ORIENTATION_180) == ORIENTATION_180) {
            list.add("ORIENTATION_180");
            flipped |= ORIENTATION_180;
        }
        if ((o & ORIENTATION_270) == ORIENTATION_270) {
            list.add("ORIENTATION_270");
            flipped |= ORIENTATION_270;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

