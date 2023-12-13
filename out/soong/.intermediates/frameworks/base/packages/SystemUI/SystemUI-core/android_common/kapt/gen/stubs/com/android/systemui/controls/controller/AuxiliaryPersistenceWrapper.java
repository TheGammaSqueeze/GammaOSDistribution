package com.android.systemui.controls.controller;

import android.app.job.JobInfo;
import android.app.job.JobParameters;
import android.app.job.JobService;
import android.content.ComponentName;
import android.content.Context;
import com.android.internal.annotations.VisibleForTesting;
import com.android.systemui.backup.BackupHelper;
import java.io.File;
import java.util.concurrent.Executor;
import java.util.concurrent.TimeUnit;

/**
 * Class to track the auxiliary persistence of controls.
 *
 * This file is a copy of the `controls_favorites.xml` file restored from a back up. It is used to
 * keep track of controls that were restored but its corresponding app has not been installed yet.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000<\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\u0018\u0000 \u00172\u00020\u0001:\u0002\u0017\u0018B\u0017\b\u0016\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006B\u000f\b\u0001\u0012\u0006\u0010\u0007\u001a\u00020\b\u00a2\u0006\u0002\u0010\tJ\u000e\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0002\u001a\u00020\u0003J\u0014\u0010\u0013\u001a\b\u0012\u0004\u0012\u00020\f0\u000b2\u0006\u0010\u0014\u001a\u00020\u0015J\u0006\u0010\u0016\u001a\u00020\u0012R*\u0010\r\u001a\b\u0012\u0004\u0012\u00020\f0\u000b2\f\u0010\n\u001a\b\u0012\u0004\u0012\u00020\f0\u000b@BX\u0086\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000e\u0010\u000fR\u000e\u0010\u0010\u001a\u00020\bX\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/controller/AuxiliaryPersistenceWrapper;", "", "file", "Ljava/io/File;", "executor", "Ljava/util/concurrent/Executor;", "(Ljava/io/File;Ljava/util/concurrent/Executor;)V", "wrapper", "Lcom/android/systemui/controls/controller/ControlsFavoritePersistenceWrapper;", "(Lcom/android/systemui/controls/controller/ControlsFavoritePersistenceWrapper;)V", "<set-?>", "", "Lcom/android/systemui/controls/controller/StructureInfo;", "favorites", "getFavorites", "()Ljava/util/List;", "persistenceWrapper", "changeFile", "", "getCachedFavoritesAndRemoveFor", "componentName", "Landroid/content/ComponentName;", "initialize", "Companion", "DeletionJobService"})
public final class AuxiliaryPersistenceWrapper {
    private com.android.systemui.controls.controller.ControlsFavoritePersistenceWrapper persistenceWrapper;
    
    /**
     * Access the current list of favorites as tracked by the auxiliary file
     */
    @org.jetbrains.annotations.NotNull()
    private java.util.List<com.android.systemui.controls.controller.StructureInfo> favorites;
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String AUXILIARY_FILE_NAME = "aux_controls_favorites.xml";
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.controller.AuxiliaryPersistenceWrapper.Companion Companion = null;
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<com.android.systemui.controls.controller.StructureInfo> getFavorites() {
        return null;
    }
    
    /**
     * Change the file that this class is tracking.
     *
     * This will reset [favorites].
     */
    public final void changeFile(@org.jetbrains.annotations.NotNull()
    java.io.File file) {
    }
    
    /**
     * Initialize the list of favorites to the content of the auxiliary file. If the file does not
     * exist, it will be initialized to an empty list.
     */
    public final void initialize() {
    }
    
    /**
     * Gets the list of favorite controls as persisted in the auxiliary file for a given component.
     *
     * When the favorites for that application are returned, they will be removed from the
     * auxiliary file immediately, so they won't be retrieved again.
     * @param componentName the name of the service that provided the controls
     * @return a list of structures with favorites
     */
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<com.android.systemui.controls.controller.StructureInfo> getCachedFavoritesAndRemoveFor(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName) {
        return null;
    }
    
    @com.android.internal.annotations.VisibleForTesting()
    public AuxiliaryPersistenceWrapper(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.ControlsFavoritePersistenceWrapper wrapper) {
        super();
    }
    
    public AuxiliaryPersistenceWrapper(@org.jetbrains.annotations.NotNull()
    java.io.File file, @org.jetbrains.annotations.NotNull()
    java.util.concurrent.Executor executor) {
        super();
    }
    
    /**
     * [JobService] to delete the auxiliary file after a week.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000&\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\u0018\u0000 \f2\u00020\u0001:\u0001\fB\u0005\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u0006H\u0007J\u0010\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\nH\u0016J\u0012\u0010\u000b\u001a\u00020\b2\b\u0010\t\u001a\u0004\u0018\u00010\nH\u0016"}, d2 = {"Lcom/android/systemui/controls/controller/AuxiliaryPersistenceWrapper$DeletionJobService;", "Landroid/app/job/JobService;", "()V", "attachContext", "", "context", "Landroid/content/Context;", "onStartJob", "", "params", "Landroid/app/job/JobParameters;", "onStopJob", "Companion"})
    public static final class DeletionJobService extends android.app.job.JobService {
        private static final int DELETE_FILE_JOB_ID = 1000;
        private static final long WEEK_IN_MILLIS = 0L;
        @org.jetbrains.annotations.NotNull()
        public static final com.android.systemui.controls.controller.AuxiliaryPersistenceWrapper.DeletionJobService.Companion Companion = null;
        
        @com.android.internal.annotations.VisibleForTesting()
        public final void attachContext(@org.jetbrains.annotations.NotNull()
        android.content.Context context) {
        }
        
        @java.lang.Override()
        public boolean onStartJob(@org.jetbrains.annotations.NotNull()
        android.app.job.JobParameters params) {
            return false;
        }
        
        @java.lang.Override()
        public boolean onStopJob(@org.jetbrains.annotations.Nullable()
        android.app.job.JobParameters params) {
            return false;
        }
        
        public DeletionJobService() {
            super();
        }
        
        @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0004\n\u0002\u0010\t\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u000e\u0010\n\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\rR\u001c\u0010\u0003\u001a\u00020\u00048\u0000X\u0081D\u00a2\u0006\u000e\n\u0000\u0012\u0004\b\u0005\u0010\u0002\u001a\u0004\b\u0006\u0010\u0007R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/controller/AuxiliaryPersistenceWrapper$DeletionJobService$Companion;", "", "()V", "DELETE_FILE_JOB_ID", "", "getDELETE_FILE_JOB_ID$main$annotations", "getDELETE_FILE_JOB_ID$main", "()I", "WEEK_IN_MILLIS", "", "getJobForContext", "Landroid/app/job/JobInfo;", "context", "Landroid/content/Context;"})
        public static final class Companion {
            
            @com.android.internal.annotations.VisibleForTesting()
            @java.lang.Deprecated()
            public static void getDELETE_FILE_JOB_ID$main$annotations() {
            }
            
            public final int getDELETE_FILE_JOB_ID$main() {
                return 0;
            }
            
            @org.jetbrains.annotations.NotNull()
            public final android.app.job.JobInfo getJobForContext(@org.jetbrains.annotations.NotNull()
            android.content.Context context) {
                return null;
            }
            
            private Companion() {
                super();
            }
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/controller/AuxiliaryPersistenceWrapper$Companion;", "", "()V", "AUXILIARY_FILE_NAME", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}