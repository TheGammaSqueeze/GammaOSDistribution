package android.hardware.radio.V1_0;


public final class CdmaSubscriptionSource {
    public static final int RUIM_SIM = 0;
    public static final int NV = 1 /* ::android::hardware::radio::V1_0::CdmaSubscriptionSource.RUIM_SIM implicitly + 1 */;
    public static final String toString(int o) {
        if (o == RUIM_SIM) {
            return "RUIM_SIM";
        }
        if (o == NV) {
            return "NV";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("RUIM_SIM"); // RUIM_SIM == 0
        if ((o & NV) == NV) {
            list.add("NV");
            flipped |= NV;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

