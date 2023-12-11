package android.hardware.wifi.supplicant.V1_3;

/**
 * Callback Interface exposed by the supplicant service
 * for each station mode interface (ISupplicantStaIface).
 *
 * Clients need to host an instance of this HIDL interface object and
 * pass a reference of the object to the supplicant via the
 * corresponding |ISupplicantStaIface.registerCallback_1_3| method.
 */
public interface ISupplicantStaIfaceCallback extends android.hardware.wifi.supplicant.V1_2.ISupplicantStaIfaceCallback {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.wifi.supplicant@1.3::ISupplicantStaIfaceCallback";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static ISupplicantStaIfaceCallback asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof ISupplicantStaIfaceCallback)) {
            return (ISupplicantStaIfaceCallback)iface;
        }

        ISupplicantStaIfaceCallback proxy = new ISupplicantStaIfaceCallback.Proxy(binder);

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
    public static ISupplicantStaIfaceCallback castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : ISupplicantStaIfaceCallback.asInterface(iface.asBinder());
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
    public static ISupplicantStaIfaceCallback getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return ISupplicantStaIfaceCallback.asInterface(android.os.HwBinder.getService("android.hardware.wifi.supplicant@1.3::ISupplicantStaIfaceCallback", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static ISupplicantStaIfaceCallback getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static ISupplicantStaIfaceCallback getService(String serviceName) throws android.os.RemoteException {
        return ISupplicantStaIfaceCallback.asInterface(android.os.HwBinder.getService("android.hardware.wifi.supplicant@1.3::ISupplicantStaIfaceCallback", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static ISupplicantStaIfaceCallback getService() throws android.os.RemoteException {
        return getService("default");
    }

    /**
     * IEEE Std 802.11-2016 - Table 9-357.
     * BTM status code filled in BSS transition management response frame.
     */
    public static final class BssTmStatusCode {
        public static final byte ACCEPT = 0;
        public static final byte REJECT_UNSPECIFIED = 1;
        public static final byte REJECT_INSUFFICIENT_BEACON = 2;
        public static final byte REJECT_INSUFFICIENT_CAPABITY = 3;
        public static final byte REJECT_BSS_TERMINATION_UNDESIRED = 4;
        public static final byte REJECT_BSS_TERMINATION_DELAY_REQUEST = 5;
        public static final byte REJECT_STA_CANDIDATE_LIST_PROVIDED = 6;
        public static final byte REJECT_NO_SUITABLE_CANDIDATES = 7;
        public static final byte REJECT_LEAVING_ESS = 8;
        public static final String toString(byte o) {
            if (o == ACCEPT) {
                return "ACCEPT";
            }
            if (o == REJECT_UNSPECIFIED) {
                return "REJECT_UNSPECIFIED";
            }
            if (o == REJECT_INSUFFICIENT_BEACON) {
                return "REJECT_INSUFFICIENT_BEACON";
            }
            if (o == REJECT_INSUFFICIENT_CAPABITY) {
                return "REJECT_INSUFFICIENT_CAPABITY";
            }
            if (o == REJECT_BSS_TERMINATION_UNDESIRED) {
                return "REJECT_BSS_TERMINATION_UNDESIRED";
            }
            if (o == REJECT_BSS_TERMINATION_DELAY_REQUEST) {
                return "REJECT_BSS_TERMINATION_DELAY_REQUEST";
            }
            if (o == REJECT_STA_CANDIDATE_LIST_PROVIDED) {
                return "REJECT_STA_CANDIDATE_LIST_PROVIDED";
            }
            if (o == REJECT_NO_SUITABLE_CANDIDATES) {
                return "REJECT_NO_SUITABLE_CANDIDATES";
            }
            if (o == REJECT_LEAVING_ESS) {
                return "REJECT_LEAVING_ESS";
            }
            return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
        }

        public static final String dumpBitfield(byte o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            byte flipped = 0;
            list.add("ACCEPT"); // ACCEPT == 0
            if ((o & REJECT_UNSPECIFIED) == REJECT_UNSPECIFIED) {
                list.add("REJECT_UNSPECIFIED");
                flipped |= REJECT_UNSPECIFIED;
            }
            if ((o & REJECT_INSUFFICIENT_BEACON) == REJECT_INSUFFICIENT_BEACON) {
                list.add("REJECT_INSUFFICIENT_BEACON");
                flipped |= REJECT_INSUFFICIENT_BEACON;
            }
            if ((o & REJECT_INSUFFICIENT_CAPABITY) == REJECT_INSUFFICIENT_CAPABITY) {
                list.add("REJECT_INSUFFICIENT_CAPABITY");
                flipped |= REJECT_INSUFFICIENT_CAPABITY;
            }
            if ((o & REJECT_BSS_TERMINATION_UNDESIRED) == REJECT_BSS_TERMINATION_UNDESIRED) {
                list.add("REJECT_BSS_TERMINATION_UNDESIRED");
                flipped |= REJECT_BSS_TERMINATION_UNDESIRED;
            }
            if ((o & REJECT_BSS_TERMINATION_DELAY_REQUEST) == REJECT_BSS_TERMINATION_DELAY_REQUEST) {
                list.add("REJECT_BSS_TERMINATION_DELAY_REQUEST");
                flipped |= REJECT_BSS_TERMINATION_DELAY_REQUEST;
            }
            if ((o & REJECT_STA_CANDIDATE_LIST_PROVIDED) == REJECT_STA_CANDIDATE_LIST_PROVIDED) {
                list.add("REJECT_STA_CANDIDATE_LIST_PROVIDED");
                flipped |= REJECT_STA_CANDIDATE_LIST_PROVIDED;
            }
            if ((o & REJECT_NO_SUITABLE_CANDIDATES) == REJECT_NO_SUITABLE_CANDIDATES) {
                list.add("REJECT_NO_SUITABLE_CANDIDATES");
                flipped |= REJECT_NO_SUITABLE_CANDIDATES;
            }
            if ((o & REJECT_LEAVING_ESS) == REJECT_LEAVING_ESS) {
                list.add("REJECT_LEAVING_ESS");
                flipped |= REJECT_LEAVING_ESS;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Bitmask of various information retrieved from BSS transition management request frame.
     */
    public static final class BssTmDataFlagsMask {
        /**
         * Preferred candidate list included.
         */
        public static final int WNM_MODE_PREFERRED_CANDIDATE_LIST_INCLUDED = 1 /* 1 << 0 */;
        /**
         * Abridged.
         */
        public static final int WNM_MODE_ABRIDGED = 2 /* 1 << 1 */;
        /**
         * Disassociation Imminent.
         */
        public static final int WNM_MODE_DISASSOCIATION_IMMINENT = 4 /* 1 << 2 */;
        /**
         * BSS termination included.
         */
        public static final int WNM_MODE_BSS_TERMINATION_INCLUDED = 8 /* 1 << 3 */;
        /**
         * ESS Disassociation Imminent.
         */
        public static final int WNM_MODE_ESS_DISASSOCIATION_IMMINENT = 16 /* 1 << 4 */;
        /**
         * MBO transition reason code included.
         */
        public static final int MBO_TRANSITION_REASON_CODE_INCLUDED = 32 /* 1 << 5 */;
        /**
         * MBO retry delay time included.
         */
        public static final int MBO_ASSOC_RETRY_DELAY_INCLUDED = 64 /* 1 << 6 */;
        /**
         * MBO cellular data connection preference value included.
         */
        public static final int MBO_CELLULAR_DATA_CONNECTION_PREFERENCE_INCLUDED = 128 /* 1 << 7 */;
        public static final String toString(int o) {
            if (o == WNM_MODE_PREFERRED_CANDIDATE_LIST_INCLUDED) {
                return "WNM_MODE_PREFERRED_CANDIDATE_LIST_INCLUDED";
            }
            if (o == WNM_MODE_ABRIDGED) {
                return "WNM_MODE_ABRIDGED";
            }
            if (o == WNM_MODE_DISASSOCIATION_IMMINENT) {
                return "WNM_MODE_DISASSOCIATION_IMMINENT";
            }
            if (o == WNM_MODE_BSS_TERMINATION_INCLUDED) {
                return "WNM_MODE_BSS_TERMINATION_INCLUDED";
            }
            if (o == WNM_MODE_ESS_DISASSOCIATION_IMMINENT) {
                return "WNM_MODE_ESS_DISASSOCIATION_IMMINENT";
            }
            if (o == MBO_TRANSITION_REASON_CODE_INCLUDED) {
                return "MBO_TRANSITION_REASON_CODE_INCLUDED";
            }
            if (o == MBO_ASSOC_RETRY_DELAY_INCLUDED) {
                return "MBO_ASSOC_RETRY_DELAY_INCLUDED";
            }
            if (o == MBO_CELLULAR_DATA_CONNECTION_PREFERENCE_INCLUDED) {
                return "MBO_CELLULAR_DATA_CONNECTION_PREFERENCE_INCLUDED";
            }
            return "0x" + Integer.toHexString(o);
        }

        public static final String dumpBitfield(int o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            int flipped = 0;
            if ((o & WNM_MODE_PREFERRED_CANDIDATE_LIST_INCLUDED) == WNM_MODE_PREFERRED_CANDIDATE_LIST_INCLUDED) {
                list.add("WNM_MODE_PREFERRED_CANDIDATE_LIST_INCLUDED");
                flipped |= WNM_MODE_PREFERRED_CANDIDATE_LIST_INCLUDED;
            }
            if ((o & WNM_MODE_ABRIDGED) == WNM_MODE_ABRIDGED) {
                list.add("WNM_MODE_ABRIDGED");
                flipped |= WNM_MODE_ABRIDGED;
            }
            if ((o & WNM_MODE_DISASSOCIATION_IMMINENT) == WNM_MODE_DISASSOCIATION_IMMINENT) {
                list.add("WNM_MODE_DISASSOCIATION_IMMINENT");
                flipped |= WNM_MODE_DISASSOCIATION_IMMINENT;
            }
            if ((o & WNM_MODE_BSS_TERMINATION_INCLUDED) == WNM_MODE_BSS_TERMINATION_INCLUDED) {
                list.add("WNM_MODE_BSS_TERMINATION_INCLUDED");
                flipped |= WNM_MODE_BSS_TERMINATION_INCLUDED;
            }
            if ((o & WNM_MODE_ESS_DISASSOCIATION_IMMINENT) == WNM_MODE_ESS_DISASSOCIATION_IMMINENT) {
                list.add("WNM_MODE_ESS_DISASSOCIATION_IMMINENT");
                flipped |= WNM_MODE_ESS_DISASSOCIATION_IMMINENT;
            }
            if ((o & MBO_TRANSITION_REASON_CODE_INCLUDED) == MBO_TRANSITION_REASON_CODE_INCLUDED) {
                list.add("MBO_TRANSITION_REASON_CODE_INCLUDED");
                flipped |= MBO_TRANSITION_REASON_CODE_INCLUDED;
            }
            if ((o & MBO_ASSOC_RETRY_DELAY_INCLUDED) == MBO_ASSOC_RETRY_DELAY_INCLUDED) {
                list.add("MBO_ASSOC_RETRY_DELAY_INCLUDED");
                flipped |= MBO_ASSOC_RETRY_DELAY_INCLUDED;
            }
            if ((o & MBO_CELLULAR_DATA_CONNECTION_PREFERENCE_INCLUDED) == MBO_CELLULAR_DATA_CONNECTION_PREFERENCE_INCLUDED) {
                list.add("MBO_CELLULAR_DATA_CONNECTION_PREFERENCE_INCLUDED");
                flipped |= MBO_CELLULAR_DATA_CONNECTION_PREFERENCE_INCLUDED;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(o & (~flipped)));
            }
            return String.join(" | ", list);
        }

    };

    /**
     *  MBO spec v1.2, 4.2.6 Table 18: MBO transition reason code attribute
     *  values.
     */
    public static final class MboTransitionReasonCode {
        public static final byte UNSPECIFIED = 0;
        public static final byte EXCESSIVE_FRAME_LOSS = 1;
        public static final byte EXCESSIVE_TRAFFIC_DELAY = 2;
        public static final byte INSUFFICIENT_BANDWIDTH = 3;
        public static final byte LOAD_BALANCING = 4;
        public static final byte LOW_RSSI = 5;
        public static final byte RX_EXCESSIVE_RETRIES = 6;
        public static final byte HIGH_INTERFERENCE = 7;
        public static final byte GRAY_ZONE = 8;
        public static final byte TRANSITION_TO_PREMIUM_AP = 9;
        public static final String toString(byte o) {
            if (o == UNSPECIFIED) {
                return "UNSPECIFIED";
            }
            if (o == EXCESSIVE_FRAME_LOSS) {
                return "EXCESSIVE_FRAME_LOSS";
            }
            if (o == EXCESSIVE_TRAFFIC_DELAY) {
                return "EXCESSIVE_TRAFFIC_DELAY";
            }
            if (o == INSUFFICIENT_BANDWIDTH) {
                return "INSUFFICIENT_BANDWIDTH";
            }
            if (o == LOAD_BALANCING) {
                return "LOAD_BALANCING";
            }
            if (o == LOW_RSSI) {
                return "LOW_RSSI";
            }
            if (o == RX_EXCESSIVE_RETRIES) {
                return "RX_EXCESSIVE_RETRIES";
            }
            if (o == HIGH_INTERFERENCE) {
                return "HIGH_INTERFERENCE";
            }
            if (o == GRAY_ZONE) {
                return "GRAY_ZONE";
            }
            if (o == TRANSITION_TO_PREMIUM_AP) {
                return "TRANSITION_TO_PREMIUM_AP";
            }
            return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
        }

        public static final String dumpBitfield(byte o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            byte flipped = 0;
            list.add("UNSPECIFIED"); // UNSPECIFIED == 0
            if ((o & EXCESSIVE_FRAME_LOSS) == EXCESSIVE_FRAME_LOSS) {
                list.add("EXCESSIVE_FRAME_LOSS");
                flipped |= EXCESSIVE_FRAME_LOSS;
            }
            if ((o & EXCESSIVE_TRAFFIC_DELAY) == EXCESSIVE_TRAFFIC_DELAY) {
                list.add("EXCESSIVE_TRAFFIC_DELAY");
                flipped |= EXCESSIVE_TRAFFIC_DELAY;
            }
            if ((o & INSUFFICIENT_BANDWIDTH) == INSUFFICIENT_BANDWIDTH) {
                list.add("INSUFFICIENT_BANDWIDTH");
                flipped |= INSUFFICIENT_BANDWIDTH;
            }
            if ((o & LOAD_BALANCING) == LOAD_BALANCING) {
                list.add("LOAD_BALANCING");
                flipped |= LOAD_BALANCING;
            }
            if ((o & LOW_RSSI) == LOW_RSSI) {
                list.add("LOW_RSSI");
                flipped |= LOW_RSSI;
            }
            if ((o & RX_EXCESSIVE_RETRIES) == RX_EXCESSIVE_RETRIES) {
                list.add("RX_EXCESSIVE_RETRIES");
                flipped |= RX_EXCESSIVE_RETRIES;
            }
            if ((o & HIGH_INTERFERENCE) == HIGH_INTERFERENCE) {
                list.add("HIGH_INTERFERENCE");
                flipped |= HIGH_INTERFERENCE;
            }
            if ((o & GRAY_ZONE) == GRAY_ZONE) {
                list.add("GRAY_ZONE");
                flipped |= GRAY_ZONE;
            }
            if ((o & TRANSITION_TO_PREMIUM_AP) == TRANSITION_TO_PREMIUM_AP) {
                list.add("TRANSITION_TO_PREMIUM_AP");
                flipped |= TRANSITION_TO_PREMIUM_AP;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
            }
            return String.join(" | ", list);
        }

    };

    /**
     *  MBO spec v1.2, 4.2.5 Table 16: MBO Cellular Data connection preference
     *  attribute values. AP use this to indicate STA, its preference for the
     *  STA to move from BSS to cellular network.
     */
    public static final class MboCellularDataConnectionPrefValue {
        public static final byte EXCLUDED = 0;
        public static final byte NOT_PREFERRED = 1;
        /*
         * 2-254 Reserved.
         */
        public static final byte PREFERRED = -1;
        public static final String toString(byte o) {
            if (o == EXCLUDED) {
                return "EXCLUDED";
            }
            if (o == NOT_PREFERRED) {
                return "NOT_PREFERRED";
            }
            if (o == PREFERRED) {
                return "PREFERRED";
            }
            return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
        }

        public static final String dumpBitfield(byte o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            byte flipped = 0;
            list.add("EXCLUDED"); // EXCLUDED == 0
            if ((o & NOT_PREFERRED) == NOT_PREFERRED) {
                list.add("NOT_PREFERRED");
                flipped |= NOT_PREFERRED;
            }
            if ((o & PREFERRED) == PREFERRED) {
                list.add("PREFERRED");
                flipped |= PREFERRED;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Data retrieved from received BSS transition management request frame.
     */
    public final static class BssTmData {
        /*
         * Status code filled in BSS transition management response frame
         */
        public byte status = 0;
        /*
         * Bitmask of BssTmDataFlagsMask
         */
        public int flags;
        /*
         * Duration for which STA shouldn't try to re-associate.
         */
        public int assocRetryDelayMs = 0;
        /*
         * Reason for BSS transition request.
         */
        public byte mboTransitionReason = 0;
        /*
         * Cellular Data Connection preference value.
         */
        public byte mboCellPreference = 0;

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.BssTmData.class) {
                return false;
            }
            android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.BssTmData other = (android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.BssTmData)otherObject;
            if (this.status != other.status) {
                return false;
            }
            if (!android.os.HidlSupport.deepEquals(this.flags, other.flags)) {
                return false;
            }
            if (this.assocRetryDelayMs != other.assocRetryDelayMs) {
                return false;
            }
            if (this.mboTransitionReason != other.mboTransitionReason) {
                return false;
            }
            if (this.mboCellPreference != other.mboCellPreference) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.status), 
                    android.os.HidlSupport.deepHashCode(this.flags), 
                    android.os.HidlSupport.deepHashCode(this.assocRetryDelayMs), 
                    android.os.HidlSupport.deepHashCode(this.mboTransitionReason), 
                    android.os.HidlSupport.deepHashCode(this.mboCellPreference));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".status = ");
            builder.append(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.BssTmStatusCode.toString(this.status));
            builder.append(", .flags = ");
            builder.append(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.BssTmDataFlagsMask.dumpBitfield(this.flags));
            builder.append(", .assocRetryDelayMs = ");
            builder.append(this.assocRetryDelayMs);
            builder.append(", .mboTransitionReason = ");
            builder.append(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.MboTransitionReasonCode.toString(this.mboTransitionReason));
            builder.append(", .mboCellPreference = ");
            builder.append(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.MboCellularDataConnectionPrefValue.toString(this.mboCellPreference));
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(16 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<BssTmData> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<BssTmData> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 16,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.BssTmData _hidl_vec_element = new android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.BssTmData();
                    ((android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.BssTmData) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 16);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            status = _hidl_blob.getInt8(_hidl_offset + 0);
            flags = _hidl_blob.getInt32(_hidl_offset + 4);
            assocRetryDelayMs = _hidl_blob.getInt32(_hidl_offset + 8);
            mboTransitionReason = _hidl_blob.getInt8(_hidl_offset + 12);
            mboCellPreference = _hidl_blob.getInt8(_hidl_offset + 13);
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<BssTmData> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 16));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 16);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            _hidl_blob.putInt8(_hidl_offset + 0, status);
            _hidl_blob.putInt32(_hidl_offset + 4, flags);
            _hidl_blob.putInt32(_hidl_offset + 8, assocRetryDelayMs);
            _hidl_blob.putInt8(_hidl_offset + 12, mboTransitionReason);
            _hidl_blob.putInt8(_hidl_offset + 13, mboCellPreference);
        }
    };

    /**
     * Indicates pairwise master key (PMK) cache added event.
     *
     * @param expirationTimeInSec expiration time in seconds
     * @param serializedEntry is serialized PMK cache entry, the content is
     *              opaque for the framework and depends on the native implementation.
     */
    void onPmkCacheAdded(long expirationTimeInSec, java.util.ArrayList<Byte> serializedEntry)
        throws android.os.RemoteException;
    /**
     * Indicates a DPP success event.
     */
    void onDppSuccess(int code)
        throws android.os.RemoteException;
    /**
     * Indicates a DPP progress event.
     */
    void onDppProgress_1_3(int code)
        throws android.os.RemoteException;
    /**
     * Indicates a DPP failure event.
     *
     * ssid: A string indicating the SSID for the AP that the Enrollee attempted to connect.
     * channelList: A string containing a list of operating channels and operating classes
     *     indicating the channels that the Enrollee scanned in attempting to discover the AP.
     *     The list conforms to the following ABNF syntax:
     *         channel-list2 = class-and-channels *(“,” class-and-channels)
     *         class-and-channels = class “/” channel *(“,” channel)
     *         class = 1*3DIGIT
     *         channel = 1*3DIGIT
     * bandList: A list of band parameters that are supported by the Enrollee expressed as the
     *     Operating Class.
     */
    void onDppFailure_1_3(int code, String ssid, String channelList, java.util.ArrayList<Short> bandList)
        throws android.os.RemoteException;
    /**
     * Indicates BTM request frame handling status.
     *
     * @param BssTmData Data retrieved from received BSS transition management
     * request frame.
     */
    void onBssTmHandlingDone(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.BssTmData tmData)
        throws android.os.RemoteException;
    /**
     * Indicates an EAP authentication failure.
     * @param errorCode Error code for EAP authentication failure.
     *        Either standard error code (enum EapErrorCode) or
     *        private error code defined by network provider.
     */
    void onEapFailure_1_3(int errorCode)
        throws android.os.RemoteException;
    /**
     * Used to indicate a state change event on this particular iface. If this
     * event is triggered by a particular network, the |SupplicantNetworkId|,
     * |ssid|, |bssid| parameters must indicate the parameters of the network/AP
     * which caused this state transition.
     *
     * @param newState New State of the interface. This must be one of the |State|
     *        values above.
     * @param bssid BSSID of the corresponding AP which caused this state
     *        change event. This must be zero'ed if this event is not
     *        specific to a particular network.
     * @param id ID of the corresponding network which caused this
     *        state change event. This must be invalid (UINT32_MAX) if this
     *        event is not specific to a particular network.
     * @param ssid SSID of the corresponding network which caused this state
     *        change event. This must be empty if this event is not specific
     *        to a particular network.
     * @param filsHlpSent If FILS HLP IEs were included in this association.
     */
    void onStateChanged_1_3(int newState, byte[/* 6 */] bssid, int id, java.util.ArrayList<Byte> ssid, boolean filsHlpSent)
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

    public static final class Proxy implements ISupplicantStaIfaceCallback {
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
            return "[class or subclass of " + ISupplicantStaIfaceCallback.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaIfaceCallback follow.
        @Override
        public void onNetworkAdded(int id)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);
            _hidl_request.writeInt32(id);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* onNetworkAdded */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onNetworkRemoved(int id)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);
            _hidl_request.writeInt32(id);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* onNetworkRemoved */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onStateChanged(int newState, byte[/* 6 */] bssid, int id, java.util.ArrayList<Byte> ssid)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);
            _hidl_request.writeInt32(newState);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) bssid;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }
            _hidl_request.writeInt32(id);
            _hidl_request.writeInt8Vector(ssid);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(3 /* onStateChanged */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onAnqpQueryDone(byte[/* 6 */] bssid, android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.AnqpData data, android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.Hs20AnqpData hs20Data)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) bssid;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }
            ((android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.AnqpData) data).writeToParcel(_hidl_request);
            ((android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.Hs20AnqpData) hs20Data).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(4 /* onAnqpQueryDone */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onHs20IconQueryDone(byte[/* 6 */] bssid, String fileName, java.util.ArrayList<Byte> data)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) bssid;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }
            _hidl_request.writeString(fileName);
            _hidl_request.writeInt8Vector(data);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(5 /* onHs20IconQueryDone */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onHs20SubscriptionRemediation(byte[/* 6 */] bssid, byte osuMethod, String url)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) bssid;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }
            _hidl_request.writeInt8(osuMethod);
            _hidl_request.writeString(url);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(6 /* onHs20SubscriptionRemediation */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onHs20DeauthImminentNotice(byte[/* 6 */] bssid, int reasonCode, int reAuthDelayInSec, String url)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) bssid;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }
            _hidl_request.writeInt32(reasonCode);
            _hidl_request.writeInt32(reAuthDelayInSec);
            _hidl_request.writeString(url);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(7 /* onHs20DeauthImminentNotice */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onDisconnected(byte[/* 6 */] bssid, boolean locallyGenerated, int reasonCode)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) bssid;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }
            _hidl_request.writeBool(locallyGenerated);
            _hidl_request.writeInt32(reasonCode);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(8 /* onDisconnected */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onAssociationRejected(byte[/* 6 */] bssid, int statusCode, boolean timedOut)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) bssid;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }
            _hidl_request.writeInt32(statusCode);
            _hidl_request.writeBool(timedOut);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(9 /* onAssociationRejected */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onAuthenticationTimeout(byte[/* 6 */] bssid)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) bssid;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(10 /* onAuthenticationTimeout */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onEapFailure()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(11 /* onEapFailure */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onBssidChanged(byte reason, byte[/* 6 */] bssid)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);
            _hidl_request.writeInt8(reason);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) bssid;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(12 /* onBssidChanged */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onWpsEventSuccess()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(13 /* onWpsEventSuccess */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onWpsEventFail(byte[/* 6 */] bssid, short configError, short errorInd)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) bssid;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }
            _hidl_request.writeInt16(configError);
            _hidl_request.writeInt16(errorInd);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(14 /* onWpsEventFail */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onWpsEventPbcOverlap()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(15 /* onWpsEventPbcOverlap */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onExtRadioWorkStart(int id)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);
            _hidl_request.writeInt32(id);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(16 /* onExtRadioWorkStart */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onExtRadioWorkTimeout(int id)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);
            _hidl_request.writeInt32(id);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(17 /* onExtRadioWorkTimeout */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback follow.
        @Override
        public void onEapFailure_1_1(int errorCode)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_1.ISupplicantStaIfaceCallback.kInterfaceName);
            _hidl_request.writeInt32(errorCode);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(18 /* onEapFailure_1_1 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::wifi::supplicant::V1_2::ISupplicantStaIfaceCallback follow.
        @Override
        public void onDppSuccessConfigReceived(java.util.ArrayList<Byte> ssid, String password, byte[/* 32 */] psk, int securityAkm)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_2.ISupplicantStaIfaceCallback.kInterfaceName);
            _hidl_request.writeInt8Vector(ssid);
            _hidl_request.writeString(password);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(32 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 32 */]) psk;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 32) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 32 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }
            _hidl_request.writeInt32(securityAkm);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(19 /* onDppSuccessConfigReceived */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onDppSuccessConfigSent()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_2.ISupplicantStaIfaceCallback.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(20 /* onDppSuccessConfigSent */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onDppProgress(int code)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_2.ISupplicantStaIfaceCallback.kInterfaceName);
            _hidl_request.writeInt32(code);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(21 /* onDppProgress */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onDppFailure(int code)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_2.ISupplicantStaIfaceCallback.kInterfaceName);
            _hidl_request.writeInt32(code);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(22 /* onDppFailure */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::wifi::supplicant::V1_3::ISupplicantStaIfaceCallback follow.
        @Override
        public void onPmkCacheAdded(long expirationTimeInSec, java.util.ArrayList<Byte> serializedEntry)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.kInterfaceName);
            _hidl_request.writeInt64(expirationTimeInSec);
            _hidl_request.writeInt8Vector(serializedEntry);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(23 /* onPmkCacheAdded */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onDppSuccess(int code)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.kInterfaceName);
            _hidl_request.writeInt32(code);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(24 /* onDppSuccess */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onDppProgress_1_3(int code)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.kInterfaceName);
            _hidl_request.writeInt32(code);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(25 /* onDppProgress_1_3 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onDppFailure_1_3(int code, String ssid, String channelList, java.util.ArrayList<Short> bandList)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.kInterfaceName);
            _hidl_request.writeInt32(code);
            _hidl_request.writeString(ssid);
            _hidl_request.writeString(channelList);
            _hidl_request.writeInt16Vector(bandList);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(26 /* onDppFailure_1_3 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onBssTmHandlingDone(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.BssTmData tmData)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.kInterfaceName);
            ((android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.BssTmData) tmData).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(27 /* onBssTmHandlingDone */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onEapFailure_1_3(int errorCode)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.kInterfaceName);
            _hidl_request.writeInt32(errorCode);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(28 /* onEapFailure_1_3 */, _hidl_request, _hidl_reply, 1 /* oneway */);
                _hidl_request.releaseTemporaryStorage();
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void onStateChanged_1_3(int newState, byte[/* 6 */] bssid, int id, java.util.ArrayList<Byte> ssid, boolean filsHlpSent)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.kInterfaceName);
            _hidl_request.writeInt32(newState);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(6 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 6 */]) bssid;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 6) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 6 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }
            _hidl_request.writeInt32(id);
            _hidl_request.writeInt8Vector(ssid);
            _hidl_request.writeBool(filsHlpSent);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(29 /* onStateChanged_1_3 */, _hidl_request, _hidl_reply, 1 /* oneway */);
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

    public static abstract class Stub extends android.os.HwBinder implements ISupplicantStaIfaceCallback {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.kInterfaceName,
                    android.hardware.wifi.supplicant.V1_2.ISupplicantStaIfaceCallback.kInterfaceName,
                    android.hardware.wifi.supplicant.V1_1.ISupplicantStaIfaceCallback.kInterfaceName,
                    android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{44,-31,-9,-5,82,-28,-97,-128,-79,58,-101,21,61,73,27,-50,83,5,82,-16,35,87,-22,114,-102,-54,-23,34,-88,101,-97,-109} /* 2ce1f7fb52e49f80b13a9b153d491bce530552f02357ea729acae922a8659f93 */,
                    new byte[/* 32 */]{9,-32,-117,93,18,-79,9,86,46,-51,-40,-120,37,50,-3,31,44,70,57,88,-114,7,118,-99,92,115,-106,-73,-59,-71,-13,79} /* 09e08b5d12b109562ecdd8882532fd1f2c4639588e07769d5c7396b7c5b9f34f */,
                    new byte[/* 32 */]{-51,67,48,-61,25,107,-38,29,100,42,50,-85,-2,35,-89,-42,78,-65,-67,-89,33,-108,6,67,-81,104,103,-81,59,63,10,-87} /* cd4330c3196bda1d642a32abfe23a7d64ebfbda721940643af6867af3b3f0aa9 */,
                    new byte[/* 32 */]{-41,-127,-56,-41,-25,-77,-2,92,-54,-116,-10,-31,-40,-128,110,119,9,-126,-82,83,88,-57,-127,110,-43,27,15,14,-62,114,-25,13} /* d781c8d7e7b3fe5cca8cf6e1d8806e770982ae5358c7816ed51b0f0ec272e70d */,
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
                case 1 /* onNetworkAdded */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    int id = _hidl_request.readInt32();
                    onNetworkAdded(id);
                    break;
                }

                case 2 /* onNetworkRemoved */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    int id = _hidl_request.readInt32();
                    onNetworkRemoved(id);
                    break;
                }

                case 3 /* onStateChanged */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    int newState = _hidl_request.readInt32();
                    byte[/* 6 */] bssid = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) bssid, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    int id = _hidl_request.readInt32();
                    java.util.ArrayList<Byte> ssid = _hidl_request.readInt8Vector();
                    onStateChanged(newState, bssid, id, ssid);
                    break;
                }

                case 4 /* onAnqpQueryDone */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    byte[/* 6 */] bssid = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) bssid, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.AnqpData data = new android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.AnqpData();
                    ((android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.AnqpData) data).readFromParcel(_hidl_request);
                    android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.Hs20AnqpData hs20Data = new android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.Hs20AnqpData();
                    ((android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.Hs20AnqpData) hs20Data).readFromParcel(_hidl_request);
                    onAnqpQueryDone(bssid, data, hs20Data);
                    break;
                }

                case 5 /* onHs20IconQueryDone */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    byte[/* 6 */] bssid = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) bssid, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    String fileName = _hidl_request.readString();
                    java.util.ArrayList<Byte> data = _hidl_request.readInt8Vector();
                    onHs20IconQueryDone(bssid, fileName, data);
                    break;
                }

                case 6 /* onHs20SubscriptionRemediation */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    byte[/* 6 */] bssid = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) bssid, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    byte osuMethod = _hidl_request.readInt8();
                    String url = _hidl_request.readString();
                    onHs20SubscriptionRemediation(bssid, osuMethod, url);
                    break;
                }

                case 7 /* onHs20DeauthImminentNotice */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    byte[/* 6 */] bssid = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) bssid, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    int reasonCode = _hidl_request.readInt32();
                    int reAuthDelayInSec = _hidl_request.readInt32();
                    String url = _hidl_request.readString();
                    onHs20DeauthImminentNotice(bssid, reasonCode, reAuthDelayInSec, url);
                    break;
                }

                case 8 /* onDisconnected */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    byte[/* 6 */] bssid = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) bssid, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    boolean locallyGenerated = _hidl_request.readBool();
                    int reasonCode = _hidl_request.readInt32();
                    onDisconnected(bssid, locallyGenerated, reasonCode);
                    break;
                }

                case 9 /* onAssociationRejected */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    byte[/* 6 */] bssid = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) bssid, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    int statusCode = _hidl_request.readInt32();
                    boolean timedOut = _hidl_request.readBool();
                    onAssociationRejected(bssid, statusCode, timedOut);
                    break;
                }

                case 10 /* onAuthenticationTimeout */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    byte[/* 6 */] bssid = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) bssid, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    onAuthenticationTimeout(bssid);
                    break;
                }

                case 11 /* onEapFailure */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    onEapFailure();
                    break;
                }

                case 12 /* onBssidChanged */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    byte reason = _hidl_request.readInt8();
                    byte[/* 6 */] bssid = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) bssid, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    onBssidChanged(reason, bssid);
                    break;
                }

                case 13 /* onWpsEventSuccess */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    onWpsEventSuccess();
                    break;
                }

                case 14 /* onWpsEventFail */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    byte[/* 6 */] bssid = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) bssid, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    short configError = _hidl_request.readInt16();
                    short errorInd = _hidl_request.readInt16();
                    onWpsEventFail(bssid, configError, errorInd);
                    break;
                }

                case 15 /* onWpsEventPbcOverlap */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    onWpsEventPbcOverlap();
                    break;
                }

                case 16 /* onExtRadioWorkStart */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    int id = _hidl_request.readInt32();
                    onExtRadioWorkStart(id);
                    break;
                }

                case 17 /* onExtRadioWorkTimeout */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaIfaceCallback.kInterfaceName);

                    int id = _hidl_request.readInt32();
                    onExtRadioWorkTimeout(id);
                    break;
                }

                case 18 /* onEapFailure_1_1 */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_1.ISupplicantStaIfaceCallback.kInterfaceName);

                    int errorCode = _hidl_request.readInt32();
                    onEapFailure_1_1(errorCode);
                    break;
                }

                case 19 /* onDppSuccessConfigReceived */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_2.ISupplicantStaIfaceCallback.kInterfaceName);

                    java.util.ArrayList<Byte> ssid = _hidl_request.readInt8Vector();
                    String password = _hidl_request.readString();
                    byte[/* 32 */] psk = new byte[32];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(32 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 32 */]) psk, 32 /* size */);
                            _hidl_array_offset_0 += 32 * 1;
                        }
                    }
                    int securityAkm = _hidl_request.readInt32();
                    onDppSuccessConfigReceived(ssid, password, psk, securityAkm);
                    break;
                }

                case 20 /* onDppSuccessConfigSent */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_2.ISupplicantStaIfaceCallback.kInterfaceName);

                    onDppSuccessConfigSent();
                    break;
                }

                case 21 /* onDppProgress */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_2.ISupplicantStaIfaceCallback.kInterfaceName);

                    int code = _hidl_request.readInt32();
                    onDppProgress(code);
                    break;
                }

                case 22 /* onDppFailure */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_2.ISupplicantStaIfaceCallback.kInterfaceName);

                    int code = _hidl_request.readInt32();
                    onDppFailure(code);
                    break;
                }

                case 23 /* onPmkCacheAdded */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.kInterfaceName);

                    long expirationTimeInSec = _hidl_request.readInt64();
                    java.util.ArrayList<Byte> serializedEntry = _hidl_request.readInt8Vector();
                    onPmkCacheAdded(expirationTimeInSec, serializedEntry);
                    break;
                }

                case 24 /* onDppSuccess */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.kInterfaceName);

                    int code = _hidl_request.readInt32();
                    onDppSuccess(code);
                    break;
                }

                case 25 /* onDppProgress_1_3 */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.kInterfaceName);

                    int code = _hidl_request.readInt32();
                    onDppProgress_1_3(code);
                    break;
                }

                case 26 /* onDppFailure_1_3 */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.kInterfaceName);

                    int code = _hidl_request.readInt32();
                    String ssid = _hidl_request.readString();
                    String channelList = _hidl_request.readString();
                    java.util.ArrayList<Short> bandList = _hidl_request.readInt16Vector();
                    onDppFailure_1_3(code, ssid, channelList, bandList);
                    break;
                }

                case 27 /* onBssTmHandlingDone */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.kInterfaceName);

                    android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.BssTmData tmData = new android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.BssTmData();
                    ((android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.BssTmData) tmData).readFromParcel(_hidl_request);
                    onBssTmHandlingDone(tmData);
                    break;
                }

                case 28 /* onEapFailure_1_3 */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.kInterfaceName);

                    int errorCode = _hidl_request.readInt32();
                    onEapFailure_1_3(errorCode);
                    break;
                }

                case 29 /* onStateChanged_1_3 */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_3.ISupplicantStaIfaceCallback.kInterfaceName);

                    int newState = _hidl_request.readInt32();
                    byte[/* 6 */] bssid = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) bssid, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    int id = _hidl_request.readInt32();
                    java.util.ArrayList<Byte> ssid = _hidl_request.readInt8Vector();
                    boolean filsHlpSent = _hidl_request.readBool();
                    onStateChanged_1_3(newState, bssid, id, ssid, filsHlpSent);
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
