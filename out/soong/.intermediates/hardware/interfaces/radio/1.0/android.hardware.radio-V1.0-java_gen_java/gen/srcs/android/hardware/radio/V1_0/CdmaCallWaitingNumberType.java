package android.hardware.radio.V1_0;


public final class CdmaCallWaitingNumberType {
    public static final int UNKNOWN = 0;
    public static final int INTERNATIONAL = 1;
    public static final int NATIONAL = 2;
    public static final int NETWORK_SPECIFIC = 3;
    public static final int SUBSCRIBER = 4;
    public static final String toString(int o) {
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        if (o == INTERNATIONAL) {
            return "INTERNATIONAL";
        }
        if (o == NATIONAL) {
            return "NATIONAL";
        }
        if (o == NETWORK_SPECIFIC) {
            return "NETWORK_SPECIFIC";
        }
        if (o == SUBSCRIBER) {
            return "SUBSCRIBER";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("UNKNOWN"); // UNKNOWN == 0
        if ((o & INTERNATIONAL) == INTERNATIONAL) {
            list.add("INTERNATIONAL");
            flipped |= INTERNATIONAL;
        }
        if ((o & NATIONAL) == NATIONAL) {
            list.add("NATIONAL");
            flipped |= NATIONAL;
        }
        if ((o & NETWORK_SPECIFIC) == NETWORK_SPECIFIC) {
            list.add("NETWORK_SPECIFIC");
            flipped |= NETWORK_SPECIFIC;
        }
        if ((o & SUBSCRIBER) == SUBSCRIBER) {
            list.add("SUBSCRIBER");
            flipped |= SUBSCRIBER;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

