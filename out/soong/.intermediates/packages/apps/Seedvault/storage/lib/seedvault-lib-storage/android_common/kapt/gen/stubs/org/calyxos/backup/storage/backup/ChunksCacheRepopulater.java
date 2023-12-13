package org.calyxos.backup.storage.backup;

import android.util.Log;
import org.calyxos.backup.storage.api.StoragePlugin;
import org.calyxos.backup.storage.db.CachedChunk;
import org.calyxos.backup.storage.db.Db;
import org.calyxos.backup.storage.plugin.SnapshotRetriever;
import java.io.IOException;
import java.security.GeneralSecurityException;
import kotlin.time.ExperimentalTime;

@kotlin.Suppress(names = {"BlockingMethodInNonBlockingContext"})
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000b\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\t\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u001e\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0012\n\u0002\b\u0003\b\u0000\u0018\u00002\u00020\u0001B\u001d\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJd\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\f2\u0016\u0010\r\u001a\u0012\u0012\u0004\u0012\u00020\u000f0\u000ej\b\u0012\u0004\u0012\u00020\u000f`\u00102\"\u0010\u0011\u001a\u001e\u0012\u0004\u0012\u00020\u000f\u0012\u0004\u0012\u00020\u00130\u0012j\u000e\u0012\u0004\u0012\u00020\u000f\u0012\u0004\u0012\u00020\u0013`\u00142\u0016\u0010\u0015\u001a\u0012\u0012\u0004\u0012\u00020\u000f0\u000ej\b\u0012\u0004\u0012\u00020\u000f`\u0010H\u0002J4\u0010\u0016\u001a\b\u0012\u0004\u0012\u00020\u00130\u00172\f\u0010\u0018\u001a\b\u0012\u0004\u0012\u00020\u001a0\u00192\u0016\u0010\r\u001a\u0012\u0012\u0004\u0012\u00020\u000f0\u000ej\b\u0012\u0004\u0012\u00020\u000f`\u0010H\u0002J1\u0010\u001b\u001a\u00020\n2\u0006\u0010\u001c\u001a\u00020\u001d2\u0016\u0010\u001e\u001a\u0012\u0012\u0004\u0012\u00020\u000f0\u000ej\b\u0012\u0004\u0012\u00020\u000f`\u0010H\u0086@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u001fJ1\u0010 \u001a\u00020\n2\u0006\u0010\u001c\u001a\u00020\u001d2\u0016\u0010\u001e\u001a\u0012\u0012\u0004\u0012\u00020\u000f0\u000ej\b\u0012\u0004\u0012\u00020\u000f`\u0010H\u0082@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u001fR\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lorg/calyxos/backup/storage/backup/ChunksCacheRepopulater;", "", "db", "Lorg/calyxos/backup/storage/db/Db;", "storagePlugin", "Lorg/calyxos/backup/storage/api/StoragePlugin;", "snapshotRetriever", "Lorg/calyxos/backup/storage/plugin/SnapshotRetriever;", "(Lorg/calyxos/backup/storage/db/Db;Lorg/calyxos/backup/storage/api/StoragePlugin;Lorg/calyxos/backup/storage/plugin/SnapshotRetriever;)V", "addCachedChunksToMap", "", "snapshotTimeStamp", "", "availableChunks", "Ljava/util/HashSet;", "", "Lkotlin/collections/HashSet;", "chunkMap", "Ljava/util/HashMap;", "Lorg/calyxos/backup/storage/db/CachedChunk;", "Lkotlin/collections/HashMap;", "chunksInSnapshot", "getCachedChunks", "", "snapshots", "", "Lorg/calyxos/backup/storage/backup/BackupSnapshot;", "repopulate", "streamKey", "", "availableChunkIds", "([BLjava/util/HashSet;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "repopulateInternal"})
public final class ChunksCacheRepopulater {
    private final org.calyxos.backup.storage.db.Db db = null;
    private final org.calyxos.backup.storage.api.StoragePlugin storagePlugin = null;
    private final org.calyxos.backup.storage.plugin.SnapshotRetriever snapshotRetriever = null;
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Object repopulate(@org.jetbrains.annotations.NotNull()
    byte[] streamKey, @org.jetbrains.annotations.NotNull()
    java.util.HashSet<java.lang.String> availableChunkIds, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p2) {
        return null;
    }
    
    private final java.util.Collection<org.calyxos.backup.storage.db.CachedChunk> getCachedChunks(java.util.List<org.calyxos.backup.storage.backup.BackupSnapshot> snapshots, java.util.HashSet<java.lang.String> availableChunks) {
        return null;
    }
    
    private final void addCachedChunksToMap(long snapshotTimeStamp, java.util.HashSet<java.lang.String> availableChunks, java.util.HashMap<java.lang.String, org.calyxos.backup.storage.db.CachedChunk> chunkMap, java.util.HashSet<java.lang.String> chunksInSnapshot) {
    }
    
    public ChunksCacheRepopulater(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.db.Db db, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.StoragePlugin storagePlugin, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.plugin.SnapshotRetriever snapshotRetriever) {
        super();
    }
}