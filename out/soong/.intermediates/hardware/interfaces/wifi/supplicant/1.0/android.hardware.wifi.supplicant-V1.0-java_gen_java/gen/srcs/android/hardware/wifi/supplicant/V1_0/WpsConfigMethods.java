package android.hardware.wifi.supplicant.V1_0;


public final class WpsConfigMethods {
    public static final short USBA = 1 /* 0x0001 */;
    public static final short ETHERNET = 2 /* 0x0002 */;
    public static final short LABEL = 4 /* 0x0004 */;
    public static final short DISPLAY = 8 /* 0x0008 */;
    public static final short EXT_NFC_TOKEN = 16 /* 0x0010 */;
    public static final short INT_NFC_TOKEN = 32 /* 0x0020 */;
    public static final short NFC_INTERFACE = 64 /* 0x0040 */;
    public static final short PUSHBUTTON = 128 /* 0x0080 */;
    public static final short KEYPAD = 256 /* 0x0100 */;
    public static final short VIRT_PUSHBUTTON = 640 /* 0x0280 */;
    public static final short PHY_PUSHBUTTON = 1152 /* 0x0480 */;
    public static final short P2PS = 4096 /* 0x1000 */;
    public static final short VIRT_DISPLAY = 8200 /* 0x2008 */;
    public static final short PHY_DISPLAY = 16392 /* 0x4008 */;
    public static final String toString(short o) {
        if (o == USBA) {
            return "USBA";
        }
        if (o == ETHERNET) {
            return "ETHERNET";
        }
        if (o == LABEL) {
            return "LABEL";
        }
        if (o == DISPLAY) {
            return "DISPLAY";
        }
        if (o == EXT_NFC_TOKEN) {
            return "EXT_NFC_TOKEN";
        }
        if (o == INT_NFC_TOKEN) {
            return "INT_NFC_TOKEN";
        }
        if (o == NFC_INTERFACE) {
            return "NFC_INTERFACE";
        }
        if (o == PUSHBUTTON) {
            return "PUSHBUTTON";
        }
        if (o == KEYPAD) {
            return "KEYPAD";
        }
        if (o == VIRT_PUSHBUTTON) {
            return "VIRT_PUSHBUTTON";
        }
        if (o == PHY_PUSHBUTTON) {
            return "PHY_PUSHBUTTON";
        }
        if (o == P2PS) {
            return "P2PS";
        }
        if (o == VIRT_DISPLAY) {
            return "VIRT_DISPLAY";
        }
        if (o == PHY_DISPLAY) {
            return "PHY_DISPLAY";
        }
        return "0x" + Integer.toHexString(Short.toUnsignedInt((short)(o)));
    }

    public static final String dumpBitfield(short o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        short flipped = 0;
        if ((o & USBA) == USBA) {
            list.add("USBA");
            flipped |= USBA;
        }
        if ((o & ETHERNET) == ETHERNET) {
            list.add("ETHERNET");
            flipped |= ETHERNET;
        }
        if ((o & LABEL) == LABEL) {
            list.add("LABEL");
            flipped |= LABEL;
        }
        if ((o & DISPLAY) == DISPLAY) {
            list.add("DISPLAY");
            flipped |= DISPLAY;
        }
        if ((o & EXT_NFC_TOKEN) == EXT_NFC_TOKEN) {
            list.add("EXT_NFC_TOKEN");
            flipped |= EXT_NFC_TOKEN;
        }
        if ((o & INT_NFC_TOKEN) == INT_NFC_TOKEN) {
            list.add("INT_NFC_TOKEN");
            flipped |= INT_NFC_TOKEN;
        }
        if ((o & NFC_INTERFACE) == NFC_INTERFACE) {
            list.add("NFC_INTERFACE");
            flipped |= NFC_INTERFACE;
        }
        if ((o & PUSHBUTTON) == PUSHBUTTON) {
            list.add("PUSHBUTTON");
            flipped |= PUSHBUTTON;
        }
        if ((o & KEYPAD) == KEYPAD) {
            list.add("KEYPAD");
            flipped |= KEYPAD;
        }
        if ((o & VIRT_PUSHBUTTON) == VIRT_PUSHBUTTON) {
            list.add("VIRT_PUSHBUTTON");
            flipped |= VIRT_PUSHBUTTON;
        }
        if ((o & PHY_PUSHBUTTON) == PHY_PUSHBUTTON) {
            list.add("PHY_PUSHBUTTON");
            flipped |= PHY_PUSHBUTTON;
        }
        if ((o & P2PS) == P2PS) {
            list.add("P2PS");
            flipped |= P2PS;
        }
        if ((o & VIRT_DISPLAY) == VIRT_DISPLAY) {
            list.add("VIRT_DISPLAY");
            flipped |= VIRT_DISPLAY;
        }
        if ((o & PHY_DISPLAY) == PHY_DISPLAY) {
            list.add("PHY_DISPLAY");
            flipped |= PHY_DISPLAY;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Short.toUnsignedInt((short)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

