package android.hardware.broadcastradio.V2_0;


public final class Rds {
    /**
     * Standard variant, used everywhere except North America.
     */
    public static final byte RDS = 1 /* 1 << 0 */;
    /**
     * Variant used in North America.
     */
    public static final byte RBDS = 2 /* 1 << 1 */;
    public static final String toString(byte o) {
        if (o == RDS) {
            return "RDS";
        }
        if (o == RBDS) {
            return "RBDS";
        }
        return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
    }

    public static final String dumpBitfield(byte o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        byte flipped = 0;
        if ((o & RDS) == RDS) {
            list.add("RDS");
            flipped |= RDS;
        }
        if ((o & RBDS) == RBDS) {
            list.add("RBDS");
            flipped |= RBDS;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

