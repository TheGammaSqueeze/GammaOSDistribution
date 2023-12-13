package com.android.systemui.util;

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
public final class DeviceConfigProxy_Factory implements Factory<DeviceConfigProxy> {
  @Override
  public DeviceConfigProxy get() {
    return newInstance();
  }

  public static DeviceConfigProxy_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static DeviceConfigProxy newInstance() {
    return new DeviceConfigProxy();
  }

  private static final class InstanceHolder {
    private static final DeviceConfigProxy_Factory INSTANCE = new DeviceConfigProxy_Factory();
  }
}
