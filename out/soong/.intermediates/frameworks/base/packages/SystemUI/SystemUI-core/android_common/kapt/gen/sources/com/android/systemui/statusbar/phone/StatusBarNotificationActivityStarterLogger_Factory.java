package com.android.systemui.statusbar.phone;

import com.android.systemui.log.LogBuffer;
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
public final class StatusBarNotificationActivityStarterLogger_Factory implements Factory<StatusBarNotificationActivityStarterLogger> {
  private final Provider<LogBuffer> bufferProvider;

  public StatusBarNotificationActivityStarterLogger_Factory(Provider<LogBuffer> bufferProvider) {
    this.bufferProvider = bufferProvider;
  }

  @Override
  public StatusBarNotificationActivityStarterLogger get() {
    return newInstance(bufferProvider.get());
  }

  public static StatusBarNotificationActivityStarterLogger_Factory create(
      Provider<LogBuffer> bufferProvider) {
    return new StatusBarNotificationActivityStarterLogger_Factory(bufferProvider);
  }

  public static StatusBarNotificationActivityStarterLogger newInstance(LogBuffer buffer) {
    return new StatusBarNotificationActivityStarterLogger(buffer);
  }
}
