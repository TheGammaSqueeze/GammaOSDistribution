package com.android.systemui.assist;

import androidx.slice.Clock;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import javax.annotation.processing.Generated;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class AssistModule_ProvideSystemClockFactory implements Factory<Clock> {
  @Override
  public Clock get() {
    return provideSystemClock();
  }

  public static AssistModule_ProvideSystemClockFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static Clock provideSystemClock() {
    return Preconditions.checkNotNullFromProvides(AssistModule.provideSystemClock());
  }

  private static final class InstanceHolder {
    private static final AssistModule_ProvideSystemClockFactory INSTANCE = new AssistModule_ProvideSystemClockFactory();
  }
}
