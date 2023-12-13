package com.android.systemui.qs.logging;

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
public final class QSLogger_Factory implements Factory<QSLogger> {
  private final Provider<LogBuffer> bufferProvider;

  public QSLogger_Factory(Provider<LogBuffer> bufferProvider) {
    this.bufferProvider = bufferProvider;
  }

  @Override
  public QSLogger get() {
    return newInstance(bufferProvider.get());
  }

  public static QSLogger_Factory create(Provider<LogBuffer> bufferProvider) {
    return new QSLogger_Factory(bufferProvider);
  }

  public static QSLogger newInstance(LogBuffer buffer) {
    return new QSLogger(buffer);
  }
}
