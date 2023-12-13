package com.android.systemui.statusbar.notification.collection.render;

import android.annotation.MainThread;
import android.view.View;

/**
 * Given a "spec" that describes a "tree" of views, adds and removes views from the
 * [rootController] and its children until the actual tree matches the spec.
 *
 * Every node in the spec tree must specify both a view and its associated [NodeController].
 * Commands to add/remove/reorder children are sent to the controller. How the controller
 * interprets these commands is left to its own discretion -- it might add them directly to its
 * associated view or to some subview container.
 *
 * It's possible for nodes to mix "unmanaged" views in alongside managed ones within the same
 * container. In this case, whenever the differ runs it will move all unmanaged views to the end
 * of the node's child list.
 */
@android.annotation.MainThread()
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000H\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010%\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010$\n\u0002\b\u0003\n\u0002\u0010\u000e\n\u0002\b\n\u0018\u00002\u00020\u0001B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u000e\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u0010J$\u0010\u0011\u001a\u00020\u000e2\u0006\u0010\u0012\u001a\u00020\t2\u0012\u0010\u0013\u001a\u000e\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u00100\u0014H\u0002J$\u0010\u0015\u001a\u00020\u000e2\u0006\u0010\u0012\u001a\u00020\t2\u0012\u0010\u0013\u001a\u000e\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u00100\u0014H\u0002J\u0010\u0010\u0016\u001a\u00020\t2\u0006\u0010\u000f\u001a\u00020\u0010H\u0002J\u000e\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\fJ,\u0010\u001a\u001a\u00020\u000e2\u0006\u0010\u0012\u001a\u00020\t2\b\u0010\u001b\u001a\u0004\u0018\u00010\u00102\u0006\u0010\u001c\u001a\u00020\t2\b\u0010\u001d\u001a\u0004\u0018\u00010\u0010H\u0002J$\u0010\u001e\u001a\u00020\u000e2\u0006\u0010\u001f\u001a\u00020\u00102\u0012\u0010 \u001a\u000e\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u00100\bH\u0002J\u001c\u0010!\u001a\u000e\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\u00100\u00142\u0006\u0010\"\u001a\u00020\u0010H\u0002R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u0007\u001a\u000e\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\t0\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u000b\u001a\u000e\u0012\u0004\u0012\u00020\f\u0012\u0004\u0012\u00020\t0\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/render/ShadeViewDiffer;", "", "rootController", "Lcom/android/systemui/statusbar/notification/collection/render/NodeController;", "logger", "Lcom/android/systemui/statusbar/notification/collection/render/ShadeViewDifferLogger;", "(Lcom/android/systemui/statusbar/notification/collection/render/NodeController;Lcom/android/systemui/statusbar/notification/collection/render/ShadeViewDifferLogger;)V", "nodes", "", "Lcom/android/systemui/statusbar/notification/collection/render/ShadeNode;", "rootNode", "views", "Landroid/view/View;", "applySpec", "", "spec", "Lcom/android/systemui/statusbar/notification/collection/render/NodeSpec;", "attachChildren", "parentNode", "specMap", "", "detachChildren", "getNode", "getViewLabel", "", "view", "maybeDetachChild", "parentSpec", "childNode", "childSpec", "registerNodes", "node", "map", "treeToMap", "tree"})
public final class ShadeViewDiffer {
    private final com.android.systemui.statusbar.notification.collection.render.ShadeNode rootNode = null;
    private final java.util.Map<com.android.systemui.statusbar.notification.collection.render.NodeController, com.android.systemui.statusbar.notification.collection.render.ShadeNode> nodes = null;
    private final java.util.Map<android.view.View, com.android.systemui.statusbar.notification.collection.render.ShadeNode> views = null;
    private final com.android.systemui.statusbar.notification.collection.render.ShadeViewDifferLogger logger = null;
    
    /**
     * Adds and removes views from the root (and its children) until their structure matches the
     * provided [spec]. The root node of the spec must match the root controller passed to the
     * differ's constructor.
     */
    public final void applySpec(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.render.NodeSpec spec) {
    }
    
    /**
     * If [view] is managed by this differ, then returns the label of the view's controller.
     * Otherwise returns View.toString().
     *
     * For debugging purposes.
     */
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getViewLabel(@org.jetbrains.annotations.NotNull()
    android.view.View view) {
        return null;
    }
    
    private final void detachChildren(com.android.systemui.statusbar.notification.collection.render.ShadeNode parentNode, java.util.Map<com.android.systemui.statusbar.notification.collection.render.NodeController, ? extends com.android.systemui.statusbar.notification.collection.render.NodeSpec> specMap) {
    }
    
    private final void maybeDetachChild(com.android.systemui.statusbar.notification.collection.render.ShadeNode parentNode, com.android.systemui.statusbar.notification.collection.render.NodeSpec parentSpec, com.android.systemui.statusbar.notification.collection.render.ShadeNode childNode, com.android.systemui.statusbar.notification.collection.render.NodeSpec childSpec) {
    }
    
    private final void attachChildren(com.android.systemui.statusbar.notification.collection.render.ShadeNode parentNode, java.util.Map<com.android.systemui.statusbar.notification.collection.render.NodeController, ? extends com.android.systemui.statusbar.notification.collection.render.NodeSpec> specMap) {
    }
    
    private final com.android.systemui.statusbar.notification.collection.render.ShadeNode getNode(com.android.systemui.statusbar.notification.collection.render.NodeSpec spec) {
        return null;
    }
    
    private final java.util.Map<com.android.systemui.statusbar.notification.collection.render.NodeController, com.android.systemui.statusbar.notification.collection.render.NodeSpec> treeToMap(com.android.systemui.statusbar.notification.collection.render.NodeSpec tree) {
        return null;
    }
    
    private final void registerNodes(com.android.systemui.statusbar.notification.collection.render.NodeSpec node, java.util.Map<com.android.systemui.statusbar.notification.collection.render.NodeController, com.android.systemui.statusbar.notification.collection.render.NodeSpec> map) {
    }
    
    public ShadeViewDiffer(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.render.NodeController rootController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.render.ShadeViewDifferLogger logger) {
        super();
    }
}