package android.hardware.broadcastradio.V2_0;


public final class MetadataKey {
    /**
     * RDS PS (string)
     */
    public static final int RDS_PS = 1;
    /**
     * RDS PTY (uint8_t)
     */
    public static final int RDS_PTY = 2 /* ::android::hardware::broadcastradio::V2_0::MetadataKey.RDS_PS implicitly + 1 */;
    /**
     * RBDS PTY (uint8_t)
     */
    public static final int RBDS_PTY = 3 /* ::android::hardware::broadcastradio::V2_0::MetadataKey.RDS_PTY implicitly + 1 */;
    /**
     * RDS RT (string)
     */
    public static final int RDS_RT = 4 /* ::android::hardware::broadcastradio::V2_0::MetadataKey.RBDS_PTY implicitly + 1 */;
    /**
     * Song title (string)
     */
    public static final int SONG_TITLE = 5 /* ::android::hardware::broadcastradio::V2_0::MetadataKey.RDS_RT implicitly + 1 */;
    /**
     * Artist name (string)
     */
    public static final int SONG_ARTIST = 6 /* ::android::hardware::broadcastradio::V2_0::MetadataKey.SONG_TITLE implicitly + 1 */;
    /**
     * Album name (string)
     */
    public static final int SONG_ALBUM = 7 /* ::android::hardware::broadcastradio::V2_0::MetadataKey.SONG_ARTIST implicitly + 1 */;
    /**
     * Station icon (uint32_t, see IBroadcastRadio::getImage)
     */
    public static final int STATION_ICON = 8 /* ::android::hardware::broadcastradio::V2_0::MetadataKey.SONG_ALBUM implicitly + 1 */;
    /**
     * Album art (uint32_t, see IBroadcastRadio::getImage)
     */
    public static final int ALBUM_ART = 9 /* ::android::hardware::broadcastradio::V2_0::MetadataKey.STATION_ICON implicitly + 1 */;
    /**
     * Station name.
     *
     * This is a generic field to cover any radio technology.
     *
     * If the PROGRAM_NAME has the same content as DAB_*_NAME or RDS_PS,
     * it may not be present, to preserve space - framework must repopulate
     * it on the client side.
     */
    public static final int PROGRAM_NAME = 10 /* ::android::hardware::broadcastradio::V2_0::MetadataKey.ALBUM_ART implicitly + 1 */;
    /**
     * DAB ensemble name (string)
     */
    public static final int DAB_ENSEMBLE_NAME = 11 /* ::android::hardware::broadcastradio::V2_0::MetadataKey.PROGRAM_NAME implicitly + 1 */;
    /**
     * DAB ensemble name abbreviated (string).
     *
     * The string must be up to 8 characters long.
     *
     * If the short variant is present, the long (DAB_ENSEMBLE_NAME) one must be
     * present as well.
     */
    public static final int DAB_ENSEMBLE_NAME_SHORT = 12 /* ::android::hardware::broadcastradio::V2_0::MetadataKey.DAB_ENSEMBLE_NAME implicitly + 1 */;
    /**
     * DAB service name (string)
     */
    public static final int DAB_SERVICE_NAME = 13 /* ::android::hardware::broadcastradio::V2_0::MetadataKey.DAB_ENSEMBLE_NAME_SHORT implicitly + 1 */;
    /**
     * DAB service name abbreviated (see DAB_ENSEMBLE_NAME_SHORT) (string)
     */
    public static final int DAB_SERVICE_NAME_SHORT = 14 /* ::android::hardware::broadcastradio::V2_0::MetadataKey.DAB_SERVICE_NAME implicitly + 1 */;
    /**
     * DAB component name (string)
     */
    public static final int DAB_COMPONENT_NAME = 15 /* ::android::hardware::broadcastradio::V2_0::MetadataKey.DAB_SERVICE_NAME_SHORT implicitly + 1 */;
    /**
     * DAB component name abbreviated (see DAB_ENSEMBLE_NAME_SHORT) (string)
     */
    public static final int DAB_COMPONENT_NAME_SHORT = 16 /* ::android::hardware::broadcastradio::V2_0::MetadataKey.DAB_COMPONENT_NAME implicitly + 1 */;
    public static final String toString(int o) {
        if (o == RDS_PS) {
            return "RDS_PS";
        }
        if (o == RDS_PTY) {
            return "RDS_PTY";
        }
        if (o == RBDS_PTY) {
            return "RBDS_PTY";
        }
        if (o == RDS_RT) {
            return "RDS_RT";
        }
        if (o == SONG_TITLE) {
            return "SONG_TITLE";
        }
        if (o == SONG_ARTIST) {
            return "SONG_ARTIST";
        }
        if (o == SONG_ALBUM) {
            return "SONG_ALBUM";
        }
        if (o == STATION_ICON) {
            return "STATION_ICON";
        }
        if (o == ALBUM_ART) {
            return "ALBUM_ART";
        }
        if (o == PROGRAM_NAME) {
            return "PROGRAM_NAME";
        }
        if (o == DAB_ENSEMBLE_NAME) {
            return "DAB_ENSEMBLE_NAME";
        }
        if (o == DAB_ENSEMBLE_NAME_SHORT) {
            return "DAB_ENSEMBLE_NAME_SHORT";
        }
        if (o == DAB_SERVICE_NAME) {
            return "DAB_SERVICE_NAME";
        }
        if (o == DAB_SERVICE_NAME_SHORT) {
            return "DAB_SERVICE_NAME_SHORT";
        }
        if (o == DAB_COMPONENT_NAME) {
            return "DAB_COMPONENT_NAME";
        }
        if (o == DAB_COMPONENT_NAME_SHORT) {
            return "DAB_COMPONENT_NAME_SHORT";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & RDS_PS) == RDS_PS) {
            list.add("RDS_PS");
            flipped |= RDS_PS;
        }
        if ((o & RDS_PTY) == RDS_PTY) {
            list.add("RDS_PTY");
            flipped |= RDS_PTY;
        }
        if ((o & RBDS_PTY) == RBDS_PTY) {
            list.add("RBDS_PTY");
            flipped |= RBDS_PTY;
        }
        if ((o & RDS_RT) == RDS_RT) {
            list.add("RDS_RT");
            flipped |= RDS_RT;
        }
        if ((o & SONG_TITLE) == SONG_TITLE) {
            list.add("SONG_TITLE");
            flipped |= SONG_TITLE;
        }
        if ((o & SONG_ARTIST) == SONG_ARTIST) {
            list.add("SONG_ARTIST");
            flipped |= SONG_ARTIST;
        }
        if ((o & SONG_ALBUM) == SONG_ALBUM) {
            list.add("SONG_ALBUM");
            flipped |= SONG_ALBUM;
        }
        if ((o & STATION_ICON) == STATION_ICON) {
            list.add("STATION_ICON");
            flipped |= STATION_ICON;
        }
        if ((o & ALBUM_ART) == ALBUM_ART) {
            list.add("ALBUM_ART");
            flipped |= ALBUM_ART;
        }
        if ((o & PROGRAM_NAME) == PROGRAM_NAME) {
            list.add("PROGRAM_NAME");
            flipped |= PROGRAM_NAME;
        }
        if ((o & DAB_ENSEMBLE_NAME) == DAB_ENSEMBLE_NAME) {
            list.add("DAB_ENSEMBLE_NAME");
            flipped |= DAB_ENSEMBLE_NAME;
        }
        if ((o & DAB_ENSEMBLE_NAME_SHORT) == DAB_ENSEMBLE_NAME_SHORT) {
            list.add("DAB_ENSEMBLE_NAME_SHORT");
            flipped |= DAB_ENSEMBLE_NAME_SHORT;
        }
        if ((o & DAB_SERVICE_NAME) == DAB_SERVICE_NAME) {
            list.add("DAB_SERVICE_NAME");
            flipped |= DAB_SERVICE_NAME;
        }
        if ((o & DAB_SERVICE_NAME_SHORT) == DAB_SERVICE_NAME_SHORT) {
            list.add("DAB_SERVICE_NAME_SHORT");
            flipped |= DAB_SERVICE_NAME_SHORT;
        }
        if ((o & DAB_COMPONENT_NAME) == DAB_COMPONENT_NAME) {
            list.add("DAB_COMPONENT_NAME");
            flipped |= DAB_COMPONENT_NAME;
        }
        if ((o & DAB_COMPONENT_NAME_SHORT) == DAB_COMPONENT_NAME_SHORT) {
            list.add("DAB_COMPONENT_NAME_SHORT");
            flipped |= DAB_COMPONENT_NAME_SHORT;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

