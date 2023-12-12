package org.calyxos.backup.storage.db;

import android.database.Cursor;
import androidx.room.EntityDeletionOrUpdateAdapter;
import androidx.room.EntityInsertionAdapter;
import androidx.room.RoomDatabase;
import androidx.room.RoomSQLiteQuery;
import androidx.room.SharedSQLiteStatement;
import androidx.room.util.CursorUtil;
import androidx.room.util.DBUtil;
import androidx.room.util.StringUtil;
import androidx.sqlite.db.SupportSQLiteStatement;
import java.lang.Class;
import java.lang.Override;
import java.lang.String;
import java.lang.StringBuilder;
import java.lang.SuppressWarnings;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;
import javax.annotation.processing.Generated;

@Generated("androidx.room.RoomProcessor")
@SuppressWarnings({"unchecked", "deprecation"})
public final class ChunksCache_Impl implements ChunksCache {
  private final RoomDatabase __db;

  private final EntityInsertionAdapter<CachedChunk> __insertionAdapterOfCachedChunk;

  private final EntityDeletionOrUpdateAdapter<CachedChunk> __deletionAdapterOfCachedChunk;

  private final SharedSQLiteStatement __preparedStmtOfClear;

  public ChunksCache_Impl(RoomDatabase __db) {
    this.__db = __db;
    this.__insertionAdapterOfCachedChunk = new EntityInsertionAdapter<CachedChunk>(__db) {
      @Override
      public String createQuery() {
        return "INSERT OR ABORT INTO `CachedChunk` (`id`,`ref_count`,`size`,`version`) VALUES (?,?,?,?)";
      }

      @Override
      public void bind(SupportSQLiteStatement stmt, CachedChunk value) {
        if (value.getId() == null) {
          stmt.bindNull(1);
        } else {
          stmt.bindString(1, value.getId());
        }
        stmt.bindLong(2, value.getRefCount());
        stmt.bindLong(3, value.getSize());
        stmt.bindLong(4, value.getVersion());
      }
    };
    this.__deletionAdapterOfCachedChunk = new EntityDeletionOrUpdateAdapter<CachedChunk>(__db) {
      @Override
      public String createQuery() {
        return "DELETE FROM `CachedChunk` WHERE `id` = ?";
      }

      @Override
      public void bind(SupportSQLiteStatement stmt, CachedChunk value) {
        if (value.getId() == null) {
          stmt.bindNull(1);
        } else {
          stmt.bindString(1, value.getId());
        }
      }
    };
    this.__preparedStmtOfClear = new SharedSQLiteStatement(__db) {
      @Override
      public String createQuery() {
        final String _query = "DELETE FROM CachedChunk";
        return _query;
      }
    };
  }

  @Override
  public void insert(final CachedChunk chunk) {
    __db.assertNotSuspendingTransaction();
    __db.beginTransaction();
    try {
      __insertionAdapterOfCachedChunk.insert(chunk);
      __db.setTransactionSuccessful();
    } finally {
      __db.endTransaction();
    }
  }

  @Override
  public void insert(final Collection<CachedChunk> chunks) {
    __db.assertNotSuspendingTransaction();
    __db.beginTransaction();
    try {
      __insertionAdapterOfCachedChunk.insert(chunks);
      __db.setTransactionSuccessful();
    } finally {
      __db.endTransaction();
    }
  }

  @Override
  public void deleteChunks(final List<CachedChunk> chunks) {
    __db.assertNotSuspendingTransaction();
    __db.beginTransaction();
    try {
      __deletionAdapterOfCachedChunk.handleMultiple(chunks);
      __db.setTransactionSuccessful();
    } finally {
      __db.endTransaction();
    }
  }

  @Override
  public void clear() {
    __db.assertNotSuspendingTransaction();
    final SupportSQLiteStatement _stmt = __preparedStmtOfClear.acquire();
    __db.beginTransaction();
    try {
      _stmt.executeUpdateDelete();
      __db.setTransactionSuccessful();
    } finally {
      __db.endTransaction();
      __preparedStmtOfClear.release(_stmt);
    }
  }

  @Override
  public CachedChunk get(final String id) {
    final String _sql = "SELECT * FROM CachedChunk WHERE id == (?)";
    final RoomSQLiteQuery _statement = RoomSQLiteQuery.acquire(_sql, 1);
    int _argIndex = 1;
    if (id == null) {
      _statement.bindNull(_argIndex);
    } else {
      _statement.bindString(_argIndex, id);
    }
    __db.assertNotSuspendingTransaction();
    final Cursor _cursor = DBUtil.query(__db, _statement, false, null);
    try {
      final int _cursorIndexOfId = CursorUtil.getColumnIndexOrThrow(_cursor, "id");
      final int _cursorIndexOfRefCount = CursorUtil.getColumnIndexOrThrow(_cursor, "ref_count");
      final int _cursorIndexOfSize = CursorUtil.getColumnIndexOrThrow(_cursor, "size");
      final int _cursorIndexOfVersion = CursorUtil.getColumnIndexOrThrow(_cursor, "version");
      final CachedChunk _result;
      if(_cursor.moveToFirst()) {
        final String _tmpId;
        if (_cursor.isNull(_cursorIndexOfId)) {
          _tmpId = null;
        } else {
          _tmpId = _cursor.getString(_cursorIndexOfId);
        }
        final long _tmpRefCount;
        _tmpRefCount = _cursor.getLong(_cursorIndexOfRefCount);
        final long _tmpSize;
        _tmpSize = _cursor.getLong(_cursorIndexOfSize);
        final byte _tmpVersion;
        _tmpVersion = (byte) _cursor.getShort(_cursorIndexOfVersion);
        _result = new CachedChunk(_tmpId,_tmpRefCount,_tmpSize,_tmpVersion);
      } else {
        _result = null;
      }
      return _result;
    } finally {
      _cursor.close();
      _statement.release();
    }
  }

  @Override
  public int getNumberOfCachedChunks(final Collection<String> ids) {
    StringBuilder _stringBuilder = StringUtil.newStringBuilder();
    _stringBuilder.append("SELECT COUNT(id) FROM CachedChunk WHERE id IN (");
    final int _inputSize = ids.size();
    StringUtil.appendPlaceholders(_stringBuilder, _inputSize);
    _stringBuilder.append(")");
    final String _sql = _stringBuilder.toString();
    final int _argCount = 0 + _inputSize;
    final RoomSQLiteQuery _statement = RoomSQLiteQuery.acquire(_sql, _argCount);
    int _argIndex = 1;
    for (String _item : ids) {
      if (_item == null) {
        _statement.bindNull(_argIndex);
      } else {
        _statement.bindString(_argIndex, _item);
      }
      _argIndex ++;
    }
    __db.assertNotSuspendingTransaction();
    final Cursor _cursor = DBUtil.query(__db, _statement, false, null);
    try {
      final int _result;
      if(_cursor.moveToFirst()) {
        _result = _cursor.getInt(0);
      } else {
        _result = 0;
      }
      return _result;
    } finally {
      _cursor.close();
      _statement.release();
    }
  }

  @Override
  public List<CachedChunk> getUnreferencedChunks() {
    final String _sql = "SELECT * FROM CachedChunk WHERE ref_count <= 0";
    final RoomSQLiteQuery _statement = RoomSQLiteQuery.acquire(_sql, 0);
    __db.assertNotSuspendingTransaction();
    final Cursor _cursor = DBUtil.query(__db, _statement, false, null);
    try {
      final int _cursorIndexOfId = CursorUtil.getColumnIndexOrThrow(_cursor, "id");
      final int _cursorIndexOfRefCount = CursorUtil.getColumnIndexOrThrow(_cursor, "ref_count");
      final int _cursorIndexOfSize = CursorUtil.getColumnIndexOrThrow(_cursor, "size");
      final int _cursorIndexOfVersion = CursorUtil.getColumnIndexOrThrow(_cursor, "version");
      final List<CachedChunk> _result = new ArrayList<CachedChunk>(_cursor.getCount());
      while(_cursor.moveToNext()) {
        final CachedChunk _item;
        final String _tmpId;
        if (_cursor.isNull(_cursorIndexOfId)) {
          _tmpId = null;
        } else {
          _tmpId = _cursor.getString(_cursorIndexOfId);
        }
        final long _tmpRefCount;
        _tmpRefCount = _cursor.getLong(_cursorIndexOfRefCount);
        final long _tmpSize;
        _tmpSize = _cursor.getLong(_cursorIndexOfSize);
        final byte _tmpVersion;
        _tmpVersion = (byte) _cursor.getShort(_cursorIndexOfVersion);
        _item = new CachedChunk(_tmpId,_tmpRefCount,_tmpSize,_tmpVersion);
        _result.add(_item);
      }
      return _result;
    } finally {
      _cursor.close();
      _statement.release();
    }
  }

  @Override
  public void incrementRefCount(final Collection<String> ids) {
    __db.assertNotSuspendingTransaction();
    StringBuilder _stringBuilder = StringUtil.newStringBuilder();
    _stringBuilder.append("UPDATE CachedChunk SET ref_count = ref_count + 1 WHERE id IN (");
    final int _inputSize = ids.size();
    StringUtil.appendPlaceholders(_stringBuilder, _inputSize);
    _stringBuilder.append(")");
    final String _sql = _stringBuilder.toString();
    final SupportSQLiteStatement _stmt = __db.compileStatement(_sql);
    int _argIndex = 1;
    for (String _item : ids) {
      if (_item == null) {
        _stmt.bindNull(_argIndex);
      } else {
        _stmt.bindString(_argIndex, _item);
      }
      _argIndex ++;
    }
    __db.beginTransaction();
    try {
      _stmt.executeUpdateDelete();
      __db.setTransactionSuccessful();
    } finally {
      __db.endTransaction();
    }
  }

  @Override
  public void decrementRefCount(final Collection<String> ids) {
    __db.assertNotSuspendingTransaction();
    StringBuilder _stringBuilder = StringUtil.newStringBuilder();
    _stringBuilder.append("UPDATE CachedChunk SET ref_count = ref_count - 1 WHERE id IN (");
    final int _inputSize = ids.size();
    StringUtil.appendPlaceholders(_stringBuilder, _inputSize);
    _stringBuilder.append(")");
    final String _sql = _stringBuilder.toString();
    final SupportSQLiteStatement _stmt = __db.compileStatement(_sql);
    int _argIndex = 1;
    for (String _item : ids) {
      if (_item == null) {
        _stmt.bindNull(_argIndex);
      } else {
        _stmt.bindString(_argIndex, _item);
      }
      _argIndex ++;
    }
    __db.beginTransaction();
    try {
      _stmt.executeUpdateDelete();
      __db.setTransactionSuccessful();
    } finally {
      __db.endTransaction();
    }
  }

  @Override
  public boolean areAllAvailableChunksCached(final Db db,
      final Collection<String> availableChunks) {
    return ChunksCache.DefaultImpls.areAllAvailableChunksCached(ChunksCache_Impl.this, db, availableChunks);
  }

  @Override
  public void clearAndRepopulate(final Db db, final Collection<CachedChunk> chunks) {
    ChunksCache.DefaultImpls.clearAndRepopulate(ChunksCache_Impl.this, db, chunks);
  }

  public static List<Class<?>> getRequiredConverters() {
    return Collections.emptyList();
  }
}
