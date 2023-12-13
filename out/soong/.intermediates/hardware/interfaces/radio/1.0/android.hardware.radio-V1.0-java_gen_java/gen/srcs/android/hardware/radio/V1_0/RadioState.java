package android.hardware.radio.V1_0;


public final class RadioState {
    public static final int OFF = 0;
    public static final int UNAVAILABLE = 1;
    public static final int ON = 10;
    public static final String toString(int o) {
        if (o == OFF) {
            return "OFF";
        }
        if (o == UNAVAILABLE) {
            return "UNAVAILABLE";
        }
        if (o == ON) {
            return "ON";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("OFF"); // OFF == 0
        if ((o & UNAVAILABLE) == UNAVAILABLE) {
            list.add("UNAVAILABLE");
            flipped |= UNAVAILABLE;
        }
        if ((o & ON) == ON) {
            list.add("ON");
            flipped |= ON;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

