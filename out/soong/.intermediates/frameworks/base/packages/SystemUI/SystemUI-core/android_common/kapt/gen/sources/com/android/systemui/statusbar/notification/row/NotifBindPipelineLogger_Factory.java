package com.android.systemui.statusbar.notification.row;

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
public final class NotifBindPipelineLogger_Factory implements Factory<NotifBindPipelineLogger> {
  private final Provider<LogBuffer> bufferProvider;

  public NotifBindPipelineLogger_Factory(Provider<LogBuffer> bufferProvider) {
    this.bufferProvider = bufferProvider;
  }

  @Override
  public NotifBindPipelineLogger get() {
    return newInstance(bufferProvider.get());
  }

  public static NotifBindPipelineLogger_Factory create(Provider<LogBuffer> bufferProvider) {
    return new NotifBindPipelineLogger_Factory(bufferProvider);
  }

  public static NotifBindPipelineLogger newInstance(LogBuffer buffer) {
    return new NotifBindPipelineLogger(buffer);
  }
}
