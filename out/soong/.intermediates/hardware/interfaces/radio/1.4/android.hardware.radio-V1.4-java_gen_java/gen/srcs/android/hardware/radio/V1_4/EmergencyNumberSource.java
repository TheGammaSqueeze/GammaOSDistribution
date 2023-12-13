package android.hardware.radio.V1_4;


public final class EmergencyNumberSource {
    /**
     * Indicates the number is from the network signal.
     */
    public static final int NETWORK_SIGNALING = 1 /* 1 << 0 */;
    /**
     * Indicates the number is from the sim card.
     */
    public static final int SIM = 2 /* 1 << 1 */;
    /**
     * Indicates the number is from the modem config.
     */
    public static final int MODEM_CONFIG = 4 /* 1 << 2 */;
    /**
     * Indicates the number is available as default. Per the reference, 112, 911 must always be
     * available; additionally, 000, 08, 110, 999, 118 and 119 must be available when sim is not
     * present.
     */
    public static final int DEFAULT = 8 /* 1 << 3 */;
    public static final String toString(int o) {
        if (o == NETWORK_SIGNALING) {
            return "NETWORK_SIGNALING";
        }
        if (o == SIM) {
            return "SIM";
        }
        if (o == MODEM_CONFIG) {
            return "MODEM_CONFIG";
        }
        if (o == DEFAULT) {
            return "DEFAULT";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & NETWORK_SIGNALING) == NETWORK_SIGNALING) {
            list.add("NETWORK_SIGNALING");
            flipped |= NETWORK_SIGNALING;
        }
        if ((o & SIM) == SIM) {
            list.add("SIM");
            flipped |= SIM;
        }
        if ((o & MODEM_CONFIG) == MODEM_CONFIG) {
            list.add("MODEM_CONFIG");
            flipped |= MODEM_CONFIG;
        }
        if ((o & DEFAULT) == DEFAULT) {
            list.add("DEFAULT");
            flipped |= DEFAULT;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

