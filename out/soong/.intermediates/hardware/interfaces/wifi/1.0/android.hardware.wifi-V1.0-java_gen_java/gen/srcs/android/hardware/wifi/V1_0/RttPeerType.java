package android.hardware.wifi.V1_0;


public final class RttPeerType {
    public static final int AP = 1 /* 0x1 */;
    public static final int STA = 2 /* 0x2 */;
    public static final int P2P_GO = 3 /* 0x3 */;
    public static final int P2P_CLIENT = 4 /* 0x4 */;
    public static final int NAN = 5 /* 0x5 */;
    public static final String toString(int o) {
        if (o == AP) {
            return "AP";
        }
        if (o == STA) {
            return "STA";
        }
        if (o == P2P_GO) {
            return "P2P_GO";
        }
        if (o == P2P_CLIENT) {
            return "P2P_CLIENT";
        }
        if (o == NAN) {
            return "NAN";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & AP) == AP) {
            list.add("AP");
            flipped |= AP;
        }
        if ((o & STA) == STA) {
            list.add("STA");
            flipped |= STA;
        }
        if ((o & P2P_GO) == P2P_GO) {
            list.add("P2P_GO");
            flipped |= P2P_GO;
        }
        if ((o & P2P_CLIENT) == P2P_CLIENT) {
            list.add("P2P_CLIENT");
            flipped |= P2P_CLIENT;
        }
        if ((o & NAN) == NAN) {
            list.add("NAN");
            flipped |= NAN;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

