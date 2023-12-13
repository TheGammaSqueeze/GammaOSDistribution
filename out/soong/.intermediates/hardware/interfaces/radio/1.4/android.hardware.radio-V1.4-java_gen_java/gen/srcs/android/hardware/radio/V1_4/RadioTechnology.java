package android.hardware.radio.V1_4;


public final class RadioTechnology {
    public static final int UNKNOWN = 0;
    public static final int GPRS = 1;
    public static final int EDGE = 2;
    public static final int UMTS = 3;
    public static final int IS95A = 4;
    public static final int IS95B = 5;
    public static final int ONE_X_RTT = 6;
    public static final int EVDO_0 = 7;
    public static final int EVDO_A = 8;
    public static final int HSDPA = 9;
    public static final int HSUPA = 10;
    public static final int HSPA = 11;
    public static final int EVDO_B = 12;
    public static final int EHRPD = 13;
    public static final int LTE = 14;
    public static final int HSPAP = 15;
    public static final int GSM = 16;
    public static final int TD_SCDMA = 17;
    public static final int IWLAN = 18;
    public static final int LTE_CA = 19;
    /**
     * 5G NR. This is only use in 5G Standalone mode.
     */
    public static final int NR = 20;
    public static final String toString(int o) {
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        if (o == GPRS) {
            return "GPRS";
        }
        if (o == EDGE) {
            return "EDGE";
        }
        if (o == UMTS) {
            return "UMTS";
        }
        if (o == IS95A) {
            return "IS95A";
        }
        if (o == IS95B) {
            return "IS95B";
        }
        if (o == ONE_X_RTT) {
            return "ONE_X_RTT";
        }
        if (o == EVDO_0) {
            return "EVDO_0";
        }
        if (o == EVDO_A) {
            return "EVDO_A";
        }
        if (o == HSDPA) {
            return "HSDPA";
        }
        if (o == HSUPA) {
            return "HSUPA";
        }
        if (o == HSPA) {
            return "HSPA";
        }
        if (o == EVDO_B) {
            return "EVDO_B";
        }
        if (o == EHRPD) {
            return "EHRPD";
        }
        if (o == LTE) {
            return "LTE";
        }
        if (o == HSPAP) {
            return "HSPAP";
        }
        if (o == GSM) {
            return "GSM";
        }
        if (o == TD_SCDMA) {
            return "TD_SCDMA";
        }
        if (o == IWLAN) {
            return "IWLAN";
        }
        if (o == LTE_CA) {
            return "LTE_CA";
        }
        if (o == NR) {
            return "NR";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("UNKNOWN"); // UNKNOWN == 0
        if ((o & GPRS) == GPRS) {
            list.add("GPRS");
            flipped |= GPRS;
        }
        if ((o & EDGE) == EDGE) {
            list.add("EDGE");
            flipped |= EDGE;
        }
        if ((o & UMTS) == UMTS) {
            list.add("UMTS");
            flipped |= UMTS;
        }
        if ((o & IS95A) == IS95A) {
            list.add("IS95A");
            flipped |= IS95A;
        }
        if ((o & IS95B) == IS95B) {
            list.add("IS95B");
            flipped |= IS95B;
        }
        if ((o & ONE_X_RTT) == ONE_X_RTT) {
            list.add("ONE_X_RTT");
            flipped |= ONE_X_RTT;
        }
        if ((o & EVDO_0) == EVDO_0) {
            list.add("EVDO_0");
            flipped |= EVDO_0;
        }
        if ((o & EVDO_A) == EVDO_A) {
            list.add("EVDO_A");
            flipped |= EVDO_A;
        }
        if ((o & HSDPA) == HSDPA) {
            list.add("HSDPA");
            flipped |= HSDPA;
        }
        if ((o & HSUPA) == HSUPA) {
            list.add("HSUPA");
            flipped |= HSUPA;
        }
        if ((o & HSPA) == HSPA) {
            list.add("HSPA");
            flipped |= HSPA;
        }
        if ((o & EVDO_B) == EVDO_B) {
            list.add("EVDO_B");
            flipped |= EVDO_B;
        }
        if ((o & EHRPD) == EHRPD) {
            list.add("EHRPD");
            flipped |= EHRPD;
        }
        if ((o & LTE) == LTE) {
            list.add("LTE");
            flipped |= LTE;
        }
        if ((o & HSPAP) == HSPAP) {
            list.add("HSPAP");
            flipped |= HSPAP;
        }
        if ((o & GSM) == GSM) {
            list.add("GSM");
            flipped |= GSM;
        }
        if ((o & TD_SCDMA) == TD_SCDMA) {
            list.add("TD_SCDMA");
            flipped |= TD_SCDMA;
        }
        if ((o & IWLAN) == IWLAN) {
            list.add("IWLAN");
            flipped |= IWLAN;
        }
        if ((o & LTE_CA) == LTE_CA) {
            list.add("LTE_CA");
            flipped |= LTE_CA;
        }
        if ((o & NR) == NR) {
            list.add("NR");
            flipped |= NR;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

