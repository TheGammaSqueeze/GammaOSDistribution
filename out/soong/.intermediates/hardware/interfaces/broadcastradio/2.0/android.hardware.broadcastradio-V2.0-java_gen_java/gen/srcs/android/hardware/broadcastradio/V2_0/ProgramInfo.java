package android.hardware.broadcastradio.V2_0;


public final class ProgramInfo {
    /**
     * An identifier used to point at the program (primarily to tune to it).
     *
     * This field is required - its type field must not be set to
     * IdentifierType::INVALID.
     */
    public android.hardware.broadcastradio.V2_0.ProgramSelector selector = new android.hardware.broadcastradio.V2_0.ProgramSelector();
    /**
     * Identifier currently used for program selection.
     *
     * It allows to determine which technology is currently used for reception.
     *
     * Some program selectors contain tuning information for different radio
     * technologies (i.e. FM RDS and DAB). For example, user may tune using
     * a ProgramSelector with RDS_PI primary identifier, but the tuner hardware
     * may choose to use DAB technology to make actual tuning. This identifier
     * must reflect that.
     *
     * This field is required for currently tuned program only.
     * For all other items on the program list, its type field must be
     * initialized to IdentifierType::INVALID.
     *
     * Only primary identifiers for a given radio technology are valid:
     *  - AMFM_FREQUENCY for analog AM/FM;
     *  - RDS_PI for FM RDS;
     *  - HD_STATION_ID_EXT;
     *  - DAB_SID_EXT;
     *  - DRMO_SERVICE_ID;
     *  - SXM_SERVICE_ID;
     *  - VENDOR_*;
     *  - more might come in next minor versions of this HAL.
     */
    public android.hardware.broadcastradio.V2_0.ProgramIdentifier logicallyTunedTo = new android.hardware.broadcastradio.V2_0.ProgramIdentifier();
    /**
     * Identifier currently used by hardware to physically tune to a channel.
     *
     * Some radio technologies broadcast the same program on multiple channels,
     * i.e. with RDS AF the same program may be broadcasted on multiple
     * alternative frequencies; the same DAB program may be broadcast on
     * multiple ensembles. This identifier points to the channel to which the
     * radio hardware is physically tuned to.
     *
     * This field is required for currently tuned program only.
     * For all other items on the program list, its type field must be
     * initialized to IdentifierType::INVALID.
     *
     * Only physical identifiers are valid:
     *  - AMFM_FREQUENCY;
     *  - DAB_ENSEMBLE;
     *  - DRMO_FREQUENCY;
     *  - SXM_CHANNEL;
     *  - VENDOR_*;
     *  - more might come in next minor versions of this HAL.
     */
    public android.hardware.broadcastradio.V2_0.ProgramIdentifier physicallyTunedTo = new android.hardware.broadcastradio.V2_0.ProgramIdentifier();
    /**
     * Primary identifiers of related contents.
     *
     * Some radio technologies provide pointers to other programs that carry
     * related content (i.e. DAB soft-links). This field is a list of pointers
     * to other programs on the program list.
     *
     * This is not a list of programs that carry the same content (i.e.
     * DAB hard-links, RDS AF). Switching to programs from this list usually
     * require user action.
     *
     * Please note, that these identifiers do not have to exist on the program
     * list - i.e. DAB tuner may provide information on FM RDS alternatives
     * despite not supporting FM RDS. If the system has multiple tuners, another
     * one may have it on its list.
     *
     * This field is optional (can be empty).
     */
    public java.util.ArrayList<android.hardware.broadcastradio.V2_0.ProgramIdentifier> relatedContent = new java.util.ArrayList<android.hardware.broadcastradio.V2_0.ProgramIdentifier>();
    public int infoFlags;
    /**
     * Signal quality measured in 0% to 100% range to be shown in the UI.
     *
     * The purpose of this field is primarily informative, must not be used to
     * determine to which frequency should it tune to.
     */
    public int signalQuality = 0;
    /**
     * Program metadata (station name, PTY, song title).
     */
    public java.util.ArrayList<android.hardware.broadcastradio.V2_0.Metadata> metadata = new java.util.ArrayList<android.hardware.broadcastradio.V2_0.Metadata>();
    /**
     * Vendor-specific information.
     *
     * It may be used for extra features, not supported by the platform,
     * for example: paid-service=true; bitrate=320kbps.
     */
    public java.util.ArrayList<android.hardware.broadcastradio.V2_0.VendorKeyValue> vendorInfo = new java.util.ArrayList<android.hardware.broadcastradio.V2_0.VendorKeyValue>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.broadcastradio.V2_0.ProgramInfo.class) {
            return false;
        }
        android.hardware.broadcastradio.V2_0.ProgramInfo other = (android.hardware.broadcastradio.V2_0.ProgramInfo)otherObject;
        if (!android.os.HidlSupport.deepEquals(this.selector, other.selector)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.logicallyTunedTo, other.logicallyTunedTo)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.physicallyTunedTo, other.physicallyTunedTo)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.relatedContent, other.relatedContent)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.infoFlags, other.infoFlags)) {
            return false;
        }
        if (this.signalQuality != other.signalQuality) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.metadata, other.metadata)) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.vendorInfo, other.vendorInfo)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.selector), 
                android.os.HidlSupport.deepHashCode(this.logicallyTunedTo), 
                android.os.HidlSupport.deepHashCode(this.physicallyTunedTo), 
                android.os.HidlSupport.deepHashCode(this.relatedContent), 
                android.os.HidlSupport.deepHashCode(this.infoFlags), 
                android.os.HidlSupport.deepHashCode(this.signalQuality), 
                android.os.HidlSupport.deepHashCode(this.metadata), 
                android.os.HidlSupport.deepHashCode(this.vendorInfo));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".selector = ");
        builder.append(this.selector);
        builder.append(", .logicallyTunedTo = ");
        builder.append(this.logicallyTunedTo);
        builder.append(", .physicallyTunedTo = ");
        builder.append(this.physicallyTunedTo);
        builder.append(", .relatedContent = ");
        builder.append(this.relatedContent);
        builder.append(", .infoFlags = ");
        builder.append(android.hardware.broadcastradio.V2_0.ProgramInfoFlags.dumpBitfield(this.infoFlags));
        builder.append(", .signalQuality = ");
        builder.append(this.signalQuality);
        builder.append(", .metadata = ");
        builder.append(this.metadata);
        builder.append(", .vendorInfo = ");
        builder.append(this.vendorInfo);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(120 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<ProgramInfo> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<ProgramInfo> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 120,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.broadcastradio.V2_0.ProgramInfo _hidl_vec_element = new android.hardware.broadcastradio.V2_0.ProgramInfo();
                ((android.hardware.broadcastradio.V2_0.ProgramInfo) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 120);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        ((android.hardware.broadcastradio.V2_0.ProgramSelector) selector).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
        ((android.hardware.broadcastradio.V2_0.ProgramIdentifier) logicallyTunedTo).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 32);
        ((android.hardware.broadcastradio.V2_0.ProgramIdentifier) physicallyTunedTo).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 48);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 64 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 16,_hidl_blob.handle(),
                    _hidl_offset + 64 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.broadcastradio.V2_0.ProgramIdentifier>) relatedContent).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.broadcastradio.V2_0.ProgramIdentifier _hidl_vec_element = new android.hardware.broadcastradio.V2_0.ProgramIdentifier();
                ((android.hardware.broadcastradio.V2_0.ProgramIdentifier) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 16);
                ((java.util.ArrayList<android.hardware.broadcastradio.V2_0.ProgramIdentifier>) relatedContent).add(_hidl_vec_element);
            }
        }
        infoFlags = _hidl_blob.getInt32(_hidl_offset + 80);
        signalQuality = _hidl_blob.getInt32(_hidl_offset + 84);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 88 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 32,_hidl_blob.handle(),
                    _hidl_offset + 88 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.broadcastradio.V2_0.Metadata>) metadata).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.broadcastradio.V2_0.Metadata _hidl_vec_element = new android.hardware.broadcastradio.V2_0.Metadata();
                ((android.hardware.broadcastradio.V2_0.Metadata) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 32);
                ((java.util.ArrayList<android.hardware.broadcastradio.V2_0.Metadata>) metadata).add(_hidl_vec_element);
            }
        }
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 104 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 32,_hidl_blob.handle(),
                    _hidl_offset + 104 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.broadcastradio.V2_0.VendorKeyValue>) vendorInfo).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.broadcastradio.V2_0.VendorKeyValue _hidl_vec_element = new android.hardware.broadcastradio.V2_0.VendorKeyValue();
                ((android.hardware.broadcastradio.V2_0.VendorKeyValue) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 32);
                ((java.util.ArrayList<android.hardware.broadcastradio.V2_0.VendorKeyValue>) vendorInfo).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(120 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<ProgramInfo> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 120));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 120);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        selector.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
        logicallyTunedTo.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 32);
        physicallyTunedTo.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 48);
        {
            int _hidl_vec_size = relatedContent.size();
            _hidl_blob.putInt32(_hidl_offset + 64 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 64 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 16));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                relatedContent.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 16);
            }
            _hidl_blob.putBlob(_hidl_offset + 64 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        _hidl_blob.putInt32(_hidl_offset + 80, infoFlags);
        _hidl_blob.putInt32(_hidl_offset + 84, signalQuality);
        {
            int _hidl_vec_size = metadata.size();
            _hidl_blob.putInt32(_hidl_offset + 88 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 88 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 32));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                metadata.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 32);
            }
            _hidl_blob.putBlob(_hidl_offset + 88 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
        {
            int _hidl_vec_size = vendorInfo.size();
            _hidl_blob.putInt32(_hidl_offset + 104 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 104 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 32));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                vendorInfo.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 32);
            }
            _hidl_blob.putBlob(_hidl_offset + 104 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

