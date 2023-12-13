package com.android.systemui.statusbar.notification.collection.render;

import android.view.View;
import java.lang.RuntimeException;
import java.lang.StringBuilder;

/**
 * Used to specify the tree of [NodeController]s that currently make up the shade.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001a\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010 \n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0005\bf\u0018\u00002\u00020\u0001R\u0018\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00000\u0003X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0004\u0010\u0005R\u0012\u0010\u0006\u001a\u00020\u0007X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\b\u0010\tR\u0014\u0010\n\u001a\u0004\u0018\u00010\u0000X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u000b\u0010\f"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/render/NodeSpec;", "", "children", "", "getChildren", "()Ljava/util/List;", "controller", "Lcom/android/systemui/statusbar/notification/collection/render/NodeController;", "getController", "()Lcom/android/systemui/statusbar/notification/collection/render/NodeController;", "parent", "getParent", "()Lcom/android/systemui/statusbar/notification/collection/render/NodeSpec;"})
public abstract interface NodeSpec {
    
    @org.jetbrains.annotations.Nullable()
    public abstract com.android.systemui.statusbar.notification.collection.render.NodeSpec getParent();
    
    @org.jetbrains.annotations.NotNull()
    public abstract com.android.systemui.statusbar.notification.collection.render.NodeController getController();
    
    @org.jetbrains.annotations.NotNull()
    public abstract java.util.List<com.android.systemui.statusbar.notification.collection.render.NodeSpec> getChildren();
}