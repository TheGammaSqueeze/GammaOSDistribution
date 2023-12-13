package android.hardware.radio.V1_0;


public final class CdmaCallWaitingNumberPlan {
    public static final int UNKNOWN = 0;
    public static final int ISDN = 1;
    public static final int DATA = 3;
    public static final int TELEX = 4;
    public static final int NATIONAL = 8;
    public static final int PRIVATE = 9;
    public static final String toString(int o) {
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        if (o == ISDN) {
            return "ISDN";
        }
        if (o == DATA) {
            return "DATA";
        }
        if (o == TELEX) {
            return "TELEX";
        }
        if (o == NATIONAL) {
            return "NATIONAL";
        }
        if (o == PRIVATE) {
            return "PRIVATE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("UNKNOWN"); // UNKNOWN == 0
        if ((o & ISDN) == ISDN) {
            list.add("ISDN");
            flipped |= ISDN;
        }
        if ((o & DATA) == DATA) {
            list.add("DATA");
            flipped |= DATA;
        }
        if ((o & TELEX) == TELEX) {
            list.add("TELEX");
            flipped |= TELEX;
        }
        if ((o & NATIONAL) == NATIONAL) {
            list.add("NATIONAL");
            flipped |= NATIONAL;
        }
        if ((o & PRIVATE) == PRIVATE) {
            list.add("PRIVATE");
            flipped |= PRIVATE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

