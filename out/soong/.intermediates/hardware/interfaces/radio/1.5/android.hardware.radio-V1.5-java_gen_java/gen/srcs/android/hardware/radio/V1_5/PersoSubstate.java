package android.hardware.radio.V1_5;


public final class PersoSubstate {
    public static final int UNKNOWN = 0;
    public static final int IN_PROGRESS = 1 /* ::android::hardware::radio::V1_0::PersoSubstate.UNKNOWN implicitly + 1 */;
    public static final int READY = 2 /* ::android::hardware::radio::V1_0::PersoSubstate.IN_PROGRESS implicitly + 1 */;
    public static final int SIM_NETWORK = 3 /* ::android::hardware::radio::V1_0::PersoSubstate.READY implicitly + 1 */;
    public static final int SIM_NETWORK_SUBSET = 4 /* ::android::hardware::radio::V1_0::PersoSubstate.SIM_NETWORK implicitly + 1 */;
    public static final int SIM_CORPORATE = 5 /* ::android::hardware::radio::V1_0::PersoSubstate.SIM_NETWORK_SUBSET implicitly + 1 */;
    public static final int SIM_SERVICE_PROVIDER = 6 /* ::android::hardware::radio::V1_0::PersoSubstate.SIM_CORPORATE implicitly + 1 */;
    public static final int SIM_SIM = 7 /* ::android::hardware::radio::V1_0::PersoSubstate.SIM_SERVICE_PROVIDER implicitly + 1 */;
    public static final int SIM_NETWORK_PUK = 8 /* ::android::hardware::radio::V1_0::PersoSubstate.SIM_SIM implicitly + 1 */;
    public static final int SIM_NETWORK_SUBSET_PUK = 9 /* ::android::hardware::radio::V1_0::PersoSubstate.SIM_NETWORK_PUK implicitly + 1 */;
    public static final int SIM_CORPORATE_PUK = 10 /* ::android::hardware::radio::V1_0::PersoSubstate.SIM_NETWORK_SUBSET_PUK implicitly + 1 */;
    public static final int SIM_SERVICE_PROVIDER_PUK = 11 /* ::android::hardware::radio::V1_0::PersoSubstate.SIM_CORPORATE_PUK implicitly + 1 */;
    public static final int SIM_SIM_PUK = 12 /* ::android::hardware::radio::V1_0::PersoSubstate.SIM_SERVICE_PROVIDER_PUK implicitly + 1 */;
    public static final int RUIM_NETWORK1 = 13 /* ::android::hardware::radio::V1_0::PersoSubstate.SIM_SIM_PUK implicitly + 1 */;
    public static final int RUIM_NETWORK2 = 14 /* ::android::hardware::radio::V1_0::PersoSubstate.RUIM_NETWORK1 implicitly + 1 */;
    public static final int RUIM_HRPD = 15 /* ::android::hardware::radio::V1_0::PersoSubstate.RUIM_NETWORK2 implicitly + 1 */;
    public static final int RUIM_CORPORATE = 16 /* ::android::hardware::radio::V1_0::PersoSubstate.RUIM_HRPD implicitly + 1 */;
    public static final int RUIM_SERVICE_PROVIDER = 17 /* ::android::hardware::radio::V1_0::PersoSubstate.RUIM_CORPORATE implicitly + 1 */;
    public static final int RUIM_RUIM = 18 /* ::android::hardware::radio::V1_0::PersoSubstate.RUIM_SERVICE_PROVIDER implicitly + 1 */;
    public static final int RUIM_NETWORK1_PUK = 19 /* ::android::hardware::radio::V1_0::PersoSubstate.RUIM_RUIM implicitly + 1 */;
    public static final int RUIM_NETWORK2_PUK = 20 /* ::android::hardware::radio::V1_0::PersoSubstate.RUIM_NETWORK1_PUK implicitly + 1 */;
    public static final int RUIM_HRPD_PUK = 21 /* ::android::hardware::radio::V1_0::PersoSubstate.RUIM_NETWORK2_PUK implicitly + 1 */;
    public static final int RUIM_CORPORATE_PUK = 22 /* ::android::hardware::radio::V1_0::PersoSubstate.RUIM_HRPD_PUK implicitly + 1 */;
    public static final int RUIM_SERVICE_PROVIDER_PUK = 23 /* ::android::hardware::radio::V1_0::PersoSubstate.RUIM_CORPORATE_PUK implicitly + 1 */;
    public static final int RUIM_RUIM_PUK = 24 /* ::android::hardware::radio::V1_0::PersoSubstate.RUIM_SERVICE_PROVIDER_PUK implicitly + 1 */;
    /**
     * The device is personalized using the content of the Service Provider Name (SPN) in the SIM
     * card.
     */
    public static final int SIM_SPN = 25 /* ::android::hardware::radio::V1_0::PersoSubstate.RUIM_RUIM_PUK implicitly + 1 */;
    public static final int SIM_SPN_PUK = 26 /* ::android::hardware::radio::V1_5::PersoSubstate.SIM_SPN implicitly + 1 */;
    /**
     * Service Provider and Equivalent Home PLMN
     * The device is personalized using both the content of the GID1 (equivalent to service provider
     * personalization) and the content of the Equivalent Home PLMN (EHPLMN) in the SIM card.
     * If the GID1 in the SIM is absent, then just the content of the Equivalent Home PLMN
     * is matched.
     */
    public static final int SIM_SP_EHPLMN = 27 /* ::android::hardware::radio::V1_5::PersoSubstate.SIM_SPN_PUK implicitly + 1 */;
    public static final int SIM_SP_EHPLMN_PUK = 28 /* ::android::hardware::radio::V1_5::PersoSubstate.SIM_SP_EHPLMN implicitly + 1 */;
    /**
     * Device is personalized using the first digits of the ICCID of the SIM card.
     */
    public static final int SIM_ICCID = 29 /* ::android::hardware::radio::V1_5::PersoSubstate.SIM_SP_EHPLMN_PUK implicitly + 1 */;
    public static final int SIM_ICCID_PUK = 30 /* ::android::hardware::radio::V1_5::PersoSubstate.SIM_ICCID implicitly + 1 */;
    /**
     * Device is personalized using the content of the IMPI in the ISIM.
     */
    public static final int SIM_IMPI = 31 /* ::android::hardware::radio::V1_5::PersoSubstate.SIM_ICCID_PUK implicitly + 1 */;
    public static final int SIM_IMPI_PUK = 32 /* ::android::hardware::radio::V1_5::PersoSubstate.SIM_IMPI implicitly + 1 */;
    /**
     * Network Subset and Service Provider
     * Device is personalized using both the content of GID1 (equivalent to service provider
     * personalization) and the first digits of the IMSI (equivalent to network subset
     * personalization).
     */
    public static final int SIM_NS_SP = 33 /* ::android::hardware::radio::V1_5::PersoSubstate.SIM_IMPI_PUK implicitly + 1 */;
    public static final int SIM_NS_SP_PUK = 34 /* ::android::hardware::radio::V1_5::PersoSubstate.SIM_NS_SP implicitly + 1 */;
    public static final String toString(int o) {
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        if (o == IN_PROGRESS) {
            return "IN_PROGRESS";
        }
        if (o == READY) {
            return "READY";
        }
        if (o == SIM_NETWORK) {
            return "SIM_NETWORK";
        }
        if (o == SIM_NETWORK_SUBSET) {
            return "SIM_NETWORK_SUBSET";
        }
        if (o == SIM_CORPORATE) {
            return "SIM_CORPORATE";
        }
        if (o == SIM_SERVICE_PROVIDER) {
            return "SIM_SERVICE_PROVIDER";
        }
        if (o == SIM_SIM) {
            return "SIM_SIM";
        }
        if (o == SIM_NETWORK_PUK) {
            return "SIM_NETWORK_PUK";
        }
        if (o == SIM_NETWORK_SUBSET_PUK) {
            return "SIM_NETWORK_SUBSET_PUK";
        }
        if (o == SIM_CORPORATE_PUK) {
            return "SIM_CORPORATE_PUK";
        }
        if (o == SIM_SERVICE_PROVIDER_PUK) {
            return "SIM_SERVICE_PROVIDER_PUK";
        }
        if (o == SIM_SIM_PUK) {
            return "SIM_SIM_PUK";
        }
        if (o == RUIM_NETWORK1) {
            return "RUIM_NETWORK1";
        }
        if (o == RUIM_NETWORK2) {
            return "RUIM_NETWORK2";
        }
        if (o == RUIM_HRPD) {
            return "RUIM_HRPD";
        }
        if (o == RUIM_CORPORATE) {
            return "RUIM_CORPORATE";
        }
        if (o == RUIM_SERVICE_PROVIDER) {
            return "RUIM_SERVICE_PROVIDER";
        }
        if (o == RUIM_RUIM) {
            return "RUIM_RUIM";
        }
        if (o == RUIM_NETWORK1_PUK) {
            return "RUIM_NETWORK1_PUK";
        }
        if (o == RUIM_NETWORK2_PUK) {
            return "RUIM_NETWORK2_PUK";
        }
        if (o == RUIM_HRPD_PUK) {
            return "RUIM_HRPD_PUK";
        }
        if (o == RUIM_CORPORATE_PUK) {
            return "RUIM_CORPORATE_PUK";
        }
        if (o == RUIM_SERVICE_PROVIDER_PUK) {
            return "RUIM_SERVICE_PROVIDER_PUK";
        }
        if (o == RUIM_RUIM_PUK) {
            return "RUIM_RUIM_PUK";
        }
        if (o == SIM_SPN) {
            return "SIM_SPN";
        }
        if (o == SIM_SPN_PUK) {
            return "SIM_SPN_PUK";
        }
        if (o == SIM_SP_EHPLMN) {
            return "SIM_SP_EHPLMN";
        }
        if (o == SIM_SP_EHPLMN_PUK) {
            return "SIM_SP_EHPLMN_PUK";
        }
        if (o == SIM_ICCID) {
            return "SIM_ICCID";
        }
        if (o == SIM_ICCID_PUK) {
            return "SIM_ICCID_PUK";
        }
        if (o == SIM_IMPI) {
            return "SIM_IMPI";
        }
        if (o == SIM_IMPI_PUK) {
            return "SIM_IMPI_PUK";
        }
        if (o == SIM_NS_SP) {
            return "SIM_NS_SP";
        }
        if (o == SIM_NS_SP_PUK) {
            return "SIM_NS_SP_PUK";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("UNKNOWN"); // UNKNOWN == 0
        if ((o & IN_PROGRESS) == IN_PROGRESS) {
            list.add("IN_PROGRESS");
            flipped |= IN_PROGRESS;
        }
        if ((o & READY) == READY) {
            list.add("READY");
            flipped |= READY;
        }
        if ((o & SIM_NETWORK) == SIM_NETWORK) {
            list.add("SIM_NETWORK");
            flipped |= SIM_NETWORK;
        }
        if ((o & SIM_NETWORK_SUBSET) == SIM_NETWORK_SUBSET) {
            list.add("SIM_NETWORK_SUBSET");
            flipped |= SIM_NETWORK_SUBSET;
        }
        if ((o & SIM_CORPORATE) == SIM_CORPORATE) {
            list.add("SIM_CORPORATE");
            flipped |= SIM_CORPORATE;
        }
        if ((o & SIM_SERVICE_PROVIDER) == SIM_SERVICE_PROVIDER) {
            list.add("SIM_SERVICE_PROVIDER");
            flipped |= SIM_SERVICE_PROVIDER;
        }
        if ((o & SIM_SIM) == SIM_SIM) {
            list.add("SIM_SIM");
            flipped |= SIM_SIM;
        }
        if ((o & SIM_NETWORK_PUK) == SIM_NETWORK_PUK) {
            list.add("SIM_NETWORK_PUK");
            flipped |= SIM_NETWORK_PUK;
        }
        if ((o & SIM_NETWORK_SUBSET_PUK) == SIM_NETWORK_SUBSET_PUK) {
            list.add("SIM_NETWORK_SUBSET_PUK");
            flipped |= SIM_NETWORK_SUBSET_PUK;
        }
        if ((o & SIM_CORPORATE_PUK) == SIM_CORPORATE_PUK) {
            list.add("SIM_CORPORATE_PUK");
            flipped |= SIM_CORPORATE_PUK;
        }
        if ((o & SIM_SERVICE_PROVIDER_PUK) == SIM_SERVICE_PROVIDER_PUK) {
            list.add("SIM_SERVICE_PROVIDER_PUK");
            flipped |= SIM_SERVICE_PROVIDER_PUK;
        }
        if ((o & SIM_SIM_PUK) == SIM_SIM_PUK) {
            list.add("SIM_SIM_PUK");
            flipped |= SIM_SIM_PUK;
        }
        if ((o & RUIM_NETWORK1) == RUIM_NETWORK1) {
            list.add("RUIM_NETWORK1");
            flipped |= RUIM_NETWORK1;
        }
        if ((o & RUIM_NETWORK2) == RUIM_NETWORK2) {
            list.add("RUIM_NETWORK2");
            flipped |= RUIM_NETWORK2;
        }
        if ((o & RUIM_HRPD) == RUIM_HRPD) {
            list.add("RUIM_HRPD");
            flipped |= RUIM_HRPD;
        }
        if ((o & RUIM_CORPORATE) == RUIM_CORPORATE) {
            list.add("RUIM_CORPORATE");
            flipped |= RUIM_CORPORATE;
        }
        if ((o & RUIM_SERVICE_PROVIDER) == RUIM_SERVICE_PROVIDER) {
            list.add("RUIM_SERVICE_PROVIDER");
            flipped |= RUIM_SERVICE_PROVIDER;
        }
        if ((o & RUIM_RUIM) == RUIM_RUIM) {
            list.add("RUIM_RUIM");
            flipped |= RUIM_RUIM;
        }
        if ((o & RUIM_NETWORK1_PUK) == RUIM_NETWORK1_PUK) {
            list.add("RUIM_NETWORK1_PUK");
            flipped |= RUIM_NETWORK1_PUK;
        }
        if ((o & RUIM_NETWORK2_PUK) == RUIM_NETWORK2_PUK) {
            list.add("RUIM_NETWORK2_PUK");
            flipped |= RUIM_NETWORK2_PUK;
        }
        if ((o & RUIM_HRPD_PUK) == RUIM_HRPD_PUK) {
            list.add("RUIM_HRPD_PUK");
            flipped |= RUIM_HRPD_PUK;
        }
        if ((o & RUIM_CORPORATE_PUK) == RUIM_CORPORATE_PUK) {
            list.add("RUIM_CORPORATE_PUK");
            flipped |= RUIM_CORPORATE_PUK;
        }
        if ((o & RUIM_SERVICE_PROVIDER_PUK) == RUIM_SERVICE_PROVIDER_PUK) {
            list.add("RUIM_SERVICE_PROVIDER_PUK");
            flipped |= RUIM_SERVICE_PROVIDER_PUK;
        }
        if ((o & RUIM_RUIM_PUK) == RUIM_RUIM_PUK) {
            list.add("RUIM_RUIM_PUK");
            flipped |= RUIM_RUIM_PUK;
        }
        if ((o & SIM_SPN) == SIM_SPN) {
            list.add("SIM_SPN");
            flipped |= SIM_SPN;
        }
        if ((o & SIM_SPN_PUK) == SIM_SPN_PUK) {
            list.add("SIM_SPN_PUK");
            flipped |= SIM_SPN_PUK;
        }
        if ((o & SIM_SP_EHPLMN) == SIM_SP_EHPLMN) {
            list.add("SIM_SP_EHPLMN");
            flipped |= SIM_SP_EHPLMN;
        }
        if ((o & SIM_SP_EHPLMN_PUK) == SIM_SP_EHPLMN_PUK) {
            list.add("SIM_SP_EHPLMN_PUK");
            flipped |= SIM_SP_EHPLMN_PUK;
        }
        if ((o & SIM_ICCID) == SIM_ICCID) {
            list.add("SIM_ICCID");
            flipped |= SIM_ICCID;
        }
        if ((o & SIM_ICCID_PUK) == SIM_ICCID_PUK) {
            list.add("SIM_ICCID_PUK");
            flipped |= SIM_ICCID_PUK;
        }
        if ((o & SIM_IMPI) == SIM_IMPI) {
            list.add("SIM_IMPI");
            flipped |= SIM_IMPI;
        }
        if ((o & SIM_IMPI_PUK) == SIM_IMPI_PUK) {
            list.add("SIM_IMPI_PUK");
            flipped |= SIM_IMPI_PUK;
        }
        if ((o & SIM_NS_SP) == SIM_NS_SP) {
            list.add("SIM_NS_SP");
            flipped |= SIM_NS_SP;
        }
        if ((o & SIM_NS_SP_PUK) == SIM_NS_SP_PUK) {
            list.add("SIM_NS_SP_PUK");
            flipped |= SIM_NS_SP_PUK;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

