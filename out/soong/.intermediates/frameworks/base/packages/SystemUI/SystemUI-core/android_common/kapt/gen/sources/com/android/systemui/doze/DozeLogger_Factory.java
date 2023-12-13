package com.android.systemui.doze;

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
public final class DozeLogger_Factory implements Factory<DozeLogger> {
  private final Provider<LogBuffer> bufferProvider;

  public DozeLogger_Factory(Provider<LogBuffer> bufferProvider) {
    this.bufferProvider = bufferProvider;
  }

  @Override
  public DozeLogger get() {
    return newInstance(bufferProvider.get());
  }

  public static DozeLogger_Factory create(Provider<LogBuffer> bufferProvider) {
    return new DozeLogger_Factory(bufferProvider);
  }

  public static DozeLogger newInstance(LogBuffer buffer) {
    return new DozeLogger(buffer);
  }
}
