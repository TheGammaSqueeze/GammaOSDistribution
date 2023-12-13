package org.calyxos.backup.storage.restore;

import org.calyxos.backup.storage.api.BackupFile;
import org.calyxos.backup.storage.backup.BackupDocumentFile;
import org.calyxos.backup.storage.backup.BackupMediaFile;
import org.calyxos.backup.storage.backup.BackupSnapshot;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00006\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u001e\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010$\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\b\r\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\b\u0080\b\u0018\u00002\u00020\u0001BC\u0012\f\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u0012\f\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u0012\u0012\u0010\u0006\u001a\u000e\u0012\u0004\u0012\u00020\b\u0012\u0004\u0012\u00020\u00040\u0007\u0012\f\u0010\t\u001a\b\u0012\u0004\u0012\u00020\n0\u0003\u00a2\u0006\u0002\u0010\u000bJ\u000f\u0010\u0012\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003H\u00c6\u0003J\u000f\u0010\u0013\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003H\u00c6\u0003J\u0015\u0010\u0014\u001a\u000e\u0012\u0004\u0012\u00020\b\u0012\u0004\u0012\u00020\u00040\u0007H\u00c6\u0003J\u000f\u0010\u0015\u001a\b\u0012\u0004\u0012\u00020\n0\u0003H\u00c6\u0003JO\u0010\u0016\u001a\u00020\u00002\u000e\b\u0002\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u00032\u000e\b\u0002\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00040\u00032\u0014\b\u0002\u0010\u0006\u001a\u000e\u0012\u0004\u0012\u00020\b\u0012\u0004\u0012\u00020\u00040\u00072\u000e\b\u0002\u0010\t\u001a\b\u0012\u0004\u0012\u00020\n0\u0003H\u00c6\u0001J\u0013\u0010\u0017\u001a\u00020\u00182\b\u0010\u0019\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u001a\u001a\u00020\u001bH\u00d6\u0001J\t\u0010\u001c\u001a\u00020\bH\u00d6\u0001R\u0017\u0010\t\u001a\b\u0012\u0004\u0012\u00020\n0\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\rR\u001d\u0010\u0006\u001a\u000e\u0012\u0004\u0012\u00020\b\u0012\u0004\u0012\u00020\u00040\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000e\u0010\u000fR\u0017\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0010\u0010\rR\u0017\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0011\u0010\r"}, d2 = {"Lorg/calyxos/backup/storage/restore/FileSplitterResult;", "", "zipChunks", "", "Lorg/calyxos/backup/storage/restore/RestorableChunk;", "singleChunks", "multiChunkMap", "", "", "multiChunkFiles", "Lorg/calyxos/backup/storage/restore/RestorableFile;", "(Ljava/util/Collection;Ljava/util/Collection;Ljava/util/Map;Ljava/util/Collection;)V", "getMultiChunkFiles", "()Ljava/util/Collection;", "getMultiChunkMap", "()Ljava/util/Map;", "getSingleChunks", "getZipChunks", "component1", "component2", "component3", "component4", "copy", "equals", "", "other", "hashCode", "", "toString"})
public final class FileSplitterResult {
    
    /**
     * Zip chunks containing several small files.
     */
    @org.jetbrains.annotations.NotNull()
    private final java.util.Collection<org.calyxos.backup.storage.restore.RestorableChunk> zipChunks = null;
    
    /**
     * Chunks that contains exactly one single file.
     */
    @org.jetbrains.annotations.NotNull()
    private final java.util.Collection<org.calyxos.backup.storage.restore.RestorableChunk> singleChunks = null;
    
    /**
     * A map of chunk ID to chunks
     * where either the chunk is used by more than one file
     * or a file needs more than one chunk.
     */
    @org.jetbrains.annotations.NotNull()
    private final java.util.Map<java.lang.String, org.calyxos.backup.storage.restore.RestorableChunk> multiChunkMap = null;
    
    /**
     * Files referenced in [multiChunkMap] sorted for restoring.
     */
    @org.jetbrains.annotations.NotNull()
    private final java.util.Collection<org.calyxos.backup.storage.restore.RestorableFile> multiChunkFiles = null;
    
    /**
     * Zip chunks containing several small files.
     */
    @org.jetbrains.annotations.NotNull()
    public final java.util.Collection<org.calyxos.backup.storage.restore.RestorableChunk> getZipChunks() {
        return null;
    }
    
    /**
     * Chunks that contains exactly one single file.
     */
    @org.jetbrains.annotations.NotNull()
    public final java.util.Collection<org.calyxos.backup.storage.restore.RestorableChunk> getSingleChunks() {
        return null;
    }
    
    /**
     * A map of chunk ID to chunks
     * where either the chunk is used by more than one file
     * or a file needs more than one chunk.
     */
    @org.jetbrains.annotations.NotNull()
    public final java.util.Map<java.lang.String, org.calyxos.backup.storage.restore.RestorableChunk> getMultiChunkMap() {
        return null;
    }
    
    /**
     * Files referenced in [multiChunkMap] sorted for restoring.
     */
    @org.jetbrains.annotations.NotNull()
    public final java.util.Collection<org.calyxos.backup.storage.restore.RestorableFile> getMultiChunkFiles() {
        return null;
    }
    
    public FileSplitterResult(@org.jetbrains.annotations.NotNull()
    java.util.Collection<org.calyxos.backup.storage.restore.RestorableChunk> zipChunks, @org.jetbrains.annotations.NotNull()
    java.util.Collection<org.calyxos.backup.storage.restore.RestorableChunk> singleChunks, @org.jetbrains.annotations.NotNull()
    java.util.Map<java.lang.String, org.calyxos.backup.storage.restore.RestorableChunk> multiChunkMap, @org.jetbrains.annotations.NotNull()
    java.util.Collection<org.calyxos.backup.storage.restore.RestorableFile> multiChunkFiles) {
        super();
    }
    
    /**
     * Zip chunks containing several small files.
     */
    @org.jetbrains.annotations.NotNull()
    public final java.util.Collection<org.calyxos.backup.storage.restore.RestorableChunk> component1() {
        return null;
    }
    
    /**
     * Chunks that contains exactly one single file.
     */
    @org.jetbrains.annotations.NotNull()
    public final java.util.Collection<org.calyxos.backup.storage.restore.RestorableChunk> component2() {
        return null;
    }
    
    /**
     * A map of chunk ID to chunks
     * where either the chunk is used by more than one file
     * or a file needs more than one chunk.
     */
    @org.jetbrains.annotations.NotNull()
    public final java.util.Map<java.lang.String, org.calyxos.backup.storage.restore.RestorableChunk> component3() {
        return null;
    }
    
    /**
     * Files referenced in [multiChunkMap] sorted for restoring.
     */
    @org.jetbrains.annotations.NotNull()
    public final java.util.Collection<org.calyxos.backup.storage.restore.RestorableFile> component4() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final org.calyxos.backup.storage.restore.FileSplitterResult copy(@org.jetbrains.annotations.NotNull()
    java.util.Collection<org.calyxos.backup.storage.restore.RestorableChunk> zipChunks, @org.jetbrains.annotations.NotNull()
    java.util.Collection<org.calyxos.backup.storage.restore.RestorableChunk> singleChunks, @org.jetbrains.annotations.NotNull()
    java.util.Map<java.lang.String, org.calyxos.backup.storage.restore.RestorableChunk> multiChunkMap, @org.jetbrains.annotations.NotNull()
    java.util.Collection<org.calyxos.backup.storage.restore.RestorableFile> multiChunkFiles) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
}