package android.hardware.radio.V1_0;


public final class RadioConst {
    public static final int CDMA_ALPHA_INFO_BUFFER_LENGTH = 64;
    public static final int CDMA_NUMBER_INFO_BUFFER_LENGTH = 81;
    public static final int MAX_RILDS = 3;
    public static final int MAX_SOCKET_NAME_LENGTH = 6;
    public static final int MAX_CLIENT_ID_LENGTH = 2;
    public static final int MAX_DEBUG_SOCKET_NAME_LENGTH = 12;
    public static final int MAX_QEMU_PIPE_NAME_LENGTH = 11;
    public static final int MAX_UUID_LENGTH = 64;
    public static final int CARD_MAX_APPS = 8;
    public static final int CDMA_MAX_NUMBER_OF_INFO_RECS = 10;
    public static final int SS_INFO_MAX = 4;
    public static final int NUM_SERVICE_CLASSES = 7;
    public static final int NUM_TX_POWER_LEVELS = 5;
    public static final String toString(int o) {
        if (o == CDMA_ALPHA_INFO_BUFFER_LENGTH) {
            return "CDMA_ALPHA_INFO_BUFFER_LENGTH";
        }
        if (o == CDMA_NUMBER_INFO_BUFFER_LENGTH) {
            return "CDMA_NUMBER_INFO_BUFFER_LENGTH";
        }
        if (o == MAX_RILDS) {
            return "MAX_RILDS";
        }
        if (o == MAX_SOCKET_NAME_LENGTH) {
            return "MAX_SOCKET_NAME_LENGTH";
        }
        if (o == MAX_CLIENT_ID_LENGTH) {
            return "MAX_CLIENT_ID_LENGTH";
        }
        if (o == MAX_DEBUG_SOCKET_NAME_LENGTH) {
            return "MAX_DEBUG_SOCKET_NAME_LENGTH";
        }
        if (o == MAX_QEMU_PIPE_NAME_LENGTH) {
            return "MAX_QEMU_PIPE_NAME_LENGTH";
        }
        if (o == MAX_UUID_LENGTH) {
            return "MAX_UUID_LENGTH";
        }
        if (o == CARD_MAX_APPS) {
            return "CARD_MAX_APPS";
        }
        if (o == CDMA_MAX_NUMBER_OF_INFO_RECS) {
            return "CDMA_MAX_NUMBER_OF_INFO_RECS";
        }
        if (o == SS_INFO_MAX) {
            return "SS_INFO_MAX";
        }
        if (o == NUM_SERVICE_CLASSES) {
            return "NUM_SERVICE_CLASSES";
        }
        if (o == NUM_TX_POWER_LEVELS) {
            return "NUM_TX_POWER_LEVELS";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & CDMA_ALPHA_INFO_BUFFER_LENGTH) == CDMA_ALPHA_INFO_BUFFER_LENGTH) {
            list.add("CDMA_ALPHA_INFO_BUFFER_LENGTH");
            flipped |= CDMA_ALPHA_INFO_BUFFER_LENGTH;
        }
        if ((o & CDMA_NUMBER_INFO_BUFFER_LENGTH) == CDMA_NUMBER_INFO_BUFFER_LENGTH) {
            list.add("CDMA_NUMBER_INFO_BUFFER_LENGTH");
            flipped |= CDMA_NUMBER_INFO_BUFFER_LENGTH;
        }
        if ((o & MAX_RILDS) == MAX_RILDS) {
            list.add("MAX_RILDS");
            flipped |= MAX_RILDS;
        }
        if ((o & MAX_SOCKET_NAME_LENGTH) == MAX_SOCKET_NAME_LENGTH) {
            list.add("MAX_SOCKET_NAME_LENGTH");
            flipped |= MAX_SOCKET_NAME_LENGTH;
        }
        if ((o & MAX_CLIENT_ID_LENGTH) == MAX_CLIENT_ID_LENGTH) {
            list.add("MAX_CLIENT_ID_LENGTH");
            flipped |= MAX_CLIENT_ID_LENGTH;
        }
        if ((o & MAX_DEBUG_SOCKET_NAME_LENGTH) == MAX_DEBUG_SOCKET_NAME_LENGTH) {
            list.add("MAX_DEBUG_SOCKET_NAME_LENGTH");
            flipped |= MAX_DEBUG_SOCKET_NAME_LENGTH;
        }
        if ((o & MAX_QEMU_PIPE_NAME_LENGTH) == MAX_QEMU_PIPE_NAME_LENGTH) {
            list.add("MAX_QEMU_PIPE_NAME_LENGTH");
            flipped |= MAX_QEMU_PIPE_NAME_LENGTH;
        }
        if ((o & MAX_UUID_LENGTH) == MAX_UUID_LENGTH) {
            list.add("MAX_UUID_LENGTH");
            flipped |= MAX_UUID_LENGTH;
        }
        if ((o & CARD_MAX_APPS) == CARD_MAX_APPS) {
            list.add("CARD_MAX_APPS");
            flipped |= CARD_MAX_APPS;
        }
        if ((o & CDMA_MAX_NUMBER_OF_INFO_RECS) == CDMA_MAX_NUMBER_OF_INFO_RECS) {
            list.add("CDMA_MAX_NUMBER_OF_INFO_RECS");
            flipped |= CDMA_MAX_NUMBER_OF_INFO_RECS;
        }
        if ((o & SS_INFO_MAX) == SS_INFO_MAX) {
            list.add("SS_INFO_MAX");
            flipped |= SS_INFO_MAX;
        }
        if ((o & NUM_SERVICE_CLASSES) == NUM_SERVICE_CLASSES) {
            list.add("NUM_SERVICE_CLASSES");
            flipped |= NUM_SERVICE_CLASSES;
        }
        if ((o & NUM_TX_POWER_LEVELS) == NUM_TX_POWER_LEVELS) {
            list.add("NUM_TX_POWER_LEVELS");
            flipped |= NUM_TX_POWER_LEVELS;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

