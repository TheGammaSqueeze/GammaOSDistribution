package com.android.systemui.dagger;

import android.content.Context;
import android.hardware.display.ColorDisplayManager;
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
public final class FrameworkServicesModule_ProvideColorDisplayManagerFactory implements Factory<ColorDisplayManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideColorDisplayManagerFactory(
      Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public ColorDisplayManager get() {
    return provideColorDisplayManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideColorDisplayManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideColorDisplayManagerFactory(contextProvider);
  }

  public static ColorDisplayManager provideColorDisplayManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideColorDisplayManager(context));
  }
}
