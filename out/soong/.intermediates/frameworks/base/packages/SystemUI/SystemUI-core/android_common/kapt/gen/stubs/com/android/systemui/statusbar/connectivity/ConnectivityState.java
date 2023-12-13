package com.android.systemui.statusbar.connectivity;

import android.annotation.SuppressLint;
import com.android.settingslib.SignalIcon.IconGroup;
import java.text.SimpleDateFormat;

/**
 * Base type for various connectivity states, for use with [SignalController] and its subtypes
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000>\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0010\t\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0004\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\b\u0016\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u0012\u001a\u00020\u0000H\u0014J\u0013\u0010\u0013\u001a\u00020\u00042\b\u0010\u0012\u001a\u0004\u0018\u00010\u0001H\u0096\u0002J\b\u0010\u0014\u001a\u00020\u000bH\u0016J\b\u0010\u0015\u001a\u00020\u0016H\u0016J\u0014\u0010\u0015\u001a\u00020\u00112\n\u0010\u0017\u001a\u00060\u0018j\u0002`\u0019H\u0014R\u0012\u0010\u0003\u001a\u00020\u00048\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010\u0005\u001a\u00020\u00048\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010\u0006\u001a\u00020\u00048\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010\u0007\u001a\u00020\u00048\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010\b\u001a\u0004\u0018\u00010\t8\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010\n\u001a\u00020\u000b8\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010\f\u001a\u00020\u000b8\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010\r\u001a\u00020\u000b8\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010\u000e\u001a\u00020\u000f8\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/connectivity/ConnectivityState;", "", "()V", "activityIn", "", "activityOut", "connected", "enabled", "iconGroup", "Lcom/android/settingslib/SignalIcon$IconGroup;", "inetCondition", "", "level", "rssi", "time", "", "copyFrom", "", "other", "equals", "hashCode", "toString", "", "builder", "Ljava/lang/StringBuilder;", "Lkotlin/text/StringBuilder;"})
public class ConnectivityState {
    public boolean connected = false;
    public boolean enabled = false;
    public boolean activityIn = false;
    public boolean activityOut = false;
    public int level = 0;
    @org.jetbrains.annotations.Nullable()
    public com.android.settingslib.SignalIcon.IconGroup iconGroup;
    public int inetCondition = 0;
    public int rssi = 0;
    public long time = 0L;
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    protected void copyFrom(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.connectivity.ConnectivityState other) {
    }
    
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
    
    public ConnectivityState() {
        super();
    }
}