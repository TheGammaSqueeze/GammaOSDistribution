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
 * A class responsible for controlling a single instance of a media player handling interactions
 * with the view instance and keeping the media view states up to date.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0098\u0001\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\t\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\f\n\u0002\u0010\u0007\n\u0002\b\n\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\u0010\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010%\n\u0002\b\u000b\n\u0002\u0018\u0002\n\u0002\b\u0018\u0018\u0000 r2\u00020\u0001:\u0002rsB\u001f\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ\u0016\u0010P\u001a\u0002062\u0006\u0010Q\u001a\u00020\f2\u0006\u0010R\u001a\u00020\fJ\u0016\u0010S\u001a\u0002062\u0006\u0010E\u001a\u00020F2\u0006\u0010L\u001a\u00020MJ\u0012\u0010T\u001a\u0002062\b\b\u0002\u0010U\u001a\u00020\nH\u0007J\u0010\u0010V\u001a\u00020\u000f2\u0006\u0010W\u001a\u00020\"H\u0002J\b\u0010X\u001a\u000206H\u0002J \u0010Y\u001a\u00020@2\u0006\u0010Z\u001a\u00020[2\u0006\u0010\\\u001a\u00020\n2\u0006\u0010]\u001a\u00020@H\u0002J\u0010\u0010^\u001a\u0004\u0018\u00010/2\u0006\u0010_\u001a\u00020[J\u0014\u0010`\u001a\u0004\u0018\u00010B2\b\u0010Z\u001a\u0004\u0018\u00010[H\u0002J\u0012\u0010a\u001a\u0004\u0018\u00010B2\u0006\u0010b\u001a\u00020\u0015H\u0002J\u0006\u0010c\u001a\u000206J\u000e\u0010d\u001a\u0002062\u0006\u0010e\u001a\u00020\u0015J\u0006\u0010f\u001a\u000206J\u0006\u0010g\u001a\u000206J&\u0010h\u001a\u0002062\u0006\u0010i\u001a\u00020\u00152\u0006\u0010j\u001a\u00020\u00152\u0006\u0010k\u001a\u00020\"2\u0006\u0010l\u001a\u00020\nJ\u0010\u0010m\u001a\u0002062\u0006\u0010n\u001a\u00020BH\u0002J\u0010\u0010o\u001a\u0002062\u0006\u0010L\u001a\u00020MH\u0002J$\u0010p\u001a\u0004\u0018\u00010B2\b\u0010n\u001a\u0004\u0018\u00010B2\u0006\u0010b\u001a\u00020\u00152\u0006\u0010q\u001a\u00020BH\u0002R\u000e\u0010\t\u001a\u00020\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0011\u0010\u000e\u001a\u00020\u000f\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0010\u0010\u0011R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0013X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R \u0010\u0014\u001a\u00020\u0015X\u0086\u000e\u00a2\u0006\u0014\n\u0000\u0012\u0004\b\u0016\u0010\u0017\u001a\u0004\b\u0018\u0010\u0019\"\u0004\b\u001a\u0010\u001bR\u001a\u0010\u001c\u001a\u00020\u0015X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001d\u0010\u0019\"\u0004\b\u001e\u0010\u001bR\u0014\u0010\u001f\u001a\u00020\u0015X\u0082\u000e\u00a2\u0006\b\n\u0000\u0012\u0004\b \u0010\u0017R\u000e\u0010!\u001a\u00020\"X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001a\u0010#\u001a\u00020\u0015X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b$\u0010\u0019\"\u0004\b%\u0010\u001bR\u0011\u0010&\u001a\u00020\u000f\u00a2\u0006\b\n\u0000\u001a\u0004\b\'\u0010\u0011R\u000e\u0010(\u001a\u00020\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001e\u0010*\u001a\u00020\n2\u0006\u0010)\u001a\u00020\n@BX\u0086\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b*\u0010+R\u000e\u0010,\u001a\u00020-X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010.\u001a\u00020/X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u00100\u001a\u00020\nX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b1\u0010+\"\u0004\b2\u00103R \u00104\u001a\b\u0012\u0004\u0012\u00020605X\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b7\u00108\"\u0004\b9\u0010:R\u0011\u0010;\u001a\u00020<\u00a2\u0006\b\n\u0000\u001a\u0004\b=\u0010>R\u000e\u0010?\u001a\u00020@X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010A\u001a\u00020BX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010C\u001a\u00020BX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010D\u001a\u00020BX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010E\u001a\u0004\u0018\u00010FX\u0082\u000e\u00a2\u0006\u0002\n\u0000R \u0010G\u001a\u00020\"2\u0006\u0010)\u001a\u00020\"8F@BX\u0086\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\bH\u0010IR \u0010J\u001a\u00020\"2\u0006\u0010)\u001a\u00020\"8F@BX\u0086\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\bK\u0010IR\u000e\u0010L\u001a\u00020MX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001c\u0010N\u001a\u0010\u0012\u0004\u0012\u00020@\u0012\u0006\u0012\u0004\u0018\u00010B0OX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/media/MediaViewController;", "", "context", "Landroid/content/Context;", "configurationController", "Lcom/android/systemui/statusbar/policy/ConfigurationController;", "mediaHostStatesManager", "Lcom/android/systemui/media/MediaHostStatesManager;", "(Landroid/content/Context;Lcom/android/systemui/statusbar/policy/ConfigurationController;Lcom/android/systemui/media/MediaHostStatesManager;)V", "animateNextStateChange", "", "animationDelay", "", "animationDuration", "collapsedLayout", "Landroidx/constraintlayout/widget/ConstraintSet;", "getCollapsedLayout", "()Landroidx/constraintlayout/widget/ConstraintSet;", "configurationListener", "Lcom/android/systemui/statusbar/policy/ConfigurationController$ConfigurationListener;", "currentEndLocation", "", "getCurrentEndLocation$annotations", "()V", "getCurrentEndLocation", "()I", "setCurrentEndLocation", "(I)V", "currentHeight", "getCurrentHeight", "setCurrentHeight", "currentStartLocation", "getCurrentStartLocation$annotations", "currentTransitionProgress", "", "currentWidth", "getCurrentWidth", "setCurrentWidth", "expandedLayout", "getExpandedLayout", "firstRefresh", "<set-?>", "isGutsVisible", "()Z", "layoutController", "Lcom/android/systemui/util/animation/TransitionLayoutController;", "measurement", "Lcom/android/systemui/util/animation/MeasurementOutput;", "shouldHideGutsSettings", "getShouldHideGutsSettings", "setShouldHideGutsSettings", "(Z)V", "sizeChangedListener", "Lkotlin/Function0;", "", "getSizeChangedListener", "()Lkotlin/jvm/functions/Function0;", "setSizeChangedListener", "(Lkotlin/jvm/functions/Function0;)V", "stateCallback", "Lcom/android/systemui/media/MediaHostStatesManager$Callback;", "getStateCallback", "()Lcom/android/systemui/media/MediaHostStatesManager$Callback;", "tmpKey", "Lcom/android/systemui/media/CacheKey;", "tmpState", "Lcom/android/systemui/util/animation/TransitionViewState;", "tmpState2", "tmpState3", "transitionLayout", "Lcom/android/systemui/util/animation/TransitionLayout;", "translationX", "getTranslationX", "()F", "translationY", "getTranslationY", "type", "Lcom/android/systemui/media/MediaViewController$TYPE;", "viewStates", "", "animatePendingStateChange", "duration", "delay", "attach", "closeGuts", "immediate", "constraintSetForExpansion", "expansion", "ensureAllMeasurements", "getKey", "state", "Lcom/android/systemui/media/MediaHostState;", "guts", "result", "getMeasurementsForState", "hostState", "obtainViewState", "obtainViewStateForLocation", "location", "onDestroy", "onLocationPreChange", "newLocation", "openGuts", "refreshState", "setCurrentState", "startLocation", "endLocation", "transitionProgress", "applyImmediately", "setGutsViewState", "viewState", "updateMediaViewControllerType", "updateViewStateToCarouselSize", "outState", "Companion", "TYPE"})
public final class MediaViewController {
    
    /**
     * A listener when the current dimensions of the player change
     */
    public kotlin.jvm.functions.Function0<kotlin.Unit> sizeChangedListener;
    private boolean firstRefresh = true;
    private com.android.systemui.util.animation.TransitionLayout transitionLayout;
    private final com.android.systemui.util.animation.TransitionLayoutController layoutController = null;
    private long animationDelay = 0L;
    private long animationDuration = 0L;
    private boolean animateNextStateChange = false;
    private final com.android.systemui.util.animation.MeasurementOutput measurement = null;
    private com.android.systemui.media.MediaViewController.TYPE type = com.android.systemui.media.MediaViewController.TYPE.PLAYER;
    
    /**
     * A map containing all viewStates for all locations of this mediaState
     */
    private final java.util.Map<com.android.systemui.media.CacheKey, com.android.systemui.util.animation.TransitionViewState> viewStates = null;
    
    /**
     * The ending location of the view where it ends when all animations and transitions have
     * finished
     */
    private int currentEndLocation = -1;
    
    /**
     * The starting location of the view where it starts for all animations and transitions
     */
    private int currentStartLocation = -1;
    
    /**
     * The progress of the transition or 1.0 if there is no transition happening
     */
    private float currentTransitionProgress = 1.0F;
    
    /**
     * A temporary state used to store intermediate measurements.
     */
    private final com.android.systemui.util.animation.TransitionViewState tmpState = null;
    
    /**
     * A temporary state used to store intermediate measurements.
     */
    private final com.android.systemui.util.animation.TransitionViewState tmpState2 = null;
    
    /**
     * A temporary state used to store intermediate measurements.
     */
    private final com.android.systemui.util.animation.TransitionViewState tmpState3 = null;
    
    /**
     * A temporary cache key to be used to look up cache entries
     */
    private final com.android.systemui.media.CacheKey tmpKey = null;
    
    /**
     * The current width of the player. This might not factor in case the player is animating
     * to the current state, but represents the end state
     */
    private int currentWidth = 0;
    
    /**
     * The current height of the player. This might not factor in case the player is animating
     * to the current state, but represents the end state
     */
    private int currentHeight = 0;
    
    /**
     * Get the translationX of the layout
     */
    private float translationX = 0.0F;
    
    /**
     * Get the translationY of the layout
     */
    private float translationY = 0.0F;
    
    /**
     * A callback for RTL config changes
     */
    private final com.android.systemui.statusbar.policy.ConfigurationController.ConfigurationListener configurationListener = null;
    
    /**
     * A callback for media state changes
     */
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.media.MediaHostStatesManager.Callback stateCallback = null;
    
    /**
     * The expanded constraint set used to render a expanded player. If it is modified, make sure
     * to call [refreshState]
     */
    @org.jetbrains.annotations.NotNull()
    private final androidx.constraintlayout.widget.ConstraintSet collapsedLayout = null;
    
    /**
     * The expanded constraint set used to render a collapsed player. If it is modified, make sure
     * to call [refreshState]
     */
    @org.jetbrains.annotations.NotNull()
    private final androidx.constraintlayout.widget.ConstraintSet expandedLayout = null;
    
    /**
     * Whether the guts are visible for the associated player.
     */
    private boolean isGutsVisible = false;
    
    /**
     * Whether the settings button in the guts should be visible
     */
    private boolean shouldHideGutsSettings = false;
    private final android.content.Context context = null;
    private final com.android.systemui.statusbar.policy.ConfigurationController configurationController = null;
    private final com.android.systemui.media.MediaHostStatesManager mediaHostStatesManager = null;
    public static final long GUTS_ANIMATION_DURATION = 500L;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.media.MediaViewController.Companion Companion = null;
    
    @org.jetbrains.annotations.NotNull()
    public final kotlin.jvm.functions.Function0<kotlin.Unit> getSizeChangedListener() {
        return null;
    }
    
    public final void setSizeChangedListener(@org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function0<kotlin.Unit> p0) {
    }
    
    /**
     * The ending location of the view where it ends when all animations and transitions have
     * finished
     */
    @MediaLocation()
    @java.lang.Deprecated()
    public static void getCurrentEndLocation$annotations() {
    }
    
    public final int getCurrentEndLocation() {
        return 0;
    }
    
    public final void setCurrentEndLocation(int p0) {
    }
    
    /**
     * The starting location of the view where it starts for all animations and transitions
     */
    @MediaLocation()
    @java.lang.Deprecated()
    private static void getCurrentStartLocation$annotations() {
    }
    
    public final int getCurrentWidth() {
        return 0;
    }
    
    public final void setCurrentWidth(int p0) {
    }
    
    public final int getCurrentHeight() {
        return 0;
    }
    
    public final void setCurrentHeight(int p0) {
    }
    
    public final float getTranslationX() {
        return 0.0F;
    }
    
    public final float getTranslationY() {
        return 0.0F;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.media.MediaHostStatesManager.Callback getStateCallback() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final androidx.constraintlayout.widget.ConstraintSet getCollapsedLayout() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final androidx.constraintlayout.widget.ConstraintSet getExpandedLayout() {
        return null;
    }
    
    public final boolean isGutsVisible() {
        return false;
    }
    
    public final boolean getShouldHideGutsSettings() {
        return false;
    }
    
    public final void setShouldHideGutsSettings(boolean p0) {
    }
    
    /**
     * Notify this controller that the view has been removed and all listeners should be destroyed
     */
    public final void onDestroy() {
    }
    
    /**
     * Show guts with an animated transition.
     */
    public final void openGuts() {
    }
    
    /**
     * Close the guts for the associated player.
     *
     * @param immediate if `false`, it will animate the transition.
     */
    public final void closeGuts(boolean immediate) {
    }
    
    /**
     * Close the guts for the associated player.
     *
     * @param immediate if `false`, it will animate the transition.
     */
    public final void closeGuts() {
    }
    
    private final void ensureAllMeasurements() {
    }
    
    /**
     * Get the constraintSet for a given expansion
     */
    private final androidx.constraintlayout.widget.ConstraintSet constraintSetForExpansion(float expansion) {
        return null;
    }
    
    /**
     * Set the views to be showing/hidden based on the [isGutsVisible] for a given
     * [TransitionViewState].
     */
    private final void setGutsViewState(com.android.systemui.util.animation.TransitionViewState viewState) {
    }
    
    /**
     * Obtain a new viewState for a given media state. This usually returns a cached state, but if
     * it's not available, it will recreate one by measuring, which may be expensive.
     */
    private final com.android.systemui.util.animation.TransitionViewState obtainViewState(com.android.systemui.media.MediaHostState state) {
        return null;
    }
    
    private final com.android.systemui.media.CacheKey getKey(com.android.systemui.media.MediaHostState state, boolean guts, com.android.systemui.media.CacheKey result) {
        return null;
    }
    
    /**
     * Attach a view to this controller. This may perform measurements if it's not available yet
     * and should therefore be done carefully.
     */
    public final void attach(@org.jetbrains.annotations.NotNull()
    com.android.systemui.util.animation.TransitionLayout transitionLayout, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaViewController.TYPE type) {
    }
    
    /**
     * Obtain a measurement for a given location. This makes sure that the state is up to date
     * and all widgets know their location. Calling this method may create a measurement if we
     * don't have a cached value available already.
     */
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.util.animation.MeasurementOutput getMeasurementsForState(@org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaHostState hostState) {
        return null;
    }
    
    /**
     * Set a new state for the controlled view which can be an interpolation between multiple
     * locations.
     */
    public final void setCurrentState(@MediaLocation()
    int startLocation, @MediaLocation()
    int endLocation, float transitionProgress, boolean applyImmediately) {
    }
    
    private final com.android.systemui.util.animation.TransitionViewState updateViewStateToCarouselSize(com.android.systemui.util.animation.TransitionViewState viewState, int location, com.android.systemui.util.animation.TransitionViewState outState) {
        return null;
    }
    
    private final void updateMediaViewControllerType(com.android.systemui.media.MediaViewController.TYPE type) {
    }
    
    /**
     * Retrieves the [TransitionViewState] and [MediaHostState] of a [@MediaLocation].
     * In the event of [location] not being visible, [locationWhenHidden] will be used instead.
     *
     * @param location Target
     * @param locationWhenHidden Location that will be used when the target is not
     * [MediaHost.visible]
     * @return State require for executing a transition, and also the respective [MediaHost].
     */
    private final com.android.systemui.util.animation.TransitionViewState obtainViewStateForLocation(@MediaLocation()
    int location) {
        return null;
    }
    
    /**
     * Notify that the location is changing right now and a [setCurrentState] change is imminent.
     * This updates the width the view will me measured with.
     */
    public final void onLocationPreChange(@MediaLocation()
    int newLocation) {
    }
    
    /**
     * Request that the next state change should be animated with the given parameters.
     */
    public final void animatePendingStateChange(long duration, long delay) {
    }
    
    /**
     * Clear all existing measurements and refresh the state to match the view.
     */
    public final void refreshState() {
    }
    
    @javax.inject.Inject()
    public MediaViewController(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.ConfigurationController configurationController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaHostStatesManager mediaHostStatesManager) {
        super();
    }
    
    /**
     * Indicating the media view controller is for a player or recommendation.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\f\n\u0002\u0018\u0002\n\u0002\u0010\u0010\n\u0002\b\u0003\b\u0086\u0001\u0018\u00002\b\u0012\u0004\u0012\u00020\u00000\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002j\u0002\b\u0003j\u0002\b\u0004"}, d2 = {"Lcom/android/systemui/media/MediaViewController$TYPE;", "", "(Ljava/lang/String;I)V", "PLAYER", "RECOMMENDATION"})
    public static enum TYPE {
        /*public static final*/ PLAYER /* = new PLAYER() */,
        /*public static final*/ RECOMMENDATION /* = new RECOMMENDATION() */;
        
        TYPE() {
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\t\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u0010\u0010\u0003\u001a\u00020\u00048\u0006X\u0087D\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/media/MediaViewController$Companion;", "", "()V", "GUTS_ANIMATION_DURATION", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}