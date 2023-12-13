package com.android.systemui.util.time;

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
public final class SystemClockImpl_Factory implements Factory<SystemClockImpl> {
  @Override
  public SystemClockImpl get() {
    return newInstance();
  }

  public static SystemClockImpl_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static SystemClockImpl newInstance() {
    return new SystemClockImpl();
  }

  private static final class InstanceHolder {
    private static final SystemClockImpl_Factory INSTANCE = new SystemClockImpl_Factory();
  }
}
