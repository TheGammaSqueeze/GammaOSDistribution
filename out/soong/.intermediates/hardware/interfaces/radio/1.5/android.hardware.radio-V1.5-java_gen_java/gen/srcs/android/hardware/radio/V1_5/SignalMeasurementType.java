package android.hardware.radio.V1_5;


public final class SignalMeasurementType {
    /**
     * Received Signal Strength Indication.
     * Range: -113 dBm and -51 dBm
     * Used RAN: GERAN, CDMA2000
     * Reference: 3GPP TS 27.007 section 8.5.
     */
    public static final int RSSI = 1;
    /**
     * Received Signal Code Power.
     * Range: -120 dBm to -25 dBm;
     * Used RAN: UTRAN
     * Reference: 3GPP TS 25.123, section 9.1.1.1
     */
    public static final int RSCP = 2;
    /**
     * Reference Signal Received Power.
     * Range: -140 dBm to -44 dBm;
     * Used RAN: EUTRAN
     * Reference: 3GPP TS 36.133 9.1.4
     */
    public static final int RSRP = 3;
    /**
     * Reference Signal Received Quality
     * Range: -34 dB to 3 dB;
     * Used RAN: EUTRAN
     * Reference: 3GPP TS 36.133 v12.6.0 section 9.1.7
     */
    public static final int RSRQ = 4;
    /**
     * Reference Signal Signal to Noise Ratio
     * Range: -20 dB to 30 dB;
     * Used RAN: EUTRAN
     * Note: this field is optional; how to support it can be decided by the
     * corresponding vendor. Though the response code is not enforced,
     * vendor's implementation must ensure this interface not crashing.
     */
    public static final int RSSNR = 5;
    /**
     * 5G SS reference signal received power.
     * Range: -140 dBm to -44 dBm.
     * Used RAN: NGRAN
     * Reference: 3GPP TS 38.215.
     */
    public static final int SSRSRP = 6;
    /**
     * 5G SS reference signal received quality.
     * Range: -43 dB to 20 dB.
     * Used RAN: NGRAN
     * Reference: 3GPP TS 38.215, 3GPP TS 38.133 section 10
     */
    public static final int SSRSRQ = 7;
    /**
     * 5G SS signal-to-noise and interference ratio.
     * Range: -23 dB to 40 dB
     * Used RAN: NGRAN
     * Reference: 3GPP TS 38.215 section 5.1.*, 3GPP TS 38.133 section 10.1.16.1.
     */
    public static final int SSSINR = 8;
    public static final String toString(int o) {
        if (o == RSSI) {
            return "RSSI";
        }
        if (o == RSCP) {
            return "RSCP";
        }
        if (o == RSRP) {
            return "RSRP";
        }
        if (o == RSRQ) {
            return "RSRQ";
        }
        if (o == RSSNR) {
            return "RSSNR";
        }
        if (o == SSRSRP) {
            return "SSRSRP";
        }
        if (o == SSRSRQ) {
            return "SSRSRQ";
        }
        if (o == SSSINR) {
            return "SSSINR";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & RSSI) == RSSI) {
            list.add("RSSI");
            flipped |= RSSI;
        }
        if ((o & RSCP) == RSCP) {
            list.add("RSCP");
            flipped |= RSCP;
        }
        if ((o & RSRP) == RSRP) {
            list.add("RSRP");
            flipped |= RSRP;
        }
        if ((o & RSRQ) == RSRQ) {
            list.add("RSRQ");
            flipped |= RSRQ;
        }
        if ((o & RSSNR) == RSSNR) {
            list.add("RSSNR");
            flipped |= RSSNR;
        }
        if ((o & SSRSRP) == SSRSRP) {
            list.add("SSRSRP");
            flipped |= SSRSRP;
        }
        if ((o & SSRSRQ) == SSRSRQ) {
            list.add("SSRSRQ");
            flipped |= SSRSRQ;
        }
        if ((o & SSSINR) == SSSINR) {
            list.add("SSSINR");
            flipped |= SSSINR;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

