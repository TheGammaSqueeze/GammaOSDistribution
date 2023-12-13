package org.calyxos.backup.storage.restore;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.util.Log;
import kotlinx.coroutines.GlobalScope;
import org.calyxos.backup.storage.api.RestoreObserver;
import org.calyxos.backup.storage.api.StorageBackup;
import org.calyxos.backup.storage.api.StoredSnapshot;
import org.calyxos.backup.storage.ui.Notifications;

/**
 * Start to trigger restore as a foreground service. Ensure that you provide the snapshot
 * to be restored with [Intent.putExtra]:
 *  * the user ID of the snapshot as a [String] in [EXTRA_USER_ID]
 *  * the snapshot's timestamp as a [Long] in [EXTRA_TIMESTAMP_START].
 *    See [BackupSnapshot.getTimeStart].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000>\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0003\b&\u0018\u0000 \u001b2\u00020\u0001:\u0001\u001bB\u0005\u00a2\u0006\u0002\u0010\u0002J\u0014\u0010\u0011\u001a\u0004\u0018\u00010\u00122\b\u0010\u0013\u001a\u0004\u0018\u00010\u0014H\u0016J\b\u0010\u0015\u001a\u00020\u0016H\u0016J\"\u0010\u0017\u001a\u00020\u00182\b\u0010\u0013\u001a\u0004\u0018\u00010\u00142\u0006\u0010\u0019\u001a\u00020\u00182\u0006\u0010\u001a\u001a\u00020\u0018H\u0016R\u001b\u0010\u0003\u001a\u00020\u00048BX\u0082\u0084\u0002\u00a2\u0006\f\n\u0004\b\u0007\u0010\b\u001a\u0004\b\u0005\u0010\u0006R\u0014\u0010\t\u001a\u0004\u0018\u00010\nX\u00a4\u0004\u00a2\u0006\u0006\u001a\u0004\b\u000b\u0010\fR\u0012\u0010\r\u001a\u00020\u000eX\u00a4\u0004\u00a2\u0006\u0006\u001a\u0004\b\u000f\u0010\u0010"}, d2 = {"Lorg/calyxos/backup/storage/restore/RestoreService;", "Landroid/app/Service;", "()V", "n", "Lorg/calyxos/backup/storage/ui/Notifications;", "getN", "()Lorg/calyxos/backup/storage/ui/Notifications;", "n$delegate", "Lkotlin/Lazy;", "restoreObserver", "Lorg/calyxos/backup/storage/api/RestoreObserver;", "getRestoreObserver", "()Lorg/calyxos/backup/storage/api/RestoreObserver;", "storageBackup", "Lorg/calyxos/backup/storage/api/StorageBackup;", "getStorageBackup", "()Lorg/calyxos/backup/storage/api/StorageBackup;", "onBind", "Landroid/os/IBinder;", "intent", "Landroid/content/Intent;", "onDestroy", "", "onStartCommand", "", "flags", "startId", "Companion"})
public abstract class RestoreService extends android.app.Service {
    private final kotlin.Lazy n$delegate = null;
    private static final java.lang.String TAG = "RestoreService";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String EXTRA_USER_ID = "userId";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String EXTRA_TIMESTAMP_START = "timestamp";
    @org.jetbrains.annotations.NotNull()
    public static final org.calyxos.backup.storage.restore.RestoreService.Companion Companion = null;
    
    private final org.calyxos.backup.storage.ui.Notifications getN() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    protected abstract org.calyxos.backup.storage.api.StorageBackup getStorageBackup();
    
    @org.jetbrains.annotations.Nullable()
    protected abstract org.calyxos.backup.storage.api.RestoreObserver getRestoreObserver();
    
    @java.lang.Override()
    public int onStartCommand(@org.jetbrains.annotations.Nullable()
    android.content.Intent intent, int flags, int startId) {
        return 0;
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
    
    public RestoreService() {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lorg/calyxos/backup/storage/restore/RestoreService$Companion;", "", "()V", "EXTRA_TIMESTAMP_START", "", "EXTRA_USER_ID", "TAG"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}