package android.hardware.radio.V1_5;


public final class PrlIndicator {
    public static final int NOT_REGISTERED = -1 /* -1 */;
    public static final int NOT_IN_PRL = 0;
    public static final int IN_PRL = 1;
    public static final String toString(int o) {
        if (o == NOT_REGISTERED) {
            return "NOT_REGISTERED";
        }
        if (o == NOT_IN_PRL) {
            return "NOT_IN_PRL";
        }
        if (o == IN_PRL) {
            return "IN_PRL";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & NOT_REGISTERED) == NOT_REGISTERED) {
            list.add("NOT_REGISTERED");
            flipped |= NOT_REGISTERED;
        }
        list.add("NOT_IN_PRL"); // NOT_IN_PRL == 0
        if ((o & IN_PRL) == IN_PRL) {
            list.add("IN_PRL");
            flipped |= IN_PRL;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

