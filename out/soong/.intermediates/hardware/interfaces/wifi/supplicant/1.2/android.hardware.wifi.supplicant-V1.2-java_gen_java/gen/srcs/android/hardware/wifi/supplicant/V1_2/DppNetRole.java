package android.hardware.wifi.supplicant.V1_2;


public final class DppNetRole {
    public static final int STA = 0;
    public static final int AP = 1 /* ::android::hardware::wifi::supplicant::V1_2::DppNetRole.STA implicitly + 1 */;
    public static final String toString(int o) {
        if (o == STA) {
            return "STA";
        }
        if (o == AP) {
            return "AP";
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
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

