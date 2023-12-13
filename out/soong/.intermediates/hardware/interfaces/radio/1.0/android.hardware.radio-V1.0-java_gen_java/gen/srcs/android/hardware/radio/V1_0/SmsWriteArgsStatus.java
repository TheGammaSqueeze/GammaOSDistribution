package android.hardware.radio.V1_0;


public final class SmsWriteArgsStatus {
    public static final int REC_UNREAD = 0;
    public static final int REC_READ = 1 /* ::android::hardware::radio::V1_0::SmsWriteArgsStatus.REC_UNREAD implicitly + 1 */;
    public static final int STO_UNSENT = 2 /* ::android::hardware::radio::V1_0::SmsWriteArgsStatus.REC_READ implicitly + 1 */;
    public static final int STO_SENT = 3 /* ::android::hardware::radio::V1_0::SmsWriteArgsStatus.STO_UNSENT implicitly + 1 */;
    public static final String toString(int o) {
        if (o == REC_UNREAD) {
            return "REC_UNREAD";
        }
        if (o == REC_READ) {
            return "REC_READ";
        }
        if (o == STO_UNSENT) {
            return "STO_UNSENT";
        }
        if (o == STO_SENT) {
            return "STO_SENT";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("REC_UNREAD"); // REC_UNREAD == 0
        if ((o & REC_READ) == REC_READ) {
            list.add("REC_READ");
            flipped |= REC_READ;
        }
        if ((o & STO_UNSENT) == STO_UNSENT) {
            list.add("STO_UNSENT");
            flipped |= STO_UNSENT;
        }
        if ((o & STO_SENT) == STO_SENT) {
            list.add("STO_SENT");
            flipped |= STO_SENT;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

