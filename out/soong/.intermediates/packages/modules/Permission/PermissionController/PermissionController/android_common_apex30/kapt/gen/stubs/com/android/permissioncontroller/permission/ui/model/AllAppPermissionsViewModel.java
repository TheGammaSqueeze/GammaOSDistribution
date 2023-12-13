package com.android.permissioncontroller.permission.ui.model;

import android.os.UserHandle;
import androidx.lifecycle.ViewModel;
import androidx.lifecycle.ViewModelProvider;
import com.android.permissioncontroller.permission.data.PackagePermissionsLiveData;
import com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData;

/**
 * ViewModel for the AllAppPermissionsFragment. Has a liveData with the UI information for all
 * Permissions (organized by group) that this package requests, and all the installed, non-runtime,
 * normal protection permissions as well.
 *
 * @param packageName The name of the package this viewModel is representing
 * @param user The user of the package this viewModel is representing
 * @param filterGroup An optional single group that should be shown, no other groups will be
 * shown
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\u0018\u00002\u00020\u0001:\u0001\fB\u001f\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\b\u0010\u0006\u001a\u0004\u0018\u00010\u0003\u00a2\u0006\u0002\u0010\u0007R\u0011\u0010\b\u001a\u00020\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\u000b"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/AllAppPermissionsViewModel;", "Landroidx/lifecycle/ViewModel;", "packageName", "", "user", "Landroid/os/UserHandle;", "filterGroup", "(Ljava/lang/String;Landroid/os/UserHandle;Ljava/lang/String;)V", "allPackagePermissionsLiveData", "Lcom/android/permissioncontroller/permission/ui/model/AllAppPermissionsViewModel$AllPackagePermissionsLiveData;", "getAllPackagePermissionsLiveData", "()Lcom/android/permissioncontroller/permission/ui/model/AllAppPermissionsViewModel$AllPackagePermissionsLiveData;", "AllPackagePermissionsLiveData"})
public final class AllAppPermissionsViewModel extends androidx.lifecycle.ViewModel {
    @org.jetbrains.annotations.NotNull()
    private final com.android.permissioncontroller.permission.ui.model.AllAppPermissionsViewModel.AllPackagePermissionsLiveData allPackagePermissionsLiveData = null;
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.ui.model.AllAppPermissionsViewModel.AllPackagePermissionsLiveData getAllPackagePermissionsLiveData() {
        return null;
    }
    
    public AllAppPermissionsViewModel(@org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user, @org.jetbrains.annotations.Nullable()
    java.lang.String filterGroup) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000.\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010$\n\u0002\u0010\u000e\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\u0018\u00002\u001f\u0012\u001b\u0012\u0019\u0012\u0004\u0012\u00020\u0003\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00030\u00040\u0002\u00a2\u0006\u0002\b\u00050\u0001B\u001f\u0012\u0006\u0010\u0006\u001a\u00020\u0003\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\b\u0010\t\u001a\u0004\u0018\u00010\u0003\u00a2\u0006\u0002\u0010\nJ\b\u0010\r\u001a\u00020\u000eH\u0014R\u0010\u0010\t\u001a\u0004\u0018\u00010\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/AllAppPermissionsViewModel$AllPackagePermissionsLiveData;", "Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData;", "", "", "", "Lkotlin/jvm/JvmSuppressWildcards;", "packageName", "user", "Landroid/os/UserHandle;", "filterGroup", "(Ljava/lang/String;Landroid/os/UserHandle;Ljava/lang/String;)V", "packagePermsLiveData", "Lcom/android/permissioncontroller/permission/data/PackagePermissionsLiveData;", "onUpdate", ""})
    public static final class AllPackagePermissionsLiveData extends com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<java.util.Map<java.lang.String, java.util.List<java.lang.String>>> {
        private final com.android.permissioncontroller.permission.data.PackagePermissionsLiveData packagePermsLiveData = null;
        private final java.lang.String filterGroup = null;
        
        @java.lang.Override()
        protected void onUpdate() {
        }
        
        public AllPackagePermissionsLiveData(@org.jetbrains.annotations.NotNull()
        java.lang.String packageName, @org.jetbrains.annotations.NotNull()
        android.os.UserHandle user, @org.jetbrains.annotations.Nullable()
        java.lang.String filterGroup) {
            super(false);
        }
    }
}