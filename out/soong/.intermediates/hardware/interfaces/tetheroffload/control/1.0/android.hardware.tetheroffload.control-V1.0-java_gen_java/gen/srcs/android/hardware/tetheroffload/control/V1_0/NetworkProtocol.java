package android.hardware.tetheroffload.control.V1_0;


public final class NetworkProtocol {
    public static final int TCP = 6;
    public static final int UDP = 17;
    public static final String toString(int o) {
        if (o == TCP) {
            return "TCP";
        }
        if (o == UDP) {
            return "UDP";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & TCP) == TCP) {
            list.add("TCP");
            flipped |= TCP;
        }
        if ((o & UDP) == UDP) {
            list.add("UDP");
            flipped |= UDP;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

