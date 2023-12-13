package com.android.systemui.statusbar.notification.collection.render;

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
public final class ShadeViewDifferLogger_Factory implements Factory<ShadeViewDifferLogger> {
  private final Provider<LogBuffer> bufferProvider;

  public ShadeViewDifferLogger_Factory(Provider<LogBuffer> bufferProvider) {
    this.bufferProvider = bufferProvider;
  }

  @Override
  public ShadeViewDifferLogger get() {
    return newInstance(bufferProvider.get());
  }

  public static ShadeViewDifferLogger_Factory create(Provider<LogBuffer> bufferProvider) {
    return new ShadeViewDifferLogger_Factory(bufferProvider);
  }

  public static ShadeViewDifferLogger newInstance(LogBuffer buffer) {
    return new ShadeViewDifferLogger(buffer);
  }
}
