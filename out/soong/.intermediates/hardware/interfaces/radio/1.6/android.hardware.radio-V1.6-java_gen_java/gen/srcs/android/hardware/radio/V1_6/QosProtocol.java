package android.hardware.radio.V1_6;


public final class QosProtocol {
    /**
     * No protocol specified
     */
    public static final byte UNSPECIFIED = -1 /* -1 */;
    /**
     * Transmission Control Protocol
     */
    public static final byte TCP = 6;
    /**
     * User Datagram Protocol
     */
    public static final byte UDP = 17;
    /**
     * Encapsulating Security Payload Protocol
     */
    public static final byte ESP = 50;
    /**
     * Authentication Header
     */
    public static final byte AH = 51;
    public static final String toString(byte o) {
        if (o == UNSPECIFIED) {
            return "UNSPECIFIED";
        }
        if (o == TCP) {
            return "TCP";
        }
        if (o == UDP) {
            return "UDP";
        }
        if (o == ESP) {
            return "ESP";
        }
        if (o == AH) {
            return "AH";
        }
        return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
    }

    public static final String dumpBitfield(byte o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        byte flipped = 0;
        if ((o & UNSPECIFIED) == UNSPECIFIED) {
            list.add("UNSPECIFIED");
            flipped |= UNSPECIFIED;
        }
        if ((o & TCP) == TCP) {
            list.add("TCP");
            flipped |= TCP;
        }
        if ((o & UDP) == UDP) {
            list.add("UDP");
            flipped |= UDP;
        }
        if ((o & ESP) == ESP) {
            list.add("ESP");
            flipped |= ESP;
        }
        if ((o & AH) == AH) {
            list.add("AH");
            flipped |= AH;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

