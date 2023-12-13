package com.android.systemui.broadcast.logging;

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
public final class BroadcastDispatcherLogger_Factory implements Factory<BroadcastDispatcherLogger> {
  private final Provider<LogBuffer> bufferProvider;

  public BroadcastDispatcherLogger_Factory(Provider<LogBuffer> bufferProvider) {
    this.bufferProvider = bufferProvider;
  }

  @Override
  public BroadcastDispatcherLogger get() {
    return newInstance(bufferProvider.get());
  }

  public static BroadcastDispatcherLogger_Factory create(Provider<LogBuffer> bufferProvider) {
    return new BroadcastDispatcherLogger_Factory(bufferProvider);
  }

  public static BroadcastDispatcherLogger newInstance(LogBuffer buffer) {
    return new BroadcastDispatcherLogger(buffer);
  }
}
