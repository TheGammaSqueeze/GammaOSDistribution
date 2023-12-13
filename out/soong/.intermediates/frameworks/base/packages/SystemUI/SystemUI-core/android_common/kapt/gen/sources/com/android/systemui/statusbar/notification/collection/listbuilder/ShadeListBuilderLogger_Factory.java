package com.android.systemui.statusbar.notification.collection.listbuilder;

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
public final class ShadeListBuilderLogger_Factory implements Factory<ShadeListBuilderLogger> {
  private final Provider<LogBuffer> bufferProvider;

  public ShadeListBuilderLogger_Factory(Provider<LogBuffer> bufferProvider) {
    this.bufferProvider = bufferProvider;
  }

  @Override
  public ShadeListBuilderLogger get() {
    return newInstance(bufferProvider.get());
  }

  public static ShadeListBuilderLogger_Factory create(Provider<LogBuffer> bufferProvider) {
    return new ShadeListBuilderLogger_Factory(bufferProvider);
  }

  public static ShadeListBuilderLogger newInstance(LogBuffer buffer) {
    return new ShadeListBuilderLogger(buffer);
  }
}
