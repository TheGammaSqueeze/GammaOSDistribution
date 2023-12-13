package com.android.systemui.biometrics;

import android.content.Context;
import android.hardware.display.DisplayManager;
import android.os.Handler;
import android.os.IBinder;
import android.os.ServiceManager;
import android.view.Surface;
import com.android.systemui.biometrics.AuthController;
import com.android.systemui.dagger.qualifiers.DisplayId;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.dagger.qualifiers.UiBackground;
import com.android.systemui.Dependency;
import com.google.hardware.pixel.display.IDisplay;
import java.util.concurrent.Executor;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000f\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0007\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0007\n\u0002\u0018\u0002\n\u0002\b\u0005\u0018\u0000 +2\u00020\u00012\u00020\u00022\u00020\u0003:\u0001+B\r\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\b\u0010\u001d\u001a\u00020\u001eH\u0016J\u0012\u0010\u001f\u001a\u00020\u001e2\b\u0010 \u001a\u0004\u0018\u00010\u001cH\u0016J\u0014\u0010!\u001a\u00020\u001e2\n\b\u0002\u0010\"\u001a\u0004\u0018\u00010\u001cH\u0002J$\u0010#\u001a\u00020\u001e2\u0006\u0010$\u001a\u00020\u00132\b\u0010%\u001a\u0004\u0018\u00010&2\b\u0010\'\u001a\u0004\u0018\u00010\u001cH\u0016J\u0010\u0010(\u001a\u00020\u001e2\u0006\u0010\u0012\u001a\u00020\u0013H\u0016J\u0010\u0010)\u001a\u00020\u001e2\u0006\u0010\u0012\u001a\u00020\u0013H\u0016J\u0010\u0010*\u001a\u00020\u001e2\u0006\u0010\u0012\u001a\u00020\u0013H\u0016R\u0016\u0010\u0007\u001a\n \t*\u0004\u0018\u00010\b0\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0016\u0010\n\u001a\n \t*\u0004\u0018\u00010\u000b0\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\f\u001a\u00020\r8BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\u000e\u0010\u000fR\u0016\u0010\u0010\u001a\n \t*\u0004\u0018\u00010\u00110\u0011X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0013X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u0014\u001a\n \t*\u0004\u0018\u00010\u00150\u0015X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u0016\u001a\n \t*\u0004\u0018\u00010\u00170\u0017X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0018\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0019\u001a\u00020\u001aX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u001b\u001a\u0004\u0018\u00010\u001cX\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/biometrics/PixelUdfpsHbmProvider;", "Lcom/android/systemui/biometrics/UdfpsHbmProvider;", "Landroid/os/IBinder$DeathRecipient;", "Landroid/hardware/display/DisplayManager$DisplayListener;", "context", "Landroid/content/Context;", "(Landroid/content/Context;)V", "authController", "Lcom/android/systemui/biometrics/AuthController;", "kotlin.jvm.PlatformType", "bgExecutor", "Ljava/util/concurrent/Executor;", "currentRefreshRate", "", "getCurrentRefreshRate", "()F", "displayHal", "Lcom/google/hardware/pixel/display/IDisplay;", "displayId", "", "displayManager", "Landroid/hardware/display/DisplayManager;", "handler", "Landroid/os/Handler;", "peakRefreshRate", "pendingEnable", "", "pendingEnableCallback", "Ljava/lang/Runnable;", "binderDied", "", "disableHbm", "onHbmDisabled", "doPendingEnable", "callback", "enableHbm", "hbmType", "surface", "Landroid/view/Surface;", "onHbmEnabled", "onDisplayAdded", "onDisplayChanged", "onDisplayRemoved", "Companion"})
public final class PixelUdfpsHbmProvider implements com.android.systemui.biometrics.UdfpsHbmProvider, android.os.IBinder.DeathRecipient, android.hardware.display.DisplayManager.DisplayListener {
    private final com.android.systemui.biometrics.AuthController authController = null;
    private final java.util.concurrent.Executor bgExecutor = null;
    private final android.os.Handler handler = null;
    private final int displayId = 0;
    private final android.hardware.display.DisplayManager displayManager = null;
    private com.google.hardware.pixel.display.IDisplay displayHal;
    private final float peakRefreshRate = 0.0F;
    private volatile boolean pendingEnable = false;
    private volatile java.lang.Runnable pendingEnableCallback;
    private final android.content.Context context = null;
    private static final java.lang.String PIXEL_DISPLAY_HAL = "com.google.hardware.pixel.display.IDisplay/default";
    private static final int HBM_TYPE = com.android.systemui.biometrics.UdfpsHbmTypes.LOCAL_HBM;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.biometrics.PixelUdfpsHbmProvider.Companion Companion = null;
    
    private final float getCurrentRefreshRate() {
        return 0.0F;
    }
    
    @java.lang.Override()
    public void enableHbm(int hbmType, @org.jetbrains.annotations.Nullable()
    android.view.Surface surface, @org.jetbrains.annotations.Nullable()
    java.lang.Runnable onHbmEnabled) {
    }
    
    private final void doPendingEnable(java.lang.Runnable callback) {
    }
    
    @java.lang.Override()
    public void disableHbm(@org.jetbrains.annotations.Nullable()
    java.lang.Runnable onHbmDisabled) {
    }
    
    @java.lang.Override()
    public void onDisplayAdded(int displayId) {
    }
    
    @java.lang.Override()
    public void onDisplayRemoved(int displayId) {
    }
    
    @java.lang.Override()
    public void onDisplayChanged(int displayId) {
    }
    
    @java.lang.Override()
    public void binderDied() {
    }
    
    public PixelUdfpsHbmProvider(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/biometrics/PixelUdfpsHbmProvider$Companion;", "", "()V", "HBM_TYPE", "", "PIXEL_DISPLAY_HAL", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}