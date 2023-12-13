package android.hardware.radio.V1_6;


public final class PbReceivedStatus {
    public static final byte PB_RECEIVED_OK = 1;
    public static final byte PB_RECEIVED_ERROR = 2;
    public static final byte PB_RECEIVED_ABORT = 3;
    public static final byte PB_RECEIVED_FINAL = 4;
    public static final String toString(byte o) {
        if (o == PB_RECEIVED_OK) {
            return "PB_RECEIVED_OK";
        }
        if (o == PB_RECEIVED_ERROR) {
            return "PB_RECEIVED_ERROR";
        }
        if (o == PB_RECEIVED_ABORT) {
            return "PB_RECEIVED_ABORT";
        }
        if (o == PB_RECEIVED_FINAL) {
            return "PB_RECEIVED_FINAL";
        }
        return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
    }

    public static final String dumpBitfield(byte o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        byte flipped = 0;
        if ((o & PB_RECEIVED_OK) == PB_RECEIVED_OK) {
            list.add("PB_RECEIVED_OK");
            flipped |= PB_RECEIVED_OK;
        }
        if ((o & PB_RECEIVED_ERROR) == PB_RECEIVED_ERROR) {
            list.add("PB_RECEIVED_ERROR");
            flipped |= PB_RECEIVED_ERROR;
        }
        if ((o & PB_RECEIVED_ABORT) == PB_RECEIVED_ABORT) {
            list.add("PB_RECEIVED_ABORT");
            flipped |= PB_RECEIVED_ABORT;
        }
        if ((o & PB_RECEIVED_FINAL) == PB_RECEIVED_FINAL) {
            list.add("PB_RECEIVED_FINAL");
            flipped |= PB_RECEIVED_FINAL;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

