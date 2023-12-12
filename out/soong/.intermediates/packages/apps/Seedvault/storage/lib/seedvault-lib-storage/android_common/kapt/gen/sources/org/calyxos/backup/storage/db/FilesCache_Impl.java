package org.calyxos.backup.storage.db;

import android.database.Cursor;
import android.net.Uri;
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
import java.lang.Integer;
import java.lang.Long;
import java.lang.Override;
import java.lang.String;
import java.lang.StringBuilder;
import java.lang.SuppressWarnings;
import java.util.Collection;
import java.util.Collections;
import java.util.List;
import javax.annotation.processing.Generated;

@Generated("androidx.room.RoomProcessor")
@SuppressWarnings({"unchecked", "deprecation"})
public final class FilesCache_Impl implements FilesCache {
  private final RoomDatabase __db;

  private final EntityInsertionAdapter<CachedFile> __insertionAdapterOfCachedFile;

  private final Converters __converters = new Converters();

  private final EntityInsertionAdapter<CachedFile> __insertionAdapterOfCachedFile_1;

  private final EntityDeletionOrUpdateAdapter<CachedFile> __updateAdapterOfCachedFile;

  private final SharedSQLiteStatement __preparedStmtOfClear;

  public FilesCache_Impl(RoomDatabase __db) {
    this.__db = __db;
    this.__insertionAdapterOfCachedFile = new EntityInsertionAdapter<CachedFile>(__db) {
      @Override
      public String createQuery() {
        return "INSERT OR ABORT INTO `CachedFile` (`uri`,`size`,`last_modified`,`generation_modified`,`chunks`,`zip_index`,`last_seen`) VALUES (?,?,?,?,?,?,?)";
      }

      @Override
      public void bind(SupportSQLiteStatement stmt, CachedFile value) {
        final String _tmp;
        _tmp = __converters.uriToString(value.getUri());
        if (_tmp == null) {
          stmt.bindNull(1);
        } else {
          stmt.bindString(1, _tmp);
        }
        stmt.bindLong(2, value.getSize());
        if (value.getLastModified() == null) {
          stmt.bindNull(3);
        } else {
          stmt.bindLong(3, value.getLastModified());
        }
        if (value.getGenerationModified() == null) {
          stmt.bindNull(4);
        } else {
          stmt.bindLong(4, value.getGenerationModified());
        }
        final String _tmp_1;
        _tmp_1 = __converters.chunkIdsToString(value.getChunks());
        if (_tmp_1 == null) {
          stmt.bindNull(5);
        } else {
          stmt.bindString(5, _tmp_1);
        }
        if (value.getZipIndex() == null) {
          stmt.bindNull(6);
        } else {
          stmt.bindLong(6, value.getZipIndex());
        }
        stmt.bindLong(7, value.getLastSeen());
      }
    };
    this.__insertionAdapterOfCachedFile_1 = new EntityInsertionAdapter<CachedFile>(__db) {
      @Override
      public String createQuery() {
        return "INSERT OR REPLACE INTO `CachedFile` (`uri`,`size`,`last_modified`,`generation_modified`,`chunks`,`zip_index`,`last_seen`) VALUES (?,?,?,?,?,?,?)";
      }

      @Override
      public void bind(SupportSQLiteStatement stmt, CachedFile value) {
        final String _tmp;
        _tmp = __converters.uriToString(value.getUri());
        if (_tmp == null) {
          stmt.bindNull(1);
        } else {
          stmt.bindString(1, _tmp);
        }
        stmt.bindLong(2, value.getSize());
        if (value.getLastModified() == null) {
          stmt.bindNull(3);
        } else {
          stmt.bindLong(3, value.getLastModified());
        }
        if (value.getGenerationModified() == null) {
          stmt.bindNull(4);
        } else {
          stmt.bindLong(4, value.getGenerationModified());
        }
        final String _tmp_1;
        _tmp_1 = __converters.chunkIdsToString(value.getChunks());
        if (_tmp_1 == null) {
          stmt.bindNull(5);
        } else {
          stmt.bindString(5, _tmp_1);
        }
        if (value.getZipIndex() == null) {
          stmt.bindNull(6);
        } else {
          stmt.bindLong(6, value.getZipIndex());
        }
        stmt.bindLong(7, value.getLastSeen());
      }
    };
    this.__updateAdapterOfCachedFile = new EntityDeletionOrUpdateAdapter<CachedFile>(__db) {
      @Override
      public String createQuery() {
        return "UPDATE OR ABORT `CachedFile` SET `uri` = ?,`size` = ?,`last_modified` = ?,`generation_modified` = ?,`chunks` = ?,`zip_index` = ?,`last_seen` = ? WHERE `uri` = ?";
      }

      @Override
      public void bind(SupportSQLiteStatement stmt, CachedFile value) {
        final String _tmp;
        _tmp = __converters.uriToString(value.getUri());
        if (_tmp == null) {
          stmt.bindNull(1);
        } else {
          stmt.bindString(1, _tmp);
        }
        stmt.bindLong(2, value.getSize());
        if (value.getLastModified() == null) {
          stmt.bindNull(3);
        } else {
          stmt.bindLong(3, value.getLastModified());
        }
        if (value.getGenerationModified() == null) {
          stmt.bindNull(4);
        } else {
          stmt.bindLong(4, value.getGenerationModified());
        }
        final String _tmp_1;
        _tmp_1 = __converters.chunkIdsToString(value.getChunks());
        if (_tmp_1 == null) {
          stmt.bindNull(5);
        } else {
          stmt.bindString(5, _tmp_1);
        }
        if (value.getZipIndex() == null) {
          stmt.bindNull(6);
        } else {
          stmt.bindLong(6, value.getZipIndex());
        }
        stmt.bindLong(7, value.getLastSeen());
        final String _tmp_2;
        _tmp_2 = __converters.uriToString(value.getUri());
        if (_tmp_2 == null) {
          stmt.bindNull(8);
        } else {
          stmt.bindString(8, _tmp_2);
        }
      }
    };
    this.__preparedStmtOfClear = new SharedSQLiteStatement(__db) {
      @Override
      public String createQuery() {
        final String _query = "DELETE FROM CachedFile";
        return _query;
      }
    };
  }

  @Override
  public void insert(final CachedFile file) {
    __db.assertNotSuspendingTransaction();
    __db.beginTransaction();
    try {
      __insertionAdapterOfCachedFile.insert(file);
      __db.setTransactionSuccessful();
    } finally {
      __db.endTransaction();
    }
  }

  @Override
  public void upsert(final CachedFile file) {
    __db.assertNotSuspendingTransaction();
    __db.beginTransaction();
    try {
      __insertionAdapterOfCachedFile_1.insert(file);
      __db.setTransactionSuccessful();
    } finally {
      __db.endTransaction();
    }
  }

  @Override
  public void update(final CachedFile file) {
    __db.assertNotSuspendingTransaction();
    __db.beginTransaction();
    try {
      __updateAdapterOfCachedFile.handle(file);
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
  public CachedFile getByUri(final Uri uri) {
    final String _sql = "SELECT * FROM CachedFile WHERE uri == (?)";
    final RoomSQLiteQuery _statement = RoomSQLiteQuery.acquire(_sql, 1);
    int _argIndex = 1;
    final String _tmp;
    _tmp = __converters.uriToString(uri);
    if (_tmp == null) {
      _statement.bindNull(_argIndex);
    } else {
      _statement.bindString(_argIndex, _tmp);
    }
    __db.assertNotSuspendingTransaction();
    final Cursor _cursor = DBUtil.query(__db, _statement, false, null);
    try {
      final int _cursorIndexOfUri = CursorUtil.getColumnIndexOrThrow(_cursor, "uri");
      final int _cursorIndexOfSize = CursorUtil.getColumnIndexOrThrow(_cursor, "size");
      final int _cursorIndexOfLastModified = CursorUtil.getColumnIndexOrThrow(_cursor, "last_modified");
      final int _cursorIndexOfGenerationModified = CursorUtil.getColumnIndexOrThrow(_cursor, "generation_modified");
      final int _cursorIndexOfChunks = CursorUtil.getColumnIndexOrThrow(_cursor, "chunks");
      final int _cursorIndexOfZipIndex = CursorUtil.getColumnIndexOrThrow(_cursor, "zip_index");
      final int _cursorIndexOfLastSeen = CursorUtil.getColumnIndexOrThrow(_cursor, "last_seen");
      final CachedFile _result;
      if(_cursor.moveToFirst()) {
        final Uri _tmpUri;
        final String _tmp_1;
        if (_cursor.isNull(_cursorIndexOfUri)) {
          _tmp_1 = null;
        } else {
          _tmp_1 = _cursor.getString(_cursorIndexOfUri);
        }
        _tmpUri = __converters.stringToUri(_tmp_1);
        final long _tmpSize;
        _tmpSize = _cursor.getLong(_cursorIndexOfSize);
        final Long _tmpLastModified;
        if (_cursor.isNull(_cursorIndexOfLastModified)) {
          _tmpLastModified = null;
        } else {
          _tmpLastModified = _cursor.getLong(_cursorIndexOfLastModified);
        }
        final Long _tmpGenerationModified;
        if (_cursor.isNull(_cursorIndexOfGenerationModified)) {
          _tmpGenerationModified = null;
        } else {
          _tmpGenerationModified = _cursor.getLong(_cursorIndexOfGenerationModified);
        }
        final List<String> _tmpChunks;
        final String _tmp_2;
        if (_cursor.isNull(_cursorIndexOfChunks)) {
          _tmp_2 = null;
        } else {
          _tmp_2 = _cursor.getString(_cursorIndexOfChunks);
        }
        _tmpChunks = __converters.stringToChunkIds(_tmp_2);
        final Integer _tmpZipIndex;
        if (_cursor.isNull(_cursorIndexOfZipIndex)) {
          _tmpZipIndex = null;
        } else {
          _tmpZipIndex = _cursor.getInt(_cursorIndexOfZipIndex);
        }
        final long _tmpLastSeen;
        _tmpLastSeen = _cursor.getLong(_cursorIndexOfLastSeen);
        _result = new CachedFile(_tmpUri,_tmpSize,_tmpLastModified,_tmpGenerationModified,_tmpChunks,_tmpZipIndex,_tmpLastSeen);
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
  public void updateLastSeen(final Collection<? extends Uri> uris, final long now) {
    __db.assertNotSuspendingTransaction();
    StringBuilder _stringBuilder = StringUtil.newStringBuilder();
    _stringBuilder.append("UPDATE CachedFile SET last_seen = ");
    _stringBuilder.append("?");
    _stringBuilder.append(" WHERE uri IN (");
    final int _inputSize = uris.size();
    StringUtil.appendPlaceholders(_stringBuilder, _inputSize);
    _stringBuilder.append(")");
    final String _sql = _stringBuilder.toString();
    final SupportSQLiteStatement _stmt = __db.compileStatement(_sql);
    int _argIndex = 1;
    _stmt.bindLong(_argIndex, now);
    _argIndex = 2;
    for (Uri _item : uris) {
      final String _tmp;
      _tmp = __converters.uriToString(_item);
      if (_tmp == null) {
        _stmt.bindNull(_argIndex);
      } else {
        _stmt.bindString(_argIndex, _tmp);
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

  public static List<Class<?>> getRequiredConverters() {
    return Collections.emptyList();
  }
}
