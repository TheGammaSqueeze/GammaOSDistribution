package com.android.systemui.statusbar.notification.stack;

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
public final class NotificationSectionsLogger_Factory implements Factory<NotificationSectionsLogger> {
  private final Provider<LogBuffer> logBufferProvider;

  public NotificationSectionsLogger_Factory(Provider<LogBuffer> logBufferProvider) {
    this.logBufferProvider = logBufferProvider;
  }

  @Override
  public NotificationSectionsLogger get() {
    return newInstance(logBufferProvider.get());
  }

  public static NotificationSectionsLogger_Factory create(Provider<LogBuffer> logBufferProvider) {
    return new NotificationSectionsLogger_Factory(logBufferProvider);
  }

  public static NotificationSectionsLogger newInstance(LogBuffer logBuffer) {
    return new NotificationSectionsLogger(logBuffer);
  }
}
