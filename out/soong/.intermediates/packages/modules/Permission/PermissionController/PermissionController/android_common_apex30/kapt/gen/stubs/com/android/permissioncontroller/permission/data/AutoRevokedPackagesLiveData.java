package com.android.permissioncontroller.permission.data;

import android.content.pm.PackageInfo;
import android.os.Build;
import android.os.UserHandle;
import android.util.Log;
import com.android.permissioncontroller.permission.utils.KotlinUtils;
import com.android.permissioncontroller.permission.utils.Utils;
import kotlinx.coroutines.GlobalScope;

/**
 * Tracks which packages have been auto-revoked, and which groups have been auto revoked for those
 * packages.
 *
 * ```(packageName, user) -> [groupName]```
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000B\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010$\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\u0010\"\n\u0002\b\u0004\n\u0002\u0010%\n\u0002\u0010#\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\b\u00c6\u0002\u0018\u00002&\u0012\"\u0012 \u0012\u0010\u0012\u000e\u0012\u0004\u0012\u00020\u0004\u0012\u0004\u0012\u00020\u00050\u0003\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00040\u00060\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0007J\u0019\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u0012\u001a\u00020\u0013H\u0096@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0014J(\u0010\u0015\u001a\u00020\u00112\u001e\u0010\u0016\u001a\u001a\u0012\u0016\u0012\u0014\u0012\u0004\u0012\u00020\u0004\u0012\u0004\u0012\u00020\u0004\u0012\u0004\u0012\u00020\u00050\u000e0\u0006H\u0002J\b\u0010\u0017\u001a\u00020\u0011H\u0002R\u0016\u0010\b\u001a\n \t*\u0004\u0018\u00010\u00040\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R,\u0010\n\u001a \u0012\u0010\u0012\u000e\u0012\u0004\u0012\u00020\u0004\u0012\u0004\u0012\u00020\u00050\u0003\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00040\f0\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R,\u0010\r\u001a \u0012\u0016\u0012\u0014\u0012\u0004\u0012\u00020\u0004\u0012\u0004\u0012\u00020\u0004\u0012\u0004\u0012\u00020\u00050\u000e\u0012\u0004\u0012\u00020\u000f0\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lcom/android/permissioncontroller/permission/data/AutoRevokedPackagesLiveData;", "Lcom/android/permissioncontroller/permission/data/SmartAsyncMediatorLiveData;", "", "Lkotlin/Pair;", "", "Landroid/os/UserHandle;", "", "()V", "LOG_TAG", "kotlin.jvm.PlatformType", "packageAutoRevokedPermsList", "", "", "permStateLiveDatas", "Lkotlin/Triple;", "Lcom/android/permissioncontroller/permission/data/PermStateLiveData;", "loadDataAndPostValue", "", "job", "Lkotlinx/coroutines/Job;", "(Lkotlinx/coroutines/Job;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "observePermStateLiveDatas", "packageGroups", "postCopyOfMap"})
public final class AutoRevokedPackagesLiveData extends com.android.permissioncontroller.permission.data.SmartAsyncMediatorLiveData<java.util.Map<kotlin.Pair<? extends java.lang.String, ? extends android.os.UserHandle>, ? extends java.util.Set<? extends java.lang.String>>> {
    private static final java.lang.String LOG_TAG = null;
    private static final java.util.Map<kotlin.Triple<java.lang.String, java.lang.String, android.os.UserHandle>, com.android.permissioncontroller.permission.data.PermStateLiveData> permStateLiveDatas = null;
    private static final java.util.Map<kotlin.Pair<java.lang.String, android.os.UserHandle>, java.util.Set<java.lang.String>> packageAutoRevokedPermsList = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.data.AutoRevokedPackagesLiveData INSTANCE = null;
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Object loadDataAndPostValue(@org.jetbrains.annotations.NotNull()
    kotlinx.coroutines.Job job, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p1) {
        return null;
    }
    
    private final void observePermStateLiveDatas(java.util.Set<kotlin.Triple<java.lang.String, java.lang.String, android.os.UserHandle>> packageGroups) {
    }
    
    private final void postCopyOfMap() {
    }
    
    private AutoRevokedPackagesLiveData() {
        super(false, false);
    }
}