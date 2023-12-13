package com.android.systemui.qs.customize;

import com.android.internal.logging.UiEventLogger;
import com.android.systemui.keyguard.ScreenLifecycle;
import com.android.systemui.qs.QSTileHost;
import com.android.systemui.statusbar.phone.LightBarController;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
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
public final class QSCustomizerController_Factory implements Factory<QSCustomizerController> {
  private final Provider<QSCustomizer> viewProvider;

  private final Provider<TileQueryHelper> tileQueryHelperProvider;

  private final Provider<QSTileHost> qsTileHostProvider;

  private final Provider<TileAdapter> tileAdapterProvider;

  private final Provider<ScreenLifecycle> screenLifecycleProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<LightBarController> lightBarControllerProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  public QSCustomizerController_Factory(Provider<QSCustomizer> viewProvider,
      Provider<TileQueryHelper> tileQueryHelperProvider, Provider<QSTileHost> qsTileHostProvider,
      Provider<TileAdapter> tileAdapterProvider, Provider<ScreenLifecycle> screenLifecycleProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<LightBarController> lightBarControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<UiEventLogger> uiEventLoggerProvider) {
    this.viewProvider = viewProvider;
    this.tileQueryHelperProvider = tileQueryHelperProvider;
    this.qsTileHostProvider = qsTileHostProvider;
    this.tileAdapterProvider = tileAdapterProvider;
    this.screenLifecycleProvider = screenLifecycleProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.lightBarControllerProvider = lightBarControllerProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
  }

  @Override
  public QSCustomizerController get() {
    return newInstance(viewProvider.get(), tileQueryHelperProvider.get(), qsTileHostProvider.get(), tileAdapterProvider.get(), screenLifecycleProvider.get(), keyguardStateControllerProvider.get(), lightBarControllerProvider.get(), configurationControllerProvider.get(), uiEventLoggerProvider.get());
  }

  public static QSCustomizerController_Factory create(Provider<QSCustomizer> viewProvider,
      Provider<TileQueryHelper> tileQueryHelperProvider, Provider<QSTileHost> qsTileHostProvider,
      Provider<TileAdapter> tileAdapterProvider, Provider<ScreenLifecycle> screenLifecycleProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<LightBarController> lightBarControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<UiEventLogger> uiEventLoggerProvider) {
    return new QSCustomizerController_Factory(viewProvider, tileQueryHelperProvider, qsTileHostProvider, tileAdapterProvider, screenLifecycleProvider, keyguardStateControllerProvider, lightBarControllerProvider, configurationControllerProvider, uiEventLoggerProvider);
  }

  public static QSCustomizerController newInstance(QSCustomizer view,
      TileQueryHelper tileQueryHelper, QSTileHost qsTileHost, TileAdapter tileAdapter,
      ScreenLifecycle screenLifecycle, KeyguardStateController keyguardStateController,
      LightBarController lightBarController, ConfigurationController configurationController,
      UiEventLogger uiEventLogger) {
    return new QSCustomizerController(view, tileQueryHelper, qsTileHost, tileAdapter, screenLifecycle, keyguardStateController, lightBarController, configurationController, uiEventLogger);
  }
}
