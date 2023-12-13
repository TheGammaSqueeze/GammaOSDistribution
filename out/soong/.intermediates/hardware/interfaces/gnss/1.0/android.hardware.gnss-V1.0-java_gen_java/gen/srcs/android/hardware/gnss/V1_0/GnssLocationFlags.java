package android.hardware.gnss.V1_0;


public final class GnssLocationFlags {
    /**
     * GnssLocation has valid latitude and longitude.
     */
    public static final short HAS_LAT_LONG = 1 /* 0x0001 */;
    /**
     * GnssLocation has valid altitude.
     */
    public static final short HAS_ALTITUDE = 2 /* 0x0002 */;
    /**
     * GnssLocation has valid speed.
     */
    public static final short HAS_SPEED = 4 /* 0x0004 */;
    /**
     * GnssLocation has valid bearing.
     */
    public static final short HAS_BEARING = 8 /* 0x0008 */;
    /**
     * GpsLocation has valid horizontal accuracy.
     */
    public static final short HAS_HORIZONTAL_ACCURACY = 16 /* 0x0010 */;
    /**
     * GpsLocation has valid vertical accuracy.
     */
    public static final short HAS_VERTICAL_ACCURACY = 32 /* 0x0020 */;
    /**
     * GpsLocation has valid speed accuracy.
     */
    public static final short HAS_SPEED_ACCURACY = 64 /* 0x0040 */;
    /**
     * GpsLocation has valid bearing accuracy.
     */
    public static final short HAS_BEARING_ACCURACY = 128 /* 0x0080 */;
    public static final String toString(short o) {
        if (o == HAS_LAT_LONG) {
            return "HAS_LAT_LONG";
        }
        if (o == HAS_ALTITUDE) {
            return "HAS_ALTITUDE";
        }
        if (o == HAS_SPEED) {
            return "HAS_SPEED";
        }
        if (o == HAS_BEARING) {
            return "HAS_BEARING";
        }
        if (o == HAS_HORIZONTAL_ACCURACY) {
            return "HAS_HORIZONTAL_ACCURACY";
        }
        if (o == HAS_VERTICAL_ACCURACY) {
            return "HAS_VERTICAL_ACCURACY";
        }
        if (o == HAS_SPEED_ACCURACY) {
            return "HAS_SPEED_ACCURACY";
        }
        if (o == HAS_BEARING_ACCURACY) {
            return "HAS_BEARING_ACCURACY";
        }
        return "0x" + Integer.toHexString(Short.toUnsignedInt((short)(o)));
    }

    public static final String dumpBitfield(short o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        short flipped = 0;
        if ((o & HAS_LAT_LONG) == HAS_LAT_LONG) {
            list.add("HAS_LAT_LONG");
            flipped |= HAS_LAT_LONG;
        }
        if ((o & HAS_ALTITUDE) == HAS_ALTITUDE) {
            list.add("HAS_ALTITUDE");
            flipped |= HAS_ALTITUDE;
        }
        if ((o & HAS_SPEED) == HAS_SPEED) {
            list.add("HAS_SPEED");
            flipped |= HAS_SPEED;
        }
        if ((o & HAS_BEARING) == HAS_BEARING) {
            list.add("HAS_BEARING");
            flipped |= HAS_BEARING;
        }
        if ((o & HAS_HORIZONTAL_ACCURACY) == HAS_HORIZONTAL_ACCURACY) {
            list.add("HAS_HORIZONTAL_ACCURACY");
            flipped |= HAS_HORIZONTAL_ACCURACY;
        }
        if ((o & HAS_VERTICAL_ACCURACY) == HAS_VERTICAL_ACCURACY) {
            list.add("HAS_VERTICAL_ACCURACY");
            flipped |= HAS_VERTICAL_ACCURACY;
        }
        if ((o & HAS_SPEED_ACCURACY) == HAS_SPEED_ACCURACY) {
            list.add("HAS_SPEED_ACCURACY");
            flipped |= HAS_SPEED_ACCURACY;
        }
        if ((o & HAS_BEARING_ACCURACY) == HAS_BEARING_ACCURACY) {
            list.add("HAS_BEARING_ACCURACY");
            flipped |= HAS_BEARING_ACCURACY;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Short.toUnsignedInt((short)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

