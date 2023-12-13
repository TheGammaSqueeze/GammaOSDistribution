package com.android.systemui.qs;

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
public final class QSSquishinessController_Factory implements Factory<QSSquishinessController> {
  private final Provider<QSAnimator> qsAnimatorProvider;

  private final Provider<QSPanelController> qsPanelControllerProvider;

  private final Provider<QuickQSPanelController> quickQSPanelControllerProvider;

  public QSSquishinessController_Factory(Provider<QSAnimator> qsAnimatorProvider,
      Provider<QSPanelController> qsPanelControllerProvider,
      Provider<QuickQSPanelController> quickQSPanelControllerProvider) {
    this.qsAnimatorProvider = qsAnimatorProvider;
    this.qsPanelControllerProvider = qsPanelControllerProvider;
    this.quickQSPanelControllerProvider = quickQSPanelControllerProvider;
  }

  @Override
  public QSSquishinessController get() {
    return newInstance(qsAnimatorProvider.get(), qsPanelControllerProvider.get(), quickQSPanelControllerProvider.get());
  }

  public static QSSquishinessController_Factory create(Provider<QSAnimator> qsAnimatorProvider,
      Provider<QSPanelController> qsPanelControllerProvider,
      Provider<QuickQSPanelController> quickQSPanelControllerProvider) {
    return new QSSquishinessController_Factory(qsAnimatorProvider, qsPanelControllerProvider, quickQSPanelControllerProvider);
  }

  public static QSSquishinessController newInstance(QSAnimator qsAnimator,
      QSPanelController qsPanelController, QuickQSPanelController quickQSPanelController) {
    return new QSSquishinessController(qsAnimator, qsPanelController, quickQSPanelController);
  }
}
