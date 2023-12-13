package android.hardware.radio.V1_0;


public final class CdmaOtaProvisionStatus {
    public static final int SPL_UNLOCKED = 0;
    public static final int SPC_RETRIES_EXCEEDED = 1 /* ::android::hardware::radio::V1_0::CdmaOtaProvisionStatus.SPL_UNLOCKED implicitly + 1 */;
    public static final int A_KEY_EXCHANGED = 2 /* ::android::hardware::radio::V1_0::CdmaOtaProvisionStatus.SPC_RETRIES_EXCEEDED implicitly + 1 */;
    public static final int SSD_UPDATED = 3 /* ::android::hardware::radio::V1_0::CdmaOtaProvisionStatus.A_KEY_EXCHANGED implicitly + 1 */;
    public static final int NAM_DOWNLOADED = 4 /* ::android::hardware::radio::V1_0::CdmaOtaProvisionStatus.SSD_UPDATED implicitly + 1 */;
    public static final int MDN_DOWNLOADED = 5 /* ::android::hardware::radio::V1_0::CdmaOtaProvisionStatus.NAM_DOWNLOADED implicitly + 1 */;
    public static final int IMSI_DOWNLOADED = 6 /* ::android::hardware::radio::V1_0::CdmaOtaProvisionStatus.MDN_DOWNLOADED implicitly + 1 */;
    public static final int PRL_DOWNLOADED = 7 /* ::android::hardware::radio::V1_0::CdmaOtaProvisionStatus.IMSI_DOWNLOADED implicitly + 1 */;
    public static final int COMMITTED = 8 /* ::android::hardware::radio::V1_0::CdmaOtaProvisionStatus.PRL_DOWNLOADED implicitly + 1 */;
    public static final int OTAPA_STARTED = 9 /* ::android::hardware::radio::V1_0::CdmaOtaProvisionStatus.COMMITTED implicitly + 1 */;
    public static final int OTAPA_STOPPED = 10 /* ::android::hardware::radio::V1_0::CdmaOtaProvisionStatus.OTAPA_STARTED implicitly + 1 */;
    public static final int OTAPA_ABORTED = 11 /* ::android::hardware::radio::V1_0::CdmaOtaProvisionStatus.OTAPA_STOPPED implicitly + 1 */;
    public static final String toString(int o) {
        if (o == SPL_UNLOCKED) {
            return "SPL_UNLOCKED";
        }
        if (o == SPC_RETRIES_EXCEEDED) {
            return "SPC_RETRIES_EXCEEDED";
        }
        if (o == A_KEY_EXCHANGED) {
            return "A_KEY_EXCHANGED";
        }
        if (o == SSD_UPDATED) {
            return "SSD_UPDATED";
        }
        if (o == NAM_DOWNLOADED) {
            return "NAM_DOWNLOADED";
        }
        if (o == MDN_DOWNLOADED) {
            return "MDN_DOWNLOADED";
        }
        if (o == IMSI_DOWNLOADED) {
            return "IMSI_DOWNLOADED";
        }
        if (o == PRL_DOWNLOADED) {
            return "PRL_DOWNLOADED";
        }
        if (o == COMMITTED) {
            return "COMMITTED";
        }
        if (o == OTAPA_STARTED) {
            return "OTAPA_STARTED";
        }
        if (o == OTAPA_STOPPED) {
            return "OTAPA_STOPPED";
        }
        if (o == OTAPA_ABORTED) {
            return "OTAPA_ABORTED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("SPL_UNLOCKED"); // SPL_UNLOCKED == 0
        if ((o & SPC_RETRIES_EXCEEDED) == SPC_RETRIES_EXCEEDED) {
            list.add("SPC_RETRIES_EXCEEDED");
            flipped |= SPC_RETRIES_EXCEEDED;
        }
        if ((o & A_KEY_EXCHANGED) == A_KEY_EXCHANGED) {
            list.add("A_KEY_EXCHANGED");
            flipped |= A_KEY_EXCHANGED;
        }
        if ((o & SSD_UPDATED) == SSD_UPDATED) {
            list.add("SSD_UPDATED");
            flipped |= SSD_UPDATED;
        }
        if ((o & NAM_DOWNLOADED) == NAM_DOWNLOADED) {
            list.add("NAM_DOWNLOADED");
            flipped |= NAM_DOWNLOADED;
        }
        if ((o & MDN_DOWNLOADED) == MDN_DOWNLOADED) {
            list.add("MDN_DOWNLOADED");
            flipped |= MDN_DOWNLOADED;
        }
        if ((o & IMSI_DOWNLOADED) == IMSI_DOWNLOADED) {
            list.add("IMSI_DOWNLOADED");
            flipped |= IMSI_DOWNLOADED;
        }
        if ((o & PRL_DOWNLOADED) == PRL_DOWNLOADED) {
            list.add("PRL_DOWNLOADED");
            flipped |= PRL_DOWNLOADED;
        }
        if ((o & COMMITTED) == COMMITTED) {
            list.add("COMMITTED");
            flipped |= COMMITTED;
        }
        if ((o & OTAPA_STARTED) == OTAPA_STARTED) {
            list.add("OTAPA_STARTED");
            flipped |= OTAPA_STARTED;
        }
        if ((o & OTAPA_STOPPED) == OTAPA_STOPPED) {
            list.add("OTAPA_STOPPED");
            flipped |= OTAPA_STOPPED;
        }
        if ((o & OTAPA_ABORTED) == OTAPA_ABORTED) {
            list.add("OTAPA_ABORTED");
            flipped |= OTAPA_ABORTED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

