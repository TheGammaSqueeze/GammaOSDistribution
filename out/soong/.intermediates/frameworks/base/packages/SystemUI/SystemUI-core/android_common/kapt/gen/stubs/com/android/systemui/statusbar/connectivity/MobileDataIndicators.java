package com.android.systemui.statusbar.connectivity;

import android.telephony.SubscriptionInfo;

/**
 * Box type for [SignalCallback.setMobileDataIndicators]
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000.\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\r\n\u0002\b\u0019\n\u0002\u0010\u000e\b\u0086\b\u0018\u00002\u00020\u0001Bw\u0012\b\u0010\u0002\u001a\u0004\u0018\u00010\u0003\u0012\b\u0010\u0004\u001a\u0004\u0018\u00010\u0003\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\u0006\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\t\u0012\b\u0010\u000b\u001a\u0004\u0018\u00010\f\u0012\b\u0010\r\u001a\u0004\u0018\u00010\f\u0012\b\u0010\u000e\u001a\u0004\u0018\u00010\f\u0012\u0006\u0010\u000f\u001a\u00020\u0006\u0012\u0006\u0010\u0010\u001a\u00020\t\u0012\u0006\u0010\u0011\u001a\u00020\t\u0012\u0006\u0010\u0012\u001a\u00020\t\u00a2\u0006\u0002\u0010\u0013J\u000b\u0010\u0014\u001a\u0004\u0018\u00010\u0003H\u00c6\u0003J\t\u0010\u0015\u001a\u00020\u0006H\u00c6\u0003J\t\u0010\u0016\u001a\u00020\tH\u00c6\u0003J\t\u0010\u0017\u001a\u00020\tH\u00c6\u0003J\t\u0010\u0018\u001a\u00020\tH\u00c6\u0003J\u000b\u0010\u0019\u001a\u0004\u0018\u00010\u0003H\u00c6\u0003J\t\u0010\u001a\u001a\u00020\u0006H\u00c6\u0003J\t\u0010\u001b\u001a\u00020\u0006H\u00c6\u0003J\t\u0010\u001c\u001a\u00020\tH\u00c6\u0003J\t\u0010\u001d\u001a\u00020\tH\u00c6\u0003J\u000b\u0010\u001e\u001a\u0004\u0018\u00010\fH\u00c6\u0003J\u000b\u0010\u001f\u001a\u0004\u0018\u00010\fH\u00c6\u0003J\u000b\u0010 \u001a\u0004\u0018\u00010\fH\u00c6\u0003J\u0095\u0001\u0010!\u001a\u00020\u00002\n\b\u0002\u0010\u0002\u001a\u0004\u0018\u00010\u00032\n\b\u0002\u0010\u0004\u001a\u0004\u0018\u00010\u00032\b\b\u0002\u0010\u0005\u001a\u00020\u00062\b\b\u0002\u0010\u0007\u001a\u00020\u00062\b\b\u0002\u0010\b\u001a\u00020\t2\b\b\u0002\u0010\n\u001a\u00020\t2\n\b\u0002\u0010\u000b\u001a\u0004\u0018\u00010\f2\n\b\u0002\u0010\r\u001a\u0004\u0018\u00010\f2\n\b\u0002\u0010\u000e\u001a\u0004\u0018\u00010\f2\b\b\u0002\u0010\u000f\u001a\u00020\u00062\b\b\u0002\u0010\u0010\u001a\u00020\t2\b\b\u0002\u0010\u0011\u001a\u00020\t2\b\b\u0002\u0010\u0012\u001a\u00020\tH\u00c6\u0001J\u0013\u0010\"\u001a\u00020\t2\b\u0010#\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010$\u001a\u00020\u0006H\u00d6\u0001J\b\u0010%\u001a\u00020&H\u0016R\u0010\u0010\b\u001a\u00020\t8\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\n\u001a\u00020\t8\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0012\u001a\u00020\t8\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0012\u0010\u000e\u001a\u0004\u0018\u00010\f8\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0012\u0010\u0004\u001a\u0004\u0018\u00010\u00038\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0007\u001a\u00020\u00068\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0010\u001a\u00020\t8\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0011\u001a\u00020\t8\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0012\u0010\u0002\u001a\u0004\u0018\u00010\u00038\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0005\u001a\u00020\u00068\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u000f\u001a\u00020\u00068\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0012\u0010\u000b\u001a\u0004\u0018\u00010\f8\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0012\u0010\r\u001a\u0004\u0018\u00010\f8\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/connectivity/MobileDataIndicators;", "", "statusIcon", "Lcom/android/systemui/statusbar/connectivity/IconState;", "qsIcon", "statusType", "", "qsType", "activityIn", "", "activityOut", "typeContentDescription", "", "typeContentDescriptionHtml", "qsDescription", "subId", "roaming", "showTriangle", "isDefault", "(Lcom/android/systemui/statusbar/connectivity/IconState;Lcom/android/systemui/statusbar/connectivity/IconState;IIZZLjava/lang/CharSequence;Ljava/lang/CharSequence;Ljava/lang/CharSequence;IZZZ)V", "component1", "component10", "component11", "component12", "component13", "component2", "component3", "component4", "component5", "component6", "component7", "component8", "component9", "copy", "equals", "other", "hashCode", "toString", ""})
public final class MobileDataIndicators {
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.connectivity.IconState statusIcon = null;
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.connectivity.IconState qsIcon = null;
    public final int statusType = 0;
    public final int qsType = 0;
    public final boolean activityIn = false;
    public final boolean activityOut = false;
    @org.jetbrains.annotations.Nullable()
    public final java.lang.CharSequence typeContentDescription = null;
    @org.jetbrains.annotations.Nullable()
    public final java.lang.CharSequence typeContentDescriptionHtml = null;
    @org.jetbrains.annotations.Nullable()
    public final java.lang.CharSequence qsDescription = null;
    public final int subId = 0;
    public final boolean roaming = false;
    public final boolean showTriangle = false;
    public final boolean isDefault = false;
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    public MobileDataIndicators(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.connectivity.IconState statusIcon, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.connectivity.IconState qsIcon, int statusType, int qsType, boolean activityIn, boolean activityOut, @org.jetbrains.annotations.Nullable()
    java.lang.CharSequence typeContentDescription, @org.jetbrains.annotations.Nullable()
    java.lang.CharSequence typeContentDescriptionHtml, @org.jetbrains.annotations.Nullable()
    java.lang.CharSequence qsDescription, int subId, boolean roaming, boolean showTriangle, boolean isDefault) {
        super();
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.connectivity.IconState component1() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.connectivity.IconState component2() {
        return null;
    }
    
    public final int component3() {
        return 0;
    }
    
    public final int component4() {
        return 0;
    }
    
    public final boolean component5() {
        return false;
    }
    
    public final boolean component6() {
        return false;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.CharSequence component7() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.CharSequence component8() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.CharSequence component9() {
        return null;
    }
    
    public final int component10() {
        return 0;
    }
    
    public final boolean component11() {
        return false;
    }
    
    public final boolean component12() {
        return false;
    }
    
    public final boolean component13() {
        return false;
    }
    
    /**
     * Box type for [SignalCallback.setMobileDataIndicators]
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.connectivity.MobileDataIndicators copy(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.connectivity.IconState statusIcon, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.connectivity.IconState qsIcon, int statusType, int qsType, boolean activityIn, boolean activityOut, @org.jetbrains.annotations.Nullable()
    java.lang.CharSequence typeContentDescription, @org.jetbrains.annotations.Nullable()
    java.lang.CharSequence typeContentDescriptionHtml, @org.jetbrains.annotations.Nullable()
    java.lang.CharSequence qsDescription, int subId, boolean roaming, boolean showTriangle, boolean isDefault) {
        return null;
    }
    
    /**
     * Box type for [SignalCallback.setMobileDataIndicators]
     */
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    /**
     * Box type for [SignalCallback.setMobileDataIndicators]
     */
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
}