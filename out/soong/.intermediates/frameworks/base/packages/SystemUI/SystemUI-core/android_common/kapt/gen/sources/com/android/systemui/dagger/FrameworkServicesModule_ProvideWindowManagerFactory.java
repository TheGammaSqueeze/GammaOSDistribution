package com.android.systemui.dagger;

import android.content.Context;
import android.view.WindowManager;
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
public final class FrameworkServicesModule_ProvideWindowManagerFactory implements Factory<WindowManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideWindowManagerFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public WindowManager get() {
    return provideWindowManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideWindowManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideWindowManagerFactory(contextProvider);
  }

  public static WindowManager provideWindowManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideWindowManager(context));
  }
}
