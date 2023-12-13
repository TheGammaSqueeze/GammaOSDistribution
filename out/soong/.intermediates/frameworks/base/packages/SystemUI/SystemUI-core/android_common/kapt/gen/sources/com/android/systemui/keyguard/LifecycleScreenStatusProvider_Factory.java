package com.android.systemui.keyguard;

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
public final class LifecycleScreenStatusProvider_Factory implements Factory<LifecycleScreenStatusProvider> {
  private final Provider<ScreenLifecycle> screenLifecycleProvider;

  public LifecycleScreenStatusProvider_Factory(Provider<ScreenLifecycle> screenLifecycleProvider) {
    this.screenLifecycleProvider = screenLifecycleProvider;
  }

  @Override
  public LifecycleScreenStatusProvider get() {
    return newInstance(screenLifecycleProvider.get());
  }

  public static LifecycleScreenStatusProvider_Factory create(
      Provider<ScreenLifecycle> screenLifecycleProvider) {
    return new LifecycleScreenStatusProvider_Factory(screenLifecycleProvider);
  }

  public static LifecycleScreenStatusProvider newInstance(ScreenLifecycle screenLifecycle) {
    return new LifecycleScreenStatusProvider(screenLifecycle);
  }
}
