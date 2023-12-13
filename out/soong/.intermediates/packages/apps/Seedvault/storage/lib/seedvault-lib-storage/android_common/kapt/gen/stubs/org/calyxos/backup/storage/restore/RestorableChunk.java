package org.calyxos.backup.storage.restore;

import org.calyxos.backup.storage.api.BackupFile;
import org.calyxos.backup.storage.backup.BackupDocumentFile;
import org.calyxos.backup.storage.backup.BackupMediaFile;
import org.calyxos.backup.storage.backup.BackupSnapshot;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000B\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\b\n\u0000\b\u0080\b\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u000e\u0010\u0010\u001a\u00020\u000e2\u0006\u0010\u0011\u001a\u00020\u0012J\u000e\u0010\u0010\u001a\u00020\u000e2\u0006\u0010\u0011\u001a\u00020\u0013J\t\u0010\u0014\u001a\u00020\u0003H\u00c6\u0003J\u0013\u0010\u0015\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u0003H\u00c6\u0001J\u0013\u0010\u0016\u001a\u00020\u000e2\b\u0010\u0017\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\u0006\u0010\u0018\u001a\u00020\u0019J\t\u0010\u001a\u001a\u00020\u001bH\u00d6\u0001J\t\u0010\u001c\u001a\u00020\u0003H\u00d6\u0001R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0005\u0010\u0006R!\u0010\u0007\u001a\u0012\u0012\u0004\u0012\u00020\t0\bj\b\u0012\u0004\u0012\u00020\t`\n\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\fR\u0011\u0010\r\u001a\u00020\u000e8F\u00a2\u0006\u0006\u001a\u0004\b\r\u0010\u000f"}, d2 = {"Lorg/calyxos/backup/storage/restore/RestorableChunk;", "", "chunkId", "", "(Ljava/lang/String;)V", "getChunkId", "()Ljava/lang/String;", "files", "Ljava/util/ArrayList;", "Lorg/calyxos/backup/storage/restore/RestorableFile;", "Lkotlin/collections/ArrayList;", "getFiles", "()Ljava/util/ArrayList;", "isSingle", "", "()Z", "add", "file", "Lorg/calyxos/backup/storage/backup/BackupDocumentFile;", "Lorg/calyxos/backup/storage/backup/BackupMediaFile;", "component1", "copy", "equals", "other", "finalize", "", "hashCode", "", "toString"})
public final class RestorableChunk {
    @org.jetbrains.annotations.NotNull()
    private final java.util.ArrayList<org.calyxos.backup.storage.restore.RestorableFile> files = null;
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String chunkId = null;
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.ArrayList<org.calyxos.backup.storage.restore.RestorableFile> getFiles() {
        return null;
    }
    
    public final boolean isSingle() {
        return false;
    }
    
    public final boolean add(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.backup.BackupMediaFile file) {
        return false;
    }
    
    public final boolean add(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.backup.BackupDocumentFile file) {
        return false;
    }
    
    /**
     * Call this after the RestorableChunk is complete and **before** using it for restore.
     */
    public final void finalize() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getChunkId() {
        return null;
    }
    
    public RestorableChunk(@org.jetbrains.annotations.NotNull()
    java.lang.String chunkId) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String component1() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final org.calyxos.backup.storage.restore.RestorableChunk copy(@org.jetbrains.annotations.NotNull()
    java.lang.String chunkId) {
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