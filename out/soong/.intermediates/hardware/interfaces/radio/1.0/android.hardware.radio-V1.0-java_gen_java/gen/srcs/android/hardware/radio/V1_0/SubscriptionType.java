package android.hardware.radio.V1_0;


public final class SubscriptionType {
    public static final int SUBSCRIPTION_1 = 0;
    public static final int SUBSCRIPTION_2 = 1 /* ::android::hardware::radio::V1_0::SubscriptionType.SUBSCRIPTION_1 implicitly + 1 */;
    public static final int SUBSCRIPTION_3 = 2 /* ::android::hardware::radio::V1_0::SubscriptionType.SUBSCRIPTION_2 implicitly + 1 */;
    public static final String toString(int o) {
        if (o == SUBSCRIPTION_1) {
            return "SUBSCRIPTION_1";
        }
        if (o == SUBSCRIPTION_2) {
            return "SUBSCRIPTION_2";
        }
        if (o == SUBSCRIPTION_3) {
            return "SUBSCRIPTION_3";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("SUBSCRIPTION_1"); // SUBSCRIPTION_1 == 0
        if ((o & SUBSCRIPTION_2) == SUBSCRIPTION_2) {
            list.add("SUBSCRIPTION_2");
            flipped |= SUBSCRIPTION_2;
        }
        if ((o & SUBSCRIPTION_3) == SUBSCRIPTION_3) {
            list.add("SUBSCRIPTION_3");
            flipped |= SUBSCRIPTION_3;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

