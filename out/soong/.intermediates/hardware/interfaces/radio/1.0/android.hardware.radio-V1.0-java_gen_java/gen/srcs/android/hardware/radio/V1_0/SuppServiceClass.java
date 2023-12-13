package android.hardware.radio.V1_0;


public final class SuppServiceClass {
    public static final int NONE = 0;
    public static final int VOICE = 1 /* 1 << 0 */;
    public static final int DATA = 2 /* 1 << 1 */;
    public static final int FAX = 4 /* 1 << 2 */;
    public static final int SMS = 8 /* 1 << 3 */;
    public static final int DATA_SYNC = 16 /* 1 << 4 */;
    public static final int DATA_ASYNC = 32 /* 1 << 5 */;
    public static final int PACKET = 64 /* 1 << 6 */;
    public static final int PAD = 128 /* 1 << 7 */;
    public static final int MAX = 128 /* 1 << 7 */;
    public static final String toString(int o) {
        if (o == NONE) {
            return "NONE";
        }
        if (o == VOICE) {
            return "VOICE";
        }
        if (o == DATA) {
            return "DATA";
        }
        if (o == FAX) {
            return "FAX";
        }
        if (o == SMS) {
            return "SMS";
        }
        if (o == DATA_SYNC) {
            return "DATA_SYNC";
        }
        if (o == DATA_ASYNC) {
            return "DATA_ASYNC";
        }
        if (o == PACKET) {
            return "PACKET";
        }
        if (o == PAD) {
            return "PAD";
        }
        if (o == MAX) {
            return "MAX";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NONE"); // NONE == 0
        if ((o & VOICE) == VOICE) {
            list.add("VOICE");
            flipped |= VOICE;
        }
        if ((o & DATA) == DATA) {
            list.add("DATA");
            flipped |= DATA;
        }
        if ((o & FAX) == FAX) {
            list.add("FAX");
            flipped |= FAX;
        }
        if ((o & SMS) == SMS) {
            list.add("SMS");
            flipped |= SMS;
        }
        if ((o & DATA_SYNC) == DATA_SYNC) {
            list.add("DATA_SYNC");
            flipped |= DATA_SYNC;
        }
        if ((o & DATA_ASYNC) == DATA_ASYNC) {
            list.add("DATA_ASYNC");
            flipped |= DATA_ASYNC;
        }
        if ((o & PACKET) == PACKET) {
            list.add("PACKET");
            flipped |= PACKET;
        }
        if ((o & PAD) == PAD) {
            list.add("PAD");
            flipped |= PAD;
        }
        if ((o & MAX) == MAX) {
            list.add("MAX");
            flipped |= MAX;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

