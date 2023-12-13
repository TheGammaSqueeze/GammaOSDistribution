package com.android.systemui.statusbar.notification;

import android.app.Notification;
import android.content.Context;
import android.content.pm.LauncherApps;
import android.graphics.drawable.AnimatedImageDrawable;
import android.os.Handler;
import android.service.notification.NotificationListenerService.Ranking;
import android.service.notification.NotificationListenerService.RankingMap;
import com.android.internal.statusbar.NotificationVisibility;
import com.android.internal.widget.ConversationLayout;
import com.android.internal.widget.MessagingImageMessage;
import com.android.internal.widget.MessagingLayout;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;
import com.android.systemui.statusbar.notification.collection.legacy.NotificationGroupManagerLegacy;
import com.android.systemui.statusbar.notification.row.ExpandableNotificationRow;
import com.android.systemui.statusbar.notification.row.NotificationContentView;
import com.android.systemui.statusbar.notification.stack.StackStateAnimator;
import com.android.systemui.statusbar.policy.HeadsUpManager;
import com.android.systemui.statusbar.policy.OnHeadsUpChangedListener;
import java.util.concurrent.ConcurrentHashMap;
import javax.inject.Inject;

/**
 * Tracks state related to animated images inside of notifications. Ex: starting and stopping
 * animations to conserve CPU and memory.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00002\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\b\u0007\u0018\u00002\u00020\u0001B\u001f\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ\u0006\u0010\u000b\u001a\u00020\fJ\u0018\u0010\r\u001a\u00020\f2\u0006\u0010\u000e\u001a\u00020\u000f2\u0006\u0010\u0010\u001a\u00020\nH\u0002R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/AnimatedImageNotificationManager;", "", "notificationEntryManager", "Lcom/android/systemui/statusbar/notification/NotificationEntryManager;", "headsUpManager", "Lcom/android/systemui/statusbar/policy/HeadsUpManager;", "statusBarStateController", "Lcom/android/systemui/plugins/statusbar/StatusBarStateController;", "(Lcom/android/systemui/statusbar/notification/NotificationEntryManager;Lcom/android/systemui/statusbar/policy/HeadsUpManager;Lcom/android/systemui/plugins/statusbar/StatusBarStateController;)V", "isStatusBarExpanded", "", "bind", "", "updateAnimatedImageDrawables", "row", "Lcom/android/systemui/statusbar/notification/row/ExpandableNotificationRow;", "animating"})
@com.android.systemui.dagger.SysUISingleton()
public final class AnimatedImageNotificationManager {
    private boolean isStatusBarExpanded = false;
    private final com.android.systemui.statusbar.notification.NotificationEntryManager notificationEntryManager = null;
    private final com.android.systemui.statusbar.policy.HeadsUpManager headsUpManager = null;
    private final com.android.systemui.plugins.statusbar.StatusBarStateController statusBarStateController = null;
    
    /**
     * Begins listening to state changes and updating animations accordingly.
     */
    public final void bind() {
    }
    
    private final void updateAnimatedImageDrawables(com.android.systemui.statusbar.notification.row.ExpandableNotificationRow row, boolean animating) {
    }
    
    @javax.inject.Inject()
    public AnimatedImageNotificationManager(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.NotificationEntryManager notificationEntryManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.HeadsUpManager headsUpManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.statusbar.StatusBarStateController statusBarStateController) {
        super();
    }
}