package android.hardware.radio.V1_0;


public final class DataProfileId {
    public static final int DEFAULT = 0;
    public static final int TETHERED = 1;
    public static final int IMS = 2;
    public static final int FOTA = 3;
    public static final int CBS = 4;
    public static final int OEM_BASE = 1000;
    public static final int INVALID = -1 /* 0xFFFFFFFF */;
    public static final String toString(int o) {
        if (o == DEFAULT) {
            return "DEFAULT";
        }
        if (o == TETHERED) {
            return "TETHERED";
        }
        if (o == IMS) {
            return "IMS";
        }
        if (o == FOTA) {
            return "FOTA";
        }
        if (o == CBS) {
            return "CBS";
        }
        if (o == OEM_BASE) {
            return "OEM_BASE";
        }
        if (o == INVALID) {
            return "INVALID";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("DEFAULT"); // DEFAULT == 0
        if ((o & TETHERED) == TETHERED) {
            list.add("TETHERED");
            flipped |= TETHERED;
        }
        if ((o & IMS) == IMS) {
            list.add("IMS");
            flipped |= IMS;
        }
        if ((o & FOTA) == FOTA) {
            list.add("FOTA");
            flipped |= FOTA;
        }
        if ((o & CBS) == CBS) {
            list.add("CBS");
            flipped |= CBS;
        }
        if ((o & OEM_BASE) == OEM_BASE) {
            list.add("OEM_BASE");
            flipped |= OEM_BASE;
        }
        if ((o & INVALID) == INVALID) {
            list.add("INVALID");
            flipped |= INVALID;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

