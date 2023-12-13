package android.hardware.wifi.V1_0;


public final class WifiDebugRingBufferFlags {
    public static final int HAS_BINARY_ENTRIES = 1 /* 1 << 0 */;
    public static final int HAS_ASCII_ENTRIES = 2 /* 1 << 1 */;
    public static final int HAS_PER_PACKET_ENTRIES = 4 /* 1 << 2 */;
    public static final String toString(int o) {
        if (o == HAS_BINARY_ENTRIES) {
            return "HAS_BINARY_ENTRIES";
        }
        if (o == HAS_ASCII_ENTRIES) {
            return "HAS_ASCII_ENTRIES";
        }
        if (o == HAS_PER_PACKET_ENTRIES) {
            return "HAS_PER_PACKET_ENTRIES";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & HAS_BINARY_ENTRIES) == HAS_BINARY_ENTRIES) {
            list.add("HAS_BINARY_ENTRIES");
            flipped |= HAS_BINARY_ENTRIES;
        }
        if ((o & HAS_ASCII_ENTRIES) == HAS_ASCII_ENTRIES) {
            list.add("HAS_ASCII_ENTRIES");
            flipped |= HAS_ASCII_ENTRIES;
        }
        if ((o & HAS_PER_PACKET_ENTRIES) == HAS_PER_PACKET_ENTRIES) {
            list.add("HAS_PER_PACKET_ENTRIES");
            flipped |= HAS_PER_PACKET_ENTRIES;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

