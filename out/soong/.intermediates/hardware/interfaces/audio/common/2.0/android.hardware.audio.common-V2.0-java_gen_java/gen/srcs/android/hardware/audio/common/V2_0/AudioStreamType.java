package android.hardware.audio.common.V2_0;


public final class AudioStreamType {
    public static final int DEFAULT = -1 /* -1 */;
    public static final int MIN = 0;
    public static final int VOICE_CALL = 0;
    public static final int SYSTEM = 1;
    public static final int RING = 2;
    public static final int MUSIC = 3;
    public static final int ALARM = 4;
    public static final int NOTIFICATION = 5;
    public static final int BLUETOOTH_SCO = 6;
    public static final int ENFORCED_AUDIBLE = 7;
    public static final int DTMF = 8;
    public static final int TTS = 9;
    public static final int ACCESSIBILITY = 10;
    public static final int REROUTING = 11;
    public static final int PATCH = 12;
    public static final int PUBLIC_CNT = 11 /* ACCESSIBILITY + 1 */;
    public static final int FOR_POLICY_CNT = 12 /* PATCH */;
    public static final int CNT = 13 /* PATCH + 1 */;
    public static final String toString(int o) {
        if (o == DEFAULT) {
            return "DEFAULT";
        }
        if (o == MIN) {
            return "MIN";
        }
        if (o == VOICE_CALL) {
            return "VOICE_CALL";
        }
        if (o == SYSTEM) {
            return "SYSTEM";
        }
        if (o == RING) {
            return "RING";
        }
        if (o == MUSIC) {
            return "MUSIC";
        }
        if (o == ALARM) {
            return "ALARM";
        }
        if (o == NOTIFICATION) {
            return "NOTIFICATION";
        }
        if (o == BLUETOOTH_SCO) {
            return "BLUETOOTH_SCO";
        }
        if (o == ENFORCED_AUDIBLE) {
            return "ENFORCED_AUDIBLE";
        }
        if (o == DTMF) {
            return "DTMF";
        }
        if (o == TTS) {
            return "TTS";
        }
        if (o == ACCESSIBILITY) {
            return "ACCESSIBILITY";
        }
        if (o == REROUTING) {
            return "REROUTING";
        }
        if (o == PATCH) {
            return "PATCH";
        }
        if (o == PUBLIC_CNT) {
            return "PUBLIC_CNT";
        }
        if (o == FOR_POLICY_CNT) {
            return "FOR_POLICY_CNT";
        }
        if (o == CNT) {
            return "CNT";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & DEFAULT) == DEFAULT) {
            list.add("DEFAULT");
            flipped |= DEFAULT;
        }
        list.add("MIN"); // MIN == 0
        list.add("VOICE_CALL"); // VOICE_CALL == 0
        if ((o & SYSTEM) == SYSTEM) {
            list.add("SYSTEM");
            flipped |= SYSTEM;
        }
        if ((o & RING) == RING) {
            list.add("RING");
            flipped |= RING;
        }
        if ((o & MUSIC) == MUSIC) {
            list.add("MUSIC");
            flipped |= MUSIC;
        }
        if ((o & ALARM) == ALARM) {
            list.add("ALARM");
            flipped |= ALARM;
        }
        if ((o & NOTIFICATION) == NOTIFICATION) {
            list.add("NOTIFICATION");
            flipped |= NOTIFICATION;
        }
        if ((o & BLUETOOTH_SCO) == BLUETOOTH_SCO) {
            list.add("BLUETOOTH_SCO");
            flipped |= BLUETOOTH_SCO;
        }
        if ((o & ENFORCED_AUDIBLE) == ENFORCED_AUDIBLE) {
            list.add("ENFORCED_AUDIBLE");
            flipped |= ENFORCED_AUDIBLE;
        }
        if ((o & DTMF) == DTMF) {
            list.add("DTMF");
            flipped |= DTMF;
        }
        if ((o & TTS) == TTS) {
            list.add("TTS");
            flipped |= TTS;
        }
        if ((o & ACCESSIBILITY) == ACCESSIBILITY) {
            list.add("ACCESSIBILITY");
            flipped |= ACCESSIBILITY;
        }
        if ((o & REROUTING) == REROUTING) {
            list.add("REROUTING");
            flipped |= REROUTING;
        }
        if ((o & PATCH) == PATCH) {
            list.add("PATCH");
            flipped |= PATCH;
        }
        if ((o & PUBLIC_CNT) == PUBLIC_CNT) {
            list.add("PUBLIC_CNT");
            flipped |= PUBLIC_CNT;
        }
        if ((o & FOR_POLICY_CNT) == FOR_POLICY_CNT) {
            list.add("FOR_POLICY_CNT");
            flipped |= FOR_POLICY_CNT;
        }
        if ((o & CNT) == CNT) {
            list.add("CNT");
            flipped |= CNT;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

