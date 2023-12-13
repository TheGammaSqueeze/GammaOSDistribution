package com.android.systemui.statusbar.policy;

import android.app.Notification;
import android.app.PendingIntent;
import android.app.RemoteInput;
import android.content.Context;
import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.os.SystemClock;
import android.util.Log;
import android.view.ContextThemeWrapper;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.accessibility.AccessibilityNodeInfo;
import android.view.accessibility.AccessibilityNodeInfo.AccessibilityAction;
import android.widget.Button;
import com.android.systemui.R;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.shared.system.ActivityManagerWrapper;
import com.android.systemui.shared.system.DevicePolicyManagerWrapper;
import com.android.systemui.shared.system.PackageManagerWrapper;
import com.android.systemui.statusbar.NotificationRemoteInputManager;
import com.android.systemui.statusbar.NotificationUiAdjustment;
import com.android.systemui.statusbar.SmartReplyController;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;
import com.android.systemui.statusbar.notification.logging.NotificationLogger;
import com.android.systemui.statusbar.phone.KeyguardDismissUtil;
import com.android.systemui.statusbar.policy.InflatedSmartReplyState.SuppressedActions;
import com.android.systemui.statusbar.policy.SmartReplyView.SmartActions;
import com.android.systemui.statusbar.policy.SmartReplyView.SmartButtonType;
import com.android.systemui.statusbar.policy.SmartReplyView.SmartReplies;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\bf\u0018\u00002\u00020\u0001J\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&J2\u0010\u0006\u001a\u00020\u00072\u0006\u0010\b\u001a\u00020\t2\u0006\u0010\n\u001a\u00020\t2\u0006\u0010\u0004\u001a\u00020\u00052\b\u0010\u000b\u001a\u0004\u0018\u00010\u00032\u0006\u0010\f\u001a\u00020\u0003H&"}, d2 = {"Lcom/android/systemui/statusbar/policy/SmartReplyStateInflater;", "", "inflateSmartReplyState", "Lcom/android/systemui/statusbar/policy/InflatedSmartReplyState;", "entry", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "inflateSmartReplyViewHolder", "Lcom/android/systemui/statusbar/policy/InflatedSmartReplyViewHolder;", "sysuiContext", "Landroid/content/Context;", "notifPackageContext", "existingSmartReplyState", "newSmartReplyState"})
public abstract interface SmartReplyStateInflater {
    
    @org.jetbrains.annotations.NotNull()
    public abstract com.android.systemui.statusbar.policy.InflatedSmartReplyState inflateSmartReplyState(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry);
    
    @org.jetbrains.annotations.NotNull()
    public abstract com.android.systemui.statusbar.policy.InflatedSmartReplyViewHolder inflateSmartReplyViewHolder(@org.jetbrains.annotations.NotNull()
    android.content.Context sysuiContext, @org.jetbrains.annotations.NotNull()
    android.content.Context notifPackageContext, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.policy.InflatedSmartReplyState existingSmartReplyState, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.InflatedSmartReplyState newSmartReplyState);
}