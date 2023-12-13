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
 * Populates additional information in conversation notifications
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\u0018\u00002\u00020\u0001B\u0017\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u0016\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\fR\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/ConversationNotificationProcessor;", "", "launcherApps", "Landroid/content/pm/LauncherApps;", "conversationNotificationManager", "Lcom/android/systemui/statusbar/notification/ConversationNotificationManager;", "(Landroid/content/pm/LauncherApps;Lcom/android/systemui/statusbar/notification/ConversationNotificationManager;)V", "processNotification", "", "entry", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "recoveredBuilder", "Landroid/app/Notification$Builder;"})
public final class ConversationNotificationProcessor {
    private final android.content.pm.LauncherApps launcherApps = null;
    private final com.android.systemui.statusbar.notification.ConversationNotificationManager conversationNotificationManager = null;
    
    public final void processNotification(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry, @org.jetbrains.annotations.NotNull()
    android.app.Notification.Builder recoveredBuilder) {
    }
    
    @javax.inject.Inject()
    public ConversationNotificationProcessor(@org.jetbrains.annotations.NotNull()
    android.content.pm.LauncherApps launcherApps, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.ConversationNotificationManager conversationNotificationManager) {
        super();
    }
}