package com.android.systemui.qs;

import com.android.systemui.statusbar.policy.ConfigurationController;
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
public final class QSContainerImplController_Factory implements Factory<QSContainerImplController> {
  private final Provider<QSContainerImpl> viewProvider;

  private final Provider<QSPanelController> qsPanelControllerProvider;

  private final Provider<QuickStatusBarHeaderController> quickStatusBarHeaderControllerProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  public QSContainerImplController_Factory(Provider<QSContainerImpl> viewProvider,
      Provider<QSPanelController> qsPanelControllerProvider,
      Provider<QuickStatusBarHeaderController> quickStatusBarHeaderControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider) {
    this.viewProvider = viewProvider;
    this.qsPanelControllerProvider = qsPanelControllerProvider;
    this.quickStatusBarHeaderControllerProvider = quickStatusBarHeaderControllerProvider;
    this.configurationControllerProvider = configurationControllerProvider;
  }

  @Override
  public QSContainerImplController get() {
    return newInstance(viewProvider.get(), qsPanelControllerProvider.get(), quickStatusBarHeaderControllerProvider.get(), configurationControllerProvider.get());
  }

  public static QSContainerImplController_Factory create(Provider<QSContainerImpl> viewProvider,
      Provider<QSPanelController> qsPanelControllerProvider,
      Provider<QuickStatusBarHeaderController> quickStatusBarHeaderControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider) {
    return new QSContainerImplController_Factory(viewProvider, qsPanelControllerProvider, quickStatusBarHeaderControllerProvider, configurationControllerProvider);
  }

  public static QSContainerImplController newInstance(QSContainerImpl view,
      QSPanelController qsPanelController, Object quickStatusBarHeaderController,
      ConfigurationController configurationController) {
    return new QSContainerImplController(view, qsPanelController, (QuickStatusBarHeaderController) quickStatusBarHeaderController, configurationController);
  }
}
