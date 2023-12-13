package org.calyxos.backup.storage.plugin;

import com.google.protobuf.InvalidProtocolBufferException;
import org.calyxos.backup.storage.api.StoragePlugin;
import org.calyxos.backup.storage.api.StoredSnapshot;
import org.calyxos.backup.storage.backup.BackupSnapshot;
import org.calyxos.backup.storage.crypto.StreamCrypto;
import java.io.IOException;
import java.security.GeneralSecurityException;

@kotlin.Suppress(names = {"BlockingMethodInNonBlockingContext"})
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0012\n\u0000\n\u0002\u0018\u0002\n\u0000\b\u0000\u0018\u00002\u00020\u0001B\u0017\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\b\b\u0002\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J!\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\fH\u0086@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\rR\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lorg/calyxos/backup/storage/plugin/SnapshotRetriever;", "", "storagePlugin", "Lorg/calyxos/backup/storage/api/StoragePlugin;", "streamCrypto", "Lorg/calyxos/backup/storage/crypto/StreamCrypto;", "(Lorg/calyxos/backup/storage/api/StoragePlugin;Lorg/calyxos/backup/storage/crypto/StreamCrypto;)V", "getSnapshot", "Lorg/calyxos/backup/storage/backup/BackupSnapshot;", "streamKey", "", "storedSnapshot", "Lorg/calyxos/backup/storage/api/StoredSnapshot;", "([BLorg/calyxos/backup/storage/api/StoredSnapshot;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;"})
public final class SnapshotRetriever {
    private final org.calyxos.backup.storage.api.StoragePlugin storagePlugin = null;
    private final org.calyxos.backup.storage.crypto.StreamCrypto streamCrypto = null;
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Object getSnapshot(@org.jetbrains.annotations.NotNull()
    byte[] streamKey, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.StoredSnapshot storedSnapshot, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super org.calyxos.backup.storage.backup.BackupSnapshot> p2) {
        return null;
    }
    
    public SnapshotRetriever(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.StoragePlugin storagePlugin, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.crypto.StreamCrypto streamCrypto) {
        super();
    }
}