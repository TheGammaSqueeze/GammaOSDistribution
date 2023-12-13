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
public final class NotificationClickerLogger_Factory implements Factory<NotificationClickerLogger> {
  private final Provider<LogBuffer> bufferProvider;

  public NotificationClickerLogger_Factory(Provider<LogBuffer> bufferProvider) {
    this.bufferProvider = bufferProvider;
  }

  @Override
  public NotificationClickerLogger get() {
    return newInstance(bufferProvider.get());
  }

  public static NotificationClickerLogger_Factory create(Provider<LogBuffer> bufferProvider) {
    return new NotificationClickerLogger_Factory(bufferProvider);
  }

  public static NotificationClickerLogger newInstance(LogBuffer buffer) {
    return new NotificationClickerLogger(buffer);
  }
}
