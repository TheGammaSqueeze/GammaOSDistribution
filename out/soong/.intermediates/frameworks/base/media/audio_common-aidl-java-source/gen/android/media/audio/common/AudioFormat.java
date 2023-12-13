/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package android.media.audio.common;
/**
 * Audio format  is a 32-bit word that consists of:
 *   main format field (upper 8 bits)
 *   sub format field (lower 24 bits).
 *
 * The main format indicates the main codec type. The sub format field indicates
 * options and parameters for each format. The sub format is mainly used for
 * record to indicate for instance the requested bitrate or profile.  It can
 * also be used for certain formats to give informations not present in the
 * encoded audio stream (e.g. octet alignement for AMR).
 *
 * {@hide}
 */
public @interface AudioFormat {
  public static final int INVALID = -1;
  public static final int DEFAULT = 0;
  public static final int PCM = 0;
  public static final int MP3 = 16777216;
  public static final int AMR_NB = 33554432;
  public static final int AMR_WB = 50331648;
  public static final int AAC = 67108864;
  /**
      * Deprecated, Use AAC_HE_V1
      */
  public static final int HE_AAC_V1 = 83886080;
  /**
      * Deprecated, Use AAC_HE_V2
      */
  public static final int HE_AAC_V2 = 100663296;
  public static final int VORBIS = 117440512;
  public static final int OPUS = 134217728;
  public static final int AC3 = 150994944;
  public static final int E_AC3 = 167772160;
  public static final int DTS = 184549376;
  public static final int DTS_HD = 201326592;
  /**
      * IEC61937 is encoded audio wrapped in 16-bit PCM.
      */
  public static final int IEC61937 = 218103808;
  public static final int DOLBY_TRUEHD = 234881024;
  public static final int EVRC = 268435456;
  public static final int EVRCB = 285212672;
  public static final int EVRCWB = 301989888;
  public static final int EVRCNW = 318767104;
  public static final int AAC_ADIF = 335544320;
  public static final int WMA = 352321536;
  public static final int WMA_PRO = 369098752;
  public static final int AMR_WB_PLUS = 385875968;
  public static final int MP2 = 402653184;
  public static final int QCELP = 419430400;
  public static final int DSD = 436207616;
  public static final int FLAC = 452984832;
  public static final int ALAC = 469762048;
  public static final int APE = 486539264;
  public static final int AAC_ADTS = 503316480;
  public static final int SBC = 520093696;
  public static final int APTX = 536870912;
  public static final int APTX_HD = 553648128;
  public static final int AC4 = 570425344;
  public static final int LDAC = 587202560;
  /**
      * Dolby Metadata-enhanced Audio Transmission
      */
  public static final int MAT = 603979776;
  public static final int AAC_LATM = 620756992;
  public static final int CELT = 637534208;
  public static final int APTX_ADAPTIVE = 654311424;
  public static final int LHDC = 671088640;
  public static final int LHDC_LL = 687865856;
  public static final int APTX_TWSP = 704643072;
  /**
      * Deprecated
      */
  public static final int MAIN_MASK = -16777216;
  public static final int SUB_MASK = 16777215;
  /**
      * Subformats
      */
  public static final int PCM_SUB_16_BIT = 1;
  public static final int PCM_SUB_8_BIT = 2;
  public static final int PCM_SUB_32_BIT = 3;
  public static final int PCM_SUB_8_24_BIT = 4;
  public static final int PCM_SUB_FLOAT = 5;
  public static final int PCM_SUB_24_BIT_PACKED = 6;
  public static final int MP3_SUB_NONE = 0;
  public static final int AMR_SUB_NONE = 0;
  public static final int AAC_SUB_MAIN = 1;
  public static final int AAC_SUB_LC = 2;
  public static final int AAC_SUB_SSR = 4;
  public static final int AAC_SUB_LTP = 8;
  public static final int AAC_SUB_HE_V1 = 16;
  public static final int AAC_SUB_SCALABLE = 32;
  public static final int AAC_SUB_ERLC = 64;
  public static final int AAC_SUB_LD = 128;
  public static final int AAC_SUB_HE_V2 = 256;
  public static final int AAC_SUB_ELD = 512;
  public static final int AAC_SUB_XHE = 768;
  public static final int VORBIS_SUB_NONE = 0;
  public static final int E_AC3_SUB_JOC = 1;
  public static final int MAT_SUB_1_0 = 1;
  public static final int MAT_SUB_2_0 = 2;
  public static final int MAT_SUB_2_1 = 3;
}
