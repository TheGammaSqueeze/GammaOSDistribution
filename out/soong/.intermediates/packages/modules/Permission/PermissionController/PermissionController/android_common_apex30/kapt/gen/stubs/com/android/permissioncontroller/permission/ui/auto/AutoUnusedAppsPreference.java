package com.android.permissioncontroller.permission.ui.auto;

import android.app.Application;
import android.content.Context;
import android.os.UserHandle;
import com.android.car.ui.preference.CarUiTwoActionIconPreference;
import com.android.permissioncontroller.R;
import com.android.permissioncontroller.permission.ui.RemovablePref;
import com.android.permissioncontroller.permission.utils.KotlinUtils;

/**
 * A Auto-styled preference which represents an app that has been auto revoked. Has the app icon and
 * label, as well as a button to uninstall/disable the app, and a button to open the app.
 *
 * @param app The current application
 * @param packageName The name of the package whose icon this preference will retrieve
 * @param user The user whose package icon will be retrieved
 * @param context The current context
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\u0018\u00002\u00020\u00012\u00020\u0002B%\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u00a2\u0006\u0002\u0010\u000bJ\u0010\u0010\f\u001a\u00020\r2\u0006\u0010\u000e\u001a\u00020\u000fH\u0016"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/auto/AutoUnusedAppsPreference;", "Lcom/android/car/ui/preference/CarUiTwoActionIconPreference;", "Lcom/android/permissioncontroller/permission/ui/RemovablePref;", "app", "Landroid/app/Application;", "packageName", "", "user", "Landroid/os/UserHandle;", "context", "Landroid/content/Context;", "(Landroid/app/Application;Ljava/lang/String;Landroid/os/UserHandle;Landroid/content/Context;)V", "setRemoveClickRunnable", "", "runnable", "Ljava/lang/Runnable;"})
public final class AutoUnusedAppsPreference extends com.android.car.ui.preference.CarUiTwoActionIconPreference implements com.android.permissioncontroller.permission.ui.RemovablePref {
    
    @java.lang.Override()
    public void setRemoveClickRunnable(@org.jetbrains.annotations.NotNull()
    java.lang.Runnable runnable) {
    }
    
    public AutoUnusedAppsPreference(@org.jetbrains.annotations.NotNull()
    android.app.Application app, @org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user, @org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super(null, null, 0, 0);
    }
}