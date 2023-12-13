package android.hardware.cas.V1_2;


public final class StatusEvent {
    /**
     * The status of CAS plugin was changed due to physical module insertion or
     * removal. Client must call enumeratePlugins to update plugins' status.
     */
    public static final byte PLUGIN_PHYSICAL_MODULE_CHANGED = 0;
    /**
     * The status of supported session number was changed due to physical module
     * insertion or removal. Client must update session resource according to
     * latest StatusMessage from the StatusEvent. The plugin supports unlimited
     * sesssion by default.
     */
    public static final byte PLUGIN_SESSION_NUMBER_CHANGED = 1 /* ::android::hardware::cas::V1_2::StatusEvent.PLUGIN_PHYSICAL_MODULE_CHANGED implicitly + 1 */;
    public static final String toString(byte o) {
        if (o == PLUGIN_PHYSICAL_MODULE_CHANGED) {
            return "PLUGIN_PHYSICAL_MODULE_CHANGED";
        }
        if (o == PLUGIN_SESSION_NUMBER_CHANGED) {
            return "PLUGIN_SESSION_NUMBER_CHANGED";
        }
        return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
    }

    public static final String dumpBitfield(byte o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        byte flipped = 0;
        list.add("PLUGIN_PHYSICAL_MODULE_CHANGED"); // PLUGIN_PHYSICAL_MODULE_CHANGED == 0
        if ((o & PLUGIN_SESSION_NUMBER_CHANGED) == PLUGIN_SESSION_NUMBER_CHANGED) {
            list.add("PLUGIN_SESSION_NUMBER_CHANGED");
            flipped |= PLUGIN_SESSION_NUMBER_CHANGED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

