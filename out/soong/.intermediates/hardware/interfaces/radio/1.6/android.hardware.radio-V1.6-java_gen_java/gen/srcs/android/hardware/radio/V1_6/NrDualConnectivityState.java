package android.hardware.radio.V1_6;


public final class NrDualConnectivityState {
    /**
     * Enable NR dual connectivity. Enabled state does not mean dual connectivity
     * is active. It means device is allowed to connect to both primary and secondary.
     */
    public static final byte ENABLE = 1;
    /**
     * Disable NR dual connectivity. Disabled state does not mean secondary cell is released.
     * Modem will release it only if current bearer is released to avoid radio link failure.
     */
    public static final byte DISABLE = 2;
    /**
     * Disable NR dual connectivity and force secondary cell to be released if dual connectivity
     * was active. This may result in radio link failure.
     */
    public static final byte DISABLE_IMMEDIATE = 3;
    public static final String toString(byte o) {
        if (o == ENABLE) {
            return "ENABLE";
        }
        if (o == DISABLE) {
            return "DISABLE";
        }
        if (o == DISABLE_IMMEDIATE) {
            return "DISABLE_IMMEDIATE";
        }
        return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
    }

    public static final String dumpBitfield(byte o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        byte flipped = 0;
        if ((o & ENABLE) == ENABLE) {
            list.add("ENABLE");
            flipped |= ENABLE;
        }
        if ((o & DISABLE) == DISABLE) {
            list.add("DISABLE");
            flipped |= DISABLE;
        }
        if ((o & DISABLE_IMMEDIATE) == DISABLE_IMMEDIATE) {
            list.add("DISABLE_IMMEDIATE");
            flipped |= DISABLE_IMMEDIATE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

