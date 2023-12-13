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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000D\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\u001a\u001a\u0010\u0004\u001a\u00020\u00012\b\u0010\u0005\u001a\u0004\u0018\u00010\u00062\b\u0010\u0007\u001a\u0004\u0018\u00010\u0006\u001a\u0016\u0010\b\u001a\u00020\u00012\u0006\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\u0006\u001a\"\u0010\f\u001a\u00020\r*\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u00012\f\u0010\u0010\u001a\b\u0012\u0004\u0012\u00020\u00010\u0011H\u0002\u001a,\u0010\u0012\u001a\u00020\r*\u00020\u00132\u0006\u0010\u0014\u001a\u00020\u00152\b\u0010\u0016\u001a\u0004\u0018\u00010\u00172\f\u0010\u0018\u001a\b\u0012\u0004\u0012\u00020\r0\u0011H\u0002\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082\u0004\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0002\u001a\u00020\u0003X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"DEBUG", "", "TAG", "", "areSuggestionsSimilar", "left", "Lcom/android/systemui/statusbar/policy/InflatedSmartReplyState;", "right", "shouldShowSmartReplyView", "entry", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "smartReplyState", "executeWhenUnlocked", "", "Lcom/android/systemui/statusbar/phone/KeyguardDismissUtil;", "requiresShadeOpen", "onDismissAction", "Lkotlin/Function0;", "startPendingIntentDismissingKeyguard", "Lcom/android/systemui/plugins/ActivityStarter;", "intent", "Landroid/app/PendingIntent;", "associatedView", "Landroid/view/View;", "runnable"})
public final class SmartReplyStateInflaterKt {
    private static final java.lang.String TAG = "SmartReplyViewInflater";
    private static final boolean DEBUG = false;
    
    /**
     * Returns whether we should show the smart reply view and its smart suggestions.
     */
    public static final boolean shouldShowSmartReplyView(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.InflatedSmartReplyState smartReplyState) {
        return false;
    }
    
    /**
     * Determines if two [InflatedSmartReplyState] are visually similar.
     */
    public static final boolean areSuggestionsSimilar(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.policy.InflatedSmartReplyState left, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.policy.InflatedSmartReplyState right) {
        return false;
    }
    
    private static final void executeWhenUnlocked(com.android.systemui.statusbar.phone.KeyguardDismissUtil $this$executeWhenUnlocked, boolean requiresShadeOpen, kotlin.jvm.functions.Function0<java.lang.Boolean> onDismissAction) {
    }
    
    private static final void startPendingIntentDismissingKeyguard(com.android.systemui.plugins.ActivityStarter $this$startPendingIntentDismissingKeyguard, android.app.PendingIntent intent, android.view.View associatedView, kotlin.jvm.functions.Function0<kotlin.Unit> runnable) {
    }
}