package com.android.systemui.media;

import javax.inject.Inject;

/**
 * Combines [MediaDataManager.Listener] events with [MediaDeviceManager.Listener] events.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000L\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010%\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010#\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\u0006\n\u0002\u0010\b\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0005\u0018\u00002\u00020\u00012\u00020\u0002B\u0007\b\u0007\u00a2\u0006\u0002\u0010\u0003J\u000e\u0010\f\u001a\u00020\r2\u0006\u0010\u000e\u001a\u00020\u0001J\u0010\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\u0006H\u0016J:\u0010\u0012\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\u00062\b\u0010\u0013\u001a\u0004\u0018\u00010\u00062\u0006\u0010\u0014\u001a\u00020\b2\u0006\u0010\u0015\u001a\u00020\r2\u0006\u0010\u0016\u001a\u00020\u00172\u0006\u0010\u0018\u001a\u00020\rH\u0016J\u0010\u0010\u0019\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\u0006H\u0016J$\u0010\u001a\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\u00062\b\u0010\u0013\u001a\u0004\u0018\u00010\u00062\b\u0010\u0014\u001a\u0004\u0018\u00010\tH\u0016J \u0010\u001b\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\u00062\u0006\u0010\u0014\u001a\u00020\u001c2\u0006\u0010\u001d\u001a\u00020\rH\u0016J\u0018\u0010\u001e\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\u00062\u0006\u0010\u0015\u001a\u00020\rH\u0016J\u0010\u0010\u001f\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\u0006H\u0002J\u000e\u0010 \u001a\u00020\r2\u0006\u0010\u000e\u001a\u00020\u0001J\u001a\u0010!\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\u00062\b\u0010\u0013\u001a\u0004\u0018\u00010\u0006H\u0002R*\u0010\u0004\u001a\u001e\u0012\u0004\u0012\u00020\u0006\u0012\u0014\u0012\u0012\u0012\u0006\u0012\u0004\u0018\u00010\b\u0012\u0006\u0012\u0004\u0018\u00010\t0\u00070\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\n\u001a\b\u0012\u0004\u0012\u00020\u00010\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/media/MediaDataCombineLatest;", "Lcom/android/systemui/media/MediaDataManager$Listener;", "Lcom/android/systemui/media/MediaDeviceManager$Listener;", "()V", "entries", "", "", "Lkotlin/Pair;", "Lcom/android/systemui/media/MediaData;", "Lcom/android/systemui/media/MediaDeviceData;", "listeners", "", "addListener", "", "listener", "onKeyRemoved", "", "key", "onMediaDataLoaded", "oldKey", "data", "immediately", "receivedSmartspaceCardLatency", "", "isSsReactivated", "onMediaDataRemoved", "onMediaDeviceChanged", "onSmartspaceMediaDataLoaded", "Lcom/android/systemui/media/SmartspaceMediaData;", "shouldPrioritize", "onSmartspaceMediaDataRemoved", "remove", "removeListener", "update"})
public final class MediaDataCombineLatest implements com.android.systemui.media.MediaDataManager.Listener, com.android.systemui.media.MediaDeviceManager.Listener {
    private final java.util.Set<com.android.systemui.media.MediaDataManager.Listener> listeners = null;
    private final java.util.Map<java.lang.String, kotlin.Pair<com.android.systemui.media.MediaData, com.android.systemui.media.MediaDeviceData>> entries = null;
    
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
    
    @java.lang.Override()
    public void onMediaDeviceChanged(@org.jetbrains.annotations.NotNull()
    java.lang.String key, @org.jetbrains.annotations.Nullable()
    java.lang.String oldKey, @org.jetbrains.annotations.Nullable()
    com.android.systemui.media.MediaDeviceData data) {
    }
    
    @java.lang.Override()
    public void onKeyRemoved(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
    }
    
    /**
     * Add a listener for [MediaData] changes that has been combined with latest [MediaDeviceData].
     */
    public final boolean addListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaDataManager.Listener listener) {
        return false;
    }
    
    /**
     * Remove a listener registered with addListener.
     */
    public final boolean removeListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaDataManager.Listener listener) {
        return false;
    }
    
    private final void update(java.lang.String key, java.lang.String oldKey) {
    }
    
    private final void remove(java.lang.String key) {
    }
    
    @javax.inject.Inject()
    public MediaDataCombineLatest() {
        super();
    }
}