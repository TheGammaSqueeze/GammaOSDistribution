package com.android.systemui.media;

import android.graphics.Rect;
import android.util.ArraySet;
import android.view.View;
import android.view.View.OnAttachStateChangeListener;
import com.android.systemui.util.animation.DisappearParameters;
import com.android.systemui.util.animation.MeasurementInput;
import com.android.systemui.util.animation.MeasurementOutput;
import com.android.systemui.util.animation.UniqueObjectHostView;
import java.util.Objects;
import javax.inject.Inject;

/**
 * A description of a media host state that describes the behavior whenever the media carousel
 * is hosted. The HostState notifies the media players of changes to their properties, who
 * in turn will create view states from it.
 * When adding a new property to this, make sure to update the listener and notify them
 * about the changes.
 * In case you need to have a different rendering based on the state, you can add a new
 * constraintState to the [MediaViewController]. Otherwise, similar host states will resolve
 * to the same viewstate, a behavior that is described in [CacheKey]. Make sure to only update
 * that key if the underlying view needs to have a different measurement.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0007\n\u0002\b\u0005\n\u0002\u0010\u000b\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u000b\bf\u0018\u0000  2\u00020\u0001:\u0001 J\b\u0010\u001f\u001a\u00020\u0000H&R\u0018\u0010\u0002\u001a\u00020\u0003X\u00a6\u000e\u00a2\u0006\f\u001a\u0004\b\u0004\u0010\u0005\"\u0004\b\u0006\u0010\u0007R\u0018\u0010\b\u001a\u00020\tX\u00a6\u000e\u00a2\u0006\f\u001a\u0004\b\n\u0010\u000b\"\u0004\b\f\u0010\rR\u0018\u0010\u000e\u001a\u00020\u000fX\u00a6\u000e\u00a2\u0006\f\u001a\u0004\b\u0010\u0010\u0011\"\u0004\b\u0012\u0010\u0013R\u001a\u0010\u0014\u001a\u0004\u0018\u00010\u0015X\u00a6\u000e\u00a2\u0006\f\u001a\u0004\b\u0016\u0010\u0017\"\u0004\b\u0018\u0010\u0019R\u0018\u0010\u001a\u001a\u00020\u000fX\u00a6\u000e\u00a2\u0006\f\u001a\u0004\b\u001b\u0010\u0011\"\u0004\b\u001c\u0010\u0013R\u0012\u0010\u001d\u001a\u00020\u000fX\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u001e\u0010\u0011"}, d2 = {"Lcom/android/systemui/media/MediaHostState;", "", "disappearParameters", "Lcom/android/systemui/util/animation/DisappearParameters;", "getDisappearParameters", "()Lcom/android/systemui/util/animation/DisappearParameters;", "setDisappearParameters", "(Lcom/android/systemui/util/animation/DisappearParameters;)V", "expansion", "", "getExpansion", "()F", "setExpansion", "(F)V", "falsingProtectionNeeded", "", "getFalsingProtectionNeeded", "()Z", "setFalsingProtectionNeeded", "(Z)V", "measurementInput", "Lcom/android/systemui/util/animation/MeasurementInput;", "getMeasurementInput", "()Lcom/android/systemui/util/animation/MeasurementInput;", "setMeasurementInput", "(Lcom/android/systemui/util/animation/MeasurementInput;)V", "showsOnlyActiveMedia", "getShowsOnlyActiveMedia", "setShowsOnlyActiveMedia", "visible", "getVisible", "copy", "Companion"})
public abstract interface MediaHostState {
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.media.MediaHostState.Companion Companion = null;
    public static final float EXPANDED = 1.0F;
    public static final float COLLAPSED = 0.0F;
    
    /**
     * The last measurement input that this state was measured with. Infers width and height of
     * the players.
     */
    @org.jetbrains.annotations.Nullable()
    public abstract com.android.systemui.util.animation.MeasurementInput getMeasurementInput();
    
    /**
     * The last measurement input that this state was measured with. Infers width and height of
     * the players.
     */
    public abstract void setMeasurementInput(@org.jetbrains.annotations.Nullable()
    com.android.systemui.util.animation.MeasurementInput p0);
    
    /**
     * The expansion of the player, [COLLAPSED] for fully collapsed (up to 3 actions),
     * [EXPANDED] for fully expanded (up to 5 actions).
     */
    public abstract float getExpansion();
    
    /**
     * The expansion of the player, [COLLAPSED] for fully collapsed (up to 3 actions),
     * [EXPANDED] for fully expanded (up to 5 actions).
     */
    public abstract void setExpansion(float p0);
    
    /**
     * Is this host only showing active media or is it showing all of them including resumption?
     */
    public abstract boolean getShowsOnlyActiveMedia();
    
    /**
     * Is this host only showing active media or is it showing all of them including resumption?
     */
    public abstract void setShowsOnlyActiveMedia(boolean p0);
    
    /**
     * If the view should be VISIBLE or GONE.
     */
    public abstract boolean getVisible();
    
    /**
     * Does this host need any falsing protection?
     */
    public abstract boolean getFalsingProtectionNeeded();
    
    /**
     * Does this host need any falsing protection?
     */
    public abstract void setFalsingProtectionNeeded(boolean p0);
    
    /**
     * The parameters how the view disappears from this location when going to a host that's not
     * visible. If modified, make sure to set this value again on the host to ensure the values
     * are propagated
     */
    @org.jetbrains.annotations.NotNull()
    public abstract com.android.systemui.util.animation.DisappearParameters getDisappearParameters();
    
    /**
     * The parameters how the view disappears from this location when going to a host that's not
     * visible. If modified, make sure to set this value again on the host to ensure the values
     * are propagated
     */
    public abstract void setDisappearParameters(@org.jetbrains.annotations.NotNull()
    com.android.systemui.util.animation.DisappearParameters p0);
    
    /**
     * Get a copy of this view state, deepcopying all appropriate members
     */
    @org.jetbrains.annotations.NotNull()
    public abstract com.android.systemui.media.MediaHostState copy();
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0012\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u0007\n\u0000\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/media/MediaHostState$Companion;", "", "()V", "COLLAPSED", "", "EXPANDED"})
    public static final class Companion {
        public static final float EXPANDED = 1.0F;
        public static final float COLLAPSED = 0.0F;
        
        private Companion() {
            super();
        }
    }
}