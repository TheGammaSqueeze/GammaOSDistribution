package android.hardware.radio.V1_0;


public final class SsServiceType {
    public static final int CFU = 0;
    public static final int CF_BUSY = 1 /* ::android::hardware::radio::V1_0::SsServiceType.CFU implicitly + 1 */;
    public static final int CF_NO_REPLY = 2 /* ::android::hardware::radio::V1_0::SsServiceType.CF_BUSY implicitly + 1 */;
    public static final int CF_NOT_REACHABLE = 3 /* ::android::hardware::radio::V1_0::SsServiceType.CF_NO_REPLY implicitly + 1 */;
    public static final int CF_ALL = 4 /* ::android::hardware::radio::V1_0::SsServiceType.CF_NOT_REACHABLE implicitly + 1 */;
    public static final int CF_ALL_CONDITIONAL = 5 /* ::android::hardware::radio::V1_0::SsServiceType.CF_ALL implicitly + 1 */;
    public static final int CLIP = 6 /* ::android::hardware::radio::V1_0::SsServiceType.CF_ALL_CONDITIONAL implicitly + 1 */;
    public static final int CLIR = 7 /* ::android::hardware::radio::V1_0::SsServiceType.CLIP implicitly + 1 */;
    public static final int COLP = 8 /* ::android::hardware::radio::V1_0::SsServiceType.CLIR implicitly + 1 */;
    public static final int COLR = 9 /* ::android::hardware::radio::V1_0::SsServiceType.COLP implicitly + 1 */;
    public static final int WAIT = 10 /* ::android::hardware::radio::V1_0::SsServiceType.COLR implicitly + 1 */;
    public static final int BAOC = 11 /* ::android::hardware::radio::V1_0::SsServiceType.WAIT implicitly + 1 */;
    public static final int BAOIC = 12 /* ::android::hardware::radio::V1_0::SsServiceType.BAOC implicitly + 1 */;
    public static final int BAOIC_EXC_HOME = 13 /* ::android::hardware::radio::V1_0::SsServiceType.BAOIC implicitly + 1 */;
    public static final int BAIC = 14 /* ::android::hardware::radio::V1_0::SsServiceType.BAOIC_EXC_HOME implicitly + 1 */;
    public static final int BAIC_ROAMING = 15 /* ::android::hardware::radio::V1_0::SsServiceType.BAIC implicitly + 1 */;
    public static final int ALL_BARRING = 16 /* ::android::hardware::radio::V1_0::SsServiceType.BAIC_ROAMING implicitly + 1 */;
    public static final int OUTGOING_BARRING = 17 /* ::android::hardware::radio::V1_0::SsServiceType.ALL_BARRING implicitly + 1 */;
    public static final int INCOMING_BARRING = 18 /* ::android::hardware::radio::V1_0::SsServiceType.OUTGOING_BARRING implicitly + 1 */;
    public static final String toString(int o) {
        if (o == CFU) {
            return "CFU";
        }
        if (o == CF_BUSY) {
            return "CF_BUSY";
        }
        if (o == CF_NO_REPLY) {
            return "CF_NO_REPLY";
        }
        if (o == CF_NOT_REACHABLE) {
            return "CF_NOT_REACHABLE";
        }
        if (o == CF_ALL) {
            return "CF_ALL";
        }
        if (o == CF_ALL_CONDITIONAL) {
            return "CF_ALL_CONDITIONAL";
        }
        if (o == CLIP) {
            return "CLIP";
        }
        if (o == CLIR) {
            return "CLIR";
        }
        if (o == COLP) {
            return "COLP";
        }
        if (o == COLR) {
            return "COLR";
        }
        if (o == WAIT) {
            return "WAIT";
        }
        if (o == BAOC) {
            return "BAOC";
        }
        if (o == BAOIC) {
            return "BAOIC";
        }
        if (o == BAOIC_EXC_HOME) {
            return "BAOIC_EXC_HOME";
        }
        if (o == BAIC) {
            return "BAIC";
        }
        if (o == BAIC_ROAMING) {
            return "BAIC_ROAMING";
        }
        if (o == ALL_BARRING) {
            return "ALL_BARRING";
        }
        if (o == OUTGOING_BARRING) {
            return "OUTGOING_BARRING";
        }
        if (o == INCOMING_BARRING) {
            return "INCOMING_BARRING";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("CFU"); // CFU == 0
        if ((o & CF_BUSY) == CF_BUSY) {
            list.add("CF_BUSY");
            flipped |= CF_BUSY;
        }
        if ((o & CF_NO_REPLY) == CF_NO_REPLY) {
            list.add("CF_NO_REPLY");
            flipped |= CF_NO_REPLY;
        }
        if ((o & CF_NOT_REACHABLE) == CF_NOT_REACHABLE) {
            list.add("CF_NOT_REACHABLE");
            flipped |= CF_NOT_REACHABLE;
        }
        if ((o & CF_ALL) == CF_ALL) {
            list.add("CF_ALL");
            flipped |= CF_ALL;
        }
        if ((o & CF_ALL_CONDITIONAL) == CF_ALL_CONDITIONAL) {
            list.add("CF_ALL_CONDITIONAL");
            flipped |= CF_ALL_CONDITIONAL;
        }
        if ((o & CLIP) == CLIP) {
            list.add("CLIP");
            flipped |= CLIP;
        }
        if ((o & CLIR) == CLIR) {
            list.add("CLIR");
            flipped |= CLIR;
        }
        if ((o & COLP) == COLP) {
            list.add("COLP");
            flipped |= COLP;
        }
        if ((o & COLR) == COLR) {
            list.add("COLR");
            flipped |= COLR;
        }
        if ((o & WAIT) == WAIT) {
            list.add("WAIT");
            flipped |= WAIT;
        }
        if ((o & BAOC) == BAOC) {
            list.add("BAOC");
            flipped |= BAOC;
        }
        if ((o & BAOIC) == BAOIC) {
            list.add("BAOIC");
            flipped |= BAOIC;
        }
        if ((o & BAOIC_EXC_HOME) == BAOIC_EXC_HOME) {
            list.add("BAOIC_EXC_HOME");
            flipped |= BAOIC_EXC_HOME;
        }
        if ((o & BAIC) == BAIC) {
            list.add("BAIC");
            flipped |= BAIC;
        }
        if ((o & BAIC_ROAMING) == BAIC_ROAMING) {
            list.add("BAIC_ROAMING");
            flipped |= BAIC_ROAMING;
        }
        if ((o & ALL_BARRING) == ALL_BARRING) {
            list.add("ALL_BARRING");
            flipped |= ALL_BARRING;
        }
        if ((o & OUTGOING_BARRING) == OUTGOING_BARRING) {
            list.add("OUTGOING_BARRING");
            flipped |= OUTGOING_BARRING;
        }
        if ((o & INCOMING_BARRING) == INCOMING_BARRING) {
            list.add("INCOMING_BARRING");
            flipped |= INCOMING_BARRING;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

