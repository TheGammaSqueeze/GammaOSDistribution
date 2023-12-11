package android.hardware.gnss.V1_0;

/**
 * Represents a GNSS navigation message (or a fragment of it).
 */
public interface IGnssNavigationMessageCallback extends android.hidl.base.V1_0.IBase {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.gnss@1.0::IGnssNavigationMessageCallback";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static IGnssNavigationMessageCallback asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof IGnssNavigationMessageCallback)) {
            return (IGnssNavigationMessageCallback)iface;
        }

        IGnssNavigationMessageCallback proxy = new IGnssNavigationMessageCallback.Proxy(binder);

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
    public static IGnssNavigationMessageCallback castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : IGnssNavigationMessageCallback.asInterface(iface.asBinder());
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
    public static IGnssNavigationMessageCallback getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return IGnssNavigationMessageCallback.asInterface(android.os.HwBinder.getService("android.hardware.gnss@1.0::IGnssNavigationMessageCallback", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static IGnssNavigationMessageCallback getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static IGnssNavigationMessageCallback getService(String serviceName) throws android.os.RemoteException {
        return IGnssNavigationMessageCallback.asInterface(android.os.HwBinder.getService("android.hardware.gnss@1.0::IGnssNavigationMessageCallback", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static IGnssNavigationMessageCallback getService() throws android.os.RemoteException {
        return getService("default");
    }

    /**
     * Enumeration of available values to indicate the GNSS Navigation message
     * types.
     *
     * For convenience, first byte is the GnssConstellationType on which that signal
     * is typically transmitted.
     */
    public static final class GnssNavigationMessageType {
        public static final short UNKNOWN = 0;
        /**
         * GPS L1 C/A message contained in the structure.
         */
        public static final short GPS_L1CA = 257 /* 0x0101 */;
        /**
         * GPS L2-CNAV message contained in the structure.
         */
        public static final short GPS_L2CNAV = 258 /* 0x0102 */;
        /**
         * GPS L5-CNAV message contained in the structure.
         */
        public static final short GPS_L5CNAV = 259 /* 0x0103 */;
        /**
         * GPS CNAV-2 message contained in the structure.
         */
        public static final short GPS_CNAV2 = 260 /* 0x0104 */;
        /**
         * Glonass L1 CA message contained in the structure.
         */
        public static final short GLO_L1CA = 769 /* 0x0301 */;
        /**
         * Beidou D1 message contained in the structure.
         */
        public static final short BDS_D1 = 1281 /* 0x0501 */;
        /**
         * Beidou D2 message contained in the structure.
         */
        public static final short BDS_D2 = 1282 /* 0x0502 */;
        /**
         * Galileo I/NAV message contained in the structure.
         */
        public static final short GAL_I = 1537 /* 0x0601 */;
        /**
         * Galileo F/NAV message contained in the structure.
         */
        public static final short GAL_F = 1538 /* 0x0602 */;
        public static final String toString(short o) {
            if (o == UNKNOWN) {
                return "UNKNOWN";
            }
            if (o == GPS_L1CA) {
                return "GPS_L1CA";
            }
            if (o == GPS_L2CNAV) {
                return "GPS_L2CNAV";
            }
            if (o == GPS_L5CNAV) {
                return "GPS_L5CNAV";
            }
            if (o == GPS_CNAV2) {
                return "GPS_CNAV2";
            }
            if (o == GLO_L1CA) {
                return "GLO_L1CA";
            }
            if (o == BDS_D1) {
                return "BDS_D1";
            }
            if (o == BDS_D2) {
                return "BDS_D2";
            }
            if (o == GAL_I) {
                return "GAL_I";
            }
            if (o == GAL_F) {
                return "GAL_F";
            }
            return "0x" + Integer.toHexString(Short.toUnsignedInt((short)(o)));
        }

        public static final String dumpBitfield(short o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            short flipped = 0;
            list.add("UNKNOWN"); // UNKNOWN == 0
            if ((o & GPS_L1CA) == GPS_L1CA) {
                list.add("GPS_L1CA");
                flipped |= GPS_L1CA;
            }
            if ((o & GPS_L2CNAV) == GPS_L2CNAV) {
                list.add("GPS_L2CNAV");
                flipped |= GPS_L2CNAV;
            }
            if ((o & GPS_L5CNAV) == GPS_L5CNAV) {
                list.add("GPS_L5CNAV");
                flipped |= GPS_L5CNAV;
            }
            if ((o & GPS_CNAV2) == GPS_CNAV2) {
                list.add("GPS_CNAV2");
                flipped |= GPS_CNAV2;
            }
            if ((o & GLO_L1CA) == GLO_L1CA) {
                list.add("GLO_L1CA");
                flipped |= GLO_L1CA;
            }
            if ((o & BDS_D1) == BDS_D1) {
                list.add("BDS_D1");
                flipped |= BDS_D1;
            }
            if ((o & BDS_D2) == BDS_D2) {
                list.add("BDS_D2");
                flipped |= BDS_D2;
            }
            if ((o & GAL_I) == GAL_I) {
                list.add("GAL_I");
                flipped |= GAL_I;
            }
            if ((o & GAL_F) == GAL_F) {
                list.add("GAL_F");
                flipped |= GAL_F;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(Short.toUnsignedInt((short)(o & (~flipped)))));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Status of Navigation Message
     * When a message is received properly without any parity error in its
     * navigation words, the status must be set to PARITY_PASSED.
     * If a message is received with words that failed a parity check, but the GNSS
     * receiver has corrected those words, the status must be set to PARITY_REBUILT.
     * Do not send any navigation message that contains words with parity errors
     * that cannot be corrected.
     */
    public static final class NavigationMessageStatus {
        public static final short PARITY_PASSED = 1 /* (1 << 0) */;
        public static final short PARITY_REBUILT = 2 /* (1 << 1) */;
        public static final short UNKNOWN = 0;
        public static final String toString(short o) {
            if (o == PARITY_PASSED) {
                return "PARITY_PASSED";
            }
            if (o == PARITY_REBUILT) {
                return "PARITY_REBUILT";
            }
            if (o == UNKNOWN) {
                return "UNKNOWN";
            }
            return "0x" + Integer.toHexString(Short.toUnsignedInt((short)(o)));
        }

        public static final String dumpBitfield(short o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            short flipped = 0;
            if ((o & PARITY_PASSED) == PARITY_PASSED) {
                list.add("PARITY_PASSED");
                flipped |= PARITY_PASSED;
            }
            if ((o & PARITY_REBUILT) == PARITY_REBUILT) {
                list.add("PARITY_REBUILT");
                flipped |= PARITY_REBUILT;
            }
            list.add("UNKNOWN"); // UNKNOWN == 0
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(Short.toUnsignedInt((short)(o & (~flipped)))));
            }
            return String.join(" | ", list);
        }

    };

    public final static class GnssNavigationMessage {
        /**
         * Satellite vehicle ID number, as defined in GnssSvInfo::svid
         * This is a mandatory value.
         */
        public short svid = 0;
        /**
         * The type of message contained in the structure.
         * This is a mandatory value.
         */
        public short type = 0;
        /**
         * The status of the received navigation message.
         * No need to send any navigation message that contains words with parity
         * errors that cannot be corrected.
         */
        public short status;
        /**
         * Message identifier. It provides an index so the complete Navigation
         * Message can be assembled.
         *
         * - For GNSS L1 C/A subframe 4 and 5, this value corresponds to the 'frame
         *   id' of the navigation message, in the range of 1-25 (Subframe 1, 2, 3
         *   does not contain a 'frame id' and this value can be set to -1.)
         *
         * - For Glonass L1 C/A, this refers to the frame ID, in the range of 1-5.
         *
         * - For BeiDou D1, this refers to the frame number in the range of 1-24
         *
         * - For Beidou D2, this refers to the frame number, in the range of 1-120
         *
         * - For Galileo F/NAV nominal frame structure, this refers to the subframe
         *   number, in the range of 1-12
         *
         * - For Galileo I/NAV nominal frame structure, this refers to the subframe
         *   number in the range of 1-24
         */
        public short messageId = 0;
        /**
         * Sub-message identifier. If required by the message 'type', this value
         * contains a sub-index within the current message (or frame) that is being
         * transmitted.
         *
         * - For GNSS L1 C/A, BeiDou D1 & BeiDou D2, the submessage id corresponds to
         *   the subframe number of the navigation message, in the range of 1-5.
         *
         * - For Glonass L1 C/A, this refers to the String number, in the range from
         *   1-15
         *
         * - For Galileo F/NAV, this refers to the page type in the range 1-6
         *
         * - For Galileo I/NAV, this refers to the word type in the range 0-10+
         * A value of 0 is only allowed if the Satellite is transmiting a Spare Word.
         */
        public short submessageId = 0;
        /**
         * The data of the reported GNSS message. The bytes (or words) are specified
         * using big endian format (MSB first).
         *
         * - For GNSS L1 C/A, Beidou D1 & Beidou D2, each subframe contains 10 30-bit
         *   words. Each word (30 bits) must fit into the last 30 bits in a
         *   4-byte word (skip B31 and B32), with MSB first, for a total of 40
         *   bytes, covering a time period of 6, 6, and 0.6 seconds, respectively.
         *   The standard followed is 1995 SPS Signal specification.
         *
         * - For Glonass L1 C/A, each string contains 85 data bits, including the
         *   checksum.  These bits must fit into 11 bytes, with MSB first (skip
         *   B86-B88), covering a time period of 2 seconds.
         *   The standard followed is Glonass Interface Control Document Edition 5.1.
         *
         * - For Galileo F/NAV, each word consists of 238-bit (sync & tail symbols
         *   excluded). Each word must fit into 30-bytes, with MSB first (skip
         *   B239, B240), covering a time period of 10 seconds. The standard
         *   followed is European GNSS(Galileo) Signal in Space Interface
         *   Control Document Issue 1.2.
         *
         * - For Galileo I/NAV, each page contains 2 page parts, even and odd, with
         *   a total of 2x114 = 228 bits, (sync & tail excluded) that must fit
         *   into 29 bytes, with MSB first (skip B229-B232). The standard followed
         *   is same as above.
         *
         * The data reported here must be the raw data as demodulated by the GNSS
         * receiver, not data received from an external source (i.e. not from a server
         * download.)
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
            if (otherObject.getClass() != android.hardware.gnss.V1_0.IGnssNavigationMessageCallback.GnssNavigationMessage.class) {
                return false;
            }
            android.hardware.gnss.V1_0.IGnssNavigationMessageCallback.GnssNavigationMessage other = (android.hardware.gnss.V1_0.IGnssNavigationMessageCallback.GnssNavigationMessage)otherObject;
            if (this.svid != other.svid) {
                return false;
            }
            if (this.type != other.type) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.status, other.status)) {
                return false;
            }
            if (this.messageId != other.messageId) {
                return false;
            }
            if (this.submessageId != other.submessageId) {
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
                    android.os.HidlSupport.deepHashCode(this.svid), 
                    android.os.HidlSupport.deepHashCode(this.type), 
                    android.os.HidlSupport.deepHashCode(this.status), 
                    android.os.HidlSupport.deepHashCode(this.messageId), 
                    android.os.HidlSupport.deepHashCode(this.submessageId), 
                    android.os.HidlSupport.deepHashCode(this.data));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".svid = ");
            builder.append(this.svid);
            builder.append(", .type = ");
            builder.append(android.hardware.gnss.V1_0.IGnssNavigationMessageCallback.GnssNavigationMessageType.toString(this.type));
            builder.append(", .status = ");
            builder.append(android.hardware.gnss.V1_0.IGnssNavigationMessageCallback.NavigationMessageStatus.dumpBitfield(this.status));
            builder.append(", .messageId = ");
            builder.append(this.messageId);
            builder.append(", .submessageId = ");
            builder.append(this.submessageId);
            builder.append(", .data = ");
            builder.append(this.data);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(32 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<GnssNavigationMessage> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<GnssNavigationMessage> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 32,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.gnss.V1_0.IGnssNavigationMessageCallback.GnssNavigationMessage _hidl_vec_element = new android.hardware.gnss.V1_0.IGnssNavigationMessageCallback.GnssNavigationMessage();
                    ((android.hardware.gnss.V1_0.IGnssNavigationMessageCallback.GnssNavigationMessage) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 32);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            svid = _hidl_blob.getInt16(_hidl_offset + 0);
            type = _hidl_blob.getInt16(_hidl_offset + 2);
            status = _hidl_blob.getInt16(_hidl_offset + 4);
            messageId = _hidl_blob.getInt16(_hidl_offset + 6);
            submessageId = _hidl_blob.getInt16(_hidl_offset + 8);
            {
                int _hidl_vec_size = _hidl_blob.getInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 1,_hidl_blob.handle(),
                        _hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                ((java.util.ArrayList<Byte>) data).clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    byte _hidl_vec_element = 0;
                    _hidl_vec_element = childBlob.getInt8(_hidl_index_0 * 1);
                    ((java.util.ArrayList<Byte>) data).add(_hidl_vec_element);
                }
            }
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(32 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<GnssNavigationMessage> _hidl_vec) {
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
            _hidl_blob.putInt16(_hidl_offset + 0, svid);
            _hidl_blob.putInt16(_hidl_offset + 2, type);
            _hidl_blob.putInt16(_hidl_offset + 4, status);
            _hidl_blob.putInt16(_hidl_offset + 6, messageId);
            _hidl_blob.putInt16(_hidl_offset + 8, submessageId);
            {
                int _hidl_vec_size = data.size();
                _hidl_blob.putInt32(_hidl_offset + 16 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(_hidl_offset + 16 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 1));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    childBlob.putInt8(_hidl_index_0 * 1, data.get(_hidl_index_0));
                }
                _hidl_blob.putBlob(_hidl_offset + 16 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }
        }
    };

    /**
     * The callback to report an available fragment of a GNSS navigation messages
     * from the HAL.
     *
     * @param message - The GNSS navigation submessage/subframe representation.
     */
    void gnssNavigationMessageCb(android.hardware.gnss.V1_0.IGnssNavigationMessageCallback.GnssNavigationMessage message)
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

    public static final class Proxy implements IGnssNavigationMessageCallback {
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
            return "[class or subclass of " + IGnssNavigationMessageCallback.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback follow.
        @Override
        public void gnssNavigationMessageCb(android.hardware.gnss.V1_0.IGnssNavigationMessageCallback.GnssNavigationMessage message)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.gnss.V1_0.IGnssNavigationMessageCallback.kInterfaceName);
            ((android.hardware.gnss.V1_0.IGnssNavigationMessageCallback.GnssNavigationMessage) message).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* gnssNavigationMessageCb */, _hidl_request, _hidl_reply, 0 /* flags */);
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

    public static abstract class Stub extends android.os.HwBinder implements IGnssNavigationMessageCallback {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.gnss.V1_0.IGnssNavigationMessageCallback.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.gnss.V1_0.IGnssNavigationMessageCallback.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{78,113,105,-111,-99,36,-5,-27,87,62,91,-51,104,61,11,-41,-85,-11,83,-92,-26,-61,76,65,-7,-33,-63,-31,32,80,-37,7} /* 4e7169919d24fbe5573e5bcd683d0bd7abf553a4e6c34c41f9dfc1e12050db07 */,
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
                case 1 /* gnssNavigationMessageCb */:
                {
                    _hidl_request.enforceInterface(android.hardware.gnss.V1_0.IGnssNavigationMessageCallback.kInterfaceName);

                    android.hardware.gnss.V1_0.IGnssNavigationMessageCallback.GnssNavigationMessage message = new android.hardware.gnss.V1_0.IGnssNavigationMessageCallback.GnssNavigationMessage();
                    ((android.hardware.gnss.V1_0.IGnssNavigationMessageCallback.GnssNavigationMessage) message).readFromParcel(_hidl_request);
                    gnssNavigationMessageCb(message);
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
