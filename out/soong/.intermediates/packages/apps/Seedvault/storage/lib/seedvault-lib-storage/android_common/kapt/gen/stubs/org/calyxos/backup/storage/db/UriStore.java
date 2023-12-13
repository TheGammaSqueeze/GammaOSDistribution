package org.calyxos.backup.storage.db;

import android.net.Uri;
import androidx.room.Dao;
import androidx.room.Delete;
import androidx.room.Entity;
import androidx.room.Insert;
import androidx.room.OnConflictStrategy;
import androidx.room.PrimaryKey;
import androidx.room.Query;

@androidx.room.Dao()
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0000\ba\u0018\u00002\u00020\u0001J\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H\'J\u000e\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\u00050\u0007H\'J\u0010\u0010\b\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H\'"}, d2 = {"Lorg/calyxos/backup/storage/db/UriStore;", "", "addStoredUri", "", "uri", "Lorg/calyxos/backup/storage/db/StoredUri;", "getStoredUris", "", "removeStoredUri"})
public abstract interface UriStore {
    
    @androidx.room.Insert(onConflict = androidx.room.OnConflictStrategy.IGNORE)
    public abstract void addStoredUri(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.db.StoredUri uri);
    
    @androidx.room.Delete()
    public abstract void removeStoredUri(@org.jetbrains.annotations.NotNull()
    org.calyxos.backup.storage.db.StoredUri uri);
    
    @org.jetbrains.annotations.NotNull()
    @androidx.room.Query(value = "SELECT * FROM StoredUri")
    public abstract java.util.List<org.calyxos.backup.storage.db.StoredUri> getStoredUris();
}