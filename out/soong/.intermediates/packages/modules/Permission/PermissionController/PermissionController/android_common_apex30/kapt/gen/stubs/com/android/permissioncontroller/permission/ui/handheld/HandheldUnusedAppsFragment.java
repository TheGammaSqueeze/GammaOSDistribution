package com.android.permissioncontroller.permission.ui.handheld;

import android.app.Application;
import android.content.Context;
import android.os.Bundle;
import android.os.UserHandle;
import android.view.MenuItem;
import androidx.preference.Preference;
import androidx.preference.PreferenceCategory;
import com.android.permissioncontroller.R;
import com.android.permissioncontroller.permission.ui.UnusedAppsFragment;

/**
 * Handheld wrapper, with customizations, around [UnusedAppsFragment].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\\\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\b\n\u0002\u0010\r\n\u0000\u0018\u0000 $2\u00020\u00012\b\u0012\u0004\u0012\u00020\u00030\u0002:\u0001$B\u0005\u00a2\u0006\u0002\u0010\u0004J\u0010\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bH\u0016J(\u0010\t\u001a\u00020\u00032\u0006\u0010\n\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\r2\u0006\u0010\u000e\u001a\u00020\u000f2\u0006\u0010\u0007\u001a\u00020\bH\u0016J\b\u0010\u0010\u001a\u00020\u0011H\u0016J\u0012\u0010\u0012\u001a\u00020\u00132\b\u0010\u0014\u001a\u0004\u0018\u00010\u0015H\u0016J\u0012\u0010\u0016\u001a\u00020\u00132\b\u0010\u0014\u001a\u0004\u0018\u00010\u0015H\u0016J\u0010\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\u001aH\u0016J\b\u0010\u001b\u001a\u00020\u0013H\u0016J\u0010\u0010\u001c\u001a\u00020\u00132\u0006\u0010\u001d\u001a\u00020\u0018H\u0016J\u0018\u0010\u001e\u001a\u00020\u00132\u0006\u0010\u001f\u001a\u00020\u00182\u0006\u0010 \u001a\u00020\u0018H\u0016J\u0010\u0010!\u001a\u00020\u00132\u0006\u0010\"\u001a\u00020#H\u0016"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/handheld/HandheldUnusedAppsFragment;", "Lcom/android/permissioncontroller/permission/ui/handheld/PermissionsFrameFragment;", "Lcom/android/permissioncontroller/permission/ui/UnusedAppsFragment$Parent;", "Lcom/android/permissioncontroller/permission/ui/handheld/UnusedAppPreference;", "()V", "createFooterPreference", "Landroidx/preference/Preference;", "context", "Landroid/content/Context;", "createUnusedAppPref", "app", "Landroid/app/Application;", "packageName", "", "user", "Landroid/os/UserHandle;", "getEmptyViewString", "", "onActivityCreated", "", "savedInstanceState", "Landroid/os/Bundle;", "onCreate", "onOptionsItemSelected", "", "item", "Landroid/view/MenuItem;", "onStart", "setEmptyState", "empty", "setLoadingState", "loading", "animate", "setTitle", "title", "", "Companion"})
public final class HandheldUnusedAppsFragment extends com.android.permissioncontroller.permission.ui.handheld.PermissionsFrameFragment implements com.android.permissioncontroller.permission.ui.UnusedAppsFragment.Parent<com.android.permissioncontroller.permission.ui.handheld.UnusedAppPreference> {
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.ui.handheld.HandheldUnusedAppsFragment.Companion Companion = null;
    
    @java.lang.Override()
    public void onCreate(@org.jetbrains.annotations.Nullable()
    android.os.Bundle savedInstanceState) {
    }
    
    @java.lang.Override()
    public void onStart() {
    }
    
    @java.lang.Override()
    public void onActivityCreated(@org.jetbrains.annotations.Nullable()
    android.os.Bundle savedInstanceState) {
    }
    
    @java.lang.Override()
    public boolean onOptionsItemSelected(@org.jetbrains.annotations.NotNull()
    android.view.MenuItem item) {
        return false;
    }
    
    @java.lang.Override()
    public int getEmptyViewString() {
        return 0;
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
    public com.android.permissioncontroller.permission.ui.handheld.UnusedAppPreference createUnusedAppPref(@org.jetbrains.annotations.NotNull()
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
    
    public HandheldUnusedAppsFragment() {
        super();
    }
    
    /**
     * Create a new instance of this fragment.
     */
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.ui.handheld.HandheldUnusedAppsFragment newInstance() {
        return null;
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\b\u0010\u0003\u001a\u00020\u0004H\u0007"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/handheld/HandheldUnusedAppsFragment$Companion;", "", "()V", "newInstance", "Lcom/android/permissioncontroller/permission/ui/handheld/HandheldUnusedAppsFragment;"})
    public static final class Companion {
        
        /**
         * Create a new instance of this fragment.
         */
        @org.jetbrains.annotations.NotNull()
        public final com.android.permissioncontroller.permission.ui.handheld.HandheldUnusedAppsFragment newInstance() {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}