package com.android.permissioncontroller.permission.data;

import android.app.ActivityManager;
import android.content.ComponentCallbacks2;
import android.content.res.Configuration;
import androidx.annotation.GuardedBy;
import androidx.annotation.MainThread;
import com.android.permissioncontroller.PermissionControllerApplication;
import java.util.concurrent.TimeUnit;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u001c\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0002\u001aP\u0010\u0000\u001a\u0002H\u0001\"\u0004\b\u0000\u0010\u0002\"\u0004\b\u0001\u0010\u0003\"\b\b\u0002\u0010\u0001*\u00020\u0004*\u001a\u0012\u0010\u0012\u000e\u0012\u0004\u0012\u0002H\u0002\u0012\u0004\u0012\u0002H\u00030\u0006\u0012\u0004\u0012\u0002H\u00010\u00052\u0006\u0010\u0007\u001a\u0002H\u00022\u0006\u0010\b\u001a\u0002H\u0003H\u0086\u0002\u00a2\u0006\u0002\u0010\t\u001ad\u0010\u0000\u001a\u0002H\u0001\"\u0004\b\u0000\u0010\u0002\"\u0004\b\u0001\u0010\u0003\"\u0004\b\u0002\u0010\n\"\b\b\u0003\u0010\u0001*\u00020\u0004* \u0012\u0016\u0012\u0014\u0012\u0004\u0012\u0002H\u0002\u0012\u0004\u0012\u0002H\u0003\u0012\u0004\u0012\u0002H\n0\u000b\u0012\u0004\u0012\u0002H\u00010\u00052\u0006\u0010\u0007\u001a\u0002H\u00022\u0006\u0010\b\u001a\u0002H\u00032\u0006\u0010\f\u001a\u0002H\nH\u0086\u0002\u00a2\u0006\u0002\u0010\r"}, d2 = {"get", "V", "K1", "K2", "Lcom/android/permissioncontroller/permission/data/DataRepository$InactiveTimekeeper;", "Lcom/android/permissioncontroller/permission/data/DataRepository;", "Lkotlin/Pair;", "k1", "k2", "(Lcom/android/permissioncontroller/permission/data/DataRepository;Ljava/lang/Object;Ljava/lang/Object;)Lcom/android/permissioncontroller/permission/data/DataRepository$InactiveTimekeeper;", "K3", "Lkotlin/Triple;", "k3", "(Lcom/android/permissioncontroller/permission/data/DataRepository;Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)Lcom/android/permissioncontroller/permission/data/DataRepository$InactiveTimekeeper;"})
public final class DataRepositoryKt {
    
    /**
     * A convenience to retrieve data from a repository with a composite key
     */
    @org.jetbrains.annotations.NotNull()
    public static final <K1 extends java.lang.Object, K2 extends java.lang.Object, V extends com.android.permissioncontroller.permission.data.DataRepository.InactiveTimekeeper>V get(@org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.data.DataRepository<kotlin.Pair<K1, K2>, V> $this$get, K1 k1, K2 k2) {
        return null;
    }
    
    /**
     * A convenience to retrieve data from a repository with a composite key
     */
    @org.jetbrains.annotations.NotNull()
    public static final <K1 extends java.lang.Object, K2 extends java.lang.Object, K3 extends java.lang.Object, V extends com.android.permissioncontroller.permission.data.DataRepository.InactiveTimekeeper>V get(@org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.data.DataRepository<kotlin.Triple<K1, K2, K3>, V> $this$get, K1 k1, K2 k2, K3 k3) {
        return null;
    }
}