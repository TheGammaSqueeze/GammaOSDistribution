package com.android.keyguard.clock;

import dagger.internal.Factory;
import dagger.internal.Preconditions;
import java.util.List;
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
public final class ClockModule_ProvideClockInfoListFactory implements Factory<List<ClockInfo>> {
  private final Provider<ClockManager> clockManagerProvider;

  public ClockModule_ProvideClockInfoListFactory(Provider<ClockManager> clockManagerProvider) {
    this.clockManagerProvider = clockManagerProvider;
  }

  @Override
  public List<ClockInfo> get() {
    return provideClockInfoList(clockManagerProvider.get());
  }

  public static ClockModule_ProvideClockInfoListFactory create(
      Provider<ClockManager> clockManagerProvider) {
    return new ClockModule_ProvideClockInfoListFactory(clockManagerProvider);
  }

  public static List<ClockInfo> provideClockInfoList(ClockManager clockManager) {
    return Preconditions.checkNotNullFromProvides(ClockModule.provideClockInfoList(clockManager));
  }
}
