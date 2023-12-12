package org.calyxos.backup.storage.api;

import android.content.Context;
import android.net.Uri;
import android.provider.MediaStore;
import android.util.Log;
import androidx.annotation.WorkerThread;
import androidx.room.Room;
import kotlinx.coroutines.CoroutineDispatcher;
import kotlinx.coroutines.Dispatchers;
import kotlinx.coroutines.flow.Flow;
import org.calyxos.backup.storage.backup.Backup;
import org.calyxos.backup.storage.backup.BackupSnapshot;
import org.calyxos.backup.storage.backup.ChunksCacheRepopulater;
import org.calyxos.backup.storage.db.Db;
import org.calyxos.backup.storage.plugin.SnapshotRetriever;
import org.calyxos.backup.storage.prune.Pruner;
import org.calyxos.backup.storage.prune.RetentionManager;
import org.calyxos.backup.storage.restore.FileRestore;
import org.calyxos.backup.storage.restore.Restore;
import org.calyxos.backup.storage.scanner.DocumentScanner;
import org.calyxos.backup.storage.scanner.FileScanner;
import org.calyxos.backup.storage.scanner.MediaScanner;
import java.io.IOException;
import java.util.concurrent.atomic.AtomicBoolean;

@kotlin.Suppress(names = {"BlockingMethodInNonBlockingContext"})
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u00b2\u0001\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\"\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\u0018\u00002\u00020\u0001B\u001f\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\b\b\u0002\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ\u0019\u00106\u001a\u0002072\u0006\u00108\u001a\u000203H\u0086@\u00f8\u0001\u0000\u00a2\u0006\u0002\u00109J\u0011\u0010:\u001a\u000207H\u0086@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010;J\u0011\u0010<\u001a\u000207H\u0086@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010;J\f\u0010=\u001a\b\u0012\u0004\u0012\u00020?0>J\b\u0010@\u001a\u00020AH\u0007J\u0011\u0010B\u001a\u00020CH\u0086@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010;J\u001b\u0010D\u001a\u00020E2\b\u0010F\u001a\u0004\u0018\u00010GH\u0086@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010HJ\u0019\u0010I\u001a\u0002072\u0006\u00108\u001a\u000203H\u0086@\u00f8\u0001\u0000\u00a2\u0006\u0002\u00109J1\u0010J\u001a\u00020E2\u0006\u0010K\u001a\u00020L2\n\b\u0002\u0010M\u001a\u0004\u0018\u00010N2\n\b\u0002\u0010O\u001a\u0004\u0018\u00010PH\u0086@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010QJ\u001b\u0010R\u001a\u00020E2\b\u0010F\u001a\u0004\u0018\u00010GH\u0086@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010HJ\u000e\u0010S\u001a\u0002072\u0006\u0010T\u001a\u00020AR\u001b\u0010\t\u001a\u00020\n8BX\u0082\u0084\u0002\u00a2\u0006\f\n\u0004\b\r\u0010\u000e\u001a\u0004\b\u000b\u0010\fR\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0011\u001a\u00020\u0012X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001b\u0010\u0013\u001a\u00020\u00148BX\u0082\u0084\u0002\u00a2\u0006\f\n\u0004\b\u0017\u0010\u000e\u001a\u0004\b\u0015\u0010\u0016R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001b\u0010\u0018\u001a\u00020\u00198BX\u0082\u0084\u0002\u00a2\u0006\f\n\u0004\b\u001c\u0010\u000e\u001a\u0004\b\u001a\u0010\u001bR\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001b\u0010\u001d\u001a\u00020\u001e8BX\u0082\u0084\u0002\u00a2\u0006\f\n\u0004\b!\u0010\u000e\u001a\u0004\b\u001f\u0010 R\u001b\u0010\"\u001a\u00020#8BX\u0082\u0084\u0002\u00a2\u0006\f\n\u0004\b&\u0010\u000e\u001a\u0004\b$\u0010%R\u000e\u0010\'\u001a\u00020\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010(\u001a\u00020)X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010*\u001a\u00020+X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001b\u0010,\u001a\u00020-8BX\u0082\u0084\u0002\u00a2\u0006\f\n\u0004\b0\u0010\u000e\u001a\u0004\b.\u0010/R\u0017\u00101\u001a\b\u0012\u0004\u0012\u000203028G\u00a2\u0006\u0006\u001a\u0004\b4\u00105\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lorg/calyxos/backup/storage/api/StorageBackup;", "", "context", "Landroid/content/Context;", "plugin", "Lorg/calyxos/backup/storage/api/StoragePlugin;", "dispatcher", "Lkotlinx/coroutines/CoroutineDispatcher;", "(Landroid/content/Context;Lorg/calyxos/backup/storage/api/StoragePlugin;Lkotlinx/coroutines/CoroutineDispatcher;)V", "backup", "Lorg/calyxos/backup/storage/backup/Backup;", "getBackup", "()Lorg/calyxos/backup/storage/backup/Backup;", "backup$delegate", "Lkotlin/Lazy;", "backupRunning", "Ljava/util/concurrent/atomic/AtomicBoolean;", "chunksCacheRepopulater", "Lorg/calyxos/backup/storage/backup/ChunksCacheRepopulater;", "db", "Lorg/calyxos/backup/storage/db/Db;", "getDb", "()Lorg/calyxos/backup/storage/db/Db;", "db$delegate", "mediaScanner", "Lorg/calyxos/backup/storage/scanner/MediaScanner;", "getMediaScanner", "()Lorg/calyxos/backup/storage/scanner/MediaScanner;", "mediaScanner$delegate", "pruner", "Lorg/calyxos/backup/storage/prune/Pruner;", "getPruner", "()Lorg/calyxos/backup/storage/prune/Pruner;", "pruner$delegate", "restore", "Lorg/calyxos/backup/storage/restore/Restore;", "getRestore", "()Lorg/calyxos/backup/storage/restore/Restore;", "restore$delegate", "restoreRunning", "retention", "Lorg/calyxos/backup/storage/prune/RetentionManager;", "snapshotRetriever", "Lorg/calyxos/backup/storage/plugin/SnapshotRetriever;", "uriStore", "Lorg/calyxos/backup/storage/db/UriStore;", "getUriStore", "()Lorg/calyxos/backup/storage/db/UriStore;", "uriStore$delegate", "uris", "", "Landroid/net/Uri;", "getUris", "()Ljava/util/Set;", "addUri", "", "uri", "(Landroid/net/Uri;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "clearCache", "(Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "deleteAllSnapshots", "getBackupSnapshots", "Lkotlinx/coroutines/flow/Flow;", "Lorg/calyxos/backup/storage/api/SnapshotResult;", "getSnapshotRetention", "Lorg/calyxos/backup/storage/api/SnapshotRetention;", "getUriSummaryString", "", "pruneOldBackups", "", "backupObserver", "Lorg/calyxos/backup/storage/api/BackupObserver;", "(Lorg/calyxos/backup/storage/api/BackupObserver;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "removeUri", "restoreBackupSnapshot", "storedSnapshot", "Lorg/calyxos/backup/storage/api/StoredSnapshot;", "snapshot", "Lorg/calyxos/backup/storage/backup/BackupSnapshot;", "restoreObserver", "Lorg/calyxos/backup/storage/api/RestoreObserver;", "(Lorg/calyxos/backup/storage/api/StoredSnapshot;Lorg/calyxos/backup/storage/backup/BackupSnapshot;Lorg/calyxos/backup/storage/api/RestoreObserver;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "runBackup", "setSnapshotRetention", "snapshotRetention"})
public final class StorageBackup {
    private final kotlin.Lazy db$delegate = null;
    private final kotlin.Lazy uriStore$delegate = null;
    private final kotlin.Lazy mediaScanner$delegate = null;
    private final org.calyxos.backup.storage.plugin.SnapshotRetriever snapshotRetriever = null;
    private final org.calyxos.backup.storage.backup.ChunksCacheRepopulater chunksCacheRepopulater = null;
    private final kotlin.Lazy backup$delegate = null;
    private final kotlin.Lazy restore$delegate = null;
    private final org.calyxos.backup.storage.prune.RetentionManager retention = null;
    private final kotlin.Lazy pruner$delegate = null;
    private final java.util.concurrent.atomic.AtomicBoolean backupRunning = null;
    private final java.util.concurrent.atomic.AtomicBoolean restoreRunning = null;
    private final android.content.Context context = null;
    private final org.calyxos.backup.storage.api.StoragePlugin plugin = null;
    private final kotlinx.coroutines.CoroutineDispatcher dispatcher = null;
    
    private final org.calyxos.backup.storage.db.Db getDb() {
        return null;
    }
    
    private final org.calyxos.backup.storage.db.UriStore getUriStore() {
        return null;
    }
    
    private final org.calyxos.backup.storage.scanner.MediaScanner getMediaScanner() {
        return null;
    }
    
    private final org.calyxos.backup.storage.backup.Backup getBackup() {
        return null;
    }
    
    private final org.calyxos.backup.storage.restore.Restore getRestore() {
        return null;
    }
    
    private final org.calyxos.backup.storage.prune.Pruner getPruner() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @androidx.annotation.WorkerThread()
    public final java.util.Set<android.net.Uri> getUris() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Object addUri(@org.jetbrains.annotations.NotNull()
    android.net.Uri uri, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p1) {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Object removeUri(@org.jetbrains.annotations.NotNull()
    android.net.Uri uri, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p1) {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Object getUriSummaryString(@org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super java.lang.String> p0) {
        return null;
    }
    
    /**
     * Run this on a new storage location to ensure that there are no old snapshots
     * (potentially encrypted with an old key) laying around.
     * Using a storage location with existing data is not supported.
     * Using the same root folder for storage on different devices or user profiles is fine though
     * as the [StoragePlugin] should isolate storage per [StoredSnapshot.userId].
     */
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Object deleteAllSnapshots(@org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p0) {
        return null;
    }
    
    /**
     * It is advised to clear existing cache when selecting a new storage location.
     */
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Object clearCache(@org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p0) {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Object runBackup(@org.jetbrains.annotations.Nullable()
    org.calyxos.backup.storage.api.BackupObserver backupObserver, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super java.lang.Boolean> p1) {
        return null;
    }
    
    /**
     * Sets how many backup snapshots to keep in storage when running [pruneOldBackups].
     *
     * @throws IllegalArgumentException if all retention values are set to 0.
     */
    public final void setSnapshotRetention(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.SnapshotRetention snapshotRetention) {
    }
    
    /**
     * Gets the current snapshot retention policy.
     */
    @org.jetbrains.annotations.NotNull()
    @androidx.annotation.WorkerThread()
    public final org.calyxos.backup.storage.api.SnapshotRetention getSnapshotRetention() {
        return null;
    }
    
    /**
     * Prunes old backup snapshots according to the parameters set via [setSnapshotRetention].
     * This will delete backed up data. Use with care!
     *
     * Run this only after [runBackup] returns true to ensure
     * that no chunks from partial backups get removed and need to be re-uploaded.
     */
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Object pruneOldBackups(@org.jetbrains.annotations.Nullable()
    org.calyxos.backup.storage.api.BackupObserver backupObserver, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super java.lang.Boolean> p1) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final kotlinx.coroutines.flow.Flow<org.calyxos.backup.storage.api.SnapshotResult> getBackupSnapshots() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Object restoreBackupSnapshot(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.StoredSnapshot storedSnapshot, @org.jetbrains.annotations.Nullable()
    org.calyxos.backup.storage.backup.BackupSnapshot snapshot, @org.jetbrains.annotations.Nullable()
    org.calyxos.backup.storage.api.RestoreObserver restoreObserver, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super java.lang.Boolean> p3) {
        return null;
    }
    
    public StorageBackup(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.StoragePlugin plugin, @org.jetbrains.annotations.NotNull()
    kotlinx.coroutines.CoroutineDispatcher dispatcher) {
        super();
    }
}