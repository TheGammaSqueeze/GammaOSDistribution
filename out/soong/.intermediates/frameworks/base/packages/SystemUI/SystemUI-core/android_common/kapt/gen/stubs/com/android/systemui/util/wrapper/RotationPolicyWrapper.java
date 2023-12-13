package com.android.systemui.util.wrapper;

import android.content.Context;
import com.android.internal.view.RotationPolicy;
import com.android.internal.view.RotationPolicy.RotationPolicyListener;
import javax.inject.Inject;

/**
 * Testable wrapper interface around RotationPolicy {link com.android.internal.view.RotationPolicy}
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000&\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\bf\u0018\u00002\u00020\u0001J\b\u0010\u0002\u001a\u00020\u0003H&J\b\u0010\u0004\u001a\u00020\u0005H&J\b\u0010\u0006\u001a\u00020\u0005H&J\u0018\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\u0003H&J\u0010\u0010\f\u001a\u00020\b2\u0006\u0010\r\u001a\u00020\u0005H&J\u0018\u0010\u000e\u001a\u00020\b2\u0006\u0010\r\u001a\u00020\u00052\u0006\u0010\u000f\u001a\u00020\u0003H&J\u0010\u0010\u0010\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\nH&"}, d2 = {"Lcom/android/systemui/util/wrapper/RotationPolicyWrapper;", "", "getRotationLockOrientation", "", "isRotationLockToggleVisible", "", "isRotationLocked", "registerRotationPolicyListener", "", "listener", "Lcom/android/internal/view/RotationPolicy$RotationPolicyListener;", "userHandle", "setRotationLock", "enabled", "setRotationLockAtAngle", "rotation", "unregisterRotationPolicyListener"})
public abstract interface RotationPolicyWrapper {
    
    public abstract void setRotationLock(boolean enabled);
    
    public abstract void setRotationLockAtAngle(boolean enabled, int rotation);
    
    public abstract int getRotationLockOrientation();
    
    public abstract boolean isRotationLockToggleVisible();
    
    public abstract boolean isRotationLocked();
    
    public abstract void registerRotationPolicyListener(@org.jetbrains.annotations.NotNull()
    com.android.internal.view.RotationPolicy.RotationPolicyListener listener, int userHandle);
    
    public abstract void unregisterRotationPolicyListener(@org.jetbrains.annotations.NotNull()
    com.android.internal.view.RotationPolicy.RotationPolicyListener listener);
}