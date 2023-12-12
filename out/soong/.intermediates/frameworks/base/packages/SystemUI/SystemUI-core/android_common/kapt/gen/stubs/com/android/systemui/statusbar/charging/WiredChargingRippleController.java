package com.android.systemui.statusbar.charging;

import android.content.Context;
import android.content.res.Configuration;
import android.graphics.PixelFormat;
import android.graphics.PointF;
import android.os.SystemProperties;
import android.util.DisplayMetrics;
import android.view.View;
import android.view.WindowManager;
import com.android.internal.annotations.VisibleForTesting;
import com.android.internal.logging.UiEvent;
import com.android.internal.logging.UiEventLogger;
import com.android.settingslib.Utils;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.statusbar.commandline.Command;
import com.android.systemui.statusbar.commandline.CommandRegistry;
import com.android.systemui.statusbar.policy.BatteryController;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.util.leak.RotationUtils;
import com.android.systemui.R;
import com.android.systemui.util.time.SystemClock;
import java.io.PrintWriter;
import javax.inject.Inject;

/**
 * *
 * Controls the ripple effect that shows when wired charging begins.
 * The ripple uses the accent color of the current theme.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000p\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\t\n\u0002\b\u0002\n\u0002\u0010\u0007\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0006\b\u0007\u0018\u00002\u00020\u0001:\u0002/0BG\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u0012\u0006\u0010\f\u001a\u00020\r\u0012\u0006\u0010\u000e\u001a\u00020\u000f\u0012\u0006\u0010\u0010\u001a\u00020\u0011\u00a2\u0006\u0002\u0010\u0012J\b\u0010)\u001a\u00020*H\u0002J\u0006\u0010+\u001a\u00020*J\r\u0010,\u001a\u00020*H\u0000\u00a2\u0006\u0002\b-J\b\u0010.\u001a\u00020*H\u0002R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0013\u001a\u00020\u0014X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010\u0015\u001a\u0004\u0018\u00010\u0016X\u0082\u000e\u00a2\u0006\u0004\n\u0002\u0010\u0017R\u000e\u0010\u0018\u001a\u00020\u0019X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001a\u001a\u00020\u0019X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0012\u0010\u001b\u001a\u0004\u0018\u00010\u001cX\u0082\u000e\u00a2\u0006\u0004\n\u0002\u0010\u001dR\u000e\u0010\u001e\u001a\u00020\u001cX\u0082\u0004\u00a2\u0006\u0002\n\u0000R$\u0010\u001f\u001a\u00020 8\u0006@\u0006X\u0087\u000e\u00a2\u0006\u0014\n\u0000\u0012\u0004\b!\u0010\"\u001a\u0004\b#\u0010$\"\u0004\b%\u0010&R\u000e\u0010\u000e\u001a\u00020\u000fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0010\u001a\u00020\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\'\u001a\u00020(X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/charging/WiredChargingRippleController;", "", "commandRegistry", "Lcom/android/systemui/statusbar/commandline/CommandRegistry;", "batteryController", "Lcom/android/systemui/statusbar/policy/BatteryController;", "configurationController", "Lcom/android/systemui/statusbar/policy/ConfigurationController;", "featureFlags", "Lcom/android/systemui/flags/FeatureFlags;", "context", "Landroid/content/Context;", "windowManager", "Landroid/view/WindowManager;", "systemClock", "Lcom/android/systemui/util/time/SystemClock;", "uiEventLogger", "Lcom/android/internal/logging/UiEventLogger;", "(Lcom/android/systemui/statusbar/commandline/CommandRegistry;Lcom/android/systemui/statusbar/policy/BatteryController;Lcom/android/systemui/statusbar/policy/ConfigurationController;Lcom/android/systemui/flags/FeatureFlags;Landroid/content/Context;Landroid/view/WindowManager;Lcom/android/systemui/util/time/SystemClock;Lcom/android/internal/logging/UiEventLogger;)V", "debounceLevel", "", "lastTriggerTime", "", "Ljava/lang/Long;", "normalizedPortPosX", "", "normalizedPortPosY", "pluggedIn", "", "Ljava/lang/Boolean;", "rippleEnabled", "rippleView", "Lcom/android/systemui/statusbar/charging/ChargingRippleView;", "getRippleView$annotations", "()V", "getRippleView", "()Lcom/android/systemui/statusbar/charging/ChargingRippleView;", "setRippleView", "(Lcom/android/systemui/statusbar/charging/ChargingRippleView;)V", "windowLayoutParams", "Landroid/view/WindowManager$LayoutParams;", "layoutRipple", "", "startRipple", "startRippleWithDebounce", "startRippleWithDebounce$main", "updateRippleColor", "ChargingRippleCommand", "WiredChargingRippleEvent"})
@com.android.systemui.dagger.SysUISingleton()
public final class WiredChargingRippleController {
    private java.lang.Boolean pluggedIn;
    private final boolean rippleEnabled = false;
    private float normalizedPortPosX;
    private float normalizedPortPosY;
    private final android.view.WindowManager.LayoutParams windowLayoutParams = null;
    private java.lang.Long lastTriggerTime;
    private int debounceLevel = 0;
    @org.jetbrains.annotations.NotNull()
    private com.android.systemui.statusbar.charging.ChargingRippleView rippleView;
    private final android.content.Context context = null;
    private final android.view.WindowManager windowManager = null;
    private final com.android.systemui.util.time.SystemClock systemClock = null;
    private final com.android.internal.logging.UiEventLogger uiEventLogger = null;
    
    @com.android.internal.annotations.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getRippleView$annotations() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.charging.ChargingRippleView getRippleView() {
        return null;
    }
    
    public final void setRippleView(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.charging.ChargingRippleView p0) {
    }
    
    public final void startRippleWithDebounce$main() {
    }
    
    public final void startRipple() {
    }
    
    private final void layoutRipple() {
    }
    
    private final void updateRippleColor() {
    }
    
    @javax.inject.Inject()
    public WiredChargingRippleController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.commandline.CommandRegistry commandRegistry, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.BatteryController batteryController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.ConfigurationController configurationController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.flags.FeatureFlags featureFlags, @org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    android.view.WindowManager windowManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.time.SystemClock systemClock, @org.jetbrains.annotations.NotNull()
    com.android.internal.logging.UiEventLogger uiEventLogger) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\"\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0010\u000e\n\u0000\b\u0086\u0004\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u001e\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u00062\f\u0010\u0007\u001a\b\u0012\u0004\u0012\u00020\t0\bH\u0016J\u0010\u0010\n\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u0006H\u0016"}, d2 = {"Lcom/android/systemui/statusbar/charging/WiredChargingRippleController$ChargingRippleCommand;", "Lcom/android/systemui/statusbar/commandline/Command;", "(Lcom/android/systemui/statusbar/charging/WiredChargingRippleController;)V", "execute", "", "pw", "Ljava/io/PrintWriter;", "args", "", "", "help"})
    public final class ChargingRippleCommand implements com.android.systemui.statusbar.commandline.Command {
        
        @java.lang.Override()
        public void execute(@org.jetbrains.annotations.NotNull()
        java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
        java.util.List<java.lang.String> args) {
        }
        
        @java.lang.Override()
        public void help(@org.jetbrains.annotations.NotNull()
        java.io.PrintWriter pw) {
        }
        
        public ChargingRippleCommand() {
            super();
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0010\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0003\b\u0086\u0001\u0018\u00002\b\u0012\u0004\u0012\u00020\u00000\u00012\u00020\u0002B\u000f\b\u0002\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\u0005J\b\u0010\u0006\u001a\u00020\u0004H\u0016R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000j\u0002\b\u0007"}, d2 = {"Lcom/android/systemui/statusbar/charging/WiredChargingRippleController$WiredChargingRippleEvent;", "", "Lcom/android/internal/logging/UiEventLogger$UiEventEnum;", "_id", "", "(Ljava/lang/String;II)V", "getId", "CHARGING_RIPPLE_PLAYED"})
    public static enum WiredChargingRippleEvent implements com.android.internal.logging.UiEventLogger.UiEventEnum {
        @com.android.internal.logging.UiEvent(doc = "Wired charging ripple effect played")
        /*public static final*/ CHARGING_RIPPLE_PLAYED /* = new CHARGING_RIPPLE_PLAYED(0) */;
        private final int _id = 0;
        
        @java.lang.Override()
        public int getId() {
            return 0;
        }
        
        WiredChargingRippleEvent(int _id) {
        }
    }
}