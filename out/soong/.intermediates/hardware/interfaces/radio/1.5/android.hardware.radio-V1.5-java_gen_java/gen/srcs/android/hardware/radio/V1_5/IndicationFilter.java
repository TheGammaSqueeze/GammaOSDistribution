package android.hardware.radio.V1_5;


public final class IndicationFilter {
    public static final int NONE = 0;
    public static final int ALL = -1 /* ~0 */;
    /**
     * When this bit is set, modem must send the signal strength update through
     * IRadioIndication.currentSignalStrength() when all criteria specified by
     * IRadio.setSignalStrengthReportingCriteria() are met.
     */
    public static final int SIGNAL_STRENGTH = 1 /* 1 << 0 */;
    /**
     * When this bit is set, modem must invoke IRadioIndication.networkStateChanged() when any field
     * in VoiceRegStateResult or DataRegStateResult changes. When this bit is not set, modem must
     * suppress IRadioIndication.networkStateChanged() when there are only changes from
     * insignificant fields. Modem must invoke IRadioIndication.networkStateChanged() when
     * significant fields are updated regardless of whether this bit is set.
     *
     * The following fields are considered significant: VoiceRegStateResult.regState,
     * VoiceRegStateResult.rat, DataRegStateResult.regState, DataRegStateResult.rat.
     */
    public static final int FULL_NETWORK_STATE = 2 /* 1 << 1 */;
    /**
     * When this bit is set, modem must send IRadioIndication.dataCallListChanged() whenever any
     * field in ITypes.SetupDataCallResult changes. When this bit is not set, modem must suppress
     * the indication when the only changed field is 'active' (for data dormancy). For all other
     * field changes, the modem must send IRadioIndication.dataCallListChanged() regardless of
     * whether this bit is set.
     */
    public static final int DATA_CALL_DORMANCY_CHANGED = 4 /* 1 << 2 */;
    /**
     * When this bit is set, modem must send the link capacity update through
     * IRadioIndication.currentLinkCapacityEstimate() when all criteria specified by
     * IRadio.setLinkCapacityReportingCriteria() are met.
     */
    public static final int LINK_CAPACITY_ESTIMATE = 8 /* 1 << 3 */;
    /**
     * When this bit is set, the modem must send the physical channel configuration update through
     * IRadioIndication.currentPhysicalChannelConfigs() when the configuration has changed. It is
     * recommended that this be reported whenever link capacity or signal strength is reported.
     */
    public static final int PHYSICAL_CHANNEL_CONFIG = 16 /* 1 << 4 */;
    /**
     * Control the unsolicited sending of registration failure reports via onRegistrationFailed
     */
    public static final int REGISTRATION_FAILURE = 32 /* 1 << 5 */;
    /**
     * Control the unsolicited sending of barring info updates via onBarringInfo
     */
    public static final int BARRING_INFO = 64 /* 1 << 6 */;
    public static final String toString(int o) {
        if (o == NONE) {
            return "NONE";
        }
        if (o == ALL) {
            return "ALL";
        }
        if (o == SIGNAL_STRENGTH) {
            return "SIGNAL_STRENGTH";
        }
        if (o == FULL_NETWORK_STATE) {
            return "FULL_NETWORK_STATE";
        }
        if (o == DATA_CALL_DORMANCY_CHANGED) {
            return "DATA_CALL_DORMANCY_CHANGED";
        }
        if (o == LINK_CAPACITY_ESTIMATE) {
            return "LINK_CAPACITY_ESTIMATE";
        }
        if (o == PHYSICAL_CHANNEL_CONFIG) {
            return "PHYSICAL_CHANNEL_CONFIG";
        }
        if (o == REGISTRATION_FAILURE) {
            return "REGISTRATION_FAILURE";
        }
        if (o == BARRING_INFO) {
            return "BARRING_INFO";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NONE"); // NONE == 0
        if ((o & ALL) == ALL) {
            list.add("ALL");
            flipped |= ALL;
        }
        if ((o & SIGNAL_STRENGTH) == SIGNAL_STRENGTH) {
            list.add("SIGNAL_STRENGTH");
            flipped |= SIGNAL_STRENGTH;
        }
        if ((o & FULL_NETWORK_STATE) == FULL_NETWORK_STATE) {
            list.add("FULL_NETWORK_STATE");
            flipped |= FULL_NETWORK_STATE;
        }
        if ((o & DATA_CALL_DORMANCY_CHANGED) == DATA_CALL_DORMANCY_CHANGED) {
            list.add("DATA_CALL_DORMANCY_CHANGED");
            flipped |= DATA_CALL_DORMANCY_CHANGED;
        }
        if ((o & LINK_CAPACITY_ESTIMATE) == LINK_CAPACITY_ESTIMATE) {
            list.add("LINK_CAPACITY_ESTIMATE");
            flipped |= LINK_CAPACITY_ESTIMATE;
        }
        if ((o & PHYSICAL_CHANNEL_CONFIG) == PHYSICAL_CHANNEL_CONFIG) {
            list.add("PHYSICAL_CHANNEL_CONFIG");
            flipped |= PHYSICAL_CHANNEL_CONFIG;
        }
        if ((o & REGISTRATION_FAILURE) == REGISTRATION_FAILURE) {
            list.add("REGISTRATION_FAILURE");
            flipped |= REGISTRATION_FAILURE;
        }
        if ((o & BARRING_INFO) == BARRING_INFO) {
            list.add("BARRING_INFO");
            flipped |= BARRING_INFO;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

