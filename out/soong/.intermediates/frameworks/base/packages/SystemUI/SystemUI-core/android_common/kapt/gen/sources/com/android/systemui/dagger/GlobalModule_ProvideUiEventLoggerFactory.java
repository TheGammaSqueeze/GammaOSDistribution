package com.android.systemui.dagger;

import com.android.internal.logging.UiEventLogger;
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
public final class GlobalModule_ProvideUiEventLoggerFactory implements Factory<UiEventLogger> {
  @Override
  public UiEventLogger get() {
    return provideUiEventLogger();
  }

  public static GlobalModule_ProvideUiEventLoggerFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static UiEventLogger provideUiEventLogger() {
    return Preconditions.checkNotNullFromProvides(GlobalModule.provideUiEventLogger());
  }

  private static final class InstanceHolder {
    private static final GlobalModule_ProvideUiEventLoggerFactory INSTANCE = new GlobalModule_ProvideUiEventLoggerFactory();
  }
}
