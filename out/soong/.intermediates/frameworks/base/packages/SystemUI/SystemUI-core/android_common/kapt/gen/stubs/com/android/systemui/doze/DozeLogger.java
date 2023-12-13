package com.android.systemui.doze;

import android.view.Display;
import com.android.systemui.doze.DozeLog.Reason;
import com.android.systemui.log.LogBuffer;
import com.android.systemui.log.dagger.DozeLog;
import com.android.systemui.statusbar.policy.DevicePostureController;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;
import javax.inject.Inject;

/**
 * Interface for logging messages to the [DozeLog].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000@\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0002\b\u000e\n\u0002\u0010\u000e\n\u0002\b\t\n\u0002\u0010\t\n\u0002\b\u0017\u0018\u00002\u00020\u0001B\u0011\b\u0007\u0012\b\b\u0001\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u000e\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bJ\u000e\u0010\t\u001a\u00020\u00062\u0006\u0010\n\u001a\u00020\bJ\u000e\u0010\u000b\u001a\u00020\u00062\u0006\u0010\f\u001a\u00020\bJ\u000e\u0010\r\u001a\u00020\u00062\u0006\u0010\u000e\u001a\u00020\u000fJ\u000e\u0010\u0010\u001a\u00020\u00062\u0006\u0010\u000e\u001a\u00020\u000fJ\u000e\u0010\u0011\u001a\u00020\u00062\u0006\u0010\u0012\u001a\u00020\u0013J\u000e\u0010\u0014\u001a\u00020\u00062\u0006\u0010\u0012\u001a\u00020\u0013J\u000e\u0010\u0015\u001a\u00020\u00062\u0006\u0010\u0016\u001a\u00020\u0013J\u0006\u0010\u0017\u001a\u00020\u0006J&\u0010\u0018\u001a\u00020\u00062\u0006\u0010\u0019\u001a\u00020\u00132\u0006\u0010\u001a\u001a\u00020\u00132\u0006\u0010\u001b\u001a\u00020\u00132\u0006\u0010\u001c\u001a\u00020\u0013J\u000e\u0010\u001d\u001a\u00020\u00062\u0006\u0010\u001e\u001a\u00020\u0013J\u000e\u0010\u001f\u001a\u00020\u00062\u0006\u0010\u001e\u001a\u00020\u0013J\u000e\u0010 \u001a\u00020\u00062\u0006\u0010!\u001a\u00020\"J\u0006\u0010#\u001a\u00020\u0006J\u000e\u0010$\u001a\u00020\u00062\u0006\u0010%\u001a\u00020\u0013J\u0016\u0010&\u001a\u00020\u00062\u0006\u0010\'\u001a\u00020\b2\u0006\u0010(\u001a\u00020\"J\u001e\u0010)\u001a\u00020\u00062\u0006\u0010*\u001a\u00020\u00132\u0006\u0010+\u001a\u00020,2\u0006\u0010-\u001a\u00020\bJ\u001e\u0010.\u001a\u00020\u00062\u0006\u0010/\u001a\u00020\u00132\u0006\u0010\u000e\u001a\u00020\u000f2\u0006\u00100\u001a\u00020\u0013J\u000e\u0010.\u001a\u00020\u00062\u0006\u0010-\u001a\u00020\"J\u0006\u00101\u001a\u00020\u0006J\u000e\u00102\u001a\u00020\u00062\u0006\u0010-\u001a\u00020\bJ\u000e\u00103\u001a\u00020\u00062\u0006\u00104\u001a\u00020\u0013J\u000e\u00105\u001a\u00020\u00062\u0006\u00106\u001a\u00020\bJ\u000e\u00107\u001a\u00020\u00062\u0006\u00108\u001a\u00020\u0013J\u0016\u00109\u001a\u00020\u00062\u0006\u0010:\u001a\u00020\b2\u0006\u0010-\u001a\u00020\"J\u000e\u0010;\u001a\u00020\u00062\u0006\u0010-\u001a\u00020\bJ\u000e\u0010<\u001a\u00020\u00062\u0006\u0010=\u001a\u00020,J\u000e\u0010>\u001a\u00020\u00062\u0006\u0010\u000e\u001a\u00020\u000fJ\u0016\u0010?\u001a\u00020\u00062\u0006\u0010@\u001a\u00020,2\u0006\u0010A\u001a\u00020,J\u0016\u0010B\u001a\u00020\u00062\u0006\u0010C\u001a\u00020\u00132\u0006\u0010-\u001a\u00020\bR\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/doze/DozeLogger;", "", "buffer", "Lcom/android/systemui/log/LogBuffer;", "(Lcom/android/systemui/log/LogBuffer;)V", "logDisplayStateChanged", "", "displayState", "", "logDisplayStateDelayedByUdfps", "delayedDisplayState", "logDozeScreenBrightness", "brightness", "logDozeStateChanged", "state", "Lcom/android/systemui/doze/DozeMachine$State;", "logDozeSuppressed", "logDozing", "isDozing", "", "logDozingChanged", "logDozingSuppressed", "isDozingSuppressed", "logEmergencyCall", "logFling", "expand", "aboveThreshold", "thresholdNeeded", "screenOnFromTouch", "logKeyguardBouncerChanged", "isShowing", "logKeyguardVisibilityChange", "logMissedTick", "delay", "", "logNotificationPulse", "logPickupWakeup", "isWithinVibrationThreshold", "logPostureChanged", "posture", "partUpdated", "logProximityResult", "isNear", "millis", "", "reason", "logPulseDropped", "pulsePending", "blocked", "logPulseFinish", "logPulseStart", "logPulseTouchDisabledByProx", "disabled", "logScreenOff", "why", "logScreenOn", "isPulsing", "logSensorEventDropped", "sensorEvent", "logSensorTriggered", "logSetAodDimmingScrim", "scrimOpacity", "logStateChangedSent", "logTimeTickScheduled", "whenAt", "triggerAt", "logWakeDisplay", "isAwake"})
public final class DozeLogger {
    private final com.android.systemui.log.LogBuffer buffer = null;
    
    public final void logPickupWakeup(boolean isWithinVibrationThreshold) {
    }
    
    public final void logPulseStart(@com.android.systemui.doze.DozeLog.Reason()
    int reason) {
    }
    
    public final void logPulseFinish() {
    }
    
    public final void logNotificationPulse() {
    }
    
    public final void logDozing(boolean isDozing) {
    }
    
    public final void logDozingChanged(boolean isDozing) {
    }
    
    public final void logDozingSuppressed(boolean isDozingSuppressed) {
    }
    
    public final void logFling(boolean expand, boolean aboveThreshold, boolean thresholdNeeded, boolean screenOnFromTouch) {
    }
    
    public final void logEmergencyCall() {
    }
    
    public final void logKeyguardBouncerChanged(boolean isShowing) {
    }
    
    public final void logScreenOn(boolean isPulsing) {
    }
    
    public final void logScreenOff(int why) {
    }
    
    public final void logMissedTick(@org.jetbrains.annotations.NotNull()
    java.lang.String delay) {
    }
    
    public final void logTimeTickScheduled(long whenAt, long triggerAt) {
    }
    
    public final void logKeyguardVisibilityChange(boolean isShowing) {
    }
    
    public final void logDozeStateChanged(@org.jetbrains.annotations.NotNull()
    com.android.systemui.doze.DozeMachine.State state) {
    }
    
    public final void logStateChangedSent(@org.jetbrains.annotations.NotNull()
    com.android.systemui.doze.DozeMachine.State state) {
    }
    
    public final void logDisplayStateDelayedByUdfps(int delayedDisplayState) {
    }
    
    public final void logDisplayStateChanged(int displayState) {
    }
    
    public final void logWakeDisplay(boolean isAwake, @com.android.systemui.doze.DozeLog.Reason()
    int reason) {
    }
    
    public final void logProximityResult(boolean isNear, long millis, @com.android.systemui.doze.DozeLog.Reason()
    int reason) {
    }
    
    public final void logPostureChanged(int posture, @org.jetbrains.annotations.NotNull()
    java.lang.String partUpdated) {
    }
    
    public final void logPulseDropped(boolean pulsePending, @org.jetbrains.annotations.NotNull()
    com.android.systemui.doze.DozeMachine.State state, boolean blocked) {
    }
    
    public final void logSensorEventDropped(int sensorEvent, @org.jetbrains.annotations.NotNull()
    java.lang.String reason) {
    }
    
    public final void logPulseDropped(@org.jetbrains.annotations.NotNull()
    java.lang.String reason) {
    }
    
    public final void logPulseTouchDisabledByProx(boolean disabled) {
    }
    
    public final void logSensorTriggered(@com.android.systemui.doze.DozeLog.Reason()
    int reason) {
    }
    
    public final void logDozeSuppressed(@org.jetbrains.annotations.NotNull()
    com.android.systemui.doze.DozeMachine.State state) {
    }
    
    public final void logDozeScreenBrightness(int brightness) {
    }
    
    public final void logSetAodDimmingScrim(long scrimOpacity) {
    }
    
    @javax.inject.Inject()
    public DozeLogger(@org.jetbrains.annotations.NotNull()
    @com.android.systemui.log.dagger.DozeLog()
    com.android.systemui.log.LogBuffer buffer) {
        super();
    }
}