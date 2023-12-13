package org.calyxos.backup.storage.restore;

import android.content.Context;
import android.util.Log;
import org.calyxos.backup.storage.api.RestoreObserver;
import org.calyxos.backup.storage.api.StoragePlugin;
import org.calyxos.backup.storage.api.StoredSnapshot;
import org.calyxos.backup.storage.crypto.StreamCrypto;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.security.GeneralSecurityException;

@kotlin.Suppress(names = {"BlockingMethodInNonBlockingContext"})
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u008e\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0012\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0010$\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u001e\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\t\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\b\u0000\u0018\u00002\u00020\u0001B-\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u00a2\u0006\u0002\u0010\fJM\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u00142\"\u0010\u0015\u001a\u001e\b\u0001\u0012\u0004\u0012\u00020\u0017\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u000e0\u0018\u0012\u0006\u0012\u0004\u0018\u00010\u00190\u0016H\u0082@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u001aJ\u0010\u0010\u001b\u001a\u00020\u001c2\u0006\u0010\u0013\u001a\u00020\u0014H\u0002J\u0010\u0010\u001d\u001a\u00020\u001e2\u0006\u0010\u0013\u001a\u00020\u0014H\u0002J\u0010\u0010\u001f\u001a\u00020\u000e2\u0006\u0010\u0013\u001a\u00020\u0014H\u0002JM\u0010 \u001a\u00020\u00102\u0006\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\u00122\u0012\u0010!\u001a\u000e\u0012\u0004\u0012\u00020\u0014\u0012\u0004\u0012\u00020#0\"2\f\u0010$\u001a\b\u0012\u0004\u0012\u00020&0%2\b\u0010\'\u001a\u0004\u0018\u00010(H\u0086@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010)JE\u0010*\u001a\u00020+2\u0006\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\u00122\u0006\u0010,\u001a\u00020&2\u0012\u0010!\u001a\u000e\u0012\u0004\u0012\u00020\u0014\u0012\u0004\u0012\u00020#0\"2\u0006\u0010-\u001a\u00020.H\u0082@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010/R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lorg/calyxos/backup/storage/restore/MultiChunkRestore;", "Lorg/calyxos/backup/storage/restore/AbstractChunkRestore;", "context", "Landroid/content/Context;", "storagePlugin", "Lorg/calyxos/backup/storage/api/StoragePlugin;", "fileRestore", "Lorg/calyxos/backup/storage/restore/FileRestore;", "streamCrypto", "Lorg/calyxos/backup/storage/crypto/StreamCrypto;", "streamKey", "", "(Landroid/content/Context;Lorg/calyxos/backup/storage/api/StoragePlugin;Lorg/calyxos/backup/storage/restore/FileRestore;Lorg/calyxos/backup/storage/crypto/StreamCrypto;[B)V", "getAndCacheChunk", "", "version", "", "storedSnapshot", "Lorg/calyxos/backup/storage/api/StoredSnapshot;", "chunkId", "", "streamReader", "Lkotlin/Function2;", "Ljava/io/InputStream;", "Lkotlin/coroutines/Continuation;", "", "(ILorg/calyxos/backup/storage/api/StoredSnapshot;Ljava/lang/String;Lkotlin/jvm/functions/Function2;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "getChunkCacheFile", "Ljava/io/File;", "isCached", "", "removeCachedChunk", "restore", "chunkMap", "", "Lorg/calyxos/backup/storage/restore/RestorableChunk;", "files", "", "Lorg/calyxos/backup/storage/restore/RestorableFile;", "observer", "Lorg/calyxos/backup/storage/api/RestoreObserver;", "(ILorg/calyxos/backup/storage/api/StoredSnapshot;Ljava/util/Map;Ljava/util/Collection;Lorg/calyxos/backup/storage/api/RestoreObserver;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "writeChunks", "", "file", "outputStream", "Ljava/io/OutputStream;", "(ILorg/calyxos/backup/storage/api/StoredSnapshot;Lorg/calyxos/backup/storage/restore/RestorableFile;Ljava/util/Map;Ljava/io/OutputStream;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;"})
public final class MultiChunkRestore extends org.calyxos.backup.storage.restore.AbstractChunkRestore {
    private final android.content.Context context = null;
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Object restore(int version, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.StoredSnapshot storedSnapshot, @org.jetbrains.annotations.NotNull()
    java.util.Map<java.lang.String, org.calyxos.backup.storage.restore.RestorableChunk> chunkMap, @org.jetbrains.annotations.NotNull()
    java.util.Collection<org.calyxos.backup.storage.restore.RestorableFile> files, @org.jetbrains.annotations.Nullable()
    org.calyxos.backup.storage.api.RestoreObserver observer, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super java.lang.Integer> p5) {
        return null;
    }
    
    private final boolean isCached(java.lang.String chunkId) {
        return false;
    }
    
    private final void removeCachedChunk(java.lang.String chunkId) {
    }
    
    private final java.io.File getChunkCacheFile(java.lang.String chunkId) {
        return null;
    }
    
    public MultiChunkRestore(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.StoragePlugin storagePlugin, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.restore.FileRestore fileRestore, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.crypto.StreamCrypto streamCrypto, @org.jetbrains.annotations.NotNull()
    byte[] streamKey) {
        super(null, null, null, null);
    }
}