package android.hardware.broadcastradio.V2_0;


public final class IdentifierType {
    /**
     * Primary/secondary identifier for vendor-specific radio technology.
     * The value format is determined by a vendor.
     *
     * The vendor identifiers have limited serialization capabilities - see
     * ProgramSelector description.
     */
    public static final int VENDOR_START = 1000;
    /**
     * See VENDOR_START
     */
    public static final int VENDOR_END = 1999;
    public static final int INVALID = 0;
    /**
     * Primary identifier for analogue (without RDS) AM/FM stations:
     * frequency in kHz.
     *
     * This identifier also contains band information:
     *  - <500kHz: AM LW;
     *  - 500kHz - 1705kHz: AM MW;
     *  - 1.71MHz - 30MHz: AM SW;
     *  - >60MHz: FM.
     */
    public static final int AMFM_FREQUENCY = 1 /* ::android::hardware::broadcastradio::V2_0::IdentifierType.INVALID implicitly + 1 */;
    /**
     * 16bit primary identifier for FM RDS station.
     */
    public static final int RDS_PI = 2 /* ::android::hardware::broadcastradio::V2_0::IdentifierType.AMFM_FREQUENCY implicitly + 1 */;
    /**
     * 64bit compound primary identifier for HD Radio.
     *
     * Consists of (from the LSB):
     * - 32bit: Station ID number;
     * - 4bit: HD Radio subchannel;
     * - 18bit: AMFM_FREQUENCY.
     *
     * While station ID number should be unique globally, it sometimes get
     * abused by broadcasters (i.e. not being set at all). To ensure local
     * uniqueness, AMFM_FREQUENCY was added here. Global uniqueness is
     * a best-effort - see HD_STATION_NAME.
     *
     * HD Radio subchannel is a value in range 0-7.
     * This index is 0-based (where 0 is MPS and 1..7 are SPS),
     * as opposed to HD Radio standard (where it's 1-based).
     *
     * The remaining bits should be set to zeros when writing on the chip side
     * and ignored when read.
     */
    public static final int HD_STATION_ID_EXT = 3 /* ::android::hardware::broadcastradio::V2_0::IdentifierType.RDS_PI implicitly + 1 */;
    /**
     * 64bit additional identifier for HD Radio.
     *
     * Due to Station ID abuse, some HD_STATION_ID_EXT identifiers may be not
     * globally unique. To provide a best-effort solution, a short version of
     * station name may be carried as additional identifier and may be used
     * by the tuner hardware to double-check tuning.
     *
     * The name is limited to the first 8 A-Z0-9 characters (lowercase letters
     * must be converted to uppercase). Encoded in little-endian ASCII:
     * the first character of the name is the LSB.
     *
     * For example: "Abc" is encoded as 0x434241.
     */
    public static final int HD_STATION_NAME = 4 /* ::android::hardware::broadcastradio::V2_0::IdentifierType.HD_STATION_ID_EXT implicitly + 1 */;
    /**
     * 28bit compound primary identifier for Digital Audio Broadcasting.
     *
     * Consists of (from the LSB):
     * - 16bit: SId;
     * - 8bit: ECC code;
     * - 4bit: SCIdS.
     *
     * SCIdS (Service Component Identifier within the Service) value
     * of 0 represents the main service, while 1 and above represents
     * secondary services.
     *
     * The remaining bits should be set to zeros when writing on the chip side
     * and ignored when read.
     */
    public static final int DAB_SID_EXT = 5 /* ::android::hardware::broadcastradio::V2_0::IdentifierType.HD_STATION_NAME implicitly + 1 */;
    /**
     * 16bit
     */
    public static final int DAB_ENSEMBLE = 6 /* ::android::hardware::broadcastradio::V2_0::IdentifierType.DAB_SID_EXT implicitly + 1 */;
    /**
     * 12bit
     */
    public static final int DAB_SCID = 7 /* ::android::hardware::broadcastradio::V2_0::IdentifierType.DAB_ENSEMBLE implicitly + 1 */;
    /**
     * kHz (see AMFM_FREQUENCY)
     */
    public static final int DAB_FREQUENCY = 8 /* ::android::hardware::broadcastradio::V2_0::IdentifierType.DAB_SCID implicitly + 1 */;
    /**
     * 24bit primary identifier for Digital Radio Mondiale.
     */
    public static final int DRMO_SERVICE_ID = 9 /* ::android::hardware::broadcastradio::V2_0::IdentifierType.DAB_FREQUENCY implicitly + 1 */;
    /**
     * kHz (see AMFM_FREQUENCY)
     */
    public static final int DRMO_FREQUENCY = 10 /* ::android::hardware::broadcastradio::V2_0::IdentifierType.DRMO_SERVICE_ID implicitly + 1 */;
    /**
     * 32bit primary identifier for SiriusXM Satellite Radio.
     */
    public static final int SXM_SERVICE_ID = 12 /* DRMO_FREQUENCY + 2 */;
    /**
     * 0-999 range
     */
    public static final int SXM_CHANNEL = 13 /* ::android::hardware::broadcastradio::V2_0::IdentifierType.SXM_SERVICE_ID implicitly + 1 */;
    public static final String toString(int o) {
        if (o == VENDOR_START) {
            return "VENDOR_START";
        }
        if (o == VENDOR_END) {
            return "VENDOR_END";
        }
        if (o == INVALID) {
            return "INVALID";
        }
        if (o == AMFM_FREQUENCY) {
            return "AMFM_FREQUENCY";
        }
        if (o == RDS_PI) {
            return "RDS_PI";
        }
        if (o == HD_STATION_ID_EXT) {
            return "HD_STATION_ID_EXT";
        }
        if (o == HD_STATION_NAME) {
            return "HD_STATION_NAME";
        }
        if (o == DAB_SID_EXT) {
            return "DAB_SID_EXT";
        }
        if (o == DAB_ENSEMBLE) {
            return "DAB_ENSEMBLE";
        }
        if (o == DAB_SCID) {
            return "DAB_SCID";
        }
        if (o == DAB_FREQUENCY) {
            return "DAB_FREQUENCY";
        }
        if (o == DRMO_SERVICE_ID) {
            return "DRMO_SERVICE_ID";
        }
        if (o == DRMO_FREQUENCY) {
            return "DRMO_FREQUENCY";
        }
        if (o == SXM_SERVICE_ID) {
            return "SXM_SERVICE_ID";
        }
        if (o == SXM_CHANNEL) {
            return "SXM_CHANNEL";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & VENDOR_START) == VENDOR_START) {
            list.add("VENDOR_START");
            flipped |= VENDOR_START;
        }
        if ((o & VENDOR_END) == VENDOR_END) {
            list.add("VENDOR_END");
            flipped |= VENDOR_END;
        }
        list.add("INVALID"); // INVALID == 0
        if ((o & AMFM_FREQUENCY) == AMFM_FREQUENCY) {
            list.add("AMFM_FREQUENCY");
            flipped |= AMFM_FREQUENCY;
        }
        if ((o & RDS_PI) == RDS_PI) {
            list.add("RDS_PI");
            flipped |= RDS_PI;
        }
        if ((o & HD_STATION_ID_EXT) == HD_STATION_ID_EXT) {
            list.add("HD_STATION_ID_EXT");
            flipped |= HD_STATION_ID_EXT;
        }
        if ((o & HD_STATION_NAME) == HD_STATION_NAME) {
            list.add("HD_STATION_NAME");
            flipped |= HD_STATION_NAME;
        }
        if ((o & DAB_SID_EXT) == DAB_SID_EXT) {
            list.add("DAB_SID_EXT");
            flipped |= DAB_SID_EXT;
        }
        if ((o & DAB_ENSEMBLE) == DAB_ENSEMBLE) {
            list.add("DAB_ENSEMBLE");
            flipped |= DAB_ENSEMBLE;
        }
        if ((o & DAB_SCID) == DAB_SCID) {
            list.add("DAB_SCID");
            flipped |= DAB_SCID;
        }
        if ((o & DAB_FREQUENCY) == DAB_FREQUENCY) {
            list.add("DAB_FREQUENCY");
            flipped |= DAB_FREQUENCY;
        }
        if ((o & DRMO_SERVICE_ID) == DRMO_SERVICE_ID) {
            list.add("DRMO_SERVICE_ID");
            flipped |= DRMO_SERVICE_ID;
        }
        if ((o & DRMO_FREQUENCY) == DRMO_FREQUENCY) {
            list.add("DRMO_FREQUENCY");
            flipped |= DRMO_FREQUENCY;
        }
        if ((o & SXM_SERVICE_ID) == SXM_SERVICE_ID) {
            list.add("SXM_SERVICE_ID");
            flipped |= SXM_SERVICE_ID;
        }
        if ((o & SXM_CHANNEL) == SXM_CHANNEL) {
            list.add("SXM_CHANNEL");
            flipped |= SXM_CHANNEL;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

