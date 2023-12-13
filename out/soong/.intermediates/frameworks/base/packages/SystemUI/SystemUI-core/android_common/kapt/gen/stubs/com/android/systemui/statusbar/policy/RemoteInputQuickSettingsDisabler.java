package com.android.systemui.statusbar.policy;

import android.app.StatusBarManager;
import android.content.Context;
import android.content.res.Configuration;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.statusbar.CommandQueue;
import com.android.systemui.util.Utils;
import javax.inject.Inject;

/**
 * Controls whether the disable flag [StatusBarManager.DISABLE2_QUICK_SETTINGS] should be set.
 * This would happen when a [RemoteInputView] is active, the device is in landscape and not using
 * split shade.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000<\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\b\u0007\u0018\u00002\u00020\u0001B\u001f\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ\u000e\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u000eJ\u0010\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u0012\u001a\u00020\u0013H\u0016J\b\u0010\u0014\u001a\u00020\u0011H\u0002J\u000e\u0010\u0015\u001a\u00020\u00112\u0006\u0010\u0016\u001a\u00020\nR\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/policy/RemoteInputQuickSettingsDisabler;", "Lcom/android/systemui/statusbar/policy/ConfigurationController$ConfigurationListener;", "context", "Landroid/content/Context;", "commandQueue", "Lcom/android/systemui/statusbar/CommandQueue;", "configController", "Lcom/android/systemui/statusbar/policy/ConfigurationController;", "(Landroid/content/Context;Lcom/android/systemui/statusbar/CommandQueue;Lcom/android/systemui/statusbar/policy/ConfigurationController;)V", "isLandscape", "", "remoteInputActive", "shouldUseSplitNotificationShade", "adjustDisableFlags", "", "state", "onConfigChanged", "", "newConfig", "Landroid/content/res/Configuration;", "recomputeDisableFlags", "setRemoteInputActive", "active"})
@com.android.systemui.dagger.SysUISingleton()
public final class RemoteInputQuickSettingsDisabler implements com.android.systemui.statusbar.policy.ConfigurationController.ConfigurationListener {
    private boolean remoteInputActive = false;
    private boolean isLandscape;
    private boolean shouldUseSplitNotificationShade;
    private final android.content.Context context = null;
    private final com.android.systemui.statusbar.CommandQueue commandQueue = null;
    
    public final int adjustDisableFlags(int state) {
        return 0;
    }
    
    public final void setRemoteInputActive(boolean active) {
    }
    
    @java.lang.Override()
    public void onConfigChanged(@org.jetbrains.annotations.NotNull()
    android.content.res.Configuration newConfig) {
    }
    
    /**
     * Called in order to trigger a refresh of the disable flags after a relevant configuration
     * change or when a [RemoteInputView] has changed its active state. The method
     * [adjustDisableFlags] will be invoked to modify the disable flags according to
     * [remoteInputActive], [isLandscape] and [shouldUseSplitNotificationShade].
     */
    private final void recomputeDisableFlags() {
    }
    
    @javax.inject.Inject()
    public RemoteInputQuickSettingsDisabler(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.CommandQueue commandQueue, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.ConfigurationController configController) {
        super();
    }
}