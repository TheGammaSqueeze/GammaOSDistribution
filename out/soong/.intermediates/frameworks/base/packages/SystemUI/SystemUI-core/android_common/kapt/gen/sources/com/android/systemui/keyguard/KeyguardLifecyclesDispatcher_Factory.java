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
public final class KeyguardLifecyclesDispatcher_Factory implements Factory<KeyguardLifecyclesDispatcher> {
  private final Provider<ScreenLifecycle> screenLifecycleProvider;

  private final Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider;

  public KeyguardLifecyclesDispatcher_Factory(Provider<ScreenLifecycle> screenLifecycleProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider) {
    this.screenLifecycleProvider = screenLifecycleProvider;
    this.wakefulnessLifecycleProvider = wakefulnessLifecycleProvider;
  }

  @Override
  public KeyguardLifecyclesDispatcher get() {
    return newInstance(screenLifecycleProvider.get(), wakefulnessLifecycleProvider.get());
  }

  public static KeyguardLifecyclesDispatcher_Factory create(
      Provider<ScreenLifecycle> screenLifecycleProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider) {
    return new KeyguardLifecyclesDispatcher_Factory(screenLifecycleProvider, wakefulnessLifecycleProvider);
  }

  public static KeyguardLifecyclesDispatcher newInstance(ScreenLifecycle screenLifecycle,
      WakefulnessLifecycle wakefulnessLifecycle) {
    return new KeyguardLifecyclesDispatcher(screenLifecycle, wakefulnessLifecycle);
  }
}
