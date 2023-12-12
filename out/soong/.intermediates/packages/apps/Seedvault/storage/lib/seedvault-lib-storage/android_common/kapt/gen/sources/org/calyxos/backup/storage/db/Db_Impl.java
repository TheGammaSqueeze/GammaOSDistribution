package org.calyxos.backup.storage.db;

import androidx.room.DatabaseConfiguration;
import androidx.room.InvalidationTracker;
import androidx.room.RoomOpenHelper;
import androidx.room.RoomOpenHelper.Delegate;
import androidx.room.RoomOpenHelper.ValidationResult;
import androidx.room.util.DBUtil;
import androidx.room.util.TableInfo;
import androidx.room.util.TableInfo.Column;
import androidx.room.util.TableInfo.ForeignKey;
import androidx.room.util.TableInfo.Index;
import androidx.sqlite.db.SupportSQLiteDatabase;
import androidx.sqlite.db.SupportSQLiteOpenHelper;
import androidx.sqlite.db.SupportSQLiteOpenHelper.Callback;
import androidx.sqlite.db.SupportSQLiteOpenHelper.Configuration;
import java.lang.Class;
import java.lang.Override;
import java.lang.String;
import java.lang.SuppressWarnings;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import javax.annotation.processing.Generated;

@Generated("androidx.room.RoomProcessor")
@SuppressWarnings({"unchecked", "deprecation"})
public final class Db_Impl extends Db {
  private volatile UriStore _uriStore;

  private volatile FilesCache _filesCache;

  private volatile ChunksCache _chunksCache;

  @Override
  protected SupportSQLiteOpenHelper createOpenHelper(DatabaseConfiguration configuration) {
    final SupportSQLiteOpenHelper.Callback _openCallback = new RoomOpenHelper(configuration, new RoomOpenHelper.Delegate(1) {
      @Override
      public void createAllTables(SupportSQLiteDatabase _db) {
        _db.execSQL("CREATE TABLE IF NOT EXISTS `StoredUri` (`uri` TEXT NOT NULL, PRIMARY KEY(`uri`))");
        _db.execSQL("CREATE TABLE IF NOT EXISTS `CachedFile` (`uri` TEXT NOT NULL, `size` INTEGER NOT NULL, `last_modified` INTEGER, `generation_modified` INTEGER, `chunks` TEXT NOT NULL, `zip_index` INTEGER, `last_seen` INTEGER NOT NULL, PRIMARY KEY(`uri`))");
        _db.execSQL("CREATE TABLE IF NOT EXISTS `CachedChunk` (`id` TEXT NOT NULL, `ref_count` INTEGER NOT NULL, `size` INTEGER NOT NULL, `version` INTEGER NOT NULL, PRIMARY KEY(`id`))");
        _db.execSQL("CREATE TABLE IF NOT EXISTS room_master_table (id INTEGER PRIMARY KEY,identity_hash TEXT)");
        _db.execSQL("INSERT OR REPLACE INTO room_master_table (id,identity_hash) VALUES(42, '6286a22113131a780d1a28ba059d5a6d')");
      }

      @Override
      public void dropAllTables(SupportSQLiteDatabase _db) {
        _db.execSQL("DROP TABLE IF EXISTS `StoredUri`");
        _db.execSQL("DROP TABLE IF EXISTS `CachedFile`");
        _db.execSQL("DROP TABLE IF EXISTS `CachedChunk`");
        if (mCallbacks != null) {
          for (int _i = 0, _size = mCallbacks.size(); _i < _size; _i++) {
            mCallbacks.get(_i).onDestructiveMigration(_db);
          }
        }
      }

      @Override
      protected void onCreate(SupportSQLiteDatabase _db) {
        if (mCallbacks != null) {
          for (int _i = 0, _size = mCallbacks.size(); _i < _size; _i++) {
            mCallbacks.get(_i).onCreate(_db);
          }
        }
      }

      @Override
      public void onOpen(SupportSQLiteDatabase _db) {
        mDatabase = _db;
        internalInitInvalidationTracker(_db);
        if (mCallbacks != null) {
          for (int _i = 0, _size = mCallbacks.size(); _i < _size; _i++) {
            mCallbacks.get(_i).onOpen(_db);
          }
        }
      }

      @Override
      public void onPreMigrate(SupportSQLiteDatabase _db) {
        DBUtil.dropFtsSyncTriggers(_db);
      }

      @Override
      public void onPostMigrate(SupportSQLiteDatabase _db) {
      }

      @Override
      protected RoomOpenHelper.ValidationResult onValidateSchema(SupportSQLiteDatabase _db) {
        final HashMap<String, TableInfo.Column> _columnsStoredUri = new HashMap<String, TableInfo.Column>(1);
        _columnsStoredUri.put("uri", new TableInfo.Column("uri", "TEXT", true, 1, null, TableInfo.CREATED_FROM_ENTITY));
        final HashSet<TableInfo.ForeignKey> _foreignKeysStoredUri = new HashSet<TableInfo.ForeignKey>(0);
        final HashSet<TableInfo.Index> _indicesStoredUri = new HashSet<TableInfo.Index>(0);
        final TableInfo _infoStoredUri = new TableInfo("StoredUri", _columnsStoredUri, _foreignKeysStoredUri, _indicesStoredUri);
        final TableInfo _existingStoredUri = TableInfo.read(_db, "StoredUri");
        if (! _infoStoredUri.equals(_existingStoredUri)) {
          return new RoomOpenHelper.ValidationResult(false, "StoredUri(org.calyxos.backup.storage.db.StoredUri).\n"
                  + " Expected:\n" + _infoStoredUri + "\n"
                  + " Found:\n" + _existingStoredUri);
        }
        final HashMap<String, TableInfo.Column> _columnsCachedFile = new HashMap<String, TableInfo.Column>(7);
        _columnsCachedFile.put("uri", new TableInfo.Column("uri", "TEXT", true, 1, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsCachedFile.put("size", new TableInfo.Column("size", "INTEGER", true, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsCachedFile.put("last_modified", new TableInfo.Column("last_modified", "INTEGER", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsCachedFile.put("generation_modified", new TableInfo.Column("generation_modified", "INTEGER", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsCachedFile.put("chunks", new TableInfo.Column("chunks", "TEXT", true, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsCachedFile.put("zip_index", new TableInfo.Column("zip_index", "INTEGER", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsCachedFile.put("last_seen", new TableInfo.Column("last_seen", "INTEGER", true, 0, null, TableInfo.CREATED_FROM_ENTITY));
        final HashSet<TableInfo.ForeignKey> _foreignKeysCachedFile = new HashSet<TableInfo.ForeignKey>(0);
        final HashSet<TableInfo.Index> _indicesCachedFile = new HashSet<TableInfo.Index>(0);
        final TableInfo _infoCachedFile = new TableInfo("CachedFile", _columnsCachedFile, _foreignKeysCachedFile, _indicesCachedFile);
        final TableInfo _existingCachedFile = TableInfo.read(_db, "CachedFile");
        if (! _infoCachedFile.equals(_existingCachedFile)) {
          return new RoomOpenHelper.ValidationResult(false, "CachedFile(org.calyxos.backup.storage.db.CachedFile).\n"
                  + " Expected:\n" + _infoCachedFile + "\n"
                  + " Found:\n" + _existingCachedFile);
        }
        final HashMap<String, TableInfo.Column> _columnsCachedChunk = new HashMap<String, TableInfo.Column>(4);
        _columnsCachedChunk.put("id", new TableInfo.Column("id", "TEXT", true, 1, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsCachedChunk.put("ref_count", new TableInfo.Column("ref_count", "INTEGER", true, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsCachedChunk.put("size", new TableInfo.Column("size", "INTEGER", true, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsCachedChunk.put("version", new TableInfo.Column("version", "INTEGER", true, 0, null, TableInfo.CREATED_FROM_ENTITY));
        final HashSet<TableInfo.ForeignKey> _foreignKeysCachedChunk = new HashSet<TableInfo.ForeignKey>(0);
        final HashSet<TableInfo.Index> _indicesCachedChunk = new HashSet<TableInfo.Index>(0);
        final TableInfo _infoCachedChunk = new TableInfo("CachedChunk", _columnsCachedChunk, _foreignKeysCachedChunk, _indicesCachedChunk);
        final TableInfo _existingCachedChunk = TableInfo.read(_db, "CachedChunk");
        if (! _infoCachedChunk.equals(_existingCachedChunk)) {
          return new RoomOpenHelper.ValidationResult(false, "CachedChunk(org.calyxos.backup.storage.db.CachedChunk).\n"
                  + " Expected:\n" + _infoCachedChunk + "\n"
                  + " Found:\n" + _existingCachedChunk);
        }
        return new RoomOpenHelper.ValidationResult(true, null);
      }
    }, "6286a22113131a780d1a28ba059d5a6d", "8e8b1beef0fbfef08b8374bf3b7d906a");
    final SupportSQLiteOpenHelper.Configuration _sqliteConfig = SupportSQLiteOpenHelper.Configuration.builder(configuration.context)
        .name(configuration.name)
        .callback(_openCallback)
        .build();
    final SupportSQLiteOpenHelper _helper = configuration.sqliteOpenHelperFactory.create(_sqliteConfig);
    return _helper;
  }

  @Override
  protected InvalidationTracker createInvalidationTracker() {
    final HashMap<String, String> _shadowTablesMap = new HashMap<String, String>(0);
    HashMap<String, Set<String>> _viewTables = new HashMap<String, Set<String>>(0);
    return new InvalidationTracker(this, _shadowTablesMap, _viewTables, "StoredUri","CachedFile","CachedChunk");
  }

  @Override
  public void clearAllTables() {
    super.assertNotMainThread();
    final SupportSQLiteDatabase _db = super.getOpenHelper().getWritableDatabase();
    try {
      super.beginTransaction();
      _db.execSQL("DELETE FROM `StoredUri`");
      _db.execSQL("DELETE FROM `CachedFile`");
      _db.execSQL("DELETE FROM `CachedChunk`");
      super.setTransactionSuccessful();
    } finally {
      super.endTransaction();
      _db.query("PRAGMA wal_checkpoint(FULL)").close();
      if (!_db.inTransaction()) {
        _db.execSQL("VACUUM");
      }
    }
  }

  @Override
  protected Map<Class<?>, List<Class<?>>> getRequiredTypeConverters() {
    final HashMap<Class<?>, List<Class<?>>> _typeConvertersMap = new HashMap<Class<?>, List<Class<?>>>();
    _typeConvertersMap.put(UriStore.class, UriStore_Impl.getRequiredConverters());
    _typeConvertersMap.put(FilesCache.class, FilesCache_Impl.getRequiredConverters());
    _typeConvertersMap.put(ChunksCache.class, ChunksCache_Impl.getRequiredConverters());
    return _typeConvertersMap;
  }

  @Override
  public UriStore getUriStore() {
    if (_uriStore != null) {
      return _uriStore;
    } else {
      synchronized(this) {
        if(_uriStore == null) {
          _uriStore = new UriStore_Impl(this);
        }
        return _uriStore;
      }
    }
  }

  @Override
  public FilesCache getFilesCache() {
    if (_filesCache != null) {
      return _filesCache;
    } else {
      synchronized(this) {
        if(_filesCache == null) {
          _filesCache = new FilesCache_Impl(this);
        }
        return _filesCache;
      }
    }
  }

  @Override
  public ChunksCache getChunksCache() {
    if (_chunksCache != null) {
      return _chunksCache;
    } else {
      synchronized(this) {
        if(_chunksCache == null) {
          _chunksCache = new ChunksCache_Impl(this);
        }
        return _chunksCache;
      }
    }
  }
}
