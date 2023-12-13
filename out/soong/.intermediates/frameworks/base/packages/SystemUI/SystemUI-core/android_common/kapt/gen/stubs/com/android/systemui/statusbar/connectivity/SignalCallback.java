package com.android.systemui.statusbar.connectivity;

import android.telephony.SubscriptionInfo;

/**
 * SignalCallback contains all of the connectivity updates from [NetworkController]. Implement this
 * interface to be able to draw iconography for Wi-Fi, mobile data, ethernet, call strength
 * indicators, etc.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000B\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\t\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\bf\u0018\u00002\u00020\u0001J\u0018\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\u0006\u0010\u0006\u001a\u00020\u0007H\u0017J \u0010\b\u001a\u00020\u00032\u0006\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\n2\u0006\u0010\f\u001a\u00020\nH\u0017J\u0010\u0010\r\u001a\u00020\u00032\u0006\u0010\u000e\u001a\u00020\u0005H\u0017J\u0010\u0010\u000f\u001a\u00020\u00032\u0006\u0010\u000e\u001a\u00020\u0005H\u0017J\u0010\u0010\u0010\u001a\u00020\u00032\u0006\u0010\u0011\u001a\u00020\nH\u0017J\u0010\u0010\u0012\u001a\u00020\u00032\u0006\u0010\u0013\u001a\u00020\u0014H\u0017J\u0018\u0010\u0015\u001a\u00020\u00032\u0006\u0010\u0016\u001a\u00020\n2\u0006\u0010\u0017\u001a\u00020\nH\u0017J\u001b\u0010\u0018\u001a\u00020\u00032\u0011\u0010\u0019\u001a\r\u0012\t\u0012\u00070\u001b\u00a2\u0006\u0002\b\u001c0\u001aH\u0017J\u0010\u0010\u001d\u001a\u00020\u00032\u0006\u0010\u001e\u001a\u00020\u001fH\u0017\u00f8\u0001\u0000\u0082\u0002\u0007\n\u0005\b\u0091(0\u0001"}, d2 = {"Lcom/android/systemui/statusbar/connectivity/SignalCallback;", "", "setCallIndicator", "", "statusIcon", "Lcom/android/systemui/statusbar/connectivity/IconState;", "subId", "", "setConnectivityStatus", "noDefaultNetwork", "", "noValidatedNetwork", "noNetworksAvailable", "setEthernetIndicators", "icon", "setIsAirplaneMode", "setMobileDataEnabled", "enabled", "setMobileDataIndicators", "mobileDataIndicators", "Lcom/android/systemui/statusbar/connectivity/MobileDataIndicators;", "setNoSims", "show", "simDetected", "setSubs", "subs", "", "Landroid/telephony/SubscriptionInfo;", "Lkotlin/jvm/JvmSuppressWildcards;", "setWifiIndicators", "wifiIndicators", "Lcom/android/systemui/statusbar/connectivity/WifiIndicators;"})
public abstract interface SignalCallback {
    
    /**
     * Called when the Wi-Fi iconography has been updated. Implement this method to draw Wi-Fi icons
     *
     * @param wifiIndicators a box type containing enough information to properly draw a Wi-Fi icon
     */
    public default void setWifiIndicators(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.connectivity.WifiIndicators wifiIndicators) {
    }
    
    /**
     * Called when the mobile iconography has been updated. Implement this method to draw mobile
     * indicators
     *
     * @param mobileDataIndicators a box type containing enough information to properly draw
     * mobile data icons
     *
     * NOTE: phones can have multiple subscriptions, so this [mobileDataIndicators] object should be
     * indexed based on its [subId][MobileDataIndicators.subId]
     */
    public default void setMobileDataIndicators(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.connectivity.MobileDataIndicators mobileDataIndicators) {
    }
    
    /**
     * Called when the list of mobile data subscriptions has changed. Use this method as a chance
     * to remove views that are no longer needed, or to make room for new icons to come in
     *
     * @param subs a [SubscriptionInfo] for each subscription that we know about
     */
    public default void setSubs(@org.jetbrains.annotations.NotNull()
    java.util.List<android.telephony.SubscriptionInfo> subs) {
    }
    
    /**
     * Called when:
     * 1. The number of [MobileSignalController]s goes to 0 while mobile data is enabled
     * OR
     * 2. The presence of any SIM changes
     *
     * @param show whether or not to show a "no sim" view
     * @param simDetected whether any SIM is detected or not
     */
    public default void setNoSims(boolean show, boolean simDetected) {
    }
    
    /**
     * Called when there is any update to the ethernet iconography. Implement this method to set an
     * ethernet icon
     *
     * @param icon an [IconState] for the current ethernet status
     */
    public default void setEthernetIndicators(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.connectivity.IconState icon) {
    }
    
    /**
     * Called whenever airplane mode changes
     *
     * @param icon an [IconState] for the current airplane mode status
     */
    public default void setIsAirplaneMode(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.connectivity.IconState icon) {
    }
    
    /**
     * Called whenever the mobile data feature enabled state changes
     *
     * @param enabled the current mobile data feature ennabled state
     */
    public default void setMobileDataEnabled(boolean enabled) {
    }
    
    /**
     * Callback for listeners to be able to update the connectivity status
     * @param noDefaultNetwork whether there is any default network.
     * @param noValidatedNetwork whether there is any validated network.
     * @param noNetworksAvailable whether there is any WiFi networks available.
     */
    public default void setConnectivityStatus(boolean noDefaultNetwork, boolean noValidatedNetwork, boolean noNetworksAvailable) {
    }
    
    /**
     * Callback for listeners to be able to update the call indicator
     * @param statusIcon the icon for the call indicator
     * @param subId subscription ID for which to update the UI
     */
    public default void setCallIndicator(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.connectivity.IconState statusIcon, int subId) {
    }
}