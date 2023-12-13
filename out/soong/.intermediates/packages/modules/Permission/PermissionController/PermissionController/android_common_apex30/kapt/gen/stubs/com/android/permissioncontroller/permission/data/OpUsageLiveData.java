package com.android.permissioncontroller.permission.data;

import android.app.AppOpsManager;
import android.app.Application;
import android.os.Parcel;
import android.os.Parcelable;
import android.os.UserHandle;
import android.util.Log;
import com.android.permissioncontroller.PermissionControllerApplication;
import kotlinx.coroutines.GlobalScope;

/**
 * LiveData that loads the last usage of each of a list of app ops for every package.
 *
 * <p>For app-ops with duration the end of the access is considered.
 *
 * <p>Returns map op-name -> {@link OpAccess}
 *
 * @param app The current application
 * @param opNames The names of the app ops we wish to search for
 * @param usageDurationMs how much ago can an access have happened to be considered
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000T\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010$\n\u0002\u0010\u000e\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\t\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\u0018\u0000 \u001e2\u001f\u0012\u001b\u0012\u0019\u0012\u0004\u0012\u00020\u0003\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00050\u00040\u0002\u00a2\u0006\u0002\b\u00060\u00012\u00020\u0007:\u0001\u001eB#\u0012\u0006\u0010\b\u001a\u00020\t\u0012\f\u0010\n\u001a\b\u0012\u0004\u0012\u00020\u00030\u0004\u0012\u0006\u0010\u000b\u001a\u00020\f\u00a2\u0006\u0002\u0010\rJ\u0019\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u0012\u001a\u00020\u0013H\u0096@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0014J\b\u0010\u0015\u001a\u00020\u0011H\u0014J\b\u0010\u0016\u001a\u00020\u0011H\u0014J(\u0010\u0017\u001a\u00020\u00112\u0006\u0010\u0018\u001a\u00020\u00032\u0006\u0010\u0019\u001a\u00020\u001a2\u0006\u0010\u001b\u001a\u00020\u00032\u0006\u0010\u001c\u001a\u00020\u001dH\u0016R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\u000fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\n\u001a\b\u0012\u0004\u0012\u00020\u00030\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lcom/android/permissioncontroller/permission/data/OpUsageLiveData;", "Lcom/android/permissioncontroller/permission/data/SmartAsyncMediatorLiveData;", "", "", "", "Lcom/android/permissioncontroller/permission/data/OpAccess;", "Lkotlin/jvm/JvmSuppressWildcards;", "Landroid/app/AppOpsManager$OnOpActiveChangedListener;", "app", "Landroid/app/Application;", "opNames", "usageDurationMs", "", "(Landroid/app/Application;Ljava/util/List;J)V", "appOpsManager", "Landroid/app/AppOpsManager;", "loadDataAndPostValue", "", "job", "Lkotlinx/coroutines/Job;", "(Lkotlinx/coroutines/Job;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onActive", "onInactive", "onOpActiveChanged", "op", "uid", "", "packageName", "active", "", "Companion"})
public final class OpUsageLiveData extends com.android.permissioncontroller.permission.data.SmartAsyncMediatorLiveData<java.util.Map<java.lang.String, java.util.List<com.android.permissioncontroller.permission.data.OpAccess>>> implements android.app.AppOpsManager.OnOpActiveChangedListener {
    private final android.app.AppOpsManager appOpsManager = null;
    private final android.app.Application app = null;
    private final java.util.List<java.lang.String> opNames = null;
    private final long usageDurationMs = 0L;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.data.OpUsageLiveData.Companion Companion = null;
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Object loadDataAndPostValue(@org.jetbrains.annotations.NotNull()
    kotlinx.coroutines.Job job, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p1) {
        return null;
    }
    
    @java.lang.Override()
    protected void onActive() {
    }
    
    @java.lang.Override()
    protected void onInactive() {
    }
    
    @java.lang.Override()
    public void onOpActiveChanged(@org.jetbrains.annotations.NotNull()
    java.lang.String op, int uid, @org.jetbrains.annotations.NotNull()
    java.lang.String packageName, boolean active) {
    }
    
    public OpUsageLiveData(@org.jetbrains.annotations.NotNull()
    android.app.Application app, @org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> opNames, long usageDurationMs) {
        super(false, false);
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010 \n\u0002\u0010\u000e\n\u0002\u0010\t\n\u0002\u0018\u0002\n\u0002\b\u0006\b\u0086\u0003\u0018\u00002 \u0012\u0016\u0012\u0014\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00040\u0003\u0012\u0004\u0012\u00020\u00050\u0002\u0012\u0004\u0012\u00020\u00060\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0007J\u001f\u0010\b\u001a\u00020\u00062\f\u0010\t\u001a\b\u0012\u0004\u0012\u00020\u00040\u00032\u0006\u0010\n\u001a\u00020\u0005H\u0086\u0002J\"\u0010\u000b\u001a\u00020\u00062\u0018\u0010\f\u001a\u0014\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00040\u0003\u0012\u0004\u0012\u00020\u00050\u0002H\u0014"}, d2 = {"Lcom/android/permissioncontroller/permission/data/OpUsageLiveData$Companion;", "Lcom/android/permissioncontroller/permission/data/DataRepository;", "Lkotlin/Pair;", "", "", "", "Lcom/android/permissioncontroller/permission/data/OpUsageLiveData;", "()V", "get", "ops", "usageDurationMs", "newValue", "key"})
    public static final class Companion extends com.android.permissioncontroller.permission.data.DataRepository<kotlin.Pair<? extends java.util.List<? extends java.lang.String>, ? extends java.lang.Long>, com.android.permissioncontroller.permission.data.OpUsageLiveData> {
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        protected com.android.permissioncontroller.permission.data.OpUsageLiveData newValue(@org.jetbrains.annotations.NotNull()
        kotlin.Pair<? extends java.util.List<java.lang.String>, java.lang.Long> key) {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.permissioncontroller.permission.data.OpUsageLiveData get(@org.jetbrains.annotations.NotNull()
        java.util.List<java.lang.String> ops, long usageDurationMs) {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}