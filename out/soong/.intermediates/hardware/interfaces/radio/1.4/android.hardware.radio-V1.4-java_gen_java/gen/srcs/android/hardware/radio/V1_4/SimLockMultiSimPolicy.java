package android.hardware.radio.V1_4;


public final class SimLockMultiSimPolicy {
    /**
     * Indicates that configuration applies to each slot independently.
     */
    public static final int NO_MULTISIM_POLICY = 0;
    /**
     * Indicates that any SIM card can be used as far as one valid card is present in the device.
     * For the modem, a SIM card is valid when its content (i.e. MCC, MNC, GID, SPN) matches the
     * carrier restriction configuration.
     */
    public static final int ONE_VALID_SIM_MUST_BE_PRESENT = 1;
    public static final String toString(int o) {
        if (o == NO_MULTISIM_POLICY) {
            return "NO_MULTISIM_POLICY";
        }
        if (o == ONE_VALID_SIM_MUST_BE_PRESENT) {
            return "ONE_VALID_SIM_MUST_BE_PRESENT";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NO_MULTISIM_POLICY"); // NO_MULTISIM_POLICY == 0
        if ((o & ONE_VALID_SIM_MUST_BE_PRESENT) == ONE_VALID_SIM_MUST_BE_PRESENT) {
            list.add("ONE_VALID_SIM_MUST_BE_PRESENT");
            flipped |= ONE_VALID_SIM_MUST_BE_PRESENT;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

