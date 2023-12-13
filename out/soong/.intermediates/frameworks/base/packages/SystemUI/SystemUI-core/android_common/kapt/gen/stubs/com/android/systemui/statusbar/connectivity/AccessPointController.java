package com.android.systemui.statusbar.connectivity;

import android.content.Intent;
import android.os.UserManager;
import android.provider.Settings;
import com.android.wifitrackerlib.MergedCarrierEntry;
import com.android.wifitrackerlib.WifiEntry;

/**
 * Tracks changes in access points.  Allows listening for changes, scanning for new APs,
 * and connecting to new ones.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00002\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\bf\u0018\u00002\u00020\u0001:\u0001\u0012J\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&J\b\u0010\u0006\u001a\u00020\u0007H&J\b\u0010\b\u001a\u00020\u0007H&J\u0012\u0010\t\u001a\u00020\u00072\b\u0010\n\u001a\u0004\u0018\u00010\u000bH&J\u0010\u0010\f\u001a\u00020\r2\u0006\u0010\n\u001a\u00020\u000bH&J\n\u0010\u000e\u001a\u0004\u0018\u00010\u000fH&J\u0010\u0010\u0010\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&J\b\u0010\u0011\u001a\u00020\u0003H&"}, d2 = {"Lcom/android/systemui/statusbar/connectivity/AccessPointController;", "", "addAccessPointCallback", "", "callback", "Lcom/android/systemui/statusbar/connectivity/AccessPointController$AccessPointCallback;", "canConfigMobileData", "", "canConfigWifi", "connect", "ap", "Lcom/android/wifitrackerlib/WifiEntry;", "getIcon", "", "getMergedCarrierEntry", "Lcom/android/wifitrackerlib/MergedCarrierEntry;", "removeAccessPointCallback", "scanForAccessPoints", "AccessPointCallback"})
public abstract interface AccessPointController {
    
    public abstract void addAccessPointCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.connectivity.AccessPointController.AccessPointCallback callback);
    
    public abstract void removeAccessPointCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.connectivity.AccessPointController.AccessPointCallback callback);
    
    /**
     * Request an updated list of available access points
     *
     * This method will trigger a call to [AccessPointCallback.onAccessPointsChanged]
     */
    public abstract void scanForAccessPoints();
    
    /**
     * Gets the current [MergedCarrierEntry]. If null, this call generates a call to
     * [AccessPointCallback.onAccessPointsChanged]
     *
     * @return the current [MergedCarrierEntry], if one exists
     */
    @org.jetbrains.annotations.Nullable()
    public abstract com.android.wifitrackerlib.MergedCarrierEntry getMergedCarrierEntry();
    
    /**
     * @return the appropriate icon id for the given [WifiEntry]'s level
     */
    public abstract int getIcon(@org.jetbrains.annotations.NotNull()
    com.android.wifitrackerlib.WifiEntry ap);
    
    /**
     * Connects to a [WifiEntry] if it's saved or does not require security.
     *
     * If the entry is not saved and requires security, will trigger
     * [AccessPointCallback.onSettingsActivityTriggered].
     *
     * @param ap
     * @return `true` if [AccessPointCallback.onSettingsActivityTriggered] is triggered
     */
    public abstract boolean connect(@org.jetbrains.annotations.Nullable()
    com.android.wifitrackerlib.WifiEntry ap);
    
    /**
     * `true` if the current user does not have the [UserManager.DISALLOW_CONFIG_WIFI] restriction
     */
    public abstract boolean canConfigWifi();
    
    /**
     * `true` if the current user does not have the [UserManager.DISALLOW_CONFIG_MOBILE_NETWORKS]
     * restriction set
     */
    public abstract boolean canConfigMobileData();
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\bf\u0018\u00002\u00020\u0001J\u001b\u0010\u0002\u001a\u00020\u00032\u0011\u0010\u0004\u001a\r\u0012\t\u0012\u00070\u0006\u00a2\u0006\u0002\b\u00070\u0005H&J\u0012\u0010\b\u001a\u00020\u00032\b\u0010\t\u001a\u0004\u0018\u00010\nH&"}, d2 = {"Lcom/android/systemui/statusbar/connectivity/AccessPointController$AccessPointCallback;", "", "onAccessPointsChanged", "", "accessPoints", "", "Lcom/android/wifitrackerlib/WifiEntry;", "Lkotlin/jvm/JvmSuppressWildcards;", "onSettingsActivityTriggered", "settingsIntent", "Landroid/content/Intent;"})
    public static abstract interface AccessPointCallback {
        
        /**
         * Called whenever [scanForAccessPoints] is called, or [getMergedCarrierEntry] is called
         * with a null entry
         *
         * @param accessPoints the list of available access points, including the current connected
         * one if it exists
         */
        public abstract void onAccessPointsChanged(@org.jetbrains.annotations.NotNull()
        java.util.List<com.android.wifitrackerlib.WifiEntry> accessPoints);
        
        /**
         * Called whenever [connecting][connect] to an unknown access point which has security.
         * Implementers should launch the intent in the appropriate context
         *
         * @param settingsIntent an intent for [Settings.ACTION_WIFI_SETTINGS] with
         * "wifi_start_connect_ssid" set as an extra
         */
        public abstract void onSettingsActivityTriggered(@org.jetbrains.annotations.Nullable()
        android.content.Intent settingsIntent);
    }
}