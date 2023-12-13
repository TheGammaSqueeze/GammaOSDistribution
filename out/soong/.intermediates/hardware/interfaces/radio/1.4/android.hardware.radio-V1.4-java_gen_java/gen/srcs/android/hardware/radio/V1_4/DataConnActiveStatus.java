package android.hardware.radio.V1_4;


public final class DataConnActiveStatus {
    /**
     * Indicates the data connection is inactive.
     */
    public static final int INACTIVE = 0;
    /**
     * Indicates the data connection is active with physical link dormant.
     */
    public static final int DORMANT = 1;
    /**
     * Indicates the data connection is active with physical link up.
     */
    public static final int ACTIVE = 2;
    public static final String toString(int o) {
        if (o == INACTIVE) {
            return "INACTIVE";
        }
        if (o == DORMANT) {
            return "DORMANT";
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
        if ((o & DORMANT) == DORMANT) {
            list.add("DORMANT");
            flipped |= DORMANT;
        }
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

