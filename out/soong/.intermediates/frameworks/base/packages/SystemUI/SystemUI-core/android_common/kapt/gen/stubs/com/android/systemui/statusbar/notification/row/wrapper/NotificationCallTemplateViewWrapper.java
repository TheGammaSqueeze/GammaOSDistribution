package com.android.systemui.statusbar.notification.row.wrapper;

import android.content.Context;
import android.view.View;
import com.android.internal.widget.CachingIconView;
import com.android.internal.widget.CallLayout;
import com.android.systemui.R;
import com.android.systemui.statusbar.notification.NotificationFadeAware;
import com.android.systemui.statusbar.notification.NotificationUtils;
import com.android.systemui.statusbar.notification.row.ExpandableNotificationRow;

/**
 * Wraps a notification containing a call template
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000J\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u0007\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0002\b\u0004\u0018\u00002\u00020\u0001B\u001d\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ\u0018\u0010\u0014\u001a\u00020\u00152\u0006\u0010\u0016\u001a\u00020\u00172\u0006\u0010\u0018\u001a\u00020\u0017H\u0016J\b\u0010\u0019\u001a\u00020\u0013H\u0016J\u0010\u0010\u001a\u001a\u00020\u001b2\u0006\u0010\u0006\u001a\u00020\u0007H\u0016J\b\u0010\u001c\u001a\u00020\u001bH\u0002J\u0010\u0010\u001d\u001a\u00020\u001b2\u0006\u0010\u001e\u001a\u00020\u0015H\u0016J\b\u0010\u001f\u001a\u00020\u001bH\u0014R\u000e\u0010\t\u001a\u00020\u0005X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\u0005X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u0005X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\u000fX\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0010\u001a\u00020\u0005X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0011\u001a\u00020\u0005X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0013X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/row/wrapper/NotificationCallTemplateViewWrapper;", "Lcom/android/systemui/statusbar/notification/row/wrapper/NotificationTemplateViewWrapper;", "ctx", "Landroid/content/Context;", "view", "Landroid/view/View;", "row", "Lcom/android/systemui/statusbar/notification/row/ExpandableNotificationRow;", "(Landroid/content/Context;Landroid/view/View;Lcom/android/systemui/statusbar/notification/row/ExpandableNotificationRow;)V", "appName", "callLayout", "Lcom/android/internal/widget/CallLayout;", "conversationBadgeBg", "conversationIconContainer", "conversationIconView", "Lcom/android/internal/widget/CachingIconView;", "conversationTitleView", "expandBtn", "minHeightWithActions", "", "disallowSingleClick", "", "x", "", "y", "getMinLayoutHeight", "onContentUpdated", "", "resolveViews", "setNotificationFaded", "faded", "updateTransformedTypes"})
public final class NotificationCallTemplateViewWrapper extends com.android.systemui.statusbar.notification.row.wrapper.NotificationTemplateViewWrapper {
    private final int minHeightWithActions = 0;
    private final com.android.internal.widget.CallLayout callLayout = null;
    private android.view.View conversationIconContainer;
    private com.android.internal.widget.CachingIconView conversationIconView;
    private android.view.View conversationBadgeBg;
    private android.view.View expandBtn;
    private android.view.View appName;
    private android.view.View conversationTitleView;
    
    private final void resolveViews() {
    }
    
    @java.lang.Override()
    public void onContentUpdated(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.row.ExpandableNotificationRow row) {
    }
    
    @java.lang.Override()
    protected void updateTransformedTypes() {
    }
    
    @java.lang.Override()
    public boolean disallowSingleClick(float x, float y) {
        return false;
    }
    
    @java.lang.Override()
    public int getMinLayoutHeight() {
        return 0;
    }
    
    /**
     * Apply the faded state as a layer type change to the face pile view which needs to have
     * overlapping contents render precisely.
     */
    @java.lang.Override()
    public void setNotificationFaded(boolean faded) {
    }
    
    public NotificationCallTemplateViewWrapper(@org.jetbrains.annotations.NotNull()
    android.content.Context ctx, @org.jetbrains.annotations.NotNull()
    android.view.View view, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.row.ExpandableNotificationRow row) {
        super(null, null, null);
    }
}