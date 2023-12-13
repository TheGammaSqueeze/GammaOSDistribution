package android.hardware.biometrics.face.V1_0;


public final class Status {
    /**
     * The method was invoked successfully.
     */
    public static final int OK = 0;
    /**
     * One of the arguments to the method call is invalid.
     */
    public static final int ILLEGAL_ARGUMENT = 1;
    /**
     * This face HAL does not support this operation.
     */
    public static final int OPERATION_NOT_SUPPORTED = 2;
    /**
     * The HAL has encountered an internal error and cannot complete the request.
     */
    public static final int INTERNAL_ERROR = 3;
    /**
     * The operation could not be completed because there are no enrolled
     * templates.
     */
    public static final int NOT_ENROLLED = 4;
    public static final String toString(int o) {
        if (o == OK) {
            return "OK";
        }
        if (o == ILLEGAL_ARGUMENT) {
            return "ILLEGAL_ARGUMENT";
        }
        if (o == OPERATION_NOT_SUPPORTED) {
            return "OPERATION_NOT_SUPPORTED";
        }
        if (o == INTERNAL_ERROR) {
            return "INTERNAL_ERROR";
        }
        if (o == NOT_ENROLLED) {
            return "NOT_ENROLLED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("OK"); // OK == 0
        if ((o & ILLEGAL_ARGUMENT) == ILLEGAL_ARGUMENT) {
            list.add("ILLEGAL_ARGUMENT");
            flipped |= ILLEGAL_ARGUMENT;
        }
        if ((o & OPERATION_NOT_SUPPORTED) == OPERATION_NOT_SUPPORTED) {
            list.add("OPERATION_NOT_SUPPORTED");
            flipped |= OPERATION_NOT_SUPPORTED;
        }
        if ((o & INTERNAL_ERROR) == INTERNAL_ERROR) {
            list.add("INTERNAL_ERROR");
            flipped |= INTERNAL_ERROR;
        }
        if ((o & NOT_ENROLLED) == NOT_ENROLLED) {
            list.add("NOT_ENROLLED");
            flipped |= NOT_ENROLLED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

