package org.calyxos.backup.storage.backup;

import android.content.ContentResolver;
import android.util.Log;
import org.calyxos.backup.storage.api.BackupObserver;
import org.calyxos.backup.storage.content.ContentFile;
import org.calyxos.backup.storage.content.DocFile;
import org.calyxos.backup.storage.content.MediaFile;
import org.calyxos.backup.storage.db.CachedFile;
import org.calyxos.backup.storage.db.FilesCache;
import java.io.IOException;
import java.security.GeneralSecurityException;

@kotlin.Suppress(names = {"BlockingMethodInNonBlockingContext"})
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000R\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\b\u0000\u0018\u0000 \u001c2\u00020\u0001:\u0002\u001c\u001dB%\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJA\u0010\u000b\u001a\u00020\f2\f\u0010\r\u001a\b\u0012\u0004\u0012\u00020\u000f0\u000e2\u0016\u0010\u0010\u001a\u0012\u0012\u0004\u0012\u00020\u00120\u0011j\b\u0012\u0004\u0012\u00020\u0012`\u00132\b\u0010\u0014\u001a\u0004\u0018\u00010\u0015H\u0086@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0016J\u001e\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u0006\u001a\u00020\u00072\f\u0010\u0019\u001a\b\u0012\u0004\u0012\u00020\u00120\u000eH\u0002J&\u0010\u001a\u001a\u0004\u0018\u00010\u00182\f\u0010\u001b\u001a\b\u0012\u0004\u0012\u00020\u000f0\u000e2\f\u0010\u0019\u001a\b\u0012\u0004\u0012\u00020\u00120\u000eH\u0002R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lorg/calyxos/backup/storage/backup/SmallFileBackup;", "", "contentResolver", "Landroid/content/ContentResolver;", "filesCache", "Lorg/calyxos/backup/storage/db/FilesCache;", "zipChunker", "Lorg/calyxos/backup/storage/backup/ZipChunker;", "hasMediaAccessPerm", "", "(Landroid/content/ContentResolver;Lorg/calyxos/backup/storage/db/FilesCache;Lorg/calyxos/backup/storage/backup/ZipChunker;Z)V", "backupFiles", "Lorg/calyxos/backup/storage/backup/BackupResult;", "files", "", "Lorg/calyxos/backup/storage/content/ContentFile;", "availableChunkIds", "Ljava/util/HashSet;", "", "Lkotlin/collections/HashSet;", "backupObserver", "Lorg/calyxos/backup/storage/api/BackupObserver;", "(Ljava/util/List;Ljava/util/HashSet;Lorg/calyxos/backup/storage/api/BackupObserver;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "finalizeAndReset", "Lorg/calyxos/backup/storage/backup/SmallFileBackup$SmallFileBackupResult;", "missingChunkIds", "makeZipChunk", "window", "Companion", "SmallFileBackupResult"})
public final class SmallFileBackup {
    private final android.content.ContentResolver contentResolver = null;
    private final org.calyxos.backup.storage.db.FilesCache filesCache = null;
    private final org.calyxos.backup.storage.backup.ZipChunker zipChunker = null;
    private final boolean hasMediaAccessPerm = false;
    private static final java.lang.String TAG = "SmallFileBackup";
    @org.jetbrains.annotations.NotNull()
    public static final org.calyxos.backup.storage.backup.SmallFileBackup.Companion Companion = null;
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Object backupFiles(@org.jetbrains.annotations.NotNull()
    java.util.List<? extends org.calyxos.backup.storage.content.ContentFile> files, @org.jetbrains.annotations.NotNull()
    java.util.HashSet<java.lang.String> availableChunkIds, @org.jetbrains.annotations.Nullable()
    org.calyxos.backup.storage.api.BackupObserver backupObserver, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super org.calyxos.backup.storage.backup.BackupResult> p3) {
        return null;
    }
    
    /**
     * Adds the first file of the given window to a [ZipChunk].
     *
     * @param window a list of exactly one or two [ContentFile]s.
     *
     * @return [SmallFileBackupResult] if the chunk is full
     * or the window contained only a single (last) file.
     * Returns null, if there's space in the zip chunk and the next file can be added.
     */
    private final org.calyxos.backup.storage.backup.SmallFileBackup.SmallFileBackupResult makeZipChunk(java.util.List<? extends org.calyxos.backup.storage.content.ContentFile> window, java.util.List<java.lang.String> missingChunkIds) {
        return null;
    }
    
    private final org.calyxos.backup.storage.backup.SmallFileBackup.SmallFileBackupResult finalizeAndReset(org.calyxos.backup.storage.backup.ZipChunker zipChunker, java.util.List<java.lang.String> missingChunkIds) {
        return null;
    }
    
    public SmallFileBackup(@org.jetbrains.annotations.NotNull()
    android.content.ContentResolver contentResolver, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.db.FilesCache filesCache, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.backup.ZipChunker zipChunker, boolean hasMediaAccessPerm) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000.\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\n\u0000\n\u0002\u0010\u000b\n\u0002\b\n\b\u0002\u0018\u00002\u00020\u0001B9\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\f\u0010\u0004\u001a\b\u0012\u0004\u0012\u00020\u00060\u0005\u0012\f\u0010\u0007\u001a\b\u0012\u0004\u0012\u00020\b0\u0005\u0012\u0006\u0010\t\u001a\u00020\n\u0012\u0006\u0010\u000b\u001a\u00020\f\u00a2\u0006\u0002\u0010\rR\u0017\u0010\u0007\u001a\b\u0012\u0004\u0012\u00020\b0\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000e\u0010\u000fR\u0017\u0010\u0004\u001a\b\u0012\u0004\u0012\u00020\u00060\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0010\u0010\u000fR\u0011\u0010\t\u001a\u00020\n\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0011\u0010\u0012R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0013\u0010\u0014R\u0011\u0010\u000b\u001a\u00020\f\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0015\u0010\u0016"}, d2 = {"Lorg/calyxos/backup/storage/backup/SmallFileBackup$SmallFileBackupResult;", "", "chunkId", "", "backupMediaFiles", "", "Lorg/calyxos/backup/storage/backup/BackupMediaFile;", "backupDocumentFiles", "Lorg/calyxos/backup/storage/backup/BackupDocumentFile;", "bytesWritten", "", "hasChanged", "", "(Ljava/lang/String;Ljava/util/List;Ljava/util/List;JZ)V", "getBackupDocumentFiles", "()Ljava/util/List;", "getBackupMediaFiles", "getBytesWritten", "()J", "getChunkId", "()Ljava/lang/String;", "getHasChanged", "()Z"})
    static final class SmallFileBackupResult {
        @org.jetbrains.annotations.NotNull()
        private final java.lang.String chunkId = null;
        @org.jetbrains.annotations.NotNull()
        private final java.util.List<org.calyxos.backup.storage.backup.BackupMediaFile> backupMediaFiles = null;
        @org.jetbrains.annotations.NotNull()
        private final java.util.List<org.calyxos.backup.storage.backup.BackupDocumentFile> backupDocumentFiles = null;
        private final long bytesWritten = 0L;
        private final boolean hasChanged = false;
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String getChunkId() {
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
        
        public final long getBytesWritten() {
            return 0L;
        }
        
        public final boolean getHasChanged() {
            return false;
        }
        
        public SmallFileBackupResult(@org.jetbrains.annotations.NotNull()
        java.lang.String chunkId, @org.jetbrains.annotations.NotNull()
        java.util.List<org.calyxos.backup.storage.backup.BackupMediaFile> backupMediaFiles, @org.jetbrains.annotations.NotNull()
        java.util.List<org.calyxos.backup.storage.backup.BackupDocumentFile> backupDocumentFiles, long bytesWritten, boolean hasChanged) {
            super();
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lorg/calyxos/backup/storage/backup/SmallFileBackup$Companion;", "", "()V", "TAG", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}