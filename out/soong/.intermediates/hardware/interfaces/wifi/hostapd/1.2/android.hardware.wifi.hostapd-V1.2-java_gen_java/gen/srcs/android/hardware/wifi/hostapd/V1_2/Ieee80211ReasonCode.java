package android.hardware.wifi.hostapd.V1_2;


public final class Ieee80211ReasonCode {
    public static final short WLAN_REASON_UNSPECIFIED = 1;
    public static final short WLAN_REASON_PREV_AUTH_NOT_VALID = 2;
    public static final short WLAN_REASON_DISASSOC_AP_BUSY = 5;
    public static final String toString(short o) {
        if (o == WLAN_REASON_UNSPECIFIED) {
            return "WLAN_REASON_UNSPECIFIED";
        }
        if (o == WLAN_REASON_PREV_AUTH_NOT_VALID) {
            return "WLAN_REASON_PREV_AUTH_NOT_VALID";
        }
        if (o == WLAN_REASON_DISASSOC_AP_BUSY) {
            return "WLAN_REASON_DISASSOC_AP_BUSY";
        }
        return "0x" + Integer.toHexString(Short.toUnsignedInt((short)(o)));
    }

    public static final String dumpBitfield(short o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        short flipped = 0;
        if ((o & WLAN_REASON_UNSPECIFIED) == WLAN_REASON_UNSPECIFIED) {
            list.add("WLAN_REASON_UNSPECIFIED");
            flipped |= WLAN_REASON_UNSPECIFIED;
        }
        if ((o & WLAN_REASON_PREV_AUTH_NOT_VALID) == WLAN_REASON_PREV_AUTH_NOT_VALID) {
            list.add("WLAN_REASON_PREV_AUTH_NOT_VALID");
            flipped |= WLAN_REASON_PREV_AUTH_NOT_VALID;
        }
        if ((o & WLAN_REASON_DISASSOC_AP_BUSY) == WLAN_REASON_DISASSOC_AP_BUSY) {
            list.add("WLAN_REASON_DISASSOC_AP_BUSY");
            flipped |= WLAN_REASON_DISASSOC_AP_BUSY;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Short.toUnsignedInt((short)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

