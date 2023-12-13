package android.hardware.radio.V1_0;


public final class TimeStampType {
    public static final int UNKNOWN = 0;
    public static final int ANTENNA = 1 /* ::android::hardware::radio::V1_0::TimeStampType.UNKNOWN implicitly + 1 */;
    public static final int MODEM = 2 /* ::android::hardware::radio::V1_0::TimeStampType.ANTENNA implicitly + 1 */;
    public static final int OEM_RIL = 3 /* ::android::hardware::radio::V1_0::TimeStampType.MODEM implicitly + 1 */;
    public static final int JAVA_RIL = 4 /* ::android::hardware::radio::V1_0::TimeStampType.OEM_RIL implicitly + 1 */;
    public static final String toString(int o) {
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        if (o == ANTENNA) {
            return "ANTENNA";
        }
        if (o == MODEM) {
            return "MODEM";
        }
        if (o == OEM_RIL) {
            return "OEM_RIL";
        }
        if (o == JAVA_RIL) {
            return "JAVA_RIL";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("UNKNOWN"); // UNKNOWN == 0
        if ((o & ANTENNA) == ANTENNA) {
            list.add("ANTENNA");
            flipped |= ANTENNA;
        }
        if ((o & MODEM) == MODEM) {
            list.add("MODEM");
            flipped |= MODEM;
        }
        if ((o & OEM_RIL) == OEM_RIL) {
            list.add("OEM_RIL");
            flipped |= OEM_RIL;
        }
        if ((o & JAVA_RIL) == JAVA_RIL) {
            list.add("JAVA_RIL");
            flipped |= JAVA_RIL;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

