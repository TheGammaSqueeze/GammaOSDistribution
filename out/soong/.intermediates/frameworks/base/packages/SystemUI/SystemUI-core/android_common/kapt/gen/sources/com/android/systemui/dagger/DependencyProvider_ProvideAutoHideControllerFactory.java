package com.android.systemui.dagger;

import android.content.Context;
import android.os.Handler;
import android.view.IWindowManager;
import com.android.systemui.statusbar.phone.AutoHideController;
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
public final class DependencyProvider_ProvideAutoHideControllerFactory implements Factory<AutoHideController> {
  private final DependencyProvider module;

  private final Provider<Context> contextProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<IWindowManager> iWindowManagerProvider;

  public DependencyProvider_ProvideAutoHideControllerFactory(DependencyProvider module,
      Provider<Context> contextProvider, Provider<Handler> mainHandlerProvider,
      Provider<IWindowManager> iWindowManagerProvider) {
    this.module = module;
    this.contextProvider = contextProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.iWindowManagerProvider = iWindowManagerProvider;
  }

  @Override
  public AutoHideController get() {
    return provideAutoHideController(module, contextProvider.get(), mainHandlerProvider.get(), iWindowManagerProvider.get());
  }

  public static DependencyProvider_ProvideAutoHideControllerFactory create(
      DependencyProvider module, Provider<Context> contextProvider,
      Provider<Handler> mainHandlerProvider, Provider<IWindowManager> iWindowManagerProvider) {
    return new DependencyProvider_ProvideAutoHideControllerFactory(module, contextProvider, mainHandlerProvider, iWindowManagerProvider);
  }

  public static AutoHideController provideAutoHideController(DependencyProvider instance,
      Context context, Handler mainHandler, IWindowManager iWindowManager) {
    return Preconditions.checkNotNullFromProvides(instance.provideAutoHideController(context, mainHandler, iWindowManager));
  }
}
