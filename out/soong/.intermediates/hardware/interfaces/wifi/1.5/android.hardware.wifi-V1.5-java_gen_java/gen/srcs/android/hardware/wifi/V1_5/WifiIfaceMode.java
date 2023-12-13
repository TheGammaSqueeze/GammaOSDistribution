package android.hardware.wifi.V1_5;


public final class WifiIfaceMode {
    /**
     * Interface operation mode is client.
     */
    public static final int IFACE_MODE_STA = 1 /* 1 << 0 */;
    /**
     * Interface operation mode is Hotspot.
     */
    public static final int IFACE_MODE_SOFTAP = 2 /* 1 << 1 */;
    /**
     * Interface operation mode is Ad-Hoc network.
     */
    public static final int IFACE_MODE_IBSS = 4 /* 1 << 2 */;
    /**
     * Interface operation mode is Wifi Direct Client.
     */
    public static final int IFACE_MODE_P2P_CLIENT = 8 /* 1 << 3 */;
    /**
     * Interface operation mode is Wifi Direct Group Owner.
     */
    public static final int IFACE_MODE_P2P_GO = 16 /* 1 << 4 */;
    /**
     * Interface operation mode is Aware.
     */
    public static final int IFACE_MODE_NAN = 32 /* 1 << 5 */;
    /**
     * Interface operation mode is Mesh network.
     */
    public static final int IFACE_MODE_MESH = 64 /* 1 << 6 */;
    /**
     * Interface operation mode is Tunneled Direct Link Setup.
     */
    public static final int IFACE_MODE_TDLS = 128 /* 1 << 7 */;
    public static final String toString(int o) {
        if (o == IFACE_MODE_STA) {
            return "IFACE_MODE_STA";
        }
        if (o == IFACE_MODE_SOFTAP) {
            return "IFACE_MODE_SOFTAP";
        }
        if (o == IFACE_MODE_IBSS) {
            return "IFACE_MODE_IBSS";
        }
        if (o == IFACE_MODE_P2P_CLIENT) {
            return "IFACE_MODE_P2P_CLIENT";
        }
        if (o == IFACE_MODE_P2P_GO) {
            return "IFACE_MODE_P2P_GO";
        }
        if (o == IFACE_MODE_NAN) {
            return "IFACE_MODE_NAN";
        }
        if (o == IFACE_MODE_MESH) {
            return "IFACE_MODE_MESH";
        }
        if (o == IFACE_MODE_TDLS) {
            return "IFACE_MODE_TDLS";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & IFACE_MODE_STA) == IFACE_MODE_STA) {
            list.add("IFACE_MODE_STA");
            flipped |= IFACE_MODE_STA;
        }
        if ((o & IFACE_MODE_SOFTAP) == IFACE_MODE_SOFTAP) {
            list.add("IFACE_MODE_SOFTAP");
            flipped |= IFACE_MODE_SOFTAP;
        }
        if ((o & IFACE_MODE_IBSS) == IFACE_MODE_IBSS) {
            list.add("IFACE_MODE_IBSS");
            flipped |= IFACE_MODE_IBSS;
        }
        if ((o & IFACE_MODE_P2P_CLIENT) == IFACE_MODE_P2P_CLIENT) {
            list.add("IFACE_MODE_P2P_CLIENT");
            flipped |= IFACE_MODE_P2P_CLIENT;
        }
        if ((o & IFACE_MODE_P2P_GO) == IFACE_MODE_P2P_GO) {
            list.add("IFACE_MODE_P2P_GO");
            flipped |= IFACE_MODE_P2P_GO;
        }
        if ((o & IFACE_MODE_NAN) == IFACE_MODE_NAN) {
            list.add("IFACE_MODE_NAN");
            flipped |= IFACE_MODE_NAN;
        }
        if ((o & IFACE_MODE_MESH) == IFACE_MODE_MESH) {
            list.add("IFACE_MODE_MESH");
            flipped |= IFACE_MODE_MESH;
        }
        if ((o & IFACE_MODE_TDLS) == IFACE_MODE_TDLS) {
            list.add("IFACE_MODE_TDLS");
            flipped |= IFACE_MODE_TDLS;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

