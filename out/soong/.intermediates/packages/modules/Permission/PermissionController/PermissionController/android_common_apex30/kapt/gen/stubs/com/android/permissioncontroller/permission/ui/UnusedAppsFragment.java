package com.android.permissioncontroller.permission.ui;

import android.Manifest.permission_group;
import android.app.AlertDialog;
import android.app.Application;
import android.app.Dialog;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.os.UserHandle;
import android.util.Log;
import androidx.fragment.app.DialogFragment;
import androidx.fragment.app.Fragment;
import androidx.lifecycle.Observer;
import androidx.lifecycle.ViewModelProvider;
import androidx.preference.Preference;
import androidx.preference.PreferenceCategory;
import androidx.preference.PreferenceFragmentCompat;
import androidx.preference.PreferenceScreen;
import com.android.permissioncontroller.R;
import com.android.permissioncontroller.permission.ui.model.UnusedAppsViewModel;
import com.android.permissioncontroller.permission.ui.model.UnusedAppsViewModel.Months;
import com.android.permissioncontroller.permission.ui.model.UnusedAppsViewModel.UnusedPackageInfo;
import com.android.permissioncontroller.permission.ui.model.UnusedAppsViewModelFactory;
import com.android.permissioncontroller.permission.utils.KotlinUtils;
import kotlinx.coroutines.GlobalScope;
import java.text.Collator;

/**
 * A fragment displaying all applications that are unused as well as the option to remove them
 * and to open them.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000t\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\t\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010 \n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010$\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\u0018\u0000 ,*\u0012\b\u0000\u0010\u0001*\u00020\u0002*\b\u0012\u0004\u0012\u0002H\u00040\u0003*\f\b\u0001\u0010\u0004*\u00020\u0005*\u00020\u00062\u00020\u0007:\u0003,-.B\u0005\u00a2\u0006\u0002\u0010\bJ\u0018\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u00052\u0006\u0010\u0014\u001a\u00020\u0005H\u0002J\u0018\u0010\u0015\u001a\u00020\u00162\u0006\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\u001aH\u0002J\u0018\u0010\u001b\u001a\u00020\u00182\u0006\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\u001aH\u0002J\b\u0010\u001c\u001a\u00020\u0016H\u0002J\u0016\u0010\u001d\u001a\u00020\u00182\f\u0010\u001e\u001a\b\u0012\u0004\u0012\u00020\u00180\u001fH\u0002J\u0012\u0010 \u001a\u00020\u00162\b\u0010!\u001a\u0004\u0018\u00010\"H\u0016J\u0012\u0010#\u001a\u00020\u00162\b\u0010!\u001a\u0004\u0018\u00010\"H\u0016J\b\u0010$\u001a\u00020\u0016H\u0016J\r\u0010%\u001a\u00028\u0000H\u0002\u00a2\u0006\u0002\u0010&J\"\u0010\'\u001a\u00020\u00162\u0018\u0010(\u001a\u0014\u0012\u0004\u0012\u00020*\u0012\n\u0012\b\u0012\u0004\u0012\u00020+0\u001f0)H\u0002R\u000e\u0010\t\u001a\u00020\nX\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082.\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/UnusedAppsFragment;", "PF", "Landroidx/preference/PreferenceFragmentCompat;", "Lcom/android/permissioncontroller/permission/ui/UnusedAppsFragment$Parent;", "UnusedAppPref", "Landroidx/preference/Preference;", "Lcom/android/permissioncontroller/permission/ui/RemovablePref;", "Landroidx/fragment/app/Fragment;", "()V", "collator", "Ljava/text/Collator;", "isFirstLoad", "", "sessionId", "", "viewModel", "Lcom/android/permissioncontroller/permission/ui/model/UnusedAppsViewModel;", "comparePreference", "", "lhs", "rhs", "createDisableDialog", "", "packageName", "", "user", "Landroid/os/UserHandle;", "createKey", "createPreferenceScreen", "getMostImportantGroup", "groupNames", "", "onActivityCreated", "savedInstanceState", "Landroid/os/Bundle;", "onCreate", "onStart", "requirePreferenceFragment", "()Landroidx/preference/PreferenceFragmentCompat;", "updatePackages", "categorizedPackages", "", "Lcom/android/permissioncontroller/permission/ui/model/UnusedAppsViewModel$Months;", "Lcom/android/permissioncontroller/permission/ui/model/UnusedAppsViewModel$UnusedPackageInfo;", "Companion", "DisableDialog", "Parent"})
public final class UnusedAppsFragment<PF extends androidx.preference.PreferenceFragmentCompat & com.android.permissioncontroller.permission.ui.UnusedAppsFragment.Parent<UnusedAppPref>, UnusedAppPref extends androidx.preference.Preference & com.android.permissioncontroller.permission.ui.RemovablePref> extends androidx.fragment.app.Fragment {
    private com.android.permissioncontroller.permission.ui.model.UnusedAppsViewModel viewModel;
    private java.text.Collator collator;
    private long sessionId = 0L;
    private boolean isFirstLoad = false;
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String INFO_MSG_CATEGORY = "info_msg_category";
    private static final long SHOW_LOAD_DELAY_MS = 200L;
    private static final java.lang.String INFO_MSG_KEY = "info_msg";
    private static final float ELEVATION_HIGH = 8.0F;
    private static final java.lang.String LOG_TAG = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.ui.UnusedAppsFragment.Companion Companion = null;
    
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
    
    private final PF requirePreferenceFragment() {
        return null;
    }
    
    /**
     * Create [PreferenceScreen] in the parent fragment.
     */
    private final void createPreferenceScreen() {
    }
    
    private final void updatePackages(java.util.Map<com.android.permissioncontroller.permission.ui.model.UnusedAppsViewModel.Months, ? extends java.util.List<com.android.permissioncontroller.permission.ui.model.UnusedAppsViewModel.UnusedPackageInfo>> categorizedPackages) {
    }
    
    private final int comparePreference(androidx.preference.Preference lhs, androidx.preference.Preference rhs) {
        return 0;
    }
    
    private final java.lang.String createKey(java.lang.String packageName, android.os.UserHandle user) {
        return null;
    }
    
    private final java.lang.String getMostImportantGroup(java.util.List<java.lang.String> groupNames) {
        return null;
    }
    
    private final void createDisableDialog(java.lang.String packageName, android.os.UserHandle user) {
    }
    
    public UnusedAppsFragment() {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public static final <PF extends androidx.preference.PreferenceFragmentCompat & com.android.permissioncontroller.permission.ui.UnusedAppsFragment.Parent<UnusedAppPref>, UnusedAppPref extends androidx.preference.Preference & com.android.permissioncontroller.permission.ui.RemovablePref>com.android.permissioncontroller.permission.ui.UnusedAppsFragment<PF, UnusedAppPref> newInstance() {
        return null;
    }
    
    /**
     * Create the args needed for this fragment
     *
     * @param sessionId The current session Id
     *
     * @return A bundle containing the session Id
     */
    @org.jetbrains.annotations.NotNull()
    public static final android.os.Bundle createArgs(long sessionId) {
        return null;
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0012\u0010\u0003\u001a\u00020\u00042\b\u0010\u0005\u001a\u0004\u0018\u00010\u0006H\u0016"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/UnusedAppsFragment$DisableDialog;", "Landroidx/fragment/app/DialogFragment;", "()V", "onCreateDialog", "Landroid/app/Dialog;", "savedInstanceState", "Landroid/os/Bundle;"})
    public static final class DisableDialog extends androidx.fragment.app.DialogFragment {
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public android.app.Dialog onCreateDialog(@org.jetbrains.annotations.Nullable()
        android.os.Bundle savedInstanceState) {
            return null;
        }
        
        public DisableDialog() {
            super();
        }
    }
    
    /**
     * Interface that the parent fragment must implement.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000D\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0005\n\u0002\u0010\r\bf\u0018\u0000*\f\b\u0002\u0010\u0001*\u00020\u0002*\u00020\u00032\u00020\u0004J\u0010\u0010\u0005\u001a\u00020\u00022\u0006\u0010\u0006\u001a\u00020\u0007H&J-\u0010\b\u001a\u00028\u00022\u0006\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\u000e2\u0006\u0010\u0006\u001a\u00020\u0007H&\u00a2\u0006\u0002\u0010\u000fJ\u0010\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u0012\u001a\u00020\u0013H&J\u0018\u0010\u0014\u001a\u00020\u00112\u0006\u0010\u0015\u001a\u00020\u00132\u0006\u0010\u0016\u001a\u00020\u0013H&J\u0010\u0010\u0017\u001a\u00020\u00112\u0006\u0010\u0018\u001a\u00020\u0019H&"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/UnusedAppsFragment$Parent;", "UnusedAppPref", "Landroidx/preference/Preference;", "Lcom/android/permissioncontroller/permission/ui/RemovablePref;", "", "createFooterPreference", "context", "Landroid/content/Context;", "createUnusedAppPref", "app", "Landroid/app/Application;", "packageName", "", "user", "Landroid/os/UserHandle;", "(Landroid/app/Application;Ljava/lang/String;Landroid/os/UserHandle;Landroid/content/Context;)Landroidx/preference/Preference;", "setEmptyState", "", "empty", "", "setLoadingState", "loading", "animate", "setTitle", "title", ""})
    public static abstract interface Parent<UnusedAppPref extends androidx.preference.Preference & com.android.permissioncontroller.permission.ui.RemovablePref> {
        
        /**
         * Set the title of the current settings page.
         *
         * @param title the title of the current settings page
         */
        public abstract void setTitle(@org.jetbrains.annotations.NotNull()
        java.lang.CharSequence title);
        
        /**
         * Creates the footer preference that explains why permissions have been re-used and how an
         * app can re-request them.
         *
         * @param context The current context
         */
        @org.jetbrains.annotations.NotNull()
        public abstract androidx.preference.Preference createFooterPreference(@org.jetbrains.annotations.NotNull()
        android.content.Context context);
        
        /**
         * Sets the loading state of the view.
         *
         * @param loading whether the view is loading
         * @param animate whether the load state should change with a fade animation
         */
        public abstract void setLoadingState(boolean loading, boolean animate);
        
        /**
         * Creates a preference which represents an app that is unused. Has the app icon and label,
         * as well as a button to uninstall/disable the app, and a button to open the app.
         *
         * @param app The current application
         * @param packageName The name of the package whose icon this preference will retrieve
         * @param user The user whose package icon will be retrieved
         * @param context The current context
         */
        @org.jetbrains.annotations.NotNull()
        public abstract UnusedAppPref createUnusedAppPref(@org.jetbrains.annotations.NotNull()
        android.app.Application app, @org.jetbrains.annotations.NotNull()
        java.lang.String packageName, @org.jetbrains.annotations.NotNull()
        android.os.UserHandle user, @org.jetbrains.annotations.NotNull()
        android.content.Context context);
        
        /**
         * Updates the state based on whether the content is empty.
         *
         * @param empty whether the content is empty
         */
        public abstract void setEmptyState(boolean empty);
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000@\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u0007\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0004\n\u0002\u0010\t\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\f\u001a\u00020\r2\u0006\u0010\u000e\u001a\u00020\u000bH\u0007J6\u0010\u000f\u001a\u000e\u0012\u0004\u0012\u0002H\u0011\u0012\u0004\u0012\u0002H\u00120\u0010\"\u0012\b\u0002\u0010\u0011*\u00020\u0013*\b\u0012\u0004\u0012\u0002H\u00120\u0014\"\f\b\u0003\u0010\u0012*\u00020\u0015*\u00020\u0016H\u0007R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\u0006X\u0082T\u00a2\u0006\u0002\n\u0000R\u0016\u0010\b\u001a\n \t*\u0004\u0018\u00010\u00060\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/UnusedAppsFragment$Companion;", "", "()V", "ELEVATION_HIGH", "", "INFO_MSG_CATEGORY", "", "INFO_MSG_KEY", "LOG_TAG", "kotlin.jvm.PlatformType", "SHOW_LOAD_DELAY_MS", "", "createArgs", "Landroid/os/Bundle;", "sessionId", "newInstance", "Lcom/android/permissioncontroller/permission/ui/UnusedAppsFragment;", "PF", "UnusedAppPref", "Landroidx/preference/PreferenceFragmentCompat;", "Lcom/android/permissioncontroller/permission/ui/UnusedAppsFragment$Parent;", "Landroidx/preference/Preference;", "Lcom/android/permissioncontroller/permission/ui/RemovablePref;"})
    public static final class Companion {
        
        @org.jetbrains.annotations.NotNull()
        public final <PF extends androidx.preference.PreferenceFragmentCompat & com.android.permissioncontroller.permission.ui.UnusedAppsFragment.Parent<UnusedAppPref>, UnusedAppPref extends androidx.preference.Preference & com.android.permissioncontroller.permission.ui.RemovablePref>com.android.permissioncontroller.permission.ui.UnusedAppsFragment<PF, UnusedAppPref> newInstance() {
            return null;
        }
        
        /**
         * Create the args needed for this fragment
         *
         * @param sessionId The current session Id
         *
         * @return A bundle containing the session Id
         */
        @org.jetbrains.annotations.NotNull()
        public final android.os.Bundle createArgs(long sessionId) {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}