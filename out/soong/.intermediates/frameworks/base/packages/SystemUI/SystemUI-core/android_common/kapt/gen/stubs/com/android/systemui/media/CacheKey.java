package com.android.systemui.media;

import android.content.Context;
import android.content.res.Configuration;
import androidx.constraintlayout.widget.ConstraintSet;
import com.android.systemui.R;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.util.animation.MeasurementOutput;
import com.android.systemui.util.animation.TransitionLayout;
import com.android.systemui.util.animation.TransitionLayoutController;
import com.android.systemui.util.animation.TransitionViewState;
import javax.inject.Inject;

/**
 * An internal key for the cache of mediaViewStates. This is a subset of the full host state.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u0007\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0018\n\u0002\u0010\u000e\b\u0082\b\u0018\u00002\u00020\u0001B-\u0012\b\b\u0002\u0010\u0002\u001a\u00020\u0003\u0012\b\b\u0002\u0010\u0004\u001a\u00020\u0003\u0012\b\b\u0002\u0010\u0005\u001a\u00020\u0006\u0012\b\b\u0002\u0010\u0007\u001a\u00020\b\u00a2\u0006\u0002\u0010\tJ\t\u0010\u0018\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u0019\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u001a\u001a\u00020\u0006H\u00c6\u0003J\t\u0010\u001b\u001a\u00020\bH\u00c6\u0003J1\u0010\u001c\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00032\b\b\u0002\u0010\u0005\u001a\u00020\u00062\b\b\u0002\u0010\u0007\u001a\u00020\bH\u00c6\u0001J\u0013\u0010\u001d\u001a\u00020\b2\b\u0010\u001e\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u001f\u001a\u00020\u0003H\u00d6\u0001J\t\u0010 \u001a\u00020!H\u00d6\u0001R\u001a\u0010\u0005\u001a\u00020\u0006X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\n\u0010\u000b\"\u0004\b\f\u0010\rR\u001a\u0010\u0007\u001a\u00020\bX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000e\u0010\u000f\"\u0004\b\u0010\u0010\u0011R\u001a\u0010\u0004\u001a\u00020\u0003X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0012\u0010\u0013\"\u0004\b\u0014\u0010\u0015R\u001a\u0010\u0002\u001a\u00020\u0003X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0016\u0010\u0013\"\u0004\b\u0017\u0010\u0015"}, d2 = {"Lcom/android/systemui/media/CacheKey;", "", "widthMeasureSpec", "", "heightMeasureSpec", "expansion", "", "gutsVisible", "", "(IIFZ)V", "getExpansion", "()F", "setExpansion", "(F)V", "getGutsVisible", "()Z", "setGutsVisible", "(Z)V", "getHeightMeasureSpec", "()I", "setHeightMeasureSpec", "(I)V", "getWidthMeasureSpec", "setWidthMeasureSpec", "component1", "component2", "component3", "component4", "copy", "equals", "other", "hashCode", "toString", ""})
final class CacheKey {
    private int widthMeasureSpec;
    private int heightMeasureSpec;
    private float expansion;
    private boolean gutsVisible;
    
    public final int getWidthMeasureSpec() {
        return 0;
    }
    
    public final void setWidthMeasureSpec(int p0) {
    }
    
    public final int getHeightMeasureSpec() {
        return 0;
    }
    
    public final void setHeightMeasureSpec(int p0) {
    }
    
    public final float getExpansion() {
        return 0.0F;
    }
    
    public final void setExpansion(float p0) {
    }
    
    public final boolean getGutsVisible() {
        return false;
    }
    
    public final void setGutsVisible(boolean p0) {
    }
    
    public CacheKey(int widthMeasureSpec, int heightMeasureSpec, float expansion, boolean gutsVisible) {
        super();
    }
    
    public CacheKey() {
        super();
    }
    
    public final int component1() {
        return 0;
    }
    
    public final int component2() {
        return 0;
    }
    
    public final float component3() {
        return 0.0F;
    }
    
    public final boolean component4() {
        return false;
    }
    
    /**
     * An internal key for the cache of mediaViewStates. This is a subset of the full host state.
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.media.CacheKey copy(int widthMeasureSpec, int heightMeasureSpec, float expansion, boolean gutsVisible) {
        return null;
    }
    
    /**
     * An internal key for the cache of mediaViewStates. This is a subset of the full host state.
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    /**
     * An internal key for the cache of mediaViewStates. This is a subset of the full host state.
     */
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    /**
     * An internal key for the cache of mediaViewStates. This is a subset of the full host state.
     */
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
}