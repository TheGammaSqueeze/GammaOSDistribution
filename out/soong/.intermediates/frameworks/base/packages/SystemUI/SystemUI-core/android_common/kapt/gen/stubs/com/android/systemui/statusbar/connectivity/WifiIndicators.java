package com.android.systemui.statusbar.connectivity;

import android.telephony.SubscriptionInfo;

/**
 * Box type for [SignalCallback.setWifiIndicators]
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000&\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u000e\n\u0002\b\u0011\n\u0002\u0010\b\n\u0000\b\u0086\b\u0018\u00002\u00020\u0001BU\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\b\u0010\u0004\u001a\u0004\u0018\u00010\u0005\u0012\b\u0010\u0006\u001a\u0004\u0018\u00010\u0005\u0012\u0006\u0010\u0007\u001a\u00020\u0003\u0012\u0006\u0010\b\u001a\u00020\u0003\u0012\b\u0010\t\u001a\u0004\u0018\u00010\n\u0012\u0006\u0010\u000b\u001a\u00020\u0003\u0012\b\u0010\f\u001a\u0004\u0018\u00010\n\u0012\u0006\u0010\r\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u000eJ\t\u0010\u000f\u001a\u00020\u0003H\u00c6\u0003J\u000b\u0010\u0010\u001a\u0004\u0018\u00010\u0005H\u00c6\u0003J\u000b\u0010\u0011\u001a\u0004\u0018\u00010\u0005H\u00c6\u0003J\t\u0010\u0012\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u0013\u001a\u00020\u0003H\u00c6\u0003J\u000b\u0010\u0014\u001a\u0004\u0018\u00010\nH\u00c6\u0003J\t\u0010\u0015\u001a\u00020\u0003H\u00c6\u0003J\u000b\u0010\u0016\u001a\u0004\u0018\u00010\nH\u00c6\u0003J\t\u0010\u0017\u001a\u00020\u0003H\u00c6\u0003Jk\u0010\u0018\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\n\b\u0002\u0010\u0004\u001a\u0004\u0018\u00010\u00052\n\b\u0002\u0010\u0006\u001a\u0004\u0018\u00010\u00052\b\b\u0002\u0010\u0007\u001a\u00020\u00032\b\b\u0002\u0010\b\u001a\u00020\u00032\n\b\u0002\u0010\t\u001a\u0004\u0018\u00010\n2\b\b\u0002\u0010\u000b\u001a\u00020\u00032\n\b\u0002\u0010\f\u001a\u0004\u0018\u00010\n2\b\b\u0002\u0010\r\u001a\u00020\u0003H\u00c6\u0001J\u0013\u0010\u0019\u001a\u00020\u00032\b\u0010\u001a\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u001b\u001a\u00020\u001cH\u00d6\u0001J\b\u0010\u001d\u001a\u00020\nH\u0016R\u0010\u0010\u0007\u001a\u00020\u00038\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\b\u001a\u00020\u00038\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0012\u0010\t\u001a\u0004\u0018\u00010\n8\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0002\u001a\u00020\u00038\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\r\u001a\u00020\u00038\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u000b\u001a\u00020\u00038\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0012\u0010\u0006\u001a\u0004\u0018\u00010\u00058\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0012\u0010\u0004\u001a\u0004\u0018\u00010\u00058\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0012\u0010\f\u001a\u0004\u0018\u00010\n8\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/connectivity/WifiIndicators;", "", "enabled", "", "statusIcon", "Lcom/android/systemui/statusbar/connectivity/IconState;", "qsIcon", "activityIn", "activityOut", "description", "", "isTransient", "statusLabel", "isDefault", "(ZLcom/android/systemui/statusbar/connectivity/IconState;Lcom/android/systemui/statusbar/connectivity/IconState;ZZLjava/lang/String;ZLjava/lang/String;Z)V", "component1", "component2", "component3", "component4", "component5", "component6", "component7", "component8", "component9", "copy", "equals", "other", "hashCode", "", "toString"})
public final class WifiIndicators {
    public final boolean enabled = false;
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.connectivity.IconState statusIcon = null;
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.connectivity.IconState qsIcon = null;
    public final boolean activityIn = false;
    public final boolean activityOut = false;
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String description = null;
    public final boolean isTransient = false;
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String statusLabel = null;
    public final boolean isDefault = false;
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    public WifiIndicators(boolean enabled, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.connectivity.IconState statusIcon, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.connectivity.IconState qsIcon, boolean activityIn, boolean activityOut, @org.jetbrains.annotations.Nullable()
    java.lang.String description, boolean isTransient, @org.jetbrains.annotations.Nullable()
    java.lang.String statusLabel, boolean isDefault) {
        super();
    }
    
    public final boolean component1() {
        return false;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.connectivity.IconState component2() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.connectivity.IconState component3() {
        return null;
    }
    
    public final boolean component4() {
        return false;
    }
    
    public final boolean component5() {
        return false;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String component6() {
        return null;
    }
    
    public final boolean component7() {
        return false;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String component8() {
        return null;
    }
    
    public final boolean component9() {
        return false;
    }
    
    /**
     * Box type for [SignalCallback.setWifiIndicators]
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.connectivity.WifiIndicators copy(boolean enabled, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.connectivity.IconState statusIcon, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.connectivity.IconState qsIcon, boolean activityIn, boolean activityOut, @org.jetbrains.annotations.Nullable()
    java.lang.String description, boolean isTransient, @org.jetbrains.annotations.Nullable()
    java.lang.String statusLabel, boolean isDefault) {
        return null;
    }
    
    /**
     * Box type for [SignalCallback.setWifiIndicators]
     */
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    /**
     * Box type for [SignalCallback.setWifiIndicators]
     */
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
}