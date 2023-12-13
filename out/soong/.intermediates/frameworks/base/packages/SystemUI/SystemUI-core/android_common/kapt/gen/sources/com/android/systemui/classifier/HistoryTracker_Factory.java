package com.android.systemui.classifier;

import com.android.systemui.util.time.SystemClock;
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
public final class HistoryTracker_Factory implements Factory<HistoryTracker> {
  private final Provider<SystemClock> systemClockProvider;

  public HistoryTracker_Factory(Provider<SystemClock> systemClockProvider) {
    this.systemClockProvider = systemClockProvider;
  }

  @Override
  public HistoryTracker get() {
    return newInstance(systemClockProvider.get());
  }

  public static HistoryTracker_Factory create(Provider<SystemClock> systemClockProvider) {
    return new HistoryTracker_Factory(systemClockProvider);
  }

  public static HistoryTracker newInstance(SystemClock systemClock) {
    return new HistoryTracker(systemClock);
  }
}
