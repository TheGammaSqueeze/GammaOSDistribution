package org.calyxos.backup.storage.prune;

import android.util.Log;
import org.calyxos.backup.storage.api.BackupObserver;
import org.calyxos.backup.storage.api.StoragePlugin;
import org.calyxos.backup.storage.api.StoredSnapshot;
import org.calyxos.backup.storage.crypto.StreamCrypto;
import org.calyxos.backup.storage.db.Db;
import org.calyxos.backup.storage.plugin.SnapshotRetriever;
import java.io.IOException;
import java.security.GeneralSecurityException;
import kotlin.time.ExperimentalTime;

@kotlin.Suppress(names = {"BlockingMethodInNonBlockingContext"})
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000J\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0012\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\b\u0000\u0018\u00002\u00020\u0001B/\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\b\b\u0002\u0010\n\u001a\u00020\u000b\u00a2\u0006\u0002\u0010\fJ\u001b\u0010\u0011\u001a\u00020\u00122\b\u0010\u0013\u001a\u0004\u0018\u00010\u0014H\u0086@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0015J#\u0010\u0016\u001a\u00020\u00122\u0006\u0010\u0017\u001a\u00020\u00182\b\u0010\u0013\u001a\u0004\u0018\u00010\u0014H\u0082@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0019R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lorg/calyxos/backup/storage/prune/Pruner;", "", "db", "Lorg/calyxos/backup/storage/db/Db;", "retentionManager", "Lorg/calyxos/backup/storage/prune/RetentionManager;", "storagePlugin", "Lorg/calyxos/backup/storage/api/StoragePlugin;", "snapshotRetriever", "Lorg/calyxos/backup/storage/plugin/SnapshotRetriever;", "streamCrypto", "Lorg/calyxos/backup/storage/crypto/StreamCrypto;", "(Lorg/calyxos/backup/storage/db/Db;Lorg/calyxos/backup/storage/prune/RetentionManager;Lorg/calyxos/backup/storage/api/StoragePlugin;Lorg/calyxos/backup/storage/plugin/SnapshotRetriever;Lorg/calyxos/backup/storage/crypto/StreamCrypto;)V", "chunksCache", "Lorg/calyxos/backup/storage/db/ChunksCache;", "streamKey", "", "prune", "", "backupObserver", "Lorg/calyxos/backup/storage/api/BackupObserver;", "(Lorg/calyxos/backup/storage/api/BackupObserver;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "pruneSnapshot", "storedSnapshot", "Lorg/calyxos/backup/storage/api/StoredSnapshot;", "(Lorg/calyxos/backup/storage/api/StoredSnapshot;Lorg/calyxos/backup/storage/api/BackupObserver;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;"})
public final class Pruner {
    private final org.calyxos.backup.storage.db.ChunksCache chunksCache = null;
    private final byte[] streamKey = null;
    private final org.calyxos.backup.storage.db.Db db = null;
    private final org.calyxos.backup.storage.prune.RetentionManager retentionManager = null;
    private final org.calyxos.backup.storage.api.StoragePlugin storagePlugin = null;
    private final org.calyxos.backup.storage.plugin.SnapshotRetriever snapshotRetriever = null;
    
    @org.jetbrains.annotations.Nullable()
    @kotlin.OptIn(markerClass = {kotlin.time.ExperimentalTime.class})
    public final java.lang.Object prune(@org.jetbrains.annotations.Nullable()
    org.calyxos.backup.storage.api.BackupObserver backupObserver, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p1) {
        return null;
    }
    
    public Pruner(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.db.Db db, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.prune.RetentionManager retentionManager, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.StoragePlugin storagePlugin, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.plugin.SnapshotRetriever snapshotRetriever, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.crypto.StreamCrypto streamCrypto) {
        super();
    }
}