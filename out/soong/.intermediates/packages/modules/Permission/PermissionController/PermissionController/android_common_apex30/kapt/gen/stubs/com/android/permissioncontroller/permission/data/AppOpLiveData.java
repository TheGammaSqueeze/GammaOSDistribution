package com.android.permissioncontroller.permission.data;

import android.app.AppOpsManager;
import android.app.Application;
import com.android.permissioncontroller.PermissionControllerApplication;

/**
 * A LiveData which represents the appop state
 *
 * @param app The current application
 * @param packageName The name of the package
 * @param op The name of the appop
 * @param uid The uid of the package
 *
 * @see AppOpsManager
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\u0018\u0000 \u000f2\b\u0012\u0004\u0012\u00020\u00020\u0001:\u0001\u000fB\'\b\u0002\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\u0006\u0012\u0006\u0010\b\u001a\u00020\u0002\u00a2\u0006\u0002\u0010\tJ\b\u0010\f\u001a\u00020\rH\u0014J\b\u0010\u000e\u001a\u00020\rH\u0014R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0002X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/data/AppOpLiveData;", "Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData;", "", "app", "Landroid/app/Application;", "packageName", "", "op", "uid", "(Landroid/app/Application;Ljava/lang/String;Ljava/lang/String;I)V", "appOpsManager", "Landroid/app/AppOpsManager;", "onActive", "", "onUpdate", "Companion"})
public final class AppOpLiveData extends com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<java.lang.Integer> {
    private final android.app.AppOpsManager appOpsManager = null;
    private final android.app.Application app = null;
    private final java.lang.String packageName = null;
    private final java.lang.String op = null;
    private final int uid = 0;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.data.AppOpLiveData.Companion Companion = null;
    
    @java.lang.Override()
    protected void onUpdate() {
    }
    
    @java.lang.Override()
    protected void onActive() {
    }
    
    private AppOpLiveData(android.app.Application app, java.lang.String packageName, java.lang.String op, int uid) {
        super(false);
    }
    
    /**
     * Repository for AppOpLiveData.
     * <p> Key value is a triple of string package name, string appop, and
     * package uid, value is its corresponding LiveData.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0010\b\n\u0002\u0018\u0002\n\u0002\b\u0003\b\u0086\u0003\u0018\u00002 \u0012\u0016\u0012\u0014\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u00040\u0002\u0012\u0004\u0012\u00020\u00050\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0006J\"\u0010\u0007\u001a\u00020\u00052\u0018\u0010\b\u001a\u0014\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u00040\u0002H\u0014"}, d2 = {"Lcom/android/permissioncontroller/permission/data/AppOpLiveData$Companion;", "Lcom/android/permissioncontroller/permission/data/DataRepository;", "Lkotlin/Triple;", "", "", "Lcom/android/permissioncontroller/permission/data/AppOpLiveData;", "()V", "newValue", "key"})
    public static final class Companion extends com.android.permissioncontroller.permission.data.DataRepository<kotlin.Triple<? extends java.lang.String, ? extends java.lang.String, ? extends java.lang.Integer>, com.android.permissioncontroller.permission.data.AppOpLiveData> {
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        protected com.android.permissioncontroller.permission.data.AppOpLiveData newValue(@org.jetbrains.annotations.NotNull()
        kotlin.Triple<java.lang.String, java.lang.String, java.lang.Integer> key) {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}