package android.hardware.tv.cec.V1_0;


public final class AbortReason {
    public static final int UNRECOGNIZED_MODE = 0;
    public static final int NOT_IN_CORRECT_MODE = 1;
    public static final int CANNOT_PROVIDE_SOURCE = 2;
    public static final int INVALID_OPERAND = 3;
    public static final int REFUSED = 4;
    public static final int UNABLE_TO_DETERMINE = 5;
    public static final String toString(int o) {
        if (o == UNRECOGNIZED_MODE) {
            return "UNRECOGNIZED_MODE";
        }
        if (o == NOT_IN_CORRECT_MODE) {
            return "NOT_IN_CORRECT_MODE";
        }
        if (o == CANNOT_PROVIDE_SOURCE) {
            return "CANNOT_PROVIDE_SOURCE";
        }
        if (o == INVALID_OPERAND) {
            return "INVALID_OPERAND";
        }
        if (o == REFUSED) {
            return "REFUSED";
        }
        if (o == UNABLE_TO_DETERMINE) {
            return "UNABLE_TO_DETERMINE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("UNRECOGNIZED_MODE"); // UNRECOGNIZED_MODE == 0
        if ((o & NOT_IN_CORRECT_MODE) == NOT_IN_CORRECT_MODE) {
            list.add("NOT_IN_CORRECT_MODE");
            flipped |= NOT_IN_CORRECT_MODE;
        }
        if ((o & CANNOT_PROVIDE_SOURCE) == CANNOT_PROVIDE_SOURCE) {
            list.add("CANNOT_PROVIDE_SOURCE");
            flipped |= CANNOT_PROVIDE_SOURCE;
        }
        if ((o & INVALID_OPERAND) == INVALID_OPERAND) {
            list.add("INVALID_OPERAND");
            flipped |= INVALID_OPERAND;
        }
        if ((o & REFUSED) == REFUSED) {
            list.add("REFUSED");
            flipped |= REFUSED;
        }
        if ((o & UNABLE_TO_DETERMINE) == UNABLE_TO_DETERMINE) {
            list.add("UNABLE_TO_DETERMINE");
            flipped |= UNABLE_TO_DETERMINE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

