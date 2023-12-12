package com.android.systemui.biometrics;

import android.content.Context;
import android.hardware.display.DisplayManager;
import android.hardware.fingerprint.FingerprintSensorPropertiesInternal;
import android.os.Handler;
import android.view.Surface;
import com.android.systemui.biometrics.BiometricDisplayListener.SensorType.Generic;

/**
 * A listener for keeping overlays for biometric sensors aligned with the physical device
 * device's screen. The [onChanged] will be dispatched on the [handler]
 * whenever a relevant change to the device's configuration (orientation, fold, display change,
 * etc.) may require the UI to change for the given [sensorType].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000<\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0007\u0018\u00002\u00020\u0001:\u0001\u0018B5\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\b\b\u0002\u0010\b\u001a\u00020\t\u0012\f\u0010\n\u001a\b\u0012\u0004\u0012\u00020\f0\u000b\u00a2\u0006\u0002\u0010\rJ\b\u0010\u0010\u001a\u00020\u0011H\u0002J\u0006\u0010\u0012\u001a\u00020\fJ\u0006\u0010\u0013\u001a\u00020\fJ\u0010\u0010\u0014\u001a\u00020\f2\u0006\u0010\u0015\u001a\u00020\u000fH\u0016J\u0010\u0010\u0016\u001a\u00020\f2\u0006\u0010\u0015\u001a\u00020\u000fH\u0016J\u0010\u0010\u0017\u001a\u00020\f2\u0006\u0010\u0015\u001a\u00020\u000fH\u0016R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\u000fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010\n\u001a\b\u0012\u0004\u0012\u00020\f0\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/biometrics/BiometricDisplayListener;", "Landroid/hardware/display/DisplayManager$DisplayListener;", "context", "Landroid/content/Context;", "displayManager", "Landroid/hardware/display/DisplayManager;", "handler", "Landroid/os/Handler;", "sensorType", "Lcom/android/systemui/biometrics/BiometricDisplayListener$SensorType;", "onChanged", "Lkotlin/Function0;", "", "(Landroid/content/Context;Landroid/hardware/display/DisplayManager;Landroid/os/Handler;Lcom/android/systemui/biometrics/BiometricDisplayListener$SensorType;Lkotlin/jvm/functions/Function0;)V", "lastRotation", "", "didRotationChange", "", "disable", "enable", "onDisplayAdded", "displayId", "onDisplayChanged", "onDisplayRemoved", "SensorType"})
public final class BiometricDisplayListener implements android.hardware.display.DisplayManager.DisplayListener {
    private int lastRotation = android.view.Surface.ROTATION_0;
    private final android.content.Context context = null;
    private final android.hardware.display.DisplayManager displayManager = null;
    private final android.os.Handler handler = null;
    private final com.android.systemui.biometrics.BiometricDisplayListener.SensorType sensorType = null;
    private final kotlin.jvm.functions.Function0<kotlin.Unit> onChanged = null;
    
    @java.lang.Override()
    public void onDisplayAdded(int displayId) {
    }
    
    @java.lang.Override()
    public void onDisplayRemoved(int displayId) {
    }
    
    @java.lang.Override()
    public void onDisplayChanged(int displayId) {
    }
    
    private final boolean didRotationChange() {
        return false;
    }
    
    /**
     * Listen for changes.
     */
    public final void enable() {
    }
    
    /**
     * Stop listening for changes.
     */
    public final void disable() {
    }
    
    public BiometricDisplayListener(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    android.hardware.display.DisplayManager displayManager, @org.jetbrains.annotations.NotNull()
    android.os.Handler handler, @org.jetbrains.annotations.NotNull()
    com.android.systemui.biometrics.BiometricDisplayListener.SensorType sensorType, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function0<kotlin.Unit> onChanged) {
        super();
    }
    
    /**
     * Type of sensor to determine what kind of display changes require layouts.
     *
     * The [Generic] type should be used in cases where the modality can vary, such as
     * biometric prompt (and this object will likely change as multi-mode auth is added).
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0018\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\b6\u0018\u00002\u00020\u0001:\u0003\u0003\u0004\u0005B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002\u0082\u0001\u0003\u0006\u0007\b"}, d2 = {"Lcom/android/systemui/biometrics/BiometricDisplayListener$SensorType;", "", "()V", "Generic", "SideFingerprint", "UnderDisplayFingerprint", "Lcom/android/systemui/biometrics/BiometricDisplayListener$SensorType$Generic;", "Lcom/android/systemui/biometrics/BiometricDisplayListener$SensorType$UnderDisplayFingerprint;", "Lcom/android/systemui/biometrics/BiometricDisplayListener$SensorType$SideFingerprint;"})
    public static abstract class SensorType {
        
        private SensorType() {
            super();
        }
        
        @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\n\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002"}, d2 = {"Lcom/android/systemui/biometrics/BiometricDisplayListener$SensorType$Generic;", "Lcom/android/systemui/biometrics/BiometricDisplayListener$SensorType;", "()V"})
        public static final class Generic extends com.android.systemui.biometrics.BiometricDisplayListener.SensorType {
            @org.jetbrains.annotations.NotNull()
            public static final com.android.systemui.biometrics.BiometricDisplayListener.SensorType.Generic INSTANCE = null;
            
            private Generic() {
                super();
            }
        }
        
        @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\b\u0086\b\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\t\u0010\u0007\u001a\u00020\u0003H\u00c6\u0003J\u0013\u0010\b\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u0003H\u00c6\u0001J\u0013\u0010\t\u001a\u00020\n2\b\u0010\u000b\u001a\u0004\u0018\u00010\fH\u00d6\u0003J\t\u0010\r\u001a\u00020\u000eH\u00d6\u0001J\t\u0010\u000f\u001a\u00020\u0010H\u00d6\u0001R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0005\u0010\u0006"}, d2 = {"Lcom/android/systemui/biometrics/BiometricDisplayListener$SensorType$UnderDisplayFingerprint;", "Lcom/android/systemui/biometrics/BiometricDisplayListener$SensorType;", "properties", "Landroid/hardware/fingerprint/FingerprintSensorPropertiesInternal;", "(Landroid/hardware/fingerprint/FingerprintSensorPropertiesInternal;)V", "getProperties", "()Landroid/hardware/fingerprint/FingerprintSensorPropertiesInternal;", "component1", "copy", "equals", "", "other", "", "hashCode", "", "toString", ""})
        public static final class UnderDisplayFingerprint extends com.android.systemui.biometrics.BiometricDisplayListener.SensorType {
            @org.jetbrains.annotations.NotNull()
            private final android.hardware.fingerprint.FingerprintSensorPropertiesInternal properties = null;
            
            @org.jetbrains.annotations.NotNull()
            public final android.hardware.fingerprint.FingerprintSensorPropertiesInternal getProperties() {
                return null;
            }
            
            public UnderDisplayFingerprint(@org.jetbrains.annotations.NotNull()
            android.hardware.fingerprint.FingerprintSensorPropertiesInternal properties) {
                super();
            }
            
            @org.jetbrains.annotations.NotNull()
            public final android.hardware.fingerprint.FingerprintSensorPropertiesInternal component1() {
                return null;
            }
            
            @org.jetbrains.annotations.NotNull()
            public final com.android.systemui.biometrics.BiometricDisplayListener.SensorType.UnderDisplayFingerprint copy(@org.jetbrains.annotations.NotNull()
            android.hardware.fingerprint.FingerprintSensorPropertiesInternal properties) {
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
        
        @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\b\u0086\b\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\t\u0010\u0007\u001a\u00020\u0003H\u00c6\u0003J\u0013\u0010\b\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u0003H\u00c6\u0001J\u0013\u0010\t\u001a\u00020\n2\b\u0010\u000b\u001a\u0004\u0018\u00010\fH\u00d6\u0003J\t\u0010\r\u001a\u00020\u000eH\u00d6\u0001J\t\u0010\u000f\u001a\u00020\u0010H\u00d6\u0001R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0005\u0010\u0006"}, d2 = {"Lcom/android/systemui/biometrics/BiometricDisplayListener$SensorType$SideFingerprint;", "Lcom/android/systemui/biometrics/BiometricDisplayListener$SensorType;", "properties", "Landroid/hardware/fingerprint/FingerprintSensorPropertiesInternal;", "(Landroid/hardware/fingerprint/FingerprintSensorPropertiesInternal;)V", "getProperties", "()Landroid/hardware/fingerprint/FingerprintSensorPropertiesInternal;", "component1", "copy", "equals", "", "other", "", "hashCode", "", "toString", ""})
        public static final class SideFingerprint extends com.android.systemui.biometrics.BiometricDisplayListener.SensorType {
            @org.jetbrains.annotations.NotNull()
            private final android.hardware.fingerprint.FingerprintSensorPropertiesInternal properties = null;
            
            @org.jetbrains.annotations.NotNull()
            public final android.hardware.fingerprint.FingerprintSensorPropertiesInternal getProperties() {
                return null;
            }
            
            public SideFingerprint(@org.jetbrains.annotations.NotNull()
            android.hardware.fingerprint.FingerprintSensorPropertiesInternal properties) {
                super();
            }
            
            @org.jetbrains.annotations.NotNull()
            public final android.hardware.fingerprint.FingerprintSensorPropertiesInternal component1() {
                return null;
            }
            
            @org.jetbrains.annotations.NotNull()
            public final com.android.systemui.biometrics.BiometricDisplayListener.SensorType.SideFingerprint copy(@org.jetbrains.annotations.NotNull()
            android.hardware.fingerprint.FingerprintSensorPropertiesInternal properties) {
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
    }
}