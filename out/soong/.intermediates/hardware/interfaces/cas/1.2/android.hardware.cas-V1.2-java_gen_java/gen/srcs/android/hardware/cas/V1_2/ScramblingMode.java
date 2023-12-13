package android.hardware.cas.V1_2;


public final class ScramblingMode {
    public static final int RESERVED = 0;
    /**
     * DVB (Digital Video Broadcasting) CSA1 (Common Scrambling Algorithm 1) is
     * the default mode and shall be used when the scrambling descriptor
     * is not present in the program map section. DVB scrambling mode is
     * specified in ETSI EN 300 468 specification.
     */
    public static final int DVB_CSA1 = 1 /* ::android::hardware::cas::V1_2::ScramblingMode.RESERVED implicitly + 1 */;
    public static final int DVB_CSA2 = 2 /* ::android::hardware::cas::V1_2::ScramblingMode.DVB_CSA1 implicitly + 1 */;
    /**
     * DVB-CSA3 in standard mode.
     */
    public static final int DVB_CSA3_STANDARD = 3 /* ::android::hardware::cas::V1_2::ScramblingMode.DVB_CSA2 implicitly + 1 */;
    /**
     * DVB-CSA3 in minimally enhanced mode.
     */
    public static final int DVB_CSA3_MINIMAL = 4 /* ::android::hardware::cas::V1_2::ScramblingMode.DVB_CSA3_STANDARD implicitly + 1 */;
    /**
     * DVB-CSA3 in fully enhanced mode.
     */
    public static final int DVB_CSA3_ENHANCE = 5 /* ::android::hardware::cas::V1_2::ScramblingMode.DVB_CSA3_MINIMAL implicitly + 1 */;
    /**
     * DVB-CISSA version 1.
     */
    public static final int DVB_CISSA_V1 = 6 /* ::android::hardware::cas::V1_2::ScramblingMode.DVB_CSA3_ENHANCE implicitly + 1 */;
    /**
     * ATIS-0800006 IIF Default Scrambling Algorithm (IDSA).
     */
    public static final int DVB_IDSA = 7 /* ::android::hardware::cas::V1_2::ScramblingMode.DVB_CISSA_V1 implicitly + 1 */;
    /**
     * a symmetric key algorithm.
     */
    public static final int MULTI2 = 8 /* ::android::hardware::cas::V1_2::ScramblingMode.DVB_IDSA implicitly + 1 */;
    /**
     * Advanced Encryption System (AES) 128-bit Encryption mode.
     */
    public static final int AES128 = 9 /* ::android::hardware::cas::V1_2::ScramblingMode.MULTI2 implicitly + 1 */;
    /**
     * Advanced Encryption System (AES) Electronic Code Book (ECB) mode.
     */
    public static final int AES_ECB = 10 /* ::android::hardware::cas::V1_2::ScramblingMode.AES128 implicitly + 1 */;
    /**
     * Advanced Encryption System (AES) Society of Cable Telecommunications
     * Engineers (SCTE) 52 mode.
     */
    public static final int AES_SCTE52 = 11 /* ::android::hardware::cas::V1_2::ScramblingMode.AES_ECB implicitly + 1 */;
    /**
     * Triple Data Encryption Algorithm (TDES) Electronic Code Book (ECB) mode.
     */
    public static final int TDES_ECB = 12 /* ::android::hardware::cas::V1_2::ScramblingMode.AES_SCTE52 implicitly + 1 */;
    /**
     * Triple Data Encryption Algorithm (TDES) Society of Cable Telecommunications
     * Engineers (SCTE) 52 mode.
     */
    public static final int TDES_SCTE52 = 13 /* ::android::hardware::cas::V1_2::ScramblingMode.TDES_ECB implicitly + 1 */;
    public static final String toString(int o) {
        if (o == RESERVED) {
            return "RESERVED";
        }
        if (o == DVB_CSA1) {
            return "DVB_CSA1";
        }
        if (o == DVB_CSA2) {
            return "DVB_CSA2";
        }
        if (o == DVB_CSA3_STANDARD) {
            return "DVB_CSA3_STANDARD";
        }
        if (o == DVB_CSA3_MINIMAL) {
            return "DVB_CSA3_MINIMAL";
        }
        if (o == DVB_CSA3_ENHANCE) {
            return "DVB_CSA3_ENHANCE";
        }
        if (o == DVB_CISSA_V1) {
            return "DVB_CISSA_V1";
        }
        if (o == DVB_IDSA) {
            return "DVB_IDSA";
        }
        if (o == MULTI2) {
            return "MULTI2";
        }
        if (o == AES128) {
            return "AES128";
        }
        if (o == AES_ECB) {
            return "AES_ECB";
        }
        if (o == AES_SCTE52) {
            return "AES_SCTE52";
        }
        if (o == TDES_ECB) {
            return "TDES_ECB";
        }
        if (o == TDES_SCTE52) {
            return "TDES_SCTE52";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("RESERVED"); // RESERVED == 0
        if ((o & DVB_CSA1) == DVB_CSA1) {
            list.add("DVB_CSA1");
            flipped |= DVB_CSA1;
        }
        if ((o & DVB_CSA2) == DVB_CSA2) {
            list.add("DVB_CSA2");
            flipped |= DVB_CSA2;
        }
        if ((o & DVB_CSA3_STANDARD) == DVB_CSA3_STANDARD) {
            list.add("DVB_CSA3_STANDARD");
            flipped |= DVB_CSA3_STANDARD;
        }
        if ((o & DVB_CSA3_MINIMAL) == DVB_CSA3_MINIMAL) {
            list.add("DVB_CSA3_MINIMAL");
            flipped |= DVB_CSA3_MINIMAL;
        }
        if ((o & DVB_CSA3_ENHANCE) == DVB_CSA3_ENHANCE) {
            list.add("DVB_CSA3_ENHANCE");
            flipped |= DVB_CSA3_ENHANCE;
        }
        if ((o & DVB_CISSA_V1) == DVB_CISSA_V1) {
            list.add("DVB_CISSA_V1");
            flipped |= DVB_CISSA_V1;
        }
        if ((o & DVB_IDSA) == DVB_IDSA) {
            list.add("DVB_IDSA");
            flipped |= DVB_IDSA;
        }
        if ((o & MULTI2) == MULTI2) {
            list.add("MULTI2");
            flipped |= MULTI2;
        }
        if ((o & AES128) == AES128) {
            list.add("AES128");
            flipped |= AES128;
        }
        if ((o & AES_ECB) == AES_ECB) {
            list.add("AES_ECB");
            flipped |= AES_ECB;
        }
        if ((o & AES_SCTE52) == AES_SCTE52) {
            list.add("AES_SCTE52");
            flipped |= AES_SCTE52;
        }
        if ((o & TDES_ECB) == TDES_ECB) {
            list.add("TDES_ECB");
            flipped |= TDES_ECB;
        }
        if ((o & TDES_SCTE52) == TDES_SCTE52) {
            list.add("TDES_SCTE52");
            flipped |= TDES_SCTE52;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

