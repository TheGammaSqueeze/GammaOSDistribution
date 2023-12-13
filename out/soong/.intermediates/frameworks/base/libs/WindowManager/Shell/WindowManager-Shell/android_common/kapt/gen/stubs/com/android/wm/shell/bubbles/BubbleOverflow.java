package com.android.wm.shell.bubbles;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Matrix;
import android.graphics.Path;
import android.graphics.drawable.AdaptiveIconDrawable;
import android.graphics.drawable.ColorDrawable;
import android.graphics.drawable.InsetDrawable;
import android.util.PathParser;
import android.util.TypedValue;
import android.view.LayoutInflater;
import android.widget.FrameLayout;
import com.android.wm.shell.R;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\\\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0007\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\t\u0018\u0000 ,2\u00020\u0001:\u0001,B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u0006\u0010\u0016\u001a\u00020\u0017J\n\u0010\u0018\u001a\u0004\u0018\u00010\bH\u0016J\b\u0010\u0019\u001a\u00020\bH\u0016J\b\u0010\u001a\u001a\u00020\nH\u0016J\n\u0010\u001b\u001a\u0004\u0018\u00010\fH\u0016J\n\u0010\u001c\u001a\u0004\u0018\u00010\u000eH\u0016J\n\u0010\u001d\u001a\u0004\u0018\u00010\u0012H\u0016J\b\u0010\u001e\u001a\u00020\u001fH\u0016J\b\u0010 \u001a\u00020\nH\u0016J\u000e\u0010!\u001a\u00020\u00172\u0006\u0010\"\u001a\u00020#J\u000e\u0010$\u001a\u00020\u00172\u0006\u0010%\u001a\u00020\u0015J\u0010\u0010&\u001a\u00020\u00172\u0006\u0010\'\u001a\u00020\u0015H\u0016J\u000e\u0010(\u001a\u00020\u00172\u0006\u0010\'\u001a\u00020\nJ\b\u0010\u0014\u001a\u00020\u0015H\u0016J\u0006\u0010)\u001a\u00020\u0017J\b\u0010*\u001a\u00020\u0017H\u0002J\u0006\u0010+\u001a\u00020\u0017R\u000e\u0010\u0007\u001a\u00020\bX\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082.\u00a2\u0006\u0002\n\u0000R\u0010\u0010\r\u001a\u0004\u0018\u00010\u000eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0011\u001a\u0004\u0018\u00010\u0012X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0013\u001a\u00020\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0014\u001a\u00020\u0015X\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/wm/shell/bubbles/BubbleOverflow;", "Lcom/android/wm/shell/bubbles/BubbleViewProvider;", "context", "Landroid/content/Context;", "positioner", "Lcom/android/wm/shell/bubbles/BubblePositioner;", "(Landroid/content/Context;Lcom/android/wm/shell/bubbles/BubblePositioner;)V", "bitmap", "Landroid/graphics/Bitmap;", "dotColor", "", "dotPath", "Landroid/graphics/Path;", "expandedView", "Lcom/android/wm/shell/bubbles/BubbleExpandedView;", "inflater", "Landroid/view/LayoutInflater;", "overflowBtn", "Lcom/android/wm/shell/bubbles/BadgedImageView;", "overflowIconInset", "showDot", "", "cleanUpExpandedState", "", "getAppBadge", "getBubbleIcon", "getDotColor", "getDotPath", "getExpandedView", "getIconView", "getKey", "", "getTaskId", "initialize", "controller", "Lcom/android/wm/shell/bubbles/BubbleController;", "setShowDot", "show", "setTaskViewVisibility", "visible", "setVisible", "update", "updateBtnTheme", "updateResources", "Companion"})
public final class BubbleOverflow implements com.android.wm.shell.bubbles.BubbleViewProvider {
    private android.graphics.Bitmap bitmap;
    private android.graphics.Path dotPath;
    private int dotColor = 0;
    private boolean showDot = false;
    private int overflowIconInset = 0;
    private final android.view.LayoutInflater inflater = null;
    private com.android.wm.shell.bubbles.BubbleExpandedView expandedView;
    private com.android.wm.shell.bubbles.BadgedImageView overflowBtn;
    private final android.content.Context context = null;
    private final com.android.wm.shell.bubbles.BubblePositioner positioner = null;
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String KEY = "Overflow";
    @org.jetbrains.annotations.NotNull()
    public static final com.android.wm.shell.bubbles.BubbleOverflow.Companion Companion = null;
    
    /**
     * Call before use and again if cleanUpExpandedState was called.
     */
    public final void initialize(@org.jetbrains.annotations.NotNull()
    com.android.wm.shell.bubbles.BubbleController controller) {
    }
    
    public final void cleanUpExpandedState() {
    }
    
    public final void update() {
    }
    
    public final void updateResources() {
    }
    
    private final void updateBtnTheme() {
    }
    
    public final void setVisible(int visible) {
    }
    
    public final void setShowDot(boolean show) {
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public com.android.wm.shell.bubbles.BubbleExpandedView getExpandedView() {
        return null;
    }
    
    @java.lang.Override()
    public int getDotColor() {
        return 0;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public android.graphics.Bitmap getAppBadge() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.graphics.Bitmap getBubbleIcon() {
        return null;
    }
    
    @java.lang.Override()
    public boolean showDot() {
        return false;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public android.graphics.Path getDotPath() {
        return null;
    }
    
    @java.lang.Override()
    public void setTaskViewVisibility(boolean visible) {
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public com.android.wm.shell.bubbles.BadgedImageView getIconView() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String getKey() {
        return null;
    }
    
    @java.lang.Override()
    public int getTaskId() {
        return 0;
    }
    
    public BubbleOverflow(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.wm.shell.bubbles.BubblePositioner positioner) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/wm/shell/bubbles/BubbleOverflow$Companion;", "", "()V", "KEY", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}