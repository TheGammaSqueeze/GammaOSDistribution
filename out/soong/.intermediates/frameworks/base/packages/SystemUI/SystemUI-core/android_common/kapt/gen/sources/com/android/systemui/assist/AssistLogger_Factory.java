package com.android.systemui.assist;

import android.content.Context;
import com.android.internal.app.AssistUtils;
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
public final class AssistLogger_Factory implements Factory<AssistLogger> {
  private final Provider<Context> contextProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  private final Provider<AssistUtils> assistUtilsProvider;

  private final Provider<PhoneStateMonitor> phoneStateMonitorProvider;

  public AssistLogger_Factory(Provider<Context> contextProvider,
      Provider<UiEventLogger> uiEventLoggerProvider, Provider<AssistUtils> assistUtilsProvider,
      Provider<PhoneStateMonitor> phoneStateMonitorProvider) {
    this.contextProvider = contextProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
    this.assistUtilsProvider = assistUtilsProvider;
    this.phoneStateMonitorProvider = phoneStateMonitorProvider;
  }

  @Override
  public AssistLogger get() {
    return newInstance(contextProvider.get(), uiEventLoggerProvider.get(), assistUtilsProvider.get(), phoneStateMonitorProvider.get());
  }

  public static AssistLogger_Factory create(Provider<Context> contextProvider,
      Provider<UiEventLogger> uiEventLoggerProvider, Provider<AssistUtils> assistUtilsProvider,
      Provider<PhoneStateMonitor> phoneStateMonitorProvider) {
    return new AssistLogger_Factory(contextProvider, uiEventLoggerProvider, assistUtilsProvider, phoneStateMonitorProvider);
  }

  public static AssistLogger newInstance(Context context, UiEventLogger uiEventLogger,
      AssistUtils assistUtils, PhoneStateMonitor phoneStateMonitor) {
    return new AssistLogger(context, uiEventLogger, assistUtils, phoneStateMonitor);
  }
}
