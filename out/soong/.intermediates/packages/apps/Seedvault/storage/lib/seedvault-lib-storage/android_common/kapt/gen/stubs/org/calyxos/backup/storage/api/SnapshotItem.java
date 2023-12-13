package org.calyxos.backup.storage.api;

import org.calyxos.backup.storage.backup.BackupSnapshot;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00002\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\t\n\u0002\b\u0006\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\b\u0086\b\u0018\u00002\u00020\u0001B\u0017\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\b\u0010\u0004\u001a\u0004\u0018\u00010\u0005\u00a2\u0006\u0002\u0010\u0006J\t\u0010\u000f\u001a\u00020\u0003H\u00c6\u0003J\u000b\u0010\u0010\u001a\u0004\u0018\u00010\u0005H\u00c6\u0003J\u001f\u0010\u0011\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\n\b\u0002\u0010\u0004\u001a\u0004\u0018\u00010\u0005H\u00c6\u0001J\u0013\u0010\u0012\u001a\u00020\u00132\b\u0010\u0014\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u0015\u001a\u00020\u0016H\u00d6\u0001J\t\u0010\u0017\u001a\u00020\u0018H\u00d6\u0001R\u0013\u0010\u0004\u001a\u0004\u0018\u00010\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0007\u0010\bR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\t\u0010\nR\u0011\u0010\u000b\u001a\u00020\f8F\u00a2\u0006\u0006\u001a\u0004\b\r\u0010\u000e"}, d2 = {"Lorg/calyxos/backup/storage/api/SnapshotItem;", "", "storedSnapshot", "Lorg/calyxos/backup/storage/api/StoredSnapshot;", "snapshot", "Lorg/calyxos/backup/storage/backup/BackupSnapshot;", "(Lorg/calyxos/backup/storage/api/StoredSnapshot;Lorg/calyxos/backup/storage/backup/BackupSnapshot;)V", "getSnapshot", "()Lorg/calyxos/backup/storage/backup/BackupSnapshot;", "getStoredSnapshot", "()Lorg/calyxos/backup/storage/api/StoredSnapshot;", "time", "", "getTime", "()J", "component1", "component2", "copy", "equals", "", "other", "hashCode", "", "toString", ""})
public final class SnapshotItem {
    @org.jetbrains.annotations.NotNull()
    private final org.calyxos.backup.storage.api.StoredSnapshot storedSnapshot = null;
    @org.jetbrains.annotations.Nullable()
    private final org.calyxos.backup.storage.backup.BackupSnapshot snapshot = null;
    
    public final long getTime() {
        return 0L;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final org.calyxos.backup.storage.api.StoredSnapshot getStoredSnapshot() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final org.calyxos.backup.storage.backup.BackupSnapshot getSnapshot() {
        return null;
    }
    
    public SnapshotItem(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.StoredSnapshot storedSnapshot, @org.jetbrains.annotations.Nullable()
    org.calyxos.backup.storage.backup.BackupSnapshot snapshot) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public final org.calyxos.backup.storage.api.StoredSnapshot component1() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final org.calyxos.backup.storage.backup.BackupSnapshot component2() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final org.calyxos.backup.storage.api.SnapshotItem copy(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.StoredSnapshot storedSnapshot, @org.jetbrains.annotations.Nullable()
    org.calyxos.backup.storage.backup.BackupSnapshot snapshot) {
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