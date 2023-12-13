package android.hardware.radio.V1_0;


public final class CarrierMatchType {
    public static final int ALL = 0;
    public static final int SPN = 1;
    public static final int IMSI_PREFIX = 2;
    public static final int GID1 = 3;
    public static final int GID2 = 4;
    public static final String toString(int o) {
        if (o == ALL) {
            return "ALL";
        }
        if (o == SPN) {
            return "SPN";
        }
        if (o == IMSI_PREFIX) {
            return "IMSI_PREFIX";
        }
        if (o == GID1) {
            return "GID1";
        }
        if (o == GID2) {
            return "GID2";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("ALL"); // ALL == 0
        if ((o & SPN) == SPN) {
            list.add("SPN");
            flipped |= SPN;
        }
        if ((o & IMSI_PREFIX) == IMSI_PREFIX) {
            list.add("IMSI_PREFIX");
            flipped |= IMSI_PREFIX;
        }
        if ((o & GID1) == GID1) {
            list.add("GID1");
            flipped |= GID1;
        }
        if ((o & GID2) == GID2) {
            list.add("GID2");
            flipped |= GID2;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

