package org.calyxos.backup.storage.db;

import androidx.room.ColumnInfo;
import androidx.room.Dao;
import androidx.room.Delete;
import androidx.room.Entity;
import androidx.room.Insert;
import androidx.room.PrimaryKey;
import androidx.room.Query;
import org.calyxos.backup.storage.backup.Backup;

@androidx.room.Dao()
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000@\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u001e\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010 \n\u0002\b\u0003\n\u0002\u0010\b\n\u0002\b\u0004\ba\u0018\u00002\u00020\u0001J\u001e\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\f\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\b0\u0007H\u0016J\b\u0010\t\u001a\u00020\nH\'J\u001e\u0010\u000b\u001a\u00020\n2\u0006\u0010\u0004\u001a\u00020\u00052\f\u0010\f\u001a\b\u0012\u0004\u0012\u00020\r0\u0007H\u0016J\u0016\u0010\u000e\u001a\u00020\n2\f\u0010\u000f\u001a\b\u0012\u0004\u0012\u00020\b0\u0007H\'J\u0016\u0010\u0010\u001a\u00020\n2\f\u0010\f\u001a\b\u0012\u0004\u0012\u00020\r0\u0011H\'J\u0012\u0010\u0012\u001a\u0004\u0018\u00010\r2\u0006\u0010\u0013\u001a\u00020\bH\'J\u0016\u0010\u0014\u001a\u00020\u00152\f\u0010\u000f\u001a\b\u0012\u0004\u0012\u00020\b0\u0007H\'J\u000e\u0010\u0016\u001a\b\u0012\u0004\u0012\u00020\r0\u0011H\'J\u0016\u0010\u0017\u001a\u00020\n2\f\u0010\u000f\u001a\b\u0012\u0004\u0012\u00020\b0\u0007H\'J\u0016\u0010\u0018\u001a\u00020\n2\f\u0010\f\u001a\b\u0012\u0004\u0012\u00020\r0\u0007H\'J\u0010\u0010\u0018\u001a\u00020\n2\u0006\u0010\u0019\u001a\u00020\rH\'"}, d2 = {"Lorg/calyxos/backup/storage/db/ChunksCache;", "", "areAllAvailableChunksCached", "", "db", "Lorg/calyxos/backup/storage/db/Db;", "availableChunks", "", "", "clear", "", "clearAndRepopulate", "chunks", "Lorg/calyxos/backup/storage/db/CachedChunk;", "decrementRefCount", "ids", "deleteChunks", "", "get", "id", "getNumberOfCachedChunks", "", "getUnreferencedChunks", "incrementRefCount", "insert", "chunk"})
public abstract interface ChunksCache {
    
    @androidx.room.Insert()
    public abstract void insert(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.db.CachedChunk chunk);
    
    @androidx.room.Insert()
    public abstract void insert(@org.jetbrains.annotations.NotNull()
    java.util.Collection<org.calyxos.backup.storage.db.CachedChunk> chunks);
    
    @org.jetbrains.annotations.Nullable()
    @androidx.room.Query(value = "SELECT * FROM CachedChunk WHERE id == (:id)")
    public abstract org.calyxos.backup.storage.db.CachedChunk get(@org.jetbrains.annotations.NotNull()
    java.lang.String id);
    
    @androidx.room.Query(value = "SELECT COUNT(id) FROM CachedChunk WHERE id IN (:ids)")
    public abstract int getNumberOfCachedChunks(@org.jetbrains.annotations.NotNull()
    java.util.Collection<java.lang.String> ids);
    
    @org.jetbrains.annotations.NotNull()
    @androidx.room.Query(value = "SELECT * FROM CachedChunk WHERE ref_count <= 0")
    public abstract java.util.List<org.calyxos.backup.storage.db.CachedChunk> getUnreferencedChunks();
    
    @androidx.room.Query(value = "UPDATE CachedChunk SET ref_count = ref_count + 1 WHERE id IN (:ids)")
    public abstract void incrementRefCount(@org.jetbrains.annotations.NotNull()
    java.util.Collection<java.lang.String> ids);
    
    @androidx.room.Query(value = "UPDATE CachedChunk SET ref_count = ref_count - 1 WHERE id IN (:ids)")
    public abstract void decrementRefCount(@org.jetbrains.annotations.NotNull()
    java.util.Collection<java.lang.String> ids);
    
    @androidx.room.Delete()
    public abstract void deleteChunks(@org.jetbrains.annotations.NotNull()
    java.util.List<org.calyxos.backup.storage.db.CachedChunk> chunks);
    
    @androidx.room.Query(value = "DELETE FROM CachedChunk")
    public abstract void clear();
    
    public abstract boolean areAllAvailableChunksCached(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.db.Db db, @org.jetbrains.annotations.NotNull()
    java.util.Collection<java.lang.String> availableChunks);
    
    public abstract void clearAndRepopulate(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.db.Db db, @org.jetbrains.annotations.NotNull()
    java.util.Collection<org.calyxos.backup.storage.db.CachedChunk> chunks);
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 3)
    public final class DefaultImpls {
        
        public static boolean areAllAvailableChunksCached(@org.jetbrains.annotations.NotNull()
        org.calyxos.backup.storage.db.ChunksCache $this, @org.jetbrains.annotations.NotNull()
        org.calyxos.backup.storage.db.Db db, @org.jetbrains.annotations.NotNull()
        java.util.Collection<java.lang.String> availableChunks) {
            return false;
        }
        
        public static void clearAndRepopulate(@org.jetbrains.annotations.NotNull()
        org.calyxos.backup.storage.db.ChunksCache $this, @org.jetbrains.annotations.NotNull()
        org.calyxos.backup.storage.db.Db db, @org.jetbrains.annotations.NotNull()
        java.util.Collection<org.calyxos.backup.storage.db.CachedChunk> chunks) {
        }
    }
}