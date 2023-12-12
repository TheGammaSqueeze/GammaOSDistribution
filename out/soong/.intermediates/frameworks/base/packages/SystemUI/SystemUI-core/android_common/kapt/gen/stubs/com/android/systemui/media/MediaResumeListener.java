package com.android.systemui.media;

import android.content.BroadcastReceiver;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.PackageManager;
import android.media.MediaDescription;
import android.os.UserHandle;
import android.provider.Settings;
import android.service.media.MediaBrowserService;
import android.util.Log;
import com.android.internal.annotations.VisibleForTesting;
import com.android.systemui.Dumpable;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Background;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.tuner.TunerService;
import com.android.systemui.util.Utils;
import com.android.systemui.util.time.SystemClock;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import java.util.concurrent.ConcurrentLinkedQueue;
import java.util.concurrent.Executor;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u00a0\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\t\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0018\u0002\n\u0002\b\b\b\u0007\u0018\u00002\u00020\u00012\u00020\u0002BA\b\u0007\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\b\b\u0001\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u0012\u0006\u0010\u000b\u001a\u00020\f\u0012\u0006\u0010\r\u001a\u00020\u000e\u0012\u0006\u0010\u000f\u001a\u00020\u0010\u00a2\u0006\u0002\u0010\u0011J-\u0010\'\u001a\u00020(2\u0006\u0010)\u001a\u00020*2\u0006\u0010+\u001a\u00020,2\u000e\u0010-\u001a\n\u0012\u0006\b\u0001\u0012\u00020/0.H\u0016\u00a2\u0006\u0002\u00100J\u0010\u00101\u001a\u0002022\u0006\u00103\u001a\u00020\u001dH\u0002J\b\u00104\u001a\u00020(H\u0002J\b\u00105\u001a\u00020(H\u0002J:\u00106\u001a\u00020(2\u0006\u00107\u001a\u00020/2\b\u00108\u001a\u0004\u0018\u00010/2\u0006\u00109\u001a\u00020:2\u0006\u0010;\u001a\u00020 2\u0006\u0010<\u001a\u00020\u00132\u0006\u0010=\u001a\u00020 H\u0016J\u000e\u0010>\u001a\u00020(2\u0006\u0010?\u001a\u00020\u0019J\u0018\u0010@\u001a\u00020(2\u0006\u00107\u001a\u00020/2\u0006\u00103\u001a\u00020\u001dH\u0002J\u0010\u0010A\u001a\u00020(2\u0006\u00103\u001a\u00020\u001dH\u0002J\b\u0010B\u001a\u00020(H\u0002R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0013X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0014\u001a\u0004\u0018\u00010\u0015X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0016\u001a\u00020\u0017X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0018\u001a\u00020\u0019X\u0082.\u00a2\u0006\u0002\n\u0000R \u0010\u001a\u001a\u0014\u0012\u0010\u0012\u000e\u0012\u0004\u0012\u00020\u001d\u0012\u0004\u0012\u00020\u001e0\u001c0\u001bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001f\u001a\u00020 X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001c\u0010!\u001a\u00020\"8\u0006X\u0087\u0004\u00a2\u0006\u000e\n\u0000\u0012\u0004\b#\u0010$\u001a\u0004\b%\u0010&"}, d2 = {"Lcom/android/systemui/media/MediaResumeListener;", "Lcom/android/systemui/media/MediaDataManager$Listener;", "Lcom/android/systemui/Dumpable;", "context", "Landroid/content/Context;", "broadcastDispatcher", "Lcom/android/systemui/broadcast/BroadcastDispatcher;", "backgroundExecutor", "Ljava/util/concurrent/Executor;", "tunerService", "Lcom/android/systemui/tuner/TunerService;", "mediaBrowserFactory", "Lcom/android/systemui/media/ResumeMediaBrowserFactory;", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "systemClock", "Lcom/android/systemui/util/time/SystemClock;", "(Landroid/content/Context;Lcom/android/systemui/broadcast/BroadcastDispatcher;Ljava/util/concurrent/Executor;Lcom/android/systemui/tuner/TunerService;Lcom/android/systemui/media/ResumeMediaBrowserFactory;Lcom/android/systemui/dump/DumpManager;Lcom/android/systemui/util/time/SystemClock;)V", "currentUserId", "", "mediaBrowser", "Lcom/android/systemui/media/ResumeMediaBrowser;", "mediaBrowserCallback", "Lcom/android/systemui/media/ResumeMediaBrowser$Callback;", "mediaDataManager", "Lcom/android/systemui/media/MediaDataManager;", "resumeComponents", "Ljava/util/concurrent/ConcurrentLinkedQueue;", "Lkotlin/Pair;", "Landroid/content/ComponentName;", "", "useMediaResumption", "", "userChangeReceiver", "Landroid/content/BroadcastReceiver;", "getUserChangeReceiver$annotations", "()V", "getUserChangeReceiver", "()Landroid/content/BroadcastReceiver;", "dump", "", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "getResumeAction", "Ljava/lang/Runnable;", "componentName", "loadMediaResumptionControls", "loadSavedComponents", "onMediaDataLoaded", "key", "oldKey", "data", "Lcom/android/systemui/media/MediaData;", "immediately", "receivedSmartspaceCardLatency", "isSsReactivated", "setManager", "manager", "tryUpdateResumptionList", "updateResumptionList", "writeSharedPrefs"})
@com.android.systemui.dagger.SysUISingleton()
public final class MediaResumeListener implements com.android.systemui.media.MediaDataManager.Listener, com.android.systemui.Dumpable {
    private boolean useMediaResumption;
    private final java.util.concurrent.ConcurrentLinkedQueue<kotlin.Pair<android.content.ComponentName, java.lang.Long>> resumeComponents = null;
    private com.android.systemui.media.MediaDataManager mediaDataManager;
    private com.android.systemui.media.ResumeMediaBrowser mediaBrowser;
    private int currentUserId;
    @org.jetbrains.annotations.NotNull()
    private final android.content.BroadcastReceiver userChangeReceiver = null;
    private final com.android.systemui.media.ResumeMediaBrowser.Callback mediaBrowserCallback = null;
    private final android.content.Context context = null;
    private final com.android.systemui.broadcast.BroadcastDispatcher broadcastDispatcher = null;
    private final java.util.concurrent.Executor backgroundExecutor = null;
    private final com.android.systemui.tuner.TunerService tunerService = null;
    private final com.android.systemui.media.ResumeMediaBrowserFactory mediaBrowserFactory = null;
    private final com.android.systemui.util.time.SystemClock systemClock = null;
    
    @com.android.internal.annotations.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getUserChangeReceiver$annotations() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.BroadcastReceiver getUserChangeReceiver() {
        return null;
    }
    
    public final void setManager(@org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaDataManager manager) {
    }
    
    private final void loadSavedComponents() {
    }
    
    /**
     * Load controls for resuming media, if available
     */
    private final void loadMediaResumptionControls() {
    }
    
    @java.lang.Override()
    public void onMediaDataLoaded(@org.jetbrains.annotations.NotNull()
    java.lang.String key, @org.jetbrains.annotations.Nullable()
    java.lang.String oldKey, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaData data, boolean immediately, int receivedSmartspaceCardLatency, boolean isSsReactivated) {
    }
    
    /**
     * Verify that we can connect to the given component with a MediaBrowser, and if so, add that
     * component to the list of resumption components
     */
    private final void tryUpdateResumptionList(java.lang.String key, android.content.ComponentName componentName) {
    }
    
    /**
     * Add the component to the saved list of media browser services, checking for duplicates and
     * removing older components that exceed the maximum limit
     * @param componentName
     */
    private final void updateResumptionList(android.content.ComponentName componentName) {
    }
    
    private final void writeSharedPrefs() {
    }
    
    /**
     * Get a runnable which will resume media playback
     */
    private final java.lang.Runnable getResumeAction(android.content.ComponentName componentName) {
        return null;
    }
    
    @java.lang.Override()
    public void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    @javax.inject.Inject()
    public MediaResumeListener(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.broadcast.BroadcastDispatcher broadcastDispatcher, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Background()
    java.util.concurrent.Executor backgroundExecutor, @org.jetbrains.annotations.NotNull()
    com.android.systemui.tuner.TunerService tunerService, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.ResumeMediaBrowserFactory mediaBrowserFactory, @org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.time.SystemClock systemClock) {
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
     * Called whenever a previously existing Media notification was removed.
     */
    public void onMediaDataRemoved(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
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
}