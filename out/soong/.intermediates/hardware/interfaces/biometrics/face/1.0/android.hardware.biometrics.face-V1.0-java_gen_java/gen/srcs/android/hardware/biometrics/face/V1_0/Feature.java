package android.hardware.biometrics.face.V1_0;


public final class Feature {
    /**
     * Require the user to look at the device during enrollment and
     * authentication. Note this is to accommodate people who have limited
     * vision. Must be enabled by default.
     */
    public static final int REQUIRE_ATTENTION = 1;
    /**
     * Require a diverse set of poses during enrollment. Note this is to
     * accommodate people with limited mobility. Must be enabled by default.
     */
    public static final int REQUIRE_DIVERSITY = 2;
    public static final String toString(int o) {
        if (o == REQUIRE_ATTENTION) {
            return "REQUIRE_ATTENTION";
        }
        if (o == REQUIRE_DIVERSITY) {
            return "REQUIRE_DIVERSITY";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & REQUIRE_ATTENTION) == REQUIRE_ATTENTION) {
            list.add("REQUIRE_ATTENTION");
            flipped |= REQUIRE_ATTENTION;
        }
        if ((o & REQUIRE_DIVERSITY) == REQUIRE_DIVERSITY) {
            list.add("REQUIRE_DIVERSITY");
            flipped |= REQUIRE_DIVERSITY;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

