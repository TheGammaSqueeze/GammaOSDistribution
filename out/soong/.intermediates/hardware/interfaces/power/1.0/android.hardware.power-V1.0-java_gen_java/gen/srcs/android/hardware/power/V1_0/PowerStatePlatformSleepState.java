package android.hardware.power.V1_0;


public final class PowerStatePlatformSleepState {
    /**
     * Platform-level Sleep state name.
     */
    public String name = new String();
    /**
     * Time spent in msec at this platform-level sleep state since boot.
     */
    public long residencyInMsecSinceBoot = 0L;
    /**
     * Total number of times system entered this state.
     */
    public long totalTransitions = 0L;
    /**
     * This platform-level sleep state can only be reached during system suspend
     */
    public boolean supportedOnlyInSuspend = false;
    /**
     * voters is useful if the Platform-level sleep state
     * is chosen by aggregation votes from multiple clients/system conditions.
     * All the voters have to say yes or all the system conditions need to be
     * met to enter a platform-level sleep state.
     *
     * Vector of size zero implies either the info is not available
     * or the system does not follow a voting mechanism to choose this
     * Platform-level sleep state.
     */
    public java.util.ArrayList<android.hardware.power.V1_0.PowerStateVoter> voters = new java.util.ArrayList<android.hardware.power.V1_0.PowerStateVoter>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.power.V1_0.PowerStatePlatformSleepState.class) {
            return false;
        }
        android.hardware.power.V1_0.PowerStatePlatformSleepState other = (android.hardware.power.V1_0.PowerStatePlatformSleepState)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.name, other.name)) {
            return false;
        }
        if (this.residencyInMsecSinceBoot != other.residencyInMsecSinceBoot) {
            return false;
        }
        if (this.totalTransitions != other.totalTransitions) {
            return false;
        }
        if (this.supportedOnlyInSuspend != other.supportedOnlyInSuspend) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.voters, other.voters)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.name), 
                android.os.HidlSupport.deepHashCode(this.residencyInMsecSinceBoot), 
                android.os.HidlSupport.deepHashCode(this.totalTransitions), 
                android.os.HidlSupport.deepHashCode(this.supportedOnlyInSuspend), 
                android.os.HidlSupport.deepHashCode(this.voters));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".name = ");
        builder.append(this.name);
        builder.append(", .residencyInMsecSinceBoot = ");
        builder.append(this.residencyInMsecSinceBoot);
        builder.append(", .totalTransitions = ");
        builder.append(this.totalTransitions);
        builder.append(", .supportedOnlyInSuspend = ");
        builder.append(this.supportedOnlyInSuspend);
        builder.append(", .voters = ");
        builder.append(this.voters);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(56 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<PowerStatePlatformSleepState> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<PowerStatePlatformSleepState> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 56,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.power.V1_0.PowerStatePlatformSleepState _hidl_vec_element = new android.hardware.power.V1_0.PowerStatePlatformSleepState();
                ((android.hardware.power.V1_0.PowerStatePlatformSleepState) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 56);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        name = _hidl_blob.getString(_hidl_offset + 0);

        parcel.readEmbeddedBuffer(
                ((String) name).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 0 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        residencyInMsecSinceBoot = _hidl_blob.getInt64(_hidl_offset + 16);
        totalTransitions = _hidl_blob.getInt64(_hidl_offset + 24);
        supportedOnlyInSuspend = _hidl_blob.getBool(_hidl_offset + 32);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 40 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 32,_hidl_blob.handle(),
                    _hidl_offset + 40 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.power.V1_0.PowerStateVoter>) voters).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.power.V1_0.PowerStateVoter _hidl_vec_element = new android.hardware.power.V1_0.PowerStateVoter();
                ((android.hardware.power.V1_0.PowerStateVoter) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 32);
                ((java.util.ArrayList<android.hardware.power.V1_0.PowerStateVoter>) voters).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(56 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<PowerStatePlatformSleepState> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 56));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 56);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putString(_hidl_offset + 0, name);
        _hidl_blob.putInt64(_hidl_offset + 16, residencyInMsecSinceBoot);
        _hidl_blob.putInt64(_hidl_offset + 24, totalTransitions);
        _hidl_blob.putBool(_hidl_offset + 32, supportedOnlyInSuspend);
        {
            int _hidl_vec_size = voters.size();
            _hidl_blob.putInt32(_hidl_offset + 40 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 40 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 32));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                voters.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 32);
            }
            _hidl_blob.putBlob(_hidl_offset + 40 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

