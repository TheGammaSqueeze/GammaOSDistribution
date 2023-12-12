package android.hardware.tv.cec.V1_0;


public final class CecMessageType {
    public static final int FEATURE_ABORT = 0 /* 0x00 */;
    public static final int IMAGE_VIEW_ON = 4 /* 0x04 */;
    public static final int TUNER_STEP_INCREMENT = 5 /* 0x05 */;
    public static final int TUNER_STEP_DECREMENT = 6 /* 0x06 */;
    public static final int TUNER_DEVICE_STATUS = 7 /* 0x07 */;
    public static final int GIVE_TUNER_DEVICE_STATUS = 8 /* 0x08 */;
    public static final int RECORD_ON = 9 /* 0x09 */;
    public static final int RECORD_STATUS = 10 /* 0x0A */;
    public static final int RECORD_OFF = 11 /* 0x0B */;
    public static final int TEXT_VIEW_ON = 13 /* 0x0D */;
    public static final int RECORD_TV_SCREEN = 15 /* 0x0F */;
    public static final int GIVE_DECK_STATUS = 26 /* 0x1A */;
    public static final int DECK_STATUS = 27 /* 0x1B */;
    public static final int SET_MENU_LANGUAGE = 50 /* 0x32 */;
    public static final int CLEAR_ANALOG_TIMER = 51 /* 0x33 */;
    public static final int SET_ANALOG_TIMER = 52 /* 0x34 */;
    public static final int TIMER_STATUS = 53 /* 0x35 */;
    public static final int STANDBY = 54 /* 0x36 */;
    public static final int PLAY = 65 /* 0x41 */;
    public static final int DECK_CONTROL = 66 /* 0x42 */;
    public static final int TIMER_CLEARED_STATUS = 67 /* 0x43 */;
    public static final int USER_CONTROL_PRESSED = 68 /* 0x44 */;
    public static final int USER_CONTROL_RELEASED = 69 /* 0x45 */;
    public static final int GIVE_OSD_NAME = 70 /* 0x46 */;
    public static final int SET_OSD_NAME = 71 /* 0x47 */;
    public static final int SET_OSD_STRING = 100 /* 0x64 */;
    public static final int SET_TIMER_PROGRAM_TITLE = 103 /* 0x67 */;
    public static final int SYSTEM_AUDIO_MODE_REQUEST = 112 /* 0x70 */;
    public static final int GIVE_AUDIO_STATUS = 113 /* 0x71 */;
    public static final int SET_SYSTEM_AUDIO_MODE = 114 /* 0x72 */;
    public static final int REPORT_AUDIO_STATUS = 122 /* 0x7A */;
    public static final int GIVE_SYSTEM_AUDIO_MODE_STATUS = 125 /* 0x7D */;
    public static final int SYSTEM_AUDIO_MODE_STATUS = 126 /* 0x7E */;
    public static final int ROUTING_CHANGE = 128 /* 0x80 */;
    public static final int ROUTING_INFORMATION = 129 /* 0x81 */;
    public static final int ACTIVE_SOURCE = 130 /* 0x82 */;
    public static final int GIVE_PHYSICAL_ADDRESS = 131 /* 0x83 */;
    public static final int REPORT_PHYSICAL_ADDRESS = 132 /* 0x84 */;
    public static final int REQUEST_ACTIVE_SOURCE = 133 /* 0x85 */;
    public static final int SET_STREAM_PATH = 134 /* 0x86 */;
    public static final int DEVICE_VENDOR_ID = 135 /* 0x87 */;
    public static final int VENDOR_COMMAND = 137 /* 0x89 */;
    public static final int VENDOR_REMOTE_BUTTON_DOWN = 138 /* 0x8A */;
    public static final int VENDOR_REMOTE_BUTTON_UP = 139 /* 0x8B */;
    public static final int GIVE_DEVICE_VENDOR_ID = 140 /* 0x8C */;
    public static final int MENU_REQUEST = 141 /* 0x8D */;
    public static final int MENU_STATUS = 142 /* 0x8E */;
    public static final int GIVE_DEVICE_POWER_STATUS = 143 /* 0x8F */;
    public static final int REPORT_POWER_STATUS = 144 /* 0x90 */;
    public static final int GET_MENU_LANGUAGE = 145 /* 0x91 */;
    public static final int SELECT_ANALOG_SERVICE = 146 /* 0x92 */;
    public static final int SELECT_DIGITAL_SERVICE = 147 /* 0x93 */;
    public static final int SET_DIGITAL_TIMER = 151 /* 0x97 */;
    public static final int CLEAR_DIGITAL_TIMER = 153 /* 0x99 */;
    public static final int SET_AUDIO_RATE = 154 /* 0x9A */;
    public static final int INACTIVE_SOURCE = 157 /* 0x9D */;
    public static final int CEC_VERSION = 158 /* 0x9E */;
    public static final int GET_CEC_VERSION = 159 /* 0x9F */;
    public static final int VENDOR_COMMAND_WITH_ID = 160 /* 0xA0 */;
    public static final int CLEAR_EXTERNAL_TIMER = 161 /* 0xA1 */;
    public static final int SET_EXTERNAL_TIMER = 162 /* 0xA2 */;
    public static final int REPORT_SHORT_AUDIO_DESCRIPTOR = 163 /* 0xA3 */;
    public static final int REQUEST_SHORT_AUDIO_DESCRIPTOR = 164 /* 0xA4 */;
    public static final int INITIATE_ARC = 192 /* 0xC0 */;
    public static final int REPORT_ARC_INITIATED = 193 /* 0xC1 */;
    public static final int REPORT_ARC_TERMINATED = 194 /* 0xC2 */;
    public static final int REQUEST_ARC_INITIATION = 195 /* 0xC3 */;
    public static final int REQUEST_ARC_TERMINATION = 196 /* 0xC4 */;
    public static final int TERMINATE_ARC = 197 /* 0xC5 */;
    public static final int ABORT = 255 /* 0xFF */;
    public static final String toString(int o) {
        if (o == FEATURE_ABORT) {
            return "FEATURE_ABORT";
        }
        if (o == IMAGE_VIEW_ON) {
            return "IMAGE_VIEW_ON";
        }
        if (o == TUNER_STEP_INCREMENT) {
            return "TUNER_STEP_INCREMENT";
        }
        if (o == TUNER_STEP_DECREMENT) {
            return "TUNER_STEP_DECREMENT";
        }
        if (o == TUNER_DEVICE_STATUS) {
            return "TUNER_DEVICE_STATUS";
        }
        if (o == GIVE_TUNER_DEVICE_STATUS) {
            return "GIVE_TUNER_DEVICE_STATUS";
        }
        if (o == RECORD_ON) {
            return "RECORD_ON";
        }
        if (o == RECORD_STATUS) {
            return "RECORD_STATUS";
        }
        if (o == RECORD_OFF) {
            return "RECORD_OFF";
        }
        if (o == TEXT_VIEW_ON) {
            return "TEXT_VIEW_ON";
        }
        if (o == RECORD_TV_SCREEN) {
            return "RECORD_TV_SCREEN";
        }
        if (o == GIVE_DECK_STATUS) {
            return "GIVE_DECK_STATUS";
        }
        if (o == DECK_STATUS) {
            return "DECK_STATUS";
        }
        if (o == SET_MENU_LANGUAGE) {
            return "SET_MENU_LANGUAGE";
        }
        if (o == CLEAR_ANALOG_TIMER) {
            return "CLEAR_ANALOG_TIMER";
        }
        if (o == SET_ANALOG_TIMER) {
            return "SET_ANALOG_TIMER";
        }
        if (o == TIMER_STATUS) {
            return "TIMER_STATUS";
        }
        if (o == STANDBY) {
            return "STANDBY";
        }
        if (o == PLAY) {
            return "PLAY";
        }
        if (o == DECK_CONTROL) {
            return "DECK_CONTROL";
        }
        if (o == TIMER_CLEARED_STATUS) {
            return "TIMER_CLEARED_STATUS";
        }
        if (o == USER_CONTROL_PRESSED) {
            return "USER_CONTROL_PRESSED";
        }
        if (o == USER_CONTROL_RELEASED) {
            return "USER_CONTROL_RELEASED";
        }
        if (o == GIVE_OSD_NAME) {
            return "GIVE_OSD_NAME";
        }
        if (o == SET_OSD_NAME) {
            return "SET_OSD_NAME";
        }
        if (o == SET_OSD_STRING) {
            return "SET_OSD_STRING";
        }
        if (o == SET_TIMER_PROGRAM_TITLE) {
            return "SET_TIMER_PROGRAM_TITLE";
        }
        if (o == SYSTEM_AUDIO_MODE_REQUEST) {
            return "SYSTEM_AUDIO_MODE_REQUEST";
        }
        if (o == GIVE_AUDIO_STATUS) {
            return "GIVE_AUDIO_STATUS";
        }
        if (o == SET_SYSTEM_AUDIO_MODE) {
            return "SET_SYSTEM_AUDIO_MODE";
        }
        if (o == REPORT_AUDIO_STATUS) {
            return "REPORT_AUDIO_STATUS";
        }
        if (o == GIVE_SYSTEM_AUDIO_MODE_STATUS) {
            return "GIVE_SYSTEM_AUDIO_MODE_STATUS";
        }
        if (o == SYSTEM_AUDIO_MODE_STATUS) {
            return "SYSTEM_AUDIO_MODE_STATUS";
        }
        if (o == ROUTING_CHANGE) {
            return "ROUTING_CHANGE";
        }
        if (o == ROUTING_INFORMATION) {
            return "ROUTING_INFORMATION";
        }
        if (o == ACTIVE_SOURCE) {
            return "ACTIVE_SOURCE";
        }
        if (o == GIVE_PHYSICAL_ADDRESS) {
            return "GIVE_PHYSICAL_ADDRESS";
        }
        if (o == REPORT_PHYSICAL_ADDRESS) {
            return "REPORT_PHYSICAL_ADDRESS";
        }
        if (o == REQUEST_ACTIVE_SOURCE) {
            return "REQUEST_ACTIVE_SOURCE";
        }
        if (o == SET_STREAM_PATH) {
            return "SET_STREAM_PATH";
        }
        if (o == DEVICE_VENDOR_ID) {
            return "DEVICE_VENDOR_ID";
        }
        if (o == VENDOR_COMMAND) {
            return "VENDOR_COMMAND";
        }
        if (o == VENDOR_REMOTE_BUTTON_DOWN) {
            return "VENDOR_REMOTE_BUTTON_DOWN";
        }
        if (o == VENDOR_REMOTE_BUTTON_UP) {
            return "VENDOR_REMOTE_BUTTON_UP";
        }
        if (o == GIVE_DEVICE_VENDOR_ID) {
            return "GIVE_DEVICE_VENDOR_ID";
        }
        if (o == MENU_REQUEST) {
            return "MENU_REQUEST";
        }
        if (o == MENU_STATUS) {
            return "MENU_STATUS";
        }
        if (o == GIVE_DEVICE_POWER_STATUS) {
            return "GIVE_DEVICE_POWER_STATUS";
        }
        if (o == REPORT_POWER_STATUS) {
            return "REPORT_POWER_STATUS";
        }
        if (o == GET_MENU_LANGUAGE) {
            return "GET_MENU_LANGUAGE";
        }
        if (o == SELECT_ANALOG_SERVICE) {
            return "SELECT_ANALOG_SERVICE";
        }
        if (o == SELECT_DIGITAL_SERVICE) {
            return "SELECT_DIGITAL_SERVICE";
        }
        if (o == SET_DIGITAL_TIMER) {
            return "SET_DIGITAL_TIMER";
        }
        if (o == CLEAR_DIGITAL_TIMER) {
            return "CLEAR_DIGITAL_TIMER";
        }
        if (o == SET_AUDIO_RATE) {
            return "SET_AUDIO_RATE";
        }
        if (o == INACTIVE_SOURCE) {
            return "INACTIVE_SOURCE";
        }
        if (o == CEC_VERSION) {
            return "CEC_VERSION";
        }
        if (o == GET_CEC_VERSION) {
            return "GET_CEC_VERSION";
        }
        if (o == VENDOR_COMMAND_WITH_ID) {
            return "VENDOR_COMMAND_WITH_ID";
        }
        if (o == CLEAR_EXTERNAL_TIMER) {
            return "CLEAR_EXTERNAL_TIMER";
        }
        if (o == SET_EXTERNAL_TIMER) {
            return "SET_EXTERNAL_TIMER";
        }
        if (o == REPORT_SHORT_AUDIO_DESCRIPTOR) {
            return "REPORT_SHORT_AUDIO_DESCRIPTOR";
        }
        if (o == REQUEST_SHORT_AUDIO_DESCRIPTOR) {
            return "REQUEST_SHORT_AUDIO_DESCRIPTOR";
        }
        if (o == INITIATE_ARC) {
            return "INITIATE_ARC";
        }
        if (o == REPORT_ARC_INITIATED) {
            return "REPORT_ARC_INITIATED";
        }
        if (o == REPORT_ARC_TERMINATED) {
            return "REPORT_ARC_TERMINATED";
        }
        if (o == REQUEST_ARC_INITIATION) {
            return "REQUEST_ARC_INITIATION";
        }
        if (o == REQUEST_ARC_TERMINATION) {
            return "REQUEST_ARC_TERMINATION";
        }
        if (o == TERMINATE_ARC) {
            return "TERMINATE_ARC";
        }
        if (o == ABORT) {
            return "ABORT";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("FEATURE_ABORT"); // FEATURE_ABORT == 0
        if ((o & IMAGE_VIEW_ON) == IMAGE_VIEW_ON) {
            list.add("IMAGE_VIEW_ON");
            flipped |= IMAGE_VIEW_ON;
        }
        if ((o & TUNER_STEP_INCREMENT) == TUNER_STEP_INCREMENT) {
            list.add("TUNER_STEP_INCREMENT");
            flipped |= TUNER_STEP_INCREMENT;
        }
        if ((o & TUNER_STEP_DECREMENT) == TUNER_STEP_DECREMENT) {
            list.add("TUNER_STEP_DECREMENT");
            flipped |= TUNER_STEP_DECREMENT;
        }
        if ((o & TUNER_DEVICE_STATUS) == TUNER_DEVICE_STATUS) {
            list.add("TUNER_DEVICE_STATUS");
            flipped |= TUNER_DEVICE_STATUS;
        }
        if ((o & GIVE_TUNER_DEVICE_STATUS) == GIVE_TUNER_DEVICE_STATUS) {
            list.add("GIVE_TUNER_DEVICE_STATUS");
            flipped |= GIVE_TUNER_DEVICE_STATUS;
        }
        if ((o & RECORD_ON) == RECORD_ON) {
            list.add("RECORD_ON");
            flipped |= RECORD_ON;
        }
        if ((o & RECORD_STATUS) == RECORD_STATUS) {
            list.add("RECORD_STATUS");
            flipped |= RECORD_STATUS;
        }
        if ((o & RECORD_OFF) == RECORD_OFF) {
            list.add("RECORD_OFF");
            flipped |= RECORD_OFF;
        }
        if ((o & TEXT_VIEW_ON) == TEXT_VIEW_ON) {
            list.add("TEXT_VIEW_ON");
            flipped |= TEXT_VIEW_ON;
        }
        if ((o & RECORD_TV_SCREEN) == RECORD_TV_SCREEN) {
            list.add("RECORD_TV_SCREEN");
            flipped |= RECORD_TV_SCREEN;
        }
        if ((o & GIVE_DECK_STATUS) == GIVE_DECK_STATUS) {
            list.add("GIVE_DECK_STATUS");
            flipped |= GIVE_DECK_STATUS;
        }
        if ((o & DECK_STATUS) == DECK_STATUS) {
            list.add("DECK_STATUS");
            flipped |= DECK_STATUS;
        }
        if ((o & SET_MENU_LANGUAGE) == SET_MENU_LANGUAGE) {
            list.add("SET_MENU_LANGUAGE");
            flipped |= SET_MENU_LANGUAGE;
        }
        if ((o & CLEAR_ANALOG_TIMER) == CLEAR_ANALOG_TIMER) {
            list.add("CLEAR_ANALOG_TIMER");
            flipped |= CLEAR_ANALOG_TIMER;
        }
        if ((o & SET_ANALOG_TIMER) == SET_ANALOG_TIMER) {
            list.add("SET_ANALOG_TIMER");
            flipped |= SET_ANALOG_TIMER;
        }
        if ((o & TIMER_STATUS) == TIMER_STATUS) {
            list.add("TIMER_STATUS");
            flipped |= TIMER_STATUS;
        }
        if ((o & STANDBY) == STANDBY) {
            list.add("STANDBY");
            flipped |= STANDBY;
        }
        if ((o & PLAY) == PLAY) {
            list.add("PLAY");
            flipped |= PLAY;
        }
        if ((o & DECK_CONTROL) == DECK_CONTROL) {
            list.add("DECK_CONTROL");
            flipped |= DECK_CONTROL;
        }
        if ((o & TIMER_CLEARED_STATUS) == TIMER_CLEARED_STATUS) {
            list.add("TIMER_CLEARED_STATUS");
            flipped |= TIMER_CLEARED_STATUS;
        }
        if ((o & USER_CONTROL_PRESSED) == USER_CONTROL_PRESSED) {
            list.add("USER_CONTROL_PRESSED");
            flipped |= USER_CONTROL_PRESSED;
        }
        if ((o & USER_CONTROL_RELEASED) == USER_CONTROL_RELEASED) {
            list.add("USER_CONTROL_RELEASED");
            flipped |= USER_CONTROL_RELEASED;
        }
        if ((o & GIVE_OSD_NAME) == GIVE_OSD_NAME) {
            list.add("GIVE_OSD_NAME");
            flipped |= GIVE_OSD_NAME;
        }
        if ((o & SET_OSD_NAME) == SET_OSD_NAME) {
            list.add("SET_OSD_NAME");
            flipped |= SET_OSD_NAME;
        }
        if ((o & SET_OSD_STRING) == SET_OSD_STRING) {
            list.add("SET_OSD_STRING");
            flipped |= SET_OSD_STRING;
        }
        if ((o & SET_TIMER_PROGRAM_TITLE) == SET_TIMER_PROGRAM_TITLE) {
            list.add("SET_TIMER_PROGRAM_TITLE");
            flipped |= SET_TIMER_PROGRAM_TITLE;
        }
        if ((o & SYSTEM_AUDIO_MODE_REQUEST) == SYSTEM_AUDIO_MODE_REQUEST) {
            list.add("SYSTEM_AUDIO_MODE_REQUEST");
            flipped |= SYSTEM_AUDIO_MODE_REQUEST;
        }
        if ((o & GIVE_AUDIO_STATUS) == GIVE_AUDIO_STATUS) {
            list.add("GIVE_AUDIO_STATUS");
            flipped |= GIVE_AUDIO_STATUS;
        }
        if ((o & SET_SYSTEM_AUDIO_MODE) == SET_SYSTEM_AUDIO_MODE) {
            list.add("SET_SYSTEM_AUDIO_MODE");
            flipped |= SET_SYSTEM_AUDIO_MODE;
        }
        if ((o & REPORT_AUDIO_STATUS) == REPORT_AUDIO_STATUS) {
            list.add("REPORT_AUDIO_STATUS");
            flipped |= REPORT_AUDIO_STATUS;
        }
        if ((o & GIVE_SYSTEM_AUDIO_MODE_STATUS) == GIVE_SYSTEM_AUDIO_MODE_STATUS) {
            list.add("GIVE_SYSTEM_AUDIO_MODE_STATUS");
            flipped |= GIVE_SYSTEM_AUDIO_MODE_STATUS;
        }
        if ((o & SYSTEM_AUDIO_MODE_STATUS) == SYSTEM_AUDIO_MODE_STATUS) {
            list.add("SYSTEM_AUDIO_MODE_STATUS");
            flipped |= SYSTEM_AUDIO_MODE_STATUS;
        }
        if ((o & ROUTING_CHANGE) == ROUTING_CHANGE) {
            list.add("ROUTING_CHANGE");
            flipped |= ROUTING_CHANGE;
        }
        if ((o & ROUTING_INFORMATION) == ROUTING_INFORMATION) {
            list.add("ROUTING_INFORMATION");
            flipped |= ROUTING_INFORMATION;
        }
        if ((o & ACTIVE_SOURCE) == ACTIVE_SOURCE) {
            list.add("ACTIVE_SOURCE");
            flipped |= ACTIVE_SOURCE;
        }
        if ((o & GIVE_PHYSICAL_ADDRESS) == GIVE_PHYSICAL_ADDRESS) {
            list.add("GIVE_PHYSICAL_ADDRESS");
            flipped |= GIVE_PHYSICAL_ADDRESS;
        }
        if ((o & REPORT_PHYSICAL_ADDRESS) == REPORT_PHYSICAL_ADDRESS) {
            list.add("REPORT_PHYSICAL_ADDRESS");
            flipped |= REPORT_PHYSICAL_ADDRESS;
        }
        if ((o & REQUEST_ACTIVE_SOURCE) == REQUEST_ACTIVE_SOURCE) {
            list.add("REQUEST_ACTIVE_SOURCE");
            flipped |= REQUEST_ACTIVE_SOURCE;
        }
        if ((o & SET_STREAM_PATH) == SET_STREAM_PATH) {
            list.add("SET_STREAM_PATH");
            flipped |= SET_STREAM_PATH;
        }
        if ((o & DEVICE_VENDOR_ID) == DEVICE_VENDOR_ID) {
            list.add("DEVICE_VENDOR_ID");
            flipped |= DEVICE_VENDOR_ID;
        }
        if ((o & VENDOR_COMMAND) == VENDOR_COMMAND) {
            list.add("VENDOR_COMMAND");
            flipped |= VENDOR_COMMAND;
        }
        if ((o & VENDOR_REMOTE_BUTTON_DOWN) == VENDOR_REMOTE_BUTTON_DOWN) {
            list.add("VENDOR_REMOTE_BUTTON_DOWN");
            flipped |= VENDOR_REMOTE_BUTTON_DOWN;
        }
        if ((o & VENDOR_REMOTE_BUTTON_UP) == VENDOR_REMOTE_BUTTON_UP) {
            list.add("VENDOR_REMOTE_BUTTON_UP");
            flipped |= VENDOR_REMOTE_BUTTON_UP;
        }
        if ((o & GIVE_DEVICE_VENDOR_ID) == GIVE_DEVICE_VENDOR_ID) {
            list.add("GIVE_DEVICE_VENDOR_ID");
            flipped |= GIVE_DEVICE_VENDOR_ID;
        }
        if ((o & MENU_REQUEST) == MENU_REQUEST) {
            list.add("MENU_REQUEST");
            flipped |= MENU_REQUEST;
        }
        if ((o & MENU_STATUS) == MENU_STATUS) {
            list.add("MENU_STATUS");
            flipped |= MENU_STATUS;
        }
        if ((o & GIVE_DEVICE_POWER_STATUS) == GIVE_DEVICE_POWER_STATUS) {
            list.add("GIVE_DEVICE_POWER_STATUS");
            flipped |= GIVE_DEVICE_POWER_STATUS;
        }
        if ((o & REPORT_POWER_STATUS) == REPORT_POWER_STATUS) {
            list.add("REPORT_POWER_STATUS");
            flipped |= REPORT_POWER_STATUS;
        }
        if ((o & GET_MENU_LANGUAGE) == GET_MENU_LANGUAGE) {
            list.add("GET_MENU_LANGUAGE");
            flipped |= GET_MENU_LANGUAGE;
        }
        if ((o & SELECT_ANALOG_SERVICE) == SELECT_ANALOG_SERVICE) {
            list.add("SELECT_ANALOG_SERVICE");
            flipped |= SELECT_ANALOG_SERVICE;
        }
        if ((o & SELECT_DIGITAL_SERVICE) == SELECT_DIGITAL_SERVICE) {
            list.add("SELECT_DIGITAL_SERVICE");
            flipped |= SELECT_DIGITAL_SERVICE;
        }
        if ((o & SET_DIGITAL_TIMER) == SET_DIGITAL_TIMER) {
            list.add("SET_DIGITAL_TIMER");
            flipped |= SET_DIGITAL_TIMER;
        }
        if ((o & CLEAR_DIGITAL_TIMER) == CLEAR_DIGITAL_TIMER) {
            list.add("CLEAR_DIGITAL_TIMER");
            flipped |= CLEAR_DIGITAL_TIMER;
        }
        if ((o & SET_AUDIO_RATE) == SET_AUDIO_RATE) {
            list.add("SET_AUDIO_RATE");
            flipped |= SET_AUDIO_RATE;
        }
        if ((o & INACTIVE_SOURCE) == INACTIVE_SOURCE) {
            list.add("INACTIVE_SOURCE");
            flipped |= INACTIVE_SOURCE;
        }
        if ((o & CEC_VERSION) == CEC_VERSION) {
            list.add("CEC_VERSION");
            flipped |= CEC_VERSION;
        }
        if ((o & GET_CEC_VERSION) == GET_CEC_VERSION) {
            list.add("GET_CEC_VERSION");
            flipped |= GET_CEC_VERSION;
        }
        if ((o & VENDOR_COMMAND_WITH_ID) == VENDOR_COMMAND_WITH_ID) {
            list.add("VENDOR_COMMAND_WITH_ID");
            flipped |= VENDOR_COMMAND_WITH_ID;
        }
        if ((o & CLEAR_EXTERNAL_TIMER) == CLEAR_EXTERNAL_TIMER) {
            list.add("CLEAR_EXTERNAL_TIMER");
            flipped |= CLEAR_EXTERNAL_TIMER;
        }
        if ((o & SET_EXTERNAL_TIMER) == SET_EXTERNAL_TIMER) {
            list.add("SET_EXTERNAL_TIMER");
            flipped |= SET_EXTERNAL_TIMER;
        }
        if ((o & REPORT_SHORT_AUDIO_DESCRIPTOR) == REPORT_SHORT_AUDIO_DESCRIPTOR) {
            list.add("REPORT_SHORT_AUDIO_DESCRIPTOR");
            flipped |= REPORT_SHORT_AUDIO_DESCRIPTOR;
        }
        if ((o & REQUEST_SHORT_AUDIO_DESCRIPTOR) == REQUEST_SHORT_AUDIO_DESCRIPTOR) {
            list.add("REQUEST_SHORT_AUDIO_DESCRIPTOR");
            flipped |= REQUEST_SHORT_AUDIO_DESCRIPTOR;
        }
        if ((o & INITIATE_ARC) == INITIATE_ARC) {
            list.add("INITIATE_ARC");
            flipped |= INITIATE_ARC;
        }
        if ((o & REPORT_ARC_INITIATED) == REPORT_ARC_INITIATED) {
            list.add("REPORT_ARC_INITIATED");
            flipped |= REPORT_ARC_INITIATED;
        }
        if ((o & REPORT_ARC_TERMINATED) == REPORT_ARC_TERMINATED) {
            list.add("REPORT_ARC_TERMINATED");
            flipped |= REPORT_ARC_TERMINATED;
        }
        if ((o & REQUEST_ARC_INITIATION) == REQUEST_ARC_INITIATION) {
            list.add("REQUEST_ARC_INITIATION");
            flipped |= REQUEST_ARC_INITIATION;
        }
        if ((o & REQUEST_ARC_TERMINATION) == REQUEST_ARC_TERMINATION) {
            list.add("REQUEST_ARC_TERMINATION");
            flipped |= REQUEST_ARC_TERMINATION;
        }
        if ((o & TERMINATE_ARC) == TERMINATE_ARC) {
            list.add("TERMINATE_ARC");
            flipped |= TERMINATE_ARC;
        }
        if ((o & ABORT) == ABORT) {
            list.add("ABORT");
            flipped |= ABORT;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

