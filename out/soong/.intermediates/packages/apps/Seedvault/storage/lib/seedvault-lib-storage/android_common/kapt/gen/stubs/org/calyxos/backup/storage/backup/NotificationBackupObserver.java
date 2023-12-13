package org.calyxos.backup.storage.backup;

import android.content.Context;
import org.calyxos.backup.storage.R;
import org.calyxos.backup.storage.api.BackupFile;
import org.calyxos.backup.storage.api.BackupObserver;
import org.calyxos.backup.storage.ui.Notifications;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000Z\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\t\n\u0002\b\t\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0010\u000e\n\u0002\b\t\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0010 \n\u0002\b\u0004\b\u0016\u0018\u00002\u00020\u0001B\u000f\b\u0016\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004B\u000f\b\u0000\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\u0002\u0010\u0007J\u001b\u0010\u000e\u001a\u00020\u000f2\b\u0010\u0010\u001a\u0004\u0018\u00010\u0011H\u0096@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0012J1\u0010\u0013\u001a\u00020\u000f2\u0006\u0010\u0014\u001a\u00020\u00112\u0006\u0010\u0015\u001a\u00020\t2\u0006\u0010\u0016\u001a\u00020\t2\u0006\u0010\u0017\u001a\u00020\tH\u0096@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0018J9\u0010\u0019\u001a\u00020\u000f2\u0006\u0010\u001a\u001a\u00020\u001b2\u0006\u0010\u001c\u001a\u00020\u001d2\u0006\u0010\u001e\u001a\u00020\t2\u0006\u0010\u001f\u001a\u00020\u00112\u0006\u0010 \u001a\u00020!H\u0096@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\"J!\u0010#\u001a\u00020\u000f2\u0006\u0010\u001a\u001a\u00020\u001b2\u0006\u0010 \u001a\u00020!H\u0096@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010$J\u0019\u0010%\u001a\u00020\u000f2\u0006\u0010&\u001a\u00020\u0011H\u0096@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\'J\'\u0010(\u001a\u00020\u000f2\b\u0010)\u001a\u0004\u0018\u00010\u00112\n\u0010*\u001a\u00060+j\u0002`,H\u0096@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010-J)\u0010.\u001a\u00020\u000f2\u0006\u0010)\u001a\u00020\u00112\u0006\u0010/\u001a\u00020\t2\u0006\u00100\u001a\u00020\u0011H\u0096@\u00f8\u0001\u0000\u00a2\u0006\u0002\u00101J\u001f\u00102\u001a\u00020\u000f2\f\u00103\u001a\b\u0012\u0004\u0012\u00020\u001104H\u0096@\u00f8\u0001\u0000\u00a2\u0006\u0002\u00105J\u0011\u00106\u001a\u00020\u000fH\u0096@\u00f8\u0001\u0000\u00a2\u0006\u0002\u00107J\u0011\u00108\u001a\u00020\u000fH\u0096@\u00f8\u0001\u0000\u00a2\u0006\u0002\u00107R\u000e\u0010\b\u001a\u00020\tX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\tX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\tX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\tX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\tX\u0082\u000e\u00a2\u0006\u0002\n\u0000\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lorg/calyxos/backup/storage/backup/NotificationBackupObserver;", "Lorg/calyxos/backup/storage/api/BackupObserver;", "context", "Landroid/content/Context;", "(Landroid/content/Context;)V", "n", "Lorg/calyxos/backup/storage/ui/Notifications;", "(Lorg/calyxos/backup/storage/ui/Notifications;)V", "filesBackedUp", "", "filesWithError", "snapshotsPruned", "snapshotsToPrune", "totalFiles", "onBackupComplete", "", "backupDuration", "", "(Ljava/lang/Long;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onBackupStart", "totalSize", "numFiles", "numSmallFiles", "numLargeFiles", "(JIIILkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onFileBackedUp", "file", "Lorg/calyxos/backup/storage/api/BackupFile;", "wasUploaded", "", "reusedChunks", "bytesWritten", "tag", "", "(Lorg/calyxos/backup/storage/api/BackupFile;ZIJLjava/lang/String;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onFileBackupError", "(Lorg/calyxos/backup/storage/api/BackupFile;Ljava/lang/String;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onPruneComplete", "pruneDuration", "(JLkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onPruneError", "snapshot", "e", "Ljava/lang/Exception;", "Lkotlin/Exception;", "(Ljava/lang/Long;Ljava/lang/Exception;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onPruneSnapshot", "numChunksToDelete", "size", "(JIJLkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onPruneStart", "snapshotsToDelete", "", "(Ljava/util/List;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onPruneStartScanning", "(Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onStartScanning"})
public class NotificationBackupObserver implements org.calyxos.backup.storage.api.BackupObserver {
    private int totalFiles = 0;
    private int filesBackedUp = 0;
    private int filesWithError = 0;
    private int snapshotsToPrune = 0;
    private int snapshotsPruned = 0;
    private final org.calyxos.backup.storage.ui.Notifications n = null;
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Object onStartScanning(@org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p0) {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Object onBackupStart(long p0, int p1, int p2, int p3, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p4) {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Object onFileBackedUp(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.BackupFile p0, boolean p1, int p2, long p3, @org.jetbrains.annotations.NotNull()
    java.lang.String p4, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p5) {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Object onFileBackupError(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.BackupFile p0, @org.jetbrains.annotations.NotNull()
    java.lang.String p1, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p2) {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Object onBackupComplete(@org.jetbrains.annotations.Nullable()
    java.lang.Long p0, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p1) {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Object onPruneStartScanning(@org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p0) {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Object onPruneStart(@org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.Long> p0, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p1) {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Object onPruneSnapshot(long p0, int p1, long p2, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p3) {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Object onPruneError(@org.jetbrains.annotations.Nullable()
    java.lang.Long p0, @org.jetbrains.annotations.NotNull()
    java.lang.Exception p1, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p2) {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Object onPruneComplete(long p0, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p1) {
        return null;
    }
    
    public NotificationBackupObserver(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.ui.Notifications n) {
        super();
    }
    
    public NotificationBackupObserver(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super();
    }
}