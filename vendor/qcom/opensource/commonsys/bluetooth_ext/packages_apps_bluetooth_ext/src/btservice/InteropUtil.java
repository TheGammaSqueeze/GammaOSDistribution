/******************************************************************************
 *  Copyright (c) 2020, The Linux Foundation. All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are
 *  met:
 *      * Redistributions of source code must retain the above copyright
 *        notice, this list of conditions and the following disclaimer.
 *      * Redistributions in binary form must reproduce the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer in the documentation and/or other materials provided
 *        with the distribution.
 *      * Neither the name of The Linux Foundation nor the names of its
 *        contributors may be used to endorse or promote products derived
 *        from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 *  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 *  ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 *  BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 *  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 *  OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 *  IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*****************************************************************************/

package com.android.bluetooth.btservice;

import android.util.Log;

/**
 * APIs of interoperability workaround utilities.
 * These APIs will call stack layer's interop APIs of interop.cc to do matching
 * or entry adding/removing.
 */
public class InteropUtil {
    private static final String TAG = "InteropUtil";

    /**
     * Add interop feature from device/include/interop.h to below InteropFeature if
     * this feature needs to be matched at java layer. Feature's name will be passed to
     * stack layer to do matching, so make sure that the added feature's name is exactly
     * same as that in device/include/interop.h.
     */
    public static enum InteropFeature {
        INTEROP_NOT_UPDATE_AVRCP_PAUSED_TO_REMOTE,
        INTEROP_PHONE_POLICY_INCREASED_DELAY_CONNECT_OTHER_PROFILES,
        INTEROP_PHONE_POLICY_REDUCED_DELAY_CONNECT_OTHER_PROFILES,
        INTEROP_HFP_FAKE_INCOMING_CALL_INDICATOR,
        INTEROP_HFP_SEND_CALL_INDICATORS_BACK_TO_BACK,
        INTEROP_SETUP_SCO_WITH_NO_DELAY_AFTER_SLC_DURING_CALL,
        INTEROP_RETRY_SCO_AFTER_REMOTE_REJECT_SCO;
    }

    /**
     * Check if a given address matches a known interoperability workaround
     * identified by the interop feature.
     *
     * @param feature a given interop feature defined in {@link InteropFeature}.
     * @param address a given address to be matched.
     * @return true if matched, false otherwise.
     */
    public static boolean interopMatchAddr(InteropFeature feature, String address) {
        AdapterService adapterService = AdapterService.getAdapterService();
        if (adapterService == null || !adapterService.isVendorIntfEnabled()) {
            Log.d(TAG, "interopMatchAddr: feature=" + feature.name() +
                    ", adapterService is null or vendor intf is not enabled");
            return false;
        }

        Log.d(TAG, "interopMatchAddr: feature=" + feature.name() + ", address=" + address);
        if (address == null) {
            return false;
        }

        boolean matched = Vendor.interopMatchAddr(feature, address);
        Log.d(TAG, "interopMatchAddr: matched=" + matched);
        return matched;
    }

    /**
     * Check if a given name matches a known interoperability workaround
     * identified by the interop feature.
     *
     * @param feature a given interop feature defined in {@link InteropFeature}.
     * @param name a given name to be matched.
     * @return true if matched, false otherwise.
     */
    public static boolean interopMatchName(InteropFeature feature, String name) {
        AdapterService adapterService = AdapterService.getAdapterService();
        if (adapterService == null || !adapterService.isVendorIntfEnabled()) {
            Log.d(TAG, "interopMatchName: feature=" + feature.name() +
                    ", adapterService is null or vendor intf is not enabled");
            return false;
        }

        Log.d(TAG, "interopMatchName: feature=" + feature.name() + ", name=" + name);
        if (name == null) {
            return false;
        }

        boolean matched = Vendor.interopMatchName(feature, name);
        Log.d(TAG, "interopMatchName: matched=" + matched);
        return matched;
    }

    /**
     * Check if a given address or remote device name matches a known interoperability workaround
     * identified by the interop feature. remote device name will be fetched internally based on
     * the given address at stack layer.
     *
     * @param feature a given interop feature defined in {@link InteropFeature}.
     * @param address a given address to be matched.
     * @return true if matched, false otherwise
     */
    public static boolean interopMatchAddrOrName(InteropFeature feature, String address) {
        AdapterService adapterService = AdapterService.getAdapterService();
        if (adapterService == null || !adapterService.isVendorIntfEnabled()) {
            Log.d(TAG, "interopMatchAddrOrName: feature=" + feature.name() +
                    ", adapterService is null or vendor intf is not enabled");
            return false;
        }

        Log.d(TAG, "interopMatchAddrOrName: feature=" + feature.name() + ", address=" + address);
        if (address == null) {
            return false;
        }

        boolean matched = Vendor.interopMatchAddrOrName(feature, address);
        Log.d(TAG, "interopMatchAddrOrName: matched=" + matched);
        return matched;
    }

    /**
     * Add a dynamic address interop database entry identified by the interop feature
     * for a device matching the first length bytes of addr.
     *
     * @param feature a given interop feature defined in {@link InteropFeature}.
     * @param address a given address to be added.
     * @param length the number of bytes of address to be stored,
     * length must be in [1,6], and usually it is 3.
     */
    public static void interopDatabaseAddAddr(InteropFeature feature,
            String address, int length) {
        AdapterService adapterService = AdapterService.getAdapterService();
        if (adapterService == null || !adapterService.isVendorIntfEnabled()) {
            Log.d(TAG, "interopDatabaseAddAddr: feature=" + feature.name() +
                    ", adapterService is null or vendor intf is not enabled");
            return;
        }

        Log.d(TAG, "interopDatabaseAddAddr: feature=" + feature.name() +
                ", address=" + address + ", length=" + length);
        if (address == null || (length <= 0 || length > 6)) {
            return;
        }

        Vendor.interopDatabaseAddAddr(feature, address, length);
    }

    /**
     * Remove a dynamic address interop database entry identified by the interop feature
     * for a device matching the addr.
     *
     * @param feature a given interop feature defined in {@link InteropFeature}.
     * @param address a given address to be removed.
     */
    public static void interopDatabaseRemoveAddr(InteropFeature feature, String address) {
        AdapterService adapterService = AdapterService.getAdapterService();
        if (adapterService == null || !adapterService.isVendorIntfEnabled()) {
            Log.d(TAG, "interopDatabaseRemoveAddr: feature=" + feature.name() +
                    ", adapterService is null or vendor intf is not enabled");
            return;
        }

        Log.d(TAG, "interopDatabaseRemoveAddr: feature=" + feature.name() + ", address=" + address);
        if (address == null) {
            return;
        }

        Vendor.interopDatabaseRemoveAddr(feature, address);
    }

    /**
     * Add a dynamic name interop database entry identified by the interop feature for the name.
     *
     * @param feature a given interop feature defined in {@link InteropFeature}.
     * @param name a given name to be added.
     */
    public static void interopDatabaseAddName(InteropFeature feature, String name) {
        AdapterService adapterService = AdapterService.getAdapterService();
        if (adapterService == null || !adapterService.isVendorIntfEnabled()) {
            Log.d(TAG, "interopDatabaseAddName: feature=" + feature.name() +
                    ", adapterService is null or vendor intf is not enabled");
            return;
        }

        Log.d(TAG, "interopDatabaseAddName: feature=" + feature.name() + ", name=" + name);
        if (name == null) {
            return;
        }

        Vendor.interopDatabaseAddName(feature, name);
    }

    /**
     * Remove a dynamic name interop database entry identified by the interop feature for the name.
     *
     * @param feature a given interop feature defined in {@link InteropFeature}.
     * @param name a given name to be removed.
     */
    public static void interopDatabaseRemoveName(InteropFeature feature, String name) {
        AdapterService adapterService = AdapterService.getAdapterService();
        if (adapterService == null || !adapterService.isVendorIntfEnabled()) {
            Log.d(TAG, "interopDatabaseRemoveName: feature=" + feature.name() +
                    ", adapterService is null or vendor intf is not enabled");
            return;
        }

        Log.d(TAG, "interopDatabaseRemoveName: feature=" + feature.name() + ", name=" + name);
        if (name == null) {
            return;
        }

        Vendor.interopDatabaseRemoveName(feature, name);
    }

}
