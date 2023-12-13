package android.hardware.radio.V1_4;


public final class FrequencyRange {
    /**
     * Indicates the frequency range is below 1GHz.
     */
    public static final int LOW = 1;
    /**
     * Indicates the frequency range is between 1GHz and 3GHz.
     */
    public static final int MID = 2;
    /**
     * Indicates the frequency range is between 3GHz and 6GHz.
     */
    public static final int HIGH = 3;
    /**
     * Indicates the frequency range is above 6GHz (millimeter wave frequency).
     */
    public static final int MMWAVE = 4;
    public static final String toString(int o) {
        if (o == LOW) {
            return "LOW";
        }
        if (o == MID) {
            return "MID";
        }
        if (o == HIGH) {
            return "HIGH";
        }
        if (o == MMWAVE) {
            return "MMWAVE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & LOW) == LOW) {
            list.add("LOW");
            flipped |= LOW;
        }
        if ((o & MID) == MID) {
            list.add("MID");
            flipped |= MID;
        }
        if ((o & HIGH) == HIGH) {
            list.add("HIGH");
            flipped |= HIGH;
        }
        if ((o & MMWAVE) == MMWAVE) {
            list.add("MMWAVE");
            flipped |= MMWAVE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

