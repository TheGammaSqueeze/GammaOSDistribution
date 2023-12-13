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
public final class PreparationCoordinatorLogger_Factory implements Factory<PreparationCoordinatorLogger> {
  private final Provider<LogBuffer> bufferProvider;

  public PreparationCoordinatorLogger_Factory(Provider<LogBuffer> bufferProvider) {
    this.bufferProvider = bufferProvider;
  }

  @Override
  public PreparationCoordinatorLogger get() {
    return newInstance(bufferProvider.get());
  }

  public static PreparationCoordinatorLogger_Factory create(Provider<LogBuffer> bufferProvider) {
    return new PreparationCoordinatorLogger_Factory(bufferProvider);
  }

  public static PreparationCoordinatorLogger newInstance(LogBuffer buffer) {
    return new PreparationCoordinatorLogger(buffer);
  }
}
