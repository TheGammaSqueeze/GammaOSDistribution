package android.hardware.audio.common.V2_0;


public final class AudioUsage {
    public static final int UNKNOWN = 0;
    public static final int MEDIA = 1;
    public static final int VOICE_COMMUNICATION = 2;
    public static final int VOICE_COMMUNICATION_SIGNALLING = 3;
    public static final int ALARM = 4;
    public static final int NOTIFICATION = 5;
    public static final int NOTIFICATION_TELEPHONY_RINGTONE = 6;
    public static final int NOTIFICATION_COMMUNICATION_REQUEST = 7;
    public static final int NOTIFICATION_COMMUNICATION_INSTANT = 8;
    public static final int NOTIFICATION_COMMUNICATION_DELAYED = 9;
    public static final int NOTIFICATION_EVENT = 10;
    public static final int ASSISTANCE_ACCESSIBILITY = 11;
    public static final int ASSISTANCE_NAVIGATION_GUIDANCE = 12;
    public static final int ASSISTANCE_SONIFICATION = 13;
    public static final int GAME = 14;
    public static final int VIRTUAL_SOURCE = 15;
    public static final int ASSISTANT = 16;
    public static final int CNT = 17 /* ::android::hardware::audio::common::V2_0::AudioUsage.ASSISTANT implicitly + 1 */;
    public static final int MAX = 16 /* CNT - 1 */;
    public static final String toString(int o) {
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        if (o == MEDIA) {
            return "MEDIA";
        }
        if (o == VOICE_COMMUNICATION) {
            return "VOICE_COMMUNICATION";
        }
        if (o == VOICE_COMMUNICATION_SIGNALLING) {
            return "VOICE_COMMUNICATION_SIGNALLING";
        }
        if (o == ALARM) {
            return "ALARM";
        }
        if (o == NOTIFICATION) {
            return "NOTIFICATION";
        }
        if (o == NOTIFICATION_TELEPHONY_RINGTONE) {
            return "NOTIFICATION_TELEPHONY_RINGTONE";
        }
        if (o == NOTIFICATION_COMMUNICATION_REQUEST) {
            return "NOTIFICATION_COMMUNICATION_REQUEST";
        }
        if (o == NOTIFICATION_COMMUNICATION_INSTANT) {
            return "NOTIFICATION_COMMUNICATION_INSTANT";
        }
        if (o == NOTIFICATION_COMMUNICATION_DELAYED) {
            return "NOTIFICATION_COMMUNICATION_DELAYED";
        }
        if (o == NOTIFICATION_EVENT) {
            return "NOTIFICATION_EVENT";
        }
        if (o == ASSISTANCE_ACCESSIBILITY) {
            return "ASSISTANCE_ACCESSIBILITY";
        }
        if (o == ASSISTANCE_NAVIGATION_GUIDANCE) {
            return "ASSISTANCE_NAVIGATION_GUIDANCE";
        }
        if (o == ASSISTANCE_SONIFICATION) {
            return "ASSISTANCE_SONIFICATION";
        }
        if (o == GAME) {
            return "GAME";
        }
        if (o == VIRTUAL_SOURCE) {
            return "VIRTUAL_SOURCE";
        }
        if (o == ASSISTANT) {
            return "ASSISTANT";
        }
        if (o == CNT) {
            return "CNT";
        }
        if (o == MAX) {
            return "MAX";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("UNKNOWN"); // UNKNOWN == 0
        if ((o & MEDIA) == MEDIA) {
            list.add("MEDIA");
            flipped |= MEDIA;
        }
        if ((o & VOICE_COMMUNICATION) == VOICE_COMMUNICATION) {
            list.add("VOICE_COMMUNICATION");
            flipped |= VOICE_COMMUNICATION;
        }
        if ((o & VOICE_COMMUNICATION_SIGNALLING) == VOICE_COMMUNICATION_SIGNALLING) {
            list.add("VOICE_COMMUNICATION_SIGNALLING");
            flipped |= VOICE_COMMUNICATION_SIGNALLING;
        }
        if ((o & ALARM) == ALARM) {
            list.add("ALARM");
            flipped |= ALARM;
        }
        if ((o & NOTIFICATION) == NOTIFICATION) {
            list.add("NOTIFICATION");
            flipped |= NOTIFICATION;
        }
        if ((o & NOTIFICATION_TELEPHONY_RINGTONE) == NOTIFICATION_TELEPHONY_RINGTONE) {
            list.add("NOTIFICATION_TELEPHONY_RINGTONE");
            flipped |= NOTIFICATION_TELEPHONY_RINGTONE;
        }
        if ((o & NOTIFICATION_COMMUNICATION_REQUEST) == NOTIFICATION_COMMUNICATION_REQUEST) {
            list.add("NOTIFICATION_COMMUNICATION_REQUEST");
            flipped |= NOTIFICATION_COMMUNICATION_REQUEST;
        }
        if ((o & NOTIFICATION_COMMUNICATION_INSTANT) == NOTIFICATION_COMMUNICATION_INSTANT) {
            list.add("NOTIFICATION_COMMUNICATION_INSTANT");
            flipped |= NOTIFICATION_COMMUNICATION_INSTANT;
        }
        if ((o & NOTIFICATION_COMMUNICATION_DELAYED) == NOTIFICATION_COMMUNICATION_DELAYED) {
            list.add("NOTIFICATION_COMMUNICATION_DELAYED");
            flipped |= NOTIFICATION_COMMUNICATION_DELAYED;
        }
        if ((o & NOTIFICATION_EVENT) == NOTIFICATION_EVENT) {
            list.add("NOTIFICATION_EVENT");
            flipped |= NOTIFICATION_EVENT;
        }
        if ((o & ASSISTANCE_ACCESSIBILITY) == ASSISTANCE_ACCESSIBILITY) {
            list.add("ASSISTANCE_ACCESSIBILITY");
            flipped |= ASSISTANCE_ACCESSIBILITY;
        }
        if ((o & ASSISTANCE_NAVIGATION_GUIDANCE) == ASSISTANCE_NAVIGATION_GUIDANCE) {
            list.add("ASSISTANCE_NAVIGATION_GUIDANCE");
            flipped |= ASSISTANCE_NAVIGATION_GUIDANCE;
        }
        if ((o & ASSISTANCE_SONIFICATION) == ASSISTANCE_SONIFICATION) {
            list.add("ASSISTANCE_SONIFICATION");
            flipped |= ASSISTANCE_SONIFICATION;
        }
        if ((o & GAME) == GAME) {
            list.add("GAME");
            flipped |= GAME;
        }
        if ((o & VIRTUAL_SOURCE) == VIRTUAL_SOURCE) {
            list.add("VIRTUAL_SOURCE");
            flipped |= VIRTUAL_SOURCE;
        }
        if ((o & ASSISTANT) == ASSISTANT) {
            list.add("ASSISTANT");
            flipped |= ASSISTANT;
        }
        if ((o & CNT) == CNT) {
            list.add("CNT");
            flipped |= CNT;
        }
        if ((o & MAX) == MAX) {
            list.add("MAX");
            flipped |= MAX;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

