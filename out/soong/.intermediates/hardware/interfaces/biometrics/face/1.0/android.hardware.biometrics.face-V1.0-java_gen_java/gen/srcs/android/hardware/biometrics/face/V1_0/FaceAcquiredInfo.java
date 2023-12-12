package android.hardware.biometrics.face.V1_0;


public final class FaceAcquiredInfo {
    /**
     * The face acquired was good; no further user interaction is necessary.
     */
    public static final int GOOD = 0;
    /**
     * The face data acquired was too noisy or did not have sufficient detail.
     * This is a catch-all for all acquisition errors not captured by the other
     * constants.
     */
    public static final int INSUFFICIENT = 1;
    /**
     * Because there was too much ambient light, the captured face data was too
     * bright. It's reasonable to return this after multiple
     * FaceAcquiredInfo.INSUFFICIENT.
     *
     * The user is expected to take action to retry the operation in better
     * lighting conditions when this is returned.
     */
    public static final int TOO_BRIGHT = 2;
    /**
     * Because there was not enough illumination, the captured face data was too
     * dark. It's reasonable to return this after multiple
     * FaceAcquiredInfo.INSUFFICIENT.
     *
     * The user is expected to take action to retry the operation in better
     * lighting conditions when this is returned.
     */
    public static final int TOO_DARK = 3;
    /**
     * The detected face is too close to the sensor, and the image cannot be
     * processed.
     *
     * The user is expected to be informed to move further from the sensor when
     * this is returned.
     */
    public static final int TOO_CLOSE = 4;
    /**
     * The detected face is too small, as the user might be too far away from
     * the sensor.
     *
     * The user is expected to be informed to move closer to the sensor when
     * this is returned.
     */
    public static final int TOO_FAR = 5;
    /**
     * Only the upper part of the face was detected. The sensor's field of view
     * is too high.
     *
     * The user should be informed to move up with respect to the sensor when
     * this is returned.
     */
    public static final int FACE_TOO_HIGH = 6;
    /**
     * Only the lower part of the face was detected. The sensor's field of view
     * is too low.
     *
     * The user should be informed to move down with respect to the sensor when
     * this is returned.
     */
    public static final int FACE_TOO_LOW = 7;
    /**
     * Only the right part of the face was detected. The sensor's field of view
     * is too far right.
     *
     * The user should be informed to move to the right with respect to the
     * sensor when this is returned.
     */
    public static final int FACE_TOO_RIGHT = 8;
    /**
     * Only the left part of the face was detected. The sensor's field of view
     * is too far left.
     *
     * The user should be informed to move to the left with respect to the
     * sensor when this is returned.
     */
    public static final int FACE_TOO_LEFT = 9;
    /**
     * The user's eyes have strayed away from the sensor. If this message is
     * sent, the user should be informed to look at the device. If the user
     * can't be found in the frame, one of the other acquisition messages
     * must be sent, e.g. NOT_DETECTED.
     */
    public static final int POOR_GAZE = 10;
    /**
     * No face was detected within the sensor's field of view.
     *
     * The user should be informed to point the sensor to a face when this is
     * returned.
     */
    public static final int NOT_DETECTED = 11;
    /**
     * Too much motion was detected.
     *
     * The user should be informed to keep their face steady relative to the
     * sensor.
     */
    public static final int TOO_MUCH_MOTION = 12;
    /**
     * The sensor needs to be re-calibrated. This is an unexpected condition,
     * and must only be sent if a serious, uncorrectable, and unrecoverable
     * calibration issue is detected which requires user intervention, e.g.
     * re-enrolling. The expected response to this message is to direct the
     * user to re-enroll.
     */
    public static final int RECALIBRATE = 13;
    /**
     * The face is too different from a previous acquisition. This condition
     * only applies to enrollment. This can happen if the user passes the
     * device to someone else in the middle of enrollment.
     */
    public static final int TOO_DIFFERENT = 14;
    /**
     * The face is too similar to a previous acquisition. This condition only
     * applies to enrollment. The user should change their pose.
     */
    public static final int TOO_SIMILAR = 15;
    /**
     * The magnitude of the pan angle of the user’s face with respect to the sensor’s
     * capture plane is too high.
     *
     * The pan angle is defined as the angle swept out by the user’s face turning
     * their neck left and right. The pan angle would be zero if the user faced the
     * camera directly.
     *
     * The user should be informed to look more directly at the camera.
     */
    public static final int PAN_TOO_EXTREME = 16;
    /**
     * The magnitude of the tilt angle of the user’s face with respect to the sensor’s
     * capture plane is too high.
     *
     * The tilt angle is defined as the angle swept out by the user’s face looking up
     * and down. The tilt angle would be zero if the user faced the camera directly.
     *
     * The user should be informed to look more directly at the camera.
     */
    public static final int TILT_TOO_EXTREME = 17;
    /**
     * The magnitude of the roll angle of the user’s face with respect to the sensor’s
     * capture plane is too high.
     *
     * The roll angle is defined as the angle swept out by the user’s face tilting their head
     * towards their shoulders to the left and right. The roll angle would be zero if the user's
     * head is vertically aligned with the camera.
     *
     * The user should be informed to look more directly at the camera.
     */
    public static final int ROLL_TOO_EXTREME = 18;
    /**
     * The user’s face has been obscured by some object.
     *
     * The user should be informed to remove any objects from the line of sight from
     * the sensor to the user’s face.
     */
    public static final int FACE_OBSCURED = 19;
    /**
     * This message represents the earliest message sent at the beginning of the authentication
     * pipeline. It is expected to be used to measure latency. For example, in a camera-based
     * authentication system it's expected to be sent prior to camera initialization. Note this
     * should be sent whenever authentication is restarted (see IBiometricsFace#userActivity).
     * The framework will measure latency based on the time between the last START message and the
     * onAuthenticated callback.
     */
    public static final int START = 20;
    /**
     * The sensor is dirty. The user should be informed to clean the sensor.
     */
    public static final int SENSOR_DIRTY = 21;
    /**
     * Used to enable a vendor-specific acquisition message.
     */
    public static final int VENDOR = 22;
    public static final String toString(int o) {
        if (o == GOOD) {
            return "GOOD";
        }
        if (o == INSUFFICIENT) {
            return "INSUFFICIENT";
        }
        if (o == TOO_BRIGHT) {
            return "TOO_BRIGHT";
        }
        if (o == TOO_DARK) {
            return "TOO_DARK";
        }
        if (o == TOO_CLOSE) {
            return "TOO_CLOSE";
        }
        if (o == TOO_FAR) {
            return "TOO_FAR";
        }
        if (o == FACE_TOO_HIGH) {
            return "FACE_TOO_HIGH";
        }
        if (o == FACE_TOO_LOW) {
            return "FACE_TOO_LOW";
        }
        if (o == FACE_TOO_RIGHT) {
            return "FACE_TOO_RIGHT";
        }
        if (o == FACE_TOO_LEFT) {
            return "FACE_TOO_LEFT";
        }
        if (o == POOR_GAZE) {
            return "POOR_GAZE";
        }
        if (o == NOT_DETECTED) {
            return "NOT_DETECTED";
        }
        if (o == TOO_MUCH_MOTION) {
            return "TOO_MUCH_MOTION";
        }
        if (o == RECALIBRATE) {
            return "RECALIBRATE";
        }
        if (o == TOO_DIFFERENT) {
            return "TOO_DIFFERENT";
        }
        if (o == TOO_SIMILAR) {
            return "TOO_SIMILAR";
        }
        if (o == PAN_TOO_EXTREME) {
            return "PAN_TOO_EXTREME";
        }
        if (o == TILT_TOO_EXTREME) {
            return "TILT_TOO_EXTREME";
        }
        if (o == ROLL_TOO_EXTREME) {
            return "ROLL_TOO_EXTREME";
        }
        if (o == FACE_OBSCURED) {
            return "FACE_OBSCURED";
        }
        if (o == START) {
            return "START";
        }
        if (o == SENSOR_DIRTY) {
            return "SENSOR_DIRTY";
        }
        if (o == VENDOR) {
            return "VENDOR";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("GOOD"); // GOOD == 0
        if ((o & INSUFFICIENT) == INSUFFICIENT) {
            list.add("INSUFFICIENT");
            flipped |= INSUFFICIENT;
        }
        if ((o & TOO_BRIGHT) == TOO_BRIGHT) {
            list.add("TOO_BRIGHT");
            flipped |= TOO_BRIGHT;
        }
        if ((o & TOO_DARK) == TOO_DARK) {
            list.add("TOO_DARK");
            flipped |= TOO_DARK;
        }
        if ((o & TOO_CLOSE) == TOO_CLOSE) {
            list.add("TOO_CLOSE");
            flipped |= TOO_CLOSE;
        }
        if ((o & TOO_FAR) == TOO_FAR) {
            list.add("TOO_FAR");
            flipped |= TOO_FAR;
        }
        if ((o & FACE_TOO_HIGH) == FACE_TOO_HIGH) {
            list.add("FACE_TOO_HIGH");
            flipped |= FACE_TOO_HIGH;
        }
        if ((o & FACE_TOO_LOW) == FACE_TOO_LOW) {
            list.add("FACE_TOO_LOW");
            flipped |= FACE_TOO_LOW;
        }
        if ((o & FACE_TOO_RIGHT) == FACE_TOO_RIGHT) {
            list.add("FACE_TOO_RIGHT");
            flipped |= FACE_TOO_RIGHT;
        }
        if ((o & FACE_TOO_LEFT) == FACE_TOO_LEFT) {
            list.add("FACE_TOO_LEFT");
            flipped |= FACE_TOO_LEFT;
        }
        if ((o & POOR_GAZE) == POOR_GAZE) {
            list.add("POOR_GAZE");
            flipped |= POOR_GAZE;
        }
        if ((o & NOT_DETECTED) == NOT_DETECTED) {
            list.add("NOT_DETECTED");
            flipped |= NOT_DETECTED;
        }
        if ((o & TOO_MUCH_MOTION) == TOO_MUCH_MOTION) {
            list.add("TOO_MUCH_MOTION");
            flipped |= TOO_MUCH_MOTION;
        }
        if ((o & RECALIBRATE) == RECALIBRATE) {
            list.add("RECALIBRATE");
            flipped |= RECALIBRATE;
        }
        if ((o & TOO_DIFFERENT) == TOO_DIFFERENT) {
            list.add("TOO_DIFFERENT");
            flipped |= TOO_DIFFERENT;
        }
        if ((o & TOO_SIMILAR) == TOO_SIMILAR) {
            list.add("TOO_SIMILAR");
            flipped |= TOO_SIMILAR;
        }
        if ((o & PAN_TOO_EXTREME) == PAN_TOO_EXTREME) {
            list.add("PAN_TOO_EXTREME");
            flipped |= PAN_TOO_EXTREME;
        }
        if ((o & TILT_TOO_EXTREME) == TILT_TOO_EXTREME) {
            list.add("TILT_TOO_EXTREME");
            flipped |= TILT_TOO_EXTREME;
        }
        if ((o & ROLL_TOO_EXTREME) == ROLL_TOO_EXTREME) {
            list.add("ROLL_TOO_EXTREME");
            flipped |= ROLL_TOO_EXTREME;
        }
        if ((o & FACE_OBSCURED) == FACE_OBSCURED) {
            list.add("FACE_OBSCURED");
            flipped |= FACE_OBSCURED;
        }
        if ((o & START) == START) {
            list.add("START");
            flipped |= START;
        }
        if ((o & SENSOR_DIRTY) == SENSOR_DIRTY) {
            list.add("SENSOR_DIRTY");
            flipped |= SENSOR_DIRTY;
        }
        if ((o & VENDOR) == VENDOR) {
            list.add("VENDOR");
            flipped |= VENDOR;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

