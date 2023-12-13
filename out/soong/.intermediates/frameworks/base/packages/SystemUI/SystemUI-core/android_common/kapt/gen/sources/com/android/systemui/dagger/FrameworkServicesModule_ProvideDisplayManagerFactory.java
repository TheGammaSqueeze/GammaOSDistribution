package com.android.systemui.dagger;

import android.content.Context;
import android.hardware.display.DisplayManager;
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
public final class FrameworkServicesModule_ProvideDisplayManagerFactory implements Factory<DisplayManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideDisplayManagerFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public DisplayManager get() {
    return provideDisplayManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideDisplayManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideDisplayManagerFactory(contextProvider);
  }

  public static DisplayManager provideDisplayManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideDisplayManager(context));
  }
}
