package android.hardware.broadcastradio.V2_0;


public final class AnnouncementType {
    /**
     * DAB alarm, RDS emergency program type (PTY 31).
     */
    public static final byte EMERGENCY = 1;
    /**
     * DAB warning.
     */
    public static final byte WARNING = 2 /* ::android::hardware::broadcastradio::V2_0::AnnouncementType.EMERGENCY implicitly + 1 */;
    /**
     * DAB road traffic, RDS TA, HD Radio transportation.
     */
    public static final byte TRAFFIC = 3 /* ::android::hardware::broadcastradio::V2_0::AnnouncementType.WARNING implicitly + 1 */;
    /**
     * Weather.
     */
    public static final byte WEATHER = 4 /* ::android::hardware::broadcastradio::V2_0::AnnouncementType.TRAFFIC implicitly + 1 */;
    /**
     * News.
     */
    public static final byte NEWS = 5 /* ::android::hardware::broadcastradio::V2_0::AnnouncementType.WEATHER implicitly + 1 */;
    /**
     * DAB event, special event.
     */
    public static final byte EVENT = 6 /* ::android::hardware::broadcastradio::V2_0::AnnouncementType.NEWS implicitly + 1 */;
    /**
     * DAB sport report, RDS sports.
     */
    public static final byte SPORT = 7 /* ::android::hardware::broadcastradio::V2_0::AnnouncementType.EVENT implicitly + 1 */;
    /**
     * All others.
     */
    public static final byte MISC = 8 /* ::android::hardware::broadcastradio::V2_0::AnnouncementType.SPORT implicitly + 1 */;
    public static final String toString(byte o) {
        if (o == EMERGENCY) {
            return "EMERGENCY";
        }
        if (o == WARNING) {
            return "WARNING";
        }
        if (o == TRAFFIC) {
            return "TRAFFIC";
        }
        if (o == WEATHER) {
            return "WEATHER";
        }
        if (o == NEWS) {
            return "NEWS";
        }
        if (o == EVENT) {
            return "EVENT";
        }
        if (o == SPORT) {
            return "SPORT";
        }
        if (o == MISC) {
            return "MISC";
        }
        return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
    }

    public static final String dumpBitfield(byte o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        byte flipped = 0;
        if ((o & EMERGENCY) == EMERGENCY) {
            list.add("EMERGENCY");
            flipped |= EMERGENCY;
        }
        if ((o & WARNING) == WARNING) {
            list.add("WARNING");
            flipped |= WARNING;
        }
        if ((o & TRAFFIC) == TRAFFIC) {
            list.add("TRAFFIC");
            flipped |= TRAFFIC;
        }
        if ((o & WEATHER) == WEATHER) {
            list.add("WEATHER");
            flipped |= WEATHER;
        }
        if ((o & NEWS) == NEWS) {
            list.add("NEWS");
            flipped |= NEWS;
        }
        if ((o & EVENT) == EVENT) {
            list.add("EVENT");
            flipped |= EVENT;
        }
        if ((o & SPORT) == SPORT) {
            list.add("SPORT");
            flipped |= SPORT;
        }
        if ((o & MISC) == MISC) {
            list.add("MISC");
            flipped |= MISC;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

