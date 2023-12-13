package android.hardware.radio.V1_0;


public final class CdmaSmsErrorClass {
    public static final int NO_ERROR = 0;
    public static final int ERROR = 1 /* ::android::hardware::radio::V1_0::CdmaSmsErrorClass.NO_ERROR implicitly + 1 */;
    public static final String toString(int o) {
        if (o == NO_ERROR) {
            return "NO_ERROR";
        }
        if (o == ERROR) {
            return "ERROR";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NO_ERROR"); // NO_ERROR == 0
        if ((o & ERROR) == ERROR) {
            list.add("ERROR");
            flipped |= ERROR;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

