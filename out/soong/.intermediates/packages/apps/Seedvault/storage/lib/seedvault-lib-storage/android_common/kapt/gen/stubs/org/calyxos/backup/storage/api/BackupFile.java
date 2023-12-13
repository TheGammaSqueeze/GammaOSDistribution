package org.calyxos.backup.storage.api;

import android.provider.MediaStore;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001a\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\t\n\u0002\b\u0003\n\u0002\u0010\u000e\n\u0002\b\u0007\bf\u0018\u00002\u00020\u0001R\u0014\u0010\u0002\u001a\u0004\u0018\u00010\u0003X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0004\u0010\u0005R\u0012\u0010\u0006\u001a\u00020\u0007X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\b\u0010\tR\u0012\u0010\n\u001a\u00020\u0003X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u000b\u0010\fR\u0012\u0010\r\u001a\u00020\u0007X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u000e\u0010\t"}, d2 = {"Lorg/calyxos/backup/storage/api/BackupFile;", "", "lastModified", "", "getLastModified", "()Ljava/lang/Long;", "path", "", "getPath", "()Ljava/lang/String;", "size", "getSize", "()J", "volume", "getVolume"})
public abstract interface BackupFile {
    
    @org.jetbrains.annotations.NotNull()
    public abstract java.lang.String getPath();
    
    /**
     * empty string for [MediaStore.VOLUME_EXTERNAL_PRIMARY]
     */
    @org.jetbrains.annotations.NotNull()
    public abstract java.lang.String getVolume();
    
    public abstract long getSize();
    
    @org.jetbrains.annotations.Nullable()
    public abstract java.lang.Long getLastModified();
}