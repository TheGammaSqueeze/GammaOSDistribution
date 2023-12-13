package com.android.permissioncontroller.permission.data;

import android.content.pm.PackageInfo;
import android.os.Build;
import android.os.UserHandle;
import android.util.Log;
import com.android.permissioncontroller.permission.utils.KotlinUtils;
import com.android.permissioncontroller.permission.utils.Utils;
import kotlinx.coroutines.GlobalScope;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000 \n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\"\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\"&\u0010\u0000\u001a\u001a\u0012\u0016\u0012\u0014\u0012\u0010\u0012\u000e\u0012\u0004\u0012\u00020\u0004\u0012\u0004\u0012\u00020\u00050\u00030\u00020\u0001X\u0082\u0004\u00a2\u0006\u0002\n\u0000\"\u0011\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\b\u0010\t"}, d2 = {"autoRevokedPackagesSetLiveData", "Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData;", "", "Lkotlin/Pair;", "", "Landroid/os/UserHandle;", "unusedAutoRevokePackagesLiveData", "Lcom/android/permissioncontroller/permission/data/UnusedPackagesLiveData;", "getUnusedAutoRevokePackagesLiveData", "()Lcom/android/permissioncontroller/permission/data/UnusedPackagesLiveData;"})
public final class AutoRevokedPackagesLiveDataKt {
    private static final com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<java.util.Set<kotlin.Pair<java.lang.String, android.os.UserHandle>>> autoRevokedPackagesSetLiveData = null;
    @org.jetbrains.annotations.NotNull()
    private static final com.android.permissioncontroller.permission.data.UnusedPackagesLiveData unusedAutoRevokePackagesLiveData = null;
    
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.data.UnusedPackagesLiveData getUnusedAutoRevokePackagesLiveData() {
        return null;
    }
}