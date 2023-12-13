package com.android.systemui.keyguard;

import com.android.wm.shell.transition.ShellTransitions;
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
public final class KeyguardService_Factory implements Factory<KeyguardService> {
  private final Provider<KeyguardViewMediator> keyguardViewMediatorProvider;

  private final Provider<KeyguardLifecyclesDispatcher> keyguardLifecyclesDispatcherProvider;

  private final Provider<ShellTransitions> shellTransitionsProvider;

  public KeyguardService_Factory(Provider<KeyguardViewMediator> keyguardViewMediatorProvider,
      Provider<KeyguardLifecyclesDispatcher> keyguardLifecyclesDispatcherProvider,
      Provider<ShellTransitions> shellTransitionsProvider) {
    this.keyguardViewMediatorProvider = keyguardViewMediatorProvider;
    this.keyguardLifecyclesDispatcherProvider = keyguardLifecyclesDispatcherProvider;
    this.shellTransitionsProvider = shellTransitionsProvider;
  }

  @Override
  public KeyguardService get() {
    return newInstance(keyguardViewMediatorProvider.get(), keyguardLifecyclesDispatcherProvider.get(), shellTransitionsProvider.get());
  }

  public static KeyguardService_Factory create(
      Provider<KeyguardViewMediator> keyguardViewMediatorProvider,
      Provider<KeyguardLifecyclesDispatcher> keyguardLifecyclesDispatcherProvider,
      Provider<ShellTransitions> shellTransitionsProvider) {
    return new KeyguardService_Factory(keyguardViewMediatorProvider, keyguardLifecyclesDispatcherProvider, shellTransitionsProvider);
  }

  public static KeyguardService newInstance(KeyguardViewMediator keyguardViewMediator,
      KeyguardLifecyclesDispatcher keyguardLifecyclesDispatcher,
      ShellTransitions shellTransitions) {
    return new KeyguardService(keyguardViewMediator, keyguardLifecyclesDispatcher, shellTransitions);
  }
}
