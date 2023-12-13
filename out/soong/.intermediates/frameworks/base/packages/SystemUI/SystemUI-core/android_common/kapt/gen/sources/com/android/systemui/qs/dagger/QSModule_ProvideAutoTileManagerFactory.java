package com.android.systemui.qs.dagger;

import android.content.Context;
import android.hardware.display.NightDisplayListener;
import android.os.Handler;
import com.android.systemui.qs.AutoAddTracker;
import com.android.systemui.qs.QSTileHost;
import com.android.systemui.qs.ReduceBrightColorsController;
import com.android.systemui.statusbar.phone.AutoTileManager;
import com.android.systemui.statusbar.phone.ManagedProfileController;
import com.android.systemui.statusbar.policy.CastController;
import com.android.systemui.statusbar.policy.DataSaverController;
import com.android.systemui.statusbar.policy.DeviceControlsController;
import com.android.systemui.statusbar.policy.HotspotController;
import com.android.systemui.statusbar.policy.WalletController;
import com.android.systemui.util.settings.SecureSettings;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class QSModule_ProvideAutoTileManagerFactory implements Factory<AutoTileManager> {
  private final Provider<Context> contextProvider;

  private final Provider<AutoAddTracker.Builder> autoAddTrackerBuilderProvider;

  private final Provider<QSTileHost> hostProvider;

  private final Provider<Handler> handlerProvider;

  private final Provider<SecureSettings> secureSettingsProvider;

  private final Provider<HotspotController> hotspotControllerProvider;

  private final Provider<DataSaverController> dataSaverControllerProvider;

  private final Provider<ManagedProfileController> managedProfileControllerProvider;

  private final Provider<NightDisplayListener> nightDisplayListenerProvider;

  private final Provider<CastController> castControllerProvider;

  private final Provider<ReduceBrightColorsController> reduceBrightColorsControllerProvider;

  private final Provider<DeviceControlsController> deviceControlsControllerProvider;

  private final Provider<WalletController> walletControllerProvider;

  private final Provider<Boolean> isReduceBrightColorsAvailableProvider;

  public QSModule_ProvideAutoTileManagerFactory(Provider<Context> contextProvider,
      Provider<AutoAddTracker.Builder> autoAddTrackerBuilderProvider,
      Provider<QSTileHost> hostProvider, Provider<Handler> handlerProvider,
      Provider<SecureSettings> secureSettingsProvider,
      Provider<HotspotController> hotspotControllerProvider,
      Provider<DataSaverController> dataSaverControllerProvider,
      Provider<ManagedProfileController> managedProfileControllerProvider,
      Provider<NightDisplayListener> nightDisplayListenerProvider,
      Provider<CastController> castControllerProvider,
      Provider<ReduceBrightColorsController> reduceBrightColorsControllerProvider,
      Provider<DeviceControlsController> deviceControlsControllerProvider,
      Provider<WalletController> walletControllerProvider,
      Provider<Boolean> isReduceBrightColorsAvailableProvider) {
    this.contextProvider = contextProvider;
    this.autoAddTrackerBuilderProvider = autoAddTrackerBuilderProvider;
    this.hostProvider = hostProvider;
    this.handlerProvider = handlerProvider;
    this.secureSettingsProvider = secureSettingsProvider;
    this.hotspotControllerProvider = hotspotControllerProvider;
    this.dataSaverControllerProvider = dataSaverControllerProvider;
    this.managedProfileControllerProvider = managedProfileControllerProvider;
    this.nightDisplayListenerProvider = nightDisplayListenerProvider;
    this.castControllerProvider = castControllerProvider;
    this.reduceBrightColorsControllerProvider = reduceBrightColorsControllerProvider;
    this.deviceControlsControllerProvider = deviceControlsControllerProvider;
    this.walletControllerProvider = walletControllerProvider;
    this.isReduceBrightColorsAvailableProvider = isReduceBrightColorsAvailableProvider;
  }

  @Override
  public AutoTileManager get() {
    return provideAutoTileManager(contextProvider.get(), autoAddTrackerBuilderProvider.get(), hostProvider.get(), handlerProvider.get(), secureSettingsProvider.get(), hotspotControllerProvider.get(), dataSaverControllerProvider.get(), managedProfileControllerProvider.get(), nightDisplayListenerProvider.get(), castControllerProvider.get(), reduceBrightColorsControllerProvider.get(), deviceControlsControllerProvider.get(), walletControllerProvider.get(), isReduceBrightColorsAvailableProvider.get());
  }

  public static QSModule_ProvideAutoTileManagerFactory create(Provider<Context> contextProvider,
      Provider<AutoAddTracker.Builder> autoAddTrackerBuilderProvider,
      Provider<QSTileHost> hostProvider, Provider<Handler> handlerProvider,
      Provider<SecureSettings> secureSettingsProvider,
      Provider<HotspotController> hotspotControllerProvider,
      Provider<DataSaverController> dataSaverControllerProvider,
      Provider<ManagedProfileController> managedProfileControllerProvider,
      Provider<NightDisplayListener> nightDisplayListenerProvider,
      Provider<CastController> castControllerProvider,
      Provider<ReduceBrightColorsController> reduceBrightColorsControllerProvider,
      Provider<DeviceControlsController> deviceControlsControllerProvider,
      Provider<WalletController> walletControllerProvider,
      Provider<Boolean> isReduceBrightColorsAvailableProvider) {
    return new QSModule_ProvideAutoTileManagerFactory(contextProvider, autoAddTrackerBuilderProvider, hostProvider, handlerProvider, secureSettingsProvider, hotspotControllerProvider, dataSaverControllerProvider, managedProfileControllerProvider, nightDisplayListenerProvider, castControllerProvider, reduceBrightColorsControllerProvider, deviceControlsControllerProvider, walletControllerProvider, isReduceBrightColorsAvailableProvider);
  }

  public static AutoTileManager provideAutoTileManager(Context context,
      AutoAddTracker.Builder autoAddTrackerBuilder, QSTileHost host, Handler handler,
      SecureSettings secureSettings, HotspotController hotspotController,
      DataSaverController dataSaverController, ManagedProfileController managedProfileController,
      NightDisplayListener nightDisplayListener, CastController castController,
      ReduceBrightColorsController reduceBrightColorsController,
      DeviceControlsController deviceControlsController, WalletController walletController,
      boolean isReduceBrightColorsAvailable) {
    return Preconditions.checkNotNullFromProvides(QSModule.provideAutoTileManager(context, autoAddTrackerBuilder, host, handler, secureSettings, hotspotController, dataSaverController, managedProfileController, nightDisplayListener, castController, reduceBrightColorsController, deviceControlsController, walletController, isReduceBrightColorsAvailable));
  }
}
