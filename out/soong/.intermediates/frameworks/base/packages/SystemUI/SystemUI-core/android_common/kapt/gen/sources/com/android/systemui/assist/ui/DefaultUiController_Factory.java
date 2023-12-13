package com.android.systemui.assist.ui;

import android.content.Context;
import com.android.systemui.assist.AssistLogger;
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
public final class DefaultUiController_Factory implements Factory<DefaultUiController> {
  private final Provider<Context> contextProvider;

  private final Provider<AssistLogger> assistLoggerProvider;

  public DefaultUiController_Factory(Provider<Context> contextProvider,
      Provider<AssistLogger> assistLoggerProvider) {
    this.contextProvider = contextProvider;
    this.assistLoggerProvider = assistLoggerProvider;
  }

  @Override
  public DefaultUiController get() {
    return newInstance(contextProvider.get(), assistLoggerProvider.get());
  }

  public static DefaultUiController_Factory create(Provider<Context> contextProvider,
      Provider<AssistLogger> assistLoggerProvider) {
    return new DefaultUiController_Factory(contextProvider, assistLoggerProvider);
  }

  public static DefaultUiController newInstance(Context context, AssistLogger assistLogger) {
    return new DefaultUiController(context, assistLogger);
  }
}
