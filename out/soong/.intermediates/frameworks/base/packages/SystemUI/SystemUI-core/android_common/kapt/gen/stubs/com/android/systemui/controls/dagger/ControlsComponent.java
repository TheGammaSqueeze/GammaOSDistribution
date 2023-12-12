package com.android.systemui.controls.dagger;

import android.content.ContentResolver;
import android.content.Context;
import android.database.ContentObserver;
import android.provider.Settings;
import com.android.systemui.controls.controller.ControlsController;
import com.android.systemui.controls.management.ControlsListingController;
import com.android.systemui.controls.ui.ControlsUiController;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.settings.UserTracker;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.util.settings.SecureSettings;
import com.android.internal.widget.LockPatternUtils;
import dagger.Lazy;
import java.util.Optional;
import javax.inject.Inject;

/**
 * Pseudo-component to inject into classes outside `com.android.systemui.controls`.
 *
 * If `featureEnabled` is false, all the optionals should be empty. The controllers will only be
 * instantiated if `featureEnabled` is true. Can also be queried for the availability of controls.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000l\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\b\u0007\u0018\u00002\u00020\u0001:\u0001(Bc\b\u0007\u0012\b\b\u0001\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\f\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\b0\u0007\u0012\f\u0010\t\u001a\b\u0012\u0004\u0012\u00020\n0\u0007\u0012\f\u0010\u000b\u001a\b\u0012\u0004\u0012\u00020\f0\u0007\u0012\u0006\u0010\r\u001a\u00020\u000e\u0012\u0006\u0010\u000f\u001a\u00020\u0010\u0012\u0006\u0010\u0011\u001a\u00020\u0012\u0012\u0006\u0010\u0013\u001a\u00020\u0014\u00a2\u0006\u0002\u0010\u0015J\f\u0010\u001f\u001a\b\u0012\u0004\u0012\u00020\b0 J\f\u0010!\u001a\b\u0012\u0004\u0012\u00020\f0 J\f\u0010\"\u001a\b\u0012\u0004\u0012\u00020\n0 J\u0006\u0010#\u001a\u00020$J\u0006\u0010%\u001a\u00020\u0003J\b\u0010&\u001a\u00020\'H\u0002R\u000e\u0010\u0016\u001a\u00020\u0003X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0017\u001a\u00020\u00188BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0019\u0010\u001aR\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\b0\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u000b\u001a\b\u0012\u0004\u0012\u00020\f0\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\t\u001a\b\u0012\u0004\u0012\u00020\n0\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0013\u001a\u00020\u0014X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0011\u0010\u001b\u001a\u00020\u001c\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001d\u0010\u001eR\u000e\u0010\u0011\u001a\u00020\u0012X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/dagger/ControlsComponent;", "", "featureEnabled", "", "context", "Landroid/content/Context;", "lazyControlsController", "Ldagger/Lazy;", "Lcom/android/systemui/controls/controller/ControlsController;", "lazyControlsUiController", "Lcom/android/systemui/controls/ui/ControlsUiController;", "lazyControlsListingController", "Lcom/android/systemui/controls/management/ControlsListingController;", "lockPatternUtils", "Lcom/android/internal/widget/LockPatternUtils;", "keyguardStateController", "Lcom/android/systemui/statusbar/policy/KeyguardStateController;", "userTracker", "Lcom/android/systemui/settings/UserTracker;", "secureSettings", "Lcom/android/systemui/util/settings/SecureSettings;", "(ZLandroid/content/Context;Ldagger/Lazy;Ldagger/Lazy;Ldagger/Lazy;Lcom/android/internal/widget/LockPatternUtils;Lcom/android/systemui/statusbar/policy/KeyguardStateController;Lcom/android/systemui/settings/UserTracker;Lcom/android/systemui/util/settings/SecureSettings;)V", "canShowWhileLockedSetting", "contentResolver", "Landroid/content/ContentResolver;", "getContentResolver", "()Landroid/content/ContentResolver;", "showWhileLockedObserver", "Landroid/database/ContentObserver;", "getShowWhileLockedObserver", "()Landroid/database/ContentObserver;", "getControlsController", "Ljava/util/Optional;", "getControlsListingController", "getControlsUiController", "getVisibility", "Lcom/android/systemui/controls/dagger/ControlsComponent$Visibility;", "isEnabled", "updateShowWhileLocked", "", "Visibility"})
@com.android.systemui.dagger.SysUISingleton()
public final class ControlsComponent {
    private boolean canShowWhileLockedSetting = false;
    @org.jetbrains.annotations.NotNull()
    private final android.database.ContentObserver showWhileLockedObserver = null;
    private final boolean featureEnabled = false;
    private final android.content.Context context = null;
    private final dagger.Lazy<com.android.systemui.controls.controller.ControlsController> lazyControlsController = null;
    private final dagger.Lazy<com.android.systemui.controls.ui.ControlsUiController> lazyControlsUiController = null;
    private final dagger.Lazy<com.android.systemui.controls.management.ControlsListingController> lazyControlsListingController = null;
    private final com.android.internal.widget.LockPatternUtils lockPatternUtils = null;
    private final com.android.systemui.statusbar.policy.KeyguardStateController keyguardStateController = null;
    private final com.android.systemui.settings.UserTracker userTracker = null;
    private final com.android.systemui.util.settings.SecureSettings secureSettings = null;
    
    private final android.content.ContentResolver getContentResolver() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.database.ContentObserver getShowWhileLockedObserver() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.Optional<com.android.systemui.controls.controller.ControlsController> getControlsController() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.Optional<com.android.systemui.controls.ui.ControlsUiController> getControlsUiController() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.Optional<com.android.systemui.controls.management.ControlsListingController> getControlsListingController() {
        return null;
    }
    
    /**
     * @return true if controls are feature-enabled and the user has the setting enabled
     */
    public final boolean isEnabled() {
        return false;
    }
    
    /**
     * Returns one of 3 states:
     * * AVAILABLE - Controls can be made visible
     * * AVAILABLE_AFTER_UNLOCK - Controls can be made visible only after device unlock
     * * UNAVAILABLE - Controls are not enabled
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.controls.dagger.ControlsComponent.Visibility getVisibility() {
        return null;
    }
    
    private final void updateShowWhileLocked() {
    }
    
    @javax.inject.Inject()
    public ControlsComponent(@ControlsFeatureEnabled()
    boolean featureEnabled, @org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    dagger.Lazy<com.android.systemui.controls.controller.ControlsController> lazyControlsController, @org.jetbrains.annotations.NotNull()
    dagger.Lazy<com.android.systemui.controls.ui.ControlsUiController> lazyControlsUiController, @org.jetbrains.annotations.NotNull()
    dagger.Lazy<com.android.systemui.controls.management.ControlsListingController> lazyControlsListingController, @org.jetbrains.annotations.NotNull()
    com.android.internal.widget.LockPatternUtils lockPatternUtils, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.KeyguardStateController keyguardStateController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.settings.UserTracker userTracker, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.settings.SecureSettings secureSettings) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\f\n\u0002\u0018\u0002\n\u0002\u0010\u0010\n\u0002\b\u0004\b\u0086\u0001\u0018\u00002\b\u0012\u0004\u0012\u00020\u00000\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002j\u0002\b\u0003j\u0002\b\u0004j\u0002\b\u0005"}, d2 = {"Lcom/android/systemui/controls/dagger/ControlsComponent$Visibility;", "", "(Ljava/lang/String;I)V", "AVAILABLE", "AVAILABLE_AFTER_UNLOCK", "UNAVAILABLE"})
    public static enum Visibility {
        /*public static final*/ AVAILABLE /* = new AVAILABLE() */,
        /*public static final*/ AVAILABLE_AFTER_UNLOCK /* = new AVAILABLE_AFTER_UNLOCK() */,
        /*public static final*/ UNAVAILABLE /* = new UNAVAILABLE() */;
        
        Visibility() {
        }
    }
}