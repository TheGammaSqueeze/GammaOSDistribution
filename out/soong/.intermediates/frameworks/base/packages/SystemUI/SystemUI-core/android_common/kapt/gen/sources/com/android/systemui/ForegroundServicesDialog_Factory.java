package com.android.systemui;

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
public final class ForegroundServicesDialog_Factory implements Factory<ForegroundServicesDialog> {
  @Override
  public ForegroundServicesDialog get() {
    return newInstance();
  }

  public static ForegroundServicesDialog_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static ForegroundServicesDialog newInstance() {
    return new ForegroundServicesDialog();
  }

  private static final class InstanceHolder {
    private static final ForegroundServicesDialog_Factory INSTANCE = new ForegroundServicesDialog_Factory();
  }
}
