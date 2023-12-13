package android.hardware.radio.V1_0;


public final class SapConnectRsp {
    public static final int SUCCESS = 0;
    public static final int CONNECT_FAILURE = 1 /* ::android::hardware::radio::V1_0::SapConnectRsp.SUCCESS implicitly + 1 */;
    public static final int MSG_SIZE_TOO_LARGE = 2 /* ::android::hardware::radio::V1_0::SapConnectRsp.CONNECT_FAILURE implicitly + 1 */;
    public static final int MSG_SIZE_TOO_SMALL = 3 /* ::android::hardware::radio::V1_0::SapConnectRsp.MSG_SIZE_TOO_LARGE implicitly + 1 */;
    public static final int CONNECT_OK_CALL_ONGOING = 4 /* ::android::hardware::radio::V1_0::SapConnectRsp.MSG_SIZE_TOO_SMALL implicitly + 1 */;
    public static final String toString(int o) {
        if (o == SUCCESS) {
            return "SUCCESS";
        }
        if (o == CONNECT_FAILURE) {
            return "CONNECT_FAILURE";
        }
        if (o == MSG_SIZE_TOO_LARGE) {
            return "MSG_SIZE_TOO_LARGE";
        }
        if (o == MSG_SIZE_TOO_SMALL) {
            return "MSG_SIZE_TOO_SMALL";
        }
        if (o == CONNECT_OK_CALL_ONGOING) {
            return "CONNECT_OK_CALL_ONGOING";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("SUCCESS"); // SUCCESS == 0
        if ((o & CONNECT_FAILURE) == CONNECT_FAILURE) {
            list.add("CONNECT_FAILURE");
            flipped |= CONNECT_FAILURE;
        }
        if ((o & MSG_SIZE_TOO_LARGE) == MSG_SIZE_TOO_LARGE) {
            list.add("MSG_SIZE_TOO_LARGE");
            flipped |= MSG_SIZE_TOO_LARGE;
        }
        if ((o & MSG_SIZE_TOO_SMALL) == MSG_SIZE_TOO_SMALL) {
            list.add("MSG_SIZE_TOO_SMALL");
            flipped |= MSG_SIZE_TOO_SMALL;
        }
        if ((o & CONNECT_OK_CALL_ONGOING) == CONNECT_OK_CALL_ONGOING) {
            list.add("CONNECT_OK_CALL_ONGOING");
            flipped |= CONNECT_OK_CALL_ONGOING;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

