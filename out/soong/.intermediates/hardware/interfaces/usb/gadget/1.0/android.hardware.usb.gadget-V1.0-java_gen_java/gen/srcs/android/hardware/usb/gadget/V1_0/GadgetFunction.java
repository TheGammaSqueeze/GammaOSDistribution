package android.hardware.usb.gadget.V1_0;


public final class GadgetFunction {
    /**
     * Removes all the functions and pulls down the gadget.
     */
    public static final long NONE = 0L;
    /**
     * Android Debug Bridge function.
     */
    public static final long ADB = 1L /* 1 << 0 */;
    /**
     * Android open accessory protocol function.
     */
    public static final long ACCESSORY = 2L /* 1 << 1 */;
    /**
     * Media Transfer protocol function.
     */
    public static final long MTP = 4L /* 1 << 2 */;
    /**
     * Peripheral mode USB Midi function.
     */
    public static final long MIDI = 8L /* 1 << 3 */;
    /**
     * Picture transfer protocol function.
     */
    public static final long PTP = 16L /* 1 << 4 */;
    /**
     * Tethering function.
     */
    public static final long RNDIS = 32L /* 1 << 5 */;
    /**
     * AOAv2.0 - Audio Source function.
     */
    public static final long AUDIO_SOURCE = 64L /* 1 << 6 */;
    public static final String toString(long o) {
        if (o == NONE) {
            return "NONE";
        }
        if (o == ADB) {
            return "ADB";
        }
        if (o == ACCESSORY) {
            return "ACCESSORY";
        }
        if (o == MTP) {
            return "MTP";
        }
        if (o == MIDI) {
            return "MIDI";
        }
        if (o == PTP) {
            return "PTP";
        }
        if (o == RNDIS) {
            return "RNDIS";
        }
        if (o == AUDIO_SOURCE) {
            return "AUDIO_SOURCE";
        }
        return "0x" + Long.toHexString(o);
    }

    public static final String dumpBitfield(long o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        long flipped = 0;
        list.add("NONE"); // NONE == 0
        if ((o & ADB) == ADB) {
            list.add("ADB");
            flipped |= ADB;
        }
        if ((o & ACCESSORY) == ACCESSORY) {
            list.add("ACCESSORY");
            flipped |= ACCESSORY;
        }
        if ((o & MTP) == MTP) {
            list.add("MTP");
            flipped |= MTP;
        }
        if ((o & MIDI) == MIDI) {
            list.add("MIDI");
            flipped |= MIDI;
        }
        if ((o & PTP) == PTP) {
            list.add("PTP");
            flipped |= PTP;
        }
        if ((o & RNDIS) == RNDIS) {
            list.add("RNDIS");
            flipped |= RNDIS;
        }
        if ((o & AUDIO_SOURCE) == AUDIO_SOURCE) {
            list.add("AUDIO_SOURCE");
            flipped |= AUDIO_SOURCE;
        }
        if (o != flipped) {
            list.add("0x" + Long.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

