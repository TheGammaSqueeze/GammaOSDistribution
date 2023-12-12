package com.android.systemui.unfold;

import android.animation.ValueAnimator;
import android.content.Context;
import android.graphics.PixelFormat;
import android.hardware.devicestate.DeviceStateManager;
import android.hardware.devicestate.DeviceStateManager.FoldStateListener;
import android.hardware.display.DisplayManager;
import android.os.Handler;
import android.os.Trace;
import android.view.Choreographer;
import android.view.Display;
import android.view.DisplayInfo;
import android.view.Surface;
import android.view.SurfaceControl;
import android.view.SurfaceControlViewHost;
import android.view.SurfaceSession;
import android.view.WindowManager;
import android.view.WindowlessWindowManager;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.dagger.qualifiers.UiBackground;
import com.android.systemui.statusbar.LightRevealEffect;
import com.android.systemui.statusbar.LightRevealScrim;
import com.android.systemui.statusbar.LinearLightRevealEffect;
import com.android.systemui.unfold.UnfoldTransitionProgressProvider.TransitionProgressListener;
import com.android.wm.shell.displayareahelper.DisplayAreaHelper;
import java.util.Optional;
import java.util.concurrent.Executor;
import java.util.function.Consumer;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u008e\u0001\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0006\b\u0007\u0018\u00002\u00020\u0001:\u0003234BS\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\f\u0010\n\u001a\b\u0012\u0004\u0012\u00020\f0\u000b\u0012\b\b\u0001\u0010\r\u001a\u00020\u000e\u0012\b\b\u0001\u0010\u000f\u001a\u00020\u0010\u0012\b\b\u0001\u0010\u0011\u001a\u00020\u000e\u00a2\u0006\u0002\u0010\u0012J\u0014\u0010&\u001a\u00020\'2\n\b\u0002\u0010(\u001a\u0004\u0018\u00010)H\u0002J\b\u0010*\u001a\u00020+H\u0002J\b\u0010,\u001a\u00020\'H\u0002J\b\u0010-\u001a\u00020.H\u0002J\b\u0010/\u001a\u00020#H\u0002J\u0006\u00100\u001a\u00020\'J\u000e\u00101\u001a\u00020\'2\u0006\u0010(\u001a\u00020)R\u000e\u0010\u0011\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0013\u001a\u00020\u0014X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\n\u001a\b\u0012\u0004\u0012\u00020\f0\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0012\u0010\u0015\u001a\u00060\u0016R\u00020\u0000X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0017\u001a\u00020\u0018X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0019\u001a\u00020\u0018X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001a\u001a\u00020\u001bX\u0082.\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u001c\u001a\u0004\u0018\u00010\u001dX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u001e\u001a\u0004\u0018\u00010\u001fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010 \u001a\u00060!R\u00020\u0000X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\"\u001a\u00020#X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010$\u001a\u00020%X\u0082.\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/unfold/UnfoldLightRevealOverlayAnimation;", "", "context", "Landroid/content/Context;", "deviceStateManager", "Landroid/hardware/devicestate/DeviceStateManager;", "displayManager", "Landroid/hardware/display/DisplayManager;", "unfoldTransitionProgressProvider", "Lcom/android/systemui/unfold/UnfoldTransitionProgressProvider;", "displayAreaHelper", "Ljava/util/Optional;", "Lcom/android/wm/shell/displayareahelper/DisplayAreaHelper;", "executor", "Ljava/util/concurrent/Executor;", "handler", "Landroid/os/Handler;", "backgroundExecutor", "(Landroid/content/Context;Landroid/hardware/devicestate/DeviceStateManager;Landroid/hardware/display/DisplayManager;Lcom/android/systemui/unfold/UnfoldTransitionProgressProvider;Ljava/util/Optional;Ljava/util/concurrent/Executor;Landroid/os/Handler;Ljava/util/concurrent/Executor;)V", "currentRotation", "", "displayListener", "Lcom/android/systemui/unfold/UnfoldLightRevealOverlayAnimation$DisplayChangeListener;", "isFolded", "", "isUnfoldHandled", "overlayContainer", "Landroid/view/SurfaceControl;", "root", "Landroid/view/SurfaceControlViewHost;", "scrimView", "Lcom/android/systemui/statusbar/LightRevealScrim;", "transitionListener", "Lcom/android/systemui/unfold/UnfoldLightRevealOverlayAnimation$TransitionListener;", "unfoldedDisplayInfo", "Landroid/view/DisplayInfo;", "wwm", "Landroid/view/WindowlessWindowManager;", "addView", "", "onOverlayReady", "Ljava/lang/Runnable;", "createLightRevealEffect", "Lcom/android/systemui/statusbar/LightRevealEffect;", "ensureOverlayRemoved", "getLayoutParams", "Landroid/view/WindowManager$LayoutParams;", "getUnfoldedDisplayInfo", "init", "onScreenTurningOn", "DisplayChangeListener", "FoldListener", "TransitionListener"})
@SysUIUnfoldScope()
public final class UnfoldLightRevealOverlayAnimation {
    private final com.android.systemui.unfold.UnfoldLightRevealOverlayAnimation.TransitionListener transitionListener = null;
    private final com.android.systemui.unfold.UnfoldLightRevealOverlayAnimation.DisplayChangeListener displayListener = null;
    private android.view.WindowlessWindowManager wwm;
    private android.view.DisplayInfo unfoldedDisplayInfo;
    private android.view.SurfaceControl overlayContainer;
    private android.view.SurfaceControlViewHost root;
    private com.android.systemui.statusbar.LightRevealScrim scrimView;
    private boolean isFolded = false;
    private boolean isUnfoldHandled = true;
    private int currentRotation;
    private final android.content.Context context = null;
    private final android.hardware.devicestate.DeviceStateManager deviceStateManager = null;
    private final android.hardware.display.DisplayManager displayManager = null;
    private final com.android.systemui.unfold.UnfoldTransitionProgressProvider unfoldTransitionProgressProvider = null;
    private final java.util.Optional<com.android.wm.shell.displayareahelper.DisplayAreaHelper> displayAreaHelper = null;
    private final java.util.concurrent.Executor executor = null;
    private final android.os.Handler handler = null;
    private final java.util.concurrent.Executor backgroundExecutor = null;
    
    public final void init() {
    }
    
    /**
     * Called when screen starts turning on, the contents of the screen might not be visible yet.
     * This method reports back that the overlay is ready in [onOverlayReady] callback.
     *
     * @param onOverlayReady callback when the overlay is drawn and visible on the screen
     * @see [com.android.systemui.keyguard.KeyguardViewMediator]
     */
    public final void onScreenTurningOn(@org.jetbrains.annotations.NotNull()
    java.lang.Runnable onOverlayReady) {
    }
    
    private final void addView(java.lang.Runnable onOverlayReady) {
    }
    
    private final android.view.WindowManager.LayoutParams getLayoutParams() {
        return null;
    }
    
    private final com.android.systemui.statusbar.LightRevealEffect createLightRevealEffect() {
        return null;
    }
    
    private final void ensureOverlayRemoved() {
    }
    
    private final android.view.DisplayInfo getUnfoldedDisplayInfo() {
        return null;
    }
    
    @javax.inject.Inject()
    public UnfoldLightRevealOverlayAnimation(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    android.hardware.devicestate.DeviceStateManager deviceStateManager, @org.jetbrains.annotations.NotNull()
    android.hardware.display.DisplayManager displayManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.unfold.UnfoldTransitionProgressProvider unfoldTransitionProgressProvider, @org.jetbrains.annotations.NotNull()
    java.util.Optional<com.android.wm.shell.displayareahelper.DisplayAreaHelper> displayAreaHelper, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    java.util.concurrent.Executor executor, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    android.os.Handler handler, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.UiBackground()
    java.util.concurrent.Executor backgroundExecutor) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001a\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0010\u0007\n\u0000\b\u0082\u0004\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\b\u0010\u0003\u001a\u00020\u0004H\u0016J\u0010\u0010\u0005\u001a\u00020\u00042\u0006\u0010\u0006\u001a\u00020\u0007H\u0016J\b\u0010\b\u001a\u00020\u0004H\u0016"}, d2 = {"Lcom/android/systemui/unfold/UnfoldLightRevealOverlayAnimation$TransitionListener;", "Lcom/android/systemui/unfold/UnfoldTransitionProgressProvider$TransitionProgressListener;", "(Lcom/android/systemui/unfold/UnfoldLightRevealOverlayAnimation;)V", "onTransitionFinished", "", "onTransitionProgress", "progress", "", "onTransitionStarted"})
    final class TransitionListener implements com.android.systemui.unfold.UnfoldTransitionProgressProvider.TransitionProgressListener {
        
        @java.lang.Override()
        public void onTransitionProgress(float progress) {
        }
        
        @java.lang.Override()
        public void onTransitionFinished() {
        }
        
        @java.lang.Override()
        public void onTransitionStarted() {
        }
        
        public TransitionListener() {
            super();
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001a\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\b\u0082\u0004\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u0006H\u0016J\u0010\u0010\u0007\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u0006H\u0016J\u0010\u0010\b\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u0006H\u0016"}, d2 = {"Lcom/android/systemui/unfold/UnfoldLightRevealOverlayAnimation$DisplayChangeListener;", "Landroid/hardware/display/DisplayManager$DisplayListener;", "(Lcom/android/systemui/unfold/UnfoldLightRevealOverlayAnimation;)V", "onDisplayAdded", "", "displayId", "", "onDisplayChanged", "onDisplayRemoved"})
    final class DisplayChangeListener implements android.hardware.display.DisplayManager.DisplayListener {
        
        @java.lang.Override()
        public void onDisplayChanged(int displayId) {
        }
        
        @java.lang.Override()
        public void onDisplayAdded(int displayId) {
        }
        
        @java.lang.Override()
        public void onDisplayRemoved(int displayId) {
        }
        
        public DisplayChangeListener() {
            super();
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\n\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\b\u0082\u0004\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002"}, d2 = {"Lcom/android/systemui/unfold/UnfoldLightRevealOverlayAnimation$FoldListener;", "Landroid/hardware/devicestate/DeviceStateManager$FoldStateListener;", "(Lcom/android/systemui/unfold/UnfoldLightRevealOverlayAnimation;)V"})
    final class FoldListener extends android.hardware.devicestate.DeviceStateManager.FoldStateListener {
        
        public FoldListener() {
            super(null, null);
        }
    }
}