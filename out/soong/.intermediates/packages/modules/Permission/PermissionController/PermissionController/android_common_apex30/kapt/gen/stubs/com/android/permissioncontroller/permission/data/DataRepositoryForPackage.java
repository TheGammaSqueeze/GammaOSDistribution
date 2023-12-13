package com.android.permissioncontroller.permission.data;

import android.app.ActivityManager;
import android.content.ComponentCallbacks2;
import android.content.res.Configuration;
import androidx.annotation.GuardedBy;
import androidx.annotation.MainThread;
import com.android.permissioncontroller.PermissionControllerApplication;
import java.util.concurrent.TimeUnit;

/**
 * A DataRepository where all values are contingent on the existence of a package. Supports
 * invalidating all values tied to a package. Expects key to be a pair or triple, with the package
 * name as the first value of the key.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001e\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000e\b&\u0018\u0000*\u0004\b\u0000\u0010\u0001*\b\b\u0001\u0010\u0002*\u00020\u00032\u000e\u0012\u0004\u0012\u0002H\u0001\u0012\u0004\u0012\u0002H\u00020\u0004B\u0005\u00a2\u0006\u0002\u0010\u0005J\u000e\u0010\u0006\u001a\u00020\u00072\u0006\u0010\b\u001a\u00020\t"}, d2 = {"Lcom/android/permissioncontroller/permission/data/DataRepositoryForPackage;", "K", "V", "Lcom/android/permissioncontroller/permission/data/DataRepository$InactiveTimekeeper;", "Lcom/android/permissioncontroller/permission/data/DataRepository;", "()V", "invalidateAllForPackage", "", "packageName", ""})
public abstract class DataRepositoryForPackage<K extends java.lang.Object, V extends com.android.permissioncontroller.permission.data.DataRepository.InactiveTimekeeper> extends com.android.permissioncontroller.permission.data.DataRepository<K, V> {
    
    /**
     * Invalidates every value with the packageName in the key.
     *
     * @param packageName The package to be invalidated
     */
    public final void invalidateAllForPackage(@org.jetbrains.annotations.NotNull()
    java.lang.String packageName) {
    }
    
    public DataRepositoryForPackage() {
        super();
    }
}