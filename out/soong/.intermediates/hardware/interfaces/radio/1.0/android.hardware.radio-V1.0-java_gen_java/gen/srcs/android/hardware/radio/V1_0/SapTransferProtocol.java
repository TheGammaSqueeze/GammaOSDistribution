package android.hardware.radio.V1_0;


public final class SapTransferProtocol {
    public static final int T0 = 0;
    public static final int T1 = 1 /* ::android::hardware::radio::V1_0::SapTransferProtocol.T0 implicitly + 1 */;
    public static final String toString(int o) {
        if (o == T0) {
            return "T0";
        }
        if (o == T1) {
            return "T1";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("T0"); // T0 == 0
        if ((o & T1) == T1) {
            list.add("T1");
            flipped |= T1;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

