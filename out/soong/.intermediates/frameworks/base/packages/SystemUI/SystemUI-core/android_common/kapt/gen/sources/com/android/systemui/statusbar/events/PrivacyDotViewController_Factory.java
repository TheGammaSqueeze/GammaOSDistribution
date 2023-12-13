package com.android.systemui.statusbar.events;

import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.phone.StatusBarContentInsetsProvider;
import com.android.systemui.statusbar.policy.ConfigurationController;
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
public final class PrivacyDotViewController_Factory implements Factory<PrivacyDotViewController> {
  private final Provider<Executor> mainExecutorProvider;

  private final Provider<StatusBarStateController> stateControllerProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<StatusBarContentInsetsProvider> contentInsetsProvider;

  private final Provider<SystemStatusAnimationScheduler> animationSchedulerProvider;

  public PrivacyDotViewController_Factory(Provider<Executor> mainExecutorProvider,
      Provider<StatusBarStateController> stateControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<StatusBarContentInsetsProvider> contentInsetsProvider,
      Provider<SystemStatusAnimationScheduler> animationSchedulerProvider) {
    this.mainExecutorProvider = mainExecutorProvider;
    this.stateControllerProvider = stateControllerProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.contentInsetsProvider = contentInsetsProvider;
    this.animationSchedulerProvider = animationSchedulerProvider;
  }

  @Override
  public PrivacyDotViewController get() {
    return newInstance(mainExecutorProvider.get(), stateControllerProvider.get(), configurationControllerProvider.get(), contentInsetsProvider.get(), animationSchedulerProvider.get());
  }

  public static PrivacyDotViewController_Factory create(Provider<Executor> mainExecutorProvider,
      Provider<StatusBarStateController> stateControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<StatusBarContentInsetsProvider> contentInsetsProvider,
      Provider<SystemStatusAnimationScheduler> animationSchedulerProvider) {
    return new PrivacyDotViewController_Factory(mainExecutorProvider, stateControllerProvider, configurationControllerProvider, contentInsetsProvider, animationSchedulerProvider);
  }

  public static PrivacyDotViewController newInstance(Executor mainExecutor,
      StatusBarStateController stateController, ConfigurationController configurationController,
      StatusBarContentInsetsProvider contentInsetsProvider,
      SystemStatusAnimationScheduler animationScheduler) {
    return new PrivacyDotViewController(mainExecutor, stateController, configurationController, contentInsetsProvider, animationScheduler);
  }
}
