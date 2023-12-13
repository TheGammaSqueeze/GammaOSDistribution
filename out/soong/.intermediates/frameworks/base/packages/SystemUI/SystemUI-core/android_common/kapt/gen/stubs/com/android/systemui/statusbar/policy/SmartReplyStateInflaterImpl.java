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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000V\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\u0018\u00002\u00020\u0001B7\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u0012\u0006\u0010\f\u001a\u00020\r\u00a2\u0006\u0002\u0010\u000eJ\u000e\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\u0012J\u001c\u0010\u0013\u001a\b\u0012\u0004\u0012\u00020\u00150\u00142\f\u0010\u0016\u001a\b\u0012\u0004\u0012\u00020\u00150\u0014H\u0002J\u0010\u0010\u0017\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\u0012H\u0016J2\u0010\u0018\u001a\u00020\u00192\u0006\u0010\u001a\u001a\u00020\u001b2\u0006\u0010\u001c\u001a\u00020\u001b2\u0006\u0010\u0011\u001a\u00020\u00122\b\u0010\u001d\u001a\u0004\u0018\u00010\u00102\u0006\u0010\u001e\u001a\u00020\u0010H\u0016R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/policy/SmartReplyStateInflaterImpl;", "Lcom/android/systemui/statusbar/policy/SmartReplyStateInflater;", "constants", "Lcom/android/systemui/statusbar/policy/SmartReplyConstants;", "activityManagerWrapper", "Lcom/android/systemui/shared/system/ActivityManagerWrapper;", "packageManagerWrapper", "Lcom/android/systemui/shared/system/PackageManagerWrapper;", "devicePolicyManagerWrapper", "Lcom/android/systemui/shared/system/DevicePolicyManagerWrapper;", "smartRepliesInflater", "Lcom/android/systemui/statusbar/policy/SmartReplyInflater;", "smartActionsInflater", "Lcom/android/systemui/statusbar/policy/SmartActionInflater;", "(Lcom/android/systemui/statusbar/policy/SmartReplyConstants;Lcom/android/systemui/shared/system/ActivityManagerWrapper;Lcom/android/systemui/shared/system/PackageManagerWrapper;Lcom/android/systemui/shared/system/DevicePolicyManagerWrapper;Lcom/android/systemui/statusbar/policy/SmartReplyInflater;Lcom/android/systemui/statusbar/policy/SmartActionInflater;)V", "chooseSmartRepliesAndActions", "Lcom/android/systemui/statusbar/policy/InflatedSmartReplyState;", "entry", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "filterAllowlistedLockTaskApps", "", "Landroid/app/Notification$Action;", "actions", "inflateSmartReplyState", "inflateSmartReplyViewHolder", "Lcom/android/systemui/statusbar/policy/InflatedSmartReplyViewHolder;", "sysuiContext", "Landroid/content/Context;", "notifPackageContext", "existingSmartReplyState", "newSmartReplyState"})
public final class SmartReplyStateInflaterImpl implements com.android.systemui.statusbar.policy.SmartReplyStateInflater {
    private final com.android.systemui.statusbar.policy.SmartReplyConstants constants = null;
    private final com.android.systemui.shared.system.ActivityManagerWrapper activityManagerWrapper = null;
    private final com.android.systemui.shared.system.PackageManagerWrapper packageManagerWrapper = null;
    private final com.android.systemui.shared.system.DevicePolicyManagerWrapper devicePolicyManagerWrapper = null;
    private final com.android.systemui.statusbar.policy.SmartReplyInflater smartRepliesInflater = null;
    private final com.android.systemui.statusbar.policy.SmartActionInflater smartActionsInflater = null;
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public com.android.systemui.statusbar.policy.InflatedSmartReplyState inflateSmartReplyState(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public com.android.systemui.statusbar.policy.InflatedSmartReplyViewHolder inflateSmartReplyViewHolder(@org.jetbrains.annotations.NotNull()
    android.content.Context sysuiContext, @org.jetbrains.annotations.NotNull()
    android.content.Context notifPackageContext, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.policy.InflatedSmartReplyState existingSmartReplyState, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.InflatedSmartReplyState newSmartReplyState) {
        return null;
    }
    
    /**
     * Chose what smart replies and smart actions to display. App generated suggestions take
     * precedence. So if the app provides any smart replies, we don't show any
     * replies or actions generated by the NotificationAssistantService (NAS), and if the app
     * provides any smart actions we also don't show any NAS-generated replies or actions.
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.policy.InflatedSmartReplyState chooseSmartRepliesAndActions(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
        return null;
    }
    
    /**
     * Filter actions so that only actions pointing to allowlisted apps are permitted.
     * This filtering is only meaningful when in lock-task mode.
     */
    private final java.util.List<android.app.Notification.Action> filterAllowlistedLockTaskApps(java.util.List<? extends android.app.Notification.Action> actions) {
        return null;
    }
    
    @javax.inject.Inject()
    public SmartReplyStateInflaterImpl(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.SmartReplyConstants constants, @org.jetbrains.annotations.NotNull()
    com.android.systemui.shared.system.ActivityManagerWrapper activityManagerWrapper, @org.jetbrains.annotations.NotNull()
    com.android.systemui.shared.system.PackageManagerWrapper packageManagerWrapper, @org.jetbrains.annotations.NotNull()
    com.android.systemui.shared.system.DevicePolicyManagerWrapper devicePolicyManagerWrapper, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.SmartReplyInflater smartRepliesInflater, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.SmartActionInflater smartActionsInflater) {
        super();
    }
}