package com.android.systemui.statusbar.events;

import android.content.Context;
import android.provider.DeviceConfig;
import com.android.systemui.R;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.privacy.PrivacyChipBuilder;
import com.android.systemui.privacy.PrivacyItem;
import com.android.systemui.privacy.PrivacyItemController;
import com.android.systemui.statusbar.policy.BatteryController;
import com.android.systemui.util.time.SystemClock;
import javax.inject.Inject;

/**
 * Listens for system events (battery, privacy, connectivity) and allows listeners
 * to show status bar animations when they happen
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000F\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0004\n\u0002\u0010\u000b\n\u0002\b\u0003\b\u0007\u0018\u00002\u00020\u0001B\'\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJ\u000e\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u0010J\u0006\u0010\u0014\u001a\u00020\u0012J\u0010\u0010\u0015\u001a\u00020\u00122\b\b\u0002\u0010\u0016\u001a\u00020\u0017J\u0006\u0010\u0018\u001a\u00020\u0012J\u0006\u0010\u0019\u001a\u00020\u0012J\u0006\u0010\u001a\u001a\u00020\u0012R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/events/SystemEventCoordinator;", "", "systemClock", "Lcom/android/systemui/util/time/SystemClock;", "batteryController", "Lcom/android/systemui/statusbar/policy/BatteryController;", "privacyController", "Lcom/android/systemui/privacy/PrivacyItemController;", "context", "Landroid/content/Context;", "(Lcom/android/systemui/util/time/SystemClock;Lcom/android/systemui/statusbar/policy/BatteryController;Lcom/android/systemui/privacy/PrivacyItemController;Landroid/content/Context;)V", "batteryStateListener", "Lcom/android/systemui/statusbar/policy/BatteryController$BatteryStateChangeCallback;", "privacyStateListener", "Lcom/android/systemui/privacy/PrivacyItemController$Callback;", "scheduler", "Lcom/android/systemui/statusbar/events/SystemStatusAnimationScheduler;", "attachScheduler", "", "s", "notifyPluggedIn", "notifyPrivacyItemsChanged", "showAnimation", "", "notifyPrivacyItemsEmpty", "startObserving", "stopObserving"})
@com.android.systemui.dagger.SysUISingleton()
public final class SystemEventCoordinator {
    private com.android.systemui.statusbar.events.SystemStatusAnimationScheduler scheduler;
    private final com.android.systemui.statusbar.policy.BatteryController.BatteryStateChangeCallback batteryStateListener = null;
    private final com.android.systemui.privacy.PrivacyItemController.Callback privacyStateListener = null;
    private final com.android.systemui.util.time.SystemClock systemClock = null;
    private final com.android.systemui.statusbar.policy.BatteryController batteryController = null;
    private final com.android.systemui.privacy.PrivacyItemController privacyController = null;
    private final android.content.Context context = null;
    
    public final void startObserving() {
    }
    
    public final void stopObserving() {
    }
    
    public final void attachScheduler(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.events.SystemStatusAnimationScheduler s) {
    }
    
    public final void notifyPluggedIn() {
    }
    
    public final void notifyPrivacyItemsEmpty() {
    }
    
    public final void notifyPrivacyItemsChanged(boolean showAnimation) {
    }
    
    @javax.inject.Inject()
    public SystemEventCoordinator(@org.jetbrains.annotations.NotNull()
    com.android.systemui.util.time.SystemClock systemClock, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.BatteryController batteryController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.privacy.PrivacyItemController privacyController, @org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super();
    }
}