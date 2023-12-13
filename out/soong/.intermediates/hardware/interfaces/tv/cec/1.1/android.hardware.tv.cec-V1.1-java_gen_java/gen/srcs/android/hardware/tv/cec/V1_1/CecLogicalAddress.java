package android.hardware.tv.cec.V1_1;


public final class CecLogicalAddress {
    public static final int TV = 0;
    public static final int RECORDER_1 = 1;
    public static final int RECORDER_2 = 2;
    public static final int TUNER_1 = 3;
    public static final int PLAYBACK_1 = 4;
    public static final int AUDIO_SYSTEM = 5;
    public static final int TUNER_2 = 6;
    public static final int TUNER_3 = 7;
    public static final int PLAYBACK_2 = 8;
    public static final int RECORDER_3 = 9;
    public static final int TUNER_4 = 10;
    public static final int PLAYBACK_3 = 11;
    public static final int FREE_USE = 14;
    public static final int UNREGISTERED = 15;
    public static final int BROADCAST = 15;
    public static final int BACKUP_1 = 12;
    public static final int BACKUP_2 = 13;
    public static final String toString(int o) {
        if (o == TV) {
            return "TV";
        }
        if (o == RECORDER_1) {
            return "RECORDER_1";
        }
        if (o == RECORDER_2) {
            return "RECORDER_2";
        }
        if (o == TUNER_1) {
            return "TUNER_1";
        }
        if (o == PLAYBACK_1) {
            return "PLAYBACK_1";
        }
        if (o == AUDIO_SYSTEM) {
            return "AUDIO_SYSTEM";
        }
        if (o == TUNER_2) {
            return "TUNER_2";
        }
        if (o == TUNER_3) {
            return "TUNER_3";
        }
        if (o == PLAYBACK_2) {
            return "PLAYBACK_2";
        }
        if (o == RECORDER_3) {
            return "RECORDER_3";
        }
        if (o == TUNER_4) {
            return "TUNER_4";
        }
        if (o == PLAYBACK_3) {
            return "PLAYBACK_3";
        }
        if (o == FREE_USE) {
            return "FREE_USE";
        }
        if (o == UNREGISTERED) {
            return "UNREGISTERED";
        }
        if (o == BROADCAST) {
            return "BROADCAST";
        }
        if (o == BACKUP_1) {
            return "BACKUP_1";
        }
        if (o == BACKUP_2) {
            return "BACKUP_2";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("TV"); // TV == 0
        if ((o & RECORDER_1) == RECORDER_1) {
            list.add("RECORDER_1");
            flipped |= RECORDER_1;
        }
        if ((o & RECORDER_2) == RECORDER_2) {
            list.add("RECORDER_2");
            flipped |= RECORDER_2;
        }
        if ((o & TUNER_1) == TUNER_1) {
            list.add("TUNER_1");
            flipped |= TUNER_1;
        }
        if ((o & PLAYBACK_1) == PLAYBACK_1) {
            list.add("PLAYBACK_1");
            flipped |= PLAYBACK_1;
        }
        if ((o & AUDIO_SYSTEM) == AUDIO_SYSTEM) {
            list.add("AUDIO_SYSTEM");
            flipped |= AUDIO_SYSTEM;
        }
        if ((o & TUNER_2) == TUNER_2) {
            list.add("TUNER_2");
            flipped |= TUNER_2;
        }
        if ((o & TUNER_3) == TUNER_3) {
            list.add("TUNER_3");
            flipped |= TUNER_3;
        }
        if ((o & PLAYBACK_2) == PLAYBACK_2) {
            list.add("PLAYBACK_2");
            flipped |= PLAYBACK_2;
        }
        if ((o & RECORDER_3) == RECORDER_3) {
            list.add("RECORDER_3");
            flipped |= RECORDER_3;
        }
        if ((o & TUNER_4) == TUNER_4) {
            list.add("TUNER_4");
            flipped |= TUNER_4;
        }
        if ((o & PLAYBACK_3) == PLAYBACK_3) {
            list.add("PLAYBACK_3");
            flipped |= PLAYBACK_3;
        }
        if ((o & FREE_USE) == FREE_USE) {
            list.add("FREE_USE");
            flipped |= FREE_USE;
        }
        if ((o & UNREGISTERED) == UNREGISTERED) {
            list.add("UNREGISTERED");
            flipped |= UNREGISTERED;
        }
        if ((o & BROADCAST) == BROADCAST) {
            list.add("BROADCAST");
            flipped |= BROADCAST;
        }
        if ((o & BACKUP_1) == BACKUP_1) {
            list.add("BACKUP_1");
            flipped |= BACKUP_1;
        }
        if ((o & BACKUP_2) == BACKUP_2) {
            list.add("BACKUP_2");
            flipped |= BACKUP_2;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

