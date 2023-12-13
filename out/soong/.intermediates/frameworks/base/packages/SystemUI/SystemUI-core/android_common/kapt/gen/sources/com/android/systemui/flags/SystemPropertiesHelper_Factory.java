package com.android.systemui.flags;

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
public final class SystemPropertiesHelper_Factory implements Factory<SystemPropertiesHelper> {
  @Override
  public SystemPropertiesHelper get() {
    return newInstance();
  }

  public static SystemPropertiesHelper_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static SystemPropertiesHelper newInstance() {
    return new SystemPropertiesHelper();
  }

  private static final class InstanceHolder {
    private static final SystemPropertiesHelper_Factory INSTANCE = new SystemPropertiesHelper_Factory();
  }
}
