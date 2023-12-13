package android.hardware.radio.V1_4;


public final class PdpProtocolType {
    /**
     * Unknown protocol
     */
    public static final int UNKNOWN = -1 /* -1 */;
    /**
     * Internet protocol
     */
    public static final int IP = 0;
    /**
     * Internet protocol, version 6
     */
    public static final int IPV6 = 1;
    /**
     * Virtual PDP type introduced to handle dual IP stack UE capability.
     */
    public static final int IPV4V6 = 2;
    /**
     * Point to point protocol
     */
    public static final int PPP = 3;
    /**
     * Transfer of Non-IP data to external packet data network
     */
    public static final int NON_IP = 4;
    /**
     * Transfer of Unstructured data to the Data Network via N6
     */
    public static final int UNSTRUCTURED = 5;
    public static final String toString(int o) {
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        if (o == IP) {
            return "IP";
        }
        if (o == IPV6) {
            return "IPV6";
        }
        if (o == IPV4V6) {
            return "IPV4V6";
        }
        if (o == PPP) {
            return "PPP";
        }
        if (o == NON_IP) {
            return "NON_IP";
        }
        if (o == UNSTRUCTURED) {
            return "UNSTRUCTURED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & UNKNOWN) == UNKNOWN) {
            list.add("UNKNOWN");
            flipped |= UNKNOWN;
        }
        list.add("IP"); // IP == 0
        if ((o & IPV6) == IPV6) {
            list.add("IPV6");
            flipped |= IPV6;
        }
        if ((o & IPV4V6) == IPV4V6) {
            list.add("IPV4V6");
            flipped |= IPV4V6;
        }
        if ((o & PPP) == PPP) {
            list.add("PPP");
            flipped |= PPP;
        }
        if ((o & NON_IP) == NON_IP) {
            list.add("NON_IP");
            flipped |= NON_IP;
        }
        if ((o & UNSTRUCTURED) == UNSTRUCTURED) {
            list.add("UNSTRUCTURED");
            flipped |= UNSTRUCTURED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

