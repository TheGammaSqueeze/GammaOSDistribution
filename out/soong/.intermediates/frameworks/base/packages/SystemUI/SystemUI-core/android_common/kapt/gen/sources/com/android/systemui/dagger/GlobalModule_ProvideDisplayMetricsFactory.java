package com.android.systemui.dagger;

import android.content.Context;
import android.util.DisplayMetrics;
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
public final class GlobalModule_ProvideDisplayMetricsFactory implements Factory<DisplayMetrics> {
  private final GlobalModule module;

  private final Provider<Context> contextProvider;

  public GlobalModule_ProvideDisplayMetricsFactory(GlobalModule module,
      Provider<Context> contextProvider) {
    this.module = module;
    this.contextProvider = contextProvider;
  }

  @Override
  public DisplayMetrics get() {
    return provideDisplayMetrics(module, contextProvider.get());
  }

  public static GlobalModule_ProvideDisplayMetricsFactory create(GlobalModule module,
      Provider<Context> contextProvider) {
    return new GlobalModule_ProvideDisplayMetricsFactory(module, contextProvider);
  }

  public static DisplayMetrics provideDisplayMetrics(GlobalModule instance, Context context) {
    return Preconditions.checkNotNullFromProvides(instance.provideDisplayMetrics(context));
  }
}
