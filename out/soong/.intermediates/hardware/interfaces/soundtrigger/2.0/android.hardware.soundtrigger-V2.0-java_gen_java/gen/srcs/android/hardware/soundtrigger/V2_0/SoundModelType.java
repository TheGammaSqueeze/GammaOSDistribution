package android.hardware.soundtrigger.V2_0;


public final class SoundModelType {
    /**
     * use for unspecified sound model type
     */
    public static final int UNKNOWN = -1 /* -1 */;
    /**
     * use for key phrase sound models
     */
    public static final int KEYPHRASE = 0;
    /**
     * use for all models other than keyphrase
     */
    public static final int GENERIC = 1;
    public static final String toString(int o) {
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        if (o == KEYPHRASE) {
            return "KEYPHRASE";
        }
        if (o == GENERIC) {
            return "GENERIC";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & UNKNOWN) == UNKNOWN) {
            list.add("UNKNOWN");
            flipped |= UNKNOWN;
        }
        list.add("KEYPHRASE"); // KEYPHRASE == 0
        if ((o & GENERIC) == GENERIC) {
            list.add("GENERIC");
            flipped |= GENERIC;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

