package org.calyxos.backup.storage.api;

import android.net.Uri;
import android.provider.MediaStore;
import androidx.annotation.DrawableRes;
import androidx.annotation.StringRes;
import org.calyxos.backup.storage.R;
import org.calyxos.backup.storage.backup.BackupMediaFile;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\f\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\b6\u0018\u0000 \u00112\u00020\u0001:\u0005\u0010\u0011\u0012\u0013\u0014B+\b\u0002\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\b\b\u0001\u0010\u0004\u001a\u00020\u0005\u0012\b\b\u0001\u0010\u0006\u001a\u00020\u0005\u0012\u0006\u0010\u0007\u001a\u00020\b\u00a2\u0006\u0002\u0010\tR\u0011\u0010\u0007\u001a\u00020\b\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\u000bR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\rR\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000e\u0010\u000f\u0082\u0001\u0004\u0015\u0016\u0017\u0018"}, d2 = {"Lorg/calyxos/backup/storage/api/MediaType;", "Lorg/calyxos/backup/storage/api/BackupContentType;", "contentUri", "Landroid/net/Uri;", "nameRes", "", "drawableRes", "backupType", "Lorg/calyxos/backup/storage/backup/BackupMediaFile$MediaType;", "(Landroid/net/Uri;IILorg/calyxos/backup/storage/backup/BackupMediaFile$MediaType;)V", "getBackupType", "()Lorg/calyxos/backup/storage/backup/BackupMediaFile$MediaType;", "getContentUri", "()Landroid/net/Uri;", "getNameRes", "()I", "Audio", "Companion", "Downloads", "Images", "Video", "Lorg/calyxos/backup/storage/api/MediaType$Images;", "Lorg/calyxos/backup/storage/api/MediaType$Video;", "Lorg/calyxos/backup/storage/api/MediaType$Audio;", "Lorg/calyxos/backup/storage/api/MediaType$Downloads;"})
public abstract class MediaType extends org.calyxos.backup.storage.api.BackupContentType {
    @org.jetbrains.annotations.NotNull()
    private final android.net.Uri contentUri = null;
    private final int nameRes = 0;
    @org.jetbrains.annotations.NotNull()
    private final org.calyxos.backup.storage.backup.BackupMediaFile.MediaType backupType = null;
    @org.jetbrains.annotations.NotNull()
    public static final org.calyxos.backup.storage.api.MediaType.Companion Companion = null;
    
    @org.jetbrains.annotations.NotNull()
    public final android.net.Uri getContentUri() {
        return null;
    }
    
    public final int getNameRes() {
        return 0;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final org.calyxos.backup.storage.backup.BackupMediaFile.MediaType getBackupType() {
        return null;
    }
    
    private MediaType(android.net.Uri contentUri, @androidx.annotation.StringRes()
    int nameRes, @androidx.annotation.DrawableRes()
    int drawableRes, org.calyxos.backup.storage.backup.BackupMediaFile.MediaType backupType) {
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\n\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002"}, d2 = {"Lorg/calyxos/backup/storage/api/MediaType$Images;", "Lorg/calyxos/backup/storage/api/MediaType;", "()V"})
    public static final class Images extends org.calyxos.backup.storage.api.MediaType {
        @org.jetbrains.annotations.NotNull()
        public static final org.calyxos.backup.storage.api.MediaType.Images INSTANCE = null;
        
        private Images() {
            super(null, 0, 0, null);
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\n\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002"}, d2 = {"Lorg/calyxos/backup/storage/api/MediaType$Video;", "Lorg/calyxos/backup/storage/api/MediaType;", "()V"})
    public static final class Video extends org.calyxos.backup.storage.api.MediaType {
        @org.jetbrains.annotations.NotNull()
        public static final org.calyxos.backup.storage.api.MediaType.Video INSTANCE = null;
        
        private Video() {
            super(null, 0, 0, null);
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\n\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002"}, d2 = {"Lorg/calyxos/backup/storage/api/MediaType$Audio;", "Lorg/calyxos/backup/storage/api/MediaType;", "()V"})
    public static final class Audio extends org.calyxos.backup.storage.api.MediaType {
        @org.jetbrains.annotations.NotNull()
        public static final org.calyxos.backup.storage.api.MediaType.Audio INSTANCE = null;
        
        private Audio() {
            super(null, 0, 0, null);
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\n\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002"}, d2 = {"Lorg/calyxos/backup/storage/api/MediaType$Downloads;", "Lorg/calyxos/backup/storage/api/MediaType;", "()V"})
    public static final class Downloads extends org.calyxos.backup.storage.api.MediaType {
        @org.jetbrains.annotations.NotNull()
        public static final org.calyxos.backup.storage.api.MediaType.Downloads INSTANCE = null;
        
        private Downloads() {
            super(null, 0, 0, null);
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\b\u0080\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u000e\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u0006"}, d2 = {"Lorg/calyxos/backup/storage/api/MediaType$Companion;", "", "()V", "fromBackupMediaType", "Lorg/calyxos/backup/storage/api/MediaType;", "type", "Lorg/calyxos/backup/storage/backup/BackupMediaFile$MediaType;"})
    public static final class Companion {
        
        @org.jetbrains.annotations.NotNull()
        public final org.calyxos.backup.storage.api.MediaType fromBackupMediaType(@org.jetbrains.annotations.NotNull()
        org.calyxos.backup.storage.backup.BackupMediaFile.MediaType type) {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}