package com.android.systemui.statusbar.phone;

import android.annotation.IntDef;
import android.content.Context;
import android.content.pm.PackageManager;
import android.hardware.biometrics.BiometricSourceType;
import android.provider.Settings;
import com.android.systemui.Dumpable;
import com.android.systemui.R;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.statusbar.StatusBarState;
import com.android.systemui.statusbar.notification.stack.StackScrollAlgorithm;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.tuner.TunerService;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u008e\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\f\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0010!\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\n\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\u0010\u000e\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\b\t\b\u0017\u0018\u0000 S2\u00020\u00012\u00020\u0002:\u0004RSTUB7\b\u0017\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u0012\u0006\u0010\u000b\u001a\u00020\f\u0012\u0006\u0010\r\u001a\u00020\u000e\u00a2\u0006\u0002\u0010\u000fJ\u0006\u0010;\u001a\u00020\u0011J\u0006\u0010<\u001a\u00020\u0011J-\u0010=\u001a\u00020>2\u0006\u0010?\u001a\u00020@2\u0006\u0010A\u001a\u00020B2\u000e\u0010C\u001a\n\u0012\u0006\b\u0001\u0012\u00020E0DH\u0016\u00a2\u0006\u0002\u0010FJ\b\u0010G\u001a\u00020\u0011H\u0016J\u0006\u0010H\u001a\u00020>J\b\u0010I\u001a\u00020>H\u0002J\u0016\u0010J\u001a\u00020\u00112\u0006\u0010K\u001a\u00020L2\u0006\u0010M\u001a\u00020\u0011J\u0006\u0010N\u001a\u00020>J\u000e\u0010O\u001a\u00020>2\u0006\u0010P\u001a\u00020+J\u000e\u0010Q\u001a\u00020>2\u0006\u0010P\u001a\u00020+R\u001a\u0010\u0010\u001a\u00020\u0011X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0012\u0010\u0013\"\u0004\b\u0014\u0010\u0015R\u001a\u0010\u0016\u001a\u00020\u0011X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0017\u0010\u0013\"\u0004\b\u0018\u0010\u0015R&\u0010\u001a\u001a\u00020\u00112\u0006\u0010\u0019\u001a\u00020\u00118F@BX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001b\u0010\u0013\"\u0004\b\u001c\u0010\u0015R\u0014\u0010\u001d\u001a\u00020\u001eX\u0082\u0004\u00a2\u0006\b\n\u0000\u0012\u0004\b\u001f\u0010 R\u000e\u0010!\u001a\u00020\"X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010#\u001a\u00020\u0011X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001a\u0010$\u001a\u00020\u0011X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b$\u0010\u0013\"\u0004\b%\u0010\u0015R\u001a\u0010&\u001a\u00020\u0011X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\'\u0010\u0013\"\u0004\b(\u0010\u0015R\u0014\u0010)\u001a\b\u0012\u0004\u0012\u00020+0*X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010,\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010-\u001a\u0004\u0018\u00010.X\u0082\u000e\u00a2\u0006\u0002\n\u0000R$\u0010/\u001a\u00020\u00112\u0006\u0010\u0019\u001a\u00020\u0011@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b0\u0010\u0013\"\u0004\b1\u0010\u0015R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u00102\u001a\u000203X\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b4\u00105\"\u0004\b6\u00107R\u001a\u00108\u001a\u00020\u0011X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b9\u0010\u0013\"\u0004\b:\u0010\u0015"}, d2 = {"Lcom/android/systemui/statusbar/phone/KeyguardBypassController;", "Lcom/android/systemui/Dumpable;", "Lcom/android/systemui/statusbar/notification/stack/StackScrollAlgorithm$BypassController;", "context", "Landroid/content/Context;", "tunerService", "Lcom/android/systemui/tuner/TunerService;", "statusBarStateController", "Lcom/android/systemui/plugins/statusbar/StatusBarStateController;", "lockscreenUserManager", "Lcom/android/systemui/statusbar/NotificationLockscreenUserManager;", "keyguardStateController", "Lcom/android/systemui/statusbar/policy/KeyguardStateController;", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "(Landroid/content/Context;Lcom/android/systemui/tuner/TunerService;Lcom/android/systemui/plugins/statusbar/StatusBarStateController;Lcom/android/systemui/statusbar/NotificationLockscreenUserManager;Lcom/android/systemui/statusbar/policy/KeyguardStateController;Lcom/android/systemui/dump/DumpManager;)V", "altBouncerShowing", "", "getAltBouncerShowing", "()Z", "setAltBouncerShowing", "(Z)V", "bouncerShowing", "getBouncerShowing", "setBouncerShowing", "value", "bypassEnabled", "getBypassEnabled", "setBypassEnabled", "bypassOverride", "", "getBypassOverride$annotations", "()V", "faceAuthEnabledChangedCallback", "Lcom/android/systemui/statusbar/policy/KeyguardStateController$Callback;", "hasFaceFeature", "isPulseExpanding", "setPulseExpanding", "launchingAffordance", "getLaunchingAffordance", "setLaunchingAffordance", "listeners", "", "Lcom/android/systemui/statusbar/phone/KeyguardBypassController$OnBypassStateChangedListener;", "mKeyguardStateController", "pendingUnlock", "Lcom/android/systemui/statusbar/phone/KeyguardBypassController$PendingUnlock;", "qSExpanded", "getQSExpanded", "setQSExpanded", "unlockController", "Lcom/android/systemui/statusbar/phone/BiometricUnlockController;", "getUnlockController", "()Lcom/android/systemui/statusbar/phone/BiometricUnlockController;", "setUnlockController", "(Lcom/android/systemui/statusbar/phone/BiometricUnlockController;)V", "userHasDeviceEntryIntent", "getUserHasDeviceEntryIntent", "setUserHasDeviceEntryIntent", "canBypass", "canPlaySubtleWindowAnimations", "dump", "", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "isBypassEnabled", "maybePerformPendingUnlock", "notifyListeners", "onBiometricAuthenticated", "biometricSourceType", "Landroid/hardware/biometrics/BiometricSourceType;", "isStrongBiometric", "onStartedGoingToSleep", "registerOnBypassStateChangedListener", "listener", "unregisterOnBypassStateChangedListener", "BypassOverride", "Companion", "OnBypassStateChangedListener", "PendingUnlock"})
@com.android.systemui.dagger.SysUISingleton()
public class KeyguardBypassController implements com.android.systemui.Dumpable, com.android.systemui.statusbar.notification.stack.StackScrollAlgorithm.BypassController {
    private final com.android.systemui.statusbar.policy.KeyguardStateController mKeyguardStateController = null;
    private final com.android.systemui.plugins.statusbar.StatusBarStateController statusBarStateController = null;
    private final int bypassOverride = 0;
    private boolean hasFaceFeature;
    private com.android.systemui.statusbar.phone.KeyguardBypassController.PendingUnlock pendingUnlock;
    private final java.util.List<com.android.systemui.statusbar.phone.KeyguardBypassController.OnBypassStateChangedListener> listeners = null;
    private final com.android.systemui.statusbar.policy.KeyguardStateController.Callback faceAuthEnabledChangedCallback = null;
    private boolean userHasDeviceEntryIntent = false;
    public com.android.systemui.statusbar.phone.BiometricUnlockController unlockController;
    private boolean isPulseExpanding = false;
    
    /**
     * If face unlock dismisses the lock screen or keeps user on keyguard for the current user.
     */
    private boolean bypassEnabled = false;
    private boolean bouncerShowing = false;
    private boolean altBouncerShowing = false;
    private boolean launchingAffordance = false;
    private boolean qSExpanded = false;
    public static final int BYPASS_FADE_DURATION = 67;
    private static final int FACE_UNLOCK_BYPASS_NO_OVERRIDE = 0;
    private static final int FACE_UNLOCK_BYPASS_ALWAYS = 1;
    private static final int FACE_UNLOCK_BYPASS_NEVER = 2;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.statusbar.phone.KeyguardBypassController.Companion Companion = null;
    
    @com.android.systemui.statusbar.phone.KeyguardBypassController.BypassOverride()
    @java.lang.Deprecated()
    private static void getBypassOverride$annotations() {
    }
    
    public final boolean getUserHasDeviceEntryIntent() {
        return false;
    }
    
    public final void setUserHasDeviceEntryIntent(boolean p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.phone.BiometricUnlockController getUnlockController() {
        return null;
    }
    
    public final void setUnlockController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.BiometricUnlockController p0) {
    }
    
    public final boolean isPulseExpanding() {
        return false;
    }
    
    public final void setPulseExpanding(boolean p0) {
    }
    
    /**
     * delegates to [bypassEnabled] but conforms to [StackScrollAlgorithm.BypassController]
     */
    @java.lang.Override()
    public boolean isBypassEnabled() {
        return false;
    }
    
    public final boolean getBypassEnabled() {
        return false;
    }
    
    private final void setBypassEnabled(boolean value) {
    }
    
    public final boolean getBouncerShowing() {
        return false;
    }
    
    public final void setBouncerShowing(boolean p0) {
    }
    
    public final boolean getAltBouncerShowing() {
        return false;
    }
    
    public final void setAltBouncerShowing(boolean p0) {
    }
    
    public final boolean getLaunchingAffordance() {
        return false;
    }
    
    public final void setLaunchingAffordance(boolean p0) {
    }
    
    public final boolean getQSExpanded() {
        return false;
    }
    
    public final void setQSExpanded(boolean value) {
    }
    
    private final void notifyListeners() {
    }
    
    /**
     * Notify that the biometric unlock has happened.
     *
     * @return false if we can not wake and unlock right now
     */
    public final boolean onBiometricAuthenticated(@org.jetbrains.annotations.NotNull()
    android.hardware.biometrics.BiometricSourceType biometricSourceType, boolean isStrongBiometric) {
        return false;
    }
    
    public final void maybePerformPendingUnlock() {
    }
    
    /**
     * If keyguard can be dismissed because of bypass.
     */
    public final boolean canBypass() {
        return false;
    }
    
    /**
     * If shorter animations should be played when unlocking.
     */
    public final boolean canPlaySubtleWindowAnimations() {
        return false;
    }
    
    public final void onStartedGoingToSleep() {
    }
    
    @java.lang.Override()
    public void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    /**
     * Registers a listener for bypass state changes.
     */
    public final void registerOnBypassStateChangedListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.KeyguardBypassController.OnBypassStateChangedListener listener) {
    }
    
    /**
     * Unregisters a listener for bypass state changes, previous registered with
     * [registerOnBypassStateChangedListener]
     */
    public final void unregisterOnBypassStateChangedListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.KeyguardBypassController.OnBypassStateChangedListener listener) {
    }
    
    @javax.inject.Inject()
    public KeyguardBypassController(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.tuner.TunerService tunerService, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.statusbar.StatusBarStateController statusBarStateController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationLockscreenUserManager lockscreenUserManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.KeyguardStateController keyguardStateController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager) {
        super();
    }
    
    @android.annotation.IntDef(value = {0, 1, 2})
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\b\n\u0002\u0018\u0002\n\u0002\u0010\u001b\b\u0083\u0002\u0018\u00002\u00020\u0001B\u0000"}, d2 = {"Lcom/android/systemui/statusbar/phone/KeyguardBypassController$BypassOverride;", ""})
    @java.lang.annotation.Retention(value = java.lang.annotation.RetentionPolicy.SOURCE)
    @kotlin.annotation.Retention(value = kotlin.annotation.AnnotationRetention.SOURCE)
    static abstract @interface BypassOverride {
    }
    
    /**
     * Pending unlock info:
     *
     * The pending unlock type which is set if the bypass was blocked when it happened.
     *
     * Whether the pending unlock type is strong biometric or non-strong biometric
     * (i.e. weak or convenience).
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\"\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\n\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\b\u0082\b\u0018\u00002\u00020\u0001B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\t\u0010\n\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u000b\u001a\u00020\u0005H\u00c6\u0003J\u001d\u0010\f\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u0005H\u00c6\u0001J\u0013\u0010\r\u001a\u00020\u00052\b\u0010\u000e\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u000f\u001a\u00020\u0010H\u00d6\u0001J\t\u0010\u0011\u001a\u00020\u0012H\u00d6\u0001R\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0004\u0010\u0007R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\b\u0010\t"}, d2 = {"Lcom/android/systemui/statusbar/phone/KeyguardBypassController$PendingUnlock;", "", "pendingUnlockType", "Landroid/hardware/biometrics/BiometricSourceType;", "isStrongBiometric", "", "(Landroid/hardware/biometrics/BiometricSourceType;Z)V", "()Z", "getPendingUnlockType", "()Landroid/hardware/biometrics/BiometricSourceType;", "component1", "component2", "copy", "equals", "other", "hashCode", "", "toString", ""})
    static final class PendingUnlock {
        @org.jetbrains.annotations.NotNull()
        private final android.hardware.biometrics.BiometricSourceType pendingUnlockType = null;
        private final boolean isStrongBiometric = false;
        
        @org.jetbrains.annotations.NotNull()
        public final android.hardware.biometrics.BiometricSourceType getPendingUnlockType() {
            return null;
        }
        
        public final boolean isStrongBiometric() {
            return false;
        }
        
        public PendingUnlock(@org.jetbrains.annotations.NotNull()
        android.hardware.biometrics.BiometricSourceType pendingUnlockType, boolean isStrongBiometric) {
            super();
        }
        
        @org.jetbrains.annotations.NotNull()
        public final android.hardware.biometrics.BiometricSourceType component1() {
            return null;
        }
        
        public final boolean component2() {
            return false;
        }
        
        /**
         * Pending unlock info:
         *
         * The pending unlock type which is set if the bypass was blocked when it happened.
         *
         * Whether the pending unlock type is strong biometric or non-strong biometric
         * (i.e. weak or convenience).
         */
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.statusbar.phone.KeyguardBypassController.PendingUnlock copy(@org.jetbrains.annotations.NotNull()
        android.hardware.biometrics.BiometricSourceType pendingUnlockType, boolean isStrongBiometric) {
            return null;
        }
        
        /**
         * Pending unlock info:
         *
         * The pending unlock type which is set if the bypass was blocked when it happened.
         *
         * Whether the pending unlock type is strong biometric or non-strong biometric
         * (i.e. weak or convenience).
         */
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.lang.String toString() {
            return null;
        }
        
        /**
         * Pending unlock info:
         *
         * The pending unlock type which is set if the bypass was blocked when it happened.
         *
         * Whether the pending unlock type is strong biometric or non-strong biometric
         * (i.e. weak or convenience).
         */
        @java.lang.Override()
        public int hashCode() {
            return 0;
        }
        
        /**
         * Pending unlock info:
         *
         * The pending unlock type which is set if the bypass was blocked when it happened.
         *
         * Whether the pending unlock type is strong biometric or non-strong biometric
         * (i.e. weak or convenience).
         */
        @java.lang.Override()
        public boolean equals(@org.jetbrains.annotations.Nullable()
        java.lang.Object p0) {
            return false;
        }
    }
    
    /**
     * Listener for bypass state change events.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000b\bf\u0018\u00002\u00020\u0001J\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&"}, d2 = {"Lcom/android/systemui/statusbar/phone/KeyguardBypassController$OnBypassStateChangedListener;", "", "onBypassStateChanged", "", "isEnabled", ""})
    public static abstract interface OnBypassStateChangedListener {
        
        /**
         * Invoked when bypass becomes enabled or disabled.
         */
        public abstract void onBypassStateChanged(boolean isEnabled);
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0003\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/phone/KeyguardBypassController$Companion;", "", "()V", "BYPASS_FADE_DURATION", "", "FACE_UNLOCK_BYPASS_ALWAYS", "FACE_UNLOCK_BYPASS_NEVER", "FACE_UNLOCK_BYPASS_NO_OVERRIDE"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}