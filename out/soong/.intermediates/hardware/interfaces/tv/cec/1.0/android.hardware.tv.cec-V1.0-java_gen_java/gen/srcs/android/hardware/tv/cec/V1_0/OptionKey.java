package android.hardware.tv.cec.V1_0;


public final class OptionKey {
    /**
     * When set to false, HAL does not wake up the system upon receiving <Image
     * View On> or <Text View On>. Used when user changes the TV settings to
     * disable the auto TV on functionality.
     * True by default.
     */
    public static final int WAKEUP = 1;
    /**
     * When set to false, all the CEC commands are discarded. Used when user
     * changes the TV settings to disable CEC functionality.
     * True by default.
     */
    public static final int ENABLE_CEC = 2;
    /**
     * Setting this flag to false means Android system must stop handling CEC
     * service and yield the control over to the microprocessor that is powered
     * on through the standby mode. When set to true, the system must gain the
     * control over, hence telling the microprocessor to stop handling the CEC
     * commands. For example, this may be called when system goes in and out of
     * standby mode to notify the microprocessor that it should start/stop
     * handling CEC commands on behalf of the system.
     * False by default.
     */
    public static final int SYSTEM_CEC_CONTROL = 3;
    public static final String toString(int o) {
        if (o == WAKEUP) {
            return "WAKEUP";
        }
        if (o == ENABLE_CEC) {
            return "ENABLE_CEC";
        }
        if (o == SYSTEM_CEC_CONTROL) {
            return "SYSTEM_CEC_CONTROL";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & WAKEUP) == WAKEUP) {
            list.add("WAKEUP");
            flipped |= WAKEUP;
        }
        if ((o & ENABLE_CEC) == ENABLE_CEC) {
            list.add("ENABLE_CEC");
            flipped |= ENABLE_CEC;
        }
        if ((o & SYSTEM_CEC_CONTROL) == SYSTEM_CEC_CONTROL) {
            list.add("SYSTEM_CEC_CONTROL");
            flipped |= SYSTEM_CEC_CONTROL;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

