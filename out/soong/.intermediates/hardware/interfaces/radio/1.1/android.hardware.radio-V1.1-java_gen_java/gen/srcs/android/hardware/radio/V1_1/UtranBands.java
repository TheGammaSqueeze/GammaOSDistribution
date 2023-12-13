package android.hardware.radio.V1_1;


public final class UtranBands {
    public static final int BAND_1 = 1;
    public static final int BAND_2 = 2;
    public static final int BAND_3 = 3;
    public static final int BAND_4 = 4;
    public static final int BAND_5 = 5;
    public static final int BAND_6 = 6;
    public static final int BAND_7 = 7;
    public static final int BAND_8 = 8;
    public static final int BAND_9 = 9;
    public static final int BAND_10 = 10;
    public static final int BAND_11 = 11;
    public static final int BAND_12 = 12;
    public static final int BAND_13 = 13;
    public static final int BAND_14 = 14;
    public static final int BAND_19 = 19;
    public static final int BAND_20 = 20;
    public static final int BAND_21 = 21;
    public static final int BAND_22 = 22;
    public static final int BAND_25 = 25;
    public static final int BAND_26 = 26;
    public static final String toString(int o) {
        if (o == BAND_1) {
            return "BAND_1";
        }
        if (o == BAND_2) {
            return "BAND_2";
        }
        if (o == BAND_3) {
            return "BAND_3";
        }
        if (o == BAND_4) {
            return "BAND_4";
        }
        if (o == BAND_5) {
            return "BAND_5";
        }
        if (o == BAND_6) {
            return "BAND_6";
        }
        if (o == BAND_7) {
            return "BAND_7";
        }
        if (o == BAND_8) {
            return "BAND_8";
        }
        if (o == BAND_9) {
            return "BAND_9";
        }
        if (o == BAND_10) {
            return "BAND_10";
        }
        if (o == BAND_11) {
            return "BAND_11";
        }
        if (o == BAND_12) {
            return "BAND_12";
        }
        if (o == BAND_13) {
            return "BAND_13";
        }
        if (o == BAND_14) {
            return "BAND_14";
        }
        if (o == BAND_19) {
            return "BAND_19";
        }
        if (o == BAND_20) {
            return "BAND_20";
        }
        if (o == BAND_21) {
            return "BAND_21";
        }
        if (o == BAND_22) {
            return "BAND_22";
        }
        if (o == BAND_25) {
            return "BAND_25";
        }
        if (o == BAND_26) {
            return "BAND_26";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & BAND_1) == BAND_1) {
            list.add("BAND_1");
            flipped |= BAND_1;
        }
        if ((o & BAND_2) == BAND_2) {
            list.add("BAND_2");
            flipped |= BAND_2;
        }
        if ((o & BAND_3) == BAND_3) {
            list.add("BAND_3");
            flipped |= BAND_3;
        }
        if ((o & BAND_4) == BAND_4) {
            list.add("BAND_4");
            flipped |= BAND_4;
        }
        if ((o & BAND_5) == BAND_5) {
            list.add("BAND_5");
            flipped |= BAND_5;
        }
        if ((o & BAND_6) == BAND_6) {
            list.add("BAND_6");
            flipped |= BAND_6;
        }
        if ((o & BAND_7) == BAND_7) {
            list.add("BAND_7");
            flipped |= BAND_7;
        }
        if ((o & BAND_8) == BAND_8) {
            list.add("BAND_8");
            flipped |= BAND_8;
        }
        if ((o & BAND_9) == BAND_9) {
            list.add("BAND_9");
            flipped |= BAND_9;
        }
        if ((o & BAND_10) == BAND_10) {
            list.add("BAND_10");
            flipped |= BAND_10;
        }
        if ((o & BAND_11) == BAND_11) {
            list.add("BAND_11");
            flipped |= BAND_11;
        }
        if ((o & BAND_12) == BAND_12) {
            list.add("BAND_12");
            flipped |= BAND_12;
        }
        if ((o & BAND_13) == BAND_13) {
            list.add("BAND_13");
            flipped |= BAND_13;
        }
        if ((o & BAND_14) == BAND_14) {
            list.add("BAND_14");
            flipped |= BAND_14;
        }
        if ((o & BAND_19) == BAND_19) {
            list.add("BAND_19");
            flipped |= BAND_19;
        }
        if ((o & BAND_20) == BAND_20) {
            list.add("BAND_20");
            flipped |= BAND_20;
        }
        if ((o & BAND_21) == BAND_21) {
            list.add("BAND_21");
            flipped |= BAND_21;
        }
        if ((o & BAND_22) == BAND_22) {
            list.add("BAND_22");
            flipped |= BAND_22;
        }
        if ((o & BAND_25) == BAND_25) {
            list.add("BAND_25");
            flipped |= BAND_25;
        }
        if ((o & BAND_26) == BAND_26) {
            list.add("BAND_26");
            flipped |= BAND_26;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

