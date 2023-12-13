package android.hardware.wifi.V1_4;


public final class NanBandIndex {
    public static final int NAN_BAND_24GHZ = 0;
    public static final int NAN_BAND_5GHZ = 1 /* ::android::hardware::wifi::V1_0::NanBandIndex.NAN_BAND_24GHZ implicitly + 1 */;
    /**
     * Index for 6 GHz band.
     */
    public static final int NAN_BAND_6GHZ = 2;
    public static final String toString(int o) {
        if (o == NAN_BAND_24GHZ) {
            return "NAN_BAND_24GHZ";
        }
        if (o == NAN_BAND_5GHZ) {
            return "NAN_BAND_5GHZ";
        }
        if (o == NAN_BAND_6GHZ) {
            return "NAN_BAND_6GHZ";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NAN_BAND_24GHZ"); // NAN_BAND_24GHZ == 0
        if ((o & NAN_BAND_5GHZ) == NAN_BAND_5GHZ) {
            list.add("NAN_BAND_5GHZ");
            flipped |= NAN_BAND_5GHZ;
        }
        if ((o & NAN_BAND_6GHZ) == NAN_BAND_6GHZ) {
            list.add("NAN_BAND_6GHZ");
            flipped |= NAN_BAND_6GHZ;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

