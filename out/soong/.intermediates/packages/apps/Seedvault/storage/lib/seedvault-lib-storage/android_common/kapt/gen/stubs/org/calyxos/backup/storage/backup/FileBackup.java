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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000X\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\b\u0000\u0018\u0000 \u001c2\u00020\u0001:\u0002\u001c\u001dB-\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u00a2\u0006\u0002\u0010\fJ(\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u00102\u0016\u0010\u0011\u001a\u0012\u0012\u0004\u0012\u00020\u00130\u0012j\b\u0012\u0004\u0012\u00020\u0013`\u0014H\u0002JA\u0010\u0015\u001a\u00020\u00162\f\u0010\u0017\u001a\b\u0012\u0004\u0012\u00020\u00100\u00182\u0016\u0010\u0011\u001a\u0012\u0012\u0004\u0012\u00020\u00130\u0012j\b\u0012\u0004\u0012\u00020\u0013`\u00142\b\u0010\u0019\u001a\u0004\u0018\u00010\u001aH\u0086@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u001bR\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lorg/calyxos/backup/storage/backup/FileBackup;", "", "contentResolver", "Landroid/content/ContentResolver;", "hasMediaAccessPerm", "", "filesCache", "Lorg/calyxos/backup/storage/db/FilesCache;", "chunker", "Lorg/calyxos/backup/storage/backup/Chunker;", "chunkWriter", "Lorg/calyxos/backup/storage/backup/ChunkWriter;", "(Landroid/content/ContentResolver;ZLorg/calyxos/backup/storage/db/FilesCache;Lorg/calyxos/backup/storage/backup/Chunker;Lorg/calyxos/backup/storage/backup/ChunkWriter;)V", "backupFile", "Lorg/calyxos/backup/storage/backup/FileBackup$FileBackupResult;", "file", "Lorg/calyxos/backup/storage/content/ContentFile;", "availableChunkIds", "Ljava/util/HashSet;", "", "Lkotlin/collections/HashSet;", "backupFiles", "Lorg/calyxos/backup/storage/backup/BackupResult;", "files", "", "backupObserver", "Lorg/calyxos/backup/storage/api/BackupObserver;", "(Ljava/util/List;Ljava/util/HashSet;Lorg/calyxos/backup/storage/api/BackupObserver;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "Companion", "FileBackupResult"})
public final class FileBackup {
    private final android.content.ContentResolver contentResolver = null;
    private final boolean hasMediaAccessPerm = false;
    private final org.calyxos.backup.storage.db.FilesCache filesCache = null;
    private final org.calyxos.backup.storage.backup.Chunker chunker = null;
    private final org.calyxos.backup.storage.backup.ChunkWriter chunkWriter = null;
    private static final java.lang.String TAG = "FileBackup";
    @org.jetbrains.annotations.NotNull()
    public static final org.calyxos.backup.storage.backup.FileBackup.Companion Companion = null;
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Object backupFiles(@org.jetbrains.annotations.NotNull()
    java.util.List<? extends org.calyxos.backup.storage.content.ContentFile> files, @org.jetbrains.annotations.NotNull()
    java.util.HashSet<java.lang.String> availableChunkIds, @org.jetbrains.annotations.Nullable()
    org.calyxos.backup.storage.api.BackupObserver backupObserver, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super org.calyxos.backup.storage.backup.BackupResult> p3) {
        return null;
    }
    
    private final org.calyxos.backup.storage.backup.FileBackup.FileBackupResult backupFile(org.calyxos.backup.storage.content.ContentFile file, java.util.HashSet<java.lang.String> availableChunkIds) {
        return null;
    }
    
    public FileBackup(@org.jetbrains.annotations.NotNull()
    android.content.ContentResolver contentResolver, boolean hasMediaAccessPerm, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.db.FilesCache filesCache, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.backup.Chunker chunker, @org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.backup.ChunkWriter chunkWriter) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010 \n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\t\n\u0000\n\u0002\u0010\u000b\n\u0002\b\t\b\u0002\u0018\u00002\u00020\u0001B+\u0012\f\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u00a2\u0006\u0002\u0010\u000bR\u0011\u0010\u0007\u001a\u00020\b\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\rR\u0017\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000e\u0010\u000fR\u0011\u0010\t\u001a\u00020\n\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0010\u0010\u0011R\u0011\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\u0013"}, d2 = {"Lorg/calyxos/backup/storage/backup/FileBackup$FileBackupResult;", "", "chunkIds", "", "", "savedChunks", "", "bytesWritten", "", "hasChanged", "", "(Ljava/util/List;IJZ)V", "getBytesWritten", "()J", "getChunkIds", "()Ljava/util/List;", "getHasChanged", "()Z", "getSavedChunks", "()I"})
    static final class FileBackupResult {
        @org.jetbrains.annotations.NotNull()
        private final java.util.List<java.lang.String> chunkIds = null;
        private final int savedChunks = 0;
        private final long bytesWritten = 0L;
        private final boolean hasChanged = false;
        
        @org.jetbrains.annotations.NotNull()
        public final java.util.List<java.lang.String> getChunkIds() {
            return null;
        }
        
        public final int getSavedChunks() {
            return 0;
        }
        
        public final long getBytesWritten() {
            return 0L;
        }
        
        public final boolean getHasChanged() {
            return false;
        }
        
        public FileBackupResult(@org.jetbrains.annotations.NotNull()
        java.util.List<java.lang.String> chunkIds, int savedChunks, long bytesWritten, boolean hasChanged) {
            super();
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lorg/calyxos/backup/storage/backup/FileBackup$Companion;", "", "()V", "TAG", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}