package com.android.systemui.statusbar.notification;

import android.view.ViewGroup;
import com.android.internal.jank.InteractionJankMonitor;
import com.android.systemui.animation.ActivityLaunchAnimator;
import com.android.systemui.animation.LaunchAnimator;
import com.android.systemui.statusbar.notification.row.ExpandableNotificationRow;
import com.android.systemui.statusbar.notification.stack.NotificationListContainer;
import com.android.systemui.statusbar.phone.HeadsUpManagerPhone;
import com.android.systemui.statusbar.phone.NotificationShadeWindowViewController;
import com.android.systemui.statusbar.policy.HeadsUpUtil;

/**
 * A provider of [NotificationLaunchAnimatorController].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\u0018\u00002\u00020\u0001B\u001d\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ\u000e\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\fR\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/NotificationLaunchAnimatorControllerProvider;", "", "notificationShadeWindowViewController", "Lcom/android/systemui/statusbar/phone/NotificationShadeWindowViewController;", "notificationListContainer", "Lcom/android/systemui/statusbar/notification/stack/NotificationListContainer;", "headsUpManager", "Lcom/android/systemui/statusbar/phone/HeadsUpManagerPhone;", "(Lcom/android/systemui/statusbar/phone/NotificationShadeWindowViewController;Lcom/android/systemui/statusbar/notification/stack/NotificationListContainer;Lcom/android/systemui/statusbar/phone/HeadsUpManagerPhone;)V", "getAnimatorController", "Lcom/android/systemui/statusbar/notification/NotificationLaunchAnimatorController;", "notification", "Lcom/android/systemui/statusbar/notification/row/ExpandableNotificationRow;"})
public final class NotificationLaunchAnimatorControllerProvider {
    private final com.android.systemui.statusbar.phone.NotificationShadeWindowViewController notificationShadeWindowViewController = null;
    private final com.android.systemui.statusbar.notification.stack.NotificationListContainer notificationListContainer = null;
    private final com.android.systemui.statusbar.phone.HeadsUpManagerPhone headsUpManager = null;
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.notification.NotificationLaunchAnimatorController getAnimatorController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.row.ExpandableNotificationRow notification) {
        return null;
    }
    
    public NotificationLaunchAnimatorControllerProvider(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.NotificationShadeWindowViewController notificationShadeWindowViewController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.stack.NotificationListContainer notificationListContainer, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.HeadsUpManagerPhone headsUpManager) {
        super();
    }
}