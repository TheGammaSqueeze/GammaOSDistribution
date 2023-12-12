package android.hardware.audio.common.V2_0;


public final class AudioFormat {
    public static final int INVALID = -1 /* 0xFFFFFFFFUL */;
    public static final int DEFAULT = 0;
    public static final int PCM = 0 /* 0x00000000UL */;
    /**
     * DO NOT CHANGE
     */
    public static final int MP3 = 16777216 /* 0x01000000UL */;
    public static final int AMR_NB = 33554432 /* 0x02000000UL */;
    public static final int AMR_WB = 50331648 /* 0x03000000UL */;
    public static final int AAC = 67108864 /* 0x04000000UL */;
    public static final int HE_AAC_V1 = 83886080 /* 0x05000000UL */;
    /**
     * Deprecated, Use AAC_HE_V1
     */
    public static final int HE_AAC_V2 = 100663296 /* 0x06000000UL */;
    /**
     * Deprecated, Use AAC_HE_V2
     */
    public static final int VORBIS = 117440512 /* 0x07000000UL */;
    public static final int OPUS = 134217728 /* 0x08000000UL */;
    public static final int AC3 = 150994944 /* 0x09000000UL */;
    public static final int E_AC3 = 167772160 /* 0x0A000000UL */;
    public static final int DTS = 184549376 /* 0x0B000000UL */;
    public static final int DTS_HD = 201326592 /* 0x0C000000UL */;
    public static final int IEC61937 = 218103808 /* 0x0D000000UL */;
    public static final int DOLBY_TRUEHD = 234881024 /* 0x0E000000UL */;
    public static final int EVRC = 268435456 /* 0x10000000UL */;
    public static final int EVRCB = 285212672 /* 0x11000000UL */;
    public static final int EVRCWB = 301989888 /* 0x12000000UL */;
    public static final int EVRCNW = 318767104 /* 0x13000000UL */;
    public static final int AAC_ADIF = 335544320 /* 0x14000000UL */;
    public static final int WMA = 352321536 /* 0x15000000UL */;
    public static final int WMA_PRO = 369098752 /* 0x16000000UL */;
    public static final int AMR_WB_PLUS = 385875968 /* 0x17000000UL */;
    public static final int MP2 = 402653184 /* 0x18000000UL */;
    public static final int QCELP = 419430400 /* 0x19000000UL */;
    public static final int DSD = 436207616 /* 0x1A000000UL */;
    public static final int FLAC = 452984832 /* 0x1B000000UL */;
    public static final int ALAC = 469762048 /* 0x1C000000UL */;
    public static final int APE = 486539264 /* 0x1D000000UL */;
    public static final int AAC_ADTS = 503316480 /* 0x1E000000UL */;
    public static final int SBC = 520093696 /* 0x1F000000UL */;
    public static final int APTX = 536870912 /* 0x20000000UL */;
    public static final int APTX_HD = 553648128 /* 0x21000000UL */;
    public static final int AC4 = 570425344 /* 0x22000000UL */;
    public static final int LDAC = 587202560 /* 0x23000000UL */;
    public static final int MAIN_MASK = -16777216 /* 0xFF000000UL */;
    /**
     * Deprecated
     */
    public static final int SUB_MASK = 16777215 /* 0x00FFFFFFUL */;
    /**
     * Subformats
     */
    public static final int PCM_SUB_16_BIT = 1 /* 0x1 */;
    public static final int PCM_SUB_8_BIT = 2 /* 0x2 */;
    public static final int PCM_SUB_32_BIT = 3 /* 0x3 */;
    public static final int PCM_SUB_8_24_BIT = 4 /* 0x4 */;
    public static final int PCM_SUB_FLOAT = 5 /* 0x5 */;
    public static final int PCM_SUB_24_BIT_PACKED = 6 /* 0x6 */;
    public static final int MP3_SUB_NONE = 0 /* 0x0 */;
    public static final int AMR_SUB_NONE = 0 /* 0x0 */;
    public static final int AAC_SUB_MAIN = 1 /* 0x1 */;
    public static final int AAC_SUB_LC = 2 /* 0x2 */;
    public static final int AAC_SUB_SSR = 4 /* 0x4 */;
    public static final int AAC_SUB_LTP = 8 /* 0x8 */;
    public static final int AAC_SUB_HE_V1 = 16 /* 0x10 */;
    public static final int AAC_SUB_SCALABLE = 32 /* 0x20 */;
    public static final int AAC_SUB_ERLC = 64 /* 0x40 */;
    public static final int AAC_SUB_LD = 128 /* 0x80 */;
    public static final int AAC_SUB_HE_V2 = 256 /* 0x100 */;
    public static final int AAC_SUB_ELD = 512 /* 0x200 */;
    public static final int VORBIS_SUB_NONE = 0 /* 0x0 */;
    /**
     * Aliases
     *
     *
     * note != AudioFormat.ENCODING_PCM_16BIT
     */
    public static final int PCM_16_BIT = 1 /* (PCM | PCM_SUB_16_BIT) */;
    /**
     * note != AudioFormat.ENCODING_PCM_8BIT
     */
    public static final int PCM_8_BIT = 2 /* (PCM | PCM_SUB_8_BIT) */;
    public static final int PCM_32_BIT = 3 /* (PCM | PCM_SUB_32_BIT) */;
    public static final int PCM_8_24_BIT = 4 /* (PCM | PCM_SUB_8_24_BIT) */;
    public static final int PCM_FLOAT = 5 /* (PCM | PCM_SUB_FLOAT) */;
    public static final int PCM_24_BIT_PACKED = 6 /* (PCM | PCM_SUB_24_BIT_PACKED) */;
    public static final int AAC_MAIN = 67108865 /* (AAC | AAC_SUB_MAIN) */;
    public static final int AAC_LC = 67108866 /* (AAC | AAC_SUB_LC) */;
    public static final int AAC_SSR = 67108868 /* (AAC | AAC_SUB_SSR) */;
    public static final int AAC_LTP = 67108872 /* (AAC | AAC_SUB_LTP) */;
    public static final int AAC_HE_V1 = 67108880 /* (AAC | AAC_SUB_HE_V1) */;
    public static final int AAC_SCALABLE = 67108896 /* (AAC | AAC_SUB_SCALABLE) */;
    public static final int AAC_ERLC = 67108928 /* (AAC | AAC_SUB_ERLC) */;
    public static final int AAC_LD = 67108992 /* (AAC | AAC_SUB_LD) */;
    public static final int AAC_HE_V2 = 67109120 /* (AAC | AAC_SUB_HE_V2) */;
    public static final int AAC_ELD = 67109376 /* (AAC | AAC_SUB_ELD) */;
    public static final int AAC_ADTS_MAIN = 503316481 /* (AAC_ADTS | AAC_SUB_MAIN) */;
    public static final int AAC_ADTS_LC = 503316482 /* (AAC_ADTS | AAC_SUB_LC) */;
    public static final int AAC_ADTS_SSR = 503316484 /* (AAC_ADTS | AAC_SUB_SSR) */;
    public static final int AAC_ADTS_LTP = 503316488 /* (AAC_ADTS | AAC_SUB_LTP) */;
    public static final int AAC_ADTS_HE_V1 = 503316496 /* (AAC_ADTS | AAC_SUB_HE_V1) */;
    public static final int AAC_ADTS_SCALABLE = 503316512 /* (AAC_ADTS | AAC_SUB_SCALABLE) */;
    public static final int AAC_ADTS_ERLC = 503316544 /* (AAC_ADTS | AAC_SUB_ERLC) */;
    public static final int AAC_ADTS_LD = 503316608 /* (AAC_ADTS | AAC_SUB_LD) */;
    public static final int AAC_ADTS_HE_V2 = 503316736 /* (AAC_ADTS | AAC_SUB_HE_V2) */;
    public static final int AAC_ADTS_ELD = 503316992 /* (AAC_ADTS | AAC_SUB_ELD) */;
    public static final String toString(int o) {
        if (o == INVALID) {
            return "INVALID";
        }
        if (o == DEFAULT) {
            return "DEFAULT";
        }
        if (o == PCM) {
            return "PCM";
        }
        if (o == MP3) {
            return "MP3";
        }
        if (o == AMR_NB) {
            return "AMR_NB";
        }
        if (o == AMR_WB) {
            return "AMR_WB";
        }
        if (o == AAC) {
            return "AAC";
        }
        if (o == HE_AAC_V1) {
            return "HE_AAC_V1";
        }
        if (o == HE_AAC_V2) {
            return "HE_AAC_V2";
        }
        if (o == VORBIS) {
            return "VORBIS";
        }
        if (o == OPUS) {
            return "OPUS";
        }
        if (o == AC3) {
            return "AC3";
        }
        if (o == E_AC3) {
            return "E_AC3";
        }
        if (o == DTS) {
            return "DTS";
        }
        if (o == DTS_HD) {
            return "DTS_HD";
        }
        if (o == IEC61937) {
            return "IEC61937";
        }
        if (o == DOLBY_TRUEHD) {
            return "DOLBY_TRUEHD";
        }
        if (o == EVRC) {
            return "EVRC";
        }
        if (o == EVRCB) {
            return "EVRCB";
        }
        if (o == EVRCWB) {
            return "EVRCWB";
        }
        if (o == EVRCNW) {
            return "EVRCNW";
        }
        if (o == AAC_ADIF) {
            return "AAC_ADIF";
        }
        if (o == WMA) {
            return "WMA";
        }
        if (o == WMA_PRO) {
            return "WMA_PRO";
        }
        if (o == AMR_WB_PLUS) {
            return "AMR_WB_PLUS";
        }
        if (o == MP2) {
            return "MP2";
        }
        if (o == QCELP) {
            return "QCELP";
        }
        if (o == DSD) {
            return "DSD";
        }
        if (o == FLAC) {
            return "FLAC";
        }
        if (o == ALAC) {
            return "ALAC";
        }
        if (o == APE) {
            return "APE";
        }
        if (o == AAC_ADTS) {
            return "AAC_ADTS";
        }
        if (o == SBC) {
            return "SBC";
        }
        if (o == APTX) {
            return "APTX";
        }
        if (o == APTX_HD) {
            return "APTX_HD";
        }
        if (o == AC4) {
            return "AC4";
        }
        if (o == LDAC) {
            return "LDAC";
        }
        if (o == MAIN_MASK) {
            return "MAIN_MASK";
        }
        if (o == SUB_MASK) {
            return "SUB_MASK";
        }
        if (o == PCM_SUB_16_BIT) {
            return "PCM_SUB_16_BIT";
        }
        if (o == PCM_SUB_8_BIT) {
            return "PCM_SUB_8_BIT";
        }
        if (o == PCM_SUB_32_BIT) {
            return "PCM_SUB_32_BIT";
        }
        if (o == PCM_SUB_8_24_BIT) {
            return "PCM_SUB_8_24_BIT";
        }
        if (o == PCM_SUB_FLOAT) {
            return "PCM_SUB_FLOAT";
        }
        if (o == PCM_SUB_24_BIT_PACKED) {
            return "PCM_SUB_24_BIT_PACKED";
        }
        if (o == MP3_SUB_NONE) {
            return "MP3_SUB_NONE";
        }
        if (o == AMR_SUB_NONE) {
            return "AMR_SUB_NONE";
        }
        if (o == AAC_SUB_MAIN) {
            return "AAC_SUB_MAIN";
        }
        if (o == AAC_SUB_LC) {
            return "AAC_SUB_LC";
        }
        if (o == AAC_SUB_SSR) {
            return "AAC_SUB_SSR";
        }
        if (o == AAC_SUB_LTP) {
            return "AAC_SUB_LTP";
        }
        if (o == AAC_SUB_HE_V1) {
            return "AAC_SUB_HE_V1";
        }
        if (o == AAC_SUB_SCALABLE) {
            return "AAC_SUB_SCALABLE";
        }
        if (o == AAC_SUB_ERLC) {
            return "AAC_SUB_ERLC";
        }
        if (o == AAC_SUB_LD) {
            return "AAC_SUB_LD";
        }
        if (o == AAC_SUB_HE_V2) {
            return "AAC_SUB_HE_V2";
        }
        if (o == AAC_SUB_ELD) {
            return "AAC_SUB_ELD";
        }
        if (o == VORBIS_SUB_NONE) {
            return "VORBIS_SUB_NONE";
        }
        if (o == PCM_16_BIT) {
            return "PCM_16_BIT";
        }
        if (o == PCM_8_BIT) {
            return "PCM_8_BIT";
        }
        if (o == PCM_32_BIT) {
            return "PCM_32_BIT";
        }
        if (o == PCM_8_24_BIT) {
            return "PCM_8_24_BIT";
        }
        if (o == PCM_FLOAT) {
            return "PCM_FLOAT";
        }
        if (o == PCM_24_BIT_PACKED) {
            return "PCM_24_BIT_PACKED";
        }
        if (o == AAC_MAIN) {
            return "AAC_MAIN";
        }
        if (o == AAC_LC) {
            return "AAC_LC";
        }
        if (o == AAC_SSR) {
            return "AAC_SSR";
        }
        if (o == AAC_LTP) {
            return "AAC_LTP";
        }
        if (o == AAC_HE_V1) {
            return "AAC_HE_V1";
        }
        if (o == AAC_SCALABLE) {
            return "AAC_SCALABLE";
        }
        if (o == AAC_ERLC) {
            return "AAC_ERLC";
        }
        if (o == AAC_LD) {
            return "AAC_LD";
        }
        if (o == AAC_HE_V2) {
            return "AAC_HE_V2";
        }
        if (o == AAC_ELD) {
            return "AAC_ELD";
        }
        if (o == AAC_ADTS_MAIN) {
            return "AAC_ADTS_MAIN";
        }
        if (o == AAC_ADTS_LC) {
            return "AAC_ADTS_LC";
        }
        if (o == AAC_ADTS_SSR) {
            return "AAC_ADTS_SSR";
        }
        if (o == AAC_ADTS_LTP) {
            return "AAC_ADTS_LTP";
        }
        if (o == AAC_ADTS_HE_V1) {
            return "AAC_ADTS_HE_V1";
        }
        if (o == AAC_ADTS_SCALABLE) {
            return "AAC_ADTS_SCALABLE";
        }
        if (o == AAC_ADTS_ERLC) {
            return "AAC_ADTS_ERLC";
        }
        if (o == AAC_ADTS_LD) {
            return "AAC_ADTS_LD";
        }
        if (o == AAC_ADTS_HE_V2) {
            return "AAC_ADTS_HE_V2";
        }
        if (o == AAC_ADTS_ELD) {
            return "AAC_ADTS_ELD";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & INVALID) == INVALID) {
            list.add("INVALID");
            flipped |= INVALID;
        }
        list.add("DEFAULT"); // DEFAULT == 0
        list.add("PCM"); // PCM == 0
        if ((o & MP3) == MP3) {
            list.add("MP3");
            flipped |= MP3;
        }
        if ((o & AMR_NB) == AMR_NB) {
            list.add("AMR_NB");
            flipped |= AMR_NB;
        }
        if ((o & AMR_WB) == AMR_WB) {
            list.add("AMR_WB");
            flipped |= AMR_WB;
        }
        if ((o & AAC) == AAC) {
            list.add("AAC");
            flipped |= AAC;
        }
        if ((o & HE_AAC_V1) == HE_AAC_V1) {
            list.add("HE_AAC_V1");
            flipped |= HE_AAC_V1;
        }
        if ((o & HE_AAC_V2) == HE_AAC_V2) {
            list.add("HE_AAC_V2");
            flipped |= HE_AAC_V2;
        }
        if ((o & VORBIS) == VORBIS) {
            list.add("VORBIS");
            flipped |= VORBIS;
        }
        if ((o & OPUS) == OPUS) {
            list.add("OPUS");
            flipped |= OPUS;
        }
        if ((o & AC3) == AC3) {
            list.add("AC3");
            flipped |= AC3;
        }
        if ((o & E_AC3) == E_AC3) {
            list.add("E_AC3");
            flipped |= E_AC3;
        }
        if ((o & DTS) == DTS) {
            list.add("DTS");
            flipped |= DTS;
        }
        if ((o & DTS_HD) == DTS_HD) {
            list.add("DTS_HD");
            flipped |= DTS_HD;
        }
        if ((o & IEC61937) == IEC61937) {
            list.add("IEC61937");
            flipped |= IEC61937;
        }
        if ((o & DOLBY_TRUEHD) == DOLBY_TRUEHD) {
            list.add("DOLBY_TRUEHD");
            flipped |= DOLBY_TRUEHD;
        }
        if ((o & EVRC) == EVRC) {
            list.add("EVRC");
            flipped |= EVRC;
        }
        if ((o & EVRCB) == EVRCB) {
            list.add("EVRCB");
            flipped |= EVRCB;
        }
        if ((o & EVRCWB) == EVRCWB) {
            list.add("EVRCWB");
            flipped |= EVRCWB;
        }
        if ((o & EVRCNW) == EVRCNW) {
            list.add("EVRCNW");
            flipped |= EVRCNW;
        }
        if ((o & AAC_ADIF) == AAC_ADIF) {
            list.add("AAC_ADIF");
            flipped |= AAC_ADIF;
        }
        if ((o & WMA) == WMA) {
            list.add("WMA");
            flipped |= WMA;
        }
        if ((o & WMA_PRO) == WMA_PRO) {
            list.add("WMA_PRO");
            flipped |= WMA_PRO;
        }
        if ((o & AMR_WB_PLUS) == AMR_WB_PLUS) {
            list.add("AMR_WB_PLUS");
            flipped |= AMR_WB_PLUS;
        }
        if ((o & MP2) == MP2) {
            list.add("MP2");
            flipped |= MP2;
        }
        if ((o & QCELP) == QCELP) {
            list.add("QCELP");
            flipped |= QCELP;
        }
        if ((o & DSD) == DSD) {
            list.add("DSD");
            flipped |= DSD;
        }
        if ((o & FLAC) == FLAC) {
            list.add("FLAC");
            flipped |= FLAC;
        }
        if ((o & ALAC) == ALAC) {
            list.add("ALAC");
            flipped |= ALAC;
        }
        if ((o & APE) == APE) {
            list.add("APE");
            flipped |= APE;
        }
        if ((o & AAC_ADTS) == AAC_ADTS) {
            list.add("AAC_ADTS");
            flipped |= AAC_ADTS;
        }
        if ((o & SBC) == SBC) {
            list.add("SBC");
            flipped |= SBC;
        }
        if ((o & APTX) == APTX) {
            list.add("APTX");
            flipped |= APTX;
        }
        if ((o & APTX_HD) == APTX_HD) {
            list.add("APTX_HD");
            flipped |= APTX_HD;
        }
        if ((o & AC4) == AC4) {
            list.add("AC4");
            flipped |= AC4;
        }
        if ((o & LDAC) == LDAC) {
            list.add("LDAC");
            flipped |= LDAC;
        }
        if ((o & MAIN_MASK) == MAIN_MASK) {
            list.add("MAIN_MASK");
            flipped |= MAIN_MASK;
        }
        if ((o & SUB_MASK) == SUB_MASK) {
            list.add("SUB_MASK");
            flipped |= SUB_MASK;
        }
        if ((o & PCM_SUB_16_BIT) == PCM_SUB_16_BIT) {
            list.add("PCM_SUB_16_BIT");
            flipped |= PCM_SUB_16_BIT;
        }
        if ((o & PCM_SUB_8_BIT) == PCM_SUB_8_BIT) {
            list.add("PCM_SUB_8_BIT");
            flipped |= PCM_SUB_8_BIT;
        }
        if ((o & PCM_SUB_32_BIT) == PCM_SUB_32_BIT) {
            list.add("PCM_SUB_32_BIT");
            flipped |= PCM_SUB_32_BIT;
        }
        if ((o & PCM_SUB_8_24_BIT) == PCM_SUB_8_24_BIT) {
            list.add("PCM_SUB_8_24_BIT");
            flipped |= PCM_SUB_8_24_BIT;
        }
        if ((o & PCM_SUB_FLOAT) == PCM_SUB_FLOAT) {
            list.add("PCM_SUB_FLOAT");
            flipped |= PCM_SUB_FLOAT;
        }
        if ((o & PCM_SUB_24_BIT_PACKED) == PCM_SUB_24_BIT_PACKED) {
            list.add("PCM_SUB_24_BIT_PACKED");
            flipped |= PCM_SUB_24_BIT_PACKED;
        }
        list.add("MP3_SUB_NONE"); // MP3_SUB_NONE == 0
        list.add("AMR_SUB_NONE"); // AMR_SUB_NONE == 0
        if ((o & AAC_SUB_MAIN) == AAC_SUB_MAIN) {
            list.add("AAC_SUB_MAIN");
            flipped |= AAC_SUB_MAIN;
        }
        if ((o & AAC_SUB_LC) == AAC_SUB_LC) {
            list.add("AAC_SUB_LC");
            flipped |= AAC_SUB_LC;
        }
        if ((o & AAC_SUB_SSR) == AAC_SUB_SSR) {
            list.add("AAC_SUB_SSR");
            flipped |= AAC_SUB_SSR;
        }
        if ((o & AAC_SUB_LTP) == AAC_SUB_LTP) {
            list.add("AAC_SUB_LTP");
            flipped |= AAC_SUB_LTP;
        }
        if ((o & AAC_SUB_HE_V1) == AAC_SUB_HE_V1) {
            list.add("AAC_SUB_HE_V1");
            flipped |= AAC_SUB_HE_V1;
        }
        if ((o & AAC_SUB_SCALABLE) == AAC_SUB_SCALABLE) {
            list.add("AAC_SUB_SCALABLE");
            flipped |= AAC_SUB_SCALABLE;
        }
        if ((o & AAC_SUB_ERLC) == AAC_SUB_ERLC) {
            list.add("AAC_SUB_ERLC");
            flipped |= AAC_SUB_ERLC;
        }
        if ((o & AAC_SUB_LD) == AAC_SUB_LD) {
            list.add("AAC_SUB_LD");
            flipped |= AAC_SUB_LD;
        }
        if ((o & AAC_SUB_HE_V2) == AAC_SUB_HE_V2) {
            list.add("AAC_SUB_HE_V2");
            flipped |= AAC_SUB_HE_V2;
        }
        if ((o & AAC_SUB_ELD) == AAC_SUB_ELD) {
            list.add("AAC_SUB_ELD");
            flipped |= AAC_SUB_ELD;
        }
        list.add("VORBIS_SUB_NONE"); // VORBIS_SUB_NONE == 0
        if ((o & PCM_16_BIT) == PCM_16_BIT) {
            list.add("PCM_16_BIT");
            flipped |= PCM_16_BIT;
        }
        if ((o & PCM_8_BIT) == PCM_8_BIT) {
            list.add("PCM_8_BIT");
            flipped |= PCM_8_BIT;
        }
        if ((o & PCM_32_BIT) == PCM_32_BIT) {
            list.add("PCM_32_BIT");
            flipped |= PCM_32_BIT;
        }
        if ((o & PCM_8_24_BIT) == PCM_8_24_BIT) {
            list.add("PCM_8_24_BIT");
            flipped |= PCM_8_24_BIT;
        }
        if ((o & PCM_FLOAT) == PCM_FLOAT) {
            list.add("PCM_FLOAT");
            flipped |= PCM_FLOAT;
        }
        if ((o & PCM_24_BIT_PACKED) == PCM_24_BIT_PACKED) {
            list.add("PCM_24_BIT_PACKED");
            flipped |= PCM_24_BIT_PACKED;
        }
        if ((o & AAC_MAIN) == AAC_MAIN) {
            list.add("AAC_MAIN");
            flipped |= AAC_MAIN;
        }
        if ((o & AAC_LC) == AAC_LC) {
            list.add("AAC_LC");
            flipped |= AAC_LC;
        }
        if ((o & AAC_SSR) == AAC_SSR) {
            list.add("AAC_SSR");
            flipped |= AAC_SSR;
        }
        if ((o & AAC_LTP) == AAC_LTP) {
            list.add("AAC_LTP");
            flipped |= AAC_LTP;
        }
        if ((o & AAC_HE_V1) == AAC_HE_V1) {
            list.add("AAC_HE_V1");
            flipped |= AAC_HE_V1;
        }
        if ((o & AAC_SCALABLE) == AAC_SCALABLE) {
            list.add("AAC_SCALABLE");
            flipped |= AAC_SCALABLE;
        }
        if ((o & AAC_ERLC) == AAC_ERLC) {
            list.add("AAC_ERLC");
            flipped |= AAC_ERLC;
        }
        if ((o & AAC_LD) == AAC_LD) {
            list.add("AAC_LD");
            flipped |= AAC_LD;
        }
        if ((o & AAC_HE_V2) == AAC_HE_V2) {
            list.add("AAC_HE_V2");
            flipped |= AAC_HE_V2;
        }
        if ((o & AAC_ELD) == AAC_ELD) {
            list.add("AAC_ELD");
            flipped |= AAC_ELD;
        }
        if ((o & AAC_ADTS_MAIN) == AAC_ADTS_MAIN) {
            list.add("AAC_ADTS_MAIN");
            flipped |= AAC_ADTS_MAIN;
        }
        if ((o & AAC_ADTS_LC) == AAC_ADTS_LC) {
            list.add("AAC_ADTS_LC");
            flipped |= AAC_ADTS_LC;
        }
        if ((o & AAC_ADTS_SSR) == AAC_ADTS_SSR) {
            list.add("AAC_ADTS_SSR");
            flipped |= AAC_ADTS_SSR;
        }
        if ((o & AAC_ADTS_LTP) == AAC_ADTS_LTP) {
            list.add("AAC_ADTS_LTP");
            flipped |= AAC_ADTS_LTP;
        }
        if ((o & AAC_ADTS_HE_V1) == AAC_ADTS_HE_V1) {
            list.add("AAC_ADTS_HE_V1");
            flipped |= AAC_ADTS_HE_V1;
        }
        if ((o & AAC_ADTS_SCALABLE) == AAC_ADTS_SCALABLE) {
            list.add("AAC_ADTS_SCALABLE");
            flipped |= AAC_ADTS_SCALABLE;
        }
        if ((o & AAC_ADTS_ERLC) == AAC_ADTS_ERLC) {
            list.add("AAC_ADTS_ERLC");
            flipped |= AAC_ADTS_ERLC;
        }
        if ((o & AAC_ADTS_LD) == AAC_ADTS_LD) {
            list.add("AAC_ADTS_LD");
            flipped |= AAC_ADTS_LD;
        }
        if ((o & AAC_ADTS_HE_V2) == AAC_ADTS_HE_V2) {
            list.add("AAC_ADTS_HE_V2");
            flipped |= AAC_ADTS_HE_V2;
        }
        if ((o & AAC_ADTS_ELD) == AAC_ADTS_ELD) {
            list.add("AAC_ADTS_ELD");
            flipped |= AAC_ADTS_ELD;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

