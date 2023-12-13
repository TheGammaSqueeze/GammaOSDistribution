package android.hardware.wifi.supplicant.V1_0;


public final class IfaceType {
    public static final int STA = 0;
    public static final int P2P = 1 /* ::android::hardware::wifi::supplicant::V1_0::IfaceType.STA implicitly + 1 */;
    public static final String toString(int o) {
        if (o == STA) {
            return "STA";
        }
        if (o == P2P) {
            return "P2P";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("STA"); // STA == 0
        if ((o & P2P) == P2P) {
            list.add("P2P");
            flipped |= P2P;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

