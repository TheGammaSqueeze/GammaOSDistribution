package com.android.permissioncontroller.permission.ui.handheld;

import android.app.Application;
import android.content.Context;
import android.os.UserHandle;
import android.widget.ImageButton;
import androidx.preference.PreferenceViewHolder;
import com.android.permissioncontroller.R;
import com.android.permissioncontroller.permission.ui.RemovablePref;

/**
 * A preference which represents an app that is unused. Has the app icon and label, as well as a
 * button to uninstall/disable the app, and a button to open the app.
 *
 * @param app The current application
 * @param packageName The name of the package whose icon this preference will retrieve
 * @param user The user whose package icon will be retrieved
 * @param context The current context
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000B\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\u0018\u00002\u00020\u00012\u00020\u0002B%\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u00a2\u0006\u0002\u0010\u000bJ\u0012\u0010\u0010\u001a\u00020\u00112\b\u0010\u0012\u001a\u0004\u0018\u00010\u000fH\u0002J\u0010\u0010\u0013\u001a\u00020\u00112\u0006\u0010\u0014\u001a\u00020\u0015H\u0016J\u0010\u0010\u0016\u001a\u00020\u00112\u0006\u0010\u0012\u001a\u00020\u000fH\u0016R\u0010\u0010\f\u001a\u0004\u0018\u00010\rX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u000e\u001a\u0004\u0018\u00010\u000fX\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/handheld/UnusedAppPreference;", "Lcom/android/permissioncontroller/permission/ui/handheld/SmartIconLoadPackagePermissionPreference;", "Lcom/android/permissioncontroller/permission/ui/RemovablePref;", "app", "Landroid/app/Application;", "packageName", "", "user", "Landroid/os/UserHandle;", "context", "Landroid/content/Context;", "(Landroid/app/Application;Ljava/lang/String;Landroid/os/UserHandle;Landroid/content/Context;)V", "removeButton", "Landroid/widget/ImageButton;", "removeRunnable", "Ljava/lang/Runnable;", "bindRemoveButtonRunnable", "", "runnable", "onBindViewHolder", "holder", "Landroidx/preference/PreferenceViewHolder;", "setRemoveClickRunnable"})
public final class UnusedAppPreference extends com.android.permissioncontroller.permission.ui.handheld.SmartIconLoadPackagePermissionPreference implements com.android.permissioncontroller.permission.ui.RemovablePref {
    private android.widget.ImageButton removeButton;
    private java.lang.Runnable removeRunnable;
    
    @java.lang.Override()
    public void onBindViewHolder(@org.jetbrains.annotations.NotNull()
    androidx.preference.PreferenceViewHolder holder) {
    }
    
    @java.lang.Override()
    public void setRemoveClickRunnable(@org.jetbrains.annotations.NotNull()
    java.lang.Runnable runnable) {
    }
    
    private final void bindRemoveButtonRunnable(java.lang.Runnable runnable) {
    }
    
    public UnusedAppPreference(@org.jetbrains.annotations.NotNull()
    android.app.Application app, @org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user, @org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super(null, null, null, null);
    }
}