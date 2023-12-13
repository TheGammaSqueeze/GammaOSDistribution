package com.android.permissioncontroller.permission.data;

import android.app.Application;
import android.telephony.TelephonyManager;
import com.android.permissioncontroller.PermissionControllerApplication;

/**
 * A LiveData which represents the carrier privileged status for a package
 *
 * @param app The current application
 * @param packageName The name of the package
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000,\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0002\b\u0002\u0018\u0000 \u000f2\b\u0012\u0004\u0012\u00020\u00020\u0001:\u0001\u000fB\u0017\b\u0002\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\u0002\u0010\u0007J\b\u0010\f\u001a\u00020\rH\u0014J\b\u0010\u000e\u001a\u00020\rH\u0014R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0011\u0010\b\u001a\u00020\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\u000b"}, d2 = {"Lcom/android/permissioncontroller/permission/data/CarrierPrivilegedStatusLiveData;", "Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData;", "", "app", "Landroid/app/Application;", "packageName", "", "(Landroid/app/Application;Ljava/lang/String;)V", "telephonyManager", "Landroid/telephony/TelephonyManager;", "getTelephonyManager", "()Landroid/telephony/TelephonyManager;", "onActive", "", "onUpdate", "Companion"})
public final class CarrierPrivilegedStatusLiveData extends com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<java.lang.Integer> {
    @org.jetbrains.annotations.NotNull()
    private final android.telephony.TelephonyManager telephonyManager = null;
    private final android.app.Application app = null;
    private final java.lang.String packageName = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.data.CarrierPrivilegedStatusLiveData.Companion Companion = null;
    
    @org.jetbrains.annotations.NotNull()
    public final android.telephony.TelephonyManager getTelephonyManager() {
        return null;
    }
    
    @java.lang.Override()
    protected void onUpdate() {
    }
    
    @java.lang.Override()
    protected void onActive() {
    }
    
    private CarrierPrivilegedStatusLiveData(android.app.Application app, java.lang.String packageName) {
        super(false);
    }
    
    /**
     * Repository for [CarrierPrivilegedStatusLiveData].
     * <p> Key value is a package name, value is its corresponding LiveData of
     * [android.telephony.Annotation.CarrierPrivilegeStatus]
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\b\u0003\b\u0086\u0003\u0018\u00002\u000e\u0012\u0004\u0012\u00020\u0002\u0012\u0004\u0012\u00020\u00030\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0004J\u0010\u0010\u0005\u001a\u00020\u00032\u0006\u0010\u0006\u001a\u00020\u0002H\u0014"}, d2 = {"Lcom/android/permissioncontroller/permission/data/CarrierPrivilegedStatusLiveData$Companion;", "Lcom/android/permissioncontroller/permission/data/DataRepository;", "", "Lcom/android/permissioncontroller/permission/data/CarrierPrivilegedStatusLiveData;", "()V", "newValue", "key"})
    public static final class Companion extends com.android.permissioncontroller.permission.data.DataRepository<java.lang.String, com.android.permissioncontroller.permission.data.CarrierPrivilegedStatusLiveData> {
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        protected com.android.permissioncontroller.permission.data.CarrierPrivilegedStatusLiveData newValue(@org.jetbrains.annotations.NotNull()
        java.lang.String key) {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}