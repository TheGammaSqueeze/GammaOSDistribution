package com.android.systemui.statusbar;

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
public final class ActionClickLogger_Factory implements Factory<ActionClickLogger> {
  private final Provider<LogBuffer> bufferProvider;

  public ActionClickLogger_Factory(Provider<LogBuffer> bufferProvider) {
    this.bufferProvider = bufferProvider;
  }

  @Override
  public ActionClickLogger get() {
    return newInstance(bufferProvider.get());
  }

  public static ActionClickLogger_Factory create(Provider<LogBuffer> bufferProvider) {
    return new ActionClickLogger_Factory(bufferProvider);
  }

  public static ActionClickLogger newInstance(LogBuffer buffer) {
    return new ActionClickLogger(buffer);
  }
}
