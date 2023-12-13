package android.hardware.vibrator.V1_3;


public final class Effect {
    /**
     * A single click effect.
     *
     * This effect should produce a sharp, crisp click sensation.
     */
    public static final int CLICK = 0;
    /**
     * A double click effect.
     *
     * This effect should produce two sequential sharp, crisp click sensations with a minimal
     * amount of time between them.
     */
    public static final int DOUBLE_CLICK = 1 /* ::android::hardware::vibrator::V1_0::Effect.CLICK implicitly + 1 */;
    /**
     * A tick effect.
     *
     * This effect should produce a soft, short sensation, like the tick of a clock.
     */
    public static final int TICK = 2 /* ::android::hardware::vibrator::V1_0::Effect.DOUBLE_CLICK implicitly + 1 */;
    /**
     * A thud effect.
     *
     * This effect should solid feeling bump, like the depression of a heavy mechanical button.
     */
    public static final int THUD = 3 /* ::android::hardware::vibrator::V1_1::Effect_1_1.TICK implicitly + 1 */;
    /**
     * A pop effect.
     *
     * A short, quick burst effect.
     */
    public static final int POP = 4 /* ::android::hardware::vibrator::V1_2::Effect.THUD implicitly + 1 */;
    /**
     * A heavy click effect.
     *
     * This should produce a sharp striking sensation, like a click but stronger.
     */
    public static final int HEAVY_CLICK = 5 /* ::android::hardware::vibrator::V1_2::Effect.POP implicitly + 1 */;
    /**
     * Ringtone patterns. They may correspond with the device's ringtone audio, or may just be a
     * pattern that can be played as a ringtone with any audio, depending on the device.
     */
    public static final int RINGTONE_1 = 6 /* ::android::hardware::vibrator::V1_2::Effect.HEAVY_CLICK implicitly + 1 */;
    public static final int RINGTONE_2 = 7 /* ::android::hardware::vibrator::V1_2::Effect.RINGTONE_1 implicitly + 1 */;
    public static final int RINGTONE_3 = 8 /* ::android::hardware::vibrator::V1_2::Effect.RINGTONE_2 implicitly + 1 */;
    public static final int RINGTONE_4 = 9 /* ::android::hardware::vibrator::V1_2::Effect.RINGTONE_3 implicitly + 1 */;
    public static final int RINGTONE_5 = 10 /* ::android::hardware::vibrator::V1_2::Effect.RINGTONE_4 implicitly + 1 */;
    public static final int RINGTONE_6 = 11 /* ::android::hardware::vibrator::V1_2::Effect.RINGTONE_5 implicitly + 1 */;
    public static final int RINGTONE_7 = 12 /* ::android::hardware::vibrator::V1_2::Effect.RINGTONE_6 implicitly + 1 */;
    public static final int RINGTONE_8 = 13 /* ::android::hardware::vibrator::V1_2::Effect.RINGTONE_7 implicitly + 1 */;
    public static final int RINGTONE_9 = 14 /* ::android::hardware::vibrator::V1_2::Effect.RINGTONE_8 implicitly + 1 */;
    public static final int RINGTONE_10 = 15 /* ::android::hardware::vibrator::V1_2::Effect.RINGTONE_9 implicitly + 1 */;
    public static final int RINGTONE_11 = 16 /* ::android::hardware::vibrator::V1_2::Effect.RINGTONE_10 implicitly + 1 */;
    public static final int RINGTONE_12 = 17 /* ::android::hardware::vibrator::V1_2::Effect.RINGTONE_11 implicitly + 1 */;
    public static final int RINGTONE_13 = 18 /* ::android::hardware::vibrator::V1_2::Effect.RINGTONE_12 implicitly + 1 */;
    public static final int RINGTONE_14 = 19 /* ::android::hardware::vibrator::V1_2::Effect.RINGTONE_13 implicitly + 1 */;
    public static final int RINGTONE_15 = 20 /* ::android::hardware::vibrator::V1_2::Effect.RINGTONE_14 implicitly + 1 */;
    /**
     * A soft tick effect meant to be played as a texture.
     *
     * A soft, short sensation like the tick of a clock. Unlike regular effects, texture effects
     * are expected to be played multiple times in quick succession, replicating a specific
     * texture to the user as a form of haptic feedback.
     */
    public static final int TEXTURE_TICK = 21 /* ::android::hardware::vibrator::V1_2::Effect.RINGTONE_15 implicitly + 1 */;
    public static final String toString(int o) {
        if (o == CLICK) {
            return "CLICK";
        }
        if (o == DOUBLE_CLICK) {
            return "DOUBLE_CLICK";
        }
        if (o == TICK) {
            return "TICK";
        }
        if (o == THUD) {
            return "THUD";
        }
        if (o == POP) {
            return "POP";
        }
        if (o == HEAVY_CLICK) {
            return "HEAVY_CLICK";
        }
        if (o == RINGTONE_1) {
            return "RINGTONE_1";
        }
        if (o == RINGTONE_2) {
            return "RINGTONE_2";
        }
        if (o == RINGTONE_3) {
            return "RINGTONE_3";
        }
        if (o == RINGTONE_4) {
            return "RINGTONE_4";
        }
        if (o == RINGTONE_5) {
            return "RINGTONE_5";
        }
        if (o == RINGTONE_6) {
            return "RINGTONE_6";
        }
        if (o == RINGTONE_7) {
            return "RINGTONE_7";
        }
        if (o == RINGTONE_8) {
            return "RINGTONE_8";
        }
        if (o == RINGTONE_9) {
            return "RINGTONE_9";
        }
        if (o == RINGTONE_10) {
            return "RINGTONE_10";
        }
        if (o == RINGTONE_11) {
            return "RINGTONE_11";
        }
        if (o == RINGTONE_12) {
            return "RINGTONE_12";
        }
        if (o == RINGTONE_13) {
            return "RINGTONE_13";
        }
        if (o == RINGTONE_14) {
            return "RINGTONE_14";
        }
        if (o == RINGTONE_15) {
            return "RINGTONE_15";
        }
        if (o == TEXTURE_TICK) {
            return "TEXTURE_TICK";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("CLICK"); // CLICK == 0
        if ((o & DOUBLE_CLICK) == DOUBLE_CLICK) {
            list.add("DOUBLE_CLICK");
            flipped |= DOUBLE_CLICK;
        }
        if ((o & TICK) == TICK) {
            list.add("TICK");
            flipped |= TICK;
        }
        if ((o & THUD) == THUD) {
            list.add("THUD");
            flipped |= THUD;
        }
        if ((o & POP) == POP) {
            list.add("POP");
            flipped |= POP;
        }
        if ((o & HEAVY_CLICK) == HEAVY_CLICK) {
            list.add("HEAVY_CLICK");
            flipped |= HEAVY_CLICK;
        }
        if ((o & RINGTONE_1) == RINGTONE_1) {
            list.add("RINGTONE_1");
            flipped |= RINGTONE_1;
        }
        if ((o & RINGTONE_2) == RINGTONE_2) {
            list.add("RINGTONE_2");
            flipped |= RINGTONE_2;
        }
        if ((o & RINGTONE_3) == RINGTONE_3) {
            list.add("RINGTONE_3");
            flipped |= RINGTONE_3;
        }
        if ((o & RINGTONE_4) == RINGTONE_4) {
            list.add("RINGTONE_4");
            flipped |= RINGTONE_4;
        }
        if ((o & RINGTONE_5) == RINGTONE_5) {
            list.add("RINGTONE_5");
            flipped |= RINGTONE_5;
        }
        if ((o & RINGTONE_6) == RINGTONE_6) {
            list.add("RINGTONE_6");
            flipped |= RINGTONE_6;
        }
        if ((o & RINGTONE_7) == RINGTONE_7) {
            list.add("RINGTONE_7");
            flipped |= RINGTONE_7;
        }
        if ((o & RINGTONE_8) == RINGTONE_8) {
            list.add("RINGTONE_8");
            flipped |= RINGTONE_8;
        }
        if ((o & RINGTONE_9) == RINGTONE_9) {
            list.add("RINGTONE_9");
            flipped |= RINGTONE_9;
        }
        if ((o & RINGTONE_10) == RINGTONE_10) {
            list.add("RINGTONE_10");
            flipped |= RINGTONE_10;
        }
        if ((o & RINGTONE_11) == RINGTONE_11) {
            list.add("RINGTONE_11");
            flipped |= RINGTONE_11;
        }
        if ((o & RINGTONE_12) == RINGTONE_12) {
            list.add("RINGTONE_12");
            flipped |= RINGTONE_12;
        }
        if ((o & RINGTONE_13) == RINGTONE_13) {
            list.add("RINGTONE_13");
            flipped |= RINGTONE_13;
        }
        if ((o & RINGTONE_14) == RINGTONE_14) {
            list.add("RINGTONE_14");
            flipped |= RINGTONE_14;
        }
        if ((o & RINGTONE_15) == RINGTONE_15) {
            list.add("RINGTONE_15");
            flipped |= RINGTONE_15;
        }
        if ((o & TEXTURE_TICK) == TEXTURE_TICK) {
            list.add("TEXTURE_TICK");
            flipped |= TEXTURE_TICK;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

