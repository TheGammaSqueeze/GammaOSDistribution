package android.hardware.gnss.V1_0;


public final class GnssConstellationType {
    public static final byte UNKNOWN = 0;
    public static final byte GPS = 1;
    public static final byte SBAS = 2;
    public static final byte GLONASS = 3;
    public static final byte QZSS = 4;
    public static final byte BEIDOU = 5;
    public static final byte GALILEO = 6;
    public static final String toString(byte o) {
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        if (o == GPS) {
            return "GPS";
        }
        if (o == SBAS) {
            return "SBAS";
        }
        if (o == GLONASS) {
            return "GLONASS";
        }
        if (o == QZSS) {
            return "QZSS";
        }
        if (o == BEIDOU) {
            return "BEIDOU";
        }
        if (o == GALILEO) {
            return "GALILEO";
        }
        return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
    }

    public static final String dumpBitfield(byte o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        byte flipped = 0;
        list.add("UNKNOWN"); // UNKNOWN == 0
        if ((o & GPS) == GPS) {
            list.add("GPS");
            flipped |= GPS;
        }
        if ((o & SBAS) == SBAS) {
            list.add("SBAS");
            flipped |= SBAS;
        }
        if ((o & GLONASS) == GLONASS) {
            list.add("GLONASS");
            flipped |= GLONASS;
        }
        if ((o & QZSS) == QZSS) {
            list.add("QZSS");
            flipped |= QZSS;
        }
        if ((o & BEIDOU) == BEIDOU) {
            list.add("BEIDOU");
            flipped |= BEIDOU;
        }
        if ((o & GALILEO) == GALILEO) {
            list.add("GALILEO");
            flipped |= GALILEO;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

