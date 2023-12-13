package com.android.systemui.statusbar.phone.ongoingcall;

import com.android.internal.logging.UiEventLogger;
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
public final class OngoingCallLogger_Factory implements Factory<OngoingCallLogger> {
  private final Provider<UiEventLogger> loggerProvider;

  public OngoingCallLogger_Factory(Provider<UiEventLogger> loggerProvider) {
    this.loggerProvider = loggerProvider;
  }

  @Override
  public OngoingCallLogger get() {
    return newInstance(loggerProvider.get());
  }

  public static OngoingCallLogger_Factory create(Provider<UiEventLogger> loggerProvider) {
    return new OngoingCallLogger_Factory(loggerProvider);
  }

  public static OngoingCallLogger newInstance(UiEventLogger logger) {
    return new OngoingCallLogger(logger);
  }
}
