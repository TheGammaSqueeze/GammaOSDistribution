package org.calyxos.backup.storage.db;

import android.net.Uri;
import androidx.room.Database;
import androidx.room.RoomDatabase;
import androidx.room.TypeConverter;
import androidx.room.TypeConverters;

@androidx.room.TypeConverters(value = {org.calyxos.backup.storage.db.Converters.class})
@androidx.room.Database(version = 1, exportSchema = false, entities = {org.calyxos.backup.storage.db.StoredUri.class, org.calyxos.backup.storage.db.CachedFile.class, org.calyxos.backup.storage.db.CachedChunk.class})
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00006\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0010\u001e\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\b!\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002JC\u0010\u0003\u001a\u00020\u0004\"\u0004\b\u0000\u0010\u00052\f\u0010\u0006\u001a\b\u0012\u0004\u0012\u0002H\u00050\u00072\'\u0010\b\u001a#\u0012\u0019\u0012\u0017\u0012\u0004\u0012\u0002H\u00050\u0007\u00a2\u0006\f\b\n\u0012\b\b\u000b\u0012\u0004\b\b(\u0006\u0012\u0004\u0012\u00020\u00040\tJ\b\u0010\f\u001a\u00020\rH&J\b\u0010\u000e\u001a\u00020\u000fH&J\b\u0010\u0010\u001a\u00020\u0011H&"}, d2 = {"Lorg/calyxos/backup/storage/db/Db;", "Landroidx/room/RoomDatabase;", "()V", "applyInParts", "", "T", "list", "", "apply", "Lkotlin/Function1;", "Lkotlin/ParameterName;", "name", "getChunksCache", "Lorg/calyxos/backup/storage/db/ChunksCache;", "getFilesCache", "Lorg/calyxos/backup/storage/db/FilesCache;", "getUriStore", "Lorg/calyxos/backup/storage/db/UriStore;"})
public abstract class Db extends androidx.room.RoomDatabase {
    
    @org.jetbrains.annotations.NotNull()
    public abstract org.calyxos.backup.storage.db.UriStore getUriStore();
    
    @org.jetbrains.annotations.NotNull()
    public abstract org.calyxos.backup.storage.db.FilesCache getFilesCache();
    
    @org.jetbrains.annotations.NotNull()
    public abstract org.calyxos.backup.storage.db.ChunksCache getChunksCache();
    
    public final <T extends java.lang.Object>void applyInParts(@org.jetbrains.annotations.NotNull()
    java.util.Collection<? extends T> list, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super java.util.Collection<? extends T>, kotlin.Unit> apply) {
    }
    
    public Db() {
        super();
    }
}