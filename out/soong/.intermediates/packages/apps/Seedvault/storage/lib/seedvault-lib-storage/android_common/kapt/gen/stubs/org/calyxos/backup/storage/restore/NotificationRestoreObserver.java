package org.calyxos.backup.storage.restore;

import android.app.PendingIntent;
import android.content.Context;
import org.calyxos.backup.storage.api.BackupFile;
import org.calyxos.backup.storage.api.RestoreObserver;
import org.calyxos.backup.storage.ui.Notifications;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000N\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\t\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0005\b\u0016\u0018\u00002\u00020\u0001B\u000f\b\u0016\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004B\u000f\b\u0000\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\u0002\u0010\u0007J\n\u0010\f\u001a\u0004\u0018\u00010\rH\u0014J\u001c\u0010\u000e\u001a\u00020\u000f2\u0006\u0010\u0010\u001a\u00020\u00112\n\u0010\u0012\u001a\u00060\u0013j\u0002`\u0014H\u0016J \u0010\u0015\u001a\u00020\u000f2\u0006\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u0016\u001a\u00020\u00172\u0006\u0010\u0018\u001a\u00020\u0019H\u0016J\u0010\u0010\u001a\u001a\u00020\u000f2\u0006\u0010\u001b\u001a\u00020\u0017H\u0016J\u0018\u0010\u001c\u001a\u00020\u000f2\u0006\u0010\u001d\u001a\u00020\t2\u0006\u0010\u001e\u001a\u00020\u0017H\u0016R\u000e\u0010\b\u001a\u00020\tX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\tX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\tX\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lorg/calyxos/backup/storage/restore/NotificationRestoreObserver;", "Lorg/calyxos/backup/storage/api/RestoreObserver;", "context", "Landroid/content/Context;", "(Landroid/content/Context;)V", "n", "Lorg/calyxos/backup/storage/ui/Notifications;", "(Lorg/calyxos/backup/storage/ui/Notifications;)V", "filesRestored", "", "filesWithError", "totalFiles", "getRestoreCompleteIntent", "Landroid/app/PendingIntent;", "onFileRestoreError", "", "file", "Lorg/calyxos/backup/storage/api/BackupFile;", "e", "Ljava/lang/Exception;", "Lkotlin/Exception;", "onFileRestored", "bytesWritten", "", "tag", "", "onRestoreComplete", "restoreDuration", "onRestoreStart", "numFiles", "totalSize"})
public class NotificationRestoreObserver implements org.calyxos.backup.storage.api.RestoreObserver {
    private int totalFiles = 0;
    private int filesRestored = 0;
    private int filesWithError = 0;
    private final org.calyxos.backup.storage.ui.Notifications n = null;
    
    @java.lang.Override()
    public void onRestoreStart(int numFiles, long totalSize) {
    }
    
    @java.lang.Override()
    public void onFileRestored(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.BackupFile file, long bytesWritten, @org.jetbrains.annotations.NotNull()
    java.lang.String tag) {
    }
    
    @java.lang.Override()
    public void onFileRestoreError(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.BackupFile file, @org.jetbrains.annotations.NotNull()
    java.lang.Exception e) {
    }
    
    @java.lang.Override()
    public void onRestoreComplete(long restoreDuration) {
    }
    
    @org.jetbrains.annotations.Nullable()
    protected android.app.PendingIntent getRestoreCompleteIntent() {
        return null;
    }
    
    public NotificationRestoreObserver(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.ui.Notifications n) {
        super();
    }
    
    public NotificationRestoreObserver(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super();
    }
}