package org.calyxos.backup.storage.backup;

import android.app.Service;
import android.app.job.JobInfo;
import android.app.job.JobParameters;
import android.app.job.JobScheduler;
import android.app.job.JobService;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.util.Log;
import java.util.concurrent.TimeUnit;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\b&\u0018\u0000 \u000b2\u00020\u0001:\u0001\u000bB\u0015\u0012\u000e\u0010\u0002\u001a\n\u0012\u0006\b\u0001\u0012\u00020\u00040\u0003\u00a2\u0006\u0002\u0010\u0005J\u0012\u0010\u0006\u001a\u00020\u00072\b\u0010\b\u001a\u0004\u0018\u00010\tH\u0016J\u0012\u0010\n\u001a\u00020\u00072\b\u0010\b\u001a\u0004\u0018\u00010\tH\u0016R\u0016\u0010\u0002\u001a\n\u0012\u0006\b\u0001\u0012\u00020\u00040\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lorg/calyxos/backup/storage/backup/BackupJobService;", "Landroid/app/job/JobService;", "serviceClass", "Ljava/lang/Class;", "Landroid/app/Service;", "(Ljava/lang/Class;)V", "onStartJob", "", "params", "Landroid/app/job/JobParameters;", "onStopJob", "Companion"})
public abstract class BackupJobService extends android.app.job.JobService {
    private final java.lang.Class<? extends android.app.Service> serviceClass = null;
    @org.jetbrains.annotations.NotNull()
    public static final org.calyxos.backup.storage.backup.BackupJobService.Companion Companion = null;
    
    @java.lang.Override()
    public boolean onStartJob(@org.jetbrains.annotations.Nullable()
    android.app.job.JobParameters params) {
        return false;
    }
    
    @java.lang.Override()
    public boolean onStopJob(@org.jetbrains.annotations.Nullable()
    android.app.job.JobParameters params) {
        return false;
    }
    
    public BackupJobService(@org.jetbrains.annotations.NotNull()
    java.lang.Class<? extends android.app.Service> serviceClass) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00004\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\n\u0000\n\u0002\u0010\b\n\u0002\b\u0003\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u000e\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u0006J\u000e\u0010\u0007\u001a\u00020\b2\u0006\u0010\u0005\u001a\u00020\u0006JI\u0010\t\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u00062\n\u0010\n\u001a\u0006\u0012\u0002\b\u00030\u000b2\b\b\u0002\u0010\f\u001a\u00020\r2\n\b\u0002\u0010\u000e\u001a\u0004\u0018\u00010\u000f2\b\b\u0002\u0010\u0010\u001a\u00020\b2\b\b\u0002\u0010\u0011\u001a\u00020\b\u00a2\u0006\u0002\u0010\u0012"}, d2 = {"Lorg/calyxos/backup/storage/backup/BackupJobService$Companion;", "", "()V", "cancelJob", "", "context", "Landroid/content/Context;", "isScheduled", "", "scheduleJob", "jobServiceClass", "Ljava/lang/Class;", "periodMillis", "", "networkType", "", "deviceIdle", "charging", "(Landroid/content/Context;Ljava/lang/Class;JLjava/lang/Integer;ZZ)V"})
    public static final class Companion {
        
        /**
         * Warning: This works only if battery optimization is disabled for the app using this.
         */
        public final void scheduleJob(@org.jetbrains.annotations.NotNull()
        android.content.Context context, @org.jetbrains.annotations.NotNull()
        java.lang.Class<?> jobServiceClass, long periodMillis, @org.jetbrains.annotations.Nullable()
        java.lang.Integer networkType, boolean deviceIdle, boolean charging) {
        }
        
        public final boolean isScheduled(@org.jetbrains.annotations.NotNull()
        android.content.Context context) {
            return false;
        }
        
        public final void cancelJob(@org.jetbrains.annotations.NotNull()
        android.content.Context context) {
        }
        
        private Companion() {
            super();
        }
    }
}