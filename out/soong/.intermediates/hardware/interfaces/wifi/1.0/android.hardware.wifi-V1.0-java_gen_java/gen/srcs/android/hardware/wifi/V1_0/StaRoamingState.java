package android.hardware.wifi.V1_0;


public final class StaRoamingState {
    /**
     * Driver/Firmware must not perform any roaming.
     */
    public static final byte DISABLED = 0;
    /**
     * Driver/Firmware is allowed to perform roaming respecting
     * the |StaRoamingConfig| parameters set using |configureRoaming|.
     */
    public static final byte ENABLED = 1;
    public static final String toString(byte o) {
        if (o == DISABLED) {
            return "DISABLED";
        }
        if (o == ENABLED) {
            return "ENABLED";
        }
        return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
    }

    public static final String dumpBitfield(byte o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        byte flipped = 0;
        list.add("DISABLED"); // DISABLED == 0
        if ((o & ENABLED) == ENABLED) {
            list.add("ENABLED");
            flipped |= ENABLED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

