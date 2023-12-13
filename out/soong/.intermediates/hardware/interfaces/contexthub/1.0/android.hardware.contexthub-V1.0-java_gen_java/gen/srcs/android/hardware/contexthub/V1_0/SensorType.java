package android.hardware.contexthub.V1_0;


public final class SensorType {
    public static final int RESERVED = 0;
    public static final int ACCELEROMETER = 1 /* ::android::hardware::contexthub::V1_0::SensorType.RESERVED implicitly + 1 */;
    public static final int GYROSCOPE = 2 /* ::android::hardware::contexthub::V1_0::SensorType.ACCELEROMETER implicitly + 1 */;
    public static final int MAGNETOMETER = 3 /* ::android::hardware::contexthub::V1_0::SensorType.GYROSCOPE implicitly + 1 */;
    public static final int BAROMETER = 4 /* ::android::hardware::contexthub::V1_0::SensorType.MAGNETOMETER implicitly + 1 */;
    public static final int PROXIMITY_SENSOR = 5 /* ::android::hardware::contexthub::V1_0::SensorType.BAROMETER implicitly + 1 */;
    public static final int AMBIENT_LIGHT_SENSOR = 6 /* ::android::hardware::contexthub::V1_0::SensorType.PROXIMITY_SENSOR implicitly + 1 */;
    public static final int STATIONARY_DETECT = 7 /* ::android::hardware::contexthub::V1_0::SensorType.AMBIENT_LIGHT_SENSOR implicitly + 1 */;
    public static final int INSTANT_MOTION_DETECT = 8 /* ::android::hardware::contexthub::V1_0::SensorType.STATIONARY_DETECT implicitly + 1 */;
    public static final int GPS = 256 /* 0x100 */;
    public static final int WIFI = 512 /* 0x200 */;
    public static final int AUDIO = 768 /* 0x300 */;
    public static final int CAMERA = 1024 /* 0x400 */;
    public static final int BLE = 1280 /* 0x500 */;
    public static final int WWAN = 1536 /* 0x600 */;
    public static final int PRIVATE_SENSOR_BASE = 65536 /* 0x10000 */;
    public static final String toString(int o) {
        if (o == RESERVED) {
            return "RESERVED";
        }
        if (o == ACCELEROMETER) {
            return "ACCELEROMETER";
        }
        if (o == GYROSCOPE) {
            return "GYROSCOPE";
        }
        if (o == MAGNETOMETER) {
            return "MAGNETOMETER";
        }
        if (o == BAROMETER) {
            return "BAROMETER";
        }
        if (o == PROXIMITY_SENSOR) {
            return "PROXIMITY_SENSOR";
        }
        if (o == AMBIENT_LIGHT_SENSOR) {
            return "AMBIENT_LIGHT_SENSOR";
        }
        if (o == STATIONARY_DETECT) {
            return "STATIONARY_DETECT";
        }
        if (o == INSTANT_MOTION_DETECT) {
            return "INSTANT_MOTION_DETECT";
        }
        if (o == GPS) {
            return "GPS";
        }
        if (o == WIFI) {
            return "WIFI";
        }
        if (o == AUDIO) {
            return "AUDIO";
        }
        if (o == CAMERA) {
            return "CAMERA";
        }
        if (o == BLE) {
            return "BLE";
        }
        if (o == WWAN) {
            return "WWAN";
        }
        if (o == PRIVATE_SENSOR_BASE) {
            return "PRIVATE_SENSOR_BASE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("RESERVED"); // RESERVED == 0
        if ((o & ACCELEROMETER) == ACCELEROMETER) {
            list.add("ACCELEROMETER");
            flipped |= ACCELEROMETER;
        }
        if ((o & GYROSCOPE) == GYROSCOPE) {
            list.add("GYROSCOPE");
            flipped |= GYROSCOPE;
        }
        if ((o & MAGNETOMETER) == MAGNETOMETER) {
            list.add("MAGNETOMETER");
            flipped |= MAGNETOMETER;
        }
        if ((o & BAROMETER) == BAROMETER) {
            list.add("BAROMETER");
            flipped |= BAROMETER;
        }
        if ((o & PROXIMITY_SENSOR) == PROXIMITY_SENSOR) {
            list.add("PROXIMITY_SENSOR");
            flipped |= PROXIMITY_SENSOR;
        }
        if ((o & AMBIENT_LIGHT_SENSOR) == AMBIENT_LIGHT_SENSOR) {
            list.add("AMBIENT_LIGHT_SENSOR");
            flipped |= AMBIENT_LIGHT_SENSOR;
        }
        if ((o & STATIONARY_DETECT) == STATIONARY_DETECT) {
            list.add("STATIONARY_DETECT");
            flipped |= STATIONARY_DETECT;
        }
        if ((o & INSTANT_MOTION_DETECT) == INSTANT_MOTION_DETECT) {
            list.add("INSTANT_MOTION_DETECT");
            flipped |= INSTANT_MOTION_DETECT;
        }
        if ((o & GPS) == GPS) {
            list.add("GPS");
            flipped |= GPS;
        }
        if ((o & WIFI) == WIFI) {
            list.add("WIFI");
            flipped |= WIFI;
        }
        if ((o & AUDIO) == AUDIO) {
            list.add("AUDIO");
            flipped |= AUDIO;
        }
        if ((o & CAMERA) == CAMERA) {
            list.add("CAMERA");
            flipped |= CAMERA;
        }
        if ((o & BLE) == BLE) {
            list.add("BLE");
            flipped |= BLE;
        }
        if ((o & WWAN) == WWAN) {
            list.add("WWAN");
            flipped |= WWAN;
        }
        if ((o & PRIVATE_SENSOR_BASE) == PRIVATE_SENSOR_BASE) {
            list.add("PRIVATE_SENSOR_BASE");
            flipped |= PRIVATE_SENSOR_BASE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

