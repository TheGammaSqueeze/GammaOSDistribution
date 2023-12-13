package android.hardware.radio.config.V1_0;


public final class SimSlotStatus {
    /**
     * Card state in the physical slot
     */
    public int cardState = 0;
    /**
     * Slot state Active/Inactive
     */
    public int slotState = 0;
    /**
     * An Answer To Reset (ATR) is a message output by a Smart Card conforming to ISO/IEC 7816
     * standards, following electrical reset of the card's chip. The ATR conveys information about
     * the communication parameters proposed by the card, and the card's nature and state.
     *
     * This data is applicable only when cardState is CardState:PRESENT.
     */
    public String atr = new String();
    public int logicalSlotId = 0;
    /**
     * Integrated Circuit Card IDentifier (ICCID) is Unique Identifier of the SIM CARD. File is
     * located in the SIM card at EFiccid (0x2FE2) as per ETSI 102.221. The ICCID is defined by
     * the ITU-T recommendation E.118 ISO/IEC 7816.
     *
     * This data is applicable only when cardState is CardState:PRESENT.
     */
    public String iccid = new String();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.radio.config.V1_0.SimSlotStatus.class) {
            return false;
        }
        android.hardware.radio.config.V1_0.SimSlotStatus other = (android.hardware.radio.config.V1_0.SimSlotStatus)otherObject;
        if (this.cardState != other.cardState) {
            return false;
        }
        if (this.slotState != other.slotState) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.atr, other.atr)) {
            return false;
        }
        if (this.logicalSlotId != other.logicalSlotId) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.iccid, other.iccid)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.cardState), 
                android.os.HidlSupport.deepHashCode(this.slotState), 
                android.os.HidlSupport.deepHashCode(this.atr), 
                android.os.HidlSupport.deepHashCode(this.logicalSlotId), 
                android.os.HidlSupport.deepHashCode(this.iccid));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".cardState = ");
        builder.append(android.hardware.radio.V1_0.CardState.toString(this.cardState));
        builder.append(", .slotState = ");
        builder.append(android.hardware.radio.config.V1_0.SlotState.toString(this.slotState));
        builder.append(", .atr = ");
        builder.append(this.atr);
        builder.append(", .logicalSlotId = ");
        builder.append(this.logicalSlotId);
        builder.append(", .iccid = ");
        builder.append(this.iccid);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(48 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<SimSlotStatus> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<SimSlotStatus> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 48,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.radio.config.V1_0.SimSlotStatus _hidl_vec_element = new android.hardware.radio.config.V1_0.SimSlotStatus();
                ((android.hardware.radio.config.V1_0.SimSlotStatus) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 48);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        cardState = _hidl_blob.getInt32(_hidl_offset + 0);
        slotState = _hidl_blob.getInt32(_hidl_offset + 4);
        atr = _hidl_blob.getString(_hidl_offset + 8);

        parcel.readEmbeddedBuffer(
                ((String) atr).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 8 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        logicalSlotId = _hidl_blob.getInt32(_hidl_offset + 24);
        iccid = _hidl_blob.getString(_hidl_offset + 32);

        parcel.readEmbeddedBuffer(
                ((String) iccid).getBytes().length + 1,
                _hidl_blob.handle(),
                _hidl_offset + 32 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(48 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<SimSlotStatus> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 48));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 48);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, cardState);
        _hidl_blob.putInt32(_hidl_offset + 4, slotState);
        _hidl_blob.putString(_hidl_offset + 8, atr);
        _hidl_blob.putInt32(_hidl_offset + 24, logicalSlotId);
        _hidl_blob.putString(_hidl_offset + 32, iccid);
    }
};

