package com.android.systemui.qs;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.database.ContentObserver;
import android.net.Uri;
import android.os.Handler;
import android.os.UserHandle;
import android.provider.Settings;
import android.text.TextUtils;
import android.util.ArraySet;
import android.util.Log;
import androidx.annotation.GuardedBy;
import androidx.annotation.VisibleForTesting;
import com.android.systemui.Dumpable;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Background;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.util.UserAwareController;
import com.android.systemui.util.settings.SecureSettings;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import java.util.concurrent.Executor;
import javax.inject.Inject;

/**
 * Class to track tiles that have been auto-added
 *
 * The list is backed by [Settings.Secure.QS_AUTO_ADDED_TILES].
 *
 * It also handles restore gracefully.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0092\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\"\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\b\u0002\n\u0002\u0010\u001e\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\b\u0018\u0000 =2\u00020\u00012\u00020\u0002:\u0002<=BA\b\u0007\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u0012\b\u0010\u000b\u001a\u0004\u0018\u00010\f\u0012\u0006\u0010\r\u001a\u00020\u000e\u0012\u0006\u0010\u000f\u001a\u00020\u0010\u00a2\u0006\u0002\u0010\u0011J\u0010\u0010\u001e\u001a\u00020\u001f2\u0006\u0010 \u001a\u00020!H\u0016J\u0006\u0010\"\u001a\u00020\u001fJ-\u0010#\u001a\u00020\u001f2\u0006\u0010$\u001a\u00020%2\u0006\u0010&\u001a\u00020\'2\u000e\u0010(\u001a\n\u0012\u0006\b\u0001\u0012\u00020\u00140)H\u0016\u00a2\u0006\u0002\u0010*J\u000e\u0010+\u001a\b\u0012\u0004\u0012\u00020\u00140,H\u0002J\b\u0010-\u001a\u00020\u0014H\u0002J\u0006\u0010.\u001a\u00020\u001fJ\u000e\u0010/\u001a\u0002002\u0006\u00101\u001a\u00020\u0014J\b\u00102\u001a\u00020\u001fH\u0002J\u0010\u00103\u001a\u00020\u001f2\u0006\u00104\u001a\u000205H\u0002J\b\u00106\u001a\u00020\u001fH\u0002J\u0010\u00107\u001a\u00020\u001f2\u0006\u00108\u001a\u00020\u0014H\u0002J\u000e\u00109\u001a\u00020\u001f2\u0006\u00101\u001a\u00020\u0014J\u000e\u0010:\u001a\u00020\u001f2\u0006\u00101\u001a\u00020\u0014J\b\u0010;\u001a\u00020\u001fH\u0002R\u0016\u0010\u0012\u001a\b\u0012\u0004\u0012\u00020\u00140\u00138\u0002X\u0083\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0015\u001a\u00020\u0016X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0017\u001a\u00020\u00108VX\u0096\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0018\u0010\u0019R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u000b\u001a\u0004\u0018\u00010\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001a\u001a\u00020\u001bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u001c\u001a\n\u0012\u0004\u0012\u00020\u0014\u0018\u00010\u001dX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/qs/AutoAddTracker;", "Lcom/android/systemui/util/UserAwareController;", "Lcom/android/systemui/Dumpable;", "secureSettings", "Lcom/android/systemui/util/settings/SecureSettings;", "broadcastDispatcher", "Lcom/android/systemui/broadcast/BroadcastDispatcher;", "qsHost", "Lcom/android/systemui/qs/QSHost;", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "mainHandler", "Landroid/os/Handler;", "backgroundExecutor", "Ljava/util/concurrent/Executor;", "userId", "", "(Lcom/android/systemui/util/settings/SecureSettings;Lcom/android/systemui/broadcast/BroadcastDispatcher;Lcom/android/systemui/qs/QSHost;Lcom/android/systemui/dump/DumpManager;Landroid/os/Handler;Ljava/util/concurrent/Executor;I)V", "autoAdded", "Landroid/util/ArraySet;", "", "contentObserver", "Landroid/database/ContentObserver;", "currentUserId", "getCurrentUserId", "()I", "restoreReceiver", "Landroid/content/BroadcastReceiver;", "restoredTiles", "", "changeUser", "", "newUser", "Landroid/os/UserHandle;", "destroy", "dump", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "getAdded", "", "getTilesFromListLocked", "initialize", "isAdded", "", "tile", "loadTiles", "processRestoreIntent", "intent", "Landroid/content/Intent;", "registerBroadcastReceiver", "saveTiles", "tiles", "setTileAdded", "setTileRemoved", "unregisterBroadcastReceiver", "Builder", "Companion"})
public final class AutoAddTracker implements com.android.systemui.util.UserAwareController, com.android.systemui.Dumpable {
    @androidx.annotation.GuardedBy(value = "autoAdded")
    private final android.util.ArraySet<java.lang.String> autoAdded = null;
    private java.util.Set<java.lang.String> restoredTiles;
    private final android.database.ContentObserver contentObserver = null;
    private final android.content.BroadcastReceiver restoreReceiver = null;
    private final com.android.systemui.util.settings.SecureSettings secureSettings = null;
    private final com.android.systemui.broadcast.BroadcastDispatcher broadcastDispatcher = null;
    private final com.android.systemui.qs.QSHost qsHost = null;
    private final com.android.systemui.dump.DumpManager dumpManager = null;
    private final android.os.Handler mainHandler = null;
    private final java.util.concurrent.Executor backgroundExecutor = null;
    private int userId;
    private static final android.content.IntentFilter FILTER = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.qs.AutoAddTracker.Companion Companion = null;
    
    @java.lang.Override()
    public int getCurrentUserId() {
        return 0;
    }
    
    private final void processRestoreIntent(android.content.Intent intent) {
    }
    
    /**
     * Init method must be called after construction to start listening
     */
    public final void initialize() {
    }
    
    /**
     * Unregister listeners, receivers and observers
     */
    public final void destroy() {
    }
    
    private final void registerBroadcastReceiver() {
    }
    
    private final void unregisterBroadcastReceiver() {
    }
    
    @java.lang.Override()
    public void changeUser(@org.jetbrains.annotations.NotNull()
    android.os.UserHandle newUser) {
    }
    
    /**
     * Returns `true` if the tile has been auto-added before
     */
    public final boolean isAdded(@org.jetbrains.annotations.NotNull()
    java.lang.String tile) {
        return false;
    }
    
    /**
     * Sets a tile as auto-added.
     *
     * From here on, [isAdded] will return true for that tile.
     */
    public final void setTileAdded(@org.jetbrains.annotations.NotNull()
    java.lang.String tile) {
    }
    
    /**
     * Removes a tile from the list of auto-added.
     *
     * This allows for this tile to be auto-added again in the future.
     */
    public final void setTileRemoved(@org.jetbrains.annotations.NotNull()
    java.lang.String tile) {
    }
    
    private final java.lang.String getTilesFromListLocked() {
        return null;
    }
    
    private final void saveTiles(java.lang.String tiles) {
    }
    
    private final void loadTiles() {
    }
    
    private final java.util.Collection<java.lang.String> getAdded() {
        return null;
    }
    
    @java.lang.Override()
    public void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    @androidx.annotation.VisibleForTesting()
    public AutoAddTracker(@org.jetbrains.annotations.NotNull()
    com.android.systemui.util.settings.SecureSettings secureSettings, @org.jetbrains.annotations.NotNull()
    com.android.systemui.broadcast.BroadcastDispatcher broadcastDispatcher, @org.jetbrains.annotations.NotNull()
    com.android.systemui.qs.QSHost qsHost, @org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager, @org.jetbrains.annotations.Nullable()
    android.os.Handler mainHandler, @org.jetbrains.annotations.NotNull()
    java.util.concurrent.Executor backgroundExecutor, int userId) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000>\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\b\u0007\u0018\u00002\u00020\u0001B;\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\b\b\u0001\u0010\n\u001a\u00020\u000b\u0012\b\b\u0001\u0010\f\u001a\u00020\r\u00a2\u0006\u0002\u0010\u000eJ\u0006\u0010\u0011\u001a\u00020\u0012J\u000e\u0010\u0013\u001a\u00020\u00002\u0006\u0010\u0014\u001a\u00020\u0010R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/qs/AutoAddTracker$Builder;", "", "secureSettings", "Lcom/android/systemui/util/settings/SecureSettings;", "broadcastDispatcher", "Lcom/android/systemui/broadcast/BroadcastDispatcher;", "qsHost", "Lcom/android/systemui/qs/QSHost;", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "handler", "Landroid/os/Handler;", "executor", "Ljava/util/concurrent/Executor;", "(Lcom/android/systemui/util/settings/SecureSettings;Lcom/android/systemui/broadcast/BroadcastDispatcher;Lcom/android/systemui/qs/QSHost;Lcom/android/systemui/dump/DumpManager;Landroid/os/Handler;Ljava/util/concurrent/Executor;)V", "userId", "", "build", "Lcom/android/systemui/qs/AutoAddTracker;", "setUserId", "_userId"})
    @com.android.systemui.dagger.SysUISingleton()
    public static final class Builder {
        private int userId = 0;
        private final com.android.systemui.util.settings.SecureSettings secureSettings = null;
        private final com.android.systemui.broadcast.BroadcastDispatcher broadcastDispatcher = null;
        private final com.android.systemui.qs.QSHost qsHost = null;
        private final com.android.systemui.dump.DumpManager dumpManager = null;
        private final android.os.Handler handler = null;
        private final java.util.concurrent.Executor executor = null;
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.qs.AutoAddTracker.Builder setUserId(int _userId) {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.qs.AutoAddTracker build() {
            return null;
        }
        
        @javax.inject.Inject()
        public Builder(@org.jetbrains.annotations.NotNull()
        com.android.systemui.util.settings.SecureSettings secureSettings, @org.jetbrains.annotations.NotNull()
        com.android.systemui.broadcast.BroadcastDispatcher broadcastDispatcher, @org.jetbrains.annotations.NotNull()
        com.android.systemui.qs.QSHost qsHost, @org.jetbrains.annotations.NotNull()
        com.android.systemui.dump.DumpManager dumpManager, @org.jetbrains.annotations.NotNull()
        @com.android.systemui.dagger.qualifiers.Main()
        android.os.Handler handler, @org.jetbrains.annotations.NotNull()
        @com.android.systemui.dagger.qualifiers.Background()
        java.util.concurrent.Executor executor) {
            super();
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/qs/AutoAddTracker$Companion;", "", "()V", "FILTER", "Landroid/content/IntentFilter;"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}