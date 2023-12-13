package org.calyxos.backup.storage.db;

import android.net.Uri;
import androidx.room.ColumnInfo;
import androidx.room.Dao;
import androidx.room.Entity;
import androidx.room.Insert;
import androidx.room.OnConflictStrategy;
import androidx.room.PrimaryKey;
import androidx.room.Query;
import androidx.room.Update;

@androidx.room.Entity()
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00002\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\n\u0002\b\u0003\n\u0002\u0010 \n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\b\n\u0002\b\u001a\n\u0002\u0010\u000b\n\u0002\b\u0003\b\u0081\b\u0018\u00002\u00020\u0001BM\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\b\u0010\u0006\u001a\u0004\u0018\u00010\u0005\u0012\n\b\u0002\u0010\u0007\u001a\u0004\u0018\u00010\u0005\u0012\f\u0010\b\u001a\b\u0012\u0004\u0012\u00020\n0\t\u0012\n\b\u0002\u0010\u000b\u001a\u0004\u0018\u00010\f\u0012\u0006\u0010\r\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u000eJ\t\u0010\u001d\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u001e\u001a\u00020\u0005H\u00c6\u0003J\u0010\u0010\u001f\u001a\u0004\u0018\u00010\u0005H\u00c6\u0003\u00a2\u0006\u0002\u0010\u0012J\u0010\u0010 \u001a\u0004\u0018\u00010\u0005H\u00c6\u0003\u00a2\u0006\u0002\u0010\u0012J\u000f\u0010!\u001a\b\u0012\u0004\u0012\u00020\n0\tH\u00c6\u0003J\u0010\u0010\"\u001a\u0004\u0018\u00010\fH\u00c6\u0003\u00a2\u0006\u0002\u0010\u001bJ\t\u0010#\u001a\u00020\u0005H\u00c6\u0003J`\u0010$\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00052\n\b\u0002\u0010\u0006\u001a\u0004\u0018\u00010\u00052\n\b\u0002\u0010\u0007\u001a\u0004\u0018\u00010\u00052\u000e\b\u0002\u0010\b\u001a\b\u0012\u0004\u0012\u00020\n0\t2\n\b\u0002\u0010\u000b\u001a\u0004\u0018\u00010\f2\b\b\u0002\u0010\r\u001a\u00020\u0005H\u00c6\u0001\u00a2\u0006\u0002\u0010%J\u0013\u0010&\u001a\u00020\'2\b\u0010(\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010)\u001a\u00020\fH\u00d6\u0001J\t\u0010*\u001a\u00020\nH\u00d6\u0001R\u0017\u0010\b\u001a\b\u0012\u0004\u0012\u00020\n0\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\u0010R\u001a\u0010\u0007\u001a\u0004\u0018\u00010\u00058\u0006X\u0087\u0004\u00a2\u0006\n\n\u0002\u0010\u0013\u001a\u0004\b\u0011\u0010\u0012R\u001a\u0010\u0006\u001a\u0004\u0018\u00010\u00058\u0006X\u0087\u0004\u00a2\u0006\n\n\u0002\u0010\u0013\u001a\u0004\b\u0014\u0010\u0012R\u0016\u0010\r\u001a\u00020\u00058\u0006X\u0087\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0015\u0010\u0016R\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0017\u0010\u0016R\u0016\u0010\u0002\u001a\u00020\u00038\u0006X\u0087\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0018\u0010\u0019R\u001a\u0010\u000b\u001a\u0004\u0018\u00010\f8\u0006X\u0087\u0004\u00a2\u0006\n\n\u0002\u0010\u001c\u001a\u0004\b\u001a\u0010\u001b"}, d2 = {"Lorg/calyxos/backup/storage/db/CachedFile;", "", "uri", "Landroid/net/Uri;", "size", "", "lastModified", "generationModified", "chunks", "", "", "zipIndex", "", "lastSeen", "(Landroid/net/Uri;JLjava/lang/Long;Ljava/lang/Long;Ljava/util/List;Ljava/lang/Integer;J)V", "getChunks", "()Ljava/util/List;", "getGenerationModified", "()Ljava/lang/Long;", "Ljava/lang/Long;", "getLastModified", "getLastSeen", "()J", "getSize", "getUri", "()Landroid/net/Uri;", "getZipIndex", "()Ljava/lang/Integer;", "Ljava/lang/Integer;", "component1", "component2", "component3", "component4", "component5", "component6", "component7", "copy", "(Landroid/net/Uri;JLjava/lang/Long;Ljava/lang/Long;Ljava/util/List;Ljava/lang/Integer;J)Lorg/calyxos/backup/storage/db/CachedFile;", "equals", "", "other", "hashCode", "toString"})
public final class CachedFile {
    @org.jetbrains.annotations.NotNull()
    @androidx.room.PrimaryKey()
    private final android.net.Uri uri = null;
    private final long size = 0L;
    @org.jetbrains.annotations.Nullable()
    @androidx.room.ColumnInfo(name = "last_modified")
    private final java.lang.Long lastModified = null;
    @org.jetbrains.annotations.Nullable()
    @androidx.room.ColumnInfo(name = "generation_modified")
    private final java.lang.Long generationModified = null;
    @org.jetbrains.annotations.NotNull()
    private final java.util.List<java.lang.String> chunks = null;
    
    /**
     * The index in the single Zip Chunk.
     * If this is not null, [chunks] must be of size 1.
     */
    @org.jetbrains.annotations.Nullable()
    @androidx.room.ColumnInfo(name = "zip_index")
    private final java.lang.Integer zipIndex = null;
    @androidx.room.ColumnInfo(name = "last_seen")
    private final long lastSeen = 0L;
    
    @org.jetbrains.annotations.NotNull()
    public final android.net.Uri getUri() {
        return null;
    }
    
    public final long getSize() {
        return 0L;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Long getLastModified() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Long getGenerationModified() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<java.lang.String> getChunks() {
        return null;
    }
    
    /**
     * The index in the single Zip Chunk.
     * If this is not null, [chunks] must be of size 1.
     */
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Integer getZipIndex() {
        return null;
    }
    
    public final long getLastSeen() {
        return 0L;
    }
    
    public CachedFile(@org.jetbrains.annotations.NotNull()
    android.net.Uri uri, long size, @org.jetbrains.annotations.Nullable()
    java.lang.Long lastModified, @org.jetbrains.annotations.Nullable()
    java.lang.Long generationModified, @org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> chunks, @org.jetbrains.annotations.Nullable()
    java.lang.Integer zipIndex, long lastSeen) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.net.Uri component1() {
        return null;
    }
    
    public final long component2() {
        return 0L;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Long component3() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Long component4() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<java.lang.String> component5() {
        return null;
    }
    
    /**
     * The index in the single Zip Chunk.
     * If this is not null, [chunks] must be of size 1.
     */
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Integer component6() {
        return null;
    }
    
    public final long component7() {
        return 0L;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final org.calyxos.backup.storage.db.CachedFile copy(@org.jetbrains.annotations.NotNull()
    android.net.Uri uri, long size, @org.jetbrains.annotations.Nullable()
    java.lang.Long lastModified, @org.jetbrains.annotations.Nullable()
    java.lang.Long generationModified, @org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> chunks, @org.jetbrains.annotations.Nullable()
    java.lang.Integer zipIndex, long lastSeen) {
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