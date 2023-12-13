package com.android.systemui.statusbar.policy;

import android.app.Notification;
import com.android.systemui.statusbar.policy.SmartReplyView.SmartActions;
import com.android.systemui.statusbar.policy.SmartReplyView.SmartReplies;

/**
 * A storage for smart replies, smart actions, and related state
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000@\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0006\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\r\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0004\u0018\u00002\u00020\u0001:\u0001\u001eB-\b\u0000\u0012\b\u0010\u0002\u001a\u0004\u0018\u00010\u0003\u0012\b\u0010\u0004\u001a\u0004\u0018\u00010\u0005\u0012\b\u0010\u0006\u001a\u0004\u0018\u00010\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nR\u0011\u0010\b\u001a\u00020\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\fR\u0013\u0010\u0004\u001a\u0004\u0018\u00010\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\r\u0010\u000eR\u0017\u0010\u000f\u001a\b\u0012\u0004\u0012\u00020\u00110\u00108F\u00a2\u0006\u0006\u001a\u0004\b\u0012\u0010\u0013R\u0013\u0010\u0002\u001a\u0004\u0018\u00010\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0014\u0010\u0015R\u0017\u0010\u0016\u001a\b\u0012\u0004\u0012\u00020\u00170\u00108F\u00a2\u0006\u0006\u001a\u0004\b\u0018\u0010\u0013R\u0017\u0010\u0019\u001a\b\u0012\u0004\u0012\u00020\u001a0\u00108F\u00a2\u0006\u0006\u001a\u0004\b\u001b\u0010\u0013R\u0013\u0010\u0006\u001a\u0004\u0018\u00010\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001c\u0010\u001d"}, d2 = {"Lcom/android/systemui/statusbar/policy/InflatedSmartReplyState;", "", "smartReplies", "Lcom/android/systemui/statusbar/policy/SmartReplyView$SmartReplies;", "smartActions", "Lcom/android/systemui/statusbar/policy/SmartReplyView$SmartActions;", "suppressedActions", "Lcom/android/systemui/statusbar/policy/InflatedSmartReplyState$SuppressedActions;", "hasPhishingAction", "", "(Lcom/android/systemui/statusbar/policy/SmartReplyView$SmartReplies;Lcom/android/systemui/statusbar/policy/SmartReplyView$SmartActions;Lcom/android/systemui/statusbar/policy/InflatedSmartReplyState$SuppressedActions;Z)V", "getHasPhishingAction", "()Z", "getSmartActions", "()Lcom/android/systemui/statusbar/policy/SmartReplyView$SmartActions;", "smartActionsList", "", "Landroid/app/Notification$Action;", "getSmartActionsList", "()Ljava/util/List;", "getSmartReplies", "()Lcom/android/systemui/statusbar/policy/SmartReplyView$SmartReplies;", "smartRepliesList", "", "getSmartRepliesList", "suppressedActionIndices", "", "getSuppressedActionIndices", "getSuppressedActions", "()Lcom/android/systemui/statusbar/policy/InflatedSmartReplyState$SuppressedActions;", "SuppressedActions"})
public final class InflatedSmartReplyState {
    @org.jetbrains.annotations.Nullable()
    private final com.android.systemui.statusbar.policy.SmartReplyView.SmartReplies smartReplies = null;
    @org.jetbrains.annotations.Nullable()
    private final com.android.systemui.statusbar.policy.SmartReplyView.SmartActions smartActions = null;
    @org.jetbrains.annotations.Nullable()
    private final com.android.systemui.statusbar.policy.InflatedSmartReplyState.SuppressedActions suppressedActions = null;
    private final boolean hasPhishingAction = false;
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<java.lang.CharSequence> getSmartRepliesList() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<android.app.Notification.Action> getSmartActionsList() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<java.lang.Integer> getSuppressedActionIndices() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.policy.SmartReplyView.SmartReplies getSmartReplies() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.policy.SmartReplyView.SmartActions getSmartActions() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.policy.InflatedSmartReplyState.SuppressedActions getSuppressedActions() {
        return null;
    }
    
    public final boolean getHasPhishingAction() {
        return false;
    }
    
    public InflatedSmartReplyState(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.policy.SmartReplyView.SmartReplies smartReplies, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.policy.SmartReplyView.SmartActions smartActions, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.policy.InflatedSmartReplyState.SuppressedActions suppressedActions, boolean hasPhishingAction) {
        super();
    }
    
    /**
     * Data class for standard actions suppressed by the smart actions.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010 \n\u0002\u0010\b\n\u0002\b\u0003\u0018\u00002\u00020\u0001B\u0013\u0012\f\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u00a2\u0006\u0002\u0010\u0005R\u0017\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0006\u0010\u0007"}, d2 = {"Lcom/android/systemui/statusbar/policy/InflatedSmartReplyState$SuppressedActions;", "", "suppressedActionIndices", "", "", "(Ljava/util/List;)V", "getSuppressedActionIndices", "()Ljava/util/List;"})
    public static final class SuppressedActions {
        @org.jetbrains.annotations.NotNull()
        private final java.util.List<java.lang.Integer> suppressedActionIndices = null;
        
        @org.jetbrains.annotations.NotNull()
        public final java.util.List<java.lang.Integer> getSuppressedActionIndices() {
            return null;
        }
        
        public SuppressedActions(@org.jetbrains.annotations.NotNull()
        java.util.List<java.lang.Integer> suppressedActionIndices) {
            super();
        }
    }
}