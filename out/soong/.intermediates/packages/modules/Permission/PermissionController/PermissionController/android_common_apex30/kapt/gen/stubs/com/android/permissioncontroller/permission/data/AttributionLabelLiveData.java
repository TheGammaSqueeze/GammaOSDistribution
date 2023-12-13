package com.android.permissioncontroller.permission.data;

import android.app.Application;
import android.content.pm.PackageManager.NameNotFoundException;
import android.os.UserHandle;
import android.util.Log;
import com.android.permissioncontroller.PermissionControllerApplication;
import org.xmlpull.v1.XmlPullParser;
import java.io.FileNotFoundException;

/**
 * Label-resource-id of an attribution of a package/user.
 *
 * <p>Obviously the resource is found in the package, hence needs to be loaded via a Resources
 * object created for this package.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000<\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\b\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\u0018\u0000 \u00182\b\u0012\u0004\u0012\u00020\u00020\u00012\u00020\u0003:\u0001\u0018B)\b\u0002\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\b\u0010\u0006\u001a\u0004\u0018\u00010\u0007\u0012\u0006\u0010\b\u001a\u00020\u0007\u0012\u0006\u0010\t\u001a\u00020\n\u00a2\u0006\u0002\u0010\u000bJ\u0019\u0010\u000e\u001a\u00020\u000f2\u0006\u0010\u0010\u001a\u00020\u0011H\u0096@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0012J\b\u0010\u0013\u001a\u00020\u000fH\u0014J\b\u0010\u0014\u001a\u00020\u000fH\u0014J\u0010\u0010\u0015\u001a\u00020\u000f2\u0006\u0010\b\u001a\u00020\u0007H\u0016J\f\u0010\u0016\u001a\u00020\u000f*\u00020\u0017H\u0002R\u0016\u0010\f\u001a\n \r*\u0004\u0018\u00010\u00070\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0006\u001a\u0004\u0018\u00010\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lcom/android/permissioncontroller/permission/data/AttributionLabelLiveData;", "Lcom/android/permissioncontroller/permission/data/SmartAsyncMediatorLiveData;", "", "Lcom/android/permissioncontroller/permission/data/PackageBroadcastReceiver$PackageBroadcastListener;", "app", "Landroid/app/Application;", "attributionTag", "", "packageName", "user", "Landroid/os/UserHandle;", "(Landroid/app/Application;Ljava/lang/String;Ljava/lang/String;Landroid/os/UserHandle;)V", "LOG_TAG", "kotlin.jvm.PlatformType", "loadDataAndPostValue", "", "job", "Lkotlinx/coroutines/Job;", "(Lkotlinx/coroutines/Job;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onActive", "onInactive", "onPackageUpdate", "skipTag", "Lorg/xmlpull/v1/XmlPullParser;", "Companion"})
public final class AttributionLabelLiveData extends com.android.permissioncontroller.permission.data.SmartAsyncMediatorLiveData<java.lang.Integer> implements com.android.permissioncontroller.permission.data.PackageBroadcastReceiver.PackageBroadcastListener {
    private final java.lang.String LOG_TAG = null;
    private final android.app.Application app = null;
    private final java.lang.String attributionTag = null;
    private final java.lang.String packageName = null;
    private final android.os.UserHandle user = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.data.AttributionLabelLiveData.Companion Companion = null;
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Object loadDataAndPostValue(@org.jetbrains.annotations.NotNull()
    kotlinx.coroutines.Job job, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p1) {
        return null;
    }
    
    /**
     * Skip tag parser is currently pointing to (including all tags nested in it)
     */
    private final void skipTag(org.xmlpull.v1.XmlPullParser $this$skipTag) {
    }
    
    @java.lang.Override()
    protected void onActive() {
    }
    
    @java.lang.Override()
    protected void onInactive() {
    }
    
    @java.lang.Override()
    public void onPackageUpdate(@org.jetbrains.annotations.NotNull()
    java.lang.String packageName) {
    }
    
    private AttributionLabelLiveData(android.app.Application app, java.lang.String attributionTag, java.lang.String packageName, android.os.UserHandle user) {
        super(false, false);
    }
    
    /**
     * Repository for AttributionLiveData.
     * <p> Key value is a pair of string attribution tag, string package name, user handle, value is
     * its corresponding LiveData.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0007\b\u0086\u0003\u0018\u00002\"\u0012\u0018\u0012\u0016\u0012\u0006\u0012\u0004\u0018\u00010\u0003\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u00040\u0002\u0012\u0004\u0012\u00020\u00050\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0006J#\u0010\u0007\u001a\u00020\u00052\b\u0010\b\u001a\u0004\u0018\u00010\u00032\u0006\u0010\t\u001a\u00020\u00032\u0006\u0010\n\u001a\u00020\u0004H\u0086\u0002J$\u0010\u000b\u001a\u00020\u00052\u001a\u0010\f\u001a\u0016\u0012\u0006\u0012\u0004\u0018\u00010\u0003\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u00040\u0002H\u0014"}, d2 = {"Lcom/android/permissioncontroller/permission/data/AttributionLabelLiveData$Companion;", "Lcom/android/permissioncontroller/permission/data/DataRepository;", "Lkotlin/Triple;", "", "Landroid/os/UserHandle;", "Lcom/android/permissioncontroller/permission/data/AttributionLabelLiveData;", "()V", "get", "attributionTag", "packageName", "user", "newValue", "key"})
    public static final class Companion extends com.android.permissioncontroller.permission.data.DataRepository<kotlin.Triple<? extends java.lang.String, ? extends java.lang.String, ? extends android.os.UserHandle>, com.android.permissioncontroller.permission.data.AttributionLabelLiveData> {
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        protected com.android.permissioncontroller.permission.data.AttributionLabelLiveData newValue(@org.jetbrains.annotations.NotNull()
        kotlin.Triple<java.lang.String, java.lang.String, android.os.UserHandle> key) {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.permissioncontroller.permission.data.AttributionLabelLiveData get(@org.jetbrains.annotations.Nullable()
        java.lang.String attributionTag, @org.jetbrains.annotations.NotNull()
        java.lang.String packageName, @org.jetbrains.annotations.NotNull()
        android.os.UserHandle user) {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}