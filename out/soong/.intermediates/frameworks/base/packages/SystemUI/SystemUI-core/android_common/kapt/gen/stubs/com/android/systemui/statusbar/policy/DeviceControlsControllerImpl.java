package com.android.systemui.statusbar.policy;

import android.content.ComponentName;
import android.content.Context;
import android.content.SharedPreferences;
import android.provider.Settings;
import android.util.Log;
import com.android.systemui.R;
import com.android.systemui.controls.ControlsServiceInfo;
import com.android.systemui.controls.dagger.ControlsComponent;
import com.android.systemui.controls.management.ControlsListingController;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.settings.UserContextProvider;
import com.android.systemui.statusbar.policy.DeviceControlsController.Callback;
import com.android.systemui.util.settings.SecureSettings;
import javax.inject.Inject;

/**
 * Watches for Device Controls QS Tile activation, which can happen in two ways:
 * <ol>
 *  <li>Migration from Power Menu - For existing Android 11 users, create a tile in a high
 *      priority position.
 *  <li>Device controls service becomes available - For non-migrated users, create a tile and
 *      place at the end of active tiles, and initiate seeding where possible.
 * </ol>
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000X\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0006\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0005\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0002\b\u0007\u0018\u0000 $2\u00020\u0001:\u0001$B\'\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJ\u0018\u0010\u0016\u001a\u00020\u00172\u0006\u0010\u0018\u001a\u00020\u00192\u0006\u0010\u001a\u001a\u00020\u001bH\u0002J\b\u0010\u001c\u001a\u00020\u0017H\u0002J\b\u0010\u001d\u001a\u00020\u0017H\u0002J\b\u0010\u001e\u001a\u00020\u0017H\u0016J\u0016\u0010\u001f\u001a\u00020\u00172\f\u0010 \u001a\b\u0012\u0004\u0012\u00020\"0!H\u0002J\u0010\u0010#\u001a\u00020\u00172\u0006\u0010\u000b\u001a\u00020\fH\u0016R\u0010\u0010\u000b\u001a\u0004\u0018\u00010\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001e\u0010\u000f\u001a\u0004\u0018\u00010\u0010X\u0080\u000e\u00a2\u0006\u0010\n\u0002\u0010\u0015\u001a\u0004\b\u0011\u0010\u0012\"\u0004\b\u0013\u0010\u0014R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/policy/DeviceControlsControllerImpl;", "Lcom/android/systemui/statusbar/policy/DeviceControlsController;", "context", "Landroid/content/Context;", "controlsComponent", "Lcom/android/systemui/controls/dagger/ControlsComponent;", "userContextProvider", "Lcom/android/systemui/settings/UserContextProvider;", "secureSettings", "Lcom/android/systemui/util/settings/SecureSettings;", "(Landroid/content/Context;Lcom/android/systemui/controls/dagger/ControlsComponent;Lcom/android/systemui/settings/UserContextProvider;Lcom/android/systemui/util/settings/SecureSettings;)V", "callback", "Lcom/android/systemui/statusbar/policy/DeviceControlsController$Callback;", "listingCallback", "Lcom/android/systemui/controls/management/ControlsListingController$ControlsListingCallback;", "position", "", "getPosition$main", "()Ljava/lang/Integer;", "setPosition$main", "(Ljava/lang/Integer;)V", "Ljava/lang/Integer;", "addPackageToSeededSet", "", "prefs", "Landroid/content/SharedPreferences;", "pkg", "", "checkMigrationToQs", "fireControlsUpdate", "removeCallback", "seedFavorites", "serviceInfos", "", "Lcom/android/systemui/controls/ControlsServiceInfo;", "setCallback", "Companion"})
@com.android.systemui.dagger.SysUISingleton()
public final class DeviceControlsControllerImpl implements com.android.systemui.statusbar.policy.DeviceControlsController {
    private com.android.systemui.statusbar.policy.DeviceControlsController.Callback callback;
    @org.jetbrains.annotations.Nullable()
    private java.lang.Integer position;
    private final com.android.systemui.controls.management.ControlsListingController.ControlsListingCallback listingCallback = null;
    private final android.content.Context context = null;
    private final com.android.systemui.controls.dagger.ControlsComponent controlsComponent = null;
    private final com.android.systemui.settings.UserContextProvider userContextProvider = null;
    private final com.android.systemui.util.settings.SecureSettings secureSettings = null;
    private static final java.lang.String TAG = "DeviceControlsControllerImpl";
    public static final int QS_PRIORITY_POSITION = 3;
    public static final int QS_DEFAULT_POSITION = 7;
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String PREFS_CONTROLS_SEEDING_COMPLETED = "SeedingCompleted";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String PREFS_CONTROLS_FILE = "controls_prefs";
    private static final int SEEDING_MAX = 2;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.statusbar.policy.DeviceControlsControllerImpl.Companion Companion = null;
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Integer getPosition$main() {
        return null;
    }
    
    public final void setPosition$main(@org.jetbrains.annotations.Nullable()
    java.lang.Integer p0) {
    }
    
    private final void checkMigrationToQs() {
    }
    
    /**
     * This migration logic assumes that something like [AutoTileManager] is tracking state
     * externally, and won't call this method after receiving a response via
     * [Callback#onControlsUpdate], once per user. Otherwise the calculated position may be
     * incorrect.
     */
    @java.lang.Override()
    public void setCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.DeviceControlsController.Callback callback) {
    }
    
    @java.lang.Override()
    public void removeCallback() {
    }
    
    private final void fireControlsUpdate() {
    }
    
    /**
     * See if any available control service providers match one of the preferred components. If
     * they do, and there are no current favorites for that component, query the preferred
     * component for a limited number of suggested controls.
     */
    private final void seedFavorites(java.util.List<com.android.systemui.controls.ControlsServiceInfo> serviceInfos) {
    }
    
    private final void addPackageToSeededSet(android.content.SharedPreferences prefs, java.lang.String pkg) {
    }
    
    @javax.inject.Inject()
    public DeviceControlsControllerImpl(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.dagger.ControlsComponent controlsComponent, @org.jetbrains.annotations.NotNull()
    com.android.systemui.settings.UserContextProvider userContextProvider, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.settings.SecureSettings secureSettings) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0003\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0080T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0080T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0080T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0007X\u0080T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\u0007X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/policy/DeviceControlsControllerImpl$Companion;", "", "()V", "PREFS_CONTROLS_FILE", "", "PREFS_CONTROLS_SEEDING_COMPLETED", "QS_DEFAULT_POSITION", "", "QS_PRIORITY_POSITION", "SEEDING_MAX", "TAG"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}