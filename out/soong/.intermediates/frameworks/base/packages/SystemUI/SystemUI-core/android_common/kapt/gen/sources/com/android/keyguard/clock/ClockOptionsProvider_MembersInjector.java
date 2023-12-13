package com.android.keyguard.clock;

import dagger.MembersInjector;
import dagger.internal.InjectedFieldSignature;
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
public final class ClockOptionsProvider_MembersInjector implements MembersInjector<ClockOptionsProvider> {
  private final Provider<List<ClockInfo>> mClockInfosProvider;

  public ClockOptionsProvider_MembersInjector(Provider<List<ClockInfo>> mClockInfosProvider) {
    this.mClockInfosProvider = mClockInfosProvider;
  }

  public static MembersInjector<ClockOptionsProvider> create(
      Provider<List<ClockInfo>> mClockInfosProvider) {
    return new ClockOptionsProvider_MembersInjector(mClockInfosProvider);
  }

  @Override
  public void injectMembers(ClockOptionsProvider instance) {
    injectMClockInfosProvider(instance, mClockInfosProvider);
  }

  @InjectedFieldSignature("com.android.keyguard.clock.ClockOptionsProvider.mClockInfosProvider")
  public static void injectMClockInfosProvider(ClockOptionsProvider instance,
      Provider<List<ClockInfo>> mClockInfosProvider) {
    instance.mClockInfosProvider = mClockInfosProvider;
  }
}
