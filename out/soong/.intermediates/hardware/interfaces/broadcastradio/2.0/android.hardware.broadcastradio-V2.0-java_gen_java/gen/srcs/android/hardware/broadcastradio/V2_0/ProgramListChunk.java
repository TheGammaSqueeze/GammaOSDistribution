package android.hardware.broadcastradio.V2_0;


public final class ProgramListChunk {
    /**
     * Treats all previously added entries as removed.
     *
     * This is meant to save binder transaction bandwidth on 'removed' vector
     * and provide a clear empty state.
     *
     * If set, 'removed' vector must be empty.
     *
     * The client may wait with taking action on this until it received the
     * chunk with complete flag set (to avoid part of stations temporarily
     * disappearing from the list).
     */
    public boolean purge = false;
    /**
     * If false, it means there are still programs not transmitted,
     * due for transmission in following updates.
     *
     * Used by UIs that wait for complete list instead of displaying
     * programs while scanning.
     *
     * After the whole channel range was scanned and all discovered programs
     * were transmitted, the last chunk must have set this flag to true.
     * This must happen within Constants::LIST_COMPLETE_TIMEOUT_MS from the
     * startProgramListUpdates call. If it doesn't, client may assume the tuner
     * came into a bad state and display error message.
     */
    public boolean complete = false;
    /**
     * Added or modified program list entries.
     *
     * Two entries with the same primaryId (ProgramSelector member)
     * are considered the same.
     */
    public java.util.ArrayList<android.hardware.broadcastradio.V2_0.ProgramInfo> modified = new java.util.ArrayList<android.hardware.broadcastradio.V2_0.ProgramInfo>();
    /**
     * Removed program list entries.
     *
     * Contains primaryId (ProgramSelector member) of a program to remove.
     */
    public java.util.ArrayList<android.hardware.broadcastradio.V2_0.ProgramIdentifier> removed = new java.util.ArrayList<android.hardware.broadcastradio.V2_0.ProgramIdentifier>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.broadcastradio.V2_0.ProgramListChunk.class) {
            return false;
        }
        android.hardware.broadcastradio.V2_0.ProgramListChunk other = (android.hardware.broadcastradio.V2_0.ProgramListChunk)otherObject;
        if (this.purge != other.purge) {
            return false;
        }
        if (this.complete != other.complete) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.modified, other.modified)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.removed, other.removed)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.purge), 
                android.os.HidlSupport.deepHashCode(this.complete), 
                android.os.HidlSupport.deepHashCode(this.modified), 
                android.os.HidlSupport.deepHashCode(this.removed));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".purge = ");
        builder.append(this.purge);
        builder.append(", .complete = ");
        builder.append(this.complete);
        builder.append(", .modified = ");
        builder.append(this.modified);
        builder.append(", .removed = ");
        builder.append(this.removed);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(40 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<ProgramListChunk> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<ProgramListChunk> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 40,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.broadcastradio.V2_0.ProgramListChunk _hidl_vec_element = new android.hardware.broadcastradio.V2_0.ProgramListChunk();
                ((android.hardware.broadcastradio.V2_0.ProgramListChunk) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 40);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        purge = _hidl_blob.getBool(_hidl_offset + 0);
        complete = _hidl_blob.getBool(_hidl_offset + 1);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 120,_hidl_blob.handle(),
                    _hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.broadcastradio.V2_0.ProgramInfo>) modified).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.broadcastradio.V2_0.ProgramInfo _hidl_vec_element = new android.hardware.broadcastradio.V2_0.ProgramInfo();
                ((android.hardware.broadcastradio.V2_0.ProgramInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 120);
                ((java.util.ArrayList<android.hardware.broadcastradio.V2_0.ProgramInfo>) modified).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 24 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 16,_hidl_blob.handle(),
                    _hidl_offset + 24 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.broadcastradio.V2_0.ProgramIdentifier>) removed).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.broadcastradio.V2_0.ProgramIdentifier _hidl_vec_element = new android.hardware.broadcastradio.V2_0.ProgramIdentifier();
                ((android.hardware.broadcastradio.V2_0.ProgramIdentifier) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 16);
                ((java.util.ArrayList<android.hardware.broadcastradio.V2_0.ProgramIdentifier>) removed).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(40 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<ProgramListChunk> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 40));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 40);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putBool(_hidl_offset + 0, purge);
        _hidl_blob.putBool(_hidl_offset + 1, complete);
        {
            int _hidl_vec_size = modified.size();
            _hidl_blob.putInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 8 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 120));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                modified.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 120);
            }
            _hidl_blob.putBlob(_hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = removed.size();
            _hidl_blob.putInt32(_hidl_offset + 24 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 24 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 16));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                removed.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 16);
            }
            _hidl_blob.putBlob(_hidl_offset + 24 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

