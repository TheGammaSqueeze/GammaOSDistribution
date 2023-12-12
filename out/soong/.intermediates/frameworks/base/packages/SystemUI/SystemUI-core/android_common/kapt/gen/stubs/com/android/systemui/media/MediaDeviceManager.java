package com.android.systemui.media;

import android.media.MediaRouter2Manager;
import android.media.session.MediaController;
import androidx.annotation.AnyThread;
import androidx.annotation.MainThread;
import androidx.annotation.WorkerThread;
import com.android.settingslib.media.LocalMediaManager;
import com.android.settingslib.media.MediaDevice;
import com.android.systemui.Dumpable;
import com.android.systemui.dagger.qualifiers.Background;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.dump.DumpManager;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import java.util.concurrent.Executor;
import javax.inject.Inject;

/**
 * Provides information about the route (ie. device) where playback is occurring.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0082\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010%\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010#\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0003\u0018\u00002\u00020\u00012\u00020\u0002:\u000201B;\b\u0007\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\b\b\u0001\u0010\t\u001a\u00020\n\u0012\b\b\u0001\u0010\u000b\u001a\u00020\n\u0012\u0006\u0010\f\u001a\u00020\r\u00a2\u0006\u0002\u0010\u000eJ\u000e\u0010\u0016\u001a\u00020\u00172\u0006\u0010\u0018\u001a\u00020\u0015J+\u0010\u0019\u001a\u00020\u001a2\u0006\u0010\u001b\u001a\u00020\u001c2\u0006\u0010\u001d\u001a\u00020\u001e2\f\u0010\u001f\u001a\b\u0012\u0004\u0012\u00020\u00110 H\u0016\u00a2\u0006\u0002\u0010!J:\u0010\"\u001a\u00020\u001a2\u0006\u0010#\u001a\u00020\u00112\b\u0010$\u001a\u0004\u0018\u00010\u00112\u0006\u0010%\u001a\u00020&2\u0006\u0010\'\u001a\u00020\u00172\u0006\u0010(\u001a\u00020)2\u0006\u0010*\u001a\u00020\u0017H\u0016J\u0010\u0010+\u001a\u00020\u001a2\u0006\u0010#\u001a\u00020\u0011H\u0016J$\u0010,\u001a\u00020\u001a2\u0006\u0010#\u001a\u00020\u00112\b\u0010$\u001a\u0004\u0018\u00010\u00112\b\u0010-\u001a\u0004\u0018\u00010.H\u0003J\u000e\u0010/\u001a\u00020\u00172\u0006\u0010\u0018\u001a\u00020\u0015R\u000e\u0010\u000b\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001e\u0010\u000f\u001a\u0012\u0012\u0004\u0012\u00020\u0011\u0012\b\u0012\u00060\u0012R\u00020\u00000\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0013\u001a\b\u0012\u0004\u0012\u00020\u00150\u0014X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/media/MediaDeviceManager;", "Lcom/android/systemui/media/MediaDataManager$Listener;", "Lcom/android/systemui/Dumpable;", "controllerFactory", "Lcom/android/systemui/media/MediaControllerFactory;", "localMediaManagerFactory", "Lcom/android/systemui/media/LocalMediaManagerFactory;", "mr2manager", "Landroid/media/MediaRouter2Manager;", "fgExecutor", "Ljava/util/concurrent/Executor;", "bgExecutor", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "(Lcom/android/systemui/media/MediaControllerFactory;Lcom/android/systemui/media/LocalMediaManagerFactory;Landroid/media/MediaRouter2Manager;Ljava/util/concurrent/Executor;Ljava/util/concurrent/Executor;Lcom/android/systemui/dump/DumpManager;)V", "entries", "", "", "Lcom/android/systemui/media/MediaDeviceManager$Entry;", "listeners", "", "Lcom/android/systemui/media/MediaDeviceManager$Listener;", "addListener", "", "listener", "dump", "", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "onMediaDataLoaded", "key", "oldKey", "data", "Lcom/android/systemui/media/MediaData;", "immediately", "receivedSmartspaceCardLatency", "", "isSsReactivated", "onMediaDataRemoved", "processDevice", "device", "Lcom/android/systemui/media/MediaDeviceData;", "removeListener", "Entry", "Listener"})
public final class MediaDeviceManager implements com.android.systemui.media.MediaDataManager.Listener, com.android.systemui.Dumpable {
    private final java.util.Set<com.android.systemui.media.MediaDeviceManager.Listener> listeners = null;
    private final java.util.Map<java.lang.String, com.android.systemui.media.MediaDeviceManager.Entry> entries = null;
    private final com.android.systemui.media.MediaControllerFactory controllerFactory = null;
    private final com.android.systemui.media.LocalMediaManagerFactory localMediaManagerFactory = null;
    private final android.media.MediaRouter2Manager mr2manager = null;
    private final java.util.concurrent.Executor fgExecutor = null;
    private final java.util.concurrent.Executor bgExecutor = null;
    
    /**
     * Add a listener for changes to the media route (ie. device).
     */
    public final boolean addListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaDeviceManager.Listener listener) {
        return false;
    }
    
    /**
     * Remove a listener that has been registered with addListener.
     */
    public final boolean removeListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaDeviceManager.Listener listener) {
        return false;
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
    
    @java.lang.Override()
    public void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    @androidx.annotation.MainThread()
    private final void processDevice(java.lang.String key, java.lang.String oldKey, com.android.systemui.media.MediaDeviceData device) {
    }
    
    @javax.inject.Inject()
    public MediaDeviceManager(@org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaControllerFactory controllerFactory, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.LocalMediaManagerFactory localMediaManagerFactory, @org.jetbrains.annotations.NotNull()
    android.media.MediaRouter2Manager mr2manager, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    java.util.concurrent.Executor fgExecutor, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Background()
    java.util.concurrent.Executor bgExecutor, @org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager) {
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
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0018\u0002\bf\u0018\u00002\u00020\u0001J\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&J$\u0010\u0006\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\b\u0010\u0007\u001a\u0004\u0018\u00010\u00052\b\u0010\b\u001a\u0004\u0018\u00010\tH&"}, d2 = {"Lcom/android/systemui/media/MediaDeviceManager$Listener;", "", "onKeyRemoved", "", "key", "", "onMediaDeviceChanged", "oldKey", "data", "Lcom/android/systemui/media/MediaDeviceData;"})
    public static abstract interface Listener {
        
        /**
         * Called when the route has changed for a given notification.
         */
        public abstract void onMediaDeviceChanged(@org.jetbrains.annotations.NotNull()
        java.lang.String key, @org.jetbrains.annotations.Nullable()
        java.lang.String oldKey, @org.jetbrains.annotations.Nullable()
        com.android.systemui.media.MediaDeviceData data);
        
        /**
         * Called when the notification was removed.
         */
        public abstract void onKeyRemoved(@org.jetbrains.annotations.NotNull()
        java.lang.String key);
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000n\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\t\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0006\b\u0082\u0004\u0018\u00002\u00020\u00012\u00020\u0002B)\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\b\u0010\u0005\u001a\u0004\u0018\u00010\u0004\u0012\b\u0010\u0006\u001a\u0004\u0018\u00010\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJ)\u0010\u001f\u001a\u00020 2\u0006\u0010!\u001a\u00020\"2\u0006\u0010#\u001a\u00020$2\f\u0010%\u001a\b\u0012\u0004\u0012\u00020\u00040&\u00a2\u0006\u0002\u0010\'J\u0012\u0010(\u001a\u00020 2\b\u0010)\u001a\u0004\u0018\u00010*H\u0017J\u0018\u0010+\u001a\u00020 2\u000e\u0010,\u001a\n\u0012\u0004\u0012\u00020.\u0018\u00010-H\u0016J\u0018\u0010/\u001a\u00020 2\u0006\u00100\u001a\u00020.2\u0006\u00101\u001a\u00020\u0018H\u0016J\b\u00102\u001a\u00020 H\u0007J\b\u00103\u001a\u00020 H\u0007J\b\u00104\u001a\u00020 H\u0003R\u0013\u0010\u0006\u001a\u0004\u0018\u00010\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\fR\"\u0010\u000f\u001a\u0004\u0018\u00010\u000e2\b\u0010\r\u001a\u0004\u0018\u00010\u000e@BX\u0082\u000e\u00a2\u0006\b\n\u0000\"\u0004\b\u0010\u0010\u0011R\u0011\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\u0013R\u0011\u0010\b\u001a\u00020\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0014\u0010\u0015R\u0013\u0010\u0005\u001a\u0004\u0018\u00010\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0016\u0010\u0013R\u000e\u0010\u0017\u001a\u00020\u0018X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0019\u001a\u00020\u001aX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0013\u0010\u001b\u001a\u0004\u0018\u00010\u001c8F\u00a2\u0006\u0006\u001a\u0004\b\u001d\u0010\u001e"}, d2 = {"Lcom/android/systemui/media/MediaDeviceManager$Entry;", "Lcom/android/settingslib/media/LocalMediaManager$DeviceCallback;", "Landroid/media/session/MediaController$Callback;", "key", "", "oldKey", "controller", "Landroid/media/session/MediaController;", "localMediaManager", "Lcom/android/settingslib/media/LocalMediaManager;", "(Lcom/android/systemui/media/MediaDeviceManager;Ljava/lang/String;Ljava/lang/String;Landroid/media/session/MediaController;Lcom/android/settingslib/media/LocalMediaManager;)V", "getController", "()Landroid/media/session/MediaController;", "value", "Lcom/android/systemui/media/MediaDeviceData;", "current", "setCurrent", "(Lcom/android/systemui/media/MediaDeviceData;)V", "getKey", "()Ljava/lang/String;", "getLocalMediaManager", "()Lcom/android/settingslib/media/LocalMediaManager;", "getOldKey", "playbackType", "", "started", "", "token", "Landroid/media/session/MediaSession$Token;", "getToken", "()Landroid/media/session/MediaSession$Token;", "dump", "", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "onAudioInfoChanged", "info", "Landroid/media/session/MediaController$PlaybackInfo;", "onDeviceListUpdate", "devices", "", "Lcom/android/settingslib/media/MediaDevice;", "onSelectedDeviceStateChanged", "device", "state", "start", "stop", "updateCurrent"})
    final class Entry extends android.media.session.MediaController.Callback implements com.android.settingslib.media.LocalMediaManager.DeviceCallback {
        private boolean started = false;
        private int playbackType = 0;
        private com.android.systemui.media.MediaDeviceData current;
        @org.jetbrains.annotations.NotNull()
        private final java.lang.String key = null;
        @org.jetbrains.annotations.Nullable()
        private final java.lang.String oldKey = null;
        @org.jetbrains.annotations.Nullable()
        private final android.media.session.MediaController controller = null;
        @org.jetbrains.annotations.NotNull()
        private final com.android.settingslib.media.LocalMediaManager localMediaManager = null;
        
        @org.jetbrains.annotations.Nullable()
        public final android.media.session.MediaSession.Token getToken() {
            return null;
        }
        
        private final void setCurrent(com.android.systemui.media.MediaDeviceData value) {
        }
        
        @androidx.annotation.AnyThread()
        public final void start() {
        }
        
        @androidx.annotation.AnyThread()
        public final void stop() {
        }
        
        public final void dump(@org.jetbrains.annotations.NotNull()
        java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
        java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
        java.lang.String[] args) {
        }
        
        @androidx.annotation.WorkerThread()
        @java.lang.Override()
        public void onAudioInfoChanged(@org.jetbrains.annotations.Nullable()
        android.media.session.MediaController.PlaybackInfo info) {
        }
        
        @java.lang.Override()
        public void onDeviceListUpdate(@org.jetbrains.annotations.Nullable()
        java.util.List<? extends com.android.settingslib.media.MediaDevice> devices) {
        }
        
        @java.lang.Override()
        public void onSelectedDeviceStateChanged(@org.jetbrains.annotations.NotNull()
        com.android.settingslib.media.MediaDevice device, int state) {
        }
        
        @androidx.annotation.WorkerThread()
        private final void updateCurrent() {
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String getKey() {
            return null;
        }
        
        @org.jetbrains.annotations.Nullable()
        public final java.lang.String getOldKey() {
            return null;
        }
        
        @org.jetbrains.annotations.Nullable()
        public final android.media.session.MediaController getController() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.settingslib.media.LocalMediaManager getLocalMediaManager() {
            return null;
        }
        
        public Entry(@org.jetbrains.annotations.NotNull()
        java.lang.String key, @org.jetbrains.annotations.Nullable()
        java.lang.String oldKey, @org.jetbrains.annotations.Nullable()
        android.media.session.MediaController controller, @org.jetbrains.annotations.NotNull()
        com.android.settingslib.media.LocalMediaManager localMediaManager) {
            super();
        }
    }
}