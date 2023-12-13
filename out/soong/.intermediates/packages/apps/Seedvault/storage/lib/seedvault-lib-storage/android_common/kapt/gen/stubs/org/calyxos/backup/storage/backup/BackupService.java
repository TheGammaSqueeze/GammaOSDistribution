package org.calyxos.backup.storage.backup;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.util.Log;
import kotlinx.coroutines.GlobalScope;
import org.calyxos.backup.storage.R;
import org.calyxos.backup.storage.api.BackupObserver;
import org.calyxos.backup.storage.api.StorageBackup;
import org.calyxos.backup.storage.ui.Notifications;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000F\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\b&\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0018\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u0016H\u0014J\u0014\u0010\u0017\u001a\u0004\u0018\u00010\u00182\b\u0010\u0013\u001a\u0004\u0018\u00010\u0014H\u0016J\b\u0010\u0019\u001a\u00020\u0012H\u0016J \u0010\u001a\u001a\u00020\u001b2\u0006\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u001c\u001a\u00020\u001b2\u0006\u0010\u001d\u001a\u00020\u001bH\u0016R\u0014\u0010\u0003\u001a\u0004\u0018\u00010\u0004X\u00a4\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0005\u0010\u0006R\u001b\u0010\u0007\u001a\u00020\b8BX\u0082\u0084\u0002\u00a2\u0006\f\n\u0004\b\u000b\u0010\f\u001a\u0004\b\t\u0010\nR\u0012\u0010\r\u001a\u00020\u000eX\u00a4\u0004\u00a2\u0006\u0006\u001a\u0004\b\u000f\u0010\u0010"}, d2 = {"Lorg/calyxos/backup/storage/backup/BackupService;", "Landroid/app/Service;", "()V", "backupObserver", "Lorg/calyxos/backup/storage/api/BackupObserver;", "getBackupObserver", "()Lorg/calyxos/backup/storage/api/BackupObserver;", "n", "Lorg/calyxos/backup/storage/ui/Notifications;", "getN", "()Lorg/calyxos/backup/storage/ui/Notifications;", "n$delegate", "Lkotlin/Lazy;", "storageBackup", "Lorg/calyxos/backup/storage/api/StorageBackup;", "getStorageBackup", "()Lorg/calyxos/backup/storage/api/StorageBackup;", "onBackupFinished", "", "intent", "Landroid/content/Intent;", "success", "", "onBind", "Landroid/os/IBinder;", "onDestroy", "onStartCommand", "", "flags", "startId"})
public abstract class BackupService extends android.app.Service {
    private final kotlin.Lazy n$delegate = null;
    
    private final org.calyxos.backup.storage.ui.Notifications getN() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    protected abstract org.calyxos.backup.storage.api.StorageBackup getStorageBackup();
    
    @org.jetbrains.annotations.Nullable()
    protected abstract org.calyxos.backup.storage.api.BackupObserver getBackupObserver();
    
    @java.lang.Override()
    public int onStartCommand(@org.jetbrains.annotations.NotNull()
    android.content.Intent intent, int flags, int startId) {
        return 0;
    }
    
    protected void onBackupFinished(@org.jetbrains.annotations.NotNull()
    android.content.Intent intent, boolean success) {
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public android.os.IBinder onBind(@org.jetbrains.annotations.Nullable()
    android.content.Intent intent) {
        return null;
    }
    
    @java.lang.Override()
    public void onDestroy() {
    }
    
    public BackupService() {
        super();
    }
}