package android.hardware.soundtrigger.V2_0;

public interface ISoundTriggerHwCallback extends android.hidl.base.V1_0.IBase {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.soundtrigger@2.0::ISoundTriggerHwCallback";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static ISoundTriggerHwCallback asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof ISoundTriggerHwCallback)) {
            return (ISoundTriggerHwCallback)iface;
        }

        ISoundTriggerHwCallback proxy = new ISoundTriggerHwCallback.Proxy(binder);

        try {
            for (String descriptor : proxy.interfaceChain()) {
                if (descriptor.equals(kInterfaceName)) {
                    return proxy;
                }
            }
        } catch (android.os.RemoteException e) {
        }

        return null;
    }

    /**
     * Does a checked conversion from any interface to this class.
     */
    public static ISoundTriggerHwCallback castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : ISoundTriggerHwCallback.asInterface(iface.asBinder());
    }

    @Override
    public android.os.IHwBinder asBinder();

    /**
     * This will invoke the equivalent of the C++ getService(std::string) if retry is
     * true or tryGetService(std::string) if retry is false. If the service is
     * available on the device and retry is true, this will wait for the service to
     * start.
     *
     * @throws NoSuchElementException if this service is not available
     */
    public static ISoundTriggerHwCallback getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return ISoundTriggerHwCallback.asInterface(android.os.HwBinder.getService("android.hardware.soundtrigger@2.0::ISoundTriggerHwCallback", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static ISoundTriggerHwCallback getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static ISoundTriggerHwCallback getService(String serviceName) throws android.os.RemoteException {
        return ISoundTriggerHwCallback.asInterface(android.os.HwBinder.getService("android.hardware.soundtrigger@2.0::ISoundTriggerHwCallback", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static ISoundTriggerHwCallback getService() throws android.os.RemoteException {
        return getService("default");
    }

    public static final class RecognitionStatus {
        public static final int SUCCESS = 0;
        public static final int ABORT = 1;
        public static final int FAILURE = 2;
        public static final String toString(int o) {
            if (o == SUCCESS) {
                return "SUCCESS";
            }
            if (o == ABORT) {
                return "ABORT";
            }
            if (o == FAILURE) {
                return "FAILURE";
            }
            return "0x" + Integer.toHexString(o);
        }

        public static final String dumpBitfield(int o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            int flipped = 0;
            list.add("SUCCESS"); // SUCCESS == 0
            if ((o & ABORT) == ABORT) {
                list.add("ABORT");
                flipped |= ABORT;
            }
            if ((o & FAILURE) == FAILURE) {
                list.add("FAILURE");
                flipped |= FAILURE;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(o & (~flipped)));
            }
            return String.join(" | ", list);
        }

    };

    public static final class SoundModelStatus {
        public static final int UPDATED = 0;
        public static final String toString(int o) {
            if (o == UPDATED) {
                return "UPDATED";
            }
            return "0x" + Integer.toHexString(o);
        }

        public static final String dumpBitfield(int o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            int flipped = 0;
            list.add("UPDATED"); // UPDATED == 0
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(o & (~flipped)));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Generic recognition event sent via recognition callback
     */
    public final static class RecognitionEvent {
        /**
         * Recognition status e.g. SUCCESS
         */
        public int status = 0;
        /**
         * Sound model type for this event. e.g SoundModelType.TYPE_KEYPHRASE
         */
        public int type = 0;
        /**
         * Handle of loaded sound model which triggered the event
         */
        public int model = 0;
        /**
         * It is possible to capture audio from this
         *
         *
         * utterance buffered by the implementation
         */
        public boolean captureAvailable = false;
        /**
         * Audio session ID. framework use
         */
        public int captureSession = 0;
        /**
         * Delay in ms between end of model detection and start of audio
         * available for capture. A negative value is possible
         * (e.g. if key phrase is also available for capture
         */
        public int captureDelayMs = 0;
        /**
         * Duration in ms of audio captured before the start of the trigger.
         * 0 if none.
         */
        public int capturePreambleMs = 0;
        /**
         * The opaque data is the capture of the trigger sound
         */
        public boolean triggerInData = false;
        /**
         * Audio format of either the trigger in event data or to use for
         * capture of the rest of the utterance
         */
        public android.hardware.audio.common.V2_0.AudioConfig audioConfig = new android.hardware.audio.common.V2_0.AudioConfig();
        /**
         * Opaque event data
         */
        public java.util.ArrayList<Byte> data = new java.util.ArrayList<Byte>();

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.RecognitionEvent.class) {
                return false;
            }
            android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.RecognitionEvent other = (android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.RecognitionEvent)otherObject;
            if (this.status != other.status) {
                return false;
            }
            if (this.type != other.type) {
                return false;
            }
            if (this.model != other.model) {
                return false;
            }
            if (this.captureAvailable != other.captureAvailable) {
                return false;
            }
            if (this.captureSession != other.captureSession) {
                return false;
            }
            if (this.captureDelayMs != other.captureDelayMs) {
                return false;
            }
            if (this.capturePreambleMs != other.capturePreambleMs) {
                return false;
            }
            if (this.triggerInData != other.triggerInData) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.audioConfig, other.audioConfig)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.data, other.data)) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.status), 
                    android.os.HidlSupport.deepHashCode(this.type), 
                    android.os.HidlSupport.deepHashCode(this.model), 
                    android.os.HidlSupport.deepHashCode(this.captureAvailable), 
                    android.os.HidlSupport.deepHashCode(this.captureSession), 
                    android.os.HidlSupport.deepHashCode(this.captureDelayMs), 
                    android.os.HidlSupport.deepHashCode(this.capturePreambleMs), 
                    android.os.HidlSupport.deepHashCode(this.triggerInData), 
                    android.os.HidlSupport.deepHashCode(this.audioConfig), 
                    android.os.HidlSupport.deepHashCode(this.data));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".status = ");
            builder.append(android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.RecognitionStatus.toString(this.status));
            builder.append(", .type = ");
            builder.append(android.hardware.soundtrigger.V2_0.SoundModelType.toString(this.type));
            builder.append(", .model = ");
            builder.append(this.model);
            builder.append(", .captureAvailable = ");
            builder.append(this.captureAvailable);
            builder.append(", .captureSession = ");
            builder.append(this.captureSession);
            builder.append(", .captureDelayMs = ");
            builder.append(this.captureDelayMs);
            builder.append(", .capturePreambleMs = ");
            builder.append(this.capturePreambleMs);
            builder.append(", .triggerInData = ");
            builder.append(this.triggerInData);
            builder.append(", .audioConfig = ");
            builder.append(this.audioConfig);
            builder.append(", .data = ");
            builder.append(this.data);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(120 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<RecognitionEvent> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<RecognitionEvent> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 120,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.RecognitionEvent _hidl_vec_element = new android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.RecognitionEvent();
                    ((android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.RecognitionEvent) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 120);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            status = _hidl_blob.getInt32(_hidl_offset + 0);
            type = _hidl_blob.getInt32(_hidl_offset + 4);
            model = _hidl_blob.getInt32(_hidl_offset + 8);
            captureAvailable = _hidl_blob.getBool(_hidl_offset + 12);
            captureSession = _hidl_blob.getInt32(_hidl_offset + 16);
            captureDelayMs = _hidl_blob.getInt32(_hidl_offset + 20);
            capturePreambleMs = _hidl_blob.getInt32(_hidl_offset + 24);
            triggerInData = _hidl_blob.getBool(_hidl_offset + 28);
            ((android.hardware.audio.common.V2_0.AudioConfig) audioConfig).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 32);
            {
                int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 104 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 1,_hidl_blob.handle(),
                        _hidl_offset + 104 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                ((java.util.ArrayList<Byte>) data).clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    byte _hidl_vec_element = 0;
                    _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                    ((java.util.ArrayList<Byte>) data).add(_hidl_vec_element);
                }
            }
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(120 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<RecognitionEvent> _hidl_vec) {
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
            _hidl_blob.putInt32(_hidl_offset + 0, status);
            _hidl_blob.putInt32(_hidl_offset + 4, type);
            _hidl_blob.putInt32(_hidl_offset + 8, model);
            _hidl_blob.putBool(_hidl_offset + 12, captureAvailable);
            _hidl_blob.putInt32(_hidl_offset + 16, captureSession);
            _hidl_blob.putInt32(_hidl_offset + 20, captureDelayMs);
            _hidl_blob.putInt32(_hidl_offset + 24, capturePreambleMs);
            _hidl_blob.putBool(_hidl_offset + 28, triggerInData);
            audioConfig.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 32);
            {
                int _hidl_vec_size = data.size();
                _hidl_blob.putInt32(_hidl_offset + 104 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(_hidl_offset + 104 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    childBlob.putInt8(_hidl_index_0 * 1, data.get(_hidl_index_0));
                }
                _hidl_blob.putBlob(_hidl_offset + 104 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }
        }
    };

    /**
     * Specialized recognition event for key phrase recognitions
     */
    public final static class PhraseRecognitionEvent {
        /**
         * Common part of the recognition event
         */
        public android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.RecognitionEvent common = new android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.RecognitionEvent();
        /**
         * List of descriptors for each recognized key phrase
         */
        public java.util.ArrayList<android.hardware.soundtrigger.V2_0.PhraseRecognitionExtra> phraseExtras = new java.util.ArrayList<android.hardware.soundtrigger.V2_0.PhraseRecognitionExtra>();

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.PhraseRecognitionEvent.class) {
                return false;
            }
            android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.PhraseRecognitionEvent other = (android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.PhraseRecognitionEvent)otherObject;
            if (!android.os.HidlSupport.deepEquals(this.common, other.common)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.phraseExtras, other.phraseExtras)) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.common), 
                    android.os.HidlSupport.deepHashCode(this.phraseExtras));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".common = ");
            builder.append(this.common);
            builder.append(", .phraseExtras = ");
            builder.append(this.phraseExtras);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(136 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<PhraseRecognitionEvent> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<PhraseRecognitionEvent> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 136,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.PhraseRecognitionEvent _hidl_vec_element = new android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.PhraseRecognitionEvent();
                    ((android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.PhraseRecognitionEvent) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 136);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            ((android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.RecognitionEvent) common).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
            {
                int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 120 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 32,_hidl_blob.handle(),
                        _hidl_offset + 120 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                ((java.util.ArrayList<android.hardware.soundtrigger.V2_0.PhraseRecognitionExtra>) phraseExtras).clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.soundtrigger.V2_0.PhraseRecognitionExtra _hidl_vec_element = new android.hardware.soundtrigger.V2_0.PhraseRecognitionExtra();
                    ((android.hardware.soundtrigger.V2_0.PhraseRecognitionExtra) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 32);
                    ((java.util.ArrayList<android.hardware.soundtrigger.V2_0.PhraseRecognitionExtra>) phraseExtras).add(_hidl_vec_element);
                }
            }
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(136 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<PhraseRecognitionEvent> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 136));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 136);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            common.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
            {
                int _hidl_vec_size = phraseExtras.size();
                _hidl_blob.putInt32(_hidl_offset + 120 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(_hidl_offset + 120 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 32));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    phraseExtras.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 32);
                }
                _hidl_blob.putBlob(_hidl_offset + 120 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }
        }
    };

    /**
     * Event sent via load sound model callback
     */
    public final static class ModelEvent {
        /**
         * Sound model status e.g. SoundModelStatus.UPDATED
         */
        public int status = 0;
        /**
         * Loaded sound model that triggered the event
         */
        public int model = 0;
        /**
         * Opaque event data, passed transparently by the framework
         */
        public java.util.ArrayList<Byte> data = new java.util.ArrayList<Byte>();

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.ModelEvent.class) {
                return false;
            }
            android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.ModelEvent other = (android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.ModelEvent)otherObject;
            if (this.status != other.status) {
                return false;
            }
            if (this.model != other.model) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.data, other.data)) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.status), 
                    android.os.HidlSupport.deepHashCode(this.model), 
                    android.os.HidlSupport.deepHashCode(this.data));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".status = ");
            builder.append(android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.SoundModelStatus.toString(this.status));
            builder.append(", .model = ");
            builder.append(this.model);
            builder.append(", .data = ");
            builder.append(this.data);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(24 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<ModelEvent> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<ModelEvent> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 24,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.ModelEvent _hidl_vec_element = new android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.ModelEvent();
                    ((android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.ModelEvent) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 24);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            status = _hidl_blob.getInt32(_hidl_offset + 0);
            model = _hidl_blob.getInt32(_hidl_offset + 4);
            {
                int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 1,_hidl_blob.handle(),
                        _hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                ((java.util.ArrayList<Byte>) data).clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    byte _hidl_vec_element = 0;
                    _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                    ((java.util.ArrayList<Byte>) data).add(_hidl_vec_element);
                }
            }
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(24 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<ModelEvent> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 24));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 24);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            _hidl_blob.putInt32(_hidl_offset + 0, status);
            _hidl_blob.putInt32(_hidl_offset + 4, model);
            {
                int _hidl_vec_size = data.size();
                _hidl_blob.putInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(_hidl_offset + 8 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    childBlob.putInt8(_hidl_index_0 * 1, data.get(_hidl_index_0));
                }
                _hidl_blob.putBlob(_hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }
        }
    };

    /**
     * Callback method called by the HAL when the sound recognition triggers
     * @param event A RecognitionEvent structure containing detailed results
     *              of the recognition triggered
     * @param cookie The cookie passed by the framework when recognition was
     *               started (see ISoundtriggerHw.startRecognition()
     */
    void recognitionCallback(android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.RecognitionEvent event, int cookie)
        throws android.os.RemoteException;
    /**
     * Callback method called by the HAL when the sound recognition triggers
     * for a key phrase sound model.
     * @param event A RecognitionEvent structure containing detailed results
     *              of the recognition triggered
     * @param cookie The cookie passed by the framework when recognition was
     *               started (see ISoundtriggerHw.startRecognition()
     */
    void phraseRecognitionCallback(android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.PhraseRecognitionEvent event, int cookie)
        throws android.os.RemoteException;
    /**
     * Callback method called by the HAL when the sound model loading completes
     * @param event A ModelEvent structure containing detailed results of the
     *              model loading operation
     * @param cookie The cookie passed by the framework when loading was
     *               initiated (see ISoundtriggerHw.loadSoundModel()
     */
    void soundModelCallback(android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.ModelEvent event, int cookie)
        throws android.os.RemoteException;
    /*
     * Provides run-time type information for this object.
     * For example, for the following interface definition:
     *     package android.hardware.foo@1.0;
     *     interface IParent {};
     *     interface IChild extends IParent {};
     * Calling interfaceChain on an IChild object must yield the following:
     *     ["android.hardware.foo@1.0::IChild",
     *      "android.hardware.foo@1.0::IParent"
     *      "android.hidl.base@1.0::IBase"]
     *
     * @return descriptors a vector of descriptors of the run-time type of the
     *         object.
     */
    java.util.ArrayList<String> interfaceChain()
        throws android.os.RemoteException;
    /*
     * Emit diagnostic information to the given file.
     *
     * Optionally overriden.
     *
     * @param fd      File descriptor to dump data to.
     *                Must only be used for the duration of this call.
     * @param options Arguments for debugging.
     *                Must support empty for default debug information.
     */
    void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options)
        throws android.os.RemoteException;
    /*
     * Provides run-time type information for this object.
     * For example, for the following interface definition:
     *     package android.hardware.foo@1.0;
     *     interface IParent {};
     *     interface IChild extends IParent {};
     * Calling interfaceDescriptor on an IChild object must yield
     *     "android.hardware.foo@1.0::IChild"
     *
     * @return descriptor a descriptor of the run-time type of the
     *         object (the first element of the vector returned by
     *         interfaceChain())
     */
    String interfaceDescriptor()
        throws android.os.RemoteException;
    /*
     * Returns hashes of the source HAL files that define the interfaces of the
     * runtime type information on the object.
     * For example, for the following interface definition:
     *     package android.hardware.foo@1.0;
     *     interface IParent {};
     *     interface IChild extends IParent {};
     * Calling interfaceChain on an IChild object must yield the following:
     *     [(hash of IChild.hal),
     *      (hash of IParent.hal)
     *      (hash of IBase.hal)].
     *
     * SHA-256 is used as the hashing algorithm. Each hash has 32 bytes
     * according to SHA-256 standard.
     *
     * @return hashchain a vector of SHA-1 digests
     */
    java.util.ArrayList<byte[/* 32 */]> getHashChain()
        throws android.os.RemoteException;
    /*
     * This method trigger the interface to enable/disable instrumentation based
     * on system property hal.instrumentation.enable.
     */
    void setHALInstrumentation()
        throws android.os.RemoteException;
    /*
     * Registers a death recipient, to be called when the process hosting this
     * interface dies.
     *
     * @param recipient a hidl_death_recipient callback object
     * @param cookie a cookie that must be returned with the callback
     * @return success whether the death recipient was registered successfully.
     */
    boolean linkToDeath(android.os.IHwBinder.DeathRecipient recipient, long cookie)
        throws android.os.RemoteException;
    /*
     * Provides way to determine if interface is running without requesting
     * any functionality.
     */
    void ping()
        throws android.os.RemoteException;
    /*
     * Get debug information on references on this interface.
     * @return info debugging information. See comments of DebugInfo.
     */
    android.hidl.base.V1_0.DebugInfo getDebugInfo()
        throws android.os.RemoteException;
    /*
     * This method notifies the interface that one or more system properties
     * have changed. The default implementation calls
     * (C++)  report_sysprop_change() in libcutils or
     * (Java) android.os.SystemProperties.reportSyspropChanged,
     * which in turn calls a set of registered callbacks (eg to update trace
     * tags).
     */
    void notifySyspropsChanged()
        throws android.os.RemoteException;
    /*
     * Unregisters the registered death recipient. If this service was registered
     * multiple times with the same exact death recipient, this unlinks the most
     * recently registered one.
     *
     * @param recipient a previously registered hidl_death_recipient callback
     * @return success whether the death recipient was unregistered successfully.
     */
    boolean unlinkToDeath(android.os.IHwBinder.DeathRecipient recipient)
        throws android.os.RemoteException;

    public static final class Proxy implements ISoundTriggerHwCallback {
        private android.os.IHwBinder mRemote;

        public Proxy(android.os.IHwBinder remote) {
            mRemote = java.util.Objects.requireNonNull(remote);
        }

        @Override
        public android.os.IHwBinder asBinder() {
            return mRemote;
        }

        @Override
        public String toString() {
            try {
                return this.interfaceDescriptor() + "@Proxy";
            } catch (android.os.RemoteException ex) {
                /* ignored; handled below. */
            }
            return "[class or subclass of " + ISoundTriggerHwCallback.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::soundtrigger::V2_0::ISoundTriggerHwCallback follow.
        @Override
        public void recognitionCallback(android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.RecognitionEvent event, int cookie)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.kInterfaceName);
            ((android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.RecognitionEvent) event).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(cookie);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* recognitionCallback */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void phraseRecognitionCallback(android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.PhraseRecognitionEvent event, int cookie)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.kInterfaceName);
            ((android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.PhraseRecognitionEvent) event).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(cookie);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* phraseRecognitionCallback */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void soundModelCallback(android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.ModelEvent event, int cookie)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.kInterfaceName);
            ((android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.ModelEvent) event).writeToParcel(_hidl_request);
            _hidl_request.writeInt32(cookie);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(3 /* soundModelCallback */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hidl::base::V1_0::IBase follow.
        @Override
        public java.util.ArrayList<String> interfaceChain()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(256067662 /* interfaceChain */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                java.util.ArrayList<String> _hidl_out_descriptors = _hidl_reply.readStringVector();
                return _hidl_out_descriptors;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);
            _hidl_request.writeNativeHandle(fd);
            _hidl_request.writeStringVector(options);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(256131655 /* debug */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public String interfaceDescriptor()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(256136003 /* interfaceDescriptor */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                String _hidl_out_descriptor = _hidl_reply.readString();
                return _hidl_out_descriptor;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public java.util.ArrayList<byte[/* 32 */]> getHashChain()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(256398152 /* getHashChain */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                java.util.ArrayList<byte[/* 32 */]> _hidl_out_hashchain =  new java.util.ArrayList<byte[/* 32 */]>();
                {
                    android.os.HwBlob _hidl_blob = _hidl_reply.readBuffer(16 /* size */);
                    {
                        int _hidl_vec_size = _hidl_blob.getInt32(0 /* offset */ + 8 /* offsetof(hidl_vec<T>, mSize) */);
                        android.os.HwBlob childBlob = _hidl_reply.readEmbeddedBuffer(
                                _hidl_vec_size * 32,_hidl_blob.handle(),
                                0 /* offset */ + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                        ((java.util.ArrayList<byte[/* 32 */]>) _hidl_out_hashchain).clear();
                        for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                            byte[/* 32 */] _hidl_vec_element = new byte[32];
                            {
                                long _hidl_array_offset_1 = _hidl_index_0 * 32;
                                childBlob.copyToInt8Array(_hidl_array_offset_1, (byte[/* 32 */]) _hidl_vec_element, 32 /* size */);
                                _hidl_array_offset_1 += 32 * 1;
                            }
                            ((java.util.ArrayList<byte[/* 32 */]>) _hidl_out_hashchain).add(_hidl_vec_element);
                        }
                    }
                }
                return _hidl_out_hashchain;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void setHALInstrumentation()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(256462420 /* setHALInstrumentation */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean linkToDeath(android.os.IHwBinder.DeathRecipient recipient, long cookie)
                throws android.os.RemoteException {
            return mRemote.linkToDeath(recipient, cookie);
        }
        @Override
        public void ping()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(256921159 /* ping */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hidl.base.V1_0.DebugInfo getDebugInfo()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(257049926 /* getDebugInfo */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hidl.base.V1_0.DebugInfo _hidl_out_info = new android.hidl.base.V1_0.DebugInfo();
                ((android.hidl.base.V1_0.DebugInfo) _hidl_out_info).readFromParcel(_hidl_reply);
                return _hidl_out_info;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void notifySyspropsChanged()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hidl.base.V1_0.IBase.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(257120595 /* notifySyspropsChanged */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public boolean unlinkToDeath(android.os.IHwBinder.DeathRecipient recipient)
                throws android.os.RemoteException {
            return mRemote.unlinkToDeath(recipient);
        }
    }

    public static abstract class Stub extends android.os.HwBinder implements ISoundTriggerHwCallback {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{26,110,43,-46,-119,-14,41,49,-59,38,-78,25,22,-111,15,29,76,67,107,122,-53,-107,86,-28,36,61,-28,-50,-114,108,-62,-28} /* 1a6e2bd289f22931c526b21916910f1d4c436b7acb9556e4243de4ce8e6cc2e4 */,
                    new byte[/* 32 */]{-20,127,-41,-98,-48,45,-6,-123,-68,73,-108,38,-83,-82,62,-66,35,-17,5,36,-13,-51,105,87,19,-109,36,-72,59,24,-54,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */));

        }

        @Override
        public final void setHALInstrumentation() {

        }

        @Override
        public final boolean linkToDeath(android.os.IHwBinder.DeathRecipient recipient, long cookie) {
            return true;

        }

        @Override
        public final void ping() {
            return;

        }

        @Override
        public final android.hidl.base.V1_0.DebugInfo getDebugInfo() {
            android.hidl.base.V1_0.DebugInfo info = new android.hidl.base.V1_0.DebugInfo();
            info.pid = android.os.HidlSupport.getPidIfSharable();
            info.ptr = 0;
            info.arch = android.hidl.base.V1_0.DebugInfo.Architecture.UNKNOWN;
            return info;

        }

        @Override
        public final void notifySyspropsChanged() {
            android.os.HwBinder.enableInstrumentation();

        }

        @Override
        public final boolean unlinkToDeath(android.os.IHwBinder.DeathRecipient recipient) {
            return true;

        }

        @Override
        public android.os.IHwInterface queryLocalInterface(String descriptor) {
            if (kInterfaceName.equals(descriptor)) {
                return this;
            }
            return null;
        }

        public void registerAsService(String serviceName) throws android.os.RemoteException {
            registerService(serviceName);
        }

        @Override
        public String toString() {
            return this.interfaceDescriptor() + "@Stub";
        }

        @Override
        public void onTransact(int _hidl_code, android.os.HwParcel _hidl_request, final android.os.HwParcel _hidl_reply, int _hidl_flags)
                throws android.os.RemoteException {
            switch (_hidl_code) {
                case 1 /* recognitionCallback */:
                {
                    _hidl_request.enforceInterface(android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.kInterfaceName);

                    android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.RecognitionEvent event = new android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.RecognitionEvent();
                    ((android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.RecognitionEvent) event).readFromParcel(_hidl_request);
                    int cookie = _hidl_request.readInt32();
                    recognitionCallback(event, cookie);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 2 /* phraseRecognitionCallback */:
                {
                    _hidl_request.enforceInterface(android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.kInterfaceName);

                    android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.PhraseRecognitionEvent event = new android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.PhraseRecognitionEvent();
                    ((android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.PhraseRecognitionEvent) event).readFromParcel(_hidl_request);
                    int cookie = _hidl_request.readInt32();
                    phraseRecognitionCallback(event, cookie);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 3 /* soundModelCallback */:
                {
                    _hidl_request.enforceInterface(android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.kInterfaceName);

                    android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.ModelEvent event = new android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.ModelEvent();
                    ((android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.ModelEvent) event).readFromParcel(_hidl_request);
                    int cookie = _hidl_request.readInt32();
                    soundModelCallback(event, cookie);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 256067662 /* interfaceChain */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    java.util.ArrayList<String> _hidl_out_descriptors = interfaceChain();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeStringVector(_hidl_out_descriptors);
                    _hidl_reply.send();
                    break;
                }

                case 256131655 /* debug */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    android.os.NativeHandle fd = _hidl_request.readNativeHandle();
                    java.util.ArrayList<String> options = _hidl_request.readStringVector();
                    debug(fd, options);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 256136003 /* interfaceDescriptor */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    String _hidl_out_descriptor = interfaceDescriptor();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeString(_hidl_out_descriptor);
                    _hidl_reply.send();
                    break;
                }

                case 256398152 /* getHashChain */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    java.util.ArrayList<byte[/* 32 */]> _hidl_out_hashchain = getHashChain();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    {
                        android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* size */);
                        {
                            int _hidl_vec_size = _hidl_out_hashchain.size();
                            _hidl_blob.putInt32(0 /* offset */ + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                            _hidl_blob.putBool(0 /* offset */ + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                            android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 32));
                            for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                                {
                                    long _hidl_array_offset_1 = _hidl_index_0 * 32;
                                    byte[] _hidl_array_item_1 = (byte[/* 32 */]) _hidl_out_hashchain.get(_hidl_index_0);

                                    if (_hidl_array_item_1 == null || _hidl_array_item_1.length != 32) {
                                        throw new IllegalArgumentException("Array element is not of the expected length");
                                    }

                                    childBlob.putInt8Array(_hidl_array_offset_1, _hidl_array_item_1);
                                    _hidl_array_offset_1 += 32 * 1;
                                }
                            }
                            _hidl_blob.putBlob(0 /* offset */ + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
                        }
                        _hidl_reply.writeBuffer(_hidl_blob);
                    }
                    _hidl_reply.send();
                    break;
                }

                case 256462420 /* setHALInstrumentation */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    setHALInstrumentation();
                    break;
                }

                case 256660548 /* linkToDeath */:
                {
                break;
                }

                case 256921159 /* ping */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    ping();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.send();
                    break;
                }

                case 257049926 /* getDebugInfo */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    android.hidl.base.V1_0.DebugInfo _hidl_out_info = getDebugInfo();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hidl.base.V1_0.DebugInfo) _hidl_out_info).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 257120595 /* notifySyspropsChanged */:
                {
                    _hidl_request.enforceInterface(android.hidl.base.V1_0.IBase.kInterfaceName);

                    notifySyspropsChanged();
                    break;
                }

                case 257250372 /* unlinkToDeath */:
                {
                break;
                }

            }
        }
    }
}
