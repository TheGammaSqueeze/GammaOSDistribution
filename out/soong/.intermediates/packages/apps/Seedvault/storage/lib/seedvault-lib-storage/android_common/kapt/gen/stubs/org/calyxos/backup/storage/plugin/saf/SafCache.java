package org.calyxos.backup.storage.plugin.saf;

import androidx.documentfile.provider.DocumentFile;
import org.calyxos.backup.storage.api.StoredSnapshot;

/**
 * Accessing files and attributes via SAF is costly.
 * This class caches them to speed up SAF related operations.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\"\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\b\n\n\u0002\u0018\u0002\n\u0000\b\u0000\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002R\u001d\u0010\u0003\u001a\u000e\u0012\u0004\u0012\u00020\u0005\u0012\u0004\u0012\u00020\u00060\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0007\u0010\bR\u001c\u0010\t\u001a\u0004\u0018\u00010\u0006X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\n\u0010\u000b\"\u0004\b\f\u0010\rR\u001d\u0010\u000e\u001a\u000e\u0012\u0004\u0012\u00020\u0005\u0012\u0004\u0012\u00020\u00060\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\bR\u001d\u0010\u0010\u001a\u000e\u0012\u0004\u0012\u00020\u0011\u0012\u0004\u0012\u00020\u00060\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\b"}, d2 = {"Lorg/calyxos/backup/storage/plugin/saf/SafCache;", "", "()V", "backupChunkFolders", "Ljava/util/HashMap;", "", "Landroidx/documentfile/provider/DocumentFile;", "getBackupChunkFolders", "()Ljava/util/HashMap;", "currentFolder", "getCurrentFolder", "()Landroidx/documentfile/provider/DocumentFile;", "setCurrentFolder", "(Landroidx/documentfile/provider/DocumentFile;)V", "restoreChunkFolders", "getRestoreChunkFolders", "snapshotFiles", "Lorg/calyxos/backup/storage/api/StoredSnapshot;", "getSnapshotFiles"})
public final class SafCache {
    
    /**
     * The folder for the current user ID (here "${ANDROID_ID}.sv").
     */
    @org.jetbrains.annotations.Nullable()
    private androidx.documentfile.provider.DocumentFile currentFolder;
    
    /**
     * Folders containing chunks for backups of the current user ID.
     */
    @org.jetbrains.annotations.NotNull()
    private final java.util.HashMap<java.lang.String, androidx.documentfile.provider.DocumentFile> backupChunkFolders = null;
    
    /**
     * Folders containing chunks for restore of a chosen [StoredSnapshot].
     */
    @org.jetbrains.annotations.NotNull()
    private final java.util.HashMap<java.lang.String, androidx.documentfile.provider.DocumentFile> restoreChunkFolders = null;
    
    /**
     * Files for each [StoredSnapshot].
     */
    @org.jetbrains.annotations.NotNull()
    private final java.util.HashMap<org.calyxos.backup.storage.api.StoredSnapshot, androidx.documentfile.provider.DocumentFile> snapshotFiles = null;
    
    @org.jetbrains.annotations.Nullable()
    public final androidx.documentfile.provider.DocumentFile getCurrentFolder() {
        return null;
    }
    
    public final void setCurrentFolder(@org.jetbrains.annotations.Nullable()
    androidx.documentfile.provider.DocumentFile p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.HashMap<java.lang.String, androidx.documentfile.provider.DocumentFile> getBackupChunkFolders() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.HashMap<java.lang.String, androidx.documentfile.provider.DocumentFile> getRestoreChunkFolders() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.HashMap<org.calyxos.backup.storage.api.StoredSnapshot, androidx.documentfile.provider.DocumentFile> getSnapshotFiles() {
        return null;
    }
    
    public SafCache() {
        super();
    }
}