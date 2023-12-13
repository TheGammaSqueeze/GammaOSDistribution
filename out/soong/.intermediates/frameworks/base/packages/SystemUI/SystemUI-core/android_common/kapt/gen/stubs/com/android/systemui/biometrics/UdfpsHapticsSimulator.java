package com.android.systemui.biometrics;

import android.media.AudioAttributes;
import android.os.VibrationEffect;
import android.os.Vibrator;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.statusbar.commandline.Command;
import com.android.systemui.statusbar.commandline.CommandRegistry;
import java.io.PrintWriter;
import javax.inject.Inject;

/**
 * Used to simulate haptics that may be used for udfps authentication.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000F\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0010\u000e\n\u0002\b\u0002\b\u0007\u0018\u00002\u00020\u0001B!\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\b\u0010\u0004\u001a\u0004\u0018\u00010\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ\u001e\u0010\u0018\u001a\u00020\u00192\u0006\u0010\u001a\u001a\u00020\u001b2\f\u0010\u001c\u001a\b\u0012\u0004\u0012\u00020\u001e0\u001dH\u0016J\u0010\u0010\u001f\u001a\u00020\u00192\u0006\u0010\u001a\u001a\u00020\u001bH\u0016J\u000e\u0010 \u001a\u00020\u00192\u0006\u0010\u001a\u001a\u00020\u001bR\u0011\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\t\u0010\nR\u0019\u0010\u000b\u001a\n \r*\u0004\u0018\u00010\f0\f\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000e\u0010\u000fR\u001c\u0010\u0010\u001a\u0004\u0018\u00010\u0011X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0012\u0010\u0013\"\u0004\b\u0014\u0010\u0015R\u0013\u0010\u0004\u001a\u0004\u0018\u00010\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0016\u0010\u0017"}, d2 = {"Lcom/android/systemui/biometrics/UdfpsHapticsSimulator;", "Lcom/android/systemui/statusbar/commandline/Command;", "commandRegistry", "Lcom/android/systemui/statusbar/commandline/CommandRegistry;", "vibrator", "Landroid/os/Vibrator;", "keyguardUpdateMonitor", "Lcom/android/keyguard/KeyguardUpdateMonitor;", "(Lcom/android/systemui/statusbar/commandline/CommandRegistry;Landroid/os/Vibrator;Lcom/android/keyguard/KeyguardUpdateMonitor;)V", "getKeyguardUpdateMonitor", "()Lcom/android/keyguard/KeyguardUpdateMonitor;", "sonificationEffects", "Landroid/media/AudioAttributes;", "kotlin.jvm.PlatformType", "getSonificationEffects", "()Landroid/media/AudioAttributes;", "udfpsController", "Lcom/android/systemui/biometrics/UdfpsController;", "getUdfpsController", "()Lcom/android/systemui/biometrics/UdfpsController;", "setUdfpsController", "(Lcom/android/systemui/biometrics/UdfpsController;)V", "getVibrator", "()Landroid/os/Vibrator;", "execute", "", "pw", "Ljava/io/PrintWriter;", "args", "", "", "help", "invalidCommand"})
@com.android.systemui.dagger.SysUISingleton()
public final class UdfpsHapticsSimulator implements com.android.systemui.statusbar.commandline.Command {
    private final android.media.AudioAttributes sonificationEffects = null;
    @org.jetbrains.annotations.Nullable()
    private com.android.systemui.biometrics.UdfpsController udfpsController;
    @org.jetbrains.annotations.Nullable()
    private final android.os.Vibrator vibrator = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.keyguard.KeyguardUpdateMonitor keyguardUpdateMonitor = null;
    
    public final android.media.AudioAttributes getSonificationEffects() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.biometrics.UdfpsController getUdfpsController() {
        return null;
    }
    
    public final void setUdfpsController(@org.jetbrains.annotations.Nullable()
    com.android.systemui.biometrics.UdfpsController p0) {
    }
    
    @java.lang.Override()
    public void execute(@org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> args) {
    }
    
    @java.lang.Override()
    public void help(@org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw) {
    }
    
    public final void invalidCommand(@org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw) {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final android.os.Vibrator getVibrator() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.keyguard.KeyguardUpdateMonitor getKeyguardUpdateMonitor() {
        return null;
    }
    
    @javax.inject.Inject()
    public UdfpsHapticsSimulator(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.commandline.CommandRegistry commandRegistry, @org.jetbrains.annotations.Nullable()
    android.os.Vibrator vibrator, @org.jetbrains.annotations.NotNull()
    com.android.keyguard.KeyguardUpdateMonitor keyguardUpdateMonitor) {
        super();
    }
}