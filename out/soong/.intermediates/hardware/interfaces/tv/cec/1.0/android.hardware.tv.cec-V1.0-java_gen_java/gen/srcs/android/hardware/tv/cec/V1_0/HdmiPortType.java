package android.hardware.tv.cec.V1_0;


public final class HdmiPortType {
    public static final int INPUT = 0;
    public static final int OUTPUT = 1;
    public static final String toString(int o) {
        if (o == INPUT) {
            return "INPUT";
        }
        if (o == OUTPUT) {
            return "OUTPUT";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("INPUT"); // INPUT == 0
        if ((o & OUTPUT) == OUTPUT) {
            list.add("OUTPUT");
            flipped |= OUTPUT;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

