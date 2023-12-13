package com.android.permissioncontroller.permission.data;

import android.os.UserHandle;
import com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo;

/**
 * A LiveData which tracks the PackageInfos of all of the packages in the system, for all users.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010$\n\u0002\u0018\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010%\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0003\b\u00c6\u0002\u0018\u00002\u001a\u0012\u0016\u0012\u0014\u0012\u0004\u0012\u00020\u0003\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00050\u00040\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0006J\b\u0010\u000b\u001a\u00020\fH\u0014J \u0010\r\u001a\u00020\f2\u0006\u0010\u000e\u001a\u00020\u00032\u000e\u0010\u000f\u001a\n\u0012\u0004\u0012\u00020\u0005\u0018\u00010\u0004H\u0002R \u0010\u0007\u001a\u0014\u0012\u0004\u0012\u00020\u0003\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00050\u00040\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\t\u001a\u000e\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\n0\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/data/AllPackageInfosLiveData;", "Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData;", "", "Landroid/os/UserHandle;", "", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;", "()V", "userPackageInfos", "", "userPackageInfosLiveDatas", "Lcom/android/permissioncontroller/permission/data/UserPackageInfosLiveData;", "onUpdate", "", "onUserPackageUpdates", "user", "packageInfos"})
public final class AllPackageInfosLiveData extends com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<java.util.Map<android.os.UserHandle, ? extends java.util.List<? extends com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo>>> {
    private static final java.util.Map<android.os.UserHandle, com.android.permissioncontroller.permission.data.UserPackageInfosLiveData> userPackageInfosLiveDatas = null;
    private static final java.util.Map<android.os.UserHandle, java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo>> userPackageInfos = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.data.AllPackageInfosLiveData INSTANCE = null;
    
    @java.lang.Override()
    protected void onUpdate() {
    }
    
    private final void onUserPackageUpdates(android.os.UserHandle user, java.util.List<com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo> packageInfos) {
    }
    
    private AllPackageInfosLiveData() {
        super(false);
    }
}