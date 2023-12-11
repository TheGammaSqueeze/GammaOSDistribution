package android.hardware.soundtrigger.V2_0;

public interface ISoundTriggerHw extends android.hidl.base.V1_0.IBase {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.soundtrigger@2.0::ISoundTriggerHw";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static ISoundTriggerHw asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof ISoundTriggerHw)) {
            return (ISoundTriggerHw)iface;
        }

        ISoundTriggerHw proxy = new ISoundTriggerHw.Proxy(binder);

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
    public static ISoundTriggerHw castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : ISoundTriggerHw.asInterface(iface.asBinder());
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
    public static ISoundTriggerHw getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return ISoundTriggerHw.asInterface(android.os.HwBinder.getService("android.hardware.soundtrigger@2.0::ISoundTriggerHw", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static ISoundTriggerHw getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static ISoundTriggerHw getService(String serviceName) throws android.os.RemoteException {
        return ISoundTriggerHw.asInterface(android.os.HwBinder.getService("android.hardware.soundtrigger@2.0::ISoundTriggerHw", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static ISoundTriggerHw getService() throws android.os.RemoteException {
        return getService("default");
    }

    /**
     * Sound trigger implementation descriptor read by the framework via
     * getProperties(). Used by SoundTrigger service to report to applications
     * and manage concurrency and policy.
     */
    public final static class Properties {
        /**
         * Implementor name
         */
        public String implementor = new String();
        /**
         * Implementation description
         */
        public String description = new String();
        /**
         * Implementation version
         */
        public int version = 0;
        /**
         * Unique implementation ID. The UUID must change with each version of
         * the engine implementation
         */
        public android.hardware.audio.common.V2_0.Uuid uuid = new android.hardware.audio.common.V2_0.Uuid();
        /**
         * Maximum number of concurrent sound models loaded
         */
        public int maxSoundModels = 0;
        /**
         * Maximum number of key phrases
         */
        public int maxKeyPhrases = 0;
        /**
         * Maximum number of concurrent users detected
         */
        public int maxUsers = 0;
        /**
         * All supported modes. e.g RecognitionMode.VOICE_TRIGGER
         */
        public int recognitionModes = 0;
        /**
         * Supports seamless transition from detection to capture
         */
        public boolean captureTransition = false;
        /**
         * Maximum buffering capacity in ms if captureTransition is true
         */
        public int maxBufferMs = 0;
        /**
         * Supports capture by other use cases while detection is active
         */
        public boolean concurrentCapture = false;
        /**
         * Returns the trigger capture in event
         */
        public boolean triggerInEvent = false;
        /**
         * Rated power consumption when detection is active with TDB
         * silence/sound/speech ratio
         */
        public int powerConsumptionMw = 0;

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.soundtrigger.V2_0.ISoundTriggerHw.Properties.class) {
                return false;
            }
            android.hardware.soundtrigger.V2_0.ISoundTriggerHw.Properties other = (android.hardware.soundtrigger.V2_0.ISoundTriggerHw.Properties)otherObject;
            if (!android.os.HidlSupport.deepEquals(this.implementor, other.implementor)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.description, other.description)) {
                return false;
            }
            if (this.version != other.version) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.uuid, other.uuid)) {
                return false;
            }
            if (this.maxSoundModels != other.maxSoundModels) {
                return false;
            }
            if (this.maxKeyPhrases != other.maxKeyPhrases) {
                return false;
            }
            if (this.maxUsers != other.maxUsers) {
                return false;
            }
            if (this.recognitionModes != other.recognitionModes) {
                return false;
            }
            if (this.captureTransition != other.captureTransition) {
                return false;
            }
            if (this.maxBufferMs != other.maxBufferMs) {
                return false;
            }
            if (this.concurrentCapture != other.concurrentCapture) {
                return false;
            }
            if (this.triggerInEvent != other.triggerInEvent) {
                return false;
            }
            if (this.powerConsumptionMw != other.powerConsumptionMw) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.implementor), 
                    android.os.HidlSupport.deepHashCode(this.description), 
                    android.os.HidlSupport.deepHashCode(this.version), 
                    android.os.HidlSupport.deepHashCode(this.uuid), 
                    android.os.HidlSupport.deepHashCode(this.maxSoundModels), 
                    android.os.HidlSupport.deepHashCode(this.maxKeyPhrases), 
                    android.os.HidlSupport.deepHashCode(this.maxUsers), 
                    android.os.HidlSupport.deepHashCode(this.recognitionModes), 
                    android.os.HidlSupport.deepHashCode(this.captureTransition), 
                    android.os.HidlSupport.deepHashCode(this.maxBufferMs), 
                    android.os.HidlSupport.deepHashCode(this.concurrentCapture), 
                    android.os.HidlSupport.deepHashCode(this.triggerInEvent), 
                    android.os.HidlSupport.deepHashCode(this.powerConsumptionMw));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".implementor = ");
            builder.append(this.implementor);
            builder.append(", .description = ");
            builder.append(this.description);
            builder.append(", .version = ");
            builder.append(this.version);
            builder.append(", .uuid = ");
            builder.append(this.uuid);
            builder.append(", .maxSoundModels = ");
            builder.append(this.maxSoundModels);
            builder.append(", .maxKeyPhrases = ");
            builder.append(this.maxKeyPhrases);
            builder.append(", .maxUsers = ");
            builder.append(this.maxUsers);
            builder.append(", .recognitionModes = ");
            builder.append(this.recognitionModes);
            builder.append(", .captureTransition = ");
            builder.append(this.captureTransition);
            builder.append(", .maxBufferMs = ");
            builder.append(this.maxBufferMs);
            builder.append(", .concurrentCapture = ");
            builder.append(this.concurrentCapture);
            builder.append(", .triggerInEvent = ");
            builder.append(this.triggerInEvent);
            builder.append(", .powerConsumptionMw = ");
            builder.append(this.powerConsumptionMw);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(88 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<Properties> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<Properties> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 88,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.soundtrigger.V2_0.ISoundTriggerHw.Properties _hidl_vec_element = new android.hardware.soundtrigger.V2_0.ISoundTriggerHw.Properties();
                    ((android.hardware.soundtrigger.V2_0.ISoundTriggerHw.Properties) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 88);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            implementor = _hidl_blob.getString(_hidl_offset + 0);

            parcel.readEmbeddedBuffer(
                    ((String) implementor).getBytes().length + 1,
                    _hidl_blob.handle(),
                    _hidl_offset + 0 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

            description = _hidl_blob.getString(_hidl_offset + 16);

            parcel.readEmbeddedBuffer(
                    ((String) description).getBytes().length + 1,
                    _hidl_blob.handle(),
                    _hidl_offset + 16 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

            version = _hidl_blob.getInt32(_hidl_offset + 32);
            ((android.hardware.audio.common.V2_0.Uuid) uuid).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 36);
            maxSoundModels = _hidl_blob.getInt32(_hidl_offset + 52);
            maxKeyPhrases = _hidl_blob.getInt32(_hidl_offset + 56);
            maxUsers = _hidl_blob.getInt32(_hidl_offset + 60);
            recognitionModes = _hidl_blob.getInt32(_hidl_offset + 64);
            captureTransition = _hidl_blob.getBool(_hidl_offset + 68);
            maxBufferMs = _hidl_blob.getInt32(_hidl_offset + 72);
            concurrentCapture = _hidl_blob.getBool(_hidl_offset + 76);
            triggerInEvent = _hidl_blob.getBool(_hidl_offset + 77);
            powerConsumptionMw = _hidl_blob.getInt32(_hidl_offset + 80);
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(88 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<Properties> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 88));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 88);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            _hidl_blob.putString(_hidl_offset + 0, implementor);
            _hidl_blob.putString(_hidl_offset + 16, description);
            _hidl_blob.putInt32(_hidl_offset + 32, version);
            uuid.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 36);
            _hidl_blob.putInt32(_hidl_offset + 52, maxSoundModels);
            _hidl_blob.putInt32(_hidl_offset + 56, maxKeyPhrases);
            _hidl_blob.putInt32(_hidl_offset + 60, maxUsers);
            _hidl_blob.putInt32(_hidl_offset + 64, recognitionModes);
            _hidl_blob.putBool(_hidl_offset + 68, captureTransition);
            _hidl_blob.putInt32(_hidl_offset + 72, maxBufferMs);
            _hidl_blob.putBool(_hidl_offset + 76, concurrentCapture);
            _hidl_blob.putBool(_hidl_offset + 77, triggerInEvent);
            _hidl_blob.putInt32(_hidl_offset + 80, powerConsumptionMw);
        }
    };

    /**
     * Base sound model descriptor. This struct is the header of a larger block
     * passed to loadSoundModel() and contains the binary data of the
     * sound model.
     */
    public final static class SoundModel {
        /**
         * Model type. e.g. SoundModelType.KEYPHRASE
         */
        public int type = 0;
        /**
         * Unique sound model ID.
         */
        public android.hardware.audio.common.V2_0.Uuid uuid = new android.hardware.audio.common.V2_0.Uuid();
        /**
         * Unique vendor ID. Identifies the engine the sound model
         * was build for
         */
        public android.hardware.audio.common.V2_0.Uuid vendorUuid = new android.hardware.audio.common.V2_0.Uuid();
        /**
         * Opaque data transparent to Android framework
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
            if (otherObject.getClass() != android.hardware.soundtrigger.V2_0.ISoundTriggerHw.SoundModel.class) {
                return false;
            }
            android.hardware.soundtrigger.V2_0.ISoundTriggerHw.SoundModel other = (android.hardware.soundtrigger.V2_0.ISoundTriggerHw.SoundModel)otherObject;
            if (this.type != other.type) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.uuid, other.uuid)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.vendorUuid, other.vendorUuid)) {
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
                    android.os.HidlSupport.deepHashCode(this.type), 
                    android.os.HidlSupport.deepHashCode(this.uuid), 
                    android.os.HidlSupport.deepHashCode(this.vendorUuid), 
                    android.os.HidlSupport.deepHashCode(this.data));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".type = ");
            builder.append(android.hardware.soundtrigger.V2_0.SoundModelType.toString(this.type));
            builder.append(", .uuid = ");
            builder.append(this.uuid);
            builder.append(", .vendorUuid = ");
            builder.append(this.vendorUuid);
            builder.append(", .data = ");
            builder.append(this.data);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(56 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<SoundModel> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<SoundModel> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 56,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.soundtrigger.V2_0.ISoundTriggerHw.SoundModel _hidl_vec_element = new android.hardware.soundtrigger.V2_0.ISoundTriggerHw.SoundModel();
                    ((android.hardware.soundtrigger.V2_0.ISoundTriggerHw.SoundModel) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 56);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            type = _hidl_blob.getInt32(_hidl_offset + 0);
            ((android.hardware.audio.common.V2_0.Uuid) uuid).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 4);
            ((android.hardware.audio.common.V2_0.Uuid) vendorUuid).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 20);
            {
                int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 40 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 1,_hidl_blob.handle(),
                        _hidl_offset + 40 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                ((java.util.ArrayList<Byte>) data).clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    byte _hidl_vec_element = 0;
                    _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                    ((java.util.ArrayList<Byte>) data).add(_hidl_vec_element);
                }
            }
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(56 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<SoundModel> _hidl_vec) {
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
            _hidl_blob.putInt32(_hidl_offset + 0, type);
            uuid.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 4);
            vendorUuid.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 20);
            {
                int _hidl_vec_size = data.size();
                _hidl_blob.putInt32(_hidl_offset + 40 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(_hidl_offset + 40 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    childBlob.putInt8(_hidl_index_0 * 1, data.get(_hidl_index_0));
                }
                _hidl_blob.putBlob(_hidl_offset + 40 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }
        }
    };

    /**
     * Key phrase descriptor
     */
    public final static class Phrase {
        /**
         * Unique keyphrase ID assigned at enrollment time
         */
        public int id = 0;
        /**
         * Recognition modes supported by this key phrase
         */
        public int recognitionModes = 0;
        /**
         * List of users IDs associated with this key phrase
         */
        public java.util.ArrayList<Integer> users = new java.util.ArrayList<Integer>();
        /**
         * Locale - Java Locale style (e.g. en_US)
         */
        public String locale = new String();
        /**
         * Phrase text in UTF-8 format.
         */
        public String text = new String();

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.soundtrigger.V2_0.ISoundTriggerHw.Phrase.class) {
                return false;
            }
            android.hardware.soundtrigger.V2_0.ISoundTriggerHw.Phrase other = (android.hardware.soundtrigger.V2_0.ISoundTriggerHw.Phrase)otherObject;
            if (this.id != other.id) {
                return false;
            }
            if (this.recognitionModes != other.recognitionModes) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.users, other.users)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.locale, other.locale)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.text, other.text)) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.id), 
                    android.os.HidlSupport.deepHashCode(this.recognitionModes), 
                    android.os.HidlSupport.deepHashCode(this.users), 
                    android.os.HidlSupport.deepHashCode(this.locale), 
                    android.os.HidlSupport.deepHashCode(this.text));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".id = ");
            builder.append(this.id);
            builder.append(", .recognitionModes = ");
            builder.append(this.recognitionModes);
            builder.append(", .users = ");
            builder.append(this.users);
            builder.append(", .locale = ");
            builder.append(this.locale);
            builder.append(", .text = ");
            builder.append(this.text);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(56 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<Phrase> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<Phrase> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 56,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.soundtrigger.V2_0.ISoundTriggerHw.Phrase _hidl_vec_element = new android.hardware.soundtrigger.V2_0.ISoundTriggerHw.Phrase();
                    ((android.hardware.soundtrigger.V2_0.ISoundTriggerHw.Phrase) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 56);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            id = _hidl_blob.getInt32(_hidl_offset + 0);
            recognitionModes = _hidl_blob.getInt32(_hidl_offset + 4);
            {
                int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 4,_hidl_blob.handle(),
                        _hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                ((java.util.ArrayList<Integer>) users).clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    int _hidl_vec_element = 0;
                    _hidl_vec_element = childBlob.getInt32(_hidl_index_0 * 4);
                    ((java.util.ArrayList<Integer>) users).add(_hidl_vec_element);
                }
            }
            locale = _hidl_blob.getString(_hidl_offset + 24);

            parcel.readEmbeddedBuffer(
                    ((String) locale).getBytes().length + 1,
                    _hidl_blob.handle(),
                    _hidl_offset + 24 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

            text = _hidl_blob.getString(_hidl_offset + 40);

            parcel.readEmbeddedBuffer(
                    ((String) text).getBytes().length + 1,
                    _hidl_blob.handle(),
                    _hidl_offset + 40 + 0 /* offsetof(hidl_string, mBuffer) */,false /* nullable */);

        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(56 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<Phrase> _hidl_vec) {
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
            _hidl_blob.putInt32(_hidl_offset + 0, id);
            _hidl_blob.putInt32(_hidl_offset + 4, recognitionModes);
            {
                int _hidl_vec_size = users.size();
                _hidl_blob.putInt32(_hidl_offset + 8 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(_hidl_offset + 8 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 4));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    childBlob.putInt32(_hidl_index_0 * 4, users.get(_hidl_index_0));
                }
                _hidl_blob.putBlob(_hidl_offset + 8 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }
            _hidl_blob.putString(_hidl_offset + 24, locale);
            _hidl_blob.putString(_hidl_offset + 40, text);
        }
    };

    /**
     * Specialized sound model for key phrase detection.
     * Proprietary representation of key phrases in binary data must match
     * information indicated by phrases field
     */
    public final static class PhraseSoundModel {
        /**
         * Common part of sound model descriptor
         */
        public android.hardware.soundtrigger.V2_0.ISoundTriggerHw.SoundModel common = new android.hardware.soundtrigger.V2_0.ISoundTriggerHw.SoundModel();
        /**
         * List of descriptors for key phrases supported by this sound model
         */
        public java.util.ArrayList<android.hardware.soundtrigger.V2_0.ISoundTriggerHw.Phrase> phrases = new java.util.ArrayList<android.hardware.soundtrigger.V2_0.ISoundTriggerHw.Phrase>();

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.soundtrigger.V2_0.ISoundTriggerHw.PhraseSoundModel.class) {
                return false;
            }
            android.hardware.soundtrigger.V2_0.ISoundTriggerHw.PhraseSoundModel other = (android.hardware.soundtrigger.V2_0.ISoundTriggerHw.PhraseSoundModel)otherObject;
            if (!android.os.HidlSupport.deepEquals(this.common, other.common)) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.phrases, other.phrases)) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.common), 
                    android.os.HidlSupport.deepHashCode(this.phrases));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".common = ");
            builder.append(this.common);
            builder.append(", .phrases = ");
            builder.append(this.phrases);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(72 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<PhraseSoundModel> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<PhraseSoundModel> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 72,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.soundtrigger.V2_0.ISoundTriggerHw.PhraseSoundModel _hidl_vec_element = new android.hardware.soundtrigger.V2_0.ISoundTriggerHw.PhraseSoundModel();
                    ((android.hardware.soundtrigger.V2_0.ISoundTriggerHw.PhraseSoundModel) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 72);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            ((android.hardware.soundtrigger.V2_0.ISoundTriggerHw.SoundModel) common).readEmbeddedFromParcel(parcel, _hidl_blob, _hidl_offset + 0);
            {
                int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 56 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 56,_hidl_blob.handle(),
                        _hidl_offset + 56 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                ((java.util.ArrayList<android.hardware.soundtrigger.V2_0.ISoundTriggerHw.Phrase>) phrases).clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.soundtrigger.V2_0.ISoundTriggerHw.Phrase _hidl_vec_element = new android.hardware.soundtrigger.V2_0.ISoundTriggerHw.Phrase();
                    ((android.hardware.soundtrigger.V2_0.ISoundTriggerHw.Phrase) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 56);
                    ((java.util.ArrayList<android.hardware.soundtrigger.V2_0.ISoundTriggerHw.Phrase>) phrases).add(_hidl_vec_element);
                }
            }
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(72 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<PhraseSoundModel> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 72));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 72);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            common.writeEmbeddedToBlob(_hidl_blob, _hidl_offset + 0);
            {
                int _hidl_vec_size = phrases.size();
                _hidl_blob.putInt32(_hidl_offset + 56 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(_hidl_offset + 56 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 56));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    phrases.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 56);
                }
                _hidl_blob.putBlob(_hidl_offset + 56 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }
        }
    };

    /**
     * Configuration for sound trigger capture session passed to
     * startRecognition() method
     */
    public final static class RecognitionConfig {
        /**
         * IO handle that will be used for capture. N/A if captureRequested
         * is false
         */
        public int captureHandle = 0;
        /**
         * Input device requested for detection capture
         */
        public int captureDevice = 0;
        /**
         * Capture and buffer audio for this recognition instance
         */
        public boolean captureRequested = false;
        /**
         * Configuration for each key phrase
         */
        public java.util.ArrayList<android.hardware.soundtrigger.V2_0.PhraseRecognitionExtra> phrases = new java.util.ArrayList<android.hardware.soundtrigger.V2_0.PhraseRecognitionExtra>();
        /**
         * Opaque capture configuration data transparent to the framework
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
            if (otherObject.getClass() != android.hardware.soundtrigger.V2_0.ISoundTriggerHw.RecognitionConfig.class) {
                return false;
            }
            android.hardware.soundtrigger.V2_0.ISoundTriggerHw.RecognitionConfig other = (android.hardware.soundtrigger.V2_0.ISoundTriggerHw.RecognitionConfig)otherObject;
            if (this.captureHandle != other.captureHandle) {
                return false;
            }
            if (this.captureDevice != other.captureDevice) {
                return false;
            }
            if (this.captureRequested != other.captureRequested) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.phrases, other.phrases)) {
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
                    android.os.HidlSupport.deepHashCode(this.captureHandle), 
                    android.os.HidlSupport.deepHashCode(this.captureDevice), 
                    android.os.HidlSupport.deepHashCode(this.captureRequested), 
                    android.os.HidlSupport.deepHashCode(this.phrases), 
                    android.os.HidlSupport.deepHashCode(this.data));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".captureHandle = ");
            builder.append(this.captureHandle);
            builder.append(", .captureDevice = ");
            builder.append(android.hardware.audio.common.V2_0.AudioDevice.toString(this.captureDevice));
            builder.append(", .captureRequested = ");
            builder.append(this.captureRequested);
            builder.append(", .phrases = ");
            builder.append(this.phrases);
            builder.append(", .data = ");
            builder.append(this.data);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(48 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<RecognitionConfig> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<RecognitionConfig> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 48,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.soundtrigger.V2_0.ISoundTriggerHw.RecognitionConfig _hidl_vec_element = new android.hardware.soundtrigger.V2_0.ISoundTriggerHw.RecognitionConfig();
                    ((android.hardware.soundtrigger.V2_0.ISoundTriggerHw.RecognitionConfig) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 48);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            captureHandle = _hidl_blob.getInt32(_hidl_offset + 0);
            captureDevice = _hidl_blob.getInt32(_hidl_offset + 4);
            captureRequested = _hidl_blob.getBool(_hidl_offset + 8);
            {
                int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 32,_hidl_blob.handle(),
                        _hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                ((java.util.ArrayList<android.hardware.soundtrigger.V2_0.PhraseRecognitionExtra>) phrases).clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.soundtrigger.V2_0.PhraseRecognitionExtra _hidl_vec_element = new android.hardware.soundtrigger.V2_0.PhraseRecognitionExtra();
                    ((android.hardware.soundtrigger.V2_0.PhraseRecognitionExtra) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 32);
                    ((java.util.ArrayList<android.hardware.soundtrigger.V2_0.PhraseRecognitionExtra>) phrases).add(_hidl_vec_element);
                }
            }
            {
                int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 32 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 1,_hidl_blob.handle(),
                        _hidl_offset + 32 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                ((java.util.ArrayList<Byte>) data).clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    byte _hidl_vec_element = 0;
                    _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                    ((java.util.ArrayList<Byte>) data).add(_hidl_vec_element);
                }
            }
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(48 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<RecognitionConfig> _hidl_vec) {
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
            _hidl_blob.putInt32(_hidl_offset + 0, captureHandle);
            _hidl_blob.putInt32(_hidl_offset + 4, captureDevice);
            _hidl_blob.putBool(_hidl_offset + 8, captureRequested);
            {
                int _hidl_vec_size = phrases.size();
                _hidl_blob.putInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(_hidl_offset + 16 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 32));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    phrases.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 32);
                }
                _hidl_blob.putBlob(_hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }
            {
                int _hidl_vec_size = data.size();
                _hidl_blob.putInt32(_hidl_offset + 32 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(_hidl_offset + 32 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    childBlob.putInt8(_hidl_index_0 * 1, data.get(_hidl_index_0));
                }
                _hidl_blob.putBlob(_hidl_offset + 32 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }
        }
    };


    @java.lang.FunctionalInterface
    public interface getPropertiesCallback {
        public void onValues(int retval, android.hardware.soundtrigger.V2_0.ISoundTriggerHw.Properties properties);
    }

    /**
     * Retrieve implementation properties.
     * @return retval Operation completion status: 0 in case of success,
     *                -ENODEV in case of initialization error.
     * @return properties A Properties structure containing implementation
     *                    description and capabilities.
     */
    void getProperties(getPropertiesCallback _hidl_cb)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface loadSoundModelCallback {
        public void onValues(int retval, int modelHandle);
    }

    /**
     * Load a sound model. Once loaded, recognition of this model can be
     * started and stopped. Only one active recognition per model at a time.
     * The SoundTrigger service must handle concurrent recognition requests by
     * different users/applications on the same model.
     * The implementation returns a unique handle used by other functions
     * (unloadSoundModel(), startRecognition(), etc...
     * @param soundModel A SoundModel structure describing the sound model to
     *                   load.
     * @param callback The callback interface on which the soundmodelCallback()
     *                 method will be called upon completion.
     * @param cookie The value of the cookie argument passed to the completion
     *               callback. This unique context information is assigned and
     *               used only by the framework.
     * @return retval Operation completion status: 0 in case of success,
     *                -EINVAL in case of invalid sound model (e.g 0 data size),
     *                -ENOSYS in case of invalid operation (e.g max number of
     *                models exceeded),
     *                -ENOMEM in case of memory allocation failure,
     *                -ENODEV in case of initialization error.
     * @return modelHandle A unique handle assigned by the HAL for use by the
     *                framework when controlling activity for this sound model.
     */
    void loadSoundModel(android.hardware.soundtrigger.V2_0.ISoundTriggerHw.SoundModel soundModel, android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback callback, int cookie, loadSoundModelCallback _hidl_cb)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface loadPhraseSoundModelCallback {
        public void onValues(int retval, int modelHandle);
    }

    /**
     * Load a key phrase sound model. Once loaded, recognition of this model can
     * be started and stopped. Only one active recognition per model at a time.
     * The SoundTrigger service must handle concurrent recognition requests by
     * different users/applications on the same model.
     * The implementation returns a unique handle used by other functions
     * (unloadSoundModel(), startRecognition(), etc...
     * @param soundModel A PhraseSoundModel structure describing the sound model
     *                   to load.
     * @param callback The callback interface on which the soundmodelCallback()
     *                 method will be called upon completion.
     * @param cookie The value of the cookie argument passed to the completion
     *               callback. This unique context information is assigned and
     *               used only by the framework.
     * @return retval Operation completion status: 0 in case of success,
     *                -EINVAL in case of invalid sound model (e.g 0 data size),
     *                -ENOSYS in case of invalid operation (e.g max number of
     *                models exceeded),
     *                -ENOMEM in case of memory allocation failure,
     *                -ENODEV in case of initialization error.
     * @return modelHandle A unique handle assigned by the HAL for use by the
     *                framework when controlling activity for this sound model.
     */
    void loadPhraseSoundModel(android.hardware.soundtrigger.V2_0.ISoundTriggerHw.PhraseSoundModel soundModel, android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback callback, int cookie, loadPhraseSoundModelCallback _hidl_cb)
        throws android.os.RemoteException;
    /**
     * Unload a sound model. A sound model may be unloaded to make room for a
     * new one to overcome implementation limitations.
     * @param modelHandle the handle of the sound model to unload
     * @return retval Operation completion status: 0 in case of success,
     *                -ENOSYS if the model is not loaded,
     *                -ENODEV in case of initialization error.
     */
    int unloadSoundModel(int modelHandle)
        throws android.os.RemoteException;
    /**
     * Start recognition on a given model. Only one recognition active
     * at a time per model. Once recognition succeeds of fails, the callback
     * is called.
     * @param modelHandle the handle of the sound model to use for recognition
     * @param config A RecognitionConfig structure containing attributes of the
     *               recognition to perform
     * @param callback The callback interface on which the recognitionCallback()
     *                 method must be called upon recognition.
     * @param cookie The value of the cookie argument passed to the recognition
     *               callback. This unique context information is assigned and
     *               used only by the framework.
     * @return retval Operation completion status: 0 in case of success,
     *                -EINVAL in case of invalid recognition attributes,
     *                -ENOSYS in case of invalid model handle,
     *                -ENOMEM in case of memory allocation failure,
     *                -ENODEV in case of initialization error.
     */
    int startRecognition(int modelHandle, android.hardware.soundtrigger.V2_0.ISoundTriggerHw.RecognitionConfig config, android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback callback, int cookie)
        throws android.os.RemoteException;
    /**
     * Stop recognition on a given model.
     * The implementation must not call the recognition callback when stopped
     * via this method.
     * @param modelHandle The handle of the sound model to use for recognition
     * @return retval Operation completion status: 0 in case of success,
     *                -ENOSYS in case of invalid model handle,
     *                -ENODEV in case of initialization error.
     */
    int stopRecognition(int modelHandle)
        throws android.os.RemoteException;
    /**
     * Stop recognition on all models.
     * @return retval Operation completion status: 0 in case of success,
     *                -ENODEV in case of initialization error.
     */
    int stopAllRecognitions()
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

    public static final class Proxy implements ISoundTriggerHw {
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
            return "[class or subclass of " + ISoundTriggerHw.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::soundtrigger::V2_0::ISoundTriggerHw follow.
        @Override
        public void getProperties(getPropertiesCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.soundtrigger.V2_0.ISoundTriggerHw.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* getProperties */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_retval = _hidl_reply.readInt32();
                android.hardware.soundtrigger.V2_0.ISoundTriggerHw.Properties _hidl_out_properties = new android.hardware.soundtrigger.V2_0.ISoundTriggerHw.Properties();
                ((android.hardware.soundtrigger.V2_0.ISoundTriggerHw.Properties) _hidl_out_properties).readFromParcel(_hidl_reply);
                _hidl_cb.onValues(_hidl_out_retval, _hidl_out_properties);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void loadSoundModel(android.hardware.soundtrigger.V2_0.ISoundTriggerHw.SoundModel soundModel, android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback callback, int cookie, loadSoundModelCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.soundtrigger.V2_0.ISoundTriggerHw.kInterfaceName);
            ((android.hardware.soundtrigger.V2_0.ISoundTriggerHw.SoundModel) soundModel).writeToParcel(_hidl_request);
            _hidl_request.writeStrongBinder(callback == null ? null : callback.asBinder());
            _hidl_request.writeInt32(cookie);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* loadSoundModel */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_retval = _hidl_reply.readInt32();
                int _hidl_out_modelHandle = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_retval, _hidl_out_modelHandle);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void loadPhraseSoundModel(android.hardware.soundtrigger.V2_0.ISoundTriggerHw.PhraseSoundModel soundModel, android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback callback, int cookie, loadPhraseSoundModelCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.soundtrigger.V2_0.ISoundTriggerHw.kInterfaceName);
            ((android.hardware.soundtrigger.V2_0.ISoundTriggerHw.PhraseSoundModel) soundModel).writeToParcel(_hidl_request);
            _hidl_request.writeStrongBinder(callback == null ? null : callback.asBinder());
            _hidl_request.writeInt32(cookie);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(3 /* loadPhraseSoundModel */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_retval = _hidl_reply.readInt32();
                int _hidl_out_modelHandle = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_retval, _hidl_out_modelHandle);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int unloadSoundModel(int modelHandle)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.soundtrigger.V2_0.ISoundTriggerHw.kInterfaceName);
            _hidl_request.writeInt32(modelHandle);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(4 /* unloadSoundModel */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_retval = _hidl_reply.readInt32();
                return _hidl_out_retval;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int startRecognition(int modelHandle, android.hardware.soundtrigger.V2_0.ISoundTriggerHw.RecognitionConfig config, android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback callback, int cookie)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.soundtrigger.V2_0.ISoundTriggerHw.kInterfaceName);
            _hidl_request.writeInt32(modelHandle);
            ((android.hardware.soundtrigger.V2_0.ISoundTriggerHw.RecognitionConfig) config).writeToParcel(_hidl_request);
            _hidl_request.writeStrongBinder(callback == null ? null : callback.asBinder());
            _hidl_request.writeInt32(cookie);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(5 /* startRecognition */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_retval = _hidl_reply.readInt32();
                return _hidl_out_retval;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int stopRecognition(int modelHandle)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.soundtrigger.V2_0.ISoundTriggerHw.kInterfaceName);
            _hidl_request.writeInt32(modelHandle);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(6 /* stopRecognition */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_retval = _hidl_reply.readInt32();
                return _hidl_out_retval;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public int stopAllRecognitions()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.soundtrigger.V2_0.ISoundTriggerHw.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(7 /* stopAllRecognitions */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                int _hidl_out_retval = _hidl_reply.readInt32();
                return _hidl_out_retval;
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

    public static abstract class Stub extends android.os.HwBinder implements ISoundTriggerHw {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.soundtrigger.V2_0.ISoundTriggerHw.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.soundtrigger.V2_0.ISoundTriggerHw.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{91,-17,-64,25,-53,-23,73,83,102,30,44,-37,-107,-29,-49,100,-11,-27,101,-62,-108,3,-31,-62,-38,-20,-62,-66,68,-32,-91,92} /* 5befc019cbe94953661e2cdb95e3cf64f5e565c29403e1c2daecc2be44e0a55c */,
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
                case 1 /* getProperties */:
                {
                    _hidl_request.enforceInterface(android.hardware.soundtrigger.V2_0.ISoundTriggerHw.kInterfaceName);

                    getProperties(new getPropertiesCallback() {
                        @Override
                        public void onValues(int retval, android.hardware.soundtrigger.V2_0.ISoundTriggerHw.Properties properties) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeInt32(retval);
                            ((android.hardware.soundtrigger.V2_0.ISoundTriggerHw.Properties) properties).writeToParcel(_hidl_reply);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 2 /* loadSoundModel */:
                {
                    _hidl_request.enforceInterface(android.hardware.soundtrigger.V2_0.ISoundTriggerHw.kInterfaceName);

                    android.hardware.soundtrigger.V2_0.ISoundTriggerHw.SoundModel soundModel = new android.hardware.soundtrigger.V2_0.ISoundTriggerHw.SoundModel();
                    ((android.hardware.soundtrigger.V2_0.ISoundTriggerHw.SoundModel) soundModel).readFromParcel(_hidl_request);
                    android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback callback = android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.asInterface(_hidl_request.readStrongBinder());
                    int cookie = _hidl_request.readInt32();
                    loadSoundModel(soundModel, callback, cookie, new loadSoundModelCallback() {
                        @Override
                        public void onValues(int retval, int modelHandle) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeInt32(retval);
                            _hidl_reply.writeInt32(modelHandle);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 3 /* loadPhraseSoundModel */:
                {
                    _hidl_request.enforceInterface(android.hardware.soundtrigger.V2_0.ISoundTriggerHw.kInterfaceName);

                    android.hardware.soundtrigger.V2_0.ISoundTriggerHw.PhraseSoundModel soundModel = new android.hardware.soundtrigger.V2_0.ISoundTriggerHw.PhraseSoundModel();
                    ((android.hardware.soundtrigger.V2_0.ISoundTriggerHw.PhraseSoundModel) soundModel).readFromParcel(_hidl_request);
                    android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback callback = android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.asInterface(_hidl_request.readStrongBinder());
                    int cookie = _hidl_request.readInt32();
                    loadPhraseSoundModel(soundModel, callback, cookie, new loadPhraseSoundModelCallback() {
                        @Override
                        public void onValues(int retval, int modelHandle) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            _hidl_reply.writeInt32(retval);
                            _hidl_reply.writeInt32(modelHandle);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 4 /* unloadSoundModel */:
                {
                    _hidl_request.enforceInterface(android.hardware.soundtrigger.V2_0.ISoundTriggerHw.kInterfaceName);

                    int modelHandle = _hidl_request.readInt32();
                    int _hidl_out_retval = unloadSoundModel(modelHandle);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_retval);
                    _hidl_reply.send();
                    break;
                }

                case 5 /* startRecognition */:
                {
                    _hidl_request.enforceInterface(android.hardware.soundtrigger.V2_0.ISoundTriggerHw.kInterfaceName);

                    int modelHandle = _hidl_request.readInt32();
                    android.hardware.soundtrigger.V2_0.ISoundTriggerHw.RecognitionConfig config = new android.hardware.soundtrigger.V2_0.ISoundTriggerHw.RecognitionConfig();
                    ((android.hardware.soundtrigger.V2_0.ISoundTriggerHw.RecognitionConfig) config).readFromParcel(_hidl_request);
                    android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback callback = android.hardware.soundtrigger.V2_0.ISoundTriggerHwCallback.asInterface(_hidl_request.readStrongBinder());
                    int cookie = _hidl_request.readInt32();
                    int _hidl_out_retval = startRecognition(modelHandle, config, callback, cookie);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_retval);
                    _hidl_reply.send();
                    break;
                }

                case 6 /* stopRecognition */:
                {
                    _hidl_request.enforceInterface(android.hardware.soundtrigger.V2_0.ISoundTriggerHw.kInterfaceName);

                    int modelHandle = _hidl_request.readInt32();
                    int _hidl_out_retval = stopRecognition(modelHandle);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_retval);
                    _hidl_reply.send();
                    break;
                }

                case 7 /* stopAllRecognitions */:
                {
                    _hidl_request.enforceInterface(android.hardware.soundtrigger.V2_0.ISoundTriggerHw.kInterfaceName);

                    int _hidl_out_retval = stopAllRecognitions();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    _hidl_reply.writeInt32(_hidl_out_retval);
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
