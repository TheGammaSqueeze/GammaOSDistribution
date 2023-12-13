package com.android.systemui.dagger;

import android.content.Context;
import com.android.internal.util.LatencyTracker;
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
public final class FrameworkServicesModule_ProvideLatencyTrackerFactory implements Factory<LatencyTracker> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideLatencyTrackerFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public LatencyTracker get() {
    return provideLatencyTracker(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideLatencyTrackerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideLatencyTrackerFactory(contextProvider);
  }

  public static LatencyTracker provideLatencyTracker(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideLatencyTracker(context));
  }
}
