package android.hardware.soundtrigger.V2_0;


public final class RecognitionMode {
    /**
     * simple voice trigger
     */
    public static final int VOICE_TRIGGER = 1 /* (1 << 0) */;
    /**
     * trigger only if one user in model identified
     */
    public static final int USER_IDENTIFICATION = 2 /* (1 << 1) */;
    /**
     * trigger only if one user in mode authenticated
     */
    public static final int USER_AUTHENTICATION = 4 /* (1 << 2) */;
    /**
     * generic sound trigger
     */
    public static final int GENERIC_TRIGGER = 8 /* (1 << 3) */;
    public static final String toString(int o) {
        if (o == VOICE_TRIGGER) {
            return "VOICE_TRIGGER";
        }
        if (o == USER_IDENTIFICATION) {
            return "USER_IDENTIFICATION";
        }
        if (o == USER_AUTHENTICATION) {
            return "USER_AUTHENTICATION";
        }
        if (o == GENERIC_TRIGGER) {
            return "GENERIC_TRIGGER";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & VOICE_TRIGGER) == VOICE_TRIGGER) {
            list.add("VOICE_TRIGGER");
            flipped |= VOICE_TRIGGER;
        }
        if ((o & USER_IDENTIFICATION) == USER_IDENTIFICATION) {
            list.add("USER_IDENTIFICATION");
            flipped |= USER_IDENTIFICATION;
        }
        if ((o & USER_AUTHENTICATION) == USER_AUTHENTICATION) {
            list.add("USER_AUTHENTICATION");
            flipped |= USER_AUTHENTICATION;
        }
        if ((o & GENERIC_TRIGGER) == GENERIC_TRIGGER) {
            list.add("GENERIC_TRIGGER");
            flipped |= GENERIC_TRIGGER;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

