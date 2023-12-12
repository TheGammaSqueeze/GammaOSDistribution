package com.android.systemui.statusbar.events;

import android.animation.Animator;
import android.annotation.UiThread;
import android.graphics.Point;
import android.graphics.Rect;
import android.util.Log;
import android.view.Gravity;
import android.view.View;
import android.widget.FrameLayout;
import com.android.internal.annotations.GuardedBy;
import com.android.systemui.animation.Interpolators;
import com.android.systemui.R;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.phone.StatusBarContentInsetsChangedListener;
import com.android.systemui.statusbar.phone.StatusBarContentInsetsProvider;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.util.concurrency.DelayableExecutor;
import com.android.systemui.util.leak.RotationUtils;
import com.android.systemui.util.leak.RotationUtils.Rotation;
import java.util.concurrent.Executor;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00000\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b+\b\u0082\b\u0018\u00002\u00020\u0001B\u009d\u0001\u0012\b\b\u0002\u0010\u0002\u001a\u00020\u0003\u0012\b\b\u0002\u0010\u0004\u001a\u00020\u0003\u0012\b\b\u0002\u0010\u0005\u001a\u00020\u0003\u0012\b\b\u0002\u0010\u0006\u001a\u00020\u0003\u0012\n\b\u0002\u0010\u0007\u001a\u0004\u0018\u00010\b\u0012\n\b\u0002\u0010\t\u001a\u0004\u0018\u00010\b\u0012\n\b\u0002\u0010\n\u001a\u0004\u0018\u00010\b\u0012\n\b\u0002\u0010\u000b\u001a\u0004\u0018\u00010\b\u0012\b\b\u0002\u0010\f\u001a\u00020\u0003\u0012\b\b\u0002\u0010\r\u001a\u00020\u000e\u0012\b\b\u0002\u0010\u000f\u001a\u00020\u000e\u0012\b\b\u0002\u0010\u0010\u001a\u00020\u000e\u0012\n\b\u0002\u0010\u0011\u001a\u0004\u0018\u00010\u0012\u0012\n\b\u0002\u0010\u0013\u001a\u0004\u0018\u00010\u0014\u00a2\u0006\u0002\u0010\u0015J\t\u0010)\u001a\u00020\u0003H\u00c6\u0003J\t\u0010*\u001a\u00020\u000eH\u00c6\u0003J\t\u0010+\u001a\u00020\u000eH\u00c6\u0003J\t\u0010,\u001a\u00020\u000eH\u00c6\u0003J\u000b\u0010-\u001a\u0004\u0018\u00010\u0012H\u00c6\u0003J\u000b\u0010.\u001a\u0004\u0018\u00010\u0014H\u00c6\u0003J\t\u0010/\u001a\u00020\u0003H\u00c6\u0003J\t\u00100\u001a\u00020\u0003H\u00c6\u0003J\t\u00101\u001a\u00020\u0003H\u00c6\u0003J\u000b\u00102\u001a\u0004\u0018\u00010\bH\u00c6\u0003J\u000b\u00103\u001a\u0004\u0018\u00010\bH\u00c6\u0003J\u000b\u00104\u001a\u0004\u0018\u00010\bH\u00c6\u0003J\u000b\u00105\u001a\u0004\u0018\u00010\bH\u00c6\u0003J\t\u00106\u001a\u00020\u0003H\u00c6\u0003J\u000e\u00107\u001a\u00020\b2\u0006\u00108\u001a\u00020\u000eJ\u00a1\u0001\u00109\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00032\b\b\u0002\u0010\u0005\u001a\u00020\u00032\b\b\u0002\u0010\u0006\u001a\u00020\u00032\n\b\u0002\u0010\u0007\u001a\u0004\u0018\u00010\b2\n\b\u0002\u0010\t\u001a\u0004\u0018\u00010\b2\n\b\u0002\u0010\n\u001a\u0004\u0018\u00010\b2\n\b\u0002\u0010\u000b\u001a\u0004\u0018\u00010\b2\b\b\u0002\u0010\f\u001a\u00020\u00032\b\b\u0002\u0010\r\u001a\u00020\u000e2\b\b\u0002\u0010\u000f\u001a\u00020\u000e2\b\b\u0002\u0010\u0010\u001a\u00020\u000e2\n\b\u0002\u0010\u0011\u001a\u0004\u0018\u00010\u00122\n\b\u0002\u0010\u0013\u001a\u0004\u0018\u00010\u0014H\u00c6\u0001J\u0013\u0010:\u001a\u00020\u00032\b\u0010;\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010<\u001a\u00020\u000eH\u00d6\u0001J\u000e\u0010=\u001a\u00020\u00032\u0006\u0010;\u001a\u00020\u0000J\u0006\u0010>\u001a\u00020\u0003J\t\u0010?\u001a\u00020\u0014H\u00d6\u0001R\u0013\u0010\u0013\u001a\u0004\u0018\u00010\u0014\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0016\u0010\u0017R\u0011\u0010\u0010\u001a\u00020\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0018\u0010\u0019R\u0013\u0010\u0011\u001a\u0004\u0018\u00010\u0012\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001a\u0010\u001bR\u0013\u0010\t\u001a\u0004\u0018\u00010\b\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001c\u0010\u001dR\u0011\u0010\f\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001e\u0010\u001fR\u0011\u0010\u000f\u001a\u00020\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b \u0010\u0019R\u0013\u0010\u0007\u001a\u0004\u0018\u00010\b\u00a2\u0006\b\n\u0000\u001a\u0004\b!\u0010\u001dR\u0011\u0010\u0006\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\"\u0010\u001fR\u0011\u0010\r\u001a\u00020\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b#\u0010\u0019R\u0013\u0010\u000b\u001a\u0004\u0018\u00010\b\u00a2\u0006\b\n\u0000\u001a\u0004\b$\u0010\u001dR\u0011\u0010\u0005\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b%\u0010\u001fR\u0011\u0010\u0004\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b&\u0010\u001fR\u0013\u0010\n\u001a\u0004\u0018\u00010\b\u00a2\u0006\b\n\u0000\u001a\u0004\b\'\u0010\u001dR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b(\u0010\u001f"}, d2 = {"Lcom/android/systemui/statusbar/events/ViewState;", "", "viewInitialized", "", "systemPrivacyEventIsActive", "shadeExpanded", "qsExpanded", "portraitRect", "Landroid/graphics/Rect;", "landscapeRect", "upsideDownRect", "seascapeRect", "layoutRtl", "rotation", "", "paddingTop", "cornerIndex", "designatedCorner", "Landroid/view/View;", "contentDescription", "", "(ZZZZLandroid/graphics/Rect;Landroid/graphics/Rect;Landroid/graphics/Rect;Landroid/graphics/Rect;ZIIILandroid/view/View;Ljava/lang/String;)V", "getContentDescription", "()Ljava/lang/String;", "getCornerIndex", "()I", "getDesignatedCorner", "()Landroid/view/View;", "getLandscapeRect", "()Landroid/graphics/Rect;", "getLayoutRtl", "()Z", "getPaddingTop", "getPortraitRect", "getQsExpanded", "getRotation", "getSeascapeRect", "getShadeExpanded", "getSystemPrivacyEventIsActive", "getUpsideDownRect", "getViewInitialized", "component1", "component10", "component11", "component12", "component13", "component14", "component2", "component3", "component4", "component5", "component6", "component7", "component8", "component9", "contentRectForRotation", "rot", "copy", "equals", "other", "hashCode", "needsLayout", "shouldShowDot", "toString"})
final class ViewState {
    private final boolean viewInitialized = false;
    private final boolean systemPrivacyEventIsActive = false;
    private final boolean shadeExpanded = false;
    private final boolean qsExpanded = false;
    @org.jetbrains.annotations.Nullable()
    private final android.graphics.Rect portraitRect = null;
    @org.jetbrains.annotations.Nullable()
    private final android.graphics.Rect landscapeRect = null;
    @org.jetbrains.annotations.Nullable()
    private final android.graphics.Rect upsideDownRect = null;
    @org.jetbrains.annotations.Nullable()
    private final android.graphics.Rect seascapeRect = null;
    private final boolean layoutRtl = false;
    private final int rotation = 0;
    private final int paddingTop = 0;
    private final int cornerIndex = 0;
    @org.jetbrains.annotations.Nullable()
    private final android.view.View designatedCorner = null;
    @org.jetbrains.annotations.Nullable()
    private final java.lang.String contentDescription = null;
    
    public final boolean shouldShowDot() {
        return false;
    }
    
    public final boolean needsLayout(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.events.ViewState other) {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.graphics.Rect contentRectForRotation(@com.android.systemui.util.leak.RotationUtils.Rotation()
    int rot) {
        return null;
    }
    
    public final boolean getViewInitialized() {
        return false;
    }
    
    public final boolean getSystemPrivacyEventIsActive() {
        return false;
    }
    
    public final boolean getShadeExpanded() {
        return false;
    }
    
    public final boolean getQsExpanded() {
        return false;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final android.graphics.Rect getPortraitRect() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final android.graphics.Rect getLandscapeRect() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final android.graphics.Rect getUpsideDownRect() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final android.graphics.Rect getSeascapeRect() {
        return null;
    }
    
    public final boolean getLayoutRtl() {
        return false;
    }
    
    public final int getRotation() {
        return 0;
    }
    
    public final int getPaddingTop() {
        return 0;
    }
    
    public final int getCornerIndex() {
        return 0;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final android.view.View getDesignatedCorner() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String getContentDescription() {
        return null;
    }
    
    public ViewState(boolean viewInitialized, boolean systemPrivacyEventIsActive, boolean shadeExpanded, boolean qsExpanded, @org.jetbrains.annotations.Nullable()
    android.graphics.Rect portraitRect, @org.jetbrains.annotations.Nullable()
    android.graphics.Rect landscapeRect, @org.jetbrains.annotations.Nullable()
    android.graphics.Rect upsideDownRect, @org.jetbrains.annotations.Nullable()
    android.graphics.Rect seascapeRect, boolean layoutRtl, int rotation, int paddingTop, int cornerIndex, @org.jetbrains.annotations.Nullable()
    android.view.View designatedCorner, @org.jetbrains.annotations.Nullable()
    java.lang.String contentDescription) {
        super();
    }
    
    public ViewState() {
        super();
    }
    
    public final boolean component1() {
        return false;
    }
    
    public final boolean component2() {
        return false;
    }
    
    public final boolean component3() {
        return false;
    }
    
    public final boolean component4() {
        return false;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final android.graphics.Rect component5() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final android.graphics.Rect component6() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final android.graphics.Rect component7() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final android.graphics.Rect component8() {
        return null;
    }
    
    public final boolean component9() {
        return false;
    }
    
    public final int component10() {
        return 0;
    }
    
    public final int component11() {
        return 0;
    }
    
    public final int component12() {
        return 0;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final android.view.View component13() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String component14() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.events.ViewState copy(boolean viewInitialized, boolean systemPrivacyEventIsActive, boolean shadeExpanded, boolean qsExpanded, @org.jetbrains.annotations.Nullable()
    android.graphics.Rect portraitRect, @org.jetbrains.annotations.Nullable()
    android.graphics.Rect landscapeRect, @org.jetbrains.annotations.Nullable()
    android.graphics.Rect upsideDownRect, @org.jetbrains.annotations.Nullable()
    android.graphics.Rect seascapeRect, boolean layoutRtl, int rotation, int paddingTop, int cornerIndex, @org.jetbrains.annotations.Nullable()
    android.view.View designatedCorner, @org.jetbrains.annotations.Nullable()
    java.lang.String contentDescription) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
}