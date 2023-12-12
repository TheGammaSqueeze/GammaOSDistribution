package com.android.systemui.media;

import android.media.session.MediaController;
import android.media.session.PlaybackState;
import android.os.SystemProperties;
import android.util.Log;
import com.android.internal.annotations.VisibleForTesting;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.util.concurrency.DelayableExecutor;
import java.util.concurrent.TimeUnit;
import javax.inject.Inject;

/**
 * Controller responsible for keeping track of playback states and expiring inactive streams.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000F\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010%\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u000b\n\u0002\u0010\u0002\n\u0002\b\t\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0003\b\u0007\u0018\u00002\u00020\u0001:\u0001\u001eB\u0019\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\b\b\u0001\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u000e\u0010\u0013\u001a\u00020\r2\u0006\u0010\u0014\u001a\u00020\tJ:\u0010\u0015\u001a\u00020\u000e2\u0006\u0010\u0014\u001a\u00020\t2\b\u0010\u0016\u001a\u0004\u0018\u00010\t2\u0006\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\r2\u0006\u0010\u001a\u001a\u00020\u001b2\u0006\u0010\u001c\u001a\u00020\rH\u0016J\u0010\u0010\u001d\u001a\u00020\u000e2\u0006\u0010\u0014\u001a\u00020\tH\u0016R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001e\u0010\u0007\u001a\u0012\u0012\u0004\u0012\u00020\t\u0012\b\u0012\u00060\nR\u00020\u00000\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R,\u0010\u000b\u001a\u0014\u0012\u0004\u0012\u00020\t\u0012\u0004\u0012\u00020\r\u0012\u0004\u0012\u00020\u000e0\fX\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000f\u0010\u0010\"\u0004\b\u0011\u0010\u0012"}, d2 = {"Lcom/android/systemui/media/MediaTimeoutListener;", "Lcom/android/systemui/media/MediaDataManager$Listener;", "mediaControllerFactory", "Lcom/android/systemui/media/MediaControllerFactory;", "mainExecutor", "Lcom/android/systemui/util/concurrency/DelayableExecutor;", "(Lcom/android/systemui/media/MediaControllerFactory;Lcom/android/systemui/util/concurrency/DelayableExecutor;)V", "mediaListeners", "", "", "Lcom/android/systemui/media/MediaTimeoutListener$PlaybackStateListener;", "timeoutCallback", "Lkotlin/Function2;", "", "", "getTimeoutCallback", "()Lkotlin/jvm/functions/Function2;", "setTimeoutCallback", "(Lkotlin/jvm/functions/Function2;)V", "isTimedOut", "key", "onMediaDataLoaded", "oldKey", "data", "Lcom/android/systemui/media/MediaData;", "immediately", "receivedSmartspaceCardLatency", "", "isSsReactivated", "onMediaDataRemoved", "PlaybackStateListener"})
@com.android.systemui.dagger.SysUISingleton()
public final class MediaTimeoutListener implements com.android.systemui.media.MediaDataManager.Listener {
    private final java.util.Map<java.lang.String, com.android.systemui.media.MediaTimeoutListener.PlaybackStateListener> mediaListeners = null;
    
    /**
     * Callback representing that a media object is now expired:
     * @param key Media control unique identifier
     * @param timedOut True when expired for {@code PAUSED_MEDIA_TIMEOUT} for active media,
     *                or {@code RESUME_MEDIA_TIMEOUT} for resume media
     */
    public kotlin.jvm.functions.Function2<? super java.lang.String, ? super java.lang.Boolean, kotlin.Unit> timeoutCallback;
    private final com.android.systemui.media.MediaControllerFactory mediaControllerFactory = null;
    private final com.android.systemui.util.concurrency.DelayableExecutor mainExecutor = null;
    
    @org.jetbrains.annotations.NotNull()
    public final kotlin.jvm.functions.Function2<java.lang.String, java.lang.Boolean, kotlin.Unit> getTimeoutCallback() {
        return null;
    }
    
    public final void setTimeoutCallback(@org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function2<? super java.lang.String, ? super java.lang.Boolean, kotlin.Unit> p0) {
    }
    
    @java.lang.Override()
    public void onMediaDataLoaded(@org.jetbrains.annotations.NotNull()
    java.lang.String key, @org.jetbrains.annotations.Nullable()
    java.lang.String oldKey, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaData data, boolean immediately, int receivedSmartspaceCardLatency, boolean isSsReactivated) {
    }
    
    @java.lang.Override()
    public void onMediaDataRemoved(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
    }
    
    public final boolean isTimedOut(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
        return false;
    }
    
    @javax.inject.Inject()
    public MediaTimeoutListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaControllerFactory mediaControllerFactory, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    com.android.systemui.util.concurrency.DelayableExecutor mainExecutor) {
        super();
    }
    
    /**
     * Called whenever there's new Smartspace media data loaded.
     *
     * @param shouldPrioritize indicates the sorting priority of the Smartspace card. If true,
     * it will be prioritized as the first card. Otherwise, it will show up as the last card as
     * default.
     */
    public void onSmartspaceMediaDataLoaded(@org.jetbrains.annotations.NotNull()
    java.lang.String key, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.SmartspaceMediaData data, boolean shouldPrioritize) {
    }
    
    /**
     * Called whenever a previously existing Smartspace media data was removed.
     *
     * @param immediately indicates should apply the UI changes immediately, otherwise wait
     * until the next refresh-round before UI becomes visible. True by default to take in place
     * immediately.
     */
    public void onSmartspaceMediaDataRemoved(@org.jetbrains.annotations.NotNull()
    java.lang.String key, boolean immediately) {
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000>\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\t\n\u0002\u0018\u0002\n\u0002\b\u0013\n\u0002\u0010\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0003\b\u0082\u0004\u0018\u00002\u00020\u0001B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u0006\u0010\'\u001a\u00020(J\u0018\u0010)\u001a\u00020(2\u0006\u0010*\u001a\u00020\u00032\u0006\u0010+\u001a\u00020\u0003H\u0002J\u0012\u0010,\u001a\u00020(2\b\u0010-\u001a\u0004\u0018\u00010.H\u0016J\b\u0010/\u001a\u00020(H\u0016J\u001a\u00100\u001a\u00020(2\b\u0010-\u001a\u0004\u0018\u00010.2\u0006\u00101\u001a\u00020\nH\u0002R\u0010\u0010\u0007\u001a\u0004\u0018\u00010\bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001a\u0010\t\u001a\u00020\nX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000b\u0010\f\"\u0004\b\r\u0010\u000eR\u001a\u0010\u0002\u001a\u00020\u0003X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000f\u0010\u0010\"\u0004\b\u0011\u0010\u0012R\u0010\u0010\u0013\u001a\u0004\u0018\u00010\u0014X\u0082\u000e\u00a2\u0006\u0002\n\u0000R$\u0010\u0016\u001a\u00020\u00052\u0006\u0010\u0015\u001a\u00020\u0005@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0017\u0010\u0018\"\u0004\b\u0019\u0010\u001aR\u001e\u0010\u001b\u001a\u0004\u0018\u00010\nX\u0086\u000e\u00a2\u0006\u0010\n\u0002\u0010 \u001a\u0004\b\u001c\u0010\u001d\"\u0004\b\u001e\u0010\u001fR\u001e\u0010!\u001a\u0004\u0018\u00010\nX\u0086\u000e\u00a2\u0006\u0010\n\u0002\u0010 \u001a\u0004\b\"\u0010\u001d\"\u0004\b#\u0010\u001fR\u001a\u0010$\u001a\u00020\nX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b%\u0010\f\"\u0004\b&\u0010\u000e"}, d2 = {"Lcom/android/systemui/media/MediaTimeoutListener$PlaybackStateListener;", "Landroid/media/session/MediaController$Callback;", "key", "", "data", "Lcom/android/systemui/media/MediaData;", "(Lcom/android/systemui/media/MediaTimeoutListener;Ljava/lang/String;Lcom/android/systemui/media/MediaData;)V", "cancellation", "Ljava/lang/Runnable;", "destroyed", "", "getDestroyed", "()Z", "setDestroyed", "(Z)V", "getKey", "()Ljava/lang/String;", "setKey", "(Ljava/lang/String;)V", "mediaController", "Landroid/media/session/MediaController;", "value", "mediaData", "getMediaData", "()Lcom/android/systemui/media/MediaData;", "setMediaData", "(Lcom/android/systemui/media/MediaData;)V", "playing", "getPlaying", "()Ljava/lang/Boolean;", "setPlaying", "(Ljava/lang/Boolean;)V", "Ljava/lang/Boolean;", "resumption", "getResumption", "setResumption", "timedOut", "getTimedOut", "setTimedOut", "destroy", "", "expireMediaTimeout", "mediaKey", "reason", "onPlaybackStateChanged", "state", "Landroid/media/session/PlaybackState;", "onSessionDestroyed", "processState", "dispatchEvents"})
    final class PlaybackStateListener extends android.media.session.MediaController.Callback {
        private boolean timedOut = false;
        @org.jetbrains.annotations.Nullable()
        private java.lang.Boolean playing;
        @org.jetbrains.annotations.Nullable()
        private java.lang.Boolean resumption;
        private boolean destroyed = false;
        @org.jetbrains.annotations.NotNull()
        private com.android.systemui.media.MediaData mediaData;
        private android.media.session.MediaController mediaController;
        private java.lang.Runnable cancellation;
        @org.jetbrains.annotations.NotNull()
        private java.lang.String key;
        
        public final boolean getTimedOut() {
            return false;
        }
        
        public final void setTimedOut(boolean p0) {
        }
        
        @org.jetbrains.annotations.Nullable()
        public final java.lang.Boolean getPlaying() {
            return null;
        }
        
        public final void setPlaying(@org.jetbrains.annotations.Nullable()
        java.lang.Boolean p0) {
        }
        
        @org.jetbrains.annotations.Nullable()
        public final java.lang.Boolean getResumption() {
            return null;
        }
        
        public final void setResumption(@org.jetbrains.annotations.Nullable()
        java.lang.Boolean p0) {
        }
        
        public final boolean getDestroyed() {
            return false;
        }
        
        public final void setDestroyed(boolean p0) {
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.media.MediaData getMediaData() {
            return null;
        }
        
        public final void setMediaData(@org.jetbrains.annotations.NotNull()
        com.android.systemui.media.MediaData value) {
        }
        
        public final void destroy() {
        }
        
        @java.lang.Override()
        public void onPlaybackStateChanged(@org.jetbrains.annotations.Nullable()
        android.media.session.PlaybackState state) {
        }
        
        @java.lang.Override()
        public void onSessionDestroyed() {
        }
        
        private final void processState(android.media.session.PlaybackState state, boolean dispatchEvents) {
        }
        
        private final void expireMediaTimeout(java.lang.String mediaKey, java.lang.String reason) {
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String getKey() {
            return null;
        }
        
        public final void setKey(@org.jetbrains.annotations.NotNull()
        java.lang.String p0) {
        }
        
        public PlaybackStateListener(@org.jetbrains.annotations.NotNull()
        java.lang.String key, @org.jetbrains.annotations.NotNull()
        com.android.systemui.media.MediaData data) {
            super();
        }
    }
}