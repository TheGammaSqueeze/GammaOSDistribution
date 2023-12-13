package com.android.systemui.dagger;

import com.android.keyguard.ViewMediatorCallback;
import com.android.systemui.keyguard.KeyguardViewMediator;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class DependencyProvider_ProvidesViewMediatorCallbackFactory implements Factory<ViewMediatorCallback> {
  private final DependencyProvider module;

  private final Provider<KeyguardViewMediator> viewMediatorProvider;

  public DependencyProvider_ProvidesViewMediatorCallbackFactory(DependencyProvider module,
      Provider<KeyguardViewMediator> viewMediatorProvider) {
    this.module = module;
    this.viewMediatorProvider = viewMediatorProvider;
  }

  @Override
  public ViewMediatorCallback get() {
    return providesViewMediatorCallback(module, viewMediatorProvider.get());
  }

  public static DependencyProvider_ProvidesViewMediatorCallbackFactory create(
      DependencyProvider module, Provider<KeyguardViewMediator> viewMediatorProvider) {
    return new DependencyProvider_ProvidesViewMediatorCallbackFactory(module, viewMediatorProvider);
  }

  public static ViewMediatorCallback providesViewMediatorCallback(DependencyProvider instance,
      KeyguardViewMediator viewMediator) {
    return Preconditions.checkNotNullFromProvides(instance.providesViewMediatorCallback(viewMediator));
  }
}
