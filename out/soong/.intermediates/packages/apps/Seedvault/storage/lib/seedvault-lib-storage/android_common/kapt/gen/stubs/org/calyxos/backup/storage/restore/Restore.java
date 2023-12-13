package org.calyxos.backup.storage.restore;

import android.content.Context;
import android.util.Log;
import kotlinx.coroutines.flow.Flow;
import org.calyxos.backup.storage.api.RestoreObserver;
import org.calyxos.backup.storage.api.SnapshotItem;
import org.calyxos.backup.storage.api.SnapshotResult;
import org.calyxos.backup.storage.api.StoragePlugin;
import org.calyxos.backup.storage.api.StoredSnapshot;
import org.calyxos.backup.storage.backup.Backup;
import org.calyxos.backup.storage.backup.BackupSnapshot;
import org.calyxos.backup.storage.crypto.StreamCrypto;
import org.calyxos.backup.storage.plugin.SnapshotRetriever;
import java.io.IOException;
import java.io.InputStream;
import java.security.GeneralSecurityException;
import kotlin.time.ExperimentalTime;

@kotlin.Suppress(names = {"BlockingMethodInNonBlockingContext"})
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000l\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u0012\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\b\u0000\u0018\u00002\u00020\u0001B/\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\b\b\u0002\u0010\n\u001a\u00020\u000b\u00a2\u0006\u0002\u0010\fJ\f\u0010\"\u001a\b\u0012\u0004\u0012\u00020$0#J1\u0010%\u001a\u00020&2\u0006\u0010\'\u001a\u00020(2\n\b\u0002\u0010)\u001a\u0004\u0018\u00010*2\n\b\u0002\u0010+\u001a\u0004\u0018\u00010,H\u0086@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010-R\u001b\u0010\r\u001a\u00020\u000e8BX\u0082\u0084\u0002\u00a2\u0006\f\n\u0004\b\u0011\u0010\u0012\u001a\u0004\b\u000f\u0010\u0010R\u001b\u0010\u0013\u001a\u00020\u00148BX\u0082\u0084\u0002\u00a2\u0006\f\n\u0004\b\u0017\u0010\u0012\u001a\u0004\b\u0015\u0010\u0016R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001b\u0010\u0018\u001a\u00020\u00198BX\u0082\u0084\u0002\u00a2\u0006\f\n\u0004\b\u001c\u0010\u0012\u001a\u0004\b\u001a\u0010\u001bR\u001b\u0010\u001d\u001a\u00020\u001e8BX\u0082\u0084\u0002\u00a2\u0006\f\n\u0004\b!\u0010\u0012\u001a\u0004\b\u001f\u0010 \u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lorg/calyxos/backup/storage/restore/Restore;", "", "context", "Landroid/content/Context;", "storagePlugin", "Lorg/calyxos/backup/storage/api/StoragePlugin;", "snapshotRetriever", "Lorg/calyxos/backup/storage/plugin/SnapshotRetriever;", "fileRestore", "Lorg/calyxos/backup/storage/restore/FileRestore;", "streamCrypto", "Lorg/calyxos/backup/storage/crypto/StreamCrypto;", "(Landroid/content/Context;Lorg/calyxos/backup/storage/api/StoragePlugin;Lorg/calyxos/backup/storage/plugin/SnapshotRetriever;Lorg/calyxos/backup/storage/restore/FileRestore;Lorg/calyxos/backup/storage/crypto/StreamCrypto;)V", "multiChunkRestore", "Lorg/calyxos/backup/storage/restore/MultiChunkRestore;", "getMultiChunkRestore", "()Lorg/calyxos/backup/storage/restore/MultiChunkRestore;", "multiChunkRestore$delegate", "Lkotlin/Lazy;", "singleChunkRestore", "Lorg/calyxos/backup/storage/restore/SingleChunkRestore;", "getSingleChunkRestore", "()Lorg/calyxos/backup/storage/restore/SingleChunkRestore;", "singleChunkRestore$delegate", "streamKey", "", "getStreamKey", "()[B", "streamKey$delegate", "zipChunkRestore", "Lorg/calyxos/backup/storage/restore/ZipChunkRestore;", "getZipChunkRestore", "()Lorg/calyxos/backup/storage/restore/ZipChunkRestore;", "zipChunkRestore$delegate", "getBackupSnapshots", "Lkotlinx/coroutines/flow/Flow;", "Lorg/calyxos/backup/storage/api/SnapshotResult;", "restoreBackupSnapshot", "", "storedSnapshot", "Lorg/calyxos/backup/storage/api/StoredSnapshot;", "optionalSnapshot", "Lorg/calyxos/backup/storage/backup/BackupSnapshot;", "observer", "Lorg/calyxos/backup/storage/api/RestoreObserver;", "(Lorg/calyxos/backup/storage/api/StoredSnapshot;Lorg/calyxos/backup/storage/backup/BackupSnapshot;Lorg/calyxos/backup/storage/api/RestoreObserver;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;"})
public final class Restore {
    private final kotlin.Lazy streamKey$delegate = null;
    private final kotlin.Lazy zipChunkRestore$delegate = null;
    private final kotlin.Lazy singleChunkRestore$delegate = null;
    private final kotlin.Lazy multiChunkRestore$delegate = null;
    private final org.calyxos.backup.storage.api.StoragePlugin storagePlugin = null;
    private final org.calyxos.backup.storage.plugin.SnapshotRetriever snapshotRetriever = null;
    
    private final byte[] getStreamKey() {
        return null;
    }
    
    private final org.calyxos.backup.storage.restore.ZipChunkRestore getZipChunkRestore() {
        return null;
    }
    
    private final org.calyxos.backup.storage.restore.SingleChunkRestore getSingleChunkRestore() {
        return null;
    }
    
    private final org.calyxos.backup.storage.restore.MultiChunkRestore getMultiChunkRestore() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final kotlinx.coroutines.flow.Flow<org.calyxos.backup.storage.api.SnapshotResult> getBackupSnapshots() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    @kotlin.OptIn(markerClass = {kotlin.time.ExperimentalTime.class})
    public final java.lang.Object restoreBackupSnapshot(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.StoredSnapshot storedSnapshot, @org.jetbrains.annotations.Nullable()
    org.calyxos.backup.storage.backup.BackupSnapshot optionalSnapshot, @org.jetbrains.annotations.Nullable()
    org.calyxos.backup.storage.api.RestoreObserver observer, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p3) {
        return null;
    }
    
    public Restore(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.StoragePlugin storagePlugin, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.plugin.SnapshotRetriever snapshotRetriever, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.restore.FileRestore fileRestore, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.crypto.StreamCrypto streamCrypto) {
        super();
    }
}