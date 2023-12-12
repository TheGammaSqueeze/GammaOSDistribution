package com.android.systemui.media;

import android.content.Context;
import android.os.SystemProperties;
import android.util.Log;
import com.android.internal.annotations.VisibleForTesting;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.settings.CurrentUserTracker;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.util.time.SystemClock;
import java.util.SortedMap;
import java.util.concurrent.Executor;
import java.util.concurrent.TimeUnit;
import javax.inject.Inject;
import kotlin.collections.LinkedHashMap;

/**
 * Filters data updates from [MediaDataCombineLatest] based on the current user ID, and handles user
 * switches (removing entries for the previous user, adding back entries for the current user). Also
 * filters out smartspace updates in favor of local recent media, when avaialble.
 *
 * This is added at the end of the pipeline since we may still need to handle callbacks from
 * background users (e.g. timeouts).
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0080\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010#\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\"\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0013\n\u0002\u0010\t\n\u0000\n\u0002\u0018\u0002\u0018\u00002\u00020\u0001B1\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\b\b\u0001\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u00a2\u0006\u0002\u0010\fJ\u000e\u0010$\u001a\u00020%2\u0006\u0010&\u001a\u00020\u0001J\u0015\u0010\'\u001a\u00020(2\u0006\u0010)\u001a\u00020*H\u0001\u00a2\u0006\u0002\b+J\u0006\u0010,\u001a\u00020%J\u0006\u0010-\u001a\u00020%J\u0006\u0010.\u001a\u00020%J\u0006\u0010/\u001a\u00020%J:\u00100\u001a\u00020(2\u0006\u00101\u001a\u00020\u00112\b\u00102\u001a\u0004\u0018\u00010\u00112\u0006\u00103\u001a\u00020\u00122\u0006\u00104\u001a\u00020%2\u0006\u00105\u001a\u00020*2\u0006\u00106\u001a\u00020%H\u0016J\u0010\u00107\u001a\u00020(2\u0006\u00101\u001a\u00020\u0011H\u0016J \u00108\u001a\u00020(2\u0006\u00101\u001a\u00020\u00112\u0006\u00103\u001a\u00020 2\u0006\u00109\u001a\u00020%H\u0016J\u0018\u0010:\u001a\u00020(2\u0006\u00101\u001a\u00020\u00112\u0006\u00104\u001a\u00020%H\u0016J\u0006\u0010;\u001a\u00020(J\u000e\u0010<\u001a\u00020%2\u0006\u0010&\u001a\u00020\u0001J\u001c\u0010=\u001a\u00020>2\u0012\u0010?\u001a\u000e\u0012\u0004\u0012\u00020\u0011\u0012\u0004\u0012\u00020\u00120@H\u0002R\u0014\u0010\r\u001a\b\u0012\u0004\u0012\u00020\u00010\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R*\u0010\u000f\u001a\u001e\u0012\u0004\u0012\u00020\u0011\u0012\u0004\u0012\u00020\u00120\u0010j\u000e\u0012\u0004\u0012\u00020\u0011\u0012\u0004\u0012\u00020\u0012`\u0013X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u0014\u001a\b\u0012\u0004\u0012\u00020\u00010\u00158@X\u0080\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0016\u0010\u0017R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u0018\u001a\u00020\u0019X\u0080.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001a\u0010\u001b\"\u0004\b\u001c\u0010\u001dR\u0010\u0010\u001e\u001a\u0004\u0018\u00010\u0011X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001f\u001a\u00020 X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R*\u0010!\u001a\u001e\u0012\u0004\u0012\u00020\u0011\u0012\u0004\u0012\u00020\u00120\u0010j\u000e\u0012\u0004\u0012\u00020\u0011\u0012\u0004\u0012\u00020\u0012`\u0013X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\"\u001a\u00020#X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/media/MediaDataFilter;", "Lcom/android/systemui/media/MediaDataManager$Listener;", "context", "Landroid/content/Context;", "broadcastDispatcher", "Lcom/android/systemui/broadcast/BroadcastDispatcher;", "lockscreenUserManager", "Lcom/android/systemui/statusbar/NotificationLockscreenUserManager;", "executor", "Ljava/util/concurrent/Executor;", "systemClock", "Lcom/android/systemui/util/time/SystemClock;", "(Landroid/content/Context;Lcom/android/systemui/broadcast/BroadcastDispatcher;Lcom/android/systemui/statusbar/NotificationLockscreenUserManager;Ljava/util/concurrent/Executor;Lcom/android/systemui/util/time/SystemClock;)V", "_listeners", "", "allEntries", "Ljava/util/LinkedHashMap;", "", "Lcom/android/systemui/media/MediaData;", "Lkotlin/collections/LinkedHashMap;", "listeners", "", "getListeners$main", "()Ljava/util/Set;", "mediaDataManager", "Lcom/android/systemui/media/MediaDataManager;", "getMediaDataManager$main", "()Lcom/android/systemui/media/MediaDataManager;", "setMediaDataManager$main", "(Lcom/android/systemui/media/MediaDataManager;)V", "reactivatedKey", "smartspaceMediaData", "Lcom/android/systemui/media/SmartspaceMediaData;", "userEntries", "userTracker", "Lcom/android/systemui/settings/CurrentUserTracker;", "addListener", "", "listener", "handleUserSwitched", "", "id", "", "handleUserSwitched$main", "hasActiveMedia", "hasActiveMediaOrRecommendation", "hasAnyMedia", "hasAnyMediaOrRecommendation", "onMediaDataLoaded", "key", "oldKey", "data", "immediately", "receivedSmartspaceCardLatency", "isSsReactivated", "onMediaDataRemoved", "onSmartspaceMediaDataLoaded", "shouldPrioritize", "onSmartspaceMediaDataRemoved", "onSwipeToDismiss", "removeListener", "timeSinceActiveForMostRecentMedia", "", "sortedEntries", "Ljava/util/SortedMap;"})
public final class MediaDataFilter implements com.android.systemui.media.MediaDataManager.Listener {
    private final com.android.systemui.settings.CurrentUserTracker userTracker = null;
    private final java.util.Set<com.android.systemui.media.MediaDataManager.Listener> _listeners = null;
    public com.android.systemui.media.MediaDataManager mediaDataManager;
    private final java.util.LinkedHashMap<java.lang.String, com.android.systemui.media.MediaData> allEntries = null;
    private final java.util.LinkedHashMap<java.lang.String, com.android.systemui.media.MediaData> userEntries = null;
    private com.android.systemui.media.SmartspaceMediaData smartspaceMediaData;
    private java.lang.String reactivatedKey;
    private final android.content.Context context = null;
    private final com.android.systemui.broadcast.BroadcastDispatcher broadcastDispatcher = null;
    private final com.android.systemui.statusbar.NotificationLockscreenUserManager lockscreenUserManager = null;
    private final java.util.concurrent.Executor executor = null;
    private final com.android.systemui.util.time.SystemClock systemClock = null;
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.Set<com.android.systemui.media.MediaDataManager.Listener> getListeners$main() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.media.MediaDataManager getMediaDataManager$main() {
        return null;
    }
    
    public final void setMediaDataManager$main(@org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaDataManager p0) {
    }
    
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
    
    @com.android.internal.annotations.VisibleForTesting()
    public final void handleUserSwitched$main(int id) {
    }
    
    /**
     * Invoked when the user has dismissed the media carousel
     */
    public final void onSwipeToDismiss() {
    }
    
    /**
     * Are there any media notifications active, including the recommendation?
     */
    public final boolean hasActiveMediaOrRecommendation() {
        return false;
    }
    
    /**
     * Are there any media entries we should display?
     */
    public final boolean hasAnyMediaOrRecommendation() {
        return false;
    }
    
    /**
     * Are there any media notifications active (excluding the recommendation)?
     */
    public final boolean hasActiveMedia() {
        return false;
    }
    
    /**
     * Are there any media entries we should display (excluding the recommendation)?
     */
    public final boolean hasAnyMedia() {
        return false;
    }
    
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
     * Return the time since last active for the most-recent media.
     *
     * @param sortedEntries userEntries sorted from the earliest to the most-recent.
     *
     * @return The duration in milliseconds from the most-recent media's last active timestamp to
     * the present. MAX_VALUE will be returned if there is no media.
     */
    private final long timeSinceActiveForMostRecentMedia(java.util.SortedMap<java.lang.String, com.android.systemui.media.MediaData> sortedEntries) {
        return 0L;
    }
    
    @javax.inject.Inject()
    public MediaDataFilter(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.broadcast.BroadcastDispatcher broadcastDispatcher, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationLockscreenUserManager lockscreenUserManager, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    java.util.concurrent.Executor executor, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.time.SystemClock systemClock) {
        super();
    }
}