package android.hardware.light.V2_0;


public final class Type {
    public static final int BACKLIGHT = 0;
    public static final int KEYBOARD = 1 /* ::android::hardware::light::V2_0::Type.BACKLIGHT implicitly + 1 */;
    public static final int BUTTONS = 2 /* ::android::hardware::light::V2_0::Type.KEYBOARD implicitly + 1 */;
    public static final int BATTERY = 3 /* ::android::hardware::light::V2_0::Type.BUTTONS implicitly + 1 */;
    public static final int NOTIFICATIONS = 4 /* ::android::hardware::light::V2_0::Type.BATTERY implicitly + 1 */;
    public static final int ATTENTION = 5 /* ::android::hardware::light::V2_0::Type.NOTIFICATIONS implicitly + 1 */;
    public static final int BLUETOOTH = 6 /* ::android::hardware::light::V2_0::Type.ATTENTION implicitly + 1 */;
    public static final int WIFI = 7 /* ::android::hardware::light::V2_0::Type.BLUETOOTH implicitly + 1 */;
    public static final int COUNT = 8 /* ::android::hardware::light::V2_0::Type.WIFI implicitly + 1 */;
    public static final String toString(int o) {
        if (o == BACKLIGHT) {
            return "BACKLIGHT";
        }
        if (o == KEYBOARD) {
            return "KEYBOARD";
        }
        if (o == BUTTONS) {
            return "BUTTONS";
        }
        if (o == BATTERY) {
            return "BATTERY";
        }
        if (o == NOTIFICATIONS) {
            return "NOTIFICATIONS";
        }
        if (o == ATTENTION) {
            return "ATTENTION";
        }
        if (o == BLUETOOTH) {
            return "BLUETOOTH";
        }
        if (o == WIFI) {
            return "WIFI";
        }
        if (o == COUNT) {
            return "COUNT";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("BACKLIGHT"); // BACKLIGHT == 0
        if ((o & KEYBOARD) == KEYBOARD) {
            list.add("KEYBOARD");
            flipped |= KEYBOARD;
        }
        if ((o & BUTTONS) == BUTTONS) {
            list.add("BUTTONS");
            flipped |= BUTTONS;
        }
        if ((o & BATTERY) == BATTERY) {
            list.add("BATTERY");
            flipped |= BATTERY;
        }
        if ((o & NOTIFICATIONS) == NOTIFICATIONS) {
            list.add("NOTIFICATIONS");
            flipped |= NOTIFICATIONS;
        }
        if ((o & ATTENTION) == ATTENTION) {
            list.add("ATTENTION");
            flipped |= ATTENTION;
        }
        if ((o & BLUETOOTH) == BLUETOOTH) {
            list.add("BLUETOOTH");
            flipped |= BLUETOOTH;
        }
        if ((o & WIFI) == WIFI) {
            list.add("WIFI");
            flipped |= WIFI;
        }
        if ((o & COUNT) == COUNT) {
            list.add("COUNT");
            flipped |= COUNT;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

