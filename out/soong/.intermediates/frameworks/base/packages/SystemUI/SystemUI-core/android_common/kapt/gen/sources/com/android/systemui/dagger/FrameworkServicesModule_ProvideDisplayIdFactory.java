package com.android.systemui.dagger;

import android.content.Context;
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
public final class FrameworkServicesModule_ProvideDisplayIdFactory implements Factory<Integer> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideDisplayIdFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public Integer get() {
    return provideDisplayId(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideDisplayIdFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideDisplayIdFactory(contextProvider);
  }

  public static int provideDisplayId(Context context) {
    return FrameworkServicesModule.provideDisplayId(context);
  }
}
