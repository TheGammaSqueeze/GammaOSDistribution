package com.android.systemui.dagger;

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
public final class SystemUIDefaultModule_ProvideAllowNotificationLongPressFactory implements Factory<Boolean> {
  @Override
  public Boolean get() {
    return provideAllowNotificationLongPress();
  }

  public static SystemUIDefaultModule_ProvideAllowNotificationLongPressFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static boolean provideAllowNotificationLongPress() {
    return SystemUIDefaultModule.provideAllowNotificationLongPress();
  }

  private static final class InstanceHolder {
    private static final SystemUIDefaultModule_ProvideAllowNotificationLongPressFactory INSTANCE = new SystemUIDefaultModule_ProvideAllowNotificationLongPressFactory();
  }
}
