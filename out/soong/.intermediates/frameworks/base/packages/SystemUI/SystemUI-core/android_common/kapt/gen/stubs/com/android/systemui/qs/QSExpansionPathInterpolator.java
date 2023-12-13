package com.android.systemui.qs;

import android.view.animation.Interpolator;
import javax.inject.Inject;
import javax.inject.Singleton;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000&\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u0007\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0000\b\u0007\u0018\u00002\u00020\u0001B\u0007\b\u0007\u00a2\u0006\u0002\u0010\u0002J\u000e\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u0004R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0011\u0010\u0007\u001a\u00020\b8F\u00a2\u0006\u0006\u001a\u0004\b\t\u0010\nR\u0011\u0010\u000b\u001a\u00020\b8F\u00a2\u0006\u0006\u001a\u0004\b\f\u0010\n"}, d2 = {"Lcom/android/systemui/qs/QSExpansionPathInterpolator;", "", "()V", "lastX", "", "pathInterpolatorBuilder", "Lcom/android/systemui/qs/PathInterpolatorBuilder;", "xInterpolator", "Landroid/view/animation/Interpolator;", "getXInterpolator", "()Landroid/view/animation/Interpolator;", "yInterpolator", "getYInterpolator", "setControlX2", "", "value"})
@javax.inject.Singleton()
public final class QSExpansionPathInterpolator {
    private com.android.systemui.qs.PathInterpolatorBuilder pathInterpolatorBuilder;
    private float lastX = 0.0F;
    
    @org.jetbrains.annotations.NotNull()
    public final android.view.animation.Interpolator getXInterpolator() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.view.animation.Interpolator getYInterpolator() {
        return null;
    }
    
    public final void setControlX2(float value) {
    }
    
    @javax.inject.Inject()
    public QSExpansionPathInterpolator() {
        super();
    }
}