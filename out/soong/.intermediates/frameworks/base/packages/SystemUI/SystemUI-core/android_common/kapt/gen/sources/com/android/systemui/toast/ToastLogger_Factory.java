package com.android.systemui.toast;

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
public final class ToastLogger_Factory implements Factory<ToastLogger> {
  private final Provider<LogBuffer> bufferProvider;

  public ToastLogger_Factory(Provider<LogBuffer> bufferProvider) {
    this.bufferProvider = bufferProvider;
  }

  @Override
  public ToastLogger get() {
    return newInstance(bufferProvider.get());
  }

  public static ToastLogger_Factory create(Provider<LogBuffer> bufferProvider) {
    return new ToastLogger_Factory(bufferProvider);
  }

  public static ToastLogger newInstance(LogBuffer buffer) {
    return new ToastLogger(buffer);
  }
}
