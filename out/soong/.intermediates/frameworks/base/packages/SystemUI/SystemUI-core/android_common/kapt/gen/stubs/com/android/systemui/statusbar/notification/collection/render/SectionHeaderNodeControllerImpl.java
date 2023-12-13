package com.android.systemui.statusbar.notification.collection.render;

import android.annotation.StringRes;
import android.content.Intent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import com.android.systemui.R;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.statusbar.notification.dagger.HeaderClickAction;
import com.android.systemui.statusbar.notification.dagger.HeaderText;
import com.android.systemui.statusbar.notification.dagger.NodeLabel;
import com.android.systemui.statusbar.notification.dagger.SectionHeaderScope;
import com.android.systemui.statusbar.notification.stack.SectionHeaderView;
import javax.inject.Inject;

@com.android.systemui.statusbar.notification.dagger.SectionHeaderScope()
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000R\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\b\u0001\u0018\u00002\u00020\u00012\u00020\u0002B5\b\u0007\u0012\b\b\u0001\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\b\b\u0001\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u0012\b\b\u0001\u0010\u000b\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\fJ\u0010\u0010\u001d\u001a\u00020\u001e2\u0006\u0010\u001f\u001a\u00020 H\u0016J\u0010\u0010!\u001a\u00020\u001e2\u0006\u0010\"\u001a\u00020\u0010H\u0016J\u0010\u0010#\u001a\u00020\u001e2\u0006\u0010$\u001a\u00020\u0012H\u0016R\u0010\u0010\r\u001a\u0004\u0018\u00010\u000eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0011\u001a\u0004\u0018\u00010\u0012X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u0013\u001a\u0004\u0018\u00010\u000e8VX\u0096\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0014\u0010\u0015R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0003\u001a\u00020\u0004X\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0016\u0010\u0017R\u000e\u0010\u0018\u001a\u00020\u0012X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0019\u001a\u00020\u001a8VX\u0096\u0004\u00a2\u0006\u0006\u001a\u0004\b\u001b\u0010\u001c"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/render/SectionHeaderNodeControllerImpl;", "Lcom/android/systemui/statusbar/notification/collection/render/NodeController;", "Lcom/android/systemui/statusbar/notification/collection/render/SectionHeaderController;", "nodeLabel", "", "layoutInflater", "Landroid/view/LayoutInflater;", "headerTextResId", "", "activityStarter", "Lcom/android/systemui/plugins/ActivityStarter;", "clickIntentAction", "(Ljava/lang/String;Landroid/view/LayoutInflater;ILcom/android/systemui/plugins/ActivityStarter;Ljava/lang/String;)V", "_view", "Lcom/android/systemui/statusbar/notification/stack/SectionHeaderView;", "clearAllButtonEnabled", "", "clearAllClickListener", "Landroid/view/View$OnClickListener;", "headerView", "getHeaderView", "()Lcom/android/systemui/statusbar/notification/stack/SectionHeaderView;", "getNodeLabel", "()Ljava/lang/String;", "onHeaderClickListener", "view", "Landroid/view/View;", "getView", "()Landroid/view/View;", "reinflateView", "", "parent", "Landroid/view/ViewGroup;", "setClearSectionEnabled", "enabled", "setOnClearSectionClickListener", "listener"})
public final class SectionHeaderNodeControllerImpl implements com.android.systemui.statusbar.notification.collection.render.NodeController, com.android.systemui.statusbar.notification.collection.render.SectionHeaderController {
    private com.android.systemui.statusbar.notification.stack.SectionHeaderView _view;
    private boolean clearAllButtonEnabled = false;
    private android.view.View.OnClickListener clearAllClickListener;
    private final android.view.View.OnClickListener onHeaderClickListener = null;
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String nodeLabel = null;
    private final android.view.LayoutInflater layoutInflater = null;
    private final int headerTextResId = 0;
    private final com.android.systemui.plugins.ActivityStarter activityStarter = null;
    private final java.lang.String clickIntentAction = null;
    
    @java.lang.Override()
    public void reinflateView(@org.jetbrains.annotations.NotNull()
    android.view.ViewGroup parent) {
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public com.android.systemui.statusbar.notification.stack.SectionHeaderView getHeaderView() {
        return null;
    }
    
    @java.lang.Override()
    public void setClearSectionEnabled(boolean enabled) {
    }
    
    @java.lang.Override()
    public void setOnClearSectionClickListener(@org.jetbrains.annotations.NotNull()
    android.view.View.OnClickListener listener) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.view.View getView() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String getNodeLabel() {
        return null;
    }
    
    @javax.inject.Inject()
    public SectionHeaderNodeControllerImpl(@org.jetbrains.annotations.NotNull()
    @com.android.systemui.statusbar.notification.dagger.NodeLabel()
    java.lang.String nodeLabel, @org.jetbrains.annotations.NotNull()
    android.view.LayoutInflater layoutInflater, @android.annotation.StringRes()
    @com.android.systemui.statusbar.notification.dagger.HeaderText()
    int headerTextResId, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.ActivityStarter activityStarter, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.statusbar.notification.dagger.HeaderClickAction()
    java.lang.String clickIntentAction) {
        super();
    }
    
    @org.jetbrains.annotations.Nullable()
    public android.view.View getChildAt(int index) {
        return null;
    }
    
    public int getChildCount() {
        return 0;
    }
    
    public void addChildAt(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.render.NodeController child, int index) {
    }
    
    public void moveChildTo(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.render.NodeController child, int index) {
    }
    
    public void removeChild(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.render.NodeController child, boolean isTransfer) {
    }
}