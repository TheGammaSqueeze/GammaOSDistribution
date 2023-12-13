package android.hardware.usb.gadget.V1_2;


public final class UsbSpeed {
    /**
     * UNKNOWN - Not Connected or Unsupported Speed
     */
    public static final int UNKNOWN = -1 /* -1 */;
    /**
     * USB Low Speed
     */
    public static final int LOWSPEED = 0;
    /**
     * USB Full Speed
     */
    public static final int FULLSPEED = 1;
    /**
     * USB High Speed
     */
    public static final int HIGHSPEED = 2;
    /**
     * USB Super Speed
     */
    public static final int SUPERSPEED = 3;
    /**
     * USB Super Speed 10Gbps
     */
    public static final int SUPERSPEED_10Gb = 4;
    /**
     * USB Super Speed 20Gbps
     */
    public static final int SUPERSPEED_20Gb = 5;
    /**
     * USB4 Gen2 x 1 (10Gbps)
     */
    public static final int USB4_GEN2_10Gb = 6;
    /**
     * USB4 Gen2 x 2 (20Gbps)
     */
    public static final int USB4_GEN2_20Gb = 7;
    /**
     * USB4 Gen3 x 1 (20Gbps)
     */
    public static final int USB4_GEN3_20Gb = 8;
    /**
     * USB4 Gen3 x 2 (40Gbps)
     */
    public static final int USB4_GEN3_40Gb = 9;
    /**
     * This is a suggestion if needed.
     *
     * Reserved Speed -- It is a newer speed after USB4 v1.0 announcement.
     * If this speed is detected, the HAL implementation should convert current
     * speed to above speeds which is lower and the closest.
     */
    public static final int RESERVED_SPEED = 64;
    public static final String toString(int o) {
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        if (o == LOWSPEED) {
            return "LOWSPEED";
        }
        if (o == FULLSPEED) {
            return "FULLSPEED";
        }
        if (o == HIGHSPEED) {
            return "HIGHSPEED";
        }
        if (o == SUPERSPEED) {
            return "SUPERSPEED";
        }
        if (o == SUPERSPEED_10Gb) {
            return "SUPERSPEED_10Gb";
        }
        if (o == SUPERSPEED_20Gb) {
            return "SUPERSPEED_20Gb";
        }
        if (o == USB4_GEN2_10Gb) {
            return "USB4_GEN2_10Gb";
        }
        if (o == USB4_GEN2_20Gb) {
            return "USB4_GEN2_20Gb";
        }
        if (o == USB4_GEN3_20Gb) {
            return "USB4_GEN3_20Gb";
        }
        if (o == USB4_GEN3_40Gb) {
            return "USB4_GEN3_40Gb";
        }
        if (o == RESERVED_SPEED) {
            return "RESERVED_SPEED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & UNKNOWN) == UNKNOWN) {
            list.add("UNKNOWN");
            flipped |= UNKNOWN;
        }
        list.add("LOWSPEED"); // LOWSPEED == 0
        if ((o & FULLSPEED) == FULLSPEED) {
            list.add("FULLSPEED");
            flipped |= FULLSPEED;
        }
        if ((o & HIGHSPEED) == HIGHSPEED) {
            list.add("HIGHSPEED");
            flipped |= HIGHSPEED;
        }
        if ((o & SUPERSPEED) == SUPERSPEED) {
            list.add("SUPERSPEED");
            flipped |= SUPERSPEED;
        }
        if ((o & SUPERSPEED_10Gb) == SUPERSPEED_10Gb) {
            list.add("SUPERSPEED_10Gb");
            flipped |= SUPERSPEED_10Gb;
        }
        if ((o & SUPERSPEED_20Gb) == SUPERSPEED_20Gb) {
            list.add("SUPERSPEED_20Gb");
            flipped |= SUPERSPEED_20Gb;
        }
        if ((o & USB4_GEN2_10Gb) == USB4_GEN2_10Gb) {
            list.add("USB4_GEN2_10Gb");
            flipped |= USB4_GEN2_10Gb;
        }
        if ((o & USB4_GEN2_20Gb) == USB4_GEN2_20Gb) {
            list.add("USB4_GEN2_20Gb");
            flipped |= USB4_GEN2_20Gb;
        }
        if ((o & USB4_GEN3_20Gb) == USB4_GEN3_20Gb) {
            list.add("USB4_GEN3_20Gb");
            flipped |= USB4_GEN3_20Gb;
        }
        if ((o & USB4_GEN3_40Gb) == USB4_GEN3_40Gb) {
            list.add("USB4_GEN3_40Gb");
            flipped |= USB4_GEN3_40Gb;
        }
        if ((o & RESERVED_SPEED) == RESERVED_SPEED) {
            list.add("RESERVED_SPEED");
            flipped |= RESERVED_SPEED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

