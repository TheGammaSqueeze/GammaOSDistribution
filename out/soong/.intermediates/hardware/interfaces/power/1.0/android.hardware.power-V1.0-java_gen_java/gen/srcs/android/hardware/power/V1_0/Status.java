package android.hardware.power.V1_0;


public final class Status {
    public static final int SUCCESS = 0;
    public static final int FILESYSTEM_ERROR = 1;
    public static final String toString(int o) {
        if (o == SUCCESS) {
            return "SUCCESS";
        }
        if (o == FILESYSTEM_ERROR) {
            return "FILESYSTEM_ERROR";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("SUCCESS"); // SUCCESS == 0
        if ((o & FILESYSTEM_ERROR) == FILESYSTEM_ERROR) {
            list.add("FILESYSTEM_ERROR");
            flipped |= FILESYSTEM_ERROR;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

