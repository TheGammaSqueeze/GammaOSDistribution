package android.hardware.gnss.measurement_corrections.V1_0;


public final class GnssSingleSatCorrectionFlags {
    /**
     * GnssSingleSatCorrectionFlags has valid satellite-is-line-of-sight-probability field.
     */
    public static final short HAS_SAT_IS_LOS_PROBABILITY = 1 /* 0x0001 */;
    /**
     * GnssSingleSatCorrectionFlags has valid Excess Path Length field.
     */
    public static final short HAS_EXCESS_PATH_LENGTH = 2 /* 0x0002 */;
    /**
     * GnssSingleSatCorrectionFlags has valid Excess Path Length Uncertainty field.
     */
    public static final short HAS_EXCESS_PATH_LENGTH_UNC = 4 /* 0x0004 */;
    /**
     * GnssSingleSatCorrectionFlags has valid Reflecting Plane field.
     */
    public static final short HAS_REFLECTING_PLANE = 8 /* 0x0008 */;
    public static final String toString(short o) {
        if (o == HAS_SAT_IS_LOS_PROBABILITY) {
            return "HAS_SAT_IS_LOS_PROBABILITY";
        }
        if (o == HAS_EXCESS_PATH_LENGTH) {
            return "HAS_EXCESS_PATH_LENGTH";
        }
        if (o == HAS_EXCESS_PATH_LENGTH_UNC) {
            return "HAS_EXCESS_PATH_LENGTH_UNC";
        }
        if (o == HAS_REFLECTING_PLANE) {
            return "HAS_REFLECTING_PLANE";
        }
        return "0x" + Integer.toHexString(Short.toUnsignedInt((short)(o)));
    }

    public static final String dumpBitfield(short o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        short flipped = 0;
        if ((o & HAS_SAT_IS_LOS_PROBABILITY) == HAS_SAT_IS_LOS_PROBABILITY) {
            list.add("HAS_SAT_IS_LOS_PROBABILITY");
            flipped |= HAS_SAT_IS_LOS_PROBABILITY;
        }
        if ((o & HAS_EXCESS_PATH_LENGTH) == HAS_EXCESS_PATH_LENGTH) {
            list.add("HAS_EXCESS_PATH_LENGTH");
            flipped |= HAS_EXCESS_PATH_LENGTH;
        }
        if ((o & HAS_EXCESS_PATH_LENGTH_UNC) == HAS_EXCESS_PATH_LENGTH_UNC) {
            list.add("HAS_EXCESS_PATH_LENGTH_UNC");
            flipped |= HAS_EXCESS_PATH_LENGTH_UNC;
        }
        if ((o & HAS_REFLECTING_PLANE) == HAS_REFLECTING_PLANE) {
            list.add("HAS_REFLECTING_PLANE");
            flipped |= HAS_REFLECTING_PLANE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Short.toUnsignedInt((short)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

