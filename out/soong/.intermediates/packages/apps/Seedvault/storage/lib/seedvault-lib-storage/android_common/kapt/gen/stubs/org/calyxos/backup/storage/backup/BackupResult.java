package org.calyxos.backup.storage.backup;

import android.content.Context;
import android.os.Build;
import android.text.format.Formatter;
import android.util.Log;
import org.calyxos.backup.storage.api.BackupObserver;
import org.calyxos.backup.storage.api.StoragePlugin;
import org.calyxos.backup.storage.crypto.ChunkCrypto;
import org.calyxos.backup.storage.crypto.StreamCrypto;
import org.calyxos.backup.storage.db.Db;
import org.calyxos.backup.storage.scanner.FileScanner;
import org.calyxos.backup.storage.scanner.FileScannerResult;
import java.io.IOException;
import java.security.GeneralSecurityException;
import kotlin.time.Duration;
import kotlin.time.ExperimentalTime;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000&\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\"\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\b\b\u0000\u0018\u00002\u00020\u0001B/\u0012\f\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u0012\f\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00070\u0006\u0012\f\u0010\b\u001a\b\u0012\u0004\u0012\u00020\t0\u0006\u00a2\u0006\u0002\u0010\nJ\u0011\u0010\u0010\u001a\u00020\u00002\u0006\u0010\u0011\u001a\u00020\u0000H\u0086\u0002R\u0017\u0010\b\u001a\b\u0012\u0004\u0012\u00020\t0\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\fR\u0017\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00070\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\r\u0010\fR\u0017\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000e\u0010\u000f"}, d2 = {"Lorg/calyxos/backup/storage/backup/BackupResult;", "", "chunkIds", "", "", "backupMediaFiles", "", "Lorg/calyxos/backup/storage/backup/BackupMediaFile;", "backupDocumentFiles", "Lorg/calyxos/backup/storage/backup/BackupDocumentFile;", "(Ljava/util/Set;Ljava/util/List;Ljava/util/List;)V", "getBackupDocumentFiles", "()Ljava/util/List;", "getBackupMediaFiles", "getChunkIds", "()Ljava/util/Set;", "plus", "other"})
public final class BackupResult {
    @org.jetbrains.annotations.NotNull()
    private final java.util.Set<java.lang.String> chunkIds = null;
    @org.jetbrains.annotations.NotNull()
    private final java.util.List<org.calyxos.backup.storage.backup.BackupMediaFile> backupMediaFiles = null;
    @org.jetbrains.annotations.NotNull()
    private final java.util.List<org.calyxos.backup.storage.backup.BackupDocumentFile> backupDocumentFiles = null;
    
    @org.jetbrains.annotations.NotNull()
    public final org.calyxos.backup.storage.backup.BackupResult plus(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.backup.BackupResult other) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.Set<java.lang.String> getChunkIds() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<org.calyxos.backup.storage.backup.BackupMediaFile> getBackupMediaFiles() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<org.calyxos.backup.storage.backup.BackupDocumentFile> getBackupDocumentFiles() {
        return null;
    }
    
    public BackupResult(@org.jetbrains.annotations.NotNull()
    java.util.Set<java.lang.String> chunkIds, @org.jetbrains.annotations.NotNull()
    java.util.List<org.calyxos.backup.storage.backup.BackupMediaFile> backupMediaFiles, @org.jetbrains.annotations.NotNull()
    java.util.List<org.calyxos.backup.storage.backup.BackupDocumentFile> backupDocumentFiles) {
        super();
    }
}