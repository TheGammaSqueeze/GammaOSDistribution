package android.hardware.soundtrigger.V2_0;


public final class PhraseRecognitionExtra {
    /**
     * keyphrase ID
     */
    public int id = 0;
    /**
     * recognition modes used for this keyphrase
     */
    public int recognitionModes = 0;
    /**
     * confidence level for mode RecognitionMode.VOICE_TRIGGER
     */
    public int confidenceLevel = 0;
    /**
     * list of confidence levels per user for
     * RecognitionMode.USER_IDENTIFICATION and
     * RecognitionMode.USER_AUTHENTICATION
     */
    public java.util.ArrayList<android.hardware.soundtrigger.V2_0.ConfidenceLevel> levels = new java.util.ArrayList<android.hardware.soundtrigger.V2_0.ConfidenceLevel>();

    @Override
    public final boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }
        if (otherObject == null) {
            return false;
        }
        if (otherObject.getClass() != android.hardware.soundtrigger.V2_0.PhraseRecognitionExtra.class) {
            return false;
        }
        android.hardware.soundtrigger.V2_0.PhraseRecognitionExtra other = (android.hardware.soundtrigger.V2_0.PhraseRecognitionExtra)otherObject;
        if (this.id != other.id) {
            return false;
        }
        if (this.recognitionModes != other.recognitionModes) {
            return false;
        }
        if (this.confidenceLevel != other.confidenceLevel) {
            return false;
        }
        if (!android.os.HidlSupport.deepEquals(this.levels, other.levels)) {
            return false;
        }
        return true;
    }

    @Override
    public final int hashCode() {
        return java.util.Objects.hash(
                android.os.HidlSupport.deepHashCode(this.id), 
                android.os.HidlSupport.deepHashCode(this.recognitionModes), 
                android.os.HidlSupport.deepHashCode(this.confidenceLevel), 
                android.os.HidlSupport.deepHashCode(this.levels));
    }

    @Override
    public final String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder();
        builder.append("{");
        builder.append(".id = ");
        builder.append(this.id);
        builder.append(", .recognitionModes = ");
        builder.append(this.recognitionModes);
        builder.append(", .confidenceLevel = ");
        builder.append(this.confidenceLevel);
        builder.append(", .levels = ");
        builder.append(this.levels);
        builder.append("}");
        return builder.toString();
    }

    public final void readFromParcel(android.os.HwParcel parcel) {
        android.os.HwBlob blob = parcel.readBuffer(32 /* size */);
        readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
    }

    public static final java.util.ArrayList<PhraseRecognitionExtra> readVectorFromParcel(android.os.HwParcel parcel) {
        java.util.ArrayList<PhraseRecognitionExtra> _hidl_vec = new java.util.ArrayList();
        android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

        {
            int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 32,_hidl_blob.handle(),
                    0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            _hidl_vec.clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.soundtrigger.V2_0.PhraseRecognitionExtra _hidl_vec_element = new android.hardware.soundtrigger.V2_0.PhraseRecognitionExtra();
                ((android.hardware.soundtrigger.V2_0.PhraseRecognitionExtra) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 32);
                _hidl_vec.add(_hidl_vec_element);
            }
        }

        return _hidl_vec;
    }

    public final void readEmbeddedFromParcel(
            android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
        id = _hidl_blob.getInt32(_hidl_offset + 0);
        recognitionModes = _hidl_blob.getInt32(_hidl_offset + 4);
        confidenceLevel = _hidl_blob.getInt32(_hidl_offset + 8);
        {
            int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */);
            android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                    _hidl_vec_size * 8,_hidl_blob.handle(),
                    _hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

            ((java.util.ArrayList<android.hardware.soundtrigger.V2_0.ConfidenceLevel>) levels).clear();
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                android.hardware.soundtrigger.V2_0.ConfidenceLevel _hidl_vec_element = new android.hardware.soundtrigger.V2_0.ConfidenceLevel();
                ((android.hardware.soundtrigger.V2_0.ConfidenceLevel) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 8);
                ((java.util.ArrayList<android.hardware.soundtrigger.V2_0.ConfidenceLevel>) levels).add(_hidl_vec_element);
            }
        }
    }

    public final void writeToParcel(android.os.HwParcel parcel) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(32 /* size */);
        writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
        parcel.writeBuffer(_hidl_blob);
    }

    public static final void writeVectorToParcel(
            android.os.HwParcel parcel, java.util.ArrayList<PhraseRecognitionExtra> _hidl_vec) {
        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
        {
            int _hidl_vec_size = _hidl_vec.size();
            _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 32));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 32);
            }
            _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }

        parcel.writeBuffer(_hidl_blob);
    }

    public final void writeEmbeddedToBlob(
            android.os.HwBlob _hidl_blob, long _hidl_offset) {
        _hidl_blob.putInt32(_hidl_offset + 0, id);
        _hidl_blob.putInt32(_hidl_offset + 4, recognitionModes);
        _hidl_blob.putInt32(_hidl_offset + 8, confidenceLevel);
        {
            int _hidl_vec_size = levels.size();
            _hidl_blob.putInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
            _hidl_blob.putBool(_hidl_offset + 16 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 8));
            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                levels.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 8);
            }
            _hidl_blob.putBlob(_hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
        }
    }
};

