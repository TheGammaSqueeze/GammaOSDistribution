package com.android.systemui.statusbar.phone;

import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.util.concurrency.DelayableExecutor;
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
public final class TapAgainViewController_Factory implements Factory<TapAgainViewController> {
  private final Provider<TapAgainView> viewProvider;

  private final Provider<DelayableExecutor> delayableExecutorProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<Long> doubleTapTimeMsProvider;

  public TapAgainViewController_Factory(Provider<TapAgainView> viewProvider,
      Provider<DelayableExecutor> delayableExecutorProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<Long> doubleTapTimeMsProvider) {
    this.viewProvider = viewProvider;
    this.delayableExecutorProvider = delayableExecutorProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.doubleTapTimeMsProvider = doubleTapTimeMsProvider;
  }

  @Override
  public TapAgainViewController get() {
    return newInstance(viewProvider.get(), delayableExecutorProvider.get(), configurationControllerProvider.get(), doubleTapTimeMsProvider.get());
  }

  public static TapAgainViewController_Factory create(Provider<TapAgainView> viewProvider,
      Provider<DelayableExecutor> delayableExecutorProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<Long> doubleTapTimeMsProvider) {
    return new TapAgainViewController_Factory(viewProvider, delayableExecutorProvider, configurationControllerProvider, doubleTapTimeMsProvider);
  }

  public static TapAgainViewController newInstance(TapAgainView view,
      DelayableExecutor delayableExecutor, ConfigurationController configurationController,
      long doubleTapTimeMs) {
    return new TapAgainViewController(view, delayableExecutor, configurationController, doubleTapTimeMs);
  }
}
