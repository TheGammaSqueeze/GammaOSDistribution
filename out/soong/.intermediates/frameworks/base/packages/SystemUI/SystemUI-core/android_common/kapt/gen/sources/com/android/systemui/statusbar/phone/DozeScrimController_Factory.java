package com.android.systemui.statusbar.phone;

import com.android.systemui.doze.DozeLog;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
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
public final class DozeScrimController_Factory implements Factory<DozeScrimController> {
  private final Provider<DozeParameters> dozeParametersProvider;

  private final Provider<DozeLog> dozeLogProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  public DozeScrimController_Factory(Provider<DozeParameters> dozeParametersProvider,
      Provider<DozeLog> dozeLogProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider) {
    this.dozeParametersProvider = dozeParametersProvider;
    this.dozeLogProvider = dozeLogProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
  }

  @Override
  public DozeScrimController get() {
    return newInstance(dozeParametersProvider.get(), dozeLogProvider.get(), statusBarStateControllerProvider.get());
  }

  public static DozeScrimController_Factory create(Provider<DozeParameters> dozeParametersProvider,
      Provider<DozeLog> dozeLogProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider) {
    return new DozeScrimController_Factory(dozeParametersProvider, dozeLogProvider, statusBarStateControllerProvider);
  }

  public static DozeScrimController newInstance(DozeParameters dozeParameters, DozeLog dozeLog,
      StatusBarStateController statusBarStateController) {
    return new DozeScrimController(dozeParameters, dozeLog, statusBarStateController);
  }
}
