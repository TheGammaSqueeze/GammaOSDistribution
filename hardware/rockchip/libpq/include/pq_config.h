#define HIGH_QUALITY "HIGH_QUALITY_MODE"
#define LOW_LATENCY "LOW_LATENCY_MODE"

typedef struct {
    // M4_BOOL_DESC("cscEnable", "1")
    bool cscEnable;
    char *cscMode;
    // M4_NUMBER_DESC("cscBrightness", "u32", M4_RANGE(0,511), "256", M4_DIGIT(0))
    unsigned int cscBrightness;
    // M4_NUMBER_DESC("cscHue", "u32", M4_RANGE(0,511), "256", M4_DIGIT(0))
    unsigned int cscHue;
    // M4_NUMBER_DESC("cscContrast", "u32", M4_RANGE(0,511), "256", M4_DIGIT(0))
    unsigned int cscContrast;
    // M4_NUMBER_DESC("cscSaturation", "u32", M4_RANGE(0,511), "256", M4_DIGIT(0))
    unsigned int cscSaturation;
    // M4_NUMBER_DESC("cscRGain", "u32", M4_RANGE(0,511), "256", M4_DIGIT(0))
    unsigned int cscRGain;
    // M4_NUMBER_DESC("cscGGain", "u32", M4_RANGE(0,511), "256", M4_DIGIT(0))
    unsigned int cscGGain;
    // M4_NUMBER_DESC("cscBGain", "u32", M4_RANGE(0,511), "256", M4_DIGIT(0))
    unsigned int cscBGain;
} csc;

typedef struct {
    // M4_BOOL_DESC("dciEnable", "1")
    bool dciEnable;
	// M4_ARRAY_DESC("dciWgtCoef_low", "u16", M4_SIZE(1,33), M4_RANGE(0, 1023), "[0,54,109,163,217,265,312,359,406,444,481,519,556,587,618,648,679,708,738,767,796,819,842,864,887,903,918,934,949,959,969,979,989]", M4_DIGIT(0), M4_DYNAMIC(0))
	unsigned short dciWgtCoef_low[33];	
	// M4_ARRAY_DESC("dciWgtCoef_mid", "u16", M4_SIZE(1,33), M4_RANGE(0, 1023), "[0,20,40,60,80,112,145,178,211,269,327,384,442,490,538,582,626,663,701,738,775,798,821,843,866,885,905,924,943,963,983,1003,1023]", M4_DIGIT(0), M4_DYNAMIC(0))
	unsigned short dciWgtCoef_mid[33];
	// M4_ARRAY_DESC("dciWgtCoef_high", "u16", M4_SIZE(1,33), M4_RANGE(0, 1023), "[0,9,17,26,35,57,80,102,125,151,178,205,232,261,289,318,346,379,412,445,478,508,538,571,607,643,685,733,793,856,916,970,1023]", M4_DIGIT(0), M4_DYNAMIC(0))
	unsigned short dciWgtCoef_high[33];
	// M4_ARRAY_DESC("dciWeight_low", "u16", M4_SIZE(1,32), M4_RANGE(0, 32), "[16, 16, 16, 16, 14, 12, 10, 8, 6, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]", M4_DIGIT(0), M4_DYNAMIC(0))
	unsigned short dciWeight_low[32];
	// M4_ARRAY_DESC("dciWeight_mid", "u16", M4_SIZE(1,32), M4_RANGE(0, 32), "[0, 0, 0, 0, 3, 6, 9, 12, 15, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 15, 12, 9, 6, 3, 0, 0, 0, 0]", M4_DIGIT(0), M4_DYNAMIC(0))
	unsigned short dciWeight_mid[32];
	// M4_ARRAY_DESC("dciWeight_high", "u16", M4_SIZE(1,32), M4_RANGE(0, 32), "[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 16, 16, 16, 16]", M4_DIGIT(0), M4_DYNAMIC(0))
	unsigned short dciWeight_high[32];
    // tag_RKVOP_DCI_CFG();
} dci;

typedef struct {
    // M4_BOOL_DESC("acmEnable", "1")
    bool acmEnable;
	// M4_ARRAY_DESC("acmTableDeltaYbyH", "u8", M4_SIZE(1,65), M4_RANGE(0, 256), "[128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128]", M4_DIGIT(0), M4_DYNAMIC(0))
	unsigned char acmTableDeltaYbyH[65];
	// M4_ARRAY_DESC("acmTableDeltaHbyH", "u8", M4_SIZE(1,65), M4_RANGE(0, 256), "[128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128]", M4_DIGIT(0), M4_DYNAMIC(0))
	unsigned char acmTableDeltaHbyH[65];
	// M4_ARRAY_DESC("acmTableDeltaSbyH", "u8", M4_SIZE(1,65), M4_RANGE(0, 256), "[128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128]", M4_DIGIT(0), M4_DYNAMIC(0))
	unsigned char acmTableDeltaSbyH[65];
	// M4_ARRAY_DESC("acmTableGainYbyY", "u8", M4_SIZE(1,9), M4_RANGE(0, 128), "[128, 128, 128, 128, 128, 128, 128, 128, 128]", M4_DIGIT(0), M4_DYNAMIC(0))
	unsigned char acmTableGainYbyY[9];
	// M4_ARRAY_DESC("acmTableGainHbyY", "u8", M4_SIZE(1,9), M4_RANGE(0, 128), "[128, 128, 128, 128, 128, 128, 128, 128, 128]", M4_DIGIT(0), M4_DYNAMIC(0))
	unsigned char acmTableGainHbyY[9];
	// M4_ARRAY_DESC("acmTableGainSbyY", "u8", M4_SIZE(1,9), M4_RANGE(0, 128), "[128, 128, 128, 128, 128, 128, 128, 128, 128]", M4_DIGIT(0), M4_DYNAMIC(0))
	unsigned char acmTableGainSbyY[9];
	// M4_ARRAY_DESC("acmTableGainYbyS", "u8", M4_SIZE(1,13), M4_RANGE(0, 128), "[128, 128, 128, 128, 128, 128, 128, 128, 128]", M4_DIGIT(0), M4_DYNAMIC(0))
	unsigned char acmTableGainYbyS[13];
	// M4_ARRAY_DESC("acmTableGainHbyS", "u8", M4_SIZE(1,13), M4_RANGE(0, 128), "[128, 128, 128, 128, 128, 128, 128, 128, 128]", M4_DIGIT(0), M4_DYNAMIC(0))
	unsigned char acmTableGainHbyS[13];
	// M4_ARRAY_DESC("acmTableGainSbyS", "u8", M4_SIZE(1,13), M4_RANGE(0, 128), "[128, 128, 128, 128, 128, 128, 128, 128, 128]", M4_DIGIT(0), M4_DYNAMIC(0))
	unsigned char acmTableGainSbyS[13];
  // M4_NUMBER_DESC("lumGain", "u32", M4_RANGE(0,511), "256", M4_DIGIT(0))
  unsigned int lumGain;
  // M4_NUMBER_DESC("hueGain", "u32", M4_RANGE(0,511), "256", M4_DIGIT(0))
  unsigned int hueGain;
  // M4_NUMBER_DESC("satGain", "u32", M4_RANGE(0,511), "256", M4_DIGIT(0))
  unsigned int satGain;
  // tag_RKVOP_ACM_CFG();
} acm;

typedef struct {
    // M4_BOOL_DESC("gammaEnable", "1")
    bool gammaEnable;
	unsigned short gammaTab_R[1024];	
	unsigned short gammaTab_G[1024];
	unsigned short gammaTab_B[1024];
  // tag_RKVOP_GAMMA_CFG();
} gamma;

typedef struct {
    csc csc;
    dci dci;
    acm acm;
    gamma gamma;
} pq_tuning_param;

typedef struct {
    pq_tuning_param pq_tuning_param;
} pq_config;
