package com.android.systemui.statusbar.lockscreen;

import android.app.PendingIntent;
import android.app.smartspace.SmartspaceConfig;
import android.app.smartspace.SmartspaceManager;
import android.app.smartspace.SmartspaceSession;
import android.app.smartspace.SmartspaceTarget;
import android.content.ContentResolver;
import android.content.Context;
import android.content.Intent;
import android.database.ContentObserver;
import android.net.Uri;
import android.os.Handler;
import android.os.UserHandle;
import android.provider.Settings;
import android.util.Log;
import android.view.View;
import android.view.ViewGroup;
import com.android.settingslib.Utils;
import com.android.systemui.R;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.BcSmartspaceDataPlugin;
import com.android.systemui.plugins.BcSmartspaceDataPlugin.SmartspaceTargetListener;
import com.android.systemui.plugins.BcSmartspaceDataPlugin.SmartspaceView;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.settings.UserTracker;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.statusbar.policy.DeviceProvisionedController;
import com.android.systemui.util.concurrency.Execution;
import com.android.systemui.util.settings.SecureSettings;
import java.lang.RuntimeException;
import java.util.Optional;
import java.util.concurrent.Executor;
import javax.inject.Inject;

/**
 * Controller for managing the smartspace view on the lockscreen
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u00d8\u0001\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010#\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0007\b\u0007\u0018\u0000 S2\u00020\u0001:\u0001SB\u0089\u0001\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u0012\u0006\u0010\f\u001a\u00020\r\u0012\u0006\u0010\u000e\u001a\u00020\u000f\u0012\u0006\u0010\u0010\u001a\u00020\u0011\u0012\u0006\u0010\u0012\u001a\u00020\u0013\u0012\u0006\u0010\u0014\u001a\u00020\u0015\u0012\u0006\u0010\u0016\u001a\u00020\u0017\u0012\u0006\u0010\u0018\u001a\u00020\u0019\u0012\b\b\u0001\u0010\u001a\u001a\u00020\u001b\u0012\b\b\u0001\u0010\u001c\u001a\u00020\u001d\u0012\f\u0010\u001e\u001a\b\u0012\u0004\u0012\u00020 0\u001f\u00a2\u0006\u0002\u0010!J\u000e\u0010?\u001a\u00020@2\u0006\u0010A\u001a\u00020BJ\u0010\u0010C\u001a\u0004\u0018\u00010D2\u0006\u0010E\u001a\u00020FJ\u0012\u0010G\u001a\u0004\u0018\u00010D2\u0006\u0010E\u001a\u00020FH\u0002J\b\u0010H\u001a\u00020@H\u0002J\u0006\u0010I\u001a\u00020@J\u0010\u0010J\u001a\u0002002\u0006\u0010K\u001a\u00020LH\u0002J\n\u0010M\u001a\u0004\u0018\u00010\'H\u0002J\u0006\u0010N\u001a\u000200J\b\u0010O\u001a\u00020@H\u0002J\u000e\u0010P\u001a\u00020@2\u0006\u0010A\u001a\u00020BJ\u0006\u0010Q\u001a\u00020@J\b\u0010R\u001a\u00020@H\u0002R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\"\u001a\u00020#X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0013X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0010\u001a\u00020\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0016\u001a\u00020\u0017X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010$\u001a\u00020%X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0018\u001a\u00020\u0019X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001c\u001a\u00020\u001dX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010&\u001a\u0004\u0018\u00010\'X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010(\u001a\u0004\u0018\u00010 X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010)\u001a\u0004\u0018\u00010*X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010+\u001a\u00020,X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010-\u001a\u00020.X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010/\u001a\u000200X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u00101\u001a\u000200X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u00102\u001a\b\u0012\u0004\u0012\u00020403X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001a\u00105\u001a\u000206X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b7\u00108\"\u0004\b9\u0010:R\u000e\u0010\u0014\u001a\u00020\u0015X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010;\u001a\u00020<X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001a\u001a\u00020\u001bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\u000fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010=\u001a\u00020>X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/lockscreen/LockscreenSmartspaceController;", "", "context", "Landroid/content/Context;", "featureFlags", "Lcom/android/systemui/flags/FeatureFlags;", "smartspaceManager", "Landroid/app/smartspace/SmartspaceManager;", "activityStarter", "Lcom/android/systemui/plugins/ActivityStarter;", "falsingManager", "Lcom/android/systemui/plugins/FalsingManager;", "secureSettings", "Lcom/android/systemui/util/settings/SecureSettings;", "userTracker", "Lcom/android/systemui/settings/UserTracker;", "contentResolver", "Landroid/content/ContentResolver;", "configurationController", "Lcom/android/systemui/statusbar/policy/ConfigurationController;", "statusBarStateController", "Lcom/android/systemui/plugins/statusbar/StatusBarStateController;", "deviceProvisionedController", "Lcom/android/systemui/statusbar/policy/DeviceProvisionedController;", "execution", "Lcom/android/systemui/util/concurrency/Execution;", "uiExecutor", "Ljava/util/concurrent/Executor;", "handler", "Landroid/os/Handler;", "optionalPlugin", "Ljava/util/Optional;", "Lcom/android/systemui/plugins/BcSmartspaceDataPlugin;", "(Landroid/content/Context;Lcom/android/systemui/flags/FeatureFlags;Landroid/app/smartspace/SmartspaceManager;Lcom/android/systemui/plugins/ActivityStarter;Lcom/android/systemui/plugins/FalsingManager;Lcom/android/systemui/util/settings/SecureSettings;Lcom/android/systemui/settings/UserTracker;Landroid/content/ContentResolver;Lcom/android/systemui/statusbar/policy/ConfigurationController;Lcom/android/systemui/plugins/statusbar/StatusBarStateController;Lcom/android/systemui/statusbar/policy/DeviceProvisionedController;Lcom/android/systemui/util/concurrency/Execution;Ljava/util/concurrent/Executor;Landroid/os/Handler;Ljava/util/Optional;)V", "configChangeListener", "Lcom/android/systemui/statusbar/policy/ConfigurationController$ConfigurationListener;", "deviceProvisionedListener", "Lcom/android/systemui/statusbar/policy/DeviceProvisionedController$DeviceProvisionedListener;", "managedUserHandle", "Landroid/os/UserHandle;", "plugin", "session", "Landroid/app/smartspace/SmartspaceSession;", "sessionListener", "Landroid/app/smartspace/SmartspaceSession$OnTargetsAvailableListener;", "settingsObserver", "Landroid/database/ContentObserver;", "showSensitiveContentForCurrentUser", "", "showSensitiveContentForManagedUser", "smartspaceViews", "", "Lcom/android/systemui/plugins/BcSmartspaceDataPlugin$SmartspaceView;", "stateChangeListener", "Landroid/view/View$OnAttachStateChangeListener;", "getStateChangeListener", "()Landroid/view/View$OnAttachStateChangeListener;", "setStateChangeListener", "(Landroid/view/View$OnAttachStateChangeListener;)V", "statusBarStateListener", "Lcom/android/systemui/plugins/statusbar/StatusBarStateController$StateListener;", "userTrackerCallback", "Lcom/android/systemui/settings/UserTracker$Callback;", "addListener", "", "listener", "Lcom/android/systemui/plugins/BcSmartspaceDataPlugin$SmartspaceTargetListener;", "buildAndConnectView", "Landroid/view/View;", "parent", "Landroid/view/ViewGroup;", "buildView", "connectSession", "disconnect", "filterSmartspaceTarget", "t", "Landroid/app/smartspace/SmartspaceTarget;", "getWorkProfileUser", "isEnabled", "reloadSmartspace", "removeListener", "requestSmartspaceUpdate", "updateTextColorFromWallpaper", "Companion"})
@com.android.systemui.dagger.SysUISingleton()
public final class LockscreenSmartspaceController {
    private android.app.smartspace.SmartspaceSession session;
    private final com.android.systemui.plugins.BcSmartspaceDataPlugin plugin = null;
    private java.util.Set<com.android.systemui.plugins.BcSmartspaceDataPlugin.SmartspaceView> smartspaceViews;
    private boolean showSensitiveContentForCurrentUser = false;
    private boolean showSensitiveContentForManagedUser = false;
    private android.os.UserHandle managedUserHandle;
    @org.jetbrains.annotations.NotNull()
    private android.view.View.OnAttachStateChangeListener stateChangeListener;
    private final android.app.smartspace.SmartspaceSession.OnTargetsAvailableListener sessionListener = null;
    private final com.android.systemui.settings.UserTracker.Callback userTrackerCallback = null;
    private final android.database.ContentObserver settingsObserver = null;
    private final com.android.systemui.statusbar.policy.ConfigurationController.ConfigurationListener configChangeListener = null;
    private final com.android.systemui.plugins.statusbar.StatusBarStateController.StateListener statusBarStateListener = null;
    private final com.android.systemui.statusbar.policy.DeviceProvisionedController.DeviceProvisionedListener deviceProvisionedListener = null;
    private final android.content.Context context = null;
    private final com.android.systemui.flags.FeatureFlags featureFlags = null;
    private final android.app.smartspace.SmartspaceManager smartspaceManager = null;
    private final com.android.systemui.plugins.ActivityStarter activityStarter = null;
    private final com.android.systemui.plugins.FalsingManager falsingManager = null;
    private final com.android.systemui.util.settings.SecureSettings secureSettings = null;
    private final com.android.systemui.settings.UserTracker userTracker = null;
    private final android.content.ContentResolver contentResolver = null;
    private final com.android.systemui.statusbar.policy.ConfigurationController configurationController = null;
    private final com.android.systemui.plugins.statusbar.StatusBarStateController statusBarStateController = null;
    private final com.android.systemui.statusbar.policy.DeviceProvisionedController deviceProvisionedController = null;
    private final com.android.systemui.util.concurrency.Execution execution = null;
    private final java.util.concurrent.Executor uiExecutor = null;
    private final android.os.Handler handler = null;
    private static final java.lang.String TAG = "LockscreenSmartspaceController";
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.statusbar.lockscreen.LockscreenSmartspaceController.Companion Companion = null;
    
    @org.jetbrains.annotations.NotNull()
    public final android.view.View.OnAttachStateChangeListener getStateChangeListener() {
        return null;
    }
    
    public final void setStateChangeListener(@org.jetbrains.annotations.NotNull()
    android.view.View.OnAttachStateChangeListener p0) {
    }
    
    public final boolean isEnabled() {
        return false;
    }
    
    /**
     * Constructs the smartspace view and connects it to the smartspace service.
     */
    @org.jetbrains.annotations.Nullable()
    public final android.view.View buildAndConnectView(@org.jetbrains.annotations.NotNull()
    android.view.ViewGroup parent) {
        return null;
    }
    
    public final void requestSmartspaceUpdate() {
    }
    
    private final android.view.View buildView(android.view.ViewGroup parent) {
        return null;
    }
    
    private final void connectSession() {
    }
    
    /**
     * Disconnects the smartspace view from the smartspace service and cleans up any resources.
     */
    public final void disconnect() {
    }
    
    public final void addListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.BcSmartspaceDataPlugin.SmartspaceTargetListener listener) {
    }
    
    public final void removeListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.BcSmartspaceDataPlugin.SmartspaceTargetListener listener) {
    }
    
    private final boolean filterSmartspaceTarget(android.app.smartspace.SmartspaceTarget t) {
        return false;
    }
    
    private final void updateTextColorFromWallpaper() {
    }
    
    private final void reloadSmartspace() {
    }
    
    private final android.os.UserHandle getWorkProfileUser() {
        return null;
    }
    
    @javax.inject.Inject()
    public LockscreenSmartspaceController(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.flags.FeatureFlags featureFlags, @org.jetbrains.annotations.NotNull()
    android.app.smartspace.SmartspaceManager smartspaceManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.ActivityStarter activityStarter, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.FalsingManager falsingManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.settings.SecureSettings secureSettings, @org.jetbrains.annotations.NotNull()
    com.android.systemui.settings.UserTracker userTracker, @org.jetbrains.annotations.NotNull()
    android.content.ContentResolver contentResolver, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.ConfigurationController configurationController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.statusbar.StatusBarStateController statusBarStateController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.DeviceProvisionedController deviceProvisionedController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.concurrency.Execution execution, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    java.util.concurrent.Executor uiExecutor, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    android.os.Handler handler, @org.jetbrains.annotations.NotNull()
    java.util.Optional<com.android.systemui.plugins.BcSmartspaceDataPlugin> optionalPlugin) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/lockscreen/LockscreenSmartspaceController$Companion;", "", "()V", "TAG", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}