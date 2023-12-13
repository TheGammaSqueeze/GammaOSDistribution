package com.android.systemui.classifier;

import dagger.internal.Factory;
import javax.annotation.processing.Generated;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class FalsingModule_ProvidesDoubleTapTimeoutMsFactory implements Factory<Long> {
  @Override
  public Long get() {
    return providesDoubleTapTimeoutMs();
  }

  public static FalsingModule_ProvidesDoubleTapTimeoutMsFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static long providesDoubleTapTimeoutMs() {
    return FalsingModule.providesDoubleTapTimeoutMs();
  }

  private static final class InstanceHolder {
    private static final FalsingModule_ProvidesDoubleTapTimeoutMsFactory INSTANCE = new FalsingModule_ProvidesDoubleTapTimeoutMsFactory();
  }
}
