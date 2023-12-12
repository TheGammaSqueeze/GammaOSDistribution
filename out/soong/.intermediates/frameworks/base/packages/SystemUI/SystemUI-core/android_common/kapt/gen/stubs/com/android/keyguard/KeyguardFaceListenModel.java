package com.android.keyguard;

import android.annotation.CurrentTimeMillisLong;
import android.hardware.biometrics.BiometricAuthenticator.Modality;

/**
 * Verbose debug information associated with [KeyguardUpdateMonitor.shouldListenForFace].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000b\n\u0002\b<\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\b\u0086\b\u0018\u00002\u00020\u0001B\u0095\u0001\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\u0007\u0012\u0006\u0010\t\u001a\u00020\u0007\u0012\u0006\u0010\n\u001a\u00020\u0007\u0012\u0006\u0010\u000b\u001a\u00020\u0007\u0012\u0006\u0010\f\u001a\u00020\u0007\u0012\u0006\u0010\r\u001a\u00020\u0007\u0012\u0006\u0010\u000e\u001a\u00020\u0007\u0012\u0006\u0010\u000f\u001a\u00020\u0007\u0012\u0006\u0010\u0010\u001a\u00020\u0007\u0012\u0006\u0010\u0011\u001a\u00020\u0007\u0012\u0006\u0010\u0012\u001a\u00020\u0007\u0012\u0006\u0010\u0013\u001a\u00020\u0007\u0012\u0006\u0010\u0014\u001a\u00020\u0007\u0012\u0006\u0010\u0015\u001a\u00020\u0007\u0012\u0006\u0010\u0016\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\u0017J\t\u0010/\u001a\u00020\u0003H\u00c6\u0003J\t\u00100\u001a\u00020\u0007H\u00c6\u0003J\t\u00101\u001a\u00020\u0007H\u00c6\u0003J\t\u00102\u001a\u00020\u0007H\u00c6\u0003J\t\u00103\u001a\u00020\u0007H\u00c6\u0003J\t\u00104\u001a\u00020\u0007H\u00c6\u0003J\t\u00105\u001a\u00020\u0007H\u00c6\u0003J\t\u00106\u001a\u00020\u0007H\u00c6\u0003J\t\u00107\u001a\u00020\u0007H\u00c6\u0003J\t\u00108\u001a\u00020\u0007H\u00c6\u0003J\t\u00109\u001a\u00020\u0005H\u00c6\u0003J\t\u0010:\u001a\u00020\u0007H\u00c6\u0003J\t\u0010;\u001a\u00020\u0007H\u00c6\u0003J\t\u0010<\u001a\u00020\u0007H\u00c6\u0003J\t\u0010=\u001a\u00020\u0007H\u00c6\u0003J\t\u0010>\u001a\u00020\u0007H\u00c6\u0003J\t\u0010?\u001a\u00020\u0007H\u00c6\u0003J\t\u0010@\u001a\u00020\u0007H\u00c6\u0003J\u00bd\u0001\u0010A\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00052\b\b\u0002\u0010\u0006\u001a\u00020\u00072\b\b\u0002\u0010\b\u001a\u00020\u00072\b\b\u0002\u0010\t\u001a\u00020\u00072\b\b\u0002\u0010\n\u001a\u00020\u00072\b\b\u0002\u0010\u000b\u001a\u00020\u00072\b\b\u0002\u0010\f\u001a\u00020\u00072\b\b\u0002\u0010\r\u001a\u00020\u00072\b\b\u0002\u0010\u000e\u001a\u00020\u00072\b\b\u0002\u0010\u000f\u001a\u00020\u00072\b\b\u0002\u0010\u0010\u001a\u00020\u00072\b\b\u0002\u0010\u0011\u001a\u00020\u00072\b\b\u0002\u0010\u0012\u001a\u00020\u00072\b\b\u0002\u0010\u0013\u001a\u00020\u00072\b\b\u0002\u0010\u0014\u001a\u00020\u00072\b\b\u0002\u0010\u0015\u001a\u00020\u00072\b\b\u0002\u0010\u0016\u001a\u00020\u0007H\u00c6\u0001J\u0013\u0010B\u001a\u00020\u00072\b\u0010C\u001a\u0004\u0018\u00010DH\u00d6\u0003J\t\u0010E\u001a\u00020\u0005H\u00d6\u0001J\t\u0010F\u001a\u00020GH\u00d6\u0001R\u0011\u0010\b\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0018\u0010\u0019R\u0011\u0010\t\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001a\u0010\u0019R\u0011\u0010\n\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001b\u0010\u0019R\u0011\u0010\u000b\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001c\u0010\u0019R\u0011\u0010\f\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001d\u0010\u0019R\u0011\u0010\r\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001e\u0010\u0019R\u0011\u0010\u000e\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001f\u0010\u0019R\u0011\u0010\u000f\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b \u0010\u0019R\u0014\u0010\u0006\u001a\u00020\u0007X\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b!\u0010\u0019R\u0011\u0010\u0010\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\"\u0010\u0019R\u0011\u0010\u0011\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b#\u0010\u0019R\u0014\u0010$\u001a\u00020\u0005X\u0096D\u00a2\u0006\b\n\u0000\u001a\u0004\b%\u0010&R\u0011\u0010\u0012\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\'\u0010\u0019R\u0011\u0010\u0013\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b(\u0010\u0019R\u0011\u0010\u0014\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b)\u0010\u0019R\u0011\u0010\u0015\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b*\u0010\u0019R\u0011\u0010\u0016\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b+\u0010\u0019R\u0014\u0010\u0002\u001a\u00020\u0003X\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b,\u0010-R\u0014\u0010\u0004\u001a\u00020\u0005X\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b.\u0010&"}, d2 = {"Lcom/android/keyguard/KeyguardFaceListenModel;", "Lcom/android/keyguard/KeyguardListenModel;", "timeMillis", "", "userId", "", "listening", "", "authInterruptActive", "becauseCannotSkipBouncer", "biometricSettingEnabledForUser", "bouncer", "faceAuthenticated", "faceDisabled", "keyguardAwake", "keyguardGoingAway", "listeningForFaceAssistant", "lockIconPressed", "occludingAppRequestingFaceAuth", "primaryUser", "scanningAllowedByStrongAuth", "secureCameraLaunched", "switchingUser", "(JIZZZZZZZZZZZZZZZZ)V", "getAuthInterruptActive", "()Z", "getBecauseCannotSkipBouncer", "getBiometricSettingEnabledForUser", "getBouncer", "getFaceAuthenticated", "getFaceDisabled", "getKeyguardAwake", "getKeyguardGoingAway", "getListening", "getListeningForFaceAssistant", "getLockIconPressed", "modality", "getModality", "()I", "getOccludingAppRequestingFaceAuth", "getPrimaryUser", "getScanningAllowedByStrongAuth", "getSecureCameraLaunched", "getSwitchingUser", "getTimeMillis", "()J", "getUserId", "component1", "component10", "component11", "component12", "component13", "component14", "component15", "component16", "component17", "component18", "component2", "component3", "component4", "component5", "component6", "component7", "component8", "component9", "copy", "equals", "other", "", "hashCode", "toString", ""})
public final class KeyguardFaceListenModel extends com.android.keyguard.KeyguardListenModel {
    private final int modality = android.hardware.biometrics.BiometricAuthenticator.TYPE_FINGERPRINT;
    private final long timeMillis = 0L;
    private final int userId = 0;
    private final boolean listening = false;
    private final boolean authInterruptActive = false;
    private final boolean becauseCannotSkipBouncer = false;
    private final boolean biometricSettingEnabledForUser = false;
    private final boolean bouncer = false;
    private final boolean faceAuthenticated = false;
    private final boolean faceDisabled = false;
    private final boolean keyguardAwake = false;
    private final boolean keyguardGoingAway = false;
    private final boolean listeningForFaceAssistant = false;
    private final boolean lockIconPressed = false;
    private final boolean occludingAppRequestingFaceAuth = false;
    private final boolean primaryUser = false;
    private final boolean scanningAllowedByStrongAuth = false;
    private final boolean secureCameraLaunched = false;
    private final boolean switchingUser = false;
    
    @java.lang.Override()
    public int getModality() {
        return 0;
    }
    
    @java.lang.Override()
    public long getTimeMillis() {
        return 0L;
    }
    
    @java.lang.Override()
    public int getUserId() {
        return 0;
    }
    
    @java.lang.Override()
    public boolean getListening() {
        return false;
    }
    
    public final boolean getAuthInterruptActive() {
        return false;
    }
    
    public final boolean getBecauseCannotSkipBouncer() {
        return false;
    }
    
    public final boolean getBiometricSettingEnabledForUser() {
        return false;
    }
    
    public final boolean getBouncer() {
        return false;
    }
    
    public final boolean getFaceAuthenticated() {
        return false;
    }
    
    public final boolean getFaceDisabled() {
        return false;
    }
    
    public final boolean getKeyguardAwake() {
        return false;
    }
    
    public final boolean getKeyguardGoingAway() {
        return false;
    }
    
    public final boolean getListeningForFaceAssistant() {
        return false;
    }
    
    public final boolean getLockIconPressed() {
        return false;
    }
    
    public final boolean getOccludingAppRequestingFaceAuth() {
        return false;
    }
    
    public final boolean getPrimaryUser() {
        return false;
    }
    
    public final boolean getScanningAllowedByStrongAuth() {
        return false;
    }
    
    public final boolean getSecureCameraLaunched() {
        return false;
    }
    
    public final boolean getSwitchingUser() {
        return false;
    }
    
    public KeyguardFaceListenModel(@android.annotation.CurrentTimeMillisLong()
    long timeMillis, int userId, boolean listening, boolean authInterruptActive, boolean becauseCannotSkipBouncer, boolean biometricSettingEnabledForUser, boolean bouncer, boolean faceAuthenticated, boolean faceDisabled, boolean keyguardAwake, boolean keyguardGoingAway, boolean listeningForFaceAssistant, boolean lockIconPressed, boolean occludingAppRequestingFaceAuth, boolean primaryUser, boolean scanningAllowedByStrongAuth, boolean secureCameraLaunched, boolean switchingUser) {
    }
    
    public final long component1() {
        return 0L;
    }
    
    public final int component2() {
        return 0;
    }
    
    public final boolean component3() {
        return false;
    }
    
    public final boolean component4() {
        return false;
    }
    
    public final boolean component5() {
        return false;
    }
    
    public final boolean component6() {
        return false;
    }
    
    public final boolean component7() {
        return false;
    }
    
    public final boolean component8() {
        return false;
    }
    
    public final boolean component9() {
        return false;
    }
    
    public final boolean component10() {
        return false;
    }
    
    public final boolean component11() {
        return false;
    }
    
    public final boolean component12() {
        return false;
    }
    
    public final boolean component13() {
        return false;
    }
    
    public final boolean component14() {
        return false;
    }
    
    public final boolean component15() {
        return false;
    }
    
    public final boolean component16() {
        return false;
    }
    
    public final boolean component17() {
        return false;
    }
    
    public final boolean component18() {
        return false;
    }
    
    /**
     * Verbose debug information associated with [KeyguardUpdateMonitor.shouldListenForFace].
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.keyguard.KeyguardFaceListenModel copy(@android.annotation.CurrentTimeMillisLong()
    long timeMillis, int userId, boolean listening, boolean authInterruptActive, boolean becauseCannotSkipBouncer, boolean biometricSettingEnabledForUser, boolean bouncer, boolean faceAuthenticated, boolean faceDisabled, boolean keyguardAwake, boolean keyguardGoingAway, boolean listeningForFaceAssistant, boolean lockIconPressed, boolean occludingAppRequestingFaceAuth, boolean primaryUser, boolean scanningAllowedByStrongAuth, boolean secureCameraLaunched, boolean switchingUser) {
        return null;
    }
    
    /**
     * Verbose debug information associated with [KeyguardUpdateMonitor.shouldListenForFace].
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    /**
     * Verbose debug information associated with [KeyguardUpdateMonitor.shouldListenForFace].
     */
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    /**
     * Verbose debug information associated with [KeyguardUpdateMonitor.shouldListenForFace].
     */
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
}