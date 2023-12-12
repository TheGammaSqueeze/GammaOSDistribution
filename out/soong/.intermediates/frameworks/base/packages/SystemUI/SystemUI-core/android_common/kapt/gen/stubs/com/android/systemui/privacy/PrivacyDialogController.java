package com.android.systemui.privacy;

import android.Manifest;
import android.app.ActivityManager;
import android.app.Dialog;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.UserHandle;
import android.permission.PermGroupUsage;
import android.permission.PermissionManager;
import android.util.Log;
import androidx.annotation.MainThread;
import androidx.annotation.VisibleForTesting;
import androidx.annotation.WorkerThread;
import com.android.internal.logging.UiEventLogger;
import com.android.systemui.appops.AppOpsController;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Background;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.privacy.logging.PrivacyLogger;
import com.android.systemui.settings.UserTracker;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import java.util.concurrent.Executor;
import javax.inject.Inject;

/**
 * Controller for [PrivacyDialog].
 *
 * This controller shows and dismissed the dialog, as well as determining the information to show in
 * it.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u009c\u0001\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\r\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\b\u0007\u0018\u0000 72\u00020\u0001:\u000278Bc\b\u0017\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u0012\b\b\u0001\u0010\f\u001a\u00020\r\u0012\b\b\u0001\u0010\u000e\u001a\u00020\r\u0012\u0006\u0010\u000f\u001a\u00020\u0010\u0012\u0006\u0010\u0011\u001a\u00020\u0012\u0012\u0006\u0010\u0013\u001a\u00020\u0014\u0012\u0006\u0010\u0015\u001a\u00020\u0016\u00a2\u0006\u0002\u0010\u0017Bg\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u0012\u0006\u0010\f\u001a\u00020\r\u0012\u0006\u0010\u000e\u001a\u00020\r\u0012\u0006\u0010\u000f\u001a\u00020\u0010\u0012\u0006\u0010\u0011\u001a\u00020\u0012\u0012\u0006\u0010\u0013\u001a\u00020\u0014\u0012\u0006\u0010\u0015\u001a\u00020\u0016\u0012\b\b\u0001\u0010\u0018\u001a\u00020\u0019\u00a2\u0006\u0002\u0010\u001aJ\u0006\u0010\u001f\u001a\u00020 J\u001c\u0010!\u001a\b\u0012\u0004\u0012\u00020#0\"2\f\u0010$\u001a\b\u0012\u0004\u0012\u00020#0\"H\u0002J\u0014\u0010%\u001a\u0004\u0018\u00010&2\b\u0010\'\u001a\u0004\u0018\u00010&H\u0002J\u0018\u0010(\u001a\u00020)2\u0006\u0010*\u001a\u00020+2\u0006\u0010,\u001a\u00020-H\u0003J\u0012\u0010.\u001a\u0004\u0018\u00010&2\u0006\u0010/\u001a\u00020+H\u0002J\u000e\u00100\u001a\b\u0012\u0004\u0012\u0002010\"H\u0003J\u000e\u00102\u001a\u00020 2\u0006\u00103\u001a\u000204J\u0018\u00105\u001a\u00020 2\u0006\u0010*\u001a\u00020+2\u0006\u00106\u001a\u00020-H\u0003R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0013\u001a\u00020\u0014X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u001b\u001a\u0004\u0018\u00010\u001cX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0018\u001a\u00020\u0019X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0011\u001a\u00020\u0012X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001d\u001a\u00020\u001eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0015\u001a\u00020\u0016X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/privacy/PrivacyDialogController;", "", "permissionManager", "Landroid/permission/PermissionManager;", "packageManager", "Landroid/content/pm/PackageManager;", "privacyItemController", "Lcom/android/systemui/privacy/PrivacyItemController;", "userTracker", "Lcom/android/systemui/settings/UserTracker;", "activityStarter", "Lcom/android/systemui/plugins/ActivityStarter;", "backgroundExecutor", "Ljava/util/concurrent/Executor;", "uiExecutor", "privacyLogger", "Lcom/android/systemui/privacy/logging/PrivacyLogger;", "keyguardStateController", "Lcom/android/systemui/statusbar/policy/KeyguardStateController;", "appOpsController", "Lcom/android/systemui/appops/AppOpsController;", "uiEventLogger", "Lcom/android/internal/logging/UiEventLogger;", "(Landroid/permission/PermissionManager;Landroid/content/pm/PackageManager;Lcom/android/systemui/privacy/PrivacyItemController;Lcom/android/systemui/settings/UserTracker;Lcom/android/systemui/plugins/ActivityStarter;Ljava/util/concurrent/Executor;Ljava/util/concurrent/Executor;Lcom/android/systemui/privacy/logging/PrivacyLogger;Lcom/android/systemui/statusbar/policy/KeyguardStateController;Lcom/android/systemui/appops/AppOpsController;Lcom/android/internal/logging/UiEventLogger;)V", "dialogProvider", "Lcom/android/systemui/privacy/PrivacyDialogController$DialogProvider;", "(Landroid/permission/PermissionManager;Landroid/content/pm/PackageManager;Lcom/android/systemui/privacy/PrivacyItemController;Lcom/android/systemui/settings/UserTracker;Lcom/android/systemui/plugins/ActivityStarter;Ljava/util/concurrent/Executor;Ljava/util/concurrent/Executor;Lcom/android/systemui/privacy/logging/PrivacyLogger;Lcom/android/systemui/statusbar/policy/KeyguardStateController;Lcom/android/systemui/appops/AppOpsController;Lcom/android/internal/logging/UiEventLogger;Lcom/android/systemui/privacy/PrivacyDialogController$DialogProvider;)V", "dialog", "Landroid/app/Dialog;", "onDialogDismissed", "Lcom/android/systemui/privacy/PrivacyDialog$OnDialogDismissed;", "dismissDialog", "", "filterAndSelect", "", "Lcom/android/systemui/privacy/PrivacyDialog$PrivacyElement;", "list", "filterType", "Lcom/android/systemui/privacy/PrivacyType;", "type", "getLabelForPackage", "", "packageName", "", "uid", "", "permGroupToPrivacyType", "group", "permGroupUsage", "Landroid/permission/PermGroupUsage;", "showDialog", "context", "Landroid/content/Context;", "startActivity", "userId", "Companion", "DialogProvider"})
@com.android.systemui.dagger.SysUISingleton()
public final class PrivacyDialogController {
    private android.app.Dialog dialog;
    private final com.android.systemui.privacy.PrivacyDialog.OnDialogDismissed onDialogDismissed = null;
    private final android.permission.PermissionManager permissionManager = null;
    private final android.content.pm.PackageManager packageManager = null;
    private final com.android.systemui.privacy.PrivacyItemController privacyItemController = null;
    private final com.android.systemui.settings.UserTracker userTracker = null;
    private final com.android.systemui.plugins.ActivityStarter activityStarter = null;
    private final java.util.concurrent.Executor backgroundExecutor = null;
    private final java.util.concurrent.Executor uiExecutor = null;
    private final com.android.systemui.privacy.logging.PrivacyLogger privacyLogger = null;
    private final com.android.systemui.statusbar.policy.KeyguardStateController keyguardStateController = null;
    private final com.android.systemui.appops.AppOpsController appOpsController = null;
    private final com.android.internal.logging.UiEventLogger uiEventLogger = null;
    private final com.android.systemui.privacy.PrivacyDialogController.DialogProvider dialogProvider = null;
    private static final java.lang.String TAG = "PrivacyDialogController";
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.privacy.PrivacyDialogController.Companion Companion = null;
    
    @androidx.annotation.MainThread()
    private final void startActivity(java.lang.String packageName, int userId) {
    }
    
    @androidx.annotation.WorkerThread()
    private final java.util.List<android.permission.PermGroupUsage> permGroupUsage() {
        return null;
    }
    
    /**
     * Show the [PrivacyDialog]
     *
     * This retrieves the permission usage from [PermissionManager] and creates a new
     * [PrivacyDialog] with a list of [PrivacyDialog.PrivacyElement] to show.
     *
     * This list will be filtered by [filterAndSelect]. Only types available by
     * [PrivacyItemController] will be shown.
     *
     * @param context A context to use to create the dialog.
     * @see filterAndSelect
     */
    public final void showDialog(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
    }
    
    /**
     * Dismisses the dialog
     */
    public final void dismissDialog() {
    }
    
    @androidx.annotation.WorkerThread()
    private final java.lang.CharSequence getLabelForPackage(java.lang.String packageName, int uid) {
        return null;
    }
    
    private final com.android.systemui.privacy.PrivacyType permGroupToPrivacyType(java.lang.String group) {
        return null;
    }
    
    private final com.android.systemui.privacy.PrivacyType filterType(com.android.systemui.privacy.PrivacyType type) {
        return null;
    }
    
    /**
     * Filters the list of elements to show.
     *
     * For each privacy type, it'll return all active elements. If there are no active elements,
     * it'll return the most recent access
     */
    private final java.util.List<com.android.systemui.privacy.PrivacyDialog.PrivacyElement> filterAndSelect(java.util.List<com.android.systemui.privacy.PrivacyDialog.PrivacyElement> list) {
        return null;
    }
    
    public PrivacyDialogController(@org.jetbrains.annotations.NotNull()
    android.permission.PermissionManager permissionManager, @org.jetbrains.annotations.NotNull()
    android.content.pm.PackageManager packageManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.privacy.PrivacyItemController privacyItemController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.settings.UserTracker userTracker, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.ActivityStarter activityStarter, @org.jetbrains.annotations.NotNull()
    java.util.concurrent.Executor backgroundExecutor, @org.jetbrains.annotations.NotNull()
    java.util.concurrent.Executor uiExecutor, @org.jetbrains.annotations.NotNull()
    com.android.systemui.privacy.logging.PrivacyLogger privacyLogger, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.KeyguardStateController keyguardStateController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.appops.AppOpsController appOpsController, @org.jetbrains.annotations.NotNull()
    com.android.internal.logging.UiEventLogger uiEventLogger, @org.jetbrains.annotations.NotNull()
    @androidx.annotation.VisibleForTesting()
    com.android.systemui.privacy.PrivacyDialogController.DialogProvider dialogProvider) {
        super();
    }
    
    @javax.inject.Inject()
    public PrivacyDialogController(@org.jetbrains.annotations.NotNull()
    android.permission.PermissionManager permissionManager, @org.jetbrains.annotations.NotNull()
    android.content.pm.PackageManager packageManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.privacy.PrivacyItemController privacyItemController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.settings.UserTracker userTracker, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.ActivityStarter activityStarter, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Background()
    java.util.concurrent.Executor backgroundExecutor, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    java.util.concurrent.Executor uiExecutor, @org.jetbrains.annotations.NotNull()
    com.android.systemui.privacy.logging.PrivacyLogger privacyLogger, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.KeyguardStateController keyguardStateController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.appops.AppOpsController appOpsController, @org.jetbrains.annotations.NotNull()
    com.android.internal.logging.UiEventLogger uiEventLogger) {
        super();
    }
    
    /**
     * Interface to create a [PrivacyDialog].
     *
     * Can be used to inject a mock creator.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00000\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0010\b\n\u0002\u0010\u0002\bf\u0018\u00002\u00020\u0001J8\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\f\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\b0\u00072\u0018\u0010\t\u001a\u0014\u0012\u0004\u0012\u00020\u000b\u0012\u0004\u0012\u00020\f\u0012\u0004\u0012\u00020\r0\nH&"}, d2 = {"Lcom/android/systemui/privacy/PrivacyDialogController$DialogProvider;", "", "makeDialog", "Lcom/android/systemui/privacy/PrivacyDialog;", "context", "Landroid/content/Context;", "list", "", "Lcom/android/systemui/privacy/PrivacyDialog$PrivacyElement;", "starter", "Lkotlin/Function2;", "", "", ""})
    public static abstract interface DialogProvider {
        
        /**
         * Create a [PrivacyDialog].
         */
        @org.jetbrains.annotations.NotNull()
        public abstract com.android.systemui.privacy.PrivacyDialog makeDialog(@org.jetbrains.annotations.NotNull()
        android.content.Context context, @org.jetbrains.annotations.NotNull()
        java.util.List<com.android.systemui.privacy.PrivacyDialog.PrivacyElement> list, @org.jetbrains.annotations.NotNull()
        kotlin.jvm.functions.Function2<? super java.lang.String, ? super java.lang.Integer, kotlin.Unit> starter);
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/privacy/PrivacyDialogController$Companion;", "", "()V", "TAG", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}