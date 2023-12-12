package com.android.systemui.media;

import android.content.ComponentName;
import android.content.Context;
import android.media.session.MediaController;
import android.media.session.MediaController.PlaybackInfo;
import android.media.session.MediaSession;
import android.media.session.MediaSessionManager;
import android.util.Log;
import com.android.systemui.dagger.qualifiers.Background;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.statusbar.phone.NotificationListenerWithPlugins;
import java.util.concurrent.Executor;
import javax.inject.Inject;

/**
 * Filters media loaded events for local media sessions while an app is casting.
 *
 * When an app is casting there can be one remote media sessions and potentially more local media
 * sessions. In this situation, there should only be a media object for the remote session. To
 * achieve this, update events for the local session need to be filtered.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000|\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010%\n\u0002\u0010\u000e\n\u0002\u0010#\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0010!\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010 \n\u0002\b\u0003\n\u0002\u0010\b\n\u0002\b\u0006\u0018\u00002\u00020\u0001B+\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\b\b\u0001\u0010\u0006\u001a\u00020\u0007\u0012\b\b\u0001\u0010\b\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\tJ\u000e\u0010\u0018\u001a\u00020\u00192\u0006\u0010\u001a\u001a\u00020\u0001J*\u0010\u001b\u001a\u00020\u001c2\u0006\u0010\u001d\u001a\u00020\f2\b\u0010\u001e\u001a\u0004\u0018\u00010\f2\u0006\u0010\u001f\u001a\u00020 2\u0006\u0010!\u001a\u00020\u0019H\u0002J\u0010\u0010\"\u001a\u00020\u001c2\u0006\u0010\u001d\u001a\u00020\fH\u0002J\u0018\u0010#\u001a\u00020\u001c2\u0006\u0010\u001d\u001a\u00020\f2\u0006\u0010\u001f\u001a\u00020$H\u0002J\u0018\u0010%\u001a\u00020\u001c2\u0006\u0010\u001d\u001a\u00020\f2\u0006\u0010!\u001a\u00020\u0019H\u0002J\u0016\u0010&\u001a\u00020\u001c2\f\u0010\'\u001a\b\u0012\u0004\u0012\u00020\u00130(H\u0002J:\u0010)\u001a\u00020\u001c2\u0006\u0010\u001d\u001a\u00020\f2\b\u0010\u001e\u001a\u0004\u0018\u00010\f2\u0006\u0010*\u001a\u00020 2\u0006\u0010!\u001a\u00020\u00192\u0006\u0010+\u001a\u00020,2\u0006\u0010-\u001a\u00020\u0019H\u0016J\u0010\u0010.\u001a\u00020\u001c2\u0006\u0010\u001d\u001a\u00020\fH\u0016J \u0010/\u001a\u00020\u001c2\u0006\u0010\u001d\u001a\u00020\f2\u0006\u0010*\u001a\u00020$2\u0006\u00100\u001a\u00020\u0019H\u0016J\u0018\u00101\u001a\u00020\u001c2\u0006\u0010\u001d\u001a\u00020\f2\u0006\u0010!\u001a\u00020\u0019H\u0016J\u000e\u00102\u001a\u00020\u00192\u0006\u0010\u001a\u001a\u00020\u0001R\u000e\u0010\b\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R \u0010\n\u001a\u0014\u0012\u0004\u0012\u00020\f\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u000e0\r0\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u000f\u001a\b\u0012\u0004\u0012\u00020\u00010\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R6\u0010\u0010\u001a*\u0012\u0004\u0012\u00020\f\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00130\u00120\u0011j\u0014\u0012\u0004\u0012\u00020\f\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00130\u0012`\u0014X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0015\u001a\u00020\u0016X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0017\u001a\b\u0012\u0004\u0012\u00020\u000e0\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/media/MediaSessionBasedFilter;", "Lcom/android/systemui/media/MediaDataManager$Listener;", "context", "Landroid/content/Context;", "sessionManager", "Landroid/media/session/MediaSessionManager;", "foregroundExecutor", "Ljava/util/concurrent/Executor;", "backgroundExecutor", "(Landroid/content/Context;Landroid/media/session/MediaSessionManager;Ljava/util/concurrent/Executor;Ljava/util/concurrent/Executor;)V", "keyedTokens", "", "", "", "Landroid/media/session/MediaSession$Token;", "listeners", "packageControllers", "Ljava/util/LinkedHashMap;", "", "Landroid/media/session/MediaController;", "Lkotlin/collections/LinkedHashMap;", "sessionListener", "Landroid/media/session/MediaSessionManager$OnActiveSessionsChangedListener;", "tokensWithNotifications", "addListener", "", "listener", "dispatchMediaDataLoaded", "", "key", "oldKey", "info", "Lcom/android/systemui/media/MediaData;", "immediately", "dispatchMediaDataRemoved", "dispatchSmartspaceMediaDataLoaded", "Lcom/android/systemui/media/SmartspaceMediaData;", "dispatchSmartspaceMediaDataRemoved", "handleControllersChanged", "controllers", "", "onMediaDataLoaded", "data", "receivedSmartspaceCardLatency", "", "isSsReactivated", "onMediaDataRemoved", "onSmartspaceMediaDataLoaded", "shouldPrioritize", "onSmartspaceMediaDataRemoved", "removeListener"})
public final class MediaSessionBasedFilter implements com.android.systemui.media.MediaDataManager.Listener {
    private final java.util.Set<com.android.systemui.media.MediaDataManager.Listener> listeners = null;
    private final java.util.LinkedHashMap<java.lang.String, java.util.List<android.media.session.MediaController>> packageControllers = null;
    private final java.util.Map<java.lang.String, java.util.Set<android.media.session.MediaSession.Token>> keyedTokens = null;
    private final java.util.Set<android.media.session.MediaSession.Token> tokensWithNotifications = null;
    private final android.media.session.MediaSessionManager.OnActiveSessionsChangedListener sessionListener = null;
    private final android.media.session.MediaSessionManager sessionManager = null;
    private final java.util.concurrent.Executor foregroundExecutor = null;
    private final java.util.concurrent.Executor backgroundExecutor = null;
    
    /**
     * Add a listener for filtered [MediaData] changes
     */
    public final boolean addListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaDataManager.Listener listener) {
        return false;
    }
    
    /**
     * Remove a listener that was registered with addListener
     */
    public final boolean removeListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaDataManager.Listener listener) {
        return false;
    }
    
    /**
     * May filter loaded events by not passing them along to listeners.
     *
     * If an app has only one session with playback type PLAYBACK_TYPE_REMOTE, then assuming that
     * the app is casting. Sometimes apps will send redundant updates to a local session with
     * playback type PLAYBACK_TYPE_LOCAL. These updates should be filtered to improve the usability
     * of the media controls.
     */
    @java.lang.Override()
    public void onMediaDataLoaded(@org.jetbrains.annotations.NotNull()
    java.lang.String key, @org.jetbrains.annotations.Nullable()
    java.lang.String oldKey, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaData data, boolean immediately, int receivedSmartspaceCardLatency, boolean isSsReactivated) {
    }
    
    @java.lang.Override()
    public void onSmartspaceMediaDataLoaded(@org.jetbrains.annotations.NotNull()
    java.lang.String key, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.SmartspaceMediaData data, boolean shouldPrioritize) {
    }
    
    @java.lang.Override()
    public void onMediaDataRemoved(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
    }
    
    @java.lang.Override()
    public void onSmartspaceMediaDataRemoved(@org.jetbrains.annotations.NotNull()
    java.lang.String key, boolean immediately) {
    }
    
    private final void dispatchMediaDataLoaded(java.lang.String key, java.lang.String oldKey, com.android.systemui.media.MediaData info, boolean immediately) {
    }
    
    private final void dispatchMediaDataRemoved(java.lang.String key) {
    }
    
    private final void dispatchSmartspaceMediaDataLoaded(java.lang.String key, com.android.systemui.media.SmartspaceMediaData info) {
    }
    
    private final void dispatchSmartspaceMediaDataRemoved(java.lang.String key, boolean immediately) {
    }
    
    private final void handleControllersChanged(java.util.List<android.media.session.MediaController> controllers) {
    }
    
    @javax.inject.Inject()
    public MediaSessionBasedFilter(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    android.media.session.MediaSessionManager sessionManager, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    java.util.concurrent.Executor foregroundExecutor, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Background()
    java.util.concurrent.Executor backgroundExecutor) {
        super();
    }
}