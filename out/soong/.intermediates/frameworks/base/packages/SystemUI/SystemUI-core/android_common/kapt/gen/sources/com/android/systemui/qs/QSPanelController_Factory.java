package com.android.systemui.qs;

import com.android.internal.logging.MetricsLogger;
import com.android.internal.logging.UiEventLogger;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.media.MediaHost;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.qs.customize.QSCustomizerController;
import com.android.systemui.qs.logging.QSLogger;
import com.android.systemui.settings.brightness.BrightnessController;
import com.android.systemui.settings.brightness.BrightnessSliderController;
import com.android.systemui.statusbar.CommandQueue;
import com.android.systemui.tuner.TunerService;
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
public final class QSPanelController_Factory implements Factory<QSPanelController> {
  private final Provider<QSPanel> viewProvider;

  private final Provider<QSSecurityFooter> qsSecurityFooterProvider;

  private final Provider<TunerService> tunerServiceProvider;

  private final Provider<QSTileHost> qstileHostProvider;

  private final Provider<QSCustomizerController> qsCustomizerControllerProvider;

  private final Provider<Boolean> usingMediaPlayerProvider;

  private final Provider<MediaHost> mediaHostProvider;

  private final Provider<QSTileRevealController.Factory> qsTileRevealControllerFactoryProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<MetricsLogger> metricsLoggerProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  private final Provider<QSLogger> qsLoggerProvider;

  private final Provider<BrightnessController.Factory> brightnessControllerFactoryProvider;

  private final Provider<BrightnessSliderController.Factory> brightnessSliderFactoryProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  public QSPanelController_Factory(Provider<QSPanel> viewProvider,
      Provider<QSSecurityFooter> qsSecurityFooterProvider,
      Provider<TunerService> tunerServiceProvider, Provider<QSTileHost> qstileHostProvider,
      Provider<QSCustomizerController> qsCustomizerControllerProvider,
      Provider<Boolean> usingMediaPlayerProvider, Provider<MediaHost> mediaHostProvider,
      Provider<QSTileRevealController.Factory> qsTileRevealControllerFactoryProvider,
      Provider<DumpManager> dumpManagerProvider, Provider<MetricsLogger> metricsLoggerProvider,
      Provider<UiEventLogger> uiEventLoggerProvider, Provider<QSLogger> qsLoggerProvider,
      Provider<BrightnessController.Factory> brightnessControllerFactoryProvider,
      Provider<BrightnessSliderController.Factory> brightnessSliderFactoryProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<CommandQueue> commandQueueProvider) {
    this.viewProvider = viewProvider;
    this.qsSecurityFooterProvider = qsSecurityFooterProvider;
    this.tunerServiceProvider = tunerServiceProvider;
    this.qstileHostProvider = qstileHostProvider;
    this.qsCustomizerControllerProvider = qsCustomizerControllerProvider;
    this.usingMediaPlayerProvider = usingMediaPlayerProvider;
    this.mediaHostProvider = mediaHostProvider;
    this.qsTileRevealControllerFactoryProvider = qsTileRevealControllerFactoryProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.metricsLoggerProvider = metricsLoggerProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
    this.qsLoggerProvider = qsLoggerProvider;
    this.brightnessControllerFactoryProvider = brightnessControllerFactoryProvider;
    this.brightnessSliderFactoryProvider = brightnessSliderFactoryProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.commandQueueProvider = commandQueueProvider;
  }

  @Override
  public QSPanelController get() {
    return newInstance(viewProvider.get(), qsSecurityFooterProvider.get(), tunerServiceProvider.get(), qstileHostProvider.get(), qsCustomizerControllerProvider.get(), usingMediaPlayerProvider.get(), mediaHostProvider.get(), qsTileRevealControllerFactoryProvider.get(), dumpManagerProvider.get(), metricsLoggerProvider.get(), uiEventLoggerProvider.get(), qsLoggerProvider.get(), brightnessControllerFactoryProvider.get(), brightnessSliderFactoryProvider.get(), falsingManagerProvider.get(), commandQueueProvider.get());
  }

  public static QSPanelController_Factory create(Provider<QSPanel> viewProvider,
      Provider<QSSecurityFooter> qsSecurityFooterProvider,
      Provider<TunerService> tunerServiceProvider, Provider<QSTileHost> qstileHostProvider,
      Provider<QSCustomizerController> qsCustomizerControllerProvider,
      Provider<Boolean> usingMediaPlayerProvider, Provider<MediaHost> mediaHostProvider,
      Provider<QSTileRevealController.Factory> qsTileRevealControllerFactoryProvider,
      Provider<DumpManager> dumpManagerProvider, Provider<MetricsLogger> metricsLoggerProvider,
      Provider<UiEventLogger> uiEventLoggerProvider, Provider<QSLogger> qsLoggerProvider,
      Provider<BrightnessController.Factory> brightnessControllerFactoryProvider,
      Provider<BrightnessSliderController.Factory> brightnessSliderFactoryProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<CommandQueue> commandQueueProvider) {
    return new QSPanelController_Factory(viewProvider, qsSecurityFooterProvider, tunerServiceProvider, qstileHostProvider, qsCustomizerControllerProvider, usingMediaPlayerProvider, mediaHostProvider, qsTileRevealControllerFactoryProvider, dumpManagerProvider, metricsLoggerProvider, uiEventLoggerProvider, qsLoggerProvider, brightnessControllerFactoryProvider, brightnessSliderFactoryProvider, falsingManagerProvider, commandQueueProvider);
  }

  public static QSPanelController newInstance(QSPanel view, Object qsSecurityFooter,
      TunerService tunerService, QSTileHost qstileHost,
      QSCustomizerController qsCustomizerController, boolean usingMediaPlayer, MediaHost mediaHost,
      Object qsTileRevealControllerFactory, DumpManager dumpManager, MetricsLogger metricsLogger,
      UiEventLogger uiEventLogger, QSLogger qsLogger,
      BrightnessController.Factory brightnessControllerFactory,
      BrightnessSliderController.Factory brightnessSliderFactory, FalsingManager falsingManager,
      CommandQueue commandQueue) {
    return new QSPanelController(view, (QSSecurityFooter) qsSecurityFooter, tunerService, qstileHost, qsCustomizerController, usingMediaPlayer, mediaHost, (QSTileRevealController.Factory) qsTileRevealControllerFactory, dumpManager, metricsLogger, uiEventLogger, qsLogger, brightnessControllerFactory, brightnessSliderFactory, falsingManager, commandQueue);
  }
}
