package android.hardware.audio.common.V2_0;


public final class AudioDevice {
    public static final int NONE = 0 /* 0x0 */;
    /**
     * reserved bits
     */
    public static final int BIT_IN = -2147483648 /* 0x80000000 */;
    public static final int BIT_DEFAULT = 1073741824 /* 0x40000000 */;
    /**
     * output devices
     */
    public static final int OUT_EARPIECE = 1 /* 0x1 */;
    public static final int OUT_SPEAKER = 2 /* 0x2 */;
    public static final int OUT_WIRED_HEADSET = 4 /* 0x4 */;
    public static final int OUT_WIRED_HEADPHONE = 8 /* 0x8 */;
    public static final int OUT_BLUETOOTH_SCO = 16 /* 0x10 */;
    public static final int OUT_BLUETOOTH_SCO_HEADSET = 32 /* 0x20 */;
    public static final int OUT_BLUETOOTH_SCO_CARKIT = 64 /* 0x40 */;
    public static final int OUT_BLUETOOTH_A2DP = 128 /* 0x80 */;
    public static final int OUT_BLUETOOTH_A2DP_HEADPHONES = 256 /* 0x100 */;
    public static final int OUT_BLUETOOTH_A2DP_SPEAKER = 512 /* 0x200 */;
    public static final int OUT_AUX_DIGITAL = 1024 /* 0x400 */;
    public static final int OUT_HDMI = 1024 /* OUT_AUX_DIGITAL */;
    /**
     * uses an analog connection (multiplexed over the USB pins for instance)
     */
    public static final int OUT_ANLG_DOCK_HEADSET = 2048 /* 0x800 */;
    public static final int OUT_DGTL_DOCK_HEADSET = 4096 /* 0x1000 */;
    /**
     * USB accessory mode: Android device is USB device and dock is USB host
     */
    public static final int OUT_USB_ACCESSORY = 8192 /* 0x2000 */;
    /**
     * USB host mode: Android device is USB host and dock is USB device
     */
    public static final int OUT_USB_DEVICE = 16384 /* 0x4000 */;
    public static final int OUT_REMOTE_SUBMIX = 32768 /* 0x8000 */;
    /**
     * Telephony voice TX path
     */
    public static final int OUT_TELEPHONY_TX = 65536 /* 0x10000 */;
    /**
     * Analog jack with line impedance detected
     */
    public static final int OUT_LINE = 131072 /* 0x20000 */;
    /**
     * HDMI Audio Return Channel
     */
    public static final int OUT_HDMI_ARC = 262144 /* 0x40000 */;
    /**
     * S/PDIF out
     */
    public static final int OUT_SPDIF = 524288 /* 0x80000 */;
    /**
     * FM transmitter out
     */
    public static final int OUT_FM = 1048576 /* 0x100000 */;
    /**
     * Line out for av devices
     */
    public static final int OUT_AUX_LINE = 2097152 /* 0x200000 */;
    /**
     * limited-output speaker device for acoustic safety
     */
    public static final int OUT_SPEAKER_SAFE = 4194304 /* 0x400000 */;
    public static final int OUT_IP = 8388608 /* 0x800000 */;
    /**
     * audio bus implemented by the audio system (e.g an MOST stereo channel)
     */
    public static final int OUT_BUS = 16777216 /* 0x1000000 */;
    public static final int OUT_PROXY = 33554432 /* 0x2000000 */;
    public static final int OUT_USB_HEADSET = 67108864 /* 0x4000000 */;
    public static final int OUT_DEFAULT = 1073741824 /* BIT_DEFAULT */;
    public static final int OUT_ALL = 1207959551 /* (OUT_EARPIECE | OUT_SPEAKER | OUT_WIRED_HEADSET | OUT_WIRED_HEADPHONE | OUT_BLUETOOTH_SCO | OUT_BLUETOOTH_SCO_HEADSET | OUT_BLUETOOTH_SCO_CARKIT | OUT_BLUETOOTH_A2DP | OUT_BLUETOOTH_A2DP_HEADPHONES | OUT_BLUETOOTH_A2DP_SPEAKER | OUT_HDMI | OUT_ANLG_DOCK_HEADSET | OUT_DGTL_DOCK_HEADSET | OUT_USB_ACCESSORY | OUT_USB_DEVICE | OUT_REMOTE_SUBMIX | OUT_TELEPHONY_TX | OUT_LINE | OUT_HDMI_ARC | OUT_SPDIF | OUT_FM | OUT_AUX_LINE | OUT_SPEAKER_SAFE | OUT_IP | OUT_BUS | OUT_PROXY | OUT_USB_HEADSET | OUT_DEFAULT) */;
    public static final int OUT_ALL_A2DP = 896 /* (OUT_BLUETOOTH_A2DP | OUT_BLUETOOTH_A2DP_HEADPHONES | OUT_BLUETOOTH_A2DP_SPEAKER) */;
    public static final int OUT_ALL_SCO = 112 /* (OUT_BLUETOOTH_SCO | OUT_BLUETOOTH_SCO_HEADSET | OUT_BLUETOOTH_SCO_CARKIT) */;
    public static final int OUT_ALL_USB = 67133440 /* (OUT_USB_ACCESSORY | OUT_USB_DEVICE | OUT_USB_HEADSET) */;
    /**
     * input devices
     */
    public static final int IN_COMMUNICATION = -2147483647 /* BIT_IN | 0x1 */;
    public static final int IN_AMBIENT = -2147483646 /* BIT_IN | 0x2 */;
    public static final int IN_BUILTIN_MIC = -2147483644 /* BIT_IN | 0x4 */;
    public static final int IN_BLUETOOTH_SCO_HEADSET = -2147483640 /* BIT_IN | 0x8 */;
    public static final int IN_WIRED_HEADSET = -2147483632 /* BIT_IN | 0x10 */;
    public static final int IN_AUX_DIGITAL = -2147483616 /* BIT_IN | 0x20 */;
    public static final int IN_HDMI = -2147483616 /* IN_AUX_DIGITAL */;
    /**
     * Telephony voice RX path
     */
    public static final int IN_VOICE_CALL = -2147483584 /* BIT_IN | 0x40 */;
    public static final int IN_TELEPHONY_RX = -2147483584 /* IN_VOICE_CALL */;
    public static final int IN_BACK_MIC = -2147483520 /* BIT_IN | 0x80 */;
    public static final int IN_REMOTE_SUBMIX = -2147483392 /* BIT_IN | 0x100 */;
    public static final int IN_ANLG_DOCK_HEADSET = -2147483136 /* BIT_IN | 0x200 */;
    public static final int IN_DGTL_DOCK_HEADSET = -2147482624 /* BIT_IN | 0x400 */;
    public static final int IN_USB_ACCESSORY = -2147481600 /* BIT_IN | 0x800 */;
    public static final int IN_USB_DEVICE = -2147479552 /* BIT_IN | 0x1000 */;
    /**
     * FM tuner input
     */
    public static final int IN_FM_TUNER = -2147475456 /* BIT_IN | 0x2000 */;
    /**
     * TV tuner input
     */
    public static final int IN_TV_TUNER = -2147467264 /* BIT_IN | 0x4000 */;
    /**
     * Analog jack with line impedance detected
     */
    public static final int IN_LINE = -2147450880 /* BIT_IN | 0x8000 */;
    /**
     * S/PDIF in
     */
    public static final int IN_SPDIF = -2147418112 /* BIT_IN | 0x10000 */;
    public static final int IN_BLUETOOTH_A2DP = -2147352576 /* BIT_IN | 0x20000 */;
    public static final int IN_LOOPBACK = -2147221504 /* BIT_IN | 0x40000 */;
    public static final int IN_IP = -2146959360 /* BIT_IN | 0x80000 */;
    /**
     * audio bus implemented by the audio system (e.g an MOST stereo channel)
     */
    public static final int IN_BUS = -2146435072 /* BIT_IN | 0x100000 */;
    public static final int IN_PROXY = -2130706432 /* BIT_IN | 0x1000000 */;
    public static final int IN_USB_HEADSET = -2113929216 /* BIT_IN | 0x2000000 */;
    public static final int IN_DEFAULT = -1073741824 /* BIT_IN | BIT_DEFAULT */;
    public static final int IN_ALL = -1021313025 /* (IN_COMMUNICATION | IN_AMBIENT | IN_BUILTIN_MIC | IN_BLUETOOTH_SCO_HEADSET | IN_WIRED_HEADSET | IN_HDMI | IN_TELEPHONY_RX | IN_BACK_MIC | IN_REMOTE_SUBMIX | IN_ANLG_DOCK_HEADSET | IN_DGTL_DOCK_HEADSET | IN_USB_ACCESSORY | IN_USB_DEVICE | IN_FM_TUNER | IN_TV_TUNER | IN_LINE | IN_SPDIF | IN_BLUETOOTH_A2DP | IN_LOOPBACK | IN_IP | IN_BUS | IN_PROXY | IN_USB_HEADSET | IN_DEFAULT) */;
    public static final int IN_ALL_SCO = -2147483640 /* IN_BLUETOOTH_SCO_HEADSET */;
    public static final int IN_ALL_USB = -2113923072 /* (IN_USB_ACCESSORY | IN_USB_DEVICE | IN_USB_HEADSET) */;
    public static final String toString(int o) {
        if (o == NONE) {
            return "NONE";
        }
        if (o == BIT_IN) {
            return "BIT_IN";
        }
        if (o == BIT_DEFAULT) {
            return "BIT_DEFAULT";
        }
        if (o == OUT_EARPIECE) {
            return "OUT_EARPIECE";
        }
        if (o == OUT_SPEAKER) {
            return "OUT_SPEAKER";
        }
        if (o == OUT_WIRED_HEADSET) {
            return "OUT_WIRED_HEADSET";
        }
        if (o == OUT_WIRED_HEADPHONE) {
            return "OUT_WIRED_HEADPHONE";
        }
        if (o == OUT_BLUETOOTH_SCO) {
            return "OUT_BLUETOOTH_SCO";
        }
        if (o == OUT_BLUETOOTH_SCO_HEADSET) {
            return "OUT_BLUETOOTH_SCO_HEADSET";
        }
        if (o == OUT_BLUETOOTH_SCO_CARKIT) {
            return "OUT_BLUETOOTH_SCO_CARKIT";
        }
        if (o == OUT_BLUETOOTH_A2DP) {
            return "OUT_BLUETOOTH_A2DP";
        }
        if (o == OUT_BLUETOOTH_A2DP_HEADPHONES) {
            return "OUT_BLUETOOTH_A2DP_HEADPHONES";
        }
        if (o == OUT_BLUETOOTH_A2DP_SPEAKER) {
            return "OUT_BLUETOOTH_A2DP_SPEAKER";
        }
        if (o == OUT_AUX_DIGITAL) {
            return "OUT_AUX_DIGITAL";
        }
        if (o == OUT_HDMI) {
            return "OUT_HDMI";
        }
        if (o == OUT_ANLG_DOCK_HEADSET) {
            return "OUT_ANLG_DOCK_HEADSET";
        }
        if (o == OUT_DGTL_DOCK_HEADSET) {
            return "OUT_DGTL_DOCK_HEADSET";
        }
        if (o == OUT_USB_ACCESSORY) {
            return "OUT_USB_ACCESSORY";
        }
        if (o == OUT_USB_DEVICE) {
            return "OUT_USB_DEVICE";
        }
        if (o == OUT_REMOTE_SUBMIX) {
            return "OUT_REMOTE_SUBMIX";
        }
        if (o == OUT_TELEPHONY_TX) {
            return "OUT_TELEPHONY_TX";
        }
        if (o == OUT_LINE) {
            return "OUT_LINE";
        }
        if (o == OUT_HDMI_ARC) {
            return "OUT_HDMI_ARC";
        }
        if (o == OUT_SPDIF) {
            return "OUT_SPDIF";
        }
        if (o == OUT_FM) {
            return "OUT_FM";
        }
        if (o == OUT_AUX_LINE) {
            return "OUT_AUX_LINE";
        }
        if (o == OUT_SPEAKER_SAFE) {
            return "OUT_SPEAKER_SAFE";
        }
        if (o == OUT_IP) {
            return "OUT_IP";
        }
        if (o == OUT_BUS) {
            return "OUT_BUS";
        }
        if (o == OUT_PROXY) {
            return "OUT_PROXY";
        }
        if (o == OUT_USB_HEADSET) {
            return "OUT_USB_HEADSET";
        }
        if (o == OUT_DEFAULT) {
            return "OUT_DEFAULT";
        }
        if (o == OUT_ALL) {
            return "OUT_ALL";
        }
        if (o == OUT_ALL_A2DP) {
            return "OUT_ALL_A2DP";
        }
        if (o == OUT_ALL_SCO) {
            return "OUT_ALL_SCO";
        }
        if (o == OUT_ALL_USB) {
            return "OUT_ALL_USB";
        }
        if (o == IN_COMMUNICATION) {
            return "IN_COMMUNICATION";
        }
        if (o == IN_AMBIENT) {
            return "IN_AMBIENT";
        }
        if (o == IN_BUILTIN_MIC) {
            return "IN_BUILTIN_MIC";
        }
        if (o == IN_BLUETOOTH_SCO_HEADSET) {
            return "IN_BLUETOOTH_SCO_HEADSET";
        }
        if (o == IN_WIRED_HEADSET) {
            return "IN_WIRED_HEADSET";
        }
        if (o == IN_AUX_DIGITAL) {
            return "IN_AUX_DIGITAL";
        }
        if (o == IN_HDMI) {
            return "IN_HDMI";
        }
        if (o == IN_VOICE_CALL) {
            return "IN_VOICE_CALL";
        }
        if (o == IN_TELEPHONY_RX) {
            return "IN_TELEPHONY_RX";
        }
        if (o == IN_BACK_MIC) {
            return "IN_BACK_MIC";
        }
        if (o == IN_REMOTE_SUBMIX) {
            return "IN_REMOTE_SUBMIX";
        }
        if (o == IN_ANLG_DOCK_HEADSET) {
            return "IN_ANLG_DOCK_HEADSET";
        }
        if (o == IN_DGTL_DOCK_HEADSET) {
            return "IN_DGTL_DOCK_HEADSET";
        }
        if (o == IN_USB_ACCESSORY) {
            return "IN_USB_ACCESSORY";
        }
        if (o == IN_USB_DEVICE) {
            return "IN_USB_DEVICE";
        }
        if (o == IN_FM_TUNER) {
            return "IN_FM_TUNER";
        }
        if (o == IN_TV_TUNER) {
            return "IN_TV_TUNER";
        }
        if (o == IN_LINE) {
            return "IN_LINE";
        }
        if (o == IN_SPDIF) {
            return "IN_SPDIF";
        }
        if (o == IN_BLUETOOTH_A2DP) {
            return "IN_BLUETOOTH_A2DP";
        }
        if (o == IN_LOOPBACK) {
            return "IN_LOOPBACK";
        }
        if (o == IN_IP) {
            return "IN_IP";
        }
        if (o == IN_BUS) {
            return "IN_BUS";
        }
        if (o == IN_PROXY) {
            return "IN_PROXY";
        }
        if (o == IN_USB_HEADSET) {
            return "IN_USB_HEADSET";
        }
        if (o == IN_DEFAULT) {
            return "IN_DEFAULT";
        }
        if (o == IN_ALL) {
            return "IN_ALL";
        }
        if (o == IN_ALL_SCO) {
            return "IN_ALL_SCO";
        }
        if (o == IN_ALL_USB) {
            return "IN_ALL_USB";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NONE"); // NONE == 0
        if ((o & BIT_IN) == BIT_IN) {
            list.add("BIT_IN");
            flipped |= BIT_IN;
        }
        if ((o & BIT_DEFAULT) == BIT_DEFAULT) {
            list.add("BIT_DEFAULT");
            flipped |= BIT_DEFAULT;
        }
        if ((o & OUT_EARPIECE) == OUT_EARPIECE) {
            list.add("OUT_EARPIECE");
            flipped |= OUT_EARPIECE;
        }
        if ((o & OUT_SPEAKER) == OUT_SPEAKER) {
            list.add("OUT_SPEAKER");
            flipped |= OUT_SPEAKER;
        }
        if ((o & OUT_WIRED_HEADSET) == OUT_WIRED_HEADSET) {
            list.add("OUT_WIRED_HEADSET");
            flipped |= OUT_WIRED_HEADSET;
        }
        if ((o & OUT_WIRED_HEADPHONE) == OUT_WIRED_HEADPHONE) {
            list.add("OUT_WIRED_HEADPHONE");
            flipped |= OUT_WIRED_HEADPHONE;
        }
        if ((o & OUT_BLUETOOTH_SCO) == OUT_BLUETOOTH_SCO) {
            list.add("OUT_BLUETOOTH_SCO");
            flipped |= OUT_BLUETOOTH_SCO;
        }
        if ((o & OUT_BLUETOOTH_SCO_HEADSET) == OUT_BLUETOOTH_SCO_HEADSET) {
            list.add("OUT_BLUETOOTH_SCO_HEADSET");
            flipped |= OUT_BLUETOOTH_SCO_HEADSET;
        }
        if ((o & OUT_BLUETOOTH_SCO_CARKIT) == OUT_BLUETOOTH_SCO_CARKIT) {
            list.add("OUT_BLUETOOTH_SCO_CARKIT");
            flipped |= OUT_BLUETOOTH_SCO_CARKIT;
        }
        if ((o & OUT_BLUETOOTH_A2DP) == OUT_BLUETOOTH_A2DP) {
            list.add("OUT_BLUETOOTH_A2DP");
            flipped |= OUT_BLUETOOTH_A2DP;
        }
        if ((o & OUT_BLUETOOTH_A2DP_HEADPHONES) == OUT_BLUETOOTH_A2DP_HEADPHONES) {
            list.add("OUT_BLUETOOTH_A2DP_HEADPHONES");
            flipped |= OUT_BLUETOOTH_A2DP_HEADPHONES;
        }
        if ((o & OUT_BLUETOOTH_A2DP_SPEAKER) == OUT_BLUETOOTH_A2DP_SPEAKER) {
            list.add("OUT_BLUETOOTH_A2DP_SPEAKER");
            flipped |= OUT_BLUETOOTH_A2DP_SPEAKER;
        }
        if ((o & OUT_AUX_DIGITAL) == OUT_AUX_DIGITAL) {
            list.add("OUT_AUX_DIGITAL");
            flipped |= OUT_AUX_DIGITAL;
        }
        if ((o & OUT_HDMI) == OUT_HDMI) {
            list.add("OUT_HDMI");
            flipped |= OUT_HDMI;
        }
        if ((o & OUT_ANLG_DOCK_HEADSET) == OUT_ANLG_DOCK_HEADSET) {
            list.add("OUT_ANLG_DOCK_HEADSET");
            flipped |= OUT_ANLG_DOCK_HEADSET;
        }
        if ((o & OUT_DGTL_DOCK_HEADSET) == OUT_DGTL_DOCK_HEADSET) {
            list.add("OUT_DGTL_DOCK_HEADSET");
            flipped |= OUT_DGTL_DOCK_HEADSET;
        }
        if ((o & OUT_USB_ACCESSORY) == OUT_USB_ACCESSORY) {
            list.add("OUT_USB_ACCESSORY");
            flipped |= OUT_USB_ACCESSORY;
        }
        if ((o & OUT_USB_DEVICE) == OUT_USB_DEVICE) {
            list.add("OUT_USB_DEVICE");
            flipped |= OUT_USB_DEVICE;
        }
        if ((o & OUT_REMOTE_SUBMIX) == OUT_REMOTE_SUBMIX) {
            list.add("OUT_REMOTE_SUBMIX");
            flipped |= OUT_REMOTE_SUBMIX;
        }
        if ((o & OUT_TELEPHONY_TX) == OUT_TELEPHONY_TX) {
            list.add("OUT_TELEPHONY_TX");
            flipped |= OUT_TELEPHONY_TX;
        }
        if ((o & OUT_LINE) == OUT_LINE) {
            list.add("OUT_LINE");
            flipped |= OUT_LINE;
        }
        if ((o & OUT_HDMI_ARC) == OUT_HDMI_ARC) {
            list.add("OUT_HDMI_ARC");
            flipped |= OUT_HDMI_ARC;
        }
        if ((o & OUT_SPDIF) == OUT_SPDIF) {
            list.add("OUT_SPDIF");
            flipped |= OUT_SPDIF;
        }
        if ((o & OUT_FM) == OUT_FM) {
            list.add("OUT_FM");
            flipped |= OUT_FM;
        }
        if ((o & OUT_AUX_LINE) == OUT_AUX_LINE) {
            list.add("OUT_AUX_LINE");
            flipped |= OUT_AUX_LINE;
        }
        if ((o & OUT_SPEAKER_SAFE) == OUT_SPEAKER_SAFE) {
            list.add("OUT_SPEAKER_SAFE");
            flipped |= OUT_SPEAKER_SAFE;
        }
        if ((o & OUT_IP) == OUT_IP) {
            list.add("OUT_IP");
            flipped |= OUT_IP;
        }
        if ((o & OUT_BUS) == OUT_BUS) {
            list.add("OUT_BUS");
            flipped |= OUT_BUS;
        }
        if ((o & OUT_PROXY) == OUT_PROXY) {
            list.add("OUT_PROXY");
            flipped |= OUT_PROXY;
        }
        if ((o & OUT_USB_HEADSET) == OUT_USB_HEADSET) {
            list.add("OUT_USB_HEADSET");
            flipped |= OUT_USB_HEADSET;
        }
        if ((o & OUT_DEFAULT) == OUT_DEFAULT) {
            list.add("OUT_DEFAULT");
            flipped |= OUT_DEFAULT;
        }
        if ((o & OUT_ALL) == OUT_ALL) {
            list.add("OUT_ALL");
            flipped |= OUT_ALL;
        }
        if ((o & OUT_ALL_A2DP) == OUT_ALL_A2DP) {
            list.add("OUT_ALL_A2DP");
            flipped |= OUT_ALL_A2DP;
        }
        if ((o & OUT_ALL_SCO) == OUT_ALL_SCO) {
            list.add("OUT_ALL_SCO");
            flipped |= OUT_ALL_SCO;
        }
        if ((o & OUT_ALL_USB) == OUT_ALL_USB) {
            list.add("OUT_ALL_USB");
            flipped |= OUT_ALL_USB;
        }
        if ((o & IN_COMMUNICATION) == IN_COMMUNICATION) {
            list.add("IN_COMMUNICATION");
            flipped |= IN_COMMUNICATION;
        }
        if ((o & IN_AMBIENT) == IN_AMBIENT) {
            list.add("IN_AMBIENT");
            flipped |= IN_AMBIENT;
        }
        if ((o & IN_BUILTIN_MIC) == IN_BUILTIN_MIC) {
            list.add("IN_BUILTIN_MIC");
            flipped |= IN_BUILTIN_MIC;
        }
        if ((o & IN_BLUETOOTH_SCO_HEADSET) == IN_BLUETOOTH_SCO_HEADSET) {
            list.add("IN_BLUETOOTH_SCO_HEADSET");
            flipped |= IN_BLUETOOTH_SCO_HEADSET;
        }
        if ((o & IN_WIRED_HEADSET) == IN_WIRED_HEADSET) {
            list.add("IN_WIRED_HEADSET");
            flipped |= IN_WIRED_HEADSET;
        }
        if ((o & IN_AUX_DIGITAL) == IN_AUX_DIGITAL) {
            list.add("IN_AUX_DIGITAL");
            flipped |= IN_AUX_DIGITAL;
        }
        if ((o & IN_HDMI) == IN_HDMI) {
            list.add("IN_HDMI");
            flipped |= IN_HDMI;
        }
        if ((o & IN_VOICE_CALL) == IN_VOICE_CALL) {
            list.add("IN_VOICE_CALL");
            flipped |= IN_VOICE_CALL;
        }
        if ((o & IN_TELEPHONY_RX) == IN_TELEPHONY_RX) {
            list.add("IN_TELEPHONY_RX");
            flipped |= IN_TELEPHONY_RX;
        }
        if ((o & IN_BACK_MIC) == IN_BACK_MIC) {
            list.add("IN_BACK_MIC");
            flipped |= IN_BACK_MIC;
        }
        if ((o & IN_REMOTE_SUBMIX) == IN_REMOTE_SUBMIX) {
            list.add("IN_REMOTE_SUBMIX");
            flipped |= IN_REMOTE_SUBMIX;
        }
        if ((o & IN_ANLG_DOCK_HEADSET) == IN_ANLG_DOCK_HEADSET) {
            list.add("IN_ANLG_DOCK_HEADSET");
            flipped |= IN_ANLG_DOCK_HEADSET;
        }
        if ((o & IN_DGTL_DOCK_HEADSET) == IN_DGTL_DOCK_HEADSET) {
            list.add("IN_DGTL_DOCK_HEADSET");
            flipped |= IN_DGTL_DOCK_HEADSET;
        }
        if ((o & IN_USB_ACCESSORY) == IN_USB_ACCESSORY) {
            list.add("IN_USB_ACCESSORY");
            flipped |= IN_USB_ACCESSORY;
        }
        if ((o & IN_USB_DEVICE) == IN_USB_DEVICE) {
            list.add("IN_USB_DEVICE");
            flipped |= IN_USB_DEVICE;
        }
        if ((o & IN_FM_TUNER) == IN_FM_TUNER) {
            list.add("IN_FM_TUNER");
            flipped |= IN_FM_TUNER;
        }
        if ((o & IN_TV_TUNER) == IN_TV_TUNER) {
            list.add("IN_TV_TUNER");
            flipped |= IN_TV_TUNER;
        }
        if ((o & IN_LINE) == IN_LINE) {
            list.add("IN_LINE");
            flipped |= IN_LINE;
        }
        if ((o & IN_SPDIF) == IN_SPDIF) {
            list.add("IN_SPDIF");
            flipped |= IN_SPDIF;
        }
        if ((o & IN_BLUETOOTH_A2DP) == IN_BLUETOOTH_A2DP) {
            list.add("IN_BLUETOOTH_A2DP");
            flipped |= IN_BLUETOOTH_A2DP;
        }
        if ((o & IN_LOOPBACK) == IN_LOOPBACK) {
            list.add("IN_LOOPBACK");
            flipped |= IN_LOOPBACK;
        }
        if ((o & IN_IP) == IN_IP) {
            list.add("IN_IP");
            flipped |= IN_IP;
        }
        if ((o & IN_BUS) == IN_BUS) {
            list.add("IN_BUS");
            flipped |= IN_BUS;
        }
        if ((o & IN_PROXY) == IN_PROXY) {
            list.add("IN_PROXY");
            flipped |= IN_PROXY;
        }
        if ((o & IN_USB_HEADSET) == IN_USB_HEADSET) {
            list.add("IN_USB_HEADSET");
            flipped |= IN_USB_HEADSET;
        }
        if ((o & IN_DEFAULT) == IN_DEFAULT) {
            list.add("IN_DEFAULT");
            flipped |= IN_DEFAULT;
        }
        if ((o & IN_ALL) == IN_ALL) {
            list.add("IN_ALL");
            flipped |= IN_ALL;
        }
        if ((o & IN_ALL_SCO) == IN_ALL_SCO) {
            list.add("IN_ALL_SCO");
            flipped |= IN_ALL_SCO;
        }
        if ((o & IN_ALL_USB) == IN_ALL_USB) {
            list.add("IN_ALL_USB");
            flipped |= IN_ALL_USB;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

