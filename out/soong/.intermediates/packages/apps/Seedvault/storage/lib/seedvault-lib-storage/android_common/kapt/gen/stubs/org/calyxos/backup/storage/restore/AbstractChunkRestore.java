package org.calyxos.backup.storage.restore;

import org.calyxos.backup.storage.api.RestoreObserver;
import org.calyxos.backup.storage.api.StoragePlugin;
import org.calyxos.backup.storage.api.StoredSnapshot;
import org.calyxos.backup.storage.crypto.StreamCrypto;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.security.GeneralSecurityException;

@kotlin.Suppress(names = {"BlockingMethodInNonBlockingContext"})
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000l\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0012\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\t\n\u0000\b \u0018\u00002\u00020\u0001B%\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJM\u0010\u000b\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\u00122\"\u0010\u0013\u001a\u001e\b\u0001\u0012\u0004\u0012\u00020\u0015\u0012\n\u0012\b\u0012\u0004\u0012\u00020\f0\u0016\u0012\u0006\u0012\u0004\u0018\u00010\u00010\u0014H\u0084@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0017J^\u0010\u0018\u001a\u00020\f2\u0006\u0010\u0019\u001a\u00020\u001a2\b\u0010\u001b\u001a\u0004\u0018\u00010\u001c2\u0006\u0010\u001d\u001a\u00020\u001221\u0010\u001e\u001a-\b\u0001\u0012\u0013\u0012\u00110\u001f\u00a2\u0006\f\b \u0012\b\b!\u0012\u0004\b\b(\"\u0012\n\u0012\b\u0012\u0004\u0012\u00020#0\u0016\u0012\u0006\u0012\u0004\u0018\u00010\u00010\u0014H\u0084@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010$R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lorg/calyxos/backup/storage/restore/AbstractChunkRestore;", "", "storagePlugin", "Lorg/calyxos/backup/storage/api/StoragePlugin;", "fileRestore", "Lorg/calyxos/backup/storage/restore/FileRestore;", "streamCrypto", "Lorg/calyxos/backup/storage/crypto/StreamCrypto;", "streamKey", "", "(Lorg/calyxos/backup/storage/api/StoragePlugin;Lorg/calyxos/backup/storage/restore/FileRestore;Lorg/calyxos/backup/storage/crypto/StreamCrypto;[B)V", "getAndDecryptChunk", "", "version", "", "storedSnapshot", "Lorg/calyxos/backup/storage/api/StoredSnapshot;", "chunkId", "", "streamReader", "Lkotlin/Function2;", "Ljava/io/InputStream;", "Lkotlin/coroutines/Continuation;", "(ILorg/calyxos/backup/storage/api/StoredSnapshot;Ljava/lang/String;Lkotlin/jvm/functions/Function2;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "restoreFile", "file", "Lorg/calyxos/backup/storage/restore/RestorableFile;", "observer", "Lorg/calyxos/backup/storage/api/RestoreObserver;", "tag", "streamWriter", "Ljava/io/OutputStream;", "Lkotlin/ParameterName;", "name", "outputStream", "", "(Lorg/calyxos/backup/storage/restore/RestorableFile;Lorg/calyxos/backup/storage/api/RestoreObserver;Ljava/lang/String;Lkotlin/jvm/functions/Function2;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;"})
public abstract class AbstractChunkRestore {
    private final org.calyxos.backup.storage.api.StoragePlugin storagePlugin = null;
    private final org.calyxos.backup.storage.restore.FileRestore fileRestore = null;
    private final org.calyxos.backup.storage.crypto.StreamCrypto streamCrypto = null;
    private final byte[] streamKey = null;
    
    @org.jetbrains.annotations.Nullable()
    protected final java.lang.Object getAndDecryptChunk(int version, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.StoredSnapshot storedSnapshot, @org.jetbrains.annotations.NotNull()
    java.lang.String chunkId, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function2<? super java.io.InputStream, ? super kotlin.coroutines.Continuation<? super kotlin.Unit>, ? extends java.lang.Object> streamReader, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p4) {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    protected final java.lang.Object restoreFile(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.restore.RestorableFile file, @org.jetbrains.annotations.Nullable()
    org.calyxos.backup.storage.api.RestoreObserver observer, @org.jetbrains.annotations.NotNull()
    java.lang.String tag, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function2<? super java.io.OutputStream, ? super kotlin.coroutines.Continuation<? super java.lang.Long>, ? extends java.lang.Object> streamWriter, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p4) {
        return null;
    }
    
    public AbstractChunkRestore(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.StoragePlugin storagePlugin, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.restore.FileRestore fileRestore, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.crypto.StreamCrypto streamCrypto, @org.jetbrains.annotations.NotNull()
    byte[] streamKey) {
        super();
    }
}