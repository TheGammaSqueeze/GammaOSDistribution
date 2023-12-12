package android.hardware.audio.common.V2_0;


public final class AudioChannelMask {
    public static final int REPRESENTATION_POSITION = 0;
    /**
     * must be 0 for compatibility
     *
     *
     * 1 is reserved for future use
     */
    public static final int REPRESENTATION_INDEX = 2;
    /**
     * 3 is reserved for future use
     *
     *
     * These can be a complete value of AudioChannelMask
     */
    public static final int NONE = 0 /* 0x0 */;
    public static final int INVALID = -1073741824 /* 0xC0000000 */;
    /**
     * These can be the bits portion of an AudioChannelMask
     * with representation REPRESENTATION_POSITION.
     *
     *
     * output channels
     */
    public static final int OUT_FRONT_LEFT = 1 /* 0x1 */;
    public static final int OUT_FRONT_RIGHT = 2 /* 0x2 */;
    public static final int OUT_FRONT_CENTER = 4 /* 0x4 */;
    public static final int OUT_LOW_FREQUENCY = 8 /* 0x8 */;
    public static final int OUT_BACK_LEFT = 16 /* 0x10 */;
    public static final int OUT_BACK_RIGHT = 32 /* 0x20 */;
    public static final int OUT_FRONT_LEFT_OF_CENTER = 64 /* 0x40 */;
    public static final int OUT_FRONT_RIGHT_OF_CENTER = 128 /* 0x80 */;
    public static final int OUT_BACK_CENTER = 256 /* 0x100 */;
    public static final int OUT_SIDE_LEFT = 512 /* 0x200 */;
    public static final int OUT_SIDE_RIGHT = 1024 /* 0x400 */;
    public static final int OUT_TOP_CENTER = 2048 /* 0x800 */;
    public static final int OUT_TOP_FRONT_LEFT = 4096 /* 0x1000 */;
    public static final int OUT_TOP_FRONT_CENTER = 8192 /* 0x2000 */;
    public static final int OUT_TOP_FRONT_RIGHT = 16384 /* 0x4000 */;
    public static final int OUT_TOP_BACK_LEFT = 32768 /* 0x8000 */;
    public static final int OUT_TOP_BACK_CENTER = 65536 /* 0x10000 */;
    public static final int OUT_TOP_BACK_RIGHT = 131072 /* 0x20000 */;
    public static final int OUT_MONO = 1 /* OUT_FRONT_LEFT */;
    public static final int OUT_STEREO = 3 /* (OUT_FRONT_LEFT | OUT_FRONT_RIGHT) */;
    public static final int OUT_2POINT1 = 11 /* (OUT_FRONT_LEFT | OUT_FRONT_RIGHT | OUT_LOW_FREQUENCY) */;
    public static final int OUT_QUAD = 51 /* (OUT_FRONT_LEFT | OUT_FRONT_RIGHT | OUT_BACK_LEFT | OUT_BACK_RIGHT) */;
    public static final int OUT_QUAD_BACK = 51 /* OUT_QUAD */;
    /**
     * like OUT_QUAD_BACK with *_SIDE_* instead of *_BACK_*
     */
    public static final int OUT_QUAD_SIDE = 1539 /* (OUT_FRONT_LEFT | OUT_FRONT_RIGHT | OUT_SIDE_LEFT | OUT_SIDE_RIGHT) */;
    public static final int OUT_SURROUND = 263 /* (OUT_FRONT_LEFT | OUT_FRONT_RIGHT | OUT_FRONT_CENTER | OUT_BACK_CENTER) */;
    public static final int OUT_PENTA = 55 /* (OUT_QUAD | OUT_FRONT_CENTER) */;
    public static final int OUT_5POINT1 = 63 /* (OUT_FRONT_LEFT | OUT_FRONT_RIGHT | OUT_FRONT_CENTER | OUT_LOW_FREQUENCY | OUT_BACK_LEFT | OUT_BACK_RIGHT) */;
    public static final int OUT_5POINT1_BACK = 63 /* OUT_5POINT1 */;
    /**
     * like OUT_5POINT1_BACK with *_SIDE_* instead of *_BACK_*
     */
    public static final int OUT_5POINT1_SIDE = 1551 /* (OUT_FRONT_LEFT | OUT_FRONT_RIGHT | OUT_FRONT_CENTER | OUT_LOW_FREQUENCY | OUT_SIDE_LEFT | OUT_SIDE_RIGHT) */;
    public static final int OUT_6POINT1 = 319 /* (OUT_FRONT_LEFT | OUT_FRONT_RIGHT | OUT_FRONT_CENTER | OUT_LOW_FREQUENCY | OUT_BACK_LEFT | OUT_BACK_RIGHT | OUT_BACK_CENTER) */;
    /**
     * matches the correct AudioFormat.CHANNEL_OUT_7POINT1_SURROUND
     */
    public static final int OUT_7POINT1 = 1599 /* (OUT_FRONT_LEFT | OUT_FRONT_RIGHT | OUT_FRONT_CENTER | OUT_LOW_FREQUENCY | OUT_BACK_LEFT | OUT_BACK_RIGHT | OUT_SIDE_LEFT | OUT_SIDE_RIGHT) */;
    public static final int OUT_ALL = 262143 /* (OUT_FRONT_LEFT | OUT_FRONT_RIGHT | OUT_FRONT_CENTER | OUT_LOW_FREQUENCY | OUT_BACK_LEFT | OUT_BACK_RIGHT | OUT_FRONT_LEFT_OF_CENTER | OUT_FRONT_RIGHT_OF_CENTER | OUT_BACK_CENTER | OUT_SIDE_LEFT | OUT_SIDE_RIGHT | OUT_TOP_CENTER | OUT_TOP_FRONT_LEFT | OUT_TOP_FRONT_CENTER | OUT_TOP_FRONT_RIGHT | OUT_TOP_BACK_LEFT | OUT_TOP_BACK_CENTER | OUT_TOP_BACK_RIGHT) */;
    /**
     * These are bits only, not complete values
     *
     *
     * input channels
     */
    public static final int IN_LEFT = 4 /* 0x4 */;
    public static final int IN_RIGHT = 8 /* 0x8 */;
    public static final int IN_FRONT = 16 /* 0x10 */;
    public static final int IN_BACK = 32 /* 0x20 */;
    public static final int IN_LEFT_PROCESSED = 64 /* 0x40 */;
    public static final int IN_RIGHT_PROCESSED = 128 /* 0x80 */;
    public static final int IN_FRONT_PROCESSED = 256 /* 0x100 */;
    public static final int IN_BACK_PROCESSED = 512 /* 0x200 */;
    public static final int IN_PRESSURE = 1024 /* 0x400 */;
    public static final int IN_X_AXIS = 2048 /* 0x800 */;
    public static final int IN_Y_AXIS = 4096 /* 0x1000 */;
    public static final int IN_Z_AXIS = 8192 /* 0x2000 */;
    public static final int IN_VOICE_UPLINK = 16384 /* 0x4000 */;
    public static final int IN_VOICE_DNLINK = 32768 /* 0x8000 */;
    public static final int IN_MONO = 16 /* IN_FRONT */;
    public static final int IN_STEREO = 12 /* (IN_LEFT | IN_RIGHT) */;
    public static final int IN_FRONT_BACK = 48 /* (IN_FRONT | IN_BACK) */;
    public static final int IN_6 = 252 /* (IN_LEFT | IN_RIGHT | IN_FRONT | IN_BACK | IN_LEFT_PROCESSED | IN_RIGHT_PROCESSED) */;
    public static final int IN_VOICE_UPLINK_MONO = 16400 /* (IN_VOICE_UPLINK | IN_MONO) */;
    public static final int IN_VOICE_DNLINK_MONO = 32784 /* (IN_VOICE_DNLINK | IN_MONO) */;
    public static final int IN_VOICE_CALL_MONO = 49168 /* (IN_VOICE_UPLINK_MONO | IN_VOICE_DNLINK_MONO) */;
    public static final int IN_ALL = 65532 /* (IN_LEFT | IN_RIGHT | IN_FRONT | IN_BACK | IN_LEFT_PROCESSED | IN_RIGHT_PROCESSED | IN_FRONT_PROCESSED | IN_BACK_PROCESSED | IN_PRESSURE | IN_X_AXIS | IN_Y_AXIS | IN_Z_AXIS | IN_VOICE_UPLINK | IN_VOICE_DNLINK) */;
    public static final int COUNT_MAX = 30;
    public static final int INDEX_HDR = -2147483648 /* REPRESENTATION_INDEX << COUNT_MAX */;
    public static final int INDEX_MASK_1 = -2147483647 /* INDEX_HDR | ((1 << 1) - 1) */;
    public static final int INDEX_MASK_2 = -2147483645 /* INDEX_HDR | ((1 << 2) - 1) */;
    public static final int INDEX_MASK_3 = -2147483641 /* INDEX_HDR | ((1 << 3) - 1) */;
    public static final int INDEX_MASK_4 = -2147483633 /* INDEX_HDR | ((1 << 4) - 1) */;
    public static final int INDEX_MASK_5 = -2147483617 /* INDEX_HDR | ((1 << 5) - 1) */;
    public static final int INDEX_MASK_6 = -2147483585 /* INDEX_HDR | ((1 << 6) - 1) */;
    public static final int INDEX_MASK_7 = -2147483521 /* INDEX_HDR | ((1 << 7) - 1) */;
    public static final int INDEX_MASK_8 = -2147483393 /* INDEX_HDR | ((1 << 8) - 1) */;
    public static final String toString(int o) {
        if (o == REPRESENTATION_POSITION) {
            return "REPRESENTATION_POSITION";
        }
        if (o == REPRESENTATION_INDEX) {
            return "REPRESENTATION_INDEX";
        }
        if (o == NONE) {
            return "NONE";
        }
        if (o == INVALID) {
            return "INVALID";
        }
        if (o == OUT_FRONT_LEFT) {
            return "OUT_FRONT_LEFT";
        }
        if (o == OUT_FRONT_RIGHT) {
            return "OUT_FRONT_RIGHT";
        }
        if (o == OUT_FRONT_CENTER) {
            return "OUT_FRONT_CENTER";
        }
        if (o == OUT_LOW_FREQUENCY) {
            return "OUT_LOW_FREQUENCY";
        }
        if (o == OUT_BACK_LEFT) {
            return "OUT_BACK_LEFT";
        }
        if (o == OUT_BACK_RIGHT) {
            return "OUT_BACK_RIGHT";
        }
        if (o == OUT_FRONT_LEFT_OF_CENTER) {
            return "OUT_FRONT_LEFT_OF_CENTER";
        }
        if (o == OUT_FRONT_RIGHT_OF_CENTER) {
            return "OUT_FRONT_RIGHT_OF_CENTER";
        }
        if (o == OUT_BACK_CENTER) {
            return "OUT_BACK_CENTER";
        }
        if (o == OUT_SIDE_LEFT) {
            return "OUT_SIDE_LEFT";
        }
        if (o == OUT_SIDE_RIGHT) {
            return "OUT_SIDE_RIGHT";
        }
        if (o == OUT_TOP_CENTER) {
            return "OUT_TOP_CENTER";
        }
        if (o == OUT_TOP_FRONT_LEFT) {
            return "OUT_TOP_FRONT_LEFT";
        }
        if (o == OUT_TOP_FRONT_CENTER) {
            return "OUT_TOP_FRONT_CENTER";
        }
        if (o == OUT_TOP_FRONT_RIGHT) {
            return "OUT_TOP_FRONT_RIGHT";
        }
        if (o == OUT_TOP_BACK_LEFT) {
            return "OUT_TOP_BACK_LEFT";
        }
        if (o == OUT_TOP_BACK_CENTER) {
            return "OUT_TOP_BACK_CENTER";
        }
        if (o == OUT_TOP_BACK_RIGHT) {
            return "OUT_TOP_BACK_RIGHT";
        }
        if (o == OUT_MONO) {
            return "OUT_MONO";
        }
        if (o == OUT_STEREO) {
            return "OUT_STEREO";
        }
        if (o == OUT_2POINT1) {
            return "OUT_2POINT1";
        }
        if (o == OUT_QUAD) {
            return "OUT_QUAD";
        }
        if (o == OUT_QUAD_BACK) {
            return "OUT_QUAD_BACK";
        }
        if (o == OUT_QUAD_SIDE) {
            return "OUT_QUAD_SIDE";
        }
        if (o == OUT_SURROUND) {
            return "OUT_SURROUND";
        }
        if (o == OUT_PENTA) {
            return "OUT_PENTA";
        }
        if (o == OUT_5POINT1) {
            return "OUT_5POINT1";
        }
        if (o == OUT_5POINT1_BACK) {
            return "OUT_5POINT1_BACK";
        }
        if (o == OUT_5POINT1_SIDE) {
            return "OUT_5POINT1_SIDE";
        }
        if (o == OUT_6POINT1) {
            return "OUT_6POINT1";
        }
        if (o == OUT_7POINT1) {
            return "OUT_7POINT1";
        }
        if (o == OUT_ALL) {
            return "OUT_ALL";
        }
        if (o == IN_LEFT) {
            return "IN_LEFT";
        }
        if (o == IN_RIGHT) {
            return "IN_RIGHT";
        }
        if (o == IN_FRONT) {
            return "IN_FRONT";
        }
        if (o == IN_BACK) {
            return "IN_BACK";
        }
        if (o == IN_LEFT_PROCESSED) {
            return "IN_LEFT_PROCESSED";
        }
        if (o == IN_RIGHT_PROCESSED) {
            return "IN_RIGHT_PROCESSED";
        }
        if (o == IN_FRONT_PROCESSED) {
            return "IN_FRONT_PROCESSED";
        }
        if (o == IN_BACK_PROCESSED) {
            return "IN_BACK_PROCESSED";
        }
        if (o == IN_PRESSURE) {
            return "IN_PRESSURE";
        }
        if (o == IN_X_AXIS) {
            return "IN_X_AXIS";
        }
        if (o == IN_Y_AXIS) {
            return "IN_Y_AXIS";
        }
        if (o == IN_Z_AXIS) {
            return "IN_Z_AXIS";
        }
        if (o == IN_VOICE_UPLINK) {
            return "IN_VOICE_UPLINK";
        }
        if (o == IN_VOICE_DNLINK) {
            return "IN_VOICE_DNLINK";
        }
        if (o == IN_MONO) {
            return "IN_MONO";
        }
        if (o == IN_STEREO) {
            return "IN_STEREO";
        }
        if (o == IN_FRONT_BACK) {
            return "IN_FRONT_BACK";
        }
        if (o == IN_6) {
            return "IN_6";
        }
        if (o == IN_VOICE_UPLINK_MONO) {
            return "IN_VOICE_UPLINK_MONO";
        }
        if (o == IN_VOICE_DNLINK_MONO) {
            return "IN_VOICE_DNLINK_MONO";
        }
        if (o == IN_VOICE_CALL_MONO) {
            return "IN_VOICE_CALL_MONO";
        }
        if (o == IN_ALL) {
            return "IN_ALL";
        }
        if (o == COUNT_MAX) {
            return "COUNT_MAX";
        }
        if (o == INDEX_HDR) {
            return "INDEX_HDR";
        }
        if (o == INDEX_MASK_1) {
            return "INDEX_MASK_1";
        }
        if (o == INDEX_MASK_2) {
            return "INDEX_MASK_2";
        }
        if (o == INDEX_MASK_3) {
            return "INDEX_MASK_3";
        }
        if (o == INDEX_MASK_4) {
            return "INDEX_MASK_4";
        }
        if (o == INDEX_MASK_5) {
            return "INDEX_MASK_5";
        }
        if (o == INDEX_MASK_6) {
            return "INDEX_MASK_6";
        }
        if (o == INDEX_MASK_7) {
            return "INDEX_MASK_7";
        }
        if (o == INDEX_MASK_8) {
            return "INDEX_MASK_8";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("REPRESENTATION_POSITION"); // REPRESENTATION_POSITION == 0
        if ((o & REPRESENTATION_INDEX) == REPRESENTATION_INDEX) {
            list.add("REPRESENTATION_INDEX");
            flipped |= REPRESENTATION_INDEX;
        }
        list.add("NONE"); // NONE == 0
        if ((o & INVALID) == INVALID) {
            list.add("INVALID");
            flipped |= INVALID;
        }
        if ((o & OUT_FRONT_LEFT) == OUT_FRONT_LEFT) {
            list.add("OUT_FRONT_LEFT");
            flipped |= OUT_FRONT_LEFT;
        }
        if ((o & OUT_FRONT_RIGHT) == OUT_FRONT_RIGHT) {
            list.add("OUT_FRONT_RIGHT");
            flipped |= OUT_FRONT_RIGHT;
        }
        if ((o & OUT_FRONT_CENTER) == OUT_FRONT_CENTER) {
            list.add("OUT_FRONT_CENTER");
            flipped |= OUT_FRONT_CENTER;
        }
        if ((o & OUT_LOW_FREQUENCY) == OUT_LOW_FREQUENCY) {
            list.add("OUT_LOW_FREQUENCY");
            flipped |= OUT_LOW_FREQUENCY;
        }
        if ((o & OUT_BACK_LEFT) == OUT_BACK_LEFT) {
            list.add("OUT_BACK_LEFT");
            flipped |= OUT_BACK_LEFT;
        }
        if ((o & OUT_BACK_RIGHT) == OUT_BACK_RIGHT) {
            list.add("OUT_BACK_RIGHT");
            flipped |= OUT_BACK_RIGHT;
        }
        if ((o & OUT_FRONT_LEFT_OF_CENTER) == OUT_FRONT_LEFT_OF_CENTER) {
            list.add("OUT_FRONT_LEFT_OF_CENTER");
            flipped |= OUT_FRONT_LEFT_OF_CENTER;
        }
        if ((o & OUT_FRONT_RIGHT_OF_CENTER) == OUT_FRONT_RIGHT_OF_CENTER) {
            list.add("OUT_FRONT_RIGHT_OF_CENTER");
            flipped |= OUT_FRONT_RIGHT_OF_CENTER;
        }
        if ((o & OUT_BACK_CENTER) == OUT_BACK_CENTER) {
            list.add("OUT_BACK_CENTER");
            flipped |= OUT_BACK_CENTER;
        }
        if ((o & OUT_SIDE_LEFT) == OUT_SIDE_LEFT) {
            list.add("OUT_SIDE_LEFT");
            flipped |= OUT_SIDE_LEFT;
        }
        if ((o & OUT_SIDE_RIGHT) == OUT_SIDE_RIGHT) {
            list.add("OUT_SIDE_RIGHT");
            flipped |= OUT_SIDE_RIGHT;
        }
        if ((o & OUT_TOP_CENTER) == OUT_TOP_CENTER) {
            list.add("OUT_TOP_CENTER");
            flipped |= OUT_TOP_CENTER;
        }
        if ((o & OUT_TOP_FRONT_LEFT) == OUT_TOP_FRONT_LEFT) {
            list.add("OUT_TOP_FRONT_LEFT");
            flipped |= OUT_TOP_FRONT_LEFT;
        }
        if ((o & OUT_TOP_FRONT_CENTER) == OUT_TOP_FRONT_CENTER) {
            list.add("OUT_TOP_FRONT_CENTER");
            flipped |= OUT_TOP_FRONT_CENTER;
        }
        if ((o & OUT_TOP_FRONT_RIGHT) == OUT_TOP_FRONT_RIGHT) {
            list.add("OUT_TOP_FRONT_RIGHT");
            flipped |= OUT_TOP_FRONT_RIGHT;
        }
        if ((o & OUT_TOP_BACK_LEFT) == OUT_TOP_BACK_LEFT) {
            list.add("OUT_TOP_BACK_LEFT");
            flipped |= OUT_TOP_BACK_LEFT;
        }
        if ((o & OUT_TOP_BACK_CENTER) == OUT_TOP_BACK_CENTER) {
            list.add("OUT_TOP_BACK_CENTER");
            flipped |= OUT_TOP_BACK_CENTER;
        }
        if ((o & OUT_TOP_BACK_RIGHT) == OUT_TOP_BACK_RIGHT) {
            list.add("OUT_TOP_BACK_RIGHT");
            flipped |= OUT_TOP_BACK_RIGHT;
        }
        if ((o & OUT_MONO) == OUT_MONO) {
            list.add("OUT_MONO");
            flipped |= OUT_MONO;
        }
        if ((o & OUT_STEREO) == OUT_STEREO) {
            list.add("OUT_STEREO");
            flipped |= OUT_STEREO;
        }
        if ((o & OUT_2POINT1) == OUT_2POINT1) {
            list.add("OUT_2POINT1");
            flipped |= OUT_2POINT1;
        }
        if ((o & OUT_QUAD) == OUT_QUAD) {
            list.add("OUT_QUAD");
            flipped |= OUT_QUAD;
        }
        if ((o & OUT_QUAD_BACK) == OUT_QUAD_BACK) {
            list.add("OUT_QUAD_BACK");
            flipped |= OUT_QUAD_BACK;
        }
        if ((o & OUT_QUAD_SIDE) == OUT_QUAD_SIDE) {
            list.add("OUT_QUAD_SIDE");
            flipped |= OUT_QUAD_SIDE;
        }
        if ((o & OUT_SURROUND) == OUT_SURROUND) {
            list.add("OUT_SURROUND");
            flipped |= OUT_SURROUND;
        }
        if ((o & OUT_PENTA) == OUT_PENTA) {
            list.add("OUT_PENTA");
            flipped |= OUT_PENTA;
        }
        if ((o & OUT_5POINT1) == OUT_5POINT1) {
            list.add("OUT_5POINT1");
            flipped |= OUT_5POINT1;
        }
        if ((o & OUT_5POINT1_BACK) == OUT_5POINT1_BACK) {
            list.add("OUT_5POINT1_BACK");
            flipped |= OUT_5POINT1_BACK;
        }
        if ((o & OUT_5POINT1_SIDE) == OUT_5POINT1_SIDE) {
            list.add("OUT_5POINT1_SIDE");
            flipped |= OUT_5POINT1_SIDE;
        }
        if ((o & OUT_6POINT1) == OUT_6POINT1) {
            list.add("OUT_6POINT1");
            flipped |= OUT_6POINT1;
        }
        if ((o & OUT_7POINT1) == OUT_7POINT1) {
            list.add("OUT_7POINT1");
            flipped |= OUT_7POINT1;
        }
        if ((o & OUT_ALL) == OUT_ALL) {
            list.add("OUT_ALL");
            flipped |= OUT_ALL;
        }
        if ((o & IN_LEFT) == IN_LEFT) {
            list.add("IN_LEFT");
            flipped |= IN_LEFT;
        }
        if ((o & IN_RIGHT) == IN_RIGHT) {
            list.add("IN_RIGHT");
            flipped |= IN_RIGHT;
        }
        if ((o & IN_FRONT) == IN_FRONT) {
            list.add("IN_FRONT");
            flipped |= IN_FRONT;
        }
        if ((o & IN_BACK) == IN_BACK) {
            list.add("IN_BACK");
            flipped |= IN_BACK;
        }
        if ((o & IN_LEFT_PROCESSED) == IN_LEFT_PROCESSED) {
            list.add("IN_LEFT_PROCESSED");
            flipped |= IN_LEFT_PROCESSED;
        }
        if ((o & IN_RIGHT_PROCESSED) == IN_RIGHT_PROCESSED) {
            list.add("IN_RIGHT_PROCESSED");
            flipped |= IN_RIGHT_PROCESSED;
        }
        if ((o & IN_FRONT_PROCESSED) == IN_FRONT_PROCESSED) {
            list.add("IN_FRONT_PROCESSED");
            flipped |= IN_FRONT_PROCESSED;
        }
        if ((o & IN_BACK_PROCESSED) == IN_BACK_PROCESSED) {
            list.add("IN_BACK_PROCESSED");
            flipped |= IN_BACK_PROCESSED;
        }
        if ((o & IN_PRESSURE) == IN_PRESSURE) {
            list.add("IN_PRESSURE");
            flipped |= IN_PRESSURE;
        }
        if ((o & IN_X_AXIS) == IN_X_AXIS) {
            list.add("IN_X_AXIS");
            flipped |= IN_X_AXIS;
        }
        if ((o & IN_Y_AXIS) == IN_Y_AXIS) {
            list.add("IN_Y_AXIS");
            flipped |= IN_Y_AXIS;
        }
        if ((o & IN_Z_AXIS) == IN_Z_AXIS) {
            list.add("IN_Z_AXIS");
            flipped |= IN_Z_AXIS;
        }
        if ((o & IN_VOICE_UPLINK) == IN_VOICE_UPLINK) {
            list.add("IN_VOICE_UPLINK");
            flipped |= IN_VOICE_UPLINK;
        }
        if ((o & IN_VOICE_DNLINK) == IN_VOICE_DNLINK) {
            list.add("IN_VOICE_DNLINK");
            flipped |= IN_VOICE_DNLINK;
        }
        if ((o & IN_MONO) == IN_MONO) {
            list.add("IN_MONO");
            flipped |= IN_MONO;
        }
        if ((o & IN_STEREO) == IN_STEREO) {
            list.add("IN_STEREO");
            flipped |= IN_STEREO;
        }
        if ((o & IN_FRONT_BACK) == IN_FRONT_BACK) {
            list.add("IN_FRONT_BACK");
            flipped |= IN_FRONT_BACK;
        }
        if ((o & IN_6) == IN_6) {
            list.add("IN_6");
            flipped |= IN_6;
        }
        if ((o & IN_VOICE_UPLINK_MONO) == IN_VOICE_UPLINK_MONO) {
            list.add("IN_VOICE_UPLINK_MONO");
            flipped |= IN_VOICE_UPLINK_MONO;
        }
        if ((o & IN_VOICE_DNLINK_MONO) == IN_VOICE_DNLINK_MONO) {
            list.add("IN_VOICE_DNLINK_MONO");
            flipped |= IN_VOICE_DNLINK_MONO;
        }
        if ((o & IN_VOICE_CALL_MONO) == IN_VOICE_CALL_MONO) {
            list.add("IN_VOICE_CALL_MONO");
            flipped |= IN_VOICE_CALL_MONO;
        }
        if ((o & IN_ALL) == IN_ALL) {
            list.add("IN_ALL");
            flipped |= IN_ALL;
        }
        if ((o & COUNT_MAX) == COUNT_MAX) {
            list.add("COUNT_MAX");
            flipped |= COUNT_MAX;
        }
        if ((o & INDEX_HDR) == INDEX_HDR) {
            list.add("INDEX_HDR");
            flipped |= INDEX_HDR;
        }
        if ((o & INDEX_MASK_1) == INDEX_MASK_1) {
            list.add("INDEX_MASK_1");
            flipped |= INDEX_MASK_1;
        }
        if ((o & INDEX_MASK_2) == INDEX_MASK_2) {
            list.add("INDEX_MASK_2");
            flipped |= INDEX_MASK_2;
        }
        if ((o & INDEX_MASK_3) == INDEX_MASK_3) {
            list.add("INDEX_MASK_3");
            flipped |= INDEX_MASK_3;
        }
        if ((o & INDEX_MASK_4) == INDEX_MASK_4) {
            list.add("INDEX_MASK_4");
            flipped |= INDEX_MASK_4;
        }
        if ((o & INDEX_MASK_5) == INDEX_MASK_5) {
            list.add("INDEX_MASK_5");
            flipped |= INDEX_MASK_5;
        }
        if ((o & INDEX_MASK_6) == INDEX_MASK_6) {
            list.add("INDEX_MASK_6");
            flipped |= INDEX_MASK_6;
        }
        if ((o & INDEX_MASK_7) == INDEX_MASK_7) {
            list.add("INDEX_MASK_7");
            flipped |= INDEX_MASK_7;
        }
        if ((o & INDEX_MASK_8) == INDEX_MASK_8) {
            list.add("INDEX_MASK_8");
            flipped |= INDEX_MASK_8;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

