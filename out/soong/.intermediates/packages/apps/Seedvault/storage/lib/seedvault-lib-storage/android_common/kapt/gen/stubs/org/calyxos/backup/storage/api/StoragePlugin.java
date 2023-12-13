package org.calyxos.backup.storage.api;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.security.KeyStore;
import javax.crypto.SecretKey;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000B\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010 \n\u0002\u0010\u000e\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\n\u0002\b\b\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\bf\u0018\u00002\u00020\u0001J\u0019\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H\u00a6@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0006J\u001f\u0010\u0007\u001a\u00020\u00032\f\u0010\b\u001a\b\u0012\u0004\u0012\u00020\n0\tH\u00a6@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u000bJ\u0017\u0010\f\u001a\b\u0012\u0004\u0012\u00020\n0\tH\u00a6@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\rJ\u0019\u0010\u000e\u001a\u00020\u000f2\u0006\u0010\u0004\u001a\u00020\u0005H\u00a6@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0006J\u0010\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u0012\u001a\u00020\u0013H&J\u0017\u0010\u0014\u001a\b\u0012\u0004\u0012\u00020\u00050\tH\u00a6@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\rJ!\u0010\u0015\u001a\u00020\u000f2\u0006\u0010\u0016\u001a\u00020\u00052\u0006\u0010\u0017\u001a\u00020\nH\u00a6@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0018J\u0010\u0010\u0019\u001a\u00020\u00112\u0006\u0010\u0017\u001a\u00020\nH&J\u0017\u0010\u001a\u001a\b\u0012\u0004\u0012\u00020\u00050\tH\u00a6@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\rJ\b\u0010\u001b\u001a\u00020\u001cH&J\b\u0010\u001d\u001a\u00020\u001eH&\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lorg/calyxos/backup/storage/api/StoragePlugin;", "", "deleteBackupSnapshot", "", "storedSnapshot", "Lorg/calyxos/backup/storage/api/StoredSnapshot;", "(Lorg/calyxos/backup/storage/api/StoredSnapshot;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "deleteChunks", "chunkIds", "", "", "(Ljava/util/List;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "getAvailableChunkIds", "(Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "getBackupSnapshotInputStream", "Ljava/io/InputStream;", "getBackupSnapshotOutputStream", "Ljava/io/OutputStream;", "timestamp", "", "getBackupSnapshotsForRestore", "getChunkInputStream", "snapshot", "chunkId", "(Lorg/calyxos/backup/storage/api/StoredSnapshot;Ljava/lang/String;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "getChunkOutputStream", "getCurrentBackupSnapshots", "getMasterKey", "Ljavax/crypto/SecretKey;", "hasMasterKey", ""})
public abstract interface StoragePlugin {
    
    /**
     * Called before starting a backup run to ensure that all cached chunks are still available.
     * Plugins should use this opportunity
     * to ensure they are ready to store a large number of chunks.
     */
    @org.jetbrains.annotations.Nullable()
    public abstract java.lang.Object getAvailableChunkIds(@org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super java.util.List<java.lang.String>> p0);
    
    /**
     * Returns a [SecretKey] for HmacSHA256, ideally stored in the [KeyStore].
     */
    @org.jetbrains.annotations.NotNull()
    public abstract javax.crypto.SecretKey getMasterKey();
    
    /**
     * Returns true if the key for [getMasterKey] exists, false otherwise.
     */
    public abstract boolean hasMasterKey();
    
    @org.jetbrains.annotations.NotNull()
    public abstract java.io.OutputStream getChunkOutputStream(@org.jetbrains.annotations.NotNull()
    java.lang.String chunkId) throws java.io.IOException;
    
    @org.jetbrains.annotations.NotNull()
    public abstract java.io.OutputStream getBackupSnapshotOutputStream(long timestamp) throws java.io.IOException;
    
    /**
     * Returns *all* [StoredSnapshot]s that are available on storage
     * independent of user ID and whether they can be decrypted
     * with the key returned by [getMasterKey].
     */
    @org.jetbrains.annotations.Nullable()
    public abstract java.lang.Object getBackupSnapshotsForRestore(@org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super java.util.List<org.calyxos.backup.storage.api.StoredSnapshot>> p0);
    
    @org.jetbrains.annotations.Nullable()
    public abstract java.lang.Object getBackupSnapshotInputStream(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.StoredSnapshot storedSnapshot, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super java.io.InputStream> p1);
    
    @org.jetbrains.annotations.Nullable()
    public abstract java.lang.Object getChunkInputStream(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.StoredSnapshot snapshot, @org.jetbrains.annotations.NotNull()
    java.lang.String chunkId, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super java.io.InputStream> p2);
    
    /**
     * Returns [StoredSnapshot]s for the currently active user ID.
     */
    @org.jetbrains.annotations.Nullable()
    public abstract java.lang.Object getCurrentBackupSnapshots(@org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super java.util.List<org.calyxos.backup.storage.api.StoredSnapshot>> p0);
    
    /**
     * Deletes the given [StoredSnapshot].
     */
    @org.jetbrains.annotations.Nullable()
    public abstract java.lang.Object deleteBackupSnapshot(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.StoredSnapshot storedSnapshot, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p1);
    
    /**
     * Deletes the given chunks of the *current* user ID only.
     */
    @org.jetbrains.annotations.Nullable()
    public abstract java.lang.Object deleteChunks(@org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> chunkIds, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p1);
}