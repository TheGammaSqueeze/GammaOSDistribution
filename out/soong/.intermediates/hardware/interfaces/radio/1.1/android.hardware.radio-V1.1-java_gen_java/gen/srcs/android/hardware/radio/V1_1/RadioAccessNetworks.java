package android.hardware.radio.V1_1;


public final class RadioAccessNetworks {
    public static final int GERAN = 1;
    public static final int UTRAN = 2;
    public static final int EUTRAN = 3;
    public static final String toString(int o) {
        if (o == GERAN) {
            return "GERAN";
        }
        if (o == UTRAN) {
            return "UTRAN";
        }
        if (o == EUTRAN) {
            return "EUTRAN";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & GERAN) == GERAN) {
            list.add("GERAN");
            flipped |= GERAN;
        }
        if ((o & UTRAN) == UTRAN) {
            list.add("UTRAN");
            flipped |= UTRAN;
        }
        if ((o & EUTRAN) == EUTRAN) {
            list.add("EUTRAN");
            flipped |= EUTRAN;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

