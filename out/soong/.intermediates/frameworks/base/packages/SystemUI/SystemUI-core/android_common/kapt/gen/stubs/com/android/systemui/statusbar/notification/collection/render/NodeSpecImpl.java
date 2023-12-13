package com.android.systemui.statusbar.notification.collection.render;

import android.view.View;
import java.lang.RuntimeException;
import java.lang.StringBuilder;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010!\n\u0002\b\u0006\u0018\u00002\u00020\u0001B\u0017\u0012\b\u0010\u0002\u001a\u0004\u0018\u00010\u0001\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\u0005R\u001a\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\u00010\u0007X\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\b\u0010\tR\u0014\u0010\u0003\u001a\u00020\u0004X\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\u000bR\u0016\u0010\u0002\u001a\u0004\u0018\u00010\u0001X\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\r"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/render/NodeSpecImpl;", "Lcom/android/systemui/statusbar/notification/collection/render/NodeSpec;", "parent", "controller", "Lcom/android/systemui/statusbar/notification/collection/render/NodeController;", "(Lcom/android/systemui/statusbar/notification/collection/render/NodeSpec;Lcom/android/systemui/statusbar/notification/collection/render/NodeController;)V", "children", "", "getChildren", "()Ljava/util/List;", "getController", "()Lcom/android/systemui/statusbar/notification/collection/render/NodeController;", "getParent", "()Lcom/android/systemui/statusbar/notification/collection/render/NodeSpec;"})
public final class NodeSpecImpl implements com.android.systemui.statusbar.notification.collection.render.NodeSpec {
    @org.jetbrains.annotations.NotNull()
    private final java.util.List<com.android.systemui.statusbar.notification.collection.render.NodeSpec> children = null;
    @org.jetbrains.annotations.Nullable()
    private final com.android.systemui.statusbar.notification.collection.render.NodeSpec parent = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.statusbar.notification.collection.render.NodeController controller = null;
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.util.List<com.android.systemui.statusbar.notification.collection.render.NodeSpec> getChildren() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public com.android.systemui.statusbar.notification.collection.render.NodeSpec getParent() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public com.android.systemui.statusbar.notification.collection.render.NodeController getController() {
        return null;
    }
    
    public NodeSpecImpl(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.render.NodeSpec parent, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.render.NodeController controller) {
        super();
    }
}