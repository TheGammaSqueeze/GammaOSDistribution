package com.android.systemui.qs;

import com.android.systemui.plugins.qs.QS;
import com.android.systemui.tuner.TunerService;
import dagger.internal.Factory;
import java.util.concurrent.Executor;
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
public final class QSAnimator_Factory implements Factory<QSAnimator> {
  private final Provider<QS> qsProvider;

  private final Provider<QuickQSPanel> quickPanelProvider;

  private final Provider<QuickStatusBarHeader> quickStatusBarHeaderProvider;

  private final Provider<QSPanelController> qsPanelControllerProvider;

  private final Provider<QuickQSPanelController> quickQSPanelControllerProvider;

  private final Provider<QSTileHost> qsTileHostProvider;

  private final Provider<QSSecurityFooter> securityFooterProvider;

  private final Provider<Executor> executorProvider;

  private final Provider<TunerService> tunerServiceProvider;

  private final Provider<QSExpansionPathInterpolator> qsExpansionPathInterpolatorProvider;

  private final Provider<FooterActionsView> qsFooterActionsViewProvider;

  private final Provider<FooterActionsView> qqsFooterActionsViewProvider;

  public QSAnimator_Factory(Provider<QS> qsProvider, Provider<QuickQSPanel> quickPanelProvider,
      Provider<QuickStatusBarHeader> quickStatusBarHeaderProvider,
      Provider<QSPanelController> qsPanelControllerProvider,
      Provider<QuickQSPanelController> quickQSPanelControllerProvider,
      Provider<QSTileHost> qsTileHostProvider, Provider<QSSecurityFooter> securityFooterProvider,
      Provider<Executor> executorProvider, Provider<TunerService> tunerServiceProvider,
      Provider<QSExpansionPathInterpolator> qsExpansionPathInterpolatorProvider,
      Provider<FooterActionsView> qsFooterActionsViewProvider,
      Provider<FooterActionsView> qqsFooterActionsViewProvider) {
    this.qsProvider = qsProvider;
    this.quickPanelProvider = quickPanelProvider;
    this.quickStatusBarHeaderProvider = quickStatusBarHeaderProvider;
    this.qsPanelControllerProvider = qsPanelControllerProvider;
    this.quickQSPanelControllerProvider = quickQSPanelControllerProvider;
    this.qsTileHostProvider = qsTileHostProvider;
    this.securityFooterProvider = securityFooterProvider;
    this.executorProvider = executorProvider;
    this.tunerServiceProvider = tunerServiceProvider;
    this.qsExpansionPathInterpolatorProvider = qsExpansionPathInterpolatorProvider;
    this.qsFooterActionsViewProvider = qsFooterActionsViewProvider;
    this.qqsFooterActionsViewProvider = qqsFooterActionsViewProvider;
  }

  @Override
  public QSAnimator get() {
    return newInstance(qsProvider.get(), quickPanelProvider.get(), quickStatusBarHeaderProvider.get(), qsPanelControllerProvider.get(), quickQSPanelControllerProvider.get(), qsTileHostProvider.get(), securityFooterProvider.get(), executorProvider.get(), tunerServiceProvider.get(), qsExpansionPathInterpolatorProvider.get(), qsFooterActionsViewProvider.get(), qqsFooterActionsViewProvider.get());
  }

  public static QSAnimator_Factory create(Provider<QS> qsProvider,
      Provider<QuickQSPanel> quickPanelProvider,
      Provider<QuickStatusBarHeader> quickStatusBarHeaderProvider,
      Provider<QSPanelController> qsPanelControllerProvider,
      Provider<QuickQSPanelController> quickQSPanelControllerProvider,
      Provider<QSTileHost> qsTileHostProvider, Provider<QSSecurityFooter> securityFooterProvider,
      Provider<Executor> executorProvider, Provider<TunerService> tunerServiceProvider,
      Provider<QSExpansionPathInterpolator> qsExpansionPathInterpolatorProvider,
      Provider<FooterActionsView> qsFooterActionsViewProvider,
      Provider<FooterActionsView> qqsFooterActionsViewProvider) {
    return new QSAnimator_Factory(qsProvider, quickPanelProvider, quickStatusBarHeaderProvider, qsPanelControllerProvider, quickQSPanelControllerProvider, qsTileHostProvider, securityFooterProvider, executorProvider, tunerServiceProvider, qsExpansionPathInterpolatorProvider, qsFooterActionsViewProvider, qqsFooterActionsViewProvider);
  }

  public static QSAnimator newInstance(QS qs, QuickQSPanel quickPanel,
      QuickStatusBarHeader quickStatusBarHeader, QSPanelController qsPanelController,
      QuickQSPanelController quickQSPanelController, QSTileHost qsTileHost, Object securityFooter,
      Executor executor, TunerService tunerService,
      QSExpansionPathInterpolator qsExpansionPathInterpolator,
      FooterActionsView qsFooterActionsView, FooterActionsView qqsFooterActionsView) {
    return new QSAnimator(qs, quickPanel, quickStatusBarHeader, qsPanelController, quickQSPanelController, qsTileHost, (QSSecurityFooter) securityFooter, executor, tunerService, qsExpansionPathInterpolator, qsFooterActionsView, qqsFooterActionsView);
  }
}
