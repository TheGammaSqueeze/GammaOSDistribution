package android.hardware.dumpstate.V1_1;


public final class DumpstateMode {
    /**
     * Takes a bug report without user interference.
     */
    public static final int FULL = 0;
    /**
     * Interactive bug report, i.e. triggered by the user.
     */
    public static final int INTERACTIVE = 1;
    /**
     * Remote bug report triggered by DevicePolicyManager, for example.
     */
    public static final int REMOTE = 2;
    /**
     * Bug report triggered on a wear device.
     */
    public static final int WEAR = 3;
    /**
     * Bug report limited to only connectivity info (cellular, wifi, and networking). Sometimes
     * called "telephony" in legacy contexts.
     *
     * All reported information MUST directly relate to connectivity debugging or customer support
     * and MUST NOT contain unrelated private information. This information MUST NOT identify
     * user-installed packages (UIDs are OK, package names are not), and MUST NOT contain logs of
     * user application traffic.
     */
    public static final int CONNECTIVITY = 4;
    /**
     * Bug report limited to only wifi info.
     */
    public static final int WIFI = 5;
    /**
     * Default mode, essentially analogous to calling @1.0::IDumpstateDevice.dumpstateBoard(handle).
     * This mode MUST be supported if the dumpstate HAL is implemented.
     */
    public static final int DEFAULT = 6;
    /**
     * Takes a report in protobuf.
     *
     * The content, if implemented, must be a binary protobuf message written to the first file
     * descriptor of the native handle. The protobuf schema shall be defined by the vendor.
     */
    public static final int PROTO = 7;
    public static final String toString(int o) {
        if (o == FULL) {
            return "FULL";
        }
        if (o == INTERACTIVE) {
            return "INTERACTIVE";
        }
        if (o == REMOTE) {
            return "REMOTE";
        }
        if (o == WEAR) {
            return "WEAR";
        }
        if (o == CONNECTIVITY) {
            return "CONNECTIVITY";
        }
        if (o == WIFI) {
            return "WIFI";
        }
        if (o == DEFAULT) {
            return "DEFAULT";
        }
        if (o == PROTO) {
            return "PROTO";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("FULL"); // FULL == 0
        if ((o & INTERACTIVE) == INTERACTIVE) {
            list.add("INTERACTIVE");
            flipped |= INTERACTIVE;
        }
        if ((o & REMOTE) == REMOTE) {
            list.add("REMOTE");
            flipped |= REMOTE;
        }
        if ((o & WEAR) == WEAR) {
            list.add("WEAR");
            flipped |= WEAR;
        }
        if ((o & CONNECTIVITY) == CONNECTIVITY) {
            list.add("CONNECTIVITY");
            flipped |= CONNECTIVITY;
        }
        if ((o & WIFI) == WIFI) {
            list.add("WIFI");
            flipped |= WIFI;
        }
        if ((o & DEFAULT) == DEFAULT) {
            list.add("DEFAULT");
            flipped |= DEFAULT;
        }
        if ((o & PROTO) == PROTO) {
            list.add("PROTO");
            flipped |= PROTO;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

