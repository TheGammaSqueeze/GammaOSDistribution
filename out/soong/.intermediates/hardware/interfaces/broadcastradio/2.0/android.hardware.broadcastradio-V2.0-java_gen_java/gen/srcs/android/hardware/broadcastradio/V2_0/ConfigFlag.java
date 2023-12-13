package android.hardware.broadcastradio.V2_0;


public final class ConfigFlag {
    /**
     * Forces mono audio stream reception.
     *
     * Analog broadcasts can recover poor reception conditions by jointing
     * stereo channels into one. Mainly for, but not limited to AM/FM.
     */
    public static final int FORCE_MONO = 1;
    /**
     * Forces the analog playback for the supporting radio technology.
     *
     * User may disable digital playback for FM HD Radio or hybrid FM/DAB with
     * this option. This is purely user choice, ie. does not reflect digital-
     * analog handover state managed from the HAL implementation side.
     *
     * Some radio technologies may not support this, ie. DAB.
     */
    public static final int FORCE_ANALOG = 2 /* ::android::hardware::broadcastradio::V2_0::ConfigFlag.FORCE_MONO implicitly + 1 */;
    /**
     * Forces the digital playback for the supporting radio technology.
     *
     * User may disable digital-analog handover that happens with poor
     * reception conditions. With digital forced, the radio will remain silent
     * instead of switching to analog channel if it's available. This is purely
     * user choice, it does not reflect the actual state of handover.
     */
    public static final int FORCE_DIGITAL = 3 /* ::android::hardware::broadcastradio::V2_0::ConfigFlag.FORCE_ANALOG implicitly + 1 */;
    /**
     * RDS Alternative Frequencies.
     *
     * If set and the currently tuned RDS station broadcasts on multiple
     * channels, radio tuner automatically switches to the best available
     * alternative.
     */
    public static final int RDS_AF = 4 /* ::android::hardware::broadcastradio::V2_0::ConfigFlag.FORCE_DIGITAL implicitly + 1 */;
    /**
     * RDS region-specific program lock-down.
     *
     * Allows user to lock to the current region as they move into the
     * other region.
     */
    public static final int RDS_REG = 5 /* ::android::hardware::broadcastradio::V2_0::ConfigFlag.RDS_AF implicitly + 1 */;
    /**
     * Enables DAB-DAB hard- and implicit-linking (the same content).
     */
    public static final int DAB_DAB_LINKING = 6 /* ::android::hardware::broadcastradio::V2_0::ConfigFlag.RDS_REG implicitly + 1 */;
    /**
     * Enables DAB-FM hard- and implicit-linking (the same content).
     */
    public static final int DAB_FM_LINKING = 7 /* ::android::hardware::broadcastradio::V2_0::ConfigFlag.DAB_DAB_LINKING implicitly + 1 */;
    /**
     * Enables DAB-DAB soft-linking (related content).
     */
    public static final int DAB_DAB_SOFT_LINKING = 8 /* ::android::hardware::broadcastradio::V2_0::ConfigFlag.DAB_FM_LINKING implicitly + 1 */;
    /**
     * Enables DAB-FM soft-linking (related content).
     */
    public static final int DAB_FM_SOFT_LINKING = 9 /* ::android::hardware::broadcastradio::V2_0::ConfigFlag.DAB_DAB_SOFT_LINKING implicitly + 1 */;
    public static final String toString(int o) {
        if (o == FORCE_MONO) {
            return "FORCE_MONO";
        }
        if (o == FORCE_ANALOG) {
            return "FORCE_ANALOG";
        }
        if (o == FORCE_DIGITAL) {
            return "FORCE_DIGITAL";
        }
        if (o == RDS_AF) {
            return "RDS_AF";
        }
        if (o == RDS_REG) {
            return "RDS_REG";
        }
        if (o == DAB_DAB_LINKING) {
            return "DAB_DAB_LINKING";
        }
        if (o == DAB_FM_LINKING) {
            return "DAB_FM_LINKING";
        }
        if (o == DAB_DAB_SOFT_LINKING) {
            return "DAB_DAB_SOFT_LINKING";
        }
        if (o == DAB_FM_SOFT_LINKING) {
            return "DAB_FM_SOFT_LINKING";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & FORCE_MONO) == FORCE_MONO) {
            list.add("FORCE_MONO");
            flipped |= FORCE_MONO;
        }
        if ((o & FORCE_ANALOG) == FORCE_ANALOG) {
            list.add("FORCE_ANALOG");
            flipped |= FORCE_ANALOG;
        }
        if ((o & FORCE_DIGITAL) == FORCE_DIGITAL) {
            list.add("FORCE_DIGITAL");
            flipped |= FORCE_DIGITAL;
        }
        if ((o & RDS_AF) == RDS_AF) {
            list.add("RDS_AF");
            flipped |= RDS_AF;
        }
        if ((o & RDS_REG) == RDS_REG) {
            list.add("RDS_REG");
            flipped |= RDS_REG;
        }
        if ((o & DAB_DAB_LINKING) == DAB_DAB_LINKING) {
            list.add("DAB_DAB_LINKING");
            flipped |= DAB_DAB_LINKING;
        }
        if ((o & DAB_FM_LINKING) == DAB_FM_LINKING) {
            list.add("DAB_FM_LINKING");
            flipped |= DAB_FM_LINKING;
        }
        if ((o & DAB_DAB_SOFT_LINKING) == DAB_DAB_SOFT_LINKING) {
            list.add("DAB_DAB_SOFT_LINKING");
            flipped |= DAB_DAB_SOFT_LINKING;
        }
        if ((o & DAB_FM_SOFT_LINKING) == DAB_FM_SOFT_LINKING) {
            list.add("DAB_FM_SOFT_LINKING");
            flipped |= DAB_FM_SOFT_LINKING;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

