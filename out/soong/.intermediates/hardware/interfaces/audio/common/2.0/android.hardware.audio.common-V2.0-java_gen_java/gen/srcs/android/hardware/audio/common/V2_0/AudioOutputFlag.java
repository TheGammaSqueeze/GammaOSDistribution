package android.hardware.audio.common.V2_0;


public final class AudioOutputFlag {
    public static final int NONE = 0 /* 0x0 */;
    public static final int DIRECT = 1 /* 0x1 */;
    public static final int PRIMARY = 2 /* 0x2 */;
    public static final int FAST = 4 /* 0x4 */;
    public static final int DEEP_BUFFER = 8 /* 0x8 */;
    public static final int COMPRESS_OFFLOAD = 16 /* 0x10 */;
    public static final int NON_BLOCKING = 32 /* 0x20 */;
    public static final int HW_AV_SYNC = 64 /* 0x40 */;
    public static final int TTS = 128 /* 0x80 */;
    public static final int RAW = 256 /* 0x100 */;
    public static final int SYNC = 512 /* 0x200 */;
    public static final int IEC958_NONAUDIO = 1024 /* 0x400 */;
    public static final int DIRECT_PCM = 8192 /* 0x2000 */;
    public static final int MMAP_NOIRQ = 16384 /* 0x4000 */;
    public static final int VOIP_RX = 32768 /* 0x8000 */;
    public static final String toString(int o) {
        if (o == NONE) {
            return "NONE";
        }
        if (o == DIRECT) {
            return "DIRECT";
        }
        if (o == PRIMARY) {
            return "PRIMARY";
        }
        if (o == FAST) {
            return "FAST";
        }
        if (o == DEEP_BUFFER) {
            return "DEEP_BUFFER";
        }
        if (o == COMPRESS_OFFLOAD) {
            return "COMPRESS_OFFLOAD";
        }
        if (o == NON_BLOCKING) {
            return "NON_BLOCKING";
        }
        if (o == HW_AV_SYNC) {
            return "HW_AV_SYNC";
        }
        if (o == TTS) {
            return "TTS";
        }
        if (o == RAW) {
            return "RAW";
        }
        if (o == SYNC) {
            return "SYNC";
        }
        if (o == IEC958_NONAUDIO) {
            return "IEC958_NONAUDIO";
        }
        if (o == DIRECT_PCM) {
            return "DIRECT_PCM";
        }
        if (o == MMAP_NOIRQ) {
            return "MMAP_NOIRQ";
        }
        if (o == VOIP_RX) {
            return "VOIP_RX";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NONE"); // NONE == 0
        if ((o & DIRECT) == DIRECT) {
            list.add("DIRECT");
            flipped |= DIRECT;
        }
        if ((o & PRIMARY) == PRIMARY) {
            list.add("PRIMARY");
            flipped |= PRIMARY;
        }
        if ((o & FAST) == FAST) {
            list.add("FAST");
            flipped |= FAST;
        }
        if ((o & DEEP_BUFFER) == DEEP_BUFFER) {
            list.add("DEEP_BUFFER");
            flipped |= DEEP_BUFFER;
        }
        if ((o & COMPRESS_OFFLOAD) == COMPRESS_OFFLOAD) {
            list.add("COMPRESS_OFFLOAD");
            flipped |= COMPRESS_OFFLOAD;
        }
        if ((o & NON_BLOCKING) == NON_BLOCKING) {
            list.add("NON_BLOCKING");
            flipped |= NON_BLOCKING;
        }
        if ((o & HW_AV_SYNC) == HW_AV_SYNC) {
            list.add("HW_AV_SYNC");
            flipped |= HW_AV_SYNC;
        }
        if ((o & TTS) == TTS) {
            list.add("TTS");
            flipped |= TTS;
        }
        if ((o & RAW) == RAW) {
            list.add("RAW");
            flipped |= RAW;
        }
        if ((o & SYNC) == SYNC) {
            list.add("SYNC");
            flipped |= SYNC;
        }
        if ((o & IEC958_NONAUDIO) == IEC958_NONAUDIO) {
            list.add("IEC958_NONAUDIO");
            flipped |= IEC958_NONAUDIO;
        }
        if ((o & DIRECT_PCM) == DIRECT_PCM) {
            list.add("DIRECT_PCM");
            flipped |= DIRECT_PCM;
        }
        if ((o & MMAP_NOIRQ) == MMAP_NOIRQ) {
            list.add("MMAP_NOIRQ");
            flipped |= MMAP_NOIRQ;
        }
        if ((o & VOIP_RX) == VOIP_RX) {
            list.add("VOIP_RX");
            flipped |= VOIP_RX;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

