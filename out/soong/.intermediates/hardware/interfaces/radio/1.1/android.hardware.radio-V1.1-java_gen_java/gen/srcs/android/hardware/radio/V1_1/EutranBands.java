package android.hardware.radio.V1_1;


public final class EutranBands {
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
    public static final int BAND_17 = 17;
    public static final int BAND_18 = 18;
    public static final int BAND_19 = 19;
    public static final int BAND_20 = 20;
    public static final int BAND_21 = 21;
    public static final int BAND_22 = 22;
    public static final int BAND_23 = 23;
    public static final int BAND_24 = 24;
    public static final int BAND_25 = 25;
    public static final int BAND_26 = 26;
    public static final int BAND_27 = 27;
    public static final int BAND_28 = 28;
    public static final int BAND_30 = 30;
    public static final int BAND_31 = 31;
    public static final int BAND_33 = 33;
    public static final int BAND_34 = 34;
    public static final int BAND_35 = 35;
    public static final int BAND_36 = 36;
    public static final int BAND_37 = 37;
    public static final int BAND_38 = 38;
    public static final int BAND_39 = 39;
    public static final int BAND_40 = 40;
    public static final int BAND_41 = 41;
    public static final int BAND_42 = 42;
    public static final int BAND_43 = 43;
    public static final int BAND_44 = 44;
    public static final int BAND_45 = 45;
    public static final int BAND_46 = 46;
    public static final int BAND_47 = 47;
    public static final int BAND_48 = 48;
    public static final int BAND_65 = 65;
    public static final int BAND_66 = 66;
    public static final int BAND_68 = 68;
    public static final int BAND_70 = 70;
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
        if (o == BAND_17) {
            return "BAND_17";
        }
        if (o == BAND_18) {
            return "BAND_18";
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
        if (o == BAND_23) {
            return "BAND_23";
        }
        if (o == BAND_24) {
            return "BAND_24";
        }
        if (o == BAND_25) {
            return "BAND_25";
        }
        if (o == BAND_26) {
            return "BAND_26";
        }
        if (o == BAND_27) {
            return "BAND_27";
        }
        if (o == BAND_28) {
            return "BAND_28";
        }
        if (o == BAND_30) {
            return "BAND_30";
        }
        if (o == BAND_31) {
            return "BAND_31";
        }
        if (o == BAND_33) {
            return "BAND_33";
        }
        if (o == BAND_34) {
            return "BAND_34";
        }
        if (o == BAND_35) {
            return "BAND_35";
        }
        if (o == BAND_36) {
            return "BAND_36";
        }
        if (o == BAND_37) {
            return "BAND_37";
        }
        if (o == BAND_38) {
            return "BAND_38";
        }
        if (o == BAND_39) {
            return "BAND_39";
        }
        if (o == BAND_40) {
            return "BAND_40";
        }
        if (o == BAND_41) {
            return "BAND_41";
        }
        if (o == BAND_42) {
            return "BAND_42";
        }
        if (o == BAND_43) {
            return "BAND_43";
        }
        if (o == BAND_44) {
            return "BAND_44";
        }
        if (o == BAND_45) {
            return "BAND_45";
        }
        if (o == BAND_46) {
            return "BAND_46";
        }
        if (o == BAND_47) {
            return "BAND_47";
        }
        if (o == BAND_48) {
            return "BAND_48";
        }
        if (o == BAND_65) {
            return "BAND_65";
        }
        if (o == BAND_66) {
            return "BAND_66";
        }
        if (o == BAND_68) {
            return "BAND_68";
        }
        if (o == BAND_70) {
            return "BAND_70";
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
        if ((o & BAND_17) == BAND_17) {
            list.add("BAND_17");
            flipped |= BAND_17;
        }
        if ((o & BAND_18) == BAND_18) {
            list.add("BAND_18");
            flipped |= BAND_18;
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
        if ((o & BAND_23) == BAND_23) {
            list.add("BAND_23");
            flipped |= BAND_23;
        }
        if ((o & BAND_24) == BAND_24) {
            list.add("BAND_24");
            flipped |= BAND_24;
        }
        if ((o & BAND_25) == BAND_25) {
            list.add("BAND_25");
            flipped |= BAND_25;
        }
        if ((o & BAND_26) == BAND_26) {
            list.add("BAND_26");
            flipped |= BAND_26;
        }
        if ((o & BAND_27) == BAND_27) {
            list.add("BAND_27");
            flipped |= BAND_27;
        }
        if ((o & BAND_28) == BAND_28) {
            list.add("BAND_28");
            flipped |= BAND_28;
        }
        if ((o & BAND_30) == BAND_30) {
            list.add("BAND_30");
            flipped |= BAND_30;
        }
        if ((o & BAND_31) == BAND_31) {
            list.add("BAND_31");
            flipped |= BAND_31;
        }
        if ((o & BAND_33) == BAND_33) {
            list.add("BAND_33");
            flipped |= BAND_33;
        }
        if ((o & BAND_34) == BAND_34) {
            list.add("BAND_34");
            flipped |= BAND_34;
        }
        if ((o & BAND_35) == BAND_35) {
            list.add("BAND_35");
            flipped |= BAND_35;
        }
        if ((o & BAND_36) == BAND_36) {
            list.add("BAND_36");
            flipped |= BAND_36;
        }
        if ((o & BAND_37) == BAND_37) {
            list.add("BAND_37");
            flipped |= BAND_37;
        }
        if ((o & BAND_38) == BAND_38) {
            list.add("BAND_38");
            flipped |= BAND_38;
        }
        if ((o & BAND_39) == BAND_39) {
            list.add("BAND_39");
            flipped |= BAND_39;
        }
        if ((o & BAND_40) == BAND_40) {
            list.add("BAND_40");
            flipped |= BAND_40;
        }
        if ((o & BAND_41) == BAND_41) {
            list.add("BAND_41");
            flipped |= BAND_41;
        }
        if ((o & BAND_42) == BAND_42) {
            list.add("BAND_42");
            flipped |= BAND_42;
        }
        if ((o & BAND_43) == BAND_43) {
            list.add("BAND_43");
            flipped |= BAND_43;
        }
        if ((o & BAND_44) == BAND_44) {
            list.add("BAND_44");
            flipped |= BAND_44;
        }
        if ((o & BAND_45) == BAND_45) {
            list.add("BAND_45");
            flipped |= BAND_45;
        }
        if ((o & BAND_46) == BAND_46) {
            list.add("BAND_46");
            flipped |= BAND_46;
        }
        if ((o & BAND_47) == BAND_47) {
            list.add("BAND_47");
            flipped |= BAND_47;
        }
        if ((o & BAND_48) == BAND_48) {
            list.add("BAND_48");
            flipped |= BAND_48;
        }
        if ((o & BAND_65) == BAND_65) {
            list.add("BAND_65");
            flipped |= BAND_65;
        }
        if ((o & BAND_66) == BAND_66) {
            list.add("BAND_66");
            flipped |= BAND_66;
        }
        if ((o & BAND_68) == BAND_68) {
            list.add("BAND_68");
            flipped |= BAND_68;
        }
        if ((o & BAND_70) == BAND_70) {
            list.add("BAND_70");
            flipped |= BAND_70;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

