package android.hardware.radio.V1_0;


public final class RadioCdmaSmsConst {
    public static final int ADDRESS_MAX = 36;
    public static final int SUBADDRESS_MAX = 36;
    public static final int BEARER_DATA_MAX = 255;
    public static final int UDH_MAX_SND_SIZE = 128;
    public static final int UDH_EO_DATA_SEGMENT_MAX = 131;
    public static final int MAX_UD_HEADERS = 7;
    public static final int USER_DATA_MAX = 229;
    public static final int UDH_LARGE_PIC_SIZE = 128;
    public static final int UDH_SMALL_PIC_SIZE = 32;
    public static final int UDH_VAR_PIC_SIZE = 134;
    public static final int UDH_ANIM_NUM_BITMAPS = 4;
    public static final int UDH_LARGE_BITMAP_SIZE = 32;
    public static final int UDH_SMALL_BITMAP_SIZE = 8;
    public static final int UDH_OTHER_SIZE = 226;
    public static final int IP_ADDRESS_SIZE = 4;
    public static final String toString(int o) {
        if (o == ADDRESS_MAX) {
            return "ADDRESS_MAX";
        }
        if (o == SUBADDRESS_MAX) {
            return "SUBADDRESS_MAX";
        }
        if (o == BEARER_DATA_MAX) {
            return "BEARER_DATA_MAX";
        }
        if (o == UDH_MAX_SND_SIZE) {
            return "UDH_MAX_SND_SIZE";
        }
        if (o == UDH_EO_DATA_SEGMENT_MAX) {
            return "UDH_EO_DATA_SEGMENT_MAX";
        }
        if (o == MAX_UD_HEADERS) {
            return "MAX_UD_HEADERS";
        }
        if (o == USER_DATA_MAX) {
            return "USER_DATA_MAX";
        }
        if (o == UDH_LARGE_PIC_SIZE) {
            return "UDH_LARGE_PIC_SIZE";
        }
        if (o == UDH_SMALL_PIC_SIZE) {
            return "UDH_SMALL_PIC_SIZE";
        }
        if (o == UDH_VAR_PIC_SIZE) {
            return "UDH_VAR_PIC_SIZE";
        }
        if (o == UDH_ANIM_NUM_BITMAPS) {
            return "UDH_ANIM_NUM_BITMAPS";
        }
        if (o == UDH_LARGE_BITMAP_SIZE) {
            return "UDH_LARGE_BITMAP_SIZE";
        }
        if (o == UDH_SMALL_BITMAP_SIZE) {
            return "UDH_SMALL_BITMAP_SIZE";
        }
        if (o == UDH_OTHER_SIZE) {
            return "UDH_OTHER_SIZE";
        }
        if (o == IP_ADDRESS_SIZE) {
            return "IP_ADDRESS_SIZE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & ADDRESS_MAX) == ADDRESS_MAX) {
            list.add("ADDRESS_MAX");
            flipped |= ADDRESS_MAX;
        }
        if ((o & SUBADDRESS_MAX) == SUBADDRESS_MAX) {
            list.add("SUBADDRESS_MAX");
            flipped |= SUBADDRESS_MAX;
        }
        if ((o & BEARER_DATA_MAX) == BEARER_DATA_MAX) {
            list.add("BEARER_DATA_MAX");
            flipped |= BEARER_DATA_MAX;
        }
        if ((o & UDH_MAX_SND_SIZE) == UDH_MAX_SND_SIZE) {
            list.add("UDH_MAX_SND_SIZE");
            flipped |= UDH_MAX_SND_SIZE;
        }
        if ((o & UDH_EO_DATA_SEGMENT_MAX) == UDH_EO_DATA_SEGMENT_MAX) {
            list.add("UDH_EO_DATA_SEGMENT_MAX");
            flipped |= UDH_EO_DATA_SEGMENT_MAX;
        }
        if ((o & MAX_UD_HEADERS) == MAX_UD_HEADERS) {
            list.add("MAX_UD_HEADERS");
            flipped |= MAX_UD_HEADERS;
        }
        if ((o & USER_DATA_MAX) == USER_DATA_MAX) {
            list.add("USER_DATA_MAX");
            flipped |= USER_DATA_MAX;
        }
        if ((o & UDH_LARGE_PIC_SIZE) == UDH_LARGE_PIC_SIZE) {
            list.add("UDH_LARGE_PIC_SIZE");
            flipped |= UDH_LARGE_PIC_SIZE;
        }
        if ((o & UDH_SMALL_PIC_SIZE) == UDH_SMALL_PIC_SIZE) {
            list.add("UDH_SMALL_PIC_SIZE");
            flipped |= UDH_SMALL_PIC_SIZE;
        }
        if ((o & UDH_VAR_PIC_SIZE) == UDH_VAR_PIC_SIZE) {
            list.add("UDH_VAR_PIC_SIZE");
            flipped |= UDH_VAR_PIC_SIZE;
        }
        if ((o & UDH_ANIM_NUM_BITMAPS) == UDH_ANIM_NUM_BITMAPS) {
            list.add("UDH_ANIM_NUM_BITMAPS");
            flipped |= UDH_ANIM_NUM_BITMAPS;
        }
        if ((o & UDH_LARGE_BITMAP_SIZE) == UDH_LARGE_BITMAP_SIZE) {
            list.add("UDH_LARGE_BITMAP_SIZE");
            flipped |= UDH_LARGE_BITMAP_SIZE;
        }
        if ((o & UDH_SMALL_BITMAP_SIZE) == UDH_SMALL_BITMAP_SIZE) {
            list.add("UDH_SMALL_BITMAP_SIZE");
            flipped |= UDH_SMALL_BITMAP_SIZE;
        }
        if ((o & UDH_OTHER_SIZE) == UDH_OTHER_SIZE) {
            list.add("UDH_OTHER_SIZE");
            flipped |= UDH_OTHER_SIZE;
        }
        if ((o & IP_ADDRESS_SIZE) == IP_ADDRESS_SIZE) {
            list.add("IP_ADDRESS_SIZE");
            flipped |= IP_ADDRESS_SIZE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

