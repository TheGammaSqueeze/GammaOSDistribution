package com.android.systemui.qs.tileimpl;

import com.android.systemui.qs.QSHost;
import com.android.systemui.qs.external.CustomTile;
import com.android.systemui.qs.tiles.AODTile;
import com.android.systemui.qs.tiles.AirplaneModeTile;
import com.android.systemui.qs.tiles.AlarmTile;
import com.android.systemui.qs.tiles.AmbientDisplayTile;
import com.android.systemui.qs.tiles.BatterySaverTile;
import com.android.systemui.qs.tiles.BluetoothTile;
import com.android.systemui.qs.tiles.CaffeineTile;
import com.android.systemui.qs.tiles.CameraToggleTile;
import com.android.systemui.qs.tiles.CastTile;
import com.android.systemui.qs.tiles.CellularTile;
import com.android.systemui.qs.tiles.ColorInversionTile;
import com.android.systemui.qs.tiles.DataSaverTile;
import com.android.systemui.qs.tiles.DeviceControlsTile;
import com.android.systemui.qs.tiles.DndTile;
import com.android.systemui.qs.tiles.FlashlightTile;
import com.android.systemui.qs.tiles.HeadsUpTile;
import com.android.systemui.qs.tiles.HotspotTile;
import com.android.systemui.qs.tiles.InternetTile;
import com.android.systemui.qs.tiles.LocationTile;
import com.android.systemui.qs.tiles.MicrophoneToggleTile;
import com.android.systemui.qs.tiles.NfcTile;
import com.android.systemui.qs.tiles.NightDisplayTile;
import com.android.systemui.qs.tiles.PowerShareTile;
import com.android.systemui.qs.tiles.ProfilesTile;
import com.android.systemui.qs.tiles.QuickAccessWalletTile;
import com.android.systemui.qs.tiles.ReadingModeTile;
import com.android.systemui.qs.tiles.ReduceBrightColorsTile;
import com.android.systemui.qs.tiles.RotationLockTile;
import com.android.systemui.qs.tiles.ScreenRecordTile;
import com.android.systemui.qs.tiles.SyncTile;
import com.android.systemui.qs.tiles.UiModeNightTile;
import com.android.systemui.qs.tiles.UsbTetherTile;
import com.android.systemui.qs.tiles.UserTile;
import com.android.systemui.qs.tiles.VpnTile;
import com.android.systemui.qs.tiles.WifiTile;
import com.android.systemui.qs.tiles.WorkModeTile;
import com.android.systemui.util.leak.GarbageMonitor;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
import dagger.internal.Factory;
import javax.annotation.processing.Generated;
import javax.inject.Provider;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class QSFactoryImpl_Factory implements Factory<QSFactoryImpl> {
  private final Provider<QSHost> qsHostLazyProvider;

  private final Provider<CustomTile.Builder> customTileBuilderProvider;

  private final Provider<WifiTile> wifiTileProvider;

  private final Provider<InternetTile> internetTileProvider;

  private final Provider<BluetoothTile> bluetoothTileProvider;

  private final Provider<CellularTile> cellularTileProvider;

  private final Provider<DndTile> dndTileProvider;

  private final Provider<ColorInversionTile> colorInversionTileProvider;

  private final Provider<AirplaneModeTile> airplaneModeTileProvider;

  private final Provider<WorkModeTile> workModeTileProvider;

  private final Provider<RotationLockTile> rotationLockTileProvider;

  private final Provider<FlashlightTile> flashlightTileProvider;

  private final Provider<LocationTile> locationTileProvider;

  private final Provider<CastTile> castTileProvider;

  private final Provider<HotspotTile> hotspotTileProvider;

  private final Provider<UserTile> userTileProvider;

  private final Provider<BatterySaverTile> batterySaverTileProvider;

  private final Provider<DataSaverTile> dataSaverTileProvider;

  private final Provider<NightDisplayTile> nightDisplayTileProvider;

  private final Provider<NfcTile> nfcTileProvider;

  private final Provider<GarbageMonitor.MemoryTile> memoryTileProvider;

  private final Provider<UiModeNightTile> uiModeNightTileProvider;

  private final Provider<ScreenRecordTile> screenRecordTileProvider;

  private final Provider<ReduceBrightColorsTile> reduceBrightColorsTileProvider;

  private final Provider<CameraToggleTile> cameraToggleTileProvider;

  private final Provider<MicrophoneToggleTile> microphoneToggleTileProvider;

  private final Provider<DeviceControlsTile> deviceControlsTileProvider;

  private final Provider<AlarmTile> alarmTileProvider;

  private final Provider<QuickAccessWalletTile> quickAccessWalletTileProvider;

  private final Provider<AmbientDisplayTile> ambientDisplayTileProvider;

  private final Provider<AODTile> aodTileProvider;

  private final Provider<CaffeineTile> caffeineTileProvider;

  private final Provider<HeadsUpTile> headsUpTileProvider;

  private final Provider<PowerShareTile> powerShareTileProvider;

  private final Provider<ProfilesTile> profilesTileProvider;

  private final Provider<ReadingModeTile> readingModeTileProvider;

  private final Provider<SyncTile> syncTileProvider;

  private final Provider<UsbTetherTile> usbTetherTileProvider;

  private final Provider<VpnTile> vpnTileProvider;

  public QSFactoryImpl_Factory(Provider<QSHost> qsHostLazyProvider,
      Provider<CustomTile.Builder> customTileBuilderProvider, Provider<WifiTile> wifiTileProvider,
      Provider<InternetTile> internetTileProvider, Provider<BluetoothTile> bluetoothTileProvider,
      Provider<CellularTile> cellularTileProvider, Provider<DndTile> dndTileProvider,
      Provider<ColorInversionTile> colorInversionTileProvider,
      Provider<AirplaneModeTile> airplaneModeTileProvider,
      Provider<WorkModeTile> workModeTileProvider,
      Provider<RotationLockTile> rotationLockTileProvider,
      Provider<FlashlightTile> flashlightTileProvider, Provider<LocationTile> locationTileProvider,
      Provider<CastTile> castTileProvider, Provider<HotspotTile> hotspotTileProvider,
      Provider<UserTile> userTileProvider, Provider<BatterySaverTile> batterySaverTileProvider,
      Provider<DataSaverTile> dataSaverTileProvider,
      Provider<NightDisplayTile> nightDisplayTileProvider, Provider<NfcTile> nfcTileProvider,
      Provider<GarbageMonitor.MemoryTile> memoryTileProvider,
      Provider<UiModeNightTile> uiModeNightTileProvider,
      Provider<ScreenRecordTile> screenRecordTileProvider,
      Provider<ReduceBrightColorsTile> reduceBrightColorsTileProvider,
      Provider<CameraToggleTile> cameraToggleTileProvider,
      Provider<MicrophoneToggleTile> microphoneToggleTileProvider,
      Provider<DeviceControlsTile> deviceControlsTileProvider,
      Provider<AlarmTile> alarmTileProvider,
      Provider<QuickAccessWalletTile> quickAccessWalletTileProvider,
      Provider<AmbientDisplayTile> ambientDisplayTileProvider, Provider<AODTile> aodTileProvider,
      Provider<CaffeineTile> caffeineTileProvider, Provider<HeadsUpTile> headsUpTileProvider,
      Provider<PowerShareTile> powerShareTileProvider, Provider<ProfilesTile> profilesTileProvider,
      Provider<ReadingModeTile> readingModeTileProvider, Provider<SyncTile> syncTileProvider,
      Provider<UsbTetherTile> usbTetherTileProvider, Provider<VpnTile> vpnTileProvider) {
    this.qsHostLazyProvider = qsHostLazyProvider;
    this.customTileBuilderProvider = customTileBuilderProvider;
    this.wifiTileProvider = wifiTileProvider;
    this.internetTileProvider = internetTileProvider;
    this.bluetoothTileProvider = bluetoothTileProvider;
    this.cellularTileProvider = cellularTileProvider;
    this.dndTileProvider = dndTileProvider;
    this.colorInversionTileProvider = colorInversionTileProvider;
    this.airplaneModeTileProvider = airplaneModeTileProvider;
    this.workModeTileProvider = workModeTileProvider;
    this.rotationLockTileProvider = rotationLockTileProvider;
    this.flashlightTileProvider = flashlightTileProvider;
    this.locationTileProvider = locationTileProvider;
    this.castTileProvider = castTileProvider;
    this.hotspotTileProvider = hotspotTileProvider;
    this.userTileProvider = userTileProvider;
    this.batterySaverTileProvider = batterySaverTileProvider;
    this.dataSaverTileProvider = dataSaverTileProvider;
    this.nightDisplayTileProvider = nightDisplayTileProvider;
    this.nfcTileProvider = nfcTileProvider;
    this.memoryTileProvider = memoryTileProvider;
    this.uiModeNightTileProvider = uiModeNightTileProvider;
    this.screenRecordTileProvider = screenRecordTileProvider;
    this.reduceBrightColorsTileProvider = reduceBrightColorsTileProvider;
    this.cameraToggleTileProvider = cameraToggleTileProvider;
    this.microphoneToggleTileProvider = microphoneToggleTileProvider;
    this.deviceControlsTileProvider = deviceControlsTileProvider;
    this.alarmTileProvider = alarmTileProvider;
    this.quickAccessWalletTileProvider = quickAccessWalletTileProvider;
    this.ambientDisplayTileProvider = ambientDisplayTileProvider;
    this.aodTileProvider = aodTileProvider;
    this.caffeineTileProvider = caffeineTileProvider;
    this.headsUpTileProvider = headsUpTileProvider;
    this.powerShareTileProvider = powerShareTileProvider;
    this.profilesTileProvider = profilesTileProvider;
    this.readingModeTileProvider = readingModeTileProvider;
    this.syncTileProvider = syncTileProvider;
    this.usbTetherTileProvider = usbTetherTileProvider;
    this.vpnTileProvider = vpnTileProvider;
  }

  @Override
  public QSFactoryImpl get() {
    return newInstance(DoubleCheck.lazy(qsHostLazyProvider), customTileBuilderProvider, wifiTileProvider, internetTileProvider, bluetoothTileProvider, cellularTileProvider, dndTileProvider, colorInversionTileProvider, airplaneModeTileProvider, workModeTileProvider, rotationLockTileProvider, flashlightTileProvider, locationTileProvider, castTileProvider, hotspotTileProvider, userTileProvider, batterySaverTileProvider, dataSaverTileProvider, nightDisplayTileProvider, nfcTileProvider, memoryTileProvider, uiModeNightTileProvider, screenRecordTileProvider, reduceBrightColorsTileProvider, cameraToggleTileProvider, microphoneToggleTileProvider, deviceControlsTileProvider, alarmTileProvider, quickAccessWalletTileProvider, ambientDisplayTileProvider, aodTileProvider, caffeineTileProvider, headsUpTileProvider, powerShareTileProvider, profilesTileProvider, readingModeTileProvider, syncTileProvider, usbTetherTileProvider, vpnTileProvider);
  }

  public static QSFactoryImpl_Factory create(Provider<QSHost> qsHostLazyProvider,
      Provider<CustomTile.Builder> customTileBuilderProvider, Provider<WifiTile> wifiTileProvider,
      Provider<InternetTile> internetTileProvider, Provider<BluetoothTile> bluetoothTileProvider,
      Provider<CellularTile> cellularTileProvider, Provider<DndTile> dndTileProvider,
      Provider<ColorInversionTile> colorInversionTileProvider,
      Provider<AirplaneModeTile> airplaneModeTileProvider,
      Provider<WorkModeTile> workModeTileProvider,
      Provider<RotationLockTile> rotationLockTileProvider,
      Provider<FlashlightTile> flashlightTileProvider, Provider<LocationTile> locationTileProvider,
      Provider<CastTile> castTileProvider, Provider<HotspotTile> hotspotTileProvider,
      Provider<UserTile> userTileProvider, Provider<BatterySaverTile> batterySaverTileProvider,
      Provider<DataSaverTile> dataSaverTileProvider,
      Provider<NightDisplayTile> nightDisplayTileProvider, Provider<NfcTile> nfcTileProvider,
      Provider<GarbageMonitor.MemoryTile> memoryTileProvider,
      Provider<UiModeNightTile> uiModeNightTileProvider,
      Provider<ScreenRecordTile> screenRecordTileProvider,
      Provider<ReduceBrightColorsTile> reduceBrightColorsTileProvider,
      Provider<CameraToggleTile> cameraToggleTileProvider,
      Provider<MicrophoneToggleTile> microphoneToggleTileProvider,
      Provider<DeviceControlsTile> deviceControlsTileProvider,
      Provider<AlarmTile> alarmTileProvider,
      Provider<QuickAccessWalletTile> quickAccessWalletTileProvider,
      Provider<AmbientDisplayTile> ambientDisplayTileProvider, Provider<AODTile> aodTileProvider,
      Provider<CaffeineTile> caffeineTileProvider, Provider<HeadsUpTile> headsUpTileProvider,
      Provider<PowerShareTile> powerShareTileProvider, Provider<ProfilesTile> profilesTileProvider,
      Provider<ReadingModeTile> readingModeTileProvider, Provider<SyncTile> syncTileProvider,
      Provider<UsbTetherTile> usbTetherTileProvider, Provider<VpnTile> vpnTileProvider) {
    return new QSFactoryImpl_Factory(qsHostLazyProvider, customTileBuilderProvider, wifiTileProvider, internetTileProvider, bluetoothTileProvider, cellularTileProvider, dndTileProvider, colorInversionTileProvider, airplaneModeTileProvider, workModeTileProvider, rotationLockTileProvider, flashlightTileProvider, locationTileProvider, castTileProvider, hotspotTileProvider, userTileProvider, batterySaverTileProvider, dataSaverTileProvider, nightDisplayTileProvider, nfcTileProvider, memoryTileProvider, uiModeNightTileProvider, screenRecordTileProvider, reduceBrightColorsTileProvider, cameraToggleTileProvider, microphoneToggleTileProvider, deviceControlsTileProvider, alarmTileProvider, quickAccessWalletTileProvider, ambientDisplayTileProvider, aodTileProvider, caffeineTileProvider, headsUpTileProvider, powerShareTileProvider, profilesTileProvider, readingModeTileProvider, syncTileProvider, usbTetherTileProvider, vpnTileProvider);
  }

  public static QSFactoryImpl newInstance(Lazy<QSHost> qsHostLazy,
      Provider<CustomTile.Builder> customTileBuilderProvider, Provider<WifiTile> wifiTileProvider,
      Provider<InternetTile> internetTileProvider, Provider<BluetoothTile> bluetoothTileProvider,
      Provider<CellularTile> cellularTileProvider, Provider<DndTile> dndTileProvider,
      Provider<ColorInversionTile> colorInversionTileProvider,
      Provider<AirplaneModeTile> airplaneModeTileProvider,
      Provider<WorkModeTile> workModeTileProvider,
      Provider<RotationLockTile> rotationLockTileProvider,
      Provider<FlashlightTile> flashlightTileProvider, Provider<LocationTile> locationTileProvider,
      Provider<CastTile> castTileProvider, Provider<HotspotTile> hotspotTileProvider,
      Provider<UserTile> userTileProvider, Provider<BatterySaverTile> batterySaverTileProvider,
      Provider<DataSaverTile> dataSaverTileProvider,
      Provider<NightDisplayTile> nightDisplayTileProvider, Provider<NfcTile> nfcTileProvider,
      Provider<GarbageMonitor.MemoryTile> memoryTileProvider,
      Provider<UiModeNightTile> uiModeNightTileProvider,
      Provider<ScreenRecordTile> screenRecordTileProvider,
      Provider<ReduceBrightColorsTile> reduceBrightColorsTileProvider,
      Provider<CameraToggleTile> cameraToggleTileProvider,
      Provider<MicrophoneToggleTile> microphoneToggleTileProvider,
      Provider<DeviceControlsTile> deviceControlsTileProvider,
      Provider<AlarmTile> alarmTileProvider,
      Provider<QuickAccessWalletTile> quickAccessWalletTileProvider,
      Provider<AmbientDisplayTile> ambientDisplayTileProvider, Provider<AODTile> aodTileProvider,
      Provider<CaffeineTile> caffeineTileProvider, Provider<HeadsUpTile> headsUpTileProvider,
      Provider<PowerShareTile> powerShareTileProvider, Provider<ProfilesTile> profilesTileProvider,
      Provider<ReadingModeTile> readingModeTileProvider, Provider<SyncTile> syncTileProvider,
      Provider<UsbTetherTile> usbTetherTileProvider, Provider<VpnTile> vpnTileProvider) {
    return new QSFactoryImpl(qsHostLazy, customTileBuilderProvider, wifiTileProvider, internetTileProvider, bluetoothTileProvider, cellularTileProvider, dndTileProvider, colorInversionTileProvider, airplaneModeTileProvider, workModeTileProvider, rotationLockTileProvider, flashlightTileProvider, locationTileProvider, castTileProvider, hotspotTileProvider, userTileProvider, batterySaverTileProvider, dataSaverTileProvider, nightDisplayTileProvider, nfcTileProvider, memoryTileProvider, uiModeNightTileProvider, screenRecordTileProvider, reduceBrightColorsTileProvider, cameraToggleTileProvider, microphoneToggleTileProvider, deviceControlsTileProvider, alarmTileProvider, quickAccessWalletTileProvider, ambientDisplayTileProvider, aodTileProvider, caffeineTileProvider, headsUpTileProvider, powerShareTileProvider, profilesTileProvider, readingModeTileProvider, syncTileProvider, usbTetherTileProvider, vpnTileProvider);
  }
}
