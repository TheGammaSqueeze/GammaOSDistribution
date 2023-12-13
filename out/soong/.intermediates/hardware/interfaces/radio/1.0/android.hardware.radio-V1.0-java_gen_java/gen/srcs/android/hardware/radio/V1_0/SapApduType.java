package android.hardware.radio.V1_0;


public final class SapApduType {
    public static final int APDU = 0;
    public static final int APDU7816 = 1 /* ::android::hardware::radio::V1_0::SapApduType.APDU implicitly + 1 */;
    public static final String toString(int o) {
        if (o == APDU) {
            return "APDU";
        }
        if (o == APDU7816) {
            return "APDU7816";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("APDU"); // APDU == 0
        if ((o & APDU7816) == APDU7816) {
            list.add("APDU7816");
            flipped |= APDU7816;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

