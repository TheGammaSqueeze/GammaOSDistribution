package com.android.systemui.dagger;

import android.app.StatsManager;
import android.content.Context;
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
public final class FrameworkServicesModule_ProvideStatsManagerFactory implements Factory<StatsManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideStatsManagerFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public StatsManager get() {
    return provideStatsManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideStatsManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideStatsManagerFactory(contextProvider);
  }

  public static StatsManager provideStatsManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideStatsManager(context));
  }
}
