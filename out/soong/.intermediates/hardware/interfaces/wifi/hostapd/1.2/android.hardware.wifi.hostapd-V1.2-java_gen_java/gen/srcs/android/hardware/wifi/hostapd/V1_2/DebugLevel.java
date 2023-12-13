package android.hardware.wifi.hostapd.V1_2;


public final class DebugLevel {
    public static final int EXCESSIVE = 0;
    public static final int MSGDUMP = 1;
    public static final int DEBUG = 2;
    public static final int INFO = 3;
    public static final int WARNING = 4;
    public static final int ERROR = 5;
    public static final String toString(int o) {
        if (o == EXCESSIVE) {
            return "EXCESSIVE";
        }
        if (o == MSGDUMP) {
            return "MSGDUMP";
        }
        if (o == DEBUG) {
            return "DEBUG";
        }
        if (o == INFO) {
            return "INFO";
        }
        if (o == WARNING) {
            return "WARNING";
        }
        if (o == ERROR) {
            return "ERROR";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("EXCESSIVE"); // EXCESSIVE == 0
        if ((o & MSGDUMP) == MSGDUMP) {
            list.add("MSGDUMP");
            flipped |= MSGDUMP;
        }
        if ((o & DEBUG) == DEBUG) {
            list.add("DEBUG");
            flipped |= DEBUG;
        }
        if ((o & INFO) == INFO) {
            list.add("INFO");
            flipped |= INFO;
        }
        if ((o & WARNING) == WARNING) {
            list.add("WARNING");
            flipped |= WARNING;
        }
        if ((o & ERROR) == ERROR) {
            list.add("ERROR");
            flipped |= ERROR;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

