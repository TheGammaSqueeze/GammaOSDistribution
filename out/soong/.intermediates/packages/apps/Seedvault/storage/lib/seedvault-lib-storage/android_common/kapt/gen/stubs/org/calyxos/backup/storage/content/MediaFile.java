package org.calyxos.backup.storage.content;

import android.net.Uri;
import android.provider.MediaStore;
import android.util.Log;
import org.calyxos.backup.storage.api.BackupFile;
import org.calyxos.backup.storage.backup.BackupDocumentFile;
import org.calyxos.backup.storage.backup.BackupMediaFile;
import org.calyxos.backup.storage.db.CachedFile;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000L\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\t\n\u0002\b\u0004\n\u0002\u0010\u000b\n\u0002\b!\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\b\u0004\b\u0080\b\u0018\u00002\u00020\u0001BS\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0005\u0012\b\u0010\u0007\u001a\u0004\u0018\u00010\b\u0012\b\u0010\t\u001a\u0004\u0018\u00010\b\u0012\u0006\u0010\n\u001a\u00020\b\u0012\u0006\u0010\u000b\u001a\u00020\u0005\u0012\u0006\u0010\f\u001a\u00020\r\u0012\b\u0010\u000e\u001a\u0004\u0018\u00010\u0005\u00a2\u0006\u0002\u0010\u000fJ\t\u0010\"\u001a\u00020\u0003H\u00c6\u0003J\t\u0010#\u001a\u00020\u0005H\u00c6\u0003J\t\u0010$\u001a\u00020\u0005H\u00c6\u0003J\u0010\u0010%\u001a\u0004\u0018\u00010\bH\u00c6\u0003\u00a2\u0006\u0002\u0010\u0011J\u0010\u0010&\u001a\u0004\u0018\u00010\bH\u00c6\u0003\u00a2\u0006\u0002\u0010\u0011J\t\u0010\'\u001a\u00020\bH\u00c6\u0003J\t\u0010(\u001a\u00020\u0005H\u00c6\u0003J\t\u0010)\u001a\u00020\rH\u00c6\u0003J\u000b\u0010*\u001a\u0004\u0018\u00010\u0005H\u00c6\u0003Jn\u0010+\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00052\b\b\u0002\u0010\u0006\u001a\u00020\u00052\n\b\u0002\u0010\u0007\u001a\u0004\u0018\u00010\b2\n\b\u0002\u0010\t\u001a\u0004\u0018\u00010\b2\b\b\u0002\u0010\n\u001a\u00020\b2\b\b\u0002\u0010\u000b\u001a\u00020\u00052\b\b\u0002\u0010\f\u001a\u00020\r2\n\b\u0002\u0010\u000e\u001a\u0004\u0018\u00010\u0005H\u00c6\u0001\u00a2\u0006\u0002\u0010,J\u0013\u0010-\u001a\u00020\r2\b\u0010.\u001a\u0004\u0018\u00010/H\u00d6\u0003J\u0017\u00100\u001a\u00020\r2\b\u00101\u001a\u0004\u0018\u000102H\u0010\u00a2\u0006\u0002\b3J\t\u00104\u001a\u000205H\u00d6\u0001J)\u00106\u001a\u0002072\f\u00108\u001a\b\u0012\u0004\u0012\u00020\u0005092\n\b\u0002\u0010:\u001a\u0004\u0018\u000105H\u0000\u00a2\u0006\u0004\b;\u0010<J\t\u0010=\u001a\u00020\u0005H\u00d6\u0001R\u0015\u0010\u0007\u001a\u0004\u0018\u00010\b\u00a2\u0006\n\n\u0002\u0010\u0012\u001a\u0004\b\u0010\u0010\u0011R\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0013\u0010\u0014R\u0014\u0010\u0015\u001a\u00020\u0005X\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0016\u0010\u0014R\u0014\u0010\u0006\u001a\u00020\u0005X\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0017\u0010\u0014R\u0018\u0010\t\u001a\u0004\u0018\u00010\bX\u0096\u0004\u00a2\u0006\n\n\u0002\u0010\u0012\u001a\u0004\b\u0018\u0010\u0011R\u0011\u0010\f\u001a\u00020\r\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\u0019R\u0018\u0010\u001a\u001a\u0004\u0018\u00010\bX\u0096\u0004\u00a2\u0006\n\n\u0002\u0010\u0012\u001a\u0004\b\u001b\u0010\u0011R\u0013\u0010\u000e\u001a\u0004\u0018\u00010\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001c\u0010\u0014R\u0014\u0010\n\u001a\u00020\bX\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001d\u0010\u001eR\u0014\u0010\u0002\u001a\u00020\u0003X\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001f\u0010 R\u0014\u0010\u000b\u001a\u00020\u0005X\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b!\u0010\u0014"}, d2 = {"Lorg/calyxos/backup/storage/content/MediaFile;", "Lorg/calyxos/backup/storage/content/ContentFile;", "uri", "Landroid/net/Uri;", "dir", "", "fileName", "dateModified", "", "generationModified", "size", "volume", "isFavorite", "", "ownerPackageName", "(Landroid/net/Uri;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Long;Ljava/lang/Long;JLjava/lang/String;ZLjava/lang/String;)V", "getDateModified", "()Ljava/lang/Long;", "Ljava/lang/Long;", "getDir", "()Ljava/lang/String;", "dirPath", "getDirPath", "getFileName", "getGenerationModified", "()Z", "lastModified", "getLastModified", "getOwnerPackageName", "getSize", "()J", "getUri", "()Landroid/net/Uri;", "getVolume", "component1", "component2", "component3", "component4", "component5", "component6", "component7", "component8", "component9", "copy", "(Landroid/net/Uri;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Long;Ljava/lang/Long;JLjava/lang/String;ZLjava/lang/String;)Lorg/calyxos/backup/storage/content/MediaFile;", "equals", "other", "", "hasNotChanged", "cachedFile", "Lorg/calyxos/backup/storage/db/CachedFile;", "hasNotChanged$main", "hashCode", "", "toBackupFile", "Lorg/calyxos/backup/storage/backup/BackupMediaFile;", "chunkIds", "", "zipIndex", "toBackupFile$main", "(Ljava/util/List;Ljava/lang/Integer;)Lorg/calyxos/backup/storage/backup/BackupMediaFile;", "toString"})
public final class MediaFile extends org.calyxos.backup.storage.content.ContentFile {
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String dirPath = null;
    @org.jetbrains.annotations.Nullable()
    private final java.lang.Long lastModified = null;
    @org.jetbrains.annotations.NotNull()
    private final android.net.Uri uri = null;
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String dir = null;
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String fileName = null;
    @org.jetbrains.annotations.Nullable()
    private final java.lang.Long dateModified = null;
    @org.jetbrains.annotations.Nullable()
    private final java.lang.Long generationModified = null;
    private final long size = 0L;
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String volume = null;
    private final boolean isFavorite = false;
    @org.jetbrains.annotations.Nullable()
    private final java.lang.String ownerPackageName = null;
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String getDirPath() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Long getLastModified() {
        return null;
    }
    
    @java.lang.Override()
    public boolean hasNotChanged$main(@org.jetbrains.annotations.Nullable()
    org.calyxos.backup.storage.db.CachedFile cachedFile) {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final org.calyxos.backup.storage.backup.BackupMediaFile toBackupFile$main(@org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> chunkIds, @org.jetbrains.annotations.Nullable()
    java.lang.Integer zipIndex) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.net.Uri getUri() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getDir() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String getFileName() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Long getDateModified() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Long getGenerationModified() {
        return null;
    }
    
    @java.lang.Override()
    public long getSize() {
        return 0L;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String getVolume() {
        return null;
    }
    
    public final boolean isFavorite() {
        return false;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String getOwnerPackageName() {
        return null;
    }
    
    public MediaFile(@org.jetbrains.annotations.NotNull()
    android.net.Uri uri, @org.jetbrains.annotations.NotNull()
    java.lang.String dir, @org.jetbrains.annotations.NotNull()
    java.lang.String fileName, @org.jetbrains.annotations.Nullable()
    java.lang.Long dateModified, @org.jetbrains.annotations.Nullable()
    java.lang.Long generationModified, long size, @org.jetbrains.annotations.NotNull()
    java.lang.String volume, boolean isFavorite, @org.jetbrains.annotations.Nullable()
    java.lang.String ownerPackageName) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.net.Uri component1() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String component2() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String component3() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Long component4() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Long component5() {
        return null;
    }
    
    public final long component6() {
        return 0L;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String component7() {
        return null;
    }
    
    public final boolean component8() {
        return false;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String component9() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final org.calyxos.backup.storage.content.MediaFile copy(@org.jetbrains.annotations.NotNull()
    android.net.Uri uri, @org.jetbrains.annotations.NotNull()
    java.lang.String dir, @org.jetbrains.annotations.NotNull()
    java.lang.String fileName, @org.jetbrains.annotations.Nullable()
    java.lang.Long dateModified, @org.jetbrains.annotations.Nullable()
    java.lang.Long generationModified, long size, @org.jetbrains.annotations.NotNull()
    java.lang.String volume, boolean isFavorite, @org.jetbrains.annotations.Nullable()
    java.lang.String ownerPackageName) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
}