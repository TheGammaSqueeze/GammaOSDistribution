package com.android.systemui.statusbar.notification.row.wrapper;

import android.content.Context;
import android.view.View;
import android.view.ViewGroup;
import com.android.internal.widget.CachingIconView;
import com.android.internal.widget.ConversationLayout;
import com.android.internal.widget.MessagingLinearLayout;
import com.android.systemui.R;
import com.android.systemui.statusbar.notification.NotificationFadeAware;
import com.android.systemui.statusbar.notification.NotificationUtils;
import com.android.systemui.statusbar.notification.row.ExpandableNotificationRow;

/**
 * Wraps a notification containing a conversation template
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000^\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u0007\n\u0002\b\u0004\n\u0002\u0010\u0002\n\u0002\b\b\n\u0002\u0018\u0002\n\u0002\b\u0002\u0018\u00002\u00020\u0001B\u001d\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ\u0018\u0010\u001d\u001a\u00020\u001e2\u0006\u0010\u001f\u001a\u00020 2\u0006\u0010!\u001a\u00020 H\u0016J\b\u0010\"\u001a\u00020\u001cH\u0016J\n\u0010#\u001a\u0004\u0018\u00010\u0005H\u0016J\u0010\u0010$\u001a\u00020%2\u0006\u0010\u0006\u001a\u00020\u0007H\u0016J\b\u0010&\u001a\u00020%H\u0002J\u0010\u0010\'\u001a\u00020%2\u0006\u0010(\u001a\u00020\u001eH\u0016J\u0010\u0010)\u001a\u00020%2\u0006\u0010*\u001a\u00020\u001eH\u0016J \u0010+\u001a\u00020%2\u0006\u0010,\u001a\u00020\u001e2\u0006\u0010-\u001a\u00020.2\u0006\u0010/\u001a\u00020\u001eH\u0016J\b\u00100\u001a\u00020%H\u0014R\u000e\u0010\t\u001a\u00020\u0005X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u0005X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\u0005X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\rX\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\u000fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0010\u001a\u00020\u0005X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0011\u001a\u00020\u0005X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0005X\u0082.\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0013\u001a\u0004\u0018\u00010\u0005X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0014\u001a\u0004\u0018\u00010\u0005X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0015\u001a\u0004\u0018\u00010\u0005X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0016\u001a\u00020\u0017X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0018\u001a\u00020\u0005X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0019\u001a\u00020\u001aX\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001b\u001a\u00020\u001cX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/row/wrapper/NotificationConversationTemplateViewWrapper;", "Lcom/android/systemui/statusbar/notification/row/wrapper/NotificationTemplateViewWrapper;", "ctx", "Landroid/content/Context;", "view", "Landroid/view/View;", "row", "Lcom/android/systemui/statusbar/notification/row/ExpandableNotificationRow;", "(Landroid/content/Context;Landroid/view/View;Lcom/android/systemui/statusbar/notification/row/ExpandableNotificationRow;)V", "appName", "conversationBadgeBg", "conversationIconContainer", "conversationIconView", "Lcom/android/internal/widget/CachingIconView;", "conversationLayout", "Lcom/android/internal/widget/ConversationLayout;", "conversationTitleView", "expandBtn", "expandBtnContainer", "facePileBottom", "facePileBottomBg", "facePileTop", "imageMessageContainer", "Landroid/view/ViewGroup;", "importanceRing", "messagingLinearLayout", "Lcom/android/internal/widget/MessagingLinearLayout;", "minHeightWithActions", "", "disallowSingleClick", "", "x", "", "y", "getMinLayoutHeight", "getShelfTransformationTarget", "onContentUpdated", "", "resolveViews", "setNotificationFaded", "faded", "setRemoteInputVisible", "visible", "updateExpandability", "expandable", "onClickListener", "Landroid/view/View$OnClickListener;", "requestLayout", "updateTransformedTypes"})
public final class NotificationConversationTemplateViewWrapper extends com.android.systemui.statusbar.notification.row.wrapper.NotificationTemplateViewWrapper {
    private final int minHeightWithActions = 0;
    private final com.android.internal.widget.ConversationLayout conversationLayout = null;
    private android.view.View conversationIconContainer;
    private com.android.internal.widget.CachingIconView conversationIconView;
    private android.view.View conversationBadgeBg;
    private android.view.View expandBtn;
    private android.view.View expandBtnContainer;
    private android.view.ViewGroup imageMessageContainer;
    private com.android.internal.widget.MessagingLinearLayout messagingLinearLayout;
    private android.view.View conversationTitleView;
    private android.view.View importanceRing;
    private android.view.View appName;
    private android.view.View facePileBottomBg;
    private android.view.View facePileBottom;
    private android.view.View facePileTop;
    
    private final void resolveViews() {
    }
    
    @java.lang.Override()
    public void onContentUpdated(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.row.ExpandableNotificationRow row) {
    }
    
    @java.lang.Override()
    protected void updateTransformedTypes() {
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public android.view.View getShelfTransformationTarget() {
        return null;
    }
    
    @java.lang.Override()
    public void setRemoteInputVisible(boolean visible) {
    }
    
    @java.lang.Override()
    public void updateExpandability(boolean expandable, @org.jetbrains.annotations.NotNull()
    android.view.View.OnClickListener onClickListener, boolean requestLayout) {
    }
    
    @java.lang.Override()
    public boolean disallowSingleClick(float x, float y) {
        return false;
    }
    
    @java.lang.Override()
    public int getMinLayoutHeight() {
        return 0;
    }
    
    @java.lang.Override()
    public void setNotificationFaded(boolean faded) {
    }
    
    public NotificationConversationTemplateViewWrapper(@org.jetbrains.annotations.NotNull()
    android.content.Context ctx, @org.jetbrains.annotations.NotNull()
    android.view.View view, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.row.ExpandableNotificationRow row) {
        super(null, null, null);
    }
}