package android.hardware.radio.config.V1_0;


public final class SlotState {
    /**
     * Physical slot is inactive
     */
    public static final int INACTIVE = 0 /* 0x00 */;
    /**
     * Physical slot is active
     */
    public static final int ACTIVE = 1 /* 0x01 */;
    public static final String toString(int o) {
        if (o == INACTIVE) {
            return "INACTIVE";
        }
        if (o == ACTIVE) {
            return "ACTIVE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("INACTIVE"); // INACTIVE == 0
        if ((o & ACTIVE) == ACTIVE) {
            list.add("ACTIVE");
            flipped |= ACTIVE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

