package com.android.systemui.statusbar.phone;

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
public final class StatusBarLocationPublisher_Factory implements Factory<StatusBarLocationPublisher> {
  @Override
  public StatusBarLocationPublisher get() {
    return newInstance();
  }

  public static StatusBarLocationPublisher_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static StatusBarLocationPublisher newInstance() {
    return new StatusBarLocationPublisher();
  }

  private static final class InstanceHolder {
    private static final StatusBarLocationPublisher_Factory INSTANCE = new StatusBarLocationPublisher_Factory();
  }
}
