package com.android.systemui.statusbar.notification.collection.render;

import android.annotation.MainThread;
import android.view.View;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00006\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u000e\n\u0002\b\b\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0005\n\u0002\u0010\u000b\b\u0002\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0016\u0010\u0014\u001a\u00020\u00152\u0006\u0010\u0016\u001a\u00020\u00002\u0006\u0010\u0017\u001a\u00020\u0018J\u0010\u0010\u0019\u001a\u0004\u0018\u00010\u00112\u0006\u0010\u0017\u001a\u00020\u0018J\u0006\u0010\u001a\u001a\u00020\u0018J\u0016\u0010\u001b\u001a\u00020\u00152\u0006\u0010\u0016\u001a\u00020\u00002\u0006\u0010\u0017\u001a\u00020\u0018J\u0016\u0010\u001c\u001a\u00020\u00152\u0006\u0010\u0016\u001a\u00020\u00002\u0006\u0010\u001d\u001a\u00020\u001eR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0005\u0010\u0006R\u0011\u0010\u0007\u001a\u00020\b8F\u00a2\u0006\u0006\u001a\u0004\b\t\u0010\nR\u001c\u0010\u000b\u001a\u0004\u0018\u00010\u0000X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\f\u0010\r\"\u0004\b\u000e\u0010\u000fR\u0011\u0010\u0010\u001a\u00020\u0011\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\u0013"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/render/ShadeNode;", "", "controller", "Lcom/android/systemui/statusbar/notification/collection/render/NodeController;", "(Lcom/android/systemui/statusbar/notification/collection/render/NodeController;)V", "getController", "()Lcom/android/systemui/statusbar/notification/collection/render/NodeController;", "label", "", "getLabel", "()Ljava/lang/String;", "parent", "getParent", "()Lcom/android/systemui/statusbar/notification/collection/render/ShadeNode;", "setParent", "(Lcom/android/systemui/statusbar/notification/collection/render/ShadeNode;)V", "view", "Landroid/view/View;", "getView", "()Landroid/view/View;", "addChildAt", "", "child", "index", "", "getChildAt", "getChildCount", "moveChildTo", "removeChild", "isTransfer", ""})
final class ShadeNode {
    @org.jetbrains.annotations.NotNull()
    private final android.view.View view = null;
    @org.jetbrains.annotations.Nullable()
    private com.android.systemui.statusbar.notification.collection.render.ShadeNode parent;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.statusbar.notification.collection.render.NodeController controller = null;
    
    @org.jetbrains.annotations.NotNull()
    public final android.view.View getView() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.notification.collection.render.ShadeNode getParent() {
        return null;
    }
    
    public final void setParent(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.render.ShadeNode p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getLabel() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final android.view.View getChildAt(int index) {
        return null;
    }
    
    public final int getChildCount() {
        return 0;
    }
    
    public final void addChildAt(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.render.ShadeNode child, int index) {
    }
    
    public final void moveChildTo(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.render.ShadeNode child, int index) {
    }
    
    public final void removeChild(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.render.ShadeNode child, boolean isTransfer) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.notification.collection.render.NodeController getController() {
        return null;
    }
    
    public ShadeNode(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.render.NodeController controller) {
        super();
    }
}