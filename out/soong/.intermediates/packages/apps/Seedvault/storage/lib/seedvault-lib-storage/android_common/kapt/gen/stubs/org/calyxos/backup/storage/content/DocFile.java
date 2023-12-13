package org.calyxos.backup.storage.content;

import android.net.Uri;
import android.provider.MediaStore;
import android.util.Log;
import org.calyxos.backup.storage.api.BackupFile;
import org.calyxos.backup.storage.backup.BackupDocumentFile;
import org.calyxos.backup.storage.backup.BackupMediaFile;
import org.calyxos.backup.storage.db.CachedFile;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000@\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\t\n\u0002\b\u0017\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\b\u0004\b\u0080\b\u0018\u00002\u00020\u0001B7\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0005\u0012\b\u0010\u0007\u001a\u0004\u0018\u00010\b\u0012\u0006\u0010\t\u001a\u00020\b\u0012\u0006\u0010\n\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u000bJ\t\u0010\u0017\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u0018\u001a\u00020\u0005H\u00c6\u0003J\t\u0010\u0019\u001a\u00020\u0005H\u00c6\u0003J\u0010\u0010\u001a\u001a\u0004\u0018\u00010\bH\u00c6\u0003\u00a2\u0006\u0002\u0010\u0010J\t\u0010\u001b\u001a\u00020\bH\u00c6\u0003J\t\u0010\u001c\u001a\u00020\u0005H\u00c6\u0003JL\u0010\u001d\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00052\b\b\u0002\u0010\u0006\u001a\u00020\u00052\n\b\u0002\u0010\u0007\u001a\u0004\u0018\u00010\b2\b\b\u0002\u0010\t\u001a\u00020\b2\b\b\u0002\u0010\n\u001a\u00020\u0005H\u00c6\u0001\u00a2\u0006\u0002\u0010\u001eJ\u0013\u0010\u001f\u001a\u00020 2\b\u0010!\u001a\u0004\u0018\u00010\"H\u00d6\u0003J\t\u0010#\u001a\u00020$H\u00d6\u0001J)\u0010%\u001a\u00020&2\f\u0010\'\u001a\b\u0012\u0004\u0012\u00020\u00050(2\n\b\u0002\u0010)\u001a\u0004\u0018\u00010$H\u0000\u00a2\u0006\u0004\b*\u0010+J\t\u0010,\u001a\u00020\u0005H\u00d6\u0001R\u0014\u0010\u0004\u001a\u00020\u0005X\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\rR\u0014\u0010\u0006\u001a\u00020\u0005X\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000e\u0010\rR\u0018\u0010\u0007\u001a\u0004\u0018\u00010\bX\u0096\u0004\u00a2\u0006\n\n\u0002\u0010\u0011\u001a\u0004\b\u000f\u0010\u0010R\u0014\u0010\t\u001a\u00020\bX\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\u0013R\u0014\u0010\u0002\u001a\u00020\u0003X\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0014\u0010\u0015R\u0014\u0010\n\u001a\u00020\u0005X\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0016\u0010\r"}, d2 = {"Lorg/calyxos/backup/storage/content/DocFile;", "Lorg/calyxos/backup/storage/content/ContentFile;", "uri", "Landroid/net/Uri;", "dirPath", "", "fileName", "lastModified", "", "size", "volume", "(Landroid/net/Uri;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Long;JLjava/lang/String;)V", "getDirPath", "()Ljava/lang/String;", "getFileName", "getLastModified", "()Ljava/lang/Long;", "Ljava/lang/Long;", "getSize", "()J", "getUri", "()Landroid/net/Uri;", "getVolume", "component1", "component2", "component3", "component4", "component5", "component6", "copy", "(Landroid/net/Uri;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Long;JLjava/lang/String;)Lorg/calyxos/backup/storage/content/DocFile;", "equals", "", "other", "", "hashCode", "", "toBackupFile", "Lorg/calyxos/backup/storage/backup/BackupDocumentFile;", "chunkIds", "", "zipIndex", "toBackupFile$main", "(Ljava/util/List;Ljava/lang/Integer;)Lorg/calyxos/backup/storage/backup/BackupDocumentFile;", "toString"})
public final class DocFile extends org.calyxos.backup.storage.content.ContentFile {
    @org.jetbrains.annotations.NotNull()
    private final android.net.Uri uri = null;
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String dirPath = null;
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String fileName = null;
    @org.jetbrains.annotations.Nullable()
    private final java.lang.Long lastModified = null;
    private final long size = 0L;
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String volume = null;
    
    @org.jetbrains.annotations.NotNull()
    public final org.calyxos.backup.storage.backup.BackupDocumentFile toBackupFile$main(@org.jetbrains.annotations.NotNull()
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
    @java.lang.Override()
    public java.lang.String getDirPath() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String getFileName() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.Long getLastModified() {
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
    
    public DocFile(@org.jetbrains.annotations.NotNull()
    android.net.Uri uri, @org.jetbrains.annotations.NotNull()
    java.lang.String dirPath, @org.jetbrains.annotations.NotNull()
    java.lang.String fileName, @org.jetbrains.annotations.Nullable()
    java.lang.Long lastModified, long size, @org.jetbrains.annotations.NotNull()
    java.lang.String volume) {
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
    
    public final long component5() {
        return 0L;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String component6() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final org.calyxos.backup.storage.content.DocFile copy(@org.jetbrains.annotations.NotNull()
    android.net.Uri uri, @org.jetbrains.annotations.NotNull()
    java.lang.String dirPath, @org.jetbrains.annotations.NotNull()
    java.lang.String fileName, @org.jetbrains.annotations.Nullable()
    java.lang.Long lastModified, long size, @org.jetbrains.annotations.NotNull()
    java.lang.String volume) {
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