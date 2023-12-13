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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000X\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\u0018\u00002\u00020\u0001B\'\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJ@\u0010\u000b\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u00162\u0006\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\u001aH\u0016J(\u0010\u001b\u001a\u00020\u001c2\u0006\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u0016H\u0002R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/policy/SmartActionInflaterImpl;", "Lcom/android/systemui/statusbar/policy/SmartActionInflater;", "constants", "Lcom/android/systemui/statusbar/policy/SmartReplyConstants;", "activityStarter", "Lcom/android/systemui/plugins/ActivityStarter;", "smartReplyController", "Lcom/android/systemui/statusbar/SmartReplyController;", "headsUpManager", "Lcom/android/systemui/statusbar/policy/HeadsUpManager;", "(Lcom/android/systemui/statusbar/policy/SmartReplyConstants;Lcom/android/systemui/plugins/ActivityStarter;Lcom/android/systemui/statusbar/SmartReplyController;Lcom/android/systemui/statusbar/policy/HeadsUpManager;)V", "inflateActionButton", "Landroid/widget/Button;", "parent", "Landroid/view/ViewGroup;", "entry", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "smartActions", "Lcom/android/systemui/statusbar/policy/SmartReplyView$SmartActions;", "actionIndex", "", "action", "Landroid/app/Notification$Action;", "delayOnClickListener", "", "packageContext", "Landroid/content/Context;", "onSmartActionClick", ""})
public final class SmartActionInflaterImpl implements com.android.systemui.statusbar.policy.SmartActionInflater {
    private final com.android.systemui.statusbar.policy.SmartReplyConstants constants = null;
    private final com.android.systemui.plugins.ActivityStarter activityStarter = null;
    private final com.android.systemui.statusbar.SmartReplyController smartReplyController = null;
    private final com.android.systemui.statusbar.policy.HeadsUpManager headsUpManager = null;
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.widget.Button inflateActionButton(@org.jetbrains.annotations.NotNull()
    android.view.ViewGroup parent, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.SmartReplyView.SmartActions smartActions, int actionIndex, @org.jetbrains.annotations.NotNull()
    android.app.Notification.Action action, boolean delayOnClickListener, @org.jetbrains.annotations.NotNull()
    android.content.Context packageContext) {
        return null;
    }
    
    private final void onSmartActionClick(com.android.systemui.statusbar.notification.collection.NotificationEntry entry, com.android.systemui.statusbar.policy.SmartReplyView.SmartActions smartActions, int actionIndex, android.app.Notification.Action action) {
    }
    
    @javax.inject.Inject()
    public SmartActionInflaterImpl(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.SmartReplyConstants constants, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.ActivityStarter activityStarter, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.SmartReplyController smartReplyController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.HeadsUpManager headsUpManager) {
        super();
    }
}