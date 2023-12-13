package android.hardware.radio.V1_0;


public final class CellInfoType {
    public static final int NONE = 0;
    public static final int GSM = 1;
    public static final int CDMA = 2;
    public static final int LTE = 3;
    public static final int WCDMA = 4;
    public static final int TD_SCDMA = 5;
    public static final String toString(int o) {
        if (o == NONE) {
            return "NONE";
        }
        if (o == GSM) {
            return "GSM";
        }
        if (o == CDMA) {
            return "CDMA";
        }
        if (o == LTE) {
            return "LTE";
        }
        if (o == WCDMA) {
            return "WCDMA";
        }
        if (o == TD_SCDMA) {
            return "TD_SCDMA";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NONE"); // NONE == 0
        if ((o & GSM) == GSM) {
            list.add("GSM");
            flipped |= GSM;
        }
        if ((o & CDMA) == CDMA) {
            list.add("CDMA");
            flipped |= CDMA;
        }
        if ((o & LTE) == LTE) {
            list.add("LTE");
            flipped |= LTE;
        }
        if ((o & WCDMA) == WCDMA) {
            list.add("WCDMA");
            flipped |= WCDMA;
        }
        if ((o & TD_SCDMA) == TD_SCDMA) {
            list.add("TD_SCDMA");
            flipped |= TD_SCDMA;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

