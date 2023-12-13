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
public final class ShadeEventCoordinatorLogger_Factory implements Factory<ShadeEventCoordinatorLogger> {
  private final Provider<LogBuffer> bufferProvider;

  public ShadeEventCoordinatorLogger_Factory(Provider<LogBuffer> bufferProvider) {
    this.bufferProvider = bufferProvider;
  }

  @Override
  public ShadeEventCoordinatorLogger get() {
    return newInstance(bufferProvider.get());
  }

  public static ShadeEventCoordinatorLogger_Factory create(Provider<LogBuffer> bufferProvider) {
    return new ShadeEventCoordinatorLogger_Factory(bufferProvider);
  }

  public static ShadeEventCoordinatorLogger newInstance(LogBuffer buffer) {
    return new ShadeEventCoordinatorLogger(buffer);
  }
}
