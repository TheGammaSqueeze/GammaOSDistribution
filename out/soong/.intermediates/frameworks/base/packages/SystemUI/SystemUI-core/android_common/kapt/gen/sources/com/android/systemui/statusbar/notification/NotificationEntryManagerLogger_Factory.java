package com.android.systemui.statusbar.notification;

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
public final class NotificationEntryManagerLogger_Factory implements Factory<NotificationEntryManagerLogger> {
  private final Provider<LogBuffer> bufferProvider;

  public NotificationEntryManagerLogger_Factory(Provider<LogBuffer> bufferProvider) {
    this.bufferProvider = bufferProvider;
  }

  @Override
  public NotificationEntryManagerLogger get() {
    return newInstance(bufferProvider.get());
  }

  public static NotificationEntryManagerLogger_Factory create(Provider<LogBuffer> bufferProvider) {
    return new NotificationEntryManagerLogger_Factory(bufferProvider);
  }

  public static NotificationEntryManagerLogger newInstance(LogBuffer buffer) {
    return new NotificationEntryManagerLogger(buffer);
  }
}
