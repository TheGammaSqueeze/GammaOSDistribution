package com.android.permissioncontroller.permission.ui.handheld;

import android.app.Application;
import android.content.Context;
import android.os.UserHandle;
import android.text.TextUtils;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;
import androidx.preference.AndroidResources;
import androidx.preference.Preference;
import androidx.preference.PreferenceViewHolder;
import com.android.permissioncontroller.R;
import com.android.permissioncontroller.permission.utils.KotlinUtils;

/**
 * A Preference representing a package for a user, which loads and displays its icon only upon
 * being bound to a viewHolder. This lets us synchronously load package icons and labels, while
 * still displaying the PermissionAppsFragment instantly.
 *
 * @param app The current application
 * @param packageName The name of the package whose icon this preference will retrieve
 * @param user The user whose package icon will be retrieved
 * @param context The current context
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00008\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\r\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\b\u0016\u0018\u00002\u00020\u0001B%\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJ\u0010\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u0010H\u0016J\u000e\u0010\u0011\u001a\u00020\u000e2\u0006\u0010\u0012\u001a\u00020\fR\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u000b\u001a\u0004\u0018\u00010\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/handheld/SmartIconLoadPackagePermissionPreference;", "Landroidx/preference/Preference;", "app", "Landroid/app/Application;", "packageName", "", "user", "Landroid/os/UserHandle;", "context", "Landroid/content/Context;", "(Landroid/app/Application;Ljava/lang/String;Landroid/os/UserHandle;Landroid/content/Context;)V", "titleContentDescription", "", "onBindViewHolder", "", "holder", "Landroidx/preference/PreferenceViewHolder;", "setTitleContentDescription", "contentDescription"})
public class SmartIconLoadPackagePermissionPreference extends androidx.preference.Preference {
    private java.lang.CharSequence titleContentDescription;
    private final android.app.Application app = null;
    private final java.lang.String packageName = null;
    private final android.os.UserHandle user = null;
    
    /**
     * Loads the package's badged icon upon being bound to a viewholder. This allows us to load
     * icons synchronously, because we only load the icons that are visible on the screen.
     */
    @java.lang.Override()
    public void onBindViewHolder(@org.jetbrains.annotations.NotNull()
    androidx.preference.PreferenceViewHolder holder) {
    }
    
    public final void setTitleContentDescription(@org.jetbrains.annotations.NotNull()
    java.lang.CharSequence contentDescription) {
    }
    
    public SmartIconLoadPackagePermissionPreference(@org.jetbrains.annotations.NotNull()
    android.app.Application app, @org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user, @org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super(null, null, 0, 0);
    }
}