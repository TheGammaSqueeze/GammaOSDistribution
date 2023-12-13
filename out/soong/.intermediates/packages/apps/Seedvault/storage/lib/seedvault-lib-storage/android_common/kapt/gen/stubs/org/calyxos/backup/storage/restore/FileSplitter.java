package org.calyxos.backup.storage.restore;

import org.calyxos.backup.storage.api.BackupFile;
import org.calyxos.backup.storage.backup.BackupDocumentFile;
import org.calyxos.backup.storage.backup.BackupMediaFile;
import org.calyxos.backup.storage.backup.BackupSnapshot;

/**
 * Splits files to be restored into several types that can be restored in parallel.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000.\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0010$\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\b\u00c0\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\"\u0010\u0003\u001a\b\u0012\u0004\u0012\u00020\u00050\u00042\u0012\u0010\u0006\u001a\u000e\u0012\u0004\u0012\u00020\b\u0012\u0004\u0012\u00020\t0\u0007H\u0002J\u000e\u0010\n\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\r"}, d2 = {"Lorg/calyxos/backup/storage/restore/FileSplitter;", "", "()V", "getMultiFiles", "", "Lorg/calyxos/backup/storage/restore/RestorableFile;", "chunkMap", "", "", "Lorg/calyxos/backup/storage/restore/RestorableChunk;", "splitSnapshot", "Lorg/calyxos/backup/storage/restore/FileSplitterResult;", "snapshot", "Lorg/calyxos/backup/storage/backup/BackupSnapshot;"})
public final class FileSplitter {
    @org.jetbrains.annotations.NotNull()
    public static final org.calyxos.backup.storage.restore.FileSplitter INSTANCE = null;
    
    @org.jetbrains.annotations.NotNull()
    public final org.calyxos.backup.storage.restore.FileSplitterResult splitSnapshot(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.backup.BackupSnapshot snapshot) {
        return null;
    }
    
    private final java.util.List<org.calyxos.backup.storage.restore.RestorableFile> getMultiFiles(java.util.Map<java.lang.String, org.calyxos.backup.storage.restore.RestorableChunk> chunkMap) {
        return null;
    }
    
    private FileSplitter() {
        super();
    }
}