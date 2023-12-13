package org.calyxos.backup.storage.api;

import java.lang.System;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00006\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\t\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0004\n\u0002\u0010\b\n\u0000\bf\u0018\u00002\u00020\u0001J\u001c\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\n\u0010\u0006\u001a\u00060\u0007j\u0002`\bH&J \u0010\t\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\u0006\u0010\n\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\rH&J\u0010\u0010\u000e\u001a\u00020\u00032\u0006\u0010\u000f\u001a\u00020\u000bH&J\u0018\u0010\u0010\u001a\u00020\u00032\u0006\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u000bH&"}, d2 = {"Lorg/calyxos/backup/storage/api/RestoreObserver;", "", "onFileRestoreError", "", "file", "Lorg/calyxos/backup/storage/api/BackupFile;", "e", "Ljava/lang/Exception;", "Lkotlin/Exception;", "onFileRestored", "bytesWritten", "", "tag", "", "onRestoreComplete", "restoreDuration", "onRestoreStart", "numFiles", "", "totalSize"})
public abstract interface RestoreObserver {
    
    public abstract void onRestoreStart(int numFiles, long totalSize);
    
    public abstract void onFileRestored(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.BackupFile file, long bytesWritten, @org.jetbrains.annotations.NotNull()
    java.lang.String tag);
    
    /**
     * Called when a file failed to restore.
     * You might want to inform the user about this.
     * The exception already gets logged.
     */
    public abstract void onFileRestoreError(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.BackupFile file, @org.jetbrains.annotations.NotNull()
    java.lang.Exception e);
    
    public abstract void onRestoreComplete(long restoreDuration);
}