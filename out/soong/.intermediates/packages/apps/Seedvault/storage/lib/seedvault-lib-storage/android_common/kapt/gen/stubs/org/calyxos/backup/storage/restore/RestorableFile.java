package org.calyxos.backup.storage.restore;

import org.calyxos.backup.storage.api.BackupFile;
import org.calyxos.backup.storage.backup.BackupDocumentFile;
import org.calyxos.backup.storage.backup.BackupMediaFile;
import org.calyxos.backup.storage.backup.BackupSnapshot;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000B\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010 \n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0010\b\n\u0002\b\b\n\u0002\u0010\t\n\u0002\b\u0013\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u0000\n\u0002\b\u0002\b\u0080\b\u0018\u00002\u00020\u0001B\u000f\b\u0016\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004B\u000f\b\u0016\u0012\u0006\u0010\u0002\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006B\u0019\u0012\b\u0010\u0007\u001a\u0004\u0018\u00010\u0003\u0012\b\u0010\b\u001a\u0004\u0018\u00010\u0005\u00a2\u0006\u0002\u0010\tJ\u000b\u0010)\u001a\u0004\u0018\u00010\u0003H\u00c6\u0003J\u000b\u0010*\u001a\u0004\u0018\u00010\u0005H\u00c6\u0003J!\u0010+\u001a\u00020\u00002\n\b\u0002\u0010\u0007\u001a\u0004\u0018\u00010\u00032\n\b\u0002\u0010\b\u001a\u0004\u0018\u00010\u0005H\u00c6\u0001J\u0013\u0010,\u001a\u00020-2\b\u0010.\u001a\u0004\u0018\u00010/H\u00d6\u0003J\t\u00100\u001a\u00020\u0010H\u00d6\u0001J\t\u00101\u001a\u00020\fH\u00d6\u0001R\u0017\u0010\n\u001a\b\u0012\u0004\u0012\u00020\f0\u000b8F\u00a2\u0006\u0006\u001a\u0004\b\r\u0010\u000eR\u0011\u0010\u000f\u001a\u00020\u00108F\u00a2\u0006\u0006\u001a\u0004\b\u0011\u0010\u0012R\u0011\u0010\u0013\u001a\u00020\f8F\u00a2\u0006\u0006\u001a\u0004\b\u0014\u0010\u0015R\u0013\u0010\b\u001a\u0004\u0018\u00010\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0016\u0010\u0017R\u0016\u0010\u0018\u001a\u0004\u0018\u00010\u00198VX\u0096\u0004\u00a2\u0006\u0006\u001a\u0004\b\u001a\u0010\u001bR\u0013\u0010\u0007\u001a\u0004\u0018\u00010\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001c\u0010\u001dR\u0011\u0010\u001e\u001a\u00020\f8F\u00a2\u0006\u0006\u001a\u0004\b\u001f\u0010\u0015R\u0014\u0010 \u001a\u00020\fX\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b!\u0010\u0015R\u0014\u0010\"\u001a\u00020\u00198VX\u0096\u0004\u00a2\u0006\u0006\u001a\u0004\b#\u0010$R\u0014\u0010%\u001a\u00020\f8VX\u0096\u0004\u00a2\u0006\u0006\u001a\u0004\b&\u0010\u0015R\u0011\u0010\'\u001a\u00020\u00108F\u00a2\u0006\u0006\u001a\u0004\b(\u0010\u0012"}, d2 = {"Lorg/calyxos/backup/storage/restore/RestorableFile;", "Lorg/calyxos/backup/storage/api/BackupFile;", "file", "Lorg/calyxos/backup/storage/backup/BackupMediaFile;", "(Lorg/calyxos/backup/storage/backup/BackupMediaFile;)V", "Lorg/calyxos/backup/storage/backup/BackupDocumentFile;", "(Lorg/calyxos/backup/storage/backup/BackupDocumentFile;)V", "mediaFile", "docFile", "(Lorg/calyxos/backup/storage/backup/BackupMediaFile;Lorg/calyxos/backup/storage/backup/BackupDocumentFile;)V", "chunkIds", "", "", "getChunkIds", "()Ljava/util/List;", "chunkIdsCount", "", "getChunkIdsCount", "()I", "dir", "getDir", "()Ljava/lang/String;", "getDocFile", "()Lorg/calyxos/backup/storage/backup/BackupDocumentFile;", "lastModified", "", "getLastModified", "()Ljava/lang/Long;", "getMediaFile", "()Lorg/calyxos/backup/storage/backup/BackupMediaFile;", "name", "getName", "path", "getPath", "size", "getSize", "()J", "volume", "getVolume", "zipIndex", "getZipIndex", "component1", "component2", "copy", "equals", "", "other", "", "hashCode", "toString"})
public final class RestorableFile implements org.calyxos.backup.storage.api.BackupFile {
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String path = null;
    @org.jetbrains.annotations.Nullable()
    private final org.calyxos.backup.storage.backup.BackupMediaFile mediaFile = null;
    @org.jetbrains.annotations.Nullable()
    private final org.calyxos.backup.storage.backup.BackupDocumentFile docFile = null;
    
    public final int getChunkIdsCount() {
        return 0;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<java.lang.String> getChunkIds() {
        return null;
    }
    
    public final int getZipIndex() {
        return 0;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getDir() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getName() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String getPath() {
        return null;
    }
    
    @java.lang.Override()
    public long getSize() {
        return 0L;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String getVolume() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Long getLastModified() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final org.calyxos.backup.storage.backup.BackupMediaFile getMediaFile() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final org.calyxos.backup.storage.backup.BackupDocumentFile getDocFile() {
        return null;
    }
    
    public RestorableFile(@org.jetbrains.annotations.Nullable()
    org.calyxos.backup.storage.backup.BackupMediaFile mediaFile, @org.jetbrains.annotations.Nullable()
    org.calyxos.backup.storage.backup.BackupDocumentFile docFile) {
        super();
    }
    
    public RestorableFile(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.backup.BackupMediaFile file) {
        super();
    }
    
    public RestorableFile(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.backup.BackupDocumentFile file) {
        super();
    }
    
    @org.jetbrains.annotations.Nullable()
    public final org.calyxos.backup.storage.backup.BackupMediaFile component1() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final org.calyxos.backup.storage.backup.BackupDocumentFile component2() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final org.calyxos.backup.storage.restore.RestorableFile copy(@org.jetbrains.annotations.Nullable()
    org.calyxos.backup.storage.backup.BackupMediaFile mediaFile, @org.jetbrains.annotations.Nullable()
    org.calyxos.backup.storage.backup.BackupDocumentFile docFile) {
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