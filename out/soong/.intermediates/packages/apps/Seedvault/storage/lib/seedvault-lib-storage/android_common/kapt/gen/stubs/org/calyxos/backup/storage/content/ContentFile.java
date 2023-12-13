package org.calyxos.backup.storage.content;

import android.net.Uri;
import android.provider.MediaStore;
import android.util.Log;
import org.calyxos.backup.storage.api.BackupFile;
import org.calyxos.backup.storage.backup.BackupDocumentFile;
import org.calyxos.backup.storage.backup.BackupMediaFile;
import org.calyxos.backup.storage.db.CachedFile;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000J\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0005\n\u0002\u0010\t\n\u0002\b\r\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010 \n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\b0\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0015\u0010\u001d\u001a\u00020\u00182\u0006\u0010\u001e\u001a\u00020\u001fH\u0000\u00a2\u0006\u0002\b J\u0017\u0010!\u001a\u00020\u001f2\b\u0010\"\u001a\u0004\u0018\u00010#H\u0010\u00a2\u0006\u0002\b$J)\u0010%\u001a\u00020#2\f\u0010&\u001a\b\u0012\u0004\u0012\u00020\u00040\'2\n\b\u0002\u0010(\u001a\u0004\u0018\u00010)H\u0000\u00a2\u0006\u0004\b*\u0010+R\u0012\u0010\u0003\u001a\u00020\u0004X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0005\u0010\u0006R\u0012\u0010\u0007\u001a\u00020\u0004X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\b\u0010\u0006R\u0018\u0010\t\u001a\u0004\u0018\u00010\nX\u0096\u0004\u00a2\u0006\n\n\u0002\u0010\r\u001a\u0004\b\u000b\u0010\fR\u0014\u0010\u000e\u001a\u00020\u00048@X\u0080\u0004\u00a2\u0006\u0006\u001a\u0004\b\u000f\u0010\u0006R\u0014\u0010\u0010\u001a\u0004\u0018\u00010\nX\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0011\u0010\fR\u0014\u0010\u0012\u001a\u00020\u00048VX\u0096\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0013\u0010\u0006R\u0012\u0010\u0014\u001a\u00020\nX\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0015\u0010\u0016R\u0012\u0010\u0017\u001a\u00020\u0018X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0019\u0010\u001aR\u0012\u0010\u001b\u001a\u00020\u0004X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u001c\u0010\u0006\u0082\u0001\u0002,-"}, d2 = {"Lorg/calyxos/backup/storage/content/ContentFile;", "Lorg/calyxos/backup/storage/api/BackupFile;", "()V", "dirPath", "", "getDirPath", "()Ljava/lang/String;", "fileName", "getFileName", "generationModified", "", "getGenerationModified", "()Ljava/lang/Long;", "Ljava/lang/Long;", "id", "getId$main", "lastModified", "getLastModified", "path", "getPath", "size", "getSize", "()J", "uri", "Landroid/net/Uri;", "getUri", "()Landroid/net/Uri;", "volume", "getVolume", "getOriginalUri", "hasMediaAccessPerm", "", "getOriginalUri$main", "hasNotChanged", "cachedFile", "Lorg/calyxos/backup/storage/db/CachedFile;", "hasNotChanged$main", "toCachedFile", "chunkIds", "", "zipIndex", "", "toCachedFile$main", "(Ljava/util/List;Ljava/lang/Integer;)Lorg/calyxos/backup/storage/db/CachedFile;", "Lorg/calyxos/backup/storage/content/MediaFile;", "Lorg/calyxos/backup/storage/content/DocFile;"})
public abstract class ContentFile implements org.calyxos.backup.storage.api.BackupFile {
    @org.jetbrains.annotations.Nullable()
    private final java.lang.Long generationModified = null;
    
    @org.jetbrains.annotations.NotNull()
    public abstract android.net.Uri getUri();
    
    @org.jetbrains.annotations.NotNull()
    public abstract java.lang.String getDirPath();
    
    @org.jetbrains.annotations.NotNull()
    public abstract java.lang.String getFileName();
    
    @java.lang.Override()
    public abstract long getSize();
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public abstract java.lang.String getVolume();
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public abstract java.lang.Long getLastModified();
    
    @org.jetbrains.annotations.Nullable()
    public java.lang.Long getGenerationModified() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String getPath() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getId$main() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final org.calyxos.backup.storage.db.CachedFile toCachedFile$main(@org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> chunkIds, @org.jetbrains.annotations.Nullable()
    java.lang.Integer zipIndex) {
        return null;
    }
    
    /**
     * Returns an [Uri] that returns the original file for backup.
     * http://aosp.opersys.com/xref/android-11.0.0_r8/xref/packages/providers/MediaProvider/apex/framework/java/android/provider/MediaStore.java#751
     */
    @org.jetbrains.annotations.NotNull()
    public final android.net.Uri getOriginalUri$main(boolean hasMediaAccessPerm) {
        return null;
    }
    
    public boolean hasNotChanged$main(@org.jetbrains.annotations.Nullable()
    org.calyxos.backup.storage.db.CachedFile cachedFile) {
        return false;
    }
    
    private ContentFile() {
        super();
    }
}