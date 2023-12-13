package com.android.systemui.statusbar.notification.collection.coordinator;

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
public final class SharedCoordinatorLogger_Factory implements Factory<SharedCoordinatorLogger> {
  private final Provider<LogBuffer> bufferProvider;

  public SharedCoordinatorLogger_Factory(Provider<LogBuffer> bufferProvider) {
    this.bufferProvider = bufferProvider;
  }

  @Override
  public SharedCoordinatorLogger get() {
    return newInstance(bufferProvider.get());
  }

  public static SharedCoordinatorLogger_Factory create(Provider<LogBuffer> bufferProvider) {
    return new SharedCoordinatorLogger_Factory(bufferProvider);
  }

  public static SharedCoordinatorLogger newInstance(LogBuffer buffer) {
    return new SharedCoordinatorLogger(buffer);
  }
}
