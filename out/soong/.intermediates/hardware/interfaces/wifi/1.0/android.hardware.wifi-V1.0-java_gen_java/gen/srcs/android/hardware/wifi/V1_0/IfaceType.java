package android.hardware.wifi.V1_0;


public final class IfaceType {
    public static final int STA = 0;
    public static final int AP = 1 /* ::android::hardware::wifi::V1_0::IfaceType.STA implicitly + 1 */;
    public static final int P2P = 2 /* ::android::hardware::wifi::V1_0::IfaceType.AP implicitly + 1 */;
    /**
     * NAN control interface. Datapath support must be queried and created
     * through this interface.
     */
    public static final int NAN = 3 /* ::android::hardware::wifi::V1_0::IfaceType.P2P implicitly + 1 */;
    public static final String toString(int o) {
        if (o == STA) {
            return "STA";
        }
        if (o == AP) {
            return "AP";
        }
        if (o == P2P) {
            return "P2P";
        }
        if (o == NAN) {
            return "NAN";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("STA"); // STA == 0
        if ((o & AP) == AP) {
            list.add("AP");
            flipped |= AP;
        }
        if ((o & P2P) == P2P) {
            list.add("P2P");
            flipped |= P2P;
        }
        if ((o & NAN) == NAN) {
            list.add("NAN");
            flipped |= NAN;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

