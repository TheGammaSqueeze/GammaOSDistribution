package org.calyxos.backup.storage.restore;

import android.util.Log;
import org.calyxos.backup.storage.api.RestoreObserver;
import org.calyxos.backup.storage.api.StoragePlugin;
import org.calyxos.backup.storage.api.StoredSnapshot;
import org.calyxos.backup.storage.crypto.StreamCrypto;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.zip.ZipInputStream;

@kotlin.Suppress(names = {"BlockingMethodInNonBlockingContext"})
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000^\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0012\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u001e\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\b\u0000\u0018\u00002\u00020\u0001B%\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJ9\u0010\u000b\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\f2\u0006\u0010\u000e\u001a\u00020\u000f2\f\u0010\u0010\u001a\b\u0012\u0004\u0012\u00020\u00120\u00112\b\u0010\u0013\u001a\u0004\u0018\u00010\u0014H\u0086@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0015J+\u0010\u0016\u001a\u00020\f2\u0006\u0010\u0017\u001a\u00020\u00122\u0006\u0010\u0018\u001a\u00020\u00192\b\u0010\u0013\u001a\u0004\u0018\u00010\u0014H\u0082@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u001aJ+\u0010\u001b\u001a\u00020\u001c2\u0006\u0010\u001d\u001a\u00020\u001e2\u0006\u0010\u001f\u001a\u00020 2\b\u0010\u0013\u001a\u0004\u0018\u00010\u0014H\u0082@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010!\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lorg/calyxos/backup/storage/restore/ZipChunkRestore;", "Lorg/calyxos/backup/storage/restore/AbstractChunkRestore;", "storagePlugin", "Lorg/calyxos/backup/storage/api/StoragePlugin;", "fileRestore", "Lorg/calyxos/backup/storage/restore/FileRestore;", "streamCrypto", "Lorg/calyxos/backup/storage/crypto/StreamCrypto;", "streamKey", "", "(Lorg/calyxos/backup/storage/api/StoragePlugin;Lorg/calyxos/backup/storage/restore/FileRestore;Lorg/calyxos/backup/storage/crypto/StreamCrypto;[B)V", "restore", "", "version", "storedSnapshot", "Lorg/calyxos/backup/storage/api/StoredSnapshot;", "zipChunks", "", "Lorg/calyxos/backup/storage/restore/RestorableChunk;", "observer", "Lorg/calyxos/backup/storage/api/RestoreObserver;", "(ILorg/calyxos/backup/storage/api/StoredSnapshot;Ljava/util/Collection;Lorg/calyxos/backup/storage/api/RestoreObserver;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "restoreZipChunk", "zipChunk", "decryptedStream", "Ljava/io/InputStream;", "(Lorg/calyxos/backup/storage/restore/RestorableChunk;Ljava/io/InputStream;Lorg/calyxos/backup/storage/api/RestoreObserver;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "restoreZipEntry", "", "zip", "Ljava/util/zip/ZipInputStream;", "file", "Lorg/calyxos/backup/storage/restore/RestorableFile;", "(Ljava/util/zip/ZipInputStream;Lorg/calyxos/backup/storage/restore/RestorableFile;Lorg/calyxos/backup/storage/api/RestoreObserver;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;"})
public final class ZipChunkRestore extends org.calyxos.backup.storage.restore.AbstractChunkRestore {
    
    /**
     * Assumes that files in [zipChunks] are sorted by zipIndex with no duplicate indices.
     */
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Object restore(int version, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.StoredSnapshot storedSnapshot, @org.jetbrains.annotations.NotNull()
    java.util.Collection<org.calyxos.backup.storage.restore.RestorableChunk> zipChunks, @org.jetbrains.annotations.Nullable()
    org.calyxos.backup.storage.api.RestoreObserver observer, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super java.lang.Integer> p4) {
        return null;
    }
    
    public ZipChunkRestore(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.StoragePlugin storagePlugin, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.restore.FileRestore fileRestore, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.crypto.StreamCrypto streamCrypto, @org.jetbrains.annotations.NotNull()
    byte[] streamKey) {
        super(null, null, null, null);
    }
}