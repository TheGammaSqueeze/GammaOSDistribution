package android.hardware.contexthub.V1_2;


public final class Setting {
    public static final byte LOCATION = 0;
    /**
     * Indicates that the WiFi capabilities can be used in CHRE. This setting
     * follows the overall availability of WiFi-related functionality within
     * the Android framework, for example if WiFi is disabled for connectivity
     * purposes but is enabled for location purposes (scanning), then
     * WIFI_AVAILABLE is enabled.
     */
    public static final byte WIFI_AVAILABLE = 1 /* ::android::hardware::contexthub::V1_1::Setting.LOCATION implicitly + 1 */;
    public static final byte AIRPLANE_MODE = 2 /* ::android::hardware::contexthub::V1_2::Setting.WIFI_AVAILABLE implicitly + 1 */;
    /**
     * Indicates if the microphone access is available for CHRE. Microphone
     * access is disabled if the user has turned off the microphone as a
     * privacy setting, in which case audio data cannot be used and propagated
     * by CHRE.
     */
    public static final byte MICROPHONE = 3 /* ::android::hardware::contexthub::V1_2::Setting.AIRPLANE_MODE implicitly + 1 */;
    public static final String toString(byte o) {
        if (o == LOCATION) {
            return "LOCATION";
        }
        if (o == WIFI_AVAILABLE) {
            return "WIFI_AVAILABLE";
        }
        if (o == AIRPLANE_MODE) {
            return "AIRPLANE_MODE";
        }
        if (o == MICROPHONE) {
            return "MICROPHONE";
        }
        return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
    }

    public static final String dumpBitfield(byte o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        byte flipped = 0;
        list.add("LOCATION"); // LOCATION == 0
        if ((o & WIFI_AVAILABLE) == WIFI_AVAILABLE) {
            list.add("WIFI_AVAILABLE");
            flipped |= WIFI_AVAILABLE;
        }
        if ((o & AIRPLANE_MODE) == AIRPLANE_MODE) {
            list.add("AIRPLANE_MODE");
            flipped |= AIRPLANE_MODE;
        }
        if ((o & MICROPHONE) == MICROPHONE) {
            list.add("MICROPHONE");
            flipped |= MICROPHONE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

