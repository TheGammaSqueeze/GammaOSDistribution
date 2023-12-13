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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000b\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\r\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\u0018\u00002\u00020\u0001B/\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u00a2\u0006\u0002\u0010\fJ\u0018\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\u0012H\u0002J8\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u00162\u0006\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0019\u001a\u00020\u001a2\u0006\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u001b\u001a\u00020\u001cH\u0016J8\u0010\u001d\u001a\u00020\u001e2\u0006\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0019\u001a\u00020\u001a2\u0006\u0010\u001f\u001a\u00020\u00162\u0006\u0010 \u001a\u00020\u00142\u0006\u0010\u0011\u001a\u00020\u0012H\u0002R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/policy/SmartReplyInflaterImpl;", "Lcom/android/systemui/statusbar/policy/SmartReplyInflater;", "constants", "Lcom/android/systemui/statusbar/policy/SmartReplyConstants;", "keyguardDismissUtil", "Lcom/android/systemui/statusbar/phone/KeyguardDismissUtil;", "remoteInputManager", "Lcom/android/systemui/statusbar/NotificationRemoteInputManager;", "smartReplyController", "Lcom/android/systemui/statusbar/SmartReplyController;", "context", "Landroid/content/Context;", "(Lcom/android/systemui/statusbar/policy/SmartReplyConstants;Lcom/android/systemui/statusbar/phone/KeyguardDismissUtil;Lcom/android/systemui/statusbar/NotificationRemoteInputManager;Lcom/android/systemui/statusbar/SmartReplyController;Landroid/content/Context;)V", "createRemoteInputIntent", "Landroid/content/Intent;", "smartReplies", "Lcom/android/systemui/statusbar/policy/SmartReplyView$SmartReplies;", "choice", "", "inflateReplyButton", "Landroid/widget/Button;", "parent", "Lcom/android/systemui/statusbar/policy/SmartReplyView;", "entry", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "replyIndex", "", "delayOnClickListener", "", "onSmartReplyClick", "", "smartReplyView", "button"})
public final class SmartReplyInflaterImpl implements com.android.systemui.statusbar.policy.SmartReplyInflater {
    private final com.android.systemui.statusbar.policy.SmartReplyConstants constants = null;
    private final com.android.systemui.statusbar.phone.KeyguardDismissUtil keyguardDismissUtil = null;
    private final com.android.systemui.statusbar.NotificationRemoteInputManager remoteInputManager = null;
    private final com.android.systemui.statusbar.SmartReplyController smartReplyController = null;
    private final android.content.Context context = null;
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.widget.Button inflateReplyButton(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.SmartReplyView parent, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.SmartReplyView.SmartReplies smartReplies, int replyIndex, @org.jetbrains.annotations.NotNull()
    java.lang.CharSequence choice, boolean delayOnClickListener) {
        return null;
    }
    
    private final void onSmartReplyClick(com.android.systemui.statusbar.notification.collection.NotificationEntry entry, com.android.systemui.statusbar.policy.SmartReplyView.SmartReplies smartReplies, int replyIndex, com.android.systemui.statusbar.policy.SmartReplyView smartReplyView, android.widget.Button button, java.lang.CharSequence choice) {
    }
    
    private final android.content.Intent createRemoteInputIntent(com.android.systemui.statusbar.policy.SmartReplyView.SmartReplies smartReplies, java.lang.CharSequence choice) {
        return null;
    }
    
    @javax.inject.Inject()
    public SmartReplyInflaterImpl(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.SmartReplyConstants constants, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.KeyguardDismissUtil keyguardDismissUtil, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationRemoteInputManager remoteInputManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.SmartReplyController smartReplyController, @org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super();
    }
}