package android.hardware.radio.V1_2;


public final class AudioQuality {
    /**
     * Unspecified audio codec
     */
    public static final int UNSPECIFIED = 0;
    /**
     * AMR (Narrowband) audio codec
     */
    public static final int AMR = 1 /* ::android::hardware::radio::V1_2::AudioQuality.UNSPECIFIED implicitly + 1 */;
    /**
     * AMR (Wideband) audio codec
     */
    public static final int AMR_WB = 2 /* ::android::hardware::radio::V1_2::AudioQuality.AMR implicitly + 1 */;
    /**
     * GSM Enhanced Full-Rate audio codec
     */
    public static final int GSM_EFR = 3 /* ::android::hardware::radio::V1_2::AudioQuality.AMR_WB implicitly + 1 */;
    /**
     * GSM Full-Rate audio codec
     */
    public static final int GSM_FR = 4 /* ::android::hardware::radio::V1_2::AudioQuality.GSM_EFR implicitly + 1 */;
    /**
     * GSM Half-Rate audio codec
     */
    public static final int GSM_HR = 5 /* ::android::hardware::radio::V1_2::AudioQuality.GSM_FR implicitly + 1 */;
    /**
     * Enhanced Variable rate codec
     */
    public static final int EVRC = 6 /* ::android::hardware::radio::V1_2::AudioQuality.GSM_HR implicitly + 1 */;
    /**
     * Enhanced Variable rate codec revision B
     */
    public static final int EVRC_B = 7 /* ::android::hardware::radio::V1_2::AudioQuality.EVRC implicitly + 1 */;
    /**
     * Enhanced Variable rate codec (Wideband)
     */
    public static final int EVRC_WB = 8 /* ::android::hardware::radio::V1_2::AudioQuality.EVRC_B implicitly + 1 */;
    /**
     * Enhanced Variable rate codec (Narrowband)
     */
    public static final int EVRC_NW = 9 /* ::android::hardware::radio::V1_2::AudioQuality.EVRC_WB implicitly + 1 */;
    public static final String toString(int o) {
        if (o == UNSPECIFIED) {
            return "UNSPECIFIED";
        }
        if (o == AMR) {
            return "AMR";
        }
        if (o == AMR_WB) {
            return "AMR_WB";
        }
        if (o == GSM_EFR) {
            return "GSM_EFR";
        }
        if (o == GSM_FR) {
            return "GSM_FR";
        }
        if (o == GSM_HR) {
            return "GSM_HR";
        }
        if (o == EVRC) {
            return "EVRC";
        }
        if (o == EVRC_B) {
            return "EVRC_B";
        }
        if (o == EVRC_WB) {
            return "EVRC_WB";
        }
        if (o == EVRC_NW) {
            return "EVRC_NW";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("UNSPECIFIED"); // UNSPECIFIED == 0
        if ((o & AMR) == AMR) {
            list.add("AMR");
            flipped |= AMR;
        }
        if ((o & AMR_WB) == AMR_WB) {
            list.add("AMR_WB");
            flipped |= AMR_WB;
        }
        if ((o & GSM_EFR) == GSM_EFR) {
            list.add("GSM_EFR");
            flipped |= GSM_EFR;
        }
        if ((o & GSM_FR) == GSM_FR) {
            list.add("GSM_FR");
            flipped |= GSM_FR;
        }
        if ((o & GSM_HR) == GSM_HR) {
            list.add("GSM_HR");
            flipped |= GSM_HR;
        }
        if ((o & EVRC) == EVRC) {
            list.add("EVRC");
            flipped |= EVRC;
        }
        if ((o & EVRC_B) == EVRC_B) {
            list.add("EVRC_B");
            flipped |= EVRC_B;
        }
        if ((o & EVRC_WB) == EVRC_WB) {
            list.add("EVRC_WB");
            flipped |= EVRC_WB;
        }
        if ((o & EVRC_NW) == EVRC_NW) {
            list.add("EVRC_NW");
            flipped |= EVRC_NW;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

