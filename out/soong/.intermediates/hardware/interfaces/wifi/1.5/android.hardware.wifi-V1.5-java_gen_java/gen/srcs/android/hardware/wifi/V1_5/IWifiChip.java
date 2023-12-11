package android.hardware.wifi.V1_5;

/**
 * Interface that represents a chip that must be configured as a single unit.
 */
public interface IWifiChip extends android.hardware.wifi.V1_4.IWifiChip {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.wifi@1.5::IWifiChip";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static IWifiChip asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof IWifiChip)) {
            return (IWifiChip)iface;
        }

        IWifiChip proxy = new IWifiChip.Proxy(binder);

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
    public static IWifiChip castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : IWifiChip.asInterface(iface.asBinder());
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
    public static IWifiChip getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return IWifiChip.asInterface(android.os.HwBinder.getService("android.hardware.wifi@1.5::IWifiChip", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static IWifiChip getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static IWifiChip getService(String serviceName) throws android.os.RemoteException {
        return IWifiChip.asInterface(android.os.HwBinder.getService("android.hardware.wifi@1.5::IWifiChip", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static IWifiChip getService() throws android.os.RemoteException {
        return getService("default");
    }

    /**
     * Capabilities exposed by this chip.
     */
    public static final class ChipCapabilityMask {
        /**
         * Memory dump of Firmware.
         */
        public static final int DEBUG_MEMORY_FIRMWARE_DUMP = 1 /* 1 << 0 */;
        /**
         * Memory dump of Driver.
         */
        public static final int DEBUG_MEMORY_DRIVER_DUMP = 2 /* 1 << 1 */;
        /**
         * Connectivity events reported via debug ring buffer.
         */
        public static final int DEBUG_RING_BUFFER_CONNECT_EVENT = 4 /* 1 << 2 */;
        /**
         * Power events reported via debug ring buffer.
         */
        public static final int DEBUG_RING_BUFFER_POWER_EVENT = 8 /* 1 << 3 */;
        /**
         * Wakelock events reported via debug ring buffer.
         */
        public static final int DEBUG_RING_BUFFER_WAKELOCK_EVENT = 16 /* 1 << 4 */;
        /**
         * Vendor data reported via debug ring buffer.
         * This mostly contains firmware event logs.
         */
        public static final int DEBUG_RING_BUFFER_VENDOR_DATA = 32 /* 1 << 5 */;
        /**
         * Host wake reasons stats collection.
         */
        public static final int DEBUG_HOST_WAKE_REASON_STATS = 64 /* 1 << 6 */;
        /**
         * Error alerts.
         */
        public static final int DEBUG_ERROR_ALERTS = 128 /* 1 << 7 */;
        /**
         * Set/Reset Tx Power limits.
         */
        public static final int SET_TX_POWER_LIMIT = 256 /* 1 << 8 */;
        /**
         * Device to Device RTT.
         */
        public static final int D2D_RTT = 512 /* 1 << 9 */;
        /**
         * Device to AP RTT.
         */
        public static final int D2AP_RTT = 1024 /* 1 << 10 */;
        /**
         * Set/Reset Tx Power limits.
         */
        public static final int USE_BODY_HEAD_SAR = 2048 /* 1 << 11 */;
        /**
         * Set Latency Mode.
         */
        public static final int SET_LATENCY_MODE = 4096 /* 1 << 12 */;
        /**
         * Support P2P MAC randomization
         */
        public static final int P2P_RAND_MAC = 8192 /* 1 << 13 */;
        /**
         * chip can operate in the 60GHz band(WiGig chip)
         */
        public static final int WIGIG = 16384 /* 1 << 14 */;
        public static final String toString(int o) {
            if (o == DEBUG_MEMORY_FIRMWARE_DUMP) {
                return "DEBUG_MEMORY_FIRMWARE_DUMP";
            }
            if (o == DEBUG_MEMORY_DRIVER_DUMP) {
                return "DEBUG_MEMORY_DRIVER_DUMP";
            }
            if (o == DEBUG_RING_BUFFER_CONNECT_EVENT) {
                return "DEBUG_RING_BUFFER_CONNECT_EVENT";
            }
            if (o == DEBUG_RING_BUFFER_POWER_EVENT) {
                return "DEBUG_RING_BUFFER_POWER_EVENT";
            }
            if (o == DEBUG_RING_BUFFER_WAKELOCK_EVENT) {
                return "DEBUG_RING_BUFFER_WAKELOCK_EVENT";
            }
            if (o == DEBUG_RING_BUFFER_VENDOR_DATA) {
                return "DEBUG_RING_BUFFER_VENDOR_DATA";
            }
            if (o == DEBUG_HOST_WAKE_REASON_STATS) {
                return "DEBUG_HOST_WAKE_REASON_STATS";
            }
            if (o == DEBUG_ERROR_ALERTS) {
                return "DEBUG_ERROR_ALERTS";
            }
            if (o == SET_TX_POWER_LIMIT) {
                return "SET_TX_POWER_LIMIT";
            }
            if (o == D2D_RTT) {
                return "D2D_RTT";
            }
            if (o == D2AP_RTT) {
                return "D2AP_RTT";
            }
            if (o == USE_BODY_HEAD_SAR) {
                return "USE_BODY_HEAD_SAR";
            }
            if (o == SET_LATENCY_MODE) {
                return "SET_LATENCY_MODE";
            }
            if (o == P2P_RAND_MAC) {
                return "P2P_RAND_MAC";
            }
            if (o == WIGIG) {
                return "WIGIG";
            }
            return "0x" + Integer.toHexString(o);
        }

        public static final String dumpBitfield(int o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            int flipped = 0;
            if ((o & DEBUG_MEMORY_FIRMWARE_DUMP) == DEBUG_MEMORY_FIRMWARE_DUMP) {
                list.add("DEBUG_MEMORY_FIRMWARE_DUMP");
                flipped |= DEBUG_MEMORY_FIRMWARE_DUMP;
            }
            if ((o & DEBUG_MEMORY_DRIVER_DUMP) == DEBUG_MEMORY_DRIVER_DUMP) {
                list.add("DEBUG_MEMORY_DRIVER_DUMP");
                flipped |= DEBUG_MEMORY_DRIVER_DUMP;
            }
            if ((o & DEBUG_RING_BUFFER_CONNECT_EVENT) == DEBUG_RING_BUFFER_CONNECT_EVENT) {
                list.add("DEBUG_RING_BUFFER_CONNECT_EVENT");
                flipped |= DEBUG_RING_BUFFER_CONNECT_EVENT;
            }
            if ((o & DEBUG_RING_BUFFER_POWER_EVENT) == DEBUG_RING_BUFFER_POWER_EVENT) {
                list.add("DEBUG_RING_BUFFER_POWER_EVENT");
                flipped |= DEBUG_RING_BUFFER_POWER_EVENT;
            }
            if ((o & DEBUG_RING_BUFFER_WAKELOCK_EVENT) == DEBUG_RING_BUFFER_WAKELOCK_EVENT) {
                list.add("DEBUG_RING_BUFFER_WAKELOCK_EVENT");
                flipped |= DEBUG_RING_BUFFER_WAKELOCK_EVENT;
            }
            if ((o & DEBUG_RING_BUFFER_VENDOR_DATA) == DEBUG_RING_BUFFER_VENDOR_DATA) {
                list.add("DEBUG_RING_BUFFER_VENDOR_DATA");
                flipped |= DEBUG_RING_BUFFER_VENDOR_DATA;
            }
            if ((o & DEBUG_HOST_WAKE_REASON_STATS) == DEBUG_HOST_WAKE_REASON_STATS) {
                list.add("DEBUG_HOST_WAKE_REASON_STATS");
                flipped |= DEBUG_HOST_WAKE_REASON_STATS;
            }
            if ((o & DEBUG_ERROR_ALERTS) == DEBUG_ERROR_ALERTS) {
                list.add("DEBUG_ERROR_ALERTS");
                flipped |= DEBUG_ERROR_ALERTS;
            }
            if ((o & SET_TX_POWER_LIMIT) == SET_TX_POWER_LIMIT) {
                list.add("SET_TX_POWER_LIMIT");
                flipped |= SET_TX_POWER_LIMIT;
            }
            if ((o & D2D_RTT) == D2D_RTT) {
                list.add("D2D_RTT");
                flipped |= D2D_RTT;
            }
            if ((o & D2AP_RTT) == D2AP_RTT) {
                list.add("D2AP_RTT");
                flipped |= D2AP_RTT;
            }
            if ((o & USE_BODY_HEAD_SAR) == USE_BODY_HEAD_SAR) {
                list.add("USE_BODY_HEAD_SAR");
                flipped |= USE_BODY_HEAD_SAR;
            }
            if ((o & SET_LATENCY_MODE) == SET_LATENCY_MODE) {
                list.add("SET_LATENCY_MODE");
                flipped |= SET_LATENCY_MODE;
            }
            if ((o & P2P_RAND_MAC) == P2P_RAND_MAC) {
                list.add("P2P_RAND_MAC");
                flipped |= P2P_RAND_MAC;
            }
            if ((o & WIGIG) == WIGIG) {
                list.add("WIGIG");
                flipped |= WIGIG;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(o & (~flipped)));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * When there are 2 or more simultaneous STA connections, this use case hint indicates what
     * use-case is being enabled by the framework. This use case hint can be used by the firmware
     * to modify various firmware configurations like:
     *   - Allowed BSSIDs the firmware can choose for the initial connection/roaming attempts.
     *   - Duty cycle to choose for the 2 STA connections if the radio is in MCC mode.
     *   - Whether roaming, APF and other offloads needs to be enabled or not.
     * Note:
     *   - This will be invoked before an active wifi connection is established on the second
     *     interface.
     *   - This use-case hint is implicitly void when the second STA interface is brought down.
     *   - When there is only 1 STA interface, the must should still retain the last use case
     *     set, which must become active the next time multi STA is enabled.
     *     1. Initialize with single STA.
     *     2. Framework creates second STA.
     *     3. Framework sets use case to DUAL_STA_NON_TRANSIENT_UNBIASED.
     *     4. Framework destroys second STA. Only 1 STA remains.
     *     5. Framework recreates second STA.
     *     6. The active use case remains DUAL_STA_NON_TRANSIENT_UNBIASED (i.e. firmware should not
     *        automatically change it during period of single STA unless requested by framework).
     */
    public static final class MultiStaUseCase {
        /**
         * Usage:
         * - This will be sent down for make before break use-case.
         * - Platform is trying to speculatively connect to a second network and evaluate it without
         *  disrupting the primary connection.
         * Requirements for Firmware:
         * - Do not reduce the number of tx/rx chains of primary connection.
         * - If using MCC, should set the MCC duty cycle of the primary connection to be higher than
         *  the secondary connection (maybe 70/30 split).
         * - Should pick the best BSSID for the secondary STA (disregard the chip mode) independent
         *   of the primary STA:
         *    - Don’t optimize for DBS vs MCC/SCC
         * - Should not impact the primary connection’s bssid selection:
         *    - Don’t downgrade chains of the existing primary connection.
         *    - Don’t optimize for DBS vs MCC/SCC.
         */
        public static final byte DUAL_STA_TRANSIENT_PREFER_PRIMARY = 0;
        /**
         * Usage:
         * - This will be sent down for any app requested peer to peer connections.
         * - In this case, both the connections needs to be allocated equal resources.
         * - For the peer to peer use case, BSSID for the secondary connection will be chosen by the
         *   framework.
         *
         * Requirements for Firmware:
         * - Can choose MCC or DBS mode depending on the MCC efficiency and HW capability.
         * - If using MCC, set the MCC duty cycle of the primary connection to be equal to the
         *   secondary connection.
         * - Prefer BSSID candidates which will help provide the best "overall" performance for both
         *   the connections.
         */
        public static final byte DUAL_STA_NON_TRANSIENT_UNBIASED = 1;
        public static final String toString(byte o) {
            if (o == DUAL_STA_TRANSIENT_PREFER_PRIMARY) {
                return "DUAL_STA_TRANSIENT_PREFER_PRIMARY";
            }
            if (o == DUAL_STA_NON_TRANSIENT_UNBIASED) {
                return "DUAL_STA_NON_TRANSIENT_UNBIASED";
            }
            return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
        }

        public static final String dumpBitfield(byte o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            byte flipped = 0;
            list.add("DUAL_STA_TRANSIENT_PREFER_PRIMARY"); // DUAL_STA_TRANSIENT_PREFER_PRIMARY == 0
            if ((o & DUAL_STA_NON_TRANSIENT_UNBIASED) == DUAL_STA_NON_TRANSIENT_UNBIASED) {
                list.add("DUAL_STA_NON_TRANSIENT_UNBIASED");
                flipped |= DUAL_STA_NON_TRANSIENT_UNBIASED;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Representation of a Wi-Fi channel for Wi-Fi coex channel avoidance.
     */
    public final static class CoexUnsafeChannel {
        /*
         * The band of the channel
         */
        public int band = 0;
        /*
         * The channel number
         */
        public int channel = 0;
        /**
         * The power cap will be a maximum power value in dbm that is allowed to be transmitted by
         * the chip on this channel. A value of PowerCapConstant.NO_POWER_CAP means no limitation
         * on transmitted power is needed by the chip for this channel.
         */
        public int powerCapDbm = 0;

        @Override
        public final boolean equals(Object otherObject) {
            if (this == otherObject) {
                return true;
            }
            if (otherObject == null) {
                return false;
            }
            if (otherObject.getClass() != android.hardware.wifi.V1_5.IWifiChip.CoexUnsafeChannel.class) {
                return false;
            }
            android.hardware.wifi.V1_5.IWifiChip.CoexUnsafeChannel other = (android.hardware.wifi.V1_5.IWifiChip.CoexUnsafeChannel)otherObject;
            if (this.band != other.band) {
                return false;
            }
            if (this.channel != other.channel) {
                return false;
            }
            if (this.powerCapDbm != other.powerCapDbm) {
                return false;
            }
            return true;
        }

        @Override
        public final int hashCode() {
            return java.util.Objects.hash(
                    android.os.HidlSupport.deepHashCode(this.band), 
                    android.os.HidlSupport.deepHashCode(this.channel), 
                    android.os.HidlSupport.deepHashCode(this.powerCapDbm));
        }

        @Override
        public final String toString() {
            java.lang.StringBuilder builder = new java.lang.StringBuilder();
            builder.append("{");
            builder.append(".band = ");
            builder.append(android.hardware.wifi.V1_5.WifiBand.toString(this.band));
            builder.append(", .channel = ");
            builder.append(this.channel);
            builder.append(", .powerCapDbm = ");
            builder.append(this.powerCapDbm);
            builder.append("}");
            return builder.toString();
        }

        public final void readFromParcel(android.os.HwParcel parcel) {
            android.os.HwBlob blob = parcel.readBuffer(12 /* size */);
            readEmbeddedFromParcel(parcel, blob, 0 /* parentOffset */);
        }

        public static final java.util.ArrayList<CoexUnsafeChannel> readVectorFromParcel(android.os.HwParcel parcel) {
            java.util.ArrayList<CoexUnsafeChannel> _hidl_vec = new java.util.ArrayList();
            android.os.HwBlob _hidl_blob = parcel.readBuffer(16 /* sizeof hidl_vec<T> */);

            {
                int _hidl_vec_size = _hidl_blob.getInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */);
                android.os.HwBlob childBlob = parcel.readEmbeddedBuffer(
                        _hidl_vec_size * 12,_hidl_blob.handle(),
                        0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */,true /* nullable */);

                _hidl_vec.clear();
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    android.hardware.wifi.V1_5.IWifiChip.CoexUnsafeChannel _hidl_vec_element = new android.hardware.wifi.V1_5.IWifiChip.CoexUnsafeChannel();
                    ((android.hardware.wifi.V1_5.IWifiChip.CoexUnsafeChannel) _hidl_vec_element).readEmbeddedFromParcel(parcel, childBlob, _hidl_index_0 * 12);
                    _hidl_vec.add(_hidl_vec_element);
                }
            }

            return _hidl_vec;
        }

        public final void readEmbeddedFromParcel(
                android.os.HwParcel parcel, android.os.HwBlob _hidl_blob, long _hidl_offset) {
            band = _hidl_blob.getInt32(_hidl_offset + 0);
            channel = _hidl_blob.getInt32(_hidl_offset + 4);
            powerCapDbm = _hidl_blob.getInt32(_hidl_offset + 8);
        }

        public final void writeToParcel(android.os.HwParcel parcel) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(12 /* size */);
            writeEmbeddedToBlob(_hidl_blob, 0 /* parentOffset */);
            parcel.writeBuffer(_hidl_blob);
        }

        public static final void writeVectorToParcel(
                android.os.HwParcel parcel, java.util.ArrayList<CoexUnsafeChannel> _hidl_vec) {
            android.os.HwBlob _hidl_blob = new android.os.HwBlob(16 /* sizeof(hidl_vec<T>) */);
            {
                int _hidl_vec_size = _hidl_vec.size();
                _hidl_blob.putInt32(0 + 8 /* offsetof(hidl_vec<T>, mSize) */, _hidl_vec_size);
                _hidl_blob.putBool(0 + 12 /* offsetof(hidl_vec<T>, mOwnsBuffer) */, false);
                android.os.HwBlob childBlob = new android.os.HwBlob((int)(_hidl_vec_size * 12));
                for (int _hidl_index_0 = 0; _hidl_index_0 < _hidl_vec_size; ++_hidl_index_0) {
                    _hidl_vec.get(_hidl_index_0).writeEmbeddedToBlob(childBlob, _hidl_index_0 * 12);
                }
                _hidl_blob.putBlob(0 + 0 /* offsetof(hidl_vec<T>, mBuffer) */, childBlob);
            }

            parcel.writeBuffer(_hidl_blob);
        }

        public final void writeEmbeddedToBlob(
                android.os.HwBlob _hidl_blob, long _hidl_offset) {
            _hidl_blob.putInt32(_hidl_offset + 0, band);
            _hidl_blob.putInt32(_hidl_offset + 4, channel);
            _hidl_blob.putInt32(_hidl_offset + 8, powerCapDbm);
        }
    };

    public static final class PowerCapConstant {
        public static final int NO_POWER_CAP = 2147483647 /* 0x7FFFFFFF */;
        public static final String toString(int o) {
            if (o == NO_POWER_CAP) {
                return "NO_POWER_CAP";
            }
            return "0x" + Integer.toHexString(o);
        }

        public static final String dumpBitfield(int o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            int flipped = 0;
            if ((o & NO_POWER_CAP) == NO_POWER_CAP) {
                list.add("NO_POWER_CAP");
                flipped |= NO_POWER_CAP;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(o & (~flipped)));
            }
            return String.join(" | ", list);
        }

    };

    public static final class CoexRestriction {
        public static final int WIFI_DIRECT = 1 /* 1 << 0 */;
        public static final int SOFTAP = 2 /* 1 << 1 */;
        public static final int WIFI_AWARE = 4 /* 1 << 2 */;
        public static final String toString(int o) {
            if (o == WIFI_DIRECT) {
                return "WIFI_DIRECT";
            }
            if (o == SOFTAP) {
                return "SOFTAP";
            }
            if (o == WIFI_AWARE) {
                return "WIFI_AWARE";
            }
            return "0x" + Integer.toHexString(o);
        }

        public static final String dumpBitfield(int o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            int flipped = 0;
            if ((o & WIFI_DIRECT) == WIFI_DIRECT) {
                list.add("WIFI_DIRECT");
                flipped |= WIFI_DIRECT;
            }
            if ((o & SOFTAP) == SOFTAP) {
                list.add("SOFTAP");
                flipped |= SOFTAP;
            }
            if ((o & WIFI_AWARE) == WIFI_AWARE) {
                list.add("WIFI_AWARE");
                flipped |= WIFI_AWARE;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(o & (~flipped)));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Usable Wifi channels filter masks.
     */
    public static final class UsableChannelFilter {
        /**
         * Filter Wifi channels that should be avoided due to extreme
         * cellular coexistence restrictions. Some Wifi channels can have
         * extreme interference from/to cellular due to short frequency
         * seperation with neighboring cellular channels or when there
         * is harmonic and intermodulation interference. Channels which
         * only have some performance degradation (e.g. power back off is
         * sufficient to deal with coexistence issue) can be included and
         * should not be filtered out.
         */
        public static final int CELLULAR_COEXISTENCE = 1 /* 1 << 0 */;
        /**
         * Filter based on concurrency state.
         * Examples:
         * - 5GHz SAP operation may be supported in standalone mode, but if
         *  there is STA connection on 5GHz DFS channel, none of the 5GHz
         *  channels are usable for SAP if device does not support DFS SAP mode.
         * - P2P GO may not be supported on indoor channels in EU during
         *  standalone mode but if there is a STA connection on indoor channel,
         *  P2P GO may be supported by some vendors on the same STA channel.
         */
        public static final int CONCURRENCY = 2 /* 1 << 1 */;
        public static final String toString(int o) {
            if (o == CELLULAR_COEXISTENCE) {
                return "CELLULAR_COEXISTENCE";
            }
            if (o == CONCURRENCY) {
                return "CONCURRENCY";
            }
            return "0x" + Integer.toHexString(o);
        }

        public static final String dumpBitfield(int o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            int flipped = 0;
            if ((o & CELLULAR_COEXISTENCE) == CELLULAR_COEXISTENCE) {
                list.add("CELLULAR_COEXISTENCE");
                flipped |= CELLULAR_COEXISTENCE;
            }
            if ((o & CONCURRENCY) == CONCURRENCY) {
                list.add("CONCURRENCY");
                flipped |= CONCURRENCY;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(o & (~flipped)));
            }
            return String.join(" | ", list);
        }

    };


    @java.lang.FunctionalInterface
    public interface getCapabilities_1_5Callback {
        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, int capabilities);
    }

    /**
     * Get the capabilities supported by this chip.
     *
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_CHIP_INVALID|,
     *         |WifiStatusCode.ERROR_NOT_AVAILABLE|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     * @return capabilities Bitset of |ChipCapabilityMask| values.
     */
    void getCapabilities_1_5(getCapabilities_1_5Callback _hidl_cb)
        throws android.os.RemoteException;
    /**
     * Invoked to indicate that the provided iface is the primary STA iface when there are more
     * than 1 STA iface concurrently active.
     * Notes:
     * - If the wifi firmware/chip cannot support multiple instances of any offload
     *   (like roaming, APF, rssi threshold, etc), the firmware should ensure that these
     *   offloads are at least enabled for the primary interface. If the new primary interface is
     *   already connected to a network, the firmware must switch all the offloads on
     *   this new interface without disconnecting.
     * - When there is only 1 STA interface, the firmware must still retain the last primary
     *   connection, which must become active the next time multi STA is enabled.
     *
     * @param ifname Name of the STA iface.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_CHIP_INVALID|,
     *         |WifiStatusCode.ERROR_INVALID_ARGS|
     */
    android.hardware.wifi.V1_0.WifiStatus setMultiStaPrimaryConnection(String ifName)
        throws android.os.RemoteException;
    /**
     * Invoked to indicate the STA + STA use-case that is active.
     *
     * Refer to documentation of |MultiStaUseCase| for details.
     *
     * @param useCase Use case that is active.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_CHIP_INVALID|,
     *         |WifiStatusCode.ERROR_INVALID_ARGS|
     */
    android.hardware.wifi.V1_0.WifiStatus setMultiStaUseCase(byte useCase)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface createBridgedApIfaceCallback {
        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, android.hardware.wifi.V1_5.IWifiApIface iface);
    }

    /**
     * Create bridged IWifiApIface.
     *
     * Depending on the mode the chip is configured in, the interface creation
     * may fail (code: |ERROR_NOT_AVAILABLE|) if we've already reached the maximum
     * allowed (specified in |ChipIfaceCombination|) number of ifaces of the AP
     * type.
     *
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_CHIP_INVALID|,
     *         |WifiStatusCode.ERROR_NOT_SUPPORTED|,
     *         |WifiStatusCode.ERROR_NOT_AVAILABLE|
     * @return iface HIDL interface object representing the iface if
     *         successful, null otherwise.
     */
    void createBridgedApIface(createBridgedApIfaceCallback _hidl_cb)
        throws android.os.RemoteException;
    /**
     * Removes one of the instance on the AP Iface with the provided ifaceName and
     * ifaceInstanceName.
     *
     * Use the API: removeApIface with brIfaceName in the V1_0::WifiChip.hal to remove bridge Iface.
     *
     * @param brIfaceName Name of the bridged AP iface.
     * @param ifaceInstanceName Name of the instance. The empty instance is
     * invalid.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_CHIP_INVALID|,
     *         |WifiStatusCode.ERROR_INVALID_ARGS|,
     *         |WifiStatusCode.ERROR_NOT_AVAILABLE|
     */
    android.hardware.wifi.V1_0.WifiStatus removeIfaceInstanceFromBridgedApIface(String brIfaceName, String ifaceInstanceName)
        throws android.os.RemoteException;
    /**
     * Invoked to indicate that the provided |CoexUnsafeChannels| should be avoided with the
     * specified restrictions.
     *
     * Channel avoidance is a suggestion and should be done on a best-effort approach. If a provided
     * channel is used, then the specified power cap should be applied.
     *
     * In addition, hard restrictions on the Wifi modes may be indicated by |CoexRestriction| bits
     * (WIFI_DIRECT, SOFTAP, WIFI_AWARE) in the |restrictions| bitfield. If a hard restriction is
     * provided, then the channels should be completely avoided for the provided Wifi modes instead
     * of by best-effort.
     *
     * @param unsafeChannels List of |CoexUnsafeChannels| to avoid.
     * @param restrictions Bitset of |CoexRestriction| values indicating Wifi interfaces to
     *         completely avoid.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_CHIP_INVALID|,
     *         |WifiStatusCode.ERROR_INVALID_ARGS|,
     */
    android.hardware.wifi.V1_0.WifiStatus setCoexUnsafeChannels(java.util.ArrayList<android.hardware.wifi.V1_5.IWifiChip.CoexUnsafeChannel> unsafeChannels, int restrictions)
        throws android.os.RemoteException;
    /**
     * Set country code for this Wifi chip.
     *
     * Country code is global setting across the Wifi chip and not Wifi
     * interface (STA or AP) specific. Legacy HAL API's for country code in
     * @1.0::ISupplicantStaIface::setCountryCode &
     * @1.0::IWifiApIface:setCountryCode are deprecated in favor of this
     * chip level API.
     *
     * @param code 2 byte country code (as defined in ISO 3166) to set.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.FAILURE_UNKNOWN|,
     *         |WifiStatusCode.FAILURE_IFACE_INVALID|
     */
    android.hardware.wifi.V1_0.WifiStatus setCountryCode(byte[/* 2 */] code)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface getUsableChannelsCallback {
        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, java.util.ArrayList<android.hardware.wifi.V1_5.WifiUsableChannel> channels);
    }

    /**
     * Retrieve list of usable Wifi channels for the specified band &
     * operational modes.
     *
     * The list of usable Wifi channels in a given band depends on factors
     * like current country code, operational mode (e.g. STA, SAP, WFD-CLI,
     * WFD-GO, TDLS, NAN) and other restrictons due to DFS, cellular coexistence
     * and conncurency state of the device.
     *
     * @param band |WifiBand| for which list of usable channels is requested.
     * @param ifaceModeMask Bitmask of the modes represented by |WifiIfaceMode|
     *        Bitmask respresents all the modes that the caller is interested
     *        in (e.g. STA, SAP, CLI, GO, TDLS, NAN). E.g. If the caller is
     *        interested in knowing usable channels for P2P CLI, P2P GO & NAN,
     *        ifaceModeMask would be set to
     *        IFACE_MODE_P2P_CLIENT|IFACE_MODE_P2P_GO|IFACE_MODE_NAN.
     * @param filterMask Bitmask of filters represented by
     *        |UsableChannelFilter|. Specifies whether driver should filter
     *        channels based on additional criteria. If no filter is specified
     *        driver should return usable channels purely based on regulatory
     *        constraints.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_NOT_SUPPORTED|,
     *         |WifiStatusCode.ERROR_INVALID_ARGS|,
     *         |WifiStatusCode.FAILURE_UNKNOWN|
     * @return channels List of channels represented by |WifiUsableChannel|
     *         Each entry represents a channel frequency, bandwidth and
     *         bitmask of modes (e.g. STA, SAP, CLI, GO, TDLS, NAN) that are
     *         allowed on that channel. E.g. If only STA mode can be supported
     *         on an indoor channel, only the IFACE_MODE_STA bit would be set
     *         for that channel. If 5GHz SAP cannot be supported, then none of
     *         the 5GHz channels will have IFACE_MODE_SOFTAP bit set.
     *         Note: Bits do not represent concurrency state. Each bit only
     *         represents whether particular mode is allowed on that channel.
     */
    void getUsableChannels(int band, int ifaceModeMask, int filterMask, getUsableChannelsCallback _hidl_cb)
        throws android.os.RemoteException;
    /**
     * Trigger subsystem restart
     *
     * If the framework detects a problem (e.g. connection failure),
     * it must call this function to attempt recovery.
     *
     * When the wifi HAL receiveds triggerSubsystemRestart(), it must restart
     * the wlan subsystem, especially the wlan firmware.
     *
     * Regarding the callback function for subsystem restart, refer to documentation of
     * |IWifiEventCallback.onSubsystemRestart| for details.
     *
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_CHIP_INVALID|,
     *         |WifiStatusCode.ERROR_NOT_AVAILABLE|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     */
    android.hardware.wifi.V1_0.WifiStatus triggerSubsystemRestart()
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

    public static final class Proxy implements IWifiChip {
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
            return "[class or subclass of " + IWifiChip.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::wifi::V1_0::IWifiChip follow.
        @Override
        public void getId(getIdCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* getId */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_id = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_id);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus registerEventCallback(android.hardware.wifi.V1_0.IWifiChipEventCallback callback)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);
            _hidl_request.writeStrongBinder(callback == null ? null : callback.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* registerEventCallback */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getCapabilities(getCapabilitiesCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(3 /* getCapabilities */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_capabilities = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_capabilities);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getAvailableModes(getAvailableModesCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(4 /* getAvailableModes */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<android.hardware.wifi.V1_0.IWifiChip.ChipMode> _hidl_out_modes = android.hardware.wifi.V1_0.IWifiChip.ChipMode.readVectorFromParcel(_hidl_reply);
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_modes);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus configureChip(int modeId)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);
            _hidl_request.writeInt32(modeId);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(5 /* configureChip */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getMode(getModeCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(6 /* getMode */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_modeId = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_modeId);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void requestChipDebugInfo(requestChipDebugInfoCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(7 /* requestChipDebugInfo */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                android.hardware.wifi.V1_0.IWifiChip.ChipDebugInfo _hidl_out_chipDebugInfo = new android.hardware.wifi.V1_0.IWifiChip.ChipDebugInfo();
                ((android.hardware.wifi.V1_0.IWifiChip.ChipDebugInfo) _hidl_out_chipDebugInfo).readFromParcel(_hidl_reply);
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_chipDebugInfo);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void requestDriverDebugDump(requestDriverDebugDumpCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(8 /* requestDriverDebugDump */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<Byte> _hidl_out_blob = _hidl_reply.readInt8Vector();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_blob);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void requestFirmwareDebugDump(requestFirmwareDebugDumpCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(9 /* requestFirmwareDebugDump */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<Byte> _hidl_out_blob = _hidl_reply.readInt8Vector();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_blob);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void createApIface(createApIfaceCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(10 /* createApIface */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                android.hardware.wifi.V1_0.IWifiApIface _hidl_out_iface = android.hardware.wifi.V1_0.IWifiApIface.asInterface(_hidl_reply.readStrongBinder());
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_iface);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getApIfaceNames(getApIfaceNamesCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(11 /* getApIfaceNames */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<String> _hidl_out_ifnames = _hidl_reply.readStringVector();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_ifnames);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getApIface(String ifname, getApIfaceCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);
            _hidl_request.writeString(ifname);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(12 /* getApIface */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                android.hardware.wifi.V1_0.IWifiApIface _hidl_out_iface = android.hardware.wifi.V1_0.IWifiApIface.asInterface(_hidl_reply.readStrongBinder());
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_iface);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus removeApIface(String ifname)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);
            _hidl_request.writeString(ifname);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(13 /* removeApIface */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void createNanIface(createNanIfaceCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(14 /* createNanIface */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                android.hardware.wifi.V1_0.IWifiNanIface _hidl_out_iface = android.hardware.wifi.V1_0.IWifiNanIface.asInterface(_hidl_reply.readStrongBinder());
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_iface);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getNanIfaceNames(getNanIfaceNamesCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(15 /* getNanIfaceNames */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<String> _hidl_out_ifnames = _hidl_reply.readStringVector();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_ifnames);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getNanIface(String ifname, getNanIfaceCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);
            _hidl_request.writeString(ifname);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(16 /* getNanIface */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                android.hardware.wifi.V1_0.IWifiNanIface _hidl_out_iface = android.hardware.wifi.V1_0.IWifiNanIface.asInterface(_hidl_reply.readStrongBinder());
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_iface);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus removeNanIface(String ifname)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);
            _hidl_request.writeString(ifname);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(17 /* removeNanIface */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void createP2pIface(createP2pIfaceCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(18 /* createP2pIface */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                android.hardware.wifi.V1_0.IWifiP2pIface _hidl_out_iface = android.hardware.wifi.V1_0.IWifiP2pIface.asInterface(_hidl_reply.readStrongBinder());
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_iface);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getP2pIfaceNames(getP2pIfaceNamesCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(19 /* getP2pIfaceNames */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<String> _hidl_out_ifnames = _hidl_reply.readStringVector();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_ifnames);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getP2pIface(String ifname, getP2pIfaceCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);
            _hidl_request.writeString(ifname);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(20 /* getP2pIface */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                android.hardware.wifi.V1_0.IWifiP2pIface _hidl_out_iface = android.hardware.wifi.V1_0.IWifiP2pIface.asInterface(_hidl_reply.readStrongBinder());
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_iface);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus removeP2pIface(String ifname)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);
            _hidl_request.writeString(ifname);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(21 /* removeP2pIface */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void createStaIface(createStaIfaceCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(22 /* createStaIface */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                android.hardware.wifi.V1_0.IWifiStaIface _hidl_out_iface = android.hardware.wifi.V1_0.IWifiStaIface.asInterface(_hidl_reply.readStrongBinder());
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_iface);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getStaIfaceNames(getStaIfaceNamesCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(23 /* getStaIfaceNames */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<String> _hidl_out_ifnames = _hidl_reply.readStringVector();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_ifnames);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getStaIface(String ifname, getStaIfaceCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);
            _hidl_request.writeString(ifname);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(24 /* getStaIface */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                android.hardware.wifi.V1_0.IWifiStaIface _hidl_out_iface = android.hardware.wifi.V1_0.IWifiStaIface.asInterface(_hidl_reply.readStrongBinder());
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_iface);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus removeStaIface(String ifname)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);
            _hidl_request.writeString(ifname);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(25 /* removeStaIface */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void createRttController(android.hardware.wifi.V1_0.IWifiIface boundIface, createRttControllerCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);
            _hidl_request.writeStrongBinder(boundIface == null ? null : boundIface.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(26 /* createRttController */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                android.hardware.wifi.V1_0.IWifiRttController _hidl_out_rtt = android.hardware.wifi.V1_0.IWifiRttController.asInterface(_hidl_reply.readStrongBinder());
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_rtt);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getDebugRingBuffersStatus(getDebugRingBuffersStatusCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(27 /* getDebugRingBuffersStatus */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<android.hardware.wifi.V1_0.WifiDebugRingBufferStatus> _hidl_out_ringBuffers = android.hardware.wifi.V1_0.WifiDebugRingBufferStatus.readVectorFromParcel(_hidl_reply);
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_ringBuffers);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus startLoggingToDebugRingBuffer(String ringName, int verboseLevel, int maxIntervalInSec, int minDataSizeInBytes)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);
            _hidl_request.writeString(ringName);
            _hidl_request.writeInt32(verboseLevel);
            _hidl_request.writeInt32(maxIntervalInSec);
            _hidl_request.writeInt32(minDataSizeInBytes);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(28 /* startLoggingToDebugRingBuffer */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus forceDumpToDebugRingBuffer(String ringName)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);
            _hidl_request.writeString(ringName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(29 /* forceDumpToDebugRingBuffer */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus stopLoggingToDebugRingBuffer()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(30 /* stopLoggingToDebugRingBuffer */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getDebugHostWakeReasonStats(getDebugHostWakeReasonStatsCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(31 /* getDebugHostWakeReasonStats */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                android.hardware.wifi.V1_0.WifiDebugHostWakeReasonStats _hidl_out_stats = new android.hardware.wifi.V1_0.WifiDebugHostWakeReasonStats();
                ((android.hardware.wifi.V1_0.WifiDebugHostWakeReasonStats) _hidl_out_stats).readFromParcel(_hidl_reply);
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_stats);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus enableDebugErrorAlerts(boolean enable)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);
            _hidl_request.writeBool(enable);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(32 /* enableDebugErrorAlerts */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::wifi::V1_1::IWifiChip follow.
        @Override
        public android.hardware.wifi.V1_0.WifiStatus selectTxPowerScenario(int scenario)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_1.IWifiChip.kInterfaceName);
            _hidl_request.writeInt32(scenario);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(33 /* selectTxPowerScenario */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus resetTxPowerScenario()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_1.IWifiChip.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(34 /* resetTxPowerScenario */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::wifi::V1_2::IWifiChip follow.
        @Override
        public android.hardware.wifi.V1_0.WifiStatus selectTxPowerScenario_1_2(int scenario)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_2.IWifiChip.kInterfaceName);
            _hidl_request.writeInt32(scenario);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(35 /* selectTxPowerScenario_1_2 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus registerEventCallback_1_2(android.hardware.wifi.V1_2.IWifiChipEventCallback callback)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_2.IWifiChip.kInterfaceName);
            _hidl_request.writeStrongBinder(callback == null ? null : callback.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(36 /* registerEventCallback_1_2 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::wifi::V1_3::IWifiChip follow.
        @Override
        public void getCapabilities_1_3(getCapabilities_1_3Callback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_3.IWifiChip.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(37 /* getCapabilities_1_3 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_capabilities = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_capabilities);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus setLatencyMode(int mode)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_3.IWifiChip.kInterfaceName);
            _hidl_request.writeInt32(mode);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(38 /* setLatencyMode */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus flushRingBufferToFile()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_3.IWifiChip.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(39 /* flushRingBufferToFile */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::wifi::V1_4::IWifiChip follow.
        @Override
        public android.hardware.wifi.V1_0.WifiStatus registerEventCallback_1_4(android.hardware.wifi.V1_4.IWifiChipEventCallback callback)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_4.IWifiChip.kInterfaceName);
            _hidl_request.writeStrongBinder(callback == null ? null : callback.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(40 /* registerEventCallback_1_4 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void createRttController_1_4(android.hardware.wifi.V1_0.IWifiIface boundIface, createRttController_1_4Callback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_4.IWifiChip.kInterfaceName);
            _hidl_request.writeStrongBinder(boundIface == null ? null : boundIface.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(41 /* createRttController_1_4 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                android.hardware.wifi.V1_4.IWifiRttController _hidl_out_rtt = android.hardware.wifi.V1_4.IWifiRttController.asInterface(_hidl_reply.readStrongBinder());
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_rtt);
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::wifi::V1_5::IWifiChip follow.
        @Override
        public void getCapabilities_1_5(getCapabilities_1_5Callback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_5.IWifiChip.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(42 /* getCapabilities_1_5 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_capabilities = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_capabilities);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus setMultiStaPrimaryConnection(String ifName)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_5.IWifiChip.kInterfaceName);
            _hidl_request.writeString(ifName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(43 /* setMultiStaPrimaryConnection */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus setMultiStaUseCase(byte useCase)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_5.IWifiChip.kInterfaceName);
            _hidl_request.writeInt8(useCase);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(44 /* setMultiStaUseCase */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void createBridgedApIface(createBridgedApIfaceCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_5.IWifiChip.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(45 /* createBridgedApIface */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                android.hardware.wifi.V1_5.IWifiApIface _hidl_out_iface = android.hardware.wifi.V1_5.IWifiApIface.asInterface(_hidl_reply.readStrongBinder());
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_iface);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus removeIfaceInstanceFromBridgedApIface(String brIfaceName, String ifaceInstanceName)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_5.IWifiChip.kInterfaceName);
            _hidl_request.writeString(brIfaceName);
            _hidl_request.writeString(ifaceInstanceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(46 /* removeIfaceInstanceFromBridgedApIface */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus setCoexUnsafeChannels(java.util.ArrayList<android.hardware.wifi.V1_5.IWifiChip.CoexUnsafeChannel> unsafeChannels, int restrictions)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_5.IWifiChip.kInterfaceName);
            android.hardware.wifi.V1_5.IWifiChip.CoexUnsafeChannel.writeVectorToParcel(_hidl_request, unsafeChannels);
            _hidl_request.writeInt32(restrictions);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(47 /* setCoexUnsafeChannels */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus setCountryCode(byte[/* 2 */] code)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_5.IWifiChip.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(2 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 2 */]) code;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 2) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 2 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(48 /* setCountryCode */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getUsableChannels(int band, int ifaceModeMask, int filterMask, getUsableChannelsCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_5.IWifiChip.kInterfaceName);
            _hidl_request.writeInt32(band);
            _hidl_request.writeInt32(ifaceModeMask);
            _hidl_request.writeInt32(filterMask);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(49 /* getUsableChannels */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<android.hardware.wifi.V1_5.WifiUsableChannel> _hidl_out_channels = android.hardware.wifi.V1_5.WifiUsableChannel.readVectorFromParcel(_hidl_reply);
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_channels);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.V1_0.WifiStatus triggerSubsystemRestart()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.V1_5.IWifiChip.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(50 /* triggerSubsystemRestart */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = new android.hardware.wifi.V1_0.WifiStatus();
                ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
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

    public static abstract class Stub extends android.os.HwBinder implements IWifiChip {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.wifi.V1_5.IWifiChip.kInterfaceName,
                    android.hardware.wifi.V1_4.IWifiChip.kInterfaceName,
                    android.hardware.wifi.V1_3.IWifiChip.kInterfaceName,
                    android.hardware.wifi.V1_2.IWifiChip.kInterfaceName,
                    android.hardware.wifi.V1_1.IWifiChip.kInterfaceName,
                    android.hardware.wifi.V1_0.IWifiChip.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.wifi.V1_5.IWifiChip.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{-95,25,61,55,-9,-31,50,34,-65,121,-17,75,115,-37,-83,21,-80,-16,-93,48,-48,51,86,-47,34,38,-36,-38,32,-34,68,-89} /* a1193d37f7e13222bf79ef4b73dbad15b0f0a330d03356d12226dcda20de44a7 */,
                    new byte[/* 32 */]{46,7,-104,58,112,-95,-71,99,-66,-24,-82,-50,5,14,94,-91,3,-93,-35,-29,30,33,-87,-8,53,44,-15,126,-111,19,-45,71} /* 2e07983a70a1b963bee8aece050e5ea503a3dde31e21a9f8352cf17e9113d347 */,
                    new byte[/* 32 */]{100,-66,8,75,110,30,-13,48,-73,95,-87,22,89,61,-64,-71,75,14,-57,-95,109,92,-6,-91,-93,30,108,-111,67,-56,40,-115} /* 64be084b6e1ef330b75fa916593dc0b94b0ec7a16d5cfaa5a31e6c9143c8288d */,
                    new byte[/* 32 */]{120,12,22,-3,-19,-95,59,119,-99,-103,57,83,-90,127,124,-91,120,-55,56,-95,114,-87,66,76,28,113,90,-24,27,-60,15,-41} /* 780c16fdeda13b779d993953a67f7ca578c938a172a9424c1c715ae81bc40fd7 */,
                    new byte[/* 32 */]{-80,86,-31,-34,-6,-76,7,21,-124,33,69,-124,5,125,11,-57,58,97,48,-127,-65,17,82,89,5,73,100,-99,69,-126,-63,60} /* b056e1defab4071584214584057d0bc73a613081bf1152590549649d4582c13c */,
                    new byte[/* 32 */]{-13,-18,-52,72,-99,-21,76,116,-119,47,89,-21,122,-37,118,-112,99,-67,92,53,74,-63,50,-74,38,-91,-12,43,54,61,54,-68} /* f3eecc489deb4c74892f59eb7adb769063bd5c354ac132b626a5f42b363d36bc */,
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
                case 1 /* getId */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    getId(new getIdCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, int id) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(id);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 2 /* registerEventCallback */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    android.hardware.wifi.V1_0.IWifiChipEventCallback callback = android.hardware.wifi.V1_0.IWifiChipEventCallback.asInterface(_hidl_request.readStrongBinder());
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = registerEventCallback(callback);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 3 /* getCapabilities */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    getCapabilities(new getCapabilitiesCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, int capabilities) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(capabilities);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 4 /* getAvailableModes */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    getAvailableModes(new getAvailableModesCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, java.util.ArrayList<android.hardware.wifi.V1_0.IWifiChip.ChipMode> modes) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            android.hardware.wifi.V1_0.IWifiChip.ChipMode.writeVectorToParcel(_hidl_reply, modes);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 5 /* configureChip */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    int modeId = _hidl_request.readInt32();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = configureChip(modeId);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 6 /* getMode */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    getMode(new getModeCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, int modeId) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(modeId);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 7 /* requestChipDebugInfo */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    requestChipDebugInfo(new requestChipDebugInfoCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, android.hardware.wifi.V1_0.IWifiChip.ChipDebugInfo chipDebugInfo) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            ((android.hardware.wifi.V1_0.IWifiChip.ChipDebugInfo) chipDebugInfo).writeToParcel(_hidl_reply);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 8 /* requestDriverDebugDump */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    requestDriverDebugDump(new requestDriverDebugDumpCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, java.util.ArrayList<Byte> blob) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt8Vector(blob);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 9 /* requestFirmwareDebugDump */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    requestFirmwareDebugDump(new requestFirmwareDebugDumpCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, java.util.ArrayList<Byte> blob) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt8Vector(blob);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 10 /* createApIface */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    createApIface(new createApIfaceCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, android.hardware.wifi.V1_0.IWifiApIface iface) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeStrongBinder(iface == null ? null : iface.asBinder());
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 11 /* getApIfaceNames */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    getApIfaceNames(new getApIfaceNamesCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, java.util.ArrayList<String> ifnames) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeStringVector(ifnames);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 12 /* getApIface */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    String ifname = _hidl_request.readString();
                    getApIface(ifname, new getApIfaceCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, android.hardware.wifi.V1_0.IWifiApIface iface) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeStrongBinder(iface == null ? null : iface.asBinder());
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 13 /* removeApIface */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    String ifname = _hidl_request.readString();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = removeApIface(ifname);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 14 /* createNanIface */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    createNanIface(new createNanIfaceCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, android.hardware.wifi.V1_0.IWifiNanIface iface) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeStrongBinder(iface == null ? null : iface.asBinder());
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 15 /* getNanIfaceNames */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    getNanIfaceNames(new getNanIfaceNamesCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, java.util.ArrayList<String> ifnames) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeStringVector(ifnames);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 16 /* getNanIface */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    String ifname = _hidl_request.readString();
                    getNanIface(ifname, new getNanIfaceCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, android.hardware.wifi.V1_0.IWifiNanIface iface) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeStrongBinder(iface == null ? null : iface.asBinder());
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 17 /* removeNanIface */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    String ifname = _hidl_request.readString();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = removeNanIface(ifname);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 18 /* createP2pIface */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    createP2pIface(new createP2pIfaceCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, android.hardware.wifi.V1_0.IWifiP2pIface iface) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeStrongBinder(iface == null ? null : iface.asBinder());
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 19 /* getP2pIfaceNames */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    getP2pIfaceNames(new getP2pIfaceNamesCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, java.util.ArrayList<String> ifnames) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeStringVector(ifnames);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 20 /* getP2pIface */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    String ifname = _hidl_request.readString();
                    getP2pIface(ifname, new getP2pIfaceCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, android.hardware.wifi.V1_0.IWifiP2pIface iface) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeStrongBinder(iface == null ? null : iface.asBinder());
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 21 /* removeP2pIface */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    String ifname = _hidl_request.readString();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = removeP2pIface(ifname);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 22 /* createStaIface */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    createStaIface(new createStaIfaceCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, android.hardware.wifi.V1_0.IWifiStaIface iface) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeStrongBinder(iface == null ? null : iface.asBinder());
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 23 /* getStaIfaceNames */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    getStaIfaceNames(new getStaIfaceNamesCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, java.util.ArrayList<String> ifnames) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeStringVector(ifnames);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 24 /* getStaIface */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    String ifname = _hidl_request.readString();
                    getStaIface(ifname, new getStaIfaceCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, android.hardware.wifi.V1_0.IWifiStaIface iface) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeStrongBinder(iface == null ? null : iface.asBinder());
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 25 /* removeStaIface */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    String ifname = _hidl_request.readString();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = removeStaIface(ifname);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 26 /* createRttController */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    android.hardware.wifi.V1_0.IWifiIface boundIface = android.hardware.wifi.V1_0.IWifiIface.asInterface(_hidl_request.readStrongBinder());
                    createRttController(boundIface, new createRttControllerCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, android.hardware.wifi.V1_0.IWifiRttController rtt) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeStrongBinder(rtt == null ? null : rtt.asBinder());
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 27 /* getDebugRingBuffersStatus */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    getDebugRingBuffersStatus(new getDebugRingBuffersStatusCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, java.util.ArrayList<android.hardware.wifi.V1_0.WifiDebugRingBufferStatus> ringBuffers) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            android.hardware.wifi.V1_0.WifiDebugRingBufferStatus.writeVectorToParcel(_hidl_reply, ringBuffers);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 28 /* startLoggingToDebugRingBuffer */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    String ringName = _hidl_request.readString();
                    int verboseLevel = _hidl_request.readInt32();
                    int maxIntervalInSec = _hidl_request.readInt32();
                    int minDataSizeInBytes = _hidl_request.readInt32();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = startLoggingToDebugRingBuffer(ringName, verboseLevel, maxIntervalInSec, minDataSizeInBytes);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 29 /* forceDumpToDebugRingBuffer */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    String ringName = _hidl_request.readString();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = forceDumpToDebugRingBuffer(ringName);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 30 /* stopLoggingToDebugRingBuffer */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = stopLoggingToDebugRingBuffer();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 31 /* getDebugHostWakeReasonStats */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    getDebugHostWakeReasonStats(new getDebugHostWakeReasonStatsCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, android.hardware.wifi.V1_0.WifiDebugHostWakeReasonStats stats) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            ((android.hardware.wifi.V1_0.WifiDebugHostWakeReasonStats) stats).writeToParcel(_hidl_reply);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 32 /* enableDebugErrorAlerts */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_0.IWifiChip.kInterfaceName);

                    boolean enable = _hidl_request.readBool();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = enableDebugErrorAlerts(enable);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 33 /* selectTxPowerScenario */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_1.IWifiChip.kInterfaceName);

                    int scenario = _hidl_request.readInt32();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = selectTxPowerScenario(scenario);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 34 /* resetTxPowerScenario */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_1.IWifiChip.kInterfaceName);

                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = resetTxPowerScenario();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 35 /* selectTxPowerScenario_1_2 */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_2.IWifiChip.kInterfaceName);

                    int scenario = _hidl_request.readInt32();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = selectTxPowerScenario_1_2(scenario);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 36 /* registerEventCallback_1_2 */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_2.IWifiChip.kInterfaceName);

                    android.hardware.wifi.V1_2.IWifiChipEventCallback callback = android.hardware.wifi.V1_2.IWifiChipEventCallback.asInterface(_hidl_request.readStrongBinder());
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = registerEventCallback_1_2(callback);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 37 /* getCapabilities_1_3 */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_3.IWifiChip.kInterfaceName);

                    getCapabilities_1_3(new getCapabilities_1_3Callback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, int capabilities) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(capabilities);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 38 /* setLatencyMode */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_3.IWifiChip.kInterfaceName);

                    int mode = _hidl_request.readInt32();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = setLatencyMode(mode);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 39 /* flushRingBufferToFile */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_3.IWifiChip.kInterfaceName);

                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = flushRingBufferToFile();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 40 /* registerEventCallback_1_4 */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_4.IWifiChip.kInterfaceName);

                    android.hardware.wifi.V1_4.IWifiChipEventCallback callback = android.hardware.wifi.V1_4.IWifiChipEventCallback.asInterface(_hidl_request.readStrongBinder());
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = registerEventCallback_1_4(callback);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 41 /* createRttController_1_4 */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_4.IWifiChip.kInterfaceName);

                    android.hardware.wifi.V1_0.IWifiIface boundIface = android.hardware.wifi.V1_0.IWifiIface.asInterface(_hidl_request.readStrongBinder());
                    createRttController_1_4(boundIface, new createRttController_1_4Callback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, android.hardware.wifi.V1_4.IWifiRttController rtt) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeStrongBinder(rtt == null ? null : rtt.asBinder());
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 42 /* getCapabilities_1_5 */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_5.IWifiChip.kInterfaceName);

                    getCapabilities_1_5(new getCapabilities_1_5Callback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, int capabilities) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(capabilities);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 43 /* setMultiStaPrimaryConnection */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_5.IWifiChip.kInterfaceName);

                    String ifName = _hidl_request.readString();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = setMultiStaPrimaryConnection(ifName);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 44 /* setMultiStaUseCase */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_5.IWifiChip.kInterfaceName);

                    byte useCase = _hidl_request.readInt8();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = setMultiStaUseCase(useCase);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 45 /* createBridgedApIface */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_5.IWifiChip.kInterfaceName);

                    createBridgedApIface(new createBridgedApIfaceCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, android.hardware.wifi.V1_5.IWifiApIface iface) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeStrongBinder(iface == null ? null : iface.asBinder());
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 46 /* removeIfaceInstanceFromBridgedApIface */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_5.IWifiChip.kInterfaceName);

                    String brIfaceName = _hidl_request.readString();
                    String ifaceInstanceName = _hidl_request.readString();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = removeIfaceInstanceFromBridgedApIface(brIfaceName, ifaceInstanceName);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 47 /* setCoexUnsafeChannels */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_5.IWifiChip.kInterfaceName);

                    java.util.ArrayList<android.hardware.wifi.V1_5.IWifiChip.CoexUnsafeChannel> unsafeChannels = android.hardware.wifi.V1_5.IWifiChip.CoexUnsafeChannel.readVectorFromParcel(_hidl_request);
                    int restrictions = _hidl_request.readInt32();
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = setCoexUnsafeChannels(unsafeChannels, restrictions);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 48 /* setCountryCode */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_5.IWifiChip.kInterfaceName);

                    byte[/* 2 */] code = new byte[2];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(2 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 2 */]) code, 2 /* size */);
                            _hidl_array_offset_0 += 2 * 1;
                        }
                    }
                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = setCountryCode(code);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 49 /* getUsableChannels */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_5.IWifiChip.kInterfaceName);

                    int band = _hidl_request.readInt32();
                    int ifaceModeMask = _hidl_request.readInt32();
                    int filterMask = _hidl_request.readInt32();
                    getUsableChannels(band, ifaceModeMask, filterMask, new getUsableChannelsCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.V1_0.WifiStatus status, java.util.ArrayList<android.hardware.wifi.V1_5.WifiUsableChannel> channels) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.V1_0.WifiStatus) status).writeToParcel(_hidl_reply);
                            android.hardware.wifi.V1_5.WifiUsableChannel.writeVectorToParcel(_hidl_reply, channels);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 50 /* triggerSubsystemRestart */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.V1_5.IWifiChip.kInterfaceName);

                    android.hardware.wifi.V1_0.WifiStatus _hidl_out_status = triggerSubsystemRestart();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.V1_0.WifiStatus) _hidl_out_status).writeToParcel(_hidl_reply);
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
