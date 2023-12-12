package com.android.systemui.media;

import android.media.MediaMetadata;
import android.media.session.MediaController;
import android.media.session.PlaybackState;
import android.os.SystemClock;
import android.view.GestureDetector;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewConfiguration;
import android.widget.SeekBar;
import androidx.annotation.AnyThread;
import androidx.annotation.WorkerThread;
import androidx.core.view.GestureDetectorCompat;
import androidx.lifecycle.LiveData;
import androidx.lifecycle.MutableLiveData;
import com.android.systemui.dagger.qualifiers.Background;
import com.android.systemui.util.concurrency.RepeatableExecutor;
import javax.inject.Inject;

/**
 * ViewModel for seek bar in QS media player.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000l\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u000b\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\u0010\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\t\n\u0002\b\b\u0018\u00002\u00020\u0001:\u0003=>?B\u0011\b\u0007\u0012\b\b\u0001\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u000e\u0010.\u001a\u00020\u001d2\u0006\u0010/\u001a\u000200J\b\u00101\u001a\u00020\u001dH\u0003J\b\u00102\u001a\u00020\u001dH\u0003J\b\u00103\u001a\u00020\u001dH\u0007J\b\u00104\u001a\u00020\u001dH\u0007J\u0010\u00105\u001a\u00020\u001d2\u0006\u00106\u001a\u000207H\u0007J\b\u00108\u001a\u00020\u001dH\u0007J\u0010\u00109\u001a\u00020\u001d2\u0006\u00106\u001a\u000207H\u0007J\b\u0010:\u001a\u00020\u001dH\u0007J\u0012\u0010;\u001a\u00020\u001d2\b\u0010<\u001a\u0004\u0018\u00010\u0010H\u0007R\u001e\u0010\u0007\u001a\u00020\u00062\u0006\u0010\u0005\u001a\u00020\u0006@BX\u0082\u000e\u00a2\u0006\b\n\u0000\"\u0004\b\b\u0010\tR\u0014\u0010\n\u001a\b\u0012\u0004\u0012\u00020\u00060\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\rX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u000e\u001a\u0004\u0018\u00010\u000fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\"\u0010\u0011\u001a\u0004\u0018\u00010\u00102\b\u0010\u0005\u001a\u0004\u0018\u00010\u0010@BX\u0082\u000e\u00a2\u0006\b\n\u0000\"\u0004\b\u0012\u0010\u0013R\u000e\u0010\u0014\u001a\u00020\u0015X\u0082\u000e\u00a2\u0006\u0002\n\u0000R$\u0010\u0016\u001a\u00020\u00152\u0006\u0010\u0005\u001a\u00020\u0015@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0017\u0010\u0018\"\u0004\b\u0019\u0010\u001aR \u0010\u001b\u001a\b\u0012\u0004\u0012\u00020\u001d0\u001cX\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001e\u0010\u001f\"\u0004\b \u0010!R\u0010\u0010\"\u001a\u0004\u0018\u00010#X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0017\u0010$\u001a\b\u0012\u0004\u0012\u00020\u00060%8F\u00a2\u0006\u0006\u001a\u0004\b&\u0010\'R\u001e\u0010(\u001a\u00020\u00152\u0006\u0010\u0005\u001a\u00020\u0015@BX\u0082\u000e\u00a2\u0006\b\n\u0000\"\u0004\b)\u0010\u001aR\u0011\u0010*\u001a\u00020+8F\u00a2\u0006\u0006\u001a\u0004\b,\u0010-"}, d2 = {"Lcom/android/systemui/media/SeekBarViewModel;", "", "bgExecutor", "Lcom/android/systemui/util/concurrency/RepeatableExecutor;", "(Lcom/android/systemui/util/concurrency/RepeatableExecutor;)V", "value", "Lcom/android/systemui/media/SeekBarViewModel$Progress;", "_data", "set_data", "(Lcom/android/systemui/media/SeekBarViewModel$Progress;)V", "_progress", "Landroidx/lifecycle/MutableLiveData;", "callback", "Landroid/media/session/MediaController$Callback;", "cancel", "Ljava/lang/Runnable;", "Landroid/media/session/MediaController;", "controller", "setController", "(Landroid/media/session/MediaController;)V", "isFalseSeek", "", "listening", "getListening", "()Z", "setListening", "(Z)V", "logSmartspaceClick", "Lkotlin/Function0;", "", "getLogSmartspaceClick", "()Lkotlin/jvm/functions/Function0;", "setLogSmartspaceClick", "(Lkotlin/jvm/functions/Function0;)V", "playbackState", "Landroid/media/session/PlaybackState;", "progress", "Landroidx/lifecycle/LiveData;", "getProgress", "()Landroidx/lifecycle/LiveData;", "scrubbing", "setScrubbing", "seekBarListener", "Landroid/widget/SeekBar$OnSeekBarChangeListener;", "getSeekBarListener", "()Landroid/widget/SeekBar$OnSeekBarChangeListener;", "attachTouchHandlers", "bar", "Landroid/widget/SeekBar;", "checkIfPollingNeeded", "checkPlaybackPosition", "clearController", "onDestroy", "onSeek", "position", "", "onSeekFalse", "onSeekProgress", "onSeekStarting", "updateController", "mediaController", "Progress", "SeekBarChangeListener", "SeekBarTouchListener"})
public final class SeekBarViewModel {
    private com.android.systemui.media.SeekBarViewModel.Progress _data;
    private final androidx.lifecycle.MutableLiveData<com.android.systemui.media.SeekBarViewModel.Progress> _progress = null;
    private android.media.session.MediaController controller;
    private android.media.session.PlaybackState playbackState;
    private android.media.session.MediaController.Callback callback;
    private java.lang.Runnable cancel;
    
    /**
     * Indicates if the seek interaction is considered a false guesture.
     */
    private boolean isFalseSeek = false;
    
    /**
     * Listening state (QS open or closed) is used to control polling of progress.
     */
    private boolean listening = true;
    
    /**
     * Set to true when the user is touching the seek bar to change the position.
     */
    private boolean scrubbing = false;
    public kotlin.jvm.functions.Function0<kotlin.Unit> logSmartspaceClick;
    private final com.android.systemui.util.concurrency.RepeatableExecutor bgExecutor = null;
    
    private final void set_data(com.android.systemui.media.SeekBarViewModel.Progress value) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final androidx.lifecycle.LiveData<com.android.systemui.media.SeekBarViewModel.Progress> getProgress() {
        return null;
    }
    
    private final void setController(android.media.session.MediaController value) {
    }
    
    public final boolean getListening() {
        return false;
    }
    
    public final void setListening(boolean value) {
    }
    
    private final void setScrubbing(boolean value) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final kotlin.jvm.functions.Function0<kotlin.Unit> getLogSmartspaceClick() {
        return null;
    }
    
    public final void setLogSmartspaceClick(@org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function0<kotlin.Unit> p0) {
    }
    
    /**
     * Event indicating that the user has started interacting with the seek bar.
     */
    @androidx.annotation.AnyThread()
    public final void onSeekStarting() {
    }
    
    /**
     * Event indicating that the user has moved the seek bar but hasn't yet finished the gesture.
     * @param position Current location in the track.
     */
    @androidx.annotation.AnyThread()
    public final void onSeekProgress(long position) {
    }
    
    /**
     * Event indicating that the seek interaction is a false gesture and it should be ignored.
     */
    @androidx.annotation.AnyThread()
    public final void onSeekFalse() {
    }
    
    /**
     * Handle request to change the current position in the media track.
     * @param position Place to seek to in the track.
     */
    @androidx.annotation.AnyThread()
    public final void onSeek(long position) {
    }
    
    /**
     * Updates media information.
     * @param mediaController controller for media session
     */
    @androidx.annotation.WorkerThread()
    public final void updateController(@org.jetbrains.annotations.Nullable()
    android.media.session.MediaController mediaController) {
    }
    
    /**
     * Puts the seek bar into a resumption state.
     *
     * This should be called when the media session behind the controller has been destroyed.
     */
    @androidx.annotation.AnyThread()
    public final void clearController() {
    }
    
    /**
     * Call to clean up any resources.
     */
    @androidx.annotation.AnyThread()
    public final void onDestroy() {
    }
    
    @androidx.annotation.WorkerThread()
    private final void checkPlaybackPosition() {
    }
    
    @androidx.annotation.WorkerThread()
    private final void checkIfPollingNeeded() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.widget.SeekBar.OnSeekBarChangeListener getSeekBarListener() {
        return null;
    }
    
    /**
     * Attach touch handlers to the seek bar view.
     */
    public final void attachTouchHandlers(@org.jetbrains.annotations.NotNull()
    android.widget.SeekBar bar) {
    }
    
    @javax.inject.Inject()
    public SeekBarViewModel(@org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Background()
    com.android.systemui.util.concurrency.RepeatableExecutor bgExecutor) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000,\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\b\u0002\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J \u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\u000eH\u0016J\u0010\u0010\u000f\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\nH\u0016J\u0010\u0010\u0010\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\nH\u0016R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0005\u0010\u0006"}, d2 = {"Lcom/android/systemui/media/SeekBarViewModel$SeekBarChangeListener;", "Landroid/widget/SeekBar$OnSeekBarChangeListener;", "viewModel", "Lcom/android/systemui/media/SeekBarViewModel;", "(Lcom/android/systemui/media/SeekBarViewModel;)V", "getViewModel", "()Lcom/android/systemui/media/SeekBarViewModel;", "onProgressChanged", "", "bar", "Landroid/widget/SeekBar;", "progress", "", "fromUser", "", "onStartTrackingTouch", "onStopTrackingTouch"})
    static final class SeekBarChangeListener implements android.widget.SeekBar.OnSeekBarChangeListener {
        @org.jetbrains.annotations.NotNull()
        private final com.android.systemui.media.SeekBarViewModel viewModel = null;
        
        @java.lang.Override()
        public void onProgressChanged(@org.jetbrains.annotations.NotNull()
        android.widget.SeekBar bar, int progress, boolean fromUser) {
        }
        
        @java.lang.Override()
        public void onStartTrackingTouch(@org.jetbrains.annotations.NotNull()
        android.widget.SeekBar bar) {
        }
        
        @java.lang.Override()
        public void onStopTrackingTouch(@org.jetbrains.annotations.NotNull()
        android.widget.SeekBar bar) {
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.media.SeekBarViewModel getViewModel() {
            return null;
        }
        
        public SeekBarChangeListener(@org.jetbrains.annotations.NotNull()
        com.android.systemui.media.SeekBarViewModel viewModel) {
            super();
        }
    }
    
    /**
     * Responsible for intercepting touch events before they reach the seek bar.
     *
     * This reduces the gestures seen by the seek bar so that users don't accidentially seek when
     * they intend to scroll the carousel.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000L\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0007\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\u0007\n\u0002\u0018\u0002\b\u0002\u0018\u00002\u00020\u00012\u00020\u0002B\u0015\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\u0002\u0010\u0007J\u0010\u0010\u000e\u001a\u00020\r2\u0006\u0010\u000f\u001a\u00020\u0010H\u0016J(\u0010\u0011\u001a\u00020\r2\u0006\u0010\u0012\u001a\u00020\u00102\u0006\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u0014H\u0016J\u0010\u0010\u0016\u001a\u00020\u00172\u0006\u0010\u000f\u001a\u00020\u0010H\u0016J(\u0010\u0018\u001a\u00020\r2\u0006\u0010\u0012\u001a\u00020\u00102\u0006\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0019\u001a\u00020\u00142\u0006\u0010\u001a\u001a\u00020\u0014H\u0016J\u0010\u0010\u001b\u001a\u00020\u00172\u0006\u0010\u000f\u001a\u00020\u0010H\u0016J\u0010\u0010\u001c\u001a\u00020\r2\u0006\u0010\u000f\u001a\u00020\u0010H\u0016J\u0018\u0010\u001d\u001a\u00020\r2\u0006\u0010\u001e\u001a\u00020\u001f2\u0006\u0010\u000f\u001a\u00020\u0010H\u0016R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\rX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/media/SeekBarViewModel$SeekBarTouchListener;", "Landroid/view/View$OnTouchListener;", "Landroid/view/GestureDetector$OnGestureListener;", "viewModel", "Lcom/android/systemui/media/SeekBarViewModel;", "bar", "Landroid/widget/SeekBar;", "(Lcom/android/systemui/media/SeekBarViewModel;Landroid/widget/SeekBar;)V", "detector", "Landroidx/core/view/GestureDetectorCompat;", "flingVelocity", "", "shouldGoToSeekBar", "", "onDown", "event", "Landroid/view/MotionEvent;", "onFling", "eventStart", "velocityX", "", "velocityY", "onLongPress", "", "onScroll", "distanceX", "distanceY", "onShowPress", "onSingleTapUp", "onTouch", "view", "Landroid/view/View;"})
    static final class SeekBarTouchListener implements android.view.View.OnTouchListener, android.view.GestureDetector.OnGestureListener {
        private final androidx.core.view.GestureDetectorCompat detector = null;
        private final int flingVelocity = 0;
        private boolean shouldGoToSeekBar = false;
        private final com.android.systemui.media.SeekBarViewModel viewModel = null;
        private final android.widget.SeekBar bar = null;
        
        /**
         * Decide which touch events to intercept before they reach the seek bar.
         *
         * Based on the gesture detected, we decide whether we want the event to reach the seek bar.
         * If we want the seek bar to see the event, then we return false so that the event isn't
         * handled here and it will be passed along. If, however, we don't want the seek bar to see
         * the event, then return true so that the event is handled here.
         *
         * When the seek bar is contained in the carousel, the carousel still has the ability to
         * intercept the touch event. So, even though we may handle the event here, the carousel can
         * still intercept the event. This way, gestures that we consider falses on the seek bar can
         * still be used by the carousel for paging.
         *
         * Returns true for events that we don't want dispatched to the seek bar.
         */
        @java.lang.Override()
        public boolean onTouch(@org.jetbrains.annotations.NotNull()
        android.view.View view, @org.jetbrains.annotations.NotNull()
        android.view.MotionEvent event) {
            return false;
        }
        
        /**
         * Handle down events that press down on the thumb.
         *
         * On the down action, determine a target box around the thumb to know when a scroll
         * gesture starts by clicking on the thumb. The target box will be used by subsequent
         * onScroll events.
         *
         * Returns true when the down event hits within the target box of the thumb.
         */
        @java.lang.Override()
        public boolean onDown(@org.jetbrains.annotations.NotNull()
        android.view.MotionEvent event) {
            return false;
        }
        
        /**
         * Always handle single tap up.
         *
         * This enables the user to single tap anywhere on the seek bar to seek to that position.
         */
        @java.lang.Override()
        public boolean onSingleTapUp(@org.jetbrains.annotations.NotNull()
        android.view.MotionEvent event) {
            return false;
        }
        
        /**
         * Handle scroll events when the down event is on the thumb.
         *
         * Returns true when the down event of the scroll hits within the target box of the thumb.
         */
        @java.lang.Override()
        public boolean onScroll(@org.jetbrains.annotations.NotNull()
        android.view.MotionEvent eventStart, @org.jetbrains.annotations.NotNull()
        android.view.MotionEvent event, float distanceX, float distanceY) {
            return false;
        }
        
        /**
         * Handle fling events when the down event is on the thumb.
         *
         * Gestures that include a fling are considered a false gesture on the seek bar.
         */
        @java.lang.Override()
        public boolean onFling(@org.jetbrains.annotations.NotNull()
        android.view.MotionEvent eventStart, @org.jetbrains.annotations.NotNull()
        android.view.MotionEvent event, float velocityX, float velocityY) {
            return false;
        }
        
        @java.lang.Override()
        public void onShowPress(@org.jetbrains.annotations.NotNull()
        android.view.MotionEvent event) {
        }
        
        @java.lang.Override()
        public void onLongPress(@org.jetbrains.annotations.NotNull()
        android.view.MotionEvent event) {
        }
        
        public SeekBarTouchListener(@org.jetbrains.annotations.NotNull()
        com.android.systemui.media.SeekBarViewModel viewModel, @org.jetbrains.annotations.NotNull()
        android.widget.SeekBar bar) {
            super();
        }
    }
    
    /**
     * State seen by seek bar UI.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001e\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0014\n\u0002\u0010\u000e\b\u0086\b\u0018\u00002\u00020\u0001B\'\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0003\u0012\b\u0010\u0005\u001a\u0004\u0018\u00010\u0006\u0012\u0006\u0010\u0007\u001a\u00020\u0006\u00a2\u0006\u0002\u0010\bJ\t\u0010\u0011\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u0012\u001a\u00020\u0003H\u00c6\u0003J\u0010\u0010\u0013\u001a\u0004\u0018\u00010\u0006H\u00c6\u0003\u00a2\u0006\u0002\u0010\fJ\t\u0010\u0014\u001a\u00020\u0006H\u00c6\u0003J8\u0010\u0015\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00032\n\b\u0002\u0010\u0005\u001a\u0004\u0018\u00010\u00062\b\b\u0002\u0010\u0007\u001a\u00020\u0006H\u00c6\u0001\u00a2\u0006\u0002\u0010\u0016J\u0013\u0010\u0017\u001a\u00020\u00032\b\u0010\u0018\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u0019\u001a\u00020\u0006H\u00d6\u0001J\t\u0010\u001a\u001a\u00020\u001bH\u00d6\u0001R\u0011\u0010\u0007\u001a\u00020\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\t\u0010\nR\u0015\u0010\u0005\u001a\u0004\u0018\u00010\u0006\u00a2\u0006\n\n\u0002\u0010\r\u001a\u0004\b\u000b\u0010\fR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000e\u0010\u000fR\u0011\u0010\u0004\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0010\u0010\u000f"}, d2 = {"Lcom/android/systemui/media/SeekBarViewModel$Progress;", "", "enabled", "", "seekAvailable", "elapsedTime", "", "duration", "(ZZLjava/lang/Integer;I)V", "getDuration", "()I", "getElapsedTime", "()Ljava/lang/Integer;", "Ljava/lang/Integer;", "getEnabled", "()Z", "getSeekAvailable", "component1", "component2", "component3", "component4", "copy", "(ZZLjava/lang/Integer;I)Lcom/android/systemui/media/SeekBarViewModel$Progress;", "equals", "other", "hashCode", "toString", ""})
    public static final class Progress {
        private final boolean enabled = false;
        private final boolean seekAvailable = false;
        @org.jetbrains.annotations.Nullable()
        private final java.lang.Integer elapsedTime = null;
        private final int duration = 0;
        
        public final boolean getEnabled() {
            return false;
        }
        
        public final boolean getSeekAvailable() {
            return false;
        }
        
        @org.jetbrains.annotations.Nullable()
        public final java.lang.Integer getElapsedTime() {
            return null;
        }
        
        public final int getDuration() {
            return 0;
        }
        
        public Progress(boolean enabled, boolean seekAvailable, @org.jetbrains.annotations.Nullable()
        java.lang.Integer elapsedTime, int duration) {
            super();
        }
        
        public final boolean component1() {
            return false;
        }
        
        public final boolean component2() {
            return false;
        }
        
        @org.jetbrains.annotations.Nullable()
        public final java.lang.Integer component3() {
            return null;
        }
        
        public final int component4() {
            return 0;
        }
        
        /**
         * State seen by seek bar UI.
         */
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.media.SeekBarViewModel.Progress copy(boolean enabled, boolean seekAvailable, @org.jetbrains.annotations.Nullable()
        java.lang.Integer elapsedTime, int duration) {
            return null;
        }
        
        /**
         * State seen by seek bar UI.
         */
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.lang.String toString() {
            return null;
        }
        
        /**
         * State seen by seek bar UI.
         */
        @java.lang.Override()
        public int hashCode() {
            return 0;
        }
        
        /**
         * State seen by seek bar UI.
         */
        @java.lang.Override()
        public boolean equals(@org.jetbrains.annotations.Nullable()
        java.lang.Object p0) {
            return false;
        }
    }
}