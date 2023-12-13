package android.keystore.cts;

import android.security.keymaster.KeymasterDefs;

class EatClaim {
    public static final int IAT = 6;
    public static final int CTI = 7;

    public static final int NONCE = -75008;
    public static final int UEID = -75009;

    public static final int SECURITY_LEVEL = -76002;
    public static final int SECURITY_LEVEL_UNRESTRICTED = 1;
    public static final int SECURITY_LEVEL_SECURE_RESTRICTED = 3;
    public static final int SECURITY_LEVEL_HARDWARE = 4;

    public static final int BOOT_STATE = -76003;
    public static final int SUBMODS = -76000;

    private static final int PRIVATE_BASE = -80000;

    public static final int PURPOSE = PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_PURPOSE);
    public static final int ALGORITHM =
            PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_ALGORITHM);
    public static final int KEY_SIZE = PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_KEY_SIZE);
    public static final int BLOCK_MODE =
            PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_BLOCK_MODE);
    public static final int DIGEST = PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_DIGEST);
    public static final int PADDING = PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_PADDING);
    public static final int CALLER_NONCE =
            PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_CALLER_NONCE);
    public static final int MIN_MAC_LENGTH =
            PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_MIN_MAC_LENGTH);
    public static final int KDF = PRIVATE_BASE - 9;

    public static final int EC_CURVE = PRIVATE_BASE - 10;
    public static final int EAT_EC_CURVE_P_224 = 0;
    public static final int EAT_EC_CURVE_P_256 = 1;
    public static final int EAT_EC_CURVE_P_384 = 2;
    public static final int EAT_EC_CURVE_P_521 = 3;

    public static final int RSA_PUBLIC_EXPONENT =
            PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_RSA_PUBLIC_EXPONENT);

    public static final int ROLLBACK_RESISTANCE = PRIVATE_BASE - 303;
    public static final int EARLY_BOOT_ONLY = PRIVATE_BASE - 305;

    public static final int ACTIVE_DATETIME =
            PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_ACTIVE_DATETIME);
    public static final int ORIGINATION_EXPIRE_DATETIME =
            PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_ORIGINATION_EXPIRE_DATETIME);
    public static final int USAGE_EXPIRE_DATETIME =
            PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_USAGE_EXPIRE_DATETIME);

    public static final int NO_AUTH_REQUIRED =
            PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_NO_AUTH_REQUIRED);
    public static final int USER_AUTH_TYPE =
            PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_USER_AUTH_TYPE);
    public static final int AUTH_TIMEOUT =
            PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_AUTH_TIMEOUT);
    public static final int ALLOW_WHILE_ON_BODY =
            PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_ALLOW_WHILE_ON_BODY);
    public static final int USER_PRESENCE_REQUIRED = PRIVATE_BASE - 507;
    public static final int TRUSTED_CONFIRMATION_REQUIRED =
            PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_TRUSTED_CONFIRMATION_REQUIRED);
    public static final int UNLOCKED_DEVICE_REQUIRED =
            PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_UNLOCKED_DEVICE_REQUIRED);

    public static final int APPLICATION_ID =
            PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_APPLICATION_ID);

    public static final int ORIGIN = PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_ORIGIN);
    // TODO: hardcoded while KeymasterDefs uses the same value for
    // ROLLBACK_RESISTANCE and ROLLBACK_RESISTANT
    public static final int ROLLBACK_RESISTANT = PRIVATE_BASE - 703;
    public static final int OS_VERSION = PRIVATE_BASE - 705;
    public static final int OS_PATCHLEVEL = PRIVATE_BASE - 706;
    public static final int ATTESTATION_APPLICATION_ID = PRIVATE_BASE - 709;
    public static final int ATTESTATION_ID_BRAND =
            PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_ATTESTATION_ID_BRAND);
    public static final int ATTESTATION_ID_DEVICE =
            PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_ATTESTATION_ID_DEVICE);
    public static final int ATTESTATION_ID_PRODUCT =
            PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_ATTESTATION_ID_PRODUCT);
    public static final int ATTESTATION_ID_SERIAL =
            PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_ATTESTATION_ID_SERIAL);
    public static final int ATTESTATION_ID_MEID =
            PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_ATTESTATION_ID_MEID);
    public static final int ATTESTATION_ID_MANUFACTURER =
            PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_ATTESTATION_ID_MANUFACTURER);
    public static final int ATTESTATION_ID_MODEL =
            PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_ATTESTATION_ID_MODEL);
    public static final int VENDOR_PATCHLEVEL =
            PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_VENDOR_PATCHLEVEL);
    public static final int BOOT_PATCHLEVEL =
            PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_BOOT_PATCHLEVEL);
    public static final int DEVICE_UNIQUE_ATTESTATION =
            PRIVATE_BASE - (0x0FFFFFFF & KeymasterDefs.KM_TAG_DEVICE_UNIQUE_ATTESTATION);
    public static final int IDENTITY_CREDENTIAL_KEY = PRIVATE_BASE - 721;

    private static final int NON_KM_BASE = PRIVATE_BASE - 2000;

    public static final int VERIFIED_BOOT_KEY = NON_KM_BASE - 1;
    public static final int DEVICE_LOCKED = NON_KM_BASE - 2;
    public static final int VERIFIED_BOOT_HASH = NON_KM_BASE - 3;
    public static final int ATTESTATION_VERSION = NON_KM_BASE - 4;
    public static final int KEYMASTER_VERSION = NON_KM_BASE - 5;
    public static final int OFFICIAL_BUILD = NON_KM_BASE - 6;

    public static final String SUBMOD_SOFTWARE = "software";
    public static final String SUBMOD_TEE = "tee";
}
