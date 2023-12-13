package android.hardware.radio.V1_0;


public final class CdmaSmsNumberMode {
    public static final int NOT_DATA_NETWORK = 0;
    public static final int DATA_NETWORK = 1 /* ::android::hardware::radio::V1_0::CdmaSmsNumberMode.NOT_DATA_NETWORK implicitly + 1 */;
    public static final String toString(int o) {
        if (o == NOT_DATA_NETWORK) {
            return "NOT_DATA_NETWORK";
        }
        if (o == DATA_NETWORK) {
            return "DATA_NETWORK";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NOT_DATA_NETWORK"); // NOT_DATA_NETWORK == 0
        if ((o & DATA_NETWORK) == DATA_NETWORK) {
            list.add("DATA_NETWORK");
            flipped |= DATA_NETWORK;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

