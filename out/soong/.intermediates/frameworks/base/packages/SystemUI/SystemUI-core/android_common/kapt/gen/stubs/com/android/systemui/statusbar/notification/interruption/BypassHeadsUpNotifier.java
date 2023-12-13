package com.android.systemui.statusbar.notification.interruption;

import android.content.Context;
import android.media.MediaMetadata;
import android.provider.Settings;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.statusbar.NotificationMediaManager;
import com.android.systemui.statusbar.StatusBarState;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;
import com.android.systemui.statusbar.phone.HeadsUpManagerPhone;
import com.android.systemui.statusbar.phone.KeyguardBypassController;
import com.android.systemui.tuner.TunerService;
import javax.inject.Inject;

/**
 * A class that automatically creates heads up for important notification when bypassing the
 * lockscreen
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000b\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\n\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0003\b\u0007\u0018\u00002\u00020\u00012\u00020\u0002BG\b\u0007\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u0012\u0006\u0010\u000b\u001a\u00020\f\u0012\u0006\u0010\r\u001a\u00020\u000e\u0012\u0006\u0010\u000f\u001a\u00020\u0010\u0012\u0006\u0010\u0011\u001a\u00020\u0012\u00a2\u0006\u0002\u0010\u0013J\u0010\u0010\u001e\u001a\u00020\u00172\u0006\u0010\u001f\u001a\u00020\u0015H\u0002J\b\u0010 \u001a\u00020\u0017H\u0002J\u001a\u0010!\u001a\u00020\"2\b\u0010#\u001a\u0004\u0018\u00010$2\u0006\u0010%\u001a\u00020&H\u0016J\b\u0010\'\u001a\u00020\"H\u0016J\u0006\u0010(\u001a\u00020\"J\u0012\u0010)\u001a\u00020\"2\b\u0010\u001f\u001a\u0004\u0018\u00010\u0015H\u0002R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0014\u001a\u0004\u0018\u00010\u0015X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0016\u001a\u00020\u0017X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000R$\u0010\u0019\u001a\u00020\u00172\u0006\u0010\u0018\u001a\u00020\u0017@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001a\u0010\u001b\"\u0004\b\u001c\u0010\u001dR\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/interruption/BypassHeadsUpNotifier;", "Lcom/android/systemui/plugins/statusbar/StatusBarStateController$StateListener;", "Lcom/android/systemui/statusbar/NotificationMediaManager$MediaListener;", "context", "Landroid/content/Context;", "bypassController", "Lcom/android/systemui/statusbar/phone/KeyguardBypassController;", "statusBarStateController", "Lcom/android/systemui/plugins/statusbar/StatusBarStateController;", "headsUpManager", "Lcom/android/systemui/statusbar/phone/HeadsUpManagerPhone;", "notificationLockscreenUserManager", "Lcom/android/systemui/statusbar/NotificationLockscreenUserManager;", "mediaManager", "Lcom/android/systemui/statusbar/NotificationMediaManager;", "entryManager", "Lcom/android/systemui/statusbar/notification/NotificationEntryManager;", "tunerService", "Lcom/android/systemui/tuner/TunerService;", "(Landroid/content/Context;Lcom/android/systemui/statusbar/phone/KeyguardBypassController;Lcom/android/systemui/plugins/statusbar/StatusBarStateController;Lcom/android/systemui/statusbar/phone/HeadsUpManagerPhone;Lcom/android/systemui/statusbar/NotificationLockscreenUserManager;Lcom/android/systemui/statusbar/NotificationMediaManager;Lcom/android/systemui/statusbar/notification/NotificationEntryManager;Lcom/android/systemui/tuner/TunerService;)V", "currentMediaEntry", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "enabled", "", "value", "fullyAwake", "getFullyAwake", "()Z", "setFullyAwake", "(Z)V", "canAutoHeadsUp", "entry", "isAutoHeadsUpAllowed", "onPrimaryMetadataOrStateChanged", "", "metadata", "Landroid/media/MediaMetadata;", "state", "", "onStatePostChange", "setUp", "updateAutoHeadsUp"})
@com.android.systemui.dagger.SysUISingleton()
public final class BypassHeadsUpNotifier implements com.android.systemui.plugins.statusbar.StatusBarStateController.StateListener, com.android.systemui.statusbar.NotificationMediaManager.MediaListener {
    private com.android.systemui.statusbar.notification.collection.NotificationEntry currentMediaEntry;
    private boolean enabled = true;
    private boolean fullyAwake = false;
    private final android.content.Context context = null;
    private final com.android.systemui.statusbar.phone.KeyguardBypassController bypassController = null;
    private final com.android.systemui.plugins.statusbar.StatusBarStateController statusBarStateController = null;
    private final com.android.systemui.statusbar.phone.HeadsUpManagerPhone headsUpManager = null;
    private final com.android.systemui.statusbar.NotificationLockscreenUserManager notificationLockscreenUserManager = null;
    private final com.android.systemui.statusbar.NotificationMediaManager mediaManager = null;
    private final com.android.systemui.statusbar.notification.NotificationEntryManager entryManager = null;
    
    public final boolean getFullyAwake() {
        return false;
    }
    
    public final void setFullyAwake(boolean value) {
    }
    
    public final void setUp() {
    }
    
    @java.lang.Override()
    public void onPrimaryMetadataOrStateChanged(@org.jetbrains.annotations.Nullable()
    android.media.MediaMetadata metadata, int state) {
    }
    
    private final void updateAutoHeadsUp(com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
    }
    
    /**
     * @return {@code true} if this entry be autoHeadsUpped right now.
     */
    private final boolean canAutoHeadsUp(com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
        return false;
    }
    
    @java.lang.Override()
    public void onStatePostChange() {
    }
    
    /**
     * @return {@code true} if autoHeadsUp is possible right now.
     */
    private final boolean isAutoHeadsUpAllowed() {
        return false;
    }
    
    @javax.inject.Inject()
    public BypassHeadsUpNotifier(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.KeyguardBypassController bypassController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.statusbar.StatusBarStateController statusBarStateController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.HeadsUpManagerPhone headsUpManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationLockscreenUserManager notificationLockscreenUserManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationMediaManager mediaManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.NotificationEntryManager entryManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.tuner.TunerService tunerService) {
        super();
    }
}