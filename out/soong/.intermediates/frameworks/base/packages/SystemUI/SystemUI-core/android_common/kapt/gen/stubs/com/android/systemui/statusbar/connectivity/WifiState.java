package com.android.systemui.statusbar.connectivity;

import java.lang.StringBuilder;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00004\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0004\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0010\u0000\n\u0002\b\u0003\n\u0002\u0018\u0002\b\u0000\u0018\u00002\u00020\u0001BE\u0012\n\b\u0002\u0010\u0002\u001a\u0004\u0018\u00010\u0003\u0012\b\b\u0002\u0010\u0004\u001a\u00020\u0005\u0012\b\b\u0002\u0010\u0006\u001a\u00020\u0005\u0012\n\b\u0002\u0010\u0007\u001a\u0004\u0018\u00010\u0003\u0012\b\b\u0002\u0010\b\u001a\u00020\u0005\u0012\b\b\u0002\u0010\t\u001a\u00020\n\u00a2\u0006\u0002\u0010\u000bJ\u0010\u0010\f\u001a\u00020\r2\u0006\u0010\u000e\u001a\u00020\u0001H\u0016J\u0013\u0010\u000f\u001a\u00020\u00052\b\u0010\u0010\u001a\u0004\u0018\u00010\u0011H\u0096\u0002J\b\u0010\u0012\u001a\u00020\nH\u0016J\u0010\u0010\u0013\u001a\u00020\r2\u0006\u0010\u0014\u001a\u00020\u0015H\u0014R\u0012\u0010\b\u001a\u00020\u00058\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010\u0006\u001a\u00020\u00058\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010\u0004\u001a\u00020\u00058\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0002\u001a\u0004\u0018\u00010\u00038\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0007\u001a\u0004\u0018\u00010\u00038\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010\t\u001a\u00020\n8\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/connectivity/WifiState;", "Lcom/android/systemui/statusbar/connectivity/ConnectivityState;", "ssid", "", "isTransient", "", "isDefault", "statusLabel", "isCarrierMerged", "subId", "", "(Ljava/lang/String;ZZLjava/lang/String;ZI)V", "copyFrom", "", "s", "equals", "other", "", "hashCode", "toString", "builder", "Ljava/lang/StringBuilder;"})
public final class WifiState extends com.android.systemui.statusbar.connectivity.ConnectivityState {
    @org.jetbrains.annotations.Nullable()
    public java.lang.String ssid;
    public boolean isTransient;
    public boolean isDefault;
    @org.jetbrains.annotations.Nullable()
    public java.lang.String statusLabel;
    public boolean isCarrierMerged;
    public int subId;
    
    @java.lang.Override()
    public void copyFrom(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.connectivity.ConnectivityState s) {
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
    
    public WifiState(@org.jetbrains.annotations.Nullable()
    java.lang.String ssid, boolean isTransient, boolean isDefault, @org.jetbrains.annotations.Nullable()
    java.lang.String statusLabel, boolean isCarrierMerged, int subId) {
        super();
    }
    
    public WifiState() {
        super();
    }
}