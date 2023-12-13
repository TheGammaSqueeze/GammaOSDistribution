package com.android.systemui.statusbar.notification.collection.render;

import android.view.View;
import java.lang.RuntimeException;
import java.lang.StringBuilder;

/**
 * A controller that represents a single unit of addable/removable view(s) in the notification
 * shade. Some nodes are just a single view (such as a header), while some might involve many views
 * (such as a notification row).
 *
 * It's possible for nodes to support having child nodes (for example, some notification rows
 * contain other notification rows). If so, they must implement all of the child-related methods
 * below.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000.\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0005\n\u0002\u0010\u000b\bf\u0018\u00002\u00020\u0001J\u0018\u0010\n\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\u00002\u0006\u0010\r\u001a\u00020\u000eH\u0016J\u0012\u0010\u000f\u001a\u0004\u0018\u00010\u00072\u0006\u0010\r\u001a\u00020\u000eH\u0016J\b\u0010\u0010\u001a\u00020\u000eH\u0016J\u0018\u0010\u0011\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\u00002\u0006\u0010\r\u001a\u00020\u000eH\u0016J\u0018\u0010\u0012\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\u00002\u0006\u0010\u0013\u001a\u00020\u0014H\u0016R\u0012\u0010\u0002\u001a\u00020\u0003X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0004\u0010\u0005R\u0012\u0010\u0006\u001a\u00020\u0007X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\b\u0010\t"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/render/NodeController;", "", "nodeLabel", "", "getNodeLabel", "()Ljava/lang/String;", "view", "Landroid/view/View;", "getView", "()Landroid/view/View;", "addChildAt", "", "child", "index", "", "getChildAt", "getChildCount", "moveChildTo", "removeChild", "isTransfer", ""})
public abstract interface NodeController {
    
    /**
     * A string that uniquely(ish) represents the node in the tree. Used for debugging.
     */
    @org.jetbrains.annotations.NotNull()
    public abstract java.lang.String getNodeLabel();
    
    @org.jetbrains.annotations.NotNull()
    public abstract android.view.View getView();
    
    @org.jetbrains.annotations.Nullable()
    public abstract android.view.View getChildAt(int index);
    
    public abstract int getChildCount();
    
    public abstract void addChildAt(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.render.NodeController child, int index);
    
    public abstract void moveChildTo(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.render.NodeController child, int index);
    
    public abstract void removeChild(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.render.NodeController child, boolean isTransfer);
    
    /**
     * A controller that represents a single unit of addable/removable view(s) in the notification
     * shade. Some nodes are just a single view (such as a header), while some might involve many views
     * (such as a notification row).
     *
     * It's possible for nodes to support having child nodes (for example, some notification rows
     * contain other notification rows). If so, they must implement all of the child-related methods
     * below.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 3)
    public final class DefaultImpls {
        
        @org.jetbrains.annotations.Nullable()
        public static android.view.View getChildAt(@org.jetbrains.annotations.NotNull()
        com.android.systemui.statusbar.notification.collection.render.NodeController $this, int index) {
            return null;
        }
        
        public static int getChildCount(@org.jetbrains.annotations.NotNull()
        com.android.systemui.statusbar.notification.collection.render.NodeController $this) {
            return 0;
        }
        
        public static void addChildAt(@org.jetbrains.annotations.NotNull()
        com.android.systemui.statusbar.notification.collection.render.NodeController $this, @org.jetbrains.annotations.NotNull()
        com.android.systemui.statusbar.notification.collection.render.NodeController child, int index) {
        }
        
        public static void moveChildTo(@org.jetbrains.annotations.NotNull()
        com.android.systemui.statusbar.notification.collection.render.NodeController $this, @org.jetbrains.annotations.NotNull()
        com.android.systemui.statusbar.notification.collection.render.NodeController child, int index) {
        }
        
        public static void removeChild(@org.jetbrains.annotations.NotNull()
        com.android.systemui.statusbar.notification.collection.render.NodeController $this, @org.jetbrains.annotations.NotNull()
        com.android.systemui.statusbar.notification.collection.render.NodeController child, boolean isTransfer) {
        }
    }
}