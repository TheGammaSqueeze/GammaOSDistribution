package com.android.systemui.statusbar.connectivity;

import android.telephony.ServiceState;
import android.telephony.SignalStrength;
import android.telephony.TelephonyDisplayInfo;
import android.telephony.TelephonyManager;
import com.android.settingslib.Utils;
import com.android.settingslib.mobile.MobileStatusTracker.MobileStatus;
import com.android.settingslib.mobile.TelephonyIcons;
import java.lang.IllegalArgumentException;

/**
 * Box for all policy-related state used in [MobileSignalController]
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000T\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\b\n\u0002\u0010\b\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0010\u0000\n\u0002\b\r\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\u0018\u0002\b\u0000\u0018\u00002\u00020\u0001B\u0081\u0001\u0012\n\b\u0002\u0010\u0002\u001a\u0004\u0018\u00010\u0003\u0012\n\b\u0002\u0010\u0004\u001a\u0004\u0018\u00010\u0003\u0012\b\b\u0002\u0010\u0005\u001a\u00020\u0006\u0012\b\b\u0002\u0010\u0007\u001a\u00020\u0006\u0012\b\b\u0002\u0010\b\u001a\u00020\u0006\u0012\b\b\u0002\u0010\t\u001a\u00020\u0006\u0012\b\b\u0002\u0010\n\u001a\u00020\u0006\u0012\b\b\u0002\u0010\u000b\u001a\u00020\u0006\u0012\b\b\u0002\u0010\f\u001a\u00020\u0006\u0012\b\b\u0002\u0010\r\u001a\u00020\u0006\u0012\b\b\u0002\u0010\u000e\u001a\u00020\u000f\u0012\b\b\u0002\u0010\u0010\u001a\u00020\u0006\u00a2\u0006\u0002\u0010\u0011J\u0010\u0010\u001a\u001a\u00020\u001b2\u0006\u0010\u001c\u001a\u00020\u0001H\u0014J\u0013\u0010\u001d\u001a\u00020\u00062\b\u0010\u001c\u001a\u0004\u0018\u00010\u001eH\u0096\u0002J\u0006\u0010\u001f\u001a\u00020\u0003J\u0006\u0010 \u001a\u00020\u000fJ\u0006\u0010!\u001a\u00020\u0006J\u0006\u0010\"\u001a\u00020\u0006J\b\u0010#\u001a\u00020\u000fH\u0016J\u0006\u0010$\u001a\u00020\u0006J\u0006\u0010%\u001a\u00020\u0006J\u0006\u0010&\u001a\u00020\u0006J\u0006\u0010\'\u001a\u00020\u0006J\u0006\u0010(\u001a\u00020\u0006J\u0006\u0010)\u001a\u00020\u0006J\u000e\u0010*\u001a\u00020\u001b2\u0006\u0010+\u001a\u00020,J\u0006\u0010-\u001a\u00020\u0006J\u0014\u0010.\u001a\u00020\u001b2\n\u0010/\u001a\u000600j\u0002`1H\u0014R\u0012\u0010\t\u001a\u00020\u00068\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010\n\u001a\u00020\u00068\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010\u0007\u001a\u00020\u00068\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010\u0005\u001a\u00020\u00068\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010\u000e\u001a\u00020\u000f8\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010\u0010\u001a\u00020\u00068\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0011\u0010\u0012\u001a\u00020\u00068F\u00a2\u0006\u0006\u001a\u0004\b\u0012\u0010\u0013R\u0012\u0010\u000b\u001a\u00020\u00068\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010\b\u001a\u00020\u00068\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0002\u001a\u0004\u0018\u00010\u00038\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0004\u001a\u0004\u0018\u00010\u00038\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010\r\u001a\u00020\u00068\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0014\u001a\u0004\u0018\u00010\u00158\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0016\u001a\u0004\u0018\u00010\u00178\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010\u0018\u001a\u00020\u00198\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010\f\u001a\u00020\u00068\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/connectivity/MobileState;", "Lcom/android/systemui/statusbar/connectivity/ConnectivityState;", "networkName", "", "networkNameData", "dataSim", "", "dataConnected", "isEmergency", "airplaneMode", "carrierNetworkChangeMode", "isDefault", "userSetup", "roaming", "dataState", "", "defaultDataOff", "(Ljava/lang/String;Ljava/lang/String;ZZZZZZZZIZ)V", "isDataDisabledOrNotDefault", "()Z", "serviceState", "Landroid/telephony/ServiceState;", "signalStrength", "Landroid/telephony/SignalStrength;", "telephonyDisplayInfo", "Landroid/telephony/TelephonyDisplayInfo;", "copyFrom", "", "other", "equals", "", "getOperatorAlphaShort", "getVoiceServiceState", "hasActivityIn", "hasActivityOut", "hashCode", "isCdma", "isDataConnected", "isEmergencyOnly", "isInService", "isNoCalling", "isRoaming", "setFromMobileStatus", "mobileStatus", "Lcom/android/settingslib/mobile/MobileStatusTracker$MobileStatus;", "showQuickSettingsRatIcon", "toString", "builder", "Ljava/lang/StringBuilder;", "Lkotlin/text/StringBuilder;"})
public final class MobileState extends com.android.systemui.statusbar.connectivity.ConnectivityState {
    @org.jetbrains.annotations.NotNull()
    public android.telephony.TelephonyDisplayInfo telephonyDisplayInfo;
    @org.jetbrains.annotations.Nullable()
    public android.telephony.ServiceState serviceState;
    @org.jetbrains.annotations.Nullable()
    public android.telephony.SignalStrength signalStrength;
    @org.jetbrains.annotations.Nullable()
    public java.lang.String networkName;
    @org.jetbrains.annotations.Nullable()
    public java.lang.String networkNameData;
    public boolean dataSim;
    public boolean dataConnected;
    public boolean isEmergency;
    public boolean airplaneMode;
    public boolean carrierNetworkChangeMode;
    public boolean isDefault;
    public boolean userSetup;
    public boolean roaming;
    public int dataState;
    public boolean defaultDataOff;
    
    public final boolean isDataDisabledOrNotDefault() {
        return false;
    }
    
    /**
     * @return if this state is considered to have inbound activity
     */
    public final boolean hasActivityIn() {
        return false;
    }
    
    /**
     * @return if this state is considered to have outbound activity
     */
    public final boolean hasActivityOut() {
        return false;
    }
    
    /**
     * @return true if this state should show a RAT icon in quick settings
     */
    public final boolean showQuickSettingsRatIcon() {
        return false;
    }
    
    @java.lang.Override()
    protected void copyFrom(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.connectivity.ConnectivityState other) {
    }
    
    public final boolean isDataConnected() {
        return false;
    }
    
    /**
     * @return the current voice service state, or -1 if null
     */
    public final int getVoiceServiceState() {
        return 0;
    }
    
    public final boolean isNoCalling() {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getOperatorAlphaShort() {
        return null;
    }
    
    public final boolean isCdma() {
        return false;
    }
    
    public final boolean isEmergencyOnly() {
        return false;
    }
    
    public final boolean isInService() {
        return false;
    }
    
    public final boolean isRoaming() {
        return false;
    }
    
    public final void setFromMobileStatus(@org.jetbrains.annotations.NotNull()
    com.android.settingslib.mobile.MobileStatusTracker.MobileStatus mobileStatus) {
    }
    
    @java.lang.Override()
    protected void toString(@org.jetbrains.annotations.NotNull()
    java.lang.StringBuilder builder) {
    }
    
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object other) {
        return false;
    }
    
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    public MobileState(@org.jetbrains.annotations.Nullable()
    java.lang.String networkName, @org.jetbrains.annotations.Nullable()
    java.lang.String networkNameData, boolean dataSim, boolean dataConnected, boolean isEmergency, boolean airplaneMode, boolean carrierNetworkChangeMode, boolean isDefault, boolean userSetup, boolean roaming, int dataState, boolean defaultDataOff) {
        super();
    }
    
    public MobileState() {
        super();
    }
}