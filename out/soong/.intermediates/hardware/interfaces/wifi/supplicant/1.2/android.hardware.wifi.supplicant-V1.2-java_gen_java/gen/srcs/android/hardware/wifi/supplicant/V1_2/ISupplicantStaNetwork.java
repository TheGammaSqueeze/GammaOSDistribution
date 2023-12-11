package android.hardware.wifi.supplicant.V1_2;

/**
 * Interface exposed by the supplicant for each station mode network
 * configuration it controls.
 */
public interface ISupplicantStaNetwork extends android.hardware.wifi.supplicant.V1_1.ISupplicantStaNetwork {
    /**
     * Fully-qualified interface name for this interface.
     */
    public static final String kInterfaceName = "android.hardware.wifi.supplicant@1.2::ISupplicantStaNetwork";

    /**
     * Does a checked conversion from a binder to this class.
     */
    /* package private */ static ISupplicantStaNetwork asInterface(android.os.IHwBinder binder) {
        if (binder == null) {
            return null;
        }

        android.os.IHwInterface iface =
                binder.queryLocalInterface(kInterfaceName);

        if ((iface != null) && (iface instanceof ISupplicantStaNetwork)) {
            return (ISupplicantStaNetwork)iface;
        }

        ISupplicantStaNetwork proxy = new ISupplicantStaNetwork.Proxy(binder);

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
    public static ISupplicantStaNetwork castFrom(android.os.IHwInterface iface) {
        return (iface == null) ? null : ISupplicantStaNetwork.asInterface(iface.asBinder());
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
    public static ISupplicantStaNetwork getService(String serviceName, boolean retry) throws android.os.RemoteException {
        return ISupplicantStaNetwork.asInterface(android.os.HwBinder.getService("android.hardware.wifi.supplicant@1.2::ISupplicantStaNetwork", serviceName, retry));
    }

    /**
     * Calls getService("default",retry).
     */
    public static ISupplicantStaNetwork getService(boolean retry) throws android.os.RemoteException {
        return getService("default", retry);
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(String,boolean) instead.
     */
    @Deprecated
    public static ISupplicantStaNetwork getService(String serviceName) throws android.os.RemoteException {
        return ISupplicantStaNetwork.asInterface(android.os.HwBinder.getService("android.hardware.wifi.supplicant@1.2::ISupplicantStaNetwork", serviceName));
    }

    /**
     * @throws NoSuchElementException if this service is not available
     * @deprecated this will not wait for the interface to come up if it hasn't yet
     * started. See getService(boolean) instead.
     */
    @Deprecated
    public static ISupplicantStaNetwork getService() throws android.os.RemoteException {
        return getService("default");
    }

    /**
     * Possble mask of values for KeyMgmt param.
     */
    public static final class KeyMgmtMask {
        public static final int WPA_EAP = 1 /* 1 << 0 */;
        public static final int WPA_PSK = 2 /* 1 << 1 */;
        public static final int NONE = 4 /* 1 << 2 */;
        public static final int IEEE8021X = 8 /* 1 << 3 */;
        public static final int FT_EAP = 32 /* 1 << 5 */;
        public static final int FT_PSK = 64 /* 1 << 6 */;
        public static final int OSEN = 32768 /* 1 << 15 */;
        /**
         * WPA using EAP authentication with stronger SHA256-based algorithms
         */
        public static final int WPA_EAP_SHA256 = 128 /* 1 << 7 */;
        /**
         * WPA pre-shared key with stronger SHA256-based algorithms
         */
        public static final int WPA_PSK_SHA256 = 256 /* 1 << 8 */;
        /**
         * WPA3-Personal SAE Key management
         */
        public static final int SAE = 1024 /* 1 << 10 */;
        /**
         * WPA3-Enterprise Suite-B Key management
         */
        public static final int SUITE_B_192 = 131072 /* 1 << 17 */;
        /**
         * Enhacned Open (OWE) Key management
         */
        public static final int OWE = 4194304 /* 1 << 22 */;
        /**
         * Easy Connect (DPP) Key management
         */
        public static final int DPP = 8388608 /* 1 << 23 */;
        public static final String toString(int o) {
            if (o == WPA_EAP) {
                return "WPA_EAP";
            }
            if (o == WPA_PSK) {
                return "WPA_PSK";
            }
            if (o == NONE) {
                return "NONE";
            }
            if (o == IEEE8021X) {
                return "IEEE8021X";
            }
            if (o == FT_EAP) {
                return "FT_EAP";
            }
            if (o == FT_PSK) {
                return "FT_PSK";
            }
            if (o == OSEN) {
                return "OSEN";
            }
            if (o == WPA_EAP_SHA256) {
                return "WPA_EAP_SHA256";
            }
            if (o == WPA_PSK_SHA256) {
                return "WPA_PSK_SHA256";
            }
            if (o == SAE) {
                return "SAE";
            }
            if (o == SUITE_B_192) {
                return "SUITE_B_192";
            }
            if (o == OWE) {
                return "OWE";
            }
            if (o == DPP) {
                return "DPP";
            }
            return "0x" + Integer.toHexString(o);
        }

        public static final String dumpBitfield(int o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            int flipped = 0;
            if ((o & WPA_EAP) == WPA_EAP) {
                list.add("WPA_EAP");
                flipped |= WPA_EAP;
            }
            if ((o & WPA_PSK) == WPA_PSK) {
                list.add("WPA_PSK");
                flipped |= WPA_PSK;
            }
            if ((o & NONE) == NONE) {
                list.add("NONE");
                flipped |= NONE;
            }
            if ((o & IEEE8021X) == IEEE8021X) {
                list.add("IEEE8021X");
                flipped |= IEEE8021X;
            }
            if ((o & FT_EAP) == FT_EAP) {
                list.add("FT_EAP");
                flipped |= FT_EAP;
            }
            if ((o & FT_PSK) == FT_PSK) {
                list.add("FT_PSK");
                flipped |= FT_PSK;
            }
            if ((o & OSEN) == OSEN) {
                list.add("OSEN");
                flipped |= OSEN;
            }
            if ((o & WPA_EAP_SHA256) == WPA_EAP_SHA256) {
                list.add("WPA_EAP_SHA256");
                flipped |= WPA_EAP_SHA256;
            }
            if ((o & WPA_PSK_SHA256) == WPA_PSK_SHA256) {
                list.add("WPA_PSK_SHA256");
                flipped |= WPA_PSK_SHA256;
            }
            if ((o & SAE) == SAE) {
                list.add("SAE");
                flipped |= SAE;
            }
            if ((o & SUITE_B_192) == SUITE_B_192) {
                list.add("SUITE_B_192");
                flipped |= SUITE_B_192;
            }
            if ((o & OWE) == OWE) {
                list.add("OWE");
                flipped |= OWE;
            }
            if ((o & DPP) == DPP) {
                list.add("DPP");
                flipped |= DPP;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(o & (~flipped)));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Possble mask of values for PairwiseCipher param.
     */
    public static final class PairwiseCipherMask {
        public static final int NONE = 1 /* 1 << 0 */;
        public static final int TKIP = 8 /* 1 << 3 */;
        public static final int CCMP = 16 /* 1 << 4 */;
        /**
         * GCMP-256 Pairwise Cipher
         */
        public static final int GCMP_256 = 256 /* 1 << 8 */;
        public static final String toString(int o) {
            if (o == NONE) {
                return "NONE";
            }
            if (o == TKIP) {
                return "TKIP";
            }
            if (o == CCMP) {
                return "CCMP";
            }
            if (o == GCMP_256) {
                return "GCMP_256";
            }
            return "0x" + Integer.toHexString(o);
        }

        public static final String dumpBitfield(int o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            int flipped = 0;
            if ((o & NONE) == NONE) {
                list.add("NONE");
                flipped |= NONE;
            }
            if ((o & TKIP) == TKIP) {
                list.add("TKIP");
                flipped |= TKIP;
            }
            if ((o & CCMP) == CCMP) {
                list.add("CCMP");
                flipped |= CCMP;
            }
            if ((o & GCMP_256) == GCMP_256) {
                list.add("GCMP_256");
                flipped |= GCMP_256;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(o & (~flipped)));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Possble mask of values for GroupCipher param.
     */
    public static final class GroupCipherMask {
        public static final int WEP40 = 2 /* 1 << 1 */;
        public static final int WEP104 = 4 /* 1 << 2 */;
        public static final int TKIP = 8 /* 1 << 3 */;
        public static final int CCMP = 16 /* 1 << 4 */;
        public static final int GTK_NOT_USED = 16384 /* 1 << 14 */;
        /**
         * GCMP-256 Group Cipher
         */
        public static final int GCMP_256 = 256 /* 1 << 8 */;
        public static final String toString(int o) {
            if (o == WEP40) {
                return "WEP40";
            }
            if (o == WEP104) {
                return "WEP104";
            }
            if (o == TKIP) {
                return "TKIP";
            }
            if (o == CCMP) {
                return "CCMP";
            }
            if (o == GTK_NOT_USED) {
                return "GTK_NOT_USED";
            }
            if (o == GCMP_256) {
                return "GCMP_256";
            }
            return "0x" + Integer.toHexString(o);
        }

        public static final String dumpBitfield(int o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            int flipped = 0;
            if ((o & WEP40) == WEP40) {
                list.add("WEP40");
                flipped |= WEP40;
            }
            if ((o & WEP104) == WEP104) {
                list.add("WEP104");
                flipped |= WEP104;
            }
            if ((o & TKIP) == TKIP) {
                list.add("TKIP");
                flipped |= TKIP;
            }
            if ((o & CCMP) == CCMP) {
                list.add("CCMP");
                flipped |= CCMP;
            }
            if ((o & GTK_NOT_USED) == GTK_NOT_USED) {
                list.add("GTK_NOT_USED");
                flipped |= GTK_NOT_USED;
            }
            if ((o & GCMP_256) == GCMP_256) {
                list.add("GCMP_256");
                flipped |= GCMP_256;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(o & (~flipped)));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Possble mask of values for GroupMgmtCipher param.
     */
    public static final class GroupMgmtCipherMask {
        /**
         * BIP_GMAC-128 Group Management Cipher
         */
        public static final int BIP_GMAC_128 = 2048 /* 1 << 11 */;
        /**
         * BIP_GMAC-256 Group Management Cipher
         */
        public static final int BIP_GMAC_256 = 4096 /* 1 << 12 */;
        /**
         * BIP_CMAC-256 Group Management Cipher
         */
        public static final int BIP_CMAC_256 = 8192 /* 1 << 13 */;
        public static final String toString(int o) {
            if (o == BIP_GMAC_128) {
                return "BIP_GMAC_128";
            }
            if (o == BIP_GMAC_256) {
                return "BIP_GMAC_256";
            }
            if (o == BIP_CMAC_256) {
                return "BIP_CMAC_256";
            }
            return "0x" + Integer.toHexString(o);
        }

        public static final String dumpBitfield(int o) {
            java.util.ArrayList<String> list = new java.util.ArrayList<>();
            int flipped = 0;
            if ((o & BIP_GMAC_128) == BIP_GMAC_128) {
                list.add("BIP_GMAC_128");
                flipped |= BIP_GMAC_128;
            }
            if ((o & BIP_GMAC_256) == BIP_GMAC_256) {
                list.add("BIP_GMAC_256");
                flipped |= BIP_GMAC_256;
            }
            if ((o & BIP_CMAC_256) == BIP_CMAC_256) {
                list.add("BIP_CMAC_256");
                flipped |= BIP_CMAC_256;
            }
            if (o != flipped) {
                list.add("0x" + Integer.toHexString(o & (~flipped)));
            }
            return String.join(" | ", list);
        }

    };

    /**
     * Set key management mask for the network.
     *
     * @param keyMgmtMask value to set.
     *        Combination of |KeyMgmtMask| values.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_ARGS_INVALID|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_NETWORK_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus setKeyMgmt_1_2(int keyMgmtMask)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface getKeyMgmt_1_2Callback {
        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, int keyMgmtMask);
    }

    /**
     * Get the key mgmt mask set for the network.
     *
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_NETWORK_INVALID|
     * @return keyMgmtMask Combination of |KeyMgmtMask| values.
     */
    void getKeyMgmt_1_2(getKeyMgmt_1_2Callback _hidl_cb)
        throws android.os.RemoteException;
    /**
     * Set pairwise cipher mask for the network.
     *
     * @param pairwiseCipherMask value to set.
     *        Combination of |PairwiseCipherMask| values.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_ARGS_INVALID|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_NETWORK_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus setPairwiseCipher_1_2(int pairwiseCipherMask)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface getPairwiseCipher_1_2Callback {
        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, int pairwiseCipherMask);
    }

    /**
     * Get the pairwise cipher mask set for the network.
     *
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_NETWORK_INVALID|
     * @return pairwiseCipherMask Combination of |PairwiseCipherMask| values.
     */
    void getPairwiseCipher_1_2(getPairwiseCipher_1_2Callback _hidl_cb)
        throws android.os.RemoteException;
    /**
     * Set group cipher mask for the network.
     *
     * @param groupCipherMask value to set.
     *        Combination of |GroupCipherMask| values.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_ARGS_INVALID|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_NETWORK_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus setGroupCipher_1_2(int groupCipherMask)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface getGroupCipher_1_2Callback {
        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, int groupCipherMask);
    }

    /**
     * Get the group cipher mask set for the network.
     *
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_NETWORK_INVALID|
     * @return groupCipherMask Combination of |GroupCipherMask| values.
     */
    void getGroupCipher_1_2(getGroupCipher_1_2Callback _hidl_cb)
        throws android.os.RemoteException;
    /**
     * Set group management cipher mask for the network.
     *
     * @param groupMgmtCipherMask value to set.
     *        Combination of |GroupMgmtCipherMask| values.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_ARGS_INVALID|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_NETWORK_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus setGroupMgmtCipher(int groupMgmtCipherMask)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface getGroupMgmtCipherCallback {
        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, int groupMgmtCipherMask);
    }

    /**
     * Get the group management cipher mask set for the network.
     *
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_NETWORK_INVALID|
     * @return groupMgmtCipherMask Combination of |GroupMgmtCipherMask| values.
     */
    void getGroupMgmtCipher(getGroupMgmtCipherCallback _hidl_cb)
        throws android.os.RemoteException;
    /**
     * Enable TLS Suite-B in EAP Phase1
     *
     * @param enable Set to true to enable TLS Suite-B in EAP phase1
     *
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_ARGS_INVALID|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_NETWORK_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus enableTlsSuiteBEapPhase1Param(boolean enable)
        throws android.os.RemoteException;
    /**
     * Set EAP OpenSSL Suite-B-192 ciphers for WPA3-Enterprise
     *        Supported option:
     *
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_ARGS_INVALID|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_NETWORK_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus enableSuiteBEapOpenSslCiphers()
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface getSaePasswordCallback {
        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, String saePassword);
    }

    /**
     * Get SAE password for WPA3-Personal
     *
     * @return status Status of the operation, and a string.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_ARGS_INVALID|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_NETWORK_INVALID|
     */
    void getSaePassword(getSaePasswordCallback _hidl_cb)
        throws android.os.RemoteException;

    @java.lang.FunctionalInterface
    public interface getSaePasswordIdCallback {
        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, String saePasswordId);
    }

    /**
     * Get SAE password ID for WPA3-Personal
     *
     * @return status Status of the operation, and a string.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_ARGS_INVALID|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_NETWORK_INVALID|
     */
    void getSaePasswordId(getSaePasswordIdCallback _hidl_cb)
        throws android.os.RemoteException;
    /**
     * Set SAE password for WPA3-Personal
     *
     * @param saePassword string with the above option
     *
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_ARGS_INVALID|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_NETWORK_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus setSaePassword(String saePassword)
        throws android.os.RemoteException;
    /**
     * Set SAE password ID for WPA3-Personal
     *
     * @param sae_password_id string with the above option
     *
     * @return status Status of the operation.
     *         Possible status codes:
     *         |SupplicantStatusCode.SUCCESS|,
     *         |SupplicantStatusCode.FAILURE_ARGS_INVALID|,
     *         |SupplicantStatusCode.FAILURE_UNKNOWN|,
     *         |SupplicantStatusCode.FAILURE_NETWORK_INVALID|
     */
    android.hardware.wifi.supplicant.V1_0.SupplicantStatus setSaePasswordId(String saePasswordId)
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

    public static final class Proxy implements ISupplicantStaNetwork {
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
            return "[class or subclass of " + ISupplicantStaNetwork.kInterfaceName + "]@Proxy";
        }

        @Override
        public final boolean equals(java.lang.Object other) {
            return android.os.HidlSupport.interfacesEqual(this, other);
        }

        @Override
        public final int hashCode() {
            return this.asBinder().hashCode();
        }

        // Methods from ::android::hardware::wifi::supplicant::V1_0::ISupplicantNetwork follow.
        @Override
        public void getId(getIdCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(1 /* getId */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_id = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_id);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getInterfaceName(getInterfaceNameCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(2 /* getInterfaceName */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                String _hidl_out_name = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_name);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getType(getTypeCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(3 /* getType */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_type = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_type);
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetwork follow.
        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus registerCallback(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetworkCallback callback)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeStrongBinder(callback == null ? null : callback.asBinder());

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(4 /* registerCallback */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setSsid(java.util.ArrayList<Byte> ssid)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeInt8Vector(ssid);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(5 /* setSsid */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setBssid(byte[/* 6 */] bssid)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
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
                mRemote.transact(6 /* setBssid */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setScanSsid(boolean enable)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeBool(enable);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(7 /* setScanSsid */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setKeyMgmt(int keyMgmtMask)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeInt32(keyMgmtMask);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(8 /* setKeyMgmt */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setProto(int protoMask)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeInt32(protoMask);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(9 /* setProto */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setAuthAlg(int authAlgMask)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeInt32(authAlgMask);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(10 /* setAuthAlg */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setGroupCipher(int groupCipherMask)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeInt32(groupCipherMask);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(11 /* setGroupCipher */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setPairwiseCipher(int pairwiseCipherMask)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeInt32(pairwiseCipherMask);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(12 /* setPairwiseCipher */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setPskPassphrase(String psk)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeString(psk);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(13 /* setPskPassphrase */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setPsk(byte[/* 32 */] psk)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
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

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(14 /* setPsk */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setWepKey(int keyIdx, java.util.ArrayList<Byte> wepKey)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeInt32(keyIdx);
            _hidl_request.writeInt8Vector(wepKey);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(15 /* setWepKey */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setWepTxKeyIdx(int keyIdx)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeInt32(keyIdx);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(16 /* setWepTxKeyIdx */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setRequirePmf(boolean enable)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeBool(enable);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(17 /* setRequirePmf */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setEapMethod(int method)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeInt32(method);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(18 /* setEapMethod */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setEapPhase2Method(int method)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeInt32(method);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(19 /* setEapPhase2Method */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setEapIdentity(java.util.ArrayList<Byte> identity)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeInt8Vector(identity);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(20 /* setEapIdentity */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setEapAnonymousIdentity(java.util.ArrayList<Byte> identity)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeInt8Vector(identity);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(21 /* setEapAnonymousIdentity */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setEapPassword(java.util.ArrayList<Byte> password)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeInt8Vector(password);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(22 /* setEapPassword */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setEapCACert(String path)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeString(path);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(23 /* setEapCACert */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setEapCAPath(String path)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeString(path);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(24 /* setEapCAPath */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setEapClientCert(String path)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeString(path);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(25 /* setEapClientCert */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setEapPrivateKeyId(String id)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeString(id);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(26 /* setEapPrivateKeyId */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setEapSubjectMatch(String match)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeString(match);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(27 /* setEapSubjectMatch */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setEapAltSubjectMatch(String match)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeString(match);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(28 /* setEapAltSubjectMatch */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setEapEngine(boolean enable)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeBool(enable);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(29 /* setEapEngine */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setEapEngineID(String id)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeString(id);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(30 /* setEapEngineID */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setEapDomainSuffixMatch(String match)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeString(match);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(31 /* setEapDomainSuffixMatch */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setProactiveKeyCaching(boolean enable)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeBool(enable);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(32 /* setProactiveKeyCaching */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setIdStr(String idStr)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeString(idStr);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(33 /* setIdStr */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setUpdateIdentifier(int id)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeInt32(id);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(34 /* setUpdateIdentifier */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getSsid(getSsidCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(35 /* getSsid */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<Byte> _hidl_out_ssid = _hidl_reply.readInt8Vector();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_ssid);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getBssid(getBssidCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(36 /* getBssid */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                byte[/* 6 */] _hidl_out_bssid = new byte[6];
                {
                    android.os.HwBlob _hidl_blob = _hidl_reply.readBuffer(6 /* size */);
                    {
                        long _hidl_array_offset_0 = 0 /* offset */;
                        _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) _hidl_out_bssid, 6 /* size */);
                        _hidl_array_offset_0 += 6 * 1;
                    }
                }
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_bssid);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getScanSsid(getScanSsidCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(37 /* getScanSsid */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                boolean _hidl_out_enabled = _hidl_reply.readBool();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_enabled);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getKeyMgmt(getKeyMgmtCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(38 /* getKeyMgmt */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_keyMgmtMask = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_keyMgmtMask);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getProto(getProtoCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(39 /* getProto */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_protoMask = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_protoMask);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getAuthAlg(getAuthAlgCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(40 /* getAuthAlg */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_authAlgMask = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_authAlgMask);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getGroupCipher(getGroupCipherCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(41 /* getGroupCipher */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_groupCipherMask = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_groupCipherMask);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getPairwiseCipher(getPairwiseCipherCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(42 /* getPairwiseCipher */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_pairwiseCipherMask = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_pairwiseCipherMask);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getPskPassphrase(getPskPassphraseCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(43 /* getPskPassphrase */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                String _hidl_out_psk = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_psk);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getPsk(getPskCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(44 /* getPsk */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                byte[/* 32 */] _hidl_out_psk = new byte[32];
                {
                    android.os.HwBlob _hidl_blob = _hidl_reply.readBuffer(32 /* size */);
                    {
                        long _hidl_array_offset_0 = 0 /* offset */;
                        _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 32 */]) _hidl_out_psk, 32 /* size */);
                        _hidl_array_offset_0 += 32 * 1;
                    }
                }
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_psk);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getWepKey(int keyIdx, getWepKeyCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeInt32(keyIdx);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(45 /* getWepKey */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<Byte> _hidl_out_wepKey = _hidl_reply.readInt8Vector();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_wepKey);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getWepTxKeyIdx(getWepTxKeyIdxCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(46 /* getWepTxKeyIdx */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_keyIdx = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_keyIdx);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getRequirePmf(getRequirePmfCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(47 /* getRequirePmf */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                boolean _hidl_out_enabled = _hidl_reply.readBool();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_enabled);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getEapMethod(getEapMethodCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(48 /* getEapMethod */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_method = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_method);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getEapPhase2Method(getEapPhase2MethodCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(49 /* getEapPhase2Method */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_method = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_method);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getEapIdentity(getEapIdentityCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(50 /* getEapIdentity */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<Byte> _hidl_out_identity = _hidl_reply.readInt8Vector();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_identity);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getEapAnonymousIdentity(getEapAnonymousIdentityCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(51 /* getEapAnonymousIdentity */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<Byte> _hidl_out_identity = _hidl_reply.readInt8Vector();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_identity);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getEapPassword(getEapPasswordCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(52 /* getEapPassword */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<Byte> _hidl_out_password = _hidl_reply.readInt8Vector();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_password);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getEapCACert(getEapCACertCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(53 /* getEapCACert */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                String _hidl_out_path = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_path);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getEapCAPath(getEapCAPathCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(54 /* getEapCAPath */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                String _hidl_out_path = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_path);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getEapClientCert(getEapClientCertCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(55 /* getEapClientCert */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                String _hidl_out_path = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_path);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getEapPrivateKeyId(getEapPrivateKeyIdCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(56 /* getEapPrivateKeyId */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                String _hidl_out_id = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_id);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getEapSubjectMatch(getEapSubjectMatchCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(57 /* getEapSubjectMatch */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                String _hidl_out_match = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_match);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getEapAltSubjectMatch(getEapAltSubjectMatchCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(58 /* getEapAltSubjectMatch */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                String _hidl_out_match = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_match);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getEapEngine(getEapEngineCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(59 /* getEapEngine */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                boolean _hidl_out_enabled = _hidl_reply.readBool();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_enabled);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getEapEngineID(getEapEngineIDCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(60 /* getEapEngineID */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                String _hidl_out_id = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_id);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getEapDomainSuffixMatch(getEapDomainSuffixMatchCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(61 /* getEapDomainSuffixMatch */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                String _hidl_out_match = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_match);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getIdStr(getIdStrCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(62 /* getIdStr */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                String _hidl_out_idStr = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_idStr);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getWpsNfcConfigurationToken(getWpsNfcConfigurationTokenCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(63 /* getWpsNfcConfigurationToken */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                java.util.ArrayList<Byte> _hidl_out_token = _hidl_reply.readInt8Vector();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_token);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus enable(boolean noConnect)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeBool(noConnect);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(64 /* enable */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus disable()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(65 /* disable */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus select()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(66 /* select */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus sendNetworkEapSimGsmAuthResponse(java.util.ArrayList<android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.NetworkResponseEapSimGsmAuthParams> params)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.NetworkResponseEapSimGsmAuthParams.writeVectorToParcel(_hidl_request, params);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(67 /* sendNetworkEapSimGsmAuthResponse */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus sendNetworkEapSimGsmAuthFailure()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(68 /* sendNetworkEapSimGsmAuthFailure */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus sendNetworkEapSimUmtsAuthResponse(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.NetworkResponseEapSimUmtsAuthParams params)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            ((android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.NetworkResponseEapSimUmtsAuthParams) params).writeToParcel(_hidl_request);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(69 /* sendNetworkEapSimUmtsAuthResponse */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus sendNetworkEapSimUmtsAutsResponse(byte[/* 14 */] auts)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            {
                android.os.HwBlob _hidl_blob = new android.os.HwBlob(14 /* size */);
                {
                    long _hidl_array_offset_0 = 0 /* offset */;
                    byte[] _hidl_array_item_0 = (byte[/* 14 */]) auts;

                    if (_hidl_array_item_0 == null || _hidl_array_item_0.length != 14) {
                        throw new IllegalArgumentException("Array element is not of the expected length");
                    }

                    _hidl_blob.putInt8Array(_hidl_array_offset_0, _hidl_array_item_0);
                    _hidl_array_offset_0 += 14 * 1;
                }
                _hidl_request.writeBuffer(_hidl_blob);
            }

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(70 /* sendNetworkEapSimUmtsAutsResponse */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus sendNetworkEapSimUmtsAuthFailure()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(71 /* sendNetworkEapSimUmtsAuthFailure */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus sendNetworkEapIdentityResponse(java.util.ArrayList<Byte> identity)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeInt8Vector(identity);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(72 /* sendNetworkEapIdentityResponse */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaNetwork follow.
        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setEapEncryptedImsiIdentity(java.util.ArrayList<Byte> identity)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_1.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeInt8Vector(identity);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(73 /* setEapEncryptedImsiIdentity */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus sendNetworkEapIdentityResponse_1_1(java.util.ArrayList<Byte> identity, java.util.ArrayList<Byte> encryptedIdentity)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_1.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeInt8Vector(identity);
            _hidl_request.writeInt8Vector(encryptedIdentity);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(74 /* sendNetworkEapIdentityResponse_1_1 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        // Methods from ::android::hardware::wifi::supplicant::V1_2::ISupplicantStaNetwork follow.
        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setKeyMgmt_1_2(int keyMgmtMask)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeInt32(keyMgmtMask);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(75 /* setKeyMgmt_1_2 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getKeyMgmt_1_2(getKeyMgmt_1_2Callback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(76 /* getKeyMgmt_1_2 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_keyMgmtMask = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_keyMgmtMask);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setPairwiseCipher_1_2(int pairwiseCipherMask)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeInt32(pairwiseCipherMask);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(77 /* setPairwiseCipher_1_2 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getPairwiseCipher_1_2(getPairwiseCipher_1_2Callback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(78 /* getPairwiseCipher_1_2 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_pairwiseCipherMask = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_pairwiseCipherMask);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setGroupCipher_1_2(int groupCipherMask)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeInt32(groupCipherMask);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(79 /* setGroupCipher_1_2 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getGroupCipher_1_2(getGroupCipher_1_2Callback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(80 /* getGroupCipher_1_2 */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_groupCipherMask = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_groupCipherMask);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setGroupMgmtCipher(int groupMgmtCipherMask)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeInt32(groupMgmtCipherMask);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(81 /* setGroupMgmtCipher */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getGroupMgmtCipher(getGroupMgmtCipherCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(82 /* getGroupMgmtCipher */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                int _hidl_out_groupMgmtCipherMask = _hidl_reply.readInt32();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_groupMgmtCipherMask);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus enableTlsSuiteBEapPhase1Param(boolean enable)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeBool(enable);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(83 /* enableTlsSuiteBEapPhase1Param */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus enableSuiteBEapOpenSslCiphers()
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(84 /* enableSuiteBEapOpenSslCiphers */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getSaePassword(getSaePasswordCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(85 /* getSaePassword */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                String _hidl_out_saePassword = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_saePassword);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public void getSaePasswordId(getSaePasswordIdCallback _hidl_cb)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(86 /* getSaePasswordId */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                String _hidl_out_saePasswordId = _hidl_reply.readString();
                _hidl_cb.onValues(_hidl_out_status, _hidl_out_saePasswordId);
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setSaePassword(String saePassword)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeString(saePassword);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(87 /* setSaePassword */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
                return _hidl_out_status;
            } finally {
                _hidl_reply.release();
            }
        }

        @Override
        public android.hardware.wifi.supplicant.V1_0.SupplicantStatus setSaePasswordId(String saePasswordId)
                throws android.os.RemoteException {
            android.os.HwParcel _hidl_request = new android.os.HwParcel();
            _hidl_request.writeInterfaceToken(android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName);
            _hidl_request.writeString(saePasswordId);

            android.os.HwParcel _hidl_reply = new android.os.HwParcel();
            try {
                mRemote.transact(88 /* setSaePasswordId */, _hidl_request, _hidl_reply, 0 /* flags */);
                _hidl_reply.verifySuccess();
                _hidl_request.releaseTemporaryStorage();

                android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = new android.hardware.wifi.supplicant.V1_0.SupplicantStatus();
                ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).readFromParcel(_hidl_reply);
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

    public static abstract class Stub extends android.os.HwBinder implements ISupplicantStaNetwork {
        @Override
        public android.os.IHwBinder asBinder() {
            return this;
        }

        @Override
        public final java.util.ArrayList<String> interfaceChain() {
            return new java.util.ArrayList<String>(java.util.Arrays.asList(
                    android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName,
                    android.hardware.wifi.supplicant.V1_1.ISupplicantStaNetwork.kInterfaceName,
                    android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName,
                    android.hardware.wifi.supplicant.V1_0.ISupplicantNetwork.kInterfaceName,
                    android.hidl.base.V1_0.IBase.kInterfaceName));

        }

        @Override
        public void debug(android.os.NativeHandle fd, java.util.ArrayList<String> options) {
            return;

        }

        @Override
        public final String interfaceDescriptor() {
            return android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName;

        }

        @Override
        public final java.util.ArrayList<byte[/* 32 */]> getHashChain() {
            return new java.util.ArrayList<byte[/* 32 */]>(java.util.Arrays.asList(
                    new byte[/* 32 */]{-17,-69,6,28,-106,-97,-87,85,61,36,61,-90,-18,35,-72,63,-27,-44,-86,102,58,123,-120,-106,-83,-59,46,43,1,91,-62,-13} /* efbb061c969fa9553d243da6ee23b83fe5d4aa663a7b8896adc52e2b015bc2f3 */,
                    new byte[/* 32 */]{16,-1,47,-82,81,99,70,-72,97,33,54,-116,-27,121,13,90,-52,-33,-53,115,-104,50,70,-72,19,-13,-44,-120,-74,109,-76,90} /* 10ff2fae516346b86121368ce5790d5accdfcb73983246b813f3d488b66db45a */,
                    new byte[/* 32 */]{-79,46,-16,-67,-40,-92,-46,71,-88,-90,-23,96,-78,39,-19,50,56,63,43,2,65,-11,93,103,-4,-22,110,-1,106,103,55,-6} /* b12ef0bdd8a4d247a8a6e960b227ed32383f2b0241f55d67fcea6eff6a6737fa */,
                    new byte[/* 32 */]{-51,-96,16,8,-64,105,34,-6,55,-63,33,62,-101,-72,49,-95,9,-77,23,69,50,-128,86,22,-5,113,97,-19,-60,3,-122,111} /* cda01008c06922fa37c1213e9bb831a109b3174532805616fb7161edc403866f */,
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
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantNetwork.kInterfaceName);

                    getId(new getIdCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, int id) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(id);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 2 /* getInterfaceName */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantNetwork.kInterfaceName);

                    getInterfaceName(new getInterfaceNameCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, String name) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeString(name);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 3 /* getType */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantNetwork.kInterfaceName);

                    getType(new getTypeCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, int type) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(type);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 4 /* registerCallback */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetworkCallback callback = android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetworkCallback.asInterface(_hidl_request.readStrongBinder());
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = registerCallback(callback);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 5 /* setSsid */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    java.util.ArrayList<Byte> ssid = _hidl_request.readInt8Vector();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setSsid(ssid);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 6 /* setBssid */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    byte[/* 6 */] bssid = new byte[6];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(6 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 6 */]) bssid, 6 /* size */);
                            _hidl_array_offset_0 += 6 * 1;
                        }
                    }
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setBssid(bssid);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 7 /* setScanSsid */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    boolean enable = _hidl_request.readBool();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setScanSsid(enable);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 8 /* setKeyMgmt */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    int keyMgmtMask = _hidl_request.readInt32();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setKeyMgmt(keyMgmtMask);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 9 /* setProto */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    int protoMask = _hidl_request.readInt32();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setProto(protoMask);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 10 /* setAuthAlg */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    int authAlgMask = _hidl_request.readInt32();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setAuthAlg(authAlgMask);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 11 /* setGroupCipher */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    int groupCipherMask = _hidl_request.readInt32();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setGroupCipher(groupCipherMask);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 12 /* setPairwiseCipher */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    int pairwiseCipherMask = _hidl_request.readInt32();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setPairwiseCipher(pairwiseCipherMask);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 13 /* setPskPassphrase */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    String psk = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setPskPassphrase(psk);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 14 /* setPsk */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    byte[/* 32 */] psk = new byte[32];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(32 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 32 */]) psk, 32 /* size */);
                            _hidl_array_offset_0 += 32 * 1;
                        }
                    }
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setPsk(psk);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 15 /* setWepKey */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    int keyIdx = _hidl_request.readInt32();
                    java.util.ArrayList<Byte> wepKey = _hidl_request.readInt8Vector();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setWepKey(keyIdx, wepKey);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 16 /* setWepTxKeyIdx */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    int keyIdx = _hidl_request.readInt32();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setWepTxKeyIdx(keyIdx);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 17 /* setRequirePmf */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    boolean enable = _hidl_request.readBool();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setRequirePmf(enable);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 18 /* setEapMethod */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    int method = _hidl_request.readInt32();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setEapMethod(method);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 19 /* setEapPhase2Method */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    int method = _hidl_request.readInt32();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setEapPhase2Method(method);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 20 /* setEapIdentity */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    java.util.ArrayList<Byte> identity = _hidl_request.readInt8Vector();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setEapIdentity(identity);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 21 /* setEapAnonymousIdentity */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    java.util.ArrayList<Byte> identity = _hidl_request.readInt8Vector();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setEapAnonymousIdentity(identity);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 22 /* setEapPassword */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    java.util.ArrayList<Byte> password = _hidl_request.readInt8Vector();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setEapPassword(password);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 23 /* setEapCACert */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    String path = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setEapCACert(path);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 24 /* setEapCAPath */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    String path = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setEapCAPath(path);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 25 /* setEapClientCert */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    String path = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setEapClientCert(path);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 26 /* setEapPrivateKeyId */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    String id = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setEapPrivateKeyId(id);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 27 /* setEapSubjectMatch */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    String match = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setEapSubjectMatch(match);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 28 /* setEapAltSubjectMatch */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    String match = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setEapAltSubjectMatch(match);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 29 /* setEapEngine */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    boolean enable = _hidl_request.readBool();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setEapEngine(enable);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 30 /* setEapEngineID */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    String id = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setEapEngineID(id);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 31 /* setEapDomainSuffixMatch */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    String match = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setEapDomainSuffixMatch(match);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 32 /* setProactiveKeyCaching */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    boolean enable = _hidl_request.readBool();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setProactiveKeyCaching(enable);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 33 /* setIdStr */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    String idStr = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setIdStr(idStr);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 34 /* setUpdateIdentifier */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    int id = _hidl_request.readInt32();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setUpdateIdentifier(id);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 35 /* getSsid */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    getSsid(new getSsidCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, java.util.ArrayList<Byte> ssid) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt8Vector(ssid);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 36 /* getBssid */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    getBssid(new getBssidCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, byte[/* 6 */] bssid) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
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
                                _hidl_reply.writeBuffer(_hidl_blob);
                            }
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 37 /* getScanSsid */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    getScanSsid(new getScanSsidCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, boolean enabled) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeBool(enabled);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 38 /* getKeyMgmt */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    getKeyMgmt(new getKeyMgmtCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, int keyMgmtMask) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(keyMgmtMask);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 39 /* getProto */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    getProto(new getProtoCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, int protoMask) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(protoMask);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 40 /* getAuthAlg */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    getAuthAlg(new getAuthAlgCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, int authAlgMask) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(authAlgMask);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 41 /* getGroupCipher */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    getGroupCipher(new getGroupCipherCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, int groupCipherMask) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(groupCipherMask);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 42 /* getPairwiseCipher */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    getPairwiseCipher(new getPairwiseCipherCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, int pairwiseCipherMask) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(pairwiseCipherMask);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 43 /* getPskPassphrase */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    getPskPassphrase(new getPskPassphraseCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, String psk) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeString(psk);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 44 /* getPsk */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    getPsk(new getPskCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, byte[/* 32 */] psk) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
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
                                _hidl_reply.writeBuffer(_hidl_blob);
                            }
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 45 /* getWepKey */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    int keyIdx = _hidl_request.readInt32();
                    getWepKey(keyIdx, new getWepKeyCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, java.util.ArrayList<Byte> wepKey) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt8Vector(wepKey);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 46 /* getWepTxKeyIdx */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    getWepTxKeyIdx(new getWepTxKeyIdxCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, int keyIdx) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(keyIdx);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 47 /* getRequirePmf */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    getRequirePmf(new getRequirePmfCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, boolean enabled) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeBool(enabled);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 48 /* getEapMethod */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    getEapMethod(new getEapMethodCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, int method) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(method);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 49 /* getEapPhase2Method */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    getEapPhase2Method(new getEapPhase2MethodCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, int method) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(method);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 50 /* getEapIdentity */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    getEapIdentity(new getEapIdentityCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, java.util.ArrayList<Byte> identity) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt8Vector(identity);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 51 /* getEapAnonymousIdentity */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    getEapAnonymousIdentity(new getEapAnonymousIdentityCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, java.util.ArrayList<Byte> identity) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt8Vector(identity);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 52 /* getEapPassword */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    getEapPassword(new getEapPasswordCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, java.util.ArrayList<Byte> password) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt8Vector(password);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 53 /* getEapCACert */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    getEapCACert(new getEapCACertCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, String path) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeString(path);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 54 /* getEapCAPath */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    getEapCAPath(new getEapCAPathCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, String path) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeString(path);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 55 /* getEapClientCert */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    getEapClientCert(new getEapClientCertCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, String path) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeString(path);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 56 /* getEapPrivateKeyId */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    getEapPrivateKeyId(new getEapPrivateKeyIdCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, String id) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeString(id);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 57 /* getEapSubjectMatch */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    getEapSubjectMatch(new getEapSubjectMatchCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, String match) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeString(match);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 58 /* getEapAltSubjectMatch */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    getEapAltSubjectMatch(new getEapAltSubjectMatchCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, String match) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeString(match);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 59 /* getEapEngine */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    getEapEngine(new getEapEngineCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, boolean enabled) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeBool(enabled);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 60 /* getEapEngineID */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    getEapEngineID(new getEapEngineIDCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, String id) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeString(id);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 61 /* getEapDomainSuffixMatch */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    getEapDomainSuffixMatch(new getEapDomainSuffixMatchCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, String match) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeString(match);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 62 /* getIdStr */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    getIdStr(new getIdStrCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, String idStr) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeString(idStr);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 63 /* getWpsNfcConfigurationToken */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    getWpsNfcConfigurationToken(new getWpsNfcConfigurationTokenCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, java.util.ArrayList<Byte> token) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt8Vector(token);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 64 /* enable */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    boolean noConnect = _hidl_request.readBool();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = enable(noConnect);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 65 /* disable */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = disable();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 66 /* select */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = select();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 67 /* sendNetworkEapSimGsmAuthResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    java.util.ArrayList<android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.NetworkResponseEapSimGsmAuthParams> params = android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.NetworkResponseEapSimGsmAuthParams.readVectorFromParcel(_hidl_request);
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = sendNetworkEapSimGsmAuthResponse(params);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 68 /* sendNetworkEapSimGsmAuthFailure */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = sendNetworkEapSimGsmAuthFailure();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 69 /* sendNetworkEapSimUmtsAuthResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.NetworkResponseEapSimUmtsAuthParams params = new android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.NetworkResponseEapSimUmtsAuthParams();
                    ((android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.NetworkResponseEapSimUmtsAuthParams) params).readFromParcel(_hidl_request);
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = sendNetworkEapSimUmtsAuthResponse(params);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 70 /* sendNetworkEapSimUmtsAutsResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    byte[/* 14 */] auts = new byte[14];
                    {
                        android.os.HwBlob _hidl_blob = _hidl_request.readBuffer(14 /* size */);
                        {
                            long _hidl_array_offset_0 = 0 /* offset */;
                            _hidl_blob.copyToInt8Array(_hidl_array_offset_0, (byte[/* 14 */]) auts, 14 /* size */);
                            _hidl_array_offset_0 += 14 * 1;
                        }
                    }
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = sendNetworkEapSimUmtsAutsResponse(auts);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 71 /* sendNetworkEapSimUmtsAuthFailure */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = sendNetworkEapSimUmtsAuthFailure();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 72 /* sendNetworkEapIdentityResponse */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_0.ISupplicantStaNetwork.kInterfaceName);

                    java.util.ArrayList<Byte> identity = _hidl_request.readInt8Vector();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = sendNetworkEapIdentityResponse(identity);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 73 /* setEapEncryptedImsiIdentity */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_1.ISupplicantStaNetwork.kInterfaceName);

                    java.util.ArrayList<Byte> identity = _hidl_request.readInt8Vector();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setEapEncryptedImsiIdentity(identity);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 74 /* sendNetworkEapIdentityResponse_1_1 */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_1.ISupplicantStaNetwork.kInterfaceName);

                    java.util.ArrayList<Byte> identity = _hidl_request.readInt8Vector();
                    java.util.ArrayList<Byte> encryptedIdentity = _hidl_request.readInt8Vector();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = sendNetworkEapIdentityResponse_1_1(identity, encryptedIdentity);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 75 /* setKeyMgmt_1_2 */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName);

                    int keyMgmtMask = _hidl_request.readInt32();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setKeyMgmt_1_2(keyMgmtMask);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 76 /* getKeyMgmt_1_2 */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName);

                    getKeyMgmt_1_2(new getKeyMgmt_1_2Callback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, int keyMgmtMask) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(keyMgmtMask);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 77 /* setPairwiseCipher_1_2 */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName);

                    int pairwiseCipherMask = _hidl_request.readInt32();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setPairwiseCipher_1_2(pairwiseCipherMask);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 78 /* getPairwiseCipher_1_2 */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName);

                    getPairwiseCipher_1_2(new getPairwiseCipher_1_2Callback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, int pairwiseCipherMask) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(pairwiseCipherMask);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 79 /* setGroupCipher_1_2 */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName);

                    int groupCipherMask = _hidl_request.readInt32();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setGroupCipher_1_2(groupCipherMask);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 80 /* getGroupCipher_1_2 */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName);

                    getGroupCipher_1_2(new getGroupCipher_1_2Callback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, int groupCipherMask) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(groupCipherMask);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 81 /* setGroupMgmtCipher */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName);

                    int groupMgmtCipherMask = _hidl_request.readInt32();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setGroupMgmtCipher(groupMgmtCipherMask);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 82 /* getGroupMgmtCipher */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName);

                    getGroupMgmtCipher(new getGroupMgmtCipherCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, int groupMgmtCipherMask) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeInt32(groupMgmtCipherMask);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 83 /* enableTlsSuiteBEapPhase1Param */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName);

                    boolean enable = _hidl_request.readBool();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = enableTlsSuiteBEapPhase1Param(enable);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 84 /* enableSuiteBEapOpenSslCiphers */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName);

                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = enableSuiteBEapOpenSslCiphers();
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 85 /* getSaePassword */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName);

                    getSaePassword(new getSaePasswordCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, String saePassword) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeString(saePassword);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 86 /* getSaePasswordId */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName);

                    getSaePasswordId(new getSaePasswordIdCallback() {
                        @Override
                        public void onValues(android.hardware.wifi.supplicant.V1_0.SupplicantStatus status, String saePasswordId) {
                            _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                            ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) status).writeToParcel(_hidl_reply);
                            _hidl_reply.writeString(saePasswordId);
                            _hidl_reply.send();
                            }});
                    break;
                }

                case 87 /* setSaePassword */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName);

                    String saePassword = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setSaePassword(saePassword);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
                    _hidl_reply.send();
                    break;
                }

                case 88 /* setSaePasswordId */:
                {
                    _hidl_request.enforceInterface(android.hardware.wifi.supplicant.V1_2.ISupplicantStaNetwork.kInterfaceName);

                    String saePasswordId = _hidl_request.readString();
                    android.hardware.wifi.supplicant.V1_0.SupplicantStatus _hidl_out_status = setSaePasswordId(saePasswordId);
                    _hidl_reply.writeStatus(android.os.HwParcel.STATUS_SUCCESS);
                    ((android.hardware.wifi.supplicant.V1_0.SupplicantStatus) _hidl_out_status).writeToParcel(_hidl_reply);
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
