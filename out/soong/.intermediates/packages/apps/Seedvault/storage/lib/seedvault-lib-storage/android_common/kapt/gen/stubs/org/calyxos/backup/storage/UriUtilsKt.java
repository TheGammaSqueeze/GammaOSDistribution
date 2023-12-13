package org.calyxos.backup.storage;

import android.content.ContentResolver;
import android.net.Uri;
import android.provider.MediaStore;
import org.calyxos.backup.storage.api.MediaType;
import org.calyxos.backup.storage.backup.BackupMediaFile;
import org.calyxos.backup.storage.db.StoredUri;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u00000\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\u001a\u000e\u0010\u0000\u001a\u0004\u0018\u00010\u0001*\u00020\u0002H\u0000\u001a\u000e\u0010\u0003\u001a\u0004\u0018\u00010\u0004*\u00020\u0002H\u0000\u001a\u000e\u0010\u0005\u001a\u0004\u0018\u00010\u0006*\u00020\u0002H\u0000\u001a\u000e\u0010\u0007\u001a\u0004\u0018\u00010\u0004*\u00020\u0002H\u0000\u001a\u0012\u0010\b\u001a\u00020\t*\u00020\u00022\u0006\u0010\n\u001a\u00020\u000b\u001a\u0012\u0010\f\u001a\u00020\r*\u00020\u00022\u0006\u0010\n\u001a\u00020\u000b\u001a\f\u0010\u000e\u001a\u00020\u000f*\u00020\u0002H\u0000"}, d2 = {"getBackupMediaType", "Lorg/calyxos/backup/storage/backup/BackupMediaFile$MediaType;", "Landroid/net/Uri;", "getDocumentPath", "", "getMediaType", "Lorg/calyxos/backup/storage/api/MediaType;", "getVolume", "openInputStream", "Ljava/io/InputStream;", "contentResolver", "Landroid/content/ContentResolver;", "openOutputStream", "Ljava/io/OutputStream;", "toStoredUri", "Lorg/calyxos/backup/storage/db/StoredUri;"})
public final class UriUtilsKt {
    
    @org.jetbrains.annotations.NotNull()
    public static final org.calyxos.backup.storage.db.StoredUri toStoredUri(@org.jetbrains.annotations.NotNull()
    android.net.Uri $this$toStoredUri) {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public static final java.lang.String getDocumentPath(@org.jetbrains.annotations.NotNull()
    android.net.Uri $this$getDocumentPath) {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public static final java.lang.String getVolume(@org.jetbrains.annotations.NotNull()
    android.net.Uri $this$getVolume) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public static final java.io.InputStream openInputStream(@org.jetbrains.annotations.NotNull()
    android.net.Uri $this$openInputStream, @org.jetbrains.annotations.NotNull()
    android.content.ContentResolver contentResolver) throws java.io.IOException {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public static final java.io.OutputStream openOutputStream(@org.jetbrains.annotations.NotNull()
    android.net.Uri $this$openOutputStream, @org.jetbrains.annotations.NotNull()
    android.content.ContentResolver contentResolver) throws java.io.IOException {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public static final org.calyxos.backup.storage.api.MediaType getMediaType(@org.jetbrains.annotations.NotNull()
    android.net.Uri $this$getMediaType) {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public static final org.calyxos.backup.storage.backup.BackupMediaFile.MediaType getBackupMediaType(@org.jetbrains.annotations.NotNull()
    android.net.Uri $this$getBackupMediaType) {
        return null;
    }
}