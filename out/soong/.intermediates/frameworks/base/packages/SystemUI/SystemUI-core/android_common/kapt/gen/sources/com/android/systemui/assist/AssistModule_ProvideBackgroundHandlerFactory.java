package com.android.systemui.assist;

import android.os.Handler;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import javax.annotation.processing.Generated;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class AssistModule_ProvideBackgroundHandlerFactory implements Factory<Handler> {
  @Override
  public Handler get() {
    return provideBackgroundHandler();
  }

  public static AssistModule_ProvideBackgroundHandlerFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static Handler provideBackgroundHandler() {
    return Preconditions.checkNotNullFromProvides(AssistModule.provideBackgroundHandler());
  }

  private static final class InstanceHolder {
    private static final AssistModule_ProvideBackgroundHandlerFactory INSTANCE = new AssistModule_ProvideBackgroundHandlerFactory();
  }
}
