package com.android.systemui.qs.tileimpl;

import java.lang.System;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\b\n\u0002\b\u0005\n\u0002\u0010\u0007\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0000\bf\u0018\u0000 \u00102\u00020\u0001:\u0001\u0010J\b\u0010\u000e\u001a\u00020\u000fH&R\u0018\u0010\u0002\u001a\u00020\u0003X\u00a6\u000e\u00a2\u0006\f\u001a\u0004\b\u0004\u0010\u0005\"\u0004\b\u0006\u0010\u0007R\u0018\u0010\b\u001a\u00020\tX\u00a6\u000e\u00a2\u0006\f\u001a\u0004\b\n\u0010\u000b\"\u0004\b\f\u0010\r"}, d2 = {"Lcom/android/systemui/qs/tileimpl/HeightOverrideable;", "", "heightOverride", "", "getHeightOverride", "()I", "setHeightOverride", "(I)V", "squishinessFraction", "", "getSquishinessFraction", "()F", "setSquishinessFraction", "(F)V", "resetOverride", "", "Companion"})
public abstract interface HeightOverrideable {
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.qs.tileimpl.HeightOverrideable.Companion Companion = null;
    public static final int NO_OVERRIDE = -1;
    
    public abstract int getHeightOverride();
    
    public abstract void setHeightOverride(int p0);
    
    public abstract void resetOverride();
    
    public abstract float getSquishinessFraction();
    
    public abstract void setSquishinessFraction(float p0);
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/qs/tileimpl/HeightOverrideable$Companion;", "", "()V", "NO_OVERRIDE", ""})
    public static final class Companion {
        public static final int NO_OVERRIDE = -1;
        
        private Companion() {
            super();
        }
    }
}