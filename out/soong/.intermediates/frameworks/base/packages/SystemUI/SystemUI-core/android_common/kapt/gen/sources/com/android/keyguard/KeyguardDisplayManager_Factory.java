package com.android.keyguard;

import android.content.Context;
import com.android.keyguard.dagger.KeyguardStatusViewComponent;
import com.android.systemui.navigationbar.NavigationBarController;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
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
public final class KeyguardDisplayManager_Factory implements Factory<KeyguardDisplayManager> {
  private final Provider<Context> contextProvider;

  private final Provider<NavigationBarController> navigationBarControllerLazyProvider;

  private final Provider<KeyguardStatusViewComponent.Factory> keyguardStatusViewComponentFactoryProvider;

  private final Provider<Executor> uiBgExecutorProvider;

  public KeyguardDisplayManager_Factory(Provider<Context> contextProvider,
      Provider<NavigationBarController> navigationBarControllerLazyProvider,
      Provider<KeyguardStatusViewComponent.Factory> keyguardStatusViewComponentFactoryProvider,
      Provider<Executor> uiBgExecutorProvider) {
    this.contextProvider = contextProvider;
    this.navigationBarControllerLazyProvider = navigationBarControllerLazyProvider;
    this.keyguardStatusViewComponentFactoryProvider = keyguardStatusViewComponentFactoryProvider;
    this.uiBgExecutorProvider = uiBgExecutorProvider;
  }

  @Override
  public KeyguardDisplayManager get() {
    return newInstance(contextProvider.get(), DoubleCheck.lazy(navigationBarControllerLazyProvider), keyguardStatusViewComponentFactoryProvider.get(), uiBgExecutorProvider.get());
  }

  public static KeyguardDisplayManager_Factory create(Provider<Context> contextProvider,
      Provider<NavigationBarController> navigationBarControllerLazyProvider,
      Provider<KeyguardStatusViewComponent.Factory> keyguardStatusViewComponentFactoryProvider,
      Provider<Executor> uiBgExecutorProvider) {
    return new KeyguardDisplayManager_Factory(contextProvider, navigationBarControllerLazyProvider, keyguardStatusViewComponentFactoryProvider, uiBgExecutorProvider);
  }

  public static KeyguardDisplayManager newInstance(Context context,
      Lazy<NavigationBarController> navigationBarControllerLazy,
      KeyguardStatusViewComponent.Factory keyguardStatusViewComponentFactory,
      Executor uiBgExecutor) {
    return new KeyguardDisplayManager(context, navigationBarControllerLazy, keyguardStatusViewComponentFactory, uiBgExecutor);
  }
}
