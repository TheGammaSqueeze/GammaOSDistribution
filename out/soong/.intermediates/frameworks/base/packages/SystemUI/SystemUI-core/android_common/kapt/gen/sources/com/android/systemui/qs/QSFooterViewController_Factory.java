package com.android.systemui.qs;

import com.android.systemui.settings.UserTracker;
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
public final class QSFooterViewController_Factory implements Factory<QSFooterViewController> {
  private final Provider<QSFooterView> viewProvider;

  private final Provider<UserTracker> userTrackerProvider;

  private final Provider<QSPanelController> qsPanelControllerProvider;

  private final Provider<QuickQSPanelController> quickQSPanelControllerProvider;

  private final Provider<FooterActionsController> footerActionsControllerProvider;

  public QSFooterViewController_Factory(Provider<QSFooterView> viewProvider,
      Provider<UserTracker> userTrackerProvider,
      Provider<QSPanelController> qsPanelControllerProvider,
      Provider<QuickQSPanelController> quickQSPanelControllerProvider,
      Provider<FooterActionsController> footerActionsControllerProvider) {
    this.viewProvider = viewProvider;
    this.userTrackerProvider = userTrackerProvider;
    this.qsPanelControllerProvider = qsPanelControllerProvider;
    this.quickQSPanelControllerProvider = quickQSPanelControllerProvider;
    this.footerActionsControllerProvider = footerActionsControllerProvider;
  }

  @Override
  public QSFooterViewController get() {
    return newInstance(viewProvider.get(), userTrackerProvider.get(), qsPanelControllerProvider.get(), quickQSPanelControllerProvider.get(), footerActionsControllerProvider.get());
  }

  public static QSFooterViewController_Factory create(Provider<QSFooterView> viewProvider,
      Provider<UserTracker> userTrackerProvider,
      Provider<QSPanelController> qsPanelControllerProvider,
      Provider<QuickQSPanelController> quickQSPanelControllerProvider,
      Provider<FooterActionsController> footerActionsControllerProvider) {
    return new QSFooterViewController_Factory(viewProvider, userTrackerProvider, qsPanelControllerProvider, quickQSPanelControllerProvider, footerActionsControllerProvider);
  }

  public static QSFooterViewController newInstance(QSFooterView view, UserTracker userTracker,
      QSPanelController qsPanelController, QuickQSPanelController quickQSPanelController,
      FooterActionsController footerActionsController) {
    return new QSFooterViewController(view, userTracker, qsPanelController, quickQSPanelController, footerActionsController);
  }
}
