package com.android.systemui.qs;

import com.android.internal.logging.MetricsLogger;
import com.android.internal.logging.UiEventLogger;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.media.MediaHost;
import com.android.systemui.qs.customize.QSCustomizerController;
import com.android.systemui.qs.logging.QSLogger;
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
public final class QuickQSPanelController_Factory implements Factory<QuickQSPanelController> {
  private final Provider<QuickQSPanel> viewProvider;

  private final Provider<QSTileHost> qsTileHostProvider;

  private final Provider<QSCustomizerController> qsCustomizerControllerProvider;

  private final Provider<Boolean> usingMediaPlayerProvider;

  private final Provider<MediaHost> mediaHostProvider;

  private final Provider<MetricsLogger> metricsLoggerProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  private final Provider<QSLogger> qsLoggerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<FooterActionsController> footerActionsControllerProvider;

  public QuickQSPanelController_Factory(Provider<QuickQSPanel> viewProvider,
      Provider<QSTileHost> qsTileHostProvider,
      Provider<QSCustomizerController> qsCustomizerControllerProvider,
      Provider<Boolean> usingMediaPlayerProvider, Provider<MediaHost> mediaHostProvider,
      Provider<MetricsLogger> metricsLoggerProvider, Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<QSLogger> qsLoggerProvider, Provider<DumpManager> dumpManagerProvider,
      Provider<FooterActionsController> footerActionsControllerProvider) {
    this.viewProvider = viewProvider;
    this.qsTileHostProvider = qsTileHostProvider;
    this.qsCustomizerControllerProvider = qsCustomizerControllerProvider;
    this.usingMediaPlayerProvider = usingMediaPlayerProvider;
    this.mediaHostProvider = mediaHostProvider;
    this.metricsLoggerProvider = metricsLoggerProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
    this.qsLoggerProvider = qsLoggerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.footerActionsControllerProvider = footerActionsControllerProvider;
  }

  @Override
  public QuickQSPanelController get() {
    return newInstance(viewProvider.get(), qsTileHostProvider.get(), qsCustomizerControllerProvider.get(), usingMediaPlayerProvider.get(), mediaHostProvider.get(), metricsLoggerProvider.get(), uiEventLoggerProvider.get(), qsLoggerProvider.get(), dumpManagerProvider.get(), footerActionsControllerProvider.get());
  }

  public static QuickQSPanelController_Factory create(Provider<QuickQSPanel> viewProvider,
      Provider<QSTileHost> qsTileHostProvider,
      Provider<QSCustomizerController> qsCustomizerControllerProvider,
      Provider<Boolean> usingMediaPlayerProvider, Provider<MediaHost> mediaHostProvider,
      Provider<MetricsLogger> metricsLoggerProvider, Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<QSLogger> qsLoggerProvider, Provider<DumpManager> dumpManagerProvider,
      Provider<FooterActionsController> footerActionsControllerProvider) {
    return new QuickQSPanelController_Factory(viewProvider, qsTileHostProvider, qsCustomizerControllerProvider, usingMediaPlayerProvider, mediaHostProvider, metricsLoggerProvider, uiEventLoggerProvider, qsLoggerProvider, dumpManagerProvider, footerActionsControllerProvider);
  }

  public static QuickQSPanelController newInstance(QuickQSPanel view, QSTileHost qsTileHost,
      QSCustomizerController qsCustomizerController, boolean usingMediaPlayer, MediaHost mediaHost,
      MetricsLogger metricsLogger, UiEventLogger uiEventLogger, QSLogger qsLogger,
      DumpManager dumpManager, FooterActionsController footerActionsController) {
    return new QuickQSPanelController(view, qsTileHost, qsCustomizerController, usingMediaPlayer, mediaHost, metricsLogger, uiEventLogger, qsLogger, dumpManager, footerActionsController);
  }
}
