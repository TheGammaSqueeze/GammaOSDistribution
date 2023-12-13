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
public final class GutsCoordinatorLogger_Factory implements Factory<GutsCoordinatorLogger> {
  private final Provider<LogBuffer> bufferProvider;

  public GutsCoordinatorLogger_Factory(Provider<LogBuffer> bufferProvider) {
    this.bufferProvider = bufferProvider;
  }

  @Override
  public GutsCoordinatorLogger get() {
    return newInstance(bufferProvider.get());
  }

  public static GutsCoordinatorLogger_Factory create(Provider<LogBuffer> bufferProvider) {
    return new GutsCoordinatorLogger_Factory(bufferProvider);
  }

  public static GutsCoordinatorLogger newInstance(LogBuffer buffer) {
    return new GutsCoordinatorLogger(buffer);
  }
}
