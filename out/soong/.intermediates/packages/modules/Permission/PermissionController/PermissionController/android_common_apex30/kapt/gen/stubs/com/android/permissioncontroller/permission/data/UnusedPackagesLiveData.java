package com.android.permissioncontroller.permission.data;

import android.os.UserHandle;
import android.provider.DeviceConfig;
import android.util.ArraySet;
import android.util.Log;
import com.android.permissioncontroller.PermissionControllerApplication;
import com.android.permissioncontroller.permission.utils.Utils;

/**
 * Gets all unused packages from an existing live data that have not been opened in a few months
 * and the permission groups that have been revoked for them, if any. This will let us removed used
 * apps from the Unused Apps screen.
 *
 * @param sourceLiveData the live data for packages to base this list of unused apps on
 * ```(packageName, user) -> [groupName]```
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010$\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\u0010\"\n\u0002\b\u0005\n\u0002\u0010\t\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\u0018\u00002&\u0012\"\u0012 \u0012\u0010\u0012\u000e\u0012\u0004\u0012\u00020\u0004\u0012\u0004\u0012\u00020\u00050\u0003\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00040\u00060\u00020\u0001B%\u0012\u001e\u0010\u0007\u001a\u001a\u0012\u0016\u0012\u0014\u0012\u0010\u0012\u000e\u0012\u0004\u0012\u00020\u0004\u0012\u0004\u0012\u00020\u00050\u00030\u00060\u0001\u00a2\u0006\u0002\u0010\bJ\b\u0010\u000f\u001a\u00020\u0010H\u0014R\u0016\u0010\t\u001a\n \n*\u0004\u0018\u00010\u00040\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R&\u0010\u0007\u001a\u001a\u0012\u0016\u0012\u0014\u0012\u0010\u0012\u000e\u0012\u0004\u0012\u00020\u0004\u0012\u0004\u0012\u00020\u00050\u00030\u00060\u0001X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/data/UnusedPackagesLiveData;", "Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData;", "", "Lkotlin/Pair;", "", "Landroid/os/UserHandle;", "", "sourceLiveData", "(Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData;)V", "LOG_TAG", "kotlin.jvm.PlatformType", "unusedThreshold", "", "usageStatsLiveData", "Lcom/android/permissioncontroller/permission/data/UsageStatsLiveData;", "onUpdate", ""})
public final class UnusedPackagesLiveData extends com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<java.util.Map<kotlin.Pair<? extends java.lang.String, ? extends android.os.UserHandle>, ? extends java.util.Set<? extends java.lang.String>>> {
    private final java.lang.String LOG_TAG = null;
    private long unusedThreshold;
    private com.android.permissioncontroller.permission.data.UsageStatsLiveData usageStatsLiveData;
    private final com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<java.util.Set<kotlin.Pair<java.lang.String, android.os.UserHandle>>> sourceLiveData = null;
    
    @java.lang.Override()
    protected void onUpdate() {
    }
    
    public UnusedPackagesLiveData(@org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<java.util.Set<kotlin.Pair<java.lang.String, android.os.UserHandle>>> sourceLiveData) {
        super(false);
    }
}