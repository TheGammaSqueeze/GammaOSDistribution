package org.calyxos.backup.storage.api;

import java.lang.System;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000J\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\t\n\u0002\b\u0004\n\u0002\u0010\b\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0010\u000e\n\u0002\b\t\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0010 \n\u0002\b\u0004\bf\u0018\u00002\u00020\u0001J\u001b\u0010\u0002\u001a\u00020\u00032\b\u0010\u0004\u001a\u0004\u0018\u00010\u0005H\u00a6@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0006J1\u0010\u0007\u001a\u00020\u00032\u0006\u0010\b\u001a\u00020\u00052\u0006\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\n2\u0006\u0010\f\u001a\u00020\nH\u00a6@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\rJ9\u0010\u000e\u001a\u00020\u00032\u0006\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\n2\u0006\u0010\u0014\u001a\u00020\u00052\u0006\u0010\u0015\u001a\u00020\u0016H\u00a6@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0017J!\u0010\u0018\u001a\u00020\u00032\u0006\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0015\u001a\u00020\u0016H\u00a6@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0019J\u0019\u0010\u001a\u001a\u00020\u00032\u0006\u0010\u001b\u001a\u00020\u0005H\u00a6@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u001cJ\'\u0010\u001d\u001a\u00020\u00032\b\u0010\u001e\u001a\u0004\u0018\u00010\u00052\n\u0010\u001f\u001a\u00060 j\u0002`!H\u00a6@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\"J)\u0010#\u001a\u00020\u00032\u0006\u0010\u001e\u001a\u00020\u00052\u0006\u0010$\u001a\u00020\n2\u0006\u0010%\u001a\u00020\u0005H\u00a6@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010&J\u001f\u0010\'\u001a\u00020\u00032\f\u0010(\u001a\b\u0012\u0004\u0012\u00020\u00050)H\u00a6@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010*J\u0011\u0010+\u001a\u00020\u0003H\u00a6@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010,J\u0011\u0010-\u001a\u00020\u0003H\u00a6@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010,\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"Lorg/calyxos/backup/storage/api/BackupObserver;", "", "onBackupComplete", "", "backupDuration", "", "(Ljava/lang/Long;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onBackupStart", "totalSize", "numFiles", "", "numSmallFiles", "numLargeFiles", "(JIIILkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onFileBackedUp", "file", "Lorg/calyxos/backup/storage/api/BackupFile;", "wasUploaded", "", "reusedChunks", "bytesWritten", "tag", "", "(Lorg/calyxos/backup/storage/api/BackupFile;ZIJLjava/lang/String;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onFileBackupError", "(Lorg/calyxos/backup/storage/api/BackupFile;Ljava/lang/String;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onPruneComplete", "pruneDuration", "(JLkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onPruneError", "snapshot", "e", "Ljava/lang/Exception;", "Lkotlin/Exception;", "(Ljava/lang/Long;Ljava/lang/Exception;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onPruneSnapshot", "numChunksToDelete", "size", "(JIJLkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onPruneStart", "snapshotsToDelete", "", "(Ljava/util/List;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onPruneStartScanning", "(Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "onStartScanning"})
public abstract interface BackupObserver {
    
    @org.jetbrains.annotations.Nullable()
    public abstract java.lang.Object onStartScanning(@org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p0);
    
    /**
     * Called after scanning files when starting the backup.
     *
     * @param totalSize the total size of all files to be backed up.
     * @param numFiles the number of all files to be backed up.
     * The sum of [numSmallFiles] and [numLargeFiles].
     * @param numSmallFiles the number of small files to be backed up.
     * @param numLargeFiles the number of large files to be backed up.
     */
    @org.jetbrains.annotations.Nullable()
    public abstract java.lang.Object onBackupStart(long totalSize, int numFiles, int numSmallFiles, int numLargeFiles, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p4);
    
    @org.jetbrains.annotations.Nullable()
    public abstract java.lang.Object onFileBackedUp(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.BackupFile file, boolean wasUploaded, int reusedChunks, long bytesWritten, @org.jetbrains.annotations.NotNull()
    java.lang.String tag, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p5);
    
    @org.jetbrains.annotations.Nullable()
    public abstract java.lang.Object onFileBackupError(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.api.BackupFile file, @org.jetbrains.annotations.NotNull()
    java.lang.String tag, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p2);
    
    /**
     * If backupDuration is null, the overall backup failed.
     */
    @org.jetbrains.annotations.Nullable()
    public abstract java.lang.Object onBackupComplete(@org.jetbrains.annotations.Nullable()
    java.lang.Long backupDuration, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p1);
    
    @org.jetbrains.annotations.Nullable()
    public abstract java.lang.Object onPruneStartScanning(@org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p0);
    
    @org.jetbrains.annotations.Nullable()
    public abstract java.lang.Object onPruneStart(@org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.Long> snapshotsToDelete, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p1);
    
    @org.jetbrains.annotations.Nullable()
    public abstract java.lang.Object onPruneSnapshot(long snapshot, int numChunksToDelete, long size, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p3);
    
    /**
     * If snapshot is null, the overall operation failed.
     */
    @org.jetbrains.annotations.Nullable()
    public abstract java.lang.Object onPruneError(@org.jetbrains.annotations.Nullable()
    java.lang.Long snapshot, @org.jetbrains.annotations.NotNull()
    java.lang.Exception e, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p2);
    
    @org.jetbrains.annotations.Nullable()
    public abstract java.lang.Object onPruneComplete(long pruneDuration, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p1);
}