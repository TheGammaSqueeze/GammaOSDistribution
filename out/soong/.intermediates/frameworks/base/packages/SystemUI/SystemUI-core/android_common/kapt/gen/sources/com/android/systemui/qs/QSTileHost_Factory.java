package com.android.systemui.qs;

import android.content.Context;
import android.os.Handler;
import android.os.Looper;
import com.android.internal.logging.UiEventLogger;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.plugins.qs.QSFactory;
import com.android.systemui.qs.external.CustomTileStatePersister;
import com.android.systemui.qs.logging.QSLogger;
import com.android.systemui.settings.UserTracker;
import com.android.systemui.shared.plugins.PluginManager;
import com.android.systemui.statusbar.phone.AutoTileManager;
import com.android.systemui.statusbar.phone.StatusBar;
import com.android.systemui.statusbar.phone.StatusBarIconController;
import com.android.systemui.tuner.TunerService;
import com.android.systemui.util.settings.SecureSettings;
import dagger.internal.Factory;
import java.util.Optional;
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
public final class QSTileHost_Factory implements Factory<QSTileHost> {
  private final Provider<Context> contextProvider;

  private final Provider<StatusBarIconController> iconControllerProvider;

  private final Provider<QSFactory> defaultFactoryProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<Looper> bgLooperProvider;

  private final Provider<PluginManager> pluginManagerProvider;

  private final Provider<TunerService> tunerServiceProvider;

  private final Provider<AutoTileManager> autoTilesProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<Optional<StatusBar>> statusBarOptionalProvider;

  private final Provider<QSLogger> qsLoggerProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  private final Provider<UserTracker> userTrackerProvider;

  private final Provider<SecureSettings> secureSettingsProvider;

  private final Provider<CustomTileStatePersister> customTileStatePersisterProvider;

  public QSTileHost_Factory(Provider<Context> contextProvider,
      Provider<StatusBarIconController> iconControllerProvider,
      Provider<QSFactory> defaultFactoryProvider, Provider<Handler> mainHandlerProvider,
      Provider<Looper> bgLooperProvider, Provider<PluginManager> pluginManagerProvider,
      Provider<TunerService> tunerServiceProvider, Provider<AutoTileManager> autoTilesProvider,
      Provider<DumpManager> dumpManagerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<Optional<StatusBar>> statusBarOptionalProvider, Provider<QSLogger> qsLoggerProvider,
      Provider<UiEventLogger> uiEventLoggerProvider, Provider<UserTracker> userTrackerProvider,
      Provider<SecureSettings> secureSettingsProvider,
      Provider<CustomTileStatePersister> customTileStatePersisterProvider) {
    this.contextProvider = contextProvider;
    this.iconControllerProvider = iconControllerProvider;
    this.defaultFactoryProvider = defaultFactoryProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.bgLooperProvider = bgLooperProvider;
    this.pluginManagerProvider = pluginManagerProvider;
    this.tunerServiceProvider = tunerServiceProvider;
    this.autoTilesProvider = autoTilesProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.statusBarOptionalProvider = statusBarOptionalProvider;
    this.qsLoggerProvider = qsLoggerProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
    this.userTrackerProvider = userTrackerProvider;
    this.secureSettingsProvider = secureSettingsProvider;
    this.customTileStatePersisterProvider = customTileStatePersisterProvider;
  }

  @Override
  public QSTileHost get() {
    return newInstance(contextProvider.get(), iconControllerProvider.get(), defaultFactoryProvider.get(), mainHandlerProvider.get(), bgLooperProvider.get(), pluginManagerProvider.get(), tunerServiceProvider.get(), autoTilesProvider, dumpManagerProvider.get(), broadcastDispatcherProvider.get(), statusBarOptionalProvider.get(), qsLoggerProvider.get(), uiEventLoggerProvider.get(), userTrackerProvider.get(), secureSettingsProvider.get(), customTileStatePersisterProvider.get());
  }

  public static QSTileHost_Factory create(Provider<Context> contextProvider,
      Provider<StatusBarIconController> iconControllerProvider,
      Provider<QSFactory> defaultFactoryProvider, Provider<Handler> mainHandlerProvider,
      Provider<Looper> bgLooperProvider, Provider<PluginManager> pluginManagerProvider,
      Provider<TunerService> tunerServiceProvider, Provider<AutoTileManager> autoTilesProvider,
      Provider<DumpManager> dumpManagerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<Optional<StatusBar>> statusBarOptionalProvider, Provider<QSLogger> qsLoggerProvider,
      Provider<UiEventLogger> uiEventLoggerProvider, Provider<UserTracker> userTrackerProvider,
      Provider<SecureSettings> secureSettingsProvider,
      Provider<CustomTileStatePersister> customTileStatePersisterProvider) {
    return new QSTileHost_Factory(contextProvider, iconControllerProvider, defaultFactoryProvider, mainHandlerProvider, bgLooperProvider, pluginManagerProvider, tunerServiceProvider, autoTilesProvider, dumpManagerProvider, broadcastDispatcherProvider, statusBarOptionalProvider, qsLoggerProvider, uiEventLoggerProvider, userTrackerProvider, secureSettingsProvider, customTileStatePersisterProvider);
  }

  public static QSTileHost newInstance(Context context, StatusBarIconController iconController,
      QSFactory defaultFactory, Handler mainHandler, Looper bgLooper, PluginManager pluginManager,
      TunerService tunerService, Provider<AutoTileManager> autoTiles, DumpManager dumpManager,
      BroadcastDispatcher broadcastDispatcher, Optional<StatusBar> statusBarOptional,
      QSLogger qsLogger, UiEventLogger uiEventLogger, UserTracker userTracker,
      SecureSettings secureSettings, CustomTileStatePersister customTileStatePersister) {
    return new QSTileHost(context, iconController, defaultFactory, mainHandler, bgLooper, pluginManager, tunerService, autoTiles, dumpManager, broadcastDispatcher, statusBarOptional, qsLogger, uiEventLogger, userTracker, secureSettings, customTileStatePersister);
  }
}
