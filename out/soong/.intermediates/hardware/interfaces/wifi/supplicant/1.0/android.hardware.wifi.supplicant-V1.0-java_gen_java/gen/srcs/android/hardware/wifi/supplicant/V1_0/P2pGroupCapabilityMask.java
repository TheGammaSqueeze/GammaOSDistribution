package android.hardware.wifi.supplicant.V1_0;


public final class P2pGroupCapabilityMask {
    public static final int GROUP_OWNER = 1 /* 1 << 0 */;
    public static final int PERSISTENT_GROUP = 2 /* 1 << 1 */;
    public static final int GROUP_LIMIT = 4 /* 1 << 2 */;
    public static final int INTRA_BSS_DIST = 8 /* 1 << 3 */;
    public static final int CROSS_CONN = 16 /* 1 << 4 */;
    public static final int PERSISTENT_RECONN = 32 /* 1 << 5 */;
    public static final int GROUP_FORMATION = 64 /* 1 << 6 */;
    public static final String toString(int o) {
        if (o == GROUP_OWNER) {
            return "GROUP_OWNER";
        }
        if (o == PERSISTENT_GROUP) {
            return "PERSISTENT_GROUP";
        }
        if (o == GROUP_LIMIT) {
            return "GROUP_LIMIT";
        }
        if (o == INTRA_BSS_DIST) {
            return "INTRA_BSS_DIST";
        }
        if (o == CROSS_CONN) {
            return "CROSS_CONN";
        }
        if (o == PERSISTENT_RECONN) {
            return "PERSISTENT_RECONN";
        }
        if (o == GROUP_FORMATION) {
            return "GROUP_FORMATION";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & GROUP_OWNER) == GROUP_OWNER) {
            list.add("GROUP_OWNER");
            flipped |= GROUP_OWNER;
        }
        if ((o & PERSISTENT_GROUP) == PERSISTENT_GROUP) {
            list.add("PERSISTENT_GROUP");
            flipped |= PERSISTENT_GROUP;
        }
        if ((o & GROUP_LIMIT) == GROUP_LIMIT) {
            list.add("GROUP_LIMIT");
            flipped |= GROUP_LIMIT;
        }
        if ((o & INTRA_BSS_DIST) == INTRA_BSS_DIST) {
            list.add("INTRA_BSS_DIST");
            flipped |= INTRA_BSS_DIST;
        }
        if ((o & CROSS_CONN) == CROSS_CONN) {
            list.add("CROSS_CONN");
            flipped |= CROSS_CONN;
        }
        if ((o & PERSISTENT_RECONN) == PERSISTENT_RECONN) {
            list.add("PERSISTENT_RECONN");
            flipped |= PERSISTENT_RECONN;
        }
        if ((o & GROUP_FORMATION) == GROUP_FORMATION) {
            list.add("GROUP_FORMATION");
            flipped |= GROUP_FORMATION;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

