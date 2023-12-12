package com.android.bluetooth.btservice.storage;

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
public final class MetadataDatabase_Impl extends MetadataDatabase {
  private volatile MetadataDao _metadataDao;

  @Override
  protected SupportSQLiteOpenHelper createOpenHelper(DatabaseConfiguration configuration) {
    final SupportSQLiteOpenHelper.Callback _openCallback = new RoomOpenHelper(configuration, new RoomOpenHelper.Delegate(106) {
      @Override
      public void createAllTables(SupportSQLiteDatabase _db) {
        _db.execSQL("CREATE TABLE IF NOT EXISTS `metadata` (`address` TEXT NOT NULL, `migrated` INTEGER NOT NULL, `a2dpSupportsOptionalCodecs` INTEGER NOT NULL, `a2dpOptionalCodecsEnabled` INTEGER NOT NULL, `last_active_time` INTEGER NOT NULL, `is_active_a2dp_device` INTEGER NOT NULL, `a2dp_connection_policy` INTEGER, `a2dp_sink_connection_policy` INTEGER, `hfp_connection_policy` INTEGER, `hfp_client_connection_policy` INTEGER, `hid_host_connection_policy` INTEGER, `pan_connection_policy` INTEGER, `pbap_connection_policy` INTEGER, `pbap_client_connection_policy` INTEGER, `map_connection_policy` INTEGER, `sap_connection_policy` INTEGER, `hearing_aid_connection_policy` INTEGER, `map_client_connection_policy` INTEGER, `le_audio_connection_policy` INTEGER, `manufacturer_name` BLOB, `model_name` BLOB, `software_version` BLOB, `hardware_version` BLOB, `companion_app` BLOB, `main_icon` BLOB, `is_untethered_headset` BLOB, `untethered_left_icon` BLOB, `untethered_right_icon` BLOB, `untethered_case_icon` BLOB, `untethered_left_battery` BLOB, `untethered_right_battery` BLOB, `untethered_case_battery` BLOB, `untethered_left_charging` BLOB, `untethered_right_charging` BLOB, `untethered_case_charging` BLOB, `enhanced_settings_ui_uri` BLOB, `device_type` BLOB, `main_battery` BLOB, `main_charging` BLOB, `main_low_battery_threshold` BLOB, `untethered_left_low_battery_threshold` BLOB, `untethered_right_low_battery_threshold` BLOB, `untethered_case_low_battery_threshold` BLOB, PRIMARY KEY(`address`))");
        _db.execSQL("CREATE TABLE IF NOT EXISTS room_master_table (id INTEGER PRIMARY KEY,identity_hash TEXT)");
        _db.execSQL("INSERT OR REPLACE INTO room_master_table (id,identity_hash) VALUES(42, 'e2c67aa60536bcccd99f827ebf6ca671')");
      }

      @Override
      public void dropAllTables(SupportSQLiteDatabase _db) {
        _db.execSQL("DROP TABLE IF EXISTS `metadata`");
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
        final HashMap<String, TableInfo.Column> _columnsMetadata = new HashMap<String, TableInfo.Column>(43);
        _columnsMetadata.put("address", new TableInfo.Column("address", "TEXT", true, 1, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("migrated", new TableInfo.Column("migrated", "INTEGER", true, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("a2dpSupportsOptionalCodecs", new TableInfo.Column("a2dpSupportsOptionalCodecs", "INTEGER", true, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("a2dpOptionalCodecsEnabled", new TableInfo.Column("a2dpOptionalCodecsEnabled", "INTEGER", true, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("last_active_time", new TableInfo.Column("last_active_time", "INTEGER", true, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("is_active_a2dp_device", new TableInfo.Column("is_active_a2dp_device", "INTEGER", true, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("a2dp_connection_policy", new TableInfo.Column("a2dp_connection_policy", "INTEGER", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("a2dp_sink_connection_policy", new TableInfo.Column("a2dp_sink_connection_policy", "INTEGER", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("hfp_connection_policy", new TableInfo.Column("hfp_connection_policy", "INTEGER", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("hfp_client_connection_policy", new TableInfo.Column("hfp_client_connection_policy", "INTEGER", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("hid_host_connection_policy", new TableInfo.Column("hid_host_connection_policy", "INTEGER", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("pan_connection_policy", new TableInfo.Column("pan_connection_policy", "INTEGER", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("pbap_connection_policy", new TableInfo.Column("pbap_connection_policy", "INTEGER", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("pbap_client_connection_policy", new TableInfo.Column("pbap_client_connection_policy", "INTEGER", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("map_connection_policy", new TableInfo.Column("map_connection_policy", "INTEGER", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("sap_connection_policy", new TableInfo.Column("sap_connection_policy", "INTEGER", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("hearing_aid_connection_policy", new TableInfo.Column("hearing_aid_connection_policy", "INTEGER", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("map_client_connection_policy", new TableInfo.Column("map_client_connection_policy", "INTEGER", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("le_audio_connection_policy", new TableInfo.Column("le_audio_connection_policy", "INTEGER", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("manufacturer_name", new TableInfo.Column("manufacturer_name", "BLOB", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("model_name", new TableInfo.Column("model_name", "BLOB", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("software_version", new TableInfo.Column("software_version", "BLOB", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("hardware_version", new TableInfo.Column("hardware_version", "BLOB", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("companion_app", new TableInfo.Column("companion_app", "BLOB", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("main_icon", new TableInfo.Column("main_icon", "BLOB", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("is_untethered_headset", new TableInfo.Column("is_untethered_headset", "BLOB", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("untethered_left_icon", new TableInfo.Column("untethered_left_icon", "BLOB", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("untethered_right_icon", new TableInfo.Column("untethered_right_icon", "BLOB", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("untethered_case_icon", new TableInfo.Column("untethered_case_icon", "BLOB", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("untethered_left_battery", new TableInfo.Column("untethered_left_battery", "BLOB", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("untethered_right_battery", new TableInfo.Column("untethered_right_battery", "BLOB", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("untethered_case_battery", new TableInfo.Column("untethered_case_battery", "BLOB", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("untethered_left_charging", new TableInfo.Column("untethered_left_charging", "BLOB", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("untethered_right_charging", new TableInfo.Column("untethered_right_charging", "BLOB", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("untethered_case_charging", new TableInfo.Column("untethered_case_charging", "BLOB", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("enhanced_settings_ui_uri", new TableInfo.Column("enhanced_settings_ui_uri", "BLOB", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("device_type", new TableInfo.Column("device_type", "BLOB", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("main_battery", new TableInfo.Column("main_battery", "BLOB", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("main_charging", new TableInfo.Column("main_charging", "BLOB", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("main_low_battery_threshold", new TableInfo.Column("main_low_battery_threshold", "BLOB", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("untethered_left_low_battery_threshold", new TableInfo.Column("untethered_left_low_battery_threshold", "BLOB", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("untethered_right_low_battery_threshold", new TableInfo.Column("untethered_right_low_battery_threshold", "BLOB", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        _columnsMetadata.put("untethered_case_low_battery_threshold", new TableInfo.Column("untethered_case_low_battery_threshold", "BLOB", false, 0, null, TableInfo.CREATED_FROM_ENTITY));
        final HashSet<TableInfo.ForeignKey> _foreignKeysMetadata = new HashSet<TableInfo.ForeignKey>(0);
        final HashSet<TableInfo.Index> _indicesMetadata = new HashSet<TableInfo.Index>(0);
        final TableInfo _infoMetadata = new TableInfo("metadata", _columnsMetadata, _foreignKeysMetadata, _indicesMetadata);
        final TableInfo _existingMetadata = TableInfo.read(_db, "metadata");
        if (! _infoMetadata.equals(_existingMetadata)) {
          return new RoomOpenHelper.ValidationResult(false, "metadata(com.android.bluetooth.btservice.storage.Metadata).\n"
                  + " Expected:\n" + _infoMetadata + "\n"
                  + " Found:\n" + _existingMetadata);
        }
        return new RoomOpenHelper.ValidationResult(true, null);
      }
    }, "e2c67aa60536bcccd99f827ebf6ca671", "6b33f0c38dcd747f40e7054dab70bbde");
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
    return new InvalidationTracker(this, _shadowTablesMap, _viewTables, "metadata");
  }

  @Override
  public void clearAllTables() {
    super.assertNotMainThread();
    final SupportSQLiteDatabase _db = super.getOpenHelper().getWritableDatabase();
    try {
      super.beginTransaction();
      _db.execSQL("DELETE FROM `metadata`");
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
    _typeConvertersMap.put(MetadataDao.class, MetadataDao_Impl.getRequiredConverters());
    return _typeConvertersMap;
  }

  @Override
  protected MetadataDao mMetadataDao() {
    if (_metadataDao != null) {
      return _metadataDao;
    } else {
      synchronized(this) {
        if(_metadataDao == null) {
          _metadataDao = new MetadataDao_Impl(this);
        }
        return _metadataDao;
      }
    }
  }
}
