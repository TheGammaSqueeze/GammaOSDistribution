package android.hardware.radio.V1_0;


public final class RadioCapabilityStatus {
    public static final int NONE = 0;
    public static final int SUCCESS = 1;
    public static final int FAIL = 2;
    public static final String toString(int o) {
        if (o == NONE) {
            return "NONE";
        }
        if (o == SUCCESS) {
            return "SUCCESS";
        }
        if (o == FAIL) {
            return "FAIL";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NONE"); // NONE == 0
        if ((o & SUCCESS) == SUCCESS) {
            list.add("SUCCESS");
            flipped |= SUCCESS;
        }
        if ((o & FAIL) == FAIL) {
            list.add("FAIL");
            flipped |= FAIL;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

