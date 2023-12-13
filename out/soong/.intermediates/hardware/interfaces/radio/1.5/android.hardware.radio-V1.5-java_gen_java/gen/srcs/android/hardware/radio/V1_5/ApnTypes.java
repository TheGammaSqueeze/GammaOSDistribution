package android.hardware.radio.V1_5;


public final class ApnTypes {
    public static final int NONE = 0;
    public static final int DEFAULT = 1 /* 1 << 0 */;
    public static final int MMS = 2 /* 1 << 1 */;
    public static final int SUPL = 4 /* 1 << 2 */;
    public static final int DUN = 8 /* 1 << 3 */;
    public static final int HIPRI = 16 /* 1 << 4 */;
    public static final int FOTA = 32 /* 1 << 5 */;
    public static final int IMS = 64 /* 1 << 6 */;
    public static final int CBS = 128 /* 1 << 7 */;
    public static final int IA = 256 /* 1 << 8 */;
    public static final int EMERGENCY = 512 /* 1 << 9 */;
    public static final int ALL = 1023 /* DEFAULT | MMS | SUPL | DUN | HIPRI | FOTA | IMS | CBS | IA | EMERGENCY */;
    /**
     * Due to the addition of this new value, the value ALL defined in 1.0::ApnTypes is now
     * deprecated and should not be used.
     */
    public static final int MCX = 1024 /* 1 << 10 */;
    /**
     * APN type for XCAP
     * NOTE: Due to the addition of this new value, the value ALL defined in
     * 1.0::ApnTypes is deprecated and should not be used.
     */
    public static final int XCAP = 2048 /* 1 << 11 */;
    public static final String toString(int o) {
        if (o == NONE) {
            return "NONE";
        }
        if (o == DEFAULT) {
            return "DEFAULT";
        }
        if (o == MMS) {
            return "MMS";
        }
        if (o == SUPL) {
            return "SUPL";
        }
        if (o == DUN) {
            return "DUN";
        }
        if (o == HIPRI) {
            return "HIPRI";
        }
        if (o == FOTA) {
            return "FOTA";
        }
        if (o == IMS) {
            return "IMS";
        }
        if (o == CBS) {
            return "CBS";
        }
        if (o == IA) {
            return "IA";
        }
        if (o == EMERGENCY) {
            return "EMERGENCY";
        }
        if (o == ALL) {
            return "ALL";
        }
        if (o == MCX) {
            return "MCX";
        }
        if (o == XCAP) {
            return "XCAP";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NONE"); // NONE == 0
        if ((o & DEFAULT) == DEFAULT) {
            list.add("DEFAULT");
            flipped |= DEFAULT;
        }
        if ((o & MMS) == MMS) {
            list.add("MMS");
            flipped |= MMS;
        }
        if ((o & SUPL) == SUPL) {
            list.add("SUPL");
            flipped |= SUPL;
        }
        if ((o & DUN) == DUN) {
            list.add("DUN");
            flipped |= DUN;
        }
        if ((o & HIPRI) == HIPRI) {
            list.add("HIPRI");
            flipped |= HIPRI;
        }
        if ((o & FOTA) == FOTA) {
            list.add("FOTA");
            flipped |= FOTA;
        }
        if ((o & IMS) == IMS) {
            list.add("IMS");
            flipped |= IMS;
        }
        if ((o & CBS) == CBS) {
            list.add("CBS");
            flipped |= CBS;
        }
        if ((o & IA) == IA) {
            list.add("IA");
            flipped |= IA;
        }
        if ((o & EMERGENCY) == EMERGENCY) {
            list.add("EMERGENCY");
            flipped |= EMERGENCY;
        }
        if ((o & ALL) == ALL) {
            list.add("ALL");
            flipped |= ALL;
        }
        if ((o & MCX) == MCX) {
            list.add("MCX");
            flipped |= MCX;
        }
        if ((o & XCAP) == XCAP) {
            list.add("XCAP");
            flipped |= XCAP;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

