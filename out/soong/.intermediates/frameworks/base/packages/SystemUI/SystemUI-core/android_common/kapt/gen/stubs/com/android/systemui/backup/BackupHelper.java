package com.android.systemui.backup;

import android.app.backup.BackupAgentHelper;
import android.app.backup.BackupDataInputStream;
import android.app.backup.BackupDataOutput;
import android.app.backup.FileBackupHelper;
import android.app.job.JobScheduler;
import android.content.Context;
import android.content.Intent;
import android.os.Environment;
import android.os.ParcelFileDescriptor;
import android.os.UserHandle;
import android.util.Log;
import com.android.systemui.controls.controller.AuxiliaryPersistenceWrapper;
import com.android.systemui.controls.controller.ControlsFavoritePersistenceWrapper;
import com.android.systemui.people.widget.PeopleBackupHelper;

/**
 * Helper for backing up elements in SystemUI
 *
 * This helper is invoked by BackupManager whenever a backup or restore is required in SystemUI.
 * The helper can be used to back up any element that is stored in [Context.getFilesDir].
 *
 * After restoring is done, a [ACTION_RESTORE_FINISHED] intent will be send to SystemUI user 0,
 * indicating that restoring is finished for a given user.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0003\b\u0016\u0018\u0000 \n2\u00020\u0001:\u0002\n\u000bB\u0005\u00a2\u0006\u0002\u0010\u0002J\u0018\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bH\u0016J\b\u0010\t\u001a\u00020\u0004H\u0016"}, d2 = {"Lcom/android/systemui/backup/BackupHelper;", "Landroid/app/backup/BackupAgentHelper;", "()V", "onCreate", "", "userHandle", "Landroid/os/UserHandle;", "operationType", "", "onRestoreFinished", "Companion", "NoOverwriteFileBackupHelper"})
public class BackupHelper extends android.app.backup.BackupAgentHelper {
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String TAG = "BackupHelper";
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String CONTROLS = "controls_favorites.xml";
    private static final java.lang.String NO_OVERWRITE_FILES_BACKUP_KEY = "systemui.files_no_overwrite";
    private static final java.lang.String PEOPLE_TILES_BACKUP_KEY = "systemui.people.shared_preferences";
    @org.jetbrains.annotations.NotNull()
    private static final java.lang.Object controlsDataLock = null;
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String ACTION_RESTORE_FINISHED = "com.android.systemui.backup.RESTORE_FINISHED";
    private static final java.lang.String PERMISSION_SELF = "com.android.systemui.permission.SELF";
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.backup.BackupHelper.Companion Companion = null;
    
    @java.lang.Override()
    public void onCreate(@org.jetbrains.annotations.NotNull()
    android.os.UserHandle userHandle, int operationType) {
    }
    
    @java.lang.Override()
    public void onRestoreFinished() {
    }
    
    public BackupHelper() {
        super();
    }
    
    /**
     * Helper class for restoring files ONLY if they are not present.
     *
     * A [Map] between filenames and actions (functions) is passed to indicate post processing
     * actions to be taken after each file is restored.
     *
     * @property lock a lock to hold while backing up and restoring the files.
     * @property context the context of the [BackupAgent]
     * @property fileNamesAndPostProcess a map from the filenames to back up and the post processing
     *                                  actions to take
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000<\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010$\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\u0010\u0002\n\u0002\b\t\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\b\u0002\u0018\u00002\u00020\u0001B/\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0018\u0010\u0006\u001a\u0014\u0012\u0004\u0012\u00020\b\u0012\n\u0012\b\u0012\u0004\u0012\u00020\n0\t0\u0007\u00a2\u0006\u0002\u0010\u000bJ&\u0010\u0012\u001a\u00020\n2\b\u0010\u0013\u001a\u0004\u0018\u00010\u00142\b\u0010\u0015\u001a\u0004\u0018\u00010\u00162\b\u0010\u0017\u001a\u0004\u0018\u00010\u0014H\u0016J\u0010\u0010\u0018\u001a\u00020\n2\u0006\u0010\u0015\u001a\u00020\u0019H\u0016R\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\rR#\u0010\u0006\u001a\u0014\u0012\u0004\u0012\u00020\b\u0012\n\u0012\b\u0012\u0004\u0012\u00020\n0\t0\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000e\u0010\u000fR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0010\u0010\u0011"}, d2 = {"Lcom/android/systemui/backup/BackupHelper$NoOverwriteFileBackupHelper;", "Landroid/app/backup/FileBackupHelper;", "lock", "", "context", "Landroid/content/Context;", "fileNamesAndPostProcess", "", "", "Lkotlin/Function0;", "", "(Ljava/lang/Object;Landroid/content/Context;Ljava/util/Map;)V", "getContext", "()Landroid/content/Context;", "getFileNamesAndPostProcess", "()Ljava/util/Map;", "getLock", "()Ljava/lang/Object;", "performBackup", "oldState", "Landroid/os/ParcelFileDescriptor;", "data", "Landroid/app/backup/BackupDataOutput;", "newState", "restoreEntity", "Landroid/app/backup/BackupDataInputStream;"})
    static final class NoOverwriteFileBackupHelper extends android.app.backup.FileBackupHelper {
        @org.jetbrains.annotations.NotNull()
        private final java.lang.Object lock = null;
        @org.jetbrains.annotations.NotNull()
        private final android.content.Context context = null;
        @org.jetbrains.annotations.NotNull()
        private final java.util.Map<java.lang.String, kotlin.jvm.functions.Function0<kotlin.Unit>> fileNamesAndPostProcess = null;
        
        @java.lang.Override()
        public void restoreEntity(@org.jetbrains.annotations.NotNull()
        android.app.backup.BackupDataInputStream data) {
        }
        
        @java.lang.Override()
        public void performBackup(@org.jetbrains.annotations.Nullable()
        android.os.ParcelFileDescriptor oldState, @org.jetbrains.annotations.Nullable()
        android.app.backup.BackupDataOutput data, @org.jetbrains.annotations.Nullable()
        android.os.ParcelFileDescriptor newState) {
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.Object getLock() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final android.content.Context getContext() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.util.Map<java.lang.String, kotlin.jvm.functions.Function0<kotlin.Unit>> getFileNamesAndPostProcess() {
            return null;
        }
        
        public NoOverwriteFileBackupHelper(@org.jetbrains.annotations.NotNull()
        java.lang.Object lock, @org.jetbrains.annotations.NotNull()
        android.content.Context context, @org.jetbrains.annotations.NotNull()
        java.util.Map<java.lang.String, ? extends kotlin.jvm.functions.Function0<kotlin.Unit>> fileNamesAndPostProcess) {
            super(null, null);
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\b\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0080T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u0011\u0010\n\u001a\u00020\u0001\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\f"}, d2 = {"Lcom/android/systemui/backup/BackupHelper$Companion;", "", "()V", "ACTION_RESTORE_FINISHED", "", "CONTROLS", "NO_OVERWRITE_FILES_BACKUP_KEY", "PEOPLE_TILES_BACKUP_KEY", "PERMISSION_SELF", "TAG", "controlsDataLock", "getControlsDataLock", "()Ljava/lang/Object;"})
    public static final class Companion {
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.Object getControlsDataLock() {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}