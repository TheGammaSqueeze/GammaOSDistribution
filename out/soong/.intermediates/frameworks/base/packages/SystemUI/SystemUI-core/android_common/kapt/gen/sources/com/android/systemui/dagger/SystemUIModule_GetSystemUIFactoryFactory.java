package com.android.systemui.dagger;

import com.android.systemui.SystemUIFactory;
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
public final class SystemUIModule_GetSystemUIFactoryFactory implements Factory<SystemUIFactory> {
  @Override
  public SystemUIFactory get() {
    return getSystemUIFactory();
  }

  public static SystemUIModule_GetSystemUIFactoryFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static SystemUIFactory getSystemUIFactory() {
    return Preconditions.checkNotNullFromProvides(SystemUIModule.getSystemUIFactory());
  }

  private static final class InstanceHolder {
    private static final SystemUIModule_GetSystemUIFactoryFactory INSTANCE = new SystemUIModule_GetSystemUIFactoryFactory();
  }
}
