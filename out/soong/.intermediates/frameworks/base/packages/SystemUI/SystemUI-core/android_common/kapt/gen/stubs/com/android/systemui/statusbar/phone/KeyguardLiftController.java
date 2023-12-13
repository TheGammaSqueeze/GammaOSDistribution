package com.android.systemui.statusbar.phone;

import android.hardware.Sensor;
import android.hardware.TriggerEvent;
import android.hardware.TriggerEventListener;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.keyguard.KeyguardUpdateMonitorCallback;
import com.android.systemui.Dumpable;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.util.Assert;
import com.android.systemui.util.sensors.AsyncSensorManager;
import java.io.FileDescriptor;
import java.io.PrintWriter;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000`\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\u0010\u000e\n\u0002\b\b\u0018\u00002\u00020\u00012\u00020\u00022\u00020\u0003B%\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u00a2\u0006\u0002\u0010\fJ-\u0010\u0015\u001a\u00020\u00162\u0006\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\u001a2\u000e\u0010\u001b\u001a\n\u0012\u0006\b\u0001\u0012\u00020\u001d0\u001cH\u0016\u00a2\u0006\u0002\u0010\u001eJ\u0010\u0010\u001f\u001a\u00020\u00162\u0006\u0010 \u001a\u00020\u000eH\u0016J\u0010\u0010!\u001a\u00020\u00162\u0006\u0010\"\u001a\u00020\u000eH\u0016J\u0010\u0010#\u001a\u00020\u00162\u0006\u0010$\u001a\u00020\u000eH\u0016J\b\u0010%\u001a\u00020\u0016H\u0002R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u000eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0010\u001a\u00020\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u0012\u001a\n \u0014*\u0004\u0018\u00010\u00130\u0013X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/phone/KeyguardLiftController;", "Lcom/android/systemui/plugins/statusbar/StatusBarStateController$StateListener;", "Lcom/android/systemui/Dumpable;", "Lcom/android/keyguard/KeyguardUpdateMonitorCallback;", "statusBarStateController", "Lcom/android/systemui/plugins/statusbar/StatusBarStateController;", "asyncSensorManager", "Lcom/android/systemui/util/sensors/AsyncSensorManager;", "keyguardUpdateMonitor", "Lcom/android/keyguard/KeyguardUpdateMonitor;", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "(Lcom/android/systemui/plugins/statusbar/StatusBarStateController;Lcom/android/systemui/util/sensors/AsyncSensorManager;Lcom/android/keyguard/KeyguardUpdateMonitor;Lcom/android/systemui/dump/DumpManager;)V", "bouncerVisible", "", "isListening", "listener", "Landroid/hardware/TriggerEventListener;", "pickupSensor", "Landroid/hardware/Sensor;", "kotlin.jvm.PlatformType", "dump", "", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "onDozingChanged", "isDozing", "onKeyguardBouncerChanged", "bouncer", "onKeyguardVisibilityChanged", "showing", "updateListeningState"})
public final class KeyguardLiftController extends com.android.keyguard.KeyguardUpdateMonitorCallback implements com.android.systemui.plugins.statusbar.StatusBarStateController.StateListener, com.android.systemui.Dumpable {
    private final android.hardware.Sensor pickupSensor = null;
    private boolean isListening = false;
    private boolean bouncerVisible = false;
    private final android.hardware.TriggerEventListener listener = null;
    private final com.android.systemui.plugins.statusbar.StatusBarStateController statusBarStateController = null;
    private final com.android.systemui.util.sensors.AsyncSensorManager asyncSensorManager = null;
    private final com.android.keyguard.KeyguardUpdateMonitor keyguardUpdateMonitor = null;
    
    @java.lang.Override()
    public void onDozingChanged(boolean isDozing) {
    }
    
    @java.lang.Override()
    public void onKeyguardBouncerChanged(boolean bouncer) {
    }
    
    @java.lang.Override()
    public void onKeyguardVisibilityChanged(boolean showing) {
    }
    
    @java.lang.Override()
    public void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    private final void updateListeningState() {
    }
    
    public KeyguardLiftController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.statusbar.StatusBarStateController statusBarStateController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.sensors.AsyncSensorManager asyncSensorManager, @org.jetbrains.annotations.NotNull()
    com.android.keyguard.KeyguardUpdateMonitor keyguardUpdateMonitor, @org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager) {
        super();
    }
}