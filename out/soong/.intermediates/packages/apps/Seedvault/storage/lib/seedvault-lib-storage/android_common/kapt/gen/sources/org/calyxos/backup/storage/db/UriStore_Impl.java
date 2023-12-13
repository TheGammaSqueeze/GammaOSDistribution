package org.calyxos.backup.storage.db;

import android.database.Cursor;
import android.net.Uri;
import androidx.room.EntityDeletionOrUpdateAdapter;
import androidx.room.EntityInsertionAdapter;
import androidx.room.RoomDatabase;
import androidx.room.RoomSQLiteQuery;
import androidx.room.util.CursorUtil;
import androidx.room.util.DBUtil;
import androidx.sqlite.db.SupportSQLiteStatement;
import java.lang.Class;
import java.lang.Override;
import java.lang.String;
import java.lang.SuppressWarnings;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import javax.annotation.processing.Generated;

@Generated("androidx.room.RoomProcessor")
@SuppressWarnings({"unchecked", "deprecation"})
public final class UriStore_Impl implements UriStore {
  private final RoomDatabase __db;

  private final EntityInsertionAdapter<StoredUri> __insertionAdapterOfStoredUri;

  private final Converters __converters = new Converters();

  private final EntityDeletionOrUpdateAdapter<StoredUri> __deletionAdapterOfStoredUri;

  public UriStore_Impl(RoomDatabase __db) {
    this.__db = __db;
    this.__insertionAdapterOfStoredUri = new EntityInsertionAdapter<StoredUri>(__db) {
      @Override
      public String createQuery() {
        return "INSERT OR IGNORE INTO `StoredUri` (`uri`) VALUES (?)";
      }

      @Override
      public void bind(SupportSQLiteStatement stmt, StoredUri value) {
        final String _tmp;
        _tmp = __converters.uriToString(value.getUri());
        if (_tmp == null) {
          stmt.bindNull(1);
        } else {
          stmt.bindString(1, _tmp);
        }
      }
    };
    this.__deletionAdapterOfStoredUri = new EntityDeletionOrUpdateAdapter<StoredUri>(__db) {
      @Override
      public String createQuery() {
        return "DELETE FROM `StoredUri` WHERE `uri` = ?";
      }

      @Override
      public void bind(SupportSQLiteStatement stmt, StoredUri value) {
        final String _tmp;
        _tmp = __converters.uriToString(value.getUri());
        if (_tmp == null) {
          stmt.bindNull(1);
        } else {
          stmt.bindString(1, _tmp);
        }
      }
    };
  }

  @Override
  public void addStoredUri(final StoredUri uri) {
    __db.assertNotSuspendingTransaction();
    __db.beginTransaction();
    try {
      __insertionAdapterOfStoredUri.insert(uri);
      __db.setTransactionSuccessful();
    } finally {
      __db.endTransaction();
    }
  }

  @Override
  public void removeStoredUri(final StoredUri uri) {
    __db.assertNotSuspendingTransaction();
    __db.beginTransaction();
    try {
      __deletionAdapterOfStoredUri.handle(uri);
      __db.setTransactionSuccessful();
    } finally {
      __db.endTransaction();
    }
  }

  @Override
  public List<StoredUri> getStoredUris() {
    final String _sql = "SELECT * FROM StoredUri";
    final RoomSQLiteQuery _statement = RoomSQLiteQuery.acquire(_sql, 0);
    __db.assertNotSuspendingTransaction();
    final Cursor _cursor = DBUtil.query(__db, _statement, false, null);
    try {
      final int _cursorIndexOfUri = CursorUtil.getColumnIndexOrThrow(_cursor, "uri");
      final List<StoredUri> _result = new ArrayList<StoredUri>(_cursor.getCount());
      while(_cursor.moveToNext()) {
        final StoredUri _item;
        final Uri _tmpUri;
        final String _tmp;
        if (_cursor.isNull(_cursorIndexOfUri)) {
          _tmp = null;
        } else {
          _tmp = _cursor.getString(_cursorIndexOfUri);
        }
        _tmpUri = __converters.stringToUri(_tmp);
        _item = new StoredUri(_tmpUri);
        _result.add(_item);
      }
      return _result;
    } finally {
      _cursor.close();
      _statement.release();
    }
  }

  public static List<Class<?>> getRequiredConverters() {
    return Collections.emptyList();
  }
}
