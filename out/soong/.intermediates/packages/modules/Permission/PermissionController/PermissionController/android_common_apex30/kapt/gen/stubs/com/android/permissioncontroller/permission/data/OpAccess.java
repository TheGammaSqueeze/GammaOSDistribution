package com.android.permissioncontroller.permission.data;

import android.app.AppOpsManager;
import android.app.Application;
import android.os.Parcel;
import android.os.Parcelable;
import android.os.UserHandle;
import android.util.Log;
import com.android.permissioncontroller.PermissionControllerApplication;
import kotlinx.coroutines.GlobalScope;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000F\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\n\u0002\b\u0005\n\u0002\u0010\u000b\n\u0002\b\u000f\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u0000\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\b\u0086\b\u0018\u0000 )2\u00020\u0001:\u0001)B3\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\b\u0010\u0004\u001a\u0004\u0018\u00010\u0003\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\n\b\u0002\u0010\t\u001a\u0004\u0018\u00010\u0000\u00a2\u0006\u0002\u0010\nJ\t\u0010\u0017\u001a\u00020\u0003H\u00c6\u0003J\u000b\u0010\u0018\u001a\u0004\u0018\u00010\u0003H\u00c6\u0003J\t\u0010\u0019\u001a\u00020\u0006H\u00c6\u0003J\t\u0010\u001a\u001a\u00020\bH\u00c6\u0003J\u000b\u0010\u001b\u001a\u0004\u0018\u00010\u0000H\u00c6\u0003J?\u0010\u001c\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\n\b\u0002\u0010\u0004\u001a\u0004\u0018\u00010\u00032\b\b\u0002\u0010\u0005\u001a\u00020\u00062\b\b\u0002\u0010\u0007\u001a\u00020\b2\n\b\u0002\u0010\t\u001a\u0004\u0018\u00010\u0000H\u00c6\u0001J\b\u0010\u001d\u001a\u00020\u001eH\u0016J\u0013\u0010\u001f\u001a\u00020\u000e2\b\u0010 \u001a\u0004\u0018\u00010!H\u00d6\u0003J\t\u0010\"\u001a\u00020\u001eH\u00d6\u0001J\t\u0010#\u001a\u00020\u0003H\u00d6\u0001J\u0018\u0010$\u001a\u00020%2\u0006\u0010&\u001a\u00020\'2\u0006\u0010(\u001a\u00020\u001eH\u0016R\u0013\u0010\u0004\u001a\u0004\u0018\u00010\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\fR\u0011\u0010\r\u001a\u00020\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\r\u0010\u000fR\u0011\u0010\u0007\u001a\u00020\b\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0010\u0010\u0011R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\fR\u0013\u0010\t\u001a\u0004\u0018\u00010\u0000\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0013\u0010\u0014R\u0011\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0015\u0010\u0016"}, d2 = {"Lcom/android/permissioncontroller/permission/data/OpAccess;", "Landroid/os/Parcelable;", "packageName", "", "attributionTag", "user", "Landroid/os/UserHandle;", "lastAccessTime", "", "proxyAccess", "(Ljava/lang/String;Ljava/lang/String;Landroid/os/UserHandle;JLcom/android/permissioncontroller/permission/data/OpAccess;)V", "getAttributionTag", "()Ljava/lang/String;", "isRunning", "", "()Z", "getLastAccessTime", "()J", "getPackageName", "getProxyAccess", "()Lcom/android/permissioncontroller/permission/data/OpAccess;", "getUser", "()Landroid/os/UserHandle;", "component1", "component2", "component3", "component4", "component5", "copy", "describeContents", "", "equals", "other", "", "hashCode", "toString", "writeToParcel", "", "parcel", "Landroid/os/Parcel;", "flags", "Companion"})
public final class OpAccess implements android.os.Parcelable {
    private final boolean isRunning = false;
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String packageName = null;
    @org.jetbrains.annotations.Nullable()
    private final java.lang.String attributionTag = null;
    @org.jetbrains.annotations.NotNull()
    private final android.os.UserHandle user = null;
    private final long lastAccessTime = 0L;
    @org.jetbrains.annotations.Nullable()
    private final com.android.permissioncontroller.permission.data.OpAccess proxyAccess = null;
    public static final long IS_RUNNING = -1L;
    @org.jetbrains.annotations.NotNull()
    public static final android.os.Parcelable.Creator<com.android.permissioncontroller.permission.data.OpAccess> CREATOR = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.data.OpAccess.Companion Companion = null;
    
    public final boolean isRunning() {
        return false;
    }
    
    @java.lang.Override()
    public void writeToParcel(@org.jetbrains.annotations.NotNull()
    android.os.Parcel parcel, int flags) {
    }
    
    @java.lang.Override()
    public int describeContents() {
        return 0;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getPackageName() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String getAttributionTag() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.os.UserHandle getUser() {
        return null;
    }
    
    public final long getLastAccessTime() {
        return 0L;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.permissioncontroller.permission.data.OpAccess getProxyAccess() {
        return null;
    }
    
    public OpAccess(@org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.Nullable()
    java.lang.String attributionTag, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user, long lastAccessTime, @org.jetbrains.annotations.Nullable()
    com.android.permissioncontroller.permission.data.OpAccess proxyAccess) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String component1() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String component2() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.os.UserHandle component3() {
        return null;
    }
    
    public final long component4() {
        return 0L;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.permissioncontroller.permission.data.OpAccess component5() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.data.OpAccess copy(@org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.Nullable()
    java.lang.String attributionTag, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user, long lastAccessTime, @org.jetbrains.annotations.Nullable()
    com.android.permissioncontroller.permission.data.OpAccess proxyAccess) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001a\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u0016\u0010\u0003\u001a\b\u0012\u0004\u0012\u00020\u00050\u00048\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0086T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/data/OpAccess$Companion;", "", "()V", "CREATOR", "Landroid/os/Parcelable$Creator;", "Lcom/android/permissioncontroller/permission/data/OpAccess;", "IS_RUNNING", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}