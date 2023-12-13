package android.hardware.radio.V1_0;


public final class PreferredNetworkType {
    public static final int GSM_WCDMA = 0;
    public static final int GSM_ONLY = 1 /* ::android::hardware::radio::V1_0::PreferredNetworkType.GSM_WCDMA implicitly + 1 */;
    public static final int WCDMA = 2 /* ::android::hardware::radio::V1_0::PreferredNetworkType.GSM_ONLY implicitly + 1 */;
    public static final int GSM_WCDMA_AUTO = 3 /* ::android::hardware::radio::V1_0::PreferredNetworkType.WCDMA implicitly + 1 */;
    public static final int CDMA_EVDO_AUTO = 4 /* ::android::hardware::radio::V1_0::PreferredNetworkType.GSM_WCDMA_AUTO implicitly + 1 */;
    public static final int CDMA_ONLY = 5 /* ::android::hardware::radio::V1_0::PreferredNetworkType.CDMA_EVDO_AUTO implicitly + 1 */;
    public static final int EVDO_ONLY = 6 /* ::android::hardware::radio::V1_0::PreferredNetworkType.CDMA_ONLY implicitly + 1 */;
    public static final int GSM_WCDMA_CDMA_EVDO_AUTO = 7 /* ::android::hardware::radio::V1_0::PreferredNetworkType.EVDO_ONLY implicitly + 1 */;
    public static final int LTE_CDMA_EVDO = 8 /* ::android::hardware::radio::V1_0::PreferredNetworkType.GSM_WCDMA_CDMA_EVDO_AUTO implicitly + 1 */;
    public static final int LTE_GSM_WCDMA = 9 /* ::android::hardware::radio::V1_0::PreferredNetworkType.LTE_CDMA_EVDO implicitly + 1 */;
    public static final int LTE_CMDA_EVDO_GSM_WCDMA = 10 /* ::android::hardware::radio::V1_0::PreferredNetworkType.LTE_GSM_WCDMA implicitly + 1 */;
    public static final int LTE_ONLY = 11 /* ::android::hardware::radio::V1_0::PreferredNetworkType.LTE_CMDA_EVDO_GSM_WCDMA implicitly + 1 */;
    public static final int LTE_WCDMA = 12 /* ::android::hardware::radio::V1_0::PreferredNetworkType.LTE_ONLY implicitly + 1 */;
    public static final int TD_SCDMA_ONLY = 13 /* ::android::hardware::radio::V1_0::PreferredNetworkType.LTE_WCDMA implicitly + 1 */;
    public static final int TD_SCDMA_WCDMA = 14 /* ::android::hardware::radio::V1_0::PreferredNetworkType.TD_SCDMA_ONLY implicitly + 1 */;
    public static final int TD_SCDMA_LTE = 15 /* ::android::hardware::radio::V1_0::PreferredNetworkType.TD_SCDMA_WCDMA implicitly + 1 */;
    public static final int TD_SCDMA_GSM = 16 /* ::android::hardware::radio::V1_0::PreferredNetworkType.TD_SCDMA_LTE implicitly + 1 */;
    public static final int TD_SCDMA_GSM_LTE = 17 /* ::android::hardware::radio::V1_0::PreferredNetworkType.TD_SCDMA_GSM implicitly + 1 */;
    public static final int TD_SCDMA_GSM_WCDMA = 18 /* ::android::hardware::radio::V1_0::PreferredNetworkType.TD_SCDMA_GSM_LTE implicitly + 1 */;
    public static final int TD_SCDMA_WCDMA_LTE = 19 /* ::android::hardware::radio::V1_0::PreferredNetworkType.TD_SCDMA_GSM_WCDMA implicitly + 1 */;
    public static final int TD_SCDMA_GSM_WCDMA_LTE = 20 /* ::android::hardware::radio::V1_0::PreferredNetworkType.TD_SCDMA_WCDMA_LTE implicitly + 1 */;
    public static final int TD_SCDMA_GSM_WCDMA_CDMA_EVDO_AUTO = 21 /* ::android::hardware::radio::V1_0::PreferredNetworkType.TD_SCDMA_GSM_WCDMA_LTE implicitly + 1 */;
    public static final int TD_SCDMA_LTE_CDMA_EVDO_GSM_WCDMA = 22 /* ::android::hardware::radio::V1_0::PreferredNetworkType.TD_SCDMA_GSM_WCDMA_CDMA_EVDO_AUTO implicitly + 1 */;
    public static final String toString(int o) {
        if (o == GSM_WCDMA) {
            return "GSM_WCDMA";
        }
        if (o == GSM_ONLY) {
            return "GSM_ONLY";
        }
        if (o == WCDMA) {
            return "WCDMA";
        }
        if (o == GSM_WCDMA_AUTO) {
            return "GSM_WCDMA_AUTO";
        }
        if (o == CDMA_EVDO_AUTO) {
            return "CDMA_EVDO_AUTO";
        }
        if (o == CDMA_ONLY) {
            return "CDMA_ONLY";
        }
        if (o == EVDO_ONLY) {
            return "EVDO_ONLY";
        }
        if (o == GSM_WCDMA_CDMA_EVDO_AUTO) {
            return "GSM_WCDMA_CDMA_EVDO_AUTO";
        }
        if (o == LTE_CDMA_EVDO) {
            return "LTE_CDMA_EVDO";
        }
        if (o == LTE_GSM_WCDMA) {
            return "LTE_GSM_WCDMA";
        }
        if (o == LTE_CMDA_EVDO_GSM_WCDMA) {
            return "LTE_CMDA_EVDO_GSM_WCDMA";
        }
        if (o == LTE_ONLY) {
            return "LTE_ONLY";
        }
        if (o == LTE_WCDMA) {
            return "LTE_WCDMA";
        }
        if (o == TD_SCDMA_ONLY) {
            return "TD_SCDMA_ONLY";
        }
        if (o == TD_SCDMA_WCDMA) {
            return "TD_SCDMA_WCDMA";
        }
        if (o == TD_SCDMA_LTE) {
            return "TD_SCDMA_LTE";
        }
        if (o == TD_SCDMA_GSM) {
            return "TD_SCDMA_GSM";
        }
        if (o == TD_SCDMA_GSM_LTE) {
            return "TD_SCDMA_GSM_LTE";
        }
        if (o == TD_SCDMA_GSM_WCDMA) {
            return "TD_SCDMA_GSM_WCDMA";
        }
        if (o == TD_SCDMA_WCDMA_LTE) {
            return "TD_SCDMA_WCDMA_LTE";
        }
        if (o == TD_SCDMA_GSM_WCDMA_LTE) {
            return "TD_SCDMA_GSM_WCDMA_LTE";
        }
        if (o == TD_SCDMA_GSM_WCDMA_CDMA_EVDO_AUTO) {
            return "TD_SCDMA_GSM_WCDMA_CDMA_EVDO_AUTO";
        }
        if (o == TD_SCDMA_LTE_CDMA_EVDO_GSM_WCDMA) {
            return "TD_SCDMA_LTE_CDMA_EVDO_GSM_WCDMA";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("GSM_WCDMA"); // GSM_WCDMA == 0
        if ((o & GSM_ONLY) == GSM_ONLY) {
            list.add("GSM_ONLY");
            flipped |= GSM_ONLY;
        }
        if ((o & WCDMA) == WCDMA) {
            list.add("WCDMA");
            flipped |= WCDMA;
        }
        if ((o & GSM_WCDMA_AUTO) == GSM_WCDMA_AUTO) {
            list.add("GSM_WCDMA_AUTO");
            flipped |= GSM_WCDMA_AUTO;
        }
        if ((o & CDMA_EVDO_AUTO) == CDMA_EVDO_AUTO) {
            list.add("CDMA_EVDO_AUTO");
            flipped |= CDMA_EVDO_AUTO;
        }
        if ((o & CDMA_ONLY) == CDMA_ONLY) {
            list.add("CDMA_ONLY");
            flipped |= CDMA_ONLY;
        }
        if ((o & EVDO_ONLY) == EVDO_ONLY) {
            list.add("EVDO_ONLY");
            flipped |= EVDO_ONLY;
        }
        if ((o & GSM_WCDMA_CDMA_EVDO_AUTO) == GSM_WCDMA_CDMA_EVDO_AUTO) {
            list.add("GSM_WCDMA_CDMA_EVDO_AUTO");
            flipped |= GSM_WCDMA_CDMA_EVDO_AUTO;
        }
        if ((o & LTE_CDMA_EVDO) == LTE_CDMA_EVDO) {
            list.add("LTE_CDMA_EVDO");
            flipped |= LTE_CDMA_EVDO;
        }
        if ((o & LTE_GSM_WCDMA) == LTE_GSM_WCDMA) {
            list.add("LTE_GSM_WCDMA");
            flipped |= LTE_GSM_WCDMA;
        }
        if ((o & LTE_CMDA_EVDO_GSM_WCDMA) == LTE_CMDA_EVDO_GSM_WCDMA) {
            list.add("LTE_CMDA_EVDO_GSM_WCDMA");
            flipped |= LTE_CMDA_EVDO_GSM_WCDMA;
        }
        if ((o & LTE_ONLY) == LTE_ONLY) {
            list.add("LTE_ONLY");
            flipped |= LTE_ONLY;
        }
        if ((o & LTE_WCDMA) == LTE_WCDMA) {
            list.add("LTE_WCDMA");
            flipped |= LTE_WCDMA;
        }
        if ((o & TD_SCDMA_ONLY) == TD_SCDMA_ONLY) {
            list.add("TD_SCDMA_ONLY");
            flipped |= TD_SCDMA_ONLY;
        }
        if ((o & TD_SCDMA_WCDMA) == TD_SCDMA_WCDMA) {
            list.add("TD_SCDMA_WCDMA");
            flipped |= TD_SCDMA_WCDMA;
        }
        if ((o & TD_SCDMA_LTE) == TD_SCDMA_LTE) {
            list.add("TD_SCDMA_LTE");
            flipped |= TD_SCDMA_LTE;
        }
        if ((o & TD_SCDMA_GSM) == TD_SCDMA_GSM) {
            list.add("TD_SCDMA_GSM");
            flipped |= TD_SCDMA_GSM;
        }
        if ((o & TD_SCDMA_GSM_LTE) == TD_SCDMA_GSM_LTE) {
            list.add("TD_SCDMA_GSM_LTE");
            flipped |= TD_SCDMA_GSM_LTE;
        }
        if ((o & TD_SCDMA_GSM_WCDMA) == TD_SCDMA_GSM_WCDMA) {
            list.add("TD_SCDMA_GSM_WCDMA");
            flipped |= TD_SCDMA_GSM_WCDMA;
        }
        if ((o & TD_SCDMA_WCDMA_LTE) == TD_SCDMA_WCDMA_LTE) {
            list.add("TD_SCDMA_WCDMA_LTE");
            flipped |= TD_SCDMA_WCDMA_LTE;
        }
        if ((o & TD_SCDMA_GSM_WCDMA_LTE) == TD_SCDMA_GSM_WCDMA_LTE) {
            list.add("TD_SCDMA_GSM_WCDMA_LTE");
            flipped |= TD_SCDMA_GSM_WCDMA_LTE;
        }
        if ((o & TD_SCDMA_GSM_WCDMA_CDMA_EVDO_AUTO) == TD_SCDMA_GSM_WCDMA_CDMA_EVDO_AUTO) {
            list.add("TD_SCDMA_GSM_WCDMA_CDMA_EVDO_AUTO");
            flipped |= TD_SCDMA_GSM_WCDMA_CDMA_EVDO_AUTO;
        }
        if ((o & TD_SCDMA_LTE_CDMA_EVDO_GSM_WCDMA) == TD_SCDMA_LTE_CDMA_EVDO_GSM_WCDMA) {
            list.add("TD_SCDMA_LTE_CDMA_EVDO_GSM_WCDMA");
            flipped |= TD_SCDMA_LTE_CDMA_EVDO_GSM_WCDMA;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

