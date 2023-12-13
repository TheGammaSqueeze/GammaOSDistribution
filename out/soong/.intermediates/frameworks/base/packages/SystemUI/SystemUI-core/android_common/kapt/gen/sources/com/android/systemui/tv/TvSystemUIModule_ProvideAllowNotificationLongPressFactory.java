package com.android.systemui.tv;

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
public final class TvSystemUIModule_ProvideAllowNotificationLongPressFactory implements Factory<Boolean> {
  @Override
  public Boolean get() {
    return provideAllowNotificationLongPress();
  }

  public static TvSystemUIModule_ProvideAllowNotificationLongPressFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static boolean provideAllowNotificationLongPress() {
    return TvSystemUIModule.provideAllowNotificationLongPress();
  }

  private static final class InstanceHolder {
    private static final TvSystemUIModule_ProvideAllowNotificationLongPressFactory INSTANCE = new TvSystemUIModule_ProvideAllowNotificationLongPressFactory();
  }
}
