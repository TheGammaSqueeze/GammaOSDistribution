package android.hardware.wifi.supplicant.V1_2;


public final class DppAkm {
    public static final int PSK = 0;
    public static final int PSK_SAE = 1 /* ::android::hardware::wifi::supplicant::V1_2::DppAkm.PSK implicitly + 1 */;
    public static final int SAE = 2 /* ::android::hardware::wifi::supplicant::V1_2::DppAkm.PSK_SAE implicitly + 1 */;
    public static final int DPP = 3 /* ::android::hardware::wifi::supplicant::V1_2::DppAkm.SAE implicitly + 1 */;
    public static final String toString(int o) {
        if (o == PSK) {
            return "PSK";
        }
        if (o == PSK_SAE) {
            return "PSK_SAE";
        }
        if (o == SAE) {
            return "SAE";
        }
        if (o == DPP) {
            return "DPP";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("PSK"); // PSK == 0
        if ((o & PSK_SAE) == PSK_SAE) {
            list.add("PSK_SAE");
            flipped |= PSK_SAE;
        }
        if ((o & SAE) == SAE) {
            list.add("SAE");
            flipped |= SAE;
        }
        if ((o & DPP) == DPP) {
            list.add("DPP");
            flipped |= DPP;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

