package com.android.permissioncontroller.permission.ui.auto;

import android.app.Application;
import android.content.Context;
import android.os.Bundle;
import android.os.UserHandle;
import androidx.preference.Preference;
import androidx.preference.PreferenceCategory;
import com.android.permissioncontroller.R;
import com.android.permissioncontroller.auto.AutoSettingsFrameFragment;
import com.android.permissioncontroller.permission.ui.UnusedAppsFragment;
import com.android.car.ui.utils.ViewUtils;
import com.android.car.ui.utils.ViewUtils.LazyLayoutView;

/**
 * Auto wrapper, with customizations, around [UnusedAppsFragment].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000P\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u000b\n\u0002\b\u0005\n\u0002\u0010\r\n\u0000\u0018\u0000  2\u00020\u00012\b\u0012\u0004\u0012\u00020\u00030\u0002:\u0001 B\u0005\u00a2\u0006\u0002\u0010\u0004J\u0010\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bH\u0016J\b\u0010\t\u001a\u00020\u0006H\u0002J(\u0010\n\u001a\u00020\u00032\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0007\u001a\u00020\bH\u0016J\u0012\u0010\u0011\u001a\u00020\u00122\b\u0010\u0013\u001a\u0004\u0018\u00010\u0014H\u0016J\u001c\u0010\u0015\u001a\u00020\u00122\b\u0010\u0013\u001a\u0004\u0018\u00010\u00142\b\u0010\u0016\u001a\u0004\u0018\u00010\u000eH\u0016J\u0010\u0010\u0017\u001a\u00020\u00122\u0006\u0010\u0018\u001a\u00020\u0019H\u0016J\u0018\u0010\u001a\u001a\u00020\u00122\u0006\u0010\u001b\u001a\u00020\u00192\u0006\u0010\u001c\u001a\u00020\u0019H\u0016J\u0010\u0010\u001d\u001a\u00020\u00122\u0006\u0010\u001e\u001a\u00020\u001fH\u0016"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/auto/AutoUnusedAppsFragment;", "Lcom/android/permissioncontroller/auto/AutoSettingsFrameFragment;", "Lcom/android/permissioncontroller/permission/ui/UnusedAppsFragment$Parent;", "Lcom/android/permissioncontroller/permission/ui/auto/AutoUnusedAppsPreference;", "()V", "createFooterPreference", "Landroidx/preference/Preference;", "context", "Landroid/content/Context;", "createNoUnusedAppsPreference", "createUnusedAppPref", "app", "Landroid/app/Application;", "packageName", "", "user", "Landroid/os/UserHandle;", "onActivityCreated", "", "savedInstanceState", "Landroid/os/Bundle;", "onCreatePreferences", "rootKey", "setEmptyState", "empty", "", "setLoadingState", "loading", "animate", "setTitle", "title", "", "Companion"})
public final class AutoUnusedAppsFragment extends com.android.permissioncontroller.auto.AutoSettingsFrameFragment implements com.android.permissioncontroller.permission.ui.UnusedAppsFragment.Parent<com.android.permissioncontroller.permission.ui.auto.AutoUnusedAppsPreference> {
    private static final java.lang.String UNUSED_PREFERENCE_KEY = "unused_pref_row_key";
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.ui.auto.AutoUnusedAppsFragment.Companion Companion = null;
    
    @java.lang.Override()
    public void onCreatePreferences(@org.jetbrains.annotations.Nullable()
    android.os.Bundle savedInstanceState, @org.jetbrains.annotations.Nullable()
    java.lang.String rootKey) {
    }
    
    @java.lang.Override()
    public void onActivityCreated(@org.jetbrains.annotations.Nullable()
    android.os.Bundle savedInstanceState) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public androidx.preference.Preference createFooterPreference(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        return null;
    }
    
    @java.lang.Override()
    public void setLoadingState(boolean loading, boolean animate) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public com.android.permissioncontroller.permission.ui.auto.AutoUnusedAppsPreference createUnusedAppPref(@org.jetbrains.annotations.NotNull()
    android.app.Application app, @org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user, @org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        return null;
    }
    
    @java.lang.Override()
    public void setTitle(@org.jetbrains.annotations.NotNull()
    java.lang.CharSequence title) {
    }
    
    @java.lang.Override()
    public void setEmptyState(boolean empty) {
    }
    
    private final androidx.preference.Preference createNoUnusedAppsPreference() {
        return null;
    }
    
    public AutoUnusedAppsFragment() {
        super();
    }
    
    /**
     * Create a new instance of this fragment.
     */
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.ui.auto.AutoUnusedAppsFragment newInstance() {
        return null;
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\b\u0010\u0005\u001a\u00020\u0006H\u0007R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/auto/AutoUnusedAppsFragment$Companion;", "", "()V", "UNUSED_PREFERENCE_KEY", "", "newInstance", "Lcom/android/permissioncontroller/permission/ui/auto/AutoUnusedAppsFragment;"})
    public static final class Companion {
        
        /**
         * Create a new instance of this fragment.
         */
        @org.jetbrains.annotations.NotNull()
        public final com.android.permissioncontroller.permission.ui.auto.AutoUnusedAppsFragment newInstance() {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}