package org.calyxos.backup.storage.api;

import org.calyxos.backup.storage.backup.BackupSnapshot;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000&\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\t\n\u0002\b\t\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\b\u0086\b\u0018\u00002\u00020\u0001B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\t\u0010\u000b\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\f\u001a\u00020\u0005H\u00c6\u0003J\u001d\u0010\r\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u0005H\u00c6\u0001J\u0013\u0010\u000e\u001a\u00020\u000f2\b\u0010\u0010\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u0011\u001a\u00020\u0012H\u00d6\u0001J\t\u0010\u0013\u001a\u00020\u0003H\u00d6\u0001R\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0007\u0010\bR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\t\u0010\n"}, d2 = {"Lorg/calyxos/backup/storage/api/StoredSnapshot;", "", "userId", "", "timestamp", "", "(Ljava/lang/String;J)V", "getTimestamp", "()J", "getUserId", "()Ljava/lang/String;", "component1", "component2", "copy", "equals", "", "other", "hashCode", "", "toString"})
public final class StoredSnapshot {
    
    /**
     * The unique ID of the current device/user combination chosen by the [StoragePlugin].
     */
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String userId = null;
    
    /**
     * The timestamp identifying a snapshot of the [userId].
     */
    private final long timestamp = 0L;
    
    /**
     * The unique ID of the current device/user combination chosen by the [StoragePlugin].
     */
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getUserId() {
        return null;
    }
    
    /**
     * The timestamp identifying a snapshot of the [userId].
     */
    public final long getTimestamp() {
        return 0L;
    }
    
    public StoredSnapshot(@org.jetbrains.annotations.NotNull()
    java.lang.String userId, long timestamp) {
        super();
    }
    
    /**
     * The unique ID of the current device/user combination chosen by the [StoragePlugin].
     */
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String component1() {
        return null;
    }
    
    /**
     * The timestamp identifying a snapshot of the [userId].
     */
    public final long component2() {
        return 0L;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final org.calyxos.backup.storage.api.StoredSnapshot copy(@org.jetbrains.annotations.NotNull()
    java.lang.String userId, long timestamp) {
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