package com.android.keyguard;

import android.annotation.CurrentTimeMillisLong;
import android.hardware.biometrics.BiometricAuthenticator.Modality;

/**
 * Verbose logging for various keyguard listening states.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000,\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0010\b\n\u0002\b\u0004\n\u0002\u0010\t\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\u0018\u0002\b6\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u0012\u0010\u0003\u001a\u00020\u0004X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0005\u0010\u0006R\u0018\u0010\u0007\u001a\u00020\bX\u00a6\u0004\u00a2\u0006\f\u0012\u0004\b\t\u0010\u0002\u001a\u0004\b\n\u0010\u000bR\u0012\u0010\f\u001a\u00020\rX\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u000e\u0010\u000fR\u0012\u0010\u0010\u001a\u00020\bX\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0011\u0010\u000b\u0082\u0001\u0002\u0012\u0013"}, d2 = {"Lcom/android/keyguard/KeyguardListenModel;", "", "()V", "listening", "", "getListening", "()Z", "modality", "", "getModality$annotations", "getModality", "()I", "timeMillis", "", "getTimeMillis", "()J", "userId", "getUserId", "Lcom/android/keyguard/KeyguardFingerprintListenModel;", "Lcom/android/keyguard/KeyguardFaceListenModel;"})
public abstract class KeyguardListenModel {
    
    /**
     * Timestamp of the state change.
     */
    public abstract long getTimeMillis();
    
    /**
     * Current user
     */
    public abstract int getUserId();
    
    /**
     * If keyguard is listening for the given [modality].
     */
    public abstract boolean getListening();
    
    /**
     * Sensor type
     */
    @android.hardware.biometrics.BiometricAuthenticator.Modality()
    @java.lang.Deprecated()
    public static void getModality$annotations() {
    }
    
    /**
     * Sensor type
     */
    public abstract int getModality();
    
    private KeyguardListenModel() {
        super();
    }
}