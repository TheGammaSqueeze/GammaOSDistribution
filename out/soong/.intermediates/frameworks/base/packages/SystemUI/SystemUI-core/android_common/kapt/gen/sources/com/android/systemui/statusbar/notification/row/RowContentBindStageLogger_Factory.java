package com.android.systemui.statusbar.notification.row;

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
public final class RowContentBindStageLogger_Factory implements Factory<RowContentBindStageLogger> {
  private final Provider<LogBuffer> bufferProvider;

  public RowContentBindStageLogger_Factory(Provider<LogBuffer> bufferProvider) {
    this.bufferProvider = bufferProvider;
  }

  @Override
  public RowContentBindStageLogger get() {
    return newInstance(bufferProvider.get());
  }

  public static RowContentBindStageLogger_Factory create(Provider<LogBuffer> bufferProvider) {
    return new RowContentBindStageLogger_Factory(bufferProvider);
  }

  public static RowContentBindStageLogger newInstance(LogBuffer buffer) {
    return new RowContentBindStageLogger(buffer);
  }
}
