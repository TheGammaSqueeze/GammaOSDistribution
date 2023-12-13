package android.hardware.radio.V1_0;


public final class AppType {
    public static final int UNKNOWN = 0;
    public static final int SIM = 1 /* ::android::hardware::radio::V1_0::AppType.UNKNOWN implicitly + 1 */;
    public static final int USIM = 2 /* ::android::hardware::radio::V1_0::AppType.SIM implicitly + 1 */;
    public static final int RUIM = 3 /* ::android::hardware::radio::V1_0::AppType.USIM implicitly + 1 */;
    public static final int CSIM = 4 /* ::android::hardware::radio::V1_0::AppType.RUIM implicitly + 1 */;
    public static final int ISIM = 5 /* ::android::hardware::radio::V1_0::AppType.CSIM implicitly + 1 */;
    public static final String toString(int o) {
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        if (o == SIM) {
            return "SIM";
        }
        if (o == USIM) {
            return "USIM";
        }
        if (o == RUIM) {
            return "RUIM";
        }
        if (o == CSIM) {
            return "CSIM";
        }
        if (o == ISIM) {
            return "ISIM";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("UNKNOWN"); // UNKNOWN == 0
        if ((o & SIM) == SIM) {
            list.add("SIM");
            flipped |= SIM;
        }
        if ((o & USIM) == USIM) {
            list.add("USIM");
            flipped |= USIM;
        }
        if ((o & RUIM) == RUIM) {
            list.add("RUIM");
            flipped |= RUIM;
        }
        if ((o & CSIM) == CSIM) {
            list.add("CSIM");
            flipped |= CSIM;
        }
        if ((o & ISIM) == ISIM) {
            list.add("ISIM");
            flipped |= ISIM;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

