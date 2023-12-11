package com.android.bluetooth.btservice.storage;

import android.database.Cursor;
import androidx.room.EntityInsertionAdapter;
import androidx.room.RoomDatabase;
import androidx.room.RoomSQLiteQuery;
import androidx.room.SharedSQLiteStatement;
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
public final class MetadataDao_Impl implements MetadataDao {
  private final RoomDatabase __db;

  private final EntityInsertionAdapter<Metadata> __insertionAdapterOfMetadata;

  private final SharedSQLiteStatement __preparedStmtOfDelete;

  private final SharedSQLiteStatement __preparedStmtOfDeleteAll;

  public MetadataDao_Impl(RoomDatabase __db) {
    this.__db = __db;
    this.__insertionAdapterOfMetadata = new EntityInsertionAdapter<Metadata>(__db) {
      @Override
      public String createQuery() {
        return "INSERT OR REPLACE INTO `metadata` (`address`,`migrated`,`a2dpSupportsOptionalCodecs`,`a2dpOptionalCodecsEnabled`,`last_active_time`,`is_active_a2dp_device`,`a2dp_connection_policy`,`a2dp_sink_connection_policy`,`hfp_connection_policy`,`hfp_client_connection_policy`,`hid_host_connection_policy`,`pan_connection_policy`,`pbap_connection_policy`,`pbap_client_connection_policy`,`map_connection_policy`,`sap_connection_policy`,`hearing_aid_connection_policy`,`map_client_connection_policy`,`le_audio_connection_policy`,`manufacturer_name`,`model_name`,`software_version`,`hardware_version`,`companion_app`,`main_icon`,`is_untethered_headset`,`untethered_left_icon`,`untethered_right_icon`,`untethered_case_icon`,`untethered_left_battery`,`untethered_right_battery`,`untethered_case_battery`,`untethered_left_charging`,`untethered_right_charging`,`untethered_case_charging`,`enhanced_settings_ui_uri`,`device_type`,`main_battery`,`main_charging`,`main_low_battery_threshold`,`untethered_left_low_battery_threshold`,`untethered_right_low_battery_threshold`,`untethered_case_low_battery_threshold`) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
      }

      @Override
      public void bind(SupportSQLiteStatement stmt, Metadata value) {
        if (value.getAddress() == null) {
          stmt.bindNull(1);
        } else {
          stmt.bindString(1, value.getAddress());
        }
        final int _tmp;
        _tmp = value.migrated ? 1 : 0;
        stmt.bindLong(2, _tmp);
        stmt.bindLong(3, value.a2dpSupportsOptionalCodecs);
        stmt.bindLong(4, value.a2dpOptionalCodecsEnabled);
        stmt.bindLong(5, value.last_active_time);
        final int _tmp_1;
        _tmp_1 = value.is_active_a2dp_device ? 1 : 0;
        stmt.bindLong(6, _tmp_1);
        final ProfilePrioritiesEntity _tmpProfileConnectionPolicies = value.profileConnectionPolicies;
        if(_tmpProfileConnectionPolicies != null) {
          stmt.bindLong(7, _tmpProfileConnectionPolicies.a2dp_connection_policy);
          stmt.bindLong(8, _tmpProfileConnectionPolicies.a2dp_sink_connection_policy);
          stmt.bindLong(9, _tmpProfileConnectionPolicies.hfp_connection_policy);
          stmt.bindLong(10, _tmpProfileConnectionPolicies.hfp_client_connection_policy);
          stmt.bindLong(11, _tmpProfileConnectionPolicies.hid_host_connection_policy);
          stmt.bindLong(12, _tmpProfileConnectionPolicies.pan_connection_policy);
          stmt.bindLong(13, _tmpProfileConnectionPolicies.pbap_connection_policy);
          stmt.bindLong(14, _tmpProfileConnectionPolicies.pbap_client_connection_policy);
          stmt.bindLong(15, _tmpProfileConnectionPolicies.map_connection_policy);
          stmt.bindLong(16, _tmpProfileConnectionPolicies.sap_connection_policy);
          stmt.bindLong(17, _tmpProfileConnectionPolicies.hearing_aid_connection_policy);
          stmt.bindLong(18, _tmpProfileConnectionPolicies.map_client_connection_policy);
          stmt.bindLong(19, _tmpProfileConnectionPolicies.le_audio_connection_policy);
        } else {
          stmt.bindNull(7);
          stmt.bindNull(8);
          stmt.bindNull(9);
          stmt.bindNull(10);
          stmt.bindNull(11);
          stmt.bindNull(12);
          stmt.bindNull(13);
          stmt.bindNull(14);
          stmt.bindNull(15);
          stmt.bindNull(16);
          stmt.bindNull(17);
          stmt.bindNull(18);
          stmt.bindNull(19);
        }
        final CustomizedMetadataEntity _tmpPublicMetadata = value.publicMetadata;
        if(_tmpPublicMetadata != null) {
          if (_tmpPublicMetadata.manufacturer_name == null) {
            stmt.bindNull(20);
          } else {
            stmt.bindBlob(20, _tmpPublicMetadata.manufacturer_name);
          }
          if (_tmpPublicMetadata.model_name == null) {
            stmt.bindNull(21);
          } else {
            stmt.bindBlob(21, _tmpPublicMetadata.model_name);
          }
          if (_tmpPublicMetadata.software_version == null) {
            stmt.bindNull(22);
          } else {
            stmt.bindBlob(22, _tmpPublicMetadata.software_version);
          }
          if (_tmpPublicMetadata.hardware_version == null) {
            stmt.bindNull(23);
          } else {
            stmt.bindBlob(23, _tmpPublicMetadata.hardware_version);
          }
          if (_tmpPublicMetadata.companion_app == null) {
            stmt.bindNull(24);
          } else {
            stmt.bindBlob(24, _tmpPublicMetadata.companion_app);
          }
          if (_tmpPublicMetadata.main_icon == null) {
            stmt.bindNull(25);
          } else {
            stmt.bindBlob(25, _tmpPublicMetadata.main_icon);
          }
          if (_tmpPublicMetadata.is_untethered_headset == null) {
            stmt.bindNull(26);
          } else {
            stmt.bindBlob(26, _tmpPublicMetadata.is_untethered_headset);
          }
          if (_tmpPublicMetadata.untethered_left_icon == null) {
            stmt.bindNull(27);
          } else {
            stmt.bindBlob(27, _tmpPublicMetadata.untethered_left_icon);
          }
          if (_tmpPublicMetadata.untethered_right_icon == null) {
            stmt.bindNull(28);
          } else {
            stmt.bindBlob(28, _tmpPublicMetadata.untethered_right_icon);
          }
          if (_tmpPublicMetadata.untethered_case_icon == null) {
            stmt.bindNull(29);
          } else {
            stmt.bindBlob(29, _tmpPublicMetadata.untethered_case_icon);
          }
          if (_tmpPublicMetadata.untethered_left_battery == null) {
            stmt.bindNull(30);
          } else {
            stmt.bindBlob(30, _tmpPublicMetadata.untethered_left_battery);
          }
          if (_tmpPublicMetadata.untethered_right_battery == null) {
            stmt.bindNull(31);
          } else {
            stmt.bindBlob(31, _tmpPublicMetadata.untethered_right_battery);
          }
          if (_tmpPublicMetadata.untethered_case_battery == null) {
            stmt.bindNull(32);
          } else {
            stmt.bindBlob(32, _tmpPublicMetadata.untethered_case_battery);
          }
          if (_tmpPublicMetadata.untethered_left_charging == null) {
            stmt.bindNull(33);
          } else {
            stmt.bindBlob(33, _tmpPublicMetadata.untethered_left_charging);
          }
          if (_tmpPublicMetadata.untethered_right_charging == null) {
            stmt.bindNull(34);
          } else {
            stmt.bindBlob(34, _tmpPublicMetadata.untethered_right_charging);
          }
          if (_tmpPublicMetadata.untethered_case_charging == null) {
            stmt.bindNull(35);
          } else {
            stmt.bindBlob(35, _tmpPublicMetadata.untethered_case_charging);
          }
          if (_tmpPublicMetadata.enhanced_settings_ui_uri == null) {
            stmt.bindNull(36);
          } else {
            stmt.bindBlob(36, _tmpPublicMetadata.enhanced_settings_ui_uri);
          }
          if (_tmpPublicMetadata.device_type == null) {
            stmt.bindNull(37);
          } else {
            stmt.bindBlob(37, _tmpPublicMetadata.device_type);
          }
          if (_tmpPublicMetadata.main_battery == null) {
            stmt.bindNull(38);
          } else {
            stmt.bindBlob(38, _tmpPublicMetadata.main_battery);
          }
          if (_tmpPublicMetadata.main_charging == null) {
            stmt.bindNull(39);
          } else {
            stmt.bindBlob(39, _tmpPublicMetadata.main_charging);
          }
          if (_tmpPublicMetadata.main_low_battery_threshold == null) {
            stmt.bindNull(40);
          } else {
            stmt.bindBlob(40, _tmpPublicMetadata.main_low_battery_threshold);
          }
          if (_tmpPublicMetadata.untethered_left_low_battery_threshold == null) {
            stmt.bindNull(41);
          } else {
            stmt.bindBlob(41, _tmpPublicMetadata.untethered_left_low_battery_threshold);
          }
          if (_tmpPublicMetadata.untethered_right_low_battery_threshold == null) {
            stmt.bindNull(42);
          } else {
            stmt.bindBlob(42, _tmpPublicMetadata.untethered_right_low_battery_threshold);
          }
          if (_tmpPublicMetadata.untethered_case_low_battery_threshold == null) {
            stmt.bindNull(43);
          } else {
            stmt.bindBlob(43, _tmpPublicMetadata.untethered_case_low_battery_threshold);
          }
        } else {
          stmt.bindNull(20);
          stmt.bindNull(21);
          stmt.bindNull(22);
          stmt.bindNull(23);
          stmt.bindNull(24);
          stmt.bindNull(25);
          stmt.bindNull(26);
          stmt.bindNull(27);
          stmt.bindNull(28);
          stmt.bindNull(29);
          stmt.bindNull(30);
          stmt.bindNull(31);
          stmt.bindNull(32);
          stmt.bindNull(33);
          stmt.bindNull(34);
          stmt.bindNull(35);
          stmt.bindNull(36);
          stmt.bindNull(37);
          stmt.bindNull(38);
          stmt.bindNull(39);
          stmt.bindNull(40);
          stmt.bindNull(41);
          stmt.bindNull(42);
          stmt.bindNull(43);
        }
      }
    };
    this.__preparedStmtOfDelete = new SharedSQLiteStatement(__db) {
      @Override
      public String createQuery() {
        final String _query = "DELETE FROM metadata WHERE address = ?";
        return _query;
      }
    };
    this.__preparedStmtOfDeleteAll = new SharedSQLiteStatement(__db) {
      @Override
      public String createQuery() {
        final String _query = "DELETE FROM metadata";
        return _query;
      }
    };
  }

  @Override
  public void insert(final Metadata... metadata) {
    __db.assertNotSuspendingTransaction();
    __db.beginTransaction();
    try {
      __insertionAdapterOfMetadata.insert(metadata);
      __db.setTransactionSuccessful();
    } finally {
      __db.endTransaction();
    }
  }

  @Override
  public void delete(final String address) {
    __db.assertNotSuspendingTransaction();
    final SupportSQLiteStatement _stmt = __preparedStmtOfDelete.acquire();
    int _argIndex = 1;
    if (address == null) {
      _stmt.bindNull(_argIndex);
    } else {
      _stmt.bindString(_argIndex, address);
    }
    __db.beginTransaction();
    try {
      _stmt.executeUpdateDelete();
      __db.setTransactionSuccessful();
    } finally {
      __db.endTransaction();
      __preparedStmtOfDelete.release(_stmt);
    }
  }

  @Override
  public void deleteAll() {
    __db.assertNotSuspendingTransaction();
    final SupportSQLiteStatement _stmt = __preparedStmtOfDeleteAll.acquire();
    __db.beginTransaction();
    try {
      _stmt.executeUpdateDelete();
      __db.setTransactionSuccessful();
    } finally {
      __db.endTransaction();
      __preparedStmtOfDeleteAll.release(_stmt);
    }
  }

  @Override
  public List<Metadata> load() {
    final String _sql = "SELECT * FROM metadata ORDER BY last_active_time DESC";
    final RoomSQLiteQuery _statement = RoomSQLiteQuery.acquire(_sql, 0);
    __db.assertNotSuspendingTransaction();
    final Cursor _cursor = DBUtil.query(__db, _statement, false, null);
    try {
      final int _cursorIndexOfAddress = CursorUtil.getColumnIndexOrThrow(_cursor, "address");
      final int _cursorIndexOfMigrated = CursorUtil.getColumnIndexOrThrow(_cursor, "migrated");
      final int _cursorIndexOfA2dpSupportsOptionalCodecs = CursorUtil.getColumnIndexOrThrow(_cursor, "a2dpSupportsOptionalCodecs");
      final int _cursorIndexOfA2dpOptionalCodecsEnabled = CursorUtil.getColumnIndexOrThrow(_cursor, "a2dpOptionalCodecsEnabled");
      final int _cursorIndexOfLastActiveTime = CursorUtil.getColumnIndexOrThrow(_cursor, "last_active_time");
      final int _cursorIndexOfIsActiveA2dpDevice = CursorUtil.getColumnIndexOrThrow(_cursor, "is_active_a2dp_device");
      final int _cursorIndexOfA2dpConnectionPolicy = CursorUtil.getColumnIndexOrThrow(_cursor, "a2dp_connection_policy");
      final int _cursorIndexOfA2dpSinkConnectionPolicy = CursorUtil.getColumnIndexOrThrow(_cursor, "a2dp_sink_connection_policy");
      final int _cursorIndexOfHfpConnectionPolicy = CursorUtil.getColumnIndexOrThrow(_cursor, "hfp_connection_policy");
      final int _cursorIndexOfHfpClientConnectionPolicy = CursorUtil.getColumnIndexOrThrow(_cursor, "hfp_client_connection_policy");
      final int _cursorIndexOfHidHostConnectionPolicy = CursorUtil.getColumnIndexOrThrow(_cursor, "hid_host_connection_policy");
      final int _cursorIndexOfPanConnectionPolicy = CursorUtil.getColumnIndexOrThrow(_cursor, "pan_connection_policy");
      final int _cursorIndexOfPbapConnectionPolicy = CursorUtil.getColumnIndexOrThrow(_cursor, "pbap_connection_policy");
      final int _cursorIndexOfPbapClientConnectionPolicy = CursorUtil.getColumnIndexOrThrow(_cursor, "pbap_client_connection_policy");
      final int _cursorIndexOfMapConnectionPolicy = CursorUtil.getColumnIndexOrThrow(_cursor, "map_connection_policy");
      final int _cursorIndexOfSapConnectionPolicy = CursorUtil.getColumnIndexOrThrow(_cursor, "sap_connection_policy");
      final int _cursorIndexOfHearingAidConnectionPolicy = CursorUtil.getColumnIndexOrThrow(_cursor, "hearing_aid_connection_policy");
      final int _cursorIndexOfMapClientConnectionPolicy = CursorUtil.getColumnIndexOrThrow(_cursor, "map_client_connection_policy");
      final int _cursorIndexOfLeAudioConnectionPolicy = CursorUtil.getColumnIndexOrThrow(_cursor, "le_audio_connection_policy");
      final int _cursorIndexOfManufacturerName = CursorUtil.getColumnIndexOrThrow(_cursor, "manufacturer_name");
      final int _cursorIndexOfModelName = CursorUtil.getColumnIndexOrThrow(_cursor, "model_name");
      final int _cursorIndexOfSoftwareVersion = CursorUtil.getColumnIndexOrThrow(_cursor, "software_version");
      final int _cursorIndexOfHardwareVersion = CursorUtil.getColumnIndexOrThrow(_cursor, "hardware_version");
      final int _cursorIndexOfCompanionApp = CursorUtil.getColumnIndexOrThrow(_cursor, "companion_app");
      final int _cursorIndexOfMainIcon = CursorUtil.getColumnIndexOrThrow(_cursor, "main_icon");
      final int _cursorIndexOfIsUntetheredHeadset = CursorUtil.getColumnIndexOrThrow(_cursor, "is_untethered_headset");
      final int _cursorIndexOfUntetheredLeftIcon = CursorUtil.getColumnIndexOrThrow(_cursor, "untethered_left_icon");
      final int _cursorIndexOfUntetheredRightIcon = CursorUtil.getColumnIndexOrThrow(_cursor, "untethered_right_icon");
      final int _cursorIndexOfUntetheredCaseIcon = CursorUtil.getColumnIndexOrThrow(_cursor, "untethered_case_icon");
      final int _cursorIndexOfUntetheredLeftBattery = CursorUtil.getColumnIndexOrThrow(_cursor, "untethered_left_battery");
      final int _cursorIndexOfUntetheredRightBattery = CursorUtil.getColumnIndexOrThrow(_cursor, "untethered_right_battery");
      final int _cursorIndexOfUntetheredCaseBattery = CursorUtil.getColumnIndexOrThrow(_cursor, "untethered_case_battery");
      final int _cursorIndexOfUntetheredLeftCharging = CursorUtil.getColumnIndexOrThrow(_cursor, "untethered_left_charging");
      final int _cursorIndexOfUntetheredRightCharging = CursorUtil.getColumnIndexOrThrow(_cursor, "untethered_right_charging");
      final int _cursorIndexOfUntetheredCaseCharging = CursorUtil.getColumnIndexOrThrow(_cursor, "untethered_case_charging");
      final int _cursorIndexOfEnhancedSettingsUiUri = CursorUtil.getColumnIndexOrThrow(_cursor, "enhanced_settings_ui_uri");
      final int _cursorIndexOfDeviceType = CursorUtil.getColumnIndexOrThrow(_cursor, "device_type");
      final int _cursorIndexOfMainBattery = CursorUtil.getColumnIndexOrThrow(_cursor, "main_battery");
      final int _cursorIndexOfMainCharging = CursorUtil.getColumnIndexOrThrow(_cursor, "main_charging");
      final int _cursorIndexOfMainLowBatteryThreshold = CursorUtil.getColumnIndexOrThrow(_cursor, "main_low_battery_threshold");
      final int _cursorIndexOfUntetheredLeftLowBatteryThreshold = CursorUtil.getColumnIndexOrThrow(_cursor, "untethered_left_low_battery_threshold");
      final int _cursorIndexOfUntetheredRightLowBatteryThreshold = CursorUtil.getColumnIndexOrThrow(_cursor, "untethered_right_low_battery_threshold");
      final int _cursorIndexOfUntetheredCaseLowBatteryThreshold = CursorUtil.getColumnIndexOrThrow(_cursor, "untethered_case_low_battery_threshold");
      final List<Metadata> _result = new ArrayList<Metadata>(_cursor.getCount());
      while(_cursor.moveToNext()) {
        final Metadata _item;
        final String _tmpAddress;
        if (_cursor.isNull(_cursorIndexOfAddress)) {
          _tmpAddress = null;
        } else {
          _tmpAddress = _cursor.getString(_cursorIndexOfAddress);
        }
        final ProfilePrioritiesEntity _tmpProfileConnectionPolicies;
        if (! (_cursor.isNull(_cursorIndexOfA2dpConnectionPolicy) && _cursor.isNull(_cursorIndexOfA2dpSinkConnectionPolicy) && _cursor.isNull(_cursorIndexOfHfpConnectionPolicy) && _cursor.isNull(_cursorIndexOfHfpClientConnectionPolicy) && _cursor.isNull(_cursorIndexOfHidHostConnectionPolicy) && _cursor.isNull(_cursorIndexOfPanConnectionPolicy) && _cursor.isNull(_cursorIndexOfPbapConnectionPolicy) && _cursor.isNull(_cursorIndexOfPbapClientConnectionPolicy) && _cursor.isNull(_cursorIndexOfMapConnectionPolicy) && _cursor.isNull(_cursorIndexOfSapConnectionPolicy) && _cursor.isNull(_cursorIndexOfHearingAidConnectionPolicy) && _cursor.isNull(_cursorIndexOfMapClientConnectionPolicy) && _cursor.isNull(_cursorIndexOfLeAudioConnectionPolicy))) {
          _tmpProfileConnectionPolicies = new ProfilePrioritiesEntity();
          _tmpProfileConnectionPolicies.a2dp_connection_policy = _cursor.getInt(_cursorIndexOfA2dpConnectionPolicy);
          _tmpProfileConnectionPolicies.a2dp_sink_connection_policy = _cursor.getInt(_cursorIndexOfA2dpSinkConnectionPolicy);
          _tmpProfileConnectionPolicies.hfp_connection_policy = _cursor.getInt(_cursorIndexOfHfpConnectionPolicy);
          _tmpProfileConnectionPolicies.hfp_client_connection_policy = _cursor.getInt(_cursorIndexOfHfpClientConnectionPolicy);
          _tmpProfileConnectionPolicies.hid_host_connection_policy = _cursor.getInt(_cursorIndexOfHidHostConnectionPolicy);
          _tmpProfileConnectionPolicies.pan_connection_policy = _cursor.getInt(_cursorIndexOfPanConnectionPolicy);
          _tmpProfileConnectionPolicies.pbap_connection_policy = _cursor.getInt(_cursorIndexOfPbapConnectionPolicy);
          _tmpProfileConnectionPolicies.pbap_client_connection_policy = _cursor.getInt(_cursorIndexOfPbapClientConnectionPolicy);
          _tmpProfileConnectionPolicies.map_connection_policy = _cursor.getInt(_cursorIndexOfMapConnectionPolicy);
          _tmpProfileConnectionPolicies.sap_connection_policy = _cursor.getInt(_cursorIndexOfSapConnectionPolicy);
          _tmpProfileConnectionPolicies.hearing_aid_connection_policy = _cursor.getInt(_cursorIndexOfHearingAidConnectionPolicy);
          _tmpProfileConnectionPolicies.map_client_connection_policy = _cursor.getInt(_cursorIndexOfMapClientConnectionPolicy);
          _tmpProfileConnectionPolicies.le_audio_connection_policy = _cursor.getInt(_cursorIndexOfLeAudioConnectionPolicy);
        }  else  {
          _tmpProfileConnectionPolicies = null;
        }
        final CustomizedMetadataEntity _tmpPublicMetadata;
        _tmpPublicMetadata = new CustomizedMetadataEntity();
        if (_cursor.isNull(_cursorIndexOfManufacturerName)) {
          _tmpPublicMetadata.manufacturer_name = null;
        } else {
          _tmpPublicMetadata.manufacturer_name = _cursor.getBlob(_cursorIndexOfManufacturerName);
        }
        if (_cursor.isNull(_cursorIndexOfModelName)) {
          _tmpPublicMetadata.model_name = null;
        } else {
          _tmpPublicMetadata.model_name = _cursor.getBlob(_cursorIndexOfModelName);
        }
        if (_cursor.isNull(_cursorIndexOfSoftwareVersion)) {
          _tmpPublicMetadata.software_version = null;
        } else {
          _tmpPublicMetadata.software_version = _cursor.getBlob(_cursorIndexOfSoftwareVersion);
        }
        if (_cursor.isNull(_cursorIndexOfHardwareVersion)) {
          _tmpPublicMetadata.hardware_version = null;
        } else {
          _tmpPublicMetadata.hardware_version = _cursor.getBlob(_cursorIndexOfHardwareVersion);
        }
        if (_cursor.isNull(_cursorIndexOfCompanionApp)) {
          _tmpPublicMetadata.companion_app = null;
        } else {
          _tmpPublicMetadata.companion_app = _cursor.getBlob(_cursorIndexOfCompanionApp);
        }
        if (_cursor.isNull(_cursorIndexOfMainIcon)) {
          _tmpPublicMetadata.main_icon = null;
        } else {
          _tmpPublicMetadata.main_icon = _cursor.getBlob(_cursorIndexOfMainIcon);
        }
        if (_cursor.isNull(_cursorIndexOfIsUntetheredHeadset)) {
          _tmpPublicMetadata.is_untethered_headset = null;
        } else {
          _tmpPublicMetadata.is_untethered_headset = _cursor.getBlob(_cursorIndexOfIsUntetheredHeadset);
        }
        if (_cursor.isNull(_cursorIndexOfUntetheredLeftIcon)) {
          _tmpPublicMetadata.untethered_left_icon = null;
        } else {
          _tmpPublicMetadata.untethered_left_icon = _cursor.getBlob(_cursorIndexOfUntetheredLeftIcon);
        }
        if (_cursor.isNull(_cursorIndexOfUntetheredRightIcon)) {
          _tmpPublicMetadata.untethered_right_icon = null;
        } else {
          _tmpPublicMetadata.untethered_right_icon = _cursor.getBlob(_cursorIndexOfUntetheredRightIcon);
        }
        if (_cursor.isNull(_cursorIndexOfUntetheredCaseIcon)) {
          _tmpPublicMetadata.untethered_case_icon = null;
        } else {
          _tmpPublicMetadata.untethered_case_icon = _cursor.getBlob(_cursorIndexOfUntetheredCaseIcon);
        }
        if (_cursor.isNull(_cursorIndexOfUntetheredLeftBattery)) {
          _tmpPublicMetadata.untethered_left_battery = null;
        } else {
          _tmpPublicMetadata.untethered_left_battery = _cursor.getBlob(_cursorIndexOfUntetheredLeftBattery);
        }
        if (_cursor.isNull(_cursorIndexOfUntetheredRightBattery)) {
          _tmpPublicMetadata.untethered_right_battery = null;
        } else {
          _tmpPublicMetadata.untethered_right_battery = _cursor.getBlob(_cursorIndexOfUntetheredRightBattery);
        }
        if (_cursor.isNull(_cursorIndexOfUntetheredCaseBattery)) {
          _tmpPublicMetadata.untethered_case_battery = null;
        } else {
          _tmpPublicMetadata.untethered_case_battery = _cursor.getBlob(_cursorIndexOfUntetheredCaseBattery);
        }
        if (_cursor.isNull(_cursorIndexOfUntetheredLeftCharging)) {
          _tmpPublicMetadata.untethered_left_charging = null;
        } else {
          _tmpPublicMetadata.untethered_left_charging = _cursor.getBlob(_cursorIndexOfUntetheredLeftCharging);
        }
        if (_cursor.isNull(_cursorIndexOfUntetheredRightCharging)) {
          _tmpPublicMetadata.untethered_right_charging = null;
        } else {
          _tmpPublicMetadata.untethered_right_charging = _cursor.getBlob(_cursorIndexOfUntetheredRightCharging);
        }
        if (_cursor.isNull(_cursorIndexOfUntetheredCaseCharging)) {
          _tmpPublicMetadata.untethered_case_charging = null;
        } else {
          _tmpPublicMetadata.untethered_case_charging = _cursor.getBlob(_cursorIndexOfUntetheredCaseCharging);
        }
        if (_cursor.isNull(_cursorIndexOfEnhancedSettingsUiUri)) {
          _tmpPublicMetadata.enhanced_settings_ui_uri = null;
        } else {
          _tmpPublicMetadata.enhanced_settings_ui_uri = _cursor.getBlob(_cursorIndexOfEnhancedSettingsUiUri);
        }
        if (_cursor.isNull(_cursorIndexOfDeviceType)) {
          _tmpPublicMetadata.device_type = null;
        } else {
          _tmpPublicMetadata.device_type = _cursor.getBlob(_cursorIndexOfDeviceType);
        }
        if (_cursor.isNull(_cursorIndexOfMainBattery)) {
          _tmpPublicMetadata.main_battery = null;
        } else {
          _tmpPublicMetadata.main_battery = _cursor.getBlob(_cursorIndexOfMainBattery);
        }
        if (_cursor.isNull(_cursorIndexOfMainCharging)) {
          _tmpPublicMetadata.main_charging = null;
        } else {
          _tmpPublicMetadata.main_charging = _cursor.getBlob(_cursorIndexOfMainCharging);
        }
        if (_cursor.isNull(_cursorIndexOfMainLowBatteryThreshold)) {
          _tmpPublicMetadata.main_low_battery_threshold = null;
        } else {
          _tmpPublicMetadata.main_low_battery_threshold = _cursor.getBlob(_cursorIndexOfMainLowBatteryThreshold);
        }
        if (_cursor.isNull(_cursorIndexOfUntetheredLeftLowBatteryThreshold)) {
          _tmpPublicMetadata.untethered_left_low_battery_threshold = null;
        } else {
          _tmpPublicMetadata.untethered_left_low_battery_threshold = _cursor.getBlob(_cursorIndexOfUntetheredLeftLowBatteryThreshold);
        }
        if (_cursor.isNull(_cursorIndexOfUntetheredRightLowBatteryThreshold)) {
          _tmpPublicMetadata.untethered_right_low_battery_threshold = null;
        } else {
          _tmpPublicMetadata.untethered_right_low_battery_threshold = _cursor.getBlob(_cursorIndexOfUntetheredRightLowBatteryThreshold);
        }
        if (_cursor.isNull(_cursorIndexOfUntetheredCaseLowBatteryThreshold)) {
          _tmpPublicMetadata.untethered_case_low_battery_threshold = null;
        } else {
          _tmpPublicMetadata.untethered_case_low_battery_threshold = _cursor.getBlob(_cursorIndexOfUntetheredCaseLowBatteryThreshold);
        }
        _item = new Metadata(_tmpAddress);
        final int _tmp;
        _tmp = _cursor.getInt(_cursorIndexOfMigrated);
        _item.migrated = _tmp != 0;
        _item.a2dpSupportsOptionalCodecs = _cursor.getInt(_cursorIndexOfA2dpSupportsOptionalCodecs);
        _item.a2dpOptionalCodecsEnabled = _cursor.getInt(_cursorIndexOfA2dpOptionalCodecsEnabled);
        _item.last_active_time = _cursor.getLong(_cursorIndexOfLastActiveTime);
        final int _tmp_1;
        _tmp_1 = _cursor.getInt(_cursorIndexOfIsActiveA2dpDevice);
        _item.is_active_a2dp_device = _tmp_1 != 0;
        _item.profileConnectionPolicies = _tmpProfileConnectionPolicies;
        _item.publicMetadata = _tmpPublicMetadata;
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
