package android.hardware.health.V2_0;


public final class DiskStats {
    /**
     * Number of reads processed.
     */
    public long reads = 0L;
    /**
     * number of read I/Os merged with in-queue I/Os.
     */
    public long readMerges = 0L;
    /**
     * number of sectors read.
     */
    public long readSectors = 0L;
    /**
     * total wait time for read requests.
     */
    public long readTicks = 0L;
    /**
     * number of writes processed.
     */
    public long writes = 0L;
    /**
     * number of writes merged with in-queue I/Os.
     */
    public long writeMerges = 0L;
    /**
     * number of sectors written.
     */
    public long writeSectors = 0L;
    /**
     * total wait time for write requests.
     */
    public long writeTicks = 0L;
    /**
     * number of I/Os currently in flight.
     */
    public long ioInFlight = 0L;
    /**
     * total time this block device has been active.
     */
    public long ioTicks = 0L;
    /**
     * total wait time for all requests.
     */
    public long ioInQueue = 0L;
    /**
     * Attributes of the memory device.
     */
    public android.hardware.health.V2_0.StorageAttribute attr = new android.hardware.health.V2_0.StorageAttribute();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.health.V2_0.DiskStats.class) {
            return false;
        }
        android.hardware.health.V2_0.DiskStats other = (android.hardware.health.V2_0.DiskStats)otherObject;
        if (this.reads != other.reads) {
            return false;
        }
        if (this.readMerges != other.readMerges) {
            return false;
        }
        if (this.readSectors != other.readSectors) {
            return false;
        }
        if (this.readTicks != other.readTicks) {
            return false;
        }
        if (this.writes != other.writes) {
            return false;
        }
        if (this.writeMerges != other.writeMerges) {
            return false;
        }
        if (this.writeSectors != other.writeSectors) {
            return false;
        }
        if (this.writeTicks != other.writeTicks) {
            return false;
        }
        if (this.ioInFlight != other.ioInFlight) {
            return false;
        }
        if (this.ioTicks != other.ioTicks) {
            return false;
        }
        if (this.ioInQueue != other.ioInQueue) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.attr, other.attr)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.reads), 
                android.os.HidlSupport.deepHashCode(this.readMerges), 
                android.os.HidlSupport.deepHashCode(this.readSectors), 
                android.os.HidlSupport.deepHashCode(this.readTicks), 
                android.os.HidlSupport.deepHashCode(this.writes), 
                android.os.HidlSupport.deepHashCode(this.writeMerges), 
                android.os.HidlSupport.deepHashCode(this.writeSectors), 
                android.os.HidlSupport.deepHashCode(this.writeTicks), 
                android.os.HidlSupport.deepHashCode(this.ioInFlight), 
                android.os.HidlSupport.deepHashCode(this.ioTicks), 
                android.os.HidlSupport.deepHashCode(this.ioInQueue), 
                android.os.HidlSupport.deepHashCode(this.attr));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".reads = ");
        builder.append(this.reads);
        builder.append(", .readMerges = ");
        builder.append(this.readMerges);
        builder.append(", .readSectors = ");
        builder.append(this.readSectors);
        builder.append(", .readTicks = ");
        builder.append(this.readTicks);
        builder.append(", .writes = ");
        builder.append(this.writes);
        builder.append(", .writeMerges = ");
        builder.append(this.writeMerges);
        builder.append(", .writeSectors = ");
        builder.append(this.writeSectors);
        builder.append(", .writeTicks = ");
        builder.append(this.writeTicks);
        builder.append(", .ioInFlight = ");
        builder.append(this.ioInFlight);
        builder.append(", .ioTicks = ");
        builder.append(this.ioTicks);
        builder.append(", .ioInQueue = ");
        builder.append(this.ioInQueue);
        builder.append(", .attr = ");
        builder.append(this.attr);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(112 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<DiskStats> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<DiskStats> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 112,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.health.V2_0.DiskStats _hidl_vec_element = new android.hardware.health.V2_0.DiskStats();
                ((android.hardware.health.V2_0.DiskStats) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 112);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        reads = _hidl_blob.getInt64(_hidl_offset + 0);
        readMerges = _hidl_blob.getInt64(_hidl_offset + 8);
        readSectors = _hidl_blob.getInt64(_hidl_offset + 16);
        readTicks = _hidl_blob.getInt64(_hidl_offset + 24);
        writes = _hidl_blob.getInt64(_hidl_offset + 32);
        writeMerges = _hidl_blob.getInt64(_hidl_offset + 40);
        writeSectors = _hidl_blob.getInt64(_hidl_offset + 48);
        writeTicks = _hidl_blob.getInt64(_hidl_offset + 56);
        ioInFlight = _hidl_blob.getInt64(_hidl_offset + 64);
        ioTicks = _hidl_blob.getInt64(_hidl_offset + 72);
        ioInQueue = _hidl_blob.getInt64(_hidl_offset + 80);
        ((android.hardware.health.V2_0.StorageAttribute) attr).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 88);
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(112 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<DiskStats> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 112));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 112);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt64(_hidl_offset + 0, reads);
        _hidl_blob.putInt64(_hidl_offset + 8, readMerges);
        _hidl_blob.putInt64(_hidl_offset + 16, readSectors);
        _hidl_blob.putInt64(_hidl_offset + 24, readTicks);
        _hidl_blob.putInt64(_hidl_offset + 32, writes);
        _hidl_blob.putInt64(_hidl_offset + 40, writeMerges);
        _hidl_blob.putInt64(_hidl_offset + 48, writeSectors);
        _hidl_blob.putInt64(_hidl_offset + 56, writeTicks);
        _hidl_blob.putInt64(_hidl_offset + 64, ioInFlight);
        _hidl_blob.putInt64(_hidl_offset + 72, ioTicks);
        _hidl_blob.putInt64(_hidl_offset + 80, ioInQueue);
        attr.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 88);
    }
};

