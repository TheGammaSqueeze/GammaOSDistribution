package com.android.systemui.privacy.logging;

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
public final class PrivacyLogger_Factory implements Factory<PrivacyLogger> {
  private final Provider<LogBuffer> bufferProvider;

  public PrivacyLogger_Factory(Provider<LogBuffer> bufferProvider) {
    this.bufferProvider = bufferProvider;
  }

  @Override
  public PrivacyLogger get() {
    return newInstance(bufferProvider.get());
  }

  public static PrivacyLogger_Factory create(Provider<LogBuffer> bufferProvider) {
    return new PrivacyLogger_Factory(bufferProvider);
  }

  public static PrivacyLogger newInstance(LogBuffer buffer) {
    return new PrivacyLogger(buffer);
  }
}
