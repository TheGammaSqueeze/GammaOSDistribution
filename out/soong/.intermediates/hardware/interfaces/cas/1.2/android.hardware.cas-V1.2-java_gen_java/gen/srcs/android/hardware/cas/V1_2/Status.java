package android.hardware.cas.V1_2;


public final class Status {
    /**
     * The CAS plugin must return OK when an operation completes without any
     * errors.
     */
    public static final int OK = 0;
    /**
     * The CAS plugin must return ERROR_CAS_NO_LICENSE, when descrambling is
     * attempted and no license keys have been provided.
     */
    public static final int ERROR_CAS_NO_LICENSE = 1 /* ::android::hardware::cas::V1_0::Status.OK implicitly + 1 */;
    /**
     * ERROR_CAS_LICENSE_EXPIRED must be returned when an attempt is made
     * to use a license and the keys in that license have expired.
     */
    public static final int ERROR_CAS_LICENSE_EXPIRED = 2 /* ::android::hardware::cas::V1_0::Status.ERROR_CAS_NO_LICENSE implicitly + 1 */;
    /**
     * The CAS plugin must return ERROR_CAS_SESSION_NOT_OPENED when an
     * attempt is made to use a session that has not been opened.
     */
    public static final int ERROR_CAS_SESSION_NOT_OPENED = 3 /* ::android::hardware::cas::V1_0::Status.ERROR_CAS_LICENSE_EXPIRED implicitly + 1 */;
    /**
     * The CAS plugin must return ERROR_CAS_CANNOT_HANDLE when an unsupported
     * data format or operation is attempted.
     */
    public static final int ERROR_CAS_CANNOT_HANDLE = 4 /* ::android::hardware::cas::V1_0::Status.ERROR_CAS_SESSION_NOT_OPENED implicitly + 1 */;
    /**
     * ERROR_CAS_INVALID_STATE must be returned when the device is in a state
     * where it is not able to perform descrambling.
     */
    public static final int ERROR_CAS_INVALID_STATE = 5 /* ::android::hardware::cas::V1_0::Status.ERROR_CAS_CANNOT_HANDLE implicitly + 1 */;
    /**
     * The CAS plugin must return BAD_VALUE whenever an illegal parameter is
     * passed to one of the interface functions.
     */
    public static final int BAD_VALUE = 6 /* ::android::hardware::cas::V1_0::Status.ERROR_CAS_INVALID_STATE implicitly + 1 */;
    /**
     * The CAS plugin must return ERROR_CAS_NOT_PROVISIONED when the device
     * has not yet been provisioned.
     */
    public static final int ERROR_CAS_NOT_PROVISIONED = 7 /* ::android::hardware::cas::V1_0::Status.BAD_VALUE implicitly + 1 */;
    /**
     * ERROR_CAS_RESOURCE_BUSY must be returned when resources, such as CAS
     * sessions or secure buffers are not available to perform a requested
     * operation because they are already in use.
     */
    public static final int ERROR_CAS_RESOURCE_BUSY = 8 /* ::android::hardware::cas::V1_0::Status.ERROR_CAS_NOT_PROVISIONED implicitly + 1 */;
    /**
     * The CAS Plugin must return ERROR_CAS_INSUFFICIENT_OUTPUT_PROTECTION
     * when the output protection level enabled on the device is not
     * sufficient to meet the requirements in the license policy. HDCP is an
     * example of a form of output protection.
     */
    public static final int ERROR_CAS_INSUFFICIENT_OUTPUT_PROTECTION = 9 /* ::android::hardware::cas::V1_0::Status.ERROR_CAS_RESOURCE_BUSY implicitly + 1 */;
    /**
     * The CAS Plugin must return ERROR_CAS_TAMPER_DETECTED if an attempt to
     * tamper with the CAS system is detected.
     */
    public static final int ERROR_CAS_TAMPER_DETECTED = 10 /* ::android::hardware::cas::V1_0::Status.ERROR_CAS_INSUFFICIENT_OUTPUT_PROTECTION implicitly + 1 */;
    /**
     * The CAS Plugin must return ERROR_CAS_DEVICE_REVOKED if the response
     * indicates that the device has been revoked. Device revocation means
     * that the device is no longer permitted to play content.
     */
    public static final int ERROR_CAS_DEVICE_REVOKED = 11 /* ::android::hardware::cas::V1_0::Status.ERROR_CAS_TAMPER_DETECTED implicitly + 1 */;
    /**
     * The CAS plugin must return ERROR_CAS_DECRYPT_UNIT_NOT_INITIALIZED when
     * descrambling is failing because the session is not initialized properly.
     */
    public static final int ERROR_CAS_DECRYPT_UNIT_NOT_INITIALIZED = 12 /* ::android::hardware::cas::V1_0::Status.ERROR_CAS_DEVICE_REVOKED implicitly + 1 */;
    /**
     * The CAS Plugin must return ERROR_CAS_DECRYPT if the DescramblerPlugin's
     * descramble operation fails.
     */
    public static final int ERROR_CAS_DECRYPT = 13 /* ::android::hardware::cas::V1_0::Status.ERROR_CAS_DECRYPT_UNIT_NOT_INITIALIZED implicitly + 1 */;
    /**
     * ERROR_CAS_UNKNOWN must be returned when a fatal failure occurs and no
     * other defined error is appropriate.
     */
    public static final int ERROR_CAS_UNKNOWN = 14 /* ::android::hardware::cas::V1_0::Status.ERROR_CAS_DECRYPT implicitly + 1 */;
    /**
     * ERROR_CAS_NEED_ACTIVATION is used to trigger device activation process.
     */
    public static final int ERROR_CAS_NEED_ACTIVATION = 15 /* ::android::hardware::cas::V1_0::Status.ERROR_CAS_UNKNOWN implicitly + 1 */;
    /**
     * ERROR_CAS_NEED_PAIRING is used to trigger pairing process.
     */
    public static final int ERROR_CAS_NEED_PAIRING = 16 /* ::android::hardware::cas::V1_2::Status.ERROR_CAS_NEED_ACTIVATION implicitly + 1 */;
    /**
     * ERROR_CAS_NO_CARD is used to report no smart card for descrambling.
     */
    public static final int ERROR_CAS_NO_CARD = 17 /* ::android::hardware::cas::V1_2::Status.ERROR_CAS_NEED_PAIRING implicitly + 1 */;
    /**
     * ERROR_CAS_CARD_MUTE is used to report smart card is muted for
     * descrambling.
     */
    public static final int ERROR_CAS_CARD_MUTE = 18 /* ::android::hardware::cas::V1_2::Status.ERROR_CAS_NO_CARD implicitly + 1 */;
    /**
     *  ERROR_CAS_CARD_INVALID is used to report smart card isn't valid.
     */
    public static final int ERROR_CAS_CARD_INVALID = 19 /* ::android::hardware::cas::V1_2::Status.ERROR_CAS_CARD_MUTE implicitly + 1 */;
    /**
     *  ERROR_CAS_BLACKOUT is used to report geographical blackout.
     */
    public static final int ERROR_CAS_BLACKOUT = 20 /* ::android::hardware::cas::V1_2::Status.ERROR_CAS_CARD_INVALID implicitly + 1 */;
    /**
     * ERROR_CAS_REBOOTING is used to report CAS is during rebooting.
     */
    public static final int ERROR_CAS_REBOOTING = 21 /* ::android::hardware::cas::V1_2::Status.ERROR_CAS_BLACKOUT implicitly + 1 */;
    public static final String toString(int o) {
        if (o == OK) {
            return "OK";
        }
        if (o == ERROR_CAS_NO_LICENSE) {
            return "ERROR_CAS_NO_LICENSE";
        }
        if (o == ERROR_CAS_LICENSE_EXPIRED) {
            return "ERROR_CAS_LICENSE_EXPIRED";
        }
        if (o == ERROR_CAS_SESSION_NOT_OPENED) {
            return "ERROR_CAS_SESSION_NOT_OPENED";
        }
        if (o == ERROR_CAS_CANNOT_HANDLE) {
            return "ERROR_CAS_CANNOT_HANDLE";
        }
        if (o == ERROR_CAS_INVALID_STATE) {
            return "ERROR_CAS_INVALID_STATE";
        }
        if (o == BAD_VALUE) {
            return "BAD_VALUE";
        }
        if (o == ERROR_CAS_NOT_PROVISIONED) {
            return "ERROR_CAS_NOT_PROVISIONED";
        }
        if (o == ERROR_CAS_RESOURCE_BUSY) {
            return "ERROR_CAS_RESOURCE_BUSY";
        }
        if (o == ERROR_CAS_INSUFFICIENT_OUTPUT_PROTECTION) {
            return "ERROR_CAS_INSUFFICIENT_OUTPUT_PROTECTION";
        }
        if (o == ERROR_CAS_TAMPER_DETECTED) {
            return "ERROR_CAS_TAMPER_DETECTED";
        }
        if (o == ERROR_CAS_DEVICE_REVOKED) {
            return "ERROR_CAS_DEVICE_REVOKED";
        }
        if (o == ERROR_CAS_DECRYPT_UNIT_NOT_INITIALIZED) {
            return "ERROR_CAS_DECRYPT_UNIT_NOT_INITIALIZED";
        }
        if (o == ERROR_CAS_DECRYPT) {
            return "ERROR_CAS_DECRYPT";
        }
        if (o == ERROR_CAS_UNKNOWN) {
            return "ERROR_CAS_UNKNOWN";
        }
        if (o == ERROR_CAS_NEED_ACTIVATION) {
            return "ERROR_CAS_NEED_ACTIVATION";
        }
        if (o == ERROR_CAS_NEED_PAIRING) {
            return "ERROR_CAS_NEED_PAIRING";
        }
        if (o == ERROR_CAS_NO_CARD) {
            return "ERROR_CAS_NO_CARD";
        }
        if (o == ERROR_CAS_CARD_MUTE) {
            return "ERROR_CAS_CARD_MUTE";
        }
        if (o == ERROR_CAS_CARD_INVALID) {
            return "ERROR_CAS_CARD_INVALID";
        }
        if (o == ERROR_CAS_BLACKOUT) {
            return "ERROR_CAS_BLACKOUT";
        }
        if (o == ERROR_CAS_REBOOTING) {
            return "ERROR_CAS_REBOOTING";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("OK"); // OK == 0
        if ((o & ERROR_CAS_NO_LICENSE) == ERROR_CAS_NO_LICENSE) {
            list.add("ERROR_CAS_NO_LICENSE");
            flipped |= ERROR_CAS_NO_LICENSE;
        }
        if ((o & ERROR_CAS_LICENSE_EXPIRED) == ERROR_CAS_LICENSE_EXPIRED) {
            list.add("ERROR_CAS_LICENSE_EXPIRED");
            flipped |= ERROR_CAS_LICENSE_EXPIRED;
        }
        if ((o & ERROR_CAS_SESSION_NOT_OPENED) == ERROR_CAS_SESSION_NOT_OPENED) {
            list.add("ERROR_CAS_SESSION_NOT_OPENED");
            flipped |= ERROR_CAS_SESSION_NOT_OPENED;
        }
        if ((o & ERROR_CAS_CANNOT_HANDLE) == ERROR_CAS_CANNOT_HANDLE) {
            list.add("ERROR_CAS_CANNOT_HANDLE");
            flipped |= ERROR_CAS_CANNOT_HANDLE;
        }
        if ((o & ERROR_CAS_INVALID_STATE) == ERROR_CAS_INVALID_STATE) {
            list.add("ERROR_CAS_INVALID_STATE");
            flipped |= ERROR_CAS_INVALID_STATE;
        }
        if ((o & BAD_VALUE) == BAD_VALUE) {
            list.add("BAD_VALUE");
            flipped |= BAD_VALUE;
        }
        if ((o & ERROR_CAS_NOT_PROVISIONED) == ERROR_CAS_NOT_PROVISIONED) {
            list.add("ERROR_CAS_NOT_PROVISIONED");
            flipped |= ERROR_CAS_NOT_PROVISIONED;
        }
        if ((o & ERROR_CAS_RESOURCE_BUSY) == ERROR_CAS_RESOURCE_BUSY) {
            list.add("ERROR_CAS_RESOURCE_BUSY");
            flipped |= ERROR_CAS_RESOURCE_BUSY;
        }
        if ((o & ERROR_CAS_INSUFFICIENT_OUTPUT_PROTECTION) == ERROR_CAS_INSUFFICIENT_OUTPUT_PROTECTION) {
            list.add("ERROR_CAS_INSUFFICIENT_OUTPUT_PROTECTION");
            flipped |= ERROR_CAS_INSUFFICIENT_OUTPUT_PROTECTION;
        }
        if ((o & ERROR_CAS_TAMPER_DETECTED) == ERROR_CAS_TAMPER_DETECTED) {
            list.add("ERROR_CAS_TAMPER_DETECTED");
            flipped |= ERROR_CAS_TAMPER_DETECTED;
        }
        if ((o & ERROR_CAS_DEVICE_REVOKED) == ERROR_CAS_DEVICE_REVOKED) {
            list.add("ERROR_CAS_DEVICE_REVOKED");
            flipped |= ERROR_CAS_DEVICE_REVOKED;
        }
        if ((o & ERROR_CAS_DECRYPT_UNIT_NOT_INITIALIZED) == ERROR_CAS_DECRYPT_UNIT_NOT_INITIALIZED) {
            list.add("ERROR_CAS_DECRYPT_UNIT_NOT_INITIALIZED");
            flipped |= ERROR_CAS_DECRYPT_UNIT_NOT_INITIALIZED;
        }
        if ((o & ERROR_CAS_DECRYPT) == ERROR_CAS_DECRYPT) {
            list.add("ERROR_CAS_DECRYPT");
            flipped |= ERROR_CAS_DECRYPT;
        }
        if ((o & ERROR_CAS_UNKNOWN) == ERROR_CAS_UNKNOWN) {
            list.add("ERROR_CAS_UNKNOWN");
            flipped |= ERROR_CAS_UNKNOWN;
        }
        if ((o & ERROR_CAS_NEED_ACTIVATION) == ERROR_CAS_NEED_ACTIVATION) {
            list.add("ERROR_CAS_NEED_ACTIVATION");
            flipped |= ERROR_CAS_NEED_ACTIVATION;
        }
        if ((o & ERROR_CAS_NEED_PAIRING) == ERROR_CAS_NEED_PAIRING) {
            list.add("ERROR_CAS_NEED_PAIRING");
            flipped |= ERROR_CAS_NEED_PAIRING;
        }
        if ((o & ERROR_CAS_NO_CARD) == ERROR_CAS_NO_CARD) {
            list.add("ERROR_CAS_NO_CARD");
            flipped |= ERROR_CAS_NO_CARD;
        }
        if ((o & ERROR_CAS_CARD_MUTE) == ERROR_CAS_CARD_MUTE) {
            list.add("ERROR_CAS_CARD_MUTE");
            flipped |= ERROR_CAS_CARD_MUTE;
        }
        if ((o & ERROR_CAS_CARD_INVALID) == ERROR_CAS_CARD_INVALID) {
            list.add("ERROR_CAS_CARD_INVALID");
            flipped |= ERROR_CAS_CARD_INVALID;
        }
        if ((o & ERROR_CAS_BLACKOUT) == ERROR_CAS_BLACKOUT) {
            list.add("ERROR_CAS_BLACKOUT");
            flipped |= ERROR_CAS_BLACKOUT;
        }
        if ((o & ERROR_CAS_REBOOTING) == ERROR_CAS_REBOOTING) {
            list.add("ERROR_CAS_REBOOTING");
            flipped |= ERROR_CAS_REBOOTING;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

