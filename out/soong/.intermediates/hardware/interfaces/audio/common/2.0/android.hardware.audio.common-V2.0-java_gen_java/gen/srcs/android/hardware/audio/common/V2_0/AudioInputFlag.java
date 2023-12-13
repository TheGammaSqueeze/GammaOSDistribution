package android.hardware.audio.common.V2_0;


public final class AudioInputFlag {
    public static final int NONE = 0 /* 0x0 */;
    public static final int FAST = 1 /* 0x1 */;
    public static final int HW_HOTWORD = 2 /* 0x2 */;
    public static final int RAW = 4 /* 0x4 */;
    public static final int SYNC = 8 /* 0x8 */;
    public static final int MMAP_NOIRQ = 16 /* 0x10 */;
    public static final int VOIP_TX = 32 /* 0x20 */;
    public static final String toString(int o) {
        if (o == NONE) {
            return "NONE";
        }
        if (o == FAST) {
            return "FAST";
        }
        if (o == HW_HOTWORD) {
            return "HW_HOTWORD";
        }
        if (o == RAW) {
            return "RAW";
        }
        if (o == SYNC) {
            return "SYNC";
        }
        if (o == MMAP_NOIRQ) {
            return "MMAP_NOIRQ";
        }
        if (o == VOIP_TX) {
            return "VOIP_TX";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NONE"); // NONE == 0
        if ((o & FAST) == FAST) {
            list.add("FAST");
            flipped |= FAST;
        }
        if ((o & HW_HOTWORD) == HW_HOTWORD) {
            list.add("HW_HOTWORD");
            flipped |= HW_HOTWORD;
        }
        if ((o & RAW) == RAW) {
            list.add("RAW");
            flipped |= RAW;
        }
        if ((o & SYNC) == SYNC) {
            list.add("SYNC");
            flipped |= SYNC;
        }
        if ((o & MMAP_NOIRQ) == MMAP_NOIRQ) {
            list.add("MMAP_NOIRQ");
            flipped |= MMAP_NOIRQ;
        }
        if ((o & VOIP_TX) == VOIP_TX) {
            list.add("VOIP_TX");
            flipped |= VOIP_TX;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

