package com.android.keyguard;

import android.annotation.CurrentTimeMillisLong;
import android.hardware.biometrics.BiometricAuthenticator.Modality;

/**
 * Verbose debug information associated with [KeyguardUpdateMonitor.shouldListenForFingerprint].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000b\n\u0002\bH\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\b\u0086\b\u0018\u00002\u00020\u0001B\u00b5\u0001\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\u0007\u0012\u0006\u0010\t\u001a\u00020\u0007\u0012\u0006\u0010\n\u001a\u00020\u0007\u0012\u0006\u0010\u000b\u001a\u00020\u0007\u0012\u0006\u0010\f\u001a\u00020\u0007\u0012\u0006\u0010\r\u001a\u00020\u0007\u0012\u0006\u0010\u000e\u001a\u00020\u0007\u0012\u0006\u0010\u000f\u001a\u00020\u0007\u0012\u0006\u0010\u0010\u001a\u00020\u0007\u0012\u0006\u0010\u0011\u001a\u00020\u0007\u0012\u0006\u0010\u0012\u001a\u00020\u0007\u0012\u0006\u0010\u0013\u001a\u00020\u0007\u0012\u0006\u0010\u0014\u001a\u00020\u0007\u0012\u0006\u0010\u0015\u001a\u00020\u0007\u0012\u0006\u0010\u0016\u001a\u00020\u0007\u0012\u0006\u0010\u0017\u001a\u00020\u0007\u0012\u0006\u0010\u0018\u001a\u00020\u0007\u0012\u0006\u0010\u0019\u001a\u00020\u0007\u0012\u0006\u0010\u001a\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\u001bJ\t\u00107\u001a\u00020\u0003H\u00c6\u0003J\t\u00108\u001a\u00020\u0007H\u00c6\u0003J\t\u00109\u001a\u00020\u0007H\u00c6\u0003J\t\u0010:\u001a\u00020\u0007H\u00c6\u0003J\t\u0010;\u001a\u00020\u0007H\u00c6\u0003J\t\u0010<\u001a\u00020\u0007H\u00c6\u0003J\t\u0010=\u001a\u00020\u0007H\u00c6\u0003J\t\u0010>\u001a\u00020\u0007H\u00c6\u0003J\t\u0010?\u001a\u00020\u0007H\u00c6\u0003J\t\u0010@\u001a\u00020\u0007H\u00c6\u0003J\t\u0010A\u001a\u00020\u0007H\u00c6\u0003J\t\u0010B\u001a\u00020\u0005H\u00c6\u0003J\t\u0010C\u001a\u00020\u0007H\u00c6\u0003J\t\u0010D\u001a\u00020\u0007H\u00c6\u0003J\t\u0010E\u001a\u00020\u0007H\u00c6\u0003J\t\u0010F\u001a\u00020\u0007H\u00c6\u0003J\t\u0010G\u001a\u00020\u0007H\u00c6\u0003J\t\u0010H\u001a\u00020\u0007H\u00c6\u0003J\t\u0010I\u001a\u00020\u0007H\u00c6\u0003J\t\u0010J\u001a\u00020\u0007H\u00c6\u0003J\t\u0010K\u001a\u00020\u0007H\u00c6\u0003J\t\u0010L\u001a\u00020\u0007H\u00c6\u0003J\u00e5\u0001\u0010M\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00052\b\b\u0002\u0010\u0006\u001a\u00020\u00072\b\b\u0002\u0010\b\u001a\u00020\u00072\b\b\u0002\u0010\t\u001a\u00020\u00072\b\b\u0002\u0010\n\u001a\u00020\u00072\b\b\u0002\u0010\u000b\u001a\u00020\u00072\b\b\u0002\u0010\f\u001a\u00020\u00072\b\b\u0002\u0010\r\u001a\u00020\u00072\b\b\u0002\u0010\u000e\u001a\u00020\u00072\b\b\u0002\u0010\u000f\u001a\u00020\u00072\b\b\u0002\u0010\u0010\u001a\u00020\u00072\b\b\u0002\u0010\u0011\u001a\u00020\u00072\b\b\u0002\u0010\u0012\u001a\u00020\u00072\b\b\u0002\u0010\u0013\u001a\u00020\u00072\b\b\u0002\u0010\u0014\u001a\u00020\u00072\b\b\u0002\u0010\u0015\u001a\u00020\u00072\b\b\u0002\u0010\u0016\u001a\u00020\u00072\b\b\u0002\u0010\u0017\u001a\u00020\u00072\b\b\u0002\u0010\u0018\u001a\u00020\u00072\b\b\u0002\u0010\u0019\u001a\u00020\u00072\b\b\u0002\u0010\u001a\u001a\u00020\u0007H\u00c6\u0001J\u0013\u0010N\u001a\u00020\u00072\b\u0010O\u001a\u0004\u0018\u00010PH\u00d6\u0003J\t\u0010Q\u001a\u00020\u0005H\u00d6\u0001J\t\u0010R\u001a\u00020SH\u00d6\u0001R\u0011\u0010\b\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001c\u0010\u001dR\u0011\u0010\t\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001e\u0010\u001dR\u0011\u0010\n\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001f\u0010\u001dR\u0011\u0010\u000b\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b \u0010\u001dR\u0011\u0010\f\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b!\u0010\u001dR\u0011\u0010\r\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\"\u0010\u001dR\u0011\u0010\u000e\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b#\u0010\u001dR\u0011\u0010\u000f\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b$\u0010\u001dR\u0011\u0010\u0010\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b%\u0010\u001dR\u0011\u0010\u0011\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b&\u0010\u001dR\u0011\u0010\u0012\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\'\u0010\u001dR\u0011\u0010\u0013\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b(\u0010\u001dR\u0011\u0010\u0014\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b)\u0010\u001dR\u0014\u0010\u0006\u001a\u00020\u0007X\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b*\u0010\u001dR\u0014\u0010+\u001a\u00020\u0005X\u0096D\u00a2\u0006\b\n\u0000\u001a\u0004\b,\u0010-R\u0011\u0010\u0015\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b.\u0010\u001dR\u0011\u0010\u0016\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b/\u0010\u001dR\u0011\u0010\u0017\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b0\u0010\u001dR\u0011\u0010\u0018\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b1\u0010\u001dR\u0014\u0010\u0002\u001a\u00020\u0003X\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b2\u00103R\u0011\u0010\u0019\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b4\u0010\u001dR\u0011\u0010\u001a\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b5\u0010\u001dR\u0014\u0010\u0004\u001a\u00020\u0005X\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b6\u0010-"}, d2 = {"Lcom/android/keyguard/KeyguardFingerprintListenModel;", "Lcom/android/keyguard/KeyguardListenModel;", "timeMillis", "", "userId", "", "listening", "", "biometricEnabledForUser", "bouncer", "canSkipBouncer", "credentialAttempted", "deviceInteractive", "dreaming", "encryptedOrLockdown", "fingerprintDisabled", "fingerprintLockedOut", "goingToSleep", "keyguardGoingAway", "keyguardIsVisible", "keyguardOccluded", "occludingAppRequestingFp", "primaryUser", "shouldListenForFingerprintAssistant", "switchingUser", "udfps", "userDoesNotHaveTrust", "(JIZZZZZZZZZZZZZZZZZZZZ)V", "getBiometricEnabledForUser", "()Z", "getBouncer", "getCanSkipBouncer", "getCredentialAttempted", "getDeviceInteractive", "getDreaming", "getEncryptedOrLockdown", "getFingerprintDisabled", "getFingerprintLockedOut", "getGoingToSleep", "getKeyguardGoingAway", "getKeyguardIsVisible", "getKeyguardOccluded", "getListening", "modality", "getModality", "()I", "getOccludingAppRequestingFp", "getPrimaryUser", "getShouldListenForFingerprintAssistant", "getSwitchingUser", "getTimeMillis", "()J", "getUdfps", "getUserDoesNotHaveTrust", "getUserId", "component1", "component10", "component11", "component12", "component13", "component14", "component15", "component16", "component17", "component18", "component19", "component2", "component20", "component21", "component22", "component3", "component4", "component5", "component6", "component7", "component8", "component9", "copy", "equals", "other", "", "hashCode", "toString", ""})
public final class KeyguardFingerprintListenModel extends com.android.keyguard.KeyguardListenModel {
    private final int modality = android.hardware.biometrics.BiometricAuthenticator.TYPE_FACE;
    private final long timeMillis = 0L;
    private final int userId = 0;
    private final boolean listening = false;
    private final boolean biometricEnabledForUser = false;
    private final boolean bouncer = false;
    private final boolean canSkipBouncer = false;
    private final boolean credentialAttempted = false;
    private final boolean deviceInteractive = false;
    private final boolean dreaming = false;
    private final boolean encryptedOrLockdown = false;
    private final boolean fingerprintDisabled = false;
    private final boolean fingerprintLockedOut = false;
    private final boolean goingToSleep = false;
    private final boolean keyguardGoingAway = false;
    private final boolean keyguardIsVisible = false;
    private final boolean keyguardOccluded = false;
    private final boolean occludingAppRequestingFp = false;
    private final boolean primaryUser = false;
    private final boolean shouldListenForFingerprintAssistant = false;
    private final boolean switchingUser = false;
    private final boolean udfps = false;
    private final boolean userDoesNotHaveTrust = false;
    
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
    
    public final boolean getBiometricEnabledForUser() {
        return false;
    }
    
    public final boolean getBouncer() {
        return false;
    }
    
    public final boolean getCanSkipBouncer() {
        return false;
    }
    
    public final boolean getCredentialAttempted() {
        return false;
    }
    
    public final boolean getDeviceInteractive() {
        return false;
    }
    
    public final boolean getDreaming() {
        return false;
    }
    
    public final boolean getEncryptedOrLockdown() {
        return false;
    }
    
    public final boolean getFingerprintDisabled() {
        return false;
    }
    
    public final boolean getFingerprintLockedOut() {
        return false;
    }
    
    public final boolean getGoingToSleep() {
        return false;
    }
    
    public final boolean getKeyguardGoingAway() {
        return false;
    }
    
    public final boolean getKeyguardIsVisible() {
        return false;
    }
    
    public final boolean getKeyguardOccluded() {
        return false;
    }
    
    public final boolean getOccludingAppRequestingFp() {
        return false;
    }
    
    public final boolean getPrimaryUser() {
        return false;
    }
    
    public final boolean getShouldListenForFingerprintAssistant() {
        return false;
    }
    
    public final boolean getSwitchingUser() {
        return false;
    }
    
    public final boolean getUdfps() {
        return false;
    }
    
    public final boolean getUserDoesNotHaveTrust() {
        return false;
    }
    
    public KeyguardFingerprintListenModel(@android.annotation.CurrentTimeMillisLong()
    long timeMillis, int userId, boolean listening, boolean biometricEnabledForUser, boolean bouncer, boolean canSkipBouncer, boolean credentialAttempted, boolean deviceInteractive, boolean dreaming, boolean encryptedOrLockdown, boolean fingerprintDisabled, boolean fingerprintLockedOut, boolean goingToSleep, boolean keyguardGoingAway, boolean keyguardIsVisible, boolean keyguardOccluded, boolean occludingAppRequestingFp, boolean primaryUser, boolean shouldListenForFingerprintAssistant, boolean switchingUser, boolean udfps, boolean userDoesNotHaveTrust) {
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
    
    public final boolean component19() {
        return false;
    }
    
    public final boolean component20() {
        return false;
    }
    
    public final boolean component21() {
        return false;
    }
    
    public final boolean component22() {
        return false;
    }
    
    /**
     * Verbose debug information associated with [KeyguardUpdateMonitor.shouldListenForFingerprint].
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.keyguard.KeyguardFingerprintListenModel copy(@android.annotation.CurrentTimeMillisLong()
    long timeMillis, int userId, boolean listening, boolean biometricEnabledForUser, boolean bouncer, boolean canSkipBouncer, boolean credentialAttempted, boolean deviceInteractive, boolean dreaming, boolean encryptedOrLockdown, boolean fingerprintDisabled, boolean fingerprintLockedOut, boolean goingToSleep, boolean keyguardGoingAway, boolean keyguardIsVisible, boolean keyguardOccluded, boolean occludingAppRequestingFp, boolean primaryUser, boolean shouldListenForFingerprintAssistant, boolean switchingUser, boolean udfps, boolean userDoesNotHaveTrust) {
        return null;
    }
    
    /**
     * Verbose debug information associated with [KeyguardUpdateMonitor.shouldListenForFingerprint].
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    /**
     * Verbose debug information associated with [KeyguardUpdateMonitor.shouldListenForFingerprint].
     */
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    /**
     * Verbose debug information associated with [KeyguardUpdateMonitor.shouldListenForFingerprint].
     */
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
}