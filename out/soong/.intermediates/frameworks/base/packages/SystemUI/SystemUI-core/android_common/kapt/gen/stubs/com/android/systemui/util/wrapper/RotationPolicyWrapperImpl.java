package com.android.systemui.util.wrapper;

import android.content.Context;
import com.android.internal.view.RotationPolicy;
import com.android.internal.view.RotationPolicy.RotationPolicyListener;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000.\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\u0018\u00002\u00020\u0001B\u000f\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\b\u0010\u0005\u001a\u00020\u0006H\u0016J\b\u0010\u0007\u001a\u00020\bH\u0016J\b\u0010\t\u001a\u00020\bH\u0016J\u0018\u0010\n\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\r2\u0006\u0010\u000e\u001a\u00020\u0006H\u0016J\u0010\u0010\u000f\u001a\u00020\u000b2\u0006\u0010\u0010\u001a\u00020\bH\u0016J\u0018\u0010\u0011\u001a\u00020\u000b2\u0006\u0010\u0010\u001a\u00020\b2\u0006\u0010\u0012\u001a\u00020\u0006H\u0016J\u0010\u0010\u0013\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\rH\u0016R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/util/wrapper/RotationPolicyWrapperImpl;", "Lcom/android/systemui/util/wrapper/RotationPolicyWrapper;", "context", "Landroid/content/Context;", "(Landroid/content/Context;)V", "getRotationLockOrientation", "", "isRotationLockToggleVisible", "", "isRotationLocked", "registerRotationPolicyListener", "", "listener", "Lcom/android/internal/view/RotationPolicy$RotationPolicyListener;", "userHandle", "setRotationLock", "enabled", "setRotationLockAtAngle", "rotation", "unregisterRotationPolicyListener"})
public final class RotationPolicyWrapperImpl implements com.android.systemui.util.wrapper.RotationPolicyWrapper {
    private final android.content.Context context = null;
    
    @java.lang.Override()
    public void setRotationLock(boolean enabled) {
    }
    
    @java.lang.Override()
    public void setRotationLockAtAngle(boolean enabled, int rotation) {
    }
    
    @java.lang.Override()
    public int getRotationLockOrientation() {
        return 0;
    }
    
    @java.lang.Override()
    public boolean isRotationLockToggleVisible() {
        return false;
    }
    
    @java.lang.Override()
    public boolean isRotationLocked() {
        return false;
    }
    
    @java.lang.Override()
    public void registerRotationPolicyListener(@org.jetbrains.annotations.NotNull()
    com.android.internal.view.RotationPolicy.RotationPolicyListener listener, int userHandle) {
    }
    
    @java.lang.Override()
    public void unregisterRotationPolicyListener(@org.jetbrains.annotations.NotNull()
    com.android.internal.view.RotationPolicy.RotationPolicyListener listener) {
    }
    
    @javax.inject.Inject()
    public RotationPolicyWrapperImpl(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super();
    }
}