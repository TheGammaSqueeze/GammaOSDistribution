package com.android.systemui.assist;

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
public final class DeviceConfigHelper_Factory implements Factory<DeviceConfigHelper> {
  @Override
  public DeviceConfigHelper get() {
    return newInstance();
  }

  public static DeviceConfigHelper_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static DeviceConfigHelper newInstance() {
    return new DeviceConfigHelper();
  }

  private static final class InstanceHolder {
    private static final DeviceConfigHelper_Factory INSTANCE = new DeviceConfigHelper_Factory();
  }
}
