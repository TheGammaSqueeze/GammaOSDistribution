package com.android.systemui;

import android.content.Context;
import android.graphics.Path;
import android.graphics.Rect;
import android.graphics.RectF;
import android.hardware.camera2.CameraManager;
import android.util.PathParser;
import java.util.concurrent.Executor;

/**
 * Listens for usage of the Camera and controls the ScreenDecorations transition to show extra
 * protection around a display cutout based on config_frontBuiltInDisplayCutoutProtection and
 * config_enableDisplayCutoutProtection
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000R\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\"\n\u0000\n\u0002\u0010!\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\n\u0018\u0000 #2\u00020\u0001:\u0002\"#B-\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\u0007\u0012\u0006\u0010\t\u001a\u00020\n\u00a2\u0006\u0002\u0010\u000bJ\u000e\u0010\u0015\u001a\u00020\u00162\u0006\u0010\u0017\u001a\u00020\u0014J\u0010\u0010\u0018\u001a\u00020\u00192\u0006\u0010\u001a\u001a\u00020\u0007H\u0002J\b\u0010\u001b\u001a\u00020\u0016H\u0002J\b\u0010\u001c\u001a\u00020\u0016H\u0002J\b\u0010\u001d\u001a\u00020\u0016H\u0002J\u000e\u0010\u001e\u001a\u00020\u00162\u0006\u0010\u0017\u001a\u00020\u0014J\u0006\u0010\u001f\u001a\u00020\u0016J\u0006\u0010 \u001a\u00020\u0016J\b\u0010!\u001a\u00020\u0016H\u0002R\u000e\u0010\f\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\u000fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0010\u001a\b\u0012\u0004\u0012\u00020\u00070\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0012\u001a\b\u0012\u0004\u0012\u00020\u00140\u0013X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/CameraAvailabilityListener;", "", "cameraManager", "Landroid/hardware/camera2/CameraManager;", "cutoutProtectionPath", "Landroid/graphics/Path;", "targetCameraId", "", "excludedPackages", "executor", "Ljava/util/concurrent/Executor;", "(Landroid/hardware/camera2/CameraManager;Landroid/graphics/Path;Ljava/lang/String;Ljava/lang/String;Ljava/util/concurrent/Executor;)V", "availabilityCallback", "Landroid/hardware/camera2/CameraManager$AvailabilityCallback;", "cutoutBounds", "Landroid/graphics/Rect;", "excludedPackageIds", "", "listeners", "", "Lcom/android/systemui/CameraAvailabilityListener$CameraTransitionCallback;", "addTransitionCallback", "", "callback", "isExcluded", "", "packageId", "notifyCameraActive", "notifyCameraInactive", "registerCameraListener", "removeTransitionCallback", "startListening", "stop", "unregisterCameraListener", "CameraTransitionCallback", "Factory"})
public final class CameraAvailabilityListener {
    private android.graphics.Rect cutoutBounds;
    private final java.util.Set<java.lang.String> excludedPackageIds = null;
    private final java.util.List<com.android.systemui.CameraAvailabilityListener.CameraTransitionCallback> listeners = null;
    private final android.hardware.camera2.CameraManager.AvailabilityCallback availabilityCallback = null;
    private final android.hardware.camera2.CameraManager cameraManager = null;
    private final android.graphics.Path cutoutProtectionPath = null;
    private final java.lang.String targetCameraId = null;
    private final java.util.concurrent.Executor executor = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.CameraAvailabilityListener.Factory Factory = null;
    
    /**
     * Start listening for availability events, and maybe notify listeners
     *
     * @return true if we started listening
     */
    public final void startListening() {
    }
    
    public final void stop() {
    }
    
    public final void addTransitionCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.CameraAvailabilityListener.CameraTransitionCallback callback) {
    }
    
    public final void removeTransitionCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.CameraAvailabilityListener.CameraTransitionCallback callback) {
    }
    
    private final boolean isExcluded(java.lang.String packageId) {
        return false;
    }
    
    private final void registerCameraListener() {
    }
    
    private final void unregisterCameraListener() {
    }
    
    private final void notifyCameraActive() {
    }
    
    private final void notifyCameraInactive() {
    }
    
    public CameraAvailabilityListener(@org.jetbrains.annotations.NotNull()
    android.hardware.camera2.CameraManager cameraManager, @org.jetbrains.annotations.NotNull()
    android.graphics.Path cutoutProtectionPath, @org.jetbrains.annotations.NotNull()
    java.lang.String targetCameraId, @org.jetbrains.annotations.NotNull()
    java.lang.String excludedPackages, @org.jetbrains.annotations.NotNull()
    java.util.concurrent.Executor executor) {
        super();
    }
    
    /**
     * Callbacks to tell a listener that a relevant camera turned on and off.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\bf\u0018\u00002\u00020\u0001J\u0018\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\u0006\u0010\u0006\u001a\u00020\u0007H&J\b\u0010\b\u001a\u00020\u0003H&"}, d2 = {"Lcom/android/systemui/CameraAvailabilityListener$CameraTransitionCallback;", "", "onApplyCameraProtection", "", "protectionPath", "Landroid/graphics/Path;", "bounds", "Landroid/graphics/Rect;", "onHideCameraProtection"})
    public static abstract interface CameraTransitionCallback {
        
        public abstract void onApplyCameraProtection(@org.jetbrains.annotations.NotNull()
        android.graphics.Path protectionPath, @org.jetbrains.annotations.NotNull()
        android.graphics.Rect bounds);
        
        public abstract void onHideCameraProtection();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0016\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bJ\u0010\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\fH\u0002"}, d2 = {"Lcom/android/systemui/CameraAvailabilityListener$Factory;", "", "()V", "build", "Lcom/android/systemui/CameraAvailabilityListener;", "context", "Landroid/content/Context;", "executor", "Ljava/util/concurrent/Executor;", "pathFromString", "Landroid/graphics/Path;", "pathString", ""})
    public static final class Factory {
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.CameraAvailabilityListener build(@org.jetbrains.annotations.NotNull()
        android.content.Context context, @org.jetbrains.annotations.NotNull()
        java.util.concurrent.Executor executor) {
            return null;
        }
        
        private final android.graphics.Path pathFromString(java.lang.String pathString) {
            return null;
        }
        
        private Factory() {
            super();
        }
    }
}