package android.hardware.radio.V1_4;


public final class EmergencyServiceCategory {
    /**
     * General emergency call, all categories
     */
    public static final int UNSPECIFIED = 0;
    public static final int POLICE = 1 /* 1 << 0 */;
    public static final int AMBULANCE = 2 /* 1 << 1 */;
    public static final int FIRE_BRIGADE = 4 /* 1 << 2 */;
    public static final int MARINE_GUARD = 8 /* 1 << 3 */;
    public static final int MOUNTAIN_RESCUE = 16 /* 1 << 4 */;
    /**
     * Manually Initiated eCall (MIeC)
     */
    public static final int MIEC = 32 /* 1 << 5 */;
    /**
     * Automatically Initiated eCall (AIeC)
     */
    public static final int AIEC = 64 /* 1 << 6 */;
    public static final String toString(int o) {
        if (o == UNSPECIFIED) {
            return "UNSPECIFIED";
        }
        if (o == POLICE) {
            return "POLICE";
        }
        if (o == AMBULANCE) {
            return "AMBULANCE";
        }
        if (o == FIRE_BRIGADE) {
            return "FIRE_BRIGADE";
        }
        if (o == MARINE_GUARD) {
            return "MARINE_GUARD";
        }
        if (o == MOUNTAIN_RESCUE) {
            return "MOUNTAIN_RESCUE";
        }
        if (o == MIEC) {
            return "MIEC";
        }
        if (o == AIEC) {
            return "AIEC";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("UNSPECIFIED"); // UNSPECIFIED == 0
        if ((o & POLICE) == POLICE) {
            list.add("POLICE");
            flipped |= POLICE;
        }
        if ((o & AMBULANCE) == AMBULANCE) {
            list.add("AMBULANCE");
            flipped |= AMBULANCE;
        }
        if ((o & FIRE_BRIGADE) == FIRE_BRIGADE) {
            list.add("FIRE_BRIGADE");
            flipped |= FIRE_BRIGADE;
        }
        if ((o & MARINE_GUARD) == MARINE_GUARD) {
            list.add("MARINE_GUARD");
            flipped |= MARINE_GUARD;
        }
        if ((o & MOUNTAIN_RESCUE) == MOUNTAIN_RESCUE) {
            list.add("MOUNTAIN_RESCUE");
            flipped |= MOUNTAIN_RESCUE;
        }
        if ((o & MIEC) == MIEC) {
            list.add("MIEC");
            flipped |= MIEC;
        }
        if ((o & AIEC) == AIEC) {
            list.add("AIEC");
            flipped |= AIEC;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

