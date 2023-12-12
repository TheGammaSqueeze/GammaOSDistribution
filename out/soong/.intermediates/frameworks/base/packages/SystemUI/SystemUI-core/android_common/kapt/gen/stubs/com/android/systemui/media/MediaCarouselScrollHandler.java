package com.android.systemui.media;

import android.graphics.Outline;
import android.util.MathUtils;
import android.view.GestureDetector;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.view.ViewOutlineProvider;
import androidx.core.view.GestureDetectorCompat;
import androidx.dynamicanimation.animation.FloatPropertyCompat;
import androidx.dynamicanimation.animation.SpringForce;
import com.android.settingslib.Utils;
import com.android.systemui.Gefingerpoken;
import com.android.systemui.R;
import com.android.systemui.classifier.FalsingCollector;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.qs.PageIndicator;
import com.android.systemui.util.concurrency.DelayableExecutor;
import com.android.wm.shell.animation.PhysicsAnimator;

/**
 * A controller class for the media scrollview, responsible for touch handling
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0094\u0001\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u000b\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u0007\n\u0002\b\f\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\t\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\r\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\b\u0015\u0018\u0000 j2\u00020\u0001:\u0001jB\u0080\u0001\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\f\u0010\b\u001a\b\u0012\u0004\u0012\u00020\n0\t\u0012\f\u0010\u000b\u001a\b\u0012\u0004\u0012\u00020\n0\t\u0012!\u0010\f\u001a\u001d\u0012\u0013\u0012\u00110\u000e\u00a2\u0006\f\b\u000f\u0012\b\b\u0010\u0012\u0004\b\b(\u0011\u0012\u0004\u0012\u00020\n0\r\u0012\u0006\u0010\u0012\u001a\u00020\u0013\u0012\u0006\u0010\u0014\u001a\u00020\u0015\u0012\u0012\u0010\u0016\u001a\u000e\u0012\u0004\u0012\u00020\u000e\u0012\u0004\u0012\u00020\n0\r\u00a2\u0006\u0002\u0010\u0017J\b\u0010G\u001a\u00020\u0019H\u0002J\b\u0010H\u001a\u00020\u000eH\u0002J\u0018\u0010I\u001a\u00020\u000e2\u0006\u0010J\u001a\u00020\u001c2\u0006\u0010K\u001a\u00020\u001cH\u0002J\u0010\u0010L\u001a\u00020\u000e2\u0006\u0010M\u001a\u00020NH\u0002J\u0018\u0010O\u001a\u00020\n2\u0006\u0010P\u001a\u00020\u00192\u0006\u0010Q\u001a\u00020\u0019H\u0002J\u0006\u0010R\u001a\u00020\nJ\u000e\u0010S\u001a\u00020\n2\u0006\u0010T\u001a\u00020UJ\u001e\u0010V\u001a\u00020\u000e2\u0006\u0010W\u001a\u00020N2\u0006\u0010X\u001a\u00020N2\u0006\u0010Y\u001a\u00020\u001cJ\u000e\u0010Z\u001a\u00020\n2\u0006\u0010[\u001a\u00020;J\u0010\u0010\\\u001a\u00020\u000e2\u0006\u0010M\u001a\u00020NH\u0002J\u0010\u0010]\u001a\u00020\n2\b\b\u0002\u0010^\u001a\u00020\u000eJ\u0018\u0010_\u001a\u00020\n2\b\b\u0002\u0010`\u001a\u00020\u00192\u0006\u0010a\u001a\u00020\u0019J\u0006\u0010b\u001a\u00020\nJ\u0016\u0010c\u001a\u00020\n2\u0006\u0010d\u001a\u00020\u00192\u0006\u0010e\u001a\u00020\u0019J\b\u0010f\u001a\u00020\nH\u0002J\b\u0010g\u001a\u00020\nH\u0002J\b\u0010h\u001a\u00020\nH\u0002J\b\u0010i\u001a\u00020\nH\u0002R\u000e\u0010\u0018\u001a\u00020\u0019X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001a\u001a\u00020\u0019X\u0082\u000e\u00a2\u0006\u0002\n\u0000R)\u0010\f\u001a\u001d\u0012\u0013\u0012\u00110\u000e\u00a2\u0006\f\b\u000f\u0012\b\b\u0010\u0012\u0004\b\b(\u0011\u0012\u0004\u0012\u00020\n0\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R$\u0010\u001d\u001a\u00020\u001c2\u0006\u0010\u001b\u001a\u00020\u001c@BX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001e\u0010\u001f\"\u0004\b \u0010!R\u000e\u0010\"\u001a\u00020\u0019X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010\b\u001a\b\u0012\u0004\u0012\u00020\n0\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0013X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0014\u001a\u00020\u0015X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010#\u001a\u00020\u000eX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b$\u0010%\"\u0004\b&\u0010\'R\u000e\u0010(\u001a\u00020)X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010*\u001a\u00020+X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0011\u0010,\u001a\u00020\u000e8F\u00a2\u0006\u0006\u001a\u0004\b,\u0010%R\u001a\u0010\u0016\u001a\u000e\u0012\u0004\u0012\u00020\u000e\u0012\u0004\u0012\u00020\n0\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010-\u001a\u00020.X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R$\u0010/\u001a\u00020\u00192\u0006\u0010\u001b\u001a\u00020\u0019@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b0\u00101\"\u0004\b2\u00103R\u001a\u00104\u001a\u00020\u000eX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b5\u0010%\"\u0004\b6\u0010\'R\u000e\u00107\u001a\u000208X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u00109\u001a\u00020\u0019X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010:\u001a\u00020;X\u0082.\u00a2\u0006\u0002\n\u0000R\u001a\u0010<\u001a\u00020\u000eX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b=\u0010%\"\u0004\b>\u0010\'R\u000e\u0010?\u001a\u00020@X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u000b\u001a\b\u0012\u0004\u0012\u00020\n0\tX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001e\u0010B\u001a\u00020\u00192\u0006\u0010A\u001a\u00020\u0019@BX\u0086\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\bC\u00101R\u001a\u0010D\u001a\u00020\u000eX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\bE\u0010%\"\u0004\bF\u0010\'"}, d2 = {"Lcom/android/systemui/media/MediaCarouselScrollHandler;", "", "scrollView", "Lcom/android/systemui/media/MediaScrollView;", "pageIndicator", "Lcom/android/systemui/qs/PageIndicator;", "mainExecutor", "Lcom/android/systemui/util/concurrency/DelayableExecutor;", "dismissCallback", "Lkotlin/Function0;", "", "translationChangedListener", "closeGuts", "Lkotlin/Function1;", "", "Lkotlin/ParameterName;", "name", "immediate", "falsingCollector", "Lcom/android/systemui/classifier/FalsingCollector;", "falsingManager", "Lcom/android/systemui/plugins/FalsingManager;", "logSmartspaceImpression", "(Lcom/android/systemui/media/MediaScrollView;Lcom/android/systemui/qs/PageIndicator;Lcom/android/systemui/util/concurrency/DelayableExecutor;Lkotlin/jvm/functions/Function0;Lkotlin/jvm/functions/Function0;Lkotlin/jvm/functions/Function1;Lcom/android/systemui/classifier/FalsingCollector;Lcom/android/systemui/plugins/FalsingManager;Lkotlin/jvm/functions/Function1;)V", "carouselHeight", "", "carouselWidth", "value", "", "contentTranslation", "getContentTranslation", "()F", "setContentTranslation", "(F)V", "cornerRadius", "falsingProtectionNeeded", "getFalsingProtectionNeeded", "()Z", "setFalsingProtectionNeeded", "(Z)V", "gestureDetector", "Landroidx/core/view/GestureDetectorCompat;", "gestureListener", "Landroid/view/GestureDetector$SimpleOnGestureListener;", "isRtl", "mediaContent", "Landroid/view/ViewGroup;", "playerWidthPlusPadding", "getPlayerWidthPlusPadding", "()I", "setPlayerWidthPlusPadding", "(I)V", "qsExpanded", "getQsExpanded", "setQsExpanded", "scrollChangedListener", "Landroid/view/View$OnScrollChangeListener;", "scrollIntoCurrentMedia", "settingsButton", "Landroid/view/View;", "showsSettingsButton", "getShowsSettingsButton", "setShowsSettingsButton", "touchListener", "Lcom/android/systemui/Gefingerpoken;", "<set-?>", "visibleMediaIndex", "getVisibleMediaIndex", "visibleToUser", "getVisibleToUser", "setVisibleToUser", "getMaxTranslation", "isFalseTouch", "onFling", "vX", "vY", "onInterceptTouch", "motionEvent", "Landroid/view/MotionEvent;", "onMediaScrollingChanged", "newIndex", "scrollInAmount", "onPlayersChanged", "onPrePlayerRemoved", "removed", "Lcom/android/systemui/media/MediaControlPanel;", "onScroll", "down", "lastMotion", "distanceX", "onSettingsButtonUpdated", "button", "onTouch", "resetTranslation", "animate", "scrollToPlayer", "sourceIndex", "destIndex", "scrollToStart", "setCarouselBounds", "currentCarouselWidth", "currentCarouselHeight", "updateClipToOutline", "updateMediaPaddings", "updatePlayerVisibilities", "updateSettingsPresentation", "Companion"})
public final class MediaCarouselScrollHandler {
    
    /**
     * Do we need falsing protection?
     */
    private boolean falsingProtectionNeeded = false;
    
    /**
     * The width of the carousel
     */
    private int carouselWidth = 0;
    
    /**
     * The height of the carousel
     */
    private int carouselHeight = 0;
    
    /**
     * How much are we scrolled into the current media?
     */
    private int cornerRadius = 0;
    
    /**
     * The content where the players are added
     */
    private android.view.ViewGroup mediaContent;
    
    /**
     * The gesture detector to detect touch gestures
     */
    private final androidx.core.view.GestureDetectorCompat gestureDetector = null;
    
    /**
     * The settings button view
     */
    private android.view.View settingsButton;
    
    /**
     * What's the currently visible player index?
     */
    private int visibleMediaIndex = 0;
    
    /**
     * How much are we scrolled into the current media?
     */
    private int scrollIntoCurrentMedia = 0;
    
    /**
     * how much is the content translated in X
     */
    private float contentTranslation = 0.0F;
    
    /**
     * The width of a player including padding
     */
    private int playerWidthPlusPadding = 0;
    
    /**
     * Does the dismiss currently show the setting cog?
     */
    private boolean showsSettingsButton = false;
    
    /**
     * A utility to detect gestures, used in the touch listener
     */
    private final android.view.GestureDetector.SimpleOnGestureListener gestureListener = null;
    
    /**
     * The touch listener for the scroll view
     */
    private final com.android.systemui.Gefingerpoken touchListener = null;
    
    /**
     * A listener that is invoked when the scrolling changes to update player visibilities
     */
    private final android.view.View.OnScrollChangeListener scrollChangedListener = null;
    
    /**
     * Whether the media card is visible to user if any
     */
    private boolean visibleToUser = false;
    
    /**
     * Whether the quick setting is expanded or not
     */
    private boolean qsExpanded = false;
    private final com.android.systemui.media.MediaScrollView scrollView = null;
    private final com.android.systemui.qs.PageIndicator pageIndicator = null;
    private final com.android.systemui.util.concurrency.DelayableExecutor mainExecutor = null;
    private final kotlin.jvm.functions.Function0<kotlin.Unit> dismissCallback = null;
    private kotlin.jvm.functions.Function0<kotlin.Unit> translationChangedListener;
    private final kotlin.jvm.functions.Function1<java.lang.Boolean, kotlin.Unit> closeGuts = null;
    private final com.android.systemui.classifier.FalsingCollector falsingCollector = null;
    private final com.android.systemui.plugins.FalsingManager falsingManager = null;
    private final kotlin.jvm.functions.Function1<java.lang.Boolean, kotlin.Unit> logSmartspaceImpression = null;
    private static final androidx.dynamicanimation.animation.FloatPropertyCompat<com.android.systemui.media.MediaCarouselScrollHandler> CONTENT_TRANSLATION = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.media.MediaCarouselScrollHandler.Companion Companion = null;
    
    public final boolean isRtl() {
        return false;
    }
    
    public final boolean getFalsingProtectionNeeded() {
        return false;
    }
    
    public final void setFalsingProtectionNeeded(boolean p0) {
    }
    
    public final int getVisibleMediaIndex() {
        return 0;
    }
    
    public final float getContentTranslation() {
        return 0.0F;
    }
    
    private final void setContentTranslation(float value) {
    }
    
    public final int getPlayerWidthPlusPadding() {
        return 0;
    }
    
    public final void setPlayerWidthPlusPadding(int value) {
    }
    
    public final boolean getShowsSettingsButton() {
        return false;
    }
    
    public final void setShowsSettingsButton(boolean p0) {
    }
    
    public final boolean getVisibleToUser() {
        return false;
    }
    
    public final void setVisibleToUser(boolean p0) {
    }
    
    public final boolean getQsExpanded() {
        return false;
    }
    
    public final void setQsExpanded(boolean p0) {
    }
    
    public final void onSettingsButtonUpdated(@org.jetbrains.annotations.NotNull()
    android.view.View button) {
    }
    
    private final void updateSettingsPresentation() {
    }
    
    private final boolean onTouch(android.view.MotionEvent motionEvent) {
        return false;
    }
    
    private final boolean isFalseTouch() {
        return false;
    }
    
    private final int getMaxTranslation() {
        return 0;
    }
    
    private final boolean onInterceptTouch(android.view.MotionEvent motionEvent) {
        return false;
    }
    
    public final boolean onScroll(@org.jetbrains.annotations.NotNull()
    android.view.MotionEvent down, @org.jetbrains.annotations.NotNull()
    android.view.MotionEvent lastMotion, float distanceX) {
        return false;
    }
    
    private final boolean onFling(float vX, float vY) {
        return false;
    }
    
    /**
     * Reset the translation of the players when swiped
     */
    public final void resetTranslation(boolean animate) {
    }
    
    private final void updateClipToOutline() {
    }
    
    private final void onMediaScrollingChanged(int newIndex, int scrollInAmount) {
    }
    
    /**
     * Notified whenever the players or their order has changed
     */
    public final void onPlayersChanged() {
    }
    
    private final void updateMediaPaddings() {
    }
    
    private final void updatePlayerVisibilities() {
    }
    
    /**
     * Notify that a player will be removed right away. This gives us the opporunity to look
     * where it was and update our scroll position.
     */
    public final void onPrePlayerRemoved(@org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaControlPanel removed) {
    }
    
    /**
     * Update the bounds of the carousel
     */
    public final void setCarouselBounds(int currentCarouselWidth, int currentCarouselHeight) {
    }
    
    /**
     * Reset the MediaScrollView to the start.
     */
    public final void scrollToStart() {
    }
    
    /**
     * Smooth scroll to the destination player.
     *
     * @param sourceIndex optional source index to indicate where the scroll should begin.
     * @param destIndex destination index to indicate where the scroll should end.
     */
    public final void scrollToPlayer(int sourceIndex, int destIndex) {
    }
    
    public MediaCarouselScrollHandler(@org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaScrollView scrollView, @org.jetbrains.annotations.NotNull()
    com.android.systemui.qs.PageIndicator pageIndicator, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.concurrency.DelayableExecutor mainExecutor, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function0<kotlin.Unit> dismissCallback, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function0<kotlin.Unit> translationChangedListener, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super java.lang.Boolean, kotlin.Unit> closeGuts, @org.jetbrains.annotations.NotNull()
    com.android.systemui.classifier.FalsingCollector falsingCollector, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.FalsingManager falsingManager, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super java.lang.Boolean, kotlin.Unit> logSmartspaceImpression) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u0014\u0010\u0003\u001a\b\u0012\u0004\u0012\u00020\u00050\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/media/MediaCarouselScrollHandler$Companion;", "", "()V", "CONTENT_TRANSLATION", "Landroidx/dynamicanimation/animation/FloatPropertyCompat;", "Lcom/android/systemui/media/MediaCarouselScrollHandler;"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}