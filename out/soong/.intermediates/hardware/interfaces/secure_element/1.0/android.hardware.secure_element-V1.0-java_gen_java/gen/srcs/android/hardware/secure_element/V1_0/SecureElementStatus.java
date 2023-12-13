package android.hardware.secure_element.V1_0;


public final class SecureElementStatus {
    public static final byte SUCCESS = 0;
    public static final byte FAILED = 1;
    public static final byte CHANNEL_NOT_AVAILABLE = 2;
    public static final byte NO_SUCH_ELEMENT_ERROR = 3;
    public static final byte UNSUPPORTED_OPERATION = 4;
    public static final byte IOERROR = 5;
    public static final String toString(byte o) {
        if (o == SUCCESS) {
            return "SUCCESS";
        }
        if (o == FAILED) {
            return "FAILED";
        }
        if (o == CHANNEL_NOT_AVAILABLE) {
            return "CHANNEL_NOT_AVAILABLE";
        }
        if (o == NO_SUCH_ELEMENT_ERROR) {
            return "NO_SUCH_ELEMENT_ERROR";
        }
        if (o == UNSUPPORTED_OPERATION) {
            return "UNSUPPORTED_OPERATION";
        }
        if (o == IOERROR) {
            return "IOERROR";
        }
        return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
    }

    public static final String dumpBitfield(byte o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        byte flipped = 0;
        list.add("SUCCESS"); // SUCCESS == 0
        if ((o & FAILED) == FAILED) {
            list.add("FAILED");
            flipped |= FAILED;
        }
        if ((o & CHANNEL_NOT_AVAILABLE) == CHANNEL_NOT_AVAILABLE) {
            list.add("CHANNEL_NOT_AVAILABLE");
            flipped |= CHANNEL_NOT_AVAILABLE;
        }
        if ((o & NO_SUCH_ELEMENT_ERROR) == NO_SUCH_ELEMENT_ERROR) {
            list.add("NO_SUCH_ELEMENT_ERROR");
            flipped |= NO_SUCH_ELEMENT_ERROR;
        }
        if ((o & UNSUPPORTED_OPERATION) == UNSUPPORTED_OPERATION) {
            list.add("UNSUPPORTED_OPERATION");
            flipped |= UNSUPPORTED_OPERATION;
        }
        if ((o & IOERROR) == IOERROR) {
            list.add("IOERROR");
            flipped |= IOERROR;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

