package com.android.systemui.media.dialog;

import android.content.Context;
import android.media.session.MediaSessionManager;
import android.view.View;
import com.android.internal.logging.UiEventLogger;
import com.android.settingslib.bluetooth.LocalBluetoothManager;
import com.android.systemui.animation.DialogLaunchAnimator;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.phone.ShadeController;
import com.android.systemui.statusbar.phone.SystemUIDialogManager;
import javax.inject.Inject;

/**
 * Factory to create [MediaOutputDialog] objects.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\\\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\u0018\u0000 \u001e2\u00020\u0001:\u0001\u001eBQ\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\b\u0010\u0006\u001a\u0004\u0018\u00010\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u0012\u0006\u0010\f\u001a\u00020\r\u0012\u0006\u0010\u000e\u001a\u00020\u000f\u0012\u0006\u0010\u0010\u001a\u00020\u0011\u0012\u0006\u0010\u0012\u001a\u00020\u0013\u00a2\u0006\u0002\u0010\u0014J\"\u0010\u0015\u001a\u00020\u00162\u0006\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\u001a2\n\b\u0002\u0010\u001b\u001a\u0004\u0018\u00010\u001cJ\u0006\u0010\u001d\u001a\u00020\u0016R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0010\u001a\u00020\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0013X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0006\u001a\u0004\u0018\u00010\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\u000fX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/media/dialog/MediaOutputDialogFactory;", "", "context", "Landroid/content/Context;", "mediaSessionManager", "Landroid/media/session/MediaSessionManager;", "lbm", "Lcom/android/settingslib/bluetooth/LocalBluetoothManager;", "shadeController", "Lcom/android/systemui/statusbar/phone/ShadeController;", "starter", "Lcom/android/systemui/plugins/ActivityStarter;", "notificationEntryManager", "Lcom/android/systemui/statusbar/notification/NotificationEntryManager;", "uiEventLogger", "Lcom/android/internal/logging/UiEventLogger;", "dialogLaunchAnimator", "Lcom/android/systemui/animation/DialogLaunchAnimator;", "dialogManager", "Lcom/android/systemui/statusbar/phone/SystemUIDialogManager;", "(Landroid/content/Context;Landroid/media/session/MediaSessionManager;Lcom/android/settingslib/bluetooth/LocalBluetoothManager;Lcom/android/systemui/statusbar/phone/ShadeController;Lcom/android/systemui/plugins/ActivityStarter;Lcom/android/systemui/statusbar/notification/NotificationEntryManager;Lcom/android/internal/logging/UiEventLogger;Lcom/android/systemui/animation/DialogLaunchAnimator;Lcom/android/systemui/statusbar/phone/SystemUIDialogManager;)V", "create", "", "packageName", "", "aboveStatusBar", "", "view", "Landroid/view/View;", "dismiss", "Companion"})
public final class MediaOutputDialogFactory {
    private final android.content.Context context = null;
    private final android.media.session.MediaSessionManager mediaSessionManager = null;
    private final com.android.settingslib.bluetooth.LocalBluetoothManager lbm = null;
    private final com.android.systemui.statusbar.phone.ShadeController shadeController = null;
    private final com.android.systemui.plugins.ActivityStarter starter = null;
    private final com.android.systemui.statusbar.notification.NotificationEntryManager notificationEntryManager = null;
    private final com.android.internal.logging.UiEventLogger uiEventLogger = null;
    private final com.android.systemui.animation.DialogLaunchAnimator dialogLaunchAnimator = null;
    private final com.android.systemui.statusbar.phone.SystemUIDialogManager dialogManager = null;
    @org.jetbrains.annotations.Nullable()
    private static com.android.systemui.media.dialog.MediaOutputDialog mediaOutputDialog;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.media.dialog.MediaOutputDialogFactory.Companion Companion = null;
    
    /**
     * Creates a [MediaOutputDialog] for the given package.
     */
    public final void create(@org.jetbrains.annotations.NotNull()
    java.lang.String packageName, boolean aboveStatusBar, @org.jetbrains.annotations.Nullable()
    android.view.View view) {
    }
    
    /**
     * dismiss [MediaOutputDialog] if exist.
     */
    public final void dismiss() {
    }
    
    @javax.inject.Inject()
    public MediaOutputDialogFactory(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    android.media.session.MediaSessionManager mediaSessionManager, @org.jetbrains.annotations.Nullable()
    com.android.settingslib.bluetooth.LocalBluetoothManager lbm, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.ShadeController shadeController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.ActivityStarter starter, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.NotificationEntryManager notificationEntryManager, @org.jetbrains.annotations.NotNull()
    com.android.internal.logging.UiEventLogger uiEventLogger, @org.jetbrains.annotations.NotNull()
    com.android.systemui.animation.DialogLaunchAnimator dialogLaunchAnimator, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.SystemUIDialogManager dialogManager) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u001c\u0010\u0003\u001a\u0004\u0018\u00010\u0004X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0005\u0010\u0006\"\u0004\b\u0007\u0010\b"}, d2 = {"Lcom/android/systemui/media/dialog/MediaOutputDialogFactory$Companion;", "", "()V", "mediaOutputDialog", "Lcom/android/systemui/media/dialog/MediaOutputDialog;", "getMediaOutputDialog", "()Lcom/android/systemui/media/dialog/MediaOutputDialog;", "setMediaOutputDialog", "(Lcom/android/systemui/media/dialog/MediaOutputDialog;)V"})
    public static final class Companion {
        
        @org.jetbrains.annotations.Nullable()
        public final com.android.systemui.media.dialog.MediaOutputDialog getMediaOutputDialog() {
            return null;
        }
        
        public final void setMediaOutputDialog(@org.jetbrains.annotations.Nullable()
        com.android.systemui.media.dialog.MediaOutputDialog p0) {
        }
        
        private Companion() {
            super();
        }
    }
}