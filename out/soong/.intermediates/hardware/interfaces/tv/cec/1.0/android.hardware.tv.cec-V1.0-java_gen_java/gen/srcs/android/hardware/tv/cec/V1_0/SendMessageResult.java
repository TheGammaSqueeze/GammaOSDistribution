package android.hardware.tv.cec.V1_0;


public final class SendMessageResult {
    public static final int SUCCESS = 0;
    public static final int NACK = 1;
    public static final int BUSY = 2;
    public static final int FAIL = 3;
    public static final String toString(int o) {
        if (o == SUCCESS) {
            return "SUCCESS";
        }
        if (o == NACK) {
            return "NACK";
        }
        if (o == BUSY) {
            return "BUSY";
        }
        if (o == FAIL) {
            return "FAIL";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("SUCCESS"); // SUCCESS == 0
        if ((o & NACK) == NACK) {
            list.add("NACK");
            flipped |= NACK;
        }
        if ((o & BUSY) == BUSY) {
            list.add("BUSY");
            flipped |= BUSY;
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

