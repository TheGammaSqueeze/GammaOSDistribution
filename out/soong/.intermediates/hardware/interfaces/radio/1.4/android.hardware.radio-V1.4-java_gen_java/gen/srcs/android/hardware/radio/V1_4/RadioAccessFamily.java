package android.hardware.radio.V1_4;


public final class RadioAccessFamily {
    public static final int UNKNOWN = 1 /* 1 << RadioTechnology:UNKNOWN */;
    public static final int GPRS = 2 /* 1 << RadioTechnology:GPRS */;
    public static final int EDGE = 4 /* 1 << RadioTechnology:EDGE */;
    public static final int UMTS = 8 /* 1 << RadioTechnology:UMTS */;
    public static final int IS95A = 16 /* 1 << RadioTechnology:IS95A */;
    public static final int IS95B = 32 /* 1 << RadioTechnology:IS95B */;
    public static final int ONE_X_RTT = 64 /* 1 << RadioTechnology:ONE_X_RTT */;
    public static final int EVDO_0 = 128 /* 1 << RadioTechnology:EVDO_0 */;
    public static final int EVDO_A = 256 /* 1 << RadioTechnology:EVDO_A */;
    public static final int HSDPA = 512 /* 1 << RadioTechnology:HSDPA */;
    public static final int HSUPA = 1024 /* 1 << RadioTechnology:HSUPA */;
    public static final int HSPA = 2048 /* 1 << RadioTechnology:HSPA */;
    public static final int EVDO_B = 4096 /* 1 << RadioTechnology:EVDO_B */;
    public static final int EHRPD = 8192 /* 1 << RadioTechnology:EHRPD */;
    public static final int LTE = 16384 /* 1 << RadioTechnology:LTE */;
    public static final int HSPAP = 32768 /* 1 << RadioTechnology:HSPAP */;
    public static final int GSM = 65536 /* 1 << RadioTechnology:GSM */;
    public static final int TD_SCDMA = 131072 /* 1 << RadioTechnology:TD_SCDMA */;
    public static final int LTE_CA = 524288 /* 1 << RadioTechnology:LTE_CA */;
    /**
     * 5G NR. This is only use in 5G Standalone mode.
     */
    public static final int NR = 1048576 /* 1 << RadioTechnology:NR */;
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
        if ((o & UNKNOWN) == UNKNOWN) {
            list.add("UNKNOWN");
            flipped |= UNKNOWN;
        }
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

