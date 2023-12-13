package com.android.systemui.media;

import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.util.animation.MeasurementOutput;
import javax.inject.Inject;

/**
 * A class responsible for managing all media host states of the various host locations and
 * coordinating the heights among different players. This class can be used to get the most up to
 * date state for any location.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000<\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010#\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010%\n\u0002\u0010\b\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\n\b\u0007\u0018\u00002\u00020\u0001:\u0001\u001cB\u0007\b\u0007\u00a2\u0006\u0002\u0010\u0002J\u000e\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u0005J\u000e\u0010\u0014\u001a\u00020\u00122\u0006\u0010\u0015\u001a\u00020\rJ\u000e\u0010\u0016\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u0005J\u000e\u0010\u0017\u001a\u00020\u00122\u0006\u0010\u0015\u001a\u00020\rJ\u0016\u0010\u0018\u001a\u00020\t2\u0006\u0010\u0019\u001a\u00020\b2\u0006\u0010\u001a\u001a\u00020\u000fJ\u0016\u0010\u001b\u001a\u00020\u00122\u0006\u0010\u0019\u001a\u00020\b2\u0006\u0010\u001a\u001a\u00020\u000fR\u0014\u0010\u0003\u001a\b\u0012\u0004\u0012\u00020\u00050\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001d\u0010\u0006\u001a\u000e\u0012\u0004\u0012\u00020\b\u0012\u0004\u0012\u00020\t0\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\u000bR\u0014\u0010\f\u001a\b\u0012\u0004\u0012\u00020\r0\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001d\u0010\u000e\u001a\u000e\u0012\u0004\u0012\u00020\b\u0012\u0004\u0012\u00020\u000f0\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0010\u0010\u000b"}, d2 = {"Lcom/android/systemui/media/MediaHostStatesManager;", "", "()V", "callbacks", "", "Lcom/android/systemui/media/MediaHostStatesManager$Callback;", "carouselSizes", "", "", "Lcom/android/systemui/util/animation/MeasurementOutput;", "getCarouselSizes", "()Ljava/util/Map;", "controllers", "Lcom/android/systemui/media/MediaViewController;", "mediaHostStates", "Lcom/android/systemui/media/MediaHostState;", "getMediaHostStates", "addCallback", "", "callback", "addController", "controller", "removeCallback", "removeController", "updateCarouselDimensions", "location", "hostState", "updateHostState", "Callback"})
@com.android.systemui.dagger.SysUISingleton()
public final class MediaHostStatesManager {
    private final java.util.Set<com.android.systemui.media.MediaHostStatesManager.Callback> callbacks = null;
    private final java.util.Set<com.android.systemui.media.MediaViewController> controllers = null;
    
    /**
     * The overall sizes of the carousel. This is needed to make sure all players in the carousel
     * have equal size.
     */
    @org.jetbrains.annotations.NotNull()
    private final java.util.Map<java.lang.Integer, com.android.systemui.util.animation.MeasurementOutput> carouselSizes = null;
    
    /**
     * A map with all media states of all locations.
     */
    @org.jetbrains.annotations.NotNull()
    private final java.util.Map<java.lang.Integer, com.android.systemui.media.MediaHostState> mediaHostStates = null;
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.Map<java.lang.Integer, com.android.systemui.util.animation.MeasurementOutput> getCarouselSizes() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.Map<java.lang.Integer, com.android.systemui.media.MediaHostState> getMediaHostStates() {
        return null;
    }
    
    /**
     * Notify that a media state for a given location has changed. Should only be called from
     * Media hosts themselves.
     */
    public final void updateHostState(@MediaLocation()
    int location, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaHostState hostState) {
    }
    
    /**
     * Get the dimensions of all players combined, which determines the overall height of the
     * media carousel and the media hosts.
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.util.animation.MeasurementOutput updateCarouselDimensions(@MediaLocation()
    int location, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaHostState hostState) {
        return null;
    }
    
    /**
     * Add a callback to be called when a MediaState has updated
     */
    public final void addCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaHostStatesManager.Callback callback) {
    }
    
    /**
     * Remove a callback that listens to media states
     */
    public final void removeCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaHostStatesManager.Callback callback) {
    }
    
    /**
     * Register a controller that listens to media states and is used to determine the size of
     * the media carousel
     */
    public final void addController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaViewController controller) {
    }
    
    /**
     * Notify the manager about the removal of a controller.
     */
    public final void removeController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaViewController controller) {
    }
    
    @javax.inject.Inject()
    public MediaHostStatesManager() {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001a\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\bf\u0018\u00002\u00020\u0001J\u0018\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\u0006\u0010\u0006\u001a\u00020\u0007H&"}, d2 = {"Lcom/android/systemui/media/MediaHostStatesManager$Callback;", "", "onHostStateChanged", "", "location", "", "mediaHostState", "Lcom/android/systemui/media/MediaHostState;"})
    public static abstract interface Callback {
        
        /**
         * Notify the callbacks that a media state for a host has changed, and that the
         * corresponding view states should be updated and applied
         */
        public abstract void onHostStateChanged(@MediaLocation()
        int location, @org.jetbrains.annotations.NotNull()
        com.android.systemui.media.MediaHostState mediaHostState);
    }
}