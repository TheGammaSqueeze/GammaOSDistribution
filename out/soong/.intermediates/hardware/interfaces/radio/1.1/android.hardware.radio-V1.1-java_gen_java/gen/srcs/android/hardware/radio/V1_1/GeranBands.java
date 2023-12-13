package android.hardware.radio.V1_1;


public final class GeranBands {
    public static final int BAND_T380 = 1;
    public static final int BAND_T410 = 2;
    public static final int BAND_450 = 3;
    public static final int BAND_480 = 4;
    public static final int BAND_710 = 5;
    public static final int BAND_750 = 6;
    public static final int BAND_T810 = 7;
    public static final int BAND_850 = 8;
    public static final int BAND_P900 = 9;
    public static final int BAND_E900 = 10;
    public static final int BAND_R900 = 11;
    public static final int BAND_DCS1800 = 12;
    public static final int BAND_PCS1900 = 13;
    public static final int BAND_ER900 = 14;
    public static final String toString(int o) {
        if (o == BAND_T380) {
            return "BAND_T380";
        }
        if (o == BAND_T410) {
            return "BAND_T410";
        }
        if (o == BAND_450) {
            return "BAND_450";
        }
        if (o == BAND_480) {
            return "BAND_480";
        }
        if (o == BAND_710) {
            return "BAND_710";
        }
        if (o == BAND_750) {
            return "BAND_750";
        }
        if (o == BAND_T810) {
            return "BAND_T810";
        }
        if (o == BAND_850) {
            return "BAND_850";
        }
        if (o == BAND_P900) {
            return "BAND_P900";
        }
        if (o == BAND_E900) {
            return "BAND_E900";
        }
        if (o == BAND_R900) {
            return "BAND_R900";
        }
        if (o == BAND_DCS1800) {
            return "BAND_DCS1800";
        }
        if (o == BAND_PCS1900) {
            return "BAND_PCS1900";
        }
        if (o == BAND_ER900) {
            return "BAND_ER900";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & BAND_T380) == BAND_T380) {
            list.add("BAND_T380");
            flipped |= BAND_T380;
        }
        if ((o & BAND_T410) == BAND_T410) {
            list.add("BAND_T410");
            flipped |= BAND_T410;
        }
        if ((o & BAND_450) == BAND_450) {
            list.add("BAND_450");
            flipped |= BAND_450;
        }
        if ((o & BAND_480) == BAND_480) {
            list.add("BAND_480");
            flipped |= BAND_480;
        }
        if ((o & BAND_710) == BAND_710) {
            list.add("BAND_710");
            flipped |= BAND_710;
        }
        if ((o & BAND_750) == BAND_750) {
            list.add("BAND_750");
            flipped |= BAND_750;
        }
        if ((o & BAND_T810) == BAND_T810) {
            list.add("BAND_T810");
            flipped |= BAND_T810;
        }
        if ((o & BAND_850) == BAND_850) {
            list.add("BAND_850");
            flipped |= BAND_850;
        }
        if ((o & BAND_P900) == BAND_P900) {
            list.add("BAND_P900");
            flipped |= BAND_P900;
        }
        if ((o & BAND_E900) == BAND_E900) {
            list.add("BAND_E900");
            flipped |= BAND_E900;
        }
        if ((o & BAND_R900) == BAND_R900) {
            list.add("BAND_R900");
            flipped |= BAND_R900;
        }
        if ((o & BAND_DCS1800) == BAND_DCS1800) {
            list.add("BAND_DCS1800");
            flipped |= BAND_DCS1800;
        }
        if ((o & BAND_PCS1900) == BAND_PCS1900) {
            list.add("BAND_PCS1900");
            flipped |= BAND_PCS1900;
        }
        if ((o & BAND_ER900) == BAND_ER900) {
            list.add("BAND_ER900");
            flipped |= BAND_ER900;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

