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

@androidx.room.Dao()
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u001e\n\u0000\n\u0002\u0010\t\n\u0000\ba\u0018\u00002\u00020\u0001J\b\u0010\u0002\u001a\u00020\u0003H\'J\u0012\u0010\u0004\u001a\u0004\u0018\u00010\u00052\u0006\u0010\u0006\u001a\u00020\u0007H\'J\u0010\u0010\b\u001a\u00020\u00032\u0006\u0010\t\u001a\u00020\u0005H\'J\u0010\u0010\n\u001a\u00020\u00032\u0006\u0010\t\u001a\u00020\u0005H\'J \u0010\u000b\u001a\u00020\u00032\f\u0010\f\u001a\b\u0012\u0004\u0012\u00020\u00070\r2\b\b\u0002\u0010\u000e\u001a\u00020\u000fH\'J\u0010\u0010\u0010\u001a\u00020\u00032\u0006\u0010\t\u001a\u00020\u0005H\'"}, d2 = {"Lorg/calyxos/backup/storage/db/FilesCache;", "", "clear", "", "getByUri", "Lorg/calyxos/backup/storage/db/CachedFile;", "uri", "Landroid/net/Uri;", "insert", "file", "update", "updateLastSeen", "uris", "", "now", "", "upsert"})
public abstract interface FilesCache {
    
    @androidx.room.Insert()
    public abstract void insert(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.db.CachedFile file);
    
    @androidx.room.Insert(onConflict = androidx.room.OnConflictStrategy.REPLACE)
    public abstract void upsert(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.db.CachedFile file);
    
    @androidx.room.Update()
    public abstract void update(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.db.CachedFile file);
    
    @androidx.room.Query(value = "DELETE FROM CachedFile")
    public abstract void clear();
    
    @androidx.room.Query(value = "UPDATE CachedFile SET last_seen = :now WHERE uri IN (:uris)")
    public abstract void updateLastSeen(@org.jetbrains.annotations.NotNull()
    java.util.Collection<? extends android.net.Uri> uris, long now);
    
    @org.jetbrains.annotations.Nullable()
    @androidx.room.Query(value = "SELECT * FROM CachedFile WHERE uri == (:uri)")
    public abstract org.calyxos.backup.storage.db.CachedFile getByUri(@org.jetbrains.annotations.NotNull()
    android.net.Uri uri);
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 3)
    public final class DefaultImpls {
    }
}