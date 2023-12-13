package android.hardware.audio.common.V2_0;


public final class AudioHandleConsts {
    public static final int AUDIO_IO_HANDLE_NONE = 0;
    public static final int AUDIO_MODULE_HANDLE_NONE = 0;
    public static final int AUDIO_PORT_HANDLE_NONE = 0;
    public static final int AUDIO_PATCH_HANDLE_NONE = 0;
    public static final String toString(int o) {
        if (o == AUDIO_IO_HANDLE_NONE) {
            return "AUDIO_IO_HANDLE_NONE";
        }
        if (o == AUDIO_MODULE_HANDLE_NONE) {
            return "AUDIO_MODULE_HANDLE_NONE";
        }
        if (o == AUDIO_PORT_HANDLE_NONE) {
            return "AUDIO_PORT_HANDLE_NONE";
        }
        if (o == AUDIO_PATCH_HANDLE_NONE) {
            return "AUDIO_PATCH_HANDLE_NONE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("AUDIO_IO_HANDLE_NONE"); // AUDIO_IO_HANDLE_NONE == 0
        list.add("AUDIO_MODULE_HANDLE_NONE"); // AUDIO_MODULE_HANDLE_NONE == 0
        list.add("AUDIO_PORT_HANDLE_NONE"); // AUDIO_PORT_HANDLE_NONE == 0
        list.add("AUDIO_PATCH_HANDLE_NONE"); // AUDIO_PATCH_HANDLE_NONE == 0
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

