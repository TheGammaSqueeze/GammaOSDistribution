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

/**
 * Understands how to keep the persistent privacy dot in the corner of the screen in
 * ScreenDecorations, which does not rotate with the device.
 *
 * The basic principle here is that each dot will sit in a box that is equal to the margins of the
 * status bar (specifically the status_bar_contents view in PhoneStatusBarView). Each dot container
 * will have its gravity set towards the corner (i.e., top-right corner gets top|right gravity), and
 * the contained ImageView will be set to center_vertical and away from the corner horizontally. The
 * Views will match the status bar top padding and status bar height so that the dot can appear to
 * reside directly after the status bar system contents (basically after the battery).
 *
 * NOTE: any operation that modifies views directly must run on the provided executor, because
 * these views are owned by ScreenDecorations and it runs in its own thread
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000~\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b(\b\u0007\u0018\u00002\u00020\u0001B1\b\u0007\u0012\b\b\u0001\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u00a2\u0006\u0002\u0010\fJ\u0018\u0010$\u001a\u00020%2\u0006\u0010&\u001a\u00020\u000e2\u0006\u0010\'\u001a\u00020(H\u0002J\u0010\u0010)\u001a\u00020%2\u0006\u0010*\u001a\u00020\u000eH\u0002J\u000e\u0010+\u001a\b\u0012\u0004\u0012\u00020-0,H\u0002J\u0018\u0010.\u001a\u00020/2\u0006\u00100\u001a\u00020\u000e2\u0006\u00101\u001a\u00020(H\u0002J&\u00102\u001a\u00020/2\u0006\u00103\u001a\u00020\u000e2\u0006\u00104\u001a\u00020\u000e2\u0006\u00105\u001a\u00020\u000e2\u0006\u00106\u001a\u00020\u000eJ\b\u00107\u001a\u00020(H\u0003J\b\u00108\u001a\u00020/H\u0002J\u0010\u00109\u001a\u00020/2\u0006\u0010:\u001a\u00020\u0013H\u0002J\u0018\u0010;\u001a\u00020%2\u0006\u0010&\u001a\u00020%2\u0006\u0010<\u001a\u00020%H\u0002J\b\u0010=\u001a\u00020/H\u0002J\u001a\u0010>\u001a\u0004\u0018\u00010\u000e2\u0006\u0010?\u001a\u00020%2\u0006\u0010@\u001a\u00020(H\u0002J\u0010\u0010A\u001a\u00020/2\u0006\u0010:\u001a\u00020\u0013H\u0002J\u0010\u0010B\u001a\u00020/2\u0006\u0010C\u001a\u00020%H\u0002J\b\u0010D\u001a\u00020/H\u0002J\u000e\u0010E\u001a\u00020/2\u0006\u0010F\u001a\u00020%J\u000e\u0010G\u001a\u00020/2\u0006\u0010H\u001a\u00020(J\u000e\u0010I\u001a\u00020/2\u0006\u0010J\u001a\u00020\u001fJ\u0018\u0010K\u001a\u00020/2\u0006\u00100\u001a\u00020\u000e2\u0006\u00101\u001a\u00020(H\u0002J \u0010L\u001a\u00020/2\u0006\u0010M\u001a\u00020%2\u0006\u0010?\u001a\u00020%2\u0006\u0010<\u001a\u00020%H\u0002J\u001a\u0010N\u001a\u00020/2\b\u0010O\u001a\u0004\u0018\u00010\u000e2\u0006\u0010P\u001a\u00020(H\u0002J\u0018\u0010Q\u001a\u00020/2\u0006\u0010<\u001a\u00020%2\u0006\u0010R\u001a\u00020%H\u0002J\b\u0010S\u001a\u00020/H\u0002J \u0010T\u001a\u00020%2\u0006\u0010&\u001a\u00020%2\u0006\u0010U\u001a\u00020%2\u0006\u0010V\u001a\u00020%H\u0002J\u000e\u0010W\u001a\u00020%*\u0004\u0018\u00010\u000eH\u0002R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u000eX\u0082.\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0010\u001a\u0004\u0018\u00010\u0011X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0013X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0014\u001a\u00020\u0015X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R \u0010\u0017\u001a\u00020\u00132\u0006\u0010\u0016\u001a\u00020\u00138\u0002@BX\u0083\u000e\u00a2\u0006\b\n\u0000\"\u0004\b\u0018\u0010\u0019R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001a\u001a\u00020\u001bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001c\u001a\u00020\u000eX\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001d\u001a\u00020\u000eX\u0082.\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u001e\u001a\u0004\u0018\u00010\u001fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001a\u0010 \u001a\b\u0012\u0004\u0012\u00020\u000e0!8BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\"\u0010#"}, d2 = {"Lcom/android/systemui/statusbar/events/PrivacyDotViewController;", "", "mainExecutor", "Ljava/util/concurrent/Executor;", "stateController", "Lcom/android/systemui/plugins/statusbar/StatusBarStateController;", "configurationController", "Lcom/android/systemui/statusbar/policy/ConfigurationController;", "contentInsetsProvider", "Lcom/android/systemui/statusbar/phone/StatusBarContentInsetsProvider;", "animationScheduler", "Lcom/android/systemui/statusbar/events/SystemStatusAnimationScheduler;", "(Ljava/util/concurrent/Executor;Lcom/android/systemui/plugins/statusbar/StatusBarStateController;Lcom/android/systemui/statusbar/policy/ConfigurationController;Lcom/android/systemui/statusbar/phone/StatusBarContentInsetsProvider;Lcom/android/systemui/statusbar/events/SystemStatusAnimationScheduler;)V", "bl", "Landroid/view/View;", "br", "cancelRunnable", "Ljava/lang/Runnable;", "currentViewState", "Lcom/android/systemui/statusbar/events/ViewState;", "lock", "Ljava/lang/Object;", "value", "nextViewState", "setNextViewState", "(Lcom/android/systemui/statusbar/events/ViewState;)V", "systemStatusAnimationCallback", "Lcom/android/systemui/statusbar/events/SystemStatusAnimationCallback;", "tl", "tr", "uiExecutor", "Lcom/android/systemui/util/concurrency/DelayableExecutor;", "views", "Lkotlin/sequences/Sequence;", "getViews", "()Lkotlin/sequences/Sequence;", "activeRotationForCorner", "", "corner", "rtl", "", "cornerForView", "v", "getLayoutRects", "", "Landroid/graphics/Rect;", "hideDotView", "", "dot", "animate", "initialize", "topLeft", "topRight", "bottomLeft", "bottomRight", "isShadeInQs", "processNextViewState", "resolveState", "state", "rotatedCorner", "rotation", "scheduleUpdate", "selectDesignatedCorner", "r", "isRtl", "setCornerSizes", "setCornerVisibilities", "vis", "setNewLayoutRects", "setNewRotation", "rot", "setQsExpanded", "expanded", "setUiExecutor", "e", "showDotView", "updateCornerSizes", "l", "updateDesignatedCorner", "newCorner", "shouldShowDot", "updateRotations", "paddingTop", "updateStatusBarState", "widthForCorner", "left", "right", "cornerIndex"})
@com.android.systemui.dagger.SysUISingleton()
public final class PrivacyDotViewController {
    private android.view.View tl;
    private android.view.View tr;
    private android.view.View bl;
    private android.view.View br;
    private com.android.systemui.statusbar.events.ViewState currentViewState;
    @com.android.internal.annotations.GuardedBy(value = {"lock"})
    private com.android.systemui.statusbar.events.ViewState nextViewState;
    private final java.lang.Object lock = null;
    private java.lang.Runnable cancelRunnable;
    private com.android.systemui.util.concurrency.DelayableExecutor uiExecutor;
    private final com.android.systemui.statusbar.events.SystemStatusAnimationCallback systemStatusAnimationCallback = null;
    private final java.util.concurrent.Executor mainExecutor = null;
    private final com.android.systemui.plugins.statusbar.StatusBarStateController stateController = null;
    private final com.android.systemui.statusbar.policy.ConfigurationController configurationController = null;
    private final com.android.systemui.statusbar.phone.StatusBarContentInsetsProvider contentInsetsProvider = null;
    private final com.android.systemui.statusbar.events.SystemStatusAnimationScheduler animationScheduler = null;
    
    private final void setNextViewState(com.android.systemui.statusbar.events.ViewState value) {
    }
    
    private final kotlin.sequences.Sequence<android.view.View> getViews() {
        return null;
    }
    
    public final void setUiExecutor(@org.jetbrains.annotations.NotNull()
    com.android.systemui.util.concurrency.DelayableExecutor e) {
    }
    
    public final void setQsExpanded(boolean expanded) {
    }
    
    @android.annotation.UiThread()
    public final void setNewRotation(int rot) {
    }
    
    @android.annotation.UiThread()
    private final void hideDotView(android.view.View dot, boolean animate) {
    }
    
    @android.annotation.UiThread()
    private final void showDotView(android.view.View dot, boolean animate) {
    }
    
    @android.annotation.UiThread()
    private final void updateRotations(int rotation, int paddingTop) {
    }
    
    @android.annotation.UiThread()
    private final void updateCornerSizes(int l, int r, int rotation) {
    }
    
    @android.annotation.UiThread()
    private final void setCornerSizes(com.android.systemui.statusbar.events.ViewState state) {
    }
    
    @android.annotation.UiThread()
    private final android.view.View selectDesignatedCorner(int r, boolean isRtl) {
        return null;
    }
    
    @android.annotation.UiThread()
    private final void updateDesignatedCorner(android.view.View newCorner, boolean shouldShowDot) {
    }
    
    @android.annotation.UiThread()
    private final void setCornerVisibilities(int vis) {
    }
    
    private final int cornerForView(android.view.View v) {
        return 0;
    }
    
    private final int rotatedCorner(int corner, int rotation) {
        return 0;
    }
    
    @com.android.systemui.util.leak.RotationUtils.Rotation()
    private final int activeRotationForCorner(android.view.View corner, boolean rtl) {
        return 0;
    }
    
    private final int widthForCorner(int corner, int left, int right) {
        return 0;
    }
    
    public final void initialize(@org.jetbrains.annotations.NotNull()
    android.view.View topLeft, @org.jetbrains.annotations.NotNull()
    android.view.View topRight, @org.jetbrains.annotations.NotNull()
    android.view.View bottomLeft, @org.jetbrains.annotations.NotNull()
    android.view.View bottomRight) {
    }
    
    private final void updateStatusBarState() {
    }
    
    /**
     * If we are unlocked with an expanded shade, QS is showing. On keyguard, the shade is always
     * expanded so we use other signals from the panel view controller to know if QS is expanded
     */
    @com.android.internal.annotations.GuardedBy(value = {"lock"})
    private final boolean isShadeInQs() {
        return false;
    }
    
    private final void scheduleUpdate() {
    }
    
    @android.annotation.UiThread()
    private final void processNextViewState() {
    }
    
    @android.annotation.UiThread()
    private final void resolveState(com.android.systemui.statusbar.events.ViewState state) {
    }
    
    private final int cornerIndex(android.view.View $this$cornerIndex) {
        return 0;
    }
    
    private final java.util.List<android.graphics.Rect> getLayoutRects() {
        return null;
    }
    
    private final void setNewLayoutRects() {
    }
    
    @javax.inject.Inject()
    public PrivacyDotViewController(@org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    java.util.concurrent.Executor mainExecutor, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.statusbar.StatusBarStateController stateController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.ConfigurationController configurationController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.StatusBarContentInsetsProvider contentInsetsProvider, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.events.SystemStatusAnimationScheduler animationScheduler) {
        super();
    }
}